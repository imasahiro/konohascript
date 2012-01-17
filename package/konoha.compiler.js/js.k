String header = """
<html>
<head>
<title>sample</title>
</head>
<script type="text/javascript" language="javascript" src="./konoha.js" > </script>
<script type="text/javascript" language="javascript" src="./konoha.math.js" > </script>
<script type="text/javascript" language="javascript" src="./js.js" > </script>
<script type="text/javascript" language="javascript" src="./js.dom.js" > </script>
<script type="text/javascript" language="javascript" src="./js.jquery.js" > </script>
<script type="text/javascript">
<!--""";
String footer = """
// -->
</script>
<body onLoad=" topLevelFunc() ">
</body>
</html>""";
TOP = "topLevelFunc()"
//class CompilerOpt {
//    String   mtdName;
//    String[] source;
//    String[] topLevelFunctionList;
//    String   obfuscatedClassName;
//    String   obfuscatedMethodName;
//    Map<String, String> varNameMap;
//    Map<String, String> methodNameMap;
//    Map<String, String> classNameMap;
//}
System.addClassField(CompilerOpt, String  , "mtdName");
System.addClassField(CompilerOpt, String[], "source");
System.addClassField(CompilerOpt, String[], "topLevelFunctionList");
System.addClassField(CompilerOpt, Map<String, String>, "varNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "methodNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "classNameMap");
@Public void CompilerOpt.init() {
    this.source = [];
    this.topLevelFunctionList = [];
    this.varNameMap = {};
    this.methodNameMap = {};
    this.classNameMap = {};
}
@Overload boolean isKonohaClass(String s) {
    return (s.startsWith("konoha") || s.startsWith("js") || s.endsWith("Script"));
}
@Overload boolean isKonohaClass(Class c) {
    String s = (to String)c;
    return isKonohaClass(s);
}
@Public @Overload String K_Inst.getVarName(Compiler asm) {
    String s = getName();
    if (asm.opt.varNameMap[s] != null) {
        return asm.opt.varNameMap[s];
    }
    Array<String> keys = asm.opt.varNameMap.keys();
    int i = 1, j, varIdx = |keys|;
    j = varIdx;
    int l = 'Z' - 'A';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    Bytes b = new byte[i+1];
    j = varIdx;
    for (int k = i-1; k >= 0; k--) {
        b[k] = 'a' + j % (l+1);
        j /= (l+1);
    }
    if (i > 1) {
        b[0] = b[0]-1;
    }
    b[i] = '_';
    asm.opt.varNameMap.set(s, b.decode());
    return b.decode();
}
@Public void Compiler.setUserClassName(String s) {
    int i = 1, j, classIdx = 0;
    Array<String> keys = opt.classNameMap.keys();
    for (; classIdx < |keys|; classIdx++) {
        if (s == keys[classIdx]) {
            break;
        }
    }
    j = classIdx;
    int l = 'Z' - 'A';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    Bytes b = new byte[i];
    j = classIdx;
    for (int k = i-1; k >= 0; k--) {
        b[k] = 'A' + j % (l+1);
        j /= (l+1);
    }
    if (i > 1) {
        b[0] = b[0]-1;
    }
    opt.classNameMap[s] = b.decode();
}
@Public String Compiler.getUserClassName(String s) {
    if (opt.classNameMap[s] == null) {
        setUserClassName(s);
    }
    return opt.classNameMap[s];
}
@Public String Compiler.class2str(String s) {
    if (s.endsWith("Script")) {
        return "Script";
    }
    if (s.startsWith("konoha.Array")) {
        return "konoha.Array";
    }   
    if (s.startsWith("konoha.Map")) {
        return "konoha.Map";
    }   
    if (s.startsWith("konoha.Iterator")) {
        return "konoha.Iterator";
    }
    String[] ary = s.split(".");
    if (|ary| >= 2 && isKonohaClass(s)) {
        String res = "";
        for (int i = 0; i < |ary|; i++) {
            res += ary[i];
            if (i != |ary|-1) {
                res += ".";
            }
        }
        return res;
    } else {
        return getUserClassName(ary[|ary|-1]);
    }
}

