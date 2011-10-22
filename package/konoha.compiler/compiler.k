/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
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

//DEBUG = false;
DEBUG = true;
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
PHI_DEFIDX = -100;
FLAG_OBJECT_NULLOBJECT = 1 << 1;
NOT_SCAST = -1;

class K_BasicBlock;
class K_Function;
class K_Inst;
class Compiler {
    Module m;
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
    Array<dynamic> const_table;
    K_Function kfunc;
    void constructKonohaTypes();
    Compiler() {
        this.m = new Module("konoha");
        ktype = {};
        constructKonohaTypes();
        const_table = [];
        this.intTy = Type.getInt64Ty();
        this.boolTy = Type.getInt1Ty();
        this.floatTy = Type.getDoubleTy();
        this.objectTy = ktype["objectPtrTy"];
    }
};
void Compiler.shiftesp(int shift);
void Compiler.emit(Method mtd);
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
    if (classType == Array) return TYPE_Array;
    if (classType == Boolean) return TYPE_Boolean;
    return 0;
}

@Public Value IRBuilder.getValueFromSfp(Value sfp, Type rTy, int sfpidx) {
    int idx;
    if (rTy.class == PointerType)
        idx = 0;
    else
        idx = 1;
    v = this.createConstGEP2_32(sfp, sfpidx, idx);
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
            if (kvalue.defPoint.indexOf(opidx) == -1) {
                defidx = kvalue.defCount;
                kvalue.defCount = defidx + 1;
                kvalue.defPoint.add(opidx);
            }
        }
    }
    void addUse(K_Opcode op, int opidx) {
        if (op.inst0 != null && op.inst1.kvalue != null) {
            if (op.inst0.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst0.kvalue.useCount = op.inst0.kvalue.useCount + 1;
                op.inst0.kvalue.usePoint.add(opidx);
            }
        }
        if (op.inst1 != null && op.inst1.kvalue != null) {
            if (op.inst1.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst1.kvalue.useCount = op.inst1.kvalue.useCount + 1;
                op.inst1.kvalue.usePoint.add(opidx);
            }
        }
        if (op.inst2 != null && op.inst2.kvalue != null) {
            if (op.inst2.kvalue.usePoint.indexOf(opidx) == -1) {
                op.inst2.kvalue.useCount = op.inst2.kvalue.useCount + 1;
                op.inst2.kvalue.usePoint.add(opidx);
            }
        }
        if (args != null) {
            foreach (K_Inst inst in args) {
                if (inst.kvalue != null && inst.kvalue.usePoint.indexOf(opidx) == -1) {
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
        switch (type) {
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
            if (inst.kvalue.usePoint.indexOf(idx) == -1) {
                inst.kvalue.useCount = inst.kvalue.useCount + 1;
                inst.kvalue.usePoint.add(idx);
            }
        }
        bbs.add(bbidx);
        insts.add(inst);
    }
    @Override void dump() {
        OUT << "\t" + getName () + " = phi [";
        String res = "";
        for (int i = 0; i < |bbs|; i++) {
            res += "[" + insts[i].getName() + ", bb" + bbs[i] + "], ";
        }
        res = res[0 to |res|-3];
        OUT << res + "]" << EOL;
    }
    @Override void codegen(Compiler asm) {
        PHINode pn = asm.builder.createPHI(asm.convertType(type), |bbs|);
        for (int i = 0; i < |bbs|; i++) {
            pn.addIncoming(insts[i].getLLVMValue(asm), asm.bblist[bbs[i]]);
        }
        setLLVMValue(asm, pn);
    }
}
class K_BasicBlock {
    int bbidx;
    BasicBlock bb;
    Array<K_Inst> insts;
    Map<String, K_PHI> phis;
    K_BasicBlock (int bbidx) {
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

    K_Function(Method mtd) {
        argsTy = [];
        params = mtd.getParamTypes();
        retTy = getcid(mtd.getReturnType());
        bbs = [];
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
    void initKCode() {
        for (i = 0; i < |linklist|; i++) {
            K_BasicBlock bb = new K_BasicBlock(i);
            bbs.add(bb);
        }
        for (i = 0; i < |phi|; i++) {
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
        OUT << "def " + getTypeName(retTy) + " function(";
        str = "";
        for (int i = 0; i < |funcargs|; i++) {
            str += funcargs[i].getName() + ", ";
        }
        str = (|str| > 0) ? str[0 to |str|-3] + ") {" : ") {";
        OUT << str << EOL;
        for (int i = 0; i < |bbs|; i++) {
            OUT << "  BasicBlock" + i + ":\tpred = ";
            for (int j = 0; j < |pred[i]|; j++) {
                OUT<< "bb" + pred[i][j] + " ";
            }
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
    void codegen(Compiler asm) {
        for (int i = 0; i < |bbs|; i++) {
            asm.bblist.add(BasicBlock.create(asm.func));
        }
        asm.builder = new IRBuilder(asm.bblist[0]);
        for (int i = 0; i < |bbs|; i++) {
            asm.builder.setInsertPoint(asm.bblist[i]);
            foreach (String s in bbs[i].phis.keys()) {
                bbs[i].phis[s].codegen(asm);
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
        asm.emit();
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createSRem(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
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
                    flag = ConstantInt.get(asm.intTy, FLAG_OBJECT_NULLOBJECT);
                    v = asm.builder.createAnd(v, flag);
                    v = asm.builder.createICmpEQ(v, flag);
                }
                break;
        }
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
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
                    flag = ConstantInt.get(asm.intTy, FLAG_OBJECT_NULLOBJECT);
                    v = asm.builder.createAnd(v, flag);
                    v = asm.builder.createICmpEQ(v, flag);
                }
                break;
        }
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
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
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createAnd(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createOr(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createXor(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createShl(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    }
    @Override void dump() {
        OUT << "\t" + getName() + " = rsft "+ getTypeName(type) + " " + op.inst0.getName() + " " + op.inst1.getName() << EOL;
    }
    @Override void codegen(Compiler asm) {
        Value v = asm.builder.createLShr(op.inst0.getLLVMValue(asm), op.inst1.getLLVMValue(asm));
        setLLVMValue(asm, v);
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
    K_CAST (K_Inst inst0, int tcid, int scid, int b, int rix, int espshift, int cast, int fptr) {
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
    @Override void codegen(Compiler asm) {
        v = op.inst0.getLLVMValue(asm);
        if (op.cast == 0) {
            v = asm.builder.createBitCast(v, asm.convertType(type));
        } else {
            typemap_exec = ConstantInt.get(asm.intTy, op.fptr);
            typemap_exec = asm.builder.createIntToPtr(typemap_exec, asm.ktype["typemapmtdPtrTy"]);
            asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(type), op.b, op.inst0.getLLVMValue(asm));
            asm.shiftesp(op.espshift);
            vsfp = asm.builder.createInBoundsGEP1(asm.sfp, ConstantInt.get(asm.intTy, op.b));
            vctx = asm.ctx;
            vtmr = ConstantInt.get(asm.intTy, op.cast);
            vrix = ConstantInt.get(asm.intTy, op.rix);
            Value[] vargs = [vctx, vtmr, vsfp, vrix];
            asm.builder.createCall(typemap_exec, vargs);
            v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.b+op.rix);
            setLLVMValue(asm, v);
        }
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
    @Override void codegen(Compiler asm) {
        asm.builder.createBr(asm.bblist[op.jmpidx]);
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
    @Override void codegen(Compiler asm) {
        asm.builder.createCondBr(op.inst0.getLLVMValue, asm.bblist[op.bbThen], asm.bblist[op.bbElse]);
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
    @Override void codegen(Compiler asm) {
        Value func;
        Value[] vargs;
        if (op.ftype != FUNC_FASTCALL) {
            func = ConstantInt.get(asm.intTy, op.mtdNC);
            func = asm.builder.createIntToPtr(func, asm.ktype["methodPtrTy"]);
            func = asm.builder.createStructGEP(func, 4);
            func = asm.builder.createLoad(func);
            thisidx = ConstantInt.get(asm.intTy, op.thisidx);
            sfp = asm.builder.createGEP1(asm.sfp, thisidx);
            vrix = ConstantInt.get(asm.intTy, op.rix);
            vargs = [asm.ctx, sfp, vrix];
            for (int i = 0; i < |args|; i++) {
                asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(args[i].type), op.thisidx + i + op.flagStatic, args[i].getLLVMValue(asm));
            }
        } else {
            Type methodTy = asm.ktype["fmethodPtrTy"];
            func = ConstantInt.get(asm.intTy, op.mtdNC);
            func = asm.builder.CreateIntToPtr(func, methodTy);
            vb = ConstantInt.get(asm.intTy, op.thisidx);
            vb = asm.builder.createGEP1(asm.sfp, vb);
            vrix = ConstantInt.get(asm.intTy, op.rix);
            vargs = [asm.ctx, vb, vrix];
        }
        asm.builder.createStoreValueToSfp(asm.sfp, asm.intTy, op.thisidx-1, ConstantInt.get(asm.intTy, op.mtdNC));
        asm.shiftesp(op.espshift);
        asm.builder.createCall(func, vargs);
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.thisidx+op.rix);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        if (op.inst0 != null) {
            asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(type), op.sfpidx, op.inst0.getLLVMValue(asm));
        }
        fmethodTy = asm.ktype["fmethodPtrTy"];
        func = ConstantInt.get(asm.intTy, op.fprint);
        func = asm.builder.CreateIntToPtr(func, fmethodTy);
        vop = ConstantInt.get(asm.intTy, op.opline);
        Value []vargs = [asm.ctx, asm.sfp, vop];
        asm.builder.createCall(func, vargs);
    }
}
class K_TRop extends K_Opcode {
    int rix;
    int cTBL;
    int ftr;
    K_TRop(int rix, int cTBL, int ftr) {
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
        OUT << "\t" + getName() + " = tr " + getTypeName(type) << EOL;
    }
    @Override void codegen(Compiler asm) {
        Type methodTy = asm.ktype["trmethodPtrTy"];
        func = ConstantInt.get(asm.intTy, op.ftr);
        func = asm.builder.CreateIntToPtr(func, methodTy);
        vb = ConstantInt.get(asm.intTy, kvalue.idx);
        vb = asm.builder.createGEP1(asm.sfp, vb);
        rix = ConstantInt.get(asm.intTy, op.rix);
        cid = ConstantInt.get(asm.intTy, op.cTBL);
        Value [] vargs = [asm.ctx, vb, rix, cid];
        asm.builder.createCall(func, vargs);
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), kvalue.idx + op.rix);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        Type methodTy = asm.ktype["trmethodPtrTy"];
        func = ConstantInt.get(asm.intTy, op.ftr);
        func = asm.builder.CreateIntToPtr(func, methodTy);
        vb = ConstantInt.get(asm.intTy, kvalue.idx);
        vb = asm.builder.createGEP1(asm.sfp, vb);
        rix = ConstantInt.get(asm.intTy, op.rix);
        cid = ConstantInt.get(asm.intTy, op.cTBL);
        Value [] vargs = [asm.ctx, vb, rix, cid];
        asm.builder.createCall(func, vargs);
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), kvalue.idx + op.rix);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        v = op.inst0.getLLVMValue(asm);
        v = asm.builder.createBitCast(v, asm.ktype["arrayPtrTy"]);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createLoad(v);
        v = asm.builder.createBitCast(v, PointerType.get(asm.intTy));
        v = asm.builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(type)));
        v = asm.builder.createLoad(v);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        v = op.inst0.getLLVMValue(asm);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
        v = asm.builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst2.type)));
        v = asm.builder.createStore(op.inst2.getLLVMValue(asm), v);
        setLLVMValue(asm, op.inst2.getLLVMValue(asm));
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
    @Override void codegen(Compiler asm) {
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

    @Override void dump() {
        OUT << "\t" + getName() + " = const " + getTypeName(type) + " ";
        OUT << op.const_table[op.table_idx] << EOL;
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
    @Override void codegen (Compiler asm) {
        v = op.inst0.getLLVMValue(asm);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createLoad(v);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
        vn = ConstantInt.get(asm.intTy, op.bn);
        v = asm.builder.createInBoundsGEP1(v, vn);
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(type)));
        v = asm.builder.createLoad(v);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        v = op.inst0.getLLVMValue(asm);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createLoad(v);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
        vn = ConstantInt.get(asm.intTy, op.an);
        v = asm.builder.createInBoundsGEP1(v, vn);
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
        v = asm.builder.createStore(op.inst1.getLLVMValue(asm), v);
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
    @Override void codegen(Compiler asm) {
        itr = op.inst0.getLLVMValue(asm);
        itr = asm.builder.createBitCast(itr, asm.ktype["IteratorPtrTy"]);
        fnext_1 = asm.builder.createStructGEP(itr, 2);
        fnext_1 = asm.builder.createLoad(fnext_1);
        vctx = asm.ctx;
        vsfp = asm.builder.createConstGEP1_32(asm.sfp, op.b);
        vrix = ConstantInt.get(asm.intTy, op.rix);
        asm.shiftesp(op.espshift);
        Value[] vargs = [vctx, vsfp, vrix];
        Value v = (Value)asm.builder.createCall(fnext_1, vargs);
        res = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.b + op.rix);
        setLLVMValue(asm, res);
        v = asm.builder.createICmpEQ(v, ConstantInt.get(asm.intTy, 0));
        asm.builder.createCondBr(v, asm.bblist[op.nextBB], asm.bblist[op.endBB]);
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
    @Override void codegen(Compiler asm) {
        fmethodTy = asm.ktype["fmethodPtrTy"];
        func = ConstantInt.get(asm.intTy, op.ldmtd);
        func = asm.builder.CreateIntToPtr(func, fmethodTy);
        vop = ConstantInt.get(asm.intTy, op.opline);
        Value []vargs = [asm.ctx, asm.sfp, vop];
        asm.builder.createCall(func, vargs);
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
    @Override void codegen(Compiler asm) {
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.argidx);
        setLLVMValue(asm, v);
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
    @Override void codegen(Compiler asm) {
        if (op.inst0 != null) {
            asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), K_RTNIDX, op.inst0.getLLVMValue(asm));
        }
        asm.builder.createRetVoid();
    }
}


void Compiler.init(Method mtd) {
    print "init ", mtd;
    this.mtd = mtd;
    func = Function.create("_", (FunctionType)ktype["fmethodTy"], m);
    bblist = [];
    Array<Value> vargs = func.getArguments();
    if (DEBUG) {
        vargs[0].setName("ctx");
        vargs[1].setName("sfp");
        vargs[2].setName("rix");
    }
    ctx = vargs[0];
    sfp = vargs[1];
    rix = vargs[2];
    register_table = [];
    value_table = {};
    //register_types = [];
    paramsclass = mtd.getParamTypes();
    retclass    = mtd.getReturnType();
    kfunc = new K_Function(mtd);
}

void Compiler.shiftesp(int shift) {
    if (shift > 0) {
        vesp = builder.createStructGEP(ctx, 7);
        vsfp = builder.createConstGEP1_32(sfp, shift);
        builder.createStore(vsfp, vesp);
    }
}

@Native void Compiler.asmEXPR(Stmt stmt, int espidx);
void Compiler.asm(Stmt stmt, Token tk, int espidx) {
    if (tk.isNotNULL()) {
        print "ASM_SMOV();"
    } else {
        asmEXPR(stmt, espidx);
    }
}
void Compiler.emit(Method mtd) {
    print "emit ", mtd;
    kfunc.dump();
}
/* stmt = {...} */
@Native void Compiler.asmBLOCK(Stmt stmt);
void Compiler.asm_mov(Token tka, Token tkb, int espidx) {
    if (tka.tokenType == Token.TT_FIELD) {
    }
}
/* stmt = let stmt[1] = stmt[2] */
void Compiler.asmLET(Stmt stmt, Token tkL, Stmt tkV, Token tkVTk) {
    int espidx = stmt.getESPIDX();
    if (tkVTk.isNotNull()) {
        int index = tkL.getIndex();
        print "ASM_MOV(lhs, tkV, espidx);", tkL, tkV;
    } else {
        asm(tkV, tkVTk, espidx);
        print espidx, tkV, tkVTk;
    }
}
/* stmt = if stmt[0] then stmt[1]:BLOCK else stmt[2] endif */
void Compiler.asmIF(Stmt stmt, Stmt stmtCond, Stmt stmtThen, Stmt stmtElse) {
    print "IF";
    //int index = stmt.getIndex();
    print stmtThen;
    print stmtElse;
    print "", stmtCond.toToken();
    asm(stmtCond, stmtCond.toToken());
    asmBlock(stmtThen);
    asmBlock(stmtElse);
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
}
void Compiler.asmDO(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    print "do-while";
    print stmtC;
    print stmtBody;
}
void Compiler.asmFOR(Stmt stmt, Stmt stmt1, Stmt stmt2, Stmt stmt3, Stmt stmtBody) {
    print "for";
    print stmt1;
    print stmt2;
    print stmt3;
    print stmtBody;
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
}
void Compiler.asmCONTINUE(Stmt stmt, Stmt stmtLabel) {
    print "continue";
    print stmtLabel;
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
    if (stmtRetExpr == null) {
        print "return;";
    } else {
        print "return expr;";
        print stmt;
        print stmtRetExpr;
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
}
void Compiler.asmFUNCCALL(Stmt stmt, int espidx, Method mtd, Class c, Stmt stmt) {
    print "funccall";
    print stmt;
    print espidx;
    print mtd;
    print c;
    print stmt;
}
void Compiler.asmCALL(Stmt stmt, int espidx, Token tkMTD, Method mtd, Class c) {
    print "call";
    print stmt;
    print espidx;
    print tkMTD;
    print mtd;
    print c;
}
void Compiler.asmCALL1(Stmt stmt, int espidx, Stmt expr1, Stmt stmtPost) {
    print "call";
    print stmt;
    print espidx;
    print expr1;
    print stmtPost;
}
void Compiler.asmBOX(Stmt stmt, int espidx, Class c, Stmt expr) {
    print "box";
    print stmt;
    print espidx;
    print c;
    print expr;

}
void Compiler.asmOPR(Stmt stmt, int espidx, Method mtd, Class c, Stmt lhs, Stmt rhs) {
    print "opr";
    print stmt;
    print espidx;
    print mtd;
    print c;
    print lhs;
    print rhs;
}
void Compiler.asmNEW(Stmt stmt, int espidx, Class thisCid, Method mtd) {
    print "new";
    print stmt;
    print espidx;
    print thisCid;
    print mtd;
}
void Compiler.asmTCAST(Stmt stmt, int espidx, TypeMap tmr, Stmt expr) {
    print "tcast";
    print stmt;
    print espidx;
    print tmr;
    print expr;
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
    int32Ty = Type.getInt32Ty();
    int64Ty = Type.getInt64Ty();
    int8PtrTy = Type.getInt8PtrTy();

    voidPtrTy = Type.getInt8PtrTy();
    longTy  = int64Ty;
    shortTy = Type.getInt16Ty();
    intTy   = int64Ty;
    sizeTy  = int64Ty;
    floatTy = Type.getDoubleTy();

    // TODO
    classTBLPtrTy = Type.getInt8PtrTy();
    typeMapPtrTy  = Type.getInt8PtrTy();

    Type[] fields = [];
    fields.add(int32Ty);
    fields.add(int32Ty);
    hcacheTy = StructType.get(fields, false);
    m.addTypeName("knh_hcache_t", hcacheTy);

    fields = [];
    fields.add(int64Ty);
    fields.add(int64Ty);
    sfxTy = StructType.get(fields, false);
    m.addTypeName("knh_sfx_t", sfxTy);

    fields = [];
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    hObjectTy = StructType.get(fields, false);
    m.addTypeName("hObject", hObjectTy);

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    objectTy = StructType.get(fields, false);
    objectPtrTy = PointerType.get(objectTy);
    objectPtrPtrTy = PointerType.get(objectPtrTy);
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
    arrayTy = StructType.get(fields, false);
    arrayPtrTy = PointerType.get(arrayTy);
    m.addTypeName("Array", arrayTy);
    ktype["arrayPtrTy"] = arrayPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(Type.getInt1PtrTy()); /* text */
    fields.add(int64Ty);   /* len */
    stringTy = StructType.get(fields, false);
    stringPtrTy = PointerType.get(stringTy);
    m.addTypeName("String", stringTy);
    ktype["stringPtrTy"] = stringPtrTy;


    fields = [];
    fields.add(hObjectTy);
    fields.add(objectPtrPtrTy);
    fields.add(objectPtrTy);
    objectFieldTy    = StructType.get(fields, false);
    objectFieldPtrTy = PointerType.get(objectFieldTy);
    m.addTypeName("ObjectField", objectFieldTy);
    ktype["objectFieldTy"] = stringPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    outputStreamTy = StructType.get(fields, false);
    outputStreamPtrTy = PointerType.get(outputStreamTy);
    m.addTypeName("OutputStream", outputStreamTy);
    ktype["outputStreamPtrTy"] = outputStreamPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    inputStreamTy = StructType.get(fields, false);
    inputStreamPtrTy = PointerType.get(inputStreamTy);
    m.addTypeName("InputStream", inputStreamTy);
    ktype["inputStreamPtrTy"] = inputStreamPtrTy;

    fields = [];
    fields.add(objectPtrTy);
    fields.add(Type.getDoubleTy());
    sfpTy = StructType.get(fields, false);
    sfpPtrTy = PointerType.get(sfpTy);
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
    sysExTy = StructType.get(fields, false);

    fields = [];
    fields.add(hObjectTy);
    fields.add(sysExTy);
    sysTy = StructType.get(fields, false);
    sysPtrTy = PointerType.get(sysTy);
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
    for (i=0; i < 16; i++) {
        vec16_fields.add(Type.getInt1Ty());
    }
    fields.add(StructType.get(vec16_fields, false));
    fields.add(int64Ty);
    fields.add(int8PtrTy);
    fields.add(objectPtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);
    fields.add(int8PtrTy);

    ctxTy = StructType.get(fields, false);
    ctxPtrTy = PointerType.get(ctxTy);
    m.addTypeName("context", ctxTy);
    m.addTypeName("CTX", ctxPtrTy);
    ktype["ctxTy"] = ctxPtrTy;

    Type[] argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    fmethodPtrTy = PointerType.get(fmethodTy);
    m.addTypeName("fmethod", fmethodTy);
    ktype["fmethodTy"]    = fmethodTy;
    ktype["fmethodPtrTy"] = fmethodPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType trmethodTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    trmethodPtrTy = PointerType.get(trmethodTy);
    m.addTypeName("trmethod", trmethodTy);
    ktype["trmethodTy"]    = trmethodTy;
    ktype["trmethodPtrTy"] = trmethodPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType fitrnextTy = FunctionType.get(Type.getInt64Ty(), argsTy, false);
    fitrnextPtrTy = PointerType.get(fitrnextTy);
    m.addTypeName("fitrnext", fitrnextTy);
    ktype["fitrnextTy"]    = fitrnextTy;
    ktype["fitrnextPtrTy"] = fitrnextPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    FunctionType typemapmtdTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    typemapmtdPtrTy = PointerType.get(typemapmtdTy);
    m.addTypeName("typemapmtd", typemapmtdTy);
    ktype["typemapmtdTy"]    = typemapmtdTy;
    ktype["typemapmtdPtrTy"] = typemapmtdPtrTy;

    argsTy = [];
    argsTy.add(ctxPtrTy);
    argsTy.add(sfpPtrTy);
    argsTy.add(int64Ty);
    argsTy.add(int64Ty);
    FunctionType fTRTy = FunctionType.get(Type.getVoidTy(), argsTy, false);
    fTRPtrTy = PointerType.get(fTRTy);
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
    oplineTy = StructType.get(fields, false);
    oplinePtrTy = PointerType.get(oplineTy);
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
    methodTy = StructType.get(fields, false);
    m.addTypeName("Method", methodTy);
    methodPtrTy = PointerType.get(methodTy);
    ktype["methodPtrTy"] = methodPtrTy;

    fields = [];
    fields.add(hObjectTy);
    fields.add(int8PtrTy);
    fields.add(fitrnextPtrTy);
    iteratorTy = StructType.get(fields, false);
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
    type = StructType.get(fields, false);
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

