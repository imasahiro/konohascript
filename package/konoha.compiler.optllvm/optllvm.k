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
include "lib:gluelink";

K_MTDIDX2 = -1;
K_RTNIDX = -4;
K_CALLDELTA = 4;
FUNC_STATIC = 0;
FUNC_VIRTUAL = 1;
FUNC_VIRTUAL2 = 1;
FUNC_FASTCALL = 2;
FLAG_OBJECT_NULLOBJECT = 1 << 1;
K_SMALLOBJECT_FIELDSIZE = 3;

LLVM_ENABLE_SAFEPOINT = false;

class LLVMConfig {
    boolean debug;
    boolean verify_each;
    Boolean print_statics;
    boolean module_dump;
    boolean enable_opt;
    boolean method_inlining;
    boolean intrinsic_method;
    boolean load_library_module;
    boolean opt_safepoint;
    boolean opt_array_access;
    boolean opt_object_new;
    boolean opt_field_access;
    boolean opt_lazycompilation;
    boolean opt_remove_sfp;
    String dllext = "dylib";
    LLVMConfig() {
        boolean b = "true" == $env.LLVM_DEBUG;
        boolean p = "true" == $env.LLVM_ENABLE_PRINT_STATICS;
        boolean v = "true" == $env.LLVM_ENABLE_VERIFY_EACH;
        boolean d = "true" == $env.LLVM_ENABLE_MODULE_DUMP;
        boolean e = "true" == $env.LLVM_ENABLE_OPT;
        boolean m = "true" == $env.LLVM_ENABLE_OPT_METHOD_INLINING;
        boolean i = "true" == $env.LLVM_ENABLE_OPT_INTRINSIC_METHOD;
        boolean l = "true" == $env.LLVM_ENABLE_OPT_LOAD_LIBRARY_MODULE;
        boolean s = "true" == $env.LLVM_ENABLE_OPT_SAFEPOINT;
        boolean a = "true" == $env.LLVM_ENABLE_OPT_ARRAY_ACCESS;
        boolean o = "true" == $env.LLVM_ENABLE_OPT_OBJECT_NEW;
        boolean f = "true" == $env.LLVM_ENABLE_OPT_FIELD_ACCESS;
        boolean c = "true" == $env.LLVM_ENABLE_OPT_LAZY_COMPILATION;
        boolean r = "true" == $env.LLVM_ENABLE_OPT_REMOVE_SFP;
        this.debug               = b;
        this.print_statics       = p;
        this.verify_each         = v;
        this.module_dump         = d;
        this.enable_opt          = e;
        this.method_inlining     = e && m;
        this.intrinsic_method    = e && i;
        this.load_library_module = e && l;
        this.opt_safepoint       = !(LLVM_ENABLE_SAFEPOINT) && s;
        this.opt_array_access    = e && a;
        this.opt_object_new      = e && o;
        this.opt_field_access    = e && f;
        //FIXME if we enable config.opt_lazycompilation,
        //      lambda method with global variable decl will
        //      break because Constructor for global variable IS_Stmt
        //      not defined and Constructor is abstract methods.
        this.opt_lazycompilation  = e && c;
        this.opt_remove_sfp       = e && r;
        this.dllext = $env.LLVM_OS_ARCH;
        if (this.dllext == null) {
            this.dllext = "dylib";
        }
        String path = $konoha.package.path + "/konoha.compiler/compiler." + dllext;
        assert(DynamicLibrary.loadLibraryPermanently(path) == false);
        if (dllext == "so" || dllext == "dylib") {
            String libname = "libm." + dllext;
            assert(DynamicLibrary.loadLibraryPermanently(libname) == false);
        } else {
            throw new Exception("not support your architecture");
        }
        if (this.debug) {
            print this;
        }
    }
}

class LLVMStatics {
    int opt_method_inlining
    int opt_intrinsic_method;
    int opt_safepoint;
    int opt_array_access;
    int opt_object_new;
    int opt_field_access;
    int compile_time;
    int optimize_time;
}

LLVMConfig  config  = new LLVMConfig();
LLVMStatics statics = new LLVMStatics();

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
//    BasicBlock[] bblist;
//    BasicBlock[] bblist2;
//}

MapSF =Map<String, Function>;
MapSFT=Map<String, FunctionType>;
System.addClassField(CompilerOpt, Module,               "m");
System.addClassField(CompilerOpt, ExecutionEngine,      "ee");
System.addClassField(CompilerOpt, IRBuilder,            "builder");
System.addClassField(CompilerOpt, Function,             "wrapperfunc");
System.addClassField(CompilerOpt, Function,             "func");
System.addClassField(CompilerOpt, FunctionPassManager,  "fpm");
System.addClassField(CompilerOpt, Map<String, Type>,    "ktype");
System.addClassField(CompilerOpt, MapSFT,               "kfunctype");
System.addClassField(CompilerOpt, MapSF,                "intrinsic_methods");
System.addClassField(CompilerOpt, FunctionType,         "funcTy");
System.addClassField(CompilerOpt, Type,                 "intTy");
System.addClassField(CompilerOpt, Type,                 "floatTy");
System.addClassField(CompilerOpt, Type,                 "boolTy");
System.addClassField(CompilerOpt, Type,                 "objectTy");
System.addClassField(CompilerOpt, Value,                "ctx");
System.addClassField(CompilerOpt, Value,                "sfp");
System.addClassField(CompilerOpt, BasicBlock[],         "bblist");
System.addClassField(CompilerOpt, BasicBlock[],         "bblist2");
System.addClassField(CompilerOpt, GlobalVariable[],     "global_list");
System.addClassField(CompilerOpt, Int[],                "addr_list");
System.addClassField(CompilerOpt, K_Function[],         "compilation_queue");

@Public void CompilerOpt.reset(Value[] args, K_Function f) {
    this.func = f.func;
    this.wrapperfunc = f.wfunc;
    this.ctx = args[0];
    if (config.opt_remove_sfp) {
        this.sfp = null;
    } else {
        this.sfp = args[1];
    }
    this.bblist = [];
    this.bblist2 = [];
}

@public Value Compiler.getsfp() {
    Value vsfp = this.opt.sfp;
    if (vsfp == null) {
        if (config.opt_remove_sfp) {
            Value[] index = [];
            Type int32Ty = Type.getInt32Ty();
            index.add(ConstantInt.get(int32Ty, 0));
            index.add(ConstantInt.get(int32Ty, 9));
            GetElementPtrInst esp = GetElementPtrInst.create(opt.ctx, index);
            LoadInst li = new LoadInst(esp);
            vsfp = li;
            BasicBlock bb = this.opt.bblist[0];
            Instruction inst = bb.getLastInst();
            bb.insertBefore(inst, esp);
            bb.insertBefore(inst, li);
        } else {
            vsfp = opt.func.getArguments()[1];
        }
        this.opt.sfp = vsfp;
    }
    return vsfp;
}

