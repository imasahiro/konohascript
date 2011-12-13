#ifndef KONOHA_CODE_H_
#define KONOHA_CODE_H_
// THIS FILE WAS AUTOMATICALLY GENERATED

//#include "konoha_vm.h"


#define OPCODE_HALT ((kopcode_t)0)
typedef struct klr_HALT_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_HALT_t;

#define OPCODE_THCODE ((kopcode_t)1)
typedef struct klr_THCODE_t {
	struct KCODE_HEAD head;
	klr_Fth th;
	kuintptr_t uri;
}  __attribute__ ((__aligned__(32))) klr_THCODE_t;

#define OPCODE_ENTER ((kopcode_t)2)
typedef struct klr_ENTER_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_ENTER_t;

#define OPCODE_VEXEC ((kopcode_t)3)
typedef struct klr_VEXEC_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_VEXEC_t;

#define OPCODE_YIELD ((kopcode_t)4)
typedef struct klr_YIELD_t {
	struct KCODE_HEAD head;
	ksfpidx_t n;
}  __attribute__ ((__aligned__(32))) klr_YIELD_t;

#define OPCODE_FUNCCALL ((kopcode_t)5)
typedef struct klr_FUNCCALL_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_FUNCCALL_t;

#define OPCODE_TRY ((kopcode_t)6)
typedef struct klr_TRY_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregO_t hn;
}  __attribute__ ((__aligned__(32))) klr_TRY_t;

#define OPCODE_TRYEND ((kopcode_t)7)
typedef struct klr_TRYEND_t {
	struct KCODE_HEAD head;
	kregO_t hn;
}  __attribute__ ((__aligned__(32))) klr_TRYEND_t;

#define OPCODE_THROW ((kopcode_t)8)
typedef struct klr_THROW_t {
	struct KCODE_HEAD head;
	ksfpidx_t start;
}  __attribute__ ((__aligned__(32))) klr_THROW_t;

#define OPCODE_ASSERT ((kopcode_t)9)
typedef struct klr_ASSERT_t {
	struct KCODE_HEAD head;
	ksfpidx_t start;
	kuintptr_t uline;
}  __attribute__ ((__aligned__(32))) klr_ASSERT_t;

#define OPCODE_CATCH ((kopcode_t)10)
typedef struct klr_CATCH_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregO_t en;
	kint_t eid;
}  __attribute__ ((__aligned__(32))) klr_CATCH_t;

#define OPCODE_CHKIN ((kopcode_t)11)
typedef struct klr_CHKIN_t {
	struct KCODE_HEAD head;
	kregO_t on;
	klr_Fcheckin checkin;
}  __attribute__ ((__aligned__(32))) klr_CHKIN_t;

#define OPCODE_CHKOUT ((kopcode_t)12)
typedef struct klr_CHKOUT_t {
	struct KCODE_HEAD head;
	kregO_t on;
	klr_Fcheckout checkout;
}  __attribute__ ((__aligned__(32))) klr_CHKOUT_t;

#define OPCODE_ERROR ((kopcode_t)13)
typedef struct klr_ERROR_t {
	struct KCODE_HEAD head;
	ksfpidx_t start;
	kString* msg;
}  __attribute__ ((__aligned__(32))) klr_ERROR_t;

#define OPCODE_P ((kopcode_t)14)
typedef struct klr_P_t {
	struct KCODE_HEAD head;
	klr_Fprint print;
	kshort_t flag;
	ksfpidx_t n;
	kString* msg;
}  __attribute__ ((__aligned__(32))) klr_P_t;

#define OPCODE_PROBE ((kopcode_t)15)
typedef struct klr_PROBE_t {
	struct KCODE_HEAD head;
	ksfpidx_t sfpidx;
	klr_Fprobe probe;
	kuintptr_t n;
}  __attribute__ ((__aligned__(32))) klr_PROBE_t;

#define OPCODE_EXIT ((kopcode_t)16)
typedef struct klr_EXIT_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_EXIT_t;

#define OPCODE_NSET ((kopcode_t)17)
typedef struct klr_NSET_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_NSET_t;

#define OPCODE_NMOV ((kopcode_t)18)
typedef struct klr_NMOV_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_NMOV_t;

