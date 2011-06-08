/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
 *           (c) 2011 Shunsuke Shida
 *           (c) 2011 Yuuki Wakamatsu
 *           (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Constants.h>
#include <llvm/GlobalVariable.h>
#include <llvm/Function.h>
#include <llvm/BasicBlock.h>
#include <llvm/Instructions.h>
#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Target/TargetData.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Transforms/Scalar.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#define USE_STEXT     1
#define USE_cwb_open  1
#undef HAVE_SYS_TYPES_H
#include "commons.h"
#define ASM_PREFIX llvmasm::
#define LLVM_TODO(str) {\
	fprintf(stderr, "(TODO: %s %d):", __func__, __LINE__);\
	fprintf(stderr, "%s\n", str);\
	asm volatile("int3");\
}
#define LLVM_WARN(str) {\
	fprintf(stderr, "(WARN: %s %d):", __func__, __LINE__);\
	fprintf(stderr, "%s\n", str);\
}

#define _UNUSED_ __attribute__((unused))

/* FIXME remove IS_Tnumbox */
#define IS_Tnumbox(t)     (t == CLASS_Object || t == CLASS_Number)

/* ************************************************************************ */

namespace llvmasm {
using namespace llvm;

#define ASM(X, ...)
#define ASML(idx) ((idx < DP(ctx->gma)->espidx) ? (DP(ctx->gma)->espidx) : idx)
static void Tn_asm(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_type_t reqt, int local);
static int _BLOCK_asm(CTX ctx, knh_Stmt_t *stmtH, knh_type_t reqt, int sfpidx);

struct llvm_context {
	Module *m;
	Function *curFunc;
	BasicBlock *curBB;
	IRBuilder<> *builder;
};

struct label_stack {
	BasicBlock *bbCon;
	BasicBlock *bbBreak;
	knh_Array_t *phiCon;
	knh_Array_t *phiBreak;
};

#define LLVM_IDX_MODULE    (0)
#define LLVM_IDX_FUNCTION  (1)
#define LLVM_IDX_BB        (2)
#define LLVM_IDX_BUILDER   (3)
#define LLVM_IDX_LABELSTACK (4)
static inline Module *LLVM_MODULE(CTX ctx)
{
	Module *m = (Module*) DP(ctx->gma)->bbNC;
	return m;
}
static inline void LLVM_MODULE_SET(CTX ctx, Module *m)
{
	DP(ctx->gma)->bbNC = (knh_BasicBlock_t*) m;
}
static inline Function *LLVM_FUNCTION(CTX ctx)
{
	knh_Array_t *a = DP(ctx->gma)->insts;
	return (Function*)a->ilist[LLVM_IDX_FUNCTION];
}
static inline BasicBlock *LLVM_BB(CTX ctx)
{
	knh_Array_t *a = DP(ctx->gma)->insts;
	return (BasicBlock*)a->ilist[LLVM_IDX_BB];
}
static inline IRBuilder<> *LLVM_BUILDER(CTX ctx)
{
	knh_Array_t *a = DP(ctx->gma)->insts;
	return (IRBuilder<>*)a->ilist[LLVM_IDX_BUILDER];
}
static inline std::vector<label_stack*> *LLVM_BBSTACK(CTX ctx)
{
	knh_Array_t *a = DP(ctx->gma)->insts;
	return (std::vector<label_stack*> *)a->ilist[LLVM_IDX_LABELSTACK];
}

static void PUSH_LABEL(CTX ctx, struct label_stack *l)
{
	std::vector<label_stack *> *bbstack = LLVM_BBSTACK(ctx);
	bbstack->push_back(l);
}

static void POP_LABEL(CTX ctx)
{
	std::vector<label_stack *> *bbstack = LLVM_BBSTACK(ctx);
	bbstack->back();
	bbstack->pop_back();
}

#define NC_(sfpidx)    (((sfpidx) * 2) + 1)
#define OC_(sfpidx)    ((sfpidx) * 2)
#define TC_(type, i) ((IS_Tunbox(type))?(NC_(i)):(OC_(i)))

#define SFP_(sfpidx)   ((sfpidx) * 2)

#define RIX_(rix)      rix

/* ------------------------------------------------------------------------ */
/* [Gamma] */

static Value *getctx(CTX ctx)
{
		Function::arg_iterator args = LLVM_FUNCTION(ctx)->arg_begin();
		return args;
}
static Value *getsfp(CTX ctx)
{
		Function::arg_iterator args = LLVM_FUNCTION(ctx)->arg_begin();
		args++;/* ctx */
		return args;
}
static Value *VNAME_(Value *v, const char *name)
{
	v->setName(name);
	return v;
}

static Value *create_loadsfp(CTX ctx, IRBuilder<> *builder, Value *v, knh_type_t type, int idx0);

#define LLVM_CONTEXT() (llvm::getGlobalContext())
#define LLVMTYPE_Void  (Type::getVoidTy(LLVM_CONTEXT()))
#define LLVMTYPE_Int   (Type::getInt64Ty(LLVM_CONTEXT()))
#define LLVMTYPE_Bool  (Type::getInt64Ty(LLVM_CONTEXT()))
#define LLVMTYPE_Float (Type::getDoubleTy(LLVM_CONTEXT()))
static const Type *LLVMTYPE_ObjectField = NULL;
static const Type *LLVMTYPE_Object = NULL;
static const Type *LLVMTYPE_Array = NULL;
static const Type *LLVMTYPE_Method = NULL;
static const Type *LLVMTYPE_context = NULL;
static const Type *LLVMTYPE_fcall = NULL;
static const Type *LLVMTYPE_checkin = NULL;
static const Type *LLVMTYPE_checkout = NULL;
static const Type *LLVMTYPE_sfp   = NULL;
static const Type *LLVMTYPE_itr   = NULL;
static const Type *LLVMTYPE_Iterator = NULL;

static void ValueStack_set(CTX ctx, int index, Value *v);
static Value *ValueStack_get(CTX ctx, int index)
{
	knh_Array_t *lstacks = DP(ctx->gma)->lstacks;
	knh_sfp_t lsfp = {};
	index = index + (-1 * K_RTNIDX);
	lsfp.a = lstacks;
	lstacks->api->get(ctx, &lsfp, index, 0);
	return (Value*) lsfp.ndata;
}

static Value *ValueStack_load(CTX ctx, int index, knh_class_t cid)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *v = create_loadsfp(ctx, builder, getsfp(ctx), cid, index);
	v = builder->CreateLoad(v);
	return v;
}

static Value *ValueStack_load_set(CTX ctx, int index, knh_class_t cid)
{
	Value *v = ValueStack_load(ctx, index, cid);
	ValueStack_set(ctx, index, v);
	return v;
}

static Value *ValueStack_get_or_load(CTX ctx, int index, knh_class_t cid)
{
	Value *v = ValueStack_get(ctx, index);
	if (!v) {
		v = ValueStack_load(ctx, index, cid);
	}
	return v;
}

#define knh_Array_capacity(a) ((a)->dim->capacity)
static void ValueStack_set(CTX ctx, int index, Value *v)
{
	knh_Array_t *lstacks = DP(ctx->gma)->lstacks;
	knh_sfp_t lsfp = {};
	index = index + (-1 * K_RTNIDX);
	if (v->getType() == Type::getInt1Ty(LLVM_CONTEXT())) {
		v = LLVM_BUILDER(ctx)->CreateZExt(v, LLVMTYPE_Int);
	}
	if ((int)knh_Array_capacity(lstacks) < index) {
		knh_Array_grow(ctx, lstacks, index, index);
	}
	lsfp.ndata = (knh_ndata_t) v;
	lstacks->api->set(ctx, lstacks, index, &lsfp);
}

static knh_Array_t *ValueStack_copy(CTX ctx, knh_Array_t *a)
{
	const knh_ClassTBL_t *ct = O_cTBL(a);
	knh_Array_t *newlstacks = (knh_Array_t*) new_hObject_(ctx, ct);
	ct->ospi->initcopy(ctx, UPCAST(newlstacks), UPCAST(a));
	return newlstacks;
}


#define TT_isSFPIDX(tk)   (TT_(tk) == TT_LOCAL || TT_(tk) == TT_FUNCVAR)
#define Token_index(tk)   Token_index_(ctx, tk)
static int Token_index_(CTX ctx, knh_Token_t *tk)
{
	return (int)(tk)->index + ((TT_(tk) == TT_LOCAL) ? DP(ctx->gma)->ebpidx : 0);
}

static void ASM_BOX2(CTX ctx, knh_type_t reqt, knh_type_t atype, int a)
{
	//knh_class_t cid = CLASS_t(atype);
	//knh_class_t bcid = ClassTBL(cid)->bcid;
	//if(bcid == CLASS_Boolean || bcid == CLASS_Int || bcid == CLASS_Float) {
	//	knh_class_t rcid = ClassTBL(CLASS_t(reqt))->bcid;
	//	if(rcid != bcid && reqt != TYPE_void) {
	//		if(cid == CLASS_Boolean) {
	//			//ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(cid), _bBOX);
	//		}
	//		else if (IS_Tnumbox(reqt)) {
	//			LLVM_TODO("Boxing");
	//			//Object *v = (cid == CLASS_Int) ? UPCAST(KNH_INT0) : UPCAST(KNH_FLOAT0);
	//			//ASM(OSET, OC_(a), v);
	//		}
	//		else {
	//			//ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(cid), _BOX);
	//		}
	//	}
	//}
	//else if(atype == CLASS_Tdynamic && IS_Tnumbox(reqt)) {
	//	//ASM(UNBOX, NC_(a), OC_(a), ClassTBL(reqt));
	//}
	//else if(IS_Tnumbox(atype) && reqt == CLASS_Tdynamic) {
	//	//ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(atype), _OBOX);
	//}
}

static void ASM_UNBOX(CTX ctx, knh_type_t atype, int a)
{
	LLVM_TODO("ASM_UNBOX");
}

static void ASM_MOVL(CTX ctx, knh_type_t reqt, int sfpidx, knh_type_t ltype, int local)
{
	if(sfpidx < DP(ctx->gma)->espidx) {
		Value *v = ValueStack_get(ctx, local);
		ValueStack_set(ctx, sfpidx, v);
	}
}
static int Tn_put(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_type_t reqt, int sfpidx)
{
	knh_Token_t *tk = tkNN(stmt, n);
	if(TT_(tk) == TT_FUNCVAR || TT_(tk) == TT_LOCAL) return Token_index(tk);
	Tn_asm(ctx, stmt, n, reqt, sfpidx);
	return sfpidx;
}

static knh_Token_t* Tn_putTK(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_type_t reqt, int sfpidx)
{
	knh_Token_t *tk = tkNN(stmt, n);
	if(IS_Stmt(tk)) {
		Tn_asm(ctx, stmt, n, reqt, sfpidx);
		DBG_ASSERT(IS_Token(tkNN(stmt, n)));
		return tkNN(stmt, n);
	}
	return tk;
}

static const Type *convert_type(CTX ctx, knh_class_t cid)
{
	switch (cid) {
		case TYPE_void:    return LLVMTYPE_Void;
		case TYPE_Boolean: return LLVMTYPE_Bool;
		case TYPE_Int:     return LLVMTYPE_Int;
		case TYPE_Float:   return LLVMTYPE_Float;
	}
	return LLVMTYPE_Object;
}

static const Type *getLongTy(Module *m)
{
#if defined(SIZEOF_VOIDP) && (SIZEOF_VOIDP == 4)
	return Type::getInt32Ty(m->getContext());
#else
	return Type::getInt64Ty(m->getContext());
#endif
}
static const Type *getShortTy(Module *m)
{
#if defined(SIZEOF_VOIDP) && (SIZEOF_VOIDP == 4)
	return Type::getInt16Ty(m->getContext());
#else
	return Type::getInt32Ty(m->getContext());
#endif
}

#define LLVMBool(v)   (ConstantInt::get(LLVMTYPE_Bool, (v)))
#define LLVMInt(v)    (ConstantInt::get(LLVMTYPE_Int, (v)))
#define LLVMFloat(v)  (ConstantFP::get(LLVMTYPE_Float, (v)))
#define LLVMValue(T, v) LLVMValue_(ctx, T, (knh_intptr_t)v)
static Value *LLVMValue_(CTX ctx, const Type *type, knh_intptr_t ptr)
{
	Module *m = LLVM_MODULE(ctx);
	Value *v = ConstantInt::get(getLongTy(m), ptr);
	return LLVM_BUILDER(ctx)->CreateIntToPtr(v, type);
}

static void asm_nulval(CTX ctx, int a, knh_class_t cid)
{
	knh_Object_t *o = KNH_NULVAL(cid);
	Value *v = LLVMValue(LLVMTYPE_Object, o);
	ValueStack_set(ctx, a, v);
}

static void param_setCtxSfp(CTX ctx, std::vector<Value*> &params, int sfpidx);

static int _BOX_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	knh_class_t cid = Tn_cid(stmt, 0);
	Tn_asm(ctx, stmt, 0, cid, sfpidx);
	DBG_ASSERT(IS_Tunbox(cid));
	
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Module *m = LLVM_MODULE(ctx);

	std::vector<const Type*>args_list;
	args_list.push_back(LLVMTYPE_context);
	args_list.push_back(LLVMTYPE_sfp);
	args_list.push_back(LLVMTYPE_Int); /* sfpidx */
	args_list.push_back(LLVMTYPE_Int); /* knh_ClassTBL_t */
	FunctionType* fnTy = FunctionType::get(LLVMTYPE_Void, args_list, false);
	Function *func = cast<Function>(m->getOrInsertFunction("BOX_llvm", fnTy));

	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, sfpidx);
	params.push_back(LLVMInt(0));
	params.push_back(LLVMInt((knh_int_t)ClassTBL(cid)));

	Value *val = ValueStack_get(ctx, sfpidx);
	Value *sftsfp = builder->CreateConstInBoundsGEP1_32(getsfp(ctx), sfpidx);
	sftsfp = builder->CreateStructGEP(sftsfp, 1);
	sftsfp = builder->CreateBitCast(sftsfp, PointerType::get(val->getType(), 0));
	builder->CreateStore(val, sftsfp);

	builder->CreateCall(func, params.begin(), params.end());
	ValueStack_load_set(ctx, sfpidx, reqt);
	return 0;
}


static void ASM_SMOVx(CTX ctx, knh_type_t atype, int a, knh_type_t btype, knh_sfx_t bx)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *v = ValueStack_get_or_load(ctx, bx.i, CLASS_Object);
	const Type *ty = convert_type(ctx, btype);
	v = builder->CreateBitCast(v, LLVMTYPE_ObjectField, "cast");
	v = builder->CreateStructGEP(v, 1, "gep");
	v = builder->CreateLoad(v, "load");
	v = builder->CreateBitCast(v, PointerType::get(ty, 0), "cast");
	v = builder->CreateConstInBoundsGEP1_32(v, bx.n, "get_");
	v = builder->CreateLoad(v);
	//if(IS_Tunbox(btype)) {
	//	ASM_BOX2(ctx, atype, btype, (a)); /* TODO */
	//}
	//else {
	//	ASM_UNBOX(ctx, btype, a); /* TODO */
	//}

	ValueStack_set(ctx, a, v);
}