@Public String Compiler.mtdclass2str(String s) {
    return class2str(s[0 to s.lastIndexOf(".")-1]);
}
String getTypeName (Class type) {
    String res = (to String) type;
    return (res == "") ? "null" : res;
}
String uscore(String in) {
    //return "__" + in + "__";
    //return "konoha." + in;
    return in;
}
LABEL = "label";
@Public void Compiler.setMethodName(Method mtd) {
    int mtdId = 0;
    Array<Method> mtds = mtd.getMethodClass().getMethods();
    for (; mtdId < |mtds|; mtdId++) {
        if (mtd == mtds[mtdId]) {
            break;
        }
    }
    Class c = mtd.getMethodClass();
    while (!isKonohaClass(c.getSuper())) {
        c = c.getSuper();
        mtdId = mtdId + |c.getMethods()|;
    }
    int i = 1, j = mtdId;
    int l = 'z' - 'a';
    while (j > l) {
        i++;
        j /= (l+1);
    }
    Bytes b = new byte[i];
    j = mtdId;
    for (int k = i-1; k >= 0; k--) {
        b[k] = 'a' + j % (l+1);
        j /= (l+1);
    }
    if (i > 1) {
        b[0] = b[0]-1;
    }
    opt.methodNameMap.set(mtd.toString(), b.decode());
}
@Public String Compiler.getMethodName(Method mtd) {
    String s = mtd.toString();
    if (!s in? opt.methodNameMap) {
        setMethodName(mtd);
    }
    return opt.methodNameMap[s];
}
@Public void Compiler.addSource(String str, int count) {
    String tmp = "";
    for (int i = 0; i < count; i++) {
        tmp += "    ";
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
        res = "var " + getVarName(asm) + " = " + insts[0].getVarName(asm) + ";";
        asm.addSource(res, 2);
    }
}
@Public void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

