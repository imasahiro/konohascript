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

include "lib:gluelink";

@RawPtr class Type;
@RawPtr class IntegerType extends Type;
@RawPtr class PointerType extends Type;
@RawPtr class FunctionType extends Type;
@RawPtr class StructType extends Type;
@RawPtr class Value;
@RawPtr class IRBuilder;
@RawPtr class Instruction extends Value;
@RawPtr class ReturnInst extends Instruction;
@RawPtr class LoadInst   extends Instruction;
@RawPtr class StoreInst  extends Instruction;
@RawPtr class BranchInst extends Instruction;
@RawPtr class CallInst   extends Instruction;
@Rawptr class BasicBlock;
@RawPtr class Module;
@RawPtr class Function extends Value;
@RawPtr class ExecutionEngine;
@RawPtr class NativeFunction;

@Native @Static Type Type.getVoidTy();
@Native @Static Type Type.getLabelTy();
@Native @Static Type Type.getFloatTy();
@Native @Static Type Type.getDoubleTy();
@Native @Static Type Type.getMetadataTy();
@Native @Static Type Type.getX86_FP80Ty();
@Native @Static Type Type.getFP128Ty();
@Native @Static Type Type.getPPC_FP128Ty();
@Native @Static Type Type.getX86_MMXTy();
@Native @Static IntegerType Type.getInt1Ty();
@Native @Static IntegerType Type.getInt8Ty();
@Native @Static IntegerType Type.getInt16Ty();
@Native @Static IntegerType Type.getInt32Ty();
@Native @Static IntegerType Type.getInt64Ty();
@Native @Static PointerType PointerType.get(Type type);
@Native @Static PointerType Type.getFloatPtrTy();
@Native @Static PointerType Type.getDoublePtrTy();
@Native @Static PointerType Type.getX86_FP80PtrTy();
@Native @Static PointerType Type.getFP128PtrTy();
@Native @Static PointerType Type.getPPC_FP128PtrTy();
@Native @Static PointerType Type.getX86_MMXPtrTy();
@Native @Static PointerType Type.getInt1PtrTy();
@Native @Static PointerType Type.getInt8PtrTy();
@Native @Static PointerType Type.getInt16PtrTy();
@Native @Static PointerType Type.getInt32PtrTy();
@Native @Static PointerType Type.getInt64PtrTy();

