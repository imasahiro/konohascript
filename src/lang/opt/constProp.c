#ifdef SSA_OPT_CP

typedef void (*replace_f) (Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value);

struct OP_REPLACE_RBP_TO_CONST {
	replace_f replace[OPCODE_MAX];
};

#define replaceRBPtoConst_toOSET(op, index, value)\
	DBG_ASSERT(op->data[1] == index);\
	DBG_P("REPLACE %s to OSET", knh_opcode_tochar(op->opcode));\
	op->opcode = OPCODE_OSET;\
	op->data[1] = value

#define replaceRBPtoConst_toNSET(op, index, value)\
	DBG_ASSERT(op->data[1] == index);\
	DBG_P("REPLACE %s to NSET", knh_opcode_tochar(op->opcode));\
	op->opcode = OPCODE_NSET;\
	op->data[1] = value

static void replaceRBPtoConst_OSET(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toOSET(op, index, value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_NSET(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_XMOV(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[2] == index);
	DBG_P("REPLACE XMOV to XOSET");
	op->opcode = OPCODE_XOSET;
	op->data[2] = value;
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

#define replaceRBPtoConst_toJMP(ssa, op, value)\
	knh_BasicBlock_t *bbC = getContainingBB(ssa, op);\
	if (value) {\
		DBG_P("REPLACE %s to NOP and next to next", knh_opcode_tochar(op->opcode));\
		removeBlock(bbC->jumpNC, getPredNum(ssa, bbC, bbC->jumpNC));\
		DP(bbC->jumpNC)->incoming -= 1;\
		iArray_n(ssa->vertex, ID(bbC->jumpNC)) = 0;\
	} else {\
		DBG_P("REPLACE %s to NOP and next to jump", knh_opcode_tochar(op->opcode));\
		removeBlock(bbC->nextNC, getPredNum(ssa, bbC, bbC->nextNC));\
		DP(bbC->nextNC)->incoming -= 1;\
		iArray_n(ssa->vertex, ID(bbC->nextNC)) = 0;\
		bbC->nextNC = bbC->jumpNC;\
	}\
	bbC->jumpNC = NULL;\
	DP(bbC)->size -= 1;\

static void replaceRBPtoConst_JMPF(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toJMP(ssa, op, value);
	UNUSED(ctx);
	UNUSED(index);
}

static void replaceRBPtoConst_bNUL(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, IS_NULL((knh_Object_t*)value));
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_bNN(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, IS_NOTNULL((knh_Object_t*)value));
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_bNOT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, !value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_NEG(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, -value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

#define replaceRBPtoConst_SWAP(op, index, value, offset)\
	DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + offset));\
	op->opcode += offset;\
	if (op->data[1] == index) {\
		op->data[1] = op->data[2];\
		op->data[2] = value;\
	} else if (op->data[2] == index) {\
		op->data[2] = value;\
	}

#define replaceRBPtoConst_noSWAP(op, index, value, offset)\
	DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + offset));\
	if (op->data[1] == index) {\
		TODO(); DBG_ABORT();\
	} else if (op->data[2] == index) {\
		op->opcode += offset;\
		op->data[2] = value;\
	}

#define iOFFSET (OPCODE_iADDn - OPCODE_iADD) // 11
#define fOFFSET (OPCODE_fADDn - OPCODE_fADD) // 10

/*
static knh_intptr_t getRegDef(knh_opline_t *op)
{
	if (op_eq(op, NEXT) || isArraySET(op)) {
		DBG_P("def %s r%d", knh_opcode_tochar(op->opcode), op->data[1]);
		return op->data[1];
	}
	if (isDEF(op) || isCALL(op) || isCAST(op)) {
		DBG_P("def %s r%d", knh_opcode_tochar(op->opcode), op->data[0]);
		return op->data[0];
	}
	DBG_P("nodef %s", knh_opcode_tochar(op->opcode));
	return -10;
}
*/

