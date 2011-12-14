/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.
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

/* ************************************************************************ */

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* kcode */

#define K_INLINECODE    (10)

static void Tn_asm(CTX ctx, kStmtExpr *stmt, size_t n, int espidx);
static void BLOCK_asm(CTX ctx, kStmtExpr *stmtH);
#define GammaBuilderLabel(ctx, n)   (kBasicBlock*)knh_Array_n(DP(ctx->gma)->lstacks, n)
#define HAS_OPCODE(C)     1

kBasicBlock* new_BasicBlockLABEL(CTX ctx)
{
	kBasicBlock *bb = new_(BasicBlock);
	bb->listNC = DP(ctx->gma)->insts;
	DP(bb)->id = knh_Array_size(bb->listNC);
	knh_Array_add(ctx, DP(ctx->gma)->insts, bb);
	return bb;
}

#if defined(K_USING_THCODE_)
#define TADDR   NULL, 0/*counter*/
#else
#define TADDR   0/*counter*/
#endif/*K_USING_THCODE_*/

#define ASMLINE  0

#define ASM(T, ...) { \
		klr_##T##_t op_ = {TADDR, OPCODE_##T, ASMLINE, ## __VA_ARGS__}; \
		GammaBuilder_asm(ctx, (kopl_t*)(&op_), sizeof(klr_##T##_t)); \
	}\

#define ASMop(T, OP, ...) { \
		klr_##T##_t op_ = {TADDR, OP, ASMLINE, ## __VA_ARGS__}; \
		GammaBuilder_asm(ctx, (kopl_t*)(&op_), sizeof(klr_##T##_t)); \
	}\

#define ASMbranch(T, lb, ...) { \
		klr_##T##_t op_ = {TADDR, OPCODE_##T, ASMLINE, NULL, ## __VA_ARGS__}; \
		ASM_BRANCH_(ctx, lb, (kopl_t*)(&op_), sizeof(klr_##T##_t)); \
	}\

#define BasicBlock_add(ctx, bb, T, ...) { \
		klr_##T##_t op_ = {TADDR, OPCODE_##T, ASMLINE, ## __VA_ARGS__};\
		knh_BasicBlock_add_(ctx, bb, 0, (kopl_t*)(&op_), sizeof(klr_##T##_t));\
	}\

#ifdef K_USING_RBP_
#define NC_(sfpidx)    (((sfpidx) * 2) + 1)
#define OC_(sfpidx)    ((sfpidx) * 2)
#define SFP_(sfpidx)   ((sfpidx) * 2)
#define SFP2_(sfpidx)   (sfpidx)
#else
#define NC_(sfpidx)    sfpidx
#define OC_(sfpidx)    sfpidx
#define SFP_(sfpidx)   sfpidx
#endif

#define RIX_(rix)      rix

static void BasicBlock_expand(CTX ctx, kBasicBlock *bb, size_t newsize)
{
	kopl_t* newbuf = (kopl_t*)KNH_MALLOC(ctx, sizeof(kopl_t) * newsize);
	knh_memcpy(newbuf, DP(bb)->opbuf, DP(bb)->capacity * sizeof(kopl_t));
	knh_bzero(newbuf + DP(bb)->capacity, (newsize - DP(bb)->capacity)*sizeof(kopl_t));
	KNH_FREE(ctx, DP(bb)->opbuf, DP(bb)->capacity * sizeof(kopl_t));
	DP(bb)->opbuf = newbuf;
	DP(bb)->capacity = newsize;
}

void knh_BasicBlock_add_(CTX ctx, kBasicBlock *bb, kushort_t line, kopl_t *op, size_t size)
{
	if(DP(bb)->capacity == 0) {
		DP(bb)->opbuf = (kopl_t*)KNH_MALLOC(ctx, sizeof(kopl_t));
		DP(bb)->capacity = 1;
	}
	else if(DP(bb)->capacity == 1) {
		BasicBlock_expand(ctx, bb, 4);
	}
	else if(DP(bb)->size == DP(bb)->capacity) {
		BasicBlock_expand(ctx, bb, DP(bb)->capacity * 2);
	}
	{
		kopl_t *pc = DP(bb)->opbuf + DP(bb)->size;
		knh_memcpy(pc, op, size == 0 ? sizeof(kopl_t) : size);
#ifdef K_USING_RCGC
		knh_opline_reftrace(ctx, op FTRDATA);
		knh_traverse_refs(ctx, RCinc);
#endif
		pc->line = line;
		DP(bb)->size += 1;
	}
}

static void _bBOX(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct);
static void _BOX(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct);

static void GammaBuilder_asm(CTX ctx, kopl_t *op, size_t opsize)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	DBG_ASSERT(op->opcode != OPCODE_JMPF);
	if(DP(bb)->size > 0) {
		kopl_t *opP = DP(bb)->opbuf + (DP(bb)->size - 1);
		if(op->opcode == opP->opcode && op->opcode <= OPCODE_TR) {
			size_t i, opsize = knh_opcode_size(op->opcode);
			for(i = 0; i < opsize; i++) {
				if(op->data[i] != opP->data[i]) goto L_REMOVE;
			}
			KNH_P("PEEPHOLE: removed same one");
			return;
		}
		L_REMOVE:;
		if(opP->opcode == OPCODE_OSET && op->opcode == OPCODE_TR) {
			klr_OSET_t *opOSET = (klr_OSET_t*)opP;
			klr_TR_t *opTR = (klr_TR_t*)op;
			if(opOSET->a == opTR->a && (opTR->tr == _BOX || opTR->tr == _bBOX)) {
				KNH_P("PEEPHOLE: removed unnecessary BOX"); // is it ok?
				return;
			}
		}
	}
	knh_BasicBlock_add_(ctx, bb, ULINE_line(ctx->gma->uline), op, opsize);
}

static int GammaBuilder_asmJMPF(CTX ctx, klr_JMPF_t *op)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	DBG_ASSERT(op->opcode == OPCODE_JMPF);
	int swap = 0;
	while(DP(bb)->size > 0) {
		kopl_t *opP = DP(bb)->opbuf + (DP(bb)->size - 1);
		if(opP->opcode == OPCODE_bNOT) {
			klr_bNOT_t *opN = (klr_bNOT_t*)opP;
//			DBG_P("REWRITE JMPF index %d => %d", op->a, opN->a);
			op->a = opN->a;
			swap = (swap == 0) ? 1 : 0;
			DP(bb)->size -= 1;
			continue;
		}
		if(OPCODE_iEQ <= opP->opcode && opP->opcode <= OPCODE_iGTE && HAS_OPCODE(iJEQ)) {
			klr_iJEQ_t *opN = (klr_iJEQ_t*)opP;
			ksfpidx_t a = ((klr_iEQ_t*)opP)->a;
			ksfpidx_t b = ((klr_iEQ_t*)opP)->b;
			opN->jumppc = (op)->jumppc;
			opN->a = a; opN->b = b;
			opP->opcode = OPCODE_iJEQ + ((opP)->opcode - OPCODE_iEQ);
			return swap;
		}
		if(OPCODE_iEQC <= opP->opcode && opP->opcode <= OPCODE_iGTEC && HAS_OPCODE(iJEQC)) {
			klr_iJEQC_t *opN = (klr_iJEQC_t*)opP;
			ksfpidx_t a = ((klr_iEQC_t*)opP)->a;
			kint_t n = ((klr_iEQC_t*)opP)->n;
			opN->jumppc = (op)->jumppc;
			opN->a = a; opN->n = n;
			opP->opcode = OPCODE_iJEQC + ((opP)->opcode - OPCODE_iEQC);
			return swap;
		}
		if(OPCODE_fEQ <= opP->opcode && opP->opcode <= OPCODE_fGTE && HAS_OPCODE(fJEQ)) {
			klr_fJEQ_t *opN = (klr_fJEQ_t*)opP;
			ksfpidx_t a = ((klr_fEQ_t*)opP)->a;
			ksfpidx_t b = ((klr_fEQ_t*)opP)->b;
			opN->jumppc = (op)->jumppc;
			opN->a = a; opN->b = b;
			opP->opcode = OPCODE_fJEQ + ((opP)->opcode - OPCODE_fEQ);
			return swap;
		}
		if(OPCODE_fEQC <= opP->opcode && opP->opcode <= OPCODE_fGTEC && HAS_OPCODE(fJEQC)) {
			klr_fJEQC_t *opN = (klr_fJEQC_t*)opP;
			ksfpidx_t a = ((klr_fEQC_t*)opP)->a;
			kfloat_t n = ((klr_fEQC_t*)opP)->n;
			opN->jumppc = (op)->jumppc;
			opN->a = a; opN->n = n;
			opP->opcode = OPCODE_fJEQC + ((opP)->opcode - OPCODE_fEQC);
			return swap;
		}
		break;
	}
	knh_BasicBlock_add_(ctx, bb, ctx->gma->uline, (kopl_t*)op, 0);
	return swap;
}

/* ------------------------------------------------------------------------ */
/* new_KonohaCode */

static inline kopcode_t BasicBlock_opcode(kBasicBlock *bb)
{
	if(DP(bb)->size == 0) return OPCODE_NOP;
	return DP(bb)->opbuf->opcode;
}

//#define BB(bb)   OPCODE__(BasicBlock_opcode(bb))
//
//static void dumpBB(kBasicBlock *bb, const char *indent)
//{
//	size_t i;
////	DBG_P("%sid=%i, size=%d", indent, DP(bb)->id, DP(bb)->size);
//	if(bb->nextNC != NULL) {
////		DBG_P("%s\tnext=%d", indent, DP(bb->nextNC)->id);
//		if(indent[0] == 0) dumpBB(bb->nextNC, "\t");
//	}
//	if(bb->jumpNC != NULL) {
////		DBG_P("%s\tjump=%d", indent, DP(bb->jumpNC)->id);
//		if(indent[0] == 0) dumpBB(bb->jumpNC, "\t");
//	}
//	for(i = 0; i < DP(bb)->size; i++) {
//		kopl_t *op = DP(bb)->opbuf + i;
////		DBG_P("%s\t opcode=%s", indent, OPCODE__(op->opcode));
//		(void)op;
//	}
//}

static void BasicBlock_strip0(CTX ctx, kBasicBlock *bb)
{
	L_TAIL:;
	if(BasicBlock_isVisited(bb)) return;
	BasicBlock_setVisited(bb, 1);
	if(bb->jumpNC != NULL) {
		L_JUMP:;
		kBasicBlock *bbJ = bb->jumpNC;
		if(DP(bbJ)->size == 0 && bbJ->jumpNC != NULL && bbJ->nextNC == NULL) {
			//DBG_P("DIRECT JMP id=%d JMP to id=%d", DP(bbJ)->id, DP(bbJ->jumpNC)->id);
			DP(bbJ)->incoming -= 1;
			bb->jumpNC = bbJ->jumpNC;
			DP(bb->jumpNC)->incoming += 1;
			goto L_JUMP;
		}
		if(DP(bbJ)->size == 0 && bbJ->jumpNC == NULL && bbJ->nextNC != NULL) {
			//DBG_P("DIRECT JMP id=%d NEXT to id=%d", DP(bbJ)->id, DP(bbJ->nextNC)->id);
			DP(bbJ)->incoming -= 1;
			bb->jumpNC = bbJ->nextNC;
			DP(bb->jumpNC)->incoming += 1;
			goto L_JUMP;
		}
		if(bb->nextNC == NULL) {
			if(DP(bbJ)->incoming == 1 ) {
				//DBG_P("REMOVED %d JMP TO %d", DP(bb)->id, DP(bbJ)->id);
				bb->nextNC = bbJ;
				bb->jumpNC = NULL;
				goto L_NEXT;
			}
		}
		BasicBlock_strip0(ctx, bbJ);
	}
	if(bb->jumpNC != NULL && bb->nextNC != NULL) {
		bb = bb->nextNC;
		goto L_TAIL;
	}
	L_NEXT:;
	if(bb->nextNC != NULL) {
		kBasicBlock *bbN = bb->nextNC;
		if(DP(bbN)->size == 0 && bbN->nextNC != NULL && bbN->jumpNC == NULL) {
			//DBG_P("DIRECT NEXT id=%d to NEXT id=%d", DP(bbN)->id, DP(bbN->nextNC)->id);
			DP(bbN)->incoming -= 1;
			bb->nextNC = bbN->nextNC;
			DP(bb->nextNC)->incoming += 1;
			goto L_NEXT;
		}
		if(DP(bbN)->size == 0 && bbN->nextNC == NULL && bbN->jumpNC != NULL) {
			//DBG_P("DIRECT NEXT id=%d to JUMP id=%d", DP(bbN)->id, DP(bbN->jumpNC)->id);
			DP(bbN)->incoming -= 1;
			bb->nextNC = NULL;
			bb->jumpNC = bbN->jumpNC;
			DP(bb->jumpNC)->incoming += 1;
			goto L_JUMP;
		}
		bb = bb->nextNC;
		goto L_TAIL;
	}
}

static void BasicBlock_freebuf(CTX ctx, kBasicBlock *bb)
{
	KNH_FREE(ctx, DP(bb)->opbuf, sizeof(kopl_t) * DP(bb)->capacity);
	DP(bb)->capacity = 0;
	DP(bb)->size = 0;
	DP(bb)->opbuf = NULL;
}

static void BasicBlock_join(CTX ctx, kBasicBlock *bb, kBasicBlock *bbN)
{
	//DBG_P("join %d(%s) size=%d and %d(%s) size=%d", DP(bb)->id, BB(bb), DP(bb)->size, DP(bbN)->id, BB(bbN), DP(bbN)->size);
	bb->nextNC = bbN->nextNC;
	bb->jumpNC = bbN->jumpNC;
	if(DP(bbN)->size == 0) {
		return;
	}
	if(DP(bb)->size == 0) {
		DBG_ASSERT(DP(bb)->capacity == 0);
		DP(bb)->opbuf = DP(bbN)->opbuf;
		DP(bb)->capacity = DP(bbN)->capacity;
		DP(bb)->size = DP(bbN)->size;
		DP(bbN)->opbuf = NULL;
		DP(bbN)->capacity = 0;
		DP(bbN)->size = 0;
		return;
	}
	if(DP(bb)->capacity < DP(bb)->size + DP(bbN)->size) {
		BasicBlock_expand(ctx, bb, DP(bb)->size + DP(bbN)->size);
	}
	knh_memcpy(DP(bb)->opbuf + DP(bb)->size, DP(bbN)->opbuf, sizeof(kopl_t) * DP(bbN)->size);
	DP(bb)->size += DP(bbN)->size;
	BasicBlock_freebuf(ctx, bbN);
}

static void BasicBlock_strip1(CTX ctx, kBasicBlock *bb)
{
	L_TAIL:;
	if(!BasicBlock_isVisited(bb)) return;
	BasicBlock_setVisited(bb, 0);  // MUST call after strip0
	if(bb->jumpNC != NULL) {
		if(bb->nextNC == NULL) {
			bb = bb->jumpNC;
			goto L_TAIL;
		}
		else {
			//DBG_P("** branch next=%d, jump%d", DP(bb->nextNC)->id, DP(bb->jumpNC)->id);
			BasicBlock_strip1(ctx, bb->jumpNC);
			bb = bb->nextNC;
			goto L_TAIL;
		}
	}
	if(bb->nextNC != NULL) {
		kBasicBlock *bbN = bb->nextNC;
		if(DP(bbN)->incoming == 1 && BasicBlock_opcode(bbN) != OPCODE_RET) {
			BasicBlock_join(ctx, bb, bbN);
			BasicBlock_setVisited(bb, 1);
			goto L_TAIL;
		}
		bb = bb->nextNC;
		goto L_TAIL;
	}
}

static size_t BasicBlock_peephole(CTX ctx, kBasicBlock *bb)
{
#define _REMOVE(opX)   opX->opcode = OPCODE_NOP; bbsize--; continue;
#define _REMOVE2(opX, opX2)   opX->opcode = OPCODE_NOP; opX2->opcode = OPCODE_NOP; bbsize -= 2; continue;
#define _REMOVE3(opX, opX2, opX3)   opX->opcode = OPCODE_NOP; opX2->opcode = OPCODE_NOP; opX3->opcode = OPCODE_NOP; bbsize -= 3; continue;

	size_t i, bbsize = DP(bb)->size;
	for(i = 0; i < DP(bb)->size; i++) {
		kopl_t *op = DP(bb)->opbuf + i;
		if(op->opcode == OPCODE_NOP) {
			bbsize--;
		}
	}
	for(i = 1; i < DP(bb)->size; i++) {
		kopl_t *opP = DP(bb)->opbuf + (i - 1);
		kopl_t *op = DP(bb)->opbuf + i;
		if((op->opcode == OPCODE_fCAST || op->opcode == OPCODE_iCAST) && opP->opcode == OPCODE_NMOV) {
			klr_fCAST_t *opCAST = (klr_fCAST_t*)op;
			klr_NMOV_t *opNMOV = (klr_NMOV_t*)opP;
			if(opNMOV->a == opCAST->b && opCAST->a == opCAST->b) {
				opCAST->b = opNMOV->b;
				_REMOVE(opP);
			}
		}
		if(opP->opcode == OPCODE_NSET && op->opcode == OPCODE_NSET) {
			klr_NSET_t *op1 = (klr_NSET_t*)opP;
			klr_NSET_t *op2 = (klr_NSET_t*)op;
			if(op1->a + K_NEXTIDX != op2->a) continue;
			if(sizeof(kuintptr_t) == sizeof(kuint_t)) {
				klr_NSET_t *op3 = (klr_NSET_t*)(DP(bb)->opbuf + i + 1);
				klr_NSET_t *op4 = (klr_NSET_t*)(DP(bb)->opbuf + i + 2);
				if(op3->opcode != OPCODE_NSET || op2->a + K_NEXTIDX != op3->a) goto L_NSET2;
				if(op4->opcode == OPCODE_NSET && op3->a + K_NEXTIDX == op4->a) {
					klr_NSET4_t *opNSET = (klr_NSET4_t*)opP;
					opNSET->opcode = OPCODE_NSET4;
					opNSET->n2 = op2->n;
					opNSET->n3 = op3->n;
					opNSET->n4 = op4->n;
					_REMOVE3(op2, op3, op4);
				}
				else {
					klr_NSET3_t *opNSET = (klr_NSET3_t*)opP;
					opNSET->opcode = OPCODE_NSET3;
					opNSET->n2 = op2->n;
					opNSET->n3 = op3->n;
					_REMOVE2(op2, op3);
				}
			}
			L_NSET2:;
			klr_NSET2_t *opNSET = (klr_NSET2_t*)opP;
			opNSET->opcode = OPCODE_NSET2;
			opNSET->n2 = op2->n;
			_REMOVE(op2);
		}
		if(opP->opcode == OPCODE_OSET && op->opcode == OPCODE_OSET) {
			klr_OSET_t *op1 = (klr_OSET_t*)opP;
			klr_OSET_t *op2 = (klr_OSET_t*)op;
			if(op1->a + K_NEXTIDX != op2->a) continue;
			{
				klr_OSET_t *op3 = (klr_OSET_t*)(DP(bb)->opbuf + i + 1);
				klr_OSET_t *op4 = (klr_OSET_t*)(DP(bb)->opbuf + i + 2);
				if(op3->opcode != OPCODE_OSET || op2->a + K_NEXTIDX != op3->a) goto L_OSET2;
				if(op4->opcode == OPCODE_OSET && op3->a + K_NEXTIDX == op4->a) {
					klr_OSET4_t *opOSET = (klr_OSET4_t*)opP;
					opOSET->opcode = OPCODE_OSET4;
					opOSET->v2 = op2->o;
					opOSET->v3 = op3->o;
					opOSET->v4 = op4->o;
					_REMOVE3(op2, op3, op4);
				}
				else {
					klr_OSET3_t *opOSET = (klr_OSET3_t*)opP;
					opOSET->opcode = OPCODE_OSET3;
					opOSET->v2 = op2->o;
					opOSET->v3 = op3->o;
					_REMOVE2(op2, op3);
				}
			}
			L_OSET2:;
			klr_OSET2_t *opOSET = (klr_OSET2_t*)opP;
			opOSET->opcode = OPCODE_OSET2;
			opOSET->v2 = op2->o;
			_REMOVE(op2);
		}
		if(op->opcode == OPCODE_NMOV) {
#ifdef OPCODE_NNMOV
			if(opP->opcode == OPCODE_NMOV && HAS_OPCODE(NNMOV)) {
				klr_NNMOV_t *opMOV = (klr_NNMOV_t*)opP;
				opMOV->c = ((klr_NMOV_t*)op)->a;
				opMOV->d = ((klr_NMOV_t*)op)->b;
				opP->opcode = OPCODE_NNMOV;
				_REMOVE(op);
			}
			if(opP->opcode == OPCODE_OMOV && HAS_OPCODE(ONMOV)) {
				klr_ONMOV_t *opMOV = (klr_ONMOV_t *)opP;
				opMOV->c = ((klr_NMOV_t*)op)->a;
				opMOV->d = ((klr_NMOV_t*)op)->b;
				opP->opcode = OPCODE_ONMOV;
				_REMOVE(op);
			}
#endif
		}
		if(op->opcode == OPCODE_OMOV) {
#ifdef OPCODE_OOMOV
			if(opP->opcode == OPCODE_OMOV && HAS_OPCODE(OOMOV)) {
				klr_OOMOV_t *opMOV = (klr_OOMOV_t*)opP;
				opMOV->c = ((klr_OMOV_t*)op)->a;
				opMOV->d = ((klr_OMOV_t*)op)->b;
				opP->opcode = OPCODE_OOMOV;
				_REMOVE(op);
			}
			if(opP->opcode == OPCODE_OMOV && HAS_OPCODE(ONMOV)) {
				klr_ONMOV_t *opMOV = (klr_ONMOV_t *)opP;
				opMOV->c = opMOV->a;
				opMOV->d = opMOV->b;
				opMOV->a = ((klr_OMOV_t*)op)->a;
				opMOV->b = ((klr_OMOV_t*)op)->b;
				opP->opcode = OPCODE_ONMOV;
				_REMOVE(op);
			}
#endif
		}
	}
	if(bbsize < DP(bb)->size) {
		kopl_t *opD = DP(bb)->opbuf;
		for(i = 0; i < DP(bb)->size; i++) {
			kopl_t *opS = DP(bb)->opbuf + i;
			if(opS->opcode == OPCODE_NOP) continue;
			if(opD != opS) {
				*opD = *opS;
			}
			opD++;
		}
		DP(bb)->size = bbsize;
	}
	return DP(bb)->size; /*bbsize*/;
}

#define BB_(bb)   (bb != NULL) ? DP(bb)->id : -1

static size_t BasicBlock_size(CTX ctx, kBasicBlock *bb, size_t c)
{
	L_TAIL:;
	if(bb == NULL || BasicBlock_isVisited(bb)) return c;
	BasicBlock_setVisited(bb, 1);
	if(bb->nextNC != NULL) {
		if(BasicBlock_isVisited(bb) || BasicBlock_opcode(bb->nextNC) == OPCODE_RET) {
			kBasicBlock *bb2 = new_BasicBlockLABEL(ctx);
			bb2->jumpNC = bb->nextNC;
			bb->nextNC = bb2;
		}
	}
	if(bb->jumpNC != NULL && bb->nextNC != NULL) {
		DBG_ASSERT(bb->jumpNC != bb->nextNC);
		c = BasicBlock_size(ctx, bb->nextNC, c + BasicBlock_peephole(ctx, bb));
		bb = bb->jumpNC; goto L_TAIL;
	}
	if(bb->jumpNC != NULL) { DBG_ASSERT(bb->nextNC == NULL);
		if(BasicBlock_opcode(bb->jumpNC) == OPCODE_RET) {
			BasicBlock_add(ctx, bb, JMP_);
		}
		else {
			BasicBlock_add(ctx, bb, JMP);
		}
		c = BasicBlock_peephole(ctx, bb) + c;
		bb = bb->jumpNC;
		goto L_TAIL;
	}
	c = BasicBlock_peephole(ctx, bb) + c;
	bb = bb->nextNC;
	goto L_TAIL;
}

static kopl_t* BasicBlock_copy(CTX ctx, kopl_t *dst, kBasicBlock *bb, kBasicBlock **prev)
{
	BasicBlock_setVisited(bb, 0);
	DBG_ASSERT(!BasicBlock_isVisited(bb));
//	DBG_P("BB%d: asm nextNC=BB%d, jumpNC=BB%d", BB_(bb), BB_(bb->nextNC), BB_(bb->jumpNC));
	if(DP(bb)->code != NULL) {
		//DBG_P("BB%d: already copied", BB_(bb));
		return dst;
	}
	if(prev[0] != NULL && prev[0]->nextNC == NULL && prev[0]->jumpNC == bb) {
		dst -= 1;
		//DBG_P("BB%d: REMOVE unnecessary JMP/(?%s)", BB_(bb), OPCODE__(dst->opcode));
		DBG_ASSERT(dst->opcode == OPCODE_JMP || dst->opcode == OPCODE_JMP_);
		prev[0]->jumpNC = NULL;
		prev[0]->nextNC = bb;
	}
	DP(bb)->code = dst;
	if(DP(bb)->size > 0) {
		size_t i;
		knh_memcpy(dst, DP(bb)->opbuf, sizeof(kopl_t) * DP(bb)->size);
		if(bb->jumpNC != NULL) {
			DP(bb)->opjmp = (dst + (DP(bb)->size - 1));
			DBG_ASSERT(knh_opcode_hasjump(DP(bb)->opjmp->opcode));
		}
		for(i = 0; i < DP(bb)->size; i++) {
			kopl_t *op = dst + i;
			if(op->opcode == OPCODE_VCALL) {
				if(BasicBlock_isStackChecked(bb)) {
					op->opcode = OPCODE_VCALL_;
				}
				else {
					BasicBlock_setStackChecked(bb, 1);
				}
			}
			if(op->opcode == OPCODE_iADDC) {
				klr_iADDC_t *opN = (klr_iADDC_t*)op;
				if(opN->a == opN->c && opN->n == 1) {
					op->opcode = OPCODE_iINC;
				}
			}
			if(op->opcode == OPCODE_iSUBC) {
				klr_iSUBC_t *opN = (klr_iSUBC_t*)op;
				if(opN->a == opN->c && opN->n == 1) {
					op->opcode = OPCODE_iDEC;
				}
			}
//			DBG_P("BB%d: [%ld] %s", BB_(bb), i, OPCODE__(op->opcode));
		}
		dst = dst + DP(bb)->size;
		BasicBlock_freebuf(ctx, bb);
		prev[0] = bb;
	}
	if(bb->nextNC != NULL) {
		//DBG_P("BB%d: NEXT=BB%d", BB_(bb), BB_(bb->nextNC));
		DBG_ASSERT(DP(bb->nextNC)->code == NULL);
		if(BasicBlock_isStackChecked(bb) && DP(bb->nextNC)->incoming == 1) {
			BasicBlock_setStackChecked(bb->nextNC, 1);
		}
		dst = BasicBlock_copy(ctx, dst, bb->nextNC, prev);
	}
	if(bb->jumpNC != NULL) {
		//DBG_P("BB%d: JUMP=%d", DP(bb)->id, BB_(bb->jumpNC));
		if(BasicBlock_isStackChecked(bb) && DP(bb->jumpNC)->incoming == 1) {
			BasicBlock_setStackChecked(bb->jumpNC, 1);
		}
		dst = BasicBlock_copy(ctx, dst, bb->jumpNC, prev);
	}
	return dst;
}

static void BasicBlock_setjump(kBasicBlock *bb)
{
	while(bb != NULL) {
		BasicBlock_setVisited(bb, 1);
		if(bb->jumpNC != NULL) {
			kBasicBlock *bbJ = bb->jumpNC;
			klr_JMP_t *j = (klr_JMP_t*)DP(bb)->opjmp;
			j->jumppc = DP(bbJ)->code;
			//DBG_P("jump from id=%d to id=%d %s jumppc=%p", DP(bb)->id, DP(bbJ)->id, OPCODE__(j->opcode), DP(bbJ)->code);
			bb->jumpNC = NULL;
			if(!BasicBlock_isVisited(bbJ)) {
				BasicBlock_setVisited(bbJ, 1);
				BasicBlock_setjump(bbJ);
			}
		}
		bb = bb->nextNC;
	}
}

static kKonohaCode* BasicBlock_link(CTX ctx, kBasicBlock *bb, kBasicBlock *bbRET)
{
	kKonohaCode *kcode = new_(KonohaCode);
	kBasicBlock *prev[1] = {};
	SP(kcode)->uri = ULINE_uri(ctx->gma->uline);
	SP(kcode)->codesize = BasicBlock_size(ctx, bb, 0) * sizeof(kopl_t);
	SP(kcode)->code = (kopl_t*)KNH_MALLOC(ctx, SP(kcode)->codesize);
	DP(bbRET)->code = SP(kcode)->code; // dummy
	{
		kopl_t *op = BasicBlock_copy(ctx, SP(kcode)->code, bb, prev);
		DBG_ASSERT(op - kcode->code > 0);
		DP(bbRET)->code = NULL;
		BasicBlock_copy(ctx, op, bbRET, prev);
		BasicBlock_setjump(bb);
	}
	return kcode;
}

/* ------------------------------------------------------------------------ */

KMETHOD knh_Fmethod_runVM(CTX ctx, ksfp_t *sfp _RIX)
{
	DBG_ASSERT(K_RIX == K_RTNIDX);
	DBG_ASSERT(IS_Method(sfp[K_MTDIDX].mtdNC));
	knh_VirtualMachine_run(ctx, sfp, CODE_VEXEC);
}

static void Method_threadCode(CTX ctx, kMethod *mtd, kKonohaCode *kcode)
{
	knh_Method_setFunc(ctx, mtd, knh_Fmethod_runVM);
	KNH_SETv(ctx, DP(mtd)->kcode, kcode);
	//if(O_isTenure(mtd)) O_toTenure(kcode);
	(mtd)->pc_start = knh_VirtualMachine_run(ctx, ctx->esp + 1, SP(kcode)->code);
	if(knh_isVerboseLang() && mtd->mn != MN_) {
		knh_write_Object(ctx, KNH_STDOUT, UPCAST(mtd), FMT_dump);
		knh_write_EOL(ctx, KNH_STDOUT);
	}
}

static void GammaBuilder_compile(CTX ctx, kBasicBlock *bb, kBasicBlock *bbRET)
{
	kMethod *mtd = DP(ctx->gma)->mtd;
	BasicBlock_strip0(ctx, bb);
	BasicBlock_strip1(ctx, bb);
#ifdef K_USING_SSA
	// SSA optimization
	knh_BasicBlock_optimize(ctx, bb);
#endif
	kKonohaCode *kcode = BasicBlock_link(ctx, bb, bbRET);
	DBG_ASSERT(IS_Method(mtd));
	Method_threadCode(ctx, mtd, kcode);
	KNH_SETv(ctx, DP(ctx->gma)->mtd, KNH_NULL);
	knh_Array_clear(ctx, DP(ctx->gma)->lstacks, 0);
	knh_Array_clear(ctx, DP(ctx->gma)->insts, 0);
}

static void ASM_LABEL(CTX ctx, kBasicBlock *label)
{
	if(label != NULL) {
		kBasicBlock *bb = DP(ctx->gma)->bbNC;
		if(bb != NULL) {
			bb->nextNC = label;
			DP(label)->incoming += 1;
			bb->jumpNC = NULL;
		}
		DP(ctx->gma)->bbNC = label;
	}
}

static void ASM_JMP(CTX ctx, kBasicBlock *label)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	if(bb != NULL) {
		bb->nextNC = NULL;
		bb->jumpNC = label;  DP(label)->incoming += 1;
	}
	DP(ctx->gma)->bbNC = NULL; /*KNH_TNULL(BasicBlock);*/
}

static kBasicBlock* ASM_JMPF(CTX ctx, int flocal, kBasicBlock *lbJUMP)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	kBasicBlock *lbNEXT = new_BasicBlockLABEL(ctx);
	klr_JMPF_t op = {TADDR, OPCODE_JMPF, ASMLINE, NULL, NC_(flocal)};
	if(GammaBuilder_asmJMPF(ctx, &op)) {
		bb->jumpNC = lbNEXT;
		bb->nextNC = lbJUMP;
	}
	else {
		bb->jumpNC = lbJUMP;
		bb->nextNC = lbNEXT;
	}
	DP(lbJUMP)->incoming += 1;
	DP(lbNEXT)->incoming += 1;
	DP(ctx->gma)->bbNC = lbNEXT;
	return lbJUMP;
}