@Native IRBuilder IRBuilder.new(BasicBlock bb);
@Native ReturnInst IRBuilder.createRetVoid();
@Native ReturnInst IRBuilder.createRet(Value v);
@Native ReturnInst IRBuilder.createAggregateRet(Value retVals, int n);
@Native BranchInst IRBuilder.createBr(BasicBlock dest);
@Native BranchInst IRBuilder.createCondBr(Value cond, BasicBlock trueBB, BasicBlock falseBB);
@Native SwitchInst IRBuilder.createSwitch(Value v, BasicBlock dest);
@Native IndirectBrInst IRBuilder.createIndirectBr(Value addr);
@Native InvokeInst IRBuilder.createInvoke0(Value callee, BasicBlock normalDest, BasicBlock unwindDest);
@Native InvokeInst IRBuilder.createInvoke1(Value callee, BasicBlock normalDest, BasicBlock unwindDest, Value arg1);
@Native InvokeInst IRBuilder.createInvoke3(Value callee, BasicBlock normalDest, BasicBlock unwindDest, Value arg1, Value arg2, Value arg3);
@Native InvokeInst IRBuilder.createInvoke(Value callee, BasicBlock normalDest, BasicBlock unwindDest, Array<Value> args);
//@Native ResumeInst IRBuilder.createResume(Value exn);
@Native UnreachableInst IRBuilder.createUnreachable();
@Native Value IRBuilder.createAdd(Value lhs, Value rhs);
@Native Value IRBuilder.createNSWAdd(Value lhs, Value rhs);
@Native Value IRBuilder.createNUWAdd(Value lhs, Value rhs);
@Native Value IRBuilder.createFAdd(Value lhs, Value rhs);
@Native Value IRBuilder.createSub(Value lhs, Value rhs);
@Native Value IRBuilder.createNSWSub(Value lhs, Value rhs);
@Native Value IRBuilder.createNUWSub(Value lhs, Value rhs);
@Native Value IRBuilder.createFSub(Value lhs, Value rhs);
@Native Value IRBuilder.createMul(Value lhs, Value rhs);
@Native Value IRBuilder.createNSWMul(Value lhs, Value rhs);
@Native Value IRBuilder.createNUWMul(Value lhs, Value rhs);
@Native Value IRBuilder.createFMul(Value lhs, Value rhs);
@Native Value IRBuilder.createUDiv(Value lhs, Value rhs);
@Native Value IRBuilder.createExactUDiv(Value lhs, Value rhs);
@Native Value IRBuilder.createSDiv(Value lhs, Value rhs);
@Native Value IRBuilder.createExactSDiv(Value lhs, Value rhs);
@Native Value IRBuilder.createFDiv(Value lhs, Value rhs);
@Native Value IRBuilder.createURem(Value lhs, Value rhs);
@Native Value IRBuilder.createSRem(Value lhs, Value rhs);
@Native Value IRBuilder.createFRem(Value lhs, Value rhs);
@Native Value IRBuilder.createShl(Value lhs, Value rhs);
@Native Value IRBuilder.createLShr(Value lhs, Value rhs);
@Native Value IRBuilder.createAShr(Value lhs, Value rhs);
@Native Value IRBuilder.createAnd(Value lhs, Value rhs);
@Native Value IRBuilder.createOr(Value lhs, Value rhs);
@Native Value IRBuilder.createXor(Value lhs, Value rhs);
@Native Value IRBuilder.createNeg(Value v);
@Native Value IRBuilder.createNSWNeg(Value v);
@Native Value IRBuilder.createNUWNeg(Value v);
@Native Value IRBuilder.createFNeg(Value v);
@Native Value IRBuilder.createNot(Value v);
@Native AllocaInst IRBuilder.createAlloca(Type ty, Value arraySize);
@Native LoadInst IRBuilder.createLoad(Value ptr, boolean isVolatile);
@Native StoreInst IRBuilder.createStore(Value val, Value ptr, boolean isVolatile);
//@Native FenceInst IRBuilder.createFence(AtomicOrdering ordering, SynchronizationScope SynchScope);
//@Native AtomicCmpXchgInst IRBuilder.createAtomicCmpXchg(Value ptr, Value Cmp, Value New, AtomicOrdering ordering, SynchronizationScope SynchScope);
@Native Value IRBuilder.createGEP(Value ptr, Array<Value> idxList);
@Native Value IRBuilder.createInBoundsGEP(Value ptr, Array<Value> idxList);
@Native Value IRBuilder.createGEP1(Value ptr, Value idx);
@Native Value IRBuilder.createInBoundsGEP1(Value ptr, Value idx);
@Native Value IRBuilder.createConstGEP1_32(Value ptr, int idx0);
@Native Value IRBuilder.createConstInBoundsGEP1_32(Value ptr, int idx0);
@Native Value IRBuilder.createConstGEP2_32(Value ptr, int idx0, int idx1);
@Native Value IRBuilder.createConstInBoundsGEP2_32(Value ptr, int idx0, int idx1);
@Native Value IRBuilder.createConstGEP1_64(Value ptr, int idx0);
@Native Value IRBuilder.createConstInBoundsGEP1_64(Value ptr, int idx0);
@Native Value IRBuilder.createConstGEP2_64(Value ptr, int idx0, int idx1);
@Native Value IRBuilder.createConstInBoundsGEP2_64(Value ptr, int idx0, int idx1);
@Native Value IRBuilder.createStructGEP(Value ptr, int idx);
@Native Value IRBuilder.createGlobalString(String str);
@Native Value IRBuilder.createGlobalStringPtr(String str);
@Native Value IRBuilder.createTrunc(Value v, Type destTy);
@Native Value IRBuilder.createZExt(Value v, Type destTy);
@Native Value IRBuilder.createSExt(Value v, Type destTy);
@Native Value IRBuilder.createFPToUI(Value v, Type destTy);
@Native Value IRBuilder.createFPToSI(Value v, Type destTy);
@Native Value IRBuilder.createUIToFP(Value v, Type destTy);
@Native Value IRBuilder.createSIToFP(Value v, Type destTy);
@Native Value IRBuilder.createFPTrunc(Value v, Type destTy);
@Native Value IRBuilder.createFPExt(Value v, Type destTy);
@Native Value IRBuilder.createPtrToInt(Value v, Type destTy);
@Native Value IRBuilder.createIntToPtr(Value v, Type destTy);
@Native Value IRBuilder.createBitCast(Value v, Type destTy);
@Native Value IRBuilder.createZExtOrBitCast(Value v, Type destTy);
@Native Value IRBuilder.createSExtOrBitCast(Value v, Type destTy);
@Native Value IRBuilder.createTruncOrBitCast(Value v, Type destTy);
@Native Value IRBuilder.createPointerCast(Value v, Type destTy);
@Native Value IRBuilder.createIntCast(Value v, Type destTy, boolean isSigned);
@Native Value IRBuilder.createFPCast(Value v, Type destTy);
@Native Value IRBuilder.createICmpEQ(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpNE(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpUGT(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpUGE(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpULT(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpULE(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpSGT(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpSGE(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpSLT(Value lhs, Value rhs);
@Native Value IRBuilder.createICmpSLE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpOEQ(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpOGT(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpOGE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpOLT(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpOLE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpONE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpORD(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpUNO(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpUEQ(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpUGT(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpUGE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpULT(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpULE(Value lhs, Value rhs);
@Native Value IRBuilder.createFCmpUNE(Value lhs, Value rhs);
@Native PHINode IRBuilder.createPHI(Type ty, int numReservedValues);
@Native CallInst IRBuilder.createCall1(Value callee, Value arg);
@Native CallInst IRBuilder.createCall2(Value callee, Value arg1, Value arg2);
@Native CallInst IRBuilder.createCall3(Value callee, Value arg1, Value arg2, Value arg3);
@Native CallInst IRBuilder.createCall4(Value callee, Value arg1, Value arg2, Value arg3, Value arg4);
@Native CallInst IRBuilder.createCall5(Value callee, Value arg1, Value arg2, Value arg3, Value arg4, Value arg5);
@Native CallInst IRBuilder.createCall(Value callee, Array<Value> args);
@Native Value IRBuilder.createSelect(Value c, Value trueV, Value falseV);
@Native VAArgInst IRBuilder.createVAArg(Value list, Type ty);
@Native Value IRBuilder.createExtractElement(Value vec, Value idx);
@Native Value IRBuilder.createInsertElement(Value vec, Value newElt, Value idx);
@Native Value IRBuilder.createShuffleVector(Value v1, Value v2, Value mask);
//@Native Value IRBuilder.createExtractValue(Value Agg, Array<int> Idxs);
//@Native Value IRBuilder.createInsertValue(Value Agg, Value val, Array<int> Idxs);
@Native Value IRBuilder.createIsNull(Value arg);
@Native Value IRBuilder.createIsNotNull(Value arg);
@Native Value IRBuilder.createPtrDiff(Value lhs, Value rhs);

@Native void IRBuilder.setInsertPoint(BasicBlock bb);
@Native Function BasicBlock.getParent();
@Native Instruction BasicBlock.getTerminator();
@Native void Function.dump();
@Native void Value.dump();
@Native void Type.dump();
@Native @Static Function Function.create(String name, FunctionType fnTy, Module m);
//@Native iterator BasicBlock.begin();
//@Native iterator BasicBlock.end();
@Native int BasicBlock.size();
@Native boolean BasicBlock.empty();
@Native Module Module.new(String name);
@Native void Module.addTypeName(String name, Type type);
@Native void Module.dump();
@Native Function Module.getOrInsertFunction(String name, FunctionType fnTy);
@Native ExecutionEngine Module.createExecutionEngine();
@Native @Static BasicBlock BasicBlock.create(Function parent);
@Native @Static FunctionType FunctionType.get(Type retTy, Array<Type> args, boolean b);
@Native @Static StructType StructType.get(Array<Type> args, boolean isPacked);
@Native NativeFunction ExecutionEngine.getPointerToFunction(Module m, Function func);

@Native Value Value.setName(String name);
@Native Type Value.getType();
@Native Array<Value> Function.getArguments();

@Native @Public void Method.setFunction(NativeFunction nf);
@Native @Public void Func.setFunction(NativeFunction nf);

class ConstantInt;
class ConstantFP;
@Native Value ConstantInt.get(Type type, int v);
@Native Value ConstantFP.get(Type type, float v);

@RawPtr class DynamicLibrary;
@Native @Static boolean DynamicLibrary.loadLibraryPermanently(String libname);
@Native @Static Int DynamicLibrary.searchForAddressOfSymbol(String fname);

