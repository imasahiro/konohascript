/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
 *           (c) 2011 Shunsuke Shida
 *           (c) 2011 Konoha Team konohaken@googlegroups.com
 *
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

using konoha.math.*;
using konoha.llvm.*;

DEBUG = false;
K_MTDIDX2 = -1;
K_RTNIDX = -4;
K_CALLDELTA = 4;
FUNC_STATIC = 0;
FUNC_VIRTUAL = 1;
FUNC_VIRTUAL2 = 1;
FUNC_FASTCALL = 2;

FLAG_OBJECT_NULLOBJECT = 1 << 1;
KFLAG_PF_BOL       = (1<<1);
KFLAG_PF_TIME      = (1<<2);
KFLAG_PF_NAME      = (1<<3);
KFLAG_PF_EOL       = (1<<4);
KFLAG_PF_NCOMMA    = (1<<5);
KFLAG_PF_LINE      = (1<<6);
KFLAG_PF_BREAK     = (1<<7);


LLVM_ENABLE_SAFEPOINT = true;
LLVM_ENABLE_OPT = true;
LLVM_ENABLE_FUNCTION_DUMP = false;
LLVM_ENABLE_MODULE_DUMP = false;
LLVM_ENABLE_DEBUG = false;
LLVM_ENABLE_OPT_INTRINSIC_METHOD = true;

//class CompilerOpt {
//    Module m;
//    ExecutionEngine     ee;
//    IRBuilder           builder;
//    Function            wrapperfunc;
//    Function            func;
//    FunctionPassManager fpm;
//    Map<String, Type>         ktype;
//    Map<String, FunctionType> kfunctype;
//    Map<String, Function>     intrinsic_methods;
//    FunctionType funcTy;
//    Type intTy;
//    Type floatTy;
//    Type boolTy;
//    Type objectTy;
//    Value     ctx;
//    Value     sfp;
//    Value     rix;
//    BasicBlock[] bblist;
//    BasicBlock[] bblist2;
//}

System.addClassField(CompilerOpt, Module,                    "m");
System.addClassField(CompilerOpt, ExecutionEngine,           "ee");
System.addClassField(CompilerOpt, IRBuilder,                 "builder");
System.addClassField(CompilerOpt, Function,                  "wrapperfunc");
System.addClassField(CompilerOpt, Function,                  "func");
System.addClassField(CompilerOpt, FunctionPassManager,       "fpm");
System.addClassField(CompilerOpt, Map<String, Type>,         "ktype");
System.addClassField(CompilerOpt, Map<String, FunctionType>, "kfunctype");
System.addClassField(CompilerOpt, Map<String, Function>,     "intrinsic_methods");
System.addClassField(CompilerOpt, FunctionType,              "funcTy");
System.addClassField(CompilerOpt, Type,                      "intTy");
System.addClassField(CompilerOpt, Type,                      "floatTy");
System.addClassField(CompilerOpt, Type,                      "boolTy");
System.addClassField(CompilerOpt, Type,                      "objectTy");
System.addClassField(CompilerOpt, Value,                     "ctx");
System.addClassField(CompilerOpt, Value,                     "sfp");
System.addClassField(CompilerOpt, Value,                     "rix");
System.addClassField(CompilerOpt, BasicBlock[],              "bblist");
System.addClassField(CompilerOpt, BasicBlock[],              "bblist2");

@Public Type Compiler.convertType(Class type) {
    if (type == Int) {
        return opt.intTy;
    }
    if (type == Float) {
        return opt.floatTy;
    }
    if (type == Boolean) {
        return opt.boolTy;
    }
    return opt.objectTy;
}
@Public Value K_Inst.getLLVMValue (Compiler asm) {
    if (value == null) {
        value = new Argument(asm.convertType(type));
        return value;
    } else {
        return value;
    }
}
@Public void K_Inst.setLLVMValue (Compiler asm, Value value) {
    if (this.value == null) {
        this.value = value;
    } else {
        this.value.replaceAllUsesWith (value);
        this.value = value;
    }
}


@Public void Compiler.register_user_class(Class c, String cname)
{
    Class[] class_fields = c.getFieldClasses();
    Type[] fields = [];

    if (cname.startsWith("konoha.") || "Script" in? cname) {
        return;
    }
    StructType klassTy = StructType.create(null, cname);/*create no-body StructType*/
    Type objectPtrTy = PointerType.get(klassTy);
    this.user_type[cname] = objectPtrTy;

    foreach (Class klass in class_fields) {
        String kname = (to String) klass;
        if (klass == Int) {
            fields.add(this.opt.intTy);
        }
        else if (klass == Float) {
            fields.add(this.opt.floatTy);
        }
        else if (klass == Boolean) {
            fields.add(this.opt.boolTy);
        }
        else if (klass == String) {
            fields.add(this.opt.ktype["stringPtrTy"]);
        }
        else if (kname.startsWith("konoha.Array")) {
            fields.add(this.opt.ktype["arrayPtrTy"]);
        }
        else if (kname in? user_type) {
            fields.add(user_type[kname]);
        }
        else {
            fields.add(this.opt.ktype["objectPtrTy"]);
        }
    }

    //print fields.size, cname;
    Type klassFieldTy = StructType.create(fields, cname+"_field", false);
    Type fieldPtrTy   = PointerType.get(klassFieldTy);
    fields = [opt.ktype["hobjectTy"], fieldPtrTy];
    assert(klassTy.isOpaque() == true);
    klassTy.setBody(fields, false);
}

@Public void Compiler.constructKonohaTypes();
@Public Compiler Compiler.new() {
    opt = new CompilerOpt();
    opt.ktype = {};
    opt.kfunctype = {};
    init_first();
    this.opt.m = new Module("konoha");
    this.opt.ee = opt.m.createExecutionEngine();
    this.opt.fpm = null;
    constructKonohaTypes();
    this.opt.intTy    = Type.getInt64Ty();
    this.opt.boolTy   = Type.getInt1Ty();
    this.opt.floatTy  = Type.getDoubleTy();
    this.opt.objectTy = opt.ktype["objectPtrTy"];
}