static void ASM_BRANCH_(CTX ctx, kBasicBlock *jump, kopl_t *op, size_t size)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	kBasicBlock *newbb = new_BasicBlockLABEL(ctx);
	GammaBuilder_asm(ctx, op, size);
	bb->jumpNC = jump;  DP(jump)->incoming += 1;
	bb->nextNC = newbb;  DP(newbb)->incoming += 1;
	DP(ctx->gma)->bbNC = newbb;
}

static void ASM_RET(CTX ctx, kStmtExpr *stmt)
{
//	while(DP(stmt)->nextNULL != NULL) {
//		stmt = DP(stmt)->nextNULL;
//		if(STT_(stmt) == STT_CHKOUT) {
//			CHKOUT_asm(ctx, stmt);
//		}
//	}
//	{
		kBasicBlock *bbEND = GammaBuilderLabel(ctx,  2);
		ASM_JMP(ctx, bbEND);
//	}
}

/* ------------------------------------------------------------------------ */
/* [func] */

static void _NULVAL(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	KNH_SETv(ctx, sfp[c].o, ct->fdefnull(ctx, ct->cid));
}
void knh_PROP(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	Object *v = (Object*)knh_getPropertyNULL(ctx, S_tobytes(sfp[0].s));
	if(v == NULL) v = ct->fdefnull(ctx, ct->cid);
	KNH_SETv(ctx, sfp[c].o, v);
}
void knh_NPROP(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	Object *v = (Object*)knh_getPropertyNULL(ctx, S_tobytes(sfp[0].s));
	sfp[c].ndata = (v == NULL) ? 0 : O_data(v);
}
static void _VARGS(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	kArray *a = new_Array(ctx, ct->cid, ctx->esp - (sfp - 1));
	a->api->multiadd(ctx, a, sfp - 1);
	KNH_SETv(ctx, sfp[c].o, a);
}
static void _bBOX(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	kObject *b = sfp[0].bvalue ? KNH_TRUE : KNH_FALSE;
	KNH_SETv(ctx, sfp[c].o, b);
}
static void _BOX(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	Object *v = new_Boxing(ctx, sfp, ct);
	KNH_SETv(ctx, sfp[c].o, v);
}
static void _CWB(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	KNH_SETv(ctx, sfp[c].o, cwb->w);
	sfp[c].ivalue = cwb->pos;
}
static void _TOSTR(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	DBG_ASSERT(IS_OutputStream(sfp[0].w));
	CWB_t cwbbuf = {ctx->bufa, ctx->bufw, (size_t)(sfp[0].ivalue)};
	kString *s = CWB_newString(ctx, &cwbbuf, 0);
	KNH_SETv(ctx, sfp[c].o, s);
}
static void _ERR(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	if(IS_bString(sfp[0].o)) {
		CTX_setThrowingException(ctx, new_Error(ctx, 0, sfp[0].s));
	}
	else {
		DBG_ASSERT(IS_Exception(sfp[0].o));
		CTX_setThrowingException(ctx, sfp[0].e);
	}
}
static void _TCHECK(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	const knh_ClassTBL_t *ct0 = O_cTBL(sfp[0].o);
	if(ct0->cid != ct->cid && !ClassTBL_isa_(ctx, ct0, ct)) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_printf(ctx, cwb->w, "ClassCast!!: %C is not %C", O_cid(sfp[0].o), ct->cid);
		CTX_setThrowingException(ctx, new_Error(ctx, 0, CWB_newString(ctx, cwb, SPOL_POOLNEVER|SPOL_ASCII)));
		knh_throw(ctx, NULL, 0);
	}
}
static void _TUNBOX(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	const knh_ClassTBL_t *ct0 = O_cTBL(sfp[0].o);
	if(ct0->cid != ct->cid && !ClassTBL_isa_(ctx, ct0, ct)) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_printf(ctx, cwb->w, "ClassCast!!: %C is not %C", O_cid(sfp[0].o), ct->cid);
		CTX_setThrowingException(ctx, new_Error(ctx, 0, CWB_newString(ctx, cwb, SPOL_POOLNEVER|SPOL_ASCII)));
		knh_throw(ctx, NULL, 0);
	}
	else{
		sfp[c].ndata = O_ndata(sfp[0].o);
	}
}
//static kMethod* _SETMTD(CTX ctx, ksfp_t *sfp, int thisidx, kMethod *mtd)
//{
//	return mtd;
//}
static void _LOOKUPMTD(CTX ctx, ksfp_t *sfp, struct klr_LDMTD_t *op)
{
	size_t thisidx = op->thisidx / 2;
	const knh_ClassTBL_t *ct = O_cTBL(sfp[thisidx].o);
	if(op->cache.cid != ct->cid) {
		kMethod *mtd = ClassTBL_getMethod(ctx, ct, op->cache.mn);
		op->mtdNC = mtd;
		op->cache.cid = ct->cid;
	}
	sfp[thisidx+K_MTDIDX].mtdNC = op->mtdNC;
}
static void _DYNMTD(CTX ctx, ksfp_t *sfp, struct klr_LDMTD_t *op)
{
	size_t thisidx = op->thisidx / 2;
	const knh_ClassTBL_t *ct = O_cTBL(sfp[thisidx].o);
	kclass_t this_cid = ct->cid;
	if(this_cid != op->cache.cid) {
		kMethod* mtd = knh_ClassTBL_findMethodNULL(ctx, ct, op->cache.mn, 0);
		if(mtd == NULL) {
			THROW_NoSuchMethod(ctx, sfp, this_cid, op->cache.mn);
		}
		op->mtdNC = mtd;
		op->cache.cid = ct->cid;
	}
	kMethod* mtd = op->mtdNC;
	if(IS_Tunbox(mtd->cid)) {
		sfp[thisidx].ndata = O_ndata(sfp[thisidx].o);
	}
	size_t i, argc = Param_isVARGs(DP(mtd)->mp) ? (ctx->esp - sfp) : knh_Method_psize(mtd);
	//DBG_P("argc=%d, psize=%d, esp-sfp=%d, isVARGs=%d", argc, knh_Method_psize(mtd), (ctx->esp - sfp), Param_isVARGs(DP(mtd)->mp));
	for(i = 0; i < argc; i++) {
		size_t idx = thisidx+1+i;
		kObject *o = sfp[idx].o;
		ktype_t reqt = knh_Method_ptype(ctx, mtd, i, this_cid);
		ct = O_cTBL(o);
		DBG_P("i=%d, reqt=%s, O_cid=%s", i, TYPE__(reqt), CLASS__(ct->cid));
		if(reqt == ct->cid && ClassTBL_isa(ct, reqt)) {
			if(IS_Tunbox(reqt)) {
				sfp[idx].ndata = O_ndata(o);
			}
			continue;
		}
		if(IS_Tfloat(reqt) && IS_Tint(ct->cid)) {
			sfp[idx].fvalue = (kfloat_t)N_toint(o); continue;
		}
		if(IS_Tint(reqt) && IS_Tfloat(ct->cid)) {
			sfp[idx].ivalue = (kint_t)N_tofloat(o); continue;
		}
		/* dynamic args */
		if (reqt == TYPE_dyn) {
			continue;
		}
		THROW_ParamTypeError(ctx, sfp, i, (mtd)->mn, reqt, O_cid(o));
	}
	sfp[thisidx+K_MTDIDX].mtdNC = op->mtdNC;
}
static void _PBOX(CTX ctx, ksfp_t *sfp, struct klr_PROBE_t *op)
{
	size_t rtnidx = op->sfpidx;
	klr_LDMTD_t *opP = (klr_LDMTD_t*)(((kopl_t*)op) - 2);
	DBG_ASSERT(opP->opcode == OPCODE_LDMTD);
	ktype_t rtype = knh_Param_rtype(DP(opP->mtdNC)->mp);
	rtype = ktype_tocid(ctx, rtype, O_cid(sfp[rtnidx+K_CALLDELTA].o));
	if(IS_Tunbox(rtype)) {
		KNH_SETv(ctx, sfp[rtnidx].o, new_Boxing(ctx, sfp+rtnidx, ClassTBL(rtype)));
	}
}

