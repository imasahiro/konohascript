#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method MPIOp MPIOp.new(MPIOpFunc opfunc, Boolean commutable);

void knh_reduce(knh_Func_t *fo, void *ivec, void *iovec, int *len, MPI_Datatype *dtype)
{
	int vlen = len[0];
	if (dtype[0] == BA_Type) {
		REDUCE_CLOSURE(BA, char, ivec, iovec, vlen);
	} else if (dtype[0] == IA_Type) {
		REDUCE_CLOSURE(IA, knh_int_t, ivec, iovec, vlen);
	} else if (dtype[0] == FA_Type) {
		REDUCE_CLOSURE(FA, knh_float_t, ivec, iovec, vlen);
	}
}

void dummyMPIOpFunc(void *invec, void *inoutvec, int *len, MPI_Datatype *dtype)
{
	return knh_reduce((knh_Func_t*)CALLBACK_MARKER, invec, inoutvec, len, dtype);
}

KMETHOD MPIOp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIOp_t *op = (knh_MPIOp_t*)sfp[0].o;
	knh_Func_t *fo = (knh_Func_t*)sfp[1].fo;
	MPI_User_function *func = (MPI_User_function*)knh_copyCallbackFunc(ctx, (void*)dummyMPIOpFunc, (void*)knh_reduce, fo);
	if (func) {
		MPI_Op newop;
		if (KNH_MPI_SUCCESS(MPI_Op_create(func, ((sfp[2].bvalue) ? 1 : 0), &newop))) {
			KNH_MPI_OP(op) = newop;
			KNH_MPI_OPFUNC(op) = func;
			goto L_RET;
		}
	}
	fprintf(stderr, "some error\n");
	KNH_MPI_OP_NULL(op);
	L_RET:;
	RETURN_(op);
}