@Public void Compiler.shiftesp(int shift) {
    if (shift > 0) {
        Value vesp = opt.builder.createStructGEP(opt.ctx, 9);
        Value vsfp = opt.builder.createConstGEP1_32(opt.sfp, shift);
        opt.builder.createStore(vsfp, vesp);
    }
}
@Public void Compiler.initFunc(K_Function func) {
    Value[] wvargs = this.opt.wrapperfunc.getArguments();
    Type[] innerArgsTy = [wvargs[0].getType(), wvargs[1].getType(), wvargs[2].getType()];

    foreach(K_ARGUMENT inst in func.funcargs) {
        innerArgsTy.add(this.convertType(inst.type));
    }
    Type innerRetTy = null;
    if (this.retclass != null) {
        innerRetTy = this.convertType(this.retclass);
    } else {
        innerRetTy = Type.getVoidTy();
    }
    FunctionType funcTy = FunctionType.get(innerRetTy, innerArgsTy, false);
    String funcname = this.mtd.toString() + "_inner";
    func.func = Function.create(funcname, funcTy, this.opt.m, GlobalValue.InternalLinkage);
    this.opt.func = func.func;
}
@Public void Compiler.init(Method mtd) {
    common_init(mtd);
    opt.wrapperfunc = Function.create(mtd.toString(), opt.funcTy, opt.m, GlobalValue.ExternalLinkage);
    Array<Value> vargs = opt.wrapperfunc.getArguments();
    opt.ctx = vargs[0];
    opt.sfp = vargs[1];
    opt.rix = vargs[2];
    opt.bblist  = [];
    opt.bblist2 = [];
}
@Public Function Compiler.createAbs() {
    Type arg0Ty = opt.floatTy;
    Type retTy  = opt.floatTy;
    FunctionType fnTy = FunctionType.get(retTy, [arg0Ty], false);
    Function func = Function.create("compiler.fabs", fnTy, opt.m,
            GlobalValue.InternalLinkage);
    BasicBlock bb = BasicBlock.create(func, "EntryBlock");
    IRBuilder builder = new IRBuilder(bb);
    Array<Value> vargs = func.getArguments();
    Value arg0 = vargs[0];
    arg0.setName("a");
    Value v    = builder.createFCmpOGE(arg0, ConstantFP.get(opt.floatTy, 0.0));
    Value v0   = builder.createFNeg(arg0);
    Value ret  = builder.createSelect(v, arg0, v0);
    builder.createRet(ret);
    return func;
}

@Public void Compiler.emit(Method mtd) {
    if (opt.fpm == null) {
        FunctionPassManager fpm = new FunctionPassManager(opt.m);
        opt.fpm = fpm;
        //fpm.add(ee.getTargetData());
        fpm.add(LLVM.createVerifierPass());
        fpm.add(LLVM.createTypeBasedAliasAnalysisPass());
        fpm.add(LLVM.createBasicAliasAnalysisPass());
        fpm.add(LLVM.createSimplifyLibCallsPass());
        fpm.add(LLVM.createCFGSimplificationPass());
        fpm.add(LLVM.createScalarReplAggregatesPass());
        fpm.add(LLVM.createEarlyCSEPass());
        fpm.add(LLVM.createLowerExpectIntrinsicPass());
    }
    if (LLVM_ENABLE_OPT_INTRINSIC_METHOD) {
        if (this.opt.intrinsic_methods == null) {
            this.opt.intrinsic_methods = {};
            Type[] args = [opt.floatTy];
            String[] intrinsic_name = [
                "konoha.math.Math.sqrt",
                "konoha.math.Math.exp",
                "konoha.math.Math.log10",
                "konoha.math.Math.log",
                "konoha.math.Math.sin",
                "konoha.math.Math.cos"];
            Int[] intrinsic_id = [
                Intrinsic.Sqrt,
                Intrinsic.Exp,
                Intrinsic.Log10,
                Intrinsic.Log,
                Intrinsic.Sin,
                Intrinsic.Cos];
            for (int i=0; i < intrinsic_id.size; i++) {
                Function f = Intrinsic.getDeclaration(this.opt.m, intrinsic_id[i], args);
                opt.intrinsic_methods[intrinsic_name[i]] = f;
            }
            Int    id2  = Intrinsic.Pow;
            String name = "konoha.math.Math.pow";
            Function f = Intrinsic.getDeclaration(this.opt.m, id2, args);
            this.opt.intrinsic_methods[name] = f;
            this.opt.intrinsic_methods["konoha.math.Math.fabs"] = createAbs();
        }
    }
    for (int i = 0; i < kfunc.const_table.size; i++) {
        this.addConstTable(kfunc.const_table[i]);
    }
    if (!kfunc.curBB.hasReturn && kfunc.retTy == null) {
        K_Ret inst = new K_Ret(new K_Retop(null));
        kfunc.curBB.insts.add(inst);
        kfunc.curBB.hasReturn = true;
    }
    if (!kfunc.isUndeveloped()) {
        kfunc.codegen(this);
        FunctionPassManager fpm = opt.fpm;
        fpm.doInitialization();
        fpm.run(opt.wrapperfunc);
        fpm.run(opt.func);
        if (mtd.getName() == "") {
        }
        else if (mtd.toString().endsWith("Script.main")) {
            //print this.const_table;
            this.compiled_methods = {};
            PassManager mpm = new PassManager();
            mpm.add(LLVM.createFunctionAttrsPass());
            mpm.add(LLVM.createInternalizePass(true));
            //TODO FIXME BUG
            //mpm.add(LLVM.createFunctionInliningPass());
            mpm.add(LLVM.createIPSCCPPass());
            mpm.add(LLVM.createGlobalOptimizerPass());
            mpm.add(LLVM.createConstantMergePass());
            mpm.add(LLVM.createInstructionCombiningPass());
            mpm.add(LLVM.createGlobalOptimizerPass());
            mpm.add(LLVM.createGlobalDCEPass());
            mpm.add(LLVM.createInstructionCombiningPass());
            mpm.add(LLVM.createJumpThreadingPass());
            mpm.add(LLVM.createScalarReplAggregatesPass());
            mpm.add(LLVM.createFunctionAttrsPass());
            mpm.add(LLVM.createGlobalsModRefPass());
            mpm.add(LLVM.createLICMPass());
            mpm.add(LLVM.createGVNPass());
            mpm.add(LLVM.createMemCpyOptPass());
            mpm.add(LLVM.createDeadStoreEliminationPass());
            mpm.add(LLVM.createInstructionCombiningPass());
            mpm.add(LLVM.createJumpThreadingPass());
            mpm.add(LLVM.createCFGSimplificationPass());
            mpm.add(LLVM.createGlobalDCEPass());
            mpm.run(opt.m);
            if (DEBUG) {
                opt.m.dump();
            }
        }
        mtd.setFunction(opt.ee.getPointerToFunction(opt.wrapperfunc));
    }
}