/* SYSVAL */
static KMETHOD Fmethod_CTX(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_((Object*)knh_toContext(ctx));
}
static KMETHOD Fmethod_CTXIN(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->in);
}
static KMETHOD Fmethod_CTXOUT(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->out);
}
static KMETHOD Fmethod_CTXERR(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->err);
}
static KMETHOD Fmethod_STDIN(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->share->in);
}
static KMETHOD Fmethod_STDOUT(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->share->out);
}
static KMETHOD Fmethod_STDERR(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->share->err);
}
static KMETHOD Fmethod_SYS(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(KNH_TNULL(System));
}
static KMETHOD Fmethod_SCRIPT(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(ctx->script);
}

static knh_Fmethod SYSVAL_MTD[] = {
	Fmethod_CTX,
	Fmethod_CTXIN,
	Fmethod_CTXOUT,
	Fmethod_CTXERR,
	Fmethod_STDIN,
	Fmethod_STDOUT,
	Fmethod_STDERR,
	Fmethod_SYS,
	Fmethod_SCRIPT,
};

/* ------------------------------------------------------------------------ */
/* [GammaBuilder] */

#define TT_isSFPIDX(tk)   (TT_(tk) == TT_LVAR || TT_(tk) == TT_FVAR)
#define Term_index(tk)   Term_index_(ctx, tk)
#define _ESPIDX           DP(stmt)->espidx

static inline int Term_index_(CTX ctx, kTerm *tk)
{
	return (int)(tk)->index/* + ((TT_(tk) == TT_LVAR) ? DP(ctx->gma)->ebpidx : 0)*/;
}

//#define(idx) (idx < DP(stmt)->espidx) ? (DP(stmt)->espidx) : idx
//
//static void ASM_MOVL(CTX ctx, ktype_t reqt, int sfpidx, ktype_t ltype, int local)
//{
//	if(sfpidx < DP(stmt)->espidx) {
//		if(IS_Tunbox(ltype)) {
//			ASM(NMOV, NC_(sfpidx), NC_(local));
//		}
//		else {
//#if defined(K_USING_RCGC) && defined(OPCODE_SWAP)
//			ASM(SWAP, NC_(sfpidx), NC_(local));
//#else
//			ASM(OMOV, OC_(sfpidx), OC_(local));
//#endif
//		}
//	}
//}

static int Tn_put(CTX ctx, kStmtExpr *stmt, size_t n, int alocal)
{
	kTerm *tk = tkNN(stmt, n);
	if(TT_(tk) == TT_FVAR) return Term_index(tk);
	Tn_asm(ctx, stmt, n, alocal);
	return alocal;
}

static kTerm* Tn_putTK(CTX ctx, kStmtExpr *stmt, size_t n, int alocal)
{
	kTerm *tk = tkNN(stmt, n);
	if(IS_StmtExpr(tk)) {
		Tn_asm(ctx, stmt, n, alocal);
		DBG_ASSERT(IS_Term(tkNN(stmt, n)));
		return tkNN(stmt, n);
	}
	return tk;
}


static void ASM_SMOVx(CTX ctx, int alocal, ktype_t btype, ksfx_t bx)
{
	if(IS_Tunbox(btype)) {
		ASM(NMOVx, NC_(alocal), bx);
	}
	else {
		ASM(OMOVx, OC_(alocal), bx);
	}
}

static void Term_setsfx(CTX ctx, kTerm *tk, ksfx_t *x)
{
	x->i = 0;
	x->n = (tk)->index;
	if(IS_Term(tk->tkIDX) && TT_(tk->tkIDX) == TT_FVAR) {
		x->i = OC_(Term_index(tk->tkIDX));
	}
	DBG_P("tk=%s, x->i=%d, x->n=%d", TT__(tk->tt), x->i/2, x->n);
}

static void ASM_SMOV(CTX ctx, int alocal, kTerm *tk)
{
	ktype_t type = SP(tk)->type;
	switch(TT_(tk)) {
		case TT_ASIS:
			break;
		case TT_NULL/*DEFVAL*/: {
			kclass_t cid = (tk)->cid;
			kObject *v = KNH_NULVAL(cid);
			if(v != ClassTBL(cid)->defnull) {
				ASM(TR, OC_(alocal), SFP_(alocal), RIX_(alocal-alocal), ClassTBL(cid), _NULVAL);
				break;
			}
			KNH_SETv(ctx, (tk)->data, v);
			goto L_CONST;
		}
		case TT_CID:
			KNH_SETv(ctx, (tk)->data, new_Type(ctx, (tk)->cid));
		case TT_CONST: L_CONST:; {
			Object *v = (tk)->data;
			if(IS_Tunbox(type)) {
				ASM(NSET, NC_(alocal), O_data((tk)->data));
			}
			else {
				ASM(OSET, OC_(alocal), v);
			}
			break;
		}
		case TT_FVAR: {
			int b = Term_index(tk);
			if(IS_Tunbox(type)) {
				ASM(NMOV, NC_(alocal), NC_(b));
			}
			else {
				ASM(OMOV, OC_(alocal), OC_(b));
			}
			break;
		}
		case TT_FIELD: {
			ksfx_t bx;
			Term_setsfx(ctx, tk, &bx);
			ASM_SMOVx(ctx, alocal, type, bx);
			break;
		}
		case TT_SYSVAL: {
			size_t sysid = (tk)->index;
			KNH_ASSERT(sysid < K_SYSVAL_MAX);
			ASM(FASTCALL0, SFP_(alocal), SFP_(alocal), 0, SFP_(alocal), SYSVAL_MTD[sysid]);
			break;
		}
		case TT_PROPN: {
			const knh_ClassTBL_t *ct = ClassTBL(CLASS_t(type));
			ASM(OSET, OC_(alocal), (tk)->data);
			if(IS_Tunbox(type)) {
				ASM(TR, NC_(alocal), SFP_(alocal), RIX_(alocal-alocal), ct, knh_NPROP);
			}
			else {
				ASM(TR, OC_(alocal), SFP_(alocal), RIX_(alocal-alocal), ct, knh_PROP);
			}
			break;
		}
		default: {
			DBG_ABORT("unknown TT=%s", TT__(TT_(tk)));
		}
	}/*switch*/
}

static void ASM_XMOVx(CTX ctx, ksfx_t ax, ktype_t btype, ksfx_t bx)
{
	if(IS_Tunbox(btype)) {
		ASM(XNMOVx, ax, bx);
	}
	else {
		ASM(XMOVx, ax, bx);
	}
}