@Public GlobalVariable CompilerOpt.get_or_create(Type type, int addr, String name) {
    GlobalVariable[] glist = this.global_list;
    Int[] alist = this.addr_list;
    if (glist == null) {
        glist = [];
        alist = [];
        this.global_list = glist;
        this.addr_list   = alist;
    }
    int index = alist.indexOf(addr);
    if (index >= 0) {
        return this.global_list[index];
    }
    GlobalVariable g = new GlobalVariable(this.m, type, null, GlobalValue.ExternalLinkage, name);
    this.ee.addGlobalMapping(g, addr);
    alist.add(addr);
    glist.add(g);
    return g;
}
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

@Public boolean Class.isSMALLOBJECT() {
    String cname = (to String) this;
    if (cname.startsWith("konoha.") || "Script" in? cname) {
        return false;
    }
    return (this.getFieldClasses().size <= K_SMALLOBJECT_FIELDSIZE);
}

@Public void Compiler.register_user_class(Class c, String cname) {
    Class[] class_fields = c.getFieldClasses();
    Type[] fields = [];

    if (cname.startsWith("konoha.") || "Script" in? cname) {
        return;
    }
    StructType klassTy = StructType.create(null, cname);
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
            fields.add(this.opt.intTy);
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
    Type[] obj_fields = [opt.ktype["hobjectTy"], fieldPtrTy];
    if (fields.size <= K_SMALLOBJECT_FIELDSIZE) {
        for (int i=0; i < fields.size; i++) {
            obj_fields.add(fields[i]);
        }
    }
    assert(klassTy.isOpaque() == true);
    klassTy.setBody(obj_fields, false);
}

@Public void Compiler.constructKonohaTypes();
@Public Compiler Compiler.new() {
    opt = new CompilerOpt();
    opt.ktype = {};
    opt.kfunctype = {};
    init_first();
    if (config.load_library_module) {
        String libkonoha = "/usr/local/konoha/lib/libkonoha." + config.dllext + ".bc";
        this.opt.m = LLVM.parseBitcodeFile(libkonoha);
    } else {
        this.opt.m = new Module("konoha");
    }
    this.opt.ee = opt.m.createExecutionEngine(2);
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
        Value vsfp = opt.builder.createConstGEP1_32(getsfp(), shift);
        opt.builder.createStore(vsfp, vesp);
    }
}
@Virtual @Public void Compiler.initFunc(K_Function func) {
    func.wfunc = this.opt.wrapperfunc;
    Value[] wvargs = func.wfunc.getArguments();
    Type[] argsTy = [wvargs[0].getType()];
    if (!config.opt_remove_sfp) {
        argsTy.add(wvargs[1].getType());
    }

    foreach(K_ARGUMENT inst in func.funcargs) {
        argsTy.add(this.convertType(inst.type));
    }
    Type innerRetTy = null;
    if (this.retclass != null) {
        innerRetTy = this.convertType(this.retclass);
    } else {
        innerRetTy = Type.getVoidTy();
    }
    FunctionType funcTy = FunctionType.get(innerRetTy, argsTy, false);
    String funcname = this.mtd.toString();
    func.func = Function.create(funcname, funcTy, this.opt.m, GlobalValue.InternalLinkage);
    this.opt.func = func.func;
    Array<Value> vargs = func.func.getArguments();
    vargs[0].setName("lctx");
    if (!config.opt_remove_sfp) {
        vargs[1].setName("lsfp");
    }
    for (int i=2; i < vargs.size; i++) {
        String name = "larg" + (i-2);
        vargs[i].setName(name);
    }
}
@Public void Compiler.init(Method mtd) {
    opt.wrapperfunc = Function.create(mtd.toString() + "_wrapper", opt.funcTy,
            opt.m, GlobalValue.ExternalLinkage);
    Array<Value> vargs = opt.wrapperfunc.getArguments();
    opt.ctx = vargs[0];
    if (config.opt_remove_sfp) {
        opt.sfp = null;
    } else {
        opt.sfp = vargs[1];
    }
    opt.bblist  = [];
    opt.bblist2 = [];

    init_common(mtd);
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
    func.addFnAttr(Attributes.AlwaysInline);
    return func;
}

@Public Value IRBuilder.getValueFromSfp(Value sfp, Type rTy, int sfpidx) {
    int idx;
    if (rTy.class == PointerType)
        idx = 0;
    else
        idx = 1;
    Value v = this.createConstGEP2_32(sfp, sfpidx, idx);
    return this.createBitCast(v, PointerType.get(rTy));
}

@Public Value IRBuilder.createLoadValueFromSfp(Value sfp, Type rTy, int sfpidx) {
    Value v = this.getValueFromSfp(sfp, rTy, sfpidx);
    return this.createLoad(v);
}
@Public void IRBuilder.createStoreValueToSfp(Value sfp, Type rTy, int sfpidx, Value v) {
    Value r  = this.getValueFromSfp(sfp, rTy, sfpidx);
    this.createStore(v, r);
}