@Public void Compiler.constructKonohaTypes() {
    Type int32Ty = Type.getInt32Ty();
    Type int64Ty = Type.getInt64Ty();
    Type int8PtrTy = Type.getInt8PtrTy();
    Type voidPtrTy = Type.getInt8PtrTy();
    Type longTy  = int64Ty;
    Type shortTy = Type.getInt16Ty();
    Type intTy   = int64Ty;
    Type sizeTy  = int64Ty;
    Type floatTy = Type.getDoubleTy();

    Type classTBLPtrTy = Type.getInt8PtrTy();
    Type typeMapPtrTy  = Type.getInt8PtrTy();

    Type[] fields = [];
    Type[] exfields = [];
    fields.add(int32Ty);
    fields.add(int32Ty);
    Type hcacheTy = StructType.create(fields, "knh_hcache_t", false);

    fields = [];
    fields.add(int64Ty);
    fields.add(int64Ty);
    Type sfxTy = StructType.create(fields, "knh_sfx_t", false);

    fields = [];
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    Type hObjectTy = StructType.create(fields, "hObject", false);
    opt.ktype["hobjectTy"] = hObjectTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type objectTy = StructType.create(fields, "Object", false);
    Type objectPtrTy = PointerType.get(objectTy);
    Type objectPtrPtrTy = PointerType.get(objectPtrTy);
    opt.ktype["objectPtrTy"] = objectPtrTy;
    opt.ktype["objectPtrPtrTy"] = objectPtrPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type arrayTy = StructType.create(fields, "Array", false);
    Type arrayPtrTy = PointerType.get(arrayTy);
    opt.ktype["arrayPtrTy"] = arrayPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(Type.getInt1PtrTy()); /* text */
    fields.add(int64Ty);   /* len */
    Type stringTy = StructType.create(fields, "String", false);
    Type stringPtrTy = PointerType.get(stringTy);
    opt.ktype["stringPtrTy"] = stringPtrTy;


    fields = [];
    fields.add(hObjectTy);
    fields.add(objectPtrPtrTy);
    fields.add(objectPtrTy);
    Type objectFieldTy    = StructType.create(fields, "ObjectField", false);
    Type objectFieldPtrTy = PointerType.get(objectFieldTy);
    opt.ktype["objectFieldTy"] = objectFieldTy;
    opt.ktype["objectFieldPtrTy"] = PointerType.get(objectFieldTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type outputStreamTy = StructType.create(fields, "OutputStream", false);
    Type outputStreamPtrTy = PointerType.get(outputStreamTy);
    opt.ktype["outputStreamPtrTy"] = outputStreamPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type inputStreamTy = StructType.create(fields, "InputStream", false);
    Type inputStreamPtrTy = PointerType.get(inputStreamTy);
    opt.ktype["inputStreamPtrTy"] = inputStreamPtrTy;

    fields = [];
    fields.add(objectPtrTy);
    fields.add(Type.getInt64Ty());
    Type sfpTy = StructType.create(fields, "sfp", false);
    Type sfpPtrTy = PointerType.get(sfpTy);
    opt.ktype["sfpPtrTy"] = sfpPtrTy;

    fields = [];
    fields.add(int64Ty);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(inputStreamPtrTy);
    fields.add(outputStreamPtrTy);
    fields.add(outputStreamPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(arrayPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type sysExTy = StructType.create(fields, "sysEx", false);

    fields = [];
    fields.add(hObjectTy);
    fields.add(sysExTy);
    Type sysTy = StructType.create(fields, "System", false);
    Type sysPtrTy = PointerType.get(sysTy);
    opt.ktype["sysPtrTy"] = sysPtrTy;

    fields = [];
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(sysPtrTy);
    fields.add(int8PtrTy);
    fields.add(sfpPtrTy);
    fields.add(sfpPtrTy);
    fields.add(int64Ty);
    fields.add(sfpPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(objectPtrTy);
    fields.add(objectPtrTy);
    fields.add(int64Ty);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(objectPtrPtrTy);
    fields.add(int64Ty);
    fields.add(objectPtrPtrTy);
    fields.add(int64Ty);
    fields.add(objectPtrPtrTy);
    fields.add(int64Ty);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(inputStreamPtrTy);
    fields.add(outputStreamPtrTy);
    fields.add(outputStreamPtrTy);
    fields.add(int8PtrTy);
    fields.add(outputStreamPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(Type.getInt32Ty);
    fields.add(Type.getInt32Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type[] vec16_fields = [];
    for (int i=0; i < 16; i++) {
        vec16_fields.add(Type.getInt1Ty());
    }
    fields.add(StructType.get(vec16_fields, false));
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(objectPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);

    Type ctxTy = StructType.create(fields, "ctx", false);
    Type ctxPtrTy = PointerType.get(ctxTy);
    opt.ktype["ctxTy"] = ctxPtrTy;

    Type[] argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type fmethodPtrTy = PointerType.get(fmethodTy);
    opt.kfunctype["fmethodTy"] = fmethodTy;
    opt.ktype["fmethodPtrTy"]  = fmethodPtrTy;
    opt.funcTy = fmethodTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType trmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type trmethodPtrTy = PointerType.get(trmethodTy);
    opt.kfunctype["trmethodTy"] = trmethodTy;
    opt.ktype["trmethodPtrTy"]  = trmethodPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int8PtrTy);
    argsTy.add(int64Ty);
    FunctionType safeptmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type safeptmethodPtrTy = PointerType.get(safeptmethodTy);
    opt.kfunctype["safeptmethodTy"]    = safeptmethodTy;
    opt.ktype["safeptmethodPtrTy"] = safeptmethodPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fitrnextTy = FunctionType.get(Type.getInt64Ty(), argsTy, false);
    Type fitrnextPtrTy = PointerType.get(fitrnextTy);
    opt.kfunctype["fitrnextTy"] = fitrnextTy;
    opt.ktype["fitrnextPtrTy"]  = fitrnextPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType typemapmtdTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type typemapmtdPtrTy = PointerType.get(typemapmtdTy);
    opt.kfunctype["typemapmtdTy"] = typemapmtdTy;
    opt.ktype["typemapmtdPtrTy"]  = typemapmtdPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType fTRTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type fTRPtrTy = PointerType.get(fTRTy);
    opt.kfunctype["fTRTy"] = fTRTy;
    opt.ktype["fTRPtrTy"]  = fTRPtrTy;

    fields = [];
    fields.add(int8PtrTy); /* codeaddr */
    fields.add(int64Ty);   /* count */
    fields.add(Type.getInt16Ty());   /* opcode */
    fields.add(Type.getInt16Ty());   /* line */
    fields.add(int64Ty);   /* data[0] */
    fields.add(int64Ty);   /* data[1] */
    fields.add(int64Ty);   /* data[2] */
    fields.add(int64Ty);   /* data[3] */
    fields.add(int64Ty);   /* data[4] */
    fields.add(int64Ty);   /* data[5] */
    fields.add(int64Ty);   /* data[6] */
    fields.add(int64Ty);   /* data[7] */
    Type oplineTy = StructType.create(fields, "opline", false);
    Type oplinePtrTy = PointerType.get(oplineTy);
    opt.ktype["oplineTy"] = oplineTy;
    opt.ktype["oplinePtrTy"] = oplinePtrTy;
    opt.ktype["oplinePtrPtrTy"] = PointerType.get(oplinePtrTy);

    fields = [];
    fields.add(hObjectTy);
    exfields = [];
    exfields.add(int32Ty);
    exfields.add(int32Ty);
    exfields.add(int8PtrTy);
    exfields.add(int8PtrTy);
    exfields.add(int8PtrTy);
    exfields.add(int8PtrTy);
    exfields.add(int8PtrTy);
    exfields.add(int32Ty);
    exfields.add(int32Ty);
    exfields.add(int64Ty);
    Type methodExTy = StructType.create(exfields, "MethodEx", false);
    fields.add(methodExTy);
    fields.add(Type.getInt32Ty);
    fields.add(Type.getInt32Ty);
    fields.add(fmethodPtrTy);
    fields.add(oplinePtrTy);
    Type methodTy = StructType.create(fields, "Method", false);
    Type methodPtrTy = PointerType.get(methodTy);
    opt.ktype["methodPtrTy"] = methodPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(fitrnextPtrTy);
    Type iteratorTy = StructType.create(fields, "Iterator", false);
    opt.ktype["IteratorPtrTy"] = PointerType.get(iteratorTy);

    /* THCODE */
    fields = [];
    fields.add(voidPtrTy); /* codeaddr */
    fields.add(sizeTy);   /* count */
    fields.add(shortTy);   /* opcode */
    fields.add(shortTy);   /* line */
    fields.add(voidPtrTy); /* th */
    fields.add(longTy); /* uri */
    Type type = StructType.create(fields, "THCODE_t", false);
    opt.ktype["THCODE"] = PointerType.get(type);

    /* PROBE */
    fields = [];
    fields.add(voidPtrTy); /* codeaddr */
    fields.add(sizeTy);   /* count */
    fields.add(shortTy);   /* opcode */
    fields.add(shortTy);   /* line */
    fields.add(longTy); /* sfpidx */
    fields.add(voidPtrTy); /* probe */
    fields.add(longTy); /* n */
    fields.add(longTy); /* n2 */
    type = StructType.create(fields, "PROBE_t", false);
    opt.ktype["PROBE"] = PointerType.get(type);

    /* RET */
    fields = [];
    fields.add(voidPtrTy); /* codeaddr */
    fields.add(sizeTy);   /* count */
    fields.add(shortTy);   /* opcode */
    fields.add(shortTy);   /* line */
    type = StructType.create(fields, "RET_t", false);
    opt.ktype["RET"] = PointerType.get(type);
}

@Public @Override void K_PHI.codegen(Compiler asm) {
    if (|bbs| == 1) {
        setLLVMValue(asm, insts[0].getLLVMValue(asm));
        return;
    } else {
        PHINode pn = asm.opt.builder.createPHI(asm.convertType(type), |bbs|);
        for (int i = 0; i < |bbs|; i++) {
            if (asm.opt.bblist2[bbs[i]] != null) {
                pn.addIncoming(insts[i].getLLVMValue(asm), asm.opt.bblist2[bbs[i]]);
            } else {
                pn.addIncoming(insts[i].getLLVMValue(asm), asm.opt.bblist[bbs[i]]);
            }
        }
        setLLVMValue(asm, pn);
    }
}

@Public void K_BasicBlock.codegen(Compiler asm) {
    int idx = this.bbidx;
    if (LLVM_ENABLE_SAFEPOINT) {
        Value vsafepoint = asm.opt.builder.createStructGEP(asm.opt.ctx, 0);
        vsafepoint = asm.opt.builder.createLoad(vsafepoint);
        BasicBlock bbThen = BasicBlock.create(asm.opt.func);
        Value cond = asm.opt.builder.createICmpEQ(vsafepoint, ConstantInt.get(asm.opt.intTy, 1));
        asm.opt.builder.createCondBr(cond, bbThen, asm.opt.bblist2[idx]);
        asm.opt.builder.setInsertPoint(bbThen);
        asm.shiftesp(this.safepoint);
        Type fType = asm.opt.ktype["safeptmethodPtrTy"];
        FunctionType fnTy  = asm.opt.kfunctype["safeptmethodTy"];
        Function fcheck_safepoint = asm.opt.m.getOrInsertFunction("knh_checkSafePoint", fnTy);
        Value vfunc = fcheck_safepoint;

        //safePointMtd = asm.createSafePointMtd();
        //vfunc = ConstantInt.get(asm.opt.intTy, asm.safePointMtd);
        //vfunc = asm.opt.builder.CreateIntToPtr(vfunc, fType);

        Value vctx  = asm.opt.ctx;
        Value vsfp  = asm.opt.builder.createConstGEP1_32(asm.opt.sfp, this.safepoint);
        Value vstr  = asm.opt.builder.createGlobalString("%d\n");
        vstr = asm.opt.builder.createBitCast(vstr, Type.getInt8PtrTy());
        Value vline = ConstantInt.get(asm.opt.intTy, 0);
        Value[] args = [vctx, vsfp, vstr, vline];
        asm.opt.builder.createCall(vfunc, args);
        asm.opt.builder.createBr(asm.opt.bblist2[idx]);
    }
    asm.opt.builder.setInsertPoint(asm.opt.bblist2[idx]);
}

@Public void K_Function.buildWrapperFunc(Compiler asm) {
    BasicBlock bb = BasicBlock.create(asm.opt.wrapperfunc, "EntryBlock");
    asm.opt.builder = new IRBuilder(bb);
    asm.opt.builder.setInsertPoint(bb);
    Array<Value> wvargs = asm.opt.wrapperfunc.getArguments();
    Value[] vargs = [wvargs[0], wvargs[1], wvargs[2]];
    foreach(K_ARGUMENT inst in funcargs) {
        inst.value = null;
        inst.codegen(asm);
        vargs.add(inst.getLLVMValue(asm));
    }
    Value res = asm.opt.builder.createCall(asm.opt.func, vargs);
    Type innerRetTy = null;
    if (asm.retclass != null) {
        innerRetTy = asm.convertType(asm.retclass);
        asm.opt.builder.createStoreValueToSfp(asm.opt.sfp, innerRetTy, K_RTNIDX, res);
    } else {
        innerRetTy = Type.getVoidTy();
    }
    asm.opt.builder.createRetVoid();
}

@Public void K_Function.codegen(Compiler asm) {
    Array<Value> args = asm.opt.func.getArguments();
    Value old_ctx = asm.opt.ctx;
    Value old_sfp = asm.opt.sfp;
    Value old_rix = asm.opt.rix;
    asm.opt.ctx = args[0];
    asm.opt.sfp = args[1];
    asm.opt.rix = args[2];

    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] != null) {
            asm.opt.bblist.add(BasicBlock.create(asm.opt.func, "bb"+i));
            if (bbs[i].safepoint != -1) {
                asm.opt.bblist2.add(BasicBlock.create(asm.opt.func, "bb"+i));
            } else {
                asm.opt.bblist2.add(null);
            }
        } else {
            asm.opt.bblist.add(null);
            asm.opt.bblist2.add(null);
        }
    }
    if (DEBUG) {
        OUT.println(dump());
    }
    asm.opt.builder = new IRBuilder(asm.opt.bblist[0]);
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null) continue;
        asm.opt.builder.setInsertPoint(asm.opt.bblist[i]);
        if (bbs[i].phis != null) {
            foreach (String s in bbs[i].phis.keys()) {
                bbs[i].phis[s].codegen(asm);
            }
        }
        if (bbs[i].safepoint != -1) {
            bbs[i].codegen(asm);
        }
        if (i == 0) {
            foreach (K_ARGUMENT inst in funcargs) {
                inst.codegen(asm);
            }
        }
        foreach (K_Inst inst in bbs[i].insts) {
            inst.codegen(asm);
        }
    }
    asm.opt.ctx = old_ctx;
    asm.opt.sfp = old_sfp;
    asm.opt.rix = old_rix;

    buildWrapperFunc(asm);
}