#define OPCODE_NNMOV ((kopcode_t)19)
typedef struct klr_NNMOV_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kregN_t b;
	kregN_t c;
	kregN_t d;
}  __attribute__ ((__aligned__(32))) klr_NNMOV_t;

#define OPCODE_NSET2 ((kopcode_t)20)
typedef struct klr_NSET2_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kint_t n;
	kint_t n2;
}  __attribute__ ((__aligned__(32))) klr_NSET2_t;

#define OPCODE_NSET3 ((kopcode_t)21)
typedef struct klr_NSET3_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kuintptr_t n;
	kuintptr_t n2;
	kuintptr_t n3;
}  __attribute__ ((__aligned__(32))) klr_NSET3_t;

#define OPCODE_NSET4 ((kopcode_t)22)
typedef struct klr_NSET4_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kuintptr_t n;
	kuintptr_t n2;
	kuintptr_t n3;
	kuintptr_t n4;
}  __attribute__ ((__aligned__(32))) klr_NSET4_t;

#define OPCODE_NMOVx ((kopcode_t)23)
typedef struct klr_NMOVx_t {
	struct KCODE_HEAD head;
	kregN_t a;
	ksfx_t b;
}  __attribute__ ((__aligned__(32))) klr_NMOVx_t;

#define OPCODE_XNSET ((kopcode_t)24)
typedef struct klr_XNSET_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	kint_t b;
}  __attribute__ ((__aligned__(32))) klr_XNSET_t;

#define OPCODE_XNMOV ((kopcode_t)25)
typedef struct klr_XNMOV_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_XNMOV_t;

#define OPCODE_XNMOVx ((kopcode_t)26)
typedef struct klr_XNMOVx_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	ksfx_t b;
}  __attribute__ ((__aligned__(32))) klr_XNMOVx_t;

#define OPCODE_iINC ((kopcode_t)27)
typedef struct klr_iINC_t {
	struct KCODE_HEAD head;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_iINC_t;

#define OPCODE_iDEC ((kopcode_t)28)
typedef struct klr_iDEC_t {
	struct KCODE_HEAD head;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_iDEC_t;

#define OPCODE_bNUL ((kopcode_t)29)
typedef struct klr_bNUL_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_bNUL_t;

#define OPCODE_bNN ((kopcode_t)30)
typedef struct klr_bNN_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_bNN_t;

#define OPCODE_bNOT ((kopcode_t)31)
typedef struct klr_bNOT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_bNOT_t;

#define OPCODE_iNEG ((kopcode_t)32)
typedef struct klr_iNEG_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_iNEG_t;

#define OPCODE_fNEG ((kopcode_t)33)
typedef struct klr_fNEG_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_fNEG_t;

#define OPCODE_iTR ((kopcode_t)34)
typedef struct klr_iTR_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	klr_Finttr inttr;
}  __attribute__ ((__aligned__(32))) klr_iTR_t;

#define OPCODE_fTR ((kopcode_t)35)
typedef struct klr_fTR_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	klr_Ffloattr floattr;
}  __attribute__ ((__aligned__(32))) klr_fTR_t;

#define OPCODE_iADD ((kopcode_t)36)
typedef struct klr_iADD_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iADD_t;

#define OPCODE_iSUB ((kopcode_t)37)
typedef struct klr_iSUB_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iSUB_t;

#define OPCODE_iMUL ((kopcode_t)38)
typedef struct klr_iMUL_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iMUL_t;

#define OPCODE_iDIV ((kopcode_t)39)
typedef struct klr_iDIV_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iDIV_t;

#define OPCODE_iMOD ((kopcode_t)40)
typedef struct klr_iMOD_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iMOD_t;

#define OPCODE_iEQ ((kopcode_t)41)
typedef struct klr_iEQ_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iEQ_t;

#define OPCODE_iNEQ ((kopcode_t)42)
typedef struct klr_iNEQ_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iNEQ_t;

#define OPCODE_iLT ((kopcode_t)43)
typedef struct klr_iLT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iLT_t;

#define OPCODE_iLTE ((kopcode_t)44)
typedef struct klr_iLTE_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iLTE_t;

#define OPCODE_iGT ((kopcode_t)45)
typedef struct klr_iGT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iGT_t;