/*
static void updateUseDef(Ctx *ctx, ssa_data_t *ssa, knh_BasicBlock_t *bb, knh_int_t opbuf)
{
	size_t i, j, k;
	for (i = 0; i < DP(bb)->size; i++) {
		knh_opline_t *opS = DP(bb)->opbuf + i;
		knh_intptr_t rdef = getRegDef(opS);
		if (rdef >= 0) {
			iArray_n(ssa->def, rdef) = (knh_int_t)opS;
		}
		int usebuf[DEF_MAX], *uselist = getRegUseList(ssa, usebuf, opS);
		for (j = 0; uselist[j] != -10; j++) {
			if (uselist[j] >= 0) {
				knh_int_t opUse;
				array_each_next(USE(uselist[j]), k, opUse, iArray_n(USE(uselist[j]), k)) {
					if (opUse >= opbuf && opUse < opbuf + (knh_int_t)(DP(bb)->size * sizeof(knh_opline_t))) {
						iArray_n(USE(uselist[j]), k) = (knh_int_t)opS;
						goto L_END;
					}
				}
				iArray_add(ctx, USE(uselist[j]), (knh_int_t)opS);
			}
L_END:;
		}
	}
}
*/

/*
#define replaceRBPtoConst_SUB(ctx, ssa, op, index, value, offset, newOp)\
	op->opcode += offset;\
	if (op->data[1] == index) {\
		knh_BasicBlock_t *bbc = getContainingBB(ssa, op);\
		knh_opline_t *opbuf = DP(bbc)->opbuf;\
		int line = (int)(op - opbuf + 1);\
		knh_int_t tmp = ssa->rindex + 1;\
		iArray_add(ctx, ssa->def, 0);\
		iArray_add(ctx, ssa->def, 0);\
		knh_Array_add(ctx, ssa->use, new_Array(ctx, CLASS_Int, 0));\
		knh_Array_add(ctx, ssa->use, new_Array(ctx, CLASS_Int, 0));\
		iArray_add(ctx, USE(tmp), (knh_int_t)op);\
		INSERT_OP(ctx, bbc, line, newOp, op->data[0], tmp);\
		op = DP(bbc)->opbuf + line - 2;\
		op->data[0] = tmp;\
		op->data[1] = op->data[2];\
		op->data[2] = value;\
		updateUseDef(ctx, ssa, bbc, (knh_int_t)opbuf);\
	} else if (op->data[2] == index) {\
		op->data[2] = value;\
	}
*/

