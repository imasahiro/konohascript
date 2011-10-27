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
//DEBUG = true;
TYPE_Tvoid = 0;
TYPE_Int = 5;
TYPE_Float = 6;
TYPE_Boolean = 3;
TYPE_Array = 13;
TYPE_Object = 55;
FUNC_STATIC = 0;
FUNC_VIRTUAL = 1;
FUNC_VIRTUAL2 = 1;
FUNC_FASTCALL = 2;
K_MTDIDX2 = -1;
K_RTNIDX = -4;
K_CALLDELTA = 4;
PHI_DEFIDX = -100;
FLAG_OBJECT_NULLOBJECT = 1 << 1;
NOT_SCAST = -1;

boolean is_Tunbox(int type) {
    boolean b = (type == TYPE_Int || type == TYPE_Float || type == TYPE_Boolean);
    return b;
}


class K_BasicBlock;
class K_Function;
class K_Inst;
class Compiler {
    Module m;
    ExecutionEngine ee;
    IRBuilder builder;
    Function  func;
    Value     ctx;
    Value     sfp;
    Value     rix;
    Method    mtd;
    BasicBlock entryBB;
    BasicBlock[] bblist;
    Type intTy, floatTy, boolTy, objectTy;
    Class[] paramsclass;
    Class   retclass;
    Map<String, Type> ktype;
    FunctionType funcTy;
    K_Function kfunc;
    Method[] system_method;
    Int[] system_method_cid;
    void constructKonohaTypes();
    @Hidden Compiler() {
        this.m = new Module("konoha");
        this.ee = m.createExecutionEngine();
        ktype = {};
        constructKonohaTypes();
        this.intTy = Type.getInt64Ty();
        this.boolTy = Type.getInt1Ty();
        this.floatTy = Type.getDoubleTy();
        this.objectTy = ktype["objectPtrTy"];
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
        this.system_method_cid = [
            -1, /*CTX*/
            -1, /*CTXIN*/
            31/*OutputSteram*/,
            31/*OutputSteram*/,
            -1,
            31/*OutputSteram*/,
            31/*OutputSteram*/,
            -1, /*SYS*/,
            -1, /*SCRIPT*/
            ];
    }
};

void Compiler.shiftesp(int shift);
//void Compiler.emit(Method mtd);
Type Compiler.convertType(int type) {
    switch (type) {
        case TYPE_Int:
            return intTy;
        case TYPE_Float:
            return floatTy;
        case TYPE_Boolean:
            return boolTy;
        default:
            return objectTy;
    }
}

String getTypeName(int type) {
    switch (type) {
        case TYPE_Int:
            return "Int";
        case TYPE_Float:
            return "Float";
        case TYPE_Boolean:
            return "Boolean";
        case TYPE_Array:
            return "Array";
        default:
            return "Object";
    }
}