#define OPCODE_iGTE ((kopcode_t)46)
typedef struct klr_iGTE_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iGTE_t;

#define OPCODE_iAND ((kopcode_t)47)
typedef struct klr_iAND_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iAND_t;

#define OPCODE_iOR ((kopcode_t)48)
typedef struct klr_iOR_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iOR_t;

#define OPCODE_iXOR ((kopcode_t)49)
typedef struct klr_iXOR_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iXOR_t;

#define OPCODE_iLSFT ((kopcode_t)50)
typedef struct klr_iLSFT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iLSFT_t;

#define OPCODE_iRSFT ((kopcode_t)51)
typedef struct klr_iRSFT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t n;
}  __attribute__ ((__aligned__(32))) klr_iRSFT_t;

#define OPCODE_iADDC ((kopcode_t)52)
typedef struct klr_iADDC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iADDC_t;

#define OPCODE_iSUBC ((kopcode_t)53)
typedef struct klr_iSUBC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iSUBC_t;

#define OPCODE_iMULC ((kopcode_t)54)
typedef struct klr_iMULC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iMULC_t;

#define OPCODE_iDIVC ((kopcode_t)55)
typedef struct klr_iDIVC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iDIVC_t;

#define OPCODE_iMODC ((kopcode_t)56)
typedef struct klr_iMODC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iMODC_t;

#define OPCODE_iEQC ((kopcode_t)57)
typedef struct klr_iEQC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iEQC_t;

#define OPCODE_iNEQC ((kopcode_t)58)
typedef struct klr_iNEQC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iNEQC_t;

#define OPCODE_iLTC ((kopcode_t)59)
typedef struct klr_iLTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iLTC_t;

#define OPCODE_iLTEC ((kopcode_t)60)
typedef struct klr_iLTEC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iLTEC_t;

#define OPCODE_iGTC ((kopcode_t)61)
typedef struct klr_iGTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iGTC_t;

#define OPCODE_iGTEC ((kopcode_t)62)
typedef struct klr_iGTEC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iGTEC_t;

#define OPCODE_iANDC ((kopcode_t)63)
typedef struct klr_iANDC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iANDC_t;

#define OPCODE_iORC ((kopcode_t)64)
typedef struct klr_iORC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iORC_t;

#define OPCODE_iXORC ((kopcode_t)65)
typedef struct klr_iXORC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iXORC_t;

#define OPCODE_iLSFTC ((kopcode_t)66)
typedef struct klr_iLSFTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iLSFTC_t;

#define OPCODE_iRSFTC ((kopcode_t)67)
typedef struct klr_iRSFTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iRSFTC_t;

#define OPCODE_fADD ((kopcode_t)68)
typedef struct klr_fADD_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fADD_t;

#define OPCODE_fSUB ((kopcode_t)69)
typedef struct klr_fSUB_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fSUB_t;

#define OPCODE_fMUL ((kopcode_t)70)
typedef struct klr_fMUL_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fMUL_t;

#define OPCODE_fDIV ((kopcode_t)71)
typedef struct klr_fDIV_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fDIV_t;

#define OPCODE_fEQ ((kopcode_t)72)
typedef struct klr_fEQ_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fEQ_t;

#define OPCODE_fNEQ ((kopcode_t)73)
typedef struct klr_fNEQ_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fNEQ_t;

#define OPCODE_fLT ((kopcode_t)74)
typedef struct klr_fLT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fLT_t;

#define OPCODE_fLTE ((kopcode_t)75)
typedef struct klr_fLTE_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fLTE_t;

#define OPCODE_fGT ((kopcode_t)76)
typedef struct klr_fGT_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fGT_t;

#define OPCODE_fGTE ((kopcode_t)77)
typedef struct klr_fGTE_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fGTE_t;

#define OPCODE_fADDC ((kopcode_t)78)
typedef struct klr_fADDC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fADDC_t;

#define OPCODE_fSUBC ((kopcode_t)79)
typedef struct klr_fSUBC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fSUBC_t;

#define OPCODE_fMULC ((kopcode_t)80)
typedef struct klr_fMULC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fMULC_t;

#define OPCODE_fDIVC ((kopcode_t)81)
typedef struct klr_fDIVC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fDIVC_t;