static void ASM_XMOV(CTX ctx, ksfpidx_t alocal, size_t an, kTerm *tkb, int espidx)
{
	ksfx_t ax = {alocal, an};
	ktype_t btype = SP(tkb)->type;
	int used_espidx = -1;
	switch(TT_(tkb)) {
		case TT_NULL/*DEFVAL*/: {
			kclass_t cid = (tkb)->cid;
			kObject *v = KNH_NULVAL(cid);
			if(v != ClassTBL(cid)->defnull) {
				used_espidx = espidx;
				ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(cid), _NULVAL);
				break;
			}
			KNH_SETv(ctx, (tkb)->data, v);
			goto L_CONST;
		}
		case TT_CID:
			KNH_SETv(ctx, (tkb)->data, new_Type(ctx, (tkb)->cid));
			/* FALLTHROUGH */
		case TT_CONST: L_CONST:; {
			Object *v = (tkb)->data;
			if(IS_Tunbox(btype)) {
				ASM(XNSET, ax, O_data(v));
			}
			else {
				ASM(XOSET, ax, v);
			}
			break;
		}
		case TT_FVAR: {
			int b = Term_index(tkb);
			if(IS_Tunbox(btype)) {
				ASM(XNMOV, ax, NC_(b));
			}
			else {
				ASM(XMOV, ax, OC_(b));
			}
			break;
		}
		case TT_FIELD: {
			ksfx_t bx;
			Term_setsfx(ctx, tkb, &bx);
			ASM_XMOVx(ctx, ax, btype, bx);
			break;
		}
		case TT_SYSVAL: {
			size_t sysid = (tkb)->index;
			KNH_ASSERT(sysid < K_SYSVAL_MAX);
			used_espidx = espidx;
			ASM(FASTCALL0, SFP_(espidx), SFP_(espidx), 0, SFP_(espidx + 1), SYSVAL_MTD[sysid]);
			break;
		}
		case TT_PROPN: {
			used_espidx = espidx;
			const knh_ClassTBL_t *ct = ClassTBL(CLASS_t(btype));
			ASM(OSET, OC_(espidx), (tkb)->data);
			if(IS_Tunbox(btype)) {
				ASM(TR, NC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ct, knh_NPROP);
			}
			else {
				ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ct, knh_PROP);
			}
			break;
		}
		default: {
			DBG_ABORT("unknown TT=%d", TT_(tkb));
		}
	}/*switch*/
	if(used_espidx != -1) {
		if(IS_Tunbox(btype)) {
			ASM(XNMOV, ax, NC_(espidx));
		}
		else {
			ASM(XMOV, ax, OC_(espidx));
		}
	}
}

static void ASM_MOV(CTX ctx, kTerm *tka, kTerm *tkb, int espidx)
{
	DBG_ASSERT(Term_isTyped(tka));
	DBG_ASSERT(IS_Term(tkb));
	DBG_ASSERT(Term_isTyped(tkb));
	if(TT_(tka) == TT_FVAR) {
		ASM_SMOV(ctx, Term_index(tka), tkb);
	}
	else {
		DBG_P("TT=%s", TT__(tka->tt));
		DBG_ASSERT(TT_(tka) == TT_FIELD);
		ksfx_t x;
		Term_setsfx(ctx, tka, &x);
		ASM_XMOV(ctx, x.i, x.n, tkb, espidx);
	}
}

static kBasicBlock* Tn_JMPIF(CTX ctx, kStmtExpr *stmt, size_t n, int isTRUE, kBasicBlock* label, int alocal)
{
	kTerm *tk = tkNN(stmt, n);
	if(TT_(tk) == TT_CONST) {
		int isTRUE2 = IS_TRUE((tk)->data);
		ASM_SMOV(ctx, alocal, tk);
		if((!isTRUE && !isTRUE2) || (isTRUE && isTRUE2)) {
			ASM_JMP(ctx, label);
			return label;
		}
		return NULL;
	}
	if(TT_(tk) == TT_FVAR) {
		int index = Term_index(tk);
		if(isTRUE) {
			ASM(bNOT, NC_(index), NC_(index));
		}
		return ASM_JMPF(ctx, index, label);
	}
	else {
		Tn_asm(ctx, stmt, n, alocal);
		if(isTRUE) {
			ASM(bNOT, NC_(alocal), NC_(alocal));
		}
		return ASM_JMPF(ctx, alocal, label);
	}
}

/* ------------------------------------------------------------------------ */
/* [EXPR] */

static void ASM_SAFEPOINT(CTX ctx, int espidx)
{
#ifdef K_USING_SAFEPOINT
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	size_t i;
	for(i = 0; i < DP(bb)->size; i++) {
		kopl_t *op = DP(bb)->opbuf + i;
		if(op->opcode == OPCODE_SAFEPOINT) return;
	}
	ASM(SAFEPOINT, SFP_(espidx));
#endif
}

/* ------------------------------------------------------------------------ */
/* CALL */

static inline kint_t Tn_int(kStmtExpr *stmt, size_t n)
{
	kTerm *tk = tkNN(stmt, n);
	DBG_ASSERT(TT_(tk) == TT_CONST);
	return ((tk)->num)->n.ivalue;
}

static inline kfloat_t Tn_float(kStmtExpr *stmt, size_t n)
{
	kTerm *tk = tkNN(stmt, n);
	DBG_ASSERT(TT_(tk) == TT_CONST);
	return ((tk)->num)->n.fvalue;
}

//static ktype_t Tn_ptype(CTX ctx, kStmtExpr *stmt, size_t n, kclass_t cid, kMethod *mtd)
//{
//	if(!IS_Method(mtd)) {
//		return TYPE_dyn;  // boxing
//	}
//	if(n == 1) { // base
//		if(IS_Tunbox(cid) && cid != (mtd)->cid) {
//			/* Object, Number, dynamic */
//			cid = (mtd)->cid;
//		}
//		DBG_(
//		if(cid != (mtd)->cid) {
//			DBG_P("** WATCH OUT ** mtd_cid=%s, (mtd)->cid=%s", CLASS__(cid), CLASS__((mtd)->cid));
//		});
//		return cid;
//	}
//	else {
//		ktype_t ptype = knh_Param_getptype(DP(mtd)->mp, n - 2);
//		return ktype_tocid(ctx, ptype, cid);
//	}
//}

static int CALLPARAMs_asm(CTX ctx, kStmtExpr *stmt, size_t s, int local, kclass_t cid, kMethod *mtd)
{
	size_t i;
	if(s == 1 && Method_isStatic(mtd)) s = 2;   // ignoring static caller, like Script
	if(DP(stmt)->size + DP(stmt)->espidx > 32) {
		ASM(CHKSTACK, SFP_(DP(stmt)->size + DP(stmt)->espidx));
	}
	for(i = s; i < DP(stmt)->size; i++) {
		Tn_asm(ctx, stmt, i, local + i + (K_CALLDELTA-1));
	}
//	// TODO(@imasahiro)
//	if(Stmt_isTAILRECURSION(stmt) && GammaBuilder_isTailRecursion(ctx->gma)) {
//		kBasicBlock *lbBEGIN = GammaBuilderLabel(ctx, 1);
//		for(i = s; i < DP(stmt)->size; i++) {
//			ktype_t reqt = Tn_type(stmt, i); //Tn_ptype(ctx, stmt, i, cid, mtd);
//			if(IS_Tunbox(reqt)) {
//				ASM(NMOV, NC_(i-1), NC_(local + i + (K_CALLDELTA-1)));
//			}
//			else {
//				ASM(OMOV, OC_(i-1), OC_(local + i + (K_CALLDELTA-1)));
//			}
//		}
//		ASM_JMP(ctx, lbBEGIN);
//		return 0;
//	}
	return 1;
}

static void ASM_INLINE(CTX ctx, int sfpshift, kopl_t *code, size_t isize)
{
	size_t i, last = isize;
	kBasicBlock* bb[K_INLINECODE];
	for(i = 0; i < isize; i++) {
		bb[i] = new_BasicBlockLABEL(ctx);
		bb[i]->nextNC = NULL;
		bb[i]->jumpNC = NULL;
		if(code[i].opcode == OPCODE_RET) {
			last = i; break;
		}
	}
	KNH_ASSERT(last != isize);
	ASM_LABEL(ctx, bb[0]);
	for(i = 0; i < last; i++) {
		kopl_t opbuf, *op;
		opbuf = code[i]; op = &opbuf;
		knh_opcode_shift(op, sfpshift);
		if(op->opcode == OPCODE_JMP_) {
			op->opcode = OPCODE_JMP;
		}
		if(op->opcode != OPCODE_JMP) {
			knh_BasicBlock_add_(ctx, bb[i], op->line, op, 0);
			bb[i]->nextNC = bb[i+1];
			DP(bb[i+1])->incoming += 1;
		}
		if(knh_opcode_hasjump(op->opcode)) {
			int jmpidx = code - (kopl_t*)(op->p[0]);
			if (jmpidx < 0) jmpidx = -jmpidx;
			DBG_ASSERT(jmpidx < (int)isize);
			bb[i]->jumpNC = bb[jmpidx];
			DP(bb[jmpidx])->incoming += 1;
			op->p[0] = NULL;
		}
	}
	DP(ctx->gma)->bbNC = bb[last];
	DBG_ASSERT(DP(bb[last])->incoming > 0);
}

#define ESP_(sfpidx, args)   SFP_(sfpidx + args + K_CALLDELTA + 1)

static kreg_t RTNIDX_(CTX ctx, int sfpidx, ktype_t rtype)
{
	if(rtype == TYPE_void) return -1;
	if(IS_Tunbox(rtype)) return NC_(sfpidx);
	return OC_(sfpidx);
}

static void ASM_CALL(CTX ctx, int espidx, ktype_t rtype, kMethod *mtd, int isStatic, size_t argc)
{
	int thisidx = espidx + K_CALLDELTA;
	DBG_ASSERT(IS_Method(mtd));
	if(Method_isFinal(mtd) || isStatic) {
		if(Method_isKonohaCode(mtd) || DP(ctx->gma)->mtd == mtd) {
			if(GammaBuilder_isInlineFunction(ctx->gma) && DP(ctx->gma)->mtd != mtd) {
				kKonohaCode *kcode = DP(mtd)->kcode;
				size_t isize = kcode->codesize / sizeof(kopl_t);
				if(isize < K_INLINECODE) {
					NoticeInliningMethod(ctx, mtd);
					if(isize-1 > 0) {
						ASM_INLINE(ctx, espidx + K_CALLDELTA, kcode->code + 1, isize - 1);
					}
					return;
				}
			}
			if(argc == 0) {
				ASM(VCALL_, RTNIDX_(ctx, espidx, rtype), SFP_(thisidx), ESP_(espidx, argc), mtd);
			}
			else {
				ASM(VCALL, RTNIDX_(ctx, espidx, rtype), SFP_(thisidx), ESP_(espidx, argc), mtd);
			}
		}
		else {
			ASM(SCALL, RTNIDX_(ctx, espidx, rtype), SFP_(thisidx), ESP_(espidx, argc), mtd);
		}
	}
	else {
		ASM(LDMTD, SFP_(thisidx), _LOOKUPMTD, {mtd->cid, mtd->mn}, mtd);
		ASM(CALL, RTNIDX_(ctx, espidx, rtype), SFP_(thisidx), ESP_(espidx, argc));
	}
}

static void ASM_CHKIDX(CTX ctx, int aidx, int nidx)
{
#ifdef OPCODE_CHKIDX
	long i;
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	for(i = (long)DP(bb)->size - 1; i >= 0; i--) {
		klr_CHKIDX_t *op = (klr_CHKIDX_t*)(DP(bb)->opbuf + i);
		kopcode_t opcode = op->opcode;
		if(opcode == OPCODE_CHKIDXC && op->a == aidx && op->n == nidx) {
			return;
		}
		if(OPCODE_SCALL <= opcode && opcode <= OPCODE_VCALL_) break;
	}
	ASM(CHKIDX, aidx, nidx);
#endif
}

static void ASM_CHKIDXC(CTX ctx, int aidx, int n)
{
#ifdef OPCODE_CHKIDX
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	long i;
	for(i = (long)DP(bb)->size - 1; i >= 0; i--) {
		klr_CHKIDXC_t *op = (klr_CHKIDXC_t*)(DP(bb)->opbuf + i);
		kopcode_t opcode = op->opcode;
		if(opcode == OPCODE_CHKIDXC && op->a == aidx) {
			if(op->n < (kuint_t) n) op->n = n;
			return;
		}
		if(OPCODE_SCALL <= opcode && opcode <= OPCODE_VCALL_) break;
	}
	ASM(CHKIDXC, aidx, n);
#endif
}

static int Tuple_index(CTX ctx, kParam *pa, size_t n, size_t psize)
{
#if defined(K_USING_DBLNDATA_)
	size_t i = 0, ti = 0;
	for(i = 0; i < psize; i++) {
		kparam_t *p = knh_Param_get(pa, i);
		if(i == n) return ti;
		if(IS_Tunbox(p->type)) ti+=2; else ti++;
	}
	return ti;
#else
	return (int)n;
#endif
}

static void CALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTerm *tkMTD = tkNN(stmt, 0);
	kMethod *mtd = (tkMTD)->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	if(!IS_Method(mtd) && C_bcid(cid) == CLASS_Tuple && (tkMTD->mn == MN_get || tkMTD->mn == MN_set)) {
		DBG_ASSERT(Tn_isCONST(stmt, 2));
		kParam *pa = ClassTBL(cid)->cparam;
		int a = Tn_put(ctx, stmt, 1, espidx + 1);
		size_t psize = pa->psize;
		size_t n = tkNN(stmt, 2)->index;
		int ti = Tuple_index(ctx, pa, n, psize);
		kparam_t *p = knh_Param_get(pa, n);
		ksfx_t tx = {OC_(a), ti};
		if(tkMTD->mn == MN_get) {
			ASM_SMOVx(ctx, espidx, p->type, tx);
		}
		else { /* mtd_mn == MN_set */
			int v = Tn_put(ctx, stmt, 3, espidx + 3);
			if(IS_Tunbox(p->type)) {
				ASM(XNMOV, tx, NC_(v));
			}
			else {
				ASM(XMOV, tx, OC_(v));
			}
		}
		return;
	}
	if(!IS_Method(mtd)) {
		size_t i;
		for(i = 1; i < DP(stmt)->size; i++) {
			Tn_asm(ctx, stmt, i, espidx + i + (K_CALLDELTA-1));
		}
		ASM(LDMTD, SFP_(espidx+K_CALLDELTA), _DYNMTD, {TYPE_void, tkMTD->mn}, NULL);
		ASM(CALL, SFP_(espidx), SFP_(espidx+K_CALLDELTA), ESP_(espidx, DP(stmt)->size - 2));
		ASM(PROBE, SFP2_(espidx), _PBOX, 0, 0);
		ASM_SAFEPOINT(ctx, espidx+1);
		return;
	}
	kclass_t mtd_cid = (mtd)->cid;
	kmethodn_t mtd_mn = (mtd)->mn;
	if(mtd_cid == CLASS_Array) {
		kclass_t p1 = C_p1(cid);
		if(mtd_mn == MN_get) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			if(Tn_isCONST(stmt, 2)) {
				kintptr_t n = (kintptr_t)Tn_int(stmt, 2);
				if(n < 0) {
					goto L_USECALL;
				}
				ASM_CHKIDXC(ctx, OC_(a), n);
				if(IS_Tunbox(p1)) {
					ASM(NGETIDXC, NC_(espidx), OC_(a), n);
				}
				else {
					ASM(OGETIDXC, OC_(espidx), OC_(a), n);
				}
			}
			else {
				int an = Tn_put(ctx, stmt, 2, espidx + 2);
				ASM_CHKIDX(ctx, OC_(a), NC_(an));
				if(IS_Tunbox(p1)) {
					ASM(NGETIDX, NC_(espidx), OC_(a), NC_(an));
				}
				else {
					ASM(OGETIDX, OC_(espidx), OC_(a), NC_(an));
				}
			}
			return;
		}
		if(mtd_mn == MN_set) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			int v = Tn_put(ctx, stmt, 3, espidx + 3);
			if(Tn_isCONST(stmt, 2)) {
				kintptr_t n = (kintptr_t)Tn_int(stmt, 2);
				if(n < 0) {
					goto L_USECALL;
				}
				kclass_t p1 = C_p1(cid);
				ASM_CHKIDXC(ctx, OC_(a), n);
				if(IS_Tunbox(p1)) {
					ASM(NSETIDXC, NC_(espidx), OC_(a), n, NC_(v));
				}
				else {
					ASM(OSETIDXC, OC_(espidx), OC_(a), n, OC_(v));
				}
			}
			else {
				int an = Tn_put(ctx, stmt, 2, espidx + 2);
				ASM_CHKIDX(ctx, OC_(a), NC_(an));
				if(IS_Tunbox(p1)) {
					ASM(NSETIDX, NC_(espidx), OC_(a), NC_(an), NC_(v));
				}
				else {
					ASM(OSETIDX, OC_(espidx), OC_(a), NC_(an), OC_(v));
				}
			}
			return;
		}
	}
