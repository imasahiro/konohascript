#include "../konoha_mpi.h"

/* ======================================================================== */
/* TYPEMAP */


TYPEMAP Int_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->i = new_Int(ctx, sfp[1].ivalue);
	data->type = MPI_LONG;
	MPID_INITCID(data);
	RETURN_(data);
}

TYPEMAP int___MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->a = sfp[1].a;
	data->type = MPI_LONG;
	data->cid = CLASS_Array;
	RETURN_(data);
}

TYPEMAP Float_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->f = new_Float_(ctx, CLASS_Float, sfp[1].fvalue);
	data->type = MPI_DOUBLE;
	MPID_INITCID(data);
	RETURN_(data);
}

TYPEMAP float___MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->a = sfp[1].a;
	data->type = MPI_DOUBLE;
	data->cid = CLASS_Array;
	RETURN_(data);
}

TYPEMAP Bytes_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->b = sfp[1].ba;
	data->type = MPI_CHAR;
	MPID_INITCID(data);
	RETURN_(data);
}

TYPEMAP String_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = knh_getcid(ctx, B("konoha.mpi.MPIData"));
	knh_MPIData_t *data = new_O(MPIData, cid);
	data->s = sfp[1].s;
	data->type = MPI_CHAR;
	MPID_INITCID(data);
	RETURN_(data);
}

TYPEMAP MPIData_int__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (data->cid == CLASS_Array && data->type == MPI_LONG) {
		RETURN_(data->a);
	}
	RETURN_(KNH_NULVAL(O_cid(data)));
}

TYPEMAP MPIData_float__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (data->cid == CLASS_Array && data->type == MPI_DOUBLE) {
		RETURN_(data->a);
	}
	RETURN_(KNH_NULVAL(O_cid(data)));
}

TYPEMAP MPIData_Bytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (data->cid == CLASS_Bytes && data->type == MPI_CHAR) {
		RETURN_(data->b);
	}
	RETURN_(KNH_NULVAL(O_cid(data)));
}

/* ------------------------------------------------------------------------ */

//## method Class MPIData.getContentClass();
KMETHOD MPIData_getContentClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	knh_Class_t *cls = new_Type(ctx, data->o->h.cTBL->cid);
	RETURN_(cls);
}

/* ------------------------------------------------------------------------ */

void* knh_MPIData_getAddr(knh_MPIData_t *data, int offset)
{
	if (offset < 0) return NULL;
	switch (MPID_CID(data)) {
	case CLASS_Int:
		return &O_data(data->i);
	case CLASS_Float:
		return &O_data(data->f);
	case CLASS_Array:
		if (data->type ==  MPI_LONG)
			return data->a->ilist + offset;
		else if (data->type == MPI_DOUBLE)
			return data->a->flist + offset;
		break;
	case CLASS_Bytes:
		return data->b->bu.buf + offset;
	case CLASS_String:
		return data->s->str.buf + offset;
	}
	return NULL;
}

void knh_MPIData_expand(CTX ctx, knh_MPIData_t *data, int offset, int *count, int *inc)
{
	/*
	 * "aaaa"      = SIZE
	 * "aa|        = offset
	 *
	 * (case 1: capacity > offset + count)
	 * "aaaa"..... = capacity
	 *    |====>   = count
	 *          <= = exp (not care)
	 * ".......>   = new_size
	 *
	 * (case 2: capacity < offset + count)
	 * "aaaa"..    = capacity
	 *    |======> = count
	 *         ==> = exp (to be expanded)
	 * ".........> = new_size
	 */
	int cur_size = MPID_SIZE(data);
	if (count <= 0 || offset > cur_size) {
		*count = 0;  // invalid param
		*inc = 0;
		return;
	}
	int new_size = offset + *count;
	int capacity = knh_MPIData_getCapacity(data);
	if (new_size <= cur_size) {
		*inc = 0; // no need to incl
		return;
	}
	if (new_size > capacity) {
		switch (MPID_CID(data)) {
		case CLASS_Bytes: {
			int exp_size = k_grow(capacity);
			if (exp_size < new_size) exp_size = k_goodsize(new_size);
			knh_Bytes_expands(ctx, data->b, exp_size);
			break;
		}
		case CLASS_Array: {
			knh_Array_grow(ctx, data->a, new_size, 0);
			break;
		}
		default: {
			*count = 0;
			*inc = 0;
			return;
		}
		}
	}
	*inc = *count;
}

int knh_MPIData_getSize(knh_MPIData_t *data)
{
	switch (MPID_CID(data)) {
	case CLASS_Array:
		return knh_Array_size(data->a);
	case CLASS_Bytes:
		return BA_size(data->b);
	case CLASS_String:
		return S_size(data->s);
	case CLASS_Int:
	case CLASS_Float:
		return 1;
	}
	return 0;
}

int knh_MPIData_incSize(knh_MPIData_t *data, int count)
{
	if (count <= 0) return 0;
	switch (MPID_CID(data)) {
	case CLASS_Array: {
		knh_Array_size(data->a) += count;
		return count;
	}
	case CLASS_Bytes: {
		BA_size(data->b) += count;
		return count;
	}
	}
	return 0;
}

int knh_MPIData_getCapacity(knh_MPIData_t *data)
{
	switch (MPID_CID(data)) {
	case CLASS_Array:
		return data->a->dim->capacity;
	case CLASS_Bytes:
		return data->b->dim->capacity;
	}
	return -1;
}

void  knh_MPIData_checkCount(knh_MPIData_t *data, int offset, int *count)
{
	int scount = MPID_SIZE(data) - offset;
	if (scount >= 0) {
		if (scount < *count) *count = scount;
		if (*count < 0) *count = 0;
	} else {
		*count = 0;
	}
}