#define OPCODE_fEQC ((kopcode_t)82)
typedef struct klr_fEQC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fEQC_t;

#define OPCODE_fNEQC ((kopcode_t)83)
typedef struct klr_fNEQC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fNEQC_t;

#define OPCODE_fLTC ((kopcode_t)84)
typedef struct klr_fLTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fLTC_t;

#define OPCODE_fLTEC ((kopcode_t)85)
typedef struct klr_fLTEC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fLTEC_t;

#define OPCODE_fGTC ((kopcode_t)86)
typedef struct klr_fGTC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fGTC_t;

#define OPCODE_fGTEC ((kopcode_t)87)
typedef struct klr_fGTEC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fGTEC_t;

#define OPCODE_RCINC ((kopcode_t)88)
typedef struct klr_RCINC_t {
	struct KCODE_HEAD head;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_RCINC_t;

#define OPCODE_RCDEC ((kopcode_t)89)
typedef struct klr_RCDEC_t {
	struct KCODE_HEAD head;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_RCDEC_t;

#define OPCODE_OSET ((kopcode_t)90)
typedef struct klr_OSET_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kObject* o;
}  __attribute__ ((__aligned__(32))) klr_OSET_t;

#define OPCODE_OMOV ((kopcode_t)91)
typedef struct klr_OMOV_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kregO_t b;
}  __attribute__ ((__aligned__(32))) klr_OMOV_t;

#define OPCODE_OOMOV ((kopcode_t)92)
typedef struct klr_OOMOV_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kregO_t b;
	kregO_t c;
	kregO_t d;
}  __attribute__ ((__aligned__(32))) klr_OOMOV_t;

#define OPCODE_ONMOV ((kopcode_t)93)
typedef struct klr_ONMOV_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kregO_t b;
	kregN_t c;
	kregN_t d;
}  __attribute__ ((__aligned__(32))) klr_ONMOV_t;

#define OPCODE_OSET2 ((kopcode_t)94)
typedef struct klr_OSET2_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kObject* v;
	kObject* v2;
}  __attribute__ ((__aligned__(32))) klr_OSET2_t;

#define OPCODE_OSET3 ((kopcode_t)95)
typedef struct klr_OSET3_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kObject* v;
	kObject* v2;
	kObject* v3;
}  __attribute__ ((__aligned__(32))) klr_OSET3_t;

#define OPCODE_OSET4 ((kopcode_t)96)
typedef struct klr_OSET4_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kObject* v;
	kObject* v2;
	kObject* v3;
	kObject* v4;
}  __attribute__ ((__aligned__(32))) klr_OSET4_t;

#define OPCODE_RCINCx ((kopcode_t)97)
typedef struct klr_RCINCx_t {
	struct KCODE_HEAD head;
	ksfx_t a;
}  __attribute__ ((__aligned__(32))) klr_RCINCx_t;

#define OPCODE_RCDECx ((kopcode_t)98)
typedef struct klr_RCDECx_t {
	struct KCODE_HEAD head;
	ksfx_t a;
}  __attribute__ ((__aligned__(32))) klr_RCDECx_t;

#define OPCODE_OMOVx ((kopcode_t)99)
typedef struct klr_OMOVx_t {
	struct KCODE_HEAD head;
	kregO_t a;
	ksfx_t b;
}  __attribute__ ((__aligned__(32))) klr_OMOVx_t;

#define OPCODE_XMOV ((kopcode_t)100)
typedef struct klr_XMOV_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	kregO_t b;
}  __attribute__ ((__aligned__(32))) klr_XMOV_t;

#define OPCODE_XOSET ((kopcode_t)101)
typedef struct klr_XOSET_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	kObject* b;
}  __attribute__ ((__aligned__(32))) klr_XOSET_t;

#define OPCODE_XMOVx ((kopcode_t)102)
typedef struct klr_XMOVx_t {
	struct KCODE_HEAD head;
	ksfx_t a;
	ksfx_t b;
}  __attribute__ ((__aligned__(32))) klr_XMOVx_t;

#define OPCODE_CHKSTACK ((kopcode_t)103)
typedef struct klr_CHKSTACK_t {
	struct KCODE_HEAD head;
	ksfpidx_t n;
}  __attribute__ ((__aligned__(32))) klr_CHKSTACK_t;