@Public @Native FunctionPass LLVM.createSafePointPass();
//@Public @Native FunctionPass LLVM.createPartialEvaluationPass();
@Public void Compiler.emit(Method mtd) {
    if (opt.fpm == null) {
        FunctionPassManager fpm = new FunctionPassManager(opt.m);
        opt.fpm = fpm;
        if (config.opt_lazycompilation == false) {
            fpm.add(LLVM.createVerifierPass());
            if (config.enable_opt) {
                fpm.add(opt.ee.getTargetData());
                fpm.add(LLVM.createTypeBasedAliasAnalysisPass());
                fpm.add(LLVM.createBasicAliasAnalysisPass());
                //fpm.add(LLVM.createPartialEvaluationPass());
                fpm.add(LLVM.createCFGSimplificationPass());
                fpm.add(LLVM.createScalarReplAggregatesPass());
                fpm.add(LLVM.createEarlyCSEPass());
                fpm.add(LLVM.createLowerExpectIntrinsicPass());
            }
        }
    }
    if (config.intrinsic_method) {
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
                Function f = Intrinsic.getDeclaration(this.opt.m,
                        intrinsic_id[i], args);
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
    if (config.opt_lazycompilation) {
        if (mtd.getName() != "" && mtd.toString().endsWith("Script.main") == false) {
            this.opt.compilation_queue.add(kfunc);
            mtd.setLazycompile();
            return;
        }
    }
    if (!kfunc.isUndeveloped()) {
        FunctionPassManager fpm = opt.fpm;
        fpm.doInitialization();
        int compile_start = System.getTime();
        if (config.opt_lazycompilation &&
                (mtd.getName() == "" || mtd.toString().endsWith("Script.main"))) {
            K_Function[] cqueue = this.opt.compilation_queue;
            //FIXME Iterator BUG foreach (K_Function f in cqueue);
            for (int i; i < cqueue.size; i++) {
                K_Function f = cqueue[i];
                f.codegen(this);
            }
        }
        kfunc.codegen(this);
        int compile_end = System.getTime();
        statics.compile_time += compile_end - compile_start;

        int fpm_start = System.getTime();
        fpm.run(kfunc.wfunc);
        fpm.run(kfunc.func);
        int fpm_end = System.getTime();
        statics.optimize_time += fpm_end - fpm_start;

        if (mtd.getName() == "") {
        }
        else if (mtd.toString().endsWith("Script.main")) {
            //print this.const_table;
            this.compiled_methods = {};
            PassManager mpm = new PassManager();
            if (config.enable_opt) {
                if (config.opt_lazycompilation) {
                    fpm.add(opt.ee.getTargetData());
                    fpm.add(LLVM.createTypeBasedAliasAnalysisPass());
                    fpm.add(LLVM.createBasicAliasAnalysisPass());
                    fpm.add(LLVM.createCFGSimplificationPass());
                    fpm.add(LLVM.createScalarReplAggregatesPass());
                    fpm.add(LLVM.createEarlyCSEPass());
                    fpm.add(LLVM.createLowerExpectIntrinsicPass());
                }
                mpm.add(LLVM.createGlobalOptimizerPass());
                mpm.add(LLVM.createIPSCCPPass());
                //FIXME mpm.add(LLVM.createDeadArgEliminationPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createCFGSimplificationPass());
                mpm.add(LLVM.createFunctionAttrsPass());
                //FIXME mpm.add(LLVM.createArgumentPromotionPass());
                mpm.add(LLVM.createScalarReplAggregatesPass(-1));
                mpm.add(LLVM.createEarlyCSEPass());
                mpm.add(LLVM.createJumpThreadingPass());
                mpm.add(LLVM.createCorrelatedValuePropagationPass());
                mpm.add(LLVM.createCFGSimplificationPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createTailCallEliminationPass());
                mpm.add(LLVM.createCFGSimplificationPass());
                mpm.add(LLVM.createReassociatePass());
                mpm.add(LLVM.createLoopRotatePass());
                mpm.add(LLVM.createLICMPass());
                mpm.add(LLVM.createLoopUnswitchPass(true));
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createIndVarSimplifyPass());
                mpm.add(LLVM.createLoopIdiomPass());
                mpm.add(LLVM.createLoopDeletionPass());
                mpm.add(LLVM.createLoopUnrollPass());
            }
            if (config.opt_safepoint) {
                mpm.add(LLVM.createSafepointPass());
            }
            if (config.enable_opt) {
                mpm.add(LLVM.createGVNPass());
                //mpm.add(LLVM.createMemCpyOptPass());
                mpm.add(LLVM.createSCCPPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createJumpThreadingPass());
                mpm.add(LLVM.createCorrelatedValuePropagationPass());
                mpm.add(LLVM.createDeadStoreEliminationPass());
                mpm.add(LLVM.createAggressiveDCEPass());
                mpm.add(LLVM.createCFGSimplificationPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createStripDeadPrototypesPass());
                mpm.add(LLVM.createGlobalDCEPass());
                mpm.add(LLVM.createConstantMergePass());
                ///* LTO Passes */
                mpm.add(LLVM.createIPSCCPPass());
                mpm.add(LLVM.createGlobalOptimizerPass());
                mpm.add(LLVM.createConstantMergePass());
                //FIXME mpm.add(LLVM.createDeadArgEliminationPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                if (config.method_inlining) {
                    //TODO FIXME BUG
                    mpm.add(LLVM.createFunctionInliningPass());
                }
                mpm.add(LLVM.createGlobalOptimizerPass());
                mpm.add(LLVM.createGlobalDCEPass());
                //FIXME mpm.add(LLVM.createArgumentPromotionPass());
                mpm.add(LLVM.createInstructionCombiningPass());
                mpm.add(LLVM.createScalarReplAggregatesPass());
                mpm.add(LLVM.createFunctionAttrsPass());
                mpm.add(LLVM.createLICMpass());
                mpm.add(LLVM.createGVNPass());
                mpm.add(LLVM.createDeadStoreEliminationPass());
                mpm.add(LLVM.createCFGSimplificationPass());
                mpm.add(LLVM.createGlobalDCEPass());
            }
            if (config.verify_each) {
                mpm.add(LLVM.createVerifierPass());
            }
            int mpm_start = System.getTime();
            mpm.run(opt.m);
            int mpm_end = System.getTime();
            statics.optimize_time += mpm_end - mpm_start;
            if (config.module_dump) {
                opt.m.dump();
            }
        }
        if (config.opt_lazycompilation) {
            if ((mtd.getName() == "" || mtd.toString().endsWith("Script.main"))) {
                K_Function[] cqueue = this.opt.compilation_queue;
                //FIXME Iterator BUG foreach (K_Function f in cqueue);
                for (int i; i < cqueue.size; i++) {
                    K_Function f = cqueue[i];
                    f.mtd.setFunction(opt.ee.getPointerToFunction(f.wfunc));
                }
                this.opt.compilation_queue = [];

            }
        }
        mtd.setFunction(opt.ee.getPointerToFunction(kfunc.wfunc));
        if (config.print_statics && mtd.toString().endsWith("Script.main")) {
            OUT.println(statics);
        }
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
    opt.ktype["objectTy"]       = objectTy;
    opt.ktype["objectPtrTy"]    = objectPtrTy;
    opt.ktype["objectPtrPtrTy"] = objectPtrPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    Type listTy = StructType.create(fields, "Abstract_List", false);
    opt.ktype["Abstract.ListPtrTy"] = PointerType.get(listTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(objectPtrPtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type arrayTy = StructType.create(fields, "Array", false);
    Type arrayPtrTy = PointerType.get(arrayTy);
    opt.ktype["arrayPtrTy"] = arrayPtrTy;

    if (config.opt_array_access) {
        fields = [];
        fields.add(hObjectTy);
        fields.add(Type.getInt64PtrTy());
        Type iArrayPtrTy = PointerType.get(StructType.create(fields, "IArray", false));
        opt.ktype["iArrayPtrTy"] = iArrayPtrTy;

        fields = [];
        fields.add(hObjectTy);
        fields.add(Type.getDoublePtrTy());
        Type fArrayPtrTy = PointerType.get(StructType.create(fields, "FArray", false));
        opt.ktype["fArrayPtrTy"] = fArrayPtrTy;
    }

    fields = [];
    fields.add(hObjectTy);
    fields.add(Type.getInt1PtrTy()); /* text */
    fields.add(int64Ty);   /* len */
    Type stringTy = StructType.create(fields, "String", false);
    Type stringPtrTy = PointerType.get(stringTy);
    opt.ktype["stringTy"]    = stringTy;
    opt.ktype["stringPtrTy"] = stringPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(Type.getInt8PtrTy()); /* text */
    fields.add(int64Ty);   /* len */
    Type bytesTy = StructType.create(fields, "kBytes", false);
    Type bytesPtrTy = PointerType.get(bytesTy);
    opt.ktype["bytesTy"]    = bytesTy;
    opt.ktype["bytesPtrTy"] = bytesPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(objectPtrPtrTy);
    fields.add(objectPtrTy);
    Type objectFieldTy    = StructType.create(fields, "ObjectField", false);
    Type objectFieldPtrTy = PointerType.get(objectFieldTy);
    //opt.ktype["objectFieldTy"] = objectFieldTy;
    opt.ktype["objectFieldPtrTy"] = PointerType.get(objectFieldTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type outputStreamTy = StructType.create(fields, "OutputStream", false);
    Type outputStreamPtrTy = PointerType.get(outputStreamTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type inputStreamTy = StructType.create(fields, "InputStream", false);
    Type inputStreamPtrTy = PointerType.get(inputStreamTy);

    fields = [];
    fields.add(objectPtrTy);
    fields.add(Type.getInt64Ty());
    Type sfpTy = StructType.create(fields, "sfp", false);
    Type sfpPtrTy = PointerType.get(sfpTy);
    opt.ktype["sfpPtrTy"] = sfpPtrTy;

    fields = [];
    /* 00 */fields.add(int32Ty);
    /* 01 */fields.add(PointerType.get(StructType.create(null, "share", false)));
    /* 02 */fields.add(PointerType.get(StructType.create(null, "memshare", false)));
    /* 03 */fields.add(PointerType.get(StructType.create(null, "memlocal", false)));
    /* 04 */fields.add(PointerType.get(StructType.create(null, "stat", false)));
    /* 05 */fields.add(PointerType.get(StructType.create(null, "spi", false)));
    /* 06 */fields.add(PointerType.get(StructType.create(null, "api2", false)));
    /* 07 */fields.add(PointerType.get(StructType.create(null, "script", false)));
    /* 08 */fields.add(sfpPtrTy); /*stack*/
    /* 09 */fields.add(sfpPtrTy); /*esp*/
    /* 10 */fields.add(int64Ty);  /*stacksize*/
    /* 11 */fields.add(sfpPtrTy); /*stack_uplimit*/
    /* 12 */fields.add(int8PtrTy);/*cstack_bottom*/
    /* 13 */fields.add(PointerType.get(StructType.create(null, "Exception", false)));
    /* 14 */fields.add(PointerType.get(StructType.create(null, "ExceptionHandler", false)));
    /* 15 */fields.add(objectPtrTy);
    /* 16 */fields.add(int64Ty); /*isEvaled*/
    /* 17 */fields.add(arrayPtrTy);
    /* 18 */fields.add(arrayPtrTy);
    /* 19 */fields.add(PointerType.get(StructType.create(null, "mtdcache", false)));
    /* 20 */fields.add(PointerType.get(StructType.create(null, "tmrcache", false)));
    /* 21 */fields.add(stringPtrTy);
    /* 22 */fields.add(inputStreamPtrTy);
    /* 23 */fields.add(outputStreamPtrTy);
    /* 24 */fields.add(outputStreamPtrTy);
    fields.add(PointerType.get(bytesTy));
    fields.add(outputStreamPtrTy);
    fields.add(PointerType.get(StructType.create(null, "kGamma", false)));
    fields.add(PointerType.get(StructType.create(null, "kMap", false)));
    fields.add(Type.getInt32Ty()); /*flag*/
    fields.add(Type.getInt32Ty());
    fields.add(PointerType.get(StructType.create(null, "kCtx", false)));
    fields.add(int8PtrTy);/*parent*/
    fields.add(int8PtrTy);/*ctxlock*/
    fields.add(ArrayType.get(Type.getInt8Ty(), 16));
    fields.add(int64Ty);
    fields.add(int32Ty);
    fields.add(voidPtrTy);
    fields.add(PointerType.get(StructType.create(null, "kFunc", false)));

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
    argsTy.add(int64Ty);
    FunctionType fnewObjectTy = FunctionType.get(objectPtrTy, argsTy, false);
    opt.kfunctype["fnewObjectTy"] = fnewObjectTy;

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
    argsTy.add(int32Ty);
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

    FunctionType printTy;
    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    argsTy.add(stringPtrTy);
    argsTy.add(objectPtrTy);
    printTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    opt.kfunctype["printTy"] = printTy;
    argsTy[5] = intTy;
    printTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    opt.kfunctype["printITy"] = printTy;
    argsTy[5] = floatTy;
    printTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    opt.kfunctype["printFTy"] = printTy;
    argsTy[5] = Type.getInt1Ty();
    printTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    opt.kfunctype["printBTy"] = printTy;

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
    opt.ktype["methodTy"] = methodTy;
    opt.ktype["methodPtrTy"] = methodPtrTy;

    exfields = [];
    exfields.add(objectPtrTy); /* source */
    exfields.add(methodPtrTy); /* mtdNULL */
    exfields.add(voidPtrTy);   /* m.nptr */
    exfields.add(voidPtrTy);   /* m.nfree */
    exfields.add(voidPtrTy);   /* m.index */
    exfields.add(voidPtrTy);   /* m.max */
    Type itrExTy = StructType.create(exfields, "ItreatorEx", false);
    fields = [];
    fields.add(hObjectTy);
    fields.add(itrExTy);
    fields.add(fitrnextPtrTy);
    Type iteratorTy = StructType.create(fields, "Iterator", false);
    opt.ktype["IteratorPtrTy"] = PointerType.get(iteratorTy);

    fields = [];
    fields.add(int32Ty); /* cid */
    fields.add(int32Ty); /* mn */
    fields.add(intTy); /* mtd */
    Type mtdCacheTy = StructType.create(fields, "mtdCacheTy", false);
    opt.ktype["mtdCacheTy"]    = mtdCacheTy;
    opt.ktype["mtdCachePtrTy"] = PointerType.get(mtdCacheTy);

}

@Public @Override void K_PHI.codegen(Compiler asm) {
    if (|bbs| == 1) {
        setLLVMValue(asm, insts[0].getLLVMValue(asm));
        return;
    } else {
        PHINode pn = asm.opt.builder.createPHI(asm.convertType(type), |bbs|);
        for (int i = 0; i < |bbs|; i++) {
            if (LLVM_ENABLE_SAFEPOINT && config.asm.opt.bblist2[bbs[i]] != null) {
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
    CompilerOpt opt = asm.opt;
    if (LLVM_ENABLE_SAFEPOINT) {
        Value vsafepoint = opt.builder.createStructGEP(opt.ctx, 0);
        vsafepoint = opt.builder.createLoad(vsafepoint);
        BasicBlock bbThen = BasicBlock.create(opt.func, "safepoint");
        Value cond = opt.builder.createICmpEQ(vsafepoint, ConstantInt.get(Type.getInt32Ty(), 1));
        opt.builder.createCondBr(cond, bbThen, opt.bblist2[idx]);
        opt.builder.setInsertPoint(bbThen);
        asm.shiftesp(this.safepoint);
        Type fType = opt.ktype["safeptmethodPtrTy"];
        FunctionType fnTy  = opt.kfunctype["safeptmethodTy"];
        Function fcheck_safepoint = opt.m.getOrInsertFunction("knh_checkSafePoint", fnTy);
        Value vfunc = fcheck_safepoint;

        Value vctx  = opt.ctx;
        Value vsfp  = opt.builder.createConstGEP1_32(asm.getsfp(), this.safepoint);
        //FIXME(@imasahiro)
        //If we enable config.method_inlining, global string will
        //cause assertion fail.

        /*
           Value vstr  = opt.builder.createGlobalStringPtr("%d\n");
           vstr = opt.builder.createBitCast(vstr, Type.getInt8PtrTy());
           Value vstr  = opt.builder.createGlobalStringPtr("");
         */
        Value vstr  = ConstantPointerNull.get(Type.getInt8PtrTy());
        Value vline = ConstantInt.get(Type.getInt32Ty(), 0);
        Value[] args = [vctx, vsfp, vstr, vline];
        opt.builder.createCall(vfunc, args);
        opt.builder.createBr(opt.bblist2[idx]);
        opt.builder.setInsertPoint(opt.bblist2[idx]);
    }
}

@Public void K_BasicBlock.setSafePointMetaData(Compiler asm) {
    BasicBlock bb = asm.opt.bblist[bbidx];
    bb.getTerminator().setMetaData(asm.opt.m, "safepoint", this.safepoint);
}

@Public void K_Function.buildWrapperFunc(Compiler asm) {
    BasicBlock bb = BasicBlock.create(wfunc, "EntryBlock");
    asm.opt.builder = new IRBuilder(bb);
    asm.opt.builder.setInsertPoint(bb);
    Array<Value> wvargs = wfunc.getArguments();
    Value[] vargs = [wvargs[0]];
    if (!config.opt_remove_sfp) {
        vargs.add(wvargs[1]);
    }
    asm.opt.ctx = wvargs[0];
    asm.opt.sfp = wvargs[1];
    Value vsfp  = wvargs[1];
    foreach(K_ARGUMENT inst in funcargs) {
        inst.value = null;
        inst.codegen(asm);
        vargs.add(inst.getLLVMValue(asm));
    }
    Value res = asm.opt.builder.createCall(this.func, vargs);
    Type retTy = null;
    if (asm.retclass != null) {
        retTy = asm.convertType(asm.retclass);
        asm.opt.builder.createStoreValueToSfp(vsfp, retTy, K_RTNIDX, res);
    } else {
        retTy = Type.getVoidTy();
    }
    asm.opt.builder.createRetVoid();
}

@Public K_Inst K_BasicBlock.getTerminator() {
    if (insts.size == 0) {
        return null;
    }
    int size = insts.size;
    return insts[size-1];
}

@Public void K_Function.codegen(Compiler asm) {
    Array<Value> args = this.func.getArguments();
    asm.mtd = this.mtd;
    asm.retclass = this.mtd.getReturnType();
    asm.opt.reset(args, this);

    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] != null) {
            BasicBlock bb = null;
            //FIXME bbs[i].insts.size > 0 and bblist must be non nullable.
            if (bbs[i].insts.size > 0) {
                bb = BasicBlock.create(asm.opt.func, "bb"+i);
            }
            asm.opt.bblist.add(bb);
            if (LLVM_ENABLE_SAFEPOINT && bbs[i].safepoint != -1) {
                asm.opt.bblist2.add(BasicBlock.create(asm.opt.func, "bb"+i));
            } else {
                //asm.opt.bblist2.add(null);
            }
        } else {
            asm.opt.bblist.add(null);
            //asm.opt.bblist2.add(null);
        }
    }
    if (config.debug) {
        OUT.println(dump());
    }
    asm.opt.builder = new IRBuilder(asm.opt.bblist[0]);
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null) continue;
        //FIXME bbs[i].insts.size > 0 and bblist must be non nullable.
        if (asm.opt.bblist[i] == null) {
            continue;
        }
        asm.opt.builder.setInsertPoint(asm.opt.bblist[i]);
        if (bbs[i].phis != null) {
            foreach (String s in bbs[i].phis.keys()) {
                bbs[i].phis[s].codegen(asm);
            }
        }
        if (LLVM_ENABLE_SAFEPOINT && bbs[i].safepoint != -1) {
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
        if (config.opt_safepoint && bbs[i].attribute == "loopcond") {
            bbs[i].setSafePointMetaData(asm);
        }
    }
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
    Value sfp = builder.createGEP1(asm.getSfp(), thisidx);
    Value vrix = ConstantInt.get(asm.opt.intTy, K_RTNIDX);
    Value[] vargs = [asm.opt.ctx, sfp, vrix];

    builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), op.espidx + K_CALLDELTA, v0);
    Value vclass = builder.CreateIntToPtr(ConstantInt.get(asm.opt.intTy, type.getPtr()), asm.opt.ktype["objectPtrTy"]);
    builder.createStoreValueToSfp(asm.getsfp(), asm.convertType(Class), op.espidx + K_CALLDELTA+1, vclass);
    Value vmtd = builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(Method), K_MTDIDX2);
    builder.createStoreValueToSfp(asm.getsfp(), asm.convertType(Method), op.espidx + K_CALLDELTA-1, vmtd);

    int espshift = op.espidx + K_CALLDELTA + 2;
    asm.shiftesp(espshift);
    builder.createCall(func, vargs);
    Value v = builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(type), op.espidx);
    setLLVMValue(asm, v);
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    CompilerOpt opt = asm.opt;
    IRBuilder builder = opt.builder;
    Type intTy = opt.intTy;
    if (op.cast == 0) {
        //v = builder.createBitCast(v, asm.convertType(type));
        if (type == Float) {
            v = builder.createSIToFP(v, opt.floatTy);
        } else if (type == Int) {
            v = builder.createFPToSI(v, intTy);
        }
        //v = builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(type), op.b+op.rix);
        setLLVMValue(asm, v);
    } else {
        Value vsfp = asm.getsfp();
        FunctionType fnTy = opt.kfunctype["typemapmtdTy"];
        Value typemap_exec = opt.m.getOrInsertFunction("knh_TypeMap_exec", fnTy);
        builder.createStoreValueToSfp(vsfp, asm.convertType(op.inst0.type), op.b, op.inst0.getLLVMValue(asm));
        asm.shiftesp(op.espshift);
        Value vsfp2 = builder.createInBoundsGEP1(vsfp, ConstantInt.get(intTy, op.b));
        Value vctx = opt.ctx;
        Value vtmr = ConstantInt.get(intTy, op.cast);
        Value vrix = ConstantInt.get(intTy, op.rix);

        builder.createCall4(typemap_exec, vctx, vtmr, vsfp2, vrix);
        v = builder.createLoadValueFromSfp(vsfp, asm.convertType(type), op.b+op.rix);
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
    Type mtdTy = asm.opt.ktype["methodTy"];
    Type intTy = asm.opt.intTy;
    Value mtdNC = asm.opt.get_or_create(mtdTy, op.mtdNC, op.mtd.toString());
    Value vctx = asm.opt.ctx;
    if (!op.mtd.isFinal()) {
        Method mtd = op.mtd;
        Type mtdPtrTy = asm.opt.ktype["methodPtrTy"];
        Type mtdCacheTy    = asm.opt.ktype["mtdCacheTy"];
        Type mtdCachePtrTy = asm.opt.ktype["mtdCachePtrTy"];
        int cid = (to Int) mtd.getMethodClass();
        int mn  = mtd.mn;
        Type int32Ty = Type.getInt32Ty();

        BasicBlock bb = asm.opt.bblist[0];
        Instruction inst = bb.getLastInst();
        Value c0 = ConstantInt.get(int32Ty, 0);
        Value c1 = ConstantInt.get(int32Ty, 1);
        Value c2 = ConstantInt.get(int32Ty, 2);

        AllocaInst cache = new AllocaInst(mtdCacheTy);
        bb.insertBefore(inst, cache);
        for (int i=0; i < 3; i++) {
            Instruction f0   = GetElementPtrInst.create(cache, [c0, c0]);
            Instruction tmp0 = new StoreInst(ConstantInt.get(int32Ty, cid), f0);
            Instruction f1   = GetElementPtrInst.create(cache, [c0, c1]);
            Instruction tmp1 = new StoreInst(ConstantInt.get(int32Ty, mn), f1);
            Instruction f2   = GetElementPtrInst.create(cache, [c0, c2]);
            Instruction tmp2 = new StoreInst(ConstantInt.get(intTy, op.mtdNC), f2);
            bb.insertBefore(inst, f0);
            bb.insertBefore(inst, tmp0);
            bb.insertBefore(inst, f1);
            bb.insertBefore(inst, tmp1);
            bb.insertBefore(inst, f2);
            bb.insertBefore(inst, tmp2);
        }
        Value arg0 = args[0].getLLVMValue(asm);

        Type[] argsTy = [];
        argsTy.add(asm.opt.ktype["ctxTy"]);
        argsTy.add(asm.opt.objectTy);
        argsTy.add(mtdCachePtrTy);
        FunctionType fnTy = FunctionType.get(mtdPtrTy, argsTy, false);
        func = asm.opt.m.getOrInsertFunction("compiler_LOOKUPMTD", fnTy);
        mtdNC = builder.createCall3(func, vctx, arg0, cache);
    }
    else if (asm.compiled_methods[this.op.fname] != null) {
        Value thisidx = ConstantInt.get(intTy, op.thisidx);
        vargs = [vctx];
        if (!config.opt_remove_sfp) {
            Value vsfp = asm.getsfp();
            Value sfp = builder.createGEP1(vsfp, thisidx);
            vargs.add(sfp);
        }

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
            if (config.debug) {
                print "**WARN** compiled_methods call failed", this.op.fname;
            }
        }
    }
    if (config.intrinsic_method) {
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
            statics.opt_intrinsic_method += 1;
            return;
        }
    }

    if (op.mtd == asm.system_method[1]) {
        /* Ctx.getIn() */
        Value v = builder.createStructGEP(vctx, 22);
        v = builder.createLoad(v);
        v = builder.createBitCast(v, asm.convertType(type));
        setLLVMValue(asm, v);
        return;
    } else if (op.mtd == asm.system_method[2]) {
        /* Ctx.getOut() */
        Value v = builder.createStructGEP(vctx, 23);
        v = builder.createLoad(v);
        v = builder.createBitCast(v, asm.convertType(type));
        setLLVMValue(asm, v);
        return;
    } else if (op.mtd == asm.system_method[3]) {
        /* Ctx.getErr() */
        Value v = builder.createStructGEP(vctx, 24);
        v = builder.createLoad(v);
        v = builder.createBitCast(v, asm.convertType(type));
        setLLVMValue(asm, v);
        return;
    } else if (op.mtd.getName() == "getSize") {
        if (op.mtd.getMethodClass() == Array ||
                op.mtd.getMethodClass() == String ||
                op.mtd.getMethodClass() == Bytes) {
            Value v = args[0].getLLVMValue(asm);
            Type  t = asm.opt.ktype["Abstract.ListPtrTy"];
            v = builder.createBitCast(v, t);
            v = builder.createStructGEP(v, 2);
            v = builder.createLoad(v);
            setLLVMValue(asm, v);
            return;
        }
    } else if (op.mtd.getName() == "set") {
        if (op.mtd.getMethodClass() == Bytes) {
            IRBuilder builder = asm.opt.builder;
            Value v = args[0].getLLVMValue(asm);/* BytesPtr */
            Value arg1 = args[1].getLLVMValue(asm);/* size_t */
            Value arg2 = args[2].getLLVMValue(asm);/* uchar_t */
            Type  t = asm.opt.ktype["bytesPtrTy"];

            v = builder.createBitCast(v, t);
            arg2 = builder.createTrunc(arg2, Type.getInt8Ty());

            /* ptr->buf */
            v = builder.createStructGEP(v, 1);
            v = builder.createLoad(v);
            v = builder.createInBoundsGEP1(v, arg1);
            v = builder.createStore(arg2, v);
            setLLVMValue(asm, v);
            return;
        }
    }
    Value vsfp = asm.getsfp();
    if (op.ftype != FUNC_FASTCALL) {
        func = mtdNC;
        func = builder.createStructGEP(func, 4);
        func = builder.createLoad(func);
        Value thisidx = ConstantInt.get(intTy, op.thisidx);
        Value sfp = builder.createGEP1(vsfp, thisidx);
        Value vrix = ConstantInt.get(intTy, op.rix);
        vargs = [vctx, sfp, vrix];
        for (int i = 0; i < |args|; i++) {
            int idx = op.thisidx + i + op.flagStatic;
            Value v = args[i].getLLVMValue(asm);
            Type  t = asm.convertType(args[i].type);
            builder.createStoreValueToSfp(vsfp, t, idx, v);
        }
    } else {
        Type methodTy = asm.opt.ktype["fmethodPtrTy"];
        func = ConstantInt.get(intTy, op.mtdNC);
        func = builder.createIntToPtr(func, methodTy);
        Value vb = ConstantInt.get(intTy, op.thisidx);
        vb = builder.createGEP1(vsfp, vb);
        Value vrix = ConstantInt.get(intTy, op.rix);
        vargs = [vctx, vb, vrix];
    }
    //mtdNCPtr = builder.createBitCast(mtdNC, intTy);
    mtdNCPtr = builder.createPtrToInt(mtdNC, intTy);
    builder.createStoreValueToSfp(vsfp, intTy, op.thisidx-1, mtdNCPtr);
    asm.shiftesp(op.espshift);
    builder.createCall(func, vargs);
    if (type != null/*void*/) {
        Type ty = asm.convertType(type);
        Value v = builder.createLoadValueFromSfp(vsfp, ty, op.thisidx+op.rix);
        setLLVMValue(asm, v);
    }
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    assert (op.inst0 != null);
    Value v0 = op.inst0.getLLVMValue(asm);
    Function func;
    CompilerOpt opt = asm.opt;
    Module m = opt.m;
    if (type == Int) {
        FunctionType fnTy = opt.kfunctype["printITy"];
        func = m.getOrInsertFunction("knh_PRINTi", fnTy);
    } else if (type == Float) {
        FunctionType fnTy = opt.kfunctype["printFTy"];
        func = m.getOrInsertFunction("knh_PRINTf", fnTy);
    } else if (type == Boolean) {
        FunctionType fnTy = opt.kfunctype["printBTy"];
        func = m.getOrInsertFunction("knh_PRINTb", fnTy);
    } else {
        FunctionType fnTy = opt.kfunctype["printTy"];
        func = m.getOrInsertFunction("knh_PRINT", fnTy);
    }
    Value vsfp = opt.builder.createConstGEP1_32(asm.getsfp(), op.sfpidx);

    Type  mtdTy = opt.ktype["methodTy"];
    Type  strTy = opt.ktype["stringTy"];
    Type  intTy = opt.intTy;
    Value mtdNC = opt.get_or_create(mtdTy, asm.mtd.getPtr(), asm.mtd.toString());
    Value msg   = opt.get_or_create(strTy, op.msg.getPtr(), "string");
    Value mtdNCPtr = builder.createPtrToInt(mtdNC, intTy);
    builder.createStoreValueToSfp(vsfp, intTy, -1, mtdNCPtr);
    Value flag  = ConstantInt.get(asm.opt.intTy, op.pflag);
    Value uline = ConstantInt.get(asm.opt.intTy, op.opline);
    Value[] vargs = [opt.ctx, vsfp, flag, uline, msg, v0];
    builder.createCall(func, vargs);
}
@Public @Override void K_TR.codegen(Compiler asm) {
    Value func;
    FunctionType fnTy = asm.opt.kfunctype["trmethodTy"];
    Module m = asm.opt.m;
    if (op.ftr == Stmt.CWB) {
        func = m.getOrInsertFunction("compiler_CWB", fnTy);
    } else if (op.ftr == Stmt.TOSTR) {
        func = m.getOrInsertFunction("compiler_TOSTR", fnTy);
    } else if (op.ftr == Stmt.NULL) {
        func = m.getOrInsertFunction("compiler_NULVAL", fnTy);
    } else {
        Type methodTy = asm.opt.ktype["trmethodPtrTy"];
        func = ConstantInt.get(asm.opt.intTy, op.ftr);
        func = asm.opt.builder.CreateIntToPtr(func, methodTy);
    }
    Value vb = ConstantInt.get(asm.opt.intTy, op.espidx);
    vb = asm.opt.builder.createGEP1(asm.getsfp(), vb);
    Value rix = ConstantInt.get(asm.opt.intTy, op.rix);
    Value cid = ConstantInt.get(asm.opt.intTy, op.c.getClassTablePtr());
    if (op.inst0 != null) {
        asm.opt.builder.createStoreValueToSfp(asm.getsfp(), asm.convertType(op.inst0.type), op.espidx, op.inst0.getLLVMValue(asm));
    }
    asm.opt.builder.createCall4(func, asm.opt.ctx, vb, rix, cid);
    Value v = asm.opt.builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(type), op.espidx + op.rix);
    setLLVMValue(asm, v);
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    assert(op.ftr == Stmt.NEW);
    Value ret;
    CompilerOpt opt = asm.opt;
    int ridx = kvalue.idx + op.rix;
    Value vsfp = asm.getsfp();
    if (config.opt_object_new) {
        statics.opt_object_new += 1;
        FunctionType fnTy = opt.kfunctype["fnewObjectTy"];
        Function func = opt.m.getOrInsertFunction("new_Object_init2", fnTy);
        Value cid = ConstantInt.get(opt.intTy, op.c.getClassTablePtr());
        ret = opt.builder.createCall2(func, opt.ctx, cid);
        opt.builder.createStoreValueToSfp(vsfp, asm.convertType(op.inst0.type), ridx, ret);
    } else {
        FunctionType fnTy = opt.kfunctype["trmethodTy"];
        Value func = opt.m.getOrInsertFunction("TR_NEW", fnTy);
        Value vb   = ConstantInt.get(opt.intTy, kvalue.idx);
        vb = opt.builder.createGEP1(vsfp, vb);
        Value rix = ConstantInt.get(opt.intTy, op.rix);
        Value cid = ConstantInt.get(opt.intTy, op.c.getClassTablePtr());
        opt.builder.createCall4(func, opt.ctx, vb, rix, cid);
        ret = opt.builder.createLoadValueFromSfp(vsfp, asm.convertType(type), ridx);
    }
    setLLVMValue(asm, ret);


}
Type get_atype(Compiler asm, Class type) {
    Type aType;
    if (config.opt_array_access) {
        statics.opt_array_access += 1;
        if (type == Int || type == Boolean) {
            aType = asm.opt.ktype["iArrayPtrTy"];
        } else if (type == Float) {
            aType = asm.opt.ktype["fArrayPtrTy"];
        } else {
            aType = asm.opt.ktype["arrayPtrTy"];
        }
    } else {
        aType = asm.opt.ktype["arrayPtrTy"];
    }
    return aType;
}

