TOP = "__topLevelFunc__()"
//class CompilerOpt {
//    String[] source;
//    Class [] declareClass;
//    String[] topLevelFunctionList;
//}
System.addClassField(CompilerOpt, String[], "source");
System.addClassField(CompilerOpt, Class [], "declareclass");
System.addClassField(CompilerOpt, String[], "topLevelFunctionList");
@Public void CompilerOpt.init() {
    this.source = [];
    this.declareClass = [];
    this.topLevelFunctionList = [];
}

String getTypeName (Class type) {
    String res = (to String) type;
    return (res == "") ? "null" : res;
}
String uscore(String in) {
    return "__" + in + "__";
}
LABEL = uscore("label");
@Public void Compiler.addSource(String str, int count) {
    String tmp = "";
    for (int i = 0; i < count; i++) {
        tmp += "  ";
    }
    tmp += str;
    int size = this.opt.source.size;
    this.opt.source[size - 1] += tmp + EOL;
}
@Public void Compiler.addFunc(String init) {
    this.opt.source.add(init);
}

@Public @Override void K_PHI.codegen(Compiler asm) {
    /* do not use */
}
@Public void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

@Public void K_Function.codegen(Compiler asm) {
    String fncdef = "";
    String thisclass = asm.mtd.toString().split(".")[1];
    if (isStatic == 1 || thisclass == "Script") {
        if (thisclass == "Script") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add("Script" + size);
            fncdef += "function Script" + size + "(script";
        } else {
            fncdef += "function " + asm.mtd.getName() + "(";
            if (asm.mtd.getName() == "main") {
                asm.opt.topLevelFunctionList.add("main");
            }
        }
    } else {
        fncdef += uscore(thisclass) + ".prototype." + asm.mtd.getName() + " = function(";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += funcargs[i].getName();
        if (i != |funcargs|-1) {
            fncdef += ", ";
        }
    }
    fncdef += ") {" + EOL;
    asm.addFunc(fncdef);
    if (isStatic == 0 && |funcargs| > 0) {
        asm.addSource("var " + funcargs[0].getName() + " = this;", 1);
    }
    asm.addSource("var " + LABEL + " = 0;", 1);
    asm.addSource("while(true) switch (" + LABEL + ") {", 1);
    for (int i = 0; i < |bbs|; i++) {
        asm.addSource("case " + i + ":", 2);
        if (bbs[i] == null) continue;
        foreach (K_Inst inst in bbs[i].insts) {
            inst.codegen(asm);
        }
        asm.addSource("break;", 2);
    }
    asm.addSource("}", 0);
    asm.addSource("", 0);
}
@Public @Override void K_ADD.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " + " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " - " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " * " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " / " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " % " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " == " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " != " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_LT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " < " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_GT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " > " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " <= " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " >= " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_AND.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " & " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_OR.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " | " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = !" + op.inst0.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " xor " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    String res = "";
    res += "var " + getName() + " = " + op.inst0.getName() + " ? " op.inst1.getName() + " : " + op.inst2.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " << " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " >> " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    /* do not use */
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource("var " + getName() + " = " + uscore("Math") + ".floor(" + op.inst0.getName() + ");", 3);
    } else {
        asm.addSource("var " + getName() + " = " + op.inst0.getName() + ";", 3);
    }
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.addSource(LABEL + " = " + op.jmpidx + ";", 3);
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if (" + op.inst0.getName() + ") {", 3);
    asm.addSource(LABEL + " = " + op.bbThen + ";", 4);
    asm.addSource("} else {", 3);
    asm.addSource(LABEL + " = " + op.bbElse + ";", 4);
    asm.addSource("}", 3);
}
@Public @Override void K_CALL.codegen(Compiler asm) {
    boolean flag = false;
    if (op.flagStatic == 0) {
        if (!args[0].kvalue.type.isUnboxType()) {
            flag = true;
        }
    }
    String res = "";
    if (op.mtd.getReturnType() != Void) {
        res = "var " + getName() + " = ";
    }
    String thisclass = op.mtd.toString().split(".")[1];
    if (flag) {
        res += args[0].getName() + ".";
    } else if (thisclass != "Script") {
        res += thisclass + ".";
    }
    res += op.mtd.getName() + "(";
    int cur = flag ? 1 : 0;
    for (; cur < |args|; cur++) {
        res += args[cur].getName();
        if (cur != |args|-1) {
            res += ", ";
        }
    }
    res += ");";
    asm.addSource(res, 3);
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
    //Type methodTy = asm.ktype["trmethodPtrTy"];
    //Value func = ConstantInt.get(asm.intTy, op.ftr);
    //func = asm.builder.CreateIntToPtr(func, methodTy);
    //Value vb = ConstantInt.get(asm.intTy, op.espidx);
    //vb = asm.builder.createGEP1(asm.sfp, vb);
    //Value rix = ConstantInt.get(asm.intTy, op.rix);
    //Value cid = ConstantInt.get(asm.intTy, op.cTBL);
    //Value[] vargs = [asm.ctx, vb, rix, cid];
    //if (op.inst0 != null) {
    //    asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), op.espidx, op.inst0.getLLVMValue(asm));
    //}
    //asm.builder.createCall(func, vargs);
    //Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.espidx + op.rix);
    //setLLVMValue(asm, v);
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String name = (to String) type;
    name = name.split(".")[1];
    asm.addSource("var " + getName() + " = new " + uscore(name) + ";", 3);
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    asm.addSource("var " + getName() + " = " + op.inst0.getName() + ".get(" + op.inst1.getName() + ");)", 3);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getName() + ".set(" + op.inst1.getName() + ", " + op.inst2.getName() + ");)", 3);
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    asm.addSource("var " + getName() + " = " + quote(op.const_table[op.table_idx]) + ";", 3);
}
@Public @Override void K_MOVx.codegen (Compiler asm) {
    asm.addSource("var " + getName() + " = " + op.inst0.getName() + ".field" + op.bn + ";", 3);
}
@Public @Override void K_xMOV.codegen(Compiler asm) {
    asm.addSource(op.inst0.getName() + ".field" + op.an + " = " + op.inst1.getName() + ";", 3);
}
@Public @Override void K_NEXT.codegen(Compiler asm) {
}
@Public @Override void K_LDMTD.codegen(Compiler asm) {
}
@Public @Override void K_ARGUMENT.codegen(Compiler asm) {
}
@Public @Override void K_RET.codegen(Compiler asm) {
    String res = "return";
    if (asm.retclass != null && op.inst0 != null) {
        res += " " + op.inst0.getName();
    }
    res += ";";
    asm.addSource(res, 3);
}