static Value *Fset_CTX(CTX ctx, Value *arg_ctx)
{
	LLVM_TODO("SYSVAL ctx");
	return NULL;
}
static Value *GetCTX_IO(CTX ctx, Value *arg_ctx, int idx)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *v = builder->CreateStructGEP(arg_ctx, idx, "gep");
	v = builder->CreateLoad(v, "l1");
	return v;
}
static Value *Fset_CTXIN(CTX ctx, Value *arg_ctx)
{
	return GetCTX_IO(ctx, arg_ctx, 28);
}
static Value *Fset_CTXOUT(CTX ctx, Value *arg_ctx)
{
	return GetCTX_IO(ctx, arg_ctx, 29);
}
static Value *Fset_CTXERR(CTX ctx, Value *arg_ctx)
{
	return GetCTX_IO(ctx, arg_ctx, 30);
}
static Value *Fset_SYS(CTX ctx, Value *arg_ctx)
{
	return LLVM_BUILDER(ctx)->CreateStructGEP(arg_ctx, 3, "gep");
}
static Value *GetSTD_IO(CTX ctx, Value *arg_ctx, int idx)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *v = Fset_SYS(ctx, arg_ctx);
	v = builder->CreateLoad(v, "l1");
	v = builder->CreateStructGEP(v, 1, "gep_");
	return builder->CreateStructGEP(v, idx, "gep");
}
static Value *Fset_STDIN(CTX ctx, Value *arg_ctx)
{
	return GetSTD_IO(ctx, arg_ctx, 3);
}
static Value *Fset_STDOUT(CTX ctx, Value *arg_ctx)
{
	return GetSTD_IO(ctx, arg_ctx, 4);
}
static Value *Fset_STDERR(CTX ctx, Value *arg_ctx)
{
	return GetSTD_IO(ctx, arg_ctx, 5);
}
static Value *Fset_SCRIPT(CTX ctx, Value *arg_ctx)
{
	return LLVM_BUILDER(ctx)->CreateStructGEP(arg_ctx, 4, "gep");
}
typedef Value* (*Fset)(CTX, Value*);
static Fset SYSVAL_LOAD_INSTS[] = {
	Fset_CTX,
	Fset_CTXIN,
	Fset_CTXOUT,
	Fset_CTXERR,
	Fset_STDIN,
	Fset_STDOUT,
	Fset_STDERR,
	Fset_SYS,
	Fset_SCRIPT,
};

static knh_int_t O_int(knh_Object_t *o)
{
	return ((knh_Int_t*)(o))->n.ivalue;
}

static knh_float_t O_float(knh_Object_t *o)
{
	return ((knh_Int_t*)(o))->n.fvalue;
}

static void ASM_SMOV(CTX ctx, knh_type_t atype, int a/*flocal*/, knh_Token_t *tkb)
{
	knh_type_t btype = SP(tkb)->type;
	switch(TT_(tkb)) {
		case TT_ASIS:
			break;
		case TT_NULL/*DEFVAL*/: {
			knh_class_t cid = (tkb)->cid;
			knh_Object_t *o = KNH_NULVAL(cid);
			if(o != ClassTBL(cid)->defnull) {
				/* TODO */
				ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(cid), _NULVAL);
				break;
			}
			KNH_SETv(ctx, (tkb)->data, o);
			goto L_CONST;
		}
		case TT_CID:
			KNH_SETv(ctx, (tkb)->data, new_Type(ctx, (tkb)->cid));
		case TT_CONST: L_CONST:; {
			Object *o = (tkb)->data;
			if(IS_Tunbox(atype)) {
				Value *v = NULL;
				if (IS_Tint(atype))        v = LLVMInt(O_int(o));
				else if (IS_Tfloat(atype)) v = LLVMFloat(O_float(o));
				else if (IS_Tbool(atype))  v = LLVMBool(O_data(o));
				ValueStack_set(ctx, a, v);
			}
			else if(IS_Tnumbox(atype)) {
				Value *v = LLVMValue(LLVMTYPE_Object, o);
				LLVM_TODO("NumBox type");
				ValueStack_set(ctx, a, v);
			}
			else {
				Value *v = LLVMValue(LLVMTYPE_Object, o);
				ValueStack_set(ctx, a, v);
			}
			break;
		}
		case TT_FUNCVAR:
		case TT_LOCAL: {
			int b = Token_index(tkb);
			if(IS_Tunbox(btype)) {
				Value *v = ValueStack_get_or_load(ctx, b, btype);
				ValueStack_set(ctx, a, v);
			}
			else {
				Value *v = ValueStack_get_or_load(ctx, b, btype);
				ValueStack_set(ctx, a, v);
				//ASM(OMOV, OC_(a), OC_(b));
				//if(IS_Tnumbox(btype)) {
				//	if(IS_Tnumbox(atype)) {
				//		ASM(NMOV, NC_(a), NC_(b));
				//	}
				//	else {
				//		ASM(TR, OC_(a), SFP_(b), RIX_(a-b), ClassTBL(atype), _OBOX);
				//	}
				//}
			}
			break;
		}
		case TT_FIELD: {
			knh_sfx_t bx = {0, (tkb)->index};
			if(IS_Token(tkb->token) && TT_isSFPIDX(tkb->token)) {
				bx.i = Token_index(tkb->token);
			}
			ASM_SMOVx(ctx, atype, a, btype, bx);
			break;
		}
		case TT_SCRFIELD: {
			int b = (int)(tkb)->index;
			knh_sfx_t bx = {OC_(DP(ctx->gma)->scridx), (size_t)b};
			ASM_SMOVx(ctx, atype, a, btype, bx);
			break;
		}
		case TT_SYSVAL: {
			size_t sysid = (tkb)->index;
			KNH_ASSERT(sysid < K_SYSVAL_MAX);
			Value *v = SYSVAL_LOAD_INSTS[sysid](ctx, getctx(ctx));
			ValueStack_set(ctx, a, v);
			break;
		}
		case TT_PROPN: {
			ASM(OSET, OC_(a), (tkb)->data);
			if(IS_Tunbox(btype)) {
				ASM(TR, NC_(a), SFP_(a), RIX_(a-a), ClassTBL(CLASS_t(btype)), _NPROP);
			}
			else {
				ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(CLASS_t(btype)), _PROP);
			}
			ASM_BOX2(ctx, atype, btype, a);
			break;
		}
		default: {
			DBG_ABORT("unknown TT=%s", TT__(TT_(tkb)));
		}
	}/*switch*/
}

static void ASM_XMOVx(CTX ctx, knh_type_t atype, knh_sfx_t ax, knh_type_t btype, knh_sfx_t bx)
{
	int espidx = DP(ctx->gma)->espidx;
	if(IS_Tunbox(atype)) {
		if(IS_Tunbox(btype)) {
			ASM(XNMOVx, ax, bx);
		}
		else {
			ASM(OMOVx, NC_(espidx), bx);
			ASM_UNBOX(ctx, atype, espidx);
			ASM(XNMOV, ax, NC_(espidx));
		}
	}
	else {
		DBG_ASSERT(atype == TYPE_dyn || IS_Tnumbox(atype));
		if(IS_Tunbox(btype)) { // dynamic a = b; // int b;
			ASM(NMOVx, NC_(espidx), bx);
			ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(CLASS_t(btype)), _BOX);
			ASM(XMOV, ax, OC_(espidx));
		}
		else {
			ASM(XMOVx, ax, bx);
		}
	}
}

static void ASM_XMOV_local(CTX ctx, IRBuilder<> *builder, knh_class_t ty, knh_sfx_t ax, Value *val)
{
	const Type *ptype = PointerType::get(convert_type(ctx, ty), 0);
	Value *v = ValueStack_get_or_load(ctx, ax.i, CLASS_Object);
	v = builder->CreateBitCast(v, LLVMTYPE_ObjectField, "cast");
	v = builder->CreateStructGEP(v, 1, "oxp");
	v = builder->CreateLoad(v, "load");
	v = builder->CreateBitCast(v, ptype, "v");
	v = builder->CreateConstInBoundsGEP1_32(v, ax.n, "p");
	builder->CreateStore(val, v, false);
}

static void ASM_XMOV(CTX ctx, knh_type_t atype, int a, size_t an, knh_Token_t *tkb)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	knh_sfx_t ax = {a, an};
	knh_type_t btype = SP(tkb)->type;
	long espidx = -1;
	DBG_ASSERT(DP(ctx->gma)->espidx != -1);
	switch(TT_(tkb)) {
		case TT_NULL/*DEFVAL*/: {
			knh_class_t cid = (tkb)->cid;
			knh_Object_t *v = KNH_NULVAL(cid);
			if(v != ClassTBL(cid)->defnull) {
				espidx = DP(ctx->gma)->espidx;
				ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(cid), _NULVAL);
				break;
			}
			KNH_SETv(ctx, (tkb)->data, v);
			goto L_CONST;
		}
		case TT_CID:
			KNH_SETv(ctx, (tkb)->data, new_Type(ctx, (tkb)->cid));
		case TT_CONST: L_CONST:; {
			Object *o = (tkb)->data;
			Value *vdata;
			if (IS_Tfloat(atype))     vdata = LLVMFloat(O_float(o));
			else if (IS_Tint(atype))  vdata = LLVMInt(O_int(o));
			else if (IS_Tbool(atype)) vdata = LLVMBool(O_data(o));
			else                      vdata = LLVMValue(LLVMTYPE_Object, o);

			ASM_XMOV_local(ctx, builder, atype, ax, vdata);
			break;
		}
		case TT_FUNCVAR:
		case TT_LOCAL: {
			int b = Token_index(tkb);
			Value *v = ValueStack_get(ctx, b);
			//ASM_BOX2(ctx, atype, btype, b);
			ASM_XMOV_local(ctx, builder, atype, ax, v);
			break;
		}
		case TT_FIELD: {
			size_t b = (tkb)->index;
			knh_sfx_t bx = {0, b};
			if(IS_Token(tkb->token) && TT_isSFPIDX(tkb->token)) {
				bx.i = Token_index(tkb->token);
			}
			ASM_XMOVx(ctx, atype, ax, btype, bx);
			break;
		}
		case TT_SCRFIELD: {
			size_t b = (tkb)->index;
			knh_sfx_t bx = {OC_(DP(ctx->gma)->scridx), b};
			ASM_XMOVx(ctx, atype, ax, btype, bx);
			break;
		}
		case TT_SYSVAL: {
			size_t sysid = (tkb)->index;
			Value *v = SYSVAL_LOAD_INSTS[sysid](ctx, getctx(ctx));
			ValueStack_set(ctx, espidx, v);
			break;
		}
		case TT_PROPN: {
			espidx = DP(ctx->gma)->espidx;
			ASM(OSET, OC_(espidx), (tkb)->data);
			if(IS_Tunbox(atype)) {
				ASM(TR, NC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(CLASS_t(atype)), _NPROP);
			}
			else {
				ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(CLASS_t(atype)), _PROP);
			}
			ASM_BOX2(ctx, atype, btype, espidx);
			break;
		}
		default: {
			DBG_ABORT("unknown TT=%d", TT_(tkb));
		}
	}/*switch*/
	if(espidx != -1) {
		if(IS_Tunbox(atype)) {
			ASM(XNMOV, ax, NC_(espidx));
		}
		else {
			ASM(XMOV, ax, OC_(espidx));
		}
	}
}

static void ASM_MOV(CTX ctx, knh_Token_t *tka, knh_Token_t *tkb)
{
	DBG_ASSERT(Token_isTyped(tka));
	DBG_ASSERT(IS_Token(tkb));
	DBG_ASSERT(Token_isTyped(tkb));
	knh_type_t atype = SP(tka)->type;
	if(TT_(tka) == TT_LOCAL || TT_(tka) == TT_FUNCVAR) {
		ASM_SMOV(ctx, atype, Token_index(tka), tkb);
	}
	else {
		DBG_ASSERT(TT_(tka) == TT_FIELD);
		int an = (int)(tka)->index;
		ASM_XMOV(ctx, atype, 0, an, tkb);
	}
}

/* ------------------------------------------------------------------------ */
/* [EXPR] */
static knh_int_t Tn_int(knh_Stmt_t *stmt, size_t n)
{
	knh_Token_t *tk = tkNN(stmt, n);
	DBG_ASSERT(TT_(tk) == TT_CONST);
	return ((tk)->num)->n.ivalue;
}

static knh_float_t Tn_float(knh_Stmt_t *stmt, size_t n)
{
	knh_Token_t *tk = tkNN(stmt, n);
	DBG_ASSERT(TT_(tk) == TT_CONST);
	return ((tk)->num)->n.fvalue;
}

static int _CALL_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx);
static knh_opcode_t OPCODE_imn(knh_methodn_t mn, int diff)
{
	switch(mn) {
	case MN_opNEG: return OPCODE_iNEG;
	case MN_opADD: return OPCODE_iADD + diff;
	case MN_opSUB: return OPCODE_iSUB + diff;
	case MN_opMUL: return OPCODE_iMUL + diff;
	case MN_opDIV: return OPCODE_iDIV+ diff;
	case MN_opMOD: return OPCODE_iMOD+ diff;
	case MN_opEQ:  return OPCODE_iEQ+ diff;
	case MN_opNOTEQ: return OPCODE_iNEQ+ diff;
	case MN_opLT:  return OPCODE_iLT+ diff;
	case MN_opLTE: return OPCODE_iLTE+ diff;
	case MN_opGT:  return OPCODE_iGT+ diff;
	case MN_opGTE: return OPCODE_iGTE+ diff;
#ifdef OPCODE_iAND
	case MN_opLAND :  return OPCODE_iAND  + diff;
	case MN_opLOR  :  return OPCODE_iOR   + diff;
	case MN_opLXOR :  return OPCODE_iXOR  + diff;
	case MN_opLSFT:  return OPCODE_iLSFT  + diff;
	case MN_opRSFT:  return OPCODE_iRSFT  + diff;
#endif
	}
	return OPCODE_NOP;
}

static knh_opcode_t OPCODE_fmn(knh_methodn_t mn, int diff)
{
	switch(mn) {
	case MN_opNEG: return OPCODE_fNEG;
	case MN_opADD: return OPCODE_fADD + diff;
	case MN_opSUB: return OPCODE_fSUB + diff;
	case MN_opMUL: return OPCODE_fMUL + diff;
	case MN_opDIV: return OPCODE_fDIV + diff;
	case MN_opEQ:  return OPCODE_fEQ + diff;
	case MN_opNOTEQ: return OPCODE_fNEQ + diff;
	case MN_opLT:  return OPCODE_fLT + diff;
	case MN_opLTE: return OPCODE_fLTE + diff;
	case MN_opGT:  return OPCODE_fGT + diff;
	case MN_opGTE: return OPCODE_fGTE + diff;
	}
	return OPCODE_NOP;
}

static knh_bool_t OPR_hasCONST(CTX ctx, knh_Stmt_t *stmt, knh_methodn_t *mn, int swap)
{
	int isCONST = (TT_(tmNN(stmt, 2)) == TT_CONST);
	if(swap == 1 && TT_(tmNN(stmt, 1)) == TT_CONST) {
		knh_methodn_t newmn = *mn;
		knh_Stmt_swap(ctx, stmt, 1, 2);
		if(*mn == MN_opLT) newmn = MN_opGT;  /* 1 < n ==> n > 1 */
		else if(*mn == MN_opLTE) newmn = MN_opGTE; /* 1 <= n => n >= 1 */
		else if(*mn == MN_opGT)  newmn = MN_opLT;
		else if(*mn == MN_opGTE) newmn = MN_opLTE;
		//DBG_P("swap %s ==> %s", MN__(*mn), MN__(newmn));
		*mn = newmn;
		isCONST = 1;
	}
	return isCONST;
}

