#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method MPIOp MPIOp.new(MPIOpFunc opfunc, Boolean commutable);

static kMPIData* new_MPIData_Bytes(CTX ctx, void *vec, int vlen)
{
	kBytes *ba = new_Bytes(ctx, NULL, vlen);
	knh_memcpy(ba->bu.buf, vec, vlen);
	BA_size(ba) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, ba, MPI_CHAR, CLASS_Bytes, O_cid(ba));
	return data;
}

static kMPIData* new_MPIData_ArrayInt(CTX ctx, void *vec, int vlen)
{
	kArray *a = new_Array(ctx, CLASS_Int, vlen);
	knh_memcpy(a->ilist, vec, sizeof(kint_t) * vlen);
	knh_Array_size(a) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, a, MPI_LONG, CLASS_Array, O_cid(a));
	return data;
}

static kMPIData* new_MPIData_ArrayFloat(CTX ctx, void *vec, int vlen)
{
	kArray *a = new_Array(ctx, CLASS_Float, vlen);
	knh_memcpy(a->flist, vec, sizeof(kfloat_t) * vlen);
	knh_Array_size(a) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, a, MPI_DOUBLE, CLASS_Array, O_cid(a));
	return data;
}

void knh_reduce(kFunc *fo, void *ivec, void *iovec, int *len, MPI_Datatype *dtype)
{
	kMPIData* (*new_func)(CTX ctx, void *vec, int vlen);
	size_t rsize = 0;
	int vlen = *len;
	CLOSURE_start(2);
	if (*dtype == MPI_CHAR) {
		new_func = new_MPIData_Bytes;
		rsize = vlen;
	}
	else if (*dtype == MPI_LONG) {
		new_func = new_MPIData_ArrayInt;
		rsize = sizeof(kint_t) * vlen;
	}
	else if (*dtype == MPI_DOUBLE) {
		new_func = new_MPIData_ArrayFloat;
		rsize = sizeof(kfloat_t) * vlen;
	}
	if (rsize > 0) {
		kMPIData *o1 = new_func(lctx, ivec, vlen);
		kMPIData *o2 = new_func(lctx, iovec, vlen);
		lsfp[1].o = (Object*)o1;
		lsfp[2].o = (Object*)o2;
		CLOSURE_call(fo);
		knh_memcpy(iovec, MPID_ADDR(o2), rsize);
	}
	else {
		KNH_NTHROW2(lctx, lsfp, "Script!!", "MPI_Reduce failed", K_FAILED, KNH_LDATA(LOG_i("unsupported datatype", *dtype)));
	}
	CLOSURE_end(return);
}

void dummyMPIOpFunc(void *invec, void *inoutvec, int *len, MPI_Datatype *dtype)
{
	return knh_reduce((kFunc*)CALLBACK_MARKER, invec, inoutvec, len, dtype);
}

KMETHOD MPIOp_new(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIO(op, sfp[0].o);
	kFunc *fo = (kFunc*)sfp[1].fo;
	MPI_User_function *func = (MPI_User_function*)knh_copyCallbackFunc(ctx, (void*)dummyMPIOpFunc, (void*)knh_reduce, fo);
	if (func) {
		if (MPI_Op_create(func, ((sfp[2].bvalue) ? 1 : 0), &MPIO_OP(op)) == MPI_SUCCESS) {
			MPIO_OPFUNC(op) = func;
			goto L_RET;
		}
	}
	KNH_MPI_OP_NULL(op);
	KNH_NTHROW2(ctx, sfp, "Script!!", "MPIOp_new failed", K_FAILED, KNH_LDATA(LOG_p("MPI_User_function", func)));
	L_RET:;
	RETURN_(op);
}