@Public void Compiler.emit(Method mtd) {
    if (!kfunc.curBB.hasReturn && kfunc.retTy == null) {
        K_RET inst = new K_RET(new K_RETop(null));
        kfunc.curBB.insts.add(inst);
        kfunc.curBB.hasReturn = true;
    }
    kfunc.codegen(this);
}
@Public void Compiler.init(Method mtd) {
    this.mtd = mtd;
    this.opt = new CompilerOpt();
    this.opt.init();
    this.kfunc = new K_Function(mtd);
}
@Public String Compiler.createKickFunc() {
    String res = "function " + TOP + " {" + EOL;
    boolean hasScr = false;
    foreach (fnc in this.opt.topLevelFunctionList) {
        if (fnc.indexOf("Script") != -1) {
            hasScr = true;
        }
    }
    if (hasScr) {
        res += "  script = new " + uscore("Script") + "();" + EOL;
    }
    foreach (fnc in this.opt.topLevelFunctionList) {
        res += "  " + fnc + "(";
        if (fnc.indexOf("Script") != -1) {
            res += "script";
        }
        res += ");" + EOL;
    }
    res += "}" + EOL;
    return res;
}
@Public void Compiler.dump(Boolean dump) {
    OUT << this.opt.topLevelFunctionList << EOL;
    foreach (str in this.opt.source) {
        OUT << str << EOL;
    }
    OUT << createKickFunc() << EOL;
}