@Public @Override void K_GETIDX.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    Type aType = get_atype(asm, type);
    v = builder.createBitCast(v, aType);
    v = builder.createStructGEP(v, 1);
    v = builder.createLoad(v);
    if (config.opt_array_access == false) {
        v = builder.createBitCast(v, PointerType.get(asm.opt.intTy));
    }
    v = builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = op.inst0.getLLVMValue(asm);
    Type aType = get_atype(asm, type);
    v = builder.createBitCast(v, aType);
    v = builder.createStructGEP(v, 1);
    v = builder.createLoad(v);
    if (!config.opt_array_access) {
        v = builder.createBitCast(v, PointerType.get(asm.opt.intTy));
    }
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
        //ConstantInt c = ConstantInt.get(asm.opt.intTy, op.objptr);
        //v = asm.opt.builder.CreateIntToPtr(c, asm.opt.ktype["objectPtrTy"]);
        Type type = asm.opt.ktype["objectTy"];
        v = asm.opt.get_or_create(type, op.objptr, "global");
    }
    setLLVMValue(asm, v);
}

@Public boolean Class.can_opt_field_access() {
    if (this.isSMALLOBJECT() == false)
        return false;
    if (this.isFinal() == false)
        return false;
    if (this.getSuper() != Object)
        return false;
    return true;
}

