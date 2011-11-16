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
#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Target/TargetData.h>
#include <llvm/Transforms/Scalar.h>

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
inline T object_cast(knh_RawPtr_t *po)
{
	return static_cast<T>(po->rawptr);
}

template <class T>
inline void convert_array(std::vector<T> &vec, knh_Array_t *a)
{
	size_t size = a->size;
	for (size_t i=0; i < size; i++) {
		T v = konoha::object_cast<T>(a->ptrs[i]);
		vec.push_back(v);
	}
}

}

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

using namespace llvm;
#define PKG_NULVAL(T) PKG_NULVAL_##T
#define PKG_NULVAL_int    (0)
#define PKG_NULVAL_float  (0.0)
#define PKG_NULVAL_String (KNH_NULVAL(CLASS_String))
#define WRAP(ptr) ((void*)ptr)

static void Type_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}
static void Type_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defType(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Type";
	cdef->init = Type_init;
	cdef->free = Type_free;
}

static void IntegerType_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}
static void IntegerType_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defIntegerType(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "IntegerType";
	cdef->init = IntegerType_init;
	cdef->free = IntegerType_free;
}

static void PointerType_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}
static void PointerType_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}
DEFAPI(void) defPointerType(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
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
KMETHOD Type_getVoidTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getVoidTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getLabelTy();
KMETHOD Type_getLabelTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getLabelTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getFloatTy();
KMETHOD Type_getFloatTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFloatTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getDoubleTy();
KMETHOD Type_getDoubleTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getDoubleTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getMetadataTy();
KMETHOD Type_getMetadataTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getMetadataTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getX86FP80Ty();
KMETHOD Type_getX86FP80Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_FP80Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getFP128Ty();
KMETHOD Type_getFP128Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFP128Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getPPCFP128Ty();
KMETHOD Type_getPPCFP128Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getPPC_FP128Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static Type Type.getX86MMXTy();
KMETHOD Type_getX86MMXTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_MMXTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt1Ty();
KMETHOD Type_getInt1Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt1Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt8Ty();
KMETHOD Type_getInt8Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt8Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt16Ty();
KMETHOD Type_getInt16Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt16Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt32Ty();
KMETHOD Type_getInt32Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt32Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static IntegerType Type.getInt64Ty();
KMETHOD Type_getInt64Ty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt64Ty(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getFloatPtrTy();
KMETHOD Type_getFloatPtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFloatPtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getDoublePtrTy();
KMETHOD Type_getDoublePtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getDoublePtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getX86FP80PtrTy();
KMETHOD Type_getX86FP80PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_FP80PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getFP128PtrTy();
KMETHOD Type_getFP128PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getFP128PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getPPCFP128PtrTy();
KMETHOD Type_getPPCFP128PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getPPC_FP128PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getX86MMXPtrTy();
KMETHOD Type_getX86MMXPtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getX86_MMXPtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt1PtrTy();
KMETHOD Type_getInt1PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt1PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt8PtrTy();
KMETHOD Type_getInt8PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt8PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt16PtrTy();
KMETHOD Type_getInt16PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt16PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt32PtrTy();
KMETHOD Type_getInt32PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt32PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType Type.getInt64PtrTy();
KMETHOD Type_getInt64PtrTy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const Type *ptr = Type::getInt64PtrTy(getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## @Static PointerType PointerType.get(Type type);
KMETHOD PointerType_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *type = konoha::object_cast<Type *>(sfp[1].p);
	const Type *ptr  = PointerType::get(type, 0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
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
KMETHOD IRBuilder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BasicBlock *bb = konoha::object_cast<BasicBlock *>(sfp[1].p);
	IRBuilder<> *self = new IRBuilder<>(bb);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(self), IRBuilder_obj_free);
	RETURN_(p);
}


//## ReturnInst IRBuilder.CreateRetVoid();
KMETHOD IRBuilder_createRetVoid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	ReturnInst *ptr = self->CreateRetVoid();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ReturnInst IRBuilder.CreateRet(Value V);
KMETHOD IRBuilder_createRet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	ReturnInst *ptr = self->CreateRet(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## ReturnInst IRBuilder.CreateAggregateRet(Value retVals, int N);
KMETHOD IRBuilder_createAggregateRet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	LLVM_TODO("NO SUPPORT");
	//IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	//Value *const retVals = konoha::object_cast<Value *const>(sfp[1].p);
	//knh_int_t N = Int_to(knh_int_t,sfp[2]);
	//ReturnInst *ptr = self->CreateAggregateRet(retVals, N);
	//knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	//RETURN_(p);
}

//## BranchInst IRBuilder.CreateBr(BasicBlock Dest);
KMETHOD IRBuilder_createBr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock *Dest = konoha::object_cast<BasicBlock *>(sfp[1].p);
	BranchInst *ptr = self->CreateBr(Dest);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## BranchInst IRBuilder.CreateCondBr(Value Cond, BasicBlock True, BasicBlock False);
KMETHOD IRBuilder_createCondBr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Cond = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *True = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *False = konoha::object_cast<BasicBlock *>(sfp[3].p);
	BranchInst *ptr = self->CreateCondBr(Cond, True, False);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## SwitchInst IRBuilder.CreateSwitch(Value V, BasicBlock Dest);
KMETHOD IRBuilder_createSwitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *Dest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	SwitchInst *ptr = self->CreateSwitch(V, Dest);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## IndirectBrInst IRBuilder.CreateIndirectBr(Value Addr);
KMETHOD IRBuilder_createIndirectBr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Addr = konoha::object_cast<Value *>(sfp[1].p);
	IndirectBrInst *ptr = self->CreateIndirectBr(Addr);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke0(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest);
KMETHOD IRBuilder_createInvoke0(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke1(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, Value Arg1);
KMETHOD IRBuilder_createInvoke1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[4].p);
	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest, Arg1);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## InvokeInst IRBuilder.CreateInvoke3(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, Value Arg1, Value Arg2, Value Arg3);
KMETHOD IRBuilder_createInvoke3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[5].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[6].p);
	InvokeInst *ptr = self->CreateInvoke3(Callee, NormalDest, UnwindDest, Arg1, Arg2, Arg3);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## InvokeInst IRBuilder.CreateInvoke(Value Callee, BasicBlock NormalDest, BasicBlock UnwindDest, ArrayRef<Value> Args);