#define VSET(ctx, local, create) ValueStack_set(ctx, local, LLVM_BUILDER(ctx)->create)
static int ASMiop(CTX ctx, knh_methodn_t mn, Value *va, Value *vb, int local)
{
	switch(mn) {
	case MN_opNEG  : VSET(ctx, local, CreateNeg(va, "neg"));break;
	case MN_opADD  : VSET(ctx, local, CreateAdd(va, vb, "add"));break;
	case MN_opSUB  : VSET(ctx, local, CreateSub(va, vb, "sub"));break;
	case MN_opMUL  : VSET(ctx, local, CreateMul(va, vb, "mul"));break;
	case MN_opDIV  : VSET(ctx, local, CreateSDiv(va, vb, "div"));break;
	case MN_opMOD  : VSET(ctx, local, CreateSRem(va, vb, "mod"));break;
	case MN_opEQ   : VSET(ctx, local, CreateICmpEQ(va, vb, "eq"));break;
	case MN_opNOTEQ: VSET(ctx, local, CreateICmpNE(va, vb, "ne"));break;
	case MN_opLT   : VSET(ctx, local, CreateICmpSLT(va, vb, "lt"));break;
	case MN_opLTE  : VSET(ctx, local, CreateICmpSLE(va, vb, "le"));break;
	case MN_opGT   : VSET(ctx, local, CreateICmpSGT(va, vb, "gt"));break;
	case MN_opGTE  : VSET(ctx, local, CreateICmpSGE(va, vb, "ge"));break;
#ifdef OPCODE_iAND
	case MN_opLAND : VSET(ctx, local, CreateAnd(va, vb, "and"));break;
	case MN_opLOR  : VSET(ctx, local, CreateOr(va, vb, "or"));break;
	case MN_opLXOR : VSET(ctx, local, CreateXor(va, vb, "xor"));break;
	case MN_opLSFT : VSET(ctx, local, CreateShl(va, vb, "lshr"));break;
	case MN_opRSFT : VSET(ctx, local, CreateAShr(va, vb, "rshr"));break;
#endif
	}
	return 1;
}
static int ASMfop(CTX ctx, knh_methodn_t mn, Value *va, Value *vb, int local)
{
	switch(mn) {
	case MN_opNEG  : VSET(ctx, local, CreateFNeg   (va, "neg"));break;
	case MN_opADD  : VSET(ctx, local, CreateFAdd   (va, vb, "add"));break;
	case MN_opSUB  : VSET(ctx, local, CreateFSub   (va, vb, "sub"));break;
	case MN_opMUL  : VSET(ctx, local, CreateFMul   (va, vb, "mul"));break;
	case MN_opDIV  : VSET(ctx, local, CreateFDiv   (va, vb, "div"));break;
	case MN_opEQ   : VSET(ctx, local, CreateFCmpOEQ(va, vb, "eq"));break;
	case MN_opNOTEQ: VSET(ctx, local, CreateFCmpONE(va, vb, "ne"));break;
	case MN_opLT   : VSET(ctx, local, CreateFCmpOLT(va, vb, "lt"));break;
	case MN_opLTE  : VSET(ctx, local, CreateFCmpOLE(va, vb, "le"));break;
	case MN_opGT   : VSET(ctx, local, CreateFCmpOGT(va, vb, "gt"));break;
	case MN_opGTE  : VSET(ctx, local, CreateFCmpOGE(va, vb, "ge"));break;
	}
	return 1;
}
static int _OPR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int local = ASML(sfpidx);
	knh_Method_t *mtd = (tkNN(stmt, 0))->mtd;
	if (IS_NULL(mtd)) return 0;
	knh_methodn_t mn = (mtd)->mn;
	knh_class_t cid = CLASS_t(SP(tkNN(stmt, 1))->type);
	knh_opcode_t opcode;
	if(cid == CLASS_Boolean && mn == MN_opNOT) {
		int a = Tn_put(ctx, stmt, 1, TYPE_Boolean, local + 1);
		Value *va = ValueStack_get(ctx, a);
		va = LLVM_BUILDER(ctx)->CreateNot(va, "not");
		ValueStack_set(ctx, sfpidx, va);
		return 1;
	}
	if (cid == CLASS_Int && ((opcode = OPCODE_imn(mn, 0)) != OPCODE_NOP)) {
		int swap = 1;
		if (mn == MN_opNEG) {
			int a = Tn_put(ctx, stmt, 1, TYPE_Int, local + 1);
			Value *va = ValueStack_get(ctx, a);
			ASMiop(ctx, MN_opNEG, va, NULL, sfpidx);
			return 1;
		}
		if (mn == MN_opSUB || mn == MN_opDIV || mn == MN_opMOD ||
				mn == MN_opLSFT || mn == MN_opRSFT) swap =0;
		if (OPR_hasCONST(ctx, stmt, &mn, swap)) {
			int a = Tn_put(ctx, stmt, 1, TYPE_Int, local + 1);
			knh_int_t b = Tn_int(stmt, 2);
			if (b == 0 && mn == MN_opDIV) {
				b = 1;
				WarningDividedByZero(ctx);
			}
			Value *va = ValueStack_get(ctx, a);
			Value *vb = LLVMInt(b);
			ASMiop(ctx, mn, va, vb, sfpidx);
		}
		else {
			int a = Tn_put(ctx, stmt, 1, TYPE_Int, local + 1);
			int b = Tn_put(ctx, stmt, 2, TYPE_Int, local + 2);
			Value *va = ValueStack_get(ctx, a);
			Value *vb = ValueStack_get(ctx, b);
			ASMiop(ctx, mn, va, vb, sfpidx);
		}
		return 1;
	}
	if (cid == CLASS_Float && ((opcode = OPCODE_fmn(mn, 0)) != OPCODE_NOP)) {
		int swap = 1;
		if (mn == MN_opNEG) {
			int a = Tn_put(ctx, stmt, 1, TYPE_Float, local + 1);
			Value *va = ValueStack_get(ctx, a);
			ASMfop(ctx, MN_opNEG, va, NULL, sfpidx);
			return 1;
		}
		if (mn == MN_opSUB || mn == MN_opDIV || mn == MN_opMOD) swap =0;
		if (OPR_hasCONST(ctx, stmt, &mn, swap)) {
			int a = Tn_put(ctx, stmt, 1, TYPE_Float, local + 1);
			knh_float_t b = Tn_float(stmt, 2);
			if (b == K_FLOAT_ZERO && mn == MN_opDIV) {
				b = K_FLOAT_ONE;
				WarningDividedByZero(ctx);
			}
			Value *va = ValueStack_get(ctx, a);
			Value *vb = LLVMFloat(b);
			ASMfop(ctx, mn, va, vb, sfpidx);
		}
		else {
			int a = Tn_put(ctx, stmt, 1, TYPE_Float, local + 1);
			int b = Tn_put(ctx, stmt, 2, TYPE_Float, local + 2);
			Value *va = ValueStack_get(ctx, a);
			Value *vb = ValueStack_get(ctx, b);
			ASMfop(ctx, mn, va, vb, sfpidx);
		}
		return 1;
	}
	_CALL_asm(ctx, stmt, reqt, sfpidx);
	return 0;
}

/* ------------------------------------------------------------------------ */
/* CALL */

static knh_type_t Tn_ptype(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_class_t cid, knh_Method_t *mtd)
{
	if(!IS_Method(mtd)) {
		return TYPE_dyn;  // boxing
	}
	if(n == 1) { // base
		if(IS_Tunbox(cid) && cid != (mtd)->cid) {
			/* Object, Number, dynamic */
			cid = (mtd)->cid;
		}
		DBG_(
		if(cid != (mtd)->cid) {
			DBG_P("** WATCH OUT ** mtd_cid=%s, (mtd)->cid=%s", CLASS__(cid), CLASS__((mtd)->cid));
		});
		return cid;
	}
	else {
		knh_type_t ptype = knh_ParamArray_getptype(DP(mtd)->mp, n - 2);
		return knh_type_tocid(ctx, ptype, cid);
	}
}
static int CALLPARAMs_asm(CTX ctx, knh_Stmt_t *stmt, size_t s, int local, knh_class_t cid, knh_Method_t *mtd)
{
	size_t i;
	if(s == 1 && Method_isStatic(mtd))
		// ignoring static caller, like Script
		s = 2;
	if(DP(stmt)->size + DP(ctx->gma)->espidx > 32) {
		LLVM_TODO("check stack");
	}
	Value *arg_sfp = getsfp(ctx);
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	for(i = s; i < DP(stmt)->size; i++) {
		knh_type_t reqt = Tn_ptype(ctx, stmt, i, cid, mtd);
		int a = local + i + (K_CALLDELTA-1);
		Tn_asm(ctx, stmt, i, reqt, a);
		Value *v = ValueStack_get_or_load(ctx, a, cid);
		const Type *ty = v->getType();
		if (reqt == TYPE_dyn && ty == LLVMTYPE_Int) {
			reqt = TYPE_Int;
		} else if (reqt == TYPE_dyn && ty == LLVMTYPE_Bool) {
			reqt = TYPE_Boolean;
		}

		Value *ptr = create_loadsfp(ctx, builder, arg_sfp, reqt, a);
		builder->CreateStore(v, ptr, false/*isVolatile*/);
	}
	return 1;
}

static void asm_shift_esp(CTX ctx, size_t idx)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *vsfp, *vesp;
	vesp = builder->CreateStructGEP(getctx(ctx), 7, "gep"); /* esp */
	vsfp = builder->CreateConstInBoundsGEP1_32(getsfp(ctx), idx);
	builder->CreateStore(vsfp, vesp, false);
}

static void _CALL(CTX ctx, knh_type_t reqt, int sfpidx, knh_type_t rtype, knh_Method_t *mtd, int isStatic, size_t argc)
{
	int thisidx = sfpidx + K_CALLDELTA;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	DBG_ASSERT(IS_Method(mtd));
	KNH_ASSERT(sfpidx >= DP(ctx->gma)->espidx);
	if(Method_isFinal(mtd) || isStatic) {
		int retIdx;
		knh_class_t retTy;
		Value *vfunc, *ret_v;
		std::vector<Value*> params;

		param_setCtxSfp(ctx, params, thisidx);
		params.push_back(LLVMInt(K_RTNIDX));
		asm_shift_esp(ctx, argc+1+thisidx);
		if(Method_isKonohaCode(mtd) || DP(ctx->gma)->mtd == mtd) {
			vfunc = LLVMValue(LLVMTYPE_Method, mtd);
			vfunc = builder->CreateStructGEP(vfunc, 4, "mtdgep");
			vfunc = builder->CreateLoad(vfunc, "fcall");
			retIdx = sfpidx;
		}
		else {
			knh_Fmethod func = mtd->fcall_1;
			vfunc = LLVMValue(LLVMTYPE_fcall, func);
			retIdx = thisidx+K_RTNIDX;
		}
		builder->CreateCall(vfunc, params.begin(), params.end());

		retTy = knh_ParamArray_rtype(DP(mtd)->mp);
		if(retTy != TYPE_void){
			Value *ptr = create_loadsfp(ctx, builder, getsfp(ctx), retTy, thisidx+K_RTNIDX);
			ret_v = builder->CreateLoad(ptr, "ret_v");
			ValueStack_set(ctx, retIdx, ret_v);
		}
	}
	else {
		LLVM_TODO("LOADMTD");
	}
}

static BasicBlock *BB_CREATE(CTX ctx, const char *bbName)
{
	Module *m = LLVM_MODULE(ctx);
	LLVMContext &llvmctx = m->getContext();
	Function *f = LLVM_FUNCTION(ctx);
	return BasicBlock::Create(llvmctx, bbName, f);
}

static void check_array_boundary(CTX ctx, Value *a, Value *n)
{
	Module *m = LLVM_MODULE(ctx);
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bb1 = BB_CREATE(ctx, "OutOfIDX");
	BasicBlock *bb2 = BB_CREATE(ctx, "bb");
	Value *size = builder->CreateStructGEP(a, 2, "size");
	size = builder->CreateLoad(size);

	Value *cond = builder->CreateICmpSLE(size, n, "le");
	builder->CreateCondBr(cond, bb1, bb2);
	builder->SetInsertPoint(bb1);

	/* throw out of index */
	std::vector<Value*> params;

	std::vector<const Type*> argsTy;
	argsTy.push_back(LLVMTYPE_context);
	argsTy.push_back(LLVMTYPE_sfp);
	argsTy.push_back(getLongTy(m));
	argsTy.push_back(getLongTy(m));

	param_setCtxSfp(ctx, params, 0);
	params.push_back(n);
	params.push_back(size);
	FunctionType *fnTy = FunctionType::get(LLVMTYPE_Void, argsTy, false);
	Function *f = cast<Function>(m->getOrInsertFunction("THROW_OutOfRange", fnTy));
	builder->CreateCall(f, params.begin(), params.end());
	builder->CreateBr(bb2);
	builder->SetInsertPoint(bb2);
}

static Value *ASM_ARRAY_N(CTX ctx, int a, knh_class_t cid, int sfpidx, Value *n)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *vobj = ValueStack_get(ctx, a);
	const Type *type = convert_type(ctx, C_p1(cid));
	const Type *ptype = PointerType::get(type, 0);

	Value *array = builder->CreateBitCast(vobj, LLVMTYPE_Array, "array");
	check_array_boundary(ctx, array, n);
	Value *lptr = builder->CreateStructGEP(array, 1, "listptr");
	Value *list = builder->CreateLoad(lptr, "list");
	list = builder->CreateBitCast(list, ptype, "cast");
	Value *vptr = builder->CreateInBoundsGEP(list, n, "vptr");
	return vptr;
}
static void ASM_ARRAY_GET(CTX ctx, int a, knh_class_t cid, int sfpidx, Value *n)
{
	Value *vptr = ASM_ARRAY_N(ctx, a, cid, sfpidx, n);
	Value *v = LLVM_BUILDER(ctx)->CreateLoad(vptr, "v");
	ValueStack_set(ctx, sfpidx, v);
}
static void ASM_ARRAY_SET(CTX ctx, int a, knh_class_t cid, int sfpidx, Value *n, Value *v)
{
	Value *vptr = ASM_ARRAY_N(ctx, a, cid, sfpidx, n);
	LLVM_BUILDER(ctx)->CreateStore(v, vptr, false);
}

static void ASM_Object_checkNULL(CTX ctx, int sfpidx, int a, int isNULL)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *idx[] = {
				ConstantInt::get(Type::getInt64Ty(LLVM_CONTEXT()), 0),
				ConstantInt::get(Type::getInt32Ty(LLVM_CONTEXT()), 0),
				ConstantInt::get(Type::getInt32Ty(LLVM_CONTEXT()), 0)
	};
	SmallVector<Value*, 3> idxs(idx, idx+3);
	Value *vflg = LLVMInt(1);
	Value *v = ValueStack_get(ctx, a);
	v = builder->CreateInBoundsGEP(v, idxs.begin(), idxs.end(), "flg");
	v = builder->CreateLoad(v);
	v = builder->CreateLShr(v, LLVMInt(1));
	v = builder->CreateAnd(v, vflg);
	if (!isNULL) {
		v = builder->CreateXor(v, LLVMInt(1));
	}
	v = builder->CreateTrunc(v, LLVMTYPE_Bool);
	ValueStack_set(ctx, sfpidx, v);
}
static int _CALL_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int local = ASML(sfpidx);
	knh_Token_t *tkMTD = tkNN(stmt, 0);
	knh_Method_t *mtd = (tkMTD)->mtd;
	knh_class_t cid = Tn_cid(stmt, 1);
	if(!IS_Method(mtd)) {
		LLVM_TODO("LOADMTD");
		return 0;
	}
	knh_class_t mtd_cid = (mtd)->cid;
	knh_methodn_t mtd_mn = (mtd)->mn;
	if(mtd_cid == CLASS_Array) {
		if (mtd_mn == MN_get) {
			int a = Tn_put(ctx, stmt, 1, cid, local + 1);
			if(Tn_isCONST(stmt, 2)) {
				knh_intptr_t n = (knh_intptr_t)Tn_int(stmt, 2);
				if(n < 0) {
					goto L_USECALL;
				}
				ASM_ARRAY_GET(ctx, a, cid, sfpidx, LLVMInt(n));
			} else {
				int n = Tn_put(ctx, stmt, 2, TYPE_Int, local + 2);
				ASM_ARRAY_GET(ctx, a, cid, sfpidx, ValueStack_get(ctx, n));
			}
			return 0;
		}
		else if (mtd_mn == MN_set) {
			int a = Tn_put(ctx, stmt, 1, cid, local + 1);
			knh_type_t ptype = knh_Method_ptype(ctx, mtd, cid, 1);
			int v = Tn_put(ctx, stmt, 3, ptype, local + 3);
			Value *value = ValueStack_get(ctx, v);
			if(Tn_isCONST(stmt, 2)){
				knh_intptr_t n = (knh_intptr_t)Tn_int(stmt, 2);
				if(n < 0) {
					goto L_USECALL;
				}
				ASM_ARRAY_SET(ctx, a, cid, sfpidx, LLVMInt(n), value);
			}
			else {
				int n = Tn_put(ctx, stmt, 2, TYPE_Int, local + 2);
				ASM_ARRAY_SET(ctx, a, cid, sfpidx, ValueStack_get(ctx, n), value);
			}
			return 0;
		}
	}
#if defined(OPCODE_BGETIDX)
	if(mtd_cid == CLASS_Bytes) {
		LLVM_TODO("CALL Bytes get/set");
	}
