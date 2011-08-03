#include "../konoha_mpi.h";

void knh_reduce(knh_Func_t *fo, void *ivec, void *iovec, int *len, MPI_Datatype *dtype)
{
	int vlen = len[0];
	switch(dtype[0]) {
	case BA_Type:
		REDUCE_CLOSURE(BA, char, ivec, iovec, vlen);
	case IA_Type:
		REDUCE_CLOSURE(IA, knh_int_t, ivec, iovec, vlen);
	case FA_Type:
		REDUCE_CLOSURE(FA, knh_float_t, ivec, iovec, vlen);
	default: break;
	}
}

void dummyMPIOpFunc(void *invec, void *inoutvec, int *len, MPI_Datatype *dtype)
{
	return knh_reduce((knh_Func_t*)CALLBACK_MARKER, invec, inoutvec, len, dtype);
}

//## method MPIOp MPIOp.new(Func<dynamic,dynamic> opfunc, Boolean commutable);
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
