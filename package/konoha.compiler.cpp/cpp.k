using konoha.math.*;
//using konoha.compiler.*;
//class CompilerOpt {
//    String[] source;
//    Class [] declareClass;
//    String[] topLevelFunctionList;
//}
System.addClassField(CompilerOpt, Array<String>, "source");
System.addClassField(CompilerOpt, Array<Class> , "declareclass");
System.addClassField(CompilerOpt, Array<String>, "topLevelFunctionList");
System.addClassField(CompilerOpt, Array<String>, "var_decls");
@Public void CompilerOpt.init() {
    this.source = [];
    this.declareClass = [];
    this.topLevelFunctionList = [];
}

@Public Compiler Compiler.new() {
    opt = new CompilerOpt();
    opt.init();
    init_first();
}

String mtdclass2str(String s) {
    return s.split(".")[|s.split(".")|-2];
}

String class2str(Class c, boolean isPtr) {
    String s = (to String) c;
    s = s.replace(".", "::");
    if ("<" in? s) {
        a = s.split(">");
        q = a[0].split("<");;
        a[0] = q[1];
        String typename = "";
        foreach (String l in a) {
            if (l == "") {
                continue;
            }
            if (!isPtr) {
                typename = "boost::shared_ptr<" + l + " >";
            } else {
                typename = l;
            }
        }
        typename += " >";
        s = q[0] + + "<" + typename;
    }
    if (s.startsWith("main::")) {
        s = s.replace("main::", "_main_::");
    }
    //if (s.indexof(".") != -1) {
    //    s = s.split(".")[|s.split(".")|-1];
    //}
    if (!c.isUnboxType() && !isPtr) {
        s = "boost::shared_ptr<" + s + " >";
    }
    return s;
}

@Public String Compiler.declValue(K_Inst inst) {
    String tmp = class2str(inst.type) + " " + inst.getName() + ";"; 
    if (|inst.declPoint| <= 1 && !tmp in? opt.var_decls ) {
        return class2str(inst.type) + " ";
    } else {
        return "";
    }
}

String getTypeName (Class type) {
    String res = (to String) type;
    return (res == "") ? "null" : res;
}

@Public void Compiler.addClass(Class c) {
    String cname = (to String)c;
    Class[] declareclass = this.opt.declareclass;
    if (c != null && cname.indexOf("Script") == -1 && !cname.startsWith("konoha.")
            && declareclass.indexOf(c) == -1) {
        declareclass.add(c);
    }
}

@Public void Compiler.addSource(String str, int count) {
    String tmp = "";
    for (int i = 0; i < count; i++) {
        tmp += "  ";
    }
    tmp += str;
    int size = this.opt.source.size;
    this.opt.source[size - 1] += tmp + EOL;
}
@Public void Compiler.addDecl(Class type, String vname) {
    vname = class2str(type) + " " + vname + ";";
    if (!vname in? opt.var_decls) {
        opt.var_decls.add(vname);
    }
}
@Public void Compiler.addFunc(String init) {
    this.opt.source.add(init);
}

@Public @Override void K_PHI.codegen(Compiler asm) {
    /* if one node incoming, this phinode behave like K_MOV instruction*/
    if (|bbs| == 1 && getName() != insts[0].getName()) {
        String res;
        res = asm.declValue(insts[0]) + getName() + " = " + insts[0].getName() + ";";
        asm.addSource(res, 2);
    }
}

@Public void K_BasicBlock.codegen(Compiler asm) {
}

@Public @Virtual void K_Inst.check_decls(Compiler asm) {
    if (type != null && |declPoint| > 1) {
        asm.addDecl(type, getName());
    }
}
@Public @Override void K_MOV.check_decls(Compiler asm) {
    if (getName() != op.inst0.getName()) {
        asm.addDecl(type, getName());
    }
}

