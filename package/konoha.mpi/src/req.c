#include "../konoha_mpi.h"

//## method Int MPIRequest.wait();
METHOD MPIRequest_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)sfp[0].o;
	MPI_Status stat;
	int ret = -1;
	if (!KNH_MPI_REQUEST_IS_NULL(mreq)) {
		ret = MPI_Wait(mreq->mpi_req, &stat);
	}
	RETURNi_(ret);
}