Value get_field_ptr(Compiler asm, K_Inst inst0, int offset) {
    Value v = null;
    IRBuilder builder = asm.opt.builder;
    BasicBlock curBB = builder.getInsertBlock();
    String cname = (to String) inst0.type;
    Type type = asm.user_type[cname];
    if (type == null) {
        asm.register_user_class(inst0.type, cname);
    }
    type = asm.user_type[cname];
    Boolean userType = (type != null);
    if (userType == false) {
        type = asm.opt.ktype["objectFieldPtrTy"];
    }
    if (config.opt_field_access) {
        if (inst0.opt != null) {
            Tuple<Value, BasicBlock> t = inst0.opt;
            if (t[1] == curBB) {
                statics.opt_field_access += 1;
                v = t[0];
            }
        }
    }
    if (v == null) {
        v = inst0.getLLVMValue(asm);
        v = builder.createBitCast(v, type);
        if (userType == true && inst0.type.can_opt_field_access()) {
            Value field = builder.createStructGEP(v, offset+2);
            return field;
        }
        v = builder.createStructGEP(v, 1);
        v = builder.createLoad(v);
        if (config.opt_field_access) {
            inst0.opt = (v, curBB);
        }
    }

    if (userType) {
        v = builder.createStructGEP(v, offset);
    }
    else {
        // access Script Field
        //TODO support opt_field_access for Script class
        v = builder.createBitCast(v, asm.opt.ktype["objectPtrPtrTy"]);
        v = builder.createConstGEP1_32(v, offset);
    }
    return v;
}