@Public void K_Function.codegen(Compiler asm) {
    asm.addClass(asm.mtd.getMethodClass());
    asm.addClass(asm.mtd.getReturnType());
    foreach (Class c in asm.mtd.getParamTypes()) {
        asm.addClass(c);
    }
    String fncdef = "";
    String thisclass = mtdclass2str(asm.mtd.toString());
    if (isStatic == 1 || thisclass == "Script") {
        if (asm.mtd.getName() == "") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add("Script" + size);
            fncdef += "void Script" + size + "(";
        } else if (asm.mtd.getName() == "main") {
            fncdef += "void " + asm.mtd.getName()+"_(";
            asm.opt.topLevelFunctionList.add("main_");
        } else {
            type = class2str(asm.mtd.getReturnType());
            fncdef += type + " " + asm.mtd.getName() + "(";
        }
    } else {
        fncdef += (thisclass) + "::" + asm.mtd.getName() + " ( ";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += asm.declValue(funcargs[i]) + /*class2str(funcargs[i].type) + " " + */funcargs[i].getName();
        if (i != |funcargs|-1) {
            fncdef += ", ";
        }
    }
    fncdef += ") {" + EOL;
    asm.addFunc(fncdef);
    if (isStatic == 0 && |funcargs| > 0) {
        asm.addSource(funcargs[0].type + " " + funcargs[0].getName() + " = this;", 1);
    }

    /* check variable decls */
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null || |bbs[i].insts| == 0) continue;
        foreach(String s in bbs[i].phis.keys()) {
            bbs[i].phis[s].check_decls(asm);
        }
        for (int j = 0; j < |bbs[i].insts|-1; j++) {
            bbs[i].insts[j].check_decls(asm);
        }
        for (int j = 0; j < |bbs[i].movs|; j++) {
            bbs[i].movs[j].check_decls(asm);
        }
        bbs[i].insts[|bbs[i].insts|-1].check_decls(asm);
    }
    /* code generate */
    String[] var_decls = asm.opt.var_decls;
    for (int i=0; i < var_decls.size; i++) {
        asm.addSource(var_decls[i], 1);
    }
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null || |bbs[i].insts| == 0) continue;
        asm.addSource("L_" + i + ": {", 1);
        foreach(String s in bbs[i].phis.keys()) {
            bbs[i].phis[s].codegen(asm);
        }
        for (int j = 0; j < |bbs[i].insts|-1; j++) {
            bbs[i].insts[j].codegen(asm);
        }
        for (int j = 0; j < |bbs[i].movs|; j++) {
            bbs[i].movs[j].codegen(asm);
        }
        bbs[i].insts[|bbs[i].insts|-1].codegen(asm);
        asm.addSource("}", 1);
    }
    asm.addSource("}", 0);
}
@Public @Override void K_MOV.codegen(Compiler asm) {
    if (getName() != op.inst0.getName()) {
        String res;
        res = getName() + " = " + op.inst0.getName() + ";";
        asm.addSource(res, 2);
    }
}
@Public void KBinaryInst.emit_binary_op(Compiler asm, Class c, String vname, String lhs, String rhs, String op) {
    String res;
    res = asm.declValue(this) + vname + " = " + lhs + " "+op+" " + rhs + ";";
    asm.addSource(res, 2);
}
@Public void KUnaryInst.emit_unary_op(Compiler asm, Class c, String vname, String lhs, String op) {
    String res;
    res = asm.declValue(this) + vname + " = " + op+" " + lhs + ";";
    asm.addSource(res, 2);
}