@Public void K_Function.codegen(Compiler asm) {
    asm.getMethodName(asm.mtd);
    if (!isKonohaClass(asm.mtd.getMethodClass())) {
        asm.opt.obfuscatedClassName = asm.class2str((to String)asm.mtd.getMethodClass());
    }
    String fncdef = "";
    String thisclass = asm.opt.obfuscatedClassName;
    if (isStatic == 1 || thisclass == "Script") {
        if (asm.mtd.getName() == "") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add("Script" + size);
            fncdef += "function Script" + size + "(";
            asm.opt.mtdName = "Script";
        } else if (asm.mtd.getName() == "main") {
            fncdef += "function " + asm.mtd.getName() + "(";
            asm.opt.topLevelFunctionList.add("main");
            asm.opt.mtdName = asm.mtd.getName();
        } else {
            fncdef += "function " + asm.mtd.getName() + "(";
            asm.opt.mtdName = asm.mtd.getName();
        }
    } else {
        fncdef += uscore(thisclass) + ".prototype." + asm.mtd.getName() + " = function(";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += funcargs[i].getVarName(asm);
        if (i != |funcargs|-1) {
            fncdef += ", ";
        }
    }
    fncdef += ") {" + EOL;
    asm.addFunc(fncdef);
    if (isStatic == 0 && |funcargs| > 0) {
        asm.addSource("var " + funcargs[0].getVarName(asm) + " = this;", 1);
    }
    //asm.addSource("'use strict';", 1);
    asm.addSource("var " + LABEL + " = 0;", 1);
    asm.addSource("while (true) switch (" + LABEL + ") {", 1);
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null) continue;
        asm.addSource("case " + i + ":", 1);
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
        if (bbs[i].insts[|bbs[i].insts|-1].class != K_RET) {
          asm.addSource("break;", 2);
        }
    }
    asm.addSource("}", 1);
    asm.addSource("}", 0);
}
@Public @Override void K_MOV.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_ADD.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " + " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " - " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " * " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " / " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " % " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " == " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " != " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_LT.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " < " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_GT.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " > " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " <= " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " >= " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_AND.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " & " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_OR.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " | " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = !" + op.inst0.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " xor " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    String res = "";
    res += "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " ? " + op.inst1.getVarName(asm) + " : " + op.inst2.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " << " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " >> " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res, 2);
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    /* do not use */
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    String tcid_str = (to String) op.tcid;
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource("var " + getVarName(asm) + " = " + "Math" + ".floor(" + op.inst0.getVarName(asm) + ");", 2);
    } else if (tcid_str.indexOf("konoha.Iterator") == 0) {
        asm.addSource("var " + getVarName(asm) + " = new " + "konoha.Iterator" + "(" + op.inst0.getVarName(asm) + ");", 2);
    } else {
        asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";", 2);
    }
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.addSource(LABEL + " = " + op.jmpidx + ";", 2);
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if (" + op.inst0.getVarName(asm) + ") {", 2);
    asm.addSource(LABEL + " = " + op.bbThen + ";", 3);
    asm.addSource("} else {", 2);
    asm.addSource(LABEL + " = " + op.bbElse + ";", 3);
    asm.addSource("}", 2);
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
        res = "var " + getVarName(asm) + " = ";
    }
    String thisclass = asm.mtdclass2str(op.mtd.toString());
    if (flag) {
        res += args[0].getVarName(asm) + ".";
    } else if (thisclass != "Script") {
        res += uscore(thisclass) + ".";
    }
    res += op.mtd.getName().replace("%s", "send").replace(":", "_") + "(";
    int cur = flag ? 1 : 0;
    for (; cur < |args|; cur++) {
        res += args[cur].getVarName(asm);
        if (cur != |args|-1) {
            res += ", ";
        }
    }
    res += ");";
    asm.addSource(res, 2);
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    int line = (op.opline&((1<<32)-1)<<32)>>32;
    String strline = "(" + asm.opt.mtdName + ":" + line + ") ";
    String msg = "";
    if (op.msg != "") {
        msg += op.msg + "=";
    }
    asm.addSource("document.write(\"" + strline + msg + "\" + " + op.inst0.getVarName(asm) + ".toString() + \"<br>\");", 2);
}
@Public @Override void K_TR.codegen(Compiler asm) {
    String type_str = (to String)type;
    switch (this.getTRMethod()) {
        case "box":
            asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";", 2);
            break;
        case "bnul":
            if (type_str.endsWith("Script")) {
                asm.addSource("var " + getVarName(asm) + " = script;", 2);
            }
            break;
        case "cwb":
            asm.addSource("var " + getVarName(asm) + " = new konoha.OutputStream(true);", 2);
            break;
        case "tostr":
            asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".tostr();", 2);
            break;
        case "chktype":
            asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";", 2);
            break;
    }
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String name = asm.class2str((to String)type);
    asm.addSource("var " + getVarName(asm) + " = new " + uscore(name) + "();", 2);
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".get(" + op.inst1.getVarName(asm) + ");", 2);
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + ".set(" + op.inst1.getVarName(asm) + ", " + op.inst2.getVarName(asm) + ");", 2);
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    if (this.type == Int || this.type == Float || this.type == Boolean) {
        asm.addSource("var " + getVarName(asm) + " = " + quote(op.const_table[op.table_idx]) + ";", 2);
    } else if (this.type == Class) {
        asm.addSource("var " + getVarName(asm) + " = new " + uscore("konoha.String") + "(" + quote(op.const_table[op.table_idx]) + ");", 2);
    } else {
        asm.addSource("var " + getVarName(asm) + " = new " + asm.class2str((to String)this.type) + "(" + quote(op.const_table[op.table_idx]) + ");", 2);
    }
}
@Public @Override void K_GetField.codegen (Compiler asm) {
    asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".field" + op.bn + ";", 2);
}
@Public @Override void K_SetField.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + ".field" + op.an + " = " + op.inst1.getVarName(asm) + ";", 2);
}
@Public @Override void K_NEXT.codegen(Compiler asm) {
    asm.addSource("var " + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".next();", 2);
    asm.addSource("if (" + getVarName(asm) + " != null) {", 2);
    asm.addSource(LABEL + " = " + op.nextBB + ";", 3);
    asm.addSource("} else {", 2);
    asm.addSource(LABEL + " = " + op.endBB + ";", 3);
    asm.addSource("}", 2);
}
@Public @Override void K_LDMTD.codegen(Compiler asm) {
}
@Public @Override void K_ARGUMENT.codegen(Compiler asm) {
}
@Public @Override void K_RET.codegen(Compiler asm) {
    String res = "return";
    if (asm.retclass != null && op.inst0 != null) {
        res += " " + op.inst0.getVarName(asm);
    }
    res += ";";
    asm.addSource(res, 2);
}

@Public void Compiler.emit(Method mtd) {
    common_emit(mtd);
    kfunc.codegen(this);
}
@Public void Compiler.init(Method mtd) {
    init_common(mtd);
    if (this.opt == null) {
        this.opt = new CompilerOpt();
        this.opt.init();
    }
    this.opt.getVarNameMap = {};
}
@Public String Compiler.createKickFunc() {
    String res = "";
    boolean flagScript = false;
    res += "function Script" + "() {" + EOL;
    //res += "    'use strict';" + EOL;
    res += "}" + EOL;
    res += EOL;
    res += "function " + TOP + " {" + EOL;
    //res += "    'use strict';" + EOL;
    res += "    script = new Script();" + EOL;
    foreach (fnc in this.opt.topLevelFunctionList) {
        res += "    " + fnc + "(";
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