#if defined(OPCODE_BGETIDX)
	if(mtd_cid == CLASS_Bytes) {
		if(mtd_mn == MN_get) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			if(Tn_isCONST(stmt, 2)) {
				kintptr_t n = (kintptr_t)Tn_int(stmt, 2);
				ASM_CHKIDXC(ctx, OC_(a), n);
				ASM(BGETIDXC, NC_(espidx), OC_(a), n);
			}
			else {
				int an = Tn_put(ctx, stmt, 2, espidx + 2);
				ASM_CHKIDX(ctx, OC_(a), NC_(an));
				ASM(BGETIDX, NC_(espidx), OC_(a), NC_(an));
			}
			return;
		}
		if(mtd_mn == MN_set) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			int v = Tn_put(ctx, stmt, 3, espidx + 3);
			if(Tn_isCONST(stmt, 2)) {
				kintptr_t n = (kintptr_t)Tn_int(stmt, 2);
				if(n < 0) {
					goto L_USECALL;
				}
				ASM_CHKIDXC(ctx, OC_(a), n);
				ASM(BSETIDXC, NC_(espidx), OC_(a), n, NC_(v));
			}
			else {
				int an = Tn_put(ctx, stmt, 2, espidx + 2);
				ASM_CHKIDX(ctx, OC_(a), NC_(an));
				ASM(BSETIDX, NC_(espidx), OC_(a), NC_(an), NC_(v));
			}
			return;
		}
	}
#endif

#ifdef OPCODE_bNUL
	if(mtd_cid == CLASS_Object) {
		if(mtd_mn == MN_isNull) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			ASM(bNUL, NC_(espidx), OC_(a));
			return;
		}
		else if(mtd_mn == MN_isNotNull) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			ASM(bNN, NC_(espidx), OC_(a));
			return;
		}
	}
#endif
	{
		kindex_t deltaidx = knh_Method_indexOfGetterField(mtd);
		if(deltaidx != -1) {
			int b = Tn_put(ctx, stmt, 1, espidx + 1);
			ktype_t type = knh_Param_rtype(DP(mtd)->mp);
			ksfx_t bx = {OC_(b), deltaidx};
			ASM_SMOVx(ctx, espidx, type, bx);
			return;
		}
		deltaidx = knh_Method_indexOfSetterField(mtd);
		if(deltaidx != -1) {
			int b = Tn_put(ctx, stmt, 1, espidx + 1);
			kTerm *tkV = Tn_putTK(ctx, stmt, 2, espidx + 2);
			ASM_XMOV(ctx, OC_(b), deltaidx, tkV, espidx+3);
//			if(reqt != TYPE_void) {
//				ASM_SMOV(ctx, espidx, tkV);
//			}
			return;
		}
	}
	L_USECALL:;
	{
#ifdef OPCODE_FASTCALL0
		ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(DP(mtd)->mp), cid);
		if(DP(stmt)->size == 2 && Method_isFastCall(mtd)) {
			int a = espidx;
			if(!Method_isStatic(mtd)) {
				a = Tn_put(ctx, stmt, 1, espidx + 1);
			}
			ASM(FASTCALL0, RTNIDX_(ctx, espidx, rtype), SFP_(a), RIX_(espidx - a), SFP_(espidx + 2), SP(mtd)->fcall_1);
			return;
		}
		if(DP(stmt)->size == 3 && Method_isStatic(mtd) && Method_isFastCall(mtd)) {
			int a = Tn_put(ctx, stmt, 2, espidx + 2);
			ASM(FASTCALL0, RTNIDX_(ctx, espidx, rtype), SFP_(a - 1), RIX_(espidx - (a - 1)), SFP_(espidx + 2), SP(mtd)->fcall_1);
			return;
		}
#endif
		if(CALLPARAMs_asm(ctx, stmt, 1, espidx, cid, mtd)) {
			ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(DP(mtd)->mp), cid);
			ASM_CALL(ctx, espidx, rtype, mtd, Method_isStatic(mtd), DP(stmt)->size - 2);
		}
	}
}

static void FUNCCALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = (tkNN(stmt, 0))->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	kParam *pa = ClassTBL(cid)->cparam;
	size_t i;
	for(i = 0; i < pa->psize; i++) {
//		kparam_t *p = knh_Param_get(pa, i);
//		ktype_t reqt = ktype_tocid(ctx, p->type, DP(ctx->gma)->this_cid);
		Tn_asm(ctx, stmt, i+2, espidx + i + (K_CALLDELTA+1));
	}
	Tn_asm(ctx, stmt, 1, espidx + K_CALLDELTA);
	if(Stmt_isDYNCALL(stmt)) {
		int a = espidx + K_CALLDELTA;
		ASM(TR, OC_(a), SFP_(a), RIX_(a-a), ClassTBL(cid), _TCHECK);
	}
	ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(DP(mtd)->mp), cid);
	ASM_CALL(ctx, espidx, rtype, mtd, Method_isStatic(mtd), DP(stmt)->size - 2);
}


static kopcode_t OPCODE_imn(kmethodn_t mn, int diff)
{
	switch(mn) {
	case MN_opNEG: return OPCODE_iNEG;
	case MN_opADD: return OPCODE_iADD + diff;
	case MN_opSUB: return OPCODE_iSUB + diff;
	case MN_opMUL: return OPCODE_iMUL + diff;
	case MN_opDIV: return OPCODE_iDIV+ diff;
	case MN_opMOD: return OPCODE_iMOD+ diff;
	case MN_opEQ:  return OPCODE_iEQ+ diff;
	case MN_opNOTEQ: return OPCODE_iNEQ+ diff;
	case MN_opLT:  return OPCODE_iLT+ diff;
	case MN_opLTE: return OPCODE_iLTE+ diff;
	case MN_opGT:  return OPCODE_iGT+ diff;
	case MN_opGTE: return OPCODE_iGTE+ diff;
#ifdef OPCODE_iAND
	case MN_opLAND :  return OPCODE_iAND  + diff;
	case MN_opLOR  :  return OPCODE_iOR   + diff;
	case MN_opLXOR :  return OPCODE_iXOR  + diff;
	case MN_opLSFT:  return OPCODE_iLSFT  + diff;
	case MN_opRSFT:  return OPCODE_iRSFT  + diff;
#endif
	}
	return OPCODE_NOP;
}

static kopcode_t OPCODE_fmn(kmethodn_t mn, int diff)
{
	switch(mn) {
	case MN_opNEG: return OPCODE_fNEG;
	case MN_opADD: return OPCODE_fADD + diff;
	case MN_opSUB: return OPCODE_fSUB + diff;
	case MN_opMUL: return OPCODE_fMUL + diff;
	case MN_opDIV: return OPCODE_fDIV + diff;
	case MN_opEQ:  return OPCODE_fEQ + diff;
	case MN_opNOTEQ: return OPCODE_fNEQ + diff;
	case MN_opLT:  return OPCODE_fLT + diff;
	case MN_opLTE: return OPCODE_fLTE + diff;
	case MN_opGT:  return OPCODE_fGT + diff;
	case MN_opGTE: return OPCODE_fGTE + diff;
	}
	return OPCODE_NOP;
}

static kbool_t OPR_hasCONST(CTX ctx, kStmtExpr *stmt, kmethodn_t *mn, int swap)
{
	int isCONST = (TT_(tmNN(stmt, 2)) == TT_CONST);
	if(swap == 1 && TT_(tmNN(stmt, 1)) == TT_CONST) {
		kmethodn_t newmn = *mn;
		knh_Stmt_swap(ctx, stmt, 1, 2);
		if(*mn == MN_opLT) newmn = MN_opGT;  /* 1 < n ==> n > 1 */
		else if(*mn == MN_opLTE) newmn = MN_opGTE; /* 1 <= n => n >= 1 */
		else if(*mn == MN_opGT) newmn = MN_opLT;
		else if(*mn == MN_opGTE) newmn = MN_opLTE;
		//DBG_P("swap %s ==> %s", MN__(*mn), MN__(newmn));
		*mn = newmn;
		isCONST = 1;
	}
	return isCONST;
}

static void OPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = (tkNN(stmt, 0))->mtd;
	if(IS_NULL(mtd)) {
		CALL_asm(ctx, stmt, espidx); return ;
	}
	kmethodn_t mn = (mtd)->mn;
	kclass_t cid = CLASS_t(SP(tkNN(stmt, 1))->type);
	kopcode_t opcode;
	if(cid == CLASS_Boolean && mn == MN_opNOT) {
		int a = Tn_put(ctx, stmt, 1, espidx + 1);
		ASM(bNOT, NC_(espidx), NC_(a));
		return;
	}
	if(cid == CLASS_Int && ((opcode = OPCODE_imn(mn, 0)) != OPCODE_NOP)) {
		int swap = 1;
		if(mn == MN_opNEG) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			ASM(iNEG, NC_(espidx), NC_(a));
			return;
		}
		if(mn == MN_opSUB || mn == MN_opDIV || mn == MN_opMOD ||
				mn == MN_opLSFT || mn == MN_opRSFT) swap = 0;
		if(OPR_hasCONST(ctx, stmt, &mn, swap)) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			kint_t b = Tn_int(stmt, 2);
			if(b == 0 && (mn == MN_opDIV || mn == MN_opMOD)) {
				b = 1;
				WARN_DividedByZero(ctx);
			}
			opcode = OPCODE_imn(mn, (OPCODE_iADDC - OPCODE_iADD));
			ASMop(iADDC, opcode, NC_(espidx), NC_(a), b);
		}
		else {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			int b = Tn_put(ctx, stmt, 2, espidx + 2);
			ASMop(iADD, opcode, NC_(espidx), NC_(a), NC_(b));
		}
		return;
	} /* CLASS_Int */
	if(cid == CLASS_Float && ((opcode = OPCODE_fmn(mn, 0)) != OPCODE_NOP)) {
		int swap = 1;
		if(mn == MN_opNEG) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			ASM(fNEG, NC_(espidx), NC_(a)); return;
		}
		if(mn == MN_opSUB || mn == MN_opDIV || mn == MN_opMOD) swap = 0;
		if(OPR_hasCONST(ctx, stmt, &mn, swap)) {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			kfloat_t b = Tn_float(stmt, 2);
			if(b == KFLOAT_ZERO && mn == MN_opDIV) {
				b = KFLOAT_ONE;
				WARN_DividedByZero(ctx);
			}
			opcode = OPCODE_fmn(mn, (OPCODE_fADDC - OPCODE_fADD));
			ASMop(fADDC, opcode, NC_(espidx), NC_(a), b);
		}
		else {
			int a = Tn_put(ctx, stmt, 1, espidx + 1);
			int b = Tn_put(ctx, stmt, 2, espidx + 2);
			ASMop(fADD, opcode, NC_(espidx), NC_(a), NC_(b));
		}
		return;
	} /* CLASS_Float */
	CALL_asm(ctx, stmt, espidx);
}


static void EXPR_asm(CTX ctx, kStmtExpr *stmt, int espidx);

static void CALL1_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	Tn_asm(ctx, stmt, 0, espidx);
	if(IS_StmtExpr(DP(stmt)->stmtPOST)) {  /* a++ */
		DP(DP(stmt)->stmtPOST)->espidx = espidx + 1;
		EXPR_asm(ctx, DP(stmt)->stmtPOST, espidx + 1);
	}
}

static void BOX_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kclass_t cid = Tn_cid(stmt, 0);
	Tn_asm(ctx, stmt, 0, espidx);
	if(cid == CLASS_Boolean) {
		ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(cid), _bBOX);
	}
	else {
		ASM_SAFEPOINT(ctx, espidx+1);
		ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(cid), _BOX);
	}
}

static void NEW_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	int thisidx = espidx + K_CALLDELTA;
	kMethod *mtd = (tkNN(stmt, 0))->mtd;
	kclass_t cid = (tkNN(stmt, 1))->cid;
	ASM_SAFEPOINT(ctx, espidx);
	if(DP(stmt)->size == 2 && (mtd)->cid == CLASS_Object && (mtd)->mn == MN_new) {
		ASM(TR, OC_(espidx), SFP_(thisidx), RIX_(espidx-thisidx), ClassTBL(cid), TR_NEW);
	}
	else {
		ASM(TR, OC_(thisidx), SFP_(thisidx), RIX_(thisidx-thisidx), ClassTBL(cid), TR_NEW);
		CALLPARAMs_asm(ctx, stmt, 2, espidx, cid, mtd);
		ASM_CALL(ctx, espidx, cid, mtd, 1, DP(stmt)->size - 2);
	}
}

static void TCAST_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTerm *tkC = tkNN(stmt, 0);
	kTypeMap *tmr = (tkC)->mpr;
	Tn_asm(ctx, stmt, 1, espidx);
	if(IS_TypeMap(tmr)) {
		kclass_t scid = SP(tmr)->scid, tcid = SP(tmr)->tcid;
		if(1/*TypeMap_isFinal(trl)*/) {
			if(scid == CLASS_Int && tcid == CLASS_Float) {
				ASM(fCAST, NC_(espidx), NC_(espidx));
			}
			else if(scid == CLASS_Float && tcid == CLASS_Int) {
				ASM(iCAST, NC_(espidx), NC_(espidx));
			}
//			else if(IS_Tunbox(scid)) {
//				ASM(NCAST, RTNIDX_(ctx, espidx, stmt->type), SFP_(espidx), RIX_(espidx-espidx), SFP_(espidx+1), tmr);
//			}
			else {
				ASM(SCAST, RTNIDX_(ctx, espidx, stmt->type), SFP_(espidx), RIX_(espidx-espidx), SFP_(espidx+1), tmr);
			}
		}
		else {
			ASM(TCAST, RTNIDX_(ctx, espidx, stmt->type), SFP_(espidx), RIX_(espidx-espidx), SFP_(espidx+1), tmr);
		}
	}
	else { // downcast
		klr_Ftr f = (IS_Tunbox(tkC->cid)) ? _TUNBOX : _TCHECK;
		ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL((tkC)->cid), f);
	}
}

static void ALT_asm(CTX ctx, kStmtExpr *stmt, int sfpidx)
{
//	kBasicBlock* label = new_BasicBlockLABEL(ctx);
//	int local = ASML(sfpidx);
//	int i, size = DP(stmt)->size;
//	ktype_t reqc = CLASS_t(reqt);
//	for(i = 0; i < size - 1; i++) {
//		Tn_asm(ctx, stmt, i, reqc, espidx);
//		Tn_ASM_JMPNN(ctx, stmt, i, label);
//	}
//	KNH_ASM_LABEL(ctx, label);
//	KNH_ASM_MOVL(ctx, reqt, sfpidx, SP(stmt)->type, espidx);
	DBG_ABORT("TODO: ALT");
}

static void OR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	int i, size = DP(stmt)->size;
	kBasicBlock*  lbTRUE = new_BasicBlockLABEL(ctx);
	kBasicBlock*  lbFALSE = new_BasicBlockLABEL(ctx);
	for(i = 0; i < size; i++) {
		Tn_JMPIF(ctx, stmt, i, 1/*TRUE*/, lbTRUE, espidx);
	}
	ASM(NSET, NC_(espidx), O_data(KNH_FALSE));
	ASM_JMP(ctx, lbFALSE);
	ASM_LABEL(ctx, lbTRUE);
	ASM(NSET, NC_(espidx), O_data(KNH_TRUE));
	ASM_LABEL(ctx, lbFALSE); // false
}

static void AND_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	int i, size = DP(stmt)->size;
	kBasicBlock*  lbTRUE = new_BasicBlockLABEL(ctx);
	kBasicBlock*  lbFALSE = new_BasicBlockLABEL(ctx);
	for(i = 0; i < size; i++) {
		Tn_JMPIF(ctx, stmt, i, 0/*FALSE*/, lbFALSE, espidx);
	}
	ASM(NSET, NC_(espidx), O_data(KNH_TRUE));
	ASM_JMP(ctx, lbTRUE);
	ASM_LABEL(ctx, lbFALSE); // false
	ASM(NSET, NC_(espidx), O_data(KNH_FALSE));
	ASM_LABEL(ctx, lbTRUE);   // TRUE
}