@Public @Override void K_ADD.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "+");
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "-");
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "*");
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "/");
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "%");
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "==");
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "!=");
}
@Public @Override void K_LT.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "<");
}
@Public @Override void K_GT.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), ">");
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "<=");
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), ">=");
}
@Public @Override void K_AND.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "&");
}
@Public @Override void K_OR.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "|");
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    emit_unary_op(asm, type, getName(), op.inst0.getName(), "!");
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "^");
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    String inst0 = op.inst0.getName();
    String inst1 = op.inst1.getName();
    String inst2 = op.inst2.getName();
    String t = class2str(type);
    String res = asm.declValue(this) + getName() + " = " + (inst0) + " ? " inst1 + " : " + inst2 + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), "<<");
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    emit_binary_op(asm, type, getName(), op.inst0.getName(), op.inst1.getName(), ">>");
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    /* TODO */
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    String t = class2str(type);
    asm.addSource(asm.declValue(this) + getName() + " = static_cast<" + t + ">("+op.inst0.getName()+");", 2);
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.addSource("goto L_" + op.jmpidx + ";", 2);
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if (" + op.inst0.getName() + ") {", 2);
    asm.addSource("goto L_" + op.bbThen + ";", 4);
    asm.addSource("} else {", 2);
    asm.addSource("goto L_" + op.bbElse + ";", 4);
    asm.addSource("}", 2);
}
@Public @Override void K_CALL.codegen(Compiler asm) {
    String t = class2str(type);
    boolean flag = false;
    if (op.flagStatic == 0) {
        if (!args[0].kvalue.type.isUnboxType()) {
            flag = true;
        }
    }
    String res = "";
    if (op.mtd.getReturnType() != Void) {
        res = asm.declValue(this) + getName() + " = ";
    }
    String thisclass = mtdclass2str(op.mtd.toString());
    if (flag) {
        res += args[0].getName() + "->";
    } else if (thisclass != "Script") {
        res += (thisclass) + "->";
    }
    res += op.mtd.getName().replace(":", "_") + "(";
    int cur = flag ? 1 : 0;
    for (; cur < |args|; cur++) {
        res += args[cur].getName();
        if (cur != |args|-1) {
            res += ", ";
        }
    }
    res += ");";
    asm.addSource(res, 2);
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    //if (op.inst0 != null) {
    //    asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(type), op.sfpidx, op.inst0.getLLVMValue(asm));
    //}
    //Type fmethodTy = asm.ktype["fmethodPtrTy"];
    //Value func = ConstantInt.get(asm.intTy, op.fprint);
    //func = asm.builder.CreateIntToPtr(func, fmethodTy);
    //Value vop = ConstantInt.get(asm.intTy, op.opline);
    //Value[] vargs = [asm.ctx, asm.sfp, vop];
    //asm.builder.createCall(func, vargs);
}
@Public @Override void K_TR.codegen(Compiler asm) {
    String tn = asm.declValue(this) + getName();
    switch (this.getTRMethod()) {
        case "box":
            asm.addSource(tn + " = konoha::cast<"+class2str(type, true)+">(" + op.inst0.getName() + ");", 2);
            break;
        case "bnul":
            if (type == Script) {
                asm.addSource(tn + " = script;", 2);
            }
            break;
        case "cwb":
            tn = "boost::shared_ptr<konoha::StringStream>" + " " + getName();
            asm.addSource(tn + "( new konoha::StringStream());", 2);
            break;
        case "tostr":
            asm.addSource(tn + " = " + op.inst0.getName + "->tostr();", 2);
            break;
    }
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String t = asm.declValue(this);
    asm.addClass(this.type);
    String name = class2str(type, true);
    asm.addSource(t + getName() + "( new " + (name) + "());", 2);
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    String t = asm.declValue(this);
    asm.addSource(t + getName() + " = " + op.inst0.getName() + ".get(" + op.inst1.getName() + ");", 2);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getName() + ".set(" + op.inst1.getName() + ", " + op.inst2.getName() + ");", 2);
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    String t = asm.declValue(this);
    asm.addClass(this.type);
    String const_data = quote(op.const_table[op.table_idx])
    if (this.type == Int || this.type == Float || this.type == Boolean) {
        asm.addSource(t + getName() + " = " + const_data + ";", 2);
    } else if (this.type == Class) {
        asm.addSource(t + getName() + " = new " + ("String") + "(" + const_data + ");", 2);
    } else {
        asm.addSource(t + getName() + " ( new " + (class2str(this.type, true)) + "(" + const_data + "));", 2);
    }
}
@Public @Override void K_GetField.codegen (Compiler asm) {
    String t = asm.declValue(this);
    asm.addClass(this.type);
    asm.addSource(t + getName() + " = " + op.inst0.getName() + "->field" + op.bn + ";", 2);
}
@Public @Override void K_SetField.codegen(Compiler asm) {
    asm.addClass(type);
    asm.addSource(op.inst0.getName() + "->field" + op.an + " = " + op.inst1.getName() + ";", 2);
}
@Public @Override void K_NEXT.codegen(Compiler asm) {}
@Public @Override void K_LDMTD.codegen(Compiler asm) {}
@Public @Override void K_ARGUMENT.codegen(Compiler asm) {}
@Public @Override void K_RET.codegen(Compiler asm) {
    String res = "return ";
    if (asm.retclass != null && op.inst0 != null) {
        res += op.inst0.getName();
    }
    res += ";";
    asm.addSource(res, 2);
}

