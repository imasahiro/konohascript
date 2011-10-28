#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#endif

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getRank();
KMETHOD MPIComm_getRank(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPIC_RANK((knh_MPIComm_t*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getSize();
KMETHOD MPIComm_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPIC_SIZE((knh_MPIComm_t*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method String MPIComm.getProcessorName();
KMETHOD MPIComm_getProcessorName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_String(ctx, (const char*)(((knh_MPIComm_t*)sfp[0].o)->proc_name)));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.barrier();
KMETHOD MPIComm_barrier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPI_Barrier(MPIC_COMM((knh_MPIComm_t*)sfp[0].o)));
}

