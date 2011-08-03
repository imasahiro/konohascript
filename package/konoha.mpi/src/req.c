#include "../konoha_mpi.h"

//## method Int MPIRequest.wait();
KMETHOD MPIRequest_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)sfp[0].o;
	MPI_Status stat;
	int ret = -1;
	if (!KNH_MPI_REQUEST_IS_NULL(mreq)) {
		ret = MPI_Wait(mreq->mpi_req, &stat);
	}
	RETURNi_(ret);
}

//## method Int MPIRequest.cancel();
KMETHOD MPIRequest_cancel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)sfp[0].o;
	int ret = -1;
	if (!KNH_MPI_REQUEST_IS_NULL(mreq)) {
		ret = MPI_Cancel(mreq->mpi_req);
	}
	RETURNi_(ret);
}