#define OPCODE_LDMTD ((kopcode_t)104)
typedef struct klr_LDMTD_t {
	struct KCODE_HEAD head;
	ksfpidx_t thisidx;
	klr_Floadmtd loadmtd;
	kcachedata_t cache;
	kMethod* mtdNC;
}  __attribute__ ((__aligned__(32))) klr_LDMTD_t;

#define OPCODE_CALL ((kopcode_t)105)
typedef struct klr_CALL_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t thisidx;
	ksfpidx_t espshift;
}  __attribute__ ((__aligned__(32))) klr_CALL_t;

#define OPCODE_SCALL ((kopcode_t)106)
typedef struct klr_SCALL_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t thisidx;
	ksfpidx_t espshift;
	kMethod* mtdNC;
}  __attribute__ ((__aligned__(32))) klr_SCALL_t;

#define OPCODE_VCALL ((kopcode_t)107)
typedef struct klr_VCALL_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t thisidx;
	ksfpidx_t espshift;
	kMethod* mtdNC;
}  __attribute__ ((__aligned__(32))) klr_VCALL_t;

#define OPCODE_VCALL_ ((kopcode_t)108)
typedef struct klr_VCALL__t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t thisidx;
	ksfpidx_t espshift;
	kMethod* mtdNC;
}  __attribute__ ((__aligned__(32))) klr_VCALL__t;

#define OPCODE_FASTCALL0 ((kopcode_t)109)
typedef struct klr_FASTCALL0_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t thisidx;
	kshort_t rix;
	ksfpidx_t espshift;
	klr_Ffcall fcall;
}  __attribute__ ((__aligned__(32))) klr_FASTCALL0_t;

#define OPCODE_RET ((kopcode_t)110)
typedef struct klr_RET_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_RET_t;

#define OPCODE_TR ((kopcode_t)111)
typedef struct klr_TR_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t b;
	kshort_t rix;
	const knh_ClassTBL_t* cid;
	klr_Ftr tr;
}  __attribute__ ((__aligned__(32))) klr_TR_t;

#define OPCODE_SCAST ((kopcode_t)112)
typedef struct klr_SCAST_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t b;
	kshort_t rix;
	ksfpidx_t espshift;
	kTypeMap* cast;
}  __attribute__ ((__aligned__(32))) klr_SCAST_t;

#define OPCODE_TCAST ((kopcode_t)113)
typedef struct klr_TCAST_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t b;
	kshort_t rix;
	ksfpidx_t espshift;
	kTypeMap* cast;
}  __attribute__ ((__aligned__(32))) klr_TCAST_t;

#define OPCODE_ACAST ((kopcode_t)114)
typedef struct klr_ACAST_t {
	struct KCODE_HEAD head;
	kreg_t a;
	ksfpidx_t b;
	kshort_t rix;
	ksfpidx_t espshift;
	kTypeMap* cast;
}  __attribute__ ((__aligned__(32))) klr_ACAST_t;

#define OPCODE_iCAST ((kopcode_t)115)
typedef struct klr_iCAST_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iCAST_t;

#define OPCODE_fCAST ((kopcode_t)116)
typedef struct klr_fCAST_t {
	struct KCODE_HEAD head;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fCAST_t;

#define OPCODE_SAFEPOINT ((kopcode_t)117)
typedef struct klr_SAFEPOINT_t {
	struct KCODE_HEAD head;
	ksfpidx_t espshift;
}  __attribute__ ((__aligned__(32))) klr_SAFEPOINT_t;

#define OPCODE_JMP ((kopcode_t)118)
typedef struct klr_JMP_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
}  __attribute__ ((__aligned__(32))) klr_JMP_t;

#define OPCODE_JMP_ ((kopcode_t)119)
typedef struct klr_JMP__t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
}  __attribute__ ((__aligned__(32))) klr_JMP__t;

#define OPCODE_JMPF ((kopcode_t)120)
typedef struct klr_JMPF_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_JMPF_t;

