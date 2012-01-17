/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with KONOHA_UNDER_LGPL3)
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

#define K_INTERNAL 1
#include <konoha1.h>
#include <konoha1/konohalang.h>
#include <konoha1/inlinelibs.h>

#ifdef __cplusplus
extern "C" {
#endif
#define tkNN(stmt, n)        (stmt)->tokens[(n)]
#define stmtNN(stmt, n)      (stmt)->stmts[(n)]
#define STT_(stmt)   SP(stmt)->stt
#define TT_(tk)   SP(tk)->tt

#include "./data_.h"

//## Class Class.getClassTablePtr();
KMETHOD Class_getClassTablePtr(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	RETURNi_((kint_t)c->cTBL);
}
//## Object Class.getNullValue();
KMETHOD Class_getNullValue(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	RETURN_(KNH_NULVAL(c->cid));
}
//## Class Class.getP1();
KMETHOD Class_getP1(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	RETURN_(new_Type(ctx, c->cTBL->p1));
}
//## Class Class.getSuper();
KMETHOD Class_getSuper(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	kclass_t cid = c->cTBL->supcid;
	RETURN_(new_Type(ctx, cid));
}

//@Public @Native boolean Class.isFinal();
KMETHOD Class_isFinal(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	kclass_t cid = c->cTBL->cid;
	RETURNb_(class_isFinal(cid));
}


//## Class Class.getBaseClass();
KMETHOD Class_getBaseClass(CTX ctx, ksfp_t *sfp _RIX) {
	kClass *c = sfp[0].c;
	kclass_t cid = c->cTBL->bcid;
	RETURN_(new_Type(ctx, cid));
}

//## @Native Int : (Class i);
TYPEMAP Class_Int(CTX ctx, ksfp_t *sfp _RIX)
{
	kClass *c = sfp[1].c;
	RETURNi_(c->cid);
}

#undef Method_isStatic
#define Method_isStatic_(o) (TFLAG_is(kflag_t,DP(o)->flag,FLAG_Method_Static))
//## boolean Method.isStatic();
KMETHOD Method_isStatic(CTX ctx, ksfp_t *sfp _RIX) {
	kMethod *mtd = sfp[0].mtd;
	kbool_t b = Method_isStatic_(mtd);
	RETURNb_(b);
}
#undef Method_isFinal
//## boolean Method.isFinal();
KMETHOD Method_isFinal(CTX ctx, ksfp_t *sfp _RIX) {
	kMethod *mtd = sfp[0].mtd;
	kbool_t b = !Method_isVirtual(mtd);
	RETURNb_(b);
}

//## int Method.indexOfGetterField();
KMETHOD Method_indexOfGetterField(CTX ctx, ksfp_t *sfp _RIX)
{
	kMethod *o = sfp[0].mtd;
	RETURNi_(knh_Method_indexOfGetterField(o));
}

//## int Method.indexOfSetterField();
KMETHOD Method_indexOfSetterField(CTX ctx, ksfp_t *sfp _RIX)
{
	kMethod *o = sfp[0].mtd;
	RETURNi_(knh_Method_indexOfSetterField(o));
}

//## int Method.getMn();
KMETHOD Method_getMn(CTX ctx, ksfp_t *sfp _RIX)
{
	kMethod *o = sfp[0].mtd;
	RETURNi_(o->mn);
}

//## Class TypeMap.getSource();
KMETHOD TypeMap_getSource(CTX ctx, ksfp_t *sfp _RIX) {
	kTypeMap *tmr = sfp[0].tmr;
	RETURN_(new_Type(ctx, tmr->scid));
}

//## Class TypeMap.getTarget();
KMETHOD TypeMap_getTarget(CTX ctx, ksfp_t *sfp _RIX) {
	kTypeMap *tmr = sfp[0].tmr;
	RETURN_(new_Type(ctx, tmr->tcid));
}

//## int Stmt.getStmtSize();
KMETHOD Stmt_getStmtSize(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	RETURNi_(DP(stmt)->size);
}

//## int Stmt.getESPIDX();
KMETHOD Stmt_getESPIDX(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	RETURNi_(DP(stmt)->espidx);
}
//## void Stmt.setESPIDX(int espidx);
KMETHOD Stmt_setESPIDX(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	kint_t espidx = Int_to(kint_t, sfp[1]);
	DP(stmt)->espidx = espidx;
	RETURNvoid_();
}
//## Token Stmt.getT(int n);
KMETHOD Stmt_getT(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	kint_t i = Int_to(kint_t, sfp[1]);
	RETURN_(tkNN(stmt, i));
}

//## Stmt Stmt.next();
KMETHOD Stmt_next(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	kStmtExpr *res = DP(stmt)->nextNULL;
	if (res) {
		RETURN_(res);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## Token Stmt.getS(int n);
KMETHOD Stmt_getS(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	kint_t i = Int_to(kint_t, sfp[1]);
	RETURN_(stmtNN(stmt, i));
}

//## int Stmt.getStmtType();
KMETHOD Stmt_getStmtType(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	RETURNi_(STT_(stmt));
}
//## Stmt Stmt.getStmtPost();
KMETHOD Stmt_getStmtPost(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	RETURN_(DP(stmt)->stmtPOST);
}

//## int Token.getTT();
KMETHOD Token_getTT(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURNi_(TT_(tk));
}
//## Object Token.getD();
KMETHOD Token_getD(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURN_(tk->data);
}
//## Token Token.gettkIDX();
KMETHOD Token_getTkIDX(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURN_(tk->tkIDX);
}
//## String Token.getText();
KMETHOD Token_getText(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURN_(tk->text);
}
//## Class Token.getTokenClass();
KMETHOD Token_getTokenClass(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	kclass_t cid = tk->cid;
	RETURN_(new_Type(ctx, cid));
}
//## int Token.getMn();
KMETHOD Token_getMn(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	kmethodn_t mn = tk->mn;
	RETURNi_(mn);
}

//## Token Stmt.toToken();
KMETHOD Stmt_toToken(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	kTerm *ret;
	if (IS_Term(tk))
		ret = tk;
	else 
		ret = KNH_TNULL(Term);
	RETURN_(ret);
}

//## Class Token.getT();
KMETHOD Token_getT(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	kClass *res = new_Type(ctx, SP(tk)->type);
	RETURN_(res);
}

static int Token_index_(CTX ctx, kTerm *tk) 
{
	return (int)(tk)->index;
}

//## int Token.getTokenIndex();
KMETHOD Token_getTokenIndex(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURNi_(Token_index_(ctx, tk));
}

// String Method.toString()
KMETHOD Method_toString(CTX ctx, ksfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_cid(ctx, cwb->w, (sfp[0].mtd)->cid);
	knh_putc(ctx, cwb->w, '.');
	knh_write_mn(ctx, cwb->w, (sfp[0].mtd)->mn);
	RETURN_(CWB_newString(ctx, cwb, SPOL_ASCII|SPOL_POOLALWAYS));
}

// Class Method.getMethodClass()
KMETHOD Method_getMethodClass(CTX ctx, ksfp_t *sfp _RIX)
{
	kMethod *mtd = sfp[0].mtd;
	RETURN_(new_Type(ctx, mtd->cid));
}
//## Array<Class> Class.getFieldClasses()
KMETHOD Class_getFieldClasses(CTX ctx, ksfp_t *sfp _RIX)
{
	int i = 0;
	kClass *o = sfp[0].c;
	const knh_ClassTBL_t *cTBL = o->cTBL;
	kArray *res = new_Array(ctx, CLASS_Class, 0);
	if (cTBL != NULL) {
		for (; i < cTBL->fsize; i++) {
			knh_Array_add(ctx, res, new_Type(ctx, cTBL->fields[i].type));
		}
	}
	RETURN_(res);
}
//## Array<String> Class.getFieldNames()
KMETHOD Class_getFieldNames(CTX ctx, ksfp_t *sfp _RIX)
{
	kClass *c = sfp[0].c;
	const knh_ClassTBL_t *cTBL = c->cTBL;
	int i = 0;
	kArray *res = new_Array(ctx, CLASS_String, 0);
	if (cTBL != NULL) {
		for (; i < cTBL->fsize; i++) {
			knh_Array_add(ctx, res, knh_getFieldName(ctx, cTBL->fields[i].fn));
		}
	}
	RETURN_(res);
}
//## int Object.getPtr() {
KMETHOD Object_getPtr(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_((kint_t)(long)sfp[0].o);
}

//## int Object.getFlag(int pos);
KMETHOD Object_getFlag(CTX ctx, ksfp_t *sfp _RIX) {
	kObject *o = sfp[0].o;
	RETURNi_((kflag_t)(o)->h.magicflag);
}

//## boolean Token.getMemo();
KMETHOD Token_getMemo(CTX ctx, ksfp_t *sfp _RIX) {
	kTerm *tk = (kTerm*)sfp[0].o;
	RETURNb_(Term_isMEMO1(tk));
}

//## boolean Stmt.getMemo();
KMETHOD Stmt_getMemo(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = (kStmtExpr*)sfp[0].o;
	RETURNb_(Stmt_isMemo1(stmt));
}

///* ------------------------------------------------------------------------ */
///* [Macros] */
//
//#define OP(inst)         ((inst)->op)
//#define PRED(inst)       ((inst)->pred)
//#define pArray_n(a, n)   (((kRawPtr*)knh_Array_n(a, n))->rawptr)
//#define NAME(s)          ""#s""
//#define INST(raw) ((knh_Instruction_t*)(((kRawPtr*)(raw))->rawptr))
//
///* ------------------------------------------------------------------------ */
///* [Structs] */
//
//typedef struct {
//	void *data1;
//	void *data2;
//	void *data3;
//} knh_Symbol_t;
//
//typedef struct {
//	knh_Symbol_t *sym;
//	kopl_t *op;
//	int label;
//	struct kRawPtr *prev;
//	struct kRawPtr *next;
//} knh_Instruction_t;
//
//
//typedef struct {
//	kArray *insts;
//	int id;
//	int topsize;
//	int flag;
//	kArray *kcode;
//	kArray *pred;
//	kArray *succ;
//} knh_Basicblock_t;
//
//typedef struct {
//	kArray *sa;
//	kArray *ia;
//	kArray *ba;
//	kRawPtr *root;
//	kMethod *mtd;
//} knh_Controlflow_t;
//
//typedef knh_Instruction_t KInst_t;
//typedef knh_Basicblock_t  KBlock_t;
///* ------------------------------------------------------------------------ */
///* [Symbol] */
//
//static void Symbol_init(CTX ctx, kRawPtr *o)
//{
//	knh_Symbol_t *sym = (knh_Symbol_t*) malloc(sizeof(knh_Symbol_t));
//	sym->data1 = NULL;
//	sym->data2 = NULL;
//	sym->data3 = NULL;
//	o->rawptr = (void*) sym;
//}
//
//static void Symbol_free(CTX ctx, kRawPtr *o)
//{
//	knh_Symbol_t *sym = (knh_Symbol_t*) o->rawptr;
//	free(sym);
//	o->rawptr = NULL;
//}
//
//DEFAPI(const kclassdef_t*) Symbol(CTX ctx)
//{
//	static kclassdef_t cdef;
//	cdef = *(knh_getDefaultClassDef());
//	cdef.name = NAME(Symbol);
//	cdef.init = Symbol_init;
//	cdef.free = Symbol_free;
//	return (const kclassdef_t*)&cdef;
//}
//
////## Symbol Symbol.new(String name);
//KMETHOD Symbol_new(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Symbol_t *sym = (knh_Symbol_t*)sfp[0].o;
//	RETURN_(sym);
//}
//
////## String Symbol.getOrigName();
//KMETHOD Symbol_getOrigName(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Symbol_t *sym = (knh_Symbol_t*)sfp[0].o;
//	RETURN_(sym);
//}
//
///* ------------------------------------------------------------------------ */
///* [Instruction] */
////## Symbol Instruction.getDefineSymbol();
//KMETHOD Instruction_getDefineSymbol(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = (knh_Instruction_t*)sfp[0].o;
//	knh_Symbol_t *sym = inst->sym;
//	RETURN_(sym);
//}
//
////## Array<Symbol> Instruction.getUseSymbolList();
//KMETHOD Instruction_getUseSymbolList(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = (knh_Instruction_t*)sfp[0].o;
//	(void)inst;
//	kArray *sa;
//	RETURN_(sa);
//}
//
////## Boolean Instruction.isMerging();
//KMETHOD Instruction_isMErging(CTX ctx, ksfp_t *sfp _RIX)
//{
//	RETURNb_(0);
//}
//
////## Boolean Instruction.approve(Int opcode);
//KMETHOD Instruction_approve(CTX ctx, ksfp_t *sfp _RIX)
//{
//	RETURNb_(0);
//}
//
///* ------------------------------------------------------------------------ */
///* [Controlflow] */
//static KBlock_t *knh_KBlock_malloc(CTX ctx, kRawPtr *po)
//{
//	KBlock_t *bb = (KBlock_t*)KNH_MALLOC(ctx, sizeof(KBlock_t));
//	bb->id = -1;
//	bb->topsize = 0;
//	bb->flag = 0;
//	bb->kcode = new_Array(ctx, knh_getcid(ctx, B(NAME(Instruction))), 0);
//	kclass_t cid = knh_getcid(ctx, B(NAME(Basicblock)));
//	bb->pred = new_Array(ctx, cid, 0);
//	bb->succ = new_Array(ctx, cid, 0);
//	return bb;
//}
//
//static void depthFirstSearch(CTX ctx, KBlock_t *bb, int *depth, kbool_t flag)
//{
//	bb->id = *depth;
//	bb->flag = flag;
//	*depth += 1;
//	size_t i;
//	for (i = 0; i < knh_Array_size(bb->succ); i++) {
//		if (((KBlock_t*)pArray_n(bb->succ, i))->flag != flag)
//			depthFirstSearch(ctx, pArray_n(bb->succ, i), depth, flag);
//	}
//}
//
//
//static kArray *gen_instlist(CTX ctx, kRawPtr *po, kKonohaCode *kcode);
//
//kRawPtr *Controlflow_new(CTX ctx, kKonohaCode *kcode, kRawPtr *oinst, kRawPtr *oblock)
//{
//	kArray *klrcode = gen_instlist(ctx, oinst, kcode);
//	size_t i, j, asize = knh_Array_size(klrcode);
//	BEGIN_LOCAL(ctx, lsfp, 2);
//	LOCAL_NEW(ctx, lsfp, 0, kArray *, head, new_Array(ctx, CLASS_Int, asize));
//	LOCAL_NEW(ctx, lsfp, 1, kArray *, stack, new_Array(ctx, knh_getcid(ctx, B(NAME(KBlock))), 0));
//	for (i = 0; i < asize; i++) {
//		KInst_t *inst = (KInst_t*)pArray_n(klrcode, i);
//		if (inst->label != -1) {
//			head->ilist[inst->label] = 1;
//		}
//		if (knh_opcode_hasjump(OP(inst)->opcode) && i + 1 < asize) {
//			head->ilist[i + 1] = 1;
//		}
//	}
//	KBlock_t *root = knh_KBlock_malloc(ctx, oblock);
//	knh_Array_add(ctx, stack, new_RawPtr(ctx, oblock, root));
//	KBlock_t *bb = root;
//	for (i = 0; i < asize; i++) {
//		if (head->ilist[i]) { // beginning of the block
//			//fprintf(stderr, "true\n");
//			//knh_opcode_dump(ctx, OP((KInst_t*)pArray_n(klrcode, i)), ctx->err, 0);
//			if (i != 0) {
//				bb = knh_KBlock_malloc(ctx, oblock);
//				knh_Array_add(ctx, stack, new_RawPtr(ctx, oblock, bb));
//			}
//		}
//		kArray *bbcode = bb->kcode;
//		//knh_opcode_dump(ctx, OP((KInst_t*)pArray_n(klrcode, i)), ctx->err, 0);
//		knh_Array_add(ctx, bbcode, knh_Array_n(klrcode, i));
//	}
//	for (i = 0; i < knh_Array_size(stack); i++) {
//		bb = (KBlock_t*)pArray_n(stack, i);
//		//fprintf(stderr, "bb\n");
//		//for (j = 0; j < knh_Array_size(bb->kcode); j++) {
//		//	knh_opcode_dump(ctx, ((KInst_t*)pArray_n(bb->kcode, j))->op, ctx->err, 0);
//		//}
//		KInst_t *last = (KInst_t*)pArray_n(bb->kcode, knh_Array_size(bb->kcode) - 1);
//		//KInst_t *dest = last->succ;
//		KInst_t *dest;
//		if (last->next) {
//			dest = INST(last->next);
//		}
//		if (dest != NULL && OP(last)->opcode != OPCODE_JMP && OP(last)->opcode != OPCODE_JMP_) {
//			for (j = 0; j < knh_Array_size(stack); j++) {
//				KBlock_t *bbdest = (KBlock_t*)pArray_n(stack, j);
//				if (pArray_n(bbdest->kcode, 0) == dest) {
//					knh_Array_add(ctx, bb->succ, knh_Array_n(stack, j));
//					knh_Array_add(ctx, bbdest->pred, knh_Array_n(stack, i));
//				}
//			}
//		}
//		if (knh_opcode_hasjump(OP(last)->opcode)) {
//			dest = (KInst_t*)pArray_n(klrcode, last->label);
//			for (j = 0; j < knh_Array_size(stack); j++) {
//				KBlock_t *bbdest = (KBlock_t*)pArray_n(stack, j);
//				if (pArray_n(bbdest->kcode, 0) == dest) {
//					knh_Array_add(ctx, bb->succ, knh_Array_n(stack, j));
//					knh_Array_add(ctx, bbdest->pred, knh_Array_n(stack, i));
//				}
//			}
//		}
//	}
//	int depth = 0;
//	depthFirstSearch(ctx, root, &depth, !(root->flag));
//	END_LOCAL(ctx, lsfp);
//	return new_RawPtr(ctx, oblock, root);
//}
//
////static kArray *KonohaCode_convertToInstructionArray(CTX ctx, kKonohaCode *kcode)
////{
////	size_t count = kcode->codesize / sizeof(kopl_t);
////	kclass_t cid = knh_getcid(ctx, B(NAME(Instruction)));
////	kArray *ia = new_Array(ctx, cid, count);
////	int i = 0;
////	kopl_t *op;
////	for (op = kcode->code; op->opcode != OPCODE_RET; op = kcode->code + ++i) {
////		op = kcode->code + i;
////		knh_Instruction_t *inst = new_O(Instruction, cid);
////		inst->op = op;
////		knh_Array_add(ctx, ia, inst);
////		DBG_(knh_opcode_dump(ctx, op, ctx->err, kcode->code));
////	}
////	return ia;
////}
//
//////## Controlflow Method.getControlflow();
////KMETHOD Method_getControlflow(CTX ctx, ksfp_t *sfp _RIX)
////{
////	kMethod *mtd = sfp[0].mtd;
////	kKonohaCode *kcode = DP(mtd)->kcode;
////	kclass_t cid = knh_getcid(ctx, B(NAME(Controlflow)));
////	knh_Controlflow_t *cf = new_O(Controlflow, cid);
////	SP(cf)->ia = KonohaCode_convertToInstructionArray(ctx, kcode);
////	RETURN_(cf);
////}
//
////## Array<Symbol> Controlflow.getAllSymbolList();
//KMETHOD Controlflow_getAllSymbolList(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*)sfp[0].o;
//	(void)cf;
//	kArray *sa;
//	RETURN_(sa);
//}
//
////## Array<Instruction> Controlflow.getUseInstList(Symbol sym);
//KMETHOD Controlflow_getUseInstList(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*)sfp[0].o;
//	(void)cf;
//	kArray *ia;
//	RETURN_(ia);
//}
//
////## Array<Basicblock> Controlflow.getBasicblockList(Symbol sym);
//KMETHOD Controlflow_getBasicblockList(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*)sfp[0].o;
//	(void)cf;
//	kArray *ba;
//	RETURN_(ba);
//}
//
////## Basicblock ByteCode.getEntryBlock();
//KMETHOD ByteCode_getEntryBlock(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*)sfp[0].p->rawptr;
//	RETURN_(cf->root);
//}
//
////## Basicblock Controlflow.getDefineBB(Symbol sym);
//KMETHOD Controlflow_getDefineBB(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*)sfp[0].o;
//	(void)cf;
//	kArray *ba;
//	RETURN_(ba);
//}
//
///* ------------------------------------------------------------------------ */
///* [Basicblock] */
//
//static void Basicblock_init(CTX ctx, kRawPtr *o)
//{
//	//knh_Basicblock_t *bb = (knh_Basicblock_t*) malloc(sizeof(knh_Basicblock_t));
//	//o->rawptr = (void*) bb;
//	o->rawptr = NULL;
//}
//
//static void Basicblock_free(CTX ctx, kRawPtr *o)
//{
//	//knh_Basicblock_t *bb = (knh_Basicblock_t*) o->rawptr;
//	//free(bb);
//	o->rawptr = NULL;
//}
//
//static void Instruction_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level);
//
//static void Basicblock_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
//{
//	knh_Basicblock_t *bb = (knh_Basicblock_t*) o->rawptr;
//	kArray *kcode = bb->kcode;
//	kArray *pred  = bb->pred;
//	kArray *succ  = bb->succ;
//	size_t i;
//	knh_printf(ctx, w, "BB(%d) ", bb->id);
//	knh_putc(ctx, w, '{');
//	knh_write_EOL(ctx, w);
//	knh_write_TAB(ctx, w);
//	knh_printf(ctx, w, "pred=");
//	if (knh_Array_size(pred) == 0) {
//		knh_printf(ctx, w, "none");
//	} else {
//		for (i = 0; i < knh_Array_size(pred); ++i) {
//			KBlock_t *bbp = (KBlock_t*) pArray_n(pred, i);
//			knh_printf(ctx, w, "BB(%d) ", bbp->id);
//		}
//	}
//	knh_write_EOL(ctx, w);
//
//	knh_write_TAB(ctx, w);
//	knh_printf(ctx, w, "succ=");
//	if (knh_Array_size(succ) == 0) {
//		knh_printf(ctx, w, "none");
//	} else {
//		for (i = 0; i < knh_Array_size(succ); ++i) {
//			KBlock_t *bbs = (KBlock_t*) pArray_n(succ, i);
//			knh_printf(ctx, w, "BB(%d) ", bbs->id);
//		}
//	}
//	knh_write_EOL(ctx, w);
//
//	for (i = 0; i < knh_Array_size(kcode); ++i) {
//		knh_write_TAB(ctx, w);
//		Instruction_p(ctx, w, RAWPTR(knh_Array_n(kcode, i)), level);
//	}
//	knh_putc(ctx, w, '}');
//}
//
//
//DEFAPI(const kclassdef_t*) Basicblock(CTX ctx)
//{
//	static kclassdef_t cdef;
//	cdef = *(knh_getDefaultClassDef());
//	cdef.name = NAME(Basicblock);
//	cdef.init = Basicblock_init;
//	cdef.free = Basicblock_free;
//	cdef.p    = Basicblock_p;
//	return (const kclassdef_t*)&cdef;
//}
//
//#define int3() asm volatile("int3");
//#define BB(sfp) ((knh_Basicblock_t*)((sfp.p)->rawptr))
//
////## Basicblock Basicblock.new(Basicblock _);
//KMETHOD Basicblock_new(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = (knh_Basicblock_t*) malloc(sizeof(*bb));
//	kRawPtr *o = new_RawPtr(ctx, sfp[1].p, bb);
//	RETURN_(o);
//}
//
////## Instruction Basicblock.getInst(int i);
//KMETHOD Basicblock_getInst(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	knh_Instruction_t *inst;
//	int3();
//	RETURN_(inst);
//}
//
////## Instruction Basicblock.getDefineInst(Symbol sym);
//KMETHOD Basicblock_getDefineInst(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	knh_Symbol_t *sym;
//	int3();
//	RETURN_(sym);
//}
//
////## Boolean Basicblock.removeInst(Instruction inst);
//KMETHOD Basicblock_removeInst(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	RETURNb_(0);
//}
//
////## Boolean Basicblock.insertBefore(Instruction inst1, Instruction inst2);
//KMETHOD Basicblock_insertBefore(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	int3();
//	RETURNb_(0);
//}
//
////## Boolean Basicblock.insertAfter(Instruction inst1, Instruction inst2);
//KMETHOD Basicblock_insertAfter(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	kRawPtr *insto1 = sfp[1].p;
//	kRawPtr *insto2 = sfp[2].p;
//	size_t i, size = knh_Array_size(bb->kcode);
//	for (i = 0; i < size; ++i) {
//		kRawPtr *insto = RAWPTR(knh_Array_n(bb->kcode, i));
//		if (insto == insto1) {
//			knh_Instruction_t *i1 = INST(insto1);
//			knh_Instruction_t *i2 = INST(insto2);
//			kRawPtr *next = i1->next;
//			i1->next = insto2;
//			INST(next)->prev = insto2;
//
//			i2->prev = insto1;
//			i2->next = next;
//		}
//	}
//
//	RETURNb_(0);
//}
//
////## Array<Basicblock> Basicblock.getSuccessors();
//KMETHOD Basicblock_getSuccessors(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	kArray *ba;
//	RETURN_(ba);
//}
//
////## Array<Basicblock> Basicblock.getPredecessors();
//KMETHOD Basicblock_getPredecessors(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	(void)bb;
//	kArray *ba;
//	int3();
//	RETURN_(ba);
//}
//
////## Instruction Basicblock.getFirstInstruction()
//KMETHOD Basicblock_getFirstInstruction(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Basicblock_t *bb = BB(sfp[0]);
//	RETURN_(knh_Array_n(bb->kcode, 0));
//}
//
//static kObject *Instruction_copy(CTX ctx, kRawPtr *po, kopl_t *pc)
//{
//	kRawPtr *o_ = (kRawPtr*) new_RawPtr(ctx, po, pc);
//	knh_Instruction_t *inst = malloc(sizeof(knh_Instruction_t));
//	inst->op = malloc(sizeof(kopl_t));
//	inst->sym = NULL;
//	inst->prev = inst->next = NULL;
//	memcpy(inst->op, pc, sizeof(kopl_t));
//	if (knh_opcode_hasjump(inst->op->opcode)) {
//		inst->label = 0;
//	} else {
//		inst->label = -1;
//	}
//
//	o_->rawptr = (void*) inst;
//	return (kObject*) o_;
//}
//
//static kArray *gen_instlist(CTX ctx, kRawPtr *po, kKonohaCode *kcode)
//{
//	kclass_t p1 = knh_getcid(ctx, B("Instruction"));
//	kArray *a = new_Array(ctx, p1, SP(kcode)->codesize);
//	kopl_t *pc = SP(kcode)->code;
//	size_t i, codesize = 0;
//	while (pc->opcode != OPCODE_RET) {
//		knh_Array_add(ctx, a, Instruction_copy(ctx, po, pc));
//		pc++;
//		codesize++;
//	}
//	knh_Array_add(ctx, a, Instruction_copy(ctx, po, pc));
//
//	knh_Instruction_t *instS = INST(knh_Array_n(a, 0));
//	knh_Instruction_t *instL = INST(knh_Array_n(a, codesize-1));
//	instS->prev = instL->next = NULL;
//	for (i = 0; i < codesize; ++i) {
//		kRawPtr *p = RAWPTR(knh_Array_n(a, i));
//		kRawPtr *c = RAWPTR(knh_Array_n(a, i+1));
//		knh_Instruction_t *instP = INST(p);
//		knh_Instruction_t *instC = INST(c);
//		instP->next = c;
//		instC->prev = p;
//	}
//	return a;
//}
//
//#define isNativeCompiled(kcode) (IS_KonohaCode(kcode) && KonohaCode_isNativeCompiled(kcode))
////## method Array<Instruction> Func.getInstList(Instruction _, Basicblock _);
//KMETHOD Func_getInstList(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kFunc *fo = sfp[0].fo;
//	kRawPtr *oinst  = sfp[1].p;
//
//	kMethod *mtd = fo->mtd;
//	kKonohaCode *kcode = DP(mtd)->kcode;
//	kArray *a;
//	if (isNativeCompiled(kcode)) {
//		KNH_P("native method=NULL");
//		RETURN_(KNH_NULL);
//	}
//	a = gen_instlist(ctx, oinst, kcode);
//	RETURN_(a);
//}
//
////## method ByteCode Func.getBytecodes(Instruction _, Basicblock _, Bytecode _);
//KMETHOD Func_getBytecodes(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kFunc *fo = sfp[0].fo;
//	kRawPtr *oinst  = sfp[1].p;
//	kRawPtr *oblock = sfp[2].p;
//
//	kMethod *mtd = fo->mtd;
//	kKonohaCode *kcode = DP(mtd)->kcode;
//	//kArray *a;
//	if (isNativeCompiled(kcode)) {
//		KNH_P("native method=NULL");
//		RETURN_(KNH_NULL);
//	}
//	knh_Controlflow_t *cfg = (knh_Controlflow_t*)malloc(sizeof(*cfg));
//	kRawPtr *obbroot = Controlflow_new(ctx, kcode, oinst, oblock);
//	kRawPtr *ocfg    = new_RawPtr(ctx, sfp[3].p, cfg);
//	cfg->root = obbroot;
//	cfg->mtd  = mtd;
//	RETURN_(ocfg);
//}
//
//static void Controlflow_init(CTX ctx, kRawPtr *o)
//{
//	//knh_Controlflow_t *cfg = (knh_Controlflow_t*) malloc(sizeof(knh_Controlflow_t));
//	//cfg->sa = new_Array(ctx, knh_getcid(ctx, B(NAME(Symbol))), 0);
//	//cfg->ia = new_Array(ctx, knh_getcid(ctx, B(NAME(Instruction))), 0);
//	//cfg->ba = new_Array(ctx, knh_getcid(ctx, B(NAME(Basicblock))), 0);
//	//o->rawptr = (void*) cfg;
//	o->rawptr = NULL;
//}
//
//static void Controlflow_reftrace(CTX ctx, kRawPtr *o FTRARG)
//{
//	//knh_Controlflow_t *cf = (knh_Controlflow_t*)o->rawptr;
//	//KNH_ADDREF(ctx, SP(cf)->sa);
//	//KNH_ADDREF(ctx, SP(cf)->ia);
//	//KNH_ADDREF(ctx, SP(cf)->ba);
//	//KNH_SIZEREF(ctx);
//}
//
//static void Controlflow_free(CTX ctx, kRawPtr *o)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*) o->rawptr;
//	free(cf);
//	o->rawptr = NULL;
//}
//
//DEFAPI(const kclassdef_t*) Controlflow(CTX ctx)
//{
//	static kclassdef_t cdef;
//	cdef = *(knh_getDefaultClassDef());
//	cdef.name = NAME(Controlflow);
//	cdef.init = Controlflow_init;
//	cdef.reftrace = Controlflow_reftrace;
//	cdef.free = Controlflow_free;
//	return (const kclassdef_t*)&cdef;
//}
//
//DEFAPI(const kclassdef_t*) ByteCode(CTX ctx)
//{
//	static kclassdef_t cdef;
//	cdef = *(knh_getDefaultClassDef());
//	cdef.name = "ByteCode";
//	cdef.init = Controlflow_init;
//	cdef.reftrace = Controlflow_reftrace;
//	cdef.free = Controlflow_free;
//	return (const kclassdef_t*)&cdef;
//}
//
//struct HasInst {
//	kopcode_t opcode;
//	kArray *bblist;
//};
//
//void hasInst(CTX ctx, kRawPtr *bbo, void *thunk)
//{
//	KBlock_t *bb = (KBlock_t*)(bbo->rawptr);
//	struct HasInst *hinst = (struct HasInst*) thunk;
//	kopcode_t opcode = hinst->opcode;
//	size_t i, codesize = knh_Array_size(bb->kcode);
//	for (i = 0; i < codesize; ++i) {
//		KInst_t *inst = (KInst_t*) pArray_n(bb->kcode, i);
//		if (OP(inst)->opcode == opcode) {
//			knh_Array_add(ctx, hinst->bblist, bbo);
//			break;
//		}
//	}
//}
//
//typedef void (*bbtrace_t)(CTX ctx, kRawPtr *bbo, void *thunk);
//void BasicBlock_traverse(CTX ctx, kRawPtr *root, void *refbuf, bbtrace_t fbb);
//
////##Instruction[] ByteCode.searchBBContains(int opcode);
//KMETHOD ByteCode_searchBBContains(CTX ctx, ksfp_t *sfp _RIX)
//{
//	struct HasInst hinst;
//	knh_Controlflow_t *cfg = (knh_Controlflow_t*) sfp[0].p->rawptr;
//	kRawPtr *rooto = cfg->root;
//	hinst.opcode = Int_to(kopcode_t, sfp[1]);
//	hinst.bblist = new_Array(ctx, knh_getcid(ctx, B("Basicblock")), 0);
//	//fprintf(stderr, "%p %d %s\n", cfg, opcode, OPDATA[opcode].name);
//	BasicBlock_traverse(ctx, rooto, &hinst, hasInst);
//	RETURN_(hinst.bblist);
//}
//
///**********************************************************************/
///* [Instruction] */
//
//static void Instruction_init(CTX ctx, kRawPtr *o)
//{
//	//knh_Instruction_t *inst = (knh_Instruction_t*) malloc(sizeof(knh_Instruction_t));
//	//inst->sym = NULL;
//	//inst->op = NULL;
//	//inst->label = 0;
//	//o->rawptr = (void*) inst;
//	o->rawptr = NULL;
//}
//
//static void Instruction_free(CTX ctx, kRawPtr *o)
//{
//	knh_Instruction_t *inst = (knh_Instruction_t*) o->rawptr;
//	if (inst && inst->op) {
//		KNH_FREE(ctx, inst->op, sizeof(kopl_t));
//	}
//	free(inst);
//	o->rawptr = NULL;
//}
//
//static void Instruction_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
//{
//	knh_Instruction_t *inst = (knh_Instruction_t*) o->rawptr;
//	kopl_t *op = inst->op;
//	if (op) {
//		knh_opcode_dump(ctx, op, w, NULL);
//	} else {
//		knh_printf(ctx, w, "NOP_OP");
//		knh_write_EOL(ctx, w);
//	}
//}
//
//DEFAPI(const kclassdef_t*) Instruction(CTX ctx)
//{
//	static kclassdef_t cdef;
//	cdef = *(knh_getDefaultClassDef());
//	cdef.name = NAME(Instruction);
//	cdef.init = Instruction_init;
//	cdef.p    = Instruction_p;
//	cdef.free = Instruction_free;
//	return (const kclassdef_t*)&cdef;
//}
//
////## Instruction Instruction.new(Int opcode, dynamic d1, dynamic d2, dynamic d3, dynamic d4, Instruction _);
//KMETHOD Instruction_new(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = (knh_Instruction_t*) malloc(sizeof(knh_Instruction_t));
//	kRawPtr *o = new_RawPtr(ctx, sfp[6].p, inst);
//	kopl_t *op = malloc(sizeof(kopl_t));
//	op->opcode = Int_to(kopcode_t, sfp[1]);
//	inst->op = op;
//
//	if (knh_opcode_hasjump(op->opcode)) {
//		inst->label = 0;
//	}
//	size_t i;
//	for (i = 0; i < OPDATA[op->opcode].size; i++) {
//		kObject *o = sfp[i+2].o;
//		kclass_t cid = O_cid(o);
//		switch (cid) {
//		case CLASS_String:
//			//DBG_P("string \"%s\"", String_to(char *, sfp[i + 2]));
//			/* TODO */
//			if (strcmp(S_totext((kString*)o), "x") == 0) {
//				op->data[i] = 5;
//			} else {
//				op->p[i] = sfp[i+2].o;
//			}
//			break;
//		case CLASS_Int: case CLASS_Float: case CLASS_Boolean:
//			{
//				kunbox_t n = O_ndata(o);
//				//DBG_P("ndata %d", n);
//				op->data[i] = n;
//				break;
//			}
//		default:
//			//DBG_P("others cid=%d", cid);
//			/* TODO */
//			op->p[i] = sfp[i+2].o;
//			break;
//		}
//	}
//	RETURN_(o);
//}
//
////## Instruction Instruction.getNext();
//KMETHOD Instruction_getNext(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = INST(sfp[0].p);
//	kRawPtr *po = RAWPTR(KNH_NULL);
//	if (inst->next) {
//		po = inst->next;
//	}
//	RETURN_(po);
//}
//
////## Instruction Instruction.getPrev();
//KMETHOD Instruction_getPrev(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = INST(sfp[0].p);
//	kRawPtr *po = RAWPTR(KNH_NULL);
//	if (inst->prev) {
//		po = inst->prev;
//	}
//	RETURN_(po);
//}
//
////## Method ByteCode.save();
//KMETHOD ByteCode_save(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Controlflow_t *cf = (knh_Controlflow_t*) sfp[0].p->rawptr;
//	kMethod *org = cf->mtd;
//	kKonohaCode *kcode = DP(org)->kcode;
//	kRawPtr *bbrooto = cf->root;
//	kopl_t *newcode = malloc(sizeof(kopl_t)*1024);
//	//kopl_t *op = newcode;
//
//	kRawPtr *bbo = bbrooto;
//	KBlock_t *bb = (KBlock_t*)bbo->rawptr;
//
//	BEGIN_LOCAL(ctx, lsfp, 1);
//	LOCAL_NEW(ctx, lsfp, 0, kArray *, stack, new_Array(ctx, CLASS_Int, 0));
//	knh_Array_add(ctx, stack, bbo);
//	bbo = (kRawPtr*)knh_Array_n(stack, knh_Array_size(stack) - 1);
//	bb  = ((KBlock_t*)bbo->rawptr);
//	//KInst_t *inst = (KInst_t*) pArray_n(bb->kcode, 0);
//	//klr_THCODE_t t0 = {NULL, 0, OPCODE_THCODE, 0 , 2, 0, 0};
//	//klr_NSET_t   t1 = {NULL, 0, OPCODE_NSET  , 0 , 5, 0, 0};
//	//klr_iJLTC_t  t2 = {NULL, 0, OPCODE_iJLTC , 0 ,-1, 5,10};
//	//klr_iADDC_t  t3 = {NULL, 0, OPCODE_iADDC , 0 , 5, 5,10};
//	//klr_NMOV_t   t4 = {NULL, 0, OPCODE_NMOV  , 0 ,-7, 5, 0};
//	//klr_JMP_t    t5 = {NULL, 0, OPCODE_JMP   , 0 ,-1, 0, 0};
//	//klr_iADDC_t  t6 = {NULL, 0, OPCODE_iADDC , 0 , 5, 5,20};
//	//klr_JMP_t    t7 = {NULL, 0, OPCODE_JMP   , 0 ,-1, 0, 0};
//	//klr_P_t      t8 = {NULL, 0, OPCODE_P     , 0,   ,  ,  };
//	//klr_RET_t    t8 = {NULL, 0, OPCODE_RET   , 0 , 0, 0, 0};
//	//t0.th = ((klr_THCODE_t*)inst->op)->th;
//	//memcpy(&newcode[0], &t0, sizeof(kopl_t));
//	//memcpy(&newcode[1], &t1, sizeof(kopl_t));
//	//memcpy(&newcode[2], &t2, sizeof(kopl_t));
//	//memcpy(&newcode[3], &t3, sizeof(kopl_t));
//	//memcpy(&newcode[4], &t4, sizeof(kopl_t));
//	//memcpy(&newcode[5], &t5, sizeof(kopl_t));
//	//memcpy(&newcode[6], &t6, sizeof(kopl_t));
//	//memcpy(&newcode[7], &t7, sizeof(kopl_t));
//	//memcpy(&newcode[8], &t8, sizeof(kopl_t));
//	//((klr_iJLTC_t*)&newcode[2])->jumppc = (newcode+6);
//	//((klr_iJLTC_t*)&newcode[5])->jumppc = (newcode+8);
//	//((klr_iJLTC_t*)&newcode[7])->jumppc = (newcode+3);
//
//	//while (knh_Array_size(stack) > 0) {
//	//	bbo = (kRawPtr*)knh_Array_n(stack, knh_Array_size(stack) - 1);
//	//	bb  = ((KBlock_t*)bbo->rawptr);
//	//	Basicblock_p(ctx, KNH_STDOUT, bbo, 0);
//	//	knh_Array_clear(ctx, stack, knh_Array_size(stack) - 1);
//
//	//	size_t i, codesize = knh_Array_size(bb->kcode);
//	//	for (i = 0; i < codesize; ++i) {
//	//		KInst_t *inst = (KInst_t*) pArray_n(bb->kcode, i);
//	//		fprintf(stderr, "%p %s\n", inst, OPDATA[inst->op->opcode].name);
//	//		memcpy(op, inst->op, sizeof(kopl_t));
//	//	}
//
//	//	for (i = 0; i < knh_Array_size(bb->succ); i++) {
//	//		KBlock_t *bbs = (KBlock_t*)pArray_n(bb->succ, i);
//	//		if (bbs->flag != flag) {
//	//			knh_Array_add(ctx, stack, knh_Array_n(bb->succ, i));
//	//			bbs->flag = flag;
//	//		}
//	//	}
//	//}
//	(org)->pc_start = knh_VirtualMachine_run(ctx, ctx->esp + 1, newcode);
//	asm volatile("int3");
//	//knh_VirtualMachine_run(ctx, lsfp+0, CODE_VEXEC);
//	END_LOCAL(ctx, lsfp);
//
//	kcode->code = newcode;
//	RETURN_(org);
//}
//
//
///* ------------------------------------------------------------------------ */
//
//#ifdef _SETUP
//
///* ------------------------------------------------------------------------ */
///* [CONST] */
//
//static knh_IntData_t IntConstData[] = {
//#include "./code_.h"
//	{"PHI", OPCODE_MAX},
//	{NULL, KINT0}
//};
//

typedef struct knh_funcname_t {
	char *name;
	void *func;
} knh_funcname_t;
extern knh_IntData_t _FuncData[];
static const knh_IntData_t MethodInt[] = {
	{"MN_get", MN_get},
	{"MN_set", MN_set},
	{"MN_getSize", MN_getSize},
	{NULL, 0}
};

static const knh_IntData_t FNInt[] = {
	{"FN_vargs", FN_vargs},
	{NULL, 0}
};
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{

	kapi->setPackageProperty(ctx, "name", "lang");
	kapi->setPackageProperty(ctx, "version", "0.0");
	kapi->loadClassIntConst(ctx, knh_getcid(ctx, STEXT("konoha.Method")), MethodInt);
	kapi->loadClassIntConst(ctx, knh_getcid(ctx, STEXT("konoha.Stmt")), StmtInt);
	kapi->loadClassIntConst(ctx, knh_getcid(ctx, STEXT("konoha.Token")), TokenInt);
	kapi->loadClassIntConst(ctx, knh_getcid(ctx, STEXT("konoha.Stmt")), (knh_IntData_t*)_FuncData);
	kapi->loadClassIntConst(ctx, knh_getcid(ctx, STEXT("konoha.Stmt")), FNInt);
	RETURN_PKGINFO("konoha.lang");
}

//
//
//
//DEFAPI(void) constInstruction(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
//{
//	kapi->loadClassIntConst(ctx, cid, IntConstData);
//}
//
//#endif
//
#ifdef __cplusplus
}
#endif
//
/////* ------------------------------------------------------------------------ */
/////* [Others] */
////
////static void analyzeCallRegister(CTX ctx, kArray *a, KInst_t *inst)
////{
////	kintptr_t max, min = OP(inst)->data[1];
////	if (OP(inst)->opcode == OPCODE_FASTCALL0) {
////		if (OP(inst)->p[4] != NULL) {
////			max = min + 2 * (knh_Method_psize((kMethod*)OP(inst)->p[4]) + 1);
////		} else {
////			DBG_P("fastcall psize=0");
////			max = min + 2;
////		}
////	} else {
////		max = OP(inst)->data[2];
////	}
////	kopl_t *op;
////	KInst_t *pinst = inst;
////	while (1) {
////		if (PRED(pinst) == NULL) break;
////		op = OP(PRED(pinst));
////		pinst = PRED(pinst);
////		if (op->opcode == OPCODE_CHKIDX || op->opcode == OPCODE_CHKIDXC) continue;
////		if (!FLAG_is(OPDATA[op->opcode].flag, F_DEF)) break;
////		if ((op->opcode == OPCODE_TR || op->opcode == OPCODE_OMOV) && op->data[0] == min) {
////			knh_Array_add(ctx, a, op->data[0]);
////			break;
////		}
////		if (FLAG_is(OPDATA[op->opcode].flag, F_MDEF)) {
////			switch (op->opcode) {
////				case OPCODE_NNMOV: case OPCODE_ONMOV: case OPCODE_OOMOV:
////					if (min <= op->data[2] && op->data[2] <= max)
////						knh_Array_add(ctx, a, op->data[2]);
////					if (min <= op->data[0] && op->data[0] <= max)
////						knh_Array_add(ctx, a, op->data[0]);
////					break;
////				case OPCODE_NSET4: case OPCODE_OSET4:
////					if (min <= op->data[0] + 6 && op->data[0] + 6 <= max)
////						knh_Array_add(ctx, a, op->data[0] + 6);
////				case OPCODE_NSET3: case OPCODE_OSET3:
////					if (min <= op->data[0] + 4 && op->data[0] + 4 <= max)
////						knh_Array_add(ctx, a, op->data[0] + 4);
////				case OPCODE_NSET2: case OPCODE_OSET2:
////					if (min <= op->data[0] + 2 && op->data[0] + 2 <= max)
////						knh_Array_add(ctx, a, op->data[0] + 2);
////					if (min <= op->data[0] && op->data[0] <= max)
////						knh_Array_add(ctx, a, op->data[0]);
////					break;
////				default:
////					DBG_P("no support");
////					KNH_ABORT();
////			}
////		} else if (min <= op->data[0] && op->data[0] <= max) {
////			knh_Array_add(ctx, a, op->data[0]);
////		} else {
////			break;
////		}
////	}
////	size_t i;
////	for (i = 0; i < knh_Array_size(a) / 2; i++) {
////		knh_Array_swap(ctx, a, i, knh_Array_size(a) - i - 1);
////	}
////}
////
////static void setManipulatedCode(CTX ctx, kopl_t *op, kArray *klrcode) {
////	size_t i;
////	for (i = 0; i < knh_Array_size(klrcode); i++) {
////		KInst_t *inst = (KInst_t*)pArray_n(klrcode, i);
////		memcpy(op, OP(inst), sizeof(kopl_t));
////		if (knh_opcode_hasjump(OP(inst)->opcode)) {
////			//fprintf(stderr, "apply jump label %d\n", inst->label);
////			//knh_opcode_dump(ctx, op, ctx->err, NULL);
////			op->p[0] = (op - i) + inst->label;
////			//knh_opcode_dump(ctx, op, ctx->err, NULL);
////		}
////		op += 1;
////	}
////}
////
////static void deconstructCfg(CTX ctx, kArray *klrcode, KBlock_t *bb, kbool_t flag, size_t codesize)
////{
////	bb->flag = flag;
////	bb->topsize = codesize;
////	size_t i;
////	for (i = 0; i < knh_Array_size(bb->kcode); i++) {
////		knh_Array_add(ctx, klrcode, knh_Array_n(bb->kcode, i));
////	}
////	for (i = 0; i < knh_Array_size(bb->succ); i++) {
////		if (((KBlock_t*)pArray_n(bb->succ, i))->flag != flag) {
////			if (i == 1) {
////				KInst_t *last = (KInst_t*)pArray_n(bb->kcode, knh_Array_size(bb->kcode) - 1);
////				DBG_ASSERT(knh_opcode_hasjump(OP(last)->opcode));
////				DBG_P("0 last->label=%d to %ld\n", last->label, knh_Array_size(klrcode));
////				last->label = knh_Array_size(klrcode);
////			}
////			deconstructCfg(ctx, klrcode, pArray_n(bb->succ, i), flag, codesize + knh_Array_size(bb->kcode));
////		} else {
////			KInst_t *last = (KInst_t*)pArray_n(bb->kcode, knh_Array_size(bb->kcode) - 1);
////			DBG_ASSERT(knh_opcode_hasjump(OP(last)->opcode));
////			KBlock_t *succ = (KBlock_t*)pArray_n(bb->succ, i);
////			DBG_P("1 last->label=%d to %ld\n", last->label, succ->topsize);
////			last->label = succ->topsize;
////		}
////	}
////}
////
////static void knh_kcode_print(CTX ctx, kArray *klrcode)
////{
////	if (knh_Array_size(klrcode) == 0) return;
////	KInst_t *kinst = (KInst_t*)pArray_n(klrcode, 0);
////	if (kinst->start == NULL) return;
////	size_t i, asize = knh_Array_size(klrcode);
////	BEGIN_LOCAL(ctx, lsfp, 1);
////	LOCAL_NEW(ctx, lsfp, 0, kArray *, dest, new_Array(ctx, CLASS_Int, asize));
////	for (i = 0; i < asize; i++) {
////		KInst_t *inst = (KInst_t*)pArray_n(klrcode, i);
////		if (dest->ilist[i]) {
////			fprintf(stderr, ">> ");
////		} else {
////			fprintf(stderr, "   ");
////		}
////		knh_opcode_dump(ctx, OP(inst), ctx->err, OP(inst) - i);
////	}
////	END_LOCAL(ctx, lsfp);
////}
////
/////* ------------------------------------------------------------------------ */
/////* [Func Method] */
////
////## method Array<KInst> Func.getKCode();
////KMETHOD Func_getKCode(CTX ctx, ksfp_t *sfp, long rix)
////{
////	kFunc *fo = sfp[0].fo;
////	kMethod *mtd = fo->mtd;
////	kKonohaCode *kcode = DP(mtd)->kcode;
////	if (kcode == (kKonohaCode*)KNH_NULL) {
////		fprintf(stderr, "kcode=NULL\n");
////		RETURN_(KNH_NULL);
////	}
////	size_t count, i = 0;
////	count = kcode->codesize / sizeof(kopl_t);
////	kclass_t cid = knh_getcid(ctx, B(NAME(KInst)));
////	kArray *a = new_Array(ctx, cid, count);
////	KInst_t *pred, *inst = NULL;
////	while (1) {
////		kopl_t *op = kcode->code + i;
////		pred = inst;
////		inst = knh_KInst_malloc(ctx);
////		inst->start = kcode->code;
////		inst->op = *op;
////		if (pred != NULL) {
////			inst->pred = pred;
////			pred->succ = inst;
////		}
////		if (knh_opcode_hasjump(op->opcode)) {
////			inst->label = (int)((kopl_t*)op->p[0] - kcode->code);
////		}
////		knh_Array_add(ctx, a, new_RawPtr(ctx, inst, knh_KInst_pfree, CLASS_Object, NAME(KInst)));
////		DBG_(knh_opcode_dump(ctx, op, ctx->err, kcode->code));
////		if (op->opcode == OPCODE_RET) break;
////		i++;
////	}
////	RETURN_(a);
////}
////
//////## method Array<KInst> Func.setKCode(Array<KInst> kcode);
////KMETHOD Func_setKCode(CTX ctx, ksfp_t *sfp, long rix)
////{
////	kFunc *fo = sfp[0].fo;
////	kMethod *mtd = fo->mtd;
////	kArray *klrcode = sfp[1].a;
////	if (klrcode == (kArray*)KNH_NULL) {
////		fprintf(stderr, "klrcode=NULL\n");
////		RETURNvoid_();
////	}
////	kKonohaCode *kcode = new_(KonohaCode);
////	SP(kcode)->uri = SP(DP(mtd)->kcode)->uri;
////	SP(kcode)->codesize = knh_Array_size(klrcode) * sizeof(kopl_t);
////	SP(kcode)->code = (kopl_t*)KNH_MALLOC(ctx, SP(kcode)->codesize);
//////	fprintf(stderr, "before\n");
//////	KonohaCode_print(ctx, DP(mtd)->kcode);
////	setManipulatedCode(ctx, SP(kcode)->code, klrcode);
//////	fprintf(stderr, "after\n");
//////	KonohaCode_print(ctx, kcode);
//////	if (Method_isObjectCode(mtd)) {
//////		fprintf(stderr, "hi\n");
//////		KNH_SETv(ctx, DP(mtd)->kcode, kcode);
//////	} else {
//////		fprintf(stderr, "hello\n");
//////		Method_setObjectCode(mtd, 1);
//////		KNH_INITv(DP(mtd)->kcode, kcode);
//////	}
//////	Method_setObjectCode(mtd, 1);
//////	KNH_INITv(DP(mtd)->kcode, kcode);
////	Method_setFunc(ctx, mtd, knh_Fmethod_runVM);
////	KNH_SETv(ctx, DP(mtd)->kcode, kcode);
////	(mtd)->pc_start = knh_VirtualMachine_run(ctx, ctx->esp + 1, SP(kcode)->code);
////	if (knh_isSystemVerbose()) {
////		knh_mtdcache_t mcache = {0, 0, NULL};
////		knh_write_Object(ctx, KNH_STDOUT, ctx->esp, &mcache, UPCAST(mtd), MN__dump);
////		knh_write_EOL(ctx, KNH_STDOUT);
////	}
////	RETURN_(kcode);
////}
////
/////* ------------------------------------------------------------------------ */
/////* [KInst Method] */
////
////KMETHOD Instruction_new(CTX ctx, ksfp_t *sfp, long rix)
////{
////	knh_Instruction_t *inst = (knh_Instruction_t*)sfp[0].o;
////	RETURN_(inst);
////}
////
//////## method dynamic KInst.get(Int n);
////KMETHOD KInst_get(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	size_t n = knh_array_index(ctx, sfp, Int_to(size_t, sfp[1]), OPDATA[OP(inst)->opcode].size);
////	switch (OPDATA[OP(inst)->opcode].types[n]) {
////		case VMT_ADDR:
////			DBG_P("addr");
////			RETURNa_(new_Int(ctx, CLASS_Int, inst->label));
////			break;
////		case VMT_SFPIDX: case VMT_R: case VMT_RN: case VMT_RO: case VMT_SFPIDX2: case VMT_SFX:
////		case VMT_U: case VMT_CID: case VMT_INT:
////			DBG_P("int");
////			RETURNa_(new_Int(ctx, CLASS_Int, OP(inst)->data[n]));
////			break;
////		case VMT_OBJECT: case VMT_STRING:
////			DBG_P("object");
////			RETURNa_(OP(inst)->p[n]);
////			break;
////		case VMT_FLOAT:
////			DBG_P("float");
////			RETURNa_(new_Float(ctx, CLASS_Float, OP(inst)->data[n]));
////		default:
////			DBG_P("others %s->data[%d]", getOpname(OP(inst)->opcode), n);
////			//knh_opcode_dump(ctx, OP(inst), ctx->err, NULL);
////			RETURNa_(new_Int(ctx, CLASS_Int, OP(inst)->data[n]));
////			break;
////	}
////	fprintf(stderr, "error!!\n");
////	RETURNa_(KNH_NULL);
////}
////
//////## method dynamic KInst.set(Int n, dynamic n);
////KMETHOD KInst_set(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	size_t n = knh_array_index(ctx, sfp, Int_to(size_t, sfp[1]), OPDATA[OP(inst)->opcode].size);
////	kClass *c = new_Type(ctx, O_cid(sfp[2].o));
////	switch (c->type) {
////		case TYPE_String:
////			DBG_P("string");
////			KNH_SETv(ctx, OP(inst)->p[n], sfp[2].s);
////			RETURNa_(OP(inst)->p[n]);
////			break;
////		case TYPE_Int:
////			DBG_P("int");
////			OP(inst)->data[n] = sfp[2].i->n.ivalue;
////			RETURNa_(new_Int(ctx, CLASS_Int, OP(inst)->data[n]));
////			break;
////		case TYPE_Float:
////			DBG_P("float");
////			OP(inst)->data[n] = sfp[2].f->n.fvalue;
////			RETURNa_(new_Float(ctx, CLASS_Float, OP(inst)->data[n]));
////			break;
////		case TYPE_Boolean:
////			DBG_P("boolean");
////			OP(inst)->data[n] = sfp[2].i->n.bvalue;
////			RETURNa_(new_Int(ctx, CLASS_Boolean, OP(inst)->data[n]));
////			break;
////		default:
////			DBG_P("others");
////			KNH_SETv(ctx, OP(inst)->p[n], sfp[2].o);
////			RETURNa_(OP(inst)->p[n]);
////			break;
////	}
////	fprintf(stderr, "error!!\n");
////	RETURNa_(KNH_NULL);
////}
////
////## method String Instruction.getOpname();
//KMETHOD Instruction_getOpname(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = INST(sfp[0].p);
//	kString *s = new_String(ctx, OPDATA[inst->op->opcode].name);
//	RETURN_(s);
//}
//
////## method Int Instruction.getOpcode();
//KMETHOD Instruction_getOpcode(CTX ctx, ksfp_t *sfp _RIX)
//{
//	knh_Instruction_t *inst = INST(sfp[0].p);
//	RETURNi_((inst)->op->opcode);
//}
//
//////## method Int KInst.setOpcode(Int opcode);
////KMETHOD KInst_setOpcode(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	int opcode = Int_to(int, sfp[1]);
////	if (0 > opcode || opcode > OPCODE_MAX + 1) {
////		fprintf(stderr, "no such opcode\n");
////		RETURNi_(-1);
////	}
////	OP(inst)->opcode = opcode;
////	RETURNi_(opcode);
////}
////
//////## method Int KInst.getJump();
////KMETHOD KInst_getJump(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	if (!knh_opcode_hasjump(OP(inst)->opcode)) {
////		DBG_P("no jump");
////		RETURNi_(-1);
////	}
////	DBG_P("return %d", inst->label);
////	RETURNi_(inst->label);
////}
////
//////## method Int KInst.setJump(Int label);
////KMETHOD KInst_setJump(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	if (!knh_opcode_hasjump(OP(inst)->opcode)) {
////		DBG_P("no jump");
////		RETURNi_(-1);
////	}
////	int dest = Int_to(int, sfp[1]);
////	if (dest < 0) {
////		DBG_P("wrong label");
////		RETURNi_(-1);
////	}
////	DBG_P("%s set label %d", getOpname(OP(inst)->opcode), dest);
////	inst->label = dest;
////	RETURNi_(dest);
////}
////
//////## method Int KInst.getSize();
////KMETHOD KInst_getSize(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	RETURNi_(OPDATA[OP(inst)->opcode].size);
////}
////
//////## method Array<Int> KInst.getDefList();
////KMETHOD KInst_getDefList(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	kArray *a = new_Array(ctx, CLASS_Int, 0);
////	kopcode_t opcode = OP(inst)->opcode;
////	if (FLAG_is(OPDATA[opcode].flag, F_DEF)) {
////		if (OP(inst)->data[0] != -1) {
////			knh_Array_add(ctx, a, OP(inst)->data[0]);
////		//} else {
////		//	DBG_P("don't assume an inverse register as a definition");
////		}
////		if (FLAG_is(OPDATA[opcode].flag, F_MDEF)) {
////			switch (opcode) {
////				case OPCODE_NNMOV:
////				case OPCODE_OOMOV:
////				case OPCODE_ONMOV:
////					knh_Array_add(ctx, a, OP(inst)->data[2]);
////					break;
////				case OPCODE_NSET2:
////				case OPCODE_OSET2:
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 2);
////					break;
////				case OPCODE_NSET3:
////				case OPCODE_OSET3:
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 2);
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 4);
////					break;
////				case OPCODE_NSET4:
////				case OPCODE_OSET4:
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 2);
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 4);
////					knh_Array_add(ctx, a, OP(inst)->data[0] + 6);
////					break;
////				default:
////					DBG_P("TODO");
////					break;
////			}
////		}
////	}
////	RETURN_(a);
////}
////
//////## method Array<Int> KInst.getUseList();
////KMETHOD KInst_getUseList(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KInst_t *inst = RawPtr_to(KInst_t *, sfp[0]);
////	kArray *a = new_Array(ctx, CLASS_Int, 0);
////	kopcode_t opcode = OP(inst)->opcode;
////	if (FLAG_is(OPDATA[opcode].flag, F_USE)) {
////		if (opcode == OPCODE_iINC || opcode == OPCODE_iDEC) {
////			knh_Array_add(ctx, a, OP(inst)->data[0]);
////		} else if (opcode == OPCODE_NNMOV || opcode == OPCODE_ONMOV || opcode == OPCODE_OOMOV) {
////			knh_Array_add(ctx, a, OP(inst)->data[1]);
////			knh_Array_add(ctx, a, OP(inst)->data[3]);
////		} else {
////			size_t i;
////			for (i = 1; i < OPDATA[opcode].size; i++) {
////				if (OPDATA[opcode].types[i] == VMT_R || OPDATA[opcode].types[i] == VMT_RN || OPDATA[opcode].types[i] == VMT_RO) {
////					knh_Array_add(ctx, a, OP(inst)->data[i]);
////				} else if (OPDATA[opcode].types[i] == VMT_SFPIDX2) {
////					if (OP(inst)->data[i] > 0) {
////						int n = OP(inst)->data[i] * 2 + 1;
////						int o = OP(inst)->data[i] * 2;
////						kopl_t *pop = OP(PRED(inst));
////						while (!FLAG_is(OPDATA[pop->opcode].flag, F_DEF)) {
////							inst = PRED(inst);
////							pop = OP(inst);
////						}
////						int idx = 0;
////						if (pop->opcode == OPCODE_NNMOV || pop->opcode == OPCODE_ONMOV ||
////								pop->opcode == OPCODE_OOMOV) {
////							idx = 2;
////						}
////						if (pop->data[idx] == n || pop->data[idx] == o) {
////							knh_Array_add(ctx, a, pop->data[idx]);
//////						} else {
//////							fprintf(stderr, "data[0]=%ld, n=%d\n",pop->data[idx],n);
////						}
////					}
////				}
////			}
////		}
////	} else if (FLAG_is(OPDATA[opcode].flag, F_CALL)) {
////		analyzeCallRegister(ctx, a, inst);
////	}
////	RETURN_(a);
////}
////
/////* ------------------------------------------------------------------------ */
/////* [KCode Method] */
//////## method Array<KInst> KCode.join(Array<KInst> kcode1, Array<KInst> kcode2);
////KMETHOD KCode_join(CTX ctx, ksfp_t *sfp, long rix)
////{
////	kArray *klrcode1 = sfp[1].a;
////	kArray *klrcode2 = sfp[2].a;
////	kArray *newcode = new_Array(ctx, knh_getcid(ctx, B(NAME(KInst))), 0);
////	size_t i;
////	KInst_t *hinst = NULL;
////	if (knh_Array_size(klrcode1) > 0) {
////		hinst = (KInst_t*)pArray_n(klrcode1, 0);
////	} else if (knh_Array_size(klrcode2) == 0) {
////		RETURN_(KNH_NULL);
////	}
////	for (i = 0; i < knh_Array_size(klrcode1) - 1; i++) { /* skip RET(109) */
////		knh_Array_add(ctx, newcode, knh_Array_n(klrcode1, i));
////	}
////	for (i = 1; i < knh_Array_size(klrcode2); i++) { /* skip THCODE(1) */
////		knh_Array_add(ctx, newcode, knh_Array_n(klrcode2, i));
////		KInst_t *kinst = (KInst_t*)pArray_n(newcode, knh_Array_size(newcode) - 1);
////		if (hinst != NULL) {
////			kinst->start = hinst->start;
////		}
////	}
////	RETURN_(newcode);
////}
////
//////## method KBlock KCode.constructCfg(Array<KInst> kcode);
////KMETHOD KCode_constructCfg(CTX ctx, ksfp_t *sfp, long rix)
////{
////	kArray *klrcode = sfp[1].a;
//////	kclass_t cid = knh_getcid(ctx, B(NAME(KBlock)));
//////	kObject *o = new_Object_init2(ctx, 0, ClassTBL(cid));
////	kRawPtr *bb = constructCfg(ctx, klrcode);
////	RETURN_(bb);
////}
////
////////## method Func KCode.generateFunc(Array<KInst> kcode);
//////KMETHOD KCode_generateFunc(CTX ctx, ksfp_t *sfp, long rix)
//////{
//////	kArray *klrcode = sfp[1].a;
//////	if (klrcode == NULL) {
//////		fprintf(stderr, "klrcode=NULL\n");
//////		RETURNvoid_();
//////	}
//////	kFunc *fo = new_(Func);
//////	kMethod *mtd = DP(ctx->gma)->mtd;
//////	Method_setFunc(ctx, mtd, knh_Fmethod_runVM);
//////	KNH_SETv(ctx, fo->mtd, mtd);
//////	kKonohaCode *kcode = new_(KonohaCode);
//////	SP(kcode)->uri = SP(DP(mtd)->kcode)->uri;
//////	SP(kcode)->codesize = knh_Array_size(klrcode) * sizeof(kopl_t);
//////	SP(kcode)->code = (kopl_t*)KNH_MALLOC(ctx, SP(kcode)->codesize);
////////	fprintf(stderr, "before\n");
////////	KonohaCode_print(ctx, DP(mtd)->kcode);
//////	setManipulatedCode(ctx, SP(kcode)->code, klrcode);
////////	fprintf(stderr, "after\n");
////////	KonohaCode_print(ctx, kcode);
////////	if (Method_isObjectCode(mtd)) {
////////		fprintf(stderr, "hi\n");
////////		KNH_SETv(ctx, DP(mtd)->kcode, kcode);
////////	} else {
////////		fprintf(stderr, "hello\n");
////////		Method_setObjectCode(mtd, 1);
////////		KNH_INITv(DP(mtd)->kcode, kcode);
////////	}
////////	Method_setObjectCode(mtd, 1);
////////	KNH_INITv(DP(mtd)->kcode, kcode);
//////	KNH_SETv(ctx, DP(mtd)->kcode, kcode);
//////	if (knh_isSystemVerbose()) {
//////		knh_mtdcache_t mcache = {0, 0, NULL};
//////		knh_write_Object(ctx, KNH_STDOUT, ctx->esp, &mcache, UPCAST(mtd), MN__dump);
//////		knh_write_EOL(ctx, KNH_STDOUT);
//////	}
//////	RETURN_(fo);
//////}
////
/////* ------------------------------------------------------------------------ */
/////* [KBlock API] */
////
////static KBlock_t *knh_KBlock_malloc(CTX ctx)
////{
////	KBlock_t *bb = (KBlock_t*)KNH_MALLOC(ctx, sizeof(KBlock_t));
////	bb->id = -1;
////	bb->topsize = 0;
////	bb->flag = 0;
////	bb->kcode = new_Array(ctx, knh_getcid(ctx, B(NAME(KInst))), 0);
////	kclass_t cid = knh_getcid(ctx, B(NAME(KBlock)));
////	bb->pred = new_Array(ctx, cid, 0);
////	bb->succ = new_Array(ctx, cid, 0);
////	return bb;
////}
////
////static void knh_KBlock_pfree(CTX ctx, kRawPtr* o)
////{
////	KBlock_t *bb = (KBlock_t*)o->ptr;
////	knh_Array_clear(ctx, bb->kcode, 0);
////	knh_Array_clear(ctx, bb->pred, 0);
////	knh_Array_clear(ctx, bb->succ, 0);
////	KNH_FREE(ctx, bb, sizeof(KBlock_t));
////}
////
////static void knh_KBlock_init(CTX ctx, ksfp_t *sfp, KBlock_t *bb, size_t id)
////{
////	bb->id = id;
////}
////
/////* ------------------------------------------------------------------------ */
/////* [KBlock Method] */
////
//////## method KBlock KBlock.new(Int id);
////KMETHOD KBlock_new(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = knh_KBlock_malloc(ctx);
////	knh_KBlock_init(ctx, sfp, bb, Int_to(size_t, sfp[1]));
//////	kRawPtr *p = new_RawPtr(ctx, bb, knh_KBlock_pfree, CLASS_Object, NAME(KBlock));
//////	kObject *of = (kObject*)p;
//////	kclass_t cid = knh_getcid(ctx, B(NAME(KBlock)));
//////	of->fields[8] = (Object*)new_Array(ctx, cid, 0); // bucket
//////	of->fields[9] = (Object*)new_Array(ctx, cid, 0); // df
//////	of->fields[10] = (Object*)new_Array(ctx, CLASS_Int, 0); // aorig
////	RETURN_(new_RawPtr(ctx, bb, knh_KBlock_pfree, CLASS_Object, NAME(KBlock)));
////}
////
//////## method Array<KBlock> KBlock.getPred();
////KMETHOD KBlock_getPred(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	RETURN_(bb->pred);
////}
////
//////## method Array<KBlock> KBlock.getSucc();
////KMETHOD KBlock_getSucc(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	RETURN_(bb->succ);
////}
////
//////## method Array<KBlock> KBlock.setSucc(Array<KBlock> succ);
////KMETHOD KBlock_setSucc(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	KNH_SETv(ctx, bb->succ, sfp[1].a);
////	RETURN_(bb->succ);
////}
////
//////## method Int KBlock.getId();
////KMETHOD KBlock_getId(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	RETURNi_(bb->id);
////}
////
//////## method Int KBlock.setId(Int id);
////KMETHOD KBlock_setId(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	bb->id = Int_to(size_t, sfp[1]);
////	RETURNi_(bb->id);
////}
////
////
////## method void Block.traverse();
//void BasicBlock_traverse(CTX ctx, kRawPtr *rootbb, void *refbuf, bbtrace_t fbb)
//{
//	kRawPtr *bbo = rootbb;
//	KBlock_t *bb = (KBlock_t*)bbo->rawptr;
//	kbool_t flag = !(bb->flag);
//	bb->flag = flag;
//	size_t i;
//	BEGIN_LOCAL(ctx, lsfp, 1);
//	LOCAL_NEW(ctx, lsfp, 0, kArray *, stack, new_Array(ctx, CLASS_Int, 0));
//	knh_Array_add(ctx, stack, bbo);
//	while (knh_Array_size(stack) > 0) {
//		bbo = (kRawPtr*)knh_Array_n(stack, knh_Array_size(stack) - 1);
//		bb  = ((KBlock_t*)bbo->rawptr);
//		//fprintf(stderr, "bb[%ld] pred[", bb->id);
//		knh_Array_clear(ctx, stack, knh_Array_size(stack) - 1);
//		//for (i = 0; i < knh_Array_size(bb->pred); i++) {
//		//	KBlock_t *bbp = (KBlock_t*)pArray_n(bb->pred, i);
//		//	fprintf(stderr, "%ld, ", bbp->id);
//		//}
//		//fprintf(stderr, "] succ=[");
//		//for (i = 0; i < knh_Array_size(bb->succ); i++) {
//		//	KBlock_t *bbs = (KBlock_t*)pArray_n(bb->succ, i);
//		//	fprintf(stderr, "%ld, ", bbs->id);
//		//}
//		//fprintf(stderr, "]\n");
//		//Basicblock_p(ctx, KNH_STDERR, RAWPTR((bb)->kcode), 0);
//		fbb(ctx, bbo, refbuf);
//		for (i = 0; i < knh_Array_size(bb->succ); i++) {
//			KBlock_t *bbs = (KBlock_t*)pArray_n(bb->succ, i);
//			if (bbs->flag != flag) {
//				knh_Array_add(ctx, stack, knh_Array_n(bb->succ, i));
//				bbs->flag = flag;
//			}
//		}
//	}
//	END_LOCAL(ctx, lsfp);
//}
//
//////## method Array<KInst> KBlock.getKCode();
////KMETHOD KBlock_getKCode(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	RETURN_(bb->kcode);
////}
////
//////## method Array<KInst> KBlock.setKCode(Array<KInst> kcode);
////KMETHOD KBlock_setKCode(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	kArray *klrcode = sfp[1].a;
////	bb->kcode = klrcode;
////	RETURN_(sfp[1].o);
////}
////
//////## method Array<KInst> KBlock.deconstructCfg();
////KMETHOD KBlock_deconstructCfg(CTX ctx, ksfp_t *sfp, long rix)
////{
////	KBlock_t *bb = RawPtr_to(KBlock_t *, sfp[0]);
////	kclass_t cid = knh_getcid(ctx, B(NAME(KInst)));
////	kArray *klrcode = new_Array(ctx, cid, 0);
////	deconstructCfg(ctx, klrcode, bb, !bb->flag, 0);
//////	fprintf(stderr, "klrcodesize=%ld\n", knh_Array_size(klrcode));
////	RETURN_(klrcode);
////}
////

