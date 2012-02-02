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

using konoha.lang.*;
using konoha.llvm.*;
/* XXX
 * To avoid konoha runtime class loader bug.
 */
using konoha.math.*;
include "lib:gluelink";

DEBUG = false;
//USE_NONSSA = false;
USE_NONSSA = true;
//DEBUG = true;
FUNC_STATIC = 0;
FUNC_FASTCALL = 2;
K_MTDIDX2 = -1;
K_RTNIDX = -4;
K_CALLDELTA = 4;
FLAG_OBJECT_NULLOBJECT = 1 << 1;
KFLAG_PF_BOL       = (1<<1);
KFLAG_PF_TIME      = (1<<2);
KFLAG_PF_NAME      = (1<<3);
KFLAG_PF_EOL       = (1<<4);
KFLAG_PF_NCOMMA    = (1<<5);
KFLAG_PF_LINE      = (1<<6);
KFLAG_PF_BREAK     = (1<<7);

NOT_SCAST = -1;
SHANEIR_ENABLE_FUNCTION_DUMP=true;

@Native @public void Method.setLazycompile();

@public boolean Class.isUnboxType() {
    if (this == Int) {
        return true;
    }
    if (this == Float) {
        return true;
    }
    if (this == Boolean) {
        return true;
    }
    return false;
}
String escape(String str) {
    str = str.replace("\t", "\\t");
    str = str.replace("\n", "\\n");
    return str;
}

class K_BasicBlock;
class K_Function;
class Compiler;
void K_Function.init(Compiler asm);
class K_Inst;
class K_Class;
@Expando class CompilerOpt {};
class Compiler {
    String[] ir;
    Array<dynamic> const_table;
    Method    mtd;
    BasicBlock entryBB;
    Class[] paramsclass;
    Class   retclass;
    K_Function kfunc;
    Method[] system_method;
    Class[] system_method_class;
    K_Class[] declareclass;
    int isCWB;
    K_Inst cwb;
    Map<String, K_Function[]> compiled_methods;
    CompilerOpt opt;

    Map<String, Type> user_type;
    Compiler() {
        init_first();
    }
    void init_first() {
        ir = [];
        const_table = [];
        declareclass = [];
        Method mtd_in, mtd_out, mtd_err;
        Method[] mtds = System.getMethods();
        foreach (Method m in mtds) {
            if (m.getName == "getIn")
                mtd_in = m;
            if (m.getName == "getOut")
                mtd_out = m;
            if (m.getName == "getErr")
                mtd_err = m;
        }

        this.system_method = [
            null, /*CTX*/
            mtd_in,
            mtd_out,
            mtd_err,
            mtd_in,
            mtd_out,
            mtd_err,
            null, /*SYS*/,
            null, /*SCRIPT*/
            ];
        this.system_method_class = [
            null, /*CTX*/
            null, /*CTXIN*/
            OutputStream/*OutputSteram*/,
            OutputStream/*OutputSteram*/,
            null,
            OutputStream/*OutputSteram*/,
            OutputStream/*OutputSteram*/,
            null, /*SYS*/,
            null, /*SCRIPT*/
            ];
        this.compiled_methods = {};
        this.user_type = {};
    }
};
@Native void Compiler.getCurrentUline();

String getTypeName(Class type) {
    String res = (to String) type;
    if (res == "") {
        return "null";
    }
    else {
        return res;
    }
}

class K_Value {
    int idx; //sfp[idx]
    int defCount;
    int useCount;
    Class type;
    Array<Int> defPoint;
    Array<Int> usePoint;
    K_Value (int idx, Class type) {
        this.idx = idx;
        this.type = type;
        defPoint = [];
        usePoint = [];
    }
}
class K_Opcode {
    K_Inst inst0, inst1, inst2;
}

class K_Inst {
    K_Value kvalue;
    Class type;
    Value value;
    dynamic opt;
    int defidx;
    int uline;
    Array<Int> declPoint;
    String attribute;

    /*for callInst*/
    Array<K_Inst> args;
    /*for dump const_value*/
    String dynName;
    void init_kvalue(K_Value v, Class c) {
        this.opt = null;
        this.kvalue = v;
        if (c == null) {
            c = v.type;
        }
        this.type   = c;
        this.uline  = Compiler.getCurrentUline();
    }

    @Virtual void codegen(Compiler asm) {
        throw new Exception();
        print "**********";
    }
    @Virtual String dump () {
        throw new Exception();
        return null;
    }
    void addDeclPoint(int bbidx) {
        if (declPoint == null) {
            declPoint = [bbidx];
        } else if (declPoint.indexOf(bbidx) == -1) {
            declPoint.add(bbidx);
        }
    }
    void addDef(K_Value kvalue, int bbidx) {
        addDeclPoint(bbidx);
        if (kvalue != null) {
            if (true || kvalue.defPoint.indexOf(bbidx) == -1) {
                defidx = kvalue.defCount;
                kvalue.defCount = defidx + 1;
                kvalue.defPoint.add(bbidx);
            }
        }
    }
    void addUse(K_Opcode op, int bbidx) {
        if (op.inst0 != null && op.inst0.kvalue != null) {
            K_Value v = op.inst0.kvalue;
            op.inst0.addDeclPoint(bbidx);
            if (true || v.usePoint.indexOf(bbidx) == -1) {
                v.useCount = v.useCount + 1;
                v.usePoint.add(bbidx);
            }
        }
        if (op.inst1 != null && op.inst1.kvalue != null) {
            K_Value v = op.inst1.kvalue;
            op.inst1.addDeclPoint(bbidx);
            if (true || v.usePoint.indexOf(bbidx) == -1) {
                v.useCount = v.useCount + 1;
                v.usePoint.add(bbidx);
            }
        }
        if (op.inst2 != null && op.inst2.kvalue != null) {
            K_Value v = op.inst2.kvalue;
            op.inst2.addDeclPoint(bbidx);
            if (true || v.usePoint.indexOf(bbidx) == -1) {
                v.useCount = v.useCount + 1;
                v.usePoint.add(bbidx);
            }
        }
        if (args != null) {
            foreach (K_Inst inst in args) {
                K_Value v = inst.kvalue;
                if (v != null && (true || v.usePoint.indexOf(bbidx) == -1)) {
                    v.useCount = v.useCount + 1;
                    v.usePoint.add(bbidx);
                }
            }
        }
    }
    @Overload String getName() {
        String res = "";
        String str_type = "";
        Class type = kvalue.type;
        String prefix = "";
        /* const value (not named) */
        if (kvalue == null) {
            return dynName;
        }
        str_type += type;
        if (type == Int) {
            prefix = "ival";
        } else if (type == Float) {
            prefix = "fval";
        } else if (type == Boolean) {
            prefix = "bval";
        } else if (type == Array || str_type.indexOf("konoha.Array") == 0) {
            prefix = "aval";
        } else if (type == Map || str_type.indexOf("konoha.Map") == 0) {
            prefix = "map";
        } else if (type == Func || str_type.indexOf("konoha.Func") == 0) {
            prefix = "fnc";
        } else if (type == Iterator || str_type.indexOf("konoha.Iterator") == 0) {
            prefix = "itr";
        } else if (type == String) {
            prefix = "str";
        } else if (type == dynamic) {
            prefix = "dyn";
        } else if (type == OutputStream) {
            prefix = "ous";
        } else if (type == InputStream) {
            prefix = "ins";
        } else if (type == Script) {
            prefix = "script";
        } else if (type == Namespace) {
            prefix = "ns";
        } else if (type == Object) {
            prefix = "obj";
        } else {
            a = ((to String)type).split(".");
            prefix = a[a.size-1];
        }
        res = prefix + kvalue.idx + "_" + defidx;
        res = res.convert(to:lower);
        return res;
    }
}
class K_MOVop extends K_Opcode {
    int defcount;
    K_MOVop(K_Inst inst0, int defcount) {
        this.inst0 = inst0;
        this.defcount = defcount;
    }
}
class K_MOV extends K_Inst {
    int idx;
    K_MOVop op;
    K_MOV(K_Value kvalue, K_MOVop op, int bbidx) {
        init_kvalue(kvalue);
        this.defidx = op.defcount;
        this.op = op;
        this.idx = idx;
    }
    @Override String dump() {
        return "\t" + getName() + " = mov " + getTypeName(type) + " " + op.inst0.getName() + " @nonssa";
    }
}
K_Value K_Function.getKValue(int idx, Class type);
class K_PHI extends K_Inst {
    int idx;
    Array<Int> bbs;
    Array<K_Inst> insts;
    K_PHI(int idx) {
        init_kvalue(null);
        idx = idx;
        bbs = [];
        insts = [];
    }
    void addIncoming(K_Function kfunc, int idx, K_Inst inst, int bbidx, Array<K_MOV> movs) {
        if (this.kvalue == null) {
            init_kvalue(inst.kvalue);
            this.type = inst.type;
            addDef(kvalue, idx);
        }
        //if (this.type.isUnboxType()) {
            if (USE_NONSSA) {
                K_MOV mov = new K_MOV(this.kvalue, new K_MOVop(inst, this.defidx), bbidx);
                movs.add(mov);
                mov.addDeclPoint(bbidx);
                inst.addDeclPoint(bbidx);
            }
        //}
        //if (inst != null && inst.kvalue != null) {
        //    if (true || inst.kvalue.usePoint.indexOf(idx) == -1) {
        //        inst.kvalue.useCount = inst.kvalue.useCount + 1;
        //        inst.kvalue.usePoint.add(idx);
        //    }
        //}
        bbs.add(bbidx);
        insts.add(inst);
    }
    @Override String dump() {
        String res = "";
        if (getName() == insts[0].getName()) {
            return null;
        }
        if (bbs.size == 1) {
            res += "\t" + getName () + " = mov " + getTypeName(type) + " " + insts[0].getName();
        } else {
            res += "\t" + getName () + " = phi [";
            for (int i = 0; i < bbs.size; i++) {
                res += "[" + insts[i].getName() + ", bb" + bbs[i] + "], ";
            }
            res = res[0 to res.size-3] + "]";
        }
        return res;
    }
}

class K_BasicBlock {
    int bbidx;
    BasicBlock bb;
    boolean hasReturn;
    boolean hasBrBreakBlock;
    boolean hasBrContinueBlock;
    Array<K_Inst> insts;
    Array<K_Inst> insts_safepoint;
    Map<String, K_PHI> phis;
    Array<K_MOV> movs;
    int safepoint;
    String attribute;
    K_BasicBlock (int bbidx, String attribute) {
        hasReturn = false;
        hasBrBreakBlock = false;
        hasBrContinueBlock = false;
        this.phis = {};
        this.movs = [];
        this.insts = [];
        this.insts_safepoint = [];
        this.bbidx = bbidx;
        this.safepoint = -1;
        this.attribute = attribute;
    }
}
class K_ARGUMENTop extends K_Opcode {
    int argidx;
    boolean inner;
    K_ARGUMENTop(int argidx) {
        this.inner = true;
        this.argidx = argidx;
    }
}
class K_ARGUMENT extends K_Inst {
    K_ARGUMENTop op;
    K_ARGUMENT(K_Value kvalue, K_ARGUMENTop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        addDef(kvalue, bb.bbidx);
    }
}
class K_Function {
    Method mtd;
    K_BasicBlock[] bbs;
    Class[] declareclass_func;
    Array<dynamic> const_table;
    Array<K_Inst> register_table;
    Array<K_BasicBlock> breakpoint;
    Array<K_BasicBlock> continuepoint;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> breakList;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> continueList;
    Class retTy;
    K_ARGUMENT[] funcargs;
    K_Inst retval;
    Map<String, K_Value> value_table;
    boolean undeveloped;
    boolean hasReturn;
    int isStatic;

    /*for SSA*/
    /*
    Int[][] linklist;
    Int[][] succ;
    Int[][] pred;
    Int[][] bucket;
    Int[][] aorig;
    Int[][] defsites;
    Int[][] phi; //phi_value[bbidx] => Array<idx>
    Int[]   dfnum;
    Int[]   vertex;
    Int[]   semi;
    Int[]   parent;
    Int[]   ancestor;
    Int[]   best;
    Int[]   idom;
    Int[]   samedom;
    Int[]   df;
    */
    K_BasicBlock curBB;
    String mtdName;
    Function func;
    Function wfunc;