#define OPCODE_NEXT ((kopcode_t)121)
typedef struct klr_NEXT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kreg_t a;
	ksfpidx_t b;
	kshort_t rix;
	ksfpidx_t espshift;
}  __attribute__ ((__aligned__(32))) klr_NEXT_t;

#define OPCODE_BGETIDX ((kopcode_t)122)
typedef struct klr_BGETIDX_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kregN_t n;
}  __attribute__ ((__aligned__(32))) klr_BGETIDX_t;

#define OPCODE_BSETIDX ((kopcode_t)123)
typedef struct klr_BSETIDX_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kregN_t n;
	kregN_t v;
}  __attribute__ ((__aligned__(32))) klr_BSETIDX_t;

#define OPCODE_BGETIDXC ((kopcode_t)124)
typedef struct klr_BGETIDXC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kuintptr_t n;
}  __attribute__ ((__aligned__(32))) klr_BGETIDXC_t;

#define OPCODE_BSETIDXC ((kopcode_t)125)
typedef struct klr_BSETIDXC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kuintptr_t n;
	kregN_t v;
}  __attribute__ ((__aligned__(32))) klr_BSETIDXC_t;

#define OPCODE_NGETIDX ((kopcode_t)126)
typedef struct klr_NGETIDX_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kregN_t n;
}  __attribute__ ((__aligned__(32))) klr_NGETIDX_t;

#define OPCODE_NSETIDX ((kopcode_t)127)
typedef struct klr_NSETIDX_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kregN_t n;
	kregN_t v;
}  __attribute__ ((__aligned__(32))) klr_NSETIDX_t;

#define OPCODE_NGETIDXC ((kopcode_t)128)
typedef struct klr_NGETIDXC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kuintptr_t n;
}  __attribute__ ((__aligned__(32))) klr_NGETIDXC_t;

#define OPCODE_NSETIDXC ((kopcode_t)129)
typedef struct klr_NSETIDXC_t {
	struct KCODE_HEAD head;
	kregN_t c;
	kregO_t a;
	kuintptr_t n;
	kregN_t v;
}  __attribute__ ((__aligned__(32))) klr_NSETIDXC_t;

#define OPCODE_OGETIDX ((kopcode_t)130)
typedef struct klr_OGETIDX_t {
	struct KCODE_HEAD head;
	kregO_t c;
	kregO_t a;
	kregN_t n;
}  __attribute__ ((__aligned__(32))) klr_OGETIDX_t;

#define OPCODE_OSETIDX ((kopcode_t)131)
typedef struct klr_OSETIDX_t {
	struct KCODE_HEAD head;
	kregO_t c;
	kregO_t a;
	kregN_t n;
	kregO_t v;
}  __attribute__ ((__aligned__(32))) klr_OSETIDX_t;

#define OPCODE_OGETIDXC ((kopcode_t)132)
typedef struct klr_OGETIDXC_t {
	struct KCODE_HEAD head;
	kregO_t c;
	kregO_t a;
	kuintptr_t n;
}  __attribute__ ((__aligned__(32))) klr_OGETIDXC_t;

#define OPCODE_OSETIDXC ((kopcode_t)133)
typedef struct klr_OSETIDXC_t {
	struct KCODE_HEAD head;
	kregO_t c;
	kregO_t a;
	kuintptr_t n;
	kregO_t v;
}  __attribute__ ((__aligned__(32))) klr_OSETIDXC_t;

#define OPCODE_bJNUL ((kopcode_t)134)
typedef struct klr_bJNUL_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_bJNUL_t;

#define OPCODE_bJNN ((kopcode_t)135)
typedef struct klr_bJNN_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregO_t a;
}  __attribute__ ((__aligned__(32))) klr_bJNN_t;

#define OPCODE_bJNOT ((kopcode_t)136)
typedef struct klr_bJNOT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
}  __attribute__ ((__aligned__(32))) klr_bJNOT_t;

#define OPCODE_iJEQ ((kopcode_t)137)
typedef struct klr_iJEQ_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJEQ_t;

#define OPCODE_iJNEQ ((kopcode_t)138)
typedef struct klr_iJNEQ_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJNEQ_t;

#define OPCODE_iJLT ((kopcode_t)139)
typedef struct klr_iJLT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJLT_t;

#define OPCODE_iJLTE ((kopcode_t)140)
typedef struct klr_iJLTE_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJLTE_t;