static void TRI_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kBasicBlock*  lbelse = new_BasicBlockLABEL(ctx);
	kBasicBlock*  lbend  = new_BasicBlockLABEL(ctx);
	//Tn_asm(ctx, stmt, 0, TYPE_Boolean, espidx);
	Tn_JMPIF(ctx, stmt, 0, 0/*FALSE*/, lbelse, espidx);
	Tn_asm(ctx, stmt, 1, espidx);
	ASM_JMP(ctx, lbend);
	/* else */
	ASM_LABEL(ctx, lbelse);
	Tn_asm(ctx, stmt, 2,  espidx);
	ASM_LABEL(ctx, lbend);
}

static void LETEXPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTerm *tkL = tkNN(stmt, 1);
	Tn_asm(ctx, stmt, 2, espidx);
	ktype_t atype = tkL->type;
	DBG_P("LETEXPR TT=%s", TT__(tkL->tt));
	if(TT_(tkL) == TT_FVAR) {
		if(IS_Tunbox(atype)) {
			ASM(NMOV, NC_(Term_index(tkL)), NC_(espidx));
		}
		else {
			ASM(OMOV, OC_(Term_index(tkL)), OC_(espidx));
		}
	}
	else {
		DBG_ASSERT(TT_(tkL) == TT_FIELD);
		ksfx_t ax;
		Term_setsfx(ctx, tkL, &ax);
		if(IS_Tunbox(atype)) {
			ASM(XNMOV, ax, NC_(espidx));
		}
		else {
			ASM(XMOV, ax, OC_(espidx));
		}
	}
}

static KMETHOD Fmethod_empty(CTX ctx, ksfp_t *sfp _RIX) {}

static kMethod* GammaBuilder_getFmt(CTX ctx, kclass_t cid, kmethodn_t mn0)
{
	kmethodn_t mn = mn0;
	kNameSpace *ns = K_GMANS;
	kMethod *mtd = knh_NameSpace_getFmtNULL(ctx, ns, cid, mn);
	if(mtd == NULL) {
		WarningUndefinedFmt(ctx, cid, mn0);
		mtd = new_Method(ctx, 0, cid, mn0, Fmethod_empty);
		KNH_SETv(ctx, DP(mtd)->mp, KNH_TNULL(Param));
		knh_NameSpace_addFmt(ctx, ns, mtd);
	}
	return mtd;
}

static void W1_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	int isCWB = 0;
	size_t thisidx = espidx + K_CALLDELTA;
	kMethod *mtdf  = tkNN(stmt, 0)->mtd;
	DBG_ASSERT(DP(stmt)->size == 3);
	if(TT_(tmNN(stmt, 1)) == TT_ASIS) {
		isCWB = 1;
		ASM(TR, OC_(thisidx), SFP_(thisidx), RIX_(thisidx-thisidx), ClassTBL(CLASS_OutputStream), _CWB);
		KNH_SETv(ctx, tmNN(stmt, 1), kTermoTYPED(ctx, tkNN(stmt, 1), TT_FVAR, TYPE_OutputStream, thisidx));
	}
	else {
		DBG_ASSERT(TT_(tkNN(stmt, 1)) == TT_FVAR);
		DBG_ASSERT(Tn_type(stmt, 1) == TYPE_OutputStream);
		thisidx = tkNN(stmt, 1)->index;
	}
	if(IS_Method(mtdf)) {
		Tn_asm(ctx, stmt, 2, thisidx + 1);
		ASM(SCALL, -1, SFP_(thisidx), ESP_((thisidx-K_CALLDELTA), 1), mtdf);
	}
	if(isCWB) {
		ASM(TR, OC_(espidx), SFP_(thisidx), RIX_(espidx-thisidx), ClassTBL(CLASS_String), _TOSTR);
		ASM_SAFEPOINT(ctx, espidx+1);
	}
}

static void FMTCALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	int isCWB = 0;
	size_t i, thisidx = espidx + (DP(stmt)->size - 2) + K_CALLDELTA;
	for(i = 2; i < DP(stmt)->size; i++) {
		Tn_asm(ctx, stmt, i, espidx + i - 2);
	}
	if(TT_(tmNN(stmt, 1)) == TT_ASIS) {
		isCWB = 1;
		ASM(TR, OC_(thisidx), SFP_(thisidx), RIX_(thisidx-thisidx), ClassTBL(CLASS_OutputStream), _CWB);
		kTermoTYPED(ctx, tkNN(stmt, 1), TT_FVAR, TYPE_OutputStream, thisidx);
	}
	else {
		DBG_ASSERT(TT_(tkNN(stmt, 1)) == TT_FVAR);
		DBG_ASSERT(Tn_type(stmt, 1) == TYPE_OutputStream);
		thisidx = tkNN(stmt, 1)->index;
	}
	{
		kStmtExpr *stmtW = stmtNN(stmt, 0);
		while(stmtW != NULL) {
			if(STT_(stmtW) == STT_W1) {
				DBG_ASSERT(tkNN(stmt, 1) == tkNN(stmtW, 1));
				if(TT_(tkNN(stmtW, 2)) == TT_NUM) {
					kTerm *tkIDX = tkNN(stmtW, 2);
					tkIDX->index += espidx;
					TT_(tkIDX) = TT_FVAR;
				}
				W1_asm(ctx, stmtW, thisidx - K_CALLDELTA);
			}
			stmtW = DP(stmtW)->nextNULL;
		}
	}
	if(isCWB) {
		ASM(TR, OC_(espidx), SFP_(thisidx), RIX_(espidx-thisidx), ClassTBL(CLASS_String), _TOSTR);
	}
}

static void SEND_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	size_t i, thisidx = espidx + K_CALLDELTA;
	int isCWB = 0;
	if(TT_(tmNN(stmt, 1)) == TT_ASIS) {
		isCWB = 1;
		ASM(TR, OC_(thisidx), SFP_(thisidx), RIX_(thisidx-thisidx), ClassTBL(CLASS_OutputStream), _CWB);
		KNH_SETv(ctx, tmNN(stmt, 1), kTermoTYPED(ctx, tkNN(stmt, 1), TT_FVAR, TYPE_OutputStream, thisidx));
	}
	else {
		Tn_asm(ctx, stmt, 1, thisidx);
	}
	for(i = 2; i < DP(stmt)->size; i++) {
		if(STT_(stmtNN(stmt, i)) == STT_W1) {
			kStmtExpr *stmtIN = stmtNN(stmt, i);
			DBG_ASSERT(TT_(tkNN(stmtIN, 1)) == TT_ASIS);
			KNH_SETv(ctx, tkNN(stmtIN, 1), tkNN(stmt, 1));
			W1_asm(ctx, stmtIN, espidx + 1);
		}
		else {
			kMethod *mtd = NULL;
			kclass_t cid = Tn_cid(stmt, i);
			Tn_asm(ctx, stmt, i, thisidx + 1);
			if(cid == CLASS_String) {
				mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_OutputStream, MN_send);
				DBG_ASSERT(mtd != NULL);
			}
			else {
				mtd = GammaBuilder_getFmt(ctx, cid, MN__s);
			}
			ASM(SCALL, -1, SFP_(thisidx), ESP_((thisidx-K_CALLDELTA), 1), mtd);
		}
	}
	if(isCWB) {
		ASM(TR, OC_(espidx), SFP_(thisidx), RIX_(espidx-thisidx), ClassTBL(CLASS_String), _TOSTR);
	}
}

/* ------------------------------------------------------------------------ */

#define STT_LETEXPR  STT_LET

#define CASE_ASM(XX, ...) case STT_##XX : { \
		XX##_asm(ctx, stmt, ## __VA_ARGS__); \
		break;\
	}\

static void EXPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	switch(STT_(stmt)) {
	CASE_ASM(LETEXPR, espidx);
	CASE_ASM(FUNCCALL, espidx);
	CASE_ASM(CALL, espidx);
	CASE_ASM(CALL1, espidx);
	CASE_ASM(BOX, espidx);
	CASE_ASM(OPR, espidx);
	CASE_ASM(NEW, espidx);
	CASE_ASM(TCAST, espidx);
	CASE_ASM(AND, espidx);
	CASE_ASM(OR, espidx);
	CASE_ASM(ALT, espidx);
	CASE_ASM(TRI, espidx);
	CASE_ASM(SEND, espidx);
	CASE_ASM(W1, espidx);
	CASE_ASM(FMTCALL, espidx);
	default:
		DBG_ABORT("unknown stt=%s", TT__(STT_(stmt)));
	}
}


static void Tn_asm(CTX ctx, kStmtExpr *stmt, size_t n, int espidx)
{
	if(IS_Term(tkNN(stmt, n))) {
		ASM_SMOV(ctx, espidx, tkNN(stmt, n));
	}
	else {
		EXPR_asm(ctx, stmtNN(stmt, n), espidx);
	}
	if(IS_Term(tkNN(stmt, n))) {
		kTerm *tk = tkNN(stmt, n);
		if(TT_(tk) != TT_FVAR) {
			kTermoTYPED(ctx, tk, TT_FVAR, tk->type, espidx);
		}
	}
	else {
		kTerm *tk = new_TermTYPED(ctx, TT_FVAR, Tn_type(stmt, n), espidx);
		KNH_SETv(ctx, tkNN(stmt, n), tk);
	}
}

/* ------------------------------------------------------------------------ */
/* [LABEL]  */

static void GammaBuilder_pushLABEL(CTX ctx, kStmtExpr *stmt, kBasicBlock *lbC, kBasicBlock *lbB)
{
	kObject *tkL = NULL;
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		tkL = knh_DictMap_getNULL(ctx, DP(stmt)->metaDictCaseMap, S_tobytes(TS_ATlabel));
	}
	if(tkL == NULL) {
		tkL = KNH_NULVAL(CLASS_Tdynamic);
	}
	knh_Array_add(ctx, DP(ctx->gma)->lstacks, tkL);
	knh_Array_add(ctx, DP(ctx->gma)->lstacks, lbC);
	knh_Array_add(ctx, DP(ctx->gma)->lstacks, lbB);
	knh_Array_add(ctx, DP(ctx->gma)->lstacks, KNH_NULL);
}

static void GammaBuilder_popLABEL(CTX ctx)
{
	kArray *a = DP(ctx->gma)->lstacks;
	DBG_ASSERT(knh_Array_size(a) - 4 >= 0);
	knh_Array_clear(ctx, a, knh_Array_size(a) - 4);
}

/* ------------------------------------------------------------------------ */
/* [IF, WHILE, DO, FOR, FOREACH]  */

static inline kTerm *Tn_it(kStmtExpr *stmt, size_t n)
{
	DBG_ASSERT(n < DP(stmt)->size);
	return tkNN(stmt, n);
}

static inline void Tn_asmBLOCK(CTX ctx, kStmtExpr *stmt, size_t n)
{
	DBG_ASSERT(IS_StmtExpr(stmtNN(stmt, n)));
	BLOCK_asm(ctx, stmtNN(stmt, n));
}

static void ASM_PMOV(CTX ctx, int isUNBOX, int a, int b)
{
	kBasicBlock *bb = DP(ctx->gma)->bbNC;
	if(DP(bb)->size > 0) {
		kopl_t *opP = DP(bb)->opbuf + (DP(bb)->size - 1);
		klr_TR_t *opTR = (klr_TR_t*)opP;
		int defidx = opTR->a;
		if(isUNBOX) {
			int r0 = NC_(a), r1 = NC_(b);
			if(r1 == defidx) {
				kopcode_t opcode = opP->opcode;
				DBG_P("r0=%d, r1=%d, def=%d", r0, r1, defidx);
				if((OPCODE_bNOT <= opcode && opcode <= OPCODE_fGTEC)
				  || (OPCODE_iCAST <= opcode && opcode <= OPCODE_fCAST)
				  || (OPCODE_BGETIDX <= opcode && opcode <= OPCODE_NSETIDXC)
				  || (OPCODE_NSET == opcode)) {
					opTR->a = r0;
					return ;
				}
			}
			ASM(NMOV, r0, r1);
		}
		else {
			int r0 = OC_(a), r1 = OC_(b);
			if(r1 == defidx) {
				kopcode_t opcode = opP->opcode;
				DBG_P("r0=%d, r1=%d, def=%d", r0, r1, defidx);
				if(opcode == OPCODE_TR) {
					opTR->a = r0;
					opTR->rix = (r0 - opTR->b) / 2;
					return ;
				}
				if((OPCODE_OGETIDX <= opcode && opcode <= OPCODE_OSETIDXC)) {
					opTR->a = r0;
					return ;
				}
			}
			ASM(OMOV, r0, r1);
		}
	}
	else {
		if(isUNBOX) {
			ASM(NMOV, NC_(a), NC_(b));
		}
		else {
			ASM(OMOV, OC_(a), OC_(b));
		}
	}
}

static void LET_asm(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkL = tkNN(stmt, 1);
	kTerm *tkV = tkNN(stmt, 2);
	ktype_t atype = tkL->type;
	if(IS_Term(tkV)) {
		ASM_MOV(ctx, tkL, tkV, DP(stmt)->espidx);
	}
	else {
		Tn_asm(ctx, stmt, 2, DP(stmt)->espidx);
		if(TT_(tkL) == TT_FVAR) {
			ASM_PMOV(ctx, IS_Tunbox(atype), Term_index(tkL), DP(stmt)->espidx);
		}
		else {
			DBG_ASSERT(TT_(tkL) == TT_FIELD);
			ktype_t atype = tkL->type;
			ksfx_t ax;
			Term_setsfx(ctx, tkL, &ax);
			if(IS_Tunbox(atype)) {
				ASM(XNMOV, ax, NC_(DP(stmt)->espidx));
			}
			else {
				ASM(XMOV, ax, OC_(DP(stmt)->espidx));
			}
		}
	}
}

static void IF_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock*  lbELSE = new_BasicBlockLABEL(ctx);
	kBasicBlock*  lbEND  = new_BasicBlockLABEL(ctx);
	/* if */
	lbELSE = Tn_JMPIF(ctx, stmt, 0, 0/*FALSE*/, lbELSE, DP(stmt)->espidx);
	/* then */
	Tn_asmBLOCK(ctx, stmt, 1);
	ASM_JMP(ctx, lbEND);
	/* else */
	ASM_LABEL(ctx, lbELSE);
	Tn_asmBLOCK(ctx, stmt, 2);
	/* endif */
	ASM_LABEL(ctx, lbEND);
}

static void SWITCH_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmtCASE;
	kTerm *tkIT = Tn_it(stmt, 2);
	kBasicBlock* lbCONTINUE = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbBREAK = new_BasicBlockLABEL(ctx);
	kBasicBlock *lbNEXT = NULL;
	GammaBuilder_pushLABEL(ctx, stmt, lbCONTINUE, lbBREAK);
	ASM_LABEL(ctx, lbCONTINUE);
	//switch(it)
	Tn_asm(ctx, stmt, 0, Term_index(tkIT));
	stmtCASE = stmtNN(stmt, 1);
	while(stmtCASE != NULL) {
		// case 'a' :
		if(STT_(stmtCASE) == STT_CASE && !Tn_isASIS(stmtCASE, 0)) {
			kBasicBlock *lbEND = new_BasicBlockLABEL(ctx);
			//@@DP(stmt)->espidx = DP(stmtCASE)->espidx + DP(ctx->gma)->ebpidx;
			Tn_JMPIF(ctx, stmtCASE, 0, 0/*FALSE*/, lbEND, DP(stmt)->espidx);
			if(lbNEXT != NULL) {
				ASM_LABEL(ctx, lbNEXT); lbNEXT = NULL;
			}
			Tn_asmBLOCK(ctx, stmtCASE, 1);
			lbNEXT = new_BasicBlockLABEL(ctx);
			ASM_JMP(ctx, lbNEXT);
			ASM_LABEL(ctx, lbEND);
		}
		stmtCASE = DP(stmtCASE)->nextNULL;
	}
	if(lbNEXT != NULL) {
		ASM_LABEL(ctx, lbNEXT); lbNEXT = NULL;
	}
	stmtCASE = stmtNN(stmt, 1);
	while(stmtCASE !=NULL) {
		if(STT_(stmtCASE) == STT_CASE && Tn_isASIS(stmtCASE, 0)) {
			Tn_asmBLOCK(ctx, stmtCASE, 1);
		}
		stmtCASE = DP(stmtCASE)->nextNULL;
	}
	ASM_LABEL(ctx, lbBREAK);
	GammaBuilder_popLABEL(ctx);
}

