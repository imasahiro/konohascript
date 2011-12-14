/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
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
#include <llvm/DerivedTypes.h>
#include <llvm/Constants.h>
#include <llvm/GlobalVariable.h>
#include <llvm/Function.h>
#include <llvm/BasicBlock.h>
#include <llvm/Instructions.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/Analysis/AliasSetTracker.h>
#include <llvm/Analysis/DomPrinter.h>
#include <llvm/Analysis/FindUsedTypes.h>
#include <llvm/Analysis/IntervalPartition.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/Analysis/PostDominators.h>
#include <llvm/Analysis/RegionPass.h>
#include <llvm/Analysis/RegionPrinter.h>
#include <llvm/Analysis/ScalarEvolution.h>
#include <llvm/Analysis/Lint.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Target/TargetData.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <llvm/Transforms/Instrumentation.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Utils/UnifyFunctionExitNodes.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/ADT/Statistic.h>

#undef HAVE_SYS_TYPES_H
#undef HAVE_SYS_STAT_H
#undef HAVE_UNISTD_H
#undef HAVE_SYS_TIME_H
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_VERSION
#define K_INTERNAL 1
#include <konoha1.h>

namespace konoha {
template <class T>
inline T object_cast(kRawPtr *po)
{
	return static_cast<T>(po->rawptr);
}

template <class T>
inline void convert_array(std::vector<T> &vec, kArray *a)
{
	size_t size = a->size;
	for (size_t i=0; i < size; i++) {
		T v = konoha::object_cast<T>(a->ptrs[i]);
		vec.push_back(v);
	}
}

}

using namespace llvm;

#ifdef __cplusplus
extern "C" {
#endif

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

#define PKG_NULVAL(T) PKG_NULVAL_##T
#define PKG_NULVAL_int    (0)
#define PKG_NULVAL_float  (0.0)
#define PKG_NULVAL_String (KNH_NULVAL(CLASS_String))
#define WRAP(ptr) ((void*)ptr)

static void Type_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}
static void Type_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defType(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Type";
	cdef->init = Type_init;
	cdef->free = Type_free;
}

static void IntegerType_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}
static void IntegerType_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defIntegerType(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "IntegerType";
	cdef->init = IntegerType_init;
	cdef->free = IntegerType_free;
}

static void PointerType_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}
static void PointerType_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defPointerType(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "PointerType";
	cdef->init = PointerType_init;
	cdef->free = PointerType_free;
}

static void type_ptr_free(void *v)
{
	/* do nothing */
}