#define OPCODE_iJGT ((kopcode_t)141)
typedef struct klr_iJGT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJGT_t;

#define OPCODE_iJGTE ((kopcode_t)142)
typedef struct klr_iJGTE_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_iJGTE_t;

#define OPCODE_iJEQC ((kopcode_t)143)
typedef struct klr_iJEQC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJEQC_t;

#define OPCODE_iJNEQC ((kopcode_t)144)
typedef struct klr_iJNEQC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJNEQC_t;

#define OPCODE_iJLTC ((kopcode_t)145)
typedef struct klr_iJLTC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJLTC_t;

#define OPCODE_iJLTEC ((kopcode_t)146)
typedef struct klr_iJLTEC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJLTEC_t;

#define OPCODE_iJGTC ((kopcode_t)147)
typedef struct klr_iJGTC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJGTC_t;

#define OPCODE_iJGTEC ((kopcode_t)148)
typedef struct klr_iJGTEC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kint_t n;
}  __attribute__ ((__aligned__(32))) klr_iJGTEC_t;

#define OPCODE_fJEQ ((kopcode_t)149)
typedef struct klr_fJEQ_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJEQ_t;

#define OPCODE_fJNEQ ((kopcode_t)150)
typedef struct klr_fJNEQ_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJNEQ_t;

#define OPCODE_fJLT ((kopcode_t)151)
typedef struct klr_fJLT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJLT_t;

#define OPCODE_fJLTE ((kopcode_t)152)
typedef struct klr_fJLTE_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJLTE_t;

#define OPCODE_fJGT ((kopcode_t)153)
typedef struct klr_fJGT_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJGT_t;

#define OPCODE_fJGTE ((kopcode_t)154)
typedef struct klr_fJGTE_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kregN_t b;
}  __attribute__ ((__aligned__(32))) klr_fJGTE_t;

#define OPCODE_fJEQC ((kopcode_t)155)
typedef struct klr_fJEQC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJEQC_t;

#define OPCODE_fJNEQC ((kopcode_t)156)
typedef struct klr_fJNEQC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJNEQC_t;

#define OPCODE_fJLTC ((kopcode_t)157)
typedef struct klr_fJLTC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJLTC_t;

#define OPCODE_fJLTEC ((kopcode_t)158)
typedef struct klr_fJLTEC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJLTEC_t;

#define OPCODE_fJGTC ((kopcode_t)159)
typedef struct klr_fJGTC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJGTC_t;

#define OPCODE_fJGTEC ((kopcode_t)160)
typedef struct klr_fJGTEC_t {
	struct KCODE_HEAD head;
	kopl_t  *jumppc;
	kregN_t a;
	kfloat_t n;
}  __attribute__ ((__aligned__(32))) klr_fJGTEC_t;

#define OPCODE_CHKIDX ((kopcode_t)161)
typedef struct klr_CHKIDX_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kregN_t n;
}  __attribute__ ((__aligned__(32))) klr_CHKIDX_t;

#define OPCODE_CHKIDXC ((kopcode_t)162)
typedef struct klr_CHKIDXC_t {
	struct KCODE_HEAD head;
	kregO_t a;
	kuintptr_t n;
}  __attribute__ ((__aligned__(32))) klr_CHKIDXC_t;

#define OPCODE_NOP ((kopcode_t)163)
typedef struct klr_NOP_t {
	struct KCODE_HEAD head;
}  __attribute__ ((__aligned__(32))) klr_NOP_t;

#define OPCODE_MAX ((kopcode_t)164)

#define VMT_VOID     0
#define VMT_ADDR     1
#define VMT_SFPIDX   2
#define VMT_R        3
#define VMT_RN       4
#define VMT_RO       5
#define VMT_SFPIDX2  6
#define VMT_SFX      7
#define VMT_U        8
#define VMT_I        9
#define VMT_F        10
#define VMT_CID      11
#define VMT_HCACHE   12
#define VMT_MTD      13
#define VMT_TMR      14
#define VMT_OBJECT   15
#define VMT_STRING   16
#define VMT_INT      17
#define VMT_FLOAT    18
#define VMT_S        19

#endif /* KONOHA_CODE_H_ */
