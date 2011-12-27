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
include "lib:gluelink";

DEBUG = false;
//USE_NONSSA = false;
USE_NONSSA = false;
//DEBUG = true;
FUNC_STATIC = 0;
FUNC_VIRTUAL = 1;
FUNC_VIRTUAL2 = 1;
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
    @Hidden Compiler() {
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

String getTypeName(Class type) {
    String res = (to String) type;
    return (res == "") ? "null" : res;
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
    int defidx;
    Class type;
    Value value;
    Value cached_value;

    /*for callInst*/
    Array<K_Inst> args;
    /*for dump const_value*/
    String dynName;

    @Virtual void codegen(Compiler asm) {
        print "**********";
    }
    @Virtual String dump () {
        return null;
    }
    void addDef(K_Value kvalue, int opidx) {
        if (kvalue != null) {
            if (true || kvalue.defPoint.indexOf(opidx) == -1) {
                defidx = kvalue.defCount;
                kvalue.defCount = defidx + 1;
                kvalue.defPoint.add(opidx);
            }
        }
    }
    void addUse(K_Opcode op, int opidx) {
        if (op.inst0 != null && op.inst1.kvalue != null) {
            if (true || op.inst0.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst0.kvalue.useCount = op.inst0.kvalue.useCount + 1;
                op.inst0.kvalue.usePoint.add(opidx);
            }
        }
        if (op.inst1 != null && op.inst1.kvalue != null) {
            if (true || op.inst1.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst1.kvalue.useCount = op.inst1.kvalue.useCount + 1;
                op.inst1.kvalue.usePoint.add(opidx);
            }
        }
        if (op.inst2 != null && op.inst2.kvalue != null) {
            if (true || op.inst2.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst2.kvalue.useCount = op.inst2.kvalue.useCount + 1;
                op.inst2.kvalue.usePoint.add(opidx);
            }
        }
        if (args != null) {
            foreach (K_Inst inst in args) {
                if (inst.kvalue != null && (true || inst.kvalue.usePoint.indexOf(opidx) == -1)) {
                    inst.kvalue.useCount = inst.kvalue.useCount + 1;
                    inst.kvalue.usePoint.add(opidx);
                }
            }
        }
    }
    String getName() {
        String res = "";
        String str_type = "";
        /* const value (not named) */
        if (kvalue == null) {
            return dynName;
        }
        str_type += kvalue.type;
        if (kvalue.type == Int) {
            res += "ival" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Float) {
            res += "fval" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Boolean) {
            res += "bval" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Array || str_type.indexOf("konoha.Array") == 0) {
            res += "ary" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Map || str_type.indexOf("konoha.Map") == 0) {
            res += "map" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Func || str_type.indexOf("konoha.Func") == 0) {
            res += "fnc" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Iterator || str_type.indexOf("konoha.Iterator") == 0) {
            res += "itr" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == String) {
            res += "str" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == dynamic) {
            res += "dyn" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == OutputStream) {
            res += "ous" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == InputStream) {
            res += "ins" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Script) {
            res += "script" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Namespace) {
            res += "ns" + kvalue.idx + "_" + defidx;
        } else if (kvalue.type == Object) {
            res += "obj" + kvalue.idx + "_" + defidx;
        } else {
            res += kvalue.type;
            res = res.split(".")[|res.split(".")|-1];
            res += kvalue.idx + "_" + defidx;
            res = res.convert(to:lower);
        }
        return res;
    }
}
class K_MOVop extends K_Opcode{
    int defcount;
    K_MOVop(K_Inst inst0, int defcount) {
        this.inst0 = inst0;
        this.defcount = defcount;
    }
}
class K_MOV extends K_Inst {
    int idx;
    K_MOVop op;
    K_MOV(K_Value kvalue, K_MOVop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
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
        idx = idx;
        bbs = [];
        insts = [];
    }
    void addIncoming(K_Function kfunc, int idx, K_Inst inst, int bbidx, Array<K_MOV> movs) {
        if (this.kvalue == null) {
            this.kvalue = inst.kvalue;
            this.type = inst.type;
            addDef(kvalue, idx);
        }
        //if (this.type.isUnboxType()) {
            if (USE_NONSSA) {
                K_MOV mov = new K_MOV(this.kvalue, new K_MOVop(inst, this.defidx), idx);
                movs.add(mov);
            }
        //}
        if (inst != null && inst.kvalue != null) {
            if (true || inst.kvalue.usePoint.indexOf(idx) == -1) {
                inst.kvalue.useCount = inst.kvalue.useCount + 1;
                inst.kvalue.usePoint.add(idx);
            }
        }
        bbs.add(bbidx);
        insts.add(inst);
    }
    @Override String dump() {
        String res = "";
        if (getName() == insts[0].getName()) {
            return null;
        }
        if (|bbs| == 1) {
            res += "\t" + getName () + " = mov " + getTypeName(type) + " " + insts[0].getName();
        } else {
            res += "\t" + getName () + " = phi [";
            for (int i = 0; i < |bbs|; i++) {
                res += "[" + insts[i].getName() + ", bb" + bbs[i] + "], ";
            }
            res = res[0 to |res|-3] + "]";
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
    K_BasicBlock (int bbidx) {
        hasReturn = false;
        hasBrBreakBlock = false;
        hasBrContinueBlock = false;
        this.phis = {};
        this.movs = [];
        this.insts = [];
        this.insts_safepoint = [];
        this.bbidx = bbidx;
        this.safepoint = -1;
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
    K_ARGUMENT(K_Value kvalue, K_ARGUMENTop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
    }
}
class K_Function {
    boolean undeveloped;
    String name;
    K_BasicBlock[] bbs;
    Class[] declareclass_func;
    Func<K_Function,Method, int=>void>[] klrasm;
    Array<dynamic> const_table;
    Array<K_Inst> register_table;
    Array<K_BasicBlock> breakpoint;
    Array<K_BasicBlock> continuepoint;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> breakList;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> continueList;
    Class retTy;
    boolean hasReturn;
    int isStatic;
    K_ARGUMENT[] funcargs;
    K_Inst retval;
    Map<String, K_Value> value_table;

    /*for SSA*/
    Int[][] linklist;
    Int[][] succ;
    Int[][] pred;
    Int[][] bucket;
    Int[][] aorig;
    Int[][] defsites;
    Int[][] phi; /*phi_value[bbidx] => Array<idx>*/
    Int[]   dfnum;
    Int[]   vertex;
    Int[]   semi;
    Int[]   parent;
    Int[]   ancestor;
    Int[]   best;
    Int[]   idom;
    Int[]   samedom;
    Int[]   df;
    K_BasicBlock curBB;
    String mtdName;
    Function func;

    K_Function(Method mtd) {
        this.declareclass_func = [];
        this.undeveloped = false;
        this.hasReturn = false;
        isStatic = mtd.isStatic() ? 1 : 0;
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
        return |const_table|-1;
    }
    void dumpConstTable() {
        for (int i = 0; i < |const_table|; i++) {
            print const_table[i];
        }
    }
    String dump() {
        String res = "";
        if (isStatic == 1) {
            res += "def " + getTypeName(retTy)  + " " + mtdName[mtdName.indexOf(".")+1 to |mtdName|-1] + " ( ";
        } else if (|funcargs| > 0) {
            res += "def " + getTypeName(retTy) + " " + mtdName[mtdName.indexOf(".")+1 to |mtdName|-1] + " " + funcargs[0].getName()  + " ( ";
        }
        String str = "";
        for (int i = 1 - isStatic; i < |funcargs|; i++) {
            str += getTypeName(funcargs[i].type) + " " + funcargs[i].getName() + " ";
        }
        str = (|str| > 0) ? str[0 to |str|-2] + " ) {" : " ) {";
        res += str;
        for (int i = 0; i < |bbs|; i++) {
            String bbStr = "\n";
            if (bbs[i] == null) continue;
            bbStr += "BasicBlock" + i;// + ":\tpred = ";
            //for (int j = 0; j < |pred[i]|; j++) {
            //    OUT<< "bb" + pred[i][j] + " ";
            //}
            bbStr += EOL;
            foreach(String s in bbs[i].phis.keys()) {
                String tmp = bbs[i].phis[s].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            for (int j = 0; j < |bbs[i].insts|-1; j++) {
                String tmp = bbs[i].insts[j].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            for (int j = 0; j < |bbs[i].movs|; j++) {
                String tmp = bbs[i].movs[j].dump();
                if (tmp != null) {
                    bbStr += tmp + "\n";
                }
            }
            bbStr += bbs[i].insts[|bbs[i].insts|-1].dump() + "\n"; //jmp
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
        if (idx < 0) { // will not happen
            return null;
        } else {
            check_or_expand(idx);
            if (register_table[idx] == null) { // argument
            } else {
                v = register_table[idx];
            }
            return v;
        }
    }

    K_Value getKValue(int idx, Class type) {
        this.addClass(type);
        K_Value res = value_table[(String)idx];
        String str_type1 = "";
        String str_type2 = "";
        if (res == null) {
            value_table[(String)idx] = new K_Value(idx, type);
        } else {
            str_type1 += res.type;
            str_type2 += type;
            boolean flag = res.type != type && 
                !(
                        str_type1.indexOf("konoha.Array") == 0 
                        && str_type2.indexOf("konoha.Array") == 0 
                        || str_type1.indexOf("konoha.Map") == 0 
                        && str_type2.indexOf("konoha.Map") == 0
                        || str_type1.indexOf("konoha.Func") == 0 
                        && str_type2.indexOf("konoha.Func") == 0
                        || str_type1.indexOf("konoha.Iterator") == 0 
                        && str_type2.indexOf("konoha.Iterator") == 0
                 );
            if (flag) {
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
class K_ADDop extends K_Opcode {
    K_ADDop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_ADD extends K_Inst {
    K_ADDop op;
    K_ADD(K_Value kvalue, Class type, K_ADDop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = add "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_SUBop extends K_Opcode {
    K_SUBop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_SUB extends K_Inst {
    K_SUBop op;
    K_SUB(K_Value kvalue, Class type, K_SUBop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = sub "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_MULop extends K_Opcode {
    K_MULop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_MUL extends K_Inst {
    K_MULop op;
    K_MUL(K_Value kvalue, Class type, K_MULop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);

    }
    @Override String dump() {
        return "\t" + getName() + " = mul "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_DIVop extends K_Opcode {
    K_DIVop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_DIV extends K_Inst {
    K_DIVop op;
    K_DIV(K_Value kvalue, Class type, K_DIVop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = div "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_MODop extends K_Opcode {
    K_MODop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_MOD extends K_Inst {
    K_MODop op;
    K_MOD(K_Value kvalue, Class type, K_MODop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = mod "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_EQop extends K_Opcode {
    K_EQop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_EQ extends K_Inst {
    K_EQop op;
    K_EQ(K_Value kvalue, Class type, K_EQop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = eq "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_NEQop extends K_Opcode {
    K_NEQop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_NEQ extends K_Inst {
    K_NEQop op;
    K_NEQ(K_Value kvalue, Class type, K_NEQop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = neq "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_LTop extends K_Opcode {
    K_LTop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_LT extends K_Inst {
    K_LTop op;
    K_LT(K_Value kvalue, Class type, K_LTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = lt "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_GTop extends K_Opcode {
    K_GTop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_GT extends K_Inst {
    K_GTop op;
    K_GT(K_Value kvalue, Class type, K_GTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = gt "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_LTEop extends K_Opcode {
    K_LTEop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_LTE extends K_Inst {
    K_LTEop op;
    K_LTE(K_Value kvalue, Class type, K_LTEop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = lte "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_GTEop extends K_Opcode {
    K_GTEop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_GTE extends K_Inst {
    K_GTEop op;
    K_GTE(K_Value kvalue, Class type, K_GTEop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = gte "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_ANDop extends K_Opcode {
    K_ANDop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_AND extends K_Inst {
    K_ANDop op;
    K_AND(K_Value kvalue, Class type, K_ANDop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = and "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_ORop extends K_Opcode {
    K_ORop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_OR extends K_Inst {
    K_ORop op;
    K_OR(K_Value kvalue, Class type, K_ORop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = or "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_NOTop extends K_Opcode {
    K_NOTop (K_Inst inst0) {
        this.inst0 = inst0;
    }
}
class K_NOT extends K_Inst {
    K_NOTop op;
    K_NOT(K_Value kvalue, Class type, K_NOTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = not "+ getTypeName(type) + " " + op.inst0.getName();
    }
}
class K_XORop extends K_Opcode {
    K_XORop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_XOR extends K_Inst {
    K_XORop op;
    K_XOR(K_Value kvalue, Class type, K_XORop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = xor "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_SELECTop extends K_Opcode {
    K_ORop (K_Inst inst0, K_Inst inst1, K_Inst inst2) {
        this.inst0 = inst0;
        this.inst1 = inst1;
        this.inst2 = inst2;
    }
}
class K_SELECT extends K_Inst {
    K_SELECTop op;
    K_SELECT(K_Value kvalue, Class type, K_SELECTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = select "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() + " " + op.inst2.getName();
    }
}
class K_LSFTop extends K_Opcode {
    K_LSFTop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_LSFT extends K_Inst {
    K_LSFTop op;
    K_LSFT(K_Value kvalue, Class type, K_LSFTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = lsft "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
class K_RSFTop extends K_Opcode {
    K_RSFTop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_RSFT extends K_Inst {
    K_RSFTop op;
    K_RSFT(K_Value kvalue, Class type, K_RSFTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = rsft "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName();
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
    K_CAST(K_Value kvalue, K_CASTop op, int idx) {
        this.kvalue = kvalue;
        this.type = op.tcid;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = cast "+ getTypeName(type) + " " +  op.inst0.getName();
    }
}
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
    K_JMP(K_JMPop op) {
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
    K_COND(K_CONDop op) {
        this.op = op;
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
    K_CALLop (String fname, Method mtd, int mtdNC, int thisidx, int espshift, int ftype, int rix, int flagStatic) {
        this.fname = fname;
        this.mtd   = mtd;
        this.mtdNC = mtdNC;
        this.thisidx = thisidx;
        this.espshift = espshift;
        this.ftype = ftype;
        this.rix = rix;
        this.flagStatic = flagStatic;
    }
}
class K_CALL extends K_Inst {
    K_CALLop op;
    K_CALL(K_Value kvalue, Array<K_Inst> args, K_CALLop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.args = args;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        String res = "\t";
        if (kvalue != null) {
            res += ((kvalue.type == null) ? "_" : getName()) + " = call " + getTypeName(kvalue.type) + " " + op.fname[op.fname.indexOf(".")+1 to |op.fname|-1] + " ( ";
        }
        for (int i = 0; i < |args|; i++) {
            res += args[i].getName() + " ";
        }
        res = res[0 to |res|-2] + " )";
        if (op.flagStatic == 0) {
            if (!args[0].kvalue.type.isUnboxType()) {
                res += " @nonstatic";
            } else {
                res += " @static";
            }
        } else {
            res += " @static";
        }
        return res;
    }
}
class K_PRINTop extends K_Opcode {
    int sfpidx;
    int opline;
    int fprint;
    K_PRINTop (K_Inst inst0, int fprint, int sfpidx, int opline) {
        this.inst0 = inst0;
        this.sfpidx = sfpidx;
        this.opline = opline;
        this.fprint = fprint;
    }
}
class K_PRINT extends K_Inst {
    K_PRINTop op;
    K_PRINT(Class type, K_PRINTop op, int idx) {
        this.type = type;
        this.op = op;
        addUse(op, idx);
    }
    @Override String dump() {
        return null;
    }
}

class K_TRop extends K_Opcode {
    int espidx;
    int rix;
    int cTBL;
    int ftr;
    K_TRop(K_Inst inst0, int espidx, int rix, int cTBL, int ftr) {
        this.espidx = espidx;
        this.inst0 = inst0;
        this.rix = rix;
        this.cTBL = cTBL;
        this.ftr = ftr;
    }
}
class K_TR extends K_Inst {
    K_TRop op;
    K_TR(K_Value kvalue, K_TRop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = " + getTRMethod() + " " + getTypeName(type) + " " + op.inst0.getName();
    }
    String K_TR.getTRMethod() {
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
    int cTBL;
    int ftr;
    K_NEWop(int rix, int cTBL, int ftr) {
        this.rix = rix;
        this.cTBL = cTBL;
        this.ftr = ftr;
    }
}
class K_NEW extends K_Inst {
    K_NEWop op;
    K_NEW(K_Value kvalue, K_NEWop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
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
    K_GETIDX(K_Value kvalue, K_GETIDXop op,int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
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
    K_SETIDX(K_Value kvalue, K_SETIDXop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
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
    K_CHKIDX(K_CHKIDXop op, int idx) {
        this.op = op;
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t_ = chkidx " + op.inst0.getName() + " " + op.inst1.getName();
    }
}
String escape(String str) {
    str = str.replace("\t", "\\t");
    str = str.replace("\n", "\\n");
    return str;
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
    K_CONST(K_Value kvalue, Class type, K_CONSTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
        dynName = "const " + getTypeName(type) + " " + "%s"(op.const_table[op.table_idx]);
    }

    String quote(dynamic value) {
        if(value.class == String) {
            String s = value;
            return  "\"" + escape(s) + "\"";
        } else if (value.class == Float) {
            Float f = value;
            return "%.20f"f;
        }else if(value.class == Array<dynamic>) {
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
    K_TCHECK(K_Value kvalue, K_TCHECKop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        if (op.inst0.class == K_CONST) {
            K_CONST inst = (K_CONST) op.inst0;
            Class c = inst.op.const_table[inst.op.table_idx];
            this.type = c;
        }
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = tcheck " + getTypeName(type) + " " + op.inst0.getName();
    }
}
class K_MOVxop extends K_Opcode {
    int bn;
    K_MOVxop(K_Inst inst0, int bn) {
        this.inst0 = inst0;
        this.bn = bn;
    }
}
class K_MOVx extends K_Inst {
    K_MOVxop op;
    K_MOVx(K_Value kvalue, K_MOVxop op, int idx) {
        this.kvalue = kvalue;
        if (kvalue == null) dynName = "movtmp";
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = getfield " + getTypeName(type) + " " + op.inst0.getName() + " " + op.bn;
    }
}
class K_xMOVop extends K_Opcode {
    int an;
    K_xMOVop(K_Inst inst0, K_Inst inst1, int an) {
        this.inst0 = inst0;
        this.inst1 = inst1;
        this.an = an;
    }
}
class K_xMOV extends K_Inst {
    K_xMOVop op;
    Value field_access_cached;
    K_xMOV(K_xMOVop op, int idx) {
        this.type = op.inst0.type;
        this.op = op;
        addUse(op, idx);
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
    K_NEXT(K_Value kvalue, K_NEXTop op, int idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
    }
    @Override String dump() {
        return "\t" + getName() + " = next " + getTypeName(type) + " " + op.inst0.getName() + " bb" + op.nextBB + " bb" + op.endBB;
    }
}

class K_TRY extends K_Inst {
    K_TRY() {
    }
    @Override String dump() {
        return null;
    }
}

class K_CATCH extends K_Inst {
    K_CATCH() {
    }
    @Override String dump() {
        return null;
    }
}

class K_THROW extends K_Inst {
    K_THROW() {
    }
    @Override String dump() {
        return null;
    }
}

class K_CHKSTACK extends K_Inst {
    K_CHKSTACK() {
    }
    @Override String dump() {
        return null;
    }
}

class K_ASSERT extends K_Inst {
    K_ASSERT() {
    }
    @Override String dump() {
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
    }
    @Override String dump() {
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
void Compiler.initFunc(K_Function func) {
    func.func = null;
}
void Compiler.common_init(Method mtd) {
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
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0));
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
        initFunc(kfunc);
        return;
    }
    if (mtd.isStatic() && gamma_hasFIELD()) {
        K_Value kval = kfunc.getKValue(0, Script);
        K_Inst inst = new K_TR(kval, new K_TRop(null, 0, 0, gamma_getThiscid().getClassTablePtr(), Stmt.NULL), 0);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(0, inst);
    }

    if (!mtd.isStatic()) {
        K_Value kvalue = kfunc.getKValue(0, mtd.getMethodClass());
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0));
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
    }
    for (int i = 0; i < |paramsclass|; i++) {
        Class j = paramsclass[i];
        K_Value kvalue = kfunc.getKValue(i+1, j);
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(i+1));
        kfunc.storeKInst(i+1, inst);
        kfunc.funcargs.add(inst);
    }
    for (int i = |paramsclass|+1; i < gamma_fvarsize(); i++) {
        Class c = gamma_gf_type(i);
        if (gamma_gf_fn(i) == 41 + 126 /* TODO FN_vargs */) {
            Class p1 = c.getP1();
            K_Value kvalue = kfunc.getKValue(i, p1);
            inst = new K_TR(kvalue, new K_TRop(null, i, i-i, p1.getClassTablePtr(), Stmt.VARGS));
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(i, inst);
            continue;
        }
        if (c.isUnboxType()) {
            int table_idx = kfunc.addConstTable(0);
            int objptr = 0;
            K_Value kvalue = kfunc.getKValue(i, c);
            K_CONST inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(i, inst);
        } else {
            K_Value kval = kfunc.getKValue(i, c);
            K_Inst inst = new K_TR(kval, new K_TRop(null, i, 0, c.getClassTablePtr(), Stmt.NULL), 0);
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
    common_init(mtd);
}

void Compiler.addSafePoint(int espidx) {
    if (kfunc.curBB.safepoint == -1) {
        kfunc.curBB.safepoint = espidx;
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
            K_CONST tmp = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, tmp, ax.n), 0);
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
            K_Inst tmp = new K_CONST(kvalue, btype, new K_CONSTop(table_idx, objptr, kfunc.const_table), 0);
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, tmp, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FVAR:
            int b = tkb.getTokenIndex();
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst1 = kfunc.getKInst(b);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FIELD:
            SFX bx = getsfx(tkb);
            K_Inst vb = kfunc.getKInst(bx.i);
            K_Value kvalue = kfunc.getKValue(espidx + 1, btype);
            K_Inst tmp = new K_MOVx(kvalue, new K_MOVxop(vb, bx.n), 0);
            kfunc.curBB.insts.add(tmp);
            K_Inst va = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(va, tmp, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(ax.i, inst);
            break;
        case Token.TT_SYSVAL:
            used_espidx = espidx;
            int sysid = tkb.getTokenIndex();
            Method mtd = system_method[sysid];
            Class rtype = system_method_class[sysid];
            int thisidx = espidx + K_CALLDELTA;
            int espshift = espidx + 0 + K_CALLDELTA + 1;
            int mtdptr = mtd.getPtr();
            String fname = mtd.toString();
            Array<K_Inst> args = [];
            K_Value kvalue = kfunc.getKValue(thisidx - 4, rtype);
            K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(fname[fname.indexOf(".")+1 to |fname|-1], mtd, mtdptr, thisidx, espshift, FUNC_STATIC, K_RTNIDX, 1));
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
            K_Inst inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(inst);
            K_Value vb = kfunc.getKValue(espidx, btype);
            inst = new K_TR(vb, new K_TRop(inst, espidx, espidx - espidx, btype.getClassTablePtr(), Stmt.PROP), 0);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(espidx, inst);
            break;
        default:
            break;
    }
    if (used_espidx != -1) {
        K_Inst inst0 = kfunc.getKInst(ax.i);
        K_Inst inst1 = kfunc.getKInst(espidx);
        K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, ax.n), 0);
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asm_smovx(int alocal, Class type, SFX bx) {
    K_Inst inst0 = kfunc.getKInst(bx.i);
    K_Value kvalue = kfunc.getKValue(alocal, type);
    K_Inst inst = new K_MOVx(kvalue, new K_MOVxop(inst0, bx.n));
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
            K_CONST inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table));
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
            K_CONST inst = new K_CONST(kvalue, type, new K_CONSTop(table_idx, objptr, kfunc.const_table));
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
            int mtdptr = mtd.getPtr();
            int isStatic = 1;
            Array<K_Inst> args = [];
            K_Value kvalue = kfunc.getKValue(thisidx - 4, rtype);

            if (DEBUG) {
                print "sysval", sysid;
                print sysid, mtd, mtdptr;
            }
            K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtd.toString(), mtd, mtdptr, thisidx, espshift, FUNC_STATIC, K_RTNIDX, 1));
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
            K_Inst inst = new K_CONST(kvalue, c, new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(inst);
            K_Value vb = kfunc.getKValue(espidx, type);
            inst = new K_TR(vb, new K_TRop(inst, espidx, espidx - espidx, type.getClassTablePtr(), Stmt.PROP), 0);
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
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, ax.n), 0);
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

    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbThen.bbidx, bbElse.bbidx, "if"));
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
    K_BasicBlock bbCond  = new K_BasicBlock(bbssize);
    K_BasicBlock bbBody  = new K_BasicBlock(bbssize + 1);
    K_BasicBlock bbBreak = new K_BasicBlock(bbssize + 2);
    kfunc.addBB(bbCond, bbssize);
    kfunc.addBB(bbBody, bbssize + 1);
    kfunc.addBB(bbBreak, bbssize + 2);

    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx, "while"));
    kfunc.curBB.insts.add(jmpCond);
    addSafePoint(espidx);
    Array<K_Inst> regTableEntry = kfunc.register_table;
    Array<K_PHI> regTablePhi = regTableToPHI(espidx, bbCond);
    kfunc.register_table = cloneTable(regTablePhi);
    // cond part
    kfunc.curBB = bbCond;
    asm(stmtC, stmtC.toToken(), espidx + 1);
    K_Inst inst = kfunc.getKInst(espidx + 1);
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx));
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
    K_BasicBlock bbBody  = new K_BasicBlock(bbssize);
    K_BasicBlock bbCond  = new K_BasicBlock(bbssize + 1);
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
    addSafePoint(espidx);
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
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx));
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

    K_BasicBlock bbCond     = new K_BasicBlock(bbssize);
    K_BasicBlock bbBody     = new K_BasicBlock(bbssize + 1);
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
    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbBody.bbidx, bbBreak.bbidx));
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
    addSafePoint(espidx);
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
        //kTerm *tkVar = tkNN(stmt, 0);
        //kStmtExpr *stmt1 = stmtNN(stmt, 1);
        //kStmtExpr *stmt2 = stmtNN(stmt, 2);
        //kStmtExpr *stmt3 = stmtNN(stmt, 3);
        //K_NEXTop(K_Inst inst0, int nextBB, int endBB, int b, int rix, int espshift)
    }

    int espidx = stmtItr.toToken().getTokenIndex();
    int varidx = tkVar.getTokenIndex();
    int bbssize = kfunc.bbs.size;
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
    K_Inst condnext = new K_NEXT(kvalue, new K_NEXTop(itrinst, bbBody.bbidx, bbBreak.bbidx, espidx, varidx - espidx, stmt.getESPIDX()));
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
    print stmt, flag;
    int espidx = stmt.getESPIDX();
    for(int i = 0; i < stmt.getStmtSize(); i++) {
        Token tkn = stmt.getT(i);
        Object data = tkn.getD();
        if(tkn.getTT() != Token.TT_CONST || data.class != String) {
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
            //TODO_ASM(P, _PRINTm, flag | mask, (tkn).getText(), 0);
            flag = KFLAG_PF_NCOMMA;
        }
        else {
            Class c = stmt.getT(i).getClass();
            if(c == Int) {
                //TODO_ASM(P, _PRINTi, flag | mask, msg, espidx+i);
            }
            else if(c == Float) {
                //TODO_ASM(P, _PRINTf, flag | mask, msg, espidx+i);
            }
            else if(c == Boolean) {
                //TODO_ASM(P, _PRINTb, flag | mask, msg, espidx+i);
            }
            else {
                //TODO_ASM(P, _PRINT, flag | mask, msg, espidx+i);
            }
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
        K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, ax.n), 0);
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asmCALL_sub(int espidx, Class rtype, Method mtd, boolean flag, int argc, int rix) {
    /*SCALL*/
    {
        int thisidx = espidx + K_CALLDELTA;
        int espshift = espidx + argc + K_CALLDELTA + 1;
        int mtdptr = mtd.getPtr();
        int isStatic = (flag) ? 1 : 0;
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
            inst = new K_TCHECK(kvalue, new K_TCHECKop(args[1], espidx), thisidx);
        } else {
            inst = new K_CALL(kvalue, args, new K_CALLop(mtd.toString(), mtd, mtdptr, thisidx, espshift, FUNC_STATIC, rix, isStatic));
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
        K_Inst inst = new K_TR(kval, new K_TRop(thisObj, a, a - a, c.getClassTablePtr(), Stmt.CHKTYPE), 0);
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
    if (mtd.getClass() != Method) {
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
        K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtdname, mtd, 0, espidx+K_CALLDELTA, espshift, FUNC_STATIC, K_RTNIDX, 0/* not static */));
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
        K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, deltaidx), 0);
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
                K_Inst vn = new K_CONST(kvalue, Int, new K_CONSTop(table_idx, 0, kfunc.const_table));
                kfunc.curBB.insts.add(vn);
                K_Inst inst = new K_GETIDX(v, new K_GETIDXop(va, vn));
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, inst);
            } else {
                K_Value v = kfunc.getKValue(espidx, p1);
                asm(stmt.getS(2), stmt.getS(2).toToken(), espidx + 2);
                K_Inst vn = kfunc.getKInst(espidx + 2);
                K_Inst inst = new K_GETIDX(v, new K_GETIDXop(va, vn));
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
                K_Inst vn = new K_CONST(kvalue, Int, new K_CONSTop(table_idx, 0, kfunc.const_table));
                kfunc.curBB.insts.add(vn);
                K_Inst inst = new K_SETIDX(v, new K_SETIDXop(va, vn, vv));
                kfunc.curBB.insts.add(inst);
                kfunc.storeKInst(espidx, vv);
            } else {
                K_Value v = kfunc.getKValue(espidx, p1);
                asm(stmt.getS(2), stmt.getS(2).toToken(), espidx + 2);
                K_Inst vn = kfunc.getKInst(espidx + 2);
                K_Inst inst = new K_SETIDX(v, new K_SETIDXop(va, vn, vv));
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
        inst = new K_TR(vb, new K_TRop(thisObj, espidx, espidx - espidx, c.getClassTablePtr(), Stmt.BBOX), 0);
        kfunc.curBB.insts.add(inst);
    } else {
        addSafePoint(espidx + 1);
        K_Inst thisObj = kfunc.getKInst(espidx);
        K_Value vb = kfunc.getKValue(espidx, Object);
        inst = new K_TR(vb, new K_TRop(thisObj, espidx, espidx - espidx, c.getClassTablePtr(), Stmt.BOX), 0);
        kfunc.curBB.insts.add(inst);
    }
    kfunc.storeKInst(espidx, inst);
}
void Compiler.asmOPR(Stmt stmt, int espidx, Method mtd, Class c, Stmt lhs, Stmt rhs) {
    if (DEBUG) {
        print "opr";
        print stmt;
    }

    Class type = c;
    if(type == Boolean && mtd.getName() == "not") {
        asm(lhs, lhs.toToken(), espidx+1);
        K_Inst inst_l = kfunc.getKInst(espidx+1);
        K_Value kval = kfunc.getKValue(espidx, type);
        K_Inst inst = new K_NOT(kval, type, new K_NOTop(inst_l), espidx);
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);
        return;
    }else if(type == Int || type == Float) {
        asm(lhs, lhs.toToken(), espidx + 1);
        K_Inst inst_l = kfunc.getKInst(espidx + 1);
        K_Inst inst_r = null;
        Token rhsTk = rhs.toToken();
        if(rhsTk.getTT() == Token.TT_CONST) {// const
            int table_idx = kfunc.addConstTable(rhsTk.getD());
            K_Value kval = kfunc.getKValue(espidx + 2, type);
            inst_r = new K_CONST(kval, type, new K_CONSTop(table_idx, 0, kfunc.const_table));
            kfunc.curBB.insts.add(inst_r);
        }else if (rhs != null) {
            asm(rhs, rhs.toToken(), espidx + 2);
            inst_r = kfunc.getKInst(espidx + 2);
        }
        K_Inst inst = null;
        switch(mtd.getName()) {
            case "+":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_ADD(kval, type, new K_ADDop(inst_l, inst_r), espidx);
                break;
            case "-":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_SUB(kval, type, new K_SUBop(inst_l, inst_r), espidx);
                break;
            case "*":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_MUL(kval, type, new K_MULop(inst_l, inst_r), espidx);
                break;
            case "/":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_DIV(kval, type, new K_DIVop(inst_l, inst_r), espidx);
                break;
            case "%":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_MOD(kval, type, new K_MODop(inst_l, inst_r), espidx);
                break;
            case "==":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_EQ(kval, Boolean, new K_EQop(inst_l, inst_r), espidx);
                break;
            case "!=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_NEQ(kval, Boolean, new K_NEQop(inst_l, inst_r), espidx);
                break;
            case "<":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_LT(kval, Boolean, new K_LTop(inst_l, inst_r), espidx);
                break;
            case "<=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_LTE(kval, Boolean, new K_LTEop(inst_l, inst_r), espidx);
                break;
            case ">":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_GT(kval, Boolean, new K_GTop(inst_l, inst_r), espidx);
                break;
            case ">=":
                K_Value kval = kfunc.getKValue(espidx, Boolean);
                inst = new K_GTE(kval, Boolean, new K_GTEop(inst_l, inst_r), espidx);
                break;
            case "&":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_AND(kval, type, new K_ANDop(inst_l, inst_r), espidx);
                break;
            case "|":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_OR(kval, type, new K_ORop(inst_l, inst_r), espidx);
                break;
            case "^":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_XOR(kval, type, new K_XORop(inst_l, inst_r), espidx);
                break;
            case "<<":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_LSFT(kval, type, new K_LSFTop(inst_l, inst_r), espidx);
                break;
            case ">>":
                K_Value kval = kfunc.getKValue(espidx, type);
                inst = new K_RSFT(kval, type, new K_RSFTop(inst_l, inst_r), espidx);
                break;
            case "---":
                K_Value kval = kfunc.getKValue(espidx, type);
                int table_idx = kfunc.addConstTable(0);
                K_Value kvalue = kfunc.getKValue(espidx + 2, Int);
                inst_r = new K_CONST(kvalue, type, new K_CONSTop(table_idx, 0, kfunc.const_table));
                kfunc.curBB.insts.add(inst_r);
                inst = new K_SUB(kval, type, new K_SUBop(inst_r, inst_l), espidx);
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
        K_Inst inst = new K_NEW(vb, new K_NEWop(espidx-thisidx, c.getClassTablePtr(), Stmt.NEW));
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);
    } else {
        K_Value vb = kfunc.getKValue(thisidx, c);
        K_Inst inst = new K_NEW(vb, new K_NEWop(thisidx-thisidx, c.getClassTablePtr(), Stmt.NEW));
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
        print tmr;
        print tmr.source;
        print tmr.target;
        print expr;
        print fptr;
        print tmr.getPtr();
    }
    Class source = tmr.source;
    Class target = tmr.target;
    if (source == Int && target == Float) {
        asm(expr, expr.toToken(), espidx);
        K_Value v = kfunc.getKValue(espidx, target);
        K_Inst inst = kfunc.getKInst(espidx);
        K_Inst cast = new K_CAST(v, new K_CASTop(inst, target, source, 0, 0, 0, 0, 0));
        kfunc.curBB.insts.add(cast);
        kfunc.storeKInst(espidx, cast);
    } else if (source == Float && target == Int) {
        asm(expr, expr.toToken(), espidx);
        K_Value v = kfunc.getKValue(espidx, target);
        K_Inst inst = kfunc.getKInst(espidx);
        K_Inst cast = new K_CAST(v, new K_CASTop(inst, target, source, 0, 0, 0, 0, 0));
        kfunc.curBB.insts.add(cast);
        kfunc.storeKInst(espidx, cast);
    } else {
        asm(expr, expr.toToken(), espidx);
        K_Value v = kfunc.getKValue(espidx, target);
        K_Inst inst = kfunc.getKInst(espidx);
        K_Inst cast = new K_CAST(v, new K_CASTop(inst, target, source, espidx, espidx-espidx, espidx+1, tmr.getPtr(), fptr));

        kfunc.curBB.insts.add(cast);
        kfunc.storeKInst(espidx, cast);
    }

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
    K_Inst tInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table));
    kfunc.curBB.insts.add(tInst);

    /* const false */
    table_idx = kfunc.addConstTable(false);
    kvalue = kfunc.getKValue(espidx, Boolean);
    K_Inst fInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table));
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
        K_Inst inst = new K_COND(new K_CONDop(cond, bbNext.bbidx, bbMerge.bbidx));
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
        tInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table));
        kfunc.curBB.insts.add(tInst);
    }
    {
        int table_idx = kfunc.addConstTable(false);
        int objptr = 0;
        K_Value kvalue = kfunc.getKValue(espidx, Boolean);
        fInst = new K_CONST(kvalue, Boolean, new K_CONSTop(table_idx, objptr, kfunc.const_table));
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
        K_Inst inst = new K_COND(new K_CONDop(cond, bbMerge.bbidx, bbNext.bbidx));
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
    K_Inst inst = new K_SELECT(kval, inst_l.type, new K_SELECTop(inst_cond, inst_l, inst_r));
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
        K_Inst inst = new K_TR(kval, new K_TRop(null, thisidx, thisidx - thisidx, OutputStream.getClass().getClassTablePtr(), Stmt.CWB), 0);
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
        K_Inst inst = new K_TR(kval, new K_TRop(thisObj, thisidx, K_RTNIDX, String.getClass().getClassTablePtr(), Stmt.TOSTR), 0);
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