@Public @Override void K_GetField.codegen (Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = get_field_ptr(asm, op.inst0, op.bn);
    v = builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Public @Override void K_SetField.codegen(Compiler asm) {
    IRBuilder builder = asm.opt.builder;
    Value v = get_field_ptr(asm, op.inst0, op.an);
    v = builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
    v = builder.createStore(op.inst1.getLLVMValue(asm), v);
    setLLVMValue(asm, v);
}

@Public @Override void K_NEXT.codegen(Compiler asm) {
    Value itr = op.inst0.getLLVMValue(asm);
    itr = asm.opt.builder.createBitCast(itr, asm.opt.ktype["IteratorPtrTy"]);
    Value fnext_1 = asm.opt.builder.createStructGEP(itr, 2);
    fnext_1 = asm.opt.builder.createLoad(fnext_1);
    Value vctx = asm.opt.ctx;
    Value vsfp = asm.opt.builder.createConstGEP1_32(asm.getsfp(), op.b);
    Value vrix = ConstantInt.get(asm.opt.intTy, op.rix);
    asm.shiftesp(op.espshift);
    Value v = asm.opt.builder.createCall3(fnext_1, vctx, vsfp, vrix);
    Value res = asm.opt.builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(type), op.b + op.rix);
    setLLVMValue(asm, res);
    v = asm.opt.builder.createICmpNE(v, ConstantInt.get(asm.opt.intTy, 0));
    asm.opt.builder.createCondBr(v, asm.opt.bblist[op.nextBB], asm.opt.bblist[op.endBB]);
}