#endif
#ifdef OPCODE_bNUL
	if(mtd_cid == CLASS_Object) {
		if (mtd_mn == MN_isNull) {
			int a = Tn_put(ctx, stmt, 1, cid, local + 1);
			ASM_Object_checkNULL(ctx, sfpidx, a, 1/*isNULL*/);
			return 0;
		}
		else if (mtd_mn == MN_isNotNull) {
			int a = Tn_put(ctx, stmt, 1, cid, local + 1);
			ASM_Object_checkNULL(ctx, sfpidx, a, 0/*isNotNULL*/);
			return 0;
		}
	}
#endif
	{
		knh_index_t deltaidx = knh_Method_indexOfGetterField(mtd);
		if(deltaidx != -1) {
			int b = Tn_put(ctx, stmt, 1, mtd_cid, local + 1);
			knh_type_t type = knh_ParamArray_rtype(DP(mtd)->mp);
			knh_sfx_t bx = {b, deltaidx};
			ASM_SMOVx(ctx, reqt, sfpidx, type, bx);
			return 0;
		}
		deltaidx = knh_Method_indexOfSetterField(mtd);
		if(deltaidx != -1) {
			int b = Tn_put(ctx, stmt, 1, mtd_cid, local + 1);
			knh_type_t reqt2 = knh_Method_ptype(ctx, mtd, cid, 0);
			knh_Token_t *tkV = Tn_putTK(ctx, stmt, 2, reqt, local + 2);
			ASM_XMOV(ctx, reqt2, b, deltaidx, tkV);
			if(reqt != TYPE_void) {
				ASM_SMOV(ctx, reqt, sfpidx, tkV);
			}
			return 0;
		}
	}
	L_USECALL:;
	{
		if(CALLPARAMs_asm(ctx, stmt, 1, local, cid, mtd)) {
			knh_type_t rtype = knh_type_tocid(ctx, knh_ParamArray_rtype(DP(mtd)->mp), cid);
			int isStatic = Method_isStatic(mtd);
			_CALL(ctx, reqt, local, rtype, mtd, isStatic, DP(stmt)->size - 2);
			ASM_MOVL(ctx, reqt, sfpidx, SP(stmt)->type, local);
		}
	}

	return 0;
}

static int _FUNCCALL_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	LLVM_TODO("FUNCCALL");
	return 0;
}

static int _EXPR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx);

static int _CALL1_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	if(IS_Stmt(DP(stmt)->stmtPOST)) {  /* a++ */
		int local = ASML(sfpidx);
		Tn_asm(ctx, stmt, 0, reqt, local);
		_EXPR_asm(ctx, DP(stmt)->stmtPOST, reqt, local+1);
		ASM_MOVL(ctx, reqt, sfpidx, SP(stmt)->type, local);
	}
	else {
		Tn_asm(ctx, stmt, 0, reqt, sfpidx);
	}
	return 0;
}

static void ASM_TR_NEW(CTX ctx, int thisidx, int sfpidx, knh_class_t cid)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	std::vector<const Type*> argsTy;
	argsTy.push_back(LLVMTYPE_context);
	argsTy.push_back(LLVMTYPE_sfp);
	argsTy.push_back(LLVMTYPE_Int);
	argsTy.push_back(LLVMTYPE_Int);
	FunctionType *fnTy = FunctionType::get(LLVMTYPE_Void, argsTy, false);
	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, thisidx);
	params.push_back(LLVMInt(RIX_(sfpidx-thisidx)));
	params.push_back(LLVMInt((knh_int_t)ClassTBL(cid)));

	Function *func = cast<Function>(LLVM_MODULE(ctx)->getOrInsertFunction("TR_NEW", fnTy));
	builder->CreateCall(func, params.begin(), params.end());

	 ValueStack_load_set(ctx, sfpidx, cid);
}

static int _NEW_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int local = ASML(sfpidx), thisidx = local + K_CALLDELTA;
	knh_Method_t *mtd = (tkNN(stmt, 0))->mtd;
	knh_class_t cid = (tkNN(stmt, 1))->cid;
	if(DP(stmt)->size == 2 && (mtd)->cid == CLASS_Object && (mtd)->mn == MN_new) {
		ASM_TR_NEW(ctx, thisidx, sfpidx, cid);
	}
	else {
		ASM_TR_NEW(ctx, thisidx, thisidx, cid);
		CALLPARAMs_asm(ctx, stmt, 2, local, cid, mtd);
		_CALL(ctx, reqt, local, cid, mtd, 1, DP(stmt)->size - 2);
		ASM_MOVL(ctx, cid, sfpidx, SP(stmt)->type, local);
	}
	return 0;
}

static void sfp_store(CTX ctx, int sfpidx, knh_class_t cid, Value *v);

static int _TCAST_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	knh_type_t srct = Tn_type(stmt, 1);
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	if(srct != reqt) {
		int local = ASML(sfpidx);
		knh_Token_t *tkC = tkNN(stmt, 0);
		knh_TypeMap_t *trl = (tkC)->mpr;
		Tn_asm(ctx, stmt, 1, srct, local);
		if(IS_TypeMap(trl)) {
			knh_class_t scid = SP(trl)->scid, tcid = SP(trl)->tcid;
			if(1/*TypeMap_isFinal(trl)*/) {
				if(scid == CLASS_Int && tcid == CLASS_Float) {
					Value *v = ValueStack_get(ctx, local);
					v = builder->CreateSIToFP(v, LLVMTYPE_Float, "fcast");
					ValueStack_set(ctx, local, v);
				}
				else if(scid == CLASS_Float && tcid == CLASS_Int) {
					Value *v = ValueStack_get(ctx, local);
					v = builder->CreateFPToSI(v, LLVMTYPE_Int, "icast");
					ValueStack_set(ctx, local, v);
				}
				else {
					Value *v, *val = ValueStack_get(ctx, local);
					Value *func = LLVMValue(LLVMTYPE_fcall, trl->ftypemap_1);
					sfp_store(ctx, local, scid, val);
					std::vector<Value*> params;
					param_setCtxSfp(ctx, params, local);
					params.push_back(LLVMInt(0));
					builder->CreateCall(func, params.begin(), params.end());
					v = ValueStack_load_set(ctx, local, (stmt)->type);

					//ASM_BOX2(ctx, TYPE_Object, srct, local);
					//ASM(SCAST, RTNIDX_(ctx, local, stmt->type), SFP_(local), RIX_(local-local), trl);
				}
			}
			else {
				LLVM_TODO("!TypeMap_isFinal(trl)");
			}
		}
		else {
			LLVM_TODO("ACAST");
		}
		ASM_MOVL(ctx, reqt, sfpidx, SP(stmt)->type, local);
	}
	return 0;
}

#define VBOOL(v) (VBOOL_(ctx, v))
static Value *VBOOL_(CTX ctx, Value *v)
{
	if (v->getType() == Type::getInt1Ty(LLVM_CONTEXT())) {
		return v;
	}
	DBG_ASSERT(v->getType() == LLVMTYPE_Bool);
	return LLVM_BUILDER(ctx)->CreateTrunc(v, Type::getInt1Ty(LLVM_CONTEXT()), "cond");
}

static int _ALT_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	DBG_ABORT("TODO: ALT");
	return 0;
}

static int _OR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int i, local = ASML(sfpidx),  size = DP(stmt)->size;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbTrue = BB_CREATE(ctx, "true");
	BasicBlock *bbNext = BB_CREATE(ctx, "next");
	std::vector<BasicBlock *> blocks;

	for(i = 0; i < size; i++){
		int n = Tn_put(ctx, stmt, i, TYPE_Boolean, local + 1);
		Value *cond = ValueStack_get(ctx, n);
		builder->CreateCondBr(VBOOL(cond), bbTrue, bbNext);

		blocks.push_back(builder->GetInsertBlock());
		builder->SetInsertPoint(bbNext);
		if(i + 1 != size)
			bbNext = BB_CREATE(ctx, "next");
	}
	builder->CreateBr(bbTrue);
	builder->SetInsertPoint(bbTrue);

	PHINode *phi = builder->CreatePHI(LLVMTYPE_Bool, "or_result");
	phi->addIncoming(LLVMBool(0), bbNext);

	std::vector<BasicBlock*>::iterator itr;
	for (itr = blocks.begin(); itr != blocks.end(); itr++) {
		phi->addIncoming(LLVMBool(1), *itr);
	}
	ValueStack_set(ctx, sfpidx, phi);

	return 0;
}

static int _AND_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int i, local = ASML(sfpidx), size = DP(stmt)->size;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbFalse = BB_CREATE(ctx, "false");
	BasicBlock *bbNext  = BB_CREATE(ctx, "next");
	std::vector<BasicBlock *> blocks;
	for(i = 0; i < size; i++){
		int n = Tn_put(ctx, stmt, i, TYPE_Boolean, local + 1);
		Value *cond = ValueStack_get(ctx, n);
		builder->CreateCondBr(VBOOL(cond), bbNext, bbFalse);
		blocks.push_back(builder->GetInsertBlock());
		builder->SetInsertPoint(bbNext);
		if(i + 1 != size)
			bbNext = BB_CREATE(ctx, "next");
	}
	builder->CreateBr(bbFalse);
	builder->SetInsertPoint(bbFalse);

	PHINode *phi = builder->CreatePHI(LLVMTYPE_Bool, "and_result");
	phi->addIncoming(LLVMBool(1), bbNext);
	std::vector<BasicBlock*>::iterator itr;
	for (itr = blocks.begin(); itr != blocks.end(); itr++) {
		phi->addIncoming(LLVMBool(0), *itr);
	}
	ValueStack_set(ctx, sfpidx, phi);
	return 0;
}

static int Tn_CondAsm(CTX ctx, knh_Stmt_t *stmt, size_t n, int isTRUE, int flocal);

static int _TRI_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int local = DP(ctx->gma)->espidx;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbThen  = BB_CREATE(ctx, "then");
	BasicBlock *bbElse  = BB_CREATE(ctx, "else");
	BasicBlock *bbMerge = BB_CREATE(ctx, "merge");

	int a = Tn_CondAsm(ctx, stmt, 0, 0, sfpidx);
	Value *cond = ValueStack_get(ctx, a);
	builder->CreateCondBr(VBOOL(cond), bbThen, bbElse);

	builder->SetInsertPoint(bbThen);
	int b = Tn_put(ctx, stmt, 1, reqt, local);
	Value* vb = ValueStack_get(ctx, b);
	builder->CreateBr(bbMerge);

	builder->SetInsertPoint(bbElse);
	int c = Tn_put(ctx, stmt, 2, reqt, local);
	Value* vc = ValueStack_get(ctx, c);
	builder->CreateBr(bbMerge);

	builder->SetInsertPoint(bbMerge);
	PHINode *phi = builder->CreatePHI(convert_type(ctx, reqt), "tri_result");
	phi->addIncoming(vb, bbThen);
	phi->addIncoming(vc, bbElse);
	ValueStack_set(ctx, sfpidx, phi);
	return 0;
}

static int _LET_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	knh_Token_t *tkL = tkNN(stmt, 1);
	if(TT_(tkL) == TT_LOCAL || TT_(tkL) == TT_FUNCVAR) {
		int index = Token_index(tkL);
		Tn_asm(ctx, stmt, 2, SP(tkL)->type, index);
	}
	else if(IS_Token(tkNN(stmt, 2))) {
		ASM_MOV(ctx, tkL, tkNN(stmt, 2));
	}
	else {
		int local = ASML(sfpidx);
		knh_term_t tt = TT_(tkL); /* NOTE: tkL is reused inside stmt */
		knh_short_t index = (tkL)->index;
		Tn_asm(ctx, stmt, 2, SP(tkL)->type, local);
		TT_(tkL) = tt;
		(tkL)->index = index;
		ASM_MOV(ctx, tkL, tkNN(stmt, 2));
		if(local == sfpidx)
			// we do not need to let variable.
			return 0;
	}
	if(stmt->type != TYPE_void && reqt != TYPE_void) {
		ASM_SMOV(ctx, reqt, sfpidx, tkL);
	}

	return 0;
}

static METHOD Fmethod_empty(CTX ctx, knh_sfp_t *sfp _RIX) {}

static knh_Method_t* Gamma_getFmt(CTX ctx, knh_class_t cid, knh_methodn_t mn0)
{
	knh_methodn_t mn = mn0;
	knh_NameSpace_t *ns = K_GMANS;
	knh_Method_t *mtd = knh_NameSpace_getFmtNULL(ctx, ns, cid, mn);
	if(mtd == NULL) {
		WarningUndefinedFmt(ctx, cid, mn0);
		mtd = new_Method(ctx, 0, cid, mn0, Fmethod_empty);
		KNH_SETv(ctx, DP(mtd)->mp, KNH_TNULL(ParamArray));
		knh_NameSpace_addFmt(ctx, ns, mtd);
	}
	return mtd;
}

static int _FMTCALL_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	LLVM_TODO("FMTCALL");
	return 0;
}

static int ASM_SEND(CTX ctx, int sfpidx, int thisidx,const char* s);
static int _W1_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	int isCWB = 0;
	int local = ASML(sfpidx);
	size_t thisidx = local + K_CALLDELTA;
	knh_Method_t *mtdf  = tkNN(stmt, 0)->mtd;
	DBG_ASSERT(DP(stmt)->size == 3);
	if(TT_(tmNN(stmt, 1)) == TT_ASIS) {
		isCWB = 1;
		ASM_SEND(ctx, sfpidx, thisidx, "CWB");
		KNH_SETv(ctx, tmNN(stmt, 1), knh_Token_toTYPED(ctx, tkNN(stmt, 1), TT_FUNCVAR, TYPE_OutputStream, thisidx));
	}
	else {
		DBG_ASSERT(TT_(tkNN(stmt, 1)) == TT_FUNCVAR);
		DBG_ASSERT(Tn_type(stmt, 1) == TYPE_OutputStream);
		thisidx = tkNN(stmt, 1)->index;
	}
	if(IS_Method(mtdf)) {
		knh_type_t reqt = Tn_type(stmt, 2);
		Tn_asm(ctx, stmt, 2, reqt, thisidx + 1);
		ASM(SCALL, -1, SFP_(thisidx), ESP_((thisidx-K_CALLDELTA), 1), mtdf);
	}
	if(isCWB) {
		ASM_SEND(ctx, sfpidx,  thisidx, "TOSTR");
	}
	return 0;
}

static int ASM_SEND(CTX ctx, int sfpidx, int thisidx, const char *s)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	std::vector<const Type*> argsTy;
	std::string fname(s);
	argsTy.push_back(LLVMTYPE_context);
	argsTy.push_back(LLVMTYPE_sfp);
	argsTy.push_back(LLVMTYPE_Int);
	FunctionType *fnTy = FunctionType::get(LLVMTYPE_Void, argsTy, false);
	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, thisidx);
	params.push_back(LLVMInt(sfpidx-thisidx));
	//asm_shift_esp(ctx, thisidx);

	Function *func = cast<Function>(LLVM_MODULE(ctx)->getOrInsertFunction(fname+"_llvm", fnTy));
	
	builder->CreateCall(func, params.begin(), params.end());

	return 0;
}

static int ASM_SCALL(CTX ctx, int sfpidx, int thisidx, knh_Method_t* mtd)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *func = LLVMValue(LLVMTYPE_fcall, mtd->fcall_1);
	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, thisidx);
	params.push_back(LLVMInt(0/*K_RTNIDX*/));
	asm_shift_esp(ctx, 1+/*argc*/1+thisidx);
	builder->CreateCall(func, params.begin(), params.end());
	return 0;
}

