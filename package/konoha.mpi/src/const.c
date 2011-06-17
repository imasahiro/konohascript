#include "../konoha_mpi.h"

#ifdef _SETUP

static knh_IntData_t IntConstData[] = {
	{"OP_MAX",     MPI_MAX},
	{"OP_MIN",     MPI_MIN},
	{"OP_SUM",     MPI_SUM},
	{"OP_PROD",    MPI_PROD},
	{"OP_LAND",    MPI_LAND},
	{"OP_BAND",    MPI_BAND},
	{"OP_LOD",     MPI_LOR},
	{"OP_BOR",     MPI_BOR},
	{"OP_LXOR",    MPI_LXOR},
	{"OP_BXOR",    MPI_BXOR},
	{"OP_MINLOC",  MPI_MINLOC},
	{"OP_MAXLOC",  MPI_MAXLOC},
	{"OP_REPLACE", MPI_REPLACE},
};

DEFAPI(void) constMPI(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadIntClassConst(ctx, cid, IntConstData);
}

#endif
