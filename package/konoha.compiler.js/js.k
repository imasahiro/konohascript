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
<!--
""";
String footer = """
// -->
</script>
<body onload="">
<script type="text/javascript">
<!--
konoha_main();
konoha.printOUT();
// -->
</script>
</body>
</html>
""";
TOP = "konoha_main()"
//class CompilerOpt {
//    int      indentLevel;
//    String   mtdName;
//    String[] source;
//    String[] unexpectedMethods;
//    String[] topLevelFunctionList;
//    String   obfuscatedClassName;
//    Map<String, String> varNameMap;
//    Map<String, String> methodNameMap;
//    Map<String, String> classNameMap;
//}
System.addClassField(CompilerOpt, String  , "mtdName");
System.addClassField(CompilerOpt, String[], "source");
System.addClassField(CompilerOpt, String[], "unexpectedMethods");
System.addClassField(CompilerOpt, String[], "topLevelFunctionList");
System.addClassField(CompilerOpt, Map<String, String>, "varNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "methodNameMap");
System.addClassField(CompilerOpt, Map<String, String>, "classNameMap");
@Public void CompilerOpt.init() {
    this.indentLevel = 0;
    this.source = [];
    this.unexpectedMethods = ["isNull"];
    this.topLevelFunctionList = [];
    this.varNameMap = {};
    this.methodNameMap = {};
    this.classNameMap = {};
}
class JSConfig {
    boolean use_obfuscate;
    boolean gen_html;
    JSConfig() {
        boolean b = "true" == $env.JS_USE_OBFUSCATE;
        boolean c = "true" == $env.JS_GEN_HTML;
        this.use_obfuscate = b;
        this.gen_html = c;
    }
}
JSConfig config = new JSConfig();

@Overload boolean isKonohaClass(String s) {
    return (s.startsWith("konoha") || s.startsWith("js"));
}
@Overload boolean isKonohaClass(Class c) {
    String s = (to String)c;
    return isKonohaClass(s);
}
@Public void Compiler.setIndentLevel(int n) {
    this.opt.indentLevel = n;
}
@Public void Compiler.incIndentLevel() {
    this.opt.indentLevel = this.opt.indentLevel + 1;
}
@Public void Compiler.decIndentLevel() {
    this.opt.indentLevel = this.opt.indentLevel - 1;
}
@Public String K_Inst.declVar(Compiler asm) {
    if (getName() in? asm.opt.varNameMap) {
        return "";
    } else {
        return "var ";
    }
}
@Overload String obfuscateString(int size, int idx, char base, boolean needDoller) {
    int l = 'z' - 'a';
    int i = size, j = idx;
    Bytes b;
    if (needDoller) {
        b = new byte[i+1];
    } else {
        b = new byte[i];
    }
    int m = 0;
    for (int k = (needDoller) ? i : i-1; m < size; k--) {
        b[k] = base + j % (l+1);
        j /= (l+1);
        m++;
    }
    if (i > 1) {
        b[0] = b[0]-1;
    }
    if (needDoller) {
        b[0] = '$';
    }
    return b.decode();
}
@Overload String obfuscateString(int idx, char base, boolean needDoller) {
    int size = 1, j = idx;
    int l = 'Z' - 'A';
    while (j > l) {
        size++;
        j /= (l+1);
    }
    return obfuscateString(size, idx, base, needDoller);
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
    asm.opt.varNameMap.set(s, obfuscateString(i, varIdx, 'a', true));
    return asm.opt.varNameMap[s];
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
    opt.classNameMap[s] = obfuscateString(i, classIdx, 'A', false);
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
    if (s.startsWith("konoha.Func")) {
        return "konoha.Func";
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
    opt.methodNameMap.set(mtd.toString(), obfuscateString(i, mtdId, 'a', false));
}
@Public String Compiler.getMethodName(Method mtd) {
    if (isKonohaClass(mtd.getMethodClass()) && mtd.getMethodClass() != Script) {
        return mtd.getName();
    }
    if (((to String)mtd.getMethodClass()).endsWith("Script") && mtd.getName() == "") {
        int i = 1, j = |this.opt.topLevelFunctionList|;
        int l = 'z' - 'a';
        while (j > l) {
            i++;
            j /= (l+1);
        }
        return "_" + obfuscateString(i, |this.opt.topLevelFunctionList|, 'a', false);
    }
    String s = mtd.toString();
    if (!s in? opt.methodNameMap) {
        setMethodName(mtd);
    }
    return opt.methodNameMap[s];
}
@Public void Compiler.addSource(String str) {
    String tmp = "";
    for (int i = 0; i < opt.indentLevel; i++) {
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
        res = declVar(asm) + getVarName(asm) + " = " + insts[0].getVarName(asm) + ";";
        asm.addSource(res);
    }
}
@Public void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

@Public void K_Function.codegen(Compiler asm) {
    boolean flagPrototype = false;
    asm.opt.obfuscatedMethodName = asm.getMethodName(asm.mtd);
    asm.opt.obfuscatedClassName = asm.class2str((to String)asm.mtd.getMethodClass());
    String fncdef = "";
    String thisclass = asm.opt.obfuscatedClassName;
    if (isKonohaClass(asm.mtd.getMethodClass())) {
        flagPrototype = true;
        fncdef += uscore(thisclass) + "." + asm.opt.obfuscatedMethodName + " = function (";
    } else if (isStatic == 1 || ((to String)asm.mtd.getMethodClass()).endsWith("Script")) {
        if (asm.mtd.getName() == "") {
            int size = |asm.opt.topLevelFunctionList|;
            asm.opt.topLevelFunctionList.add(asm.opt.obfuscatedMethodName);
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            //fncdef += "function Script" + size + "(";
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        } else if (asm.mtd.getName() == "main") {
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            asm.opt.topLevelFunctionList.add(asm.opt.obfuscatedMethodName);
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        } else {
            fncdef += "function " + asm.opt.obfuscatedMethodName + "(";
            asm.opt.mtdName = asm.opt.obfuscatedMethodName;
        }
    } else {
        flagPrototype = true;
        fncdef += uscore(thisclass) + ".prototype." + asm.opt.obfuscatedMethodName + " = function (";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += funcargs[i].getVarName(asm);
        if (i != |funcargs|-1) {
            fncdef += ", ";
        }
    }
    fncdef += ") {" + EOL;
    asm.addFunc(fncdef);
    asm.setIndentLevel(1);
    if (isStatic == 0 && |funcargs| > 0) {
        asm.addSource("var " + funcargs[0].getVarName(asm) + " = this;");
    }
    boolean needSwitch = false;
    int count = 0;
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] != null) {
            count++;
            if (count == 2) {
                needSwitch = true;
                break;
            }
        }
    }
    //asm.addSource("'use strict';", 1);
    if (needSwitch) {
        asm.addSource("var " + LABEL + " = 0;");
        asm.addSource("while (true) {");
        asm.incIndentLevel();
        asm.addSource("switch (" + LABEL + ") {");
    }
    for (int i = 0; i < |bbs|; i++) {
        if (bbs[i] == null) continue;
        if (needSwitch) {
            asm.addSource("case " + i + ":");
            asm.incIndentLevel();
        }
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
          asm.addSource("break;");
        }
        if (needSwitch) {
            asm.decIndentLevel();
        }
    }
    if (needSwitch) {
        asm.addSource("}");
        asm.decIndentLevel();
        asm.addSource("}");
        asm.decIndentLevel();
    }
    asm.decIndentLevel();
    if (flagPrototype) {
        asm.addSource("};");
    } else {
        asm.addSource("}");
    }
}
@Public @Override void K_MOV.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_ADD.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " + " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_SUB.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " - " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_MUL.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " * " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_DIV.codegen(Compiler asm) {
    String res;
    if (this.type == Int) {
        res = declVar(asm) + getVarName(asm) + " = Math.floor(" + op.inst0.getVarName(asm) + " / " + op.inst1.getVarName(asm) + ");";
    } else {
        res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " / " + op.inst1.getVarName(asm) + ";";
    }
    asm.addSource(res);
}
@Public @Override void K_MOD.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " % " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_EQ.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " == " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_NEQ.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " != " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " < " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_GT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " > " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LTE.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " <= " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_GTE.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " >= " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_AND.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " & " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_OR.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " | " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_NOT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = !" + op.inst0.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_XOR.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " xor " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_SELECT.codegen(Compiler asm) {
    String res = "";
    res += declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " ? " + op.inst1.getVarName(asm) + " : " + op.inst2.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_LSFT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " << " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_RSFT.codegen(Compiler asm) {
    String res;
    res = declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + " >> " + op.inst1.getVarName(asm) + ";";
    asm.addSource(res);
}
@Public @Override void K_TCHECK.codegen(Compiler asm) {
    /* do not use */
}
@Public @Override void K_CAST.codegen(Compiler asm) {
    String tcid_str = (to String) op.tcid;
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource(declVar(asm) + getVarName(asm) + " = " + "Math" + ".floor(" + op.inst0.getVarName(asm) + ");");
    } else if (tcid_str.indexOf("konoha.Iterator") == 0) {
        asm.addSource(declVar(asm) + getVarName(asm) + " = new " + "konoha.Iterator" + "(" + op.inst0.getVarName(asm) + ");");
    } else {
        asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";");
    }
}
@Public @Override void K_JMP.codegen(Compiler asm) {
    asm.addSource(LABEL + " = " + op.jmpidx + ";");
}
@Public @Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if (" + op.inst0.getVarName(asm) + ") {");
    asm.incIndentLevel();
    asm.addSource(LABEL + " = " + op.bbThen + ";");
    asm.decIndentLevel();
    asm.addSource("} else {");
    asm.incIndentLevel();
    asm.addSource(LABEL + " = " + op.bbElse + ";");
    asm.decIndentLevel();
    asm.addSource("}");
}
@Public void K_CALL.genUnexpectedMethod(Compiler asm) {
    if (op.mtd.getName() == asm.opt.unexpectedMethods[0]) {
        asm.addSource(declVar(asm) + getVarName(asm) + " = " + args[0].getVarName(asm) + " == null;");
    }
}
@Public @Override void K_CALL.codegen(Compiler asm) {
    boolean flag = false;
    if (op.flagStatic == 0) {
        if (!args[0].kvalue.type.isUnboxType()) {
            flag = true;
        }
    }
    if (op.mtd.getName() in? asm.opt.unexpectedMethods) {
        genUnexpectedMethod(asm);
        return;
    }
    String res = "";
    if (op.mtd.getReturnType() != Void) {
        res = declVar(asm) + getVarName(asm) + " = ";
    }
    String thisclass = asm.mtdclass2str(op.mtd.toString());
    if (flag) {
        res += args[0].getVarName(asm) + ".";
    } else if (thisclass != "Script") {
        res += uscore(thisclass) + ".";
    }
    if (asm.getMethodName(op.mtd) == "new") {
        res += "_new";
    } else {
        res += asm.getMethodName(op.mtd).replace("%s", "send").replace(":", "_");
    }
    res += "(";
    int cur = flag ? 1 : 0;
    for (; cur < |args|; cur++) {
        res += args[cur].getVarName(asm);
        if (cur != |args|-1) {
            res += ", ";
        }
    }
    res += ");";
    asm.addSource(res);
}
@Public @Override void K_PRINT.codegen(Compiler asm) {
    int line = (op.opline&((1<<32)-1)<<32)>>32;
    String strline = "(" + asm.opt.mtdName + ":" + line + ") ";
    String msg = "";
    if (op.msg != "") {
        msg += op.msg + "=";
    }
    asm.addSource("konoha.OUT += \"" + strline + msg + "\" + " + op.inst0.getVarName(asm) + ".toString() + \"\\n\";");
}
@Public @Override void K_TR.codegen(Compiler asm) {
    String type_str = (to String)type;
    switch (this.getTRMethod()) {
        case "box":
            asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";");
            break;
        case "bnul":
            if (type_str.endsWith("Script")) {
                asm.addSource(declVar(asm) + getVarName(asm) + " = script;");
            }
            break;
        case "cwb":
            asm.addSource(declVar(asm) + getVarName(asm) + " = new konoha.OutputStream(true);");
            break;
        case "tostr":
            asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".tostr();");
            break;
        case "chktype":
            asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ";");
            break;
    }
}
@Public @Override void K_NEW.codegen(Compiler asm) {
    String name = asm.class2str((to String)type);
    asm.addSource(declVar(asm) + getVarName(asm) + " = new " + uscore(name) + "();");
}
@Public @Override void K_GETIDX.codegen(Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".get(" + op.inst1.getVarName(asm) + ");");
}
@Public @Override void K_SETIDX.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + ".set(" + op.inst1.getVarName(asm) + ", " + op.inst2.getVarName(asm) + ");");
}
@Public @Override void K_CONST.codegen(Compiler asm) {
    if (op.const_table[op.table_idx].class == Int || op.const_table[op.table_idx].class == Float || op.const_table[op.table_idx].class == Boolean) {
        asm.addSource(declVar(asm) + getVarName(asm) + " = " + quote(op.const_table[op.table_idx]) + ";");
    } else if (op.const_table[op.table_idx].class == Class) {
        asm.addSource(declVar(asm) + getVarName(asm) + " = new " + uscore("konoha.String") + "(" + quote(op.const_table[op.table_idx]) + ");");
    } else {
        asm.addSource(declVar(asm) + getVarName(asm) + " = new " + asm.class2str((to String)op.const_table[op.table_idx].class) + "(" + quote(op.const_table[op.table_idx]) + ");");
    }
}
@Public @Override void K_GetField.codegen (Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + "." + obfuscateString(op.bn, 'a', true) + ";");
}
@Public @Override void K_SetField.codegen(Compiler asm) {
    asm.addSource(op.inst0.getVarName(asm) + "." + obfuscateString(op.an, 'a', true) + " = " + op.inst1.getVarName(asm) + ";");
}
@Public @Override void K_NEXT.codegen(Compiler asm) {
    asm.addSource(declVar(asm) + getVarName(asm) + " = " + op.inst0.getVarName(asm) + ".next();");
    asm.addSource("if (" + getVarName(asm) + " != null) {");
    asm.incIndentLevel();
    asm.addSource(LABEL + " = " + op.nextBB + ";");
    asm.decIndentLevel();
    asm.addSource("} else {");
    asm.incIndentLevel();
    asm.addSource(LABEL + " = " + op.endBB + ";");
    asm.decIndentLevel();
    asm.addSource("}");
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
    asm.addSource(res);
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
@Public String Compiler.createMain() {
    String indent = "    ";
    String res = "";
    boolean flagScript = false;
    res += "function Script" + "() {" + EOL;
    res += "}" + EOL;
    res += EOL;
    res += "function " + TOP + " {" + EOL;
    res += indent + "script = new Script();" + EOL;
    foreach (fname in this.opt.topLevelFunctionList) {
        res += indent + fname + "(";
        res += "script";
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
            res += "    " + "this." + obfuscateString(i, 'a', true) + " = 0;";
        } else {
            res += "    " + "this." + obfuscateString(i, 'a', true) + " = null;";
        }
        res += EOL;
        i++;
    }
    res += "}" + EOL;
    return res;
}
@Public void Compiler.dump(Boolean dump) {
    String output = $script.output;
    OutputStream ous;
    if (output != null) {
        ous = new OutputStream(output);
    } else {
        ous = OUT;
    }
    if ((config.gen_html) == true) {
        ous << header << EOL + EOL;
    }
    foreach (K_Class kc in this.declareclass) {
        String cname = class2str((to String)kc.c);
        ous << createClassDefinition(kc.c, cname) << EOL;
    }
    foreach (str in this.opt.source) {
        ous << str << EOL;
    }
    ous << createMain() << EOL;
    if ((config.gen_html) == true) {
        ous << footer;
    }
    ous.close();
}