static int _SEND_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	static int isTOSTR;
	int local = ASML(sfpidx);
	size_t i, thisidx = local + K_CALLDELTA;
	int isCWB = 0;
	if(TT_(tmNN(stmt, 1)) == TT_ASIS) {
		isCWB = 1;
		//size_t pos = BA_size(ctx->bufa);

		ASM_SEND(ctx, thisidx,  thisidx, "CWB");

		KNH_SETv(ctx, tmNN(stmt, 1), knh_Token_toTYPED(ctx, tkNN(stmt, 1), TT_FUNCVAR, TYPE_OutputStream, thisidx));
	}
	else {
		int j = Tn_put(ctx, stmt, 1, TYPE_OutputStream, thisidx+1);
		Value *v = ValueStack_get(ctx, j);
		sfp_store(ctx, thisidx, CLASS_OutputStream, v);
	}
	for(i = 2; i < DP(stmt)->size; i++) {
		if(STT_(stmtNN(stmt, i)) == STT_W1) {
			knh_Stmt_t *stmtIN = stmtNN(stmt, i);
			DBG_ASSERT(TT_(tkNN(stmtIN, 1)) == TT_ASIS);
			KNH_SETv(ctx, tkNN(stmtIN, 1), tkNN(stmt, 1));
			_W1_asm(ctx, stmtIN, TYPE_void, local + 1);
		}
		else {
			knh_Method_t *mtd = NULL;
			knh_class_t cid = Tn_cid(stmt, i);
			int j = Tn_put(ctx, stmt, i, cid/* not TYPE_Object*/, thisidx+1);
			Value *v;
			if (isTOSTR == 1){
				isTOSTR = 0;
				v = ValueStack_load(ctx, j, cid);
			} else {
				Value *v = ValueStack_get_or_load(ctx, j, cid);
					sfp_store(ctx, thisidx+1, cid, v);
			}


			if(false && cid == CLASS_String) {
				mtd = knh_NameSpace_getMethodNULL(ctx, CLASS_OutputStream, MN_send);
				DBG_ASSERT(mtd != NULL);
			}
			else {
				mtd = Gamma_getFmt(ctx, cid, MN__s);
			}
			ASM_SCALL(ctx, thisidx, thisidx, mtd);
		}
	}
	if(isCWB) {
		ASM_SEND(ctx, sfpidx, thisidx, "TOSTR");
		isTOSTR = 1;
	} else {
		isTOSTR = 0;
	}
	return 0;
}


/* ------------------------------------------------------------------------ */

#define CASE_ASM(XX, ...) case STT_##XX : { \
		_##XX##_asm(ctx, stmt, ## __VA_ARGS__); \
		break;\
	}\

static int _EXPR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	switch(STT_(stmt)) {
	CASE_ASM(LET, reqt, sfpidx);
	CASE_ASM(FUNCCALL, reqt, sfpidx);
	CASE_ASM(CALL, reqt, sfpidx);
	CASE_ASM(CALL1, reqt, sfpidx);
	CASE_ASM(OPR, reqt, sfpidx);
	CASE_ASM(NEW, reqt, sfpidx);
	CASE_ASM(TCAST, reqt, sfpidx);
	CASE_ASM(BOX, reqt, sfpidx);
	CASE_ASM(AND, reqt, sfpidx);
	CASE_ASM(OR, reqt, sfpidx);
	CASE_ASM(ALT, reqt, sfpidx);
	CASE_ASM(TRI, reqt, sfpidx);
	CASE_ASM(SEND, reqt, sfpidx);
	CASE_ASM(W1, reqt, sfpidx);
	CASE_ASM(FMTCALL, reqt, sfpidx);
	default:
		DBG_ABORT("unknown stt=%s", TT__(STT_(stmt)));
	}
	ASM_BOX2(ctx, reqt, SP(stmt)->type, sfpidx);
	return 0;
}

static void Tn_asm(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_type_t reqt, int local)
{
	if(IS_Token(tkNN(stmt, n))) {
		knh_Token_t *tk = tkNN(stmt, n);
		ASM_SMOV(ctx, reqt, local, tk);
	}
	else {
		_EXPR_asm(ctx, stmtNN(stmt, n), reqt, local);
	}
	if(IS_Token(tkNN(stmt, n))) {
		knh_Token_t *tk = tkNN(stmt, n);
		//DBG_P("@START %s tk=%p tk->index=%d local=%d esp=%d", TT__(tk->tt), tk, tk->index, local, DP(ctx->gma)->espidx);
		if(TT_(tk) == TT_LOCAL) {
			knh_Token_toTYPED(ctx, tk, TT_FUNCVAR, tk->type, tk->index + DP(ctx->gma)->ebpidx);
		}
		if(TT_(tk) != TT_FUNCVAR) {
			knh_Token_toTYPED(ctx, tk, TT_FUNCVAR, reqt, local);
		}
		//DBG_P("@END %s tk=%p tk->index=%d local=%d esp=%d", TT__(tk->tt), tk, tk->index, local, DP(ctx->gma)->espidx);
	}
	else {
		knh_Token_t *tk = new_TokenTYPED(ctx, TT_FUNCVAR, reqt, local);
		KNH_SETv(ctx, tkNN(stmt, n), tk);
	}
	DBG_ASSERT(IS_Token(tkNN(stmt, n)));
}

/* ------------------------------------------------------------------------ */
/* [IF, WHILE, DO, FOR, FOREACH]  */
static void ASM_BBLAST(CTX ctx, void *ptr, void (*func)(CTX, void*))
{
	BasicBlock *bb = LLVM_BUILDER(ctx)->GetInsertBlock();
	BasicBlock::iterator itr;
	for(itr = bb->begin(); itr != bb->end(); itr++) {
		Instruction &inst = *itr;
		if(ReturnInst::classof(&inst) || BranchInst::classof(&inst)){
			return;
		}
	}
	func(ctx, ptr);
}
static bool BB_hasReturn(BasicBlock *bb)
{
	BasicBlock::iterator itr;
	for(itr = bb->begin(); itr != bb->end(); itr++) {
		Instruction &inst = *itr;
		if(ReturnInst::classof(&inst) || BranchInst::classof(&inst)){
			return true;
		}
	}
	return false;
}
static int Tn_CondAsm(CTX ctx, knh_Stmt_t *stmt, size_t n, int isTRUE, int flocal)
{
	knh_Token_t *tk = tkNN(stmt, n);
	if(TT_(tk) == TT_CONST) {
		int isTRUE2 = IS_TRUE((tk)->data);
		/* TODO isTRUE2 */
		ASM_SMOV(ctx, TYPE_Boolean, flocal, tk);
		return flocal;
	}
	if(TT_(tk) == TT_LOCAL || TT_(tk) == TT_FUNCVAR) {
		int index = Token_index(tk);
		if(isTRUE) {
			ASM(bNOT, NC_(index), NC_(index));
		}
		return index;
	}
	else {
		Tn_asm(ctx, stmt, n, TYPE_Boolean, flocal);
		if(isTRUE) {
			ASM(bNOT, NC_(flocal), NC_(flocal));
		}
		return flocal;
	}
}

static knh_Token_t *Tn_it(knh_Stmt_t *stmt, size_t n)
{
	DBG_ASSERT(n < DP(stmt)->size);
	knh_Token_t *tkIT = tkNN(stmt, n);
	DBG_ASSERT(TT_(tkIT) == TT_LOCAL);
	return tkIT;
}

static inline void Tn_asmBLOCK(CTX ctx, knh_Stmt_t *stmt, size_t n, knh_type_t reqt)
{
	DBG_ASSERT(IS_Stmt(stmtNN(stmt, n)));
	_BLOCK_asm(ctx, stmtNN(stmt, n), reqt, 0);
}

static void __asm_br(CTX ctx, void *ptr)
{
	BasicBlock *bbMerge = (BasicBlock*) ptr;
	LLVM_BUILDER(ctx)->CreateBr(bbMerge);
}
static void __asm_ret(CTX ctx, void *ptr)
{
	knh_ParamArray_t *pa = DP(DP(ctx->gma)->mtd)->mp;
	knh_class_t rtype = knh_ParamArray_rtype(pa);
	Value *v = ValueStack_get_or_load(ctx, K_RTNIDX, rtype);
	const Type *retTy = LLVM_FUNCTION(ctx)->getReturnType();
	if (retTy != LLVMTYPE_Void) {
		LLVM_BUILDER(ctx)->CreateRet(v);
	} else {
		LLVM_BUILDER(ctx)->CreateRetVoid();
	}
}

static void phi_nop(CTX ctx, knh_Array_t *a, int i, Value *v0, Value *v1, Value *v2, BasicBlock *bb1, BasicBlock *bb2)
{
	(void)a;(void)v1;(void)v2;(void)i;
	(void)bb1;(void)bb2;
}
static void phi_then(CTX ctx, knh_Array_t *a, int i, Value *v0, Value *v1, Value *v2, BasicBlock *bb1, BasicBlock *bb2)
{
	a->nlist[i] = (knh_ndata_t)v1;
}
static void phi_else(CTX ctx, knh_Array_t *a, int i, Value *v0, Value *v1, Value *v2, BasicBlock *bb1, BasicBlock *bb2)
{
	a->nlist[i] = (knh_ndata_t)v2;
}

static void phi_phi(CTX ctx, knh_Array_t *a, int i, Value *v0, Value *v1, Value *v2, BasicBlock *bb1, BasicBlock *bb2)
{
	PHINode *phi = LLVM_BUILDER(ctx)->CreatePHI(v1->getType(), "phi");
	phi->addIncoming(v1, bb1);
	phi->addIncoming(v2, bb2);
	a->nlist[i] = (knh_ndata_t)phi;
}

typedef void (*fphi_t)(CTX ctx, knh_Array_t *a, int i, Value *, Value *, Value *, BasicBlock *, BasicBlock *);

static int PHI_asm(CTX ctx, knh_Array_t *prev, knh_Array_t *thenArray, knh_Array_t *elseArray, BasicBlock *bbThen, BasicBlock *bbElse)
{
	int i, size = DP(ctx->gma)->espidx + (-1 * K_RTNIDX);
	fphi_t fphi = NULL;
	if (BB_hasReturn(bbThen) && BB_hasReturn(bbElse)) {
		fphi = phi_nop;
	} else if (BB_hasReturn(bbThen)) {
		fphi = phi_else;
	} else if (BB_hasReturn(bbElse)) {
		fphi = phi_then;
	} else {
		fphi = phi_phi;
	}
	for (i = 0; i < size; i++) {
		Value *vp = (Value *)prev->nlist[i];
		if(vp == NULL) continue;
		Value *v1 = (Value *)thenArray->nlist[i];
		Value *v2 = (Value *)elseArray->nlist[i];
		if(vp != v1 || vp != v2){
			fphi(ctx, prev, i, vp, v1, v2, bbThen, bbElse);
		}
	}
	return 1;
}

static int _IF_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx _UNUSED_)
{
	Value *cond = NULL;//expr
	int local = DP(ctx->gma)->espidx;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbThen  = BB_CREATE(ctx, "then");
	BasicBlock *bbElse  = BB_CREATE(ctx, "else");
	BasicBlock *bbMerge = BB_CREATE(ctx, "ifcont");

	//Tn_JMPIF(ctx, stmt, 0, 0/*FALSE*/, ElseBB, local);
	int a = Tn_CondAsm(ctx, stmt, 0, 0, local);
	cond = ValueStack_get(ctx, a);
	builder->CreateCondBr(VBOOL(cond), bbThen, bbElse);
	knh_Array_t *prev = DP(ctx->gma)->lstacks;
	knh_Array_t *st1 = ValueStack_copy(ctx, prev);
	knh_Array_t *st2 = ValueStack_copy(ctx, prev);
	BEGIN_LOCAL(ctx, lsfp, 3);
	KNH_SETv(ctx, lsfp[0].o, prev);
	KNH_SETv(ctx, lsfp[1].o, st1);
	KNH_SETv(ctx, lsfp[2].o, st2);

	builder->SetInsertPoint(bbThen);
	KNH_SETv(ctx, DP(ctx->gma)->lstacks, st1);
	Tn_asmBLOCK(ctx, stmt, 1, reqt);
	ASM_BBLAST(ctx, (void*)bbMerge, __asm_br);
	bbThen = builder->GetInsertBlock();

	builder->SetInsertPoint(bbElse);
	KNH_SETv(ctx, DP(ctx->gma)->lstacks, st2);
	Tn_asmBLOCK(ctx, stmt, 2, reqt);
	ASM_BBLAST(ctx, (void*)bbMerge, __asm_br);
	bbElse = builder->GetInsertBlock();

	builder->SetInsertPoint(bbMerge);
	PHI_asm(ctx, prev, st1, st2, bbThen, bbElse);
	KNH_SETv(ctx, DP(ctx->gma)->lstacks, prev);

	END_LOCAL_NONGC(ctx, lsfp);

	return 0;
}

static int _SWITCH_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx)
{
	knh_Stmt_t *stmtCASE;
	Value *cond = NULL;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	//BasicBlock *bbContinue = BB_CREATE(ctx, "continue");
	BasicBlock *bbBreak    = BB_CREATE(ctx, "break");
	BasicBlock *bbCase     = BB_CREATE(ctx, "case");
	BasicBlock *bbDefault  = BB_CREATE(ctx, "default");

	LLVM_WARN("TODO: undeveloped");
	knh_Token_t *tkIT = Tn_it(stmt, 2);
	//PUSH_LABEL(ctx, bbContinue, bbBreak);
	Tn_asm(ctx, stmt, 0, SP(tkIT)->type, Token_index(tkIT));
	cond = ValueStack_get(ctx, Token_index(tkIT));

	SwitchInst *SwInst = builder->CreateSwitch(cond, bbDefault, 10);
	// 10 is a hint for the number of cases

	stmtCASE = stmtNN(stmt, 1);
	while (stmtCASE != NULL) {
		if (STT_(stmtCASE) == STT_CASE && !Tn_isASIS(stmtCASE, 0)) {
			LLVM_TODO("switch-case");
			DP(ctx->gma)->espidx = DP(stmtCASE)->espidx + DP(ctx->gma)->ebpidx;
			builder->SetInsertPoint(bbCase);
			SwInst->addCase((ConstantInt*)cond, bbCase);
			Tn_asmBLOCK(ctx, stmtCASE, 1, reqt);
			bbCase = BB_CREATE(ctx, "case");
			builder->CreateBr(bbCase);
		}
		stmtCASE = DP(stmtCASE)->nextNULL;
	}
	builder->SetInsertPoint(bbBreak);
	POP_LABEL(ctx);
	return 0;
}

static void ASM_JUMPLABEL(CTX ctx, knh_Stmt_t *stmt, int delta)
{
	LLVM_TODO("JUMPLABEL");
}

static int addPhiArray(CTX ctx, knh_Array_t *phi, knh_Array_t *block, BasicBlock *bb, int esp);

static int _CONTINUE_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	std::vector<label_stack *> *bbstack = LLVM_BBSTACK(ctx);
	label_stack *l = bbstack->back();
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bb = l->bbCon;
	knh_Array_t *phi = l->phiCon;
	addPhiArray(ctx, phi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), DP(ctx->gma)->espidx);
	builder->CreateBr(bb);
	return 0;
}

static int _BREAK_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	std::vector<label_stack *> *bbstack = LLVM_BBSTACK(ctx);
	label_stack *l = bbstack->back();
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bb = l->bbBreak;
	knh_Array_t *phi = l->phiBreak;
	addPhiArray(ctx, phi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), DP(ctx->gma)->espidx);
	builder->CreateBr(bb);
	return 0;
}

static knh_Array_t *createPhiArray(CTX ctx, BasicBlock *bb, knh_Array_t *a, int esp)
{
	knh_Array_t *newlstacks = ValueStack_copy(ctx, a);
	int i, size = esp + K_CALLDELTA;//knh_Array_capacity(newlstacks);
	for (i = K_CALLDELTA; i < size; i++){
		Value *v = (Value *)knh_Array_n(a, i);
		if (v != NULL){
			PHINode *phi = PHINode::Create(v->getType(), "phi", bb);
			knh_Array_n(newlstacks, i) = (knh_Object_t *) phi;
		}
	}
	return newlstacks;
}

static int addPhiArray(CTX ctx, knh_Array_t *phi, knh_Array_t *block, BasicBlock *bb, int esp) {
	int i, size;
	size = esp + K_CALLDELTA;
	for (i = K_CALLDELTA; i < size; i++) {
		Value *p = (Value *)knh_Array_n(phi, i);
		Value *v = (Value *)knh_Array_n(block, i);
		if (p != NULL && v != NULL) {
			if (PHINode::classof(p) && p->getType() == v->getType()) {
				PHINode *phi = static_cast<PHINode*>(p);
				phi->addIncoming(v, bb);
			}
		}
	}
	return 0;
}