@Public @Override void K_LDMTD.codegen(Compiler asm) {
    //Type fmethodTy = asm.opt.ktype["fmethodPtrTy"];
    //Value func = ConstantInt.get(asm.opt.intTy, op.ldmtd);
    //func = asm.opt.builder.CreateIntToPtr(func, fmethodTy);
    //Value vop = ConstantInt.get(asm.opt.intTy, op.opline);
    //asm.opt.builder.createCall3(func, asm.opt.ctx, asm.getsfp(), vop);
    throw new Exception();
}

@Public @Override void K_ARGUMENT.codegen(Compiler asm) {
    Value v;
    if (!op.inner) {
        v = asm.opt.builder.createLoadValueFromSfp(asm.getsfp(), asm.convertType(type), op.argidx);
    } else {
        Value[] vargs = asm.opt.func.getArguments();
        Method mtd = asm.mtd;
        String mtdName = mtd.toString();
        int index = op.argidx;
        if (!config.opt_remove_sfp) {
            index += 1;
        }
        if (!(mtd.isStatic() && !mtdName.endsWith("new") && !mtdName.endsWith("Script."))) {
                index += 1;
        }
        String name = "arg"+(index-1);
        v = vargs[index];
        v.setName(name);
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
            builder.createStoreValueToSfp(asm.getsfp(), asm.convertType(Object), K_RTNIDX, op.inst0.getLLVMValue(asm));
        }
        builder.createRetVoid();
    }
}

