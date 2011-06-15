#include "../konoha_mpi.h"

#ifdef _SETUP

static knh_IntData_t IntConstData[] = {
	{"MPIContext.OP_MAX",     MPI_MAX},
	{"MPIContext.OP_MIN",     MPI_MIN},
	{"MPIContext.OP_SUM",     MPI_SUM},
	{"MPIContext.OP_PROD",    MPI_PROD},
	{"MPIContext.OP_LAND",    MPI_LAND},
	{"MPIContext.OP_BAND",    MPI_BAND},
	{"MPIContext.OP_LOD",     MPI_LOR},
	{"MPIContext.OP_BOR",     MPI_BOR},
	{"MPIContext.OP_LXOR",    MPI_LXOR},
	{"MPIContext.OP_BXOR",    MPI_BXOR},
	{"MPIContext.OP_MINLOC",  MPI_MINLOC},
	{"MPIContext.OP_MAXLOC",  MPI_MAXLOC},
	{"MPIContext.OP_REPLACE", MPI_REPLACE},
};

DEFAPI(void) MPICONST(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
{
	kapi->loadIntData(ctx, ns, IntConstData);
}

#endif