static void ASM_JUMPLABEL(CTX ctx, kStmtExpr *stmt, int delta)
{
	size_t s = knh_Array_size(DP(ctx->gma)->lstacks);
	if(s < 4) {
		kStmtExproERR(ctx, stmt, ERROR_OnlyTopLevel(ctx, Stmt__(stmt)));
	}
	else {
		kTerm *tkL = NULL;
		kBasicBlock *lbBLOCK = NULL;
		if(DP(stmt)->size == 1) {
			tkL = tkNN(stmt, 0);
			if(TT_(tkL) == TT_ASIS) tkL = NULL;
		}
		if(tkL != NULL) {
			int i;
			kbytes_t lname = S_tobytes((tkL)->text);
			for(i = s - 4; i >= 0; i -= 4) {
				kTerm *tkSTACK = DP(ctx->gma)->lstacks->terms[i];
				if(IS_NOTNULL(tkSTACK) && S_equals((tkSTACK)->text, lname)) {
					lbBLOCK = GammaBuilderLabel(ctx,  i + delta);
					goto L_JUMP;
				}
			}
			ErrorUndefinedLabel(ctx, tkL);
			return;
		}
		lbBLOCK = GammaBuilderLabel(ctx,  s - 4 + delta);
		L_JUMP:;
		ASM_JMP(ctx, lbBLOCK);
	}
}

static void CONTINUE_asm(CTX ctx, kStmtExpr *stmt)
{
	ASM_JUMPLABEL(ctx, stmt, 1);
}

static void BREAK_asm(CTX ctx, kStmtExpr *stmt)
{
	ASM_JUMPLABEL(ctx, stmt, 2);
}

static void WHILE_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock* lbCONTINUE = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbBREAK = new_BasicBlockLABEL(ctx);
	GammaBuilder_pushLABEL(ctx, stmt, lbCONTINUE, lbBREAK);
	ASM_LABEL(ctx, lbCONTINUE);
	ASM_SAFEPOINT(ctx, DP(stmt)->espidx);
	if(!Tn_isTRUE(stmt, 0)) {
		Tn_JMPIF(ctx, stmt, 0, 0/*FALSE*/, lbBREAK, DP(stmt)->espidx);
		//ASM_CHECK_INFINITE_LOOP(ctx, stmt);
	}
	Tn_asmBLOCK(ctx, stmt, 1);
	ASM_JMP(ctx, lbCONTINUE);
	ASM_LABEL(ctx, lbBREAK);
	GammaBuilder_popLABEL(ctx);
}

static void DO_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock* lbCONTINUE = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbBREAK = new_BasicBlockLABEL(ctx);
	GammaBuilder_pushLABEL(ctx, stmt, lbCONTINUE, lbBREAK);
	ASM_LABEL(ctx, lbCONTINUE);
	ASM_SAFEPOINT(ctx, DP(stmt)->espidx);
	Tn_asmBLOCK(ctx, stmt, 0);
	Tn_JMPIF(ctx, stmt, 1, 0/*FALSE*/, lbBREAK, DP(stmt)->espidx);
	ASM_JMP(ctx, lbCONTINUE);
	ASM_LABEL(ctx, lbBREAK);
	GammaBuilder_popLABEL(ctx);
}

static void FOR_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock* lbCONTINUE = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbBREAK = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbREDO = new_BasicBlockLABEL(ctx);
	GammaBuilder_pushLABEL(ctx, stmt, lbCONTINUE, lbBREAK);
	/* i = 1 part */
	Tn_asmBLOCK(ctx, stmt, 0);
	ASM_JMP(ctx, lbREDO);
	/* i++ part */
	ASM_LABEL(ctx, lbCONTINUE); /* CONTINUE */
	ASM_SAFEPOINT(ctx, DP(stmt)->espidx);
	Tn_asmBLOCK(ctx, stmt, 2);
	/* i < 10 part */
	ASM_LABEL(ctx, lbREDO);
	if(!Tn_isTRUE(stmt, 1)) {
		Tn_JMPIF(ctx, stmt, 1, 0/*FALSE*/, lbBREAK, DP(stmt)->espidx);
	}
	Tn_asmBLOCK(ctx, stmt, 3);
	ASM_JMP(ctx, lbCONTINUE);
	ASM_LABEL(ctx, lbBREAK);
	GammaBuilder_popLABEL(ctx);
}

/* ------------------------------------------------------------------------ */

static void FOREACH_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock* lbC = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbB = new_BasicBlockLABEL(ctx);
	GammaBuilder_pushLABEL(ctx, stmt, lbC, lbB);
	{
		kTerm *tkN = tkNN(stmt, 0);
		int varidx = Term_index(tkN);
		int itridx = Term_index(tkNN(stmt, 2));
		Tn_asm(ctx, stmt, 1, itridx);
		ASM_LABEL(ctx, lbC);
		ASM_SAFEPOINT(ctx, DP(stmt)->espidx);
		ASMbranch(NEXT, lbB, RTNIDX_(ctx, varidx, (tkN)->type), SFP_(itridx), RIX_(varidx - itridx), SFP_(_ESPIDX));
	}
	Tn_asmBLOCK(ctx, stmt, 3);
	ASM_JMP(ctx, lbC);
	/* end */
	ASM_LABEL(ctx, lbB);
	GammaBuilder_popLABEL(ctx);
}

/* ------------------------------------------------------------------------ */
/* [TRY] */

#define GammaBuilder_inTry(ctx)  IS_StmtExpr(DP(ctx->gma)->finallyStmt)

static void GammaBuilder_setFINALLY(CTX ctx, kStmtExpr *stmt)
{
	if(IS_NOTNULL(stmt)) {
		if(IS_NOTNULL(DP(ctx->gma)->finallyStmt)) {
			ErrorMisplaced(ctx);
			KNH_HINT(ctx, "try"); // not nested try
			return;
		}
		KNH_SETv(ctx, DP(ctx->gma)->finallyStmt, stmt);
	}
	else { /* stmt == null */
		KNH_SETv(ctx, DP(ctx->gma)->finallyStmt, stmt);
	}
}

static void ASM_FINALLY(CTX ctx)
{
	if(IS_NOTNULL(DP(ctx->gma)->finallyStmt)) {
		BLOCK_asm(ctx, DP(ctx->gma)->finallyStmt);
	}
}

static void TRY_asm(CTX ctx, kStmtExpr *stmt)
{
	kBasicBlock*  lbCATCH   = new_BasicBlockLABEL(ctx);
	kBasicBlock*  lbFINALLY = new_BasicBlockLABEL(ctx);
	kTerm *tkIT = Tn_it(stmt, 3/*HDR*/);
	kStmtExpr *stmtCATCH = stmtNN(stmt, 1);
	GammaBuilder_setFINALLY(ctx, stmtNN(stmt, 2/*finally*/));
	/* try { */
	ASMbranch(TRY, lbCATCH, OC_((tkIT)->index));
	Tn_asmBLOCK(ctx, stmt, 0/*try*/);
	ASM_JMP(ctx, lbFINALLY);
	GammaBuilder_setFINALLY(ctx, (kStmtExpr*)KNH_NULL); // InTry
	/* catch */
	ASM_LABEL(ctx, lbCATCH);
	DBG_P("stmtCATCH=%s", CLASS__(O_cid(stmtCATCH)));
	while(stmtCATCH != NULL) {
		DBG_ASSERT(IS_StmtExpr(stmtCATCH));
		if(SP(stmtCATCH)->stt == STT_CATCH) {
			kString *emsg = tkNN(stmtCATCH, 0)->text;
			kTerm *tkN = tkNN(stmtCATCH, 1);
			DBG_ASSERT(IS_String(emsg));
			DBG_ASSERT(TT_(tkN) == TT_FVAR || TT_(tkN) == TT_LVAR);
			if(!knh_isDefinedEvent(ctx, S_tobytes(emsg))) {
				WARN_Undefined(ctx, "fault", CLASS_Exception, tkNN(stmtCATCH, 0));
			}
			lbCATCH = new_BasicBlockLABEL(ctx);
			ASMbranch(CATCH, lbCATCH, OC_((tkN)->index), knh_geteid(ctx, S_tobytes(emsg)));
			Tn_asmBLOCK(ctx, stmtCATCH, 2);
			ASM_JMP(ctx, lbFINALLY);  /* GOTO FINALLY */
			ASM_LABEL(ctx, lbCATCH); /* _CATCH_NEXT_ */
		}
		stmtCATCH = DP(stmtCATCH)->nextNULL;
	}
	ASM_LABEL(ctx, lbFINALLY); /* FINALLY */
	Tn_asmBLOCK(ctx, stmt, 2/*finally*/);
	ASM(THROW, SFP_(((tkIT)->index)-1));
}

static void ASSURE_asm(CTX ctx, kStmtExpr *stmt)
{
	int index = Term_index(tkNN(stmt, 2)); // it
	Tn_asm(ctx, stmt, 0, index);
	ASM(CHKIN, OC_(index), ClassTBL(CLASS_Assurance)->cdef->checkin);
	Tn_asmBLOCK(ctx, stmt, 1);
	ASM(CHKOUT, OC_(index), ClassTBL(CLASS_Assurance)->cdef->checkout);
}

static void THROW_asm(CTX ctx, kStmtExpr *stmt)
{
	int start = 0, espidx = DP(stmt)->espidx;
	if(GammaBuilder_inTry(ctx)) {
		start = espidx;
	}
	Tn_asm(ctx, stmt, 0, espidx);
	ASM(TR, OC_(espidx), SFP_(espidx), RIX_(espidx-espidx), ClassTBL(CLASS_Exception), _ERR);
	ASM(THROW, SFP_(start));
}

static void RETURN_asm(CTX ctx, kStmtExpr *stmt)
{
	ASM_FINALLY(ctx);
	size_t size = DP(stmt)->size;
	if(size == 1) {
		Tn_asm(ctx, stmt, 0, DP(stmt)->espidx);
		ASM_PMOV(ctx, IS_Tunbox(Tn_type(stmt, 0)), K_RTNIDX, DP(stmt)->espidx);
	}
	if(IS_StmtExpr(DP(stmt)->stmtPOST)) {
		DP(DP(stmt)->stmtPOST)->espidx = DP(stmt)->espidx + 1;
		EXPR_asm(ctx, DP(stmt)->stmtPOST, DP(stmt)->espidx + 1);
	}
	if(!Stmt_isImplicit(stmt)) {
		ASM_RET(ctx, stmt);
	}
}

static void YIELD_asm(CTX ctx, kStmtExpr *stmt)
{
	KNH_TODO("yield");
}

static void ERR_asm(CTX ctx, kStmtExpr *stmt)
{
	int start = 0, espidx = DP(stmt)->espidx;
	kTerm *tkERR = tkNN(stmt, 0);
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	DBG_ASSERT(DP(stmt)->size > 0);
	DBG_ASSERT(TT_(tkERR) == TT_ERR);
	if(GammaBuilder_inTry(ctx)) start = espidx;
	DBG_ASSERT(IS_String((tkERR)->text));
	knh_write_ascii(ctx, cwb->w, "Script!!: ");
	knh_write(ctx, cwb->w, S_tobytes(tkERR->text));
	ASM(ERROR, SFP_(start), CWB_newString(ctx, cwb, SPOL_POOLNEVER));
	if(DP(stmt)->nextNULL != NULL) {
		KNH_FINALv(ctx, DP(stmt)->nextNULL);
		DP(stmt)->nextNULL = NULL;
	}
}

/* ------------------------------------------------------------------------ */
/* [PRINT] */

#define KFLAG_PF_STDERR      1
#define KFLAG_PF_BOL         (1<<1)
#define KFLAG_PF_TIME        (1<<2)
#define KFLAG_PF_NAME        (1<<3)
#define KFLAG_PF_EOL         (1<<4)
#define KFLAG_PF_NCOMMA      (1<<5)
#define KFLAG_PF_LINE        (1<<6)
#define KFLAG_PF_BREAK       (1<<7)


static kflag_t PRINT_flag(CTX ctx, kStmtExpr *o)
{
	kflag_t flag = 0;
	if(IS_Map(DP(o)->metaDictCaseMap)) {
		Object *v = knh_DictMap_getNULL(ctx,  DP(o)->metaDictCaseMap, STEXT("Time"));
		if(v != NULL) {
			flag |= KFLAG_PF_TIME;
		}
	}
	return flag;
}

static void _PRINTh(CTX ctx, ksfp_t *sfp, kOutputStream *w, struct klr_P_t *op)
{
	kflag_t flag = (kflag_t)op->flag;
	knh_write_ascii(ctx, w, TERM_BNOTE(ctx, LOG_NOTICE));
	if(FLAG_is(flag, KFLAG_PF_BOL)) {
		if(FLAG_is(flag, KFLAG_PF_LINE)) {
			kline_t uline = op->line;
			kMethod *mtd = sfp[-1].mtdNC;
			DBG_ASSERT(IS_Method(mtd));
			ULINE_setURI(uline, DP(mtd)->uri);
			knh_write_mline(ctx, w, mtd->mn, uline);
		}
		if(FLAG_is(flag, KFLAG_PF_TIME)) {
			knh_write_now(ctx, w);
			knh_putc(ctx, w, ' ');
		}
	}
	else if(!FLAG_is(flag, KFLAG_PF_NCOMMA)) {
		knh_putc(ctx, w, ',');
		knh_putc(ctx, w, ' ');
	}
	if(IS_bString(op->msg)) {
		if((op->msg)->str.len > 0) {
			knh_write_utf8(ctx, w, S_tobytes(op->msg), !String_isASCII(op->msg));
		}
	}
	if(FLAG_is(flag, KFLAG_PF_NAME)) {
		knh_putc(ctx, w, '=');
	}
}

static void _PRINTln(CTX ctx, ksfp_t *sfp, kOutputStream *w, struct klr_P_t *op)
{
	kflag_t flag = (kflag_t)op->flag;
	if(FLAG_is(flag, KFLAG_PF_EOL)) {
		if(FLAG_is(flag, KFLAG_PF_BREAK)) {
			char buf[80];
			knh_write_dots(ctx, w);
			knh_flush(ctx, w);
			char *ret = fgets(buf, sizeof(buf), stdin);
			(void)ret;
		}
		knh_write_ascii(ctx, w, TERM_ENOTE(ctx, LOG_NOTICE));
		knh_write_EOL(ctx, w);
	}
}

static void _PRINT(CTX ctx, ksfp_t *sfp, struct klr_P_t *op)
{
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, op);
	knh_write_Object(ctx, w, sfp[op->n].o, FMT_data);
	_PRINTln(ctx, sfp, w, op);
}

static void _PRINTm(CTX ctx, ksfp_t *sfp, struct klr_P_t *op)
{
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, op);
	if(FLAG_is(((kflag_t)op->flag), KFLAG_PF_EOL)) {
		knh_write_ascii(ctx, w, TERM_ENOTE(ctx, LOG_NOTICE));
		knh_write_EOL(ctx, w);
	}
}

static void _PRINTi(CTX ctx, ksfp_t *sfp, struct klr_P_t *op)
{
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, op);
	knh_write_ifmt(ctx, w, KINT_FMT, sfp[op->n].ivalue);
	_PRINTln(ctx, sfp, w, op);
}

static void _PRINTf(CTX ctx, ksfp_t *sfp, struct klr_P_t *op)
{
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, op);
	knh_write_ffmt(ctx, w, KFLOAT_FMT, sfp[op->n].fvalue);
	_PRINTln(ctx, sfp, w, op);
}

static void _PRINTb(CTX ctx, ksfp_t *sfp, struct klr_P_t *op)
{
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, op);
	knh_write_bool(ctx, w, sfp[op->n].bvalue);
	_PRINTln(ctx, sfp, w, op);
}

void knh_PRINT(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kObject *o)
{
	struct klr_P_t op = {TADDR, OPCODE_P, ASMLINE, NULL, flag, msg, 0};
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, &op);
	knh_write_Object(ctx, w, o, FMT_data);
	_PRINTln(ctx, sfp, w, &op);
}