static int _WHILE_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	int local = DP(ctx->gma)->espidx;
	Value *cond;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbContinue = BB_CREATE(ctx, "continue");
	BasicBlock *bbBreak    = BB_CREATE(ctx, "break");
	BasicBlock *bbBlock    = BB_CREATE(ctx, "block");
	BasicBlock *bbPrev     = builder->GetInsertBlock();

	// create phi array
	knh_Array_t *prev = DP(ctx->gma)->lstacks;
	knh_Array_t *conPhi = createPhiArray(ctx, bbContinue, prev, local);
	knh_Array_t *brPhi = createPhiArray(ctx, bbBreak, prev, local);
	DP(ctx->gma)->lstacks = ValueStack_copy(ctx, conPhi);

	builder->CreateBr(bbContinue);
	addPhiArray(ctx, conPhi, prev, bbPrev, local);

	// continue part
	builder->SetInsertPoint(bbContinue);
	if (!Tn_isTRUE(stmt, 0)) {
		int n = Tn_CondAsm(ctx, stmt, 0, 0, local+1);
		cond = ValueStack_get(ctx, n);
	} else {
		cond = LLVMBool(1);
	}
	builder->CreateCondBr(VBOOL(cond), bbBlock, bbBreak);
	addPhiArray(ctx, brPhi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), local);

	// block part
	builder->SetInsertPoint(bbBlock);
	struct label_stack l = {bbContinue, bbBreak, conPhi, brPhi};
	PUSH_LABEL(ctx, &l);
	Tn_asmBLOCK(ctx, stmt, 1, TYPE_void);
	POP_LABEL(ctx);
	BasicBlock *bbTemp = builder->GetInsertBlock();
	if (!BB_hasReturn(bbTemp)) {
		builder->CreateBr(bbContinue);
		addPhiArray(ctx, conPhi, DP(ctx->gma)->lstacks, bbTemp, local);
	}
	
	// break part
	builder->SetInsertPoint(bbBreak);
	DP(ctx->gma)->lstacks = brPhi;
	return 0;
}

static int _DO_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	int local = DP(ctx->gma)->espidx;
	Value *cond;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbContinue = BB_CREATE(ctx, "continue");
	BasicBlock *bbBreak    = BB_CREATE(ctx, "break");
	BasicBlock *bbBlock    = BB_CREATE(ctx, "block");
	BasicBlock *bbPrev     = builder->GetInsertBlock();

	// create phi array
	knh_Array_t *prev = DP(ctx->gma)->lstacks;
	knh_Array_t *blockPhi = createPhiArray(ctx, bbBlock, prev, local);
	knh_Array_t *conPhi = createPhiArray(ctx, bbContinue, prev, local);
	knh_Array_t *brPhi = createPhiArray(ctx, bbBreak, prev, local);
	DP(ctx->gma)->lstacks = ValueStack_copy(ctx, blockPhi);

	builder->CreateBr(bbBlock);
	addPhiArray(ctx, blockPhi, prev, bbPrev, local);

	// block part
	builder->SetInsertPoint(bbBlock);
	struct label_stack l = {bbContinue, bbBreak, conPhi, brPhi};
	PUSH_LABEL(ctx, &l);
	Tn_asmBLOCK(ctx, stmt, 0, TYPE_void);
	POP_LABEL(ctx);
	BasicBlock *bbTemp = builder->GetInsertBlock();
	if (!BB_hasReturn(bbTemp)) {
		builder->CreateBr(bbContinue);
		addPhiArray(ctx, conPhi, DP(ctx->gma)->lstacks, bbTemp, local);
	}	
	
	// continue part
	DP(ctx->gma)->lstacks = conPhi;
	builder->SetInsertPoint(bbContinue);
	if (!Tn_isTRUE(stmt, 1)) {
		int n = Tn_CondAsm(ctx, stmt, 1, 0, local+1);
		cond = ValueStack_get(ctx, n);
	} else {
		cond = LLVMBool(1);
	}
	builder->CreateCondBr(VBOOL(cond), bbBlock, bbBreak);
	addPhiArray(ctx, blockPhi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), local);
	addPhiArray(ctx, brPhi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), local);

	// break part
	builder->SetInsertPoint(bbBreak);
	DP(ctx->gma)->lstacks = brPhi;
	return 0;
}

static int _FOR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	int local = DP(ctx->gma)->espidx + 1;
	Value *cond;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbContinue = BB_CREATE(ctx, "continue");
	BasicBlock *bbCond     = BB_CREATE(ctx, "cond");
	BasicBlock *bbBreak    = BB_CREATE(ctx, "break");
	BasicBlock *bbBlock    = BB_CREATE(ctx, "block");
	BasicBlock *bbPrev     = builder->GetInsertBlock();

	// init part
	Tn_asm(ctx, stmt, 0, TYPE_void, local);
	builder->CreateBr(bbCond);

	// create phi array
	knh_Array_t *prev = DP(ctx->gma)->lstacks;
	knh_Array_t *condPhi = createPhiArray(ctx, bbCond, prev, local);
	knh_Array_t *contPhi = createPhiArray(ctx, bbContinue, prev, local);
	knh_Array_t *brPhi   = createPhiArray(ctx, bbBreak, prev, local);
	DP(ctx->gma)->lstacks = ValueStack_copy(ctx, condPhi);

	addPhiArray(ctx, condPhi, prev, bbPrev, local);
	
	// condition part
	builder->SetInsertPoint(bbCond);
	if (!Tn_isTRUE(stmt, 1)) {
		int n = Tn_CondAsm(ctx, stmt, 1, 0, local+1);
		cond = ValueStack_get(ctx, n);
	} else {
		cond = LLVMBool(1);
	}	
	builder->CreateCondBr(VBOOL(cond), bbBlock, bbBreak);
	addPhiArray(ctx, brPhi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), local);

	// block part
	builder->SetInsertPoint(bbBlock);
	struct label_stack l = {bbContinue, bbBreak, contPhi, brPhi};
	PUSH_LABEL(ctx, &l);
	Tn_asmBLOCK(ctx, stmt, 3, TYPE_void);
	POP_LABEL(ctx);
	BasicBlock *bbTemp = builder->GetInsertBlock();
	if (!BB_hasReturn(bbTemp)) {
		builder->CreateBr(bbContinue);
		addPhiArray(ctx, contPhi, DP(ctx->gma)->lstacks, bbTemp, local);
	}
	
	// continue part
	builder->SetInsertPoint(bbContinue);
	DP(ctx->gma)->lstacks = contPhi;
	Tn_asmBLOCK(ctx, stmt, 2, TYPE_void);
	builder->CreateBr(bbCond);
	addPhiArray(ctx, condPhi, DP(ctx->gma)->lstacks, builder->GetInsertBlock(), local);
	
	// break part
	builder->SetInsertPoint(bbBreak);
	DP(ctx->gma)->lstacks = brPhi;

	return 0;
}

static void param_setCtxSfp(CTX ctx, std::vector<Value*> &params, int sfpidx)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Function::arg_iterator args = LLVM_FUNCTION(ctx)->arg_begin();
	Value *arg_ctx = args++;
	Value *arg_sfp = args;
	params.push_back(arg_ctx);
	if (sfpidx) {
		arg_sfp = builder->CreateGEP(arg_sfp, LLVMInt(sfpidx), "sfpsft");
	}
	params.push_back(arg_sfp);
}

static void sfp_store(CTX ctx, int sfpidx, knh_class_t cid, Value *v)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	Value *vsfp = getsfp(ctx);
	vsfp = create_loadsfp(ctx, builder, vsfp, cid, sfpidx);
	builder->CreateStore(v, vsfp, false/*isVolatile*/);
}

static int _FOREACH_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	Value *cond, *v, *vitr;
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbContinue = BB_CREATE(ctx, "continue");
	BasicBlock *bbBreak    = BB_CREATE(ctx, "break");
	BasicBlock *bbBlock    = BB_CREATE(ctx, "block");

	knh_Token_t *tkN = tkNN(stmt, 0);
	int varidx = Token_index(tkN);
	int itridx = Token_index(tkNN(stmt, 3));
	Tn_asm(ctx, stmt, 1, TYPE_Iterator, itridx);

	vitr = ValueStack_get(ctx, itridx);
	v = vitr;
	v = builder->CreateBitCast(v, LLVMTYPE_Iterator, "cast");
	v = builder->CreateStructGEP(v, 2, "gep");
	v = builder->CreateLoad(v);

	builder->CreateBr(bbContinue);
	builder->SetInsertPoint(bbContinue);

	sfp_store(ctx, itridx, CLASS_Iterator, vitr);
	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, itridx);
	params.push_back(LLVMInt(varidx-itridx));

	cond = builder->CreateCall(v, params.begin(), params.end());

	v = ValueStack_load_set(ctx, varidx, (tkN)->type);
	builder->CreateCondBr(VBOOL(cond), bbBlock, bbBreak);

	builder->SetInsertPoint(bbBlock);
	Tn_asmBLOCK(ctx, stmt, 2, TYPE_void);
	builder->CreateBr(bbContinue);
	builder->SetInsertPoint(bbBreak);
	POP_LABEL(ctx);
	return 0;

}

/* ------------------------------------------------------------------------ */
/* [TRY] */

#define Gamma_inTry(ctx)  IS_Stmt(DP(ctx->gma)->finallyStmt)

static void Gamma_setFINALLY(CTX ctx, knh_Stmt_t *stmt)
{
	if(IS_NOTNULL(stmt)) {
		if(IS_NOTNULL(DP(ctx->gma)->finallyStmt)) {
			ErrorMisplaced(ctx);
			KNH_HINT(ctx, "try"); // not nested try
			return;
		}
		KNH_SETv(ctx, DP(ctx->gma)->finallyStmt, stmt);
	}
	else { /* stmt == null */
		KNH_SETv(ctx, DP(ctx->gma)->finallyStmt, stmt);
	}
}

static void ASM_FINALLY(CTX ctx)
{
	if(IS_NOTNULL(DP(ctx->gma)->finallyStmt)) {
		_BLOCK_asm(ctx, DP(ctx->gma)->finallyStmt, TYPE_void, 0);
	}
}

static int _TRY_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	LLVM_TODO("TRY");
	return 0;
}

static void ASM_CHECKIN(CTX ctx, int thisidx, int sfpidx, knh_class_t cid)
{
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	std::vector<Value*> params;
  int *func = (int*)ClassTBL(CLASS_Assurance)->ospi->checkin;
	Value *vfunc = LLVMValue(LLVMTYPE_checkin, func);


	param_setCtxSfp(ctx, params, thisidx);
	Value *v = ValueStack_get_or_load(ctx, sfpidx, cid);
	params.push_back(v);


	builder->CreateCall(vfunc, params.begin(), params.end());
	return;
}

static void ASM_CHECKOUT(CTX ctx, int thisidx, int sfpidx, knh_class_t cid, int index)
{

	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	std::vector<Value*> params;
  int *func = (int*)ClassTBL(CLASS_Assurance)->ospi->checkout;
	Value *vfunc = LLVMValue(LLVMTYPE_checkout, func);

	Function::arg_iterator args = LLVM_FUNCTION(ctx)->arg_begin();
	Value *arg_ctx = args;
	params.push_back(arg_ctx);
	Value *v = ValueStack_get_or_load(ctx, sfpidx, cid);
	params.push_back(v);
	params.push_back(LLVMInt(cid));

	builder->CreateCall(vfunc, params.begin(), params.end());
	return;

}

static int _ASSURE_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	int local = DP(ctx->gma)->espidx, thisidx = local + K_CALLDELTA;
	int index = Token_index(tkNN(stmt, 2)); // it

	knh_class_t cid = (tkNN(stmt, 2))->cid;
	Tn_asm(ctx, stmt, 0, CLASS_Assurance, index);

	ASM_CHECKIN(ctx, thisidx, local, cid);
	Tn_asmBLOCK(ctx, stmt, 1, TYPE_void);
	ASM_CHECKOUT(ctx, thisidx, local, cid, index);
	return 0;
}

static int _ASSERT_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	Module *m = LLVM_MODULE(ctx);
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	BasicBlock *bbThen  = BB_CREATE(ctx, "then");
	BasicBlock *bbElse  = BB_CREATE(ctx, "else");

	int a = Tn_CondAsm(ctx, stmt, 0, 0, DP(ctx->gma)->espidx);
	Value *cond = ValueStack_get(ctx, a);
	builder->CreateCondBr(VBOOL(cond), bbThen, bbElse);

	builder->SetInsertPoint(bbElse);

	std::vector<const Type*>args_list;
	args_list.push_back(LLVMTYPE_context);
	args_list.push_back(LLVMTYPE_sfp);
	args_list.push_back(LLVMTYPE_Int); /* start */
	args_list.push_back(LLVMTYPE_Int); /* uline */
	FunctionType* fnTy = FunctionType::get(LLVMTYPE_Void, args_list, false);
	Function *func = cast<Function>(m->getOrInsertFunction("knh_assert", fnTy));

	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, 0);
	params.push_back(LLVMInt(DP(ctx->gma)->espidx));
	params.push_back(LLVMInt(stmt->uline));
	builder->CreateCall(func, params.begin(), params.end());

	builder->CreateBr(bbThen);
	builder->SetInsertPoint(bbThen);
	return 0;
}

static int _THROW_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	LLVM_TODO("THROW");
	return 0;
}

static void ASM_LastRET(CTX ctx, knh_Stmt_t *stmt)
{
	//while(DP(stmt)->nextNULL != NULL) {
	//	stmt = DP(stmt)->nextNULL;
	//	if(STT_(stmt) == STT_CHKOUT) {
	//		CHKOUT_asm(ctx, stmt);
	//	}
	//}
	BasicBlock *bb = LLVM_BUILDER(ctx)->GetInsertBlock();
	ASM_BBLAST(ctx, (void*)bb, __asm_ret);
}


static int _RETURN_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	ASM_FINALLY(ctx);
	size_t size = DP(stmt)->size;
	knh_type_t rtype = TYPE_void;
	if(size == 1) {
		rtype = Tn_type(stmt, 0);
		Tn_asm(ctx, stmt, 0, rtype, K_RTNIDX);
		if(IS_Tunbox(rtype)) {
			knh_ParamArray_t *pa = DP(DP(ctx->gma)->mtd)->mp;
			knh_param_t *p = knh_ParamArray_rget(pa, 0);
			ASM_BOX2(ctx, knh_type_tocid(ctx, p->type, DP(ctx->gma)->this_cid), rtype, K_RTNIDX);
		}
	}
	if(IS_Stmt(DP(stmt)->stmtPOST)) {
		_EXPR_asm(ctx, DP(stmt)->stmtPOST, Tn_type(stmt, 0), DP(DP(stmt)->stmtPOST)->espidx+1);
	}
	if(!Stmt_isImplicit(stmt)) {
		Value *v = NULL;
		if (rtype != TYPE_void) {
			int retidx = (SP(DP(ctx->gma)->mtd)->mn == MN_new)?0:K_RTNIDX;
			v = ValueStack_get_or_load(ctx, retidx, reqt);
		}
		LLVM_BUILDER(ctx)->CreateRet(v);
	}
	return 0;
}

static int _YIELD_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	LLVM_TODO("yield");
	return 0;
}


static int _ERR_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	LLVM_TODO("ERR");
	return 0;
}

static knh_flag_t PRINT_flag(CTX ctx, knh_Stmt_t *o)
{
	knh_flag_t flag = 0;
	if(IS_Map(DP(o)->metaDictCaseMap)) {
		Object *v = knh_DictMap_getNULL(ctx,  DP(o)->metaDictCaseMap, STEXT("Time"));
		if(v != NULL) {
			flag |= K_FLAG_PF_TIME;
		}
	}
	return flag;
}

static Function *PRINT_func(CTX ctx, const char *name, knh_class_t cid)
{
	Module *m = LLVM_MODULE(ctx);
	std::vector<const Type*>args_list;
	args_list.push_back(LLVMTYPE_context);
	args_list.push_back(LLVMTYPE_sfp);
	args_list.push_back(LLVMTYPE_Int); /* flag */
	args_list.push_back(LLVMTYPE_Int); /* uline */
	args_list.push_back(LLVMTYPE_Object); /* msg */
	args_list.push_back(convert_type(ctx, cid));
	FunctionType* fnTy = FunctionType::get(LLVMTYPE_Void, args_list, false);
	Function *func = cast<Function>(m->getOrInsertFunction(name, fnTy));
	return func;
}