static void replaceRBPtoConst_inoSWAP(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_noSWAP(op, index, value, iOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iSWAP(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_SWAP(op, index, value, iOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_fnoSWAP(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_noSWAP(op, index, value, fOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_fSWAP(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_SWAP(op, index, value, fOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

#define LT2GT (OPCODE_iGT - OPCODE_iLT) // 2

#define replaceRBPtoConst_LT(op, index, value, offset)\
	if (op->data[1] == index) {\
		DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + LT2GT));\
		op->opcode += LT2GT;\
		op->data[1] = op->data[2];\
		op->data[2] = value;\
	} else if (op->data[2] == index) {\
		DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + offset));\
		op->opcode += offset;\
		op->data[2] = value;\
	}

#define GT2LT (-LT2GT) // -2

#define replaceRBPtoConst_GT(op, index, value, offset)\
	if (op->data[1] == index) {\
		DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + GT2LT));\
		op->opcode += GT2LT;\
		op->data[1] = op->data[2];\
		op->data[2] = value;\
	} else if (op->data[2] == index) {\
		DBG_P("REPLACE %s to %s", knh_opcode_tochar(op->opcode), knh_opcode_tochar(op->opcode + offset));\
		op->opcode += offset;\
		op->data[2] = value;\
	}

static void replaceRBPtoConst_iLT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_LT(op, index, value, iOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iGT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_GT(op, index, value, iOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_ADDn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value + op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_SUBn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value - op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_MULn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value * op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_DIVn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value / op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iMODn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value % op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_EQn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value == op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_NEQn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value != op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_LTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value < op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_LTEn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value <= op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_GTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value > op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_GTEn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value >= op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iANDn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value & op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iORn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value | op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iXORn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value ^ op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iLSFTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value << op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_iRSFTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_toNSET(op, index, value >> op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_fLT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_LT(op, index, value, fOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_fGT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_GT(op, index, value, fOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_bJNUL(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, IS_NULL((knh_Object_t*)value));
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_bJNN(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, IS_NOTNULL((knh_Object_t*)value));
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_bJNOT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, !value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

#define BOFFSET (OPCODE_iJEQn - OPCODE_iJEQ) // 6

static void replaceRBPtoConst_JEQ(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_SWAP(op, index, value, BOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JLT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_LT(op, index, value, BOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JGT(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	replaceRBPtoConst_GT(op, index, value, BOFFSET);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JEQn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value == op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JNEQn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value != op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JLTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value < op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JLTEn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value <= op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JGTn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value > op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_JGTEn(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_ASSERT(op->data[1] == index);
	replaceRBPtoConst_toJMP(ssa, op, value >= op->data[2]);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
}

static void replaceRBPtoConst_PHI(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	if (op->data[1] == index) {
		DBG_P("REPLACE PHIARG 1 r%d to %d", op->data[1], value);
		op->data[1] = value;
//		if (isOBJ(op->data[0]);
//			knh_Object_RCinc(op->obj[1]);
		if (phi_isMod(op, 2))
			op->data[3] = MOD_BOTH;
		else
			op->data[3] = MOD_LEFT;
	} else if (op->data[2] == index) {
		DBG_P("REPLACE PHIARG 2 r%d to %d", op->data[2], value);
		op->data[2] = value;
//		if (isOBJ(op->data[0]))
//			knh_Object_RCinc(op->obj[2]);
		if (phi_isMod(op, 1))
			op->data[3] = MOD_BOTH;
		else
			op->data[3] = MOD_RIGHT;
	}
	UNUSED(ctx);
	UNUSED(ssa);
}

static void replaceRBPtoConst_NULL(Ctx *ctx, ssa_data_t *ssa, knh_opline_t *op, knh_r_t index, knh_int_t value)
{
	DBG_P("Don't replace %s r%d %d", knh_opcode_tochar(op->opcode), index, value);
	UNUSED(ctx);
	UNUSED(ssa);
	UNUSED(index);
	UNUSED(op);
	UNUSED(value);
}

struct OP_REPLACE_RBP_TO_CONST op_replaceRBPtoConst = {{
	replaceRBPtoConst_NULL, // HALT,
	replaceRBPtoConst_NULL, // THCODE,
	replaceRBPtoConst_NULL, // FUNCCALL,
	replaceRBPtoConst_NULL, // ENTER,
	replaceRBPtoConst_NULL, // PROBE,
	replaceRBPtoConst_NULL, // VEXEC,
	replaceRBPtoConst_NULL, // YEILD,
	replaceRBPtoConst_NULL, // EXIT,
	replaceRBPtoConst_NULL, // P,
	replaceRBPtoConst_NULL, // OSET,
	replaceRBPtoConst_NULL, // NSET,
	replaceRBPtoConst_OSET, // OMOV,
	replaceRBPtoConst_NSET, // NMOV,
	replaceRBPtoConst_NULL, // OMOVx,
	replaceRBPtoConst_NULL, // iMOVx,
	replaceRBPtoConst_NULL, // fMOVx,
	replaceRBPtoConst_NULL, // bMOVx,
	replaceRBPtoConst_XMOV, // XMOV,
	replaceRBPtoConst_NULL, // XMOVx,
	replaceRBPtoConst_NULL, // XOSET,
	replaceRBPtoConst_NULL, // XIMOV,
	replaceRBPtoConst_NULL, // XFMOV,
	replaceRBPtoConst_NULL, // XBMOV,
	replaceRBPtoConst_NULL, // CHKSTACK,
	replaceRBPtoConst_NULL, // LOADMTD,
	replaceRBPtoConst_NULL, // CALL,
	replaceRBPtoConst_NULL, // SCALL,
	replaceRBPtoConst_NULL, // VCALL,
	replaceRBPtoConst_NULL, // VCALL_,
	replaceRBPtoConst_NULL, // FASTCALL0,
	replaceRBPtoConst_NULL, // RET,
	replaceRBPtoConst_NULL, // SCAST,
	replaceRBPtoConst_NULL, // TCAST,
	replaceRBPtoConst_NULL, // ACAST,
	replaceRBPtoConst_NULL, // iCAST,
	replaceRBPtoConst_NULL, // fCAST,
	replaceRBPtoConst_NULL, // TR,
	replaceRBPtoConst_NULL, // UNBOX,
	replaceRBPtoConst_NULL, // JMP,
	replaceRBPtoConst_NULL, // JMP_,
	replaceRBPtoConst_JMPF, // JMPF,
	replaceRBPtoConst_NULL, // DYJMP,
	replaceRBPtoConst_NULL, // NEXT,
	replaceRBPtoConst_NULL, // TRY,
	replaceRBPtoConst_NULL, // TRYEND,
	replaceRBPtoConst_NULL, // THROW,
	replaceRBPtoConst_NULL, // CATCH,
	replaceRBPtoConst_bNUL, // bNUL,
	replaceRBPtoConst_bNN, // bNN,
	replaceRBPtoConst_bNOT, // bNOT,
	replaceRBPtoConst_NULL, // iINC,
	replaceRBPtoConst_NULL, // iDEC,
	replaceRBPtoConst_NEG, // iNEG,
	replaceRBPtoConst_iSWAP, // iADD,
	replaceRBPtoConst_inoSWAP, // iSUB,
	replaceRBPtoConst_iSWAP, // iMUL,
	replaceRBPtoConst_inoSWAP, // iDIV,
	replaceRBPtoConst_inoSWAP, // iMOD,
	replaceRBPtoConst_iSWAP, // iEQ,
	replaceRBPtoConst_iSWAP, // iNEQ,
	replaceRBPtoConst_iLT, // iLT,
	replaceRBPtoConst_iLT, // iLTE,
	replaceRBPtoConst_iGT, // iGT,
	replaceRBPtoConst_iGT, // iGTE,
	replaceRBPtoConst_iSWAP, // iAND,
	replaceRBPtoConst_iSWAP, // iOR,
	replaceRBPtoConst_iSWAP, // iXOR,
	replaceRBPtoConst_inoSWAP, // iLSFT,
	replaceRBPtoConst_inoSWAP, // iRSFT,
	replaceRBPtoConst_ADDn, // iADDn,
	replaceRBPtoConst_SUBn, // iSUBn,
	replaceRBPtoConst_MULn, // iMULn,
	replaceRBPtoConst_DIVn, // iDIVn,
	replaceRBPtoConst_iMODn, // iMODn,
	replaceRBPtoConst_EQn, // iEQn,
	replaceRBPtoConst_NEQn, // iNEQn,
	replaceRBPtoConst_LTn, // iLTn,
	replaceRBPtoConst_LTEn, // iLTEn,
	replaceRBPtoConst_GTn, // iGTn,
	replaceRBPtoConst_GTEn, // iGTEn,
	replaceRBPtoConst_iANDn, // iANDn,
	replaceRBPtoConst_iORn, // iORn,
	replaceRBPtoConst_iXORn, // iXORn,
	replaceRBPtoConst_iLSFTn, // iLSFTn,
	replaceRBPtoConst_iRSFTn, // iRSFTn,
	replaceRBPtoConst_NEG, // fNEG,
	replaceRBPtoConst_fSWAP, // fADD,
	replaceRBPtoConst_fnoSWAP, // fSUB,
	replaceRBPtoConst_fSWAP, // fMUL,
	replaceRBPtoConst_fnoSWAP, // fDIV,
	replaceRBPtoConst_fSWAP, // fEQ,
	replaceRBPtoConst_fSWAP, // fNEQ,
	replaceRBPtoConst_fLT, // fLT,
	replaceRBPtoConst_fLT, // fLTE,
	replaceRBPtoConst_fGT, // fGT,
	replaceRBPtoConst_fGT, // fGTE,
	replaceRBPtoConst_ADDn, // fADDn,
	replaceRBPtoConst_SUBn, // fSUBn,
	replaceRBPtoConst_MULn, // fMULn,
	replaceRBPtoConst_DIVn, // fDIVn,
	replaceRBPtoConst_EQn, // fEQn,
	replaceRBPtoConst_NEQn, // fNEQn,
	replaceRBPtoConst_LTn, // fLTn,
	replaceRBPtoConst_LTEn, // fLTEn,
	replaceRBPtoConst_GTn, // fGTn,
	replaceRBPtoConst_GTEn, // fGTEn,
	replaceRBPtoConst_NULL, // OGETIDX,
	replaceRBPtoConst_NULL, // OSETIDX,
	replaceRBPtoConst_NULL, // OGETIDXn,
	replaceRBPtoConst_NULL, // OSETIDXn,
	replaceRBPtoConst_NULL, // NGETIDX,
	replaceRBPtoConst_NULL, // NSETIDX,
	replaceRBPtoConst_NULL, // NGETIDXn,
	replaceRBPtoConst_NULL, // NSETIDXn,
	replaceRBPtoConst_NULL, // BGETIDX,
	replaceRBPtoConst_NULL, // BSETIDX,
	replaceRBPtoConst_NULL, // BGETIDXn,
	replaceRBPtoConst_NULL, // BSETIDXn,
	replaceRBPtoConst_bJNUL, // bJNUL,
	replaceRBPtoConst_bJNN, // bJNN,
	replaceRBPtoConst_bJNOT, // bJNOT,
	replaceRBPtoConst_JEQ, // iJEQ,
	replaceRBPtoConst_JEQ, // iJNEQ,
	replaceRBPtoConst_JLT, // iJLT,
	replaceRBPtoConst_JLT, // iJLTE,
	replaceRBPtoConst_JGT, // iJGT,
	replaceRBPtoConst_JGT, // iJGTE,
	replaceRBPtoConst_JEQn, // iJEQn,
	replaceRBPtoConst_JNEQn, // iJNEQn,
	replaceRBPtoConst_JLTn, // iJLTn,
	replaceRBPtoConst_JLTEn, // iJLTEn,
	replaceRBPtoConst_JGTn, // iJGTn,
	replaceRBPtoConst_JGTEn, // iJGTEn,
	replaceRBPtoConst_JEQ, // fJEQ,
	replaceRBPtoConst_JEQ, // fJNEQ,
	replaceRBPtoConst_JLT, // fJLT,
	replaceRBPtoConst_JLT, // fJLTE,
	replaceRBPtoConst_JGT, // fJGT,
	replaceRBPtoConst_JGT, // fJGTE,
	replaceRBPtoConst_JEQn, // fJEQn,
	replaceRBPtoConst_JNEQn, // fJNEQn,
	replaceRBPtoConst_JLTn, // fJLTn,
	replaceRBPtoConst_JLTEn, // fJLTEn,
	replaceRBPtoConst_JGTn, // fJGTn,
	replaceRBPtoConst_JGTEn, // fJGTEn,
	replaceRBPtoConst_NULL, // ONMOV,
	replaceRBPtoConst_NULL, // OOMOV,
	replaceRBPtoConst_NULL, // NNMOV,
	replaceRBPtoConst_NULL, // NSET2,
	replaceRBPtoConst_NULL, // NSET3,
	replaceRBPtoConst_NULL, // NSET4,
	replaceRBPtoConst_NULL, // OSET2,
	replaceRBPtoConst_NULL, // OSET3,
	replaceRBPtoConst_NULL, // OSET4,
	replaceRBPtoConst_PHI, // PHI,
	replaceRBPtoConst_NULL  // NOP,
}};


static void workwithList(Ctx *ctx, ssa_data_t *ssa, knh_Array_t *wlist, knh_Array_t *wlist_lazy)
{
	size_t i, j;
	knh_opline_t *ops, *opT;
	knh_r_t index, toIndex, fromIndex;
	knh_int_t value;
	while (knh_Array_size(wlist) > 0) {
		ops = (knh_opline_t*)iArray_pop_ret(ctx, wlist);
		if (op_eq(ops, PHI) && ops->data[1] == ops->data[2] && phi_isMod(ops, 1) && phi_isMod(ops, 2)) {
			if (isOBJ(ops->data[0])) {
				DBG_P("REPLACE PHI to OSET");
				ops->opcode = OPCODE_OSET;
			} else {
				DBG_P("REPLACE PHI to NSET");
				ops->opcode = OPCODE_NSET;
			}
			i = 0;
			opT = ops;
			while (op_eq(opT, PHI)) {
				i++;
				opT = ops + i;
			}
			SWAP(ops, opT, sizeof(knh_opline_t));
		}
		if (op_eq(ops, NSET) || op_eq(ops, OSET)) {
			if (ops->data[0] >= 0) {
				index = ops->data[0];
				value = ops->data[1];
				Array_each_next(USE(index), i, opT, Array(opline, USE(index), i)) {
					if (isCALL(opT) || isCAST(opT) || op_eq(opT, fCAST) || op_eq(opT, iCAST) ||
							isArraySET(opT) || op_eq(opT, P) || (op_neq(opT, XMOV) && isVUSE(opT, 1)) ||
							knh_opcode_sfpidx(opT->opcode, 0) || (op_neq(opT, XMOV) && isVDEF(opT, 0))) {
						DBG_P("Don't remove %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
						goto L_SKIP;
					} else if (op_eq(opT, LOADMTD)) {
						DBG_P("Don't remove %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
						goto L_END;
					} else if (op_eq(opT, iSUB) || op_eq(opT, fSUB) || op_eq(opT, iDIV) || op_eq(opT, fDIV) || op_eq(opT, iMOD)) {
						if (opT->data[1] == index) {
							if (wlist_lazy != NULL) {
								DBG_P("add lazy %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
								iArray_add(ctx, wlist_lazy, (knh_int_t)ops);
							}
							goto L_END;
						}
					}
				}
				DBG_P("REMOVE %s r%d %d", knh_opcode_tochar(ops->opcode), index, value);
				DBG_A("used by", printArray_Opline(USE(index)));
				ops->opcode = OPCODE_NOP;
L_SKIP:;
				Array_each_next(USE(index), i, opT, Array(opline, USE(index), i)) {
					DBG_P("r%d is used by %s", index, knh_opcode_tochar(opT->opcode));
					op_replaceRBPtoConst.replace[opT->opcode](ctx, ssa, opT, index, value);
					iArray_insert(ctx, wlist, (knh_int_t)opT);
//					DBG_A("wlist", printArray_Opline(wlist));
				}
			}
		}
L_END:;
		// Copy Propagation
		if (op_eq(ops, NMOV) || op_eq(ops, OMOV)) {
			if (ops->data[0] >= 0) {
				toIndex = ops->data[0];
				fromIndex = ops->data[1];
				Array_each_next(USE(toIndex), i, opT, Array(opline, USE(toIndex), i)) {
					if (isCALL(opT) || isCAST(opT) || op_eq(opT, fCAST) || op_eq(opT, iCAST) ||
							isArraySET(opT) || op_eq(opT, P)) {
						DBG_P("Don't remove %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
						goto L_SKIP2;
					} else if (op_eq(opT, LOADMTD)) {
						DBG_P("Don't remove %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
						goto L_LAST;
					} else if (op_eq(opT, iSUB) || op_eq(opT, fSUB) || op_eq(opT, iDIV) || op_eq(opT, fDIV) || op_eq(opT, iMOD)) {
						if (opT->data[1] == toIndex) {
							if (wlist_lazy != NULL) {
								DBG_P("add lazy %s used by %s", knh_opcode_tochar(ops->opcode), knh_opcode_tochar(opT->opcode));
								iArray_add(ctx, wlist_lazy, (knh_int_t)ops);
							}
							goto L_LAST;
						}
					}
				}
				DBG_P("REMOVE %s r%d r%d", knh_opcode_tochar(ops->opcode), toIndex, fromIndex);
				DBG_A("used by", printArray_Opline(USE(toIndex)));
				ops->opcode = OPCODE_NOP;
L_SKIP2:;
				Array_each_next(USE(toIndex), i, opT, Array(opline, USE(toIndex), i)) {
					if (isCALL(opT) || isCAST(opT))
						goto L_LAST;
					DBG_P("r%d is used by %s", toIndex, knh_opcode_tochar(opT->opcode));
					for (j = 1; j < knh_opcode_size(opT->opcode); j++) {
						if ((isUSE(opT, j) || isVUSE(opT, j) || isVDEF(opT, j)) && opT->data[j] == toIndex) {
							DBG_P("REPLACE %s r%d to r%d", knh_opcode_tochar(opT->opcode), toIndex, fromIndex);
							opT->data[j] = fromIndex;
							iArray_add(ctx, USE(fromIndex), (knh_int_t)opT);
						}
					}
					if (op_eq(opT, NEXT))
						replaceRix(opT);
					iArray_insert(ctx, wlist, (knh_int_t)opT);
//					DBG_A("wlist", printArray_Opline(wlist));
				}
			}
		}
L_LAST:;
	}
}

static void constantPropagation(Ctx *ctx, ssa_data_t *ssa)
{
	DBG_P("=== constnatPropagation ===");
	size_t i, j;
	knh_BasicBlock_t *bbn;
	knh_opline_t *ops;
	BEGIN_LOCAL(ctx, lsfp, 2);
	LOCAL_NEW(ctx, lsfp, 0, knh_Array_t*, wlist, new_Array(ctx, CLASS_Int, 0));
	LOCAL_NEW(ctx, lsfp, 1, knh_Array_t*, wlist_lazy, new_Array(ctx, CLASS_Int, 0));
	Array_each_cast(ssa->vertex, i, bbn, BasicBlock) {
		bblock_each(bbn, j, ops) {
			iArray_add(ctx, wlist, (knh_int_t)ops);
		}
	}
	workwithList(ctx, ssa, wlist, wlist_lazy);
	if (knh_Array_size(wlist_lazy) > 0)
		workwithList(ctx, ssa, wlist_lazy, NULL);
	END_LOCAL(ctx, lsfp);
}

#endif /* SSA_OPT_CP */
