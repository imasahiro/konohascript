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
#include <llvm/Pass.h>
#include <llvm/Constants.h>
#include <llvm/Function.h>
#include <llvm/Instructions.h>
#include <llvm/Metadata.h>
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

static void default_free(void *p) {
    /* do nothing */
    (void)p;
}

template<class T>
static void object_free(void *p)
{
    T *o = static_cast<T *>(p);
    delete o;
}
}

using namespace llvm;

#if 0
static void emit(Function &F, Module *m, BasicBlock *BB, int espshift) {
    LLVMContext &Context = m->getContext();
    Function::arg_iterator args = F.arg_begin();
    Value *vctx = args++;
    Value *vsfp = args;
    Type *IntTy = Type::getInt64Ty(Context);
    PointerType *Int8PtrTy = Type::getInt8PtrTy(Context);
    BasicBlock *bb0 = BasicBlock::Create(Context, "bb0", &F);
    BasicBlock *bb1 = BasicBlock::Create(Context, "bb1", &F);
    BasicBlock *bb2 = BB->splitBasicBlock(--(BB->end()), "bb2");
    IRBuilder<> builder(bb0);

    {
        TerminatorInst *TI = BB->getTerminator();
        for (size_t i = 0; i < TI->getNumSuccessors(); ++i) {
            if (TI->getSuccessor(i) == bb2) {
                TI->setSuccessor(i, bb0);
                break;
            }
        }
    }

    /* cond = (ctx->safepoint == 1) */
    Value *V    = builder.CreateLoad(builder.CreateStructGEP(vctx, 0));
    Value *Cond = builder.CreateICmpEQ(V, ConstantInt::get(Type::getInt32Ty(Context), 1));

    builder.CreateCondBr(Cond, bb1, bb2);
    builder.SetInsertPoint(bb1);

    if (espshift > 0) {
        Value *vesp  = builder.CreateStructGEP(vctx, 9);
        Value *vsfp_ = builder.CreateConstGEP1_32(vsfp, espshift);
        builder.CreateStore(vsfp_, vesp);
    }
    Type *argsType[]   = {vctx->getType(), vsfp->getType(), Int8PtrTy, IntTy};
    FunctionType *fnTy = FunctionType::get(Type::getVoidTy(Context), argsType, false);
    Function *fcheck = cast<Function>(m->getOrInsertFunction("knh_checkSafePoint", fnTy));

    Value *vstr  = ConstantPointerNull::get(Int8PtrTy);
    Value *vline = ConstantInt::get(IntTy, 0);
    vsfp  = builder.CreateConstGEP1_32(vsfp, espshift);
    builder.CreateCall4(fcheck, vctx, vsfp, vstr, vline);
    builder.CreateBr(bb2);
}
#else

extern "C" void compiler_checkSafePoint(CTX ctx, int espshift)
{
    if (ctx->safepoint != 0) {
        asm volatile("int3");
        ((kcontext_t*)ctx)->esp = ctx->esp + espshift;
        knh_checkSafePoint(ctx, ctx->esp, __FILE__, __LINE__);
    }
}

static void emit(Function &F, Module *m, BasicBlock *BB, int espshift) {
    LLVMContext &Context = m->getContext();
    Function::arg_iterator args = F.arg_begin();
    Value *vctx = args;
    Type *Int32Ty = Type::getInt32Ty(Context);
    Type *VoidTy  = Type::getVoidTy(Context);
    Instruction *I = --(BB->end());
    Constant *C    = ConstantInt::get(Int32Ty, espshift);
    ///* cond = (ctx->safepoint == 1) */
    //if (espshift > 0) {
    //    Value *Zero = ConstantInt::get(Int32Ty, 0);
    //    Value *Idx0[] = { Zero, ConstantInt::get(Int32Ty, 9)};
    //    Value *Idx1[] = { C };
    //    GetElementPtrInst *vesp  = GetElementPtrInst::Create(vctx, Idx0);
    //    GetElementPtrInst *vsfp_ = GetElementPtrInst::Create(vsfp, Idx1);
    //    StoreInst *SI = new StoreInst(vsfp_, vesp);
    //    BB->getInstList().insert(I, vesp);
    //    BB->getInstList().insert(I, vsfp_);
    //    BB->getInstList().insert(I, SI);
    //}
    Type *argsType[]   = {vctx->getType(), Int32Ty};
    FunctionType *fnTy = FunctionType::get(VoidTy, argsType, false);
    Value *Args[] = { vctx, C };

#if 0
#if SIZEOF_VOIDP == 8
    Type *LongTy = Type::getInt64Ty(Context);
#else
    Type *LongTy = Type::getInt32Ty(Context);
#endif
    PointerType  *fnPtrTy = PointerType::get(fnTy, 0);
    Constant *Fptr  = ConstantInt::get(LongTy, (intptr_t)compiler_checkSafePoint);
    Value *Check = ConstantExpr::getBitCast(Fptr, fnPtrTy);
#else
    Value *Check = m->getOrInsertFunction("compiler_checkSafePoint", fnTy);
#endif
    CallInst *CI = CallInst::Create(Check, Args);
    CI->setTailCall(true);
    BB->getInstList().insert(I, CI);
}
#endif

namespace compiler {
struct SafePoint : public FunctionPass {
    static char ID;
    SafePoint() : FunctionPass(ID) {}
    virtual bool runOnFunction(Function &F) {
        bool Changed = false;
        Module *m = F.getParent();
        LLVMContext &Context = m->getContext();
        NamedMDNode *NMD = m->getNamedMetadata("safepoint");
        if (!NMD)
            return false;
        unsigned KindID = Context.getMDKindID("safepoint");

        std::vector<BasicBlock *> BBs;
        std::vector<int64_t> OPs;
        size_t N = NMD->getNumOperands();
        for (Function::iterator I = F.begin(), E = F.end(); I != E; ++I) {
            TerminatorInst *Inst = I->getTerminator();
            if (Inst->hasMetadata()) {
                MDNode *MD = Inst->getMetadata(KindID);
                for (size_t i = 0; i < N; ++i) {
                    MDNode *node = NMD->getOperand(i);
                    if (MD == node) {
                        ConstantInt *C = cast<ConstantInt>(MD->getOperand(0));
                        BBs.push_back(I);
                        OPs.push_back(C->getSExtValue());
                        Changed = true;
                    }
                }
            }
        }
        if (Changed == false) {
            return Changed;
        }

        for (size_t i = 0; i < BBs.size(); ++i) {
            BasicBlock *BB = BBs[i];
            emit(F, m, BB, OPs[i]);
        }
        return Changed;
    }
};
} /* namespace compiler */

char compiler::SafePoint::ID = 0;
static RegisterPass<compiler::SafePoint> X("SafePoint", "SafePoint World Pass");

#define WRAP(ptr) ((void*)ptr)
#define _UNUSED_ __attribute__((unused))

//## @Public @Native FunctionPass LLVM.createSafePointPass();
extern "C" KMETHOD LLVM_createSafePointPass(CTX ctx, ksfp_t *sfp _RIX)
{
    FunctionPass *ptr = new compiler::SafePoint();
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ptr), konoha::default_free);
    RETURN_(p);
}

extern "C" DEFAPI(const knh_PackageDef_t*) init(CTX ctx _UNUSED_, const knh_LoaderAPI_t *kapi _UNUSED_)
{
    kapi->setPackageProperty(ctx, "name", "compiler.llvm");
    kapi->setPackageProperty(ctx, "version", "0.0");
    RETURN_PKGINFO("compiler-llvm-0.0");
}