struct print_data {
	knh_class_t cid;
	const char *name;
};
static struct print_data PRINT_DATA[] = {
	{CLASS_Boolean, "llvm_PRINTb"},
	{CLASS_Int,     "llvm_PRINTi"},
	{CLASS_Float,   "llvm_PRINTf"},
	{CLASS_Object,  "llvm_PRINT"},
};

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
static void init_print_func(CTX ctx)
{
	Module *m = LLVM_MODULE(ctx);
	Function* func;
	std::vector<const Type*>args;
	size_t i;
	for (i = 0; i < ARRAY_SIZE(PRINT_DATA); i++) {
		knh_class_t cid = PRINT_DATA[i].cid;
		const char *name = PRINT_DATA[i].name;
		args.push_back(LLVMTYPE_context);
		args.push_back(LLVMTYPE_sfp);
		args.push_back(LLVMTYPE_Int); /* flag */
		args.push_back(LLVMTYPE_Int); /* uline */
		args.push_back(LLVMTYPE_Object); /* msg */
		args.push_back(convert_type(ctx, cid));

		FunctionType* fnTy = FunctionType::get(LLVMTYPE_Void, args, false);
		func = Function::Create(fnTy, GlobalValue::ExternalLinkage, name, m);
		func->setCallingConv(CallingConv::C);
		args.clear();
	}
}

static void ASM_P(CTX ctx, const char *name, knh_flag_t flag, knh_uline_t line, knh_String_t *msg, knh_class_t cid, Value *v)
{
	Function *f = PRINT_func(ctx, name, cid);
	IRBuilder<> *builder = LLVM_BUILDER(ctx);
	std::vector<Value*> params;
	param_setCtxSfp(ctx, params, 0);
	params.push_back(LLVMInt(flag));
	params.push_back(LLVMInt(line));
	params.push_back(LLVMValue(LLVMTYPE_Object, msg)); /* msg */
	params.push_back(v);
	builder->CreateCall(f, params.begin(), params.end());
}

