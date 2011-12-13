/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 * 
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 * 
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

#include"commons.h"


#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
/* [common] */

#define K_USING_VMINLINE
#ifndef offsetof
#define offsetof(T, M) ((size_t) &(((T*)0)->M))
#endif
#include "vminline.c"

/* ------------------------------------------------------------------------ */
/* [data] */

#define _CONST 1
#define _JIT   (1<<1)
#define _DEF   (1<<2)
typedef struct {
	const char *name;
	kflag_t   flag;
	kushort_t size;
	kushort_t struct_size;
	kushort_t types[6];
	kushort_t fields[6];
} knh_OPDATA_t;

static const knh_OPDATA_t OPDATA[] = {
	{"HALT", 0, 0, sizeof(klr_HALT_t), { VMT_VOID}, {0}},
	{"THCODE", 0, 2, sizeof(klr_THCODE_t), { VMT_F, VMT_U, VMT_VOID}, {offsetof(klr_THCODE_t, th), offsetof(klr_THCODE_t, uri), 0}},
	{"ENTER", 0, 0, sizeof(klr_ENTER_t), { VMT_VOID}, {0}},
	{"VEXEC", 0, 0, sizeof(klr_VEXEC_t), { VMT_VOID}, {0}},
	{"YIELD", 0, 1, sizeof(klr_YIELD_t), { VMT_SFPIDX, VMT_VOID}, {offsetof(klr_YIELD_t, n), 0}},
	{"FUNCCALL", 0, 0, sizeof(klr_FUNCCALL_t), { VMT_VOID}, {0}},
	{"TRY", 0, 2, sizeof(klr_TRY_t), { VMT_ADDR, VMT_RO, VMT_VOID}, {offsetof(klr_TRY_t, jumppc), offsetof(klr_TRY_t, hn), 0}},
	{"TRYEND", 0, 1, sizeof(klr_TRYEND_t), { VMT_RO, VMT_VOID}, {offsetof(klr_TRYEND_t, hn), 0}},
	{"THROW", 0, 1, sizeof(klr_THROW_t), { VMT_SFPIDX, VMT_VOID}, {offsetof(klr_THROW_t, start), 0}},
	{"ASSERT", 0, 2, sizeof(klr_ASSERT_t), { VMT_SFPIDX, VMT_U, VMT_VOID}, {offsetof(klr_ASSERT_t, start), offsetof(klr_ASSERT_t, uline), 0}},
	{"CATCH", _CONST, 3+VMTSIZE_int, sizeof(klr_CATCH_t), { VMT_ADDR, VMT_RO, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_CATCH_t, jumppc), offsetof(klr_CATCH_t, en), offsetof(klr_CATCH_t, eid), 0}},
	{"CHKIN", 0, 2, sizeof(klr_CHKIN_t), { VMT_RO, VMT_F, VMT_VOID}, {offsetof(klr_CHKIN_t, on), offsetof(klr_CHKIN_t, checkin), 0}},
	{"CHKOUT", 0, 2, sizeof(klr_CHKOUT_t), { VMT_RO, VMT_F, VMT_VOID}, {offsetof(klr_CHKOUT_t, on), offsetof(klr_CHKOUT_t, checkout), 0}},
	{"ERROR", _CONST, 2, sizeof(klr_ERROR_t), { VMT_SFPIDX, VMT_STRING, VMT_VOID}, {offsetof(klr_ERROR_t, start), offsetof(klr_ERROR_t, msg), 0}},
	{"P", _CONST, 4, sizeof(klr_P_t), { VMT_F, VMT_S, VMT_SFPIDX2, VMT_STRING, VMT_VOID}, {offsetof(klr_P_t, print), offsetof(klr_P_t, flag), offsetof(klr_P_t, n), offsetof(klr_P_t, msg), 0}},
	{"PROBE", 0, 3, sizeof(klr_PROBE_t), { VMT_SFPIDX2, VMT_F, VMT_U, VMT_VOID}, {offsetof(klr_PROBE_t, sfpidx), offsetof(klr_PROBE_t, probe), offsetof(klr_PROBE_t, n), 0}},
	{"EXIT", 0, 0, sizeof(klr_EXIT_t), { VMT_VOID}, {0}},
	{"NSET", _DEF|_JIT, 2+VMTSIZE_int, sizeof(klr_NSET_t), { VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_NSET_t, a), offsetof(klr_NSET_t, n), 0}},
	{"NMOV", _DEF|_JIT, 2, sizeof(klr_NMOV_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_NMOV_t, a), offsetof(klr_NMOV_t, b), 0}},
	{"NNMOV", _DEF, 4, sizeof(klr_NNMOV_t), { VMT_RN, VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_NNMOV_t, a), offsetof(klr_NNMOV_t, b), offsetof(klr_NNMOV_t, c), offsetof(klr_NNMOV_t, d), 0}},
	{"NSET2", _DEF|_JIT, 3+VMTSIZE_int+VMTSIZE_int, sizeof(klr_NSET2_t), { VMT_RN, VMT_INT VMTX_INT, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_NSET2_t, a), offsetof(klr_NSET2_t, n), offsetof(klr_NSET2_t, n2), 0}},
	{"NSET3", _DEF|_JIT, 4, sizeof(klr_NSET3_t), { VMT_RN, VMT_U, VMT_U, VMT_U, VMT_VOID}, {offsetof(klr_NSET3_t, a), offsetof(klr_NSET3_t, n), offsetof(klr_NSET3_t, n2), offsetof(klr_NSET3_t, n3), 0}},
	{"NSET4", _DEF|_JIT, 5, sizeof(klr_NSET4_t), { VMT_RN, VMT_U, VMT_U, VMT_U, VMT_U, VMT_VOID}, {offsetof(klr_NSET4_t, a), offsetof(klr_NSET4_t, n), offsetof(klr_NSET4_t, n2), offsetof(klr_NSET4_t, n3), offsetof(klr_NSET4_t, n4), 0}},
	{"NMOVx", _DEF, 2+1, sizeof(klr_NMOVx_t), { VMT_RN, VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_NMOVx_t, a), offsetof(klr_NMOVx_t, b), offsetof(klr_NMOVx_t, b.n), 0}},
	{"XNSET", 0, 2+1+VMTSIZE_int, sizeof(klr_XNSET_t), { VMT_SFX, VMT_VOID, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_XNSET_t, a), offsetof(klr_XNSET_t, a.n), offsetof(klr_XNSET_t, b), 0}},
	{"XNMOV", 0, 2+1, sizeof(klr_XNMOV_t), { VMT_SFX, VMT_VOID, VMT_RN, VMT_VOID}, {offsetof(klr_XNMOV_t, a), offsetof(klr_XNMOV_t, a.n), offsetof(klr_XNMOV_t, b), 0}},
	{"XNMOVx", 0, 2+1+1, sizeof(klr_XNMOVx_t), { VMT_SFX, VMT_VOID, VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_XNMOVx_t, a), offsetof(klr_XNMOVx_t, a.n), offsetof(klr_XNMOVx_t, b), offsetof(klr_XNMOVx_t, b.n), 0}},
	{"iINC", _DEF|_JIT, 1, sizeof(klr_iINC_t), { VMT_RN, VMT_VOID}, {offsetof(klr_iINC_t, a), 0}},
	{"iDEC", _DEF|_JIT, 1, sizeof(klr_iDEC_t), { VMT_RN, VMT_VOID}, {offsetof(klr_iDEC_t, a), 0}},
	{"bNUL", _DEF|_JIT, 2, sizeof(klr_bNUL_t), { VMT_RN, VMT_RO, VMT_VOID}, {offsetof(klr_bNUL_t, c), offsetof(klr_bNUL_t, a), 0}},
	{"bNN", _DEF|_JIT, 2, sizeof(klr_bNN_t), { VMT_RN, VMT_RO, VMT_VOID}, {offsetof(klr_bNN_t, c), offsetof(klr_bNN_t, a), 0}},
	{"bNOT", _DEF|_JIT, 2, sizeof(klr_bNOT_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_bNOT_t, c), offsetof(klr_bNOT_t, a), 0}},
	{"iNEG", _DEF|_JIT, 2, sizeof(klr_iNEG_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iNEG_t, c), offsetof(klr_iNEG_t, a), 0}},
	{"fNEG", _DEF|_JIT, 2, sizeof(klr_fNEG_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fNEG_t, c), offsetof(klr_fNEG_t, a), 0}},
	{"iTR", _DEF|_JIT, 3, sizeof(klr_iTR_t), { VMT_RN, VMT_RN, VMT_F, VMT_VOID}, {offsetof(klr_iTR_t, c), offsetof(klr_iTR_t, a), offsetof(klr_iTR_t, inttr), 0}},
	{"fTR", _DEF|_JIT, 3, sizeof(klr_fTR_t), { VMT_RN, VMT_RN, VMT_F, VMT_VOID}, {offsetof(klr_fTR_t, c), offsetof(klr_fTR_t, a), offsetof(klr_fTR_t, floattr), 0}},
	{"iADD", _DEF|_JIT, 3, sizeof(klr_iADD_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iADD_t, c), offsetof(klr_iADD_t, a), offsetof(klr_iADD_t, b), 0}},
	{"iSUB", _DEF|_JIT, 3, sizeof(klr_iSUB_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iSUB_t, c), offsetof(klr_iSUB_t, a), offsetof(klr_iSUB_t, b), 0}},
	{"iMUL", _DEF|_JIT, 3, sizeof(klr_iMUL_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iMUL_t, c), offsetof(klr_iMUL_t, a), offsetof(klr_iMUL_t, b), 0}},
	{"iDIV", _DEF|_JIT, 3, sizeof(klr_iDIV_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iDIV_t, c), offsetof(klr_iDIV_t, a), offsetof(klr_iDIV_t, b), 0}},
	{"iMOD", _DEF|_JIT, 3, sizeof(klr_iMOD_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iMOD_t, c), offsetof(klr_iMOD_t, a), offsetof(klr_iMOD_t, b), 0}},
	{"iEQ", _DEF|_JIT, 3, sizeof(klr_iEQ_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iEQ_t, c), offsetof(klr_iEQ_t, a), offsetof(klr_iEQ_t, b), 0}},
	{"iNEQ", _DEF|_JIT, 3, sizeof(klr_iNEQ_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iNEQ_t, c), offsetof(klr_iNEQ_t, a), offsetof(klr_iNEQ_t, b), 0}},
	{"iLT", _DEF|_JIT, 3, sizeof(klr_iLT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iLT_t, c), offsetof(klr_iLT_t, a), offsetof(klr_iLT_t, b), 0}},
	{"iLTE", _DEF|_JIT, 3, sizeof(klr_iLTE_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iLTE_t, c), offsetof(klr_iLTE_t, a), offsetof(klr_iLTE_t, b), 0}},
	{"iGT", _DEF|_JIT, 3, sizeof(klr_iGT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iGT_t, c), offsetof(klr_iGT_t, a), offsetof(klr_iGT_t, b), 0}},
	{"iGTE", _DEF|_JIT, 3, sizeof(klr_iGTE_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iGTE_t, c), offsetof(klr_iGTE_t, a), offsetof(klr_iGTE_t, b), 0}},
	{"iAND", _DEF|_JIT, 3, sizeof(klr_iAND_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iAND_t, c), offsetof(klr_iAND_t, a), offsetof(klr_iAND_t, b), 0}},
	{"iOR", _DEF|_JIT, 3, sizeof(klr_iOR_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iOR_t, c), offsetof(klr_iOR_t, a), offsetof(klr_iOR_t, b), 0}},
	{"iXOR", _DEF|_JIT, 3, sizeof(klr_iXOR_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iXOR_t, c), offsetof(klr_iXOR_t, a), offsetof(klr_iXOR_t, b), 0}},
	{"iLSFT", _DEF|_JIT, 3, sizeof(klr_iLSFT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iLSFT_t, c), offsetof(klr_iLSFT_t, a), offsetof(klr_iLSFT_t, b), 0}},
	{"iRSFT", _DEF|_JIT, 3, sizeof(klr_iRSFT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iRSFT_t, c), offsetof(klr_iRSFT_t, a), offsetof(klr_iRSFT_t, n), 0}},
	{"iADDC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iADDC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iADDC_t, c), offsetof(klr_iADDC_t, a), offsetof(klr_iADDC_t, n), 0}},
	{"iSUBC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iSUBC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iSUBC_t, c), offsetof(klr_iSUBC_t, a), offsetof(klr_iSUBC_t, n), 0}},
	{"iMULC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iMULC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iMULC_t, c), offsetof(klr_iMULC_t, a), offsetof(klr_iMULC_t, n), 0}},
	{"iDIVC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iDIVC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iDIVC_t, c), offsetof(klr_iDIVC_t, a), offsetof(klr_iDIVC_t, n), 0}},
	{"iMODC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iMODC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iMODC_t, c), offsetof(klr_iMODC_t, a), offsetof(klr_iMODC_t, n), 0}},
	{"iEQC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iEQC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iEQC_t, c), offsetof(klr_iEQC_t, a), offsetof(klr_iEQC_t, n), 0}},
	{"iNEQC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iNEQC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iNEQC_t, c), offsetof(klr_iNEQC_t, a), offsetof(klr_iNEQC_t, n), 0}},
	{"iLTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iLTC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iLTC_t, c), offsetof(klr_iLTC_t, a), offsetof(klr_iLTC_t, n), 0}},
	{"iLTEC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iLTEC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iLTEC_t, c), offsetof(klr_iLTEC_t, a), offsetof(klr_iLTEC_t, n), 0}},
	{"iGTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iGTC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iGTC_t, c), offsetof(klr_iGTC_t, a), offsetof(klr_iGTC_t, n), 0}},
	{"iGTEC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iGTEC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iGTEC_t, c), offsetof(klr_iGTEC_t, a), offsetof(klr_iGTEC_t, n), 0}},
	{"iANDC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iANDC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iANDC_t, c), offsetof(klr_iANDC_t, a), offsetof(klr_iANDC_t, n), 0}},
	{"iORC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iORC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iORC_t, c), offsetof(klr_iORC_t, a), offsetof(klr_iORC_t, n), 0}},
	{"iXORC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iXORC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iXORC_t, c), offsetof(klr_iXORC_t, a), offsetof(klr_iXORC_t, n), 0}},
	{"iLSFTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iLSFTC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iLSFTC_t, c), offsetof(klr_iLSFTC_t, a), offsetof(klr_iLSFTC_t, n), 0}},
	{"iRSFTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iRSFTC_t), { VMT_RN, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iRSFTC_t, c), offsetof(klr_iRSFTC_t, a), offsetof(klr_iRSFTC_t, n), 0}},
	{"fADD", _DEF|_JIT, 3, sizeof(klr_fADD_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fADD_t, c), offsetof(klr_fADD_t, a), offsetof(klr_fADD_t, b), 0}},
	{"fSUB", _DEF|_JIT, 3, sizeof(klr_fSUB_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fSUB_t, c), offsetof(klr_fSUB_t, a), offsetof(klr_fSUB_t, b), 0}},
	{"fMUL", _DEF|_JIT, 3, sizeof(klr_fMUL_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fMUL_t, c), offsetof(klr_fMUL_t, a), offsetof(klr_fMUL_t, b), 0}},
	{"fDIV", _DEF|_JIT, 3, sizeof(klr_fDIV_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fDIV_t, c), offsetof(klr_fDIV_t, a), offsetof(klr_fDIV_t, b), 0}},
	{"fEQ", _DEF|_JIT, 3, sizeof(klr_fEQ_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fEQ_t, c), offsetof(klr_fEQ_t, a), offsetof(klr_fEQ_t, b), 0}},
	{"fNEQ", _DEF|_JIT, 3, sizeof(klr_fNEQ_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fNEQ_t, c), offsetof(klr_fNEQ_t, a), offsetof(klr_fNEQ_t, b), 0}},
	{"fLT", _DEF|_JIT, 3, sizeof(klr_fLT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fLT_t, c), offsetof(klr_fLT_t, a), offsetof(klr_fLT_t, b), 0}},
	{"fLTE", _DEF|_JIT, 3, sizeof(klr_fLTE_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fLTE_t, c), offsetof(klr_fLTE_t, a), offsetof(klr_fLTE_t, b), 0}},
	{"fGT", _DEF|_JIT, 3, sizeof(klr_fGT_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fGT_t, c), offsetof(klr_fGT_t, a), offsetof(klr_fGT_t, b), 0}},
	{"fGTE", _DEF|_JIT, 3, sizeof(klr_fGTE_t), { VMT_RN, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fGTE_t, c), offsetof(klr_fGTE_t, a), offsetof(klr_fGTE_t, b), 0}},
	{"fADDC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fADDC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fADDC_t, c), offsetof(klr_fADDC_t, a), offsetof(klr_fADDC_t, n), 0}},
	{"fSUBC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fSUBC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fSUBC_t, c), offsetof(klr_fSUBC_t, a), offsetof(klr_fSUBC_t, n), 0}},
	{"fMULC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fMULC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fMULC_t, c), offsetof(klr_fMULC_t, a), offsetof(klr_fMULC_t, n), 0}},
	{"fDIVC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fDIVC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fDIVC_t, c), offsetof(klr_fDIVC_t, a), offsetof(klr_fDIVC_t, n), 0}},
	{"fEQC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fEQC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fEQC_t, c), offsetof(klr_fEQC_t, a), offsetof(klr_fEQC_t, n), 0}},
	{"fNEQC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fNEQC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fNEQC_t, c), offsetof(klr_fNEQC_t, a), offsetof(klr_fNEQC_t, n), 0}},
	{"fLTC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fLTC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fLTC_t, c), offsetof(klr_fLTC_t, a), offsetof(klr_fLTC_t, n), 0}},
	{"fLTEC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fLTEC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fLTEC_t, c), offsetof(klr_fLTEC_t, a), offsetof(klr_fLTEC_t, n), 0}},
	{"fGTC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fGTC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fGTC_t, c), offsetof(klr_fGTC_t, a), offsetof(klr_fGTC_t, n), 0}},
	{"fGTEC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fGTEC_t), { VMT_RN, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fGTEC_t, c), offsetof(klr_fGTEC_t, a), offsetof(klr_fGTEC_t, n), 0}},
	{"RCINC", _JIT, 1, sizeof(klr_RCINC_t), { VMT_RO, VMT_VOID}, {offsetof(klr_RCINC_t, a), 0}},
	{"RCDEC", _JIT, 1, sizeof(klr_RCDEC_t), { VMT_RO, VMT_VOID}, {offsetof(klr_RCDEC_t, a), 0}},
	{"OSET", _DEF|_JIT|_CONST, 2, sizeof(klr_OSET_t), { VMT_RO, VMT_OBJECT, VMT_VOID}, {offsetof(klr_OSET_t, a), offsetof(klr_OSET_t, o), 0}},
	{"OMOV", _DEF|_JIT, 2, sizeof(klr_OMOV_t), { VMT_RO, VMT_RO, VMT_VOID}, {offsetof(klr_OMOV_t, a), offsetof(klr_OMOV_t, b), 0}},
	{"OOMOV", _DEF|_JIT, 4, sizeof(klr_OOMOV_t), { VMT_RO, VMT_RO, VMT_RO, VMT_RO, VMT_VOID}, {offsetof(klr_OOMOV_t, a), offsetof(klr_OOMOV_t, b), offsetof(klr_OOMOV_t, c), offsetof(klr_OOMOV_t, d), 0}},
	{"ONMOV", _DEF|_JIT, 4, sizeof(klr_ONMOV_t), { VMT_RO, VMT_RO, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_ONMOV_t, a), offsetof(klr_ONMOV_t, b), offsetof(klr_ONMOV_t, c), offsetof(klr_ONMOV_t, d), 0}},
	{"OSET2", _JIT|_CONST, 3, sizeof(klr_OSET2_t), { VMT_RO, VMT_OBJECT, VMT_OBJECT, VMT_VOID}, {offsetof(klr_OSET2_t, a), offsetof(klr_OSET2_t, v), offsetof(klr_OSET2_t, v2), 0}},
	{"OSET3", _JIT|_CONST, 4, sizeof(klr_OSET3_t), { VMT_RO, VMT_OBJECT, VMT_OBJECT, VMT_OBJECT, VMT_VOID}, {offsetof(klr_OSET3_t, a), offsetof(klr_OSET3_t, v), offsetof(klr_OSET3_t, v2), offsetof(klr_OSET3_t, v3), 0}},
	{"OSET4", _JIT|_CONST, 5, sizeof(klr_OSET4_t), { VMT_RO, VMT_OBJECT, VMT_OBJECT, VMT_OBJECT, VMT_OBJECT, VMT_VOID}, {offsetof(klr_OSET4_t, a), offsetof(klr_OSET4_t, v), offsetof(klr_OSET4_t, v2), offsetof(klr_OSET4_t, v3), offsetof(klr_OSET4_t, v4), 0}},
	{"RCINCx", 0, 1+1, sizeof(klr_RCINCx_t), { VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_RCINCx_t, a), offsetof(klr_RCINCx_t, a.n), 0}},
	{"RCDECx", 0, 1+1, sizeof(klr_RCDECx_t), { VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_RCDECx_t, a), offsetof(klr_RCDECx_t, a.n), 0}},
	{"OMOVx", _DEF|_JIT, 2+1, sizeof(klr_OMOVx_t), { VMT_RO, VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_OMOVx_t, a), offsetof(klr_OMOVx_t, b), offsetof(klr_OMOVx_t, b.n), 0}},
	{"XMOV", _JIT, 2+1, sizeof(klr_XMOV_t), { VMT_SFX, VMT_VOID, VMT_RO, VMT_VOID}, {offsetof(klr_XMOV_t, a), offsetof(klr_XMOV_t, a.n), offsetof(klr_XMOV_t, b), 0}},
	{"XOSET", _JIT|_CONST, 2+1, sizeof(klr_XOSET_t), { VMT_SFX, VMT_VOID, VMT_OBJECT, VMT_VOID}, {offsetof(klr_XOSET_t, a), offsetof(klr_XOSET_t, a.n), offsetof(klr_XOSET_t, b), 0}},
	{"XMOVx", 0, 2+1+1, sizeof(klr_XMOVx_t), { VMT_SFX, VMT_VOID, VMT_SFX, VMT_VOID, VMT_VOID}, {offsetof(klr_XMOVx_t, a), offsetof(klr_XMOVx_t, a.n), offsetof(klr_XMOVx_t, b), offsetof(klr_XMOVx_t, b.n), 0}},
	{"CHKSTACK", 0, 1, sizeof(klr_CHKSTACK_t), { VMT_SFPIDX, VMT_VOID}, {offsetof(klr_CHKSTACK_t, n), 0}},
	{"LDMTD", 0, 4, sizeof(klr_LDMTD_t), { VMT_SFPIDX, VMT_F, VMT_HCACHE, VMT_MTD, VMT_VOID}, {offsetof(klr_LDMTD_t, thisidx), offsetof(klr_LDMTD_t, loadmtd), offsetof(klr_LDMTD_t, cache), offsetof(klr_LDMTD_t, mtdNC), 0}},
	{"CALL", _DEF|_JIT, 3, sizeof(klr_CALL_t), { VMT_R, VMT_SFPIDX, VMT_SFPIDX, VMT_VOID}, {offsetof(klr_CALL_t, a), offsetof(klr_CALL_t, thisidx), offsetof(klr_CALL_t, espshift), 0}},
	{"SCALL", _DEF|_JIT, 4, sizeof(klr_SCALL_t), { VMT_R, VMT_SFPIDX, VMT_SFPIDX, VMT_MTD, VMT_VOID}, {offsetof(klr_SCALL_t, a), offsetof(klr_SCALL_t, thisidx), offsetof(klr_SCALL_t, espshift), offsetof(klr_SCALL_t, mtdNC), 0}},
	{"VCALL", _DEF|_JIT, 4, sizeof(klr_VCALL_t), { VMT_R, VMT_SFPIDX, VMT_SFPIDX, VMT_MTD, VMT_VOID}, {offsetof(klr_VCALL_t, a), offsetof(klr_VCALL_t, thisidx), offsetof(klr_VCALL_t, espshift), offsetof(klr_VCALL_t, mtdNC), 0}},
	{"VCALL", _DEF|_JIT, 4, sizeof(klr_VCALL__t), { VMT_R, VMT_SFPIDX, VMT_SFPIDX, VMT_MTD, VMT_VOID}, {offsetof(klr_VCALL__t, a), offsetof(klr_VCALL__t, thisidx), offsetof(klr_VCALL__t, espshift), offsetof(klr_VCALL__t, mtdNC), 0}},
	{"FASTCALL0", _DEF|_JIT, 5, sizeof(klr_FASTCALL0_t), { VMT_R, VMT_SFPIDX, VMT_S, VMT_SFPIDX, VMT_F, VMT_VOID}, {offsetof(klr_FASTCALL0_t, a), offsetof(klr_FASTCALL0_t, thisidx), offsetof(klr_FASTCALL0_t, rix), offsetof(klr_FASTCALL0_t, espshift), offsetof(klr_FASTCALL0_t, fcall), 0}},
	{"RET", _JIT, 0, sizeof(klr_RET_t), { VMT_VOID}, {0}},
	{"TR", _DEF|_JIT, 5, sizeof(klr_TR_t), { VMT_R, VMT_SFPIDX, VMT_S, VMT_CID, VMT_F, VMT_VOID}, {offsetof(klr_TR_t, a), offsetof(klr_TR_t, b), offsetof(klr_TR_t, rix), offsetof(klr_TR_t, cid), offsetof(klr_TR_t, tr), 0}},
	{"SCAST", _DEF, 5, sizeof(klr_SCAST_t), { VMT_R, VMT_SFPIDX, VMT_S, VMT_SFPIDX, VMT_TMR, VMT_VOID}, {offsetof(klr_SCAST_t, a), offsetof(klr_SCAST_t, b), offsetof(klr_SCAST_t, rix), offsetof(klr_SCAST_t, espshift), offsetof(klr_SCAST_t, cast), 0}},
	{"TCAST", _DEF, 5, sizeof(klr_TCAST_t), { VMT_R, VMT_SFPIDX, VMT_S, VMT_SFPIDX, VMT_TMR, VMT_VOID}, {offsetof(klr_TCAST_t, a), offsetof(klr_TCAST_t, b), offsetof(klr_TCAST_t, rix), offsetof(klr_TCAST_t, espshift), offsetof(klr_TCAST_t, cast), 0}},
	{"ACAST", _DEF, 5, sizeof(klr_ACAST_t), { VMT_R, VMT_SFPIDX, VMT_S, VMT_SFPIDX, VMT_TMR, VMT_VOID}, {offsetof(klr_ACAST_t, a), offsetof(klr_ACAST_t, b), offsetof(klr_ACAST_t, rix), offsetof(klr_ACAST_t, espshift), offsetof(klr_ACAST_t, cast), 0}},
	{"iCAST", _DEF|_JIT, 2, sizeof(klr_iCAST_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iCAST_t, a), offsetof(klr_iCAST_t, b), 0}},
	{"fCAST", _DEF|_JIT, 2, sizeof(klr_fCAST_t), { VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fCAST_t, a), offsetof(klr_fCAST_t, b), 0}},
	{"SAFEPOINT", _JIT, 1, sizeof(klr_SAFEPOINT_t), { VMT_SFPIDX, VMT_VOID}, {offsetof(klr_SAFEPOINT_t, espshift), 0}},
	{"JMP", _JIT, 1, sizeof(klr_JMP_t), { VMT_ADDR, VMT_VOID}, {offsetof(klr_JMP_t, jumppc), 0}},
	{"JMP", _JIT, 1, sizeof(klr_JMP__t), { VMT_ADDR, VMT_VOID}, {offsetof(klr_JMP__t, jumppc), 0}},
	{"JMPF", 0, 2, sizeof(klr_JMPF_t), { VMT_ADDR, VMT_RN, VMT_VOID}, {offsetof(klr_JMPF_t, jumppc), offsetof(klr_JMPF_t, a), 0}},
	{"NEXT", _DEF, 5, sizeof(klr_NEXT_t), { VMT_ADDR, VMT_R, VMT_SFPIDX, VMT_S, VMT_SFPIDX, VMT_VOID}, {offsetof(klr_NEXT_t, jumppc), offsetof(klr_NEXT_t, a), offsetof(klr_NEXT_t, b), offsetof(klr_NEXT_t, rix), offsetof(klr_NEXT_t, espshift), 0}},
	{"BGETIDX", _DEF|_JIT, 3, sizeof(klr_BGETIDX_t), { VMT_RN, VMT_RO, VMT_RN, VMT_VOID}, {offsetof(klr_BGETIDX_t, c), offsetof(klr_BGETIDX_t, a), offsetof(klr_BGETIDX_t, n), 0}},
	{"BSETIDX", _DEF|_JIT, 4, sizeof(klr_BSETIDX_t), { VMT_RN, VMT_RO, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_BSETIDX_t, c), offsetof(klr_BSETIDX_t, a), offsetof(klr_BSETIDX_t, n), offsetof(klr_BSETIDX_t, v), 0}},
	{"BGETIDXC", _DEF|_JIT, 3, sizeof(klr_BGETIDXC_t), { VMT_RN, VMT_RO, VMT_U, VMT_VOID}, {offsetof(klr_BGETIDXC_t, c), offsetof(klr_BGETIDXC_t, a), offsetof(klr_BGETIDXC_t, n), 0}},
	{"BSETIDXC", _DEF|_JIT, 4, sizeof(klr_BSETIDXC_t), { VMT_RN, VMT_RO, VMT_U, VMT_RN, VMT_VOID}, {offsetof(klr_BSETIDXC_t, c), offsetof(klr_BSETIDXC_t, a), offsetof(klr_BSETIDXC_t, n), offsetof(klr_BSETIDXC_t, v), 0}},
	{"NGETIDX", _DEF|_JIT, 3, sizeof(klr_NGETIDX_t), { VMT_RN, VMT_RO, VMT_RN, VMT_VOID}, {offsetof(klr_NGETIDX_t, c), offsetof(klr_NGETIDX_t, a), offsetof(klr_NGETIDX_t, n), 0}},
	{"NSETIDX", _DEF|_JIT, 4, sizeof(klr_NSETIDX_t), { VMT_RN, VMT_RO, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_NSETIDX_t, c), offsetof(klr_NSETIDX_t, a), offsetof(klr_NSETIDX_t, n), offsetof(klr_NSETIDX_t, v), 0}},
	{"NGETIDXC", _DEF|_JIT, 3, sizeof(klr_NGETIDXC_t), { VMT_RN, VMT_RO, VMT_U, VMT_VOID}, {offsetof(klr_NGETIDXC_t, c), offsetof(klr_NGETIDXC_t, a), offsetof(klr_NGETIDXC_t, n), 0}},
	{"NSETIDXC", _DEF|_JIT, 4, sizeof(klr_NSETIDXC_t), { VMT_RN, VMT_RO, VMT_U, VMT_RN, VMT_VOID}, {offsetof(klr_NSETIDXC_t, c), offsetof(klr_NSETIDXC_t, a), offsetof(klr_NSETIDXC_t, n), offsetof(klr_NSETIDXC_t, v), 0}},
	{"OGETIDX", _DEF|_JIT, 3, sizeof(klr_OGETIDX_t), { VMT_RO, VMT_RO, VMT_RN, VMT_VOID}, {offsetof(klr_OGETIDX_t, c), offsetof(klr_OGETIDX_t, a), offsetof(klr_OGETIDX_t, n), 0}},
	{"OSETIDX", _DEF|_JIT, 4, sizeof(klr_OSETIDX_t), { VMT_RO, VMT_RO, VMT_RN, VMT_RO, VMT_VOID}, {offsetof(klr_OSETIDX_t, c), offsetof(klr_OSETIDX_t, a), offsetof(klr_OSETIDX_t, n), offsetof(klr_OSETIDX_t, v), 0}},
	{"OGETIDXC", _DEF|_JIT, 3, sizeof(klr_OGETIDXC_t), { VMT_RO, VMT_RO, VMT_U, VMT_VOID}, {offsetof(klr_OGETIDXC_t, c), offsetof(klr_OGETIDXC_t, a), offsetof(klr_OGETIDXC_t, n), 0}},
	{"OSETIDXC", _DEF|_JIT, 4, sizeof(klr_OSETIDXC_t), { VMT_RO, VMT_RO, VMT_U, VMT_RO, VMT_VOID}, {offsetof(klr_OSETIDXC_t, c), offsetof(klr_OSETIDXC_t, a), offsetof(klr_OSETIDXC_t, n), offsetof(klr_OSETIDXC_t, v), 0}},
	{"bJNUL", _DEF|_JIT, 2, sizeof(klr_bJNUL_t), { VMT_ADDR, VMT_RO, VMT_VOID}, {offsetof(klr_bJNUL_t, jumppc), offsetof(klr_bJNUL_t, a), 0}},
	{"bJNN", _DEF|_JIT, 2, sizeof(klr_bJNN_t), { VMT_ADDR, VMT_RO, VMT_VOID}, {offsetof(klr_bJNN_t, jumppc), offsetof(klr_bJNN_t, a), 0}},
	{"bJNOT", _DEF|_JIT, 2, sizeof(klr_bJNOT_t), { VMT_ADDR, VMT_RN, VMT_VOID}, {offsetof(klr_bJNOT_t, jumppc), offsetof(klr_bJNOT_t, a), 0}},
	{"iJEQ", _DEF|_JIT, 3, sizeof(klr_iJEQ_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJEQ_t, jumppc), offsetof(klr_iJEQ_t, a), offsetof(klr_iJEQ_t, b), 0}},
	{"iJNEQ", _DEF|_JIT, 3, sizeof(klr_iJNEQ_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJNEQ_t, jumppc), offsetof(klr_iJNEQ_t, a), offsetof(klr_iJNEQ_t, b), 0}},
	{"iJLT", _DEF|_JIT, 3, sizeof(klr_iJLT_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJLT_t, jumppc), offsetof(klr_iJLT_t, a), offsetof(klr_iJLT_t, b), 0}},
	{"iJLTE", _DEF|_JIT, 3, sizeof(klr_iJLTE_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJLTE_t, jumppc), offsetof(klr_iJLTE_t, a), offsetof(klr_iJLTE_t, b), 0}},
	{"iJGT", _DEF|_JIT, 3, sizeof(klr_iJGT_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJGT_t, jumppc), offsetof(klr_iJGT_t, a), offsetof(klr_iJGT_t, b), 0}},
	{"iJGTE", _DEF|_JIT, 3, sizeof(klr_iJGTE_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_iJGTE_t, jumppc), offsetof(klr_iJGTE_t, a), offsetof(klr_iJGTE_t, b), 0}},
	{"iJEQC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJEQC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJEQC_t, jumppc), offsetof(klr_iJEQC_t, a), offsetof(klr_iJEQC_t, n), 0}},
	{"iJNEQC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJNEQC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJNEQC_t, jumppc), offsetof(klr_iJNEQC_t, a), offsetof(klr_iJNEQC_t, n), 0}},
	{"iJLTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJLTC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJLTC_t, jumppc), offsetof(klr_iJLTC_t, a), offsetof(klr_iJLTC_t, n), 0}},
	{"iJLTEC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJLTEC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJLTEC_t, jumppc), offsetof(klr_iJLTEC_t, a), offsetof(klr_iJLTEC_t, n), 0}},
	{"iJGTC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJGTC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJGTC_t, jumppc), offsetof(klr_iJGTC_t, a), offsetof(klr_iJGTC_t, n), 0}},
	{"iJGTEC", _DEF|_JIT, 3+VMTSIZE_int, sizeof(klr_iJGTEC_t), { VMT_ADDR, VMT_RN, VMT_INT VMTX_INT, VMT_VOID}, {offsetof(klr_iJGTEC_t, jumppc), offsetof(klr_iJGTEC_t, a), offsetof(klr_iJGTEC_t, n), 0}},
	{"fJEQ", _DEF|_JIT, 3, sizeof(klr_fJEQ_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJEQ_t, jumppc), offsetof(klr_fJEQ_t, a), offsetof(klr_fJEQ_t, b), 0}},
	{"fJNEQ", _DEF|_JIT, 3, sizeof(klr_fJNEQ_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJNEQ_t, jumppc), offsetof(klr_fJNEQ_t, a), offsetof(klr_fJNEQ_t, b), 0}},
	{"fJLT", _DEF|_JIT, 3, sizeof(klr_fJLT_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJLT_t, jumppc), offsetof(klr_fJLT_t, a), offsetof(klr_fJLT_t, b), 0}},
	{"fJLTE", _DEF|_JIT, 3, sizeof(klr_fJLTE_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJLTE_t, jumppc), offsetof(klr_fJLTE_t, a), offsetof(klr_fJLTE_t, b), 0}},
	{"fJGT", _DEF|_JIT, 3, sizeof(klr_fJGT_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJGT_t, jumppc), offsetof(klr_fJGT_t, a), offsetof(klr_fJGT_t, b), 0}},
	{"fJGTE", _DEF|_JIT, 3, sizeof(klr_fJGTE_t), { VMT_ADDR, VMT_RN, VMT_RN, VMT_VOID}, {offsetof(klr_fJGTE_t, jumppc), offsetof(klr_fJGTE_t, a), offsetof(klr_fJGTE_t, b), 0}},
	{"fJEQC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJEQC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJEQC_t, jumppc), offsetof(klr_fJEQC_t, a), offsetof(klr_fJEQC_t, n), 0}},
	{"fJNEQC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJNEQC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJNEQC_t, jumppc), offsetof(klr_fJNEQC_t, a), offsetof(klr_fJNEQC_t, n), 0}},
	{"fJLTC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJLTC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJLTC_t, jumppc), offsetof(klr_fJLTC_t, a), offsetof(klr_fJLTC_t, n), 0}},
	{"fJLTEC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJLTEC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJLTEC_t, jumppc), offsetof(klr_fJLTEC_t, a), offsetof(klr_fJLTEC_t, n), 0}},
	{"fJGTC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJGTC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJGTC_t, jumppc), offsetof(klr_fJGTC_t, a), offsetof(klr_fJGTC_t, n), 0}},
	{"fJGTEC", _DEF|_JIT, 3+VMTSIZE_float, sizeof(klr_fJGTEC_t), { VMT_ADDR, VMT_RN, VMT_FLOAT VMTX_FLOAT, VMT_VOID}, {offsetof(klr_fJGTEC_t, jumppc), offsetof(klr_fJGTEC_t, a), offsetof(klr_fJGTEC_t, n), 0}},
	{"CHKIDX", _JIT, 2, sizeof(klr_CHKIDX_t), { VMT_RO, VMT_RN, VMT_VOID}, {offsetof(klr_CHKIDX_t, a), offsetof(klr_CHKIDX_t, n), 0}},
	{"CHKIDXC", _JIT, 2, sizeof(klr_CHKIDXC_t), { VMT_RO, VMT_U, VMT_VOID}, {offsetof(klr_CHKIDXC_t, a), offsetof(klr_CHKIDXC_t, n), 0}},
	{"NOP", 0, 0, sizeof(klr_NOP_t), { VMT_VOID}, {0}},
};

void knh_opcode_check(void)
{
	KNH_ASSERT(sizeof(klr_HALT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_THCODE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_ENTER_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_VEXEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_YIELD_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_FUNCCALL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_TRY_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_TRYEND_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_THROW_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_ASSERT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CATCH_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CHKIN_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CHKOUT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_ERROR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_P_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_PROBE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_EXIT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSET_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NNMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSET2_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSET3_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSET4_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NMOVx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XNSET_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XNMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XNMOVx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iINC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iDEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bNUL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bNN_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bNOT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iNEG_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fNEG_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iTR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fTR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iADD_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iSUB_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iMUL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iDIV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iMOD_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iNEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iGT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iGTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iAND_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iOR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iXOR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLSFT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iRSFT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iADDC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iSUBC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iMULC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iDIVC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iMODC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iNEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iGTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iGTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iANDC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iORC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iXORC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iLSFTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iRSFTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fADD_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fSUB_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fMUL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fDIV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fNEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fLT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fLTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fGT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fGTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fADDC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fSUBC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fMULC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fDIVC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fNEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fLTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fLTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fGTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fGTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_RCINC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_RCDEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSET_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OOMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_ONMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSET2_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSET3_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSET4_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_RCINCx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_RCDECx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OMOVx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XMOV_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XOSET_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_XMOVx_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CHKSTACK_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_LDMTD_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CALL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_SCALL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_VCALL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_VCALL__t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_FASTCALL0_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_RET_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_TR_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_SCAST_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_TCAST_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_ACAST_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iCAST_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fCAST_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_SAFEPOINT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_JMP_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_JMP__t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_JMPF_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NEXT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_BGETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_BSETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_BGETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_BSETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NGETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NGETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NSETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OGETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSETIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OGETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_OSETIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bJNUL_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bJNN_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_bJNOT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJNEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJLT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJLTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJGT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJGTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJNEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJLTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJLTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJGTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_iJGTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJNEQ_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJLT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJLTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJGT_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJGTE_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJNEQC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJLTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJLTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJGTC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_fJGTEC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CHKIDX_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_CHKIDXC_t) <= sizeof(kopl_t));
	KNH_ASSERT(sizeof(klr_NOP_t) <= sizeof(kopl_t));
}

/* ------------------------------------------------------------------------ */
const char *OPCODE__(kopcode_t opcode)
{
	if(opcode < OPCODE_MAX) {
		return OPDATA[opcode].name;
	}
	else {
		DBG_P("opcode=%d", (int)opcode);
		return "OPCODE_??";
	}
}

/* ------------------------------------------------------------------------ */
size_t knh_opcode_size(kopcode_t opcode)
{
	return OPDATA[opcode].size;
}

/* ------------------------------------------------------------------------ */
size_t knh_opline_size(kopcode_t opcode)
{
	return OPDATA[opcode].struct_size;
}

/* ------------------------------------------------------------------------ */
kbool_t knh_opcode_hasjump(kopcode_t opcode)
{
	return (OPDATA[opcode].types[0] == VMT_ADDR);
}
/* ------------------------------------------------------------------------ */
kbool_t knh_opcode_usedef(kopcode_t opcode, int i)
{
	kushort_t type = OPDATA[opcode].types[i];
	if ((type == VMT_SFPIDX) || (type == VMT_R) ||
			(type == VMT_RN) || (type == VMT_RO)) {
		return 1;
	}
	return 0;
}
/* ------------------------------------------------------------------------ */
#define FIELD(T, C, n) (*(T*)&C->c[OPDATA[c->head.opcode].fields[n] - sizeof(struct KCODE_HEAD)])

kObject** knh_opline_reftrace(CTX ctx, kopl_t *c FTRARG)
{
	if(FLAG_is(OPDATA[c->head.opcode].flag, _CONST)) {
		size_t i, size = OPDATA[c->head.opcode].size;
		for(i = 0; i < size; i++) {
			kushort_t vtype = OPDATA[c->head.opcode].types[i];
			if(vtype == VMT_OBJECT || vtype == VMT_STRING) {
				KNH_ADDREF(ctx, FIELD(kObject*, c, i));
			}
		}
	}
	return tail_;
}
/* ------------------------------------------------------------------------ */

#define RBP_ASSERT0(N) do {\
	if((N % 2) != 0) {\
		DBG_P("r=%d", N); \
		DBG_ASSERT((N % 2) == 0);\
	}\
} while (0)

#define RBP_ASSERT1(N) do {\
	if((N % 2) == 0) {\
		DBG_P("r=%d", N);\
		DBG_ASSERT((N % 2) != 0);\
	}\
} while (0)

void knh_opcode_dump(CTX ctx, kopl_t *c, kOutputStream *w, kopl_t *pc_start)
{
	size_t i, size = OPDATA[c->head.opcode].size;
	const kushort_t *vmt = OPDATA[c->head.opcode].types;
	if(pc_start == NULL) {
		knh_printf(ctx, w, "[%p:%d] %s(%d)", c, c->head.line, OPCODE__(c->head.opcode), (kintptr_t)c->head.opcode);
	}
	else {
		knh_printf(ctx, w, "L%d(%d): %s(%d)", c - pc_start, c->head.line, OPCODE__(c->head.opcode), (kintptr_t)c->head.opcode);
	}
	for(i = 0; i < size; i++) {
		knh_putc(ctx, w, ' '); 
		switch(vmt[i]) {
		case VMT_VOID: break;
		case VMT_ADDR: 
			if(pc_start == NULL) {
				knh_printf(ctx, w, "%p", FIELD(void*, c, i)); break;
			}
			else {
				knh_printf(ctx, w, "L%d", FIELD(kopl_t*, c, i) - pc_start); break;
			}
		case VMT_SFPIDX2:
			knh_printf(ctx, w, "sfp[%d]", FIELD(ksfpidx_t, c, i));
			break;
		case VMT_RN: 
			RBP_ASSERT1(FIELD(kreg_t, c, i));
			if(((kintptr_t)FIELD(kreg_t, c, i)) < 0) {
				knh_printf(ctx, w, "r(%d)", (kintptr_t)FIELD(kreg_t, c, i));
			}
			else {
				knh_printf(ctx, w, "r%d", FIELD(kreg_t, c, i));
			}
			break;
		case VMT_SFX:
			RBP_ASSERT0(FIELD(kreg_t, c, i));
			knh_printf(ctx, w, "r%d(+%d)", FIELD(kreg_t, c, i), FIELD(kreg_t, c, i+1));
			break;
		case VMT_SFPIDX: 
		case VMT_RO:
			RBP_ASSERT0(FIELD(kreg_t, c, i));
		case VMT_R: 
			if(((kintptr_t)FIELD(kreg_t, c, i)) < 0) {
				knh_printf(ctx, w, "r(%d)", (kintptr_t)FIELD(kreg_t, c, i));
			}
			else {
				knh_printf(ctx, w, "r%d", FIELD(kreg_t, c, i));
			}
			break;
		case VMT_S:
			knh_write_dfmt(ctx, w, K_INTPTR_FMT, (kint_t)FIELD(kshort_t, c, i)); break;
		case VMT_U: case VMT_I:
			knh_write_dfmt(ctx, w, K_INTPTR_FMT, FIELD(kint_t, c, i)); break;
		case VMT_F:
			knh_write_vmfunc(ctx, w, FIELD(void*, c, i)); break;
		case VMT_CID:
			knh_write_cname(ctx, w, ((knh_ClassTBL_t*)c->data[i])->cid); break;
		case VMT_HCACHE: {
			kcachedata_t *hc = (kcachedata_t*)&(FIELD(kcachedata_t, c, i));
			knh_write_cname(ctx, w, hc->cid); 
			knh_putc(ctx, w, '/');
			knh_write_mn(ctx, w, hc->mn); 
		}
		break;
		case VMT_MTD: if(FIELD(void*, c, i) != NULL) {
			kMethod *mtd = FIELD(kMethod*, c, i);
			knh_write_cname(ctx, w, (mtd)->cid); knh_putc(ctx, w, '.');
			knh_write_mn(ctx, w, (mtd)->mn); 
		}
		else {
			knh_write_ascii(ctx, w, "NULL");
		}
		break;
		case VMT_TMR:
		case VMT_OBJECT:
		case VMT_STRING: {
			knh_write_Object(ctx, w, FIELD(kObject*, c, i), FMT_line);
			break;
		}
		case VMT_INT: {
			kint_t n = FIELD(kint_t, c, i);
			knh_write_ifmt(ctx, w, KINT_FMT, n); break;
		}
		case VMT_FLOAT:
			knh_write_ffmt(ctx, w, KFLOAT_FMT, FIELD(kfloat_t, c, i)); break;
		}
	}
	knh_write_EOL(ctx, w);
}

void knh_opcode_shift(kopl_t *c, int shift)
{
	size_t i, size = OPDATA[c->head.opcode].size;
	const kushort_t *vmt = OPDATA[c->head.opcode].types;
	for(i = 0; i < size; i++) {
		switch(vmt[i]) {
			case VMT_SFPIDX: case VMT_R: case VMT_RN: case VMT_RO: case VMT_SFX:
				FIELD(kreg_t, c, i) = FIELD(kreg_t, c, i) + (shift * 2); break;
			case VMT_SFPIDX2:
				FIELD(kreg_t, c, i) = FIELD(kreg_t, c, i) + (shift); break;
		}
	}
}


/* ------------------------------------------------------------------------ */
/* [exec] */


#include"../../include/konoha1/konoha_vm.h"

typedef unsigned char vmc_t;
#ifdef K_USING_VMCOUNT_
#define VMCOUNT(op)    ((op)->count)++;
#else
#define VMCOUNT(op)
#endif

//#if (defined(K_USING_LINUX_) && (defined(__i386__) || defined(__x86_64__)) && (defined(__GNUC__) && __GNUC__ >= 3))
//#define K_USING_VMASMDISPATCH 1
//#endif

#ifdef K_USING_THCODE_
#define CASE(x)  L_##x : 
#define NEXT_OP   (((kopl_t*)pc)->head.codeaddr)
#define JUMP      *(NEXT_OP)
#ifdef K_USING_VMASMDISPATCH
#define GOTO_NEXT()     \
	asm volatile("jmp *%0;": : "g"(NEXT_OP));\
	goto *(NEXT_OP)

#else
#define GOTO_NEXT()     goto *(NEXT_OP)
#endif
#define TC(c) 
#define DISPATCH_START(pc) goto *OPJUMP[((kopl_t*)pc)->head.opcode]
#define DISPATCH_END(pc)
#define GOTO_PC(pc)        GOTO_NEXT()
#else/*K_USING_THCODE_*/
#define OPJUMP      NULL
#define CASE(x)     case OPCODE_##x : 
#define NEXT_OP     L_HEAD
#define GOTO_NEXT() goto NEXT_OP
#define JUMP        L_HEAD
#define TC(c)
#define DISPATCH_START(pc) L_HEAD:;switch(((kopl_t*)pc)->head.opcode) {
#define DISPATCH_END(pc)   } KNH_DIE("unknown opcode=%d", (int)pc->head.opcode); 
#define GOTO_PC(pc)         GOTO_NEXT()
#endif/*K_USING_THCODE_*/

kopl_t* knh_VirtualMachine_run(CTX ctx, ksfp_t *sfp0, kopl_t *pc_)
{
	vmc_t *pc = (vmc_t *) pc_;
#ifdef K_USING_THCODE_
	static void *OPJUMP[] = {
		&&L_HALT, &&L_THCODE, &&L_ENTER, &&L_VEXEC, 
		&&L_YIELD, &&L_FUNCCALL, &&L_TRY, &&L_TRYEND, 
		&&L_THROW, &&L_ASSERT, &&L_CATCH, &&L_CHKIN, 
		&&L_CHKOUT, &&L_ERROR, &&L_P, &&L_PROBE, 
		&&L_EXIT, &&L_NSET, &&L_NMOV, &&L_NNMOV, 
		&&L_NSET2, &&L_NSET3, &&L_NSET4, &&L_NMOVx, 
		&&L_XNSET, &&L_XNMOV, &&L_XNMOVx, &&L_iINC, 
		&&L_iDEC, &&L_bNUL, &&L_bNN, &&L_bNOT, 
		&&L_iNEG, &&L_fNEG, &&L_iTR, &&L_fTR, 
		&&L_iADD, &&L_iSUB, &&L_iMUL, &&L_iDIV, 
		&&L_iMOD, &&L_iEQ, &&L_iNEQ, &&L_iLT, 
		&&L_iLTE, &&L_iGT, &&L_iGTE, &&L_iAND, 
		&&L_iOR, &&L_iXOR, &&L_iLSFT, &&L_iRSFT, 
		&&L_iADDC, &&L_iSUBC, &&L_iMULC, &&L_iDIVC, 
		&&L_iMODC, &&L_iEQC, &&L_iNEQC, &&L_iLTC, 
		&&L_iLTEC, &&L_iGTC, &&L_iGTEC, &&L_iANDC, 
		&&L_iORC, &&L_iXORC, &&L_iLSFTC, &&L_iRSFTC, 
		&&L_fADD, &&L_fSUB, &&L_fMUL, &&L_fDIV, 
		&&L_fEQ, &&L_fNEQ, &&L_fLT, &&L_fLTE, 
		&&L_fGT, &&L_fGTE, &&L_fADDC, &&L_fSUBC, 
		&&L_fMULC, &&L_fDIVC, &&L_fEQC, &&L_fNEQC, 
		&&L_fLTC, &&L_fLTEC, &&L_fGTC, &&L_fGTEC, 
		&&L_RCINC, &&L_RCDEC, &&L_OSET, &&L_OMOV, 
		&&L_OOMOV, &&L_ONMOV, &&L_OSET2, &&L_OSET3, 
		&&L_OSET4, &&L_RCINCx, &&L_RCDECx, &&L_OMOVx, 
		&&L_XMOV, &&L_XOSET, &&L_XMOVx, &&L_CHKSTACK, 
		&&L_LDMTD, &&L_CALL, &&L_SCALL, &&L_VCALL, 
		&&L_VCALL_, &&L_FASTCALL0, &&L_RET, &&L_TR, 
		&&L_SCAST, &&L_TCAST, &&L_ACAST, &&L_iCAST, 
		&&L_fCAST, &&L_SAFEPOINT, &&L_JMP, &&L_JMP_, 
		&&L_JMPF, &&L_NEXT, &&L_BGETIDX, &&L_BSETIDX, 
		&&L_BGETIDXC, &&L_BSETIDXC, &&L_NGETIDX, &&L_NSETIDX, 
		&&L_NGETIDXC, &&L_NSETIDXC, &&L_OGETIDX, &&L_OSETIDX, 
		&&L_OGETIDXC, &&L_OSETIDXC, &&L_bJNUL, &&L_bJNN, 
		&&L_bJNOT, &&L_iJEQ, &&L_iJNEQ, &&L_iJLT, 
		&&L_iJLTE, &&L_iJGT, &&L_iJGTE, &&L_iJEQC, 
		&&L_iJNEQC, &&L_iJLTC, &&L_iJLTEC, &&L_iJGTC, 
		&&L_iJGTEC, &&L_fJEQ, &&L_fJNEQ, &&L_fJLT, 
		&&L_fJLTE, &&L_fJGT, &&L_fJGTE, &&L_fJEQC, 
		&&L_fJNEQC, &&L_fJLTC, &&L_fJLTEC, &&L_fJGTC, 
		&&L_fJGTEC, &&L_CHKIDX, &&L_CHKIDXC, &&L_NOP, 
	};
#endif
	krbp_t *rbp = (krbp_t*)sfp0;
	USE_PROF(
	kuint64_t _utime = knh_getTime();
	static kuint64_t _UTIME[OPCODE_NOP+1] = {0};
	static size_t _UC[OPCODE_NOP+1] = {0};)
	DISPATCH_START(pc);

	CASE(HALT) {
		klr_HALT_t *op = (klr_HALT_t*)pc; (void)op;
		KLR_HALT(ctx);
		pc += sizeof(klr_HALT_t);
		GOTO_NEXT();
	} 
	CASE(THCODE) {
		klr_THCODE_t *op = (klr_THCODE_t*)pc; (void)op;
		KLR_THCODE(ctx, op->th, op->uri);
		pc += sizeof(klr_THCODE_t);
		GOTO_NEXT();
	} 
	CASE(ENTER) {
		klr_ENTER_t *op = (klr_ENTER_t*)pc; (void)op;
		KLR_ENTER(ctx);
		pc += sizeof(klr_ENTER_t);
		GOTO_NEXT();
	} 
	CASE(VEXEC) {
		klr_VEXEC_t *op = (klr_VEXEC_t*)pc; (void)op;
		KLR_VEXEC(ctx);
		pc += sizeof(klr_VEXEC_t);
		GOTO_NEXT();
	} 
	CASE(YIELD) {
		klr_YIELD_t *op = (klr_YIELD_t*)pc; (void)op;
		KLR_YIELD(ctx, op->n);
		pc += sizeof(klr_YIELD_t);
		GOTO_NEXT();
	} 
	CASE(FUNCCALL) {
		klr_FUNCCALL_t *op = (klr_FUNCCALL_t*)pc; (void)op;
		KLR_FUNCCALL(ctx);
		pc += sizeof(klr_FUNCCALL_t);
		GOTO_NEXT();
	} 
	CASE(TRY) {
		klr_TRY_t *op = (klr_TRY_t*)pc; (void)op;
		KLR_TRY(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->hn);
		pc += sizeof(klr_TRY_t);
		GOTO_NEXT();
	} 
	CASE(TRYEND) {
		klr_TRYEND_t *op = (klr_TRYEND_t*)pc; (void)op;
		KLR_TRYEND(ctx, op->hn);
		pc += sizeof(klr_TRYEND_t);
		GOTO_NEXT();
	} 
	CASE(THROW) {
		klr_THROW_t *op = (klr_THROW_t*)pc; (void)op;
		KLR_THROW(ctx, op->start);
		pc += sizeof(klr_THROW_t);
		GOTO_NEXT();
	} 
	CASE(ASSERT) {
		klr_ASSERT_t *op = (klr_ASSERT_t*)pc; (void)op;
		KLR_ASSERT(ctx, op->start, op->uline);
		pc += sizeof(klr_ASSERT_t);
		GOTO_NEXT();
	} 
	CASE(CATCH) {
		klr_CATCH_t *op = (klr_CATCH_t*)pc; (void)op;
		KLR_CATCH(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->en, op->eid);
		pc += sizeof(klr_CATCH_t);
		GOTO_NEXT();
	} 
	CASE(CHKIN) {
		klr_CHKIN_t *op = (klr_CHKIN_t*)pc; (void)op;
		KLR_CHKIN(ctx, op->on, op->checkin);
		pc += sizeof(klr_CHKIN_t);
		GOTO_NEXT();
	} 
	CASE(CHKOUT) {
		klr_CHKOUT_t *op = (klr_CHKOUT_t*)pc; (void)op;
		KLR_CHKOUT(ctx, op->on, op->checkout);
		pc += sizeof(klr_CHKOUT_t);
		GOTO_NEXT();
	} 
	CASE(ERROR) {
		klr_ERROR_t *op = (klr_ERROR_t*)pc; (void)op;
		KLR_ERROR(ctx, op->start, op->msg);
		pc += sizeof(klr_ERROR_t);
		GOTO_NEXT();
	} 
	CASE(P) {
		klr_P_t *op = (klr_P_t*)pc; (void)op;
		KLR_P(ctx, op->print, op->flag, op->n, op->msg);
		pc += sizeof(klr_P_t);
		GOTO_NEXT();
	} 
	CASE(PROBE) {
		klr_PROBE_t *op = (klr_PROBE_t*)pc; (void)op;
		KLR_PROBE(ctx, op->sfpidx, op->probe, op->n);
		pc += sizeof(klr_PROBE_t);
		GOTO_NEXT();
	} 
	CASE(EXIT) {
		klr_EXIT_t *op = (klr_EXIT_t*)pc; (void)op;
		KLR_EXIT(ctx);
		pc += sizeof(klr_EXIT_t);
		GOTO_NEXT();
	} 
	CASE(NSET) {
		klr_NSET_t *op = (klr_NSET_t*)pc; (void)op;
		KLR_NSET(ctx, op->a, op->n);
		pc += sizeof(klr_NSET_t);
		GOTO_NEXT();
	} 
	CASE(NMOV) {
		klr_NMOV_t *op = (klr_NMOV_t*)pc; (void)op;
		KLR_NMOV(ctx, op->a, op->b);
		pc += sizeof(klr_NMOV_t);
		GOTO_NEXT();
	} 
	CASE(NNMOV) {
		klr_NNMOV_t *op = (klr_NNMOV_t*)pc; (void)op;
		KLR_NNMOV(ctx, op->a, op->b, op->c, op->d);
		pc += sizeof(klr_NNMOV_t);
		GOTO_NEXT();
	} 
	CASE(NSET2) {
		klr_NSET2_t *op = (klr_NSET2_t*)pc; (void)op;
		KLR_NSET2(ctx, op->a, op->n, op->n2);
		pc += sizeof(klr_NSET2_t);
		GOTO_NEXT();
	} 
	CASE(NSET3) {
		klr_NSET3_t *op = (klr_NSET3_t*)pc; (void)op;
		KLR_NSET3(ctx, op->a, op->n, op->n2, op->n3);
		pc += sizeof(klr_NSET3_t);
		GOTO_NEXT();
	} 
	CASE(NSET4) {
		klr_NSET4_t *op = (klr_NSET4_t*)pc; (void)op;
		KLR_NSET4(ctx, op->a, op->n, op->n2, op->n3, op->n4);
		pc += sizeof(klr_NSET4_t);
		GOTO_NEXT();
	} 
	CASE(NMOVx) {
		klr_NMOVx_t *op = (klr_NMOVx_t*)pc; (void)op;
		KLR_NMOVx(ctx, op->a, op->b);
		pc += sizeof(klr_NMOVx_t);
		GOTO_NEXT();
	} 
	CASE(XNSET) {
		klr_XNSET_t *op = (klr_XNSET_t*)pc; (void)op;
		KLR_XNSET(ctx, op->a, op->b);
		pc += sizeof(klr_XNSET_t);
		GOTO_NEXT();
	} 
	CASE(XNMOV) {
		klr_XNMOV_t *op = (klr_XNMOV_t*)pc; (void)op;
		KLR_XNMOV(ctx, op->a, op->b);
		pc += sizeof(klr_XNMOV_t);
		GOTO_NEXT();
	} 
	CASE(XNMOVx) {
		klr_XNMOVx_t *op = (klr_XNMOVx_t*)pc; (void)op;
		KLR_XNMOVx(ctx, op->a, op->b);
		pc += sizeof(klr_XNMOVx_t);
		GOTO_NEXT();
	} 
	CASE(iINC) {
		klr_iINC_t *op = (klr_iINC_t*)pc; (void)op;
		KLR_iINC(ctx, op->a);
		pc += sizeof(klr_iINC_t);
		GOTO_NEXT();
	} 
	CASE(iDEC) {
		klr_iDEC_t *op = (klr_iDEC_t*)pc; (void)op;
		KLR_iDEC(ctx, op->a);
		pc += sizeof(klr_iDEC_t);
		GOTO_NEXT();
	} 
	CASE(bNUL) {
		klr_bNUL_t *op = (klr_bNUL_t*)pc; (void)op;
		KLR_bNUL(ctx, op->c, op->a);
		pc += sizeof(klr_bNUL_t);
		GOTO_NEXT();
	} 
	CASE(bNN) {
		klr_bNN_t *op = (klr_bNN_t*)pc; (void)op;
		KLR_bNN(ctx, op->c, op->a);
		pc += sizeof(klr_bNN_t);
		GOTO_NEXT();
	} 
	CASE(bNOT) {
		klr_bNOT_t *op = (klr_bNOT_t*)pc; (void)op;
		KLR_bNOT(ctx, op->c, op->a);
		pc += sizeof(klr_bNOT_t);
		GOTO_NEXT();
	} 
	CASE(iNEG) {
		klr_iNEG_t *op = (klr_iNEG_t*)pc; (void)op;
		KLR_iNEG(ctx, op->c, op->a);
		pc += sizeof(klr_iNEG_t);
		GOTO_NEXT();
	} 
	CASE(fNEG) {
		klr_fNEG_t *op = (klr_fNEG_t*)pc; (void)op;
		KLR_fNEG(ctx, op->c, op->a);
		pc += sizeof(klr_fNEG_t);
		GOTO_NEXT();
	} 
	CASE(iTR) {
		klr_iTR_t *op = (klr_iTR_t*)pc; (void)op;
		KLR_iTR(ctx, op->c, op->a, op->inttr);
		pc += sizeof(klr_iTR_t);
		GOTO_NEXT();
	} 
	CASE(fTR) {
		klr_fTR_t *op = (klr_fTR_t*)pc; (void)op;
		KLR_fTR(ctx, op->c, op->a, op->floattr);
		pc += sizeof(klr_fTR_t);
		GOTO_NEXT();
	} 
	CASE(iADD) {
		klr_iADD_t *op = (klr_iADD_t*)pc; (void)op;
		KLR_iADD(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iADD_t);
		GOTO_NEXT();
	} 
	CASE(iSUB) {
		klr_iSUB_t *op = (klr_iSUB_t*)pc; (void)op;
		KLR_iSUB(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iSUB_t);
		GOTO_NEXT();
	} 
	CASE(iMUL) {
		klr_iMUL_t *op = (klr_iMUL_t*)pc; (void)op;
		KLR_iMUL(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iMUL_t);
		GOTO_NEXT();
	} 
	CASE(iDIV) {
		klr_iDIV_t *op = (klr_iDIV_t*)pc; (void)op;
		KLR_iDIV(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iDIV_t);
		GOTO_NEXT();
	} 
	CASE(iMOD) {
		klr_iMOD_t *op = (klr_iMOD_t*)pc; (void)op;
		KLR_iMOD(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iMOD_t);
		GOTO_NEXT();
	} 
	CASE(iEQ) {
		klr_iEQ_t *op = (klr_iEQ_t*)pc; (void)op;
		KLR_iEQ(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iEQ_t);
		GOTO_NEXT();
	} 
	CASE(iNEQ) {
		klr_iNEQ_t *op = (klr_iNEQ_t*)pc; (void)op;
		KLR_iNEQ(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iNEQ_t);
		GOTO_NEXT();
	} 
	CASE(iLT) {
		klr_iLT_t *op = (klr_iLT_t*)pc; (void)op;
		KLR_iLT(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iLT_t);
		GOTO_NEXT();
	} 
	CASE(iLTE) {
		klr_iLTE_t *op = (klr_iLTE_t*)pc; (void)op;
		KLR_iLTE(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iLTE_t);
		GOTO_NEXT();
	} 
	CASE(iGT) {
		klr_iGT_t *op = (klr_iGT_t*)pc; (void)op;
		KLR_iGT(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iGT_t);
		GOTO_NEXT();
	} 
	CASE(iGTE) {
		klr_iGTE_t *op = (klr_iGTE_t*)pc; (void)op;
		KLR_iGTE(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iGTE_t);
		GOTO_NEXT();
	} 
	CASE(iAND) {
		klr_iAND_t *op = (klr_iAND_t*)pc; (void)op;
		KLR_iAND(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iAND_t);
		GOTO_NEXT();
	} 
	CASE(iOR) {
		klr_iOR_t *op = (klr_iOR_t*)pc; (void)op;
		KLR_iOR(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iOR_t);
		GOTO_NEXT();
	} 
	CASE(iXOR) {
		klr_iXOR_t *op = (klr_iXOR_t*)pc; (void)op;
		KLR_iXOR(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iXOR_t);
		GOTO_NEXT();
	} 
	CASE(iLSFT) {
		klr_iLSFT_t *op = (klr_iLSFT_t*)pc; (void)op;
		KLR_iLSFT(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_iLSFT_t);
		GOTO_NEXT();
	} 
	CASE(iRSFT) {
		klr_iRSFT_t *op = (klr_iRSFT_t*)pc; (void)op;
		KLR_iRSFT(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iRSFT_t);
		GOTO_NEXT();
	} 
	CASE(iADDC) {
		klr_iADDC_t *op = (klr_iADDC_t*)pc; (void)op;
		KLR_iADDC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iADDC_t);
		GOTO_NEXT();
	} 
	CASE(iSUBC) {
		klr_iSUBC_t *op = (klr_iSUBC_t*)pc; (void)op;
		KLR_iSUBC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iSUBC_t);
		GOTO_NEXT();
	} 
	CASE(iMULC) {
		klr_iMULC_t *op = (klr_iMULC_t*)pc; (void)op;
		KLR_iMULC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iMULC_t);
		GOTO_NEXT();
	} 
	CASE(iDIVC) {
		klr_iDIVC_t *op = (klr_iDIVC_t*)pc; (void)op;
		KLR_iDIVC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iDIVC_t);
		GOTO_NEXT();
	} 
	CASE(iMODC) {
		klr_iMODC_t *op = (klr_iMODC_t*)pc; (void)op;
		KLR_iMODC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iMODC_t);
		GOTO_NEXT();
	} 
	CASE(iEQC) {
		klr_iEQC_t *op = (klr_iEQC_t*)pc; (void)op;
		KLR_iEQC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iEQC_t);
		GOTO_NEXT();
	} 
	CASE(iNEQC) {
		klr_iNEQC_t *op = (klr_iNEQC_t*)pc; (void)op;
		KLR_iNEQC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iNEQC_t);
		GOTO_NEXT();
	} 
	CASE(iLTC) {
		klr_iLTC_t *op = (klr_iLTC_t*)pc; (void)op;
		KLR_iLTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iLTC_t);
		GOTO_NEXT();
	} 
	CASE(iLTEC) {
		klr_iLTEC_t *op = (klr_iLTEC_t*)pc; (void)op;
		KLR_iLTEC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iLTEC_t);
		GOTO_NEXT();
	} 
	CASE(iGTC) {
		klr_iGTC_t *op = (klr_iGTC_t*)pc; (void)op;
		KLR_iGTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iGTC_t);
		GOTO_NEXT();
	} 
	CASE(iGTEC) {
		klr_iGTEC_t *op = (klr_iGTEC_t*)pc; (void)op;
		KLR_iGTEC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iGTEC_t);
		GOTO_NEXT();
	} 
	CASE(iANDC) {
		klr_iANDC_t *op = (klr_iANDC_t*)pc; (void)op;
		KLR_iANDC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iANDC_t);
		GOTO_NEXT();
	} 
	CASE(iORC) {
		klr_iORC_t *op = (klr_iORC_t*)pc; (void)op;
		KLR_iORC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iORC_t);
		GOTO_NEXT();
	} 
	CASE(iXORC) {
		klr_iXORC_t *op = (klr_iXORC_t*)pc; (void)op;
		KLR_iXORC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iXORC_t);
		GOTO_NEXT();
	} 
	CASE(iLSFTC) {
		klr_iLSFTC_t *op = (klr_iLSFTC_t*)pc; (void)op;
		KLR_iLSFTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iLSFTC_t);
		GOTO_NEXT();
	} 
	CASE(iRSFTC) {
		klr_iRSFTC_t *op = (klr_iRSFTC_t*)pc; (void)op;
		KLR_iRSFTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_iRSFTC_t);
		GOTO_NEXT();
	} 
	CASE(fADD) {
		klr_fADD_t *op = (klr_fADD_t*)pc; (void)op;
		KLR_fADD(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fADD_t);
		GOTO_NEXT();
	} 
	CASE(fSUB) {
		klr_fSUB_t *op = (klr_fSUB_t*)pc; (void)op;
		KLR_fSUB(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fSUB_t);
		GOTO_NEXT();
	} 
	CASE(fMUL) {
		klr_fMUL_t *op = (klr_fMUL_t*)pc; (void)op;
		KLR_fMUL(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fMUL_t);
		GOTO_NEXT();
	} 
	CASE(fDIV) {
		klr_fDIV_t *op = (klr_fDIV_t*)pc; (void)op;
		KLR_fDIV(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fDIV_t);
		GOTO_NEXT();
	} 
	CASE(fEQ) {
		klr_fEQ_t *op = (klr_fEQ_t*)pc; (void)op;
		KLR_fEQ(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fEQ_t);
		GOTO_NEXT();
	} 
	CASE(fNEQ) {
		klr_fNEQ_t *op = (klr_fNEQ_t*)pc; (void)op;
		KLR_fNEQ(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fNEQ_t);
		GOTO_NEXT();
	} 
	CASE(fLT) {
		klr_fLT_t *op = (klr_fLT_t*)pc; (void)op;
		KLR_fLT(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fLT_t);
		GOTO_NEXT();
	} 
	CASE(fLTE) {
		klr_fLTE_t *op = (klr_fLTE_t*)pc; (void)op;
		KLR_fLTE(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fLTE_t);
		GOTO_NEXT();
	} 
	CASE(fGT) {
		klr_fGT_t *op = (klr_fGT_t*)pc; (void)op;
		KLR_fGT(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fGT_t);
		GOTO_NEXT();
	} 
	CASE(fGTE) {
		klr_fGTE_t *op = (klr_fGTE_t*)pc; (void)op;
		KLR_fGTE(ctx, op->c, op->a, op->b);
		pc += sizeof(klr_fGTE_t);
		GOTO_NEXT();
	} 
	CASE(fADDC) {
		klr_fADDC_t *op = (klr_fADDC_t*)pc; (void)op;
		KLR_fADDC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fADDC_t);
		GOTO_NEXT();
	} 
	CASE(fSUBC) {
		klr_fSUBC_t *op = (klr_fSUBC_t*)pc; (void)op;
		KLR_fSUBC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fSUBC_t);
		GOTO_NEXT();
	} 
	CASE(fMULC) {
		klr_fMULC_t *op = (klr_fMULC_t*)pc; (void)op;
		KLR_fMULC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fMULC_t);
		GOTO_NEXT();
	} 
	CASE(fDIVC) {
		klr_fDIVC_t *op = (klr_fDIVC_t*)pc; (void)op;
		KLR_fDIVC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fDIVC_t);
		GOTO_NEXT();
	} 
	CASE(fEQC) {
		klr_fEQC_t *op = (klr_fEQC_t*)pc; (void)op;
		KLR_fEQC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fEQC_t);
		GOTO_NEXT();
	} 
	CASE(fNEQC) {
		klr_fNEQC_t *op = (klr_fNEQC_t*)pc; (void)op;
		KLR_fNEQC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fNEQC_t);
		GOTO_NEXT();
	} 
	CASE(fLTC) {
		klr_fLTC_t *op = (klr_fLTC_t*)pc; (void)op;
		KLR_fLTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fLTC_t);
		GOTO_NEXT();
	} 
	CASE(fLTEC) {
		klr_fLTEC_t *op = (klr_fLTEC_t*)pc; (void)op;
		KLR_fLTEC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fLTEC_t);
		GOTO_NEXT();
	} 
	CASE(fGTC) {
		klr_fGTC_t *op = (klr_fGTC_t*)pc; (void)op;
		KLR_fGTC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fGTC_t);
		GOTO_NEXT();
	} 
	CASE(fGTEC) {
		klr_fGTEC_t *op = (klr_fGTEC_t*)pc; (void)op;
		KLR_fGTEC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_fGTEC_t);
		GOTO_NEXT();
	} 
	CASE(RCINC) {
		klr_RCINC_t *op = (klr_RCINC_t*)pc; (void)op;
		KLR_RCINC(ctx, op->a);
		pc += sizeof(klr_RCINC_t);
		GOTO_NEXT();
	} 
	CASE(RCDEC) {
		klr_RCDEC_t *op = (klr_RCDEC_t*)pc; (void)op;
		KLR_RCDEC(ctx, op->a);
		pc += sizeof(klr_RCDEC_t);
		GOTO_NEXT();
	} 
	CASE(OSET) {
		klr_OSET_t *op = (klr_OSET_t*)pc; (void)op;
		KLR_OSET(ctx, op->a, op->o);
		pc += sizeof(klr_OSET_t);
		GOTO_NEXT();
	} 
	CASE(OMOV) {
		klr_OMOV_t *op = (klr_OMOV_t*)pc; (void)op;
		KLR_OMOV(ctx, op->a, op->b);
		pc += sizeof(klr_OMOV_t);
		GOTO_NEXT();
	} 
	CASE(OOMOV) {
		klr_OOMOV_t *op = (klr_OOMOV_t*)pc; (void)op;
		KLR_OOMOV(ctx, op->a, op->b, op->c, op->d);
		pc += sizeof(klr_OOMOV_t);
		GOTO_NEXT();
	} 
	CASE(ONMOV) {
		klr_ONMOV_t *op = (klr_ONMOV_t*)pc; (void)op;
		KLR_ONMOV(ctx, op->a, op->b, op->c, op->d);
		pc += sizeof(klr_ONMOV_t);
		GOTO_NEXT();
	} 
	CASE(OSET2) {
		klr_OSET2_t *op = (klr_OSET2_t*)pc; (void)op;
		KLR_OSET2(ctx, op->a, op->v, op->v2);
		pc += sizeof(klr_OSET2_t);
		GOTO_NEXT();
	} 
	CASE(OSET3) {
		klr_OSET3_t *op = (klr_OSET3_t*)pc; (void)op;
		KLR_OSET3(ctx, op->a, op->v, op->v2, op->v3);
		pc += sizeof(klr_OSET3_t);
		GOTO_NEXT();
	} 
	CASE(OSET4) {
		klr_OSET4_t *op = (klr_OSET4_t*)pc; (void)op;
		KLR_OSET4(ctx, op->a, op->v, op->v2, op->v3, op->v4);
		pc += sizeof(klr_OSET4_t);
		GOTO_NEXT();
	} 
	CASE(RCINCx) {
		klr_RCINCx_t *op = (klr_RCINCx_t*)pc; (void)op;
		KLR_RCINCx(ctx, op->a);
		pc += sizeof(klr_RCINCx_t);
		GOTO_NEXT();
	} 
	CASE(RCDECx) {
		klr_RCDECx_t *op = (klr_RCDECx_t*)pc; (void)op;
		KLR_RCDECx(ctx, op->a);
		pc += sizeof(klr_RCDECx_t);
		GOTO_NEXT();
	} 
	CASE(OMOVx) {
		klr_OMOVx_t *op = (klr_OMOVx_t*)pc; (void)op;
		KLR_OMOVx(ctx, op->a, op->b);
		pc += sizeof(klr_OMOVx_t);
		GOTO_NEXT();
	} 
	CASE(XMOV) {
		klr_XMOV_t *op = (klr_XMOV_t*)pc; (void)op;
		KLR_XMOV(ctx, op->a, op->b);
		pc += sizeof(klr_XMOV_t);
		GOTO_NEXT();
	} 
	CASE(XOSET) {
		klr_XOSET_t *op = (klr_XOSET_t*)pc; (void)op;
		KLR_XOSET(ctx, op->a, op->b);
		pc += sizeof(klr_XOSET_t);
		GOTO_NEXT();
	} 
	CASE(XMOVx) {
		klr_XMOVx_t *op = (klr_XMOVx_t*)pc; (void)op;
		KLR_XMOVx(ctx, op->a, op->b);
		pc += sizeof(klr_XMOVx_t);
		GOTO_NEXT();
	} 
	CASE(CHKSTACK) {
		klr_CHKSTACK_t *op = (klr_CHKSTACK_t*)pc; (void)op;
		KLR_CHKSTACK(ctx, op->n);
		pc += sizeof(klr_CHKSTACK_t);
		GOTO_NEXT();
	} 
	CASE(LDMTD) {
		klr_LDMTD_t *op = (klr_LDMTD_t*)pc; (void)op;
		KLR_LDMTD(ctx, op->thisidx, op->loadmtd, op->cache, op->mtdNC);
		pc += sizeof(klr_LDMTD_t);
		GOTO_NEXT();
	} 
	CASE(CALL) {
		klr_CALL_t *op = (klr_CALL_t*)pc; (void)op;
		KLR_CALL(ctx, op->a, op->thisidx, op->espshift);
		pc += sizeof(klr_CALL_t);
		GOTO_NEXT();
	} 
	CASE(SCALL) {
		klr_SCALL_t *op = (klr_SCALL_t*)pc; (void)op;
		KLR_SCALL(ctx, op->a, op->thisidx, op->espshift, op->mtdNC);
		pc += sizeof(klr_SCALL_t);
		GOTO_NEXT();
	} 
	CASE(VCALL) {
		klr_VCALL_t *op = (klr_VCALL_t*)pc; (void)op;
		KLR_VCALL(ctx, op->a, op->thisidx, op->espshift, op->mtdNC);
		pc += sizeof(klr_VCALL_t);
		GOTO_NEXT();
	} 
	CASE(VCALL_) {
		klr_VCALL__t *op = (klr_VCALL__t*)pc; (void)op;
		KLR_VCALL_(ctx, op->a, op->thisidx, op->espshift, op->mtdNC);
		pc += sizeof(klr_VCALL__t);
		GOTO_NEXT();
	} 
	CASE(FASTCALL0) {
		klr_FASTCALL0_t *op = (klr_FASTCALL0_t*)pc; (void)op;
		KLR_FASTCALL0(ctx, op->a, op->thisidx, op->rix, op->espshift, op->fcall);
		pc += sizeof(klr_FASTCALL0_t);
		GOTO_NEXT();
	} 
	CASE(RET) {
		klr_RET_t *op = (klr_RET_t*)pc; (void)op;
		KLR_RET(ctx);
		pc += sizeof(klr_RET_t);
		GOTO_NEXT();
	} 
	CASE(TR) {
		klr_TR_t *op = (klr_TR_t*)pc; (void)op;
		KLR_TR(ctx, op->a, op->b, op->rix, op->cid, op->tr);
		pc += sizeof(klr_TR_t);
		GOTO_NEXT();
	} 
	CASE(SCAST) {
		klr_SCAST_t *op = (klr_SCAST_t*)pc; (void)op;
		KLR_SCAST(ctx, op->a, op->b, op->rix, op->espshift, op->cast);
		pc += sizeof(klr_SCAST_t);
		GOTO_NEXT();
	} 
	CASE(TCAST) {
		klr_TCAST_t *op = (klr_TCAST_t*)pc; (void)op;
		KLR_TCAST(ctx, op->a, op->b, op->rix, op->espshift, op->cast);
		pc += sizeof(klr_TCAST_t);
		GOTO_NEXT();
	} 
	CASE(ACAST) {
		klr_ACAST_t *op = (klr_ACAST_t*)pc; (void)op;
		KLR_ACAST(ctx, op->a, op->b, op->rix, op->espshift, op->cast);
		pc += sizeof(klr_ACAST_t);
		GOTO_NEXT();
	} 
	CASE(iCAST) {
		klr_iCAST_t *op = (klr_iCAST_t*)pc; (void)op;
		KLR_iCAST(ctx, op->a, op->b);
		pc += sizeof(klr_iCAST_t);
		GOTO_NEXT();
	} 
	CASE(fCAST) {
		klr_fCAST_t *op = (klr_fCAST_t*)pc; (void)op;
		KLR_fCAST(ctx, op->a, op->b);
		pc += sizeof(klr_fCAST_t);
		GOTO_NEXT();
	} 
	CASE(SAFEPOINT) {
		klr_SAFEPOINT_t *op = (klr_SAFEPOINT_t*)pc; (void)op;
		KLR_SAFEPOINT(ctx, op->espshift);
		pc += sizeof(klr_SAFEPOINT_t);
		GOTO_NEXT();
	} 
	CASE(JMP) {
		klr_JMP_t *op = (klr_JMP_t*)pc; (void)op;
		KLR_JMP(ctx, pc = (vmc_t*)op->jumppc, JUMP);
		pc += sizeof(klr_JMP_t);
		GOTO_NEXT();
	} 
	CASE(JMP_) {
		klr_JMP__t *op = (klr_JMP__t*)pc; (void)op;
		KLR_JMP_(ctx, pc = (vmc_t*)op->jumppc, JUMP);
		pc += sizeof(klr_JMP__t);
		GOTO_NEXT();
	} 
	CASE(JMPF) {
		klr_JMPF_t *op = (klr_JMPF_t*)pc; (void)op;
		KLR_JMPF(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a);
		pc += sizeof(klr_JMPF_t);
		GOTO_NEXT();
	} 
	CASE(NEXT) {
		klr_NEXT_t *op = (klr_NEXT_t*)pc; (void)op;
		KLR_NEXT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b, op->rix, op->espshift);
		pc += sizeof(klr_NEXT_t);
		GOTO_NEXT();
	} 
	CASE(BGETIDX) {
		klr_BGETIDX_t *op = (klr_BGETIDX_t*)pc; (void)op;
		KLR_BGETIDX(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_BGETIDX_t);
		GOTO_NEXT();
	} 
	CASE(BSETIDX) {
		klr_BSETIDX_t *op = (klr_BSETIDX_t*)pc; (void)op;
		KLR_BSETIDX(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_BSETIDX_t);
		GOTO_NEXT();
	} 
	CASE(BGETIDXC) {
		klr_BGETIDXC_t *op = (klr_BGETIDXC_t*)pc; (void)op;
		KLR_BGETIDXC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_BGETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(BSETIDXC) {
		klr_BSETIDXC_t *op = (klr_BSETIDXC_t*)pc; (void)op;
		KLR_BSETIDXC(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_BSETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(NGETIDX) {
		klr_NGETIDX_t *op = (klr_NGETIDX_t*)pc; (void)op;
		KLR_NGETIDX(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_NGETIDX_t);
		GOTO_NEXT();
	} 
	CASE(NSETIDX) {
		klr_NSETIDX_t *op = (klr_NSETIDX_t*)pc; (void)op;
		KLR_NSETIDX(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_NSETIDX_t);
		GOTO_NEXT();
	} 
	CASE(NGETIDXC) {
		klr_NGETIDXC_t *op = (klr_NGETIDXC_t*)pc; (void)op;
		KLR_NGETIDXC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_NGETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(NSETIDXC) {
		klr_NSETIDXC_t *op = (klr_NSETIDXC_t*)pc; (void)op;
		KLR_NSETIDXC(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_NSETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(OGETIDX) {
		klr_OGETIDX_t *op = (klr_OGETIDX_t*)pc; (void)op;
		KLR_OGETIDX(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_OGETIDX_t);
		GOTO_NEXT();
	} 
	CASE(OSETIDX) {
		klr_OSETIDX_t *op = (klr_OSETIDX_t*)pc; (void)op;
		KLR_OSETIDX(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_OSETIDX_t);
		GOTO_NEXT();
	} 
	CASE(OGETIDXC) {
		klr_OGETIDXC_t *op = (klr_OGETIDXC_t*)pc; (void)op;
		KLR_OGETIDXC(ctx, op->c, op->a, op->n);
		pc += sizeof(klr_OGETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(OSETIDXC) {
		klr_OSETIDXC_t *op = (klr_OSETIDXC_t*)pc; (void)op;
		KLR_OSETIDXC(ctx, op->c, op->a, op->n, op->v);
		pc += sizeof(klr_OSETIDXC_t);
		GOTO_NEXT();
	} 
	CASE(bJNUL) {
		klr_bJNUL_t *op = (klr_bJNUL_t*)pc; (void)op;
		KLR_bJNUL(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a);
		pc += sizeof(klr_bJNUL_t);
		GOTO_NEXT();
	} 
	CASE(bJNN) {
		klr_bJNN_t *op = (klr_bJNN_t*)pc; (void)op;
		KLR_bJNN(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a);
		pc += sizeof(klr_bJNN_t);
		GOTO_NEXT();
	} 
	CASE(bJNOT) {
		klr_bJNOT_t *op = (klr_bJNOT_t*)pc; (void)op;
		KLR_bJNOT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a);
		pc += sizeof(klr_bJNOT_t);
		GOTO_NEXT();
	} 
	CASE(iJEQ) {
		klr_iJEQ_t *op = (klr_iJEQ_t*)pc; (void)op;
		KLR_iJEQ(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJEQ_t);
		GOTO_NEXT();
	} 
	CASE(iJNEQ) {
		klr_iJNEQ_t *op = (klr_iJNEQ_t*)pc; (void)op;
		KLR_iJNEQ(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJNEQ_t);
		GOTO_NEXT();
	} 
	CASE(iJLT) {
		klr_iJLT_t *op = (klr_iJLT_t*)pc; (void)op;
		KLR_iJLT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJLT_t);
		GOTO_NEXT();
	} 
	CASE(iJLTE) {
		klr_iJLTE_t *op = (klr_iJLTE_t*)pc; (void)op;
		KLR_iJLTE(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJLTE_t);
		GOTO_NEXT();
	} 
	CASE(iJGT) {
		klr_iJGT_t *op = (klr_iJGT_t*)pc; (void)op;
		KLR_iJGT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJGT_t);
		GOTO_NEXT();
	} 
	CASE(iJGTE) {
		klr_iJGTE_t *op = (klr_iJGTE_t*)pc; (void)op;
		KLR_iJGTE(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_iJGTE_t);
		GOTO_NEXT();
	} 
	CASE(iJEQC) {
		klr_iJEQC_t *op = (klr_iJEQC_t*)pc; (void)op;
		KLR_iJEQC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJEQC_t);
		GOTO_NEXT();
	} 
	CASE(iJNEQC) {
		klr_iJNEQC_t *op = (klr_iJNEQC_t*)pc; (void)op;
		KLR_iJNEQC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJNEQC_t);
		GOTO_NEXT();
	} 
	CASE(iJLTC) {
		klr_iJLTC_t *op = (klr_iJLTC_t*)pc; (void)op;
		KLR_iJLTC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJLTC_t);
		GOTO_NEXT();
	} 
	CASE(iJLTEC) {
		klr_iJLTEC_t *op = (klr_iJLTEC_t*)pc; (void)op;
		KLR_iJLTEC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJLTEC_t);
		GOTO_NEXT();
	} 
	CASE(iJGTC) {
		klr_iJGTC_t *op = (klr_iJGTC_t*)pc; (void)op;
		KLR_iJGTC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJGTC_t);
		GOTO_NEXT();
	} 
	CASE(iJGTEC) {
		klr_iJGTEC_t *op = (klr_iJGTEC_t*)pc; (void)op;
		KLR_iJGTEC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_iJGTEC_t);
		GOTO_NEXT();
	} 
	CASE(fJEQ) {
		klr_fJEQ_t *op = (klr_fJEQ_t*)pc; (void)op;
		KLR_fJEQ(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJEQ_t);
		GOTO_NEXT();
	} 
	CASE(fJNEQ) {
		klr_fJNEQ_t *op = (klr_fJNEQ_t*)pc; (void)op;
		KLR_fJNEQ(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJNEQ_t);
		GOTO_NEXT();
	} 
	CASE(fJLT) {
		klr_fJLT_t *op = (klr_fJLT_t*)pc; (void)op;
		KLR_fJLT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJLT_t);
		GOTO_NEXT();
	} 
	CASE(fJLTE) {
		klr_fJLTE_t *op = (klr_fJLTE_t*)pc; (void)op;
		KLR_fJLTE(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJLTE_t);
		GOTO_NEXT();
	} 
	CASE(fJGT) {
		klr_fJGT_t *op = (klr_fJGT_t*)pc; (void)op;
		KLR_fJGT(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJGT_t);
		GOTO_NEXT();
	} 
	CASE(fJGTE) {
		klr_fJGTE_t *op = (klr_fJGTE_t*)pc; (void)op;
		KLR_fJGTE(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->b);
		pc += sizeof(klr_fJGTE_t);
		GOTO_NEXT();
	} 
	CASE(fJEQC) {
		klr_fJEQC_t *op = (klr_fJEQC_t*)pc; (void)op;
		KLR_fJEQC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJEQC_t);
		GOTO_NEXT();
	} 
	CASE(fJNEQC) {
		klr_fJNEQC_t *op = (klr_fJNEQC_t*)pc; (void)op;
		KLR_fJNEQC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJNEQC_t);
		GOTO_NEXT();
	} 
	CASE(fJLTC) {
		klr_fJLTC_t *op = (klr_fJLTC_t*)pc; (void)op;
		KLR_fJLTC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJLTC_t);
		GOTO_NEXT();
	} 
	CASE(fJLTEC) {
		klr_fJLTEC_t *op = (klr_fJLTEC_t*)pc; (void)op;
		KLR_fJLTEC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJLTEC_t);
		GOTO_NEXT();
	} 
	CASE(fJGTC) {
		klr_fJGTC_t *op = (klr_fJGTC_t*)pc; (void)op;
		KLR_fJGTC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJGTC_t);
		GOTO_NEXT();
	} 
	CASE(fJGTEC) {
		klr_fJGTEC_t *op = (klr_fJGTEC_t*)pc; (void)op;
		KLR_fJGTEC(ctx, pc = (vmc_t*)op->jumppc, JUMP, op->a, op->n);
		pc += sizeof(klr_fJGTEC_t);
		GOTO_NEXT();
	} 
	CASE(CHKIDX) {
		klr_CHKIDX_t *op = (klr_CHKIDX_t*)pc; (void)op;
		KLR_CHKIDX(ctx, op->a, op->n);
		pc += sizeof(klr_CHKIDX_t);
		GOTO_NEXT();
	} 
	CASE(CHKIDXC) {
		klr_CHKIDXC_t *op = (klr_CHKIDXC_t*)pc; (void)op;
		KLR_CHKIDXC(ctx, op->a, op->n);
		pc += sizeof(klr_CHKIDXC_t);
		GOTO_NEXT();
	} 
	CASE(NOP) {
		klr_NOP_t *op = (klr_NOP_t*)pc; (void)op;
		KLR_NOP(ctx);
		pc += sizeof(klr_NOP_t);
		GOTO_NEXT();
	} 
	DISPATCH_END(pc);
	L_RETURN:;
	return (kopl_t*) pc;
}


#ifdef __cplusplus
}
#endif