@Public void Compiler.emit(Method mtd) {
    for (int i = 0; i < kfunc.const_table.size; i++) {
        this.addConstTable(kfunc.const_table[i]);
    }
    if (!kfunc.curBB.hasReturn && kfunc.retTy == null) {
        K_RET inst = new K_RET(new K_RETop(null));
        kfunc.curBB.insts.add(inst);
        kfunc.curBB.hasReturn = true;
    }
    kfunc.codegen(this);
}
@Public void Compiler.init(Method mtd) {
    this.mtd = mtd;
    if (this.opt == null) {
        this.opt = new CompilerOpt();
    }
    this.opt.var_decls = [];
    paramsclass = mtd.getParamTypes();
    retclass    = mtd.getReturnType();
    this.kfunc = new K_Function(mtd);
    if (mtd.getName() == ""/*global variable definition*/) {
        K_Value kvalue = kfunc.getKValue(0, Script);
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0), kfunc.curBB);
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
        initFunc(kfunc);
        return;
    }
    if (mtd.isStatic() && gamma_hasFIELD()) {
        K_Value kval = kfunc.getKValue(0, Script);
        K_Inst inst = new K_TR(kval, new K_TRop(null, 0, 0, gamma_getThiscid(), Stmt.NULL), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(0, inst);
    }

    if (!mtd.isStatic()) {
        K_Value kvalue = kfunc.getKValue(0, mtd.getMethodClass());
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0), kfunc.curBB);
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
    }
    for (int i =  0; i < |paramsclass|; i++) {
        Class j = paramsclass[i];
        K_Value kvalue = kfunc.getKValue(i+1, j);
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(i+1), kfunc.curBB);
        kfunc.storeKInst(i+1, inst);
        kfunc.funcargs.add(inst);
    }
    initFunc(kfunc);
    String mtdName = mtd.toString();
    if (this.compiled_methods[mtdName] == null) {
        this.compiled_methods[mtdName] = [];
    }
    this.compiled_methods[mtdName].add(kfunc);
}
@Public String Compiler.createKickFunc() {
    String res = "";
    boolean hasScr = false;
    foreach (fnc in this.opt.topLevelFunctionList) {
        if (fnc.indexOf("Script") != -1) {
            hasScr = true;
        }
    }
    if (hasScr) {
        res += "void " + "Script" + "() {" + EOL;
        res += "}" + EOL;
        res += EOL;
    }
    res += "int main (int argc, const char **argv) {" + EOL;
    res += "  boost::shared_ptr<konoha::Array<boost::shared_ptr<konoha::String> > > args(new konoha::Array<boost::shared_ptr<konoha::String> >());" + EOL;
    res += "  System.reset(new konoha::System());" + EOL;
    res += "  for (int i=0; i < argc; i++) {" + EOL;
    res += "      boost::shared_ptr<konoha::String> s(new konoha::String(argv[i]));" + EOL;
    res += "      args->append(s);" + EOL;
    res += "  }" + EOL;
    if (hasScr) {
        res += "  script = new " + ("Script") + "();" + EOL;
    }
    foreach (fnc in this.opt.topLevelFunctionList) {
        res += "  " + fnc + "(";
        if (fnc.indexOf("Script") != -1) {
            res += "script";
        }
        if (fnc == "main_") {
            res += "args";
        }
        res += ");" + EOL;
    }
    res += "  return 0;" + EOL;
    res += "}" + EOL;
    return res;
}
@Public String Compiler.createClassDefinition(Class c, String cname) {
    String[] ns = [];
    String res = "";
    if ("::" in? cname) {
        ns = cname.split("::");
        cname = ns.pop();
    }
    foreach (String n in ns) {
        if (n.startsWith("main::")) {
            n = n.replace("main::", "_main_::");
        }
        res += "namespace " + n + " {" + EOL;
    }
    res += "class " + cname + " {" + EOL;
    res += "public:" + EOL;
    int i = 0;
    foreach (Class fieldclass in c.getFieldClasses()) {
        fclass = class2str(fieldclass);
        res += "  " + fclass + " " + "field" + i + ";";
        res += EOL;
        i++;
    }
    foreach (Method mtd in c.getMethods) {
        if (mtd.indexOfGetterField() == -1 && mtd.indexOfSetterField() == -1) {
            String retTy = class2str(mtd.getReturnType());
            res += "  " + retTy + " " + mtd.getName() + "(";
            Class[] params = mtd.getParamTypes();
            for (int j = 0; j < |params|; j++) {
                res += class2str(params[j]);
                if (j != |params|-1) {
                    res += ", ";
                }
            }
            res += ");" + EOL;
        }
    }
    res += "};" + EOL;
    foreach (String n in ns) {
        res += "} //" + n + EOL;
    }
    return res;
}
@Public void Compiler.dump(Boolean dump) {
    OUT << "#include \"konoha.hpp\"" << EOL;
    OUT << "boost::shared_ptr<konoha::System> System;" << EOL;
    foreach (Class c in this.opt.declareclass) {
        String cname = class2str(c, true);
        OUT << createClassDefinition(c, cname) << EOL;
    }
    foreach (str in this.opt.source) {
        OUT << str << EOL;
    }
    OUT << createKickFunc() << EOL;
}