//KMETHOD IRBuilder_createInvoke(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
//	BasicBlock *NormalDest = konoha::object_cast<BasicBlock *>(sfp[2].p);
//	BasicBlock *UnwindDest = konoha::object_cast<BasicBlock *>(sfp[3].p);
//	knh_Array_t *Args = (sfp[4].a);
//	std::vector<Value*> List;
//	konoha::convert_array(List, Args);
//	InvokeInst *ptr = self->CreateInvoke(Callee, NormalDest, UnwindDest, List.begin(), List.end());
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## ResumeInst IRBuilder.CreateResume(Value Exn);
//KMETHOD IRBuilder_createResume(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Exn = konoha::object_cast<Value *>(sfp[1].p);
//	ResumeInst *ptr = self->CreateResume(Exn);
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}
//
//## UnreachableInst IRBuilder.CreateUnreachable();
KMETHOD IRBuilder_createUnreachable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	UnreachableInst *ptr = self->CreateUnreachable();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createAdd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAdd(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWAdd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWAdd(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWAdd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWAdd(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFAdd(Value LHS, Value RHS);
KMETHOD IRBuilder_createFAdd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFAdd(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createSub(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSub(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWSub(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWSub(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWSub(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWSub(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFSub(Value LHS, Value RHS);
KMETHOD IRBuilder_createFSub(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFSub(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createMul(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateMul(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createNSWMul(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNSWMul(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createNUWMul(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateNUWMul(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFMul(Value LHS, Value RHS);
KMETHOD IRBuilder_createFMul(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFMul(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateUDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createUDiv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateUDiv(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExactUDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createExactUDiv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExactUDiv(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createSDiv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSDiv(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExactSDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createExactSDiv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExactSDiv(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFDiv(Value LHS, Value RHS);
KMETHOD IRBuilder_createFDiv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFDiv(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateURem(Value LHS, Value RHS);
KMETHOD IRBuilder_createURem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateURem(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSRem(Value LHS, Value RHS);
KMETHOD IRBuilder_createSRem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateSRem(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFRem(Value LHS, Value RHS);
KMETHOD IRBuilder_createFRem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFRem(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateShl(Value LHS, Value RHS);
KMETHOD IRBuilder_createShl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateShl(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateLShr(Value LHS, Value RHS);
KMETHOD IRBuilder_createLShr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateLShr(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAShr(Value LHS, Value RHS);
KMETHOD IRBuilder_createAShr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAShr(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateAnd(Value LHS, Value RHS);
KMETHOD IRBuilder_createAnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateAnd(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateOr(Value LHS, Value RHS);
KMETHOD IRBuilder_createOr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateOr(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateXor(Value LHS, Value RHS);
KMETHOD IRBuilder_createXor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateXor(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNeg(Value V);
KMETHOD IRBuilder_createNeg(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNeg(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNSWNeg(Value V);
KMETHOD IRBuilder_createNSWNeg(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNSWNeg(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNUWNeg(Value V);
KMETHOD IRBuilder_createNUWNeg(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNUWNeg(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFNeg(Value V);
KMETHOD IRBuilder_createFNeg(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateFNeg(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateNot(Value V);
KMETHOD IRBuilder_createNot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateNot(V);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## AllocaInst IRBuilder.CreateAlloca(Type Ty, Value ArraySize);
KMETHOD IRBuilder_createAlloca(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[1].p);
	Value *ArraySize = konoha::object_cast<Value *>(sfp[2].p);
	AllocaInst *ptr = self->CreateAlloca(Ty, ArraySize);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## LoadInst IRBuilder.CreateLoad(Value Ptr, bool isVolatile);
KMETHOD IRBuilder_createLoad(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_bool_t isVolatile = sfp[2].bvalue;
	LoadInst *ptr = self->CreateLoad(Ptr, isVolatile);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## StoreInst IRBuilder.CreateStore(Value Val, Value Ptr, bool isVolatile);
KMETHOD IRBuilder_createStore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Val = konoha::object_cast<Value *>(sfp[1].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[2].p);
	knh_bool_t isVolatile = sfp[3].bvalue;
	StoreInst *ptr = self->CreateStore(Val, Ptr, isVolatile);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## FenceInst IRBuilder.CreateFence(AtomicOrdering Ordering, SynchronizationScope SynchScope);
//KMETHOD IRBuilder_createFence(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	AtomicOrdering *Ordering = konoha::object_cast<AtomicOrdering *>(sfp[1].p);
//	SynchronizationScope *SynchScope = konoha::object_cast<SynchronizationScope *>(sfp[2].p);
//	FenceInst *ptr = self->CreateFence(Ordering, SynchScope);
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}
//
////## AtomicCmpXchgInst IRBuilder.CreateAtomicCmpXchg(Value Ptr, Value Cmp, Value New, AtomicOrdering Ordering, SynchronizationScope SynchScope);
//KMETHOD IRBuilder_createAtomicCmpXchg(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
//	Value *Cmp = konoha::object_cast<Value *>(sfp[2].p);
//	Value *New = konoha::object_cast<Value *>(sfp[3].p);
//	AtomicOrdering *Ordering = konoha::object_cast<AtomicOrdering *>(sfp[4].p);
//	SynchronizationScope *SynchScope = konoha::object_cast<SynchronizationScope *>(sfp[5].p);
//	AtomicCmpXchgInst *ptr = self->CreateAtomicCmpXchg(Ptr, Cmp, New, Ordering, SynchScope);
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

//## Value IRBuilder.CreateGEP(Value Ptr, ArrayRef< Value > IdxList);
KMETHOD IRBuilder_createGEP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_Array_t *IdxList = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, IdxList);
	Value *ptr = self->CreateGEP(Ptr, List);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInBoundsGEP(Value Ptr, ArrayRef< Value > IdxList);
KMETHOD IRBuilder_createInBoundsGEP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_Array_t *IdxList = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, IdxList);
	Value *ptr = self->CreateInBoundsGEP(Ptr, List);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGEP1(Value Ptr, Value Idx);
KMETHOD IRBuilder_createGEP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateGEP(Ptr, Idx);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInBoundsGEP1(Value Ptr, Value Idx);
KMETHOD IRBuilder_createInBoundsGEP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateInBoundsGEP(Ptr, Idx);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP1_32(Value Ptr, int Idx0);
KMETHOD IRBuilder_createConstGEP132(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = Int_to(knh_int_t,sfp[2]);
	Value *ptr = self->CreateConstGEP1_32(Ptr, Idx0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP1_32(Value Ptr, int Idx0);
KMETHOD IRBuilder_createConstInBoundsGEP132(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = Int_to(knh_int_t,sfp[2]);
	Value *ptr = self->CreateConstInBoundsGEP1_32(Ptr, Idx0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP2_32(Value Ptr, int Idx0, int Idx1);
KMETHOD IRBuilder_createConstGEP232(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = Int_to(knh_int_t,sfp[2]);
	knh_int_t Idx1 = Int_to(knh_int_t,sfp[3]);
	Value *ptr = self->CreateConstGEP2_32(Ptr, Idx0, Idx1);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP2_32(Value Ptr, int Idx0, int Idx1);
KMETHOD IRBuilder_createConstInBoundsGEP232(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = Int_to(knh_int_t,sfp[2]);
	knh_int_t Idx1 = Int_to(knh_int_t,sfp[3]);
	Value *ptr = self->CreateConstInBoundsGEP2_32(Ptr, Idx0, Idx1);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP1_64(Value Ptr, uint64_t Idx0);
KMETHOD IRBuilder_createConstGEP164(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = sfp[2].ivalue;
	Value *ptr = self->CreateConstGEP1_64(Ptr, Idx0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP1_64(Value Ptr, uint64_t Idx0);
KMETHOD IRBuilder_createConstInBoundsGEP164(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = sfp[2].ivalue;
	Value *ptr = self->CreateConstInBoundsGEP1_64(Ptr, Idx0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstGEP2_64(Value Ptr, uint64_t Idx0, uint64_t Idx1);
KMETHOD IRBuilder_createConstGEP264(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = sfp[2].ivalue;
	knh_int_t Idx1 = sfp[3].ivalue;
	Value *ptr = self->CreateConstGEP2_64(Ptr, Idx0, Idx1);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateConstInBoundsGEP2_64(Value Ptr, uint64_t Idx0, uint64_t Idx1);
KMETHOD IRBuilder_createConstInBoundsGEP264(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx0 = sfp[2].ivalue;
	knh_int_t Idx1 = sfp[3].ivalue;
	Value *ptr = self->CreateConstInBoundsGEP2_64(Ptr, Idx0, Idx1);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateStructGEP(Value Ptr, int Idx);
KMETHOD IRBuilder_createStructGEP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Ptr = konoha::object_cast<Value *>(sfp[1].p);
	knh_int_t Idx = Int_to(knh_int_t,sfp[2]);
	Value *ptr = self->CreateStructGEP(Ptr, Idx);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGlobalString(StringRef Str);
KMETHOD IRBuilder_createGlobalString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	knh_String_t *Str = sfp[1].s;
	Value *ptr = self->CreateGlobalString(S_totext(Str));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateGlobalStringPtr(StringRef Str);
KMETHOD IRBuilder_createGlobalStringPtr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	knh_String_t *Str = sfp[1].s;
	Value *ptr = self->CreateGlobalStringPtr(S_totext(Str));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateTrunc(Value V, Type DestTy);
KMETHOD IRBuilder_createTrunc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateTrunc(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateZExt(Value V, Type DestTy);
KMETHOD IRBuilder_createZExt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateZExt(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSExt(Value V, Type DestTy);
KMETHOD IRBuilder_createSExt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSExt(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPToUI(Value V, Type DestTy);
KMETHOD IRBuilder_createFPToUI(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPToUI(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPToSI(Value V, Type DestTy);
KMETHOD IRBuilder_createFPToSI(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPToSI(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateUIToFP(Value V, Type DestTy);
KMETHOD IRBuilder_createUIToFP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateUIToFP(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSIToFP(Value V, Type DestTy);
KMETHOD IRBuilder_createSIToFP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSIToFP(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPTrunc(Value V, Type DestTy);
KMETHOD IRBuilder_createFPTrunc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPTrunc(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPExt(Value V, Type DestTy);
KMETHOD IRBuilder_createFPExt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPExt(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePtrToInt(Value V, Type DestTy);
KMETHOD IRBuilder_createPtrToInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreatePtrToInt(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIntToPtr(Value V, Type DestTy);
KMETHOD IRBuilder_createIntToPtr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateIntToPtr(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createBitCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateBitCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateZExtOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createZExtOrBitCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateZExtOrBitCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSExtOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createSExtOrBitCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateSExtOrBitCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateTruncOrBitCast(Value V, Type DestTy);
KMETHOD IRBuilder_createTruncOrBitCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateTruncOrBitCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePointerCast(Value V, Type DestTy);
KMETHOD IRBuilder_createPointerCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreatePointerCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIntCast(Value V, Type DestTy, boolean isSigned);
KMETHOD IRBuilder_createIntCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	knh_bool_t isSigned = sfp[3].bvalue;
	Value *ptr = self->CreateIntCast(V, DestTy, isSigned);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFPCast(Value V, Type DestTy);
KMETHOD IRBuilder_createFPCast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V = konoha::object_cast<Value *>(sfp[1].p);
	Type *DestTy = konoha::object_cast<Type *>(sfp[2].p);
	Value *ptr = self->CreateFPCast(V, DestTy);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpEQ(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpNE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpNE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpNE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpUGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpUGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpUGT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpUGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpUGE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpUGE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpULT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpULT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpULT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpULE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpULE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpULE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSGT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSGE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSGE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSLT(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSLT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSLT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateICmpSLE(Value LHS, Value RHS);
KMETHOD IRBuilder_createICmpSLE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateICmpSLE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOEQ(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOGT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOGE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOGE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOLT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOLT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOLT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpOLE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpOLE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpOLE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpONE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpONE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpONE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpORD(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpORD(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpORD(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUNO(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUNO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUNO(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUEQ(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUEQ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUEQ(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUGT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUGT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUGT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUGE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUGE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUGE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpULT(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpULT(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpULT(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpULE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpULE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpULE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateFCmpUNE(Value LHS, Value RHS);
KMETHOD IRBuilder_createFCmpUNE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateFCmpUNE(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## PHINode IRBuilder.CreatePHI(Type Ty, int numReservedValues);
KMETHOD IRBuilder_createPHI(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[1].p);
	knh_int_t num = sfp[2].ivalue;
	PHINode *ptr = self->CreatePHI(Ty, num);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void IRBuilder.addIncoming(Type Ty, BasicBlock bb);
KMETHOD PHINode_addIncoming(CTX ctx, knh_sfp_t *sfp _RIX)
{
	PHINode *self = konoha::object_cast<PHINode *>(sfp[0].p);
	Value *v = konoha::object_cast<Value *>(sfp[1].p);
	BasicBlock *bb = konoha::object_cast<BasicBlock *>(sfp[2].p);
	self->addIncoming(v, bb);
	RETURNvoid_();
}

//## CallInst IRBuilder.CreateCall1(Value Callee, Value Arg);
KMETHOD IRBuilder_createCall1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[2].p);
	CallInst *ptr = self->CreateCall(Callee, Arg);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall2(Value Callee, Value Arg1, Value Arg2);
KMETHOD IRBuilder_createCall2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	CallInst *ptr = self->CreateCall2(Callee, Arg1, Arg2);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall3(Value Callee, Value Arg1, Value Arg2, Value Arg3);
KMETHOD IRBuilder_createCall3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	CallInst *ptr = self->CreateCall3(Callee, Arg1, Arg2, Arg3);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall4(Value Callee, Value Arg1, Value Arg2, Value Arg3, Value Arg4);
KMETHOD IRBuilder_createCall4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg4 = konoha::object_cast<Value *>(sfp[5].p);
	CallInst *ptr = self->CreateCall4(Callee, Arg1, Arg2, Arg3, Arg4);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall5(Value Callee, Value Arg1, Value Arg2, Value Arg3, Value Arg4, Value Arg5);
KMETHOD IRBuilder_createCall5(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	Value *Arg1 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Arg2 = konoha::object_cast<Value *>(sfp[3].p);
	Value *Arg3 = konoha::object_cast<Value *>(sfp[4].p);
	Value *Arg4 = konoha::object_cast<Value *>(sfp[5].p);
	Value *Arg5 = konoha::object_cast<Value *>(sfp[6].p);
	CallInst *ptr = self->CreateCall5(Callee, Arg1, Arg2, Arg3, Arg4, Arg5);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## CallInst IRBuilder.CreateCall(Value Callee, ArrayRef< Value > Args);
KMETHOD IRBuilder_createCall(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Callee = konoha::object_cast<Value *>(sfp[1].p);
	knh_Array_t *Args = sfp[2].a;
	std::vector<Value*> List;
	konoha::convert_array(List, Args);
	CallInst *ptr = self->CreateCall(Callee, List);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateSelect(Value C, Value True, Value False);
KMETHOD IRBuilder_createSelect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *C = konoha::object_cast<Value *>(sfp[1].p);
	Value *True = konoha::object_cast<Value *>(sfp[2].p);
	Value *False = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateSelect(C, True, False);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## VAArgInst IRBuilder.CreateVAArg(Value List, Type Ty);
KMETHOD IRBuilder_createVAArg(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *List = konoha::object_cast<Value *>(sfp[1].p);
	Type *Ty = konoha::object_cast<Type *>(sfp[2].p);
	VAArgInst *ptr = self->CreateVAArg(List, Ty);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateExtractElement(Value Vec, Value Idx);
KMETHOD IRBuilder_createExtractElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Vec = konoha::object_cast<Value *>(sfp[1].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreateExtractElement(Vec, Idx);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateInsertElement(Value Vec, Value NewElt, Value Idx);
KMETHOD IRBuilder_createInsertElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Vec = konoha::object_cast<Value *>(sfp[1].p);
	Value *NewElt = konoha::object_cast<Value *>(sfp[2].p);
	Value *Idx = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateInsertElement(Vec, NewElt, Idx);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateShuffleVector(Value V1, Value V2, Value Mask);
KMETHOD IRBuilder_createShuffleVector(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *V1 = konoha::object_cast<Value *>(sfp[1].p);
	Value *V2 = konoha::object_cast<Value *>(sfp[2].p);
	Value *Mask = konoha::object_cast<Value *>(sfp[3].p);
	Value *ptr = self->CreateShuffleVector(V1, V2, Mask);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

////## Value IRBuilder.CreateExtractValue(Value Agg, Array<int> Idxs);
//KMETHOD IRBuilder_createExtractValue(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Agg = konoha::object_cast<Value *>(sfp[1].p);
//	knh_Array_t *Idxs = sfp[2].a;
//	std::vector<int> List;
//	konoha::convert_array_int(List, Idxs);
//	Value *ptr = self->CreateExtractValue(Agg, List.begin(), List.end());
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

////## Value IRBuilder.CreateInsertValue(Value Agg, Value Val, Array<int> Idxs);
//KMETHOD IRBuilder_createInsertValue(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
//	Value *Agg = konoha::object_cast<Value *>(sfp[1].p);
//	Value *Val = konoha::object_cast<Value *>(sfp[2].p);
//	knh_Array_t *Idxs = sfp[2].a;
//	std::vector<int> List;
//	konoha::convert_array_int(List, Idxs);
//	Value *ptr = self->CreateInsertValue(Agg, Val, List.begin(), List.end());
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(p);
//}

//## Value IRBuilder.CreateIsNull(Value Arg);
KMETHOD IRBuilder_createIsNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateIsNull(Arg);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreateIsNotNull(Value Arg);
KMETHOD IRBuilder_createIsNotNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *Arg = konoha::object_cast<Value *>(sfp[1].p);
	Value *ptr = self->CreateIsNotNull(Arg);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Value IRBuilder.CreatePtrDiff(Value LHS, Value RHS);
KMETHOD IRBuilder_createPtrDiff(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	Value *LHS = konoha::object_cast<Value *>(sfp[1].p);
	Value *RHS = konoha::object_cast<Value *>(sfp[2].p);
	Value *ptr = self->CreatePtrDiff(LHS, RHS);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void IRBuilder.SetInsertPoint(BasicBlock BB);
KMETHOD IRBuilder_setInsertPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock * BB = konoha::object_cast<BasicBlock *>(sfp[1].p);
	self->SetInsertPoint(BB);
	RETURNvoid_();
}

//## BasicBlock IRBuilder.GetInsertBlock();
KMETHOD IRBuilder_getInsertBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IRBuilder<> *self = konoha::object_cast<IRBuilder<> *>(sfp[0].p);
	BasicBlock *BB = self->GetInsertBlock();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(BB), obj_free);
	RETURN_(p);
}

//## Function BasicBlock.getParent();
KMETHOD BasicBlock_getParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	Function *ptr = self->getParent();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## Instruction BasicBlock.getTerminator();
KMETHOD BasicBlock_getTerminator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	TerminatorInst *ptr = self->getTerminator();
	if (ptr) {
		knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}


////## iterator BasicBlock.begin();
//KMETHOD BasicBlock_begin(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
//	*ptr = self->Create();
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(KNH_NULL);
//}
//
////## iterator BasicBlock.end();
//KMETHOD BasicBlock_end(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
//	*ptr = self->Create();
//	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
//	RETURN_(KNH_NULL);
//}

//## int BasicBlock.size();
KMETHOD BasicBlock_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	int ret = self->size();
	RETURNi_(ret);
}

//## boolean BasicBlock.empty();
KMETHOD BasicBlock_empty(CTX ctx, knh_sfp_t *sfp _RIX)
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
KMETHOD Argument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *ty = konoha::object_cast<Type *>(sfp[1].p);
	Value *v = new Argument(ty, "", 0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(v), obj_free);
	RETURN_(p);
}

//## Module Module.new(String name);
KMETHOD Module_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *name = sfp[1].s;
	Module *ptr = new Module(S_totext(name), getGlobalContext());
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), Module_obj_free);
	RETURN_(p);
}

////## void Module.addTypeName(String name, Type type);
//KMETHOD Module_addTypeName(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	Module *self = konoha::object_cast<Module *>(sfp[0].p);
//	knh_String_t * name = sfp[1].s;
//	Type *type = konoha::object_cast<Type *>(sfp[2].p);
//	self->addTypeName(S_totext(name), type);
//	RETURNvoid_();
//}

//## void Module.dump();
KMETHOD Module_dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	(*self).dump();
	RETURNvoid_();
}

//## void BasicBlock.dump();
KMETHOD BasicBlock_dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BasicBlock *self = konoha::object_cast<BasicBlock *>(sfp[0].p);
	(*self).dump();
	RETURNvoid_();
}

//## Function Module.getOrInsertFunction(String name, FunctionType fnTy);
KMETHOD Module_getOrInsertFunction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	knh_String_t *name = sfp[1].s;
	FunctionType *fnTy = konoha::object_cast<FunctionType *>(sfp[2].p);
	Function *ptr = cast<Function>(self->getOrInsertFunction(S_totext(name), fnTy));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static @Native Function Function.create(String name, FunctionType fnTy, Module m);
KMETHOD Function_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *name = sfp[1].s;
	FunctionType *fnTy = konoha::object_cast<FunctionType *>(sfp[2].p);
	Module *m = konoha::object_cast<Module *>(sfp[3].p);
	Function *ptr = Function::Create(fnTy, GlobalValue::ExternalLinkage, S_totext(name), m);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native void Function.dump();
KMETHOD Function_dump(CTX ctx, knh_sfp_t *sfp _RIX)
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
KMETHOD Module_createExecutionEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Module *self = konoha::object_cast<Module *>(sfp[0].p);
	ExecutionEngine *ptr = EngineBuilder(self).setEngineKind(EngineKind::JIT).create();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), ExecutionEngine_obj_free);
	if (!ptr) {
		KNH_P("error");
	}
	RETURN_(p);
}
//## @Static BasicBlock BasicBlock.create(Function parent);
KMETHOD BasicBlock_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Function * parent = konoha::object_cast<Function *>(sfp[1].p);
	BasicBlock *ptr = BasicBlock::Create(getGlobalContext(), "", parent);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static FunctionType.get(Type retTy, Array<Type> args, boolean b);
KMETHOD FunctionType_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *retTy = konoha::object_cast<Type *>(sfp[1].p);
	knh_Array_t * args = sfp[2].a;
	knh_bool_t b = sfp[3].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	FunctionType *ptr = FunctionType::get(retTy, List, b);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native Value ConstantInt.get(Type type, int v);
KMETHOD ConstantInt_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *type  = konoha::object_cast<Type *>(sfp[1].p);
	knh_int_t v = sfp[2].ivalue;
	Value *ptr = ConstantInt::get(type, v);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Native Value ConstantFP.get(Type type, float v);
KMETHOD ConstantFP_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *type  = konoha::object_cast<Type *>(sfp[1].p);
	knh_float_t v = sfp[2].fvalue;
	Value *ptr = ConstantFP::get(type, v);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static StructType.get(Array<Type> args, boolean isPacked);
KMETHOD StructType_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *args = sfp[1].a;
	knh_bool_t isPacked = sfp[2].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	StructType *ptr = StructType::get(getGlobalContext(), List, isPacked);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## @Static StructType.create(Array<Type> args, String name, boolean isPacked);
KMETHOD StructType_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *args = sfp[1].a;
	knh_String_t *name = sfp[2].s;
	knh_bool_t isPacked = sfp[3].bvalue;
	std::vector<Type*> List;
	konoha::convert_array(List, args);
	StructType *ptr = StructType::create(List, S_totext(name), isPacked);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}


//## NativeFunction ExecutionEngine.getPointerToFunction(Module m, Function func);
KMETHOD ExecutionEngine_getPointerToFunction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	ExecutionEngine *ee = konoha::object_cast<ExecutionEngine *>(sfp[0].p);
	Module *m = konoha::object_cast<Module *>(sfp[1].p);
	Function *func = konoha::object_cast<Function *>(sfp[2].p);

	FunctionPassManager pm(m);
	pm.add(new TargetData(*ee->getTargetData()));
	pm.add(createBasicAliasAnalysisPass());
	pm.add(createPromoteMemoryToRegisterPass());
	pm.add(createInstructionCombiningPass());
	pm.add(createReassociatePass());
	pm.add(createGVNPass());
	pm.add(createCFGSimplificationPass());
	pm.doInitialization();

	pm.run(*func);

	void *ptr = ee->getPointerToFunction(func);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), obj_free);
	RETURN_(p);
}

//## void Method.setFunction(NativeFunction func);
KMETHOD Method_setFunction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = (knh_Method_t*) sfp[0].o;
	knh_RawPtr_t *po = sfp[1].p;
	knh_Method_setFunc(ctx, mtd, (knh_Fmethod)po->rawptr);
	RETURNvoid_();
}

//## void Func.setFunction(NativeFunction func);
KMETHOD Func_setFunction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t *fo   = sfp[0].fo;
	knh_RawPtr_t *po = sfp[1].p;
	knh_Method_t *mtd = fo->mtd;
	knh_Method_setFunc(ctx, mtd, (knh_Fmethod)po->rawptr);
	RETURNvoid_();
}

//## @Native Array<Value> Function.getArguments();
KMETHOD Function_getArguments(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_type_t rtype = knh_ParamArray_rtype(DP(sfp[K_MTDIDX].mtdNC)->mp);
	knh_class_t cid = C_p1(rtype);
	Function *func = konoha::object_cast<Function *>(sfp[0].p);
	knh_Array_t *a = new_Array(ctx, cid, 0);
	for (Function::arg_iterator I = func->arg_begin(), E = func->arg_end();
			I != E; ++I) {
		Value *v = I;
		knh_RawPtr_t *po = new_Pointer(ctx, "Value", WRAP(v), NULL);
		knh_Array_add(ctx, a, po);
	}
	RETURN_(a);
}
//## void Value.replaceAllUsesWith(Value v);
KMETHOD Value_replaceAllUsesWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	Value *v = konoha::object_cast<Value *>(sfp[1].p);
	self->replaceAllUsesWith(v);
	RETURNvoid_();
}
//## Value Value.setName(String name);
KMETHOD Value_setName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	knh_String_t *name = sfp[1].s;
	self->setName(S_totext(name));
	RETURNvoid_();
}

//## Type Value.getType();
KMETHOD Value_getType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	const Type *ptr = self->getType();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), type_ptr_free);
	RETURN_(p);
}

//## void Value.dump();
KMETHOD Value_dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Value *self = konoha::object_cast<Value *>(sfp[0].p);
	self->dump();
	RETURNvoid_();
}

//## @Native void Type.dump();
KMETHOD Type_dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Type *type = konoha::object_cast<Type *>(sfp[0].p);
	type->dump();
	RETURNvoid_();
}


//## @Static boolean DynamicLibrary.loadLibraryPermanently(String libname);
KMETHOD DynamicLibrary_loadLibraryPermanently(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *libname = S_totext(sfp[1].s);
	std::string ErrMsg;
	knh_bool_t ret = sys::DynamicLibrary::LoadLibraryPermanently(libname, &ErrMsg);
	if (ret == 0) {
		knh_ldata_t ldata[] = {LOG_s("libname", libname), LOG_msg(ErrMsg.c_str()), LOG_sfp, LOG_END};
		KNH_NTRACE(ctx, "LoadLibraryPermanently", K_FAILED, ldata);
	}
	RETURNb_(ret);
}

//## @Static Int DynamicLibrary.searchForAddressOfSymbol(String fname);
KMETHOD DynamicLibrary_searchForAddressOfSymbol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *fname = S_totext(sfp[1].s);
	knh_int_t ret = 0;
	void *symAddr = NULL;
	if (!(symAddr = sys::DynamicLibrary::SearchForAddressOfSymbol(fname))) {
		ret = reinterpret_cast<knh_int_t>(symAddr);
	}
	RETURNi_(ret);
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
