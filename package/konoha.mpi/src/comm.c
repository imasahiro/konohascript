#include "../konoha_mpi.h"

//## method Int MPICommunicator.getRank();
KMETHOD MPICommunicator_getRank(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(comm) ? KNH_MPI_RANK(comm) : -1);
}

//## method Int MPICommunicator.getSize();
KMETHOD MPICommunicator_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(comm) ? KNH_MPI_SIZE(comm) : -1);
}

//## method String MPICommunicator.getProcessorName();
KMETHOD MPICommunicator_getProcessorName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)sfp[0].o;
	knh_String_t *pname = (KNH_ON_MPI(comm)) ?
		new_String(ctx, (const char*)comm->proc_name) : (knh_String_t*)KNH_NULVAL(CLASS_String);
	RETURN_(pname);
}

//## method Int MPICommunicator.getWtime();
KMETHOD MPICommunicator_getWtime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(comm) ? MPI_Wtime() : 0);
}

//## method Int MPICommunicator.barrier();
KMETHOD MPICommunicator_barrier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(comm) ? MPI_Barrier(KNH_MPI_COMM(comm)) : 0);
}