void knh_PRINTi(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kint_t n)
{
	struct klr_P_t op = {TADDR, OPCODE_P, ASMLINE, NULL, flag, msg, 0};
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, &op);
	knh_write_ifmt(ctx, w, KINT_FMT, n);
	_PRINTln(ctx, sfp, w, &op);
}

void knh_PRINTf(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kfloat_t f)
{
	struct klr_P_t op = {TADDR, OPCODE_P, ASMLINE, NULL, flag, msg, 0};
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, &op);
	knh_write_ffmt(ctx, w, KFLOAT_FMT, f);
	_PRINTln(ctx, sfp, w, &op);
}

void knh_PRINTb(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kbool_t b)
{
	struct klr_P_t op = {TADDR, OPCODE_P, ASMLINE, NULL, flag, msg, 0};
	kOutputStream *w = KNH_STDOUT;
	_PRINTh(ctx, sfp, w, &op);
	knh_write_bool(ctx, w, b);
	_PRINTln(ctx, sfp, w, &op);
}

static void PRINT_asm(CTX ctx, kStmtExpr *stmt)
{
	kflag_t flag = PRINT_flag(ctx, stmt) | KFLAG_PF_BOL | KFLAG_PF_LINE;
	long i, espidx = DP(stmt)->espidx;
	for(i = 0; i < DP(stmt)->size; i++) {
		kTerm *tkn = tkNN(stmt, i);
		if(TT_(tkn) != TT_CONST || !IS_String((tkn)->data)) {
			Tn_asm(ctx, stmt, i, espidx + i);
		}
	}
	for(i = 0; i < DP(stmt)->size; i++) {
		kflag_t mask = 0;
		kString *msg = (kString*)KNH_NULL;
		L_REDO:;
		kTerm *tkn = tkNN(stmt, i);
		if(i == (long)DP(stmt)->size - 1) {
			mask |= KFLAG_PF_EOL;
			if(Stmt_isBreakPoint(stmt)) {
				mask |= KFLAG_PF_BREAK;
			}
		}
		if(TT_(tkn) == TT_CONST && IS_String((tkn)->data)) {
			if(Term_isPNAME(tkn)) { /* name= */
				msg = (tkn)->text;
				mask |= KFLAG_PF_NAME; i++;
				goto L_REDO;
			}
			DBG_ASSERT(stmt->uline == ctx->gma->uline);
			ASM(P, _PRINTm, flag | mask, (tkn)->text, 0);
			flag = KFLAG_PF_NCOMMA;
		}
		else {
			kclass_t cid = Tn_cid(stmt, i);
			if(IS_Tint(cid)) {
				ASM(P, _PRINTi, flag | mask, msg, espidx+i);
			}
			else if(IS_Tfloat(cid)) {
				ASM(P, _PRINTf, flag | mask, msg, espidx+i);
			}
			else if(cid == CLASS_Boolean) {
				ASM(P, _PRINTb, flag | mask, msg, espidx+i);
			}
			else {
				ASM(P, _PRINT, flag | mask, msg, espidx+i);
			}
			flag=0;
		}
	}
}

static void ASSERT_asm(CTX ctx, kStmtExpr *stmt)
{
	int espidx = DP(stmt)->espidx;
	kBasicBlock* lbskip = new_BasicBlockLABEL(ctx);
	/* if */
	Tn_JMPIF(ctx, stmt, 0, 1, lbskip, DP(stmt)->espidx);
	/*then*/
	ASM(ASSERT, SFP_(espidx), stmt->uline);
	ASM_LABEL(ctx, lbskip);
}

/* ------------------------------------------------------------------------ */

static void BLOCK_asm(CTX ctx, kStmtExpr *stmtH)
{
	kStmtExpr *stmt = stmtH;
	while(stmt != NULL) {
		ctx->gma->uline = stmt->uline;
		switch(STT_(stmt)) {
		case STT_REGISTER:
		{
			size_t i;
			for(i = 0; i < DP(stmt)->size; i++) {
				kStmtExpr *stmtLET = stmtNN(stmt, i);
				if(STT_(stmtLET) == STT_LET) {
					DP(stmtLET)->espidx = DP(stmt)->espidx;
					LET_asm(ctx, stmtLET);
				}
			}
			break;
		}
		case STT_BLOCK :
		{
			BLOCK_asm(ctx, stmtNN(stmt, 0));
			break;
		}
		CASE_ASM(LET);
		CASE_ASM(IF);
		CASE_ASM(SWITCH);
		CASE_ASM(WHILE);
		CASE_ASM(DO);
		CASE_ASM(FOR);
		CASE_ASM(FOREACH);
		CASE_ASM(BREAK);
		CASE_ASM(CONTINUE);
		CASE_ASM(TRY);
		CASE_ASM(THROW);
		CASE_ASM(RETURN);
		CASE_ASM(YIELD);
		CASE_ASM(PRINT);
		CASE_ASM(ASSURE);
		CASE_ASM(ASSERT);
		CASE_ASM(ERR);
		case STT_DECL: case STT_DONE: break;
		default:
			EXPR_asm(ctx, stmt, DP(stmt)->espidx);
		}
		stmt = DP(stmt)->nextNULL;
	}
}

/* ------------------------------------------------------------------------ */

static void _THCODE(CTX ctx, kopl_t *pc, void **codeaddr)
{
#ifdef K_USING_THCODE_
	while(1) {
		DBG_ASSERT_OPCODE(pc->opcode);
		pc->codeaddr = codeaddr[pc->opcode];
		if(pc->opcode == OPCODE_RET) break;
		pc++;
	}
#endif
}

void GammaBuilder_shiftLocalScope(CTX ctx)
{
	knh_gint_t shift = DP(ctx->gma)->fvarsize;
	size_t i;
	kArray *a = DP(ctx->gma)->insts;
	for(i = 0; i < knh_Array_size(a); i++) {
		if(IS_Term(a->terms[i])) {
			kTerm *tk = a->terms[i];
			if(TT_(tk) == TT_LVAR) {
				TT_(tk) = TT_FVAR;
				tk->index += shift;
			}
			if(TT_(tk) == TT_LFIELD) {
				TT_(tk) = TT_FIELD;
				tk->index += shift;
			}
		}
		if(IS_StmtExpr(a->stmts[i])) {
			kStmtExpr *stmt = a->stmts[i];
			DP(stmt)->espidx += shift;
		}
	}
	knh_Array_clear(ctx, a, 0);
}

static void Method_compile(CTX ctx, kMethod *mtd, kStmtExpr *stmtB)
{
	DBG_ASSERT(knh_Array_size(DP(ctx->gma)->insts) == 0);
	DBG_ASSERT(knh_Array_size(DP(ctx->gma)->lstacks) == 0);
	kBasicBlock* lbINIT = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbBEGIN = new_BasicBlockLABEL(ctx);
	kBasicBlock* lbEND = new_BasicBlockLABEL(ctx);
	SP(ctx->gma)->uline = SP(stmtB)->uline;
	DP(ctx->gma)->bbNC = lbINIT;
	GammaBuilder_pushLABEL(ctx, stmtB, lbBEGIN, lbEND);
	ASM(THCODE, _THCODE, ULINE_uri(SP(stmtB)->uline));
	if(Method_isStatic(mtd) && GammaBuilder_hasFIELD(ctx->gma)) {
		ASM(TR, OC_(0), SFP_(0), RIX_(0), ClassTBL(DP(ctx->gma)->this_cid), _NULVAL);
	}
	ASM_LABEL(ctx, lbBEGIN);
	{
		long i;
		knh_gamma2_t *gf = DP(ctx->gma)->gf;
		for(i = 1; i < (long)DP(ctx->gma)->psize + 1; i++) {
			if(IS_NOTNULL(gf[i].tk)) {
	//					kBasicBlock*  lb = new_BasicBlockLABEL(ctx);
	//					KNH_ASM(JMPNN, TADDRx lb, i);
	//					KNH_ASM(OSET, (i), value);
	//					KNH_ASM_UNBOX(ctx, O_cid(value), i);
	//					KNH_ASM_LABEL(ctx, lb);
			}
		}
		for(; i < DP(ctx->gma)->fvarsize; i++) {
			ktype_t type = gf[i].type;
			if(gf[i].fn == FN_vargs) {
				kclass_t cid = C_p1(CLASS_t(type));
				DBG_ASSERT_cid(cid);
				ASM(TR, OC_(i), SFP_(i), RIX_(i-i), ClassTBL(cid), _VARGS);// i++;
				continue;
			}
			if(IS_Tunbox(type)) {
				ASM(NSET, NC_(i), 0);
			}
			else {
				kclass_t cid = CLASS_t(type);
				kObject *v = KNH_NULVAL(cid);
				if(v != ClassTBL(cid)->defnull) {
					ASM(TR, OC_(i), SFP_(i), RIX_(i-i), ClassTBL(cid), _NULVAL);
				}
				else {
					ASM(OSET, OC_(i), v);
				}
			}
		}
	}
	DP(ctx->gma)->fvarsize = 0;
	BLOCK_asm(ctx, stmtB);
	ASM_LABEL(ctx, lbEND);
	ASM(RET);
	GammaBuilder_popLABEL(ctx);
	DBG_ASSERT(knh_Array_size(DP(ctx->gma)->lstacks) == 0);
	GammaBuilder_compile(ctx, lbINIT, lbEND);
}

void knh_Method_asm(CTX ctx, kMethod *mtd, kStmtExpr *stmtB, knh_Ftyping typing)
{
	// FIXME
	//DBG_ASSERT(knh_Array_size(DP(ctx->gma)->insts) == 0);
	DP(ctx->gma)->flag  = 0;
	KNH_SETv(ctx, DP(ctx->gma)->mtd, mtd);
	typing(ctx, mtd, stmtB);
//	kMethodoAbstract(ctx, mtd);
	GammaBuilder_shiftLocalScope(ctx);
	knh_Array_clear(ctx, DP(ctx->gma)->lstacks, 0);
#ifdef K_USING_LLVM
	void knh_LLVMMethod_asm(CTX ctx, kMethod *mtd, kStmtExpr *stmtP);
	knh_LLVMMethod_asm(ctx, mtd, stmtB);
#else
	/* CompilerAPI */
	if (IS_NOTNULL(ctx->share->konoha_compiler)) {
		ctx->share->compilerAPI(ctx, mtd, stmtB);
	} else {
		Method_compile(ctx, mtd, stmtB);
	}
#endif /* K_USING_LLVM */
}

KMETHOD knh_Fmethod_asm(CTX ctx, ksfp_t *sfp _RIX)
{
	BEGIN_LOCAL(ctx, lsfp, 1);
	kMethod *mtd = sfp[K_MTDIDX].mtdNC;
	DBG_ASSERT(IS_Method(mtd));
	KNH_SETv(ctx, lsfp[0].o, DP(mtd)->stmtB);
	DP(ctx->gma)->flag  = 0;
	KNH_SETv(ctx, DP(ctx->gma)->mtd, mtd);
	kMethodoAbstract(ctx, mtd);
	DP(ctx->gma)->fvarsize = DP(mtd)->delta;
	DBG_ASSERT(IS_StmtExpr(lsfp[0].o));
	Method_compile(ctx, mtd, (kStmtExpr*)lsfp[0].o);
	END_LOCAL(ctx, lsfp);
	(mtd)->fcall_1(ctx, sfp, K_RIX);
}

/* ------------------------------------------------------------------------ */
/* [loadSystem] */

static kopl_t* opline_findOPCODE(CTX ctx, kopl_t *op, kopcode_t opcode)
{
	while(1) {
		if(op->opcode == opcode) return op;
		if(op->opcode == OPCODE_RET) break;
		op++;
	}
	KNH_ASSERT(ctx == NULL); // DON'T NOT HAPPEN
	return NULL;
}

static void _STACKTRACE(CTX ctx, ksfp_t *sfp, klr_PROBE_t *op)
{
	if(IS_Exception(ctx->e)) {
		kOutputStream *w = KNH_STDOUT;
		knh_write_ascii(ctx, w, TERM_BNOTE(ctx, LOG_ERR));
		knh_write_Object(ctx, w, UPCAST(ctx->e), FMT_dump);
		knh_write_ascii(ctx, w, TERM_ENOTE(ctx, LOG_ERR));
	}
}

void knh_loadScriptSystemKonohaCode(CTX ctx)
{
	BEGIN_LOCAL(ctx, lsfp, 4);
	kBasicBlock* ia = new_(BasicBlock);
	kBasicBlock* ib = new_(BasicBlock);
	kBasicBlock* ic = new_(BasicBlock);
	kBasicBlock* id = new_(BasicBlock);
	KNH_SETv(ctx, lsfp[0].o, ia);
	KNH_SETv(ctx, lsfp[1].o, ib);
	KNH_SETv(ctx, lsfp[2].o, ic);
	KNH_SETv(ctx, lsfp[3].o, id);
	BasicBlock_add(ctx, ia, THCODE, _THCODE, URI_unknown);
	BasicBlock_add(ctx, ia, TRY, NULL/*lb*/, OC_(-(K_CALLDELTA+1)));  // LAUNCH
	ia->nextNC = ib;
	ia->jumpNC = ic;
	BasicBlock_add(ctx, ib, ENTER);
	BasicBlock_add(ctx, ib, TRYEND, OC_(-(K_CALLDELTA+1)));
	BasicBlock_add(ctx, ib, EXIT);
	ib->nextNC = ic;
	BasicBlock_add(ctx, ic, PROBE, 0, _STACKTRACE, 0, 0);
	BasicBlock_add(ctx, ic, EXIT);
	BasicBlock_add(ctx, ic, FUNCCALL);               // FUNCCALL
	BasicBlock_add(ctx, ic, VEXEC);                  // VEXEC
	BasicBlock_add(ctx, ic, EXIT);
	ic->nextNC = id;
	BasicBlock_add(ctx, id, RET);  // NEED TERMINATION
	{
		kKonohaCode *kcode = BasicBlock_link(ctx, ia, id);
		kopl_t *pc = knh_VirtualMachine_run(ctx, ctx->esp, SP(kcode)->code);
		knh_setClassDefaultValue(ctx, CLASS_KonohaCode, kcode, NULL);
		((kshare_t*)ctx->share)->PRECOMPILED_LAUNCH = opline_findOPCODE(ctx, pc, OPCODE_TRY);
		((kshare_t*)ctx->share)->PRECOMPILED_FUNCCALL = opline_findOPCODE(ctx, pc, OPCODE_FUNCCALL);
		((kshare_t*)ctx->share)->PRECOMPILED_VEXEC = opline_findOPCODE(ctx, pc, OPCODE_VEXEC);
	}
	knh_Array_clear(ctx, DP(ctx->gma)->insts, 0);
	END_LOCAL(ctx, lsfp);
}

/* ------------------------------------------------------------------------ */

typedef struct knh_funcname_t {
	char *name;
	void *func;
} knh_funcname_t;

#define _FUNC(func, name) { (char *) name , (void*) func}

struct knh_funcname_t _FuncData[] = {
	_FUNC(_PRINT, "PRINT"), _FUNC(_BOX, "BOX"), _FUNC(TR_NEW, "NEW"),
	_FUNC(_NULVAL, "NULL"), _FUNC(_CWB, "CWB"), _FUNC(_TOSTR, "TOSTR"),
	_FUNC(_LOOKUPMTD, "LOOKUPMTD"),
	_FUNC(knh_PROP, "PROP"), _FUNC(_bBOX, "bBOX"), _FUNC(_VARGS, "VARGS"),
	_FUNC(_ERR, "ERR"), _FUNC(_TCHECK, "CHKTYPE"),
	_FUNC(_DYNMTD, "DYNMTD"), _FUNC(_PBOX, "PBOX"),
	_FUNC(NULL, NULL),
};

void knh_write_vmfunc(CTX ctx, kOutputStream *w, void *f)
{
	knh_funcname_t *d = _FuncData;
	while(d->func != NULL) {
		if(d->func == f) {
			knh_write(ctx, w, B(d->name));
			return;
		}
		d++;
	}
	knh_printf(ctx, w, "func:%p", f);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
