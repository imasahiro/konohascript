#include "../konoha_mpi.h"

//## method MPIContext MPIContext.new();
METHOD MPIContext_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	int flag;
	MPI_Initialized(&flag);
	if (!flag) {
		KNH_NOT_ON_MPI(mctx);
		KNH_LOG("MPI is not initialized");
	} else {
		static char proc_name[MPI_MAX_PROCESSOR_NAME] = {0};
		mctx->proc_name = (char*)&proc_name;
		MPI_Comm_rank(MPI_COMM_WORLD, &KNH_MPI_RANK(mctx));
		MPI_Comm_size(MPI_COMM_WORLD, &KNH_MPI_SIZE(mctx));
		MPI_Get_processor_name(proc_name, &flag);
	}
	RETURN_(mctx);
}

//## method Int MPIContext.getRank();
METHOD MPIContext_getRank(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(mctx) ? KNH_MPI_RANK(mctx) : -1);
}

//## method Int MPIContext.getSize();
METHOD MPIContext_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(mctx) ? KNH_MPI_SIZE(mctx) : -1);
}

//## method String MPIContext.getProcessorName();
METHOD MPIContext_getProcessorName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	RETURN_((KNH_ON_MPI(mctx)) ? new_String(ctx, mctx->proc_name) : (knh_String_t*)KNH_NULVAL(CLASS_String));
}

//## method Int MPIContext.getWtime();
METHOD MPIContext_getWtime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(mctx) ? MPI_Wtime() : 0);
}