BuilderFunc=Func<Value, Value=>Value>;
@Public @Override void K_ADD.codegen(Compiler asm) {
    BuilderFunc f;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (type == Int) {
        f = delegate(asm.opt.builder, createAdd);
    }
    else if (type == Float) {
        f = delegate(asm.opt.builder, createFAdd);
    }
    else {
        throw new Exception();
    }
    setLLVMValue(asm, f(v0, v1));
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    BuilderFunc f;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (type == Int) {
        f = delegate(asm.opt.builder, createSub);
    }
    else if (type == Float) {
        f = delegate(asm.opt.builder, createFSub);
    }
    setLLVMValue(asm, f(v0, v1));
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (type == Int) {
        v = asm.opt.builder.createMul(v0, v1);
    }
    if (type == Float) {
        v = asm.opt.builder.createFMul(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (type == Int) {
        v = asm.opt.builder.createSDiv(v0, v1);
    }
    if (type == Float) {
        v = asm.opt.builder.createFDiv(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createSRem(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpEQ(v0, v1);
    } else if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpOEQ(v0, v1);
    } else if (op.inst1 == null) {
        v = asm.opt.builder.createStructGEP(v0, 0);
        v = asm.opt.builder.createStructGEP(v, 0);
        v = asm.opt.builder.createLoad(v);
        Value flag = ConstantInt.get(asm.opt.intTy, FLAG_OBJECT_NULLOBJECT);
        v = asm.opt.builder.createAnd(v, flag);
        v = asm.opt.builder.createICmpEQ(v, flag);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpNE(v0, v1);
    } else if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpONE(v0, v1);
    } else if (op.inst1 == null) {
        v = asm.opt.builder.createStructGEP(v0, 0);
        v = asm.opt.builder.createStructGEP(v, 0);
        v = asm.opt.builder.createLoad(v);
        Value flag = ConstantInt.get(asm.opt.intTy, FLAG_OBJECT_NULLOBJECT);
        v = asm.opt.builder.createAnd(v, flag);
        v = asm.opt.builder.createICmpEQ(v, flag);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_LT.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpSLT(v0, v1);
    }
    if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpOLT(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_GT.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpSGT(v0, v1);
    }
    if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpOGT(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpSLE(v0, v1);
    }
    if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpOLE(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    Value v;
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    if (op.inst0.type == Int) {
        v = asm.opt.builder.createICmpSGE(v0, v1);
    }
    if (op.inst0.type == Float) {
        v = asm.opt.builder.createFCmpOGE(v0, v1);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_AND.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createAnd(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_OR.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createOr(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v = asm.opt.builder.createNot(v0);
    setLLVMValue(asm, v);
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createXor(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createSelect(v0, v1, op.inst2.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createShl(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    Value v1 = op.inst1.getLLVMValue(asm);
    Value v = asm.opt.builder.createLShr(v0, v1);
    setLLVMValue(asm, v);
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    Value v0 = op.inst0.getLLVMValue(asm);
    IRBuilder builder = asm.opt.builder;
    Type methodPtrTy = asm.opt.ktype["methodPtrTy"];

    Value func = ConstantInt.get(asm.opt.intTy, (method:Object.typeCheck).getPtr());
    func = builder.CreateIntToPtr(func, methodPtrTy);
    func = builder.createStructGEP(func, 4);
    func = builder.createLoad(func);
    Value thisidx = ConstantInt.get(asm.opt.intTy, op.espidx + K_CALLDELTA);
    Value sfp = builder.createGEP1(asm.opt.sfp, thisidx);
    Value vrix = ConstantInt.get(asm.opt.intTy, K_RTNIDX);
    Value[] vargs = [asm.opt.ctx, sfp, vrix];

    builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(op.inst0.type), op.espidx + K_CALLDELTA, v0);
    Value vclass = builder.CreateIntToPtr(ConstantInt.get(asm.opt.intTy, type.getPtr()), asm.opt.ktype["objectPtrTy"]);
    builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(Class), op.espidx + K_CALLDELTA+1, vclass);
    Value vmtd = builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(Method), K_MTDIDX2);
    builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(Method), op.espidx + K_CALLDELTA-1, vmtd);

    int espshift = op.espidx + K_CALLDELTA + 2;
    asm.shiftesp(espshift);
    builder.createCall(func, vargs);
    Value v = builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), op.espidx);
    setLLVMValue(asm, v);
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    CompilerOpt opt = asm.opt;
    IRBuilder builder = opt.builder;
    Type intTy = opt.intTy;
    print op.cast;
    if (op.cast == 0) {
        //v = builder.createBitCast(v, asm.convertType(type));
        if (type == Float) {
            v = builder.createSIToFP(v, opt.floatTy);
        } else if (type == Int) {
            v = builder.createFPToSI(v, intTy);
        }
        //v = builder.createLoadValueFromSfp(opt.sfp, asm.convertType(type), op.b+op.rix);
        setLLVMValue(asm, v);
    } else {
        //TODO need debug
        //Type[] a = [];
        //a.add(opt.ktype["sfpPtrTy"]);
        //FunctionType ty = FunctionType.get(intTy, a, false);
        //FUnction ftest = opt.m.getOrInsertFunction("__test__", ty);
        //builder.createCall1(ftest, vsfp);
        FunctionType fnTy = opt.kfunctype["typemapmtdTy"];
        Value typemap_exec = opt.m.getOrInsertFunction("knh_TypeMap_exec", fnTy);
        builder.createStoreValueToSfp(opt.sfp, asm.convertType(op.inst0.type), op.b, op.inst0.getLLVMValue(asm));
        asm.shiftesp(op.espshift);
        Value vsfp = builder.createInBoundsGEP1(opt.sfp, ConstantInt.get(intTy, op.b));
        Value vctx = opt.ctx;
        Value vtmr = ConstantInt.get(intTy, op.cast);
        Value vrix = ConstantInt.get(intTy, op.rix);

        builder.createCall4(typemap_exec, vctx, vtmr, vsfp, vrix);
        v = builder.createLoadValueFromSfp(opt.sfp, asm.convertType(type), op.b+op.rix);
        setLLVMValue(asm, v);
    }
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.opt.builder.createBr(asm.opt.bblist[op.jmpidx]);
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.opt.builder.createCondBr(op.inst0.getLLVMValue, asm.opt.bblist[op.bbThen], asm.opt.bblist[op.bbElse]);
}
@Public @Override void K_CALL.codegen(Compiler asm) {
    Value func;
    Value[] vargs;
    IRBuilder builder = asm.opt.builder;
    if (asm.compiled_methods[this.op.fname] != null) {
        Value thisidx = ConstantInt.get(asm.opt.intTy, op.thisidx);
        Value sfp = builder.createGEP1(asm.opt.sfp, thisidx);
        Value vrix = ConstantInt.get(asm.opt.intTy, op.rix);
        vargs = [asm.opt.ctx, sfp, vrix];
        for (int i = 0; i < args.size; i++) {
            vargs.add(args[i].getLLVMValue(asm));
        }
        asm.shiftesp(op.espshift);
        K_Function[] func_list = asm.compiled_methods[this.op.fname];
        boolean check_overload = true;
        K_Function cfunc = null;
        foreach (K_Function f in func_list) {
            K_ARGUMENT[] funcargs = f.funcargs;
            //print f.mtdName, this.op.fname;
            //print funcargs.size, args.size;
            if (funcargs.size == args.size) {
                for (int i=1; i < funcargs.size; i++) {
                    //print funcargs[i].type, args[i].type;
                    if (funcargs[i].type != args[i].type) {
                        check_overload = false;
                    }
                }
                if (check_overload) {
                    cfunc = f;
                    //print f.mtdName, cfunc.mtdName;
                    break;
                }
            }
        }
        if (check_overload) {
            func = cfunc.func;
            //print vargs.size, cfunc.mtdName;
            Value ret = builder.createCall(func, vargs);
            if (type != null/*void*/) {
                setLLVMValue(asm, ret);
            }
            return;
        } else {
            print "**WARN** compiled_methods call failed", this.op.fname;
        }
    }
    if (LLVM_ENABLE_OPT_INTRINSIC_METHOD) {
        if (asm.opt.intrinsic_methods[this.op.fname] != null) {
            Function func = asm.opt.intrinsic_methods[this.op.fname];
            vargs = [];
            for (int i = 0; i < |args|; i++) {
                vargs.add(args[i].getLLVMValue(asm));
            }
            Value ret = builder.createCall(func, vargs);
            if (type != null/*void*/) {
                setLLVMValue(asm, ret);
            }
            return;
        }
    }
    if (op.ftype != FUNC_FASTCALL) {
        func = ConstantInt.get(asm.opt.intTy, op.mtdNC);
        func = builder.createIntToPtr(func, asm.opt.ktype["methodPtrTy"]);
        func = builder.createStructGEP(func, 4);
        func = builder.createLoad(func);
        Value thisidx = ConstantInt.get(asm.opt.intTy, op.thisidx);
        Value sfp = builder.createGEP1(asm.opt.sfp, thisidx);
        Value vrix = ConstantInt.get(asm.opt.intTy, op.rix);
        vargs = [asm.opt.ctx, sfp, vrix];
        for (int i = 0; i < |args|; i++) {
            builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(args[i].type), op.thisidx + i + op.flagStatic, args[i].getLLVMValue(asm));
        }
    } else {
        Type methodTy = asm.opt.ktype["fmethodPtrTy"];
        func = ConstantInt.get(asm.opt.intTy, op.mtdNC);
        func = builder.CreateIntToPtr(func, methodTy);
        Value vb = ConstantInt.get(asm.opt.intTy, op.thisidx);
        vb = builder.createGEP1(asm.opt.sfp, vb);
        Value vrix = ConstantInt.get(asm.opt.intTy, op.rix);
        vargs = [asm.opt.ctx, vb, vrix];
    }
    builder.createStoreValueToSfp(asm.opt.sfp, asm.opt.intTy, op.thisidx-1, ConstantInt.get(asm.opt.intTy, op.mtdNC));
    asm.shiftesp(op.espshift);
    builder.createCall(func, vargs);
    if (type != null/*void*/) {
        Value v = builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), op.thisidx+op.rix);
        setLLVMValue(asm, v);
    }
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    if (op.inst0 != null) {
        builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(type), op.sfpidx, op.inst0.getLLVMValue(asm));
    }
    Type fmethodTy = asm.opt.ktype["fmethodPtrTy"];
    Value func = ConstantInt.get(asm.opt.intTy, op.fprint);
    func = builder.CreateIntToPtr(func, fmethodTy);
    Value vop = ConstantInt.get(asm.opt.intTy, op.opline);
    Value[] vargs = [asm.opt.ctx, asm.opt.sfp, vop];
    builder.createCall(func, vargs);
}
@Public @Override void K_TR.codegen(Compiler asm) {
    Type methodTy = asm.opt.ktype["trmethodPtrTy"];
    Value func;
    FunctionType fnTy = asm.opt.kfunctype["trmethodTy"];
    DynamicLibrary.loadLibraryPermanently("compiler.dylib");
    Module m = asm.opt.m;;
    if (op.ftr == Stmt.CWB) {
        func = m.getOrInsertFunction("compiler_CWB", fnTy);
    } else if (op.ftr == Stmt.TOSTR) {
        func = m.getOrInsertFunction("compiler_TOSTR", fnTy);
    } else if (op.ftr == Stmt.NULL) {
        func = m.getOrInsertFunction("compiler_NULVAL", fnTy);
    } else {
        func = ConstantInt.get(asm.opt.intTy, op.ftr);
        func = asm.opt.builder.CreateIntToPtr(func, methodTy);
    }
    Value vb = ConstantInt.get(asm.opt.intTy, op.espidx);
    vb = asm.opt.builder.createGEP1(asm.opt.sfp, vb);
    Value rix = ConstantInt.get(asm.opt.intTy, op.rix);
    Value cid = ConstantInt.get(asm.opt.intTy, op.cTBL);
    if (op.inst0 != null) {
        asm.opt.builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(op.inst0.type), op.espidx, op.inst0.getLLVMValue(asm));
    }
    asm.opt.builder.createCall4(func, asm.opt.ctx, vb, rix, cid);
    Value v = asm.opt.builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), op.espidx + op.rix);
    setLLVMValue(asm, v);
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    Type methodTy = asm.opt.ktype["trmethodPtrTy"];
    Value func;
    if (op.ftr == Stmt.NEW) {
        FunctionType fnTy = asm.opt.kfunctype["trmethodTy"];
        DynamicLibrary.loadLibraryPermanently("compiler.dylib");
        Function tr_new = asm.opt.m.getOrInsertFunction("TR_NEW", fnTy);
        func  = (Value) tr_new;
    } else {
        func = ConstantInt.get(asm.opt.intTy, op.ftr);
        func = asm.opt.builder.CreateIntToPtr(func, methodTy);
    }
    Value vb = ConstantInt.get(asm.opt.intTy, kvalue.idx);
    vb = asm.opt.builder.createGEP1(asm.opt.sfp, vb);
    Value rix = ConstantInt.get(asm.opt.intTy, op.rix);
    Value cid = ConstantInt.get(asm.opt.intTy, op.cTBL);
    asm.opt.builder.createCall4(func, asm.opt.ctx, vb, rix, cid);
    Value v = asm.opt.builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), kvalue.idx + op.rix);
    setLLVMValue(asm, v);
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    v = builder.createBitCast(v, asm.opt.ktype["arrayPtrTy"]);
    v = builder.createStructGEP(v, 1);
    v = builder.createLoad(v);
    v = builder.createBitCast(v, PointerType.get(asm.opt.intTy));
    v = builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    v = builder.createBitCast(v, asm.opt.ktype["objectPtrTy"]);
    v = builder.createStructGEP(v, 1);
    v = builder.createLoad(v);
    v = builder.createBitCast(v, PointerType.get(asm.opt.intTy));
    //v = builder.createBitCast(v, asm.opt.ktype["objectPtrPtrTy"]);
    v = builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = builder.createBitCast(v, PointerType.get(asm.convertType(op.inst2.type)));
    v = builder.createStore(op.inst2.getLLVMValue(asm), v);
    setLLVMValue(asm, op.inst2.getLLVMValue(asm));
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    Value v;
    if (type == Int) {
        v = ConstantInt.get(asm.opt.intTy, (int)op.const_table[op.table_idx]);
    } else if (type == Float) {
        v = ConstantFP.get(asm.opt.floatTy, (float)op.const_table[op.table_idx]);
    } else if (type == Boolean) {
        v = ConstantInt.get(asm.opt.boolTy, (op.const_table[op.table_idx] == true) ? 1 : 0);
    } else {
        ConstantInt c = ConstantInt.get(asm.opt.intTy, op.objptr);
        v = asm.opt.builder.CreateIntToPtr(c, asm.opt.ktype["objectPtrTy"]);
    }
    setLLVMValue(asm, v);
}
@Public @Override void K_MOVx.codegen (Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    v = builder.createBitCast(v, asm.opt.ktype["objectPtrTy"]);
    v = builder.createStructGEP(v, 1);
    v = builder.createLoad(v);
    v = builder.createBitCast(v, asm.opt.ktype["objectPtrPtrTy"]);
    Value vn = ConstantInt.get(asm.opt.intTy, op.bn);
    v = builder.createInBoundsGEP1(v, vn);
    v = builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Public @Override void K_xMOV.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    String cname = (to String) op.inst0.type;
    Type type = asm.user_type[cname];
    if (type == null) {
        asm.register_user_class(op.inst0.type, cname);
    }
    type = asm.user_type[cname];
    if (type != null) {
        v = builder.createBitCast(v, type);
        v = builder.createStructGEP(v, 1);
        v = builder.createLoad(v);
        v = builder.createStructGEP(v, op.an);
        v = builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
    }
    else {
        Value vn = ConstantInt.get(asm.opt.intTy, op.an);
        Type ptrTy = PointerType.get(asm.convertType(op.inst1.type));
        v = builder.createBitCast(v, asm.opt.ktype["objectFieldPtrTy"]);
        v = builder.createStructGEP(v, 1);
        v = builder.createLoad(v);
        v = builder.createInBoundsGEP1(v, vn);
        v = builder.createBitCast(v, ptrTy);
    }
    v = builder.createStore(op.inst1.getLLVMValue(asm), v);
    setLLVMValue(asm, v);
}

