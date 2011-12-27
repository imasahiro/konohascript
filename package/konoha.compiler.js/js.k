using konoha.math.*;
String header = """
<html>
<head>
<title>sample</title>
</head>
<script type="text/javascript" language="javascript" src="./konoha.js" > </script>
<script type="text/javascript" language="javascript" src="./math.js" > </script>
<script type="text/javascript" language="javascript" src="./window.js" > </script>
<script type="text/javascript">
<!--""";
String footer = """
// -->
</script>
<body onLoad=" __topLevelFunc__() ">
</body>
</html>""";
TOP = "__topLevelFunc__()"
//class CompilerOpt {
//    String[] source;
//    String[] topLevelFunctionList;
//}
System.addClassField(CompilerOpt, String[], "source");
System.addClassField(CompilerOpt, String[], "topLevelFunctionList");
@Public void CompilerOpt.init() {
    this.source = [];
    this.topLevelFunctionList = [];
}

String mtdclass2str(String s) {
    return s.split(".")[|s.split(".")|-2];
}
String class2str(String s) {
    if (s.startsWith("konoha.Array")) {
        return "Array";
    }   
    if (s.startsWith("konoha.Map")) {
        return "Map";
    }   
    if (s.startsWith("konoha.Iterator")) {
        return "Iterator";
    }   
    if (s.indexof(".") != -1) {
        s = s.split(".")[|s.split(".")|-1];
    }   
    return s;
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
    /* if one node incoming, this phinode behave like K_MOV instruction*/
    if (|bbs| == 1) {
        String res;
        res = "var " + getName() + " = " + insts[0].getName() + ";";
        asm.addSource(res, 3);
    }
}
@Public void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

@Public void K_Function.codegen(Compiler asm) {
    String fncdef = "";
    String thisclass = mtdclass2str(asm.mtd.toString());
    if (isStatic == 1 || thisclass == "Script") {
        if (asm.mtd.getName() == "") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add("Script" + size);
            fncdef += "function Script" + size + "(";
        } else if (asm.mtd.getName() == "main") {
            fncdef += "function " + asm.mtd.getName() + "(";
            asm.opt.topLevelFunctionList.add("main");
        } else {
            fncdef += "function " + asm.mtd.getName() + "(";
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
        if (bbs[i] == null) continue;
        asm.addSource("case " + i + ":", 2);
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
        asm.addSource("break;", 2);
    }
    asm.addSource("}", 1);
    asm.addSource("}", 0);
}
@Public @Override void K_MOV.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + ";";
    asm.addSource(res, 3);
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
    res += "var " + getName() + " = " + op.inst0.getName() + " ? " + op.inst1.getName() + " : " + op.inst2.getName() + ";";
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
    String tcid_str = (to String) op.tcid;
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource("var " + getName() + " = " + uscore("Math") + ".floor(" + op.inst0.getName() + ");", 3);
    } else if (tcid_str.indexOf("konoha.Iterator") == 0) {
        asm.addSource("var " + getName() + " = new " + uscore("Iterator") + "(" + op.inst0.getName() + ");", 3);
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
    String thisclass = mtdclass2str(op.mtd.toString());
    if (flag) {
        res += args[0].getName() + ".";
    } else if (thisclass != "Script") {
        res += uscore(thisclass) + ".";
    }
    res += op.mtd.getName().replace("%s", "send").replace(":", "_") + "(";
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
    switch (this.getTRMethod()) {
        case "box":
            asm.addSource("var " + getName() + " = " + op.inst0.getName() + ";", 3);
            break;
        case "bnul":
            if (type == Script) {
                asm.addSource("var " + getName() + " = script;", 3);
            }
            break;
        case "cwb":
            asm.addSource("var " + getName() + " = new __OutputStream__(true);", 3);
            break;
        case "tostr":
            asm.addSource("var " + getName() + " = " + op.inst0.getName + ".tostr();", 3);
            break;
    }
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String name = class2str((to String)type);
    asm.addSource("var " + getName() + " = new " + uscore(name) + "();", 3);
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    asm.addSource("var " + getName() + " = " + op.inst0.getName() + ".get(" + op.inst1.getName() + ");", 3);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getName() + ".set(" + op.inst1.getName() + ", " + op.inst2.getName() + ");", 3);
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    if (this.type == Int || this.type == Float || this.type == Boolean) {
        asm.addSource("var " + getName() + " = " + quote(op.const_table[op.table_idx]) + ";", 3);
    } else if (this.type == Class) {
        asm.addSource("var " + getName() + " = new " + uscore("String") + "(" + quote(op.const_table[op.table_idx]) + ");", 3);
    } else {
        asm.addSource("var " + getName() + " = new " + uscore(class2str((to String)this.type)) + "(" + quote(op.const_table[op.table_idx]) + ");", 3);
    }
}
@Public @Override void K_MOVx.codegen (Compiler asm) {
    asm.addSource("var " + getName() + " = " + op.inst0.getName() + ".field" + op.bn + ";", 3);
}
@Public @Override void K_xMOV.codegen(Compiler asm) {
    asm.addSource(op.inst0.getName() + ".field" + op.an + " = " + op.inst1.getName() + ";", 3);
}
@Public @Override void K_NEXT.codegen(Compiler asm) {
    asm.addSource("var " + getName() + " = " + op.inst0.getName() + ".next();", 3);
    asm.addSource("if (" + getName() + " != null) {", 3);
    asm.addSource(LABEL + " = " + op.nextBB + ";", 4);
    asm.addSource("} else {", 3);
    asm.addSource(LABEL + " = " + op.endBB + ";", 4);
    asm.addSource("}", 3);
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
    common_emit(mtd);
    kfunc.codegen(this);
}
@Public void Compiler.init(Method mtd) {
    common_init(mtd);
    if (this.opt == null) {
        this.opt = new CompilerOpt();
        this.opt.init();
    }
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
        res += "function " + uscore("Script") + "() {" + EOL;
        res += "}" + EOL;
        res += EOL;
    }
    res += "function " + TOP + " {" + EOL;
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
@Public String Compiler.createClassDefinition(Class c, String cname) {
    String res = "";
    if (c.getSuper() != Object) {
        String supcname = class2str((to String)c.getSuper());
        res += uscore(cname) + ".prototype = new " + uscore(supcname) + "()" + EOL;
    }
    res += "function " + uscore(cname) + "() {" + EOL;
    int i = 0;
    foreach (Class fieldclass in c.getFieldClasses()) {
        if (fieldclass.isUnboxType()) {
            res += "  " + "this.field" + i + " = 0;";
        } else {
            res += "  " + "this.field" + i + " = null;";
        }
        res += EOL;
        i++;
    }
    res += "}" + EOL;
    return res;
}
@Public void Compiler.dump(Boolean dump) {
    OUT << header << EOL + EOL;
    foreach (K_Class kc in this.declareclass) {
        String cname = class2str((to String)kc.c);
        OUT << createClassDefinition(kc.c, cname) << EOL;
    }
    foreach (str in this.opt.source) {
        OUT << str << EOL;
    }
    OUT << createKickFunc() << EOL;
    OUT << footer;
}
