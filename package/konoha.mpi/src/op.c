#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method MPIOp MPIOp.new(MPIOpFunc opfunc, Boolean commutable);

void knh_reduce(knh_Func_t *fo, void *ivec, void *iovec, int *len, MPI_Datatype *dtype)
{
	CLOSURE_start(2);
	CTX ctx = lctx;
	int vlen = len[0];
	if (dtype[0] == MPI_CHAR) {
		knh_Bytes_t *o1 = new_Bytes(ctx, NULL, vlen);
		knh_memcpy(o1->bu.buf, ivec, vlen);
		BA_size(o1) = vlen;
		knh_Bytes_t *o2 = new_Bytes(ctx, NULL, vlen);
		knh_memcpy(o2->bu.buf, iovec, vlen);
		BA_size(o2) = vlen;
		lsfp[1].o = (Object*)o1;
		lsfp[2].o = (Object*)o2;
		CLOSURE_call(fo);
		knh_memcpy(iovec, o2->bu.buf, vlen);
	} else if (dtype[0] == MPI_LONG) {
		knh_Array_t *o1 = new_Array(ctx, CLASS_Int, vlen);
		knh_memcpy(o1->ilist, ivec, sizeof(knh_int_t) * vlen);
		knh_Array_size(o1) = vlen;
		knh_Array_t *o2 = new_Array(ctx, CLASS_Int, vlen);
		knh_memcpy(o2->ilist, iovec, sizeof(knh_int_t) * vlen);
		knh_Array_size(o2) = vlen;
		lsfp[1].o = (Object*)o1;
		lsfp[2].o = (Object*)o2;
		CLOSURE_call(fo);
		knh_memcpy(iovec, o2->ilist, sizeof(knh_int_t) * vlen);
	} else if (dtype[0] == MPI_DOUBLE) {
		knh_Array_t *o1 = new_Array(ctx, CLASS_Float, vlen);
		knh_memcpy(o1->flist, ivec, sizeof(knh_float_t) * vlen);
		knh_Array_size(o1) = vlen;
		knh_Array_t *o2 = new_Array(ctx, CLASS_Int, vlen);
		knh_memcpy(o2->flist, iovec, sizeof(knh_float_t) * vlen);
		knh_Array_size(o2) = vlen;
		lsfp[1].o = (Object*)o1;
		lsfp[2].o = (Object*)o2;
		CLOSURE_call(fo);
		knh_memcpy(iovec, o2->ilist, sizeof(knh_float_t) * vlen);
	}
	CLOSURE_end(return);
}

void dummyMPIOpFunc(void *invec, void *inoutvec, int *len, MPI_Datatype *dtype)
{
	return knh_reduce((knh_Func_t*)CALLBACK_MARKER, invec, inoutvec, len, dtype);
}

KMETHOD MPIOp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIO(op, sfp[0].o);
	knh_Func_t *fo = (knh_Func_t*)sfp[1].fo;
	MPI_User_function *func = (MPI_User_function*)knh_copyCallbackFunc(ctx, (void*)dummyMPIOpFunc, (void*)knh_reduce, fo);
	if (func) {
		MPI_Op newop;
		if (MPI_Op_create(func, ((sfp[2].bvalue) ? 1 : 0), &newop) == MPI_SUCCESS) {
			MPIO_OP(op) = newop;
			MPIO_OPFUNC(op) = func;
			goto L_RET;
		}
	}
	fprintf(stderr, "some error\n");
	KNH_MPI_OP_NULL(op);
	L_RET:;
	RETURN_(op);
}