@Public @Override void K_NEXT.codegen(Compiler asm) {
    Value itr = op.inst0.getLLVMValue(asm);
    itr = asm.opt.builder.createBitCast(itr, asm.opt.ktype["IteratorPtrTy"]);
    Value fnext_1 = asm.opt.builder.createStructGEP(itr, 2);
    fnext_1 = asm.opt.builder.createLoad(fnext_1);
    Value vctx = asm.opt.ctx;
    Value vsfp = asm.opt.builder.createConstGEP1_32(asm.opt.sfp, op.b);
    Value vrix = ConstantInt.get(asm.opt.intTy, op.rix);
    asm.shiftesp(op.espshift);
    Value v = (Value)asm.opt.builder.createCall3(fnext_1, vctx, vsfp, vrix);
    Value res = asm.opt.builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), op.b + op.rix);
    setLLVMValue(asm, res);
    Value v = asm.opt.builder.createICmpEQ(v, ConstantInt.get(asm.opt.intTy, 0));
    asm.opt.builder.createCondBr(v, asm.opt.bblist[op.nextBB], asm.opt.bblist[op.endBB]);
}

@Public @Override void K_LDMTD.codegen(Compiler asm) {
    //Type fmethodTy = asm.opt.ktype["fmethodPtrTy"];
    //Value func = ConstantInt.get(asm.opt.intTy, op.ldmtd);
    //func = asm.opt.builder.CreateIntToPtr(func, fmethodTy);
    //Value vop = ConstantInt.get(asm.opt.intTy, op.opline);
    //asm.opt.builder.createCall3(func, asm.opt.ctx, asm.opt.sfp, vop);
    throw new Exception();
}

@Public @Override void K_ARGUMENT.codegen(Compiler asm) {
    Value v;
    if (!op.inner) {
        v = asm.opt.builder.createLoadValueFromSfp(asm.opt.sfp, asm.convertType(type), op.argidx);
    } else {
        Value[] vargs = asm.opt.func.getArguments();
        int difference = 2 + ((asm.mtd.isStatic() && !asm.mtd.toString().endsWith("new") && !asm.mtd.toString().endsWith("Script.")) ? 0 : 1);
        v = vargs[op.argidx+difference];
        v.setName("arg"+(op.argidx+difference));
        op.inner = false;
    }
    setLLVMValue(asm, v);
}

@Public @Override void K_Ret.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    if (asm.retclass != null && op.inst0 != null) {
        builder.createRet(op.inst0.getLLVMValue(asm));
    } else  {
        if (op.inst0 != null && asm.mtd.toString().endsWith("Script.")) {
            builder.createStoreValueToSfp(asm.opt.sfp, asm.convertType(Object), K_RTNIDX, op.inst0.getLLVMValue(asm));
        }
        builder.createRetVoid();
    }
}