//## @Static Type Type.getVoidTy();
KMETHOD Type_getVoidTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getVoidTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getLabelTy();
KMETHOD Type_getLabelTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getLabelTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getFloatTy();
KMETHOD Type_getFloatTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFloatTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getDoubleTy();
KMETHOD Type_getDoubleTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getDoubleTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getMetadataTy();
KMETHOD Type_getMetadataTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getMetadataTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getX86FP80Ty();
KMETHOD Type_getX86FP80Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_FP80Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getFP128Ty();
KMETHOD Type_getFP128Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFP128Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getPPCFP128Ty();
KMETHOD Type_getPPCFP128Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getPPC_FP128Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getX86MMXTy();
KMETHOD Type_getX86MMXTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_MMXTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt1Ty();
KMETHOD Type_getInt1Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt1Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt8Ty();
KMETHOD Type_getInt8Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt8Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt16Ty();
KMETHOD Type_getInt16Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt16Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt32Ty();
KMETHOD Type_getInt32Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt32Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt64Ty();
KMETHOD Type_getInt64Ty(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt64Ty(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getFloatPtrTy();
KMETHOD Type_getFloatPtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFloatPtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getDoublePtrTy();
KMETHOD Type_getDoublePtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getDoublePtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getX86FP80PtrTy();
KMETHOD Type_getX86FP80PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_FP80PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getFP128PtrTy();
KMETHOD Type_getFP128PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFP128PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getPPCFP128PtrTy();
KMETHOD Type_getPPCFP128PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getPPC_FP128PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getX86MMXPtrTy();
KMETHOD Type_getX86MMXPtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_MMXPtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt1PtrTy();
KMETHOD Type_getInt1PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt1PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt8PtrTy();
KMETHOD Type_getInt8PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt8PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt16PtrTy();
KMETHOD Type_getInt16PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt16PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt32PtrTy();
KMETHOD Type_getInt32PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt32PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt64PtrTy();
KMETHOD Type_getInt64PtrTy(CTX ctx, ksfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt64PtrTy(getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType PointerType.get(Type type);
KMETHOD PointerType_get(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *type = konoha::object_cast<Type *>(sfp[1].p);
	const Type *ptr  = PointerType::get(type, 0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

static void obj_free(void *p)
{
	/* do nothing */
}
static void IRBuilder_obj_free(void *p)
{
	IRBuilder<> *builder = static_cast<IRBuilder<> *>(p);
	delete builder;
}
//## IRBuilder IRBuilder.new(BasicBlock bb);
KMETHOD IRBuilder_new(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *bb = konoha::object_cast<BasicBlock *>(sfp[1].p);
	IRBuilder<> *self = new IRBuilder<>(bb);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(self), IRBuilder_obj_free);
	RETURN_(p);
}


//## ReturnInst IRBuilder.CreateRetVoid();
KMETHOD IRBuilder_createRetVoid(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	ReturnInst *ptr = self->CreateRetVoid();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ReturnInst IRBuilder.CreateRet(Value V);
KMETHOD IRBuilder_createRet(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	ReturnInst *ptr = self->CreateRet(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ReturnInst IRBuilder.CreateAggregateRet(Value retVals, int N);
KMETHOD IRBuilder_createAggregateRet(CTX ctx, ksfp_t *sfp _RIX)
{
	LLVM_TODO("NO SUPPORT");
	//IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	//Value *const retVals = konoha::object_cast<Value *const>(sfp[1].p);
	//kint_t N = Int_to(kint_t,sfp[2]);
	//ReturnInst *ptr = self->CreateAggregateRet(retVals, N);
	//kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	//RETURN_(p);
}

//## BranchInst IRBuilder.CreateBr(BasicBlock Dest);
KMETHOD IRBuilder_createBr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock *Dest = konoha::object_cast<BasicBlock *>(sfp[1].p);
	BranchInst *ptr = self->CreateBr(Dest);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## BranchInst IRBuilder.CreateCondBr(Value Cond, BasicBlock True, BasicBlock False);
KMETHOD IRBuilder_createCondBr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Cond = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *True = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *False = konoha::object_cast<BasicBlock *>(sfp[3].p);
	BranchInst *ptr = self->CreateCondBr(Cond, True, False);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## SwitchInst IRBuilder.CreateSwitch(Value V, BasicBlock Dest);
KMETHOD IRBuilder_createSwitch(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *Dest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	SwitchInst *ptr = self->CreateSwitch(V, Dest);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## IndirectBrInst IRBuilder.CreateIndirectBr(Value Addr);
KMETHOD IRBuilder_createIndirectBr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Addr = konoha::object_cast<Value *>(sfp[1].p);
	IndirectBrInst *ptr = self->CreateIndirectBr(Addr);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke0(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest);
KMETHOD IRBuilder_createInvoke0(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke1(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, Value Arg1);
KMETHOD IRBuilder_createInvoke1(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[4].p);
	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest, Arg1);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke3(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, Value Arg1, Value Arg2, Value Arg3);
KMETHOD IRBuilder_createInvoke3(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[5].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[6].p);
	InvokeInst *ptr = self->CreateInvoke3(Callee, NormalDest, UnwindDest, Arg1, Arg2, Arg3);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## InvokeInst IRBuilder.CreateInvoke(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, ArrayRef<Value> Args);
//KMETHOD IRBuilder_createInvoke(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
//	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
//	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
//	kArray *Args = (sfp[4].a);
//	std::vector<Value*> List;
//	konoha::convert_array(List, Args);
//	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest, List.begin(), List.end());
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ResumeInst IRBuilder.CreateResume(Value Exn);
//KMETHOD IRBuilder_createResume(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Exn = konoha::object_cast<Value *>(sfp[1].p);
//	ResumeInst *ptr = self->CreateResume(Exn);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}
//
//## UnreachableInst IRBuilder.CreateUnreachable();
KMETHOD IRBuilder_createUnreachable(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	UnreachableInst *ptr = self->CreateUnreachable();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createAdd(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAdd(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWAdd(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWAdd(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWAdd(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWAdd(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createFAdd(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFAdd(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createSub(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSub(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWSub(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWSub(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWSub(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWSub(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createFSub(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFSub(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createMul(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateMul(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWMul(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWMul(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWMul(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWMul(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createFMul(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFMul(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateUDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createUDiv(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateUDiv(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExactUDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createExactUDiv(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExactUDiv(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createSDiv(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSDiv(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExactSDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createExactSDiv(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExactSDiv(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createFDiv(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFDiv(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateURem(Value LHS, Value RHS);
KMETHOD IRBuilder_createURem(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateURem(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSRem(Value LHS, Value RHS);
KMETHOD IRBuilder_createSRem(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSRem(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFRem(Value LHS, Value RHS);
KMETHOD IRBuilder_createFRem(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFRem(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateShl(Value LHS, Value RHS);
KMETHOD IRBuilder_createShl(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateShl(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateLShr(Value LHS, Value RHS);
KMETHOD IRBuilder_createLShr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateLShr(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAShr(Value LHS, Value RHS);
KMETHOD IRBuilder_createAShr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAShr(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAnd(Value LHS, Value RHS);
KMETHOD IRBuilder_createAnd(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAnd(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateOr(Value LHS, Value RHS);
KMETHOD IRBuilder_createOr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateOr(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateXor(Value LHS, Value RHS);
KMETHOD IRBuilder_createXor(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateXor(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNeg(Value V);
KMETHOD IRBuilder_createNeg(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNeg(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWNeg(Value V);
KMETHOD IRBuilder_createNSWNeg(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNSWNeg(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWNeg(Value V);
KMETHOD IRBuilder_createNUWNeg(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNUWNeg(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFNeg(Value V);
KMETHOD IRBuilder_createFNeg(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateFNeg(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNot(Value V);
KMETHOD IRBuilder_createNot(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNot(V);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## AllocaInst IRBuilder.CreateAlloca(Type Ty, Value ArraySize);
KMETHOD IRBuilder_createAlloca(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[1].p);
	Value *ArraySize = konoha::object_cast<Value *>(sfp[2].p);
	AllocaInst *ptr = self->CreateAlloca(Ty, ArraySize);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## LoadInst IRBuilder.CreateLoad(Value Ptr, boolean isVolatile);
KMETHOD IRBuilder_createLoad(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kbool_t isVolatile = sfp[2].bvalue;
	LoadInst *ptr = self->CreateLoad(Ptr, isVolatile);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## StoreInst IRBuilder.CreateStore(Value Val, Value Ptr, boolean isVolatile);
KMETHOD IRBuilder_createStore(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Val = konoha::object_cast<Value *>(sfp[1].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[2].p);
	kbool_t isVolatile = sfp[3].bvalue;
	StoreInst *ptr = self->CreateStore(Val, Ptr, isVolatile);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## FenceInst IRBuilder.CreateFence(AtomicOrdering Ordering, SynchronizationScope SynchScope);
//KMETHOD IRBuilder_createFence(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	AtomicOrdering *Ordering = konoha::object_cast<AtomicOrdering *>(sfp[1].p);
//	SynchronizationScope *SynchScope = konoha::object_cast<SynchronizationScope *>(sfp[2].p);
//	FenceInst *ptr = self->CreateFence(Ordering, SynchScope);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}
//
////## AtomicCmpXchgInst IRBuilder.CreateAtomicCmpXchg(Value Ptr, Value Cmp, Value New, AtomicOrdering Ordering, SynchronizationScope SynchScope);
//KMETHOD IRBuilder_createAtomicCmpXchg(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
//	Value *Cmp = konoha::object_cast<Value *>(sfp[2].p);
//	Value *New = konoha::object_cast<Value *>(sfp[3].p);
//	AtomicOrdering *Ordering = konoha::object_cast<AtomicOrdering *>(sfp[4].p);
//	SynchronizationScope *SynchScope = konoha::object_cast<SynchronizationScope *>(sfp[5].p);
//	AtomicCmpXchgInst *ptr = self->CreateAtomicCmpXchg(Ptr, Cmp, New, Ordering, SynchScope);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

//## Value IRBuilder.CreateGEP(Value Ptr, ArrayRef< Value > IdxList);
KMETHOD IRBuilder_createGEP(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kArray *IdxList = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, IdxList);
	Value *ptr = self->CreateGEP(Ptr, List);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInBoundsGEP(Value Ptr, ArrayRef< Value > IdxList);
KMETHOD IRBuilder_createInBoundsGEP(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kArray *IdxList = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, IdxList);
	Value *ptr = self->CreateInBoundsGEP(Ptr, List);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGEP1(Value Ptr, Value Idx);
KMETHOD IRBuilder_createGEP1(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateGEP(Ptr, Idx);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInBoundsGEP1(Value Ptr, Value Idx);
KMETHOD IRBuilder_createInBoundsGEP1(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateInBoundsGEP(Ptr, Idx);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP1_32(Value Ptr, int Idx0);
KMETHOD IRBuilder_createConstGEP132(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = Int_to(kint_t,sfp[2]);
	Value *ptr = self->CreateConstGEP1_32(Ptr, Idx0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP1_32(Value Ptr, int Idx0);
KMETHOD IRBuilder_createConstInBoundsGEP132(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = Int_to(kint_t,sfp[2]);
	Value *ptr = self->CreateConstInBoundsGEP1_32(Ptr, Idx0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP2_32(Value Ptr, int Idx0, int Idx1);
KMETHOD IRBuilder_createConstGEP232(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = Int_to(kint_t,sfp[2]);
	kint_t Idx1 = Int_to(kint_t,sfp[3]);
	Value *ptr = self->CreateConstGEP2_32(Ptr, Idx0, Idx1);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP2_32(Value Ptr, int Idx0, int Idx1);
KMETHOD IRBuilder_createConstInBoundsGEP232(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = Int_to(kint_t,sfp[2]);
	kint_t Idx1 = Int_to(kint_t,sfp[3]);
	Value *ptr = self->CreateConstInBoundsGEP2_32(Ptr, Idx0, Idx1);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP1_64(Value Ptr, uint64_t Idx0);
KMETHOD IRBuilder_createConstGEP164(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = sfp[2].ivalue;
	Value *ptr = self->CreateConstGEP1_64(Ptr, Idx0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP1_64(Value Ptr, uint64_t Idx0);
KMETHOD IRBuilder_createConstInBoundsGEP164(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = sfp[2].ivalue;
	Value *ptr = self->CreateConstInBoundsGEP1_64(Ptr, Idx0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP2_64(Value Ptr, uint64_t Idx0, uint64_t Idx1);
KMETHOD IRBuilder_createConstGEP264(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = sfp[2].ivalue;
	kint_t Idx1 = sfp[3].ivalue;
	Value *ptr = self->CreateConstGEP2_64(Ptr, Idx0, Idx1);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP2_64(Value Ptr, uint64_t Idx0, uint64_t Idx1);
KMETHOD IRBuilder_createConstInBoundsGEP264(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx0 = sfp[2].ivalue;
	kint_t Idx1 = sfp[3].ivalue;
	Value *ptr = self->CreateConstInBoundsGEP2_64(Ptr, Idx0, Idx1);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateStructGEP(Value Ptr, int Idx);
KMETHOD IRBuilder_createStructGEP(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	kint_t Idx = Int_to(kint_t,sfp[2]);
	Value *ptr = self->CreateStructGEP(Ptr, Idx);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGlobalString(StringRef Str);
KMETHOD IRBuilder_createGlobalString(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	kString *Str = sfp[1].s;
	Value *ptr = self->CreateGlobalString(S_totext(Str));
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGlobalStringPtr(StringRef Str);
KMETHOD IRBuilder_createGlobalStringPtr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	kString *Str = sfp[1].s;
	Value *ptr = self->CreateGlobalStringPtr(S_totext(Str));
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateTrunc(Value V, Type DestTy);
KMETHOD IRBuilder_createTrunc(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateTrunc(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateZExt(Value V, Type DestTy);
KMETHOD IRBuilder_createZExt(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateZExt(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSExt(Value V, Type DestTy);
KMETHOD IRBuilder_createSExt(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSExt(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPToUI(Value V, Type DestTy);
KMETHOD IRBuilder_createFPToUI(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPToUI(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPToSI(Value V, Type DestTy);
KMETHOD IRBuilder_createFPToSI(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPToSI(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateUIToFP(Value V, Type DestTy);
KMETHOD IRBuilder_createUIToFP(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateUIToFP(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSIToFP(Value V, Type DestTy);
KMETHOD IRBuilder_createSIToFP(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSIToFP(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPTrunc(Value V, Type DestTy);
KMETHOD IRBuilder_createFPTrunc(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPTrunc(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPExt(Value V, Type DestTy);
KMETHOD IRBuilder_createFPExt(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPExt(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePtrToInt(Value V, Type DestTy);
KMETHOD IRBuilder_createPtrToInt(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreatePtrToInt(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIntToPtr(Value V, Type DestTy);
KMETHOD IRBuilder_createIntToPtr(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateIntToPtr(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createBitCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateBitCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateZExtOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createZExtOrBitCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateZExtOrBitCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSExtOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createSExtOrBitCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSExtOrBitCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateTruncOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createTruncOrBitCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateTruncOrBitCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePointerCast(Value V, Type DestTy);
KMETHOD IRBuilder_createPointerCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreatePointerCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIntCast(Value V, Type DestTy, boolean isSigned);
KMETHOD IRBuilder_createIntCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	kbool_t isSigned = sfp[3].bvalue;
	Value *ptr = self->CreateIntCast(V, DestTy, isSigned);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPCast(Value V, Type DestTy);
KMETHOD IRBuilder_createFPCast(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPCast(V, DestTy);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpEQ(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpEQ(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpNE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpNE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpNE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpUGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpUGT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpUGT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpUGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpUGE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpUGE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpULT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpULT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpULT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpULE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpULE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpULE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSGT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSGT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSGE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSGE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSLT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSLT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSLT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSLE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSLE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSLE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOEQ(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOEQ(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOGT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOGT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOGE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOGE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOLT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOLT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOLT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOLE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOLE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOLE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpONE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpONE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpONE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpORD(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpORD(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpORD(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUNO(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUNO(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUNO(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUEQ(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUEQ(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUGT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUGT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUGE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUGE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpULT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpULT(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpULT(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpULE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpULE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpULE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUNE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUNE(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUNE(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## PHINode IRBuilder.CreatePHI(Type Ty, int numReservedValues);
KMETHOD IRBuilder_createPHI(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[1].p);
	kint_t num = sfp[2].ivalue;
	PHINode *ptr = self->CreatePHI(Ty, num);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void IRBuilder.addIncoming(Type Ty, BasicBlock bb);
KMETHOD PHINode_addIncoming(CTX ctx, ksfp_t *sfp _RIX)
{
	PHINode *self = konoha::object_cast<PHINode *>(sfp[0].p);
	Value *v = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *bb = konoha::object_cast<BasicBlock *>(sfp[2].p);
	self->addIncoming(v, bb);
	RETURNvoid_();
}

//## CallInst IRBuilder.CreateCall1(Value Callee, Value Arg);
KMETHOD IRBuilder_createCall1(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[2].p);
	CallInst *ptr = self->CreateCall(Callee, Arg);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall2(Value Callee, Value Arg1, Value Arg2);
KMETHOD IRBuilder_createCall2(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	CallInst *ptr = self->CreateCall2(Callee, Arg1, Arg2);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall3(Value Callee, Value Arg1, Value Arg2, Value Arg3);
KMETHOD IRBuilder_createCall3(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	CallInst *ptr = self->CreateCall3(Callee, Arg1, Arg2, Arg3);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall4(Value Callee, Value Arg1, Value Arg2, Value Arg3, Value Arg4);
KMETHOD IRBuilder_createCall4(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg4 = konoha::object_cast<Value *>(sfp[5].p);
	CallInst *ptr = self->CreateCall4(Callee, Arg1, Arg2, Arg3, Arg4);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall5(Value Callee, Value Arg1, Value Arg2, Value Arg3, Value Arg4, Value Arg5);
KMETHOD IRBuilder_createCall5(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg4 = konoha::object_cast<Value *>(sfp[5].p);
	Value *Arg5 = konoha::object_cast<Value *>(sfp[6].p);
	CallInst *ptr = self->CreateCall5(Callee, Arg1, Arg2, Arg3, Arg4, Arg5);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall(Value Callee, ArrayRef< Value > Args);
KMETHOD IRBuilder_createCall(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	kArray *Args = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, Args);
	CallInst *ptr = self->CreateCall(Callee, List);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSelect(Value C, Value True, Value False);
KMETHOD IRBuilder_createSelect(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *C = konoha::object_cast<Value *>(sfp[1].p);
	Value *True = konoha::object_cast<Value *>(sfp[2].p);
	Value *False = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateSelect(C, True, False);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## VAArgInst IRBuilder.CreateVAArg(Value List, Type Ty);
KMETHOD IRBuilder_createVAArg(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *List = konoha::object_cast<Value *>(sfp[1].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[2].p);
	VAArgInst *ptr = self->CreateVAArg(List, Ty);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExtractElement(Value Vec, Value Idx);
KMETHOD IRBuilder_createExtractElement(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Vec = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExtractElement(Vec, Idx);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInsertElement(Value Vec, Value NewElt, Value Idx);
KMETHOD IRBuilder_createInsertElement(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Vec = konoha::object_cast<Value *>(sfp[1].p);
	Value *NewElt = konoha::object_cast<Value *>(sfp[2].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateInsertElement(Vec, NewElt, Idx);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateShuffleVector(Value V1, Value V2, Value Mask);
KMETHOD IRBuilder_createShuffleVector(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V1 = konoha::object_cast<Value *>(sfp[1].p);
	Value *V2 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Mask = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateShuffleVector(V1, V2, Mask);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## Value IRBuilder.CreateExtractValue(Value Agg, Array<int> Idxs);
//KMETHOD IRBuilder_createExtractValue(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Agg = konoha::object_cast<Value *>(sfp[1].p);
//	kArray *Idxs = sfp[2].a;
//	std::vector<int> List;
//	konoha::convert_array_int(List, Idxs);
//	Value *ptr = self->CreateExtractValue(Agg, List.begin(), List.end());
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## Value IRBuilder.CreateInsertValue(Value Agg, Value Val, Array<int> Idxs);
//KMETHOD IRBuilder_createInsertValue(CTX ctx, ksfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Agg = konoha::object_cast<Value *>(sfp[1].p);
//	Value *Val = konoha::object_cast<Value *>(sfp[2].p);
//	kArray *Idxs = sfp[2].a;
//	std::vector<int> List;
//	konoha::convert_array_int(List, Idxs);
//	Value *ptr = self->CreateInsertValue(Agg, Val, List.begin(), List.end());
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

//## Value IRBuilder.CreateIsNull(Value Arg);
KMETHOD IRBuilder_createIsNull(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateIsNull(Arg);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIsNotNull(Value Arg);
KMETHOD IRBuilder_createIsNotNull(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateIsNotNull(Arg);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePtrDiff(Value LHS, Value RHS);
KMETHOD IRBuilder_createPtrDiff(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreatePtrDiff(LHS, RHS);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void IRBuilder.SetInsertPoint(BasicBlock BB);
KMETHOD IRBuilder_setInsertPoint(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock * BB = konoha::object_cast<BasicBlock *>(sfp[1].p);
	self->SetInsertPoint(BB);
	RETURNvoid_();
}

//## BasicBlock IRBuilder.GetInsertBlock();
KMETHOD IRBuilder_getInsertBlock(CTX ctx, ksfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock *BB = self->GetInsertBlock();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(BB), obj_free);
	RETURN_(p);
}

//## Function BasicBlock.getParent();
KMETHOD BasicBlock_getParent(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	Function *ptr = self->getParent();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Instruction BasicBlock.getTerminator();
KMETHOD BasicBlock_getTerminator(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	TerminatorInst *ptr = self->getTerminator();
	if (ptr) {
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}


////## iterator BasicBlock.begin();
//KMETHOD BasicBlock_begin(CTX ctx, ksfp_t *sfp _RIX)
//{
//	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
//	*ptr = self->Create();
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(KNH_NULL);
//}
//
////## iterator BasicBlock.end();
//KMETHOD BasicBlock_end(CTX ctx, ksfp_t *sfp _RIX)
//{
//	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
//	*ptr = self->Create();
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(KNH_NULL);
//}

//## int BasicBlock.size();
KMETHOD BasicBlock_size(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	int ret = self->size();
	RETURNi_(ret);
}

//## boolean BasicBlock.empty();
KMETHOD BasicBlock_empty(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	bool isEmpty = self->empty();
	RETURNb_(isEmpty);
}

static void Module_obj_free(void *p)
{
	Module *m = static_cast<Module *>(p);
	delete m;
}

//## Argument Argument.new(Type ty, int scid);
KMETHOD Argument_new(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *ty = konoha::object_cast<Type *>(sfp[1].p);
	Value *v = new Argument(ty, "", 0);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(v), obj_free);
	RETURN_(p);
}

//## Module Module.new(String name);
KMETHOD Module_new(CTX ctx, ksfp_t *sfp _RIX)
{
	kString *name = sfp[1].s;
	Module *ptr = new Module(S_totext(name), getGlobalContext());
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), Module_obj_free);
	RETURN_(p);
}

//## void Module.addTypeName(String name, Type type);
KMETHOD Module_addTypeName(CTX ctx, ksfp_t *sfp _RIX)
{
	KNH_P("deprecated method");
	//Module *self = konoha::object_cast<Module *>(sfp[0].p);
	//kString * name = sfp[1].s;
	//Type *type = konoha::object_cast<Type *>(sfp[2].p);
	//self->addTypeName(S_totext(name), type);
	RETURNvoid_();
}

//## void Module.dump();
KMETHOD Module_dump(CTX ctx, ksfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	(*self).dump();
	RETURNvoid_();
}

//## void BasicBlock.dump();
KMETHOD BasicBlock_dump(CTX ctx, ksfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	(*self).dump();
	RETURNvoid_();
}

//## Function Module.getOrInsertFunction(String name, FunctionType fnTy);
KMETHOD Module_getOrInsertFunction(CTX ctx, ksfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	kString *name = sfp[1].s;
	FunctionType *fnTy = konoha::object_cast<FunctionType *>(sfp[2].p);
	Function *ptr = cast<Function>(self->getOrInsertFunction(S_totext(name), fnTy));
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static @Native Function Function.create(String name, FunctionType fnTy, Module m);
KMETHOD Function_create(CTX ctx, ksfp_t *sfp _RIX)
{
	kString *name = sfp[1].s;
	FunctionType *fnTy = konoha::object_cast<FunctionType *>(sfp[2].p);
	Module *m = konoha::object_cast<Module *>(sfp[3].p);
	Function *ptr = Function::Create(fnTy, GlobalValue::ExternalLinkage, S_totext(name), m);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native void Function.dump();
KMETHOD Function_dump(CTX ctx, ksfp_t *sfp _RIX)
{
	Function *func = konoha::object_cast<Function *>(sfp[0].p);
	func->dump();
	RETURNvoid_();
}

static void ExecutionEngine_obj_free(void *p)
{
	ExecutionEngine *ee = static_cast<ExecutionEngine*>(p);
	delete ee;
}

//## ExecutionEngine Module.createExecutionEngine();
KMETHOD Module_createExecutionEngine(CTX ctx, ksfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	ExecutionEngine *ptr = EngineBuilder(self).setEngineKind(EngineKind::JIT).create();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), ExecutionEngine_obj_free);
	RETURN_(p);
}
//## @Static BasicBlock BasicBlock.create(Function parent);
KMETHOD BasicBlock_create(CTX ctx, ksfp_t *sfp _RIX)
{
	Function * parent = konoha::object_cast<Function *>(sfp[1].p);
	BasicBlock *ptr = BasicBlock::Create(getGlobalContext(), "", parent);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static FunctionType.get(Type retTy, Array<Type> args, boolean b);
KMETHOD FunctionType_get(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *retTy = konoha::object_cast<Type *>(sfp[1].p);
	kArray * args = sfp[2].a;
	kbool_t b = sfp[3].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	FunctionType *ptr = FunctionType::get(retTy, List, b);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native Value ConstantInt.get(Type type, int v);
KMETHOD ConstantInt_get(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *type  = konoha::object_cast<Type *>(sfp[1].p);
	kint_t v = sfp[2].ivalue;
	Value *ptr = ConstantInt::get(type, v);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native Value ConstantFP.get(Type type, float v);
KMETHOD ConstantFP_get(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *type  = konoha::object_cast<Type *>(sfp[1].p);
	kfloat_t v = sfp[2].fvalue;
	Value *ptr = ConstantFP::get(type, v);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static StructType.get(Array<Type> args, boolean isPacked);
KMETHOD StructType_get(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *args = sfp[1].a;
	kbool_t isPacked = sfp[2].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	StructType *ptr = StructType::get(getGlobalContext(), List, isPacked);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static StructType.create(Array<Type> args, String name, boolean isPacked);
KMETHOD StructType_create(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *args = sfp[1].a;
	kString *name = sfp[2].s;
	kbool_t isPacked = sfp[3].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	StructType *ptr = StructType::create(List, S_totext(name), isPacked);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## NativeFunction ExecutionEngine.getPointerToFunction(Function func);
KMETHOD ExecutionEngine_getPointerToFunction(CTX ctx, ksfp_t *sfp _RIX)
{
	ExecutionEngine *ee = konoha::object_cast<ExecutionEngine *>(sfp[0].p);
	Function *func = konoha::object_cast<Function *>(sfp[1].p);
	void *ptr = ee->getPointerToFunction(func);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

static void FunctionPassManager_ptr_free(void *p)
{
	FunctionPassManager *o = static_cast<FunctionPassManager *>(p);
	delete o;
}

//## FunctionPassManager FunctionPassManager.new(Module m)
KMETHOD FunctionPassManager_new(CTX ctx, ksfp_t *sfp _RIX)
{
	Module *m = konoha::object_cast<Module *>(sfp[1].p);
	FunctionPassManager *self = new FunctionPassManager(m);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(self), FunctionPassManager_ptr_free);
	RETURN_(p);
}
//## void FunctionPassManager.add(Pass p)
KMETHOD FunctionPassManager_add(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPassManager *self = konoha::object_cast<FunctionPassManager *>(sfp[0].p);
	Pass *pass = konoha::object_cast<Pass *>(sfp[1].p);
	self->add(pass);
	RETURNvoid_();
}
//## void FunctionPassManager.doInitialization()
KMETHOD FunctionPassManager_doInitialization(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPassManager *self = konoha::object_cast<FunctionPassManager *>(sfp[0].p);
	self->doInitialization();
	RETURNvoid_();
}

//## void FunctionPassManager.run(Function func)
KMETHOD FunctionPassManager_run(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPassManager *self = konoha::object_cast<FunctionPassManager *>(sfp[0].p);
	Function *func = konoha::object_cast<Function *>(sfp[1].p);
	self->run(*func);
	RETURNvoid_();
}

//## TargetData ExecutionEngine.getTargetData();
KMETHOD ExecutionEngine_getTargetData(CTX ctx, ksfp_t *sfp _RIX)
{
	ExecutionEngine *ee = konoha::object_cast<ExecutionEngine *>(sfp[0].p);
	TargetData *ptr = new TargetData(*(ee->getTargetData()));
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void Method.setFunction(NativeFunction func);
KMETHOD Method_setFunction(CTX ctx, ksfp_t *sfp _RIX)
{
	kMethod *mtd = (kMethod*) sfp[0].o;
	kRawPtr *po = sfp[1].p;
	knh_Method_setFunc(ctx, mtd, (knh_Fmethod)po->rawptr);
	RETURNvoid_();
}

//## void Func.setFunction(NativeFunction func);
KMETHOD Func_setFunction(CTX ctx, ksfp_t *sfp _RIX)
{
	kFunc *fo   = sfp[0].fo;
	kRawPtr *po = sfp[1].p;
	kMethod *mtd = fo->mtd;
	knh_Method_setFunc(ctx, mtd, (knh_Fmethod)po->rawptr);
	RETURNvoid_();
}

//## @Native Array<Value> Function.getArguments();
KMETHOD Function_getArguments(CTX ctx, ksfp_t *sfp _RIX)
{
	ktype_t rtype = knh_Param_rtype(DP(sfp[K_MTDIDX].mtdNC)->mp);
	kclass_t cid = C_p1(rtype);
	Function *func = konoha::object_cast<Function *>(sfp[0].p);
	kArray *a = new_Array(ctx, cid, 0);
	for (Function::arg_iterator I = func->arg_begin(), E = func->arg_end();
			I != E; ++I) {
		Value *v = I;
		kRawPtr *po = new_Pointer(ctx, "Value", WRAP(v), NULL);
		knh_Array_add(ctx, a, po);
	}
	RETURN_(a);
}
//## void Value.replaceAllUsesWith(Value v);
KMETHOD Value_replaceAllUsesWith(CTX ctx, ksfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	Value *v = konoha::object_cast<Value *>(sfp[1].p);
	self->replaceAllUsesWith(v);
	RETURNvoid_();
}
//## Value Value.setName(String name);
KMETHOD Value_setName(CTX ctx, ksfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	kString *name = sfp[1].s;
	self->setName(S_totext(name));
	RETURNvoid_();
}

//## Type Value.getType();
KMETHOD Value_getType(CTX ctx, ksfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	const Type *ptr = self->getType();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## void Value.dump();
KMETHOD Value_dump(CTX ctx, ksfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	self->dump();
	RETURNvoid_();
}

//## @Native void Type.dump();
KMETHOD Type_dump(CTX ctx, ksfp_t *sfp _RIX)
{
	Type *type = konoha::object_cast<Type *>(sfp[0].p);
	type->dump();
	RETURNvoid_();
}

//## @Static boolean DynamicLibrary.loadLibraryPermanently(String libname);
KMETHOD DynamicLibrary_loadLibraryPermanently(CTX ctx, ksfp_t *sfp _RIX)
{
	const char *libname = S_totext(sfp[1].s);
	std::string ErrMsg;
	kbool_t ret = sys::DynamicLibrary::LoadLibraryPermanently(libname, &ErrMsg);
	if (ret == 0) {
		KNH_NTRACE2(ctx, "LoadLibraryPermanently", K_FAILED, KNH_LDATA(LOG_s("libname", libname), LOG_msg(ErrMsg.c_str())));
	}
	RETURNb_(ret);
}

//## @Static Int DynamicLibrary.searchForAddressOfSymbol(String fname);
KMETHOD DynamicLibrary_searchForAddressOfSymbol(CTX ctx, ksfp_t *sfp _RIX)
{
	const char *fname = S_totext(sfp[1].s);
	kint_t ret = 0;
	void *symAddr = NULL;
	if (!(symAddr = sys::DynamicLibrary::SearchForAddressOfSymbol(fname))) {
		ret = reinterpret_cast<kint_t>(symAddr);
	}
	RETURNi_(ret);
}

//## FunctionPass LLVM.createDomPrinterPass();
KMETHOD LLVM_createDomPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDomPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDomOnlyPrinterPass();
KMETHOD LLVM_createDomOnlyPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDomOnlyPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDomViewerPass();
KMETHOD LLVM_createDomViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDomViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDomOnlyViewerPass();
KMETHOD LLVM_createDomOnlyViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDomOnlyViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPostDomPrinterPass();
KMETHOD LLVM_createPostDomPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPostDomPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPostDomOnlyPrinterPass();
KMETHOD LLVM_createPostDomOnlyPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPostDomOnlyPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPostDomViewerPass();
KMETHOD LLVM_createPostDomViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPostDomViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPostDomOnlyViewerPass();
KMETHOD LLVM_createPostDomOnlyViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPostDomOnlyViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createGlobalsModRefPass();
KMETHOD LLVM_createGlobalsModRefPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createGlobalsModRefPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createAliasDebugger();
KMETHOD LLVM_createAliasDebugger(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createAliasDebugger();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createAliasAnalysisCounterPass();
KMETHOD LLVM_createAliasAnalysisCounterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createAliasAnalysisCounterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createAAEvalPass();
KMETHOD LLVM_createAAEvalPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createAAEvalPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createLibCallAliasAnalysisPass(LibCallInfo lci);
KMETHOD LLVM_createLibCallAliasAnalysisPass(CTX ctx, ksfp_t *sfp _RIX)
{
	LibCallInfo *lci = konoha::object_cast<LibCallInfo *>(sfp[0].p);
	FunctionPass *ptr = createLibCallAliasAnalysisPass(lci);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createScalarEvolutionAliasAnalysisPass();
KMETHOD LLVM_createScalarEvolutionAliasAnalysisPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createScalarEvolutionAliasAnalysisPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createProfileLoaderPass();
KMETHOD LLVM_createProfileLoaderPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createProfileLoaderPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createProfileEstimatorPass();
KMETHOD LLVM_createProfileEstimatorPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createProfileEstimatorPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createProfileVerifierPass();
KMETHOD LLVM_createProfileVerifierPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createProfileVerifierPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createPathProfileLoaderPass();
KMETHOD LLVM_createPathProfileLoaderPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createPathProfileLoaderPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createPathProfileVerifierPass();
KMETHOD LLVM_createPathProfileVerifierPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createPathProfileVerifierPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createLazyValueInfoPass();
KMETHOD LLVM_createLazyValueInfoPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createLazyValueInfoPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## LoopPass LLVM.createLoopDependenceAnalysisPass();
KMETHOD LLVM_createLoopDependenceAnalysisPass(CTX ctx, ksfp_t *sfp _RIX)
{
	LoopPass *ptr = createLoopDependenceAnalysisPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createInstCountPass();
KMETHOD LLVM_createInstCountPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createInstCountPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDbgInfoPrinterPass();
KMETHOD LLVM_createDbgInfoPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDbgInfoPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createRegionInfoPass();
KMETHOD LLVM_createRegionInfoPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createRegionInfoPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createModuleDebugInfoPrinterPass();
KMETHOD LLVM_createModuleDebugInfoPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createModuleDebugInfoPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createMemDepPrinter();
KMETHOD LLVM_createMemDepPrinter(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createMemDepPrinter();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPostDomTree();
KMETHOD LLVM_createPostDomTree(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPostDomTree();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createRegionViewerPass();
KMETHOD LLVM_createRegionViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createRegionViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createRegionOnlyViewerPass();
KMETHOD LLVM_createRegionOnlyViewerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createRegionOnlyViewerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createRegionPrinterPass();
KMETHOD LLVM_createRegionPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createRegionPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createRegionOnlyPrinterPass();
KMETHOD LLVM_createRegionOnlyPrinterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createRegionOnlyPrinterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createLintPass();
KMETHOD LLVM_createLintPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createLintPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## ModulePass LLVM.createPrintModulePass(raw_ostream *OS);
//KMETHOD LLVM_createPrintModulePass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	raw_ostream **OS = konoha::object_cast<raw_ostream *>(sfp[0].p);
//	ModulePass *ptr = createPrintModulePass(*OS);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}
//
////## FunctionPass LLVM.createPrintFunctionPass(String banner, OutputStream os, boolean deleteStream);
//KMETHOD LLVM_createPrintFunctionPass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	String *banner = konoha::object_cast<String *>(sfp[0].p);
//	OutputStream *os = konoha::object_cast<OutputStream *>(sfp[1].p);
//	bool deleteStream = sfp[2].bvalue;
//	FunctionPass *ptr = createPrintFunctionPass(banner,os,deleteStream);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ModulePass LLVM.createEdgeProfilerPass();
//KMETHOD LLVM_createEdgeProfilerPass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	ModulePass *ptr = createEdgeProfilerPass();
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ModulePass LLVM.createOptimalEdgeProfilerPass();
//KMETHOD LLVM_createOptimalEdgeProfilerPass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	ModulePass *ptr = createOptimalEdgeProfilerPass();
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ModulePass LLVM.createPathProfilerPass();
//KMETHOD LLVM_createPathProfilerPass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	ModulePass *ptr = createPathProfilerPass();
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ModulePass LLVM.createGCOVProfilerPass(boolean emitNotes, boolean emitData, boolean use402Format);
//KMETHOD LLVM_createGCOVProfilerPass(CTX ctx, ksfp_t *sfp _RIX)
//{
//	bool emitNotes = sfp[0].bvalue;
//	bool emitData = sfp[1].bvalue;
//	bool use402Format = sfp[2].bvalue;
//	ModulePass *ptr = createGCOVProfilerPass(emitNotes,emitData,use402Format);
//	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

//## ModulePass LLVM.createStripSymbolsPass(bool onlyDebugInfo);
KMETHOD LLVM_createStripSymbolsPass(CTX ctx, ksfp_t *sfp _RIX)
{
	bool onlyDebugInfo = sfp[0].bvalue;
	ModulePass *ptr = createStripSymbolsPass(onlyDebugInfo);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createStripNonDebugSymbolsPass();
KMETHOD LLVM_createStripNonDebugSymbolsPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createStripNonDebugSymbolsPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createStripDeadDebugInfoPass();
KMETHOD LLVM_createStripDeadDebugInfoPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createStripDeadDebugInfoPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createConstantMergePass();
KMETHOD LLVM_createConstantMergePass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createConstantMergePass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createGlobalOptimizerPass();
KMETHOD LLVM_createGlobalOptimizerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createGlobalOptimizerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createGlobalDCEPass();
KMETHOD LLVM_createGlobalDCEPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createGlobalDCEPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createFunctionInliningPass(int threshold);
KMETHOD LLVM_createFunctionInliningPass(CTX ctx, ksfp_t *sfp _RIX)
{
	int threshold = sfp[0].ivalue;
	Pass *ptr = createFunctionInliningPass(threshold);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createAlwaysInlinerPass();
KMETHOD LLVM_createAlwaysInlinerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createAlwaysInlinerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createPruneEHPass();
KMETHOD LLVM_createPruneEHPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createPruneEHPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createInternalizePass(bool allButMain);
KMETHOD LLVM_createInternalizePass(CTX ctx, ksfp_t *sfp _RIX)
{
	bool allButMain = sfp[0].bvalue;
	ModulePass *ptr = createInternalizePass(allButMain);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createDeadArgEliminationPass();
KMETHOD LLVM_createDeadArgEliminationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createDeadArgEliminationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createArgumentPromotionPass(int maxElements);
KMETHOD LLVM_createArgumentPromotionPass(CTX ctx, ksfp_t *sfp _RIX)
{
	int maxElements = sfp[0].ivalue;
	Pass *ptr = createArgumentPromotionPass(maxElements);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createIPConstantPropagationPass();
KMETHOD LLVM_createIPConstantPropagationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createIPConstantPropagationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createIPSCCPPass();
KMETHOD LLVM_createIPSCCPPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createIPSCCPPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopExtractorPass();
KMETHOD LLVM_createLoopExtractorPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopExtractorPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createSingleLoopExtractorPass();
KMETHOD LLVM_createSingleLoopExtractorPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createSingleLoopExtractorPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createBlockExtractorPass();
KMETHOD LLVM_createBlockExtractorPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createBlockExtractorPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createStripDeadPrototypesPass();
KMETHOD LLVM_createStripDeadPrototypesPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createStripDeadPrototypesPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createFunctionAttrsPass();
KMETHOD LLVM_createFunctionAttrsPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createFunctionAttrsPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createMergeFunctionsPass();
KMETHOD LLVM_createMergeFunctionsPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createMergeFunctionsPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ModulePass LLVM.createPartialInliningPass();
KMETHOD LLVM_createPartialInliningPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ModulePass *ptr = createPartialInliningPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createConstantPropagationPass();
KMETHOD LLVM_createConstantPropagationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createConstantPropagationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createSCCPPass();
KMETHOD LLVM_createSCCPPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createSCCPPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createDeadInstEliminationPass();
KMETHOD LLVM_createDeadInstEliminationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createDeadInstEliminationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDeadCodeEliminationPass();
KMETHOD LLVM_createDeadCodeEliminationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDeadCodeEliminationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDeadStoreEliminationPass();
KMETHOD LLVM_createDeadStoreEliminationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDeadStoreEliminationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createAggressiveDCEPass();
KMETHOD LLVM_createAggressiveDCEPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createAggressiveDCEPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createScalarReplAggregatesPass(int threshold);
KMETHOD LLVM_createScalarReplAggregatesPass(CTX ctx, ksfp_t *sfp _RIX)
{
	int threshold = sfp[0].ivalue;
	FunctionPass *ptr = createScalarReplAggregatesPass(threshold);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createIndVarSimplifyPass();
KMETHOD LLVM_createIndVarSimplifyPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createIndVarSimplifyPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createInstructionCombiningPass();
KMETHOD LLVM_createInstructionCombiningPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createInstructionCombiningPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLICMPass();
KMETHOD LLVM_createLICMPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLICMPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopUnswitchPass(bool optimizeForSize);
KMETHOD LLVM_createLoopUnswitchPass(CTX ctx, ksfp_t *sfp _RIX)
{
	bool optimizeForSize = sfp[0].bvalue;
	Pass *ptr = createLoopUnswitchPass(optimizeForSize);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopInstSimplifyPass();
KMETHOD LLVM_createLoopInstSimplifyPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopInstSimplifyPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopUnrollPass(int threshold, int count, int allowPartial);
KMETHOD LLVM_createLoopUnrollPass(CTX ctx, ksfp_t *sfp _RIX)
{
	int threshold = sfp[0].ivalue;
	int count = sfp[1].ivalue;
	int allowPartial = sfp[2].ivalue;
	Pass *ptr = createLoopUnrollPass(threshold,count,allowPartial);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopRotatePass();
KMETHOD LLVM_createLoopRotatePass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopRotatePass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopIdiomPass();
KMETHOD LLVM_createLoopIdiomPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopIdiomPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createPromoteMemoryToRegisterPass();
KMETHOD LLVM_createPromoteMemoryToRegisterPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createPromoteMemoryToRegisterPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createDemoteRegisterToMemoryPass();
KMETHOD LLVM_createDemoteRegisterToMemoryPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createDemoteRegisterToMemoryPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createReassociatePass();
KMETHOD LLVM_createReassociatePass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createReassociatePass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createJumpThreadingPass();
KMETHOD LLVM_createJumpThreadingPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createJumpThreadingPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createCFGSimplificationPass();
KMETHOD LLVM_createCFGSimplificationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createCFGSimplificationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createBreakCriticalEdgesPass();
KMETHOD LLVM_createBreakCriticalEdgesPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createBreakCriticalEdgesPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopSimplifyPass();
KMETHOD LLVM_createLoopSimplifyPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopSimplifyPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createTailCallEliminationPass();
KMETHOD LLVM_createTailCallEliminationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createTailCallEliminationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createLowerSwitchPass();
KMETHOD LLVM_createLowerSwitchPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createLowerSwitchPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createBlockPlacementPass();
KMETHOD LLVM_createBlockPlacementPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createBlockPlacementPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLCSSAPass();
KMETHOD LLVM_createLCSSAPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLCSSAPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createEarlyCSEPass();
KMETHOD LLVM_createEarlyCSEPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createEarlyCSEPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createGVNPass(bool noLoads);
KMETHOD LLVM_createGVNPass(CTX ctx, ksfp_t *sfp _RIX)
{
	bool noLoads = sfp[0].bvalue;
	FunctionPass *ptr = createGVNPass(noLoads);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createMemCpyOptPass();
KMETHOD LLVM_createMemCpyOptPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createMemCpyOptPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLoopDeletionPass();
KMETHOD LLVM_createLoopDeletionPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLoopDeletionPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createSimplifyLibCallsPass();
KMETHOD LLVM_createSimplifyLibCallsPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createSimplifyLibCallsPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createInstructionNamerPass();
KMETHOD LLVM_createInstructionNamerPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createInstructionNamerPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createSinkingPass();
KMETHOD LLVM_createSinkingPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createSinkingPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createLowerAtomicPass();
KMETHOD LLVM_createLowerAtomicPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createLowerAtomicPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createCorrelatedValuePropagationPass();
KMETHOD LLVM_createCorrelatedValuePropagationPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createCorrelatedValuePropagationPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createObjCARCExpandPass();
KMETHOD LLVM_createObjCARCExpandPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createObjCARCExpandPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createObjCARCContractPass();
KMETHOD LLVM_createObjCARCContractPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createObjCARCContractPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createObjCARCOptPass();
KMETHOD LLVM_createObjCARCOptPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createObjCARCOptPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createInstructionSimplifierPass();
KMETHOD LLVM_createInstructionSimplifierPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createInstructionSimplifierPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## FunctionPass LLVM.createLowerExpectIntrinsicPass();
KMETHOD LLVM_createLowerExpectIntrinsicPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createLowerExpectIntrinsicPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Pass LLVM.createUnifyFunctionExitNodesPass();
KMETHOD LLVM_createUnifyFunctionExitNodesPass(CTX ctx, ksfp_t *sfp _RIX)
{
	Pass *ptr = createUnifyFunctionExitNodesPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ImmutablePass LLVM.createTypeBasedAliasAnalysisPass();
KMETHOD LLVM_createTypeBasedAliasAnalysisPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ImmutablePass *ptr = createTypeBasedAliasAnalysisPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ImmutablePass LLVM.createBasicAliasAnalysisPass();
KMETHOD LLVM_createBasicAliasAnalysisPass(CTX ctx, ksfp_t *sfp _RIX)
{
	ImmutablePass *ptr = createBasicAliasAnalysisPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ImmutablePass LLVM.createVerifierPass();
KMETHOD LLVM_createVerifierPass(CTX ctx, ksfp_t *sfp _RIX)
{
	FunctionPass *ptr = createVerifierPass();
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	InitializeNativeTarget();
	//kapi->loadIntClassConst(ctx, CLASS_System, IntConstData);
	RETURN_PKGINFO("llvm-2.9");
}

#ifdef __cplusplus
}
#endif
