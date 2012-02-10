#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## @Static method void MPI.preventLog();

KMETHOD MPI_preventLog(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_closelog();
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @Static method Float MPI.getWtime();
KMETHOD MPI_getWtime(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(MPI_Wtime());
}