static int _PRINT_asm(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt _UNUSED_, int sfpidx _UNUSED_)
{
	knh_flag_t flag = PRINT_flag(ctx, stmt) | K_FLAG_PF_BOL | K_FLAG_PF_LINE;
	long i, espidx = DP(ctx->gma)->espidx;
	for(i = 0; i < DP(stmt)->size; i++) {
		knh_Token_t *tkn = tkNN(stmt, i);
		if(TT_(tkn) != TT_CONST || !IS_String((tkn)->data)) {
			knh_class_t cid = Tn_cid(stmt, i);
			Tn_asm(ctx, stmt, i, cid, espidx + i);
		}
	}
	for(i = 0; i < DP(stmt)->size; i++) {
		knh_flag_t mask = 0;
		knh_String_t *msg = (knh_String_t*)KNH_NULL;
		L_REDO:;
		knh_Token_t *tkn = tkNN(stmt, i);
		if(i == (long)DP(stmt)->size - 1) {
			mask |= K_FLAG_PF_EOL;
		}
		if(TT_(tkn) == TT_CONST && IS_String((tkn)->data)) {
			if(Token_isPNAME(tkn)) { /* name= */
				msg = (tkn)->text;
				mask |= K_FLAG_PF_NAME; i++;
				goto L_REDO;
			}
			DBG_ASSERT(stmt->uline == ctx->gma->uline);
			//ASM(P, _PRINTm, flag | mask, (tkn)->text, 0); flag = 0;
		}
		else {
			knh_class_t cid = Tn_cid(stmt, i);
			Value *v = ValueStack_get(ctx, espidx+i);
			const char *fname;
			if(IS_Tint(cid))        fname = "llvm_PRINTi";
			else if(IS_Tfloat(cid)) fname = "llvm_PRINTf";
			else if(IS_Tbool(cid))  fname = "llvm_PRINTb";
			else                    fname = "llvm_PRINT";
			ASM_P(ctx, fname, flag | mask, tkNN(stmt, i)->uline, msg, cid, v);
			flag=0;
		}
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

static int _BLOCK_asm(CTX ctx, knh_Stmt_t *stmtH, knh_type_t reqt, int sfpidx _UNUSED_)
{
	knh_Stmt_t *stmt = stmtH;
	while(stmt != NULL) {
		knh_type_t etype = (DP(stmt)->nextNULL == NULL) ? reqt : TYPE_void;
		ctx->gma->uline = stmt->uline;
		DP(ctx->gma)->espidx = DP(stmt)->espidx + DP(ctx->gma)->ebpidx;
		//DBG_P("ASM %s %p etype=%s,%s, espidx=%d", TT__(STT_(stmt)), stmt, TYPE__(etype), TYPE__(stmt->type), DP(ctx->gma)->espidx);
		switch(STT_(stmt)) {
		case STT_REGISTER:
		{
			size_t i;
			for(i = 0; i < DP(stmt)->size; i++) {
				if(IS_Stmt(tmNN(stmt, i)) && STT_(stmtNN(stmt, i)) == STT_LET) {
					_LET_asm(ctx, stmtNN(stmt, i), TYPE_void, DP(ctx->gma)->espidx);
				}
			}
			break;
		}
		case STT_BLOCK :
		{
			_BLOCK_asm(ctx, stmtNN(stmt, 0), etype, sfpidx);
			break;
		}
		CASE_ASM(IF      , etype    , 0);
		CASE_ASM(SWITCH  , etype    , 0);
		CASE_ASM(WHILE   , TYPE_void, 0);
		CASE_ASM(DO      , TYPE_void, 0);
		CASE_ASM(FOR     , TYPE_void, 0);
		CASE_ASM(FOREACH , TYPE_void, 0);
		CASE_ASM(BREAK   , TYPE_void, 0);
		CASE_ASM(CONTINUE, TYPE_void, 0);
		CASE_ASM(TRY     , TYPE_void, 0);
		CASE_ASM(THROW   , TYPE_void, 0);
		CASE_ASM(RETURN  , TYPE_void, 0);
		CASE_ASM(YIELD   , TYPE_void, 0);
		CASE_ASM(PRINT   , TYPE_void, 0);
		CASE_ASM(ASSURE  , TYPE_void, 0);
		CASE_ASM(ASSERT  , TYPE_void, 0);
		CASE_ASM(ERR     , TYPE_void, 0);
		case STT_DECL: case STT_DONE: break;
		default:
			_EXPR_asm(ctx, stmt, etype, DP(ctx->gma)->espidx);
		}
		stmt = DP(stmt)->nextNULL;
	}
	return 0;
}

static void ConstructObjectStruct(Module *m)
{
	// Type Definitions
	const Type *longTy , *shortTy;
	const Type *voidTy  = Type::getVoidTy(m->getContext());
	const Type *hObjectTy, *objectPtr;
	StructType* structTy;
	longTy  = getLongTy(m);
	shortTy = getShortTy(m);
	const Type *voidPtr = PointerType::get(longTy, 0);

	/* hObject */
	std::vector<const Type*>fields;
	fields.push_back(longTy);  /* magicflag */
	fields.push_back(voidPtr); /* cTBL */
	fields.push_back(longTy);  /* refc */
	fields.push_back(voidPtr); /* meta */

	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	m->addTypeName("struct.hObject", structTy);
	hObjectTy = structTy;
	fields.clear();

	/* Object */
	fields.push_back(structTy);
	fields.push_back(voidPtr);
	fields.push_back(voidPtr);
	fields.push_back(voidPtr);
	fields.push_back(voidPtr);
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	objectPtr = PointerType::get(structTy, 0);
	LLVMTYPE_Object = objectPtr;
	m->addTypeName("Object", objectPtr);
	fields.clear();

	/* ObjectField */
	fields.push_back(hObjectTy);
	fields.push_back(objectPtr);
	fields.push_back(PointerType::get(objectPtr, 0));
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	LLVMTYPE_ObjectField = PointerType::get(structTy, 0);
	m->addTypeName("ObjectField", LLVMTYPE_ObjectField);
	fields.clear();

	/* sfp */
	fields.push_back(objectPtr);
	//fields.push_back(LLVMTYPE_Int);
	fields.push_back(LLVMTYPE_Float);
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	const Type *sfpPtr = PointerType::get(structTy, 0);
	m->addTypeName("struct.knh_sfp_t", structTy);
	m->addTypeName("knh_sfp_t_ptr", sfpPtr);
	LLVMTYPE_sfp = sfpPtr;
	fields.clear();

	/* InputStream */
	/* System */
	/* SystemEX */
	fields.push_back(longTy);  // knh_uintptr_t sysid;
	fields.push_back(longTy);  // size_t     ctxcount;
	fields.push_back(voidPtr); // struct knh_DictMap_t*      props;
	fields.push_back(objectPtr/*TODO*/);  // struct knh_InputStream_t*  in;
	fields.push_back(objectPtr/*TODO*/);  // struct knh_OutputStream_t* out;
	fields.push_back(objectPtr/*TODO*/);  // struct knh_OutputStream_t* err;
	fields.push_back(objectPtr/*TODO*/);  // struct knh_String_t*       enc;
	fields.push_back(voidPtr); // struct knh_DictSet_t       *tokenDictSet;
	fields.push_back(voidPtr); // struct knh_DictSet_t   *nameDictCaseSet;
	fields.push_back(longTy);  // size_t                      namecapacity;
	fields.push_back(voidPtr); // knh_nameinfo_t             *nameinfo;
	fields.push_back(voidPtr); // struct knh_DictSet_t      *urnDictSet;
	fields.push_back(voidPtr); // struct knh_Array_t        *urns;
	fields.push_back(voidPtr); // struct knh_DictSet_t      *ClassNameDictSet;
	fields.push_back(voidPtr); // struct knh_DictSet_t  *EventDictCaseSet;
	fields.push_back(voidPtr); // struct knh_DictMap_t      *PackageDictMap;
	fields.push_back(voidPtr); // struct knh_DictMap_t      *URNAliasDictMap;
	fields.push_back(voidPtr); // struct knh_DictSet_t      *dspiDictSet;

	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	fields.clear();
	fields.push_back(hObjectTy);
	fields.push_back(structTy);
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	const Type *sysPtr = PointerType::get(structTy, 0);
	m->addTypeName("System", sysPtr);
	fields.clear();

	/* ctx */
	/* 00 */fields.push_back(voidPtr);   /* share */
	/* 01 */fields.push_back(voidPtr);   /* stat */
	/* 02 */fields.push_back(voidPtr);   /* spi */
	/* 03 */fields.push_back(voidPtr);   //const struct knh_api2_t        *api2;
	/* 04 */fields.push_back(sysPtr);    /* sys */
	/* 05 */fields.push_back(voidPtr); /* script */
	/* stack */
	/* 06 */fields.push_back(sfpPtr); //knh_sfp_t*                   stack;
	/* 07 */fields.push_back(sfpPtr); //knh_sfp_t*                   esp;
	/* 08 */fields.push_back(longTy); //size_t                       stacksize;
	/* 09 */fields.push_back(sfpPtr); //knh_sfp_t*                   stacktop;
	/* 10 */fields.push_back(voidPtr); //void*                        cstack_bottom;
	/* 11 */fields.push_back(objectPtr); //struct knh_Exception_t      *e;
	/* 12 */fields.push_back(objectPtr); //struct knh_Monitor_t        *mon;
	/* memory */
	/* 13 */fields.push_back(objectPtr); //knh_Object_t                *freeObjectList;
	/* 14 */fields.push_back(objectPtr); //knh_Object_t                *freeObjectTail;
	/* 15 */fields.push_back(longTy); //size_t                       freeObjectListSize;
	/* 16 */fields.push_back(longTy); //knh_uintptr_t                mscheck;
	/* 17 */fields.push_back(voidPtr); //knh_fastmem_t               *freeMemoryList;
	/* 18 */fields.push_back(voidPtr); //knh_fastmem_t               *freeMemoryTail;

	/* cache */
	/* 19 */fields.push_back(voidPtr); //knh_mtdcache_t              *mtdcache;
	/* 20 */fields.push_back(voidPtr); //knh_tmrcache_t             *tmrcache;
	/* 21 */fields.push_back(voidPtr); //struct knh_Object_t        **refs;
	/* 22 */fields.push_back(longTy); //size_t                       ref_size;
	/* 23 */fields.push_back(voidPtr); //struct knh_Object_t        **ref_buf;
	/* 24 */fields.push_back(longTy); //size_t                       ref_capacity;
	/* 25 */fields.push_back(voidPtr); //struct knh_Object_t        **queue;
	/* 26 */fields.push_back(longTy); //size_t                       queue_capacity;

	/* 27 */fields.push_back(objectPtr); //struct knh_String_t*         enc;
	/* 28 */fields.push_back(objectPtr); //struct knh_InputStream_t*    in;
	/* 29 */fields.push_back(objectPtr); //struct knh_OutputStream_t*   out;
	/* 30 */fields.push_back(objectPtr); //struct knh_OutputStream_t*   err;
	/* 31 */fields.push_back(objectPtr); //struct knh_Bytes_t*          bufa;
	/* 32 */fields.push_back(objectPtr); //struct knh_OutputStream_t*   bufw;
	/* 33 */fields.push_back(objectPtr); //struct knh_Gamma_t*          gma;
	/* 34 */fields.push_back(objectPtr); //struct knh_DictMap_t*        symbolDictMap;
	/* 35 */fields.push_back(objectPtr); //struct knh_Array_t*          constPools;

	fields.push_back(shortTy);   //knh_flag_t                   flag;
	fields.push_back(shortTy);   //knh_ushort_t                 ctxid;
	fields.push_back(voidPtr);   //struct knh_Context_t        *ctxobjNC;
	fields.push_back(voidPtr);   //struct knh_context_t        *parent;
	fields.push_back(voidPtr);   //knh_mutex_t                 *ctxlock;

	fields.push_back(voidPtr);   //const struct _knh_ExportsAPI_t *api;
	fields.push_back(voidPtr);   //char                            trace[16];
	fields.push_back(voidPtr);   //knh_uint_t                      seq;
	// add here for new entry
	fields.push_back(voidPtr);   //struct knh_ExceptionHandler_t  *ehdrNC;
	fields.push_back(voidPtr);   //struct knh_Object_t            *evaled;


	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	const Type *ctxPtr = PointerType::get(structTy, 0);
	m->addTypeName("struct.context", structTy);
	m->addTypeName("ctx", ctxPtr);
	LLVMTYPE_context = ctxPtr;
	fields.clear();

	// Function Type Definitions
	FunctionType* callTy;
	std::vector<const Type*>args;
	args.push_back(ctxPtr);
	args.push_back(sfpPtr);
	args.push_back(longTy);
	callTy = FunctionType::get(/*Result=*/voidTy,/*Params=*/args,/*isVarArg=*/false);
	LLVMTYPE_fcall = PointerType::get(callTy, 0);
	m->addTypeName("fcall", callTy);
	args.clear();

	/* checkin */
	args.push_back(ctxPtr);
	args.push_back(sfpPtr);
	args.push_back(objectPtr);
	callTy = FunctionType::get(/*Result=*/voidTy,/*Params=*/args,/*isVarArg=*/false);
	LLVMTYPE_checkin = PointerType::get(callTy, 0);
	m->addTypeName("checkin", callTy);
	args.clear();

	/* checkout */
	args.push_back(ctxPtr);
	args.push_back(objectPtr);
	args.push_back(longTy);
	FunctionType* callTy2 = FunctionType::get(/*Result=*/voidTy,/*Params=*/args,/*isVarArg=*/false);
	LLVMTYPE_checkout = PointerType::get(callTy2, 0);
	m->addTypeName("checkout", callTy2);

	/* Method */
	fields.push_back(hObjectTy);
	fields.push_back(voidPtr);
	fields.push_back(shortTy);
	fields.push_back(shortTy);
	fields.push_back(LLVMTYPE_fcall);
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	LLVMTYPE_Method = PointerType::get(structTy, 0);
	m->addTypeName("Method", LLVMTYPE_Method);
	fields.clear();

	/* Array */
	fields.push_back(hObjectTy);
	fields.push_back(voidPtr);
	fields.push_back(longTy); /* size */
	fields.push_back(voidPtr);/* dim */
	fields.push_back(voidPtr);/* api */
	structTy = StructType::get(LLVM_CONTEXT(), fields, false);
	LLVMTYPE_Array = PointerType::get(structTy, 0);
	m->addTypeName("Array", LLVMTYPE_Array);
	fields.clear();

	/* fitr */
	{
		args.clear();
		args.push_back(ctxPtr);
		args.push_back(sfpPtr);
		args.push_back(longTy);
		FunctionType* callTy = FunctionType::get(longTy, args, false);
		LLVMTYPE_itr = PointerType::get(callTy, 0);
		m->addTypeName("fitr", callTy);
	}

	/* Iterator */
	fields.push_back(hObjectTy);
	fields.push_back(voidPtr);
	fields.push_back(LLVMTYPE_itr);
	structTy = StructType::get(m->getContext(), fields, /*isPacked=*/false);
	LLVMTYPE_Iterator = PointerType::get(structTy, 0);
	m->addTypeName("Iterator", LLVMTYPE_Iterator);
	fields.clear();

}

static std::string build_function_name(CTX ctx, knh_Method_t *mtd, std::string suffix)
{
	std::stringstream ss;
	ss << CLASS__(SP(mtd)->cid);
	ss <<  "_" << knh_getmnname(ctx, SP(mtd)->mn) << suffix;
	return ss.str();
}

static Function *build_function(CTX ctx, Module *m, knh_Method_t *mtd)
{
	size_t i;
	knh_ParamArray_t *pa = DP(mtd)->mp;
	knh_class_t retTy = knh_ParamArray_rtype(pa);;
	std::vector<const Type*> argsTy;
	std::string name = build_function_name(ctx, mtd, "");

	argsTy.push_back(LLVMTYPE_context);
	argsTy.push_back(LLVMTYPE_sfp);
	for (i = 0; i < pa->psize; i++) {
		knh_type_t type = knh_ParamArray_getptype(pa, i);
		argsTy.push_back(convert_type(ctx, type));
	}
	FunctionType *fnTy = FunctionType::get(convert_type(ctx, retTy), argsTy, false);
	Function *func = cast<Function>(m->getOrInsertFunction(name, fnTy));
	Function::arg_iterator args = func->arg_begin();
	VNAME_(args++, "ctx");
	VNAME_(args, "sfp");
	return func;
}

static Value *create_loadsfp(CTX ctx, IRBuilder<> *builder, Value *v, knh_type_t type, int idx0)
{
	unsigned int idx = TC_(type, 0);
	v = builder->CreateConstGEP2_32(v, (unsigned)idx0, (unsigned)idx, "gep");
	if (IS_Tint(type) || IS_Tbool(type)) {
		v = builder->CreateBitCast(v, PointerType::get(convert_type(ctx, type), 0), "cast");
	}
	return v;
}

static Function *build_wrapper_func(CTX ctx, Module *m, knh_Method_t *mtd, Function *orig_func)
{
	size_t i;
	knh_ParamArray_t *pa = DP(mtd)->mp;
	knh_class_t retTy = knh_ParamArray_rtype(pa);
	std::string name = build_function_name(ctx, mtd, "_wrapper");
	const FunctionType *fnTy = cast<FunctionType>(m->getTypeByName("fcall"));
	Function *f = cast<Function>(m->getOrInsertFunction(name, fnTy));
	BasicBlock *bb = BasicBlock::Create(LLVM_CONTEXT(), "EntryBlock", f);
	IRBuilder<> *builder = new IRBuilder<>(bb);

	Function::arg_iterator args = f->arg_begin();
	Value *arg_ctx = VNAME_(args++, "ctx");
	Value *arg_sfp = VNAME_(args++, "sfp");
	VNAME_(args++, "rix");

	builder->SetInsertPoint(bb);

	/* load konoha args from sfp and build call params*/
	std::vector<Value*> params;
	params.push_back(arg_ctx);
	params.push_back(arg_sfp);
	for (i = 0; i < pa->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(DP(mtd)->mp, i);
		Value *v = arg_sfp;
		//Value *idx = LLVMInt(i+1);
		v = create_loadsfp(ctx, builder, v, p->type, i+1);
		v = builder->CreateLoad(v, "load");
		params.push_back(v);
	}

	/* call function and  set return values */
	{
		Value *callinst = builder->CreateCall(orig_func, params.begin(), params.end());
		if (retTy != TYPE_void) {
			Value *v = arg_sfp;
			v = create_loadsfp(ctx, builder, v, retTy, K_RTNIDX);
			builder->CreateStore(callinst, v, false/*isVolatile*/);
		}
		builder->CreateRetVoid();
	}
	return f;
}

static void init_first(CTX ctx)
{
	Module *m = new Module("test", LLVM_CONTEXT());
	ConstructObjectStruct(m);
	LLVM_MODULE_SET(ctx, m);
	init_print_func(ctx);
}

static void Init(CTX ctx, knh_Method_t *mtd, knh_Array_t *a)
{
	Module *m = LLVM_MODULE(ctx);
	Function *func;
	BasicBlock *bb;
	IRBuilder<> *builder;

	func = build_function(ctx, m, mtd);
	bb = BasicBlock::Create(LLVM_CONTEXT(), "EntryBlock", func);
	builder = new IRBuilder<>(bb);

	a->ilist[LLVM_IDX_MODULE] = (knh_int_t) m;
	a->ilist[LLVM_IDX_FUNCTION] = (knh_int_t) func;
	a->ilist[LLVM_IDX_BB] = (knh_int_t) bb;
	a->ilist[LLVM_IDX_BUILDER] = (knh_int_t) builder;
	a->ilist[LLVM_IDX_LABELSTACK] = (knh_int_t) new std::vector<label_stack *>();

	size_t i;
	Function::arg_iterator args = func->arg_begin();
	args++;/*ctx*/
	args++;/*sfp*/
	for (i = 0; i < DP(mtd)->mp->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(DP(mtd)->mp, i);
		Value *arg = VNAME_(args++, FN__(p->fn));
		ValueStack_set(ctx, i+1, arg);
	}
}

static void Finish(CTX ctx, knh_Method_t *mtd, knh_Array_t *a, knh_Stmt_t *stmt)
{
	knh_Fmethod f;
	Module *m = LLVM_MODULE(ctx);
	Function *func = LLVM_FUNCTION(ctx);
	ASM_LastRET(ctx, stmt);
	/* asm for script function is done. */

	/* build wrapper function and compile to native code. */
	ExecutionEngine *ee = EngineBuilder(m).setEngineKind(EngineKind::JIT).create();
	Function *func1 = build_wrapper_func(ctx, m, mtd, func);

#ifdef K_USING_DEBUG
	(*m).dump();
#endif

	/* optimization */
	FunctionPassManager OurFPM(m);
	OurFPM.add(new TargetData(*ee->getTargetData()));
	OurFPM.add(createBasicAliasAnalysisPass());
	OurFPM.add(createInstructionCombiningPass());
	OurFPM.add(createReassociatePass());
	OurFPM.add(createGVNPass());
	OurFPM.add(createCFGSimplificationPass());
	OurFPM.doInitialization();
	verifyFunction(*func);
	OurFPM.run(*func);
	verifyFunction(*func1);
	OurFPM.run(*func1);

	f = (knh_Fmethod) ee->getPointerToFunction(func1);
	knh_Method_setFunc(ctx, mtd, f);
	delete LLVM_BUILDER(ctx);
	delete LLVM_BBSTACK(ctx);
}

#define _ALLOW_asm _EXPR_asm
#define _DENY_asm _EXPR_asm
#define _CASE_asm _EXPR_asm
#define _REGISTER_asm _EXPR_asm
#define _DECL_asm _EXPR_asm
#define _ACALL_asm _EXPR_asm
#define _ASM_(prefix, f) prefix _ ## f
#define MAX_CODEASM (31)
typedef int (*fcodeasm)(CTX ctx, knh_Stmt_t *stmt, knh_type_t reqt, int sfpidx);
typedef struct CodeAsm {
	fcodeasm asm_[MAX_CODEASM];
} CodeWriter_t;
struct CodeAsm CODEASM_ = {{
	_ASM_(ASM_PREFIX, ALLOW_asm),
	_ASM_(ASM_PREFIX, DENY_asm),
	_ASM_(ASM_PREFIX, RETURN_asm),
	_ASM_(ASM_PREFIX, YIELD_asm),
	_ASM_(ASM_PREFIX, IF_asm),
	_ASM_(ASM_PREFIX, SWITCH_asm),
	_ASM_(ASM_PREFIX, CASE_asm),
	_ASM_(ASM_PREFIX, WHILE_asm),
	_ASM_(ASM_PREFIX, DO_asm),
	_ASM_(ASM_PREFIX, FOR_asm),
	_ASM_(ASM_PREFIX, THROW_asm),
	_ASM_(ASM_PREFIX, PRINT_asm),
	_ASM_(ASM_PREFIX, ASSURE_asm),
	_ASM_(ASM_PREFIX, ASSERT_asm),
	_ASM_(ASM_PREFIX, REGISTER_asm),
	_ASM_(ASM_PREFIX, DECL_asm),
	_ASM_(ASM_PREFIX, LET_asm),
	_ASM_(ASM_PREFIX, TCAST_asm),
	_ASM_(ASM_PREFIX, OPR_asm),
	_ASM_(ASM_PREFIX, CALL_asm),
	_ASM_(ASM_PREFIX, NEW_asm),
	_ASM_(ASM_PREFIX, FUNCCALL_asm),
	_ASM_(ASM_PREFIX, ACALL_asm),
	_ASM_(ASM_PREFIX, ALT_asm),
	_ASM_(ASM_PREFIX, TRI_asm),
	_ASM_(ASM_PREFIX, AND_asm),
	_ASM_(ASM_PREFIX, OR_asm),
	_ASM_(ASM_PREFIX, W1_asm),
	_ASM_(ASM_PREFIX, SEND_asm),
	_ASM_(ASM_PREFIX, FMTCALL_asm),
	_ASM_(ASM_PREFIX, CALL1_asm),
}};

} /* namespace llvmasm */

#ifdef __cplusplus
extern "C" {
#endif

void knh_LLVMMethod_asm(CTX ctx, knh_Method_t *mtd, knh_Stmt_t *stmtP, knh_type_t ittype, knh_Stmt_t *stmtB)
{
	knh_Array_t *lstack_org, *lstack;
	knh_Array_t *insts_org, *insts;
	int i;

	static int LLVM_IS_INITED = 0;
	if (!LLVM_IS_INITED) {
		llvm::InitializeNativeTarget();
		LLVM_IS_INITED = 1;
		llvmasm::init_first(ctx);
	}
#define STACK_N 64
	insts     = new_Array(ctx, CLASS_Int, 8);
	lstack    = new_Array(ctx, CLASS_Int, STACK_N);
	insts_org  = DP(ctx->gma)->insts;
	lstack_org = DP(ctx->gma)->lstacks;
	BEGIN_LOCAL(ctx, lsfp, 4);
	KNH_SETv(ctx, lsfp[0].o, insts);
	KNH_SETv(ctx, lsfp[1].o, insts_org);
	KNH_SETv(ctx, lsfp[2].o, lstack);
	KNH_SETv(ctx, lsfp[3].o, lstack_org);
	KNH_SETv(ctx, DP(ctx->gma)->insts, insts);
	KNH_SETv(ctx, DP(ctx->gma)->lstacks, lstack);

	{
		BEGIN_LOCAL(ctx, lsfp2, 1);
		for (i = 0; i < STACK_N; i++) {
			lsfp2[0].ivalue = 0;
			lstack->api->add(ctx, lstack, lsfp2);
		}
		END_LOCAL_NONGC(ctx, lsfp2);
	}

	{
		DBG_ASSERT(knh_Array_size(DP(ctx->gma)->insts) == 0);
		SP(ctx->gma)->uline = SP(stmtB)->uline;
		llvmasm::Init(ctx, mtd, insts);
		if(Method_isStatic(mtd) && Gamma_hasFIELD(ctx->gma)) {
			llvmasm::asm_nulval(ctx, 0, DP(ctx->gma)->this_cid);
		}
		llvmasm::_BLOCK_asm(ctx, stmtB, knh_ParamArray_rtype(DP(mtd)->mp), 0);
		llvmasm::Finish(ctx, mtd, insts, stmtB);
	}

	KNH_SETv(ctx, DP(ctx->gma)->insts, insts_org);
	KNH_SETv(ctx, DP(ctx->gma)->lstacks, lstack_org);
	END_LOCAL_NONGC(ctx, lsfp);
}

/* copied from asm.c 
 * TODO Integrate into PRINT functions in asm.c */
static void llvm_PRINTh(CTX ctx, knh_sfp_t *sfp, knh_OutputStream_t *w, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg)
{
	knh_write_ascii(ctx, w, TERM_BNOTE(ctx, LOG_NOTICE));
	if(FLAG_is(flag, K_FLAG_PF_BOL) && FLAG_is(flag, K_FLAG_PF_LINE)) {
		//knh_Method_t *mtd = sfp[-1].mtdNC;
		//DBG_ASSERT(IS_Method(mtd));
		//ULINE_setURI(uline, DP(mtd)->uri);
		knh_write_uline(ctx, w, uline);
	}
	if(IS_bString(msg)) {
		if((msg)->str.len > 0) {
			knh_write_utf8(ctx, w, S_tobytes(msg), !String_isASCII(msg));
		}
	}
	if(FLAG_is(flag, K_FLAG_PF_NAME)) {
		knh_putc(ctx, w, '=');
	}
}

static void llvm_PRINTln(CTX ctx, knh_sfp_t *sfp, knh_OutputStream_t *w, knh_flag_t flag)
{
	if(FLAG_is(flag, K_FLAG_PF_EOL)) {
		knh_write_ascii(ctx, w, TERM_ENOTE(ctx, LOG_NOTICE));
		knh_write_EOL(ctx, w);
	}
	else {
		knh_putc(ctx, w, ',');
		knh_putc(ctx, w, ' ');
	}
}

void llvm_PRINT(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_Object_t *o)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	llvm_PRINTh(ctx, sfp, w, flag, uline, msg);
	knh_write_Object(ctx, w, o, FMT_data);
	llvm_PRINTln(ctx, sfp, w, flag);
}

void llvm_PRINTm(CTX ctx, knh_sfp_t *sfp, knh_String_t *msg, knh_flag_t flag, knh_uline_t uline)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	llvm_PRINTh(ctx, sfp, w, flag, uline, msg);
	if(FLAG_is(flag, K_FLAG_PF_EOL)) {
		knh_write_ascii(ctx, w, TERM_ENOTE(ctx, LOG_NOTICE));
		knh_write_EOL(ctx, w);
	}
}

void llvm_PRINTi(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_int_t n)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	llvm_PRINTh(ctx, sfp, w, flag, uline, msg);
	knh_write_ifmt(ctx, w, K_INT_FMT, n);
	llvm_PRINTln(ctx, sfp, w, flag);
}

void llvm_PRINTf(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_float_t f)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	llvm_PRINTh(ctx, sfp, w, flag, uline, msg);
	knh_write_ffmt(ctx, w, K_FLOAT_FMT, f);
	llvm_PRINTln(ctx, sfp, w, flag);
}

static void llvm_PRINTb(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_bool_t b)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	llvm_PRINTh(ctx, sfp, w, flag, uline, msg);
	knh_write_bool(ctx, w, b);
	llvm_PRINTln(ctx, sfp, w, flag);
}

void CWB_llvm(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c)
{
	size_t pos = BA_size(ctx->bufa);
	KNH_SETv(ctx, sfp[c].o, ctx->bufw);
	sfp[c].ivalue = pos;
}

void TOSTR_llvm(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c)
{
	DBG_ASSERT(IS_OutputStream(sfp[0].w));
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	cwb->pos = (size_t)(sfp[0].ivalue); // reset
	knh_String_t *s = knh_cwb_newString(ctx, cwb);
	KNH_SETv(ctx, sfp[c].o, s);
}

void BOX_llvm(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c, const knh_ClassTBL_t *ct)
{
	Object *v = new_Boxing(ctx, sfp, ct);
	KNH_SETv(ctx, sfp[c].o, v);
}


#ifdef __cplusplus
}
#endif
