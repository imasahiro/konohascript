#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## @Static method void System.disableLog();

KMETHOD System_disableLog(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_closelog();
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## @Static method Float System.getMPIWtime();
KMETHOD System_getMPIWtime(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(MPI_Wtime());
}