int getcid(Class classType) {
    if (classType == null) return -1;
    if (classType == Int) return TYPE_Int;
    if (classType == Float) return TYPE_Float;
    if (classType == Boolean) return TYPE_Boolean;
    return TYPE_Object;
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
    int type;
    Array<Int> defPoint;
    Array<Int> usePoint;
    K_Value (int idx, int type) {
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
    int type;
    Value value;

    /*for callInst*/
    Array<K_Inst> args;
    /*for dump const_value*/
    String dynName;

    @Virtual void codegen(Compiler asm) {
    }
    @Virtual void dump () {
    }
    Value getLLVMValue (Compiler asm) {
        if (value == null) {
            value = new Argument(asm.convertType(type));
            return value;
        } else {
            return value;
        }
    }
    void setLLVMValue (Compiler asm, Value value) {
        if (this.value == null) {
            this.value = value;
        } else {
            this.value.replaceAllUsesWith (value);
            this.value = value;
        }
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
        /* const value (not named) */
        if (kvalue == null) {
            return dynName;
        }
        switch (kvalue.type) {
            case TYPE_Int:
                res += "ival" + kvalue.idx + "_" + defidx;
                break;
            case TYPE_Float:
                res += "fval" + kvalue.idx + "_" + defidx;
                break;
            case TYPE_Boolean:
                res += "bval" + kvalue.idx + "_" + defidx;
                break;
            case TYPE_Array:
                res += "aval" + kvalue.idx + "_" + defidx;
                break;
            default:
                res += "obj" + kvalue.idx;
                break;
        }
        return res;
    }
}

class K_PHI extends K_Inst {
    int idx;
    Array<Int> bbs;
    Array<K_Inst> insts;
    K_PHI(int idx) {
        idx = idx;
        bbs = [];
        insts = [];
    }
    void addIncoming(K_Inst inst, int bbidx, int idx) {
        if (this.kvalue == null) {
            this.kvalue = inst.kvalue;
            this.type = inst.kvalue.type;
        }
        addDef(kvalue, idx);
        if (inst != null && inst.kvalue != null) {
            if (true || inst.kvalue.usePoint.indexOf(idx) == -1) {
                inst.kvalue.useCount = inst.kvalue.useCount + 1;
                inst.kvalue.usePoint.add(idx);
            }
        }
        bbs.add(bbidx);
        insts.add(inst);
    }
    @Override void dump() {
        if (|bbs| == 1) {
            OUT << "\t" + getName () + " = " + insts[0].getName() << EOL;
        } else {
            OUT << "\t" + getName () + " = phi [";
            String res = "";
            for (int i = 0; i < |bbs|; i++) {
                res += "[" + insts[i].getName() + ", bb" + bbs[i] + "], ";
            }
            res = res[0 to |res|-3];
            OUT << res + "]" << EOL;
        }
    }
}
class K_BasicBlock {
    int bbidx;
    BasicBlock bb;
    boolean hasReturn;
    boolean hasBrBreakBlock;
    boolean hasBrContinueBlock;
    Array<K_Inst> insts;
    Map<String, K_PHI> phis;
    K_BasicBlock (int bbidx) {
        hasReturn = false;
        hasBrBreakBlock = false;
        hasBrContinueBlock = false;
        this.phis = {};
        this.insts = [];
        this.bbidx = bbidx;
    }
}
class K_Function {
    String name;
    K_BasicBlock[] bbs;
    Func<K_Function,Method, int=>void>[] klrasm;
    Array<dynamic> const_table;
    Array<K_Inst> register_table;
    Array<K_BasicBlock> breakpoint;
    Array<K_BasicBlock> continuepoint;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> breakList;
    Array<Tuple<K_BasicBlock, Array<K_Inst>>> continueList;
    int retTy;
    Array<K_Inst> funcargs;
    Array<Int> argsTy;
    K_Inst retval;
    Map<String, K_Value> value_table;

    /*for SSA*/
    Array<Array<Int>> linklist;
    Array<Array<Int>> succ;
    Array<Array<Int>> pred;
    Array<Array<Int>> bucket;
    Array<Array<Int>> aorig;
    Array<Array<Int>> defsites;
    Array<Array<Int>> phi; /*phi_value[bbidx] => Array<idx>*/
    Array<Int> dfnum;
    Array<Int> vertex;
    Array<Int> semi;
    Array<Int> parent;
    Array<Int> ancestor;
    Array<Int> best;
    Array<Int> idom;
    Array<Int> samedom;
    Array<Int> df;
    K_BasicBlock curBB;
    String mtdName;

    K_Function(Method mtd) {
        mtdName = mtd.toString();
        bbs = [new K_BasicBlock(0)];
        curBB = bbs[0];
        breakpoint = [];
        continuepoint = [];
        breakList = [];
        continueList = [];
        argsTy = [];
        Class[] params = mtd.getParamTypes();
        retTy = getcid(mtd.getReturnType());
        const_table = [];
        register_table = [];
        funcargs = [];
        value_table = {};
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
    void codegen(Compiler asm);
    void initKCode() {
        for (int i = 0; i < |linklist|; i++) {
            K_BasicBlock bb = new K_BasicBlock(i);
            bbs.add(bb);
        }
        for (int i = 0; i < |phi|; i++) {
            for (int j = 0; j < |phi[i]|; j++) {
                bbs[i].phis[(String)phi[i][j]] = new K_PHI(phi[i][j]);
            }
        }
    }
    int addConstTable(dynamic val) {
        if (const_table.indexOf(val) == -1) {
            const_table.add(val);
            return |const_table|-1;
        }
        return const_table.indexOf(val);
    }
    void dumpConstTable() {
        for (int i = 0; i < |const_table|; i++) {
            print const_table[i];
        }
    }
    void dump() {
        OUT << "def " + getTypeName(retTy) + " function " + mtdName + " (";
        String str = "";
        for (int i = 0; i < |funcargs|; i++) {
            str += funcargs[i].getName() + ", ";
        }
        str = (|str| > 0) ? str[0 to |str|-3] + ") {" : ") {";
        OUT << str << EOL;
        for (int i = 0; i < |bbs|; i++) {
            OUT << "  BasicBlock" + i + ":\tpred = ";
            //for (int j = 0; j < |pred[i]|; j++) {
            //    OUT<< "bb" + pred[i][j] + " ";
            //}
            OUT << EOL;
            foreach(String s in bbs[i].phis.keys()) {
                bbs[i].phis[s].dump();
            }
            for (int j = 0; j < |bbs[i].insts|; j++) {
                bbs[i].insts[j].dump();
            }
            OUT << EOL;
        }
        OUT << "}" << EOL;
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

    K_Value getKValue(int idx, int type) {
        K_Value res = value_table[(String)idx];
        if (res == null || (res.type != type)) {
            value_table[(String)idx] = new K_Value(idx, type);
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
}
class K_ADDop extends K_Opcode {
    K_ADDop (K_Inst inst0, K_Inst inst1) {
        this.inst0 = inst0;
        this.inst1 = inst1;
    }
}
class K_ADD extends K_Inst {
    K_ADDop op;
    K_ADD(K_Value kvalue, int type, K_ADDop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = add "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_SUB(K_Value kvalue, int type, K_SUBop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = sub "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_MUL(K_Value kvalue, int type, K_MULop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);

    }
    @Override void dump() {
        OUT << "\t" + getName() + " = mul "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_DIV(K_Value kvalue, int type, K_DIVop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = div "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_MOD(K_Value kvalue, int type, K_MODop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = mod "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_EQ(K_Value kvalue, int type, K_EQop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = eq "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_NEQ(K_Value kvalue, int type, K_NEQop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = neq "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_LT(K_Value kvalue, int type, K_LTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = lt "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_GT(K_Value kvalue, int type, K_GTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = gt "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_LTE(K_Value kvalue, int type, K_LTEop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = lte "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_GTE(K_Value kvalue, int type, K_GTEop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        if (kvalue == null) dynName = "cmptmp";
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = gte "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_AND(K_Value kvalue, int type, K_ANDop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = and "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_OR(K_Value kvalue, int type, K_ORop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = or "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_XOR(K_Value kvalue, int type, K_XORop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = xor "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_LSFT(K_Value kvalue, int type, K_LSFTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = lsft "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_RSFT(K_Value kvalue, int type, K_RSFTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = rsft "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
    }
}
class K_CASTop extends K_Opcode{
    int tcid;
    int scid;
    int b;
    int rix;
    int espshift;
    int cast;
    int fptr;
    K_CASTop (K_Inst inst0, int tcid, int scid, int b, int rix, int espshift, int cast, int fptr) {
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
    @Override void dump() {
        OUT << "\t" + getName() + " = cast " + getTypeName(type) + " " + op.inst0.getName() << EOL;
    }
}
class K_JMPop extends K_Opcode {
    int jmpidx;
    K_JMPop (int jmpidx) {
        this.jmpidx = jmpidx;
    }
}
class K_JMP extends K_Inst {
    K_JMPop op;
    K_JMP(K_JMPop op) {
        this.op = op;
    }
    @Override void dump() {
        OUT << "\tjmp bb" + op.jmpidx << EOL;
    }
}
class K_CONDop extends K_Opcode {
    int bbThen;
    int bbElse;
    K_CONDop (K_Inst inst0, int bbThen, int bbElse) {
        this.inst0 = inst0;
        this.bbThen = bbThen;
        this.bbElse = bbElse;
    }
}
class K_COND extends K_Inst {
    K_CONDop op;
    K_COND(K_CONDop op) {
        this.op = op;
    }
    @Override void dump() {
        OUT << "\tcond " + op.inst0.getName() + " bb" + op.bbThen + " bb" + op.bbElse << EOL;
    }
}
class K_CALLop extends K_Opcode {
    int mtdNC;
    int thisidx;
    int espshift;
    int ftype;
    int rix;
    int flagStatic;
    K_CALLop (int mtdNC, int thisidx, int espshift, int ftype, int rix, int flagStatic) {
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
    @Override void dump() {
        String res = "\t";
        if (kvalue != null) res += getName() + " = call " + getTypeName(kvalue.type) + " " + op.mtdNC + " (";
        foreach (K_Inst inst in args) {
            res += inst.getName() + ", ";
        }
        res = res[0 to |res|-3] + ")";
        OUT << res << EOL;
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
    K_PRINT(int type, K_PRINTop op, int idx) {
        this.type = type;
        this.op = op;
        addUse(op, idx);
    }
    @Override void dump() {
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
    @Override void dump() {
        OUT << "\t" + getName() + " = tr " + getTypeName(type) + " " + op.inst0.getName()<< EOL;
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
    @Override void dump() {
        OUT << "\t" + getName() + " = new " + getTypeName(type) << EOL;
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
    K_GETIDX(K_Value kvalue, K_GETIDXop op, idx) {
        this.kvalue = kvalue;
        this.type = kvalue.type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = getidx " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    @Override void dump() {
        OUT << "\t" + "setidx " + op.inst0.getName() + " " + op.inst1.getName() + " " + op.inst2.getName() << EOL;
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
    @Override void dump() {
        OUT << "\tchkidx " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
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
    K_CONST(K_Value kvalue, int type, K_CONSTop op, int idx) {
        this.kvalue = kvalue;
        this.type = type;
        this.op = op;
        addDef(kvalue, idx);
        addUse(op, idx);
        dynName = "%s"(op.const_table[op.table_idx]);
    }
    @Override void dump() {
        if (kvalue != null) {
            OUT << "\t" + getName() + " = const " + getTypeName(type) + " ";
            OUT << op.const_table[op.table_idx] << EOL;
        }
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
    @Override void dump() {
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
    K_xMOV(K_xMOVop op, int idx) {
        this.type = TYPE_Object;
        this.op = op;
        addUse(op, idx);
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
    @Override void dump() {
    }
}

class K_TRY extends K_Inst {
    K_TRY() {
    }
    @Override void dump() {
    }
}

class K_CATCH extends K_Inst {
    K_CATCH() {
    }
    @Override void dump() {
    }
}

class K_THROW extends K_Inst {
    K_THROW() {
    }
    @Override void dump() {
    }
}

class K_CHKSTACK extends K_Inst {
    K_CHKSTACK() {
    }
    @Override void dump() {
    }
}

class K_ASSERT extends K_Inst {
    K_ASSERT() {
    }
    @Override void dump() {
    }
}
class K_LDMTDop extends K_Opcode {
    int ldmtd;
    int opline;
    K_LDMTDop(int ldmtd, int opline) {
        this.ldmtd = ldmtd;
        this.opline = opline;
    }
}
class K_LDMTD extends K_Inst {
    K_LDMTDop op;
    K_LDMTD(K_LDMTDop op) {
        this.op = op;
    }
    @Override void dump() {
    }
}
class K_ARGUMENTop extends K_Opcode {
    int argidx;
    K_ARGUMENTop(int argidx) {
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
class K_RETop extends K_Opcode {
    K_RETop(K_Inst inst0) {
        this.inst0 = inst0;
    }
}
class K_RET extends K_Inst {
    K_RETop op;
    K_RET(K_RETop op) {
        this.op = op;
    }
    @Override void dump() {
        String name = "";
        if (op.inst0 != null) name = op.inst0.getName();
        OUT << "\treturn " + name << EOL;
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

int getcid(Class classType) {
    if (classType == null) return -1;
    if (classType == Int) return TYPE_Int;
    if (classType == Float) return TYPE_Float;
    if (classType == Array) return TYPE_Array;
    if (classType == Boolean) return TYPE_Boolean;
    return TYPE_Object;
}

void Compiler.init(Method mtd) {
    this.mtd = mtd;
    func = Function.create("_", this.funcTy, m);
    bblist = [];
    Array<Value> vargs = func.getArguments();
    if (DEBUG) {
        vargs[0].setName("ctx");
        vargs[1].setName("sfp");
        vargs[2].setName("rix");
        print mtd;
        print mtd.getName();
        print mtd.getReturnType();
        print mtd.getParamTypes();
        print mtd.toString();
    }
    ctx = vargs[0];
    sfp = vargs[1];
    rix = vargs[2];
    paramsclass = mtd.getParamTypes();
    retclass    = mtd.getReturnType();
    kfunc = new K_Function(mtd);

    if (mtd.toString() == "global.Script." || mtd.toString() == "main.Script.") {
        K_Value kvalue = kfunc.getKValue(0, TYPE_Object);
        K_Inst inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0));
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
        return;
    }
    if (!mtd.isStatic()) {
        print "global";
        K_Value kvalue = kfunc.getKValue(0, TYPE_Object);
        K_Inst inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(0));
        kfunc.storeKInst(0, inst);
        kfunc.funcargs.add(inst);
    }
    for (int i = 0; i < |paramsclass|; i++) {
        int j = getcid(paramsclass[i]);
        K_Value kvalue = kfunc.getKValue(i+1, j);
        K_ARGUMENT inst = new K_ARGUMENT(kvalue, new K_ARGUMENTop(i+1));
        kfunc.storeKInst(i+1, inst);
        kfunc.funcargs.add(inst);
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
            phi.addIncoming(kfunc.register_table[i], kfunc.curBB.bbidx);
            res.add(phi);
            bb.phis[(String)i] = phi;
        }
    }
    return res;
}
void Compiler.createPhiArrayBackEdge(Array<K_PHI> phis, Array<K_Inst> regTableCont, K_BasicBlock bb, int espidx) {
    for (int i = 0; i < espidx; i++) {
        if (phis[i] != null) {
            /*TODO Support K_Inst != K_PHI*/
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
                phis[i].addIncoming(regTableCont[i], bb.bbidx);
                for (int j = 0; j < |kfunc.continueList|; j++) {
                    phis[i].addIncoming(kfunc.continueList[j][1][i], kfunc.continueList[j][0].bbidx);
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
        if (flag) {
            res.add(regTableCont[i]);
        } else {
            K_PHI phi = new K_PHI(i);
            phi.addIncoming(regTableCont[i], bbCont.bbidx);
            for (int j = 0; j < |breakList|; j++) {
                Tuple<K_BasicBlock, K_Inst[]> tuple = breakList[j];
                phi.addIncoming(tuple[1][i], tuple[0].bbidx);
            }
            res.add(phi);
            bb.phis[(String)i] = phi;
        }
    }
    return res;
}
void Compiler.shiftesp(int shift) {
    if (shift > 0) {
        Value vesp = builder.createStructGEP(ctx, 7);
        Value vsfp = builder.createConstGEP1_32(sfp, shift);
        builder.createStore(vsfp, vesp);
    }
}
SFX getsfx(Token tk) {
    int i = 0;
    int n = tk.getTokenIndex();
    if (typeof(tk.getD()) == typeof(tk) && getTT(tk.getD()) == TT_FVAR) {
        i = tk.getD().getTokenIndex();
    }
    return new SFX(i, n);
}
@Native void Compiler.asmEXPR(Stmt stmt, int espidx);
@Native void Compiler.debug();

void Compiler.asm_xmov(SFX ax, Token tkb, int espidx) {
    int btype = tkb.getT();
    int used_espidx = -1;
    switch (tkb.getTT()) {
        case Token.TT_NULL:
            /* TODO overwriting default null value */
            Class c = tkb.getTokenClass();
            Object v = c.getNullValue();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            K_CONST tmp = new K_CONST(null, getcid(c), new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, tmp, ax.n), 0);
            kfunc.curBB.insts.add(inst);

            break;
        case Token.TT_CID:
        case Token.TT_CONST:
            Object v = tkb.getD();
            int table_idx;
            int objptr = 0;
            if (is_Tunbox(btype)) {
                table_idx = kfunc.addConstTable(v);
            } else {
                objptr = v.getPtr();
                table_idx = kfunc.addConstTable(v);
            }
            K_Inst tmp = new K_CONST(null, btype, new K_CONSTop(table_idx, objptr, kfunc.const_table), 0);
            kfunc.curBB.insts.add(tmp);
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, tmp, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FVAR:
            print "TT_FVAR";
            int b = tkb.getTokenIndex();
            K_Inst inst0 = kfunc.getKInst(ax.i);
            K_Inst inst1 = kfunc.getKInst(b);
            K_Inst inst = new K_xMOV(new K_xMOVop(inst0, inst1, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_FIELD:
            print "TT_FIELD";
            SFX bx = getsfx(tkb);
            K_Inst vb = kfunc.getKInst(bx.i);
            K_Inst tmp = new K_MOVx(null, new K_MOVxop(vb, bx.n), 0);
            K_Inst va = kfunc.getKInst(ax.i);
            K_Inst inst = new K_xMOV(new K_xMOVop(va, tmp, ax.n), 0);
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(ax.i, inst);
            break;
        case Token.TT_SYSVAL:
            print "sysval";
            int sysid = tkb.getTokenIndex();
            Method mtd = system_method[sysid];
            int rtype = system_method_cid[sysid];
            int thisidx = espidx + K_CALLDELTA;
            int espshift = espidx + 0 + K_CALLDELTA + 1;
            int mtdptr = mtd.getPtr();
            Array<K_Inst> args = [];
            K_Value kvalue = kfunc.getKValue(thisidx - 4, rtype);

            K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtdptr, thisidx, espshift, FUNC_STATIC, K_RTNIDX, 1));
            kfunc.curBB.insts.add(inst);
            break;
        case Token.TT_PROPN:
            print "prop";
            break;
        default:
            break;
    }
    if (used_espidx != -1) {

    }
}
void Compiler.asm_smovx(int alocal, int type, SFX bx) {
    K_Inst inst0 = kfunc.getKInst(bx.i);
    K_Value kvalue = kfunc.getKValue(alocal, type);
    K_Inst inst = new K_MOVx(kvalue, new K_MOVxop(inst0, bx.n));
    kfunc.curBB.insts.add(inst);
    kfunc.storeKInst(alocal, inst);
}
void Compiler.asm_smov(int alocal, Token tk) {
    int type = tk.getT();
    //print "hi, smov";
    switch(tk.getTT()) {
        case Token.TT_ASIS:
            break;
        case Token.TT_NULL:
            /* TODO overwriting default null value */
            Class c = tk.getTokenClass();
            Object v = c.getNullValue();
            int table_idx = kfunc.addConstTable(v);
            int objptr = v.getPtr();
            K_Value kvalue = kfunc.getKValue(alocal, getcid(c));
            K_CONST inst = new K_CONST(kvalue, getcid(c), new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(alocal, inst);
            break;
        case Token.TT_CID:
        case Token.TT_CONST:
            Object v = tk.getD();
            int table_idx = kfunc.addConstTable(v);
            int objptr = 0;
            if (!is_Tunbox(type)) {
                objptr = v.getPtr();
            }
            K_Value kvalue = kfunc.getKValue(alocal, type);
            K_CONST inst = new K_CONST(kvalue, type, new K_CONSTop(table_idx, objptr, kfunc.const_table));
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(alocal, inst);
            break;
        case Token.TT_FVAR:
            int b = tk.getTokenIndex();
            //print "nmov ", alocal, b;
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
            int rtype = system_method_cid[sysid];
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
            K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtdptr, thisidx, espshift, FUNC_STATIC, K_RTNIDX, 1));
            kfunc.curBB.insts.add(inst);
            kfunc.storeKInst(thisidx + K_RTNIDX, inst);
            break;
        case Token.TT_PROPN:
            print "prop";
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
void Compiler.emit(Method mtd) {
    if (!kfunc.bbs[kfunc.bbs.size-1].hasReturn) {
        K_RET inst = new K_RET(new K_RETop(null));
        kfunc.bbs[kfunc.bbs.size-1].insts.add(inst);
    }
    kfunc.codegen(this);
    if (DEBUG) {
        kfunc.dump();
        func.dump();
    }
    mtd.setFunction(ee.getPointerToFunction(m, func));
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
    kfunc.bbs.add(bbThen, bbElse);

    K_Inst condjmp = new K_COND(new K_CONDop(inst, bbThen.bbidx, bbElse.bbidx));
    kfunc.curBB.insts.add(condjmp);

    kfunc.curBB = bbThen;
    kfunc.register_table = regTableThen;
    asmBlock(stmtThen);
    regTableThen = kfunc.register_table;
    bbThen = kfunc.curBB;
    if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock) {
        K_Inst jmp = new K_JMP(new K_JMPop(bb.bbidx));
        kfunc.curBB.insts.add(jmp);
    }

    kfunc.curBB = bbElse;
    kfunc.register_table = regTableElse;
    asmBlock(stmtElse);
    regTableElse = kfunc.register_table;
    bbElse = kfunc.curBB;
    if (!bbElse.hasReturn && !bbElse.hasBrContinueBlock && !bbElse.hasBrContinueBlock) {
        K_Inst jmp = new K_JMP(new K_JMPop(bb.bbidx));
        kfunc.curBB.insts.add(jmp);
    }

    /*PHI Node*/
    Array<K_Inst> regTableMerge = [];
    if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock && !bbElse.hasReturn && !bbElse.hasBrContinueBlock && !bbElse.hasBrBreakBlock) {
        for (int i = 0; i < size; i++) {
            if (regTableThen[i] != regTableElse[i] && regTableThen[i] != null && regTableElse[i] != null) {
                K_PHI phi = new K_PHI(i);
                phi.addIncoming(regTableThen[i], bbssize);
                phi.addIncoming(regtableElse[i], bbssize+1);
                bb.phis[(String)i] = phi;
                regTableMerge.add(phi);
            } else if (regTableThen[i] != null){
                regTableMerge.add(regTableThen[i]);
            } else {
                regTableMerge.add(regTableElse[i]);
            }
        }
        kfunc.register_table = regTableMerge;
        kfunc.curBB = bb;
        kfunc.bbs.add(bb);
    } else if (!bbThen.hasReturn && !bbThen.hasBrBreakBlock && !bbThen.hasBrContinueBlock) {
        regTableMerge = regTableThen;
        kfunc.register_table = regTableMerge;
        kfunc.curBB = bb;
        kfunc.bbs.add(bb);
    } else if (!bbElse.hasReturn && !bbElse.hasBrBreakBlock && !bbElse.hasBrContinueBlock) {
        regTableMerge = regtableElse;
        kfunc.register_table = regTableMerge;
        kfunc.curBB = bb;
        kfunc.bbs.add(bb);
    }
}
void Compiler.asmSWITCH(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    print "switch";
    print stmtC;
    print stmtBody;
}
void Compiler.asmWHILE(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    print "while";
    print stmt;
    print stmtC;
    print stmtBody;
    int espidx = stmt.getESPIDX();

    K_BasicBlock bbCond  = new K_BasicBlock(kfunc.bbs.size);
    K_BasicBlock bbBody  = new K_BasicBlock(kfunc.bbs.size + 1);
    K_BasicBlock bbBreak = new K_BasicBlock(kfunc.bbs.size + 2);
    kfunc.bbs.add(bbCond, bbBody, bbBreak);

    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx));
    kfunc.curBB.insts.add(jmpCond);
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
    print "do-while";
    print stmt;

    K_BasicBlock bbBody  = new K_BasicBlock(kfunc.bbs.size);
    K_BasicBlock bbCond  = new K_BasicBlock(kfunc.bbs.size + 1);
    K_BasicBlock bbBreak = new K_BasicBlock(kfunc.bbs.size + 2);
    kfunc.bbs.add(bbBody, bbCond, bbBreak);
    int espidx = stmt.getESPIDX();

    K_Inst jmpBody = new K_JMP(new K_JMPop(bbBody.bbidx));
    kfunc.curBB.insts.add(jmpBody);
    Array<K_Inst> regTableEntry = kfunc.register_table;
    // body part
    Array<K_PHI> regTablePhi = regTableToPHI(espidx, bbBody);
    kfunc.register_table = cloneTable(regTablePhi);
    kfunc.breakpoint.add(bbBreak);
    kfunc.continuepoint.add(bbCond);
    kfunc.curBB = bbBody;
    asmBlock(stmtBody);
    kfunc.breakpoint.pop();
    kfunc.continuepoint.pop();

    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx));
    kfunc.curBB.insts.add(jmpCond);
    // cond part
    Array<K_Inst> regTableCont = createPhiArray(bbCond, kfunc.register_table, kfunc.curBB, kfunc.continueList, espidx);
    kfunc.continueList = [];
    kfunc.register_table = regTableCont;
    kfunc.curBB = bbCond;
    asm(stmtC, stmtC.toToken(), stmt.getESPIDX());
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

    K_BasicBlock bbCond     = new K_BasicBlock(kfunc.bbs.size);
    K_BasicBlock bbContinue = new K_BasicBlock(kfunc.bbs.size + 1);
    K_BasicBlock bbBody     = new K_BasicBlock(kfunc.bbs.size + 2);
    K_BasicBlock bbBreak    = new K_BasicBlock(kfunc.bbs.size + 3);
    if (DEBUG) {
        print bbBreak.bbidx;
    }
    kfunc.bbs.add(bbCond, bbContinue, bbBody, bbBreak);
    int espidx = stmt1.getESPIDX();

    // init part
    asmBlock(stmt1);
    K_Inst jmpCond = new K_JMP(new K_JMPop(bbCond.bbidx));
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
        K_Inst jmpC = new K_JMP(new K_JMPop(bbContinue.bbidx));
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
    kfunc.curBB.insts.add(jmpCond);
    createPhiArrayBackEdge(regTablePhi, kfunc.register_table, bbContinue, espidx);
    // break part
    Array<K_Inst> regTableBreak = createPhiArray(bbBreak, regTableCond, bbCond, kfunc.breakList, espidx);
    kfunc.breakList = [];
    kfunc.register_table = regTableBreak;
    kfunc.curBB = bbBreak;
}
void Compiler.asmFOREACH(Stmt stmt, Token tkVar, Stmt stmtItr, Stmt stmtBody, Stmt stmtVar) {
    print "foreach";
    print tkVar;
    print stmtItr;
    print stmtBody;
    print stmtVar;
}
void Compiler.asmBREAK(Stmt stmt, Stmt stmtLabel) {
    print "break";
    print stmtLabel;
    kfunc.breakList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(kfunc.breakpoint[|kfunc.breakpoint|-1].bbidx));
    kfunc.curBB.insts.add(jmp);
    kfunc.curBB.hasBrBreakBlock = true;
}
void Compiler.asmCONTINUE(Stmt stmt, Stmt stmtLabel) {
    print "continue";
    print stmtLabel;
    kfunc.continueList.add((kfunc.curBB, cloneRegTable()));
    K_Inst jmp = new K_JMP(new K_JMPop(kfunc.continuepoint[|kfunc.continuepoint|-1].bbidx));
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
void Compiler.asmRETURN(Stmt stmt, Stmt stmtRetExpr) {
    kfunc.curBB.hasReturn = true;
    if (stmtRetExpr == null) {
        K_RET inst = new K_RET(new K_RETop(null));
        kfunc.curBB.insts.add(inst);
        if (DEBUG) {
            print "return;";
        }
    } else {
        if (DEBUG) {
            print "return expr;";
            print stmt;
            print stmtRetExpr;
        }
        int espidx = stmt.getESPIDX();
        //print stmtRetExpr.toToken();
        asm(stmtRetExpr, stmtRetExpr.toToken(), espidx);
        kfunc.storeKInst(K_RTNIDX, kfunc.getKInst(espidx));
        K_RET inst = new K_RET(new K_RETop(kfunc.retval));
        kfunc.curBB.insts.add(inst);
    }
}
void Compiler.asmYIELD(Stmt stmt) {
    /* TODO */
}
void Compiler.asmPRINT(Stmt stmt) {
    /* TODO */
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
    print "Hi";
    print espidx;
    print tkL;
    print expr;
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
void Compiler.asmFUNCCALL(Stmt stmt, int espidx, Method mtd, Class c, Stmt stmt) {
    if (DEBUG) {
        print "funccall";
        print stmt;
        print espidx;
        print mtd;
        print c;
        print stmt;
    }
    print "*****************TODO*****************";
}
boolean Compiler.callparams_asm(Stmt stmt, int s, int local, int cid, Method mtd) {
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
    }
    return true;
}
void Compiler.asmCALL_sub(int espidx, int rtype, Method mtd, boolean flag, int argc) {
    /*TODO*/
    //if (Method_isFinal(mtd) || isStatic) {
    /*SCALL*/
    {
        int thisidx = espidx + K_CALLDELTA;
        int espshift = espidx + argc + K_CALLDELTA + 1;
        int mtdptr = mtd.getPtr();
        int isStatic = (flag) ? 1 : 0;
        Array<K_Inst> args = [];
        for (int i = isStatic; i <= argc; i++) {
            if (DEBUG) {
                print "parans ", i;
            }
            K_Inst arg = kfunc.getKInst(thisidx + i);
            args.add(arg);
        }
        K_Value kvalue = null;
        kvalue = kfunc.getKValue(thisidx - 4, rtype);
        K_Inst inst = new K_CALL(kvalue, args, new K_CALLop(mtdptr, thisidx, espshift, FUNC_STATIC, K_RTNIDX, isStatic));
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(thisidx + K_RTNIDX, inst);
    }
    //}
}
void Compiler.asmCALL(Stmt stmt, int espidx, Token tkMTD, Method mtd, int cid) {
    if (DEBUG) {
        print "call";
        print stmt;
        print espidx;
        print tkMTD;
        print mtd;
        print cid;
        print mtd.isStatic();
        print stmt.getStmtSize() - 2;
    }
    if (callparams_asm(stmt, 1, espidx, cid, mtd)) {
        asmCALL_sub(espidx, getcid(mtd.getReturnType()), mtd, mtd.isStatic(), stmt.getStmtSize() - 2);
    }
}
void Compiler.asmCALL1(Stmt stmt, int espidx, Stmt expr1, Stmt stmtPost) {
    print "call";
    print stmt;
    print espidx;
    print expr1;
    print stmtPost;
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
        K_Value vb = kfunc.getKValue(espidx, TYPE_Object);
        inst = new K_TR(vb, new K_TRop(thisObj, espidx, espidx - espidx, c.getClassTablePtr(), Stmt.BOX), 0);
        kfunc.curBB.insts.add(inst);
    } else {
        K_Inst thisObj = kfunc.getKInst(espidx);
        K_Value vb = kfunc.getKValue(espidx, TYPE_Object);
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

    int type = getcid(c);
    if(type == TYPE_Boolean && mtd.getName() == "!") {
        print "TODO: " + mtd; // TODO
        return;
    }else if(type == TYPE_Int || type == TYPE_Float) {
        asm(lhs, lhs.toToken(), espidx + 1);
        K_Inst inst_l = kfunc.getKInst(espidx + 1);
        K_Inst inst_r = null;
        Token rhsTk = rhs.toToken();
        if(rhsTk.getTT() == Token.TT_CONST) {// const
            int table_idx = kfunc.addConstTable(rhsTk.getD());
            inst_r = new K_CONST(null, type, new K_CONSTop(table_idx, 0, kfunc.const_table));
            kfunc.curBB.insts.add(inst_r);
        }else{
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
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_EQ(kval, type, new K_EQop(inst_l, inst_r), espidx);
                break;
            case "!=":
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_NEQ(kval, type, new K_NEQop(inst_l, inst_r), espidx);
                break;
            case "<":
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_LT(kval, type, new K_LTop(inst_l, inst_r), espidx);
                break;
            case "<=":
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_LTE(kval, type, new K_LTEop(inst_l, inst_r), espidx);
                break;
            case ">":
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_GT(kval, type, new K_GTop(inst_l, inst_r), espidx);
                break;
            case ">=":
                K_Value kval = kfunc.getKValue(espidx, TYPE_Boolean);
                inst = new K_GTE(kval, type, new K_GTEop(inst_l, inst_r), espidx);
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
            default:
                print "TODO: " + mtd; // TODO
                break;
        }
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);

        return;
    }
}
void Compiler.asmNEW(Stmt stmt, int espidx, Class thisCid, Method mtd) {
    if (DEBUG) {
        print "new";
        print stmt;
        print stmt.getStmtSize();
        print getcid(thisCid);
        print espidx;
        print thisCid;
        print mtd;
        print mtd.getName();
    }
    int thisidx = espidx + K_CALLDELTA;
    if (stmt.getStmtSize() == 2 && getcid(thisCid) == TYPE_Object && mtd.getName() == "new") {
        K_Value vb = kfunc.getKValue(espidx, TYPE_Object);
        K_Inst inst = new K_NEW(vb, new K_NEWop(espidx-thisidx, thisCid.getClassTablePtr(), Stmt.NEW));
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(espidx, inst);
    } else {
        K_Value vb = kfunc.getKValue(thisidx, TYPE_Object);
        K_Inst inst = new K_NEW(vb, new K_NEWop(thisidx-thisidx, thisCid.getClassTablePtr(), Stmt.NEW));
        kfunc.curBB.insts.add(inst);
        kfunc.storeKInst(thisidx, inst);
        callparams_asm(stmt, 2, espidx, getcid(thisCid), mtd);
        asmCALL_sub(espidx, getcid(mtd.getReturnType()), mtd, false, stmt.getStmtSize() - 2);
    }
    //ASM(TR, OC_(thisidx), SFP_(thisidx), RIX_(thisidx-thisidx), ClassTBL(cid), TR_NEW);
}
void Compiler.asmTCAST(Stmt stmt, int espidx, TypeMap tmr, Stmt expr) {
    print "tcast";
    print stmt;
    print espidx;
    print tmr;
    print tmr.source;
    print tmr.target;
    print expr;
    Class source = tmr.source;
    Class target = tmr.target;
    if (source == Int && target == Float) {
        asm(expr, expr.toToken(), espidx);
        K_Value v = kfunc.getKValue(espidx, getcid(target));
        K_Inst inst = kfunc.getKInst(espidx);
        //K_Inst inst = new K_NEW(vb, new K_NEWop(thisidx-thisidx, thisCid.getClassTablePtr(), Stmt.NEW));
        K_Inst cast = new K_CAST(v, new K_CASTop(inst, getcid(target), getcid(source), espidx, espidx, 0, 0, 0));
        print "********TODO******";
    }

}
void Compiler.asmAND(Stmt stmt, int espidx) {
    print "and";
    print stmt;
    print espidx;
}
void Compiler.asmOR(Stmt stmt, int espidx) {
    print "or";
    print stmt;
    print espidx;
}
void Compiler.asmALT(Stmt stmt, int espidx) {
    /* TODO */
}
void Compiler.asmTRI(Stmt stmt, int espidx, Stmt cond, Stmt lhs, Stmt rhs) {
    /* use CreateSelect */
    print "tri";
    print espidx;
    print cond;
    print lhs;
    print rhs;
}
void Compiler.asmSEND(Stmt stmt, int espidx) {
    print "send";
    print stmt;
    print espidx;
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
}

void Compiler.constructKonohaTypes() {
    Type int32Ty = Type.getInt32Ty();
    Type int64Ty = Type.getInt64Ty();
    Type int8PtrTy = Type.getInt8PtrTy();
    Type voidPtrTy = Type.getInt8PtrTy();
    Type longTy  = int64Ty;
    Type shortTy = Type.getInt16Ty();
    Type intTy   = int64Ty;
    Type sizeTy  = int64Ty;
    Type floatTy = Type.getDoubleTy();

    // TODO
    Type classTBLPtrTy = Type.getInt8PtrTy();
    Type typeMapPtrTy  = Type.getInt8PtrTy();

    Type[] fields = [];
    fields.add(int32Ty);
    fields.add(int32Ty);
    Type hcacheTy = StructType.get(fields, false);
    m.addTypeName("knh_hcache_t", hcacheTy);

    fields = [];
    fields.add(int64Ty);
    fields.add(int64Ty);
    Type sfxTy = StructType.get(fields, false);
    m.addTypeName("knh_sfx_t", sfxTy);

    fields = [];
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    Type hObjectTy = StructType.get(fields, false);
    m.addTypeName("hObject", hObjectTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type objectTy = StructType.get(fields, false);
    Type objectPtrTy = PointerType.get(objectTy);
    Type objectPtrPtrTy = PointerType.get(objectPtrTy);
    m.addTypeName("Object", objectTy);
    m.addTypeName("ObjectPtr", objectPtrTy);
    ktype["objectPtrTy"] = objectPtrTy;
    ktype["objectPtrPtrTy"] = objectPtrPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type arrayTy = StructType.get(fields, false);
    Type arrayPtrTy = PointerType.get(arrayTy);
    m.addTypeName("Array", arrayTy);
    ktype["arrayPtrTy"] = arrayPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(Type.getInt1PtrTy()); /* text */
    fields.add(int64Ty);   /* len */
    Type stringTy = StructType.get(fields, false);
    Type stringPtrTy = PointerType.get(stringTy);
    m.addTypeName("String", stringTy);
    ktype["stringPtrTy"] = stringPtrTy;


    fields = [];
    fields.add(hObjectTy);
    fields.add(objectPtrPtrTy);
    fields.add(objectPtrTy);
    Type objectFieldTy    = StructType.get(fields, false);
    Type objectFieldPtrTy = PointerType.get(objectFieldTy);
    m.addTypeName("ObjectField", objectFieldTy);
    ktype["objectFieldTy"] = stringPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type outputStreamTy = StructType.get(fields, false);
    Type outputStreamPtrTy = PointerType.get(outputStreamTy);
    m.addTypeName("OutputStream", outputStreamTy);
    ktype["outputStreamPtrTy"] = outputStreamPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    Type inputStreamTy = StructType.get(fields, false);
    Type inputStreamPtrTy = PointerType.get(inputStreamTy);
    m.addTypeName("InputStream", inputStreamTy);
    ktype["inputStreamPtrTy"] = inputStreamPtrTy;

    fields = [];
    fields.add(objectPtrTy);
    fields.add(Type.getDoubleTy());
    Type sfpTy = StructType.get(fields, false);
    Type sfpPtrTy = PointerType.get(sfpTy);
    m.addTypeName("sfp", sfpTy);
    ktype["sfpPtrTy"] = sfpPtrTy;

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
    Type sysExTy = StructType.get(fields, false);

    fields = [];
    fields.add(hObjectTy);
    fields.add(sysExTy);
    Type sysTy = StructType.get(fields, false);
    Type sysPtrTy = PointerType.get(sysTy);
    m.addTypeName("System", sysTy);
    ktype["sysPtrTy"] = sysPtrTy;

    fields = [];
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

    Type ctxTy = StructType.get(fields, false);
    Type ctxPtrTy = PointerType.get(ctxTy);
    m.addTypeName("context", ctxTy);
    m.addTypeName("CTX", ctxPtrTy);
    ktype["ctxTy"] = ctxPtrTy;

    Type[] argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type fmethodPtrTy = PointerType.get(fmethodTy);
    m.addTypeName("fmethod", fmethodTy);
    ktype["fmethodTy"]    = fmethodTy;
    ktype["fmethodPtrTy"] = fmethodPtrTy;
    this.funcTy = fmethodTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType trmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type trmethodPtrTy = PointerType.get(trmethodTy);
    m.addTypeName("trmethod", trmethodTy);
    ktype["trmethodTy"]    = trmethodTy;
    ktype["trmethodPtrTy"] = trmethodPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fitrnextTy = FunctionType.get(Type.getInt64Ty(), argsTy, false);
    Type fitrnextPtrTy = PointerType.get(fitrnextTy);
    m.addTypeName("fitrnext", fitrnextTy);
    ktype["fitrnextTy"]    = fitrnextTy;
    ktype["fitrnextPtrTy"] = fitrnextPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType typemapmtdTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type typemapmtdPtrTy = PointerType.get(typemapmtdTy);
    m.addTypeName("typemapmtd", typemapmtdTy);
    ktype["typemapmtdTy"]    = typemapmtdTy;
    ktype["typemapmtdPtrTy"] = typemapmtdPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType fTRTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    Type fTRPtrTy = PointerType.get(fTRTy);
    ktype["fTRTy"]    = fTRTy;
    ktype["fTRPtrTy"] = fTRPtrTy;

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
    Type oplineTy = StructType.get(fields, false);
    Type oplinePtrTy = PointerType.get(oplineTy);
    m.addTypeName("opline_t", oplineTy);
    ktype["oplineTy"] = oplineTy;
    ktype["oplinePtrTy"] = oplinePtrTy;
    ktype["oplinePtrPtrTy"] = PointerType.get(oplinePtrTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(Type.getInt32Ty);
    fields.add(Type.getInt32Ty);
    fields.add(fmethodPtrTy);
    fields.add(oplinePtrTy);
    Type methodTy = StructType.get(fields, false);
    m.addTypeName("Method", methodTy);
    Type methodPtrTy = PointerType.get(methodTy);
    ktype["methodPtrTy"] = methodPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(fitrnextPtrTy);
    Type iteratorTy = StructType.get(fields, false);
    m.addTypeName("Iterator", iteratorTy);
    ktype["IteratorPtrTy"] = PointerType.get(iteratorTy);

    /* THCODE */
    fields = [];
    fields.add(voidPtrTy); /* codeaddr */
    fields.add(sizeTy);   /* count */
    fields.add(shortTy);   /* opcode */
    fields.add(shortTy);   /* line */
    fields.add(voidPtrTy); /* th */
    fields.add(longTy); /* uri */
    Type type = StructType.get(fields, false);
    m.addTypeName("THCODE_t", type);
    ktype["THCODE"] = PointerType.get(type);

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
    type = StructType.get(fields, false);
    m.addTypeName("PROBE_t", type);
    ktype["PROBE"] = PointerType.get(type);

    /* RET */
    fields = [];
    fields.add(voidPtrTy); /* codeaddr */
    fields.add(sizeTy);   /* count */
    fields.add(shortTy);   /* opcode */
    fields.add(shortTy);   /* line */
    type = StructType.get(fields, false);
    m.addTypeName("RET_t", type);
    ktype["RET"] = PointerType.get(type);
}
@Override void K_PHI.codegen(Compiler asm) {
    if (|bbs| == 1) {
        if (DEBUG) {
            print "hi";
        }
        setLLVMValue(asm, insts[0].getLLVMValue(asm));
        return;
    } else {
        PHINode pn = asm.builder.createPHI(asm.convertType(type), |bbs|);
        for (int i = 0; i < |bbs|; i++) {
            pn.addIncoming(insts[i].getLLVMValue(asm), asm.bblist[bbs[i]]);
        }
        setLLVMValue(asm, pn);
    }
}
void K_Function.codegen(Compiler asm) {
    for (int i = 0; i < |bbs|; i++) {
        asm.bblist.add(BasicBlock.create(asm.func));
    }
    asm.builder = new IRBuilder(asm.bblist[0]);
    for (int i = 0; i < |bbs|; i++) {
        asm.builder.setInsertPoint(asm.bblist[i]);
        if (bbs[i].phis != null) {
            foreach (String s in bbs[i].phis.keys()) {
                bbs[i].phis[s].codegen(asm);
            }
        }
        if (i == 0) {
            foreach(K_Inst inst in funcargs) {
                inst.codegen(asm);
            }
        }
        foreach (K_Inst inst in bbs[i].insts) {
            inst.codegen(asm);
        }
    }
}
@Override void K_ADD.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createAdd(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFadd(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_SUB.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createSub(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFSub(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_MUL.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createMul(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFMul(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_DIV.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createSDiv(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFDiv(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_MOD.codegen(Compiler asm) {
    Value v = asm.builder.createSRem(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_EQ.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpEQ(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpOEQ(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Object:
            if (op.inst1 == null) {
                v = asm.builder.createStructGEP(op.inst0.getLLVMValue(asm), 0);
                v = asm.builder.createStructGEP(v, 0);
                v = asm.builder.createLoad(v);
                Value flag = ConstantInt.get(asm.intTy, FLAG_OBJECT_NULLOBJECT);
                v = asm.builder.createAnd(v, flag);
                v = asm.builder.createICmpEQ(v, flag);
            }
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_NEQ.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpNE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpONE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Object:
            if (op.inst1 == null) {
                v = asm.builder.createStructGEP(op.inst0.getLLVMValue(asm), 0);
                v = asm.builder.createStructGEP(v, 0);
                v = asm.builder.createLoad(v);
                Value flag = ConstantInt.get(asm.intTy, FLAG_OBJECT_NULLOBJECT);
                v = asm.builder.createAnd(v, flag);
                v = asm.builder.createICmpEQ(v, flag);
            }
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_LT.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpSLT(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpOLT(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_GT.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpSGT(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpOGT(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_LTE.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpSLE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpOLE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_GTE.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case TYPE_Int:
            v = asm.builder.createICmpSGE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
        case TYPE_Float:
            v = asm.builder.createFCmpOGE(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_AND.codegen(Compiler asm) {
    Value v = asm.builder.createAnd(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_OR.codegen(Compiler asm) {
    Value v = asm.builder.createOr(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_XOR.codegen(Compiler asm) {
    Value v = asm.builder.createXor(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_LSFT.codegen(Compiler asm) {
    Value v = asm.builder.createShl(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_RSFT.codegen(Compiler asm) {
    Value v = asm.builder.createLShr(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
    setLLVMValue(asm, v);
}
@Override void K_CAST.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    if (op.cast == 0) {
        v = asm.builder.createBitCast(v, asm.convertType(type));
    } else {
        Value typemap_exec = ConstantInt.get(asm.intTy, op.fptr);
        typemap_exec = asm.builder.createIntToPtr(typemap_exec, asm.ktype["typemapmtdPtrTy"]);
        asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(type), op.b, op.inst0.getLLVMValue(asm));
        asm.shiftesp(op.espshift);
        Value vsfp = asm.builder.createInBoundsGEP1(asm.sfp, ConstantInt.get(asm.intTy, op.b));
        Value vctx = asm.ctx;
        Value vtmr = ConstantInt.get(asm.intTy, op.cast);
        Value vrix = ConstantInt.get(asm.intTy, op.rix);
        Value[] vargs = [vctx, vtmr, vsfp, vrix];
        asm.builder.createCall(typemap_exec, vargs);
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.b+op.rix);
        setLLVMValue(asm, v);
    }
}
@Override void K_JMP.codegen(Compiler asm) {
    asm.builder.createBr(asm.bblist[op.jmpidx]);
}
@Override void K_COND.codegen(Compiler asm) {
    asm.builder.createCondBr(op.inst0.getLLVMValue, asm.bblist[op.bbThen], asm.bblist[op.bbElse]);
}
@Override void K_CALL.codegen(Compiler asm) {
    Value func;
    Value[] vargs;
    if (op.ftype != FUNC_FASTCALL) {
        func = ConstantInt.get(asm.intTy, op.mtdNC);
        func = asm.builder.createIntToPtr(func, asm.ktype["methodPtrTy"]);
        func = asm.builder.createStructGEP(func, 4);
        func = asm.builder.createLoad(func);
        Value thisidx = ConstantInt.get(asm.intTy, op.thisidx);
        Value sfp = asm.builder.createGEP1(asm.sfp, thisidx);
        Value vrix = ConstantInt.get(asm.intTy, op.rix);
        vargs = [asm.ctx, sfp, vrix];
        for (int i = 0; i < |args|; i++) {
            asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(args[i].type), op.thisidx + i + op.flagStatic, args[i].getLLVMValue(asm));
        }
    } else {
        Type methodTy = asm.ktype["fmethodPtrTy"];
        func = ConstantInt.get(asm.intTy, op.mtdNC);
        func = asm.builder.CreateIntToPtr(func, methodTy);
        Value vb = ConstantInt.get(asm.intTy, op.thisidx);
        vb = asm.builder.createGEP1(asm.sfp, vb);
        Value vrix = ConstantInt.get(asm.intTy, op.rix);
        vargs = [asm.ctx, vb, vrix];
    }
    asm.builder.createStoreValueToSfp(asm.sfp, asm.intTy, op.thisidx-1, ConstantInt.get(asm.intTy, op.mtdNC));
    asm.shiftesp(op.espshift);
    asm.builder.createCall(func, vargs);
    Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.thisidx+op.rix);
    setLLVMValue(asm, v);
}
@Override void K_PRINT.codegen(Compiler asm) {
    if (op.inst0 != null) {
        asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(type), op.sfpidx, op.inst0.getLLVMValue(asm));
    }
    Type fmethodTy = asm.ktype["fmethodPtrTy"];
    Value func = ConstantInt.get(asm.intTy, op.fprint);
    func = asm.builder.CreateIntToPtr(func, fmethodTy);
    Value vop = ConstantInt.get(asm.intTy, op.opline);
    Value[] vargs = [asm.ctx, asm.sfp, vop];
    asm.builder.createCall(func, vargs);
}
@Override void K_TR.codegen(Compiler asm) {
    Type methodTy = asm.ktype["trmethodPtrTy"];
    Value func = ConstantInt.get(asm.intTy, op.ftr);
    func = asm.builder.CreateIntToPtr(func, methodTy);
    Value vb = ConstantInt.get(asm.intTy, kvalue.idx);
    vb = asm.builder.createGEP1(asm.sfp, vb);
    Value rix = ConstantInt.get(asm.intTy, op.rix);
    Value cid = ConstantInt.get(asm.intTy, op.cTBL);
    Value[] vargs = [asm.ctx, vb, rix, cid];
    asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), op.espidx, op.inst0.getLLVMValue(asm));
    asm.builder.createCall(func, vargs);
    Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.espidx + op.rix);
    setLLVMValue(asm, v);
}
@Override void K_NEW.codegen(Compiler asm) {
    Type methodTy = asm.ktype["trmethodPtrTy"];
    Value func = ConstantInt.get(asm.intTy, op.ftr);
    func = asm.builder.CreateIntToPtr(func, methodTy);
    Value vb = ConstantInt.get(asm.intTy, kvalue.idx);
    vb = asm.builder.createGEP1(asm.sfp, vb);
    Value rix = ConstantInt.get(asm.intTy, op.rix);
    Value cid = ConstantInt.get(asm.intTy, op.cTBL);
    Value [] vargs = [asm.ctx, vb, rix, cid];
    asm.builder.createCall(func, vargs);
    Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), kvalue.idx + op.rix);
    setLLVMValue(asm, v);
}
@Override void K_GETIDX.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    v = asm.builder.createBitCast(v, asm.ktype["arrayPtrTy"]);
    v = asm.builder.createStructGEP(v, 1);
    v = asm.builder.createLoad(v);
    v = asm.builder.createBitCast(v, PointerType.get(asm.intTy));
    v = asm.builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = asm.builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Override void K_SETIDX.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
    v = asm.builder.createStructGEP(v, 1);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
    v = asm.builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst2.type)));
    v = asm.builder.createStore(op.inst2.getLLVMValue(asm), v);
    setLLVMValue(asm, op.inst2.getLLVMValue(asm));
}
@Override void K_CONST.codegen(Compiler asm) {
    Value v;
    switch(type) {
        case (TYPE_Int) :
            v = ConstantInt.get(asm.intTy, (int)op.const_table[op.table_idx]);
            break;
        case (TYPE_Float) :
            v = ConstantFP.get(asm.floatTy, (float)op.const_table[op.table_idx]);
            break;
        default:
            v = asm.builder.CreateIntToPtr(ConstantInt.get(asm.intTy, op.objptr), asm.ktype["objectPtrTy"]);
            break;
    }
    setLLVMValue(asm, v);
}
@Override void K_MOVx.codegen (Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
    v = asm.builder.createStructGEP(v, 1);
    v = asm.builder.createLoad(v);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
    Value vn = ConstantInt.get(asm.intTy, op.bn);
    v = asm.builder.createInBoundsGEP1(v, vn);
    v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(type)));
    v = asm.builder.createLoad(v);
    setLLVMValue(asm, v);
}
@Override void K_xMOV.codegen(Compiler asm) {
    Value v = op.inst0.getLLVMValue(asm);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
    v = asm.builder.createStructGEP(v, 1);
    v = asm.builder.createLoad(v);
    v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
    Value vn = ConstantInt.get(asm.intTy, op.an);
    v = asm.builder.createInBoundsGEP1(v, vn);
    v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
    v = asm.builder.createStore(op.inst1.getLLVMValue(asm), v);
}
@Override void K_NEXT.codegen(Compiler asm) {
    Value itr = op.inst0.getLLVMValue(asm);
    itr = asm.builder.createBitCast(itr, asm.ktype["IteratorPtrTy"]);
    Value fnext_1 = asm.builder.createStructGEP(itr, 2);
    fnext_1 = asm.builder.createLoad(fnext_1);
    Value vctx = asm.ctx;
    Value vsfp = asm.builder.createConstGEP1_32(asm.sfp, op.b);
    Value vrix = ConstantInt.get(asm.intTy, op.rix);
    asm.shiftesp(op.espshift);
    Value[] vargs = [vctx, vsfp, vrix];
    Value v = (Value)asm.builder.createCall(fnext_1, vargs);
    Value res = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.b + op.rix);
    setLLVMValue(asm, res);
    Value v = asm.builder.createICmpEQ(v, ConstantInt.get(asm.intTy, 0));
    asm.builder.createCondBr(v, asm.bblist[op.nextBB], asm.bblist[op.endBB]);
}
@Override void K_LDMTD.codegen(Compiler asm) {
    Type fmethodTy = asm.ktype["fmethodPtrTy"];
    Value func = ConstantInt.get(asm.intTy, op.ldmtd);
    func = asm.builder.CreateIntToPtr(func, fmethodTy);
    Value vop = ConstantInt.get(asm.intTy, op.opline);
    Value[] vargs = [asm.ctx, asm.sfp, vop];
    asm.builder.createCall(func, vargs);
}
@Override void K_ARGUMENT.codegen(Compiler asm) {
    Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.argidx);
    setLLVMValue(asm, v);
}
@Override void K_RET.codegen(Compiler asm) {
    if (op.inst0 != null) {
        asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), K_RTNIDX, op.inst0.getLLVMValue(asm));
    }
    asm.builder.createRetVoid();
}

