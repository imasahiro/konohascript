using konoha.compiler.*;

String uscore(String in) {
    return "__" + in + "__";
}
LABEL = uscore("label");
void Compiler.addSource(String str, int count) {
    String tmp = "";
    for (int i = 0; i < count; i++) {
        tmp += "\t";
    }
    tmp += str;
    this.source[|source|-1] += tmp + EOL;
}
void Compiler.addFunc(String init) {
    this.source.add(init);
}

@Override void K_PHI.codegen(Compiler asm) {
    /* do not use */
}
void K_BasicBlock.codegen(Compiler asm) {
    /* do not use */
}

void K_Function.codegen(Compiler asm) {
    String fncdef = "";
    if (isStatic == 1) {
        fncdef += "function " + asm.mtd.getName() + "(";
    } else {
        String thisclass = asm.mtd.toStrnig().split(".")[0];
        fncdef += uscore(thisclass) + ".prototype." + asm.mtd.getName() + " = function(";
    }
    for (int i = 1 - isStatic; i < |funcargs|; i++) {
        fncdef += funcargs[i].getName();
        if (i != |funcargs|-1) {
            fncdef += ", ";
        }
    }
    fncdef += ") {";
    asm.addFunc(fncdef);
    if (isStatic == 0) {
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
@Override void K_ADD.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " + " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_SUB.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " - " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_MUL.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " * " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_DIV.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " / " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_MOD.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " % " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_EQ.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " == " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_NEQ.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " != " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_LT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " < " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_GT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " > " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_LTE.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " <= " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_GTE.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " >= " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_AND.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " & " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_OR.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " | " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_NOT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = !" + op.inst0.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_XOR.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " xor " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_SELECT.codegen(Compiler asm) {
    String res = "";
    res += "var " + getName() + " = " + op.inst0.getName() + " ? " op.inst1.getName() + " : " + op.inst2.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_LSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " << " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_RSFT.codegen(Compiler asm) {
    String res;
    res = "var " + getName() + " = " + op.inst0.getName() + " >> " + op.inst1.getName() + ";";
    asm.addSource(res, 3);
}
@Override void K_TCHECK.codegen(Compiler asm) {
    /* do not use */
}
@Override void K_CAST.codegen(Compiler asm) {
    if (op.scid == Float && op.tcid == Int) {
        asm.addSource("var " + getName() + " = " + uscore("Math") + ".floor(" + op.inst0.getName() + ");", 3);
    } else {
        asm.addSource("var " + getName() + " = " + op.inst0.getName() + ";", 3);
    }
    }
}
@Override void K_JMP.codegen(Compiler asm) {
    asm.addSource(LABEL + " = " + op.jmpidx + ";", 3);
}
@Override void K_COND.codegen(Compiler asm) {
    asm.addSource("if (" + op.inst0.getName() + ") {", 3);
    asm.addSource(LABEL + " = " + op.bbThen + ";", 4);
    asm.addSource("} else {", 3);
    asm.addSource(LABEL + " = " + op.bbElse + ";", 4);
    asm.addSource("}", 3);
}
@Override void K_CALL.codegen(Compiler asm) {
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
    String thisclass = op.mtd.toStrnig().split(".")[0];
    if (flag) {
        res += args[0].getName();
    }

    int cur = flag ? 1 : 0;

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
    Value vb = ConstantInt.get(asm.intTy, op.espidx);
    vb = asm.builder.createGEP1(asm.sfp, vb);
    Value rix = ConstantInt.get(asm.intTy, op.rix);
    Value cid = ConstantInt.get(asm.intTy, op.cTBL);
    Value[] vargs = [asm.ctx, vb, rix, cid];
    if (op.inst0 != null) {
        asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(op.inst0.type), op.espidx, op.inst0.getLLVMValue(asm));
    }
    asm.builder.createCall(func, vargs);
    Value v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.espidx + op.rix);
    setLLVMValue(asm, v);
}
@Override void K_NEW.codegen(Compiler asm) {
    Type methodTy = asm.ktype["trmethodPtrTy"];
    Value func;
    if (op.ftr == Stmt.NEW) {
        FunctionType fnTy = asm.kfunctype["trmethodTy"];
        DynamicLibrary.loadLibraryPermanently("compiler.dylib");
        Function tr_new = asm.m.getOrInsertFunction("TR_NEW", fnTy);
        func  = (Value) tr_new;
    } else {
        func = ConstantInt.get(asm.intTy, op.ftr);
        func = asm.builder.CreateIntToPtr(func, methodTy);
    }
    Value vb = ConstantInt.get(asm.intTy, kvalue.idx);
    vb = asm.builder.createGEP1(asm.sfp, vb);
    Value rix = ConstantInt.get(asm.intTy, op.rix);
    Value cid = ConstantInt.get(asm.intTy, op.cTBL);
    asm.builder.createCall4(func, asm.ctx, vb, rix, cid);
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
    v = asm.builder.createLoad(v);
    v = asm.builder.createBitCast(v, PointerType.get(asm.intTy));
    //v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
    v = asm.builder.createInBoundsGEP1(v, op.inst1.getLLVMValue(asm));
    v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst2.type)));
    v = asm.builder.createStore(op.inst2.getLLVMValue(asm), v);
    setLLVMValue(asm, op.inst2.getLLVMValue(asm));
}
@Override void K_CONST.codegen(Compiler asm) {
    Value v;
    if (type == Int) {
        v = ConstantInt.get(asm.intTy, (int)op.const_table[op.table_idx]);
    } else if (type == Float) {
        v = ConstantFP.get(asm.floatTy, (float)op.const_table[op.table_idx]);
    } else if (type == Boolean) {
        v = ConstantInt.get(asm.boolTy, (op.const_table[op.table_idx] == true) ? 1 : 0);
    } else {
        v = asm.builder.CreateIntToPtr(ConstantInt.get(asm.intTy, op.objptr), asm.ktype["objectPtrTy"]);
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
    String cname = (to String) op.inst0.type;
    Type type = asm.user_type[cname];
    if (type == null) {
        asm.register_user_class(op.inst0.type, cname);
    }
    type = asm.user_type[cname];
    if (type != null) {
        v = asm.builder.createBitCast(v, type);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createLoad(v);
        v = asm.builder.createStructGEP(v, op.an);
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
    }
    else {
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrTy"]);
        v = asm.builder.createStructGEP(v, 1);
        v = asm.builder.createLoad(v);
        v = asm.builder.createBitCast(v, asm.ktype["objectPtrPtrTy"]);
        Value vn = ConstantInt.get(asm.intTy, op.an);
        v = asm.builder.createInBoundsGEP1(v, vn);
        v = asm.builder.createBitCast(v, PointerType.get(asm.convertType(op.inst1.type)));
    }
    v = asm.builder.createStore(op.inst1.getLLVMValue(asm), v);
    setLLVMValue(asm, v);
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
    //Type fmethodTy = asm.ktype["fmethodPtrTy"];
    //Value func = ConstantInt.get(asm.intTy, op.ldmtd);
    //func = asm.builder.CreateIntToPtr(func, fmethodTy);
    //Value vop = ConstantInt.get(asm.intTy, op.opline);
    //Value[] vargs = [asm.ctx, asm.sfp, vop];
    //asm.builder.createCall(func, vargs);
}
@Override void K_ARGUMENT.codegen(Compiler asm) {
    Value v;
    if (!op.inner) {
        v = asm.builder.createLoadValueFromSfp(asm.sfp, asm.convertType(type), op.argidx);
    } else {
        Value[] vargs = asm.innerfunc.getArguments();
        int difference = 2 + ((asm.mtd.isStatic() && !asm.mtd.toString().endsWith("new") && !asm.mtd.toString().endsWith("Script.")) ? 0 : 1);
        v = vargs[op.argidx+difference];
        v.setName("arg"+(op.argidx+difference));
        op.inner = false;
    }
    setLLVMValue(asm, v);
}
@Override void K_RET.codegen(Compiler asm) {
    if (asm.retclass != null && op.inst0 != null) {
        asm.builder.createRet(op.inst0.getLLVMValue(asm));
    } else  {
        if (op.inst0 != null && asm.mtd.toString().endsWith("Script.")) {
            asm.builder.createStoreValueToSfp(asm.sfp, asm.convertType(Object), K_RTNIDX, op.inst0.getLLVMValue(asm));
        }
        asm.builder.createRetVoid();
    }
}

void Compiler.emit(Method mtd) {
    if (!kfunc.curBB.hasReturn && kfunc.retTy == null) {
        K_RET inst = new K_RET(new K_RETop(null));
        kfunc.curBB.insts.add(inst);
        kfunc.curBB.hasReturn = true;
    }
    kfunc.codegen(this);
}