    K_Function(Method mtd) {
        this.mtd = mtd;
        this.declareclass_func = [];
        this.undeveloped = false;
        this.hasReturn = false;
        if (mtd.isStatic()) {
            isStatic = 1;
        } else {
            isStatic = 0;
        }
        this.mtdName = mtd.toString();
        this.bbs = [new K_BasicBlock(0)];
        this.curBB = bbs[0];
        this.breakpoint = [];
        this.continuepoint = [];
        this.breakList = [];
        this.continueList = [];
        Class[] params = mtd.getParamTypes();
        this.retTy = mtd.getReturnType();
        this.const_table = [];
        this.register_table = [];
        this.funcargs = [];
        this.value_table = {};
        /* SSA
        this.succ = [];
        this.pred = [];
        this.bucket = [];
        this.aorig = [];
        this.defsites = [];
        this.phi = [];
        this.dfnum = [];
        this.vertex = [];
        this.semi = [];
        this.parent = [];
        this.ancestor = [];
        this.best = [];
        this.idom = [];
        this.samedom = [];
        this.df = [];
        */
    }
    void addClass(Class c) {
        String cname = (to String)c;
        while (c != null && cname.indexOf("Script") == -1 && !cname.startsWith("konoha.") && !cname.startsWith("js.") && declareclass_func.indexOf(c) == -1  && cname != "dynamic") {
            declareclass_func.add(c);
            c = c.getSuper();
            cname = (to String)c;
        }
    }
    void setUndevelop() {
        //undeveloped = true;
    }
    void codegen(Compiler asm);
    int addConstTable(dynamic val) {
        // TODO(imasahiro) remove duplicated const value
        //if (!(val in? const_table)) {
        //    const_table.add(val);
        //}
        const_table.add(val);
        return const_table.size-1;
    }
    void dumpConstTable() {
        for (int i = 0; i < const_table.size; i++) {
            print const_table[i];
        }
    }
    String dump() {
        String res = "";
        String fname = mtdName[mtdName.indexOf(".")+1 to |mtdName|-1];
        String rtype = getTypeName(retTy);
        if (isStatic == 1) {
            res += "def " + rtype  + " " + fname + " ( ";
        } else if (|funcargs| > 0) {
            String a0 = funcargs[0].getName();
            res += "def " + rtype + " " + fname + " " + a0  + " ( ";
        }
        String arg = "";
        for (int i = 1 - isStatic; i < |funcargs|; i++) {
            String t = getTypeName(funcargs[i].type);
            String n = funcargs[i].getName();
            arg += t + " " + n + " ";
        }
        if (arg.size > 0) {
            arg = arg[0 to arg.size-2];
        }
        res += arg + " ) {";

        for (int i = 0; i < |bbs|; i++) {
            String bbStr = "\n";
            if (bbs[i] == null) continue;
            bbStr += "BasicBlock" + i + ":" + bbs[i].attribute;
            //bbStr += ":\tpred = ";
            //for (int j = 0; j < |pred[i]|; j++) {
            //    OUT<< "bb" + pred[i][j] + " ";
            //}
            bbStr += EOL;
            bb = bbs[i];
            foreach(String s in bb.phis.keys()) {
                String tmp = bb.phis[s].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            for (int j = 0; j < |bb.insts|-1; j++) {
                String tmp = bb.insts[j].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            for (int j = 0; j < |bb.movs|; j++) {
                String tmp = bb.movs[j].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            if (bb.insts.size > 0) {
                bbStr += bb.insts[|bb.insts|-1].dump() + "\n"; //jmp
            }
            res += bbStr;
        }
        res += "}" + "\n";
        return res;
    }
    void check_or_expand(int size) {
        size = size + 1;
        while(register_table.size < size) {
            register_table.add(null);
        }
    }

    K_Inst getKInst(int idx) {
        K_Inst v = null;
        assert(idx >= 0);
        check_or_expand(idx);
        if (register_table[idx] == null) { // argument
        } else {
            v = register_table[idx];
        }
        return v;
    }

    Boolean checkBaseType(Class c1, Class c2) {
        String t1 = (to String) c1;
        String t2 = (to String) c2;
        String[] types = ["konoha.Array", "konoha.Map", "konoha.Array", "konoha.Func", "konoha.Iterator"];
        for (int i=0; i < types.size; i++) {
            String type = types[i];
            if (t1.startsWith(type) && t2.startsWith(type)) {
                return true;
            }
        }
        return false;
    }
    K_Value getKValue(int idx, Class type) {
        this.addClass(type);
        K_Value res = value_table[(String)idx];
        if (res == null) {
            value_table[(String)idx] = new K_Value(idx, type);
        } else {
            Class rtype = res.type;
            if (rtype != type && !checkBaseType(rtype, type)) {
                value_table[(String)idx] = new K_Value(idx, type);
            }
        }
        return value_table[(String)idx];
    }

    void storeKInst(int idx, K_Inst v) {
        if (idx < 0) {
            retval = v;
        } else {
            check_or_expand(idx);
            register_table[idx] = v;
        }
    }
    void addBB(K_BasicBlock bb, int bbidx) {
        while(bbs.size < bbidx + 1) {
            bbs.add(null);
        }
        bbs[bbidx] = bb;
    }
}
class K_Class {
    int offset;
    Class c;
    Class[] fieldClasses;
    String[] fieldNames;
    K_Class (Class c) {
        this.c = c;
        this.fieldClasses = c.getFieldClasses();
        this.fieldNames = c.getFieldNames();
        this.offset = |c.getSuper().getFieldClasses()|;
    }

    String dump() {
        String res = "class " + c + " extends " + c.getSuper() + EOL;
        res += "{" + EOL;
        for(int i = offset; i < |fieldNames|; i++) {
            res += "\t" + fieldClasses[i] + " " + fieldNames[i] + EOL;
        }
        res += "}" + EOL;
        return res;
    }
}

class KBinaryInstOp extends K_Opcode {
    KBinaryInstOp(K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}

class KBinaryInst extends K_Inst {
    String operand;
    KBinaryInstOp op;
    void init0(String name, K_Value kv, Class type, KBinaryInstOp op, int bbidx) {
        init_kvalue(kv, type);
        this.operand = name;
        this.op = op;
        addDef(kvalue, bbidx);
        addUse(op, bbidx);
    }
    @Virtual void init(String operand, K_Value kvalue, Class type, KBinaryInstOp op, int bbidx) {
        init0(operand, kvalue, type, op, bbidx);
    }
    @Override String dump() {
        String v2 = getName();
        String v0 = op.inst0.getName();
        String v1 = op.inst1.getName();
        String t  = getTypeName(type);
        return "\t" + v2 + " = " + operand + " "+ t + " " + v0 + " " + v1;
    }
}

class KRelationalInst extends KBinaryInst {
    @Override void init(String operand, K_Value kvalue, Class type, KBinaryInstOp op, int bbidx) {
        if (kvalue == null) dynName = "cmptmp";
        init0(operand, kvalue, type, op, bbidx);
    }
}
class KUnaryInstOp extends K_Opcode {
    KUnaryInstOp (K_Inst inst0) {
        this.inst0 = inst0;
    }
}

class KUnaryInst extends K_Inst {
    String operand;
    KUnaryInstOp op;
    void init(String name, K_Value kvalue, Class type, KUnaryInstOp op, int bbidx) {
        this.operand = name;
        init_kvalue(kvalue, type);
        this.op = op;
        addDef(kvalue, bbidx);
        addUse(op, bbidx);
    }
    @Override String dump() {
        String v1 = getName();
        String v0 = op.inst0.getName();
        String t  = getTypeName(type);
        return "\t" + v1 + " = " + operand + " " + t + " " + v0;
    }
}

class K_ADD extends KBinaryInst {
    K_ADD(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("add", kvalue, type, op, bb.bbidx);
    }
}
class K_SUB extends KBinaryInst {
    K_SUB(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("sub", kvalue, type, op, bb.bbidx);
    }
}
class K_MUL extends KBinaryInst {
    K_MUL(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("mul", kvalue, type, op, bb.bbidx);
    }
}

class K_DIV extends KBinaryInst {
    K_DIV(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("div", kvalue, type, op, bb.bbidx);
    }
}
class K_MOD extends KBinaryInst {
    K_MOD(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("mod", kvalue, type, op, bb.bbidx);
    }
}
class K_AND extends KBinaryInst {
    K_AND(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("and", kvalue, type, op, bb.bbidx);
    }
}
class K_OR extends KBinaryInst {
    K_OR(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("or", kvalue, type, op, bb.bbidx);
    }
}
class K_XOR extends KBinaryInst {
    K_XOR(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("xor", kvalue, type, op, bb.bbidx);
    }
}
class K_LSFT extends KBinaryInst {
    K_LSFT(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("lsft", kvalue, type, op, bb.bbidx);
    }
}
class K_RSFT extends KBinaryInst {
    K_RSFT(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("rsft", kvalue, type, op, bb.bbidx);
    }
}
class K_NOT extends KUnaryInst {
    K_NOT(K_Value kvalue, Class type, KUnaryInstOp op, K_BasicBlock bb) {
        init("not", kvalue, type, op, bb.bbidx);
    }
}
class K_EQ extends KRelationalInst {
    K_EQ(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("eq", kvalue, type, op, bb.bbidx);
    }
}
class K_NEQ extends KRelationalInst {
    K_NEQ(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("neq", kvalue, type, op, bb.bbidx);
    }
}

class K_LT extends KRelationalInst {
    K_LT(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("lt", kvalue, type, op, bb.bbidx);
    }
}
class K_GT extends KRelationalInst {
    K_GT(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("gt", kvalue, type, op, bb.bbidx);
    }
}
class K_LTE extends KRelationalInst {
    K_LTE(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("lte", kvalue, type, op, bb.bbidx);
    }
}
class K_GTE extends KRelationalInst {
    K_GTE(K_Value kvalue, Class type, KBinaryInstOp op, K_BasicBlock bb) {
        init("gte", kvalue, type, op, bb.bbidx);
    }
}
class K_SELECTop extends K_Opcode {
    KBinaryInstOp (K_Inst inst0, K_Inst inst1, K_Inst inst2) {
        this.inst0 = inst0;
        this.inst1 = inst1;
        this.inst2 = inst2;
    }
}
class K_SELECT extends K_Inst {
    K_SELECTop op;
    K_SELECT(K_Value kvalue, Class type, K_SELECTop op, K_BasicBlock bb) {
        init_kvalue(kvalue, type);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        String v3 = getName();
        String v0 = op.inst0.getName();
        String v1 = op.inst1.getName();
        String v2 = op.inst2.getName();
        String t  = getTypeName(type);
        return "\t" + v3 + " = select " + t + " " + v0 + " " + v1 + " " + v2;
    }
}
class K_CASTop extends K_Opcode{
    Class tcid;
    Class scid;
    int b;
    int rix;
    int espshift;
    int cast;
    int fptr;
    K_CASTop (K_Inst inst0, Class tcid, Class scid, int b, int rix, int espshift, int cast, int fptr) {
        this.inst0 = inst0;
        this.tcid = tcid;
        this.scid = scid;
        this.b = b;
        this.rix = rix;
        this.espshift = espshift;
        this.cast = cast;
        this.fptr = fptr;
    }
}
class K_CAST extends K_Inst {
    K_CASTop op;
    K_CAST(K_Value kvalue, K_CASTop op, K_BasicBlock bb) {
        init_kvalue(kvalue, op.tcid);
        assert(this.type != null);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = cast "+ getTypeName(type) + " " +  op.inst0.getName();
    }
}
class K_IntToFloat extends K_CAST {}
class K_FloatToInt extends K_CAST {}

class K_JMPop extends K_Opcode {
    int jmpidx;
    String attribute;
    K_JMPop (int jmpidx, String attribute) {
        this.jmpidx = jmpidx;
        this.attribute = attribute;
    }
}
class K_JMP extends K_Inst {
    K_JMPop op;
    K_JMP(K_JMPop op, K_BasicBlock bb) {
        init_kvalue(null);
        this.op = op;
    }
    @Override String dump() {
        String res = "\t_ = jmp bb" + op.jmpidx;
        if (op.attribute != null) {
            res += " @" + op.attribute;
        }
        return res;
    }
}
class K_CONDop extends K_Opcode {
    int bbThen;
    int bbElse;
    String attribute;
    K_CONDop (K_Inst inst0, int bbThen, int bbElse, String attribute) {
        this.inst0 = inst0;
        this.bbThen = bbThen;
        this.bbElse = bbElse;
        this.attribute = attribute;
    }
}
class K_COND extends K_Inst {
    K_CONDop op;
    K_COND(K_CONDop op, K_BasicBlock bb) {
        this.op = op;
        init_kvalue(null);
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        String res = "\t_ = cond Boolean " + op.inst0.getName() + " bb" + op.bbThen + " bb" + op.bbElse;
        if (op.attribute != null) {
            res += " @" + op.attribute;
        }
        return res;
    }
}
class K_CALLop extends K_Opcode {
    String fname;
    Method mtd;
    int mtdNC;
    int thisidx;
    int espshift;
    int ftype;
    int rix;
    int flagStatic;
    void init(String fname, Method mtd, int thisidx, int espshift, int ftype, int rix, int flagStatic) {
        this.fname = fname;
        this.mtd   = mtd;
        this.mtdNC = mtd.getPtr();
        this.thisidx = thisidx;
        this.espshift = espshift;
        this.ftype = ftype;
        this.rix = rix;
        this.flagStatic = flagStatic;
    }
    K_CALLop (String fname, Method mtd, int thisidx, int espshift, int rix) {
        init(fname, mtd, thisidx, espshift, FUNC_STATIC, rix, 0);
    }
    @Virtual String dumpStaticAnnotation(K_Inst[] args) {
        String res = "";
        if (!args[0].kvalue.type.isUnboxType()) {
            res = " @nonstatic";
        } else {
            res = " @static";
        }
        return res;
    }

}
class K_StaticCallOp extends K_CALLop {
    K_StaticCallOp(String fname, Method mtd, int thisidx, int espshift, int rix) {
        init(fname, mtd, thisidx, espshift, FUNC_STATIC, rix, 1);
    }
    @Override String dumpStaticAnnotation(K_Inst[] args) {
        return " @static";
    }

}
class K_CALL extends K_Inst {
    K_CALLop op;
    K_CALL(K_Value kvalue, Array<K_Inst> args, K_CALLop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.args = args;
        this.op = op;
        if (getTypeName(kvalue.type) != "null") {
            addDef(kvalue, bb.bbidx);
        }
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        String res = "\t";
        if (kvalue != null) {
            String ret;
            if (kvalue.type == null) {
                ret = "_";
            } else {
                ret = getName();
            }
            String type = getTypeName(kvalue.type);
            res += ret + " = call " + type + " " + op.fname + " ( ";
        }
        for (int i = 0; i < |args|; i++) {
            res += args[i].getName() + " ";
        }
        res = res[0 to |res|-2] + " )";
        res += op.dumpStaticAnnotation(args);
        return res;
    }
}
class K_PRINTop extends K_Opcode {
    int sfpidx;
    int opline;
    int pflag;
    String msg;
    K_PRINTop(K_Inst inst0, int flag, int sfpidx, int opline, String msg) {
        this.inst0 = inst0;
        this.pflag  = flag;
        this.sfpidx = sfpidx;
        this.opline = opline;
        this.msg    = msg;
    }
}
class K_PRINT extends K_Inst {
    K_PRINTop op;
    K_PRINT(Class type, K_PRINTop op, K_BasicBlock bb) {
        init_kvalue(null, type);
        this.op = op;
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        String v0 = op.inst0.getName();
        String data = op.pflag + " " + op.opline + " ";
        String msg = "\"" + escape(op.msg) + "\"";
        String res = "\t_ = print " + type + " " +data + msg + " "+ v0;
        return res;
    }
}

class K_TRop extends K_Opcode {
    int espidx;
    int rix;
    Class c;
    int ftr;
    K_TRop(K_Inst inst0, int espidx, int rix, Class c, int ftr) {
        this.espidx = espidx;
        this.inst0 = inst0;
        this.rix = rix;
        this.c = c;
        this.ftr = ftr;
    }
}
class K_TR extends K_Inst {
    K_TRop op;
    K_TR(K_Value kvalue, K_TRop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = " + getTRMethod() + " " + getTypeName(type) + " " + op.inst0.getName();
    }
    String getTRMethod() {
        switch (op.ftr) {
            case Stmt.BBOX:
                return "box";
            case Stmt.BOX:
                return "box";
            case Stmt.NULL:
                return "bnul";
            case Stmt.CWB:
                return "cwb";
            case Stmt.TOSTR:
                return "tostr";
            case Stmt.LOOKUPMTD:
                return "lookupmtd";
            case Stmt.PROP:
                return "prop";
            case Stmt.VARGS:
                return "vargs";
            case Stmt.ERR:
                return "err";
            case Stmt.CHKTYPE:
                return "chktype";
            case Stmt.DYNMTD:
                return "dynmtd";
            case Stmt.PBOX:
                return "pbox";
        }
    }
}
class K_NEWop extends K_Opcode {
    int rix;
    Class c;
    int ftr;
    K_NEWop(int rix, Class c, int ftr) {
        this.rix = rix;
        this.c   = c;
        this.ftr = ftr;
    }
}
class K_NEW extends K_Inst {
    K_NEWop op;
    K_NEW(K_Value kvalue, K_NEWop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        addDef(kvalue, bb.bbidx);
    }
    @Override String dump() {
        return "\t"+ getName() + " = new " + getTypeName(type) + " ";
    }
}
class K_GETIDXop extends K_Opcode {
    K_GETIDXop(K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_GETIDX extends K_Inst {
    K_GETIDXop op;
    K_GETIDX(K_Value kvalue, K_GETIDXop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = getidx " + getTypeName(type) + " " +  op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_SETIDXop extends K_Opcode {
    K_SETIDXop(K_Inst inst0, K_Inst inst1, K_Inst inst2) {
        this.inst0 = inst0;
        this.inst1 = inst1;
        this.inst2 = inst2;
    }
}
class K_SETIDX extends K_Inst {
    K_SETIDXop op;
    K_SETIDX(K_Value kvalue, K_SETIDXop op, K_BasicBlock bb) {
        init_kvalue(kvalue, type);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + "_ = setidx " + getTypeName(type) + " " + op.inst0.getName() + " " + op.inst2.getName() + " " + op.inst1.getName();
    }
}
class K_CHKIDXop extends K_Opcode {
    K_CHKIDXop(K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_CHKIDX extends K_Inst {
    K_CHKIDXop op;
    K_CHKIDX(K_CHKIDXop op, K_BasicBlock bb) {
        init_kvalue(null);
        this.op = op;
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t_ = chkidx " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_CONSTop extends K_Opcode {
    Array<dynamic> const_table;
    int table_idx;
    int objptr;
    K_CONSTop(int table_idx, int objptr, Array<dynamic> const_table) {
        this.table_idx = table_idx;
        this.objptr = objptr;
        this.const_table = const_table;
    }
}
class K_CONST extends K_Inst {
    K_CONSTop op;
    Array<dynamic> const_table;
    K_CONST(K_Value kvalue, Class type, K_CONSTop op, K_BasicBlock bb) {
        init_kvalue(kvalue, type);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
        dynName = "const " + getTypeName(type) + " " + "%s"(op.const_table[op.table_idx]);
    }

    String quote(dynamic value) {
        if(value.class == String) {
            String s = value;
            return  "\"" + escape(s) + "\"";
        } else if (value.class == Float) {
            Float f = value;
            return f.format("%.20f");
        } else if(value.class == Array<dynamic>) {
            Array a = value;
            String res = "[";
            for(int i=0; i<|a|; i++) {
                if(i != 0) res += ", ";
                res += quote(a[i]);
            }
            res += "] [";
            for(int i=0; i<|a|; i++) {
                if(i != 0) res += " ";
                res += a[i].class;
            }
            res += "]";
            return res;
        } else if(value.class == Map<String, dynamic>) {
            Map m = value;
            String[] keys = m.keys();
            String res = "{";
            for(int i=0; i<|keys|; i++) {
                if(i != 0) res += ", ";
                dynamic o = m[keys[i]];
                res += quote(keys[i]) + ": " + quote(o);
            }
            res += "} [";
            for(int i=0; i<|keys|; i++) {
                if(i != 0) res += " ";
                res += m[keys[i]].class;
            }
            res += "]";
            return res;
        } else if (value.class == Method) {
            Method m = (to Method)value;
            return m.getMethodClass() + "." + m.getName();
        } else if (value == null && value.class.isUnboxType()) {
            return "0";
        } else {
            return "" + value;
        }
    }

    @Override String dump() {
        String res;
        if (kvalue != null) {
            res += "\t" + getName() + " = const " + getTypeName(type) + " ";
            res += quote(op.const_table[op.table_idx]);
            return (String)res;
        }
        return null;
    }
}
class K_TCHECKop extends K_Opcode {
    int espidx;
    K_TCHECKop(K_Inst inst0, int espidx) {
        this.inst0 = inst0;
        this.espidx = espidx;
    }
}
class K_TCHECK extends K_Inst {
    K_TCHECKop op;
    K_TCHECK(K_Value kvalue, K_TCHECKop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        if (op.inst0.class == K_CONST) {
            K_CONST inst = (K_CONST) op.inst0;
            Class c = inst.op.const_table[inst.op.table_idx];
            this.type = c;
        }
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = tcheck " + getTypeName(type) + " " + op.inst0.getName();
    }
}
class K_GetFieldOp extends K_Opcode {
    int bn;
    K_GetFieldOp(K_Inst inst0, int bn) {
        this.inst0 = inst0;
        this.bn = bn;
    }
}
class K_GetField extends K_Inst {
    K_GetFieldOp op;
    K_GetField(K_Value kvalue, K_GetFieldOp op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        if (kvalue == null) dynName = "movtmp";
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = getfield " + getTypeName(type) + " " + op.inst0.getName() + " " + op.bn;
    }
}
class K_SetFieldOp extends K_Opcode {
    int an;
    K_SetFieldOp(K_Inst inst0, K_Inst inst1, int an) {
        this.inst0 = inst0;
        this.inst1 = inst1;
        this.an = an;
    }
}
class K_SetField extends K_Inst {
    K_SetFieldOp op;
    Value field_access_cached;
    K_SetField(K_SetFieldOp op, K_BasicBlock bb) {
        init_kvalue(null, op.inst0.type);
        this.op = op;
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t_ = setfield " + getTypeName(type) + " " + op.inst0.getName() + " " + op.an + " " + op.inst1.getName();
    }
}
class K_NEXTop extends K_Opcode {
    int nextBB;
    int endBB;
    int b;
    int rix;
    int espshift;
    K_NEXTop(K_Inst inst0, int nextBB, int endBB, int b, int rix, int espshift) {
        this.inst0 = inst0;
        this.nextBB = nextBB;
        this.endBB = endBB;
        this.b = b;
        this.rix = rix;
        this.espshift = espshift;
    }
}
class K_NEXT extends K_Inst {
    K_NEXTop op;
    int thenBB, elseBB;
    K_NEXT(K_Value kvalue, K_NEXTop op, K_BasicBlock bb) {
        init_kvalue(kvalue);
        this.op = op;
        addDef(kvalue, bb.bbidx);
        addUse(op, bb.bbidx);
    }
    @Override String dump() {
        return "\t" + getName() + " = next " + getTypeName(type) + " " + op.inst0.getName() + " bb" + op.nextBB + " bb" + op.endBB;
    }
}

class K_TRY extends K_Inst {
    K_TRY() {
        init_kvalue(null);
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}

class K_CATCH extends K_Inst {
    K_CATCH() {
        init_kvalue(null);
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}

class K_THROW extends K_Inst {
    K_THROW() {
        init_kvalue(null);
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}

class K_CHKSTACK extends K_Inst {
    K_CHKSTACK() {
        init_kvalue(null);
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}

class K_ASSERT extends K_Inst {
    K_ASSERT() {
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}
class K_LDMTDop extends K_Opcode {
    int thisidx;
    int ldmtd;
    Class c;
    String name;
    Method mtd;
    int argc;
    K_LDMTDop(int thisidx, int ldmtd, Class c, String name, Method mtd, int argc) {
        this.ldmtd = ldmtd;
        this.thisidx = thisidx;
        this.c = c;
        this.name = name;
        this.mtd = mtd;
        this.argc = argc;
    }
}
class K_LDMTD extends K_Inst {
    K_LDMTDop op;
    K_LDMTD(K_LDMTDop op) {
        this.op = op;
        init_kvalue(null);
    }
    @Override String dump() {
        throw new Exception();
        return null;
    }
}

class K_Retop extends K_Opcode {
    K_Retop(K_Inst inst0) {
        this.inst0 = inst0;
    }
}
class K_Ret extends K_Inst {
    K_Retop op;
    K_Ret(K_Retop op) {
        this.op = op;
        init_kvalue(null);
    }
    @Override String dump() {
        String name = "";
        if (op.inst0 != null) name = op.inst0.getName();
        return "\t_ = return " + name;
    }
}

class SFX {
    int i;
    int n;
    SFX(int i, int n) {
        this.i = i;
        this.n = n;
    }
}

@Native boolean Compiler.gammaHasFIELD();
@Native int Compiler.gamma_fvarsize();
@Native int Compiler.gamma_gf_fn(int i);
@Native Class Compiler.gamma_gf_type(int i);
@Native Class Compiler.gammaGetThiscid();
@Virtual void Compiler.initFunc(K_Function func) {
    func.func = null;
}

void Compiler.init_common(Method mtd) {
    this.mtd = mtd;
    if (DEBUG) {
        print mtd;
        print mtd.toString();
        print mtd.getReturnType();
        //print mtd.getParamTypes();
        print mtd.toString();
    }
    this.mtd = mtd;
    paramsclass = mtd.getParamTypes();
    retclass    = mtd.getReturnType();
    this.kfunc = new K_Function(mtd);
    this.kfunc.addClass(mtd.getMethodClass());
    this.kfunc.addClass(mtd.getReturnType());
    foreach (Class c in mtd.getParamTypes()) {
        this.kfunc.addClass(c);
    }
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
    for (int i = 0; i < |paramsclass|; i++) {
        Class j = paramsclass[i];
        K_Value kvalue = kfunc.getKValue(i+1, j);
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(i+1), kfunc.curBB);
        kfunc.storeKInst(i+1, inst);
        kfunc.funcargs.add(inst);
    }
    for (int i = |paramsclass|+1; i < gamma_fvarsize(); i++) {
        Class c = gamma_gf_type(i);
        if (gamma_gf_fn(i) == Stmt.FN_vargs) {
            Class p1 = c.getP1();
            K_Value kvalue = kfunc.getKValue(i, p1);
            inst = new K_TR(kvalue, new K_TRop(null, i, i-i, p1, Stmt.VARGS), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(i, inst);
            continue;
        }
        if (c.isUnboxType()) {
            int table_idx = kfunc.addConstTable(0);
            int objptr = 0;
            K_Value kvalue = kfunc.getKValue(i, c);
            K_CONST inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(i, inst);
        } else {
            K_Value kval = kfunc.getKValue(i, c);
            K_Inst inst = new K_TR(kval, new K_TRop(null, i, 0, c, Stmt.NULL), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(i, inst);
        }
    }
    initFunc(kfunc);
    String mtdName = mtd.toString();
    if (this.compiled_methods[mtdName] == null) {
        this.compiled_methods[mtdName] = [];
    }
    this.compiled_methods[mtdName].add(kfunc);
}
void Compiler.init(Method mtd) {
    init_common(mtd);
}

void Compiler.addSafePoint(int espidx, K_BasicBlock bb) {
    if (bb == null) {
        bb = kfunc.curBB;
    }
    if (bb.safepoint == -1) {
        bb.safepoint = espidx;
    }
}

Array<K_Inst> Compiler.cloneRegTable() {
    Array<K_Inst> res = [];
    foreach (K_Inst inst in kfunc.register_table) {
        res.add(inst);
    }
    return res;
}
Array<K_Inst> Compiler.cloneTable(Array<K_PHI> phis) {
    Array<K_Inst> res = [];
    for (int i = 0; i < |phis|; i++) {
        res.add((K_Inst)phis[i]);
    }
    return res;
}
Array<K_PHI> Compiler.regTableToPHI(int espidx, K_BasicBlock bb) {
    Array<K_PHI> res = [];
    for (int i = 0; i < espidx; i++) {
        if (kfunc.register_table[i] == null) {
            res.add(null);
        } else {
            K_PHI phi = new K_PHI(i);
            phi.addIncoming(kfunc, i, kfunc.register_table[i], kfunc.curBB.bbidx, kfunc.curBB.movs);
            res.add(phi);
            bb.phis[(String)i] = phi;
        }
    }
    return res;
}
void Compiler.createPhiArrayBackEdge(Array<K_PHI> phis, Array<K_Inst> regTableCont, K_BasicBlock bb, int espidx) {
    for (int i = 0; i < espidx; i++) {
        if (phis[i] != null /*&& regTableCont[i].type.isUnboxType()*/) {
            boolean flag = true;
            if (regTableCont[i].getName() != phis[i].getName()) {
                flag = false;
            }
            for (int j = 0; j < |kfunc.continueList|; j++) {
                if (regTableCont[i].getName() != kfunc.continueList[j][1][i].getName()) {
                    flag = false;
                }
            }
            if (flag == false) {
                phis[i].addIncoming(kfunc, i, regTableCont[i], bb.bbidx, bb.movs);
                for (int j = 0; j < |kfunc.continueList|; j++) {
                    phis[i].addIncoming(kfunc, j, kfunc.continueList[j][1][i], kfunc.continueList[j][0].bbidx, kfunc.continueList[j][0].movs);
                }
            }
        }
    }
}
Array<K_Inst> Compiler.createPhiArray(K_BasicBlock bb, Array<K_Inst> regTableCont, K_BasicBlock bbCont,Array<Tuple<K_BasicBlock, Array<K_Inst>>> breakList, int espidx) {
    Array<K_Inst> res = [];
    for (int i = 0; i < espidx; i++) {
        boolean flag = true;
        if (regTableCont[i] == null) {
            res.add(null);
            continue;
        }
        for (int j = 0; j < |breakList|; j++) {
            Tuple <K_BasicBlock, K_Inst[]> tuple = breakList[j];
            if (regTableCont[i] != tuple[1][i]) {
                flag = false;
            }
        }
        if (flag /*|| !regTableCont[i].type.isUnboxType()*/) {
            res.add(regTableCont[i]);
        } else {
            K_PHI phi = new K_PHI(i);
            phi.addIncoming(kfunc, i, regTableCont[i], bbCont.bbidx, bbCont.movs);
            for (int j = 0; j < |breakList|; j++) {
                Tuple<K_BasicBlock, K_Inst[]> tuple = breakList[j];
                phi.addIncoming(kfunc, j, tuple[1][i], tuple[0].bbidx, tuple[0].movs);
            }
            res.add(phi);
            bb.phis[(String)i] = phi;
        }
    }
    return res;
}
SFX getsfx(Token tk) {
    int i = 0;
    int n = tk.getTokenIndex();
    Token tkIDX = tk.gettkIdx();
    if (tk.getD().class == Term && tkIDX.getTT() == Token.TT_FVAR) {
        i = tkIdx.getTokenIndex();
    }
    return new SFX(i, n);
}
@Native void Compiler.asmEXPR(Stmt stmt, int espidx);
@Native void Compiler.debug();

void Compiler.asm_xmov(SFX ax, Token tkb, int espidx) {
    Class btype = tkb.getT();
    int used_espidx = -1;
    Object v = null;
    switch (tkb.getTT()) {
        case Token.TT_NULL:
            /* TODO overwriting default null value */
            Class c = tkb.getTokenClass();
            v = c.getNullValue();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            K_Value kvalue = kfunc.getKValue(espidx + 1, c);
            K_CONST tmp = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, tmp, ax.n), kfunc.curBB);
            kfunc.curBB.insts.add(inst);

            break;
        case Token.TT_CID:
            v = tkb.getTokenClass();
        case Token.TT_CONST:
            if (v == null) {
                v = tkb.getD();
            }
            int table_idx;
            int objptr = 0;
            if (btype.isUnboxType()) {
                table_idx = kfunc.addConstTable(v);
            } else {
                objptr = v.getPtr();
                table_idx = kfunc.addConstTable(v);
            }
            K_Value kvalue = kfunc.getKValue(espidx + 1, btype);
            K_Inst tmp = new K_CONST(kvalue, btype, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, tmp, ax.n), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FVAR:
            int b = tkb.getTokenIndex();
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst1 = kfunc.getKInst(b);
            K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, inst1, ax.n), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FIELD:
            SFX bx = getsfx(tkb);
            K_Inst vb = kfunc.getKInst(bx.i);
            K_Value kvalue = kfunc.getKValue(espidx + 1, btype);
            K_Inst tmp = new K_GetField(kvalue, new K_GetFieldOp(vb, bx.n), kfunc.curBB);
            kfunc.curBB.insts.add(tmp);
            K_Inst va = kfunc.getKInst(ax.i);
            K_Inst inst = new K_SetField(new K_SetFieldOp(va, tmp, ax.n), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_SYSVAL:
            used_espidx = espidx;
            int sysid = tkb.getTokenIndex();
            Method mtd = system_method[sysid];
            Class rtype = system_method_class[sysid];
            int thisidx = espidx + K_CALLDELTA;
            int espshift = espidx + 0 + K_CALLDELTA + 1;
            String fname = mtd.toString();
            Array<K_Inst> args = [];
            K_Value kvalue = kfunc.getKValue(thisidx - 4, rtype);
            String fname = fname[fname.indexOf(".")+1 to |fname|-1];
            K_Inst inst = new K_CALL(kvalue, args, new K_StaticCallOp(fname, mtd, thisidx, espshift, K_RTNIDX), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(espidx, inst);
            break;
        case Token.TT_PROPN:
            kfunc.setUndevelop();
            used_espidx = espidx;

            Class c = String;
            v = tkb.getD();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            K_Value kvalue = kfunc.getKValue(espidx, c);
            K_Inst inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            K_Value vb = kfunc.getKValue(espidx, btype);
            inst = new K_TR(vb, new K_TRop(inst, espidx, espidx - espidx, btype, Stmt.PROP), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(espidx, inst);
            break;
        default:
            break;
    }
    if (used_espidx != -1) {
        K_Inst inst0 = kfunc.getKInst(ax.i);
        K_Inst inst1 = kfunc.getKInst(espidx);
        K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, inst1, ax.n), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asm_smovx(int alocal, Class type, SFX bx) {
    K_Inst inst0 = kfunc.getKInst(bx.i);
    K_Value kvalue = kfunc.getKValue(alocal, type);
    K_Inst inst = new K_GetField(kvalue, new K_GetFieldOp(inst0, bx.n), kfunc.curBB);
    kfunc.curBB.insts.add(inst);
    kfunc.storeKInst(alocal, inst);
}
void Compiler.asm_smov(int alocal, Token tk) {
    Class type = tk.getT();
    Object v = null;
    switch(tk.getTT()) {
        case Token.TT_ASIS:
            break;
        case Token.TT_NULL:
            /* TODO overwriting default null value */
            Class c = tk.getTokenClass();
            v = c.getNullValue();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            K_Value kvalue = kfunc.getKValue(alocal, c);
            K_CONST inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(alocal, inst);
            break;
        case Token.TT_CID:
            v = tk.getTokenClass();
        case Token.TT_CONST:
            if (v == null) {
                v = tk.getD();
            }
            int table_idx = kfunc.addConstTable(v);
            int objptr = 0;
            if (!type.isUnboxType()) {
                objptr = v.getPtr();
            }
            K_Value kvalue = kfunc.getKValue(alocal, type);
            K_CONST inst = new K_CONST(kvalue, type, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(alocal, inst);
            break;
        case Token.TT_FVAR:
            int b = tk.getTokenIndex();
            kfunc.storeKInst(alocal, kfunc.getKInst(b));
            //kfunc.storeKInst(alocal, kfunc.getKInst(b));
            break;
        case Token.TT_FIELD:
            SFX bx = getsfx(tk);
            asm_smovx(alocal, type, bx);
            break;
        case Token.TT_SYSVAL:
            int sysid = tk.getTokenIndex();
            Method mtd = system_method[sysid];
            Class rtype = system_method_class[sysid];
            int espidx = alocal;
            int thisidx = espidx + K_CALLDELTA;
            int espshift = espidx + 0 + K_CALLDELTA + 1;
            int isStatic = 1;
            Array<K_Inst> args = [];
            K_Value kvalue = kfunc.getKValue(thisidx - 4, rtype);

            if (DEBUG) {
                print "sysval", sysid;
                print sysid, mtd;
            }
            K_Inst inst = new K_CALL(kvalue, args, new K_StaticCallOp(mtd.toString(), mtd, thisidx, espshift, K_RTNIDX), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(thisidx + K_RTNIDX, inst);
            break;
        case Token.TT_PROPN:
            kfunc.setUndevelop();
            Class c = String;
            v = tk.getD();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            int espidx = alocal;
            K_Value kvalue = kfunc.getKValue(espidx, c);
            K_Inst inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            K_Value vb = kfunc.getKValue(espidx, type);
            inst = new K_TR(vb, new K_TRop(inst, espidx, 0, type, Stmt.PROP), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(espidx, inst);
            break;
        default:
            break;
    }
}
void Compiler.asm(Stmt stmt, Token tk, int espidx) {
    if (DEBUG) {
        print tk.isNotNULL();
    }
    if (tk.isNotNULL()) {
        asm_smov(espidx, tk);
    } else {
        asmEXPR(stmt, espidx);
    }
}
void Compiler.addConstTable(dynamic val) {
    const_table.add(val);
}

void Compiler.dump(Boolean dump) {
    foreach (K_Class c in declareclass) {
        OUT << c.dump() << EOL;
    }
    if (SHANEIR_ENABLE_FUNCTION_DUMP) {
        foreach (String str in this.ir) {
            OUT << str << EOL;
        }
    }
}
void Compiler.common_emit(Method mtd) {
    foreach (Class c in this.kfunc.declareclass_func) {
        boolean found = false;
        foreach (K_Class kc in this.declareclass) {
            if (kc.c == c) {
                found = true;
            }
        }
        if (!found) {
            this.declareclass.add(new K_Class(c));
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
}
void Compiler.emit(Method mtd) {
    common_emit(mtd);
    String result = kfunc.dump();
    this.ir << result;
    if (!kfunc.isUndeveloped()) {
        kfunc.codegen(this);
    }
}
void Compiler.asm_mov(Token tka, Token tkb, int espidx) {
    if (DEBUG) {
        print "mov";
    }
    if (tka.getTT() == Token.TT_FVAR) {
        asm_smov(tka.getTokenIndex(), tkb);
    } else {
        SFX x = getsfx(tka);
        asm_xmov(x, tkb, espidx);
        if (DEBUG) {
            print "ASM_XMOV();";
        }
    }
}

/* stmt = {...} */
@Native void Compiler.asmBLOCK(Stmt stmt);
/* stmt = let stmt[1] = stmt[2] */
void Compiler.asmLET(Stmt stmt, Token tkL, Stmt tkV, Token tkVTk) {
    int espidx = stmt.getESPIDX();
    if (tkVTk.isNotNull()) {
        asm_mov(tkL, tkVtk, espidx);
        if (DEBUG) {
            print "ASM_MOV(lhs, tkV, espidx);", tkL, tkV;
        }
    } else {
        asm(tkV, tkVtk, espidx);
        if (DEBUG) {
            print espidx, tkV, tkVTk, tkL.getTokenIndex();
        }
        if (tkL.getTT() == Token.TT_FVAR) {
            if (DEBUG) {
                print "TT_FVAR ", tkL.getTokenIndex(), espidx;
            }
            kfunc.storeKInst(tkL.getTokenIndex(), kfunc.getKInst(espidx));
        } else {
            SFX ax = getsfx(tkL);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst1 = kfunc.getKInst(espidx);
            K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, inst1, ax.n), kfunc.curBB);
            kfunc.curBB.insts.add(inst);
        }
    }
}
/* stmt = if stmt[0] then stmt[1]:BLOCK else stmt[2] endif */
void Compiler.asmIF(Stmt stmt, Stmt stmtCond, Stmt stmtThen, Stmt stmtElse) {
    if (DEBUG) {
        print "IF";
        //int index = stmt.getIndex();
        print stmtThen;
        print stmtElse;
        print "", stmtCond.toToken();
        print stmtCond;
    }
    int size = stmt.getESPIDX();

    asm(stmtCond, stmtCond.toToken(), stmt.getESPIDX());

    Array<K_Inst> regTableThen = cloneRegTable();
    Array<K_Inst> regTableElse = cloneRegTable();

    K_Inst inst = kfunc.getKInst(stmt.getESPIDX());
    int bbssize = kfunc.bbs.size;
    K_BasicBlock bbThen = new K_BasicBlock(bbssize);
    K_BasicBlock bbElse = new K_BasicBlock(bbssize + 1);
    K_BasicBlock bb     = new K_BasicBlock(bbssize + 2);
    kfunc.addBB(bbThen, bbssize);
    kfunc.addBB(bbElse, bbssize+1);
    kfunc.addBB(bb, bbssize+2);

    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbThen.bbidx, bbElse.bbidx, "if"), kfunc.curBB);
    kfunc.curBB.insts.add(condjmp);

    kfunc.curBB = bbThen;
    kfunc.register_table = regTableThen;
    asmBlock(stmtThen);
    regTableThen = kfunc.register_table;
    bbThen = kfunc.curBB;
    if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock) {
        K_Inst jmp = new K_JMP(new K_JMPop(bb.bbidx, "merge"));
        kfunc.curBB.insts.add(jmp);
    }

    kfunc.curBB = bbElse;
    kfunc.register_table = regTableElse;
    asmBlock(stmtElse);
    regTableElse = kfunc.register_table;
    bbElse = kfunc.curBB;
    if (!bbElse.hasReturn && !bbElse.hasBrContinueBlock && !bbElse.hasBrContinueBlock) {
        K_Inst jmp = new K_JMP(new K_JMPop(bb.bbidx, "merge"));
        kfunc.curBB.insts.add(jmp);
    }

    /*PHI Node*/
    kfunc.curBB = bb;
    Array<K_Inst> regTableMerge = [];
    if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock && !bbElse.hasReturn && !bbElse.hasBrContinueBlock && !bbElse.hasBrBreakBlock) {
        for (int i = 0; i < size; i++) {
            if (regTableThen[i] != regTableElse[i] && regTableThen[i] != null &&
                    regTableElse[i] != null /*&& regTableThen[i].type.isUnboxType()*/) {
                K_PHI phi = new K_PHI(i);
                phi.addIncoming(kfunc, i, regTableThen[i], bbThen.bbidx, bbThen.movs);
                phi.addIncoming(kfunc, i, regtableElse[i], bbElse.bbidx, bbElse.movs);
                bb.phis[(String)i] = phi;
                regTableMerge.add(phi);
            } else if (regTableThen[i] != null){
                regTableMerge.add(regTableThen[i]);
            } else {
                regTableMerge.add(regTableElse[i]);
            }
        }
        kfunc.register_table = regTableMerge;
    } else if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock) {
        regTableMerge = regTableThen;
        kfunc.register_table = regTableMerge;
    } else if (!bbElse.hasReturn && !bbElse.hasBrBreakBlock && !bbElse.hasBrContinueBlock) {
        regTableMerge = regtableElse;
        kfunc.register_table = regTableMerge;
    } else {
        kfunc.bbs[bb.bbidx] = null;
    }
}
void Compiler.asmSWITCH(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    print "switch";
    print stmtC;
    print stmtBody;
}
void Compiler.asmWHILE(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    if (DEBUG) {
        print "while";
        print stmt;
        print stmtC;
        print stmtBody;
    }
    int espidx = stmt.getESPIDX();
    int bbssize = kfunc.bbs.size;
    K_BasicBlock bbCond  = new K_BasicBlock(bbssize + 0, "loopcond");
    K_BasicBlock bbBody  = new K_BasicBlock(bbssize + 1, "loopbody");
    K_BasicBlock bbBreak = new K_BasicBlock(bbssize + 2);
    kfunc.addBB(bbCond, bbssize);
    kfunc.addBB(bbBody, bbssize + 1);
    kfunc.addBB(bbBreak, bbssize + 2);

    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx, "while"));
    kfunc.curBB.insts.add(jmpCond);
    if ($env.LLVM_ENABLE_OPT_SAFEPOINT == "true") {
        addSafePoint(espidx, bbCond);
    } else {
        addSafePoint(espidx);
    }
    Array<K_Inst> regTableEntry = kfunc.register_table;
    Array<K_PHI> regTablePhi = regTableToPHI(espidx, bbCond);
    kfunc.register_table = cloneTable(regTablePhi);
    // cond part
    kfunc.curBB = bbCond;
    asm(stmtC, stmtC.toToken(), espidx + 1);
    K_Inst inst = kfunc.getKInst(espidx + 1);
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx), kfunc.curBB);
    kfunc.curBB.insts.add(condjmp);
    Array<K_Inst> regTableCond = cloneRegTable();
    // body part
    kfunc.breakpoint.add(bbBreak);
    kfunc.continuepoint.add(bbCond);
    kfunc.curBB = bbBody;
    asmBlock(stmtBody);
    kfunc.breakpoint.pop();
    kfunc.continuepoint.pop();
    if (!kfunc.curBB.hasBrContinueBlock && !kfunc.curBB.hasBrBreakBlock ) {
        kfunc.curBB.insts.add(jmpCond);
    }
    if (kfunc.curBB.hasReturn) {
        return;
    }
    createPhiArrayBackEdge(regTablePhi, kfunc.register_table, kfunc.curBB, espidx);
    kfunc.continueList = [];

    // break part
    Array<K_Inst> regTableBreak = createPhiArray(bbBreak, regTableCond, bbCond, kfunc.getbreaklist, espidx);
    kfunc.breakList = [];
    kfunc.register_table = regTableBreak;
    kfunc.curBB = bbBreak;
}
void Compiler.asmDO(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    if (DEBUG) {
        print "do-while";
        print stmt;
    }

    int bbssize = kfunc.bbs.size;
    K_BasicBlock bbBody  = new K_BasicBlock(bbssize + 0, "loopbody");
    K_BasicBlock bbCond  = new K_BasicBlock(bbssize + 1, "loopcond");
    K_BasicBlock bbBreak = new K_BasicBlock(bbssize + 2);
    kfunc.addBB(bbBody, bbssize);
    kfunc.addBB(bbCond, bbssize + 1);
    kfunc.addBB(bbBreak, bbssize + 2);
    int espidx = stmt.getESPIDX();

    K_Inst jmpBody = new K_JMP(new K_JMPop(bbBody.bbidx, "do_while"));
    kfunc.curBB.insts.add(jmpBody);
    Array<K_Inst> regTableEntry = kfunc.register_table;
    // body part
    Array<K_PHI> regTablePhi = regTableToPHI(espidx, bbBody);
    kfunc.register_table = cloneTable(regTablePhi);
    kfunc.breakpoint.add(bbBreak);
    kfunc.continuepoint.add(bbCond);
    kfunc.curBB = bbBody;
    if ($env.LLVM_ENABLE_OPT_SAFEPOINT == "true") {
        addSafePoint(espidx, bbCond);
    } else {
        addSafePoint(espidx);
    }

    asmBlock(stmtBody);
    kfunc.breakpoint.pop();
    kfunc.continuepoint.pop();

    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx, "cond"));
    kfunc.curBB.insts.add(jmpCond);
    // cond part
    Array<K_Inst> regTableCont = createPhiArray(bbCond, kfunc.register_table, kfunc.curBB, kfunc.continueList, espidx);
    kfunc.continueList = [];
    kfunc.register_table = regTableCont;
    kfunc.curBB = bbCond;
    asm(stmtC, stmtC.toToken(), stmt.getESPIDX());
    bbCond = kfunc.curBB;
    K_Inst inst = kfunc.getKInst(stmt.getESPIDX());
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx), kfunc.curBB);
    kfunc.curBB.insts.add(condjmp);
    Array<K_Inst> regTableCond = kfunc.register_table;
    createPhiArrayBackEdge(regTablePhi, kfunc.register_table, bbCond, espidx);
    // break part
    Array<K_Inst> regTableBreak = createPhiArray(bbBreak, regTableCond, bbCond, kfunc.breakList, espidx);
    kfunc.breakList = [];
    kfunc.register_table = regTableBreak;
    kfunc.curBB = bbBreak;
}
void Compiler.asmFOR(Stmt stmt, Stmt stmt1, Stmt stmt2, Stmt stmt3, Stmt stmtBody) {
    if (DEBUG) {
        print "for";
        print stmt;
        print stmt.getESPIDX();
        print stmt1.getESPIDX();
        print stmt2.getESPIDX();
        print stmt3.getESPIDX();
        print stmtBody.getESPIDX();
    }
    int bbssize = kfunc.bbs.size;

    K_BasicBlock bbCond     = new K_BasicBlock(bbssize + 0, "loopcond");
    K_BasicBlock bbBody     = new K_BasicBlock(bbssize + 1, "loopbody");
    K_BasicBlock bbContinue = new K_BasicBlock(bbssize + 2);
    K_BasicBlock bbBreak    = new K_BasicBlock(bbssize + 3);
    if (DEBUG) {
        print bbBreak.bbidx;
    }
    kfunc.addBB(bbCond, bbssize);
    kfunc.addBB(bbBody, bbssize + 1);
    kfunc.addBB(bbContinue, bbssize + 2);
    kfunc.addBB(bbBreak, bbssize + 3);
    int espidx = stmt1.getESPIDX();

    // init part
    asmBlock(stmt1);
    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx, "for"));
    kfunc.curBB.insts.add(jmpCond);
    Array<K_Inst> regTableEntry = kfunc.register_table;
    Array<K_PHI> regTablePhi = regTableToPHI(stmt1.getESPIDX(), bbCond);
    kfunc.register_table = cloneTable(regTablePhi);
    // cond part
    kfunc.curBB = bbCond;
    asm(stmt2, stmt2.toToken(), espidx + 1);
    K_Inst inst = kfunc.getKInst(espidx + 1);
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx), kfunc.curBB);
    kfunc.curBB.insts.add(condjmp);
    Array<K_Inst> regTableCond = cloneRegTable();

    // body part
    kfunc.breakpoint.add(bbBreak);
    kfunc.continuepoint.add(bbContinue);
    kfunc.curBB = bbBody;
    asmBlock(stmtBody);
    kfunc.breakpoint.pop();
    kfunc.continuepoint.pop();

    if (!kfunc.curBB.hasBrContinueBlock && !kfunc.curBB.hasBrBreakBlock) {
        K_Inst jmpC = new K_JMP(new K_JMPop(bbContinue.bbidx, "forcont"));
        kfunc.curBB.insts.add(jmpC);
    }
    if (kfunc.curBB.hasReturn) {
        return;
    }

    // continue part
    Array<K_Inst> regTableCont = createPhiArray(bbContinue, kfunc.register_table, kfunc.curBB, kfunc.continueList, espidx);
    kfunc.continueList = [];
    kfunc.register_table = regTableCont;
    kfunc.curBB = bbContinue;
    asmBlock(stmt3);
    if ($env.LLVM_ENABLE_OPT_SAFEPOINT == "true") {
        addSafePoint(espidx, bbCond);
    } else {
        addSafePoint(espidx);
    }
    K_Inst jmpNext = new K_JMP(new K_JMPop(bbCond.bbidx, null));
    kfunc.curBB.insts.add(jmpNext);
    createPhiArrayBackEdge(regTablePhi, kfunc.register_table, kfunc.curBB, espidx);
    //createPhiArrayBackEdge(regTablePhi, kfunc.register_table, bbContinue, espidx);
    // break part
    Array<K_Inst> regTableBreak = createPhiArray(bbBreak, regTableCond, bbCond, kfunc.breakList, espidx);
    kfunc.breakList = [];
    kfunc.register_table = regTableBreak;
    kfunc.curBB = bbBreak;
}
void Compiler.asmFOREACH(Stmt stmt, Token tkVar, Stmt stmtInit, Stmt stmtItr, Stmt stmtBody) {
    kfunc.setUndevelop();
    if (DEBUG) {
        print "foreach";
        print tkVar;
        print stmtInit;
        print stmtItr;
        print stmtBody;
    }

    int espidx = stmtItr.toToken().getTokenIndex();
    int varidx = tkVar.getTokenIndex();
    int bbssize = kfunc.bbs.size;
    kfunc.storeKInst(varidx, null);
    Class itrClass = tkVar.getT();
    K_BasicBlock bbCond  = new K_BasicBlock(bbssize);
    K_BasicBlock bbBody  = new K_BasicBlock(bbssize + 1);
    K_BasicBlock bbBreak = new K_BasicBlock(bbssize + 2);
    kfunc.addBB(bbCond, bbssize);
    kfunc.addBB(bbBody, bbssize + 1);
    kfunc.addBB(bbBreak, bbssize + 2);
    asm(stmtInit, stmtInit.toToken(), espidx);
    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx, "foreach"));
    kfunc.curBB.insts.add(jmpCond);
    addSafePoint(espidx);
    Array<K_Inst> regTableEntry = kfunc.register_table;
    Array<K_PHI> regTablePhi = regTableToPHI(espidx+1, bbCond);
    kfunc.register_table = cloneTable(regTablePhi);
    // next part
    kfunc.curBB = bbCond;
    //asm(stmtC, stmtC.toToken(), espidx + 1);
    K_Inst itrinst = kfunc.getKInst(espidx);
    K_Value kvalue = kfunc.getKValue(varidx, itrClass);
    K_Inst condnext = new K_NEXT(kvalue, new K_NEXTop(itrinst, bbBody.bbidx, bbBreak.bbidx, espidx, varidx - espidx, stmt.getESPIDX()), kfunc.curBB);
    kfunc.curBB.insts.add(condnext);
    kfunc.storeKInst(varidx, condnext);
    Array<K_Inst> regTableCond = cloneRegTable();
    // body part
    kfunc.breakpoint.add(bbBreak);
    kfunc.continuepoint.add(bbCond);
    kfunc.curBB = bbBody;
    asmBlock(stmtBody);
    kfunc.breakpoint.pop();
    kfunc.continuepoint.pop();
    if (!kfunc.curBB.hasBrContinueBlock && !kfunc.curBB.hasBrBreakBlock ) {
        kfunc.curBB.insts.add(jmpCond);
    }
    if (kfunc.curBB.hasReturn) {
        return;
    }
    createPhiArrayBackEdge(regTablePhi, kfunc.register_table, kfunc.curBB, espidx);
    kfunc.continueList = [];

    // break part
    Array<K_Inst> regTableBreak = createPhiArray(bbBreak, regTableCond, bbCond, kfunc.getbreaklist, espidx);
    kfunc.breakList = [];
    kfunc.register_table = regTableBreak;
    kfunc.curBB = bbBreak;

}

void Compiler.asmBREAK(Stmt stmt, Stmt stmtLabel) {
    kfunc.breakList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(kfunc.breakpoint[|kfunc.breakpoint|-1].bbidx, "break"));
    kfunc.curBB.insts.add(jmp);
    kfunc.curBB.hasBrBreakBlock = true;
}
void Compiler.asmCONTINUE(Stmt stmt, Stmt stmtLabel) {
    kfunc.continueList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(kfunc.continuepoint[|kfunc.continuepoint|-1].bbidx, "cont"));
    kfunc.curBB.insts.add(jmp);
    kfunc.curBB.hasBrContinueBlock = true;
}
void Compiler.asmTRY(Stmt stmt, Stmt stmtTry, Stmt stmtCATCH, Stmt stmtFINAL) {
    print "try";
    print stmtTry;
    print stmtCATCH;
    print stmtFINAL;
}
void Compiler.asmTHROW(Stmt stmt) {
    print "throw";
    print stmt;
    //int espidx = stmt.getESPIDX;
    //print espidx;
}
void Compiler.asmRETURN(Stmt stmt, Stmt stmtRetExpr, Stmt stmtPOST) {
    if (DEBUG) {
        print "return expr;";
        print stmt;
        print stmtRetExpr;
        print stmtPOST;
    }
    kfunc.curBB.hasReturn = true;
    kfunc.hasReturn = true;
    if (stmtRetExpr == null) {
        K_Ret inst = new K_Ret(new K_Retop(null));
        kfunc.curBB.insts.add(inst);
    } else {
        int espidx = stmt.getESPIDX();
        asm(stmtRetExpr, stmtRetExpr.toToken(), espidx);
        kfunc.storeKInst(K_RTNIDX, kfunc.getKInst(espidx));
        if (stmtPOST != null) {
            asmEXPR(stmtPost, espidx + 1);
        }
        K_Ret inst = new K_Ret(new K_Retop(kfunc.retval));
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asmYIELD(Stmt stmt) {
    /* TODO */
}
void Compiler.asmPRINT(Stmt stmt, int flag) {
    flag = flag | KFLAG_PF_BOL | KFLAG_PF_LINE;
    int uline = this.getCurrentUline();
    int espidx = stmt.getESPIDX();
    for(int i = 0; i < stmt.getStmtSize(); i++) {
        Token tkn = stmt.getT(i);
        if(tkn.getTT() != Token.TT_CONST || tkn.getD().class != String) {
            asm(stmt.getS(i), stmt.getS(i).toToken(), espidx + i);
        }
    }
    int mask = 0;
    String msg = "";
    for(int i = 0; i < stmt.getStmtSize(); i++) {
        Token tkn = stmt.getT(i);
        if(i == stmt.getStmtSize() - 1) {
            mask = mask | KFLAG_PF_EOL;
            //if(Stmt_isBreakPoint(stmt)) {
            //    mask = mask | KFLAG_PF_BREAK;
            //}
        }
        if(tkn.getTT() == Token.TT_CONST && String == (tkn).getD().class) {
            if(tkn.isPNAME()) { /* name= */
                msg = (tkn).getText();
                mask |= KFLAG_PF_NAME;
                continue;
            }
            int table_idx = kfunc.addConstTable(tkn.getText());
            opc = new K_CONSTop(table_idx, tkn.getText().ptr, kfunc.const_table);
            K_Value kvalue = kfunc.getKValue(espidx + i, String);
            K_Inst inst = new K_CONST(kvalue, String, opc, kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            opp = new K_PRINTop(inst, flag|mask, espidx+i, uline, msg);
            inst = new K_PRINT(String, opp, kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            flag = KFLAG_PF_NCOMMA;
        }
        else {
            Class c = stmt.getT(i).getT();
            if (!c.isUnboxType()) { c = Object; }
            K_Inst inst = kfunc.getKInst(espidx+i);
            opp = new K_PRINTop(inst, flag|mask, espidx+i, uline, msg);
            inst = new K_PRINT(c, opp, kfunc.curBB);
            kfunc.curBB.insts.add(inst);
            flag = 0;
        }
        mask = 0;
        msg  = "";
    }
}
void Compiler.asmASSURE(Stmt stmt, Stmt stmtInit, Stmt stmtBody) {
    print "assure";
    print stmtInit;
    print stmtBody;
}
void Compiler.asmASSERT(Stmt stmt, Stmt cond) {
    print "assert";
    print cond;
}
void Compiler.asmERR(Stmt stmt, Token tkERR) {
    print "err";
    print tkERR;
}

void Compiler.asmLETEXPR(Stmt stmt, int espidx, Token tkL, Stmt expr) {
    if (DEBUG) {
        print espidx;
        print tkL;
        print expr;
    }
    asm(expr, expr.toToken(), espidx);
    if (tkL.getTT() == Token.TT_FVAR) {
        kfunc.storeKInst(tkL.getTokenIndex(), kfunc.getKInst(espidx));
    } else {
        SFX ax = getsfx(tkL);
        K_Inst inst0 = kfunc.getKInst(ax.i);
        K_Inst inst1 = kfunc.getKInst(espidx);
        K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, inst1, ax.n), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asmCALL_sub(int espidx, Class rtype, Method mtd, boolean flag, int argc, int rix) {
    /*SCALL*/
    {
        int thisidx = espidx + K_CALLDELTA;
        int espshift = espidx + argc + K_CALLDELTA + 1;
        int isStatic = 0;
        if (flag) {
            isStatic = 1;
        }

        /* @Hidden Func.() */
        if (mtd.getMethodClass() == Func && mtd.getName() == "") {
            rtype = kfunc.getKInst(thisidx).type.getP1();
        }

        Array<K_Inst> args = [];
        for (int i = isStatic; i <= argc; i++) {
            K_Inst arg = kfunc.getKInst(thisidx + i);
            args.add(arg);
            if (DEBUG) {
                print arg != null;
                print "parans ", i;
            }
        }
        K_Value kvalue = kfunc.getKValue(thisidx + rix, rtype);
        K_Inst inst;
        if (mtd == method:Object.typeCheck) {
            inst = new K_TCHECK(kvalue, new K_TCHECKop(args[1], espidx), kfunc.curBB);
        } else {
            K_CALLop op;
            String mtdName = mtd.toString();
            if (isStatic == 1) {
                op = new K_StaticCallOp(mtdName, mtd, thisidx, espshift, rix);
            } else {
                op = new K_CallOp(mtdName, mtd, thisidx, espshift, rix);
            }
            inst = new K_CALL(kvalue, args, op, kfunc.curBB);
        }
        kfunc.curBB.insts.add(inst);
        if (rtype != null) {
            kfunc.storeKInst(thisidx + rix, inst);
        }
    }
}
void Compiler.asmFUNCCALL(Stmt stmt, int espidx, Method mtd, Class c, Class rclass, boolean stmt_isDYNCALL) {
    if (DEBUG) {
        print "funccall";
        print stmt;
        print espidx;
        print mtd;
        print mtd.getReturnType();
        print mtd.isStatic();
        print c;
        print stmt_isDYNCALL;
    }
    for (int i = 2; i < stmt.getStmtSize(); i++) {
        asm(stmt.getS(i), stmt.getS(i).toToken(), espidx + i + (K_CALLDELTA-1));
    }
    asm(stmt.getS(1), stmt.getS(1).toToken(), espidx + K_CALLDELTA);
    if (stmt_isDYNCALL) {
        int a = espidx + K_CALLDELTA;
        K_Inst thisObj = kfunc.getKInst(espidx);
        K_Value kval = kfunc.getKValue(a, c);
        K_Inst inst = new K_TR(kval, new K_TRop(thisObj, a, a - a, c, Stmt.CHKTYPE), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(a, inst);
    }
    asmCALL_sub(espidx, rclass, mtd, mtd.isStatic(), stmt.getStmtSize()-2, K_RTNIDX);
}
boolean Compiler.callparams_asm(Stmt stmt, int s, int local, Class cid, Method mtd) {
    int i;
    if (DEBUG) {
        print cid;
    }
    if (s == 1 && mtd.isStatic()) {
        s = 2;
    }
    /*TODO chkstack*/
    for (i = s; i < stmt.getStmtSize(); i++) {
        asm(stmt.getS(i), stmt.getS(i).toToken(), local + i + (K_CALLDELTA-1));
        K_Inst arg = kfunc.getKInst(local + i + K_CALLDELTA-1);
    }
    return true;
}

@Native String Compiler.getMnName(int mn);
@Native void Compiler.asmCALL2(Stmt stmt, int espidx);
void Compiler.asmCALL(Stmt stmt, int espidx, Token tkMTD, Method mtd, Class c) {
    if (DEBUG) {
        print "call";
        print stmt;
        print espidx;
        print tkMTD;
        print mtd;
        print c;
        print mtd.isStatic();
        print stmt.getStmtSize() - 2;
    }
    int mn = tkMTD.getMn();
    if (mtd.class != Method) {
        int argc = stmt.getStmtSize() - 1;
        Array<K_Inst> args = [];
        for (int i = 1; i < stmt.getStmtSize(); i++) {
            asm(stmt.getS(i), stmt.getS(i).toToken(), espidx + i + K_CALLDELTA-1);
            K_Inst arg = kfunc.getKInst(espidx + i + K_CALLDELTA-1);
            args.add(arg);
        }
        String mtdname;
        if (mn == Method.MN_get) {
            mtdname = "get";
        } else if (mn == Method.MN_set) {
            mtdname = "set";
        } else if (mn == Method.MN_getSize) {
            mtdname = "getSize";
        } else {
            mtdname = getMnName(mn);
            assert(mtdname != "");
        }
        int espshift = espidx + argc + K_CALLDELTA + 1;
        K_Inst ldinst = new K_LDMTD(new K_LDMTDop(espidx + K_CALLDELTA, Stmt.DYNMTD, c, mtdname, mtd, argc));
        kfunc.curBB.insts.add(ldinst);
        K_Value kvalue = kfunc.getKValue(espidx, dynamic);
        K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtdname, mtd, espidx+K_CALLDELTA, espshift, K_RTNIDX), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);

        return;
    }
    int deltaidx = mtd.indexOfGetterField();
    if (deltaidx != -1) {
        asm(stmt.getS(1), stmt.getS(1).toToken(), espidx + 1);
        Class retClass = mtd.getReturnType();
        SFX bx = new SFX(espidx+1, deltaidx);
        asm_smovx(espidx, retClass, bx);
        return;
    }
    deltaidx = mtd.indexOfSetterField();
    if (deltaidx != -1) {
        asm(stmt.getS(1), stmt.getS(1).toToken(), espidx+1);
        asm(stmt.getS(2), stmt.getS(2).toToken(), espidx+2);
        Class retClass = mtd.getReturnType();
        K_Inst inst0 = kfunc.getKInst(espidx+1);
        K_Inst inst1 = kfunc.getKInst(espidx+2);
        K_Inst inst = new K_SetField(new K_SetFieldOp(inst0, inst1, deltaidx), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        return;
    }

    Class retClass = mtd.getReturnType();
    if (mtd.getMethodClass() == Array) {
        Class p1 = c.getP1();
        if (mtd.getName() == "get") {
            asm(stmt.getS(1), stmt.getS(1).toToken(), espidx + 1);
            K_Inst va = kfunc.getKInst(espidx + 1);
            if (stmt.getS(2).toToken().getTT() == Token.TT_CONST) {
                K_Value v = kfunc.getKValue(espidx, p1);
                Object n = stmt.getS(2).toToken().getD();
                //if ((int)n < 0) {
                //    /* TODO L_USECALL */
                //}
                int table_idx = kfunc.addConstTable(n);
                K_Value kvalue = kfunc.getKValue(espidx + 1, Int);
                K_Inst vn = new K_CONST(kvalue, Int, new K_CONSTop(table_idx, 0, kfunc.const_table), kfunc.curBB);
                kfunc.curBB.insts.add(vn);
                K_Inst inst = new K_GETIDX(v, new K_GETIDXop(va, vn), kfunc.curBB);
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, inst);
            } else {
                K_Value v = kfunc.getKValue(espidx, p1);
                asm(stmt.getS(2), stmt.getS(2).toToken(), espidx + 2);
                K_Inst vn = kfunc.getKInst(espidx + 2);
                K_Inst inst = new K_GETIDX(v, new K_GETIDXop(va, vn), kfunc.curBB);
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, inst);
            }
            return;
        } else if (mtd.getName() == "set") {
            asm(stmt.getS(1), stmt.getS(1).toToken(), espidx + 1);
            K_Inst va = kfunc.getKInst(espidx + 1);
            asm(stmt.getS(3), stmt.getS(3).toToken(), espidx + 3);
            K_Inst vv = kfunc.getKInst(espidx + 3);
            if (stmt.getS(2).toToken().getTT() == Token.TT_CONST) {
                K_Value v = kfunc.getKValue(espidx, p1);
                Object n = stmt.getS(2).toToken().getD();
                //if ((int)n < 0) {
                //    /* TODO L_USECALL */
                //}
                int table_idx = kfunc.addConstTable(n);
                K_Value kvalue = kfunc.getKValue(espidx + 1, Int);
                K_Inst vn = new K_CONST(kvalue, Int, new K_CONSTop(table_idx, 0, kfunc.const_table), kfunc.curBB);
                kfunc.curBB.insts.add(vn);
                K_Inst inst = new K_SETIDX(v, new K_SETIDXop(va, vn, vv), kfunc.curBB);
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, vv);
            } else {
                K_Value v = kfunc.getKValue(espidx, p1);
                asm(stmt.getS(2), stmt.getS(2).toToken(), espidx + 2);
                K_Inst vn = kfunc.getKInst(espidx + 2);
                K_Inst inst = new K_SETIDX(v, new K_SETIDXop(va, vn, vv), kfunc.curBB);
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, vv);
            }
            return;
        }
        if (mtd.getName() == "set2" || mtd.getName() == "get2") {
            retClass = p1;
        }
    }
    if (callparams_asm(stmt, 1, espidx, c, mtd)) {
        asmCALL_sub(espidx, retClass, mtd, mtd.isStatic(), stmt.getStmtSize() - 2, K_RTNIDX);
    }
}
void Compiler.asmCALL1(Stmt stmt, int espidx, Stmt expr1, Stmt stmtPost) {
    if (DEBUG) {
        print "call";
        print stmt;
        print espidx;
        print expr1;
        print stmtPost;
    }
    asm(expr1, expr1.toToken(), espidx);
    //if (stmtPost.toToken() == null) { /* IS_Stmt(DP(stmt)->stmtPOST) */
    if (stmtPost.getClass() == Stmt) { /* IS_Stmt(DP(stmt)->stmtPOST) */
        stmtPost.setESPIDX(espidx + 1);
        asmEXPR(stmtPost, espidx + 1);
    }
}
void Compiler.asmBOX(Stmt stmt, int espidx, Class c, Stmt expr) {
    if (DEBUG) {
        print "box";
        print stmt;
        print espidx;
        print c;
        print expr;
    }
    K_Inst inst;
    asm(expr, expr.toToken(), espidx);
    if (c == Boolean) {
        K_Inst thisObj = kfunc.getKInst(espidx);
        K_Value vb = kfunc.getKValue(espidx, Object);
        inst = new K_TR(vb, new K_TRop(thisObj, espidx, espidx - espidx, c, Stmt.BBOX), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
    } else {
        addSafePoint(espidx + 1);
        K_Inst thisObj = kfunc.getKInst(espidx);
        K_Value vb = kfunc.getKValue(espidx, Object);
        inst = new K_TR(vb, new K_TRop(thisObj, espidx, espidx - espidx, c, Stmt.BOX), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
    }
    kfunc.storeKInst(espidx, inst);
}
void Compiler.asmOPR(Stmt stmt, int espidx, Method mtd, Class type, Stmt lhs, Stmt rhs) {
    if (DEBUG) {
        print "opr";
        print stmt;
    }

    if(type == Boolean && mtd.getName() == "not") {
        asm(lhs, lhs.toToken(), espidx+1);
        K_Inst inst_l = kfunc.getKInst(espidx+1);
        K_Value kval = kfunc.getKValue(espidx, type);
        K_Inst inst = new K_NOT(kval, type, new KUnaryInstOp(inst_l), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);
        return;
    } else if(type == Int || type == Float) {
        asm(lhs, lhs.toToken(), espidx + 1);
        K_Inst inst_l = kfunc.getKInst(espidx + 1);
        K_Inst inst_r = null;
        Token rhsTk = rhs.toToken();
        if(rhsTk.getTT() == Token.TT_CONST) {// const
            int table_idx = kfunc.addConstTable(rhsTk.getD());
            K_Value kval = kfunc.getKValue(espidx + 2, type);
            inst_r = new K_CONST(kval, type, new K_CONSTop(table_idx, 0, kfunc.const_table), kfunc.curBB);
            kfunc.curBB.insts.add(inst_r);
        } else if (rhs != null) {
            asm(rhs, rhs.toToken(), espidx + 2);
            inst_r = kfunc.getKInst(espidx + 2);
        }
        K_Inst inst = null;
        KBinaryInstOp op = new KBinaryInstOp(inst_l, inst_r);
        switch(mtd.getName()) {
            case "+":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_ADD(kval, type, op, kfunc.curBB);
                break;
            case "-":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_SUB(kval, type, op, kfunc.curBB);
                break;
            case "*":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_MUL(kval, type, op, kfunc.curBB);
                break;
            case "/":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_DIV(kval, type, op, kfunc.curBB);
                break;
            case "%":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_MOD(kval, type, op, kfunc.curBB);
                break;
            case "==":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_EQ(kval, Boolean, op, kfunc.curBB);
                break;
            case "!=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_NEQ(kval, Boolean, op, kfunc.curBB);
                break;
            case "<":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_LT(kval, Boolean, op, kfunc.curBB);
                break;
            case "<=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_LTE(kval, Boolean, op, kfunc.curBB);
                break;
            case ">":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_GT(kval, Boolean, op, kfunc.curBB);
                break;
            case ">=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_GTE(kval, Boolean, op, kfunc.curBB);
                break;
            case "&":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_AND(kval, type, op, kfunc.curBB);
                break;
            case "|":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_OR(kval, type, op, kfunc.curBB);
                break;
            case "^":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_XOR(kval, type, op, kfunc.curBB);
                break;
            case "<<":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_LSFT(kval, type, op, kfunc.curBB);
                break;
            case ">>":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_RSFT(kval, type, op, kfunc.curBB);
                break;
            case "---":
                K_Value kval = kfunc.getKValue(espidx, type);
                int table_idx = kfunc.addConstTable(0);
                assert(type == Int or type == Float);
                K_Value kvalue = kfunc.getKValue(espidx + 2, type);
                inst_r = new K_CONST(kvalue, type, new K_CONSTop(table_idx, 0, kfunc.const_table), kfunc.curBB);
                kfunc.curBB.insts.add(inst_r);
                op.inst1 = op.inst0;
                op.inst0 = inst_r;
                inst = new K_SUB(kval, type, op, kfunc.curBB);
                break;
            default:
                break;
        }
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);

        return;
    }
    asmCALL2(stmt, espidx);
}
void Compiler.asmNEW(Stmt stmt, int espidx, Class c, Method mtd) {
    if (DEBUG) {
        print "new";
        print stmt;
        print stmt.getStmtSize();
        print c;
        print espidx;
        print c;
        print mtd;
        print mtd.getName();
    }
    int thisidx = espidx + K_CALLDELTA;
    addSafePoint(espidx);
    if (stmt.getStmtSize() == 2 && mtd.getMethodClass() == Object && mtd.getName() == "new") {
        K_Value vb = kfunc.getKValue(espidx, c);
        K_Inst inst = new K_NEW(vb, new K_NEWop(espidx-thisidx, c, Stmt.NEW), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);
    } else {
        K_Value vb = kfunc.getKValue(thisidx, c);
        K_Inst inst = new K_NEW(vb, new K_NEWop(thisidx-thisidx, c, Stmt.NEW), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(thisidx, inst);
        callparams_asm(stmt, 2, espidx, c, mtd);
        asmCALL_sub(espidx, c, mtd, false, stmt.getStmtSize() - 2, K_RTNIDX);
    }
}
void Compiler.asmTCAST(Stmt stmt, int espidx, TypeMap tmr, Stmt expr, int fptr) {
    if (DEBUG) {
        print "tcast";
        print stmt;
        print espidx;
        print tmr, tmr.source, tmr.target, tmr.getPtr();
        print expr;
        print fptr;
    }
    asm(expr, expr.toToken(), espidx);
    K_Inst inst = kfunc.getKInst(espidx);
    K_Inst cast;
    if (tmr == null) {/* downcast */
        Token tkc = stmt.getS(0).toToken();
        Class c = tkc.getTokenClass();
        if (c.isUnboxType()) {
            throw new Exception();
        } else {
            K_Value v = kfunc.getKValue(espidx, Object);
            cast = new K_TR(v, new K_TRop(inst, espidx, 0, c, Stmt.CHKTYPE), kfunc.curBB);
        }
    } else {
        Class source = tmr.source;
        Class target = tmr.target;
        if (source == Int && target == Float) {
            K_Value v = kfunc.getKValue(espidx, target);
            cast = new K_CAST(v, new K_CASTop(inst, target, source), kfunc.curBB);
        } else if (source == Float && target == Int) {
            K_Value v = kfunc.getKValue(espidx, target);
            cast = new K_CAST(v, new K_CASTop(inst, target, source), kfunc.curBB);
        } else {
            K_Value v = kfunc.getKValue(espidx, target);
            cast = new K_CAST(v, new K_CASTop(inst, target, source, espidx, 0, espidx+1, tmr.getPtr(), fptr), kfunc.curBB);

        }
    }
    kfunc.curBB.insts.add(cast);
    kfunc.storeKInst(espidx, cast);
}
void Compiler.asmAND(Stmt stmt, int espidx) {
    if (DEBUG) {
        print "and";
        print stmt;
        print espidx;
    }
    int table_idx;
    int objptr = 0;
    K_Value kvalue;
    /* const true */
    table_idx = kfunc.addConstTable(true);
    kvalue = kfunc.getKValue(espidx, Boolean);
    K_Inst tInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
    kfunc.curBB.insts.add(tInst);

    /* const false */
    table_idx = kfunc.addConstTable(false);
    kvalue = kfunc.getKValue(espidx, Boolean);
    K_Inst fInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
    kfunc.curBB.insts.add(fInst);

    int bbssize = kfunc.bbs.size;
    int entryIdx = kfunc.curBB.bbidx;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> tupleList = [];
    K_BasicBlock bbMerge = new K_BasicBlock(kfunc.bbs.size);
    K_BasicBlock bbNext;
    kfunc.addBB(bbMerge, kfunc.bbs.size);

    int size = stmt.getStmtSize();
    for (int i = 0; i < size; i++) {
        bbNext = new K_BasicBlock(kfunc.bbs.size);
        kfunc.addBB(bbNext, kfunc.bbs.size);
        asm(stmt.getS(i), stmt.getS(i).toToken(), espidx);
        tupleList.add((kfunc.curBB, cloneRegTable()));
        K_Inst cond = kfunc.getKInst(espidx);
        K_Inst inst = new K_COND(new K_CONDop(cond, bbNext.bbidx, bbMerge.bbidx), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.curBB = bbNext;
    }
    tupleList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(bbMerge.bbidx, "merge"));
    kfunc.curBB.insts.add(jmp);
    kfunc.curBB = bbMerge;

    Array<K_Inst> regTableCont = createPhiArray(bbMerge, kfunc.register_table, bbNext, tupleList, espidx);
    kfunc.register_table = regTableCont;

    K_PHI phi = new K_PHI(espidx);
    for (int i = |tupleList|-1; i >= 0; i--) {
        if (DEBUG) {
            print i, tupleList[|tupleList|-1][0].bbidx, bbssize;
        }
        if (i == |tupleList|-1) {
            phi.addIncoming(kfunc, espidx, tInst, tupleList[i][0].bbidx, tupleList[i][0].movs);
        } else {
            phi.addIncoming(kfunc, espidx, fInst, tupleList[i][0].bbidx, tupleList[i][0].movs);
        }
    }

    if (DEBUG) {
        print kfunc.bbs[entryIdx].bbidx, kfunc.bbs[entryIdx].movs;
        print phi.dump();
    }
    bbMerge.phis[(String)espidx] = phi;
    kfunc.storeKInst(espidx, phi);
}
void Compiler.asmOR(Stmt stmt, int espidx) {
    if (DEBUG) {
        print "or";
        print stmt;
        print espidx;
    }
    K_Inst tInst, fInst;
    {
        int table_idx = kfunc.addConstTable(true);
        int objptr = 0;
        K_Value kvalue = kfunc.getKValue(espidx, Boolean);
        tInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
        kfunc.curBB.insts.add(tInst);
    }
    {
        int table_idx = kfunc.addConstTable(false);
        int objptr = 0;
        K_Value kvalue = kfunc.getKValue(espidx, Boolean);
        fInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table), kfunc.curBB);
        kfunc.curBB.insts.add(fInst);
    }
    int bbssize = kfunc.bbs.size;
    int entryIdx = kfunc.curBB.bbidx;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> tupleList = [];
    K_BasicBlock bbMerge = new K_BasicBlock(kfunc.bbs.size);
    K_BasicBlock bbNext;
    kfunc.addBB(bbMerge, kfunc.bbs.size);

    int size = stmt.getStmtSize();
    for (int i = 0; i < size; i++) {
        bbNext = new K_BasicBlock(kfunc.bbs.size);
        kfunc.addBB(bbNext, kfunc.bbs.size);
        asm(stmt.getS(i), stmt.getS(i).toToken(), espidx + i);
        tupleList.add((kfunc.curBB, cloneRegTable()));
        K_Inst cond = kfunc.getKInst(espidx + i);
        K_Inst inst = new K_COND(new K_CONDop(cond, bbMerge.bbidx, bbNext.bbidx), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.curBB = bbNext;
    }
    tupleList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(bbMerge.bbidx, "merge"));
    kfunc.curBB.insts.add(jmp);
    kfunc.curBB = bbMerge;

    Array<K_Inst> regTableCont = createPhiArray(bbMerge, kfunc.register_table, bbNext, tupleList, espidx);
    kfunc.register_table = regTableCont;

    K_PHI phi = new K_PHI(espidx);
    for (int i = |tupleList|-1; i >= 0; i--) {
        if (i == |tupleList|-1) {
            phi.addIncoming(kfunc, espidx, fInst, tupleList[i][0].bbidx, tupleList[i][0].movs);
        } else {
            phi.addIncoming(kfunc, espidx, tInst, tupleList[i][0].bbidx, tupleList[i][0].movs);
        }
    }

    bbMerge.phis[(String)espidx] = phi;
    kfunc.storeKInst(espidx, phi);
}
void Compiler.asmALT(Stmt stmt, int espidx) {
    /* TODO */
    throw new Exception();
}
void Compiler.asmTRI(Stmt stmt, int espidx, Stmt cond, Stmt lhs, Stmt rhs) {
    if (DEBUG) {
        print "tri";
        print espidx;
        print cond;
        print lhs;
        print rhs;
    }
    asm(cond, cond.toToken(), espidx);
    K_Inst inst_cond = kfunc.getKInst(espidx);
    asm(lhs, lhs.toToken(), espidx+1);
    K_Inst inst_l = kfunc.getKInst(espidx+1);
    asm(rhs, rhs.toToken(), espidx+2);
    K_Inst inst_r = kfunc.getKInst(espidx+2);
    assert (inst_l.type == inst_r.type);
    K_Value kval = kfunc.getKValue(espidx, inst_l.type);
    K_Inst inst = new K_SELECT(kval, inst_l.type, new K_SELECTop(inst_cond, inst_l, inst_r), kfunc.curBB);
    kfunc.curBB.insts.add(inst);
    kfunc.storeKInst(espidx, inst);
}
@Native Method Compiler.getSendMethod(Stmt stmt, int idx);
void Compiler.asmSEND(Stmt stmt, int espidx) {
    if (DEBUG) {
        print "send";
        print stmt;
        print espidx;
    }
    int thisidx = espidx + K_CALLDELTA;
    boolean cwbflag = false;
    if (stmt.getS(1).toToken().getTT() == Token.TT_ASIS) {
        isCWB = 1;
        cwbflag = true;
        K_Value kval = kfunc.getKValue(thisidx, OutputStream);
        K_Inst inst = new K_TR(kval, new K_TRop(null, thisidx, 0,
                    OutputStream, Stmt.CWB), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(thisidx, inst);
        this.cwb = inst;
    } else {
        asm(stmt.getS(1), stmt.getS(1).toToken(), thisidx);
    }
    for (int i = 2; i < stmt.getStmtSize(); i++) {
        if (stmt.getS(i).getStmtType() == Stmt.STT_W1) {
            /*TODO*/
            print "send todo";
            throw new Exception();
        } else {
            Method sendmtd = null;
            Class c = stmt.getS(i).toToken().getT();
            sendmtd = getSendMethod(stmt, i);
            asm(stmt.getS(i), stmt.getS(i).toToken(), thisidx + 1);
            asmCALL_sub(espidx, null, sendmtd, false, 1, -4);
        }
    }
    if (cwbflag) {
        isCWB = 0;
        this.cwb = null;
        K_Value kval = kfunc.getKValue(thisidx + K_RTNIDX, String);
        K_Inst thisObj = kfunc.getKInst(thisidx);
        K_Inst inst = new K_TR(kval, new K_TRop(thisObj, thisidx, K_RTNIDX,
                    String, Stmt.TOSTR), kfunc.curBB);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(thisidx + K_RTNIDX, inst);
    }
}
void Compiler.asmW1(Stmt stmt, int espidx, Method mtd, Token streamTk, Stmt expr) {
    print "W1";
    print stmt;
    print espidx;
    print mtd;
    print streamTk;
    print expr;
}

void Compiler.asmFMTCALL(Stmt stmt, int espidx) {
    /* TODO */
    print "fmtcall todo";
    throw new Exception();
}

