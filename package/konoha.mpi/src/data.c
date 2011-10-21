#include "../konoha_mpi.h"

/* ======================================================================== */
/* TYPEMAP */

TYPEMAP Int_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->i = new_Int(ctx, sfp[1].ivalue);
	MPID_TYPE(data) = MPI_LONG;
	MPID_DCID(data) = CLASS_Int;
	RETURN_(data);
}

TYPEMAP int___MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->a = sfp[1].a;
	MPID_TYPE(data) = MPI_LONG;
	MPID_DCID(data) = CLASS_Array;
	RETURN_(data);
}

TYPEMAP Float_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->f = new_Float_(ctx, CLASS_Float, sfp[1].fvalue);
	MPID_TYPE(data) = MPI_DOUBLE;
	MPID_DCID(data) = CLASS_Float;
	RETURN_(data);
}

TYPEMAP float___MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->a = sfp[1].a;
	MPID_TYPE(data) = MPI_DOUBLE;
	MPID_DCID(data) = CLASS_Array;
	RETURN_(data);
}

TYPEMAP Bytes_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->ba = sfp[1].ba;
	MPID_TYPE(data) = MPI_CHAR;
	MPID_DCID(data) = CLASS_Bytes;
	RETURN_(data);
}

TYPEMAP String_MPIData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->s = sfp[1].s;
	MPID_TYPE(data) = MPI_CHAR;
	MPID_DCID(data) = CLASS_String;
	RETURN_(data);
}

TYPEMAP MPIData_int__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (MPID_DCID(data) != CLASS_Array || MPID_TYPE(data) != MPI_LONG) {
		knh_ldata_t ldata[] = {LOG_s("content class", SAFECLASS__(ctx, MPID_DCID(data))), LOG_END};
		KNH_NTHROW(ctx, sfp, "Script!!", "invalid type casting", K_FAILED, ldata);
	}
	RETURN_(data->a);
}

TYPEMAP MPIData_float__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (MPID_DCID(data) != CLASS_Array || MPID_TYPE(data) != MPI_DOUBLE) {
		knh_ldata_t ldata[] = {LOG_s("content class", SAFECLASS__(ctx, MPID_DCID(data))), LOG_END};
		KNH_NTHROW(ctx, sfp, "Script!!", "invalid type casting", K_FAILED, ldata);
	}
	RETURN_(data->a);
}

TYPEMAP MPIData_Bytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (MPID_DCID(data) != CLASS_Bytes || MPID_TYPE(data) != MPI_CHAR) {
		knh_ldata_t ldata[] = {LOG_s("content class", SAFECLASS__(ctx, MPID_DCID(data))), LOG_END};
		KNH_NTHROW(ctx, sfp, "Script!!", "invalid type casting", K_FAILED, ldata);
	}
	RETURN_(data->ba);
}

/* ------------------------------------------------------------------------ */
//## method Class MPIData.getContentClass();

KMETHOD MPIData_getContentClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	RETURN_(new_Type(ctx, O_cid(data->o)));
}

/* ------------------------------------------------------------------------ */
//## method MPIData MPIData.opADD(int offset);

KMETHOD MPIData_opADD(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	MPID(newdata, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	newdata->o = data->o;
	MPID_TYPE(newdata) = MPID_TYPE(data);
	MPID_DCID(newdata) = MPID_DCID(data);
	int ofs = Int_to(int, sfp[1]);
	if (ofs < 0 || MPID_SIZE(data) < ofs) {
		knh_ldata_t ldata[] = {LOG_i("offset", ofs), LOG_END};
		ofs = 0;
		KNH_NTHROW(ctx, sfp, "Script!!", "invalid offset value", K_FAILED, ldata);
	}
	MPID_POFS(newdata) = MPID_POFS(data) + ofs;
	RETURN_(newdata);
}

/* ------------------------------------------------------------------------ */

void* knh_MPIData_getAddr(knh_MPIData_t *data)
{
	switch (MPID_DCID(data)) {
	case CLASS_Int:
		return &O_data(data->i);
	case CLASS_Float:
		return &O_data(data->f);
	case CLASS_Array:
		if (MPID_TYPE(data) ==  MPI_LONG)
			return data->a->ilist + MPID_POFS(data);
		else if (MPID_TYPE(data) == MPI_DOUBLE)
			return data->a->flist + MPID_POFS(data);
	case CLASS_Bytes:
		return data->ba->bu.buf + MPID_POFS(data);
	case CLASS_String:
		return data->s->str.buf + MPID_POFS(data);
	}
	return NULL;
}

void knh_MPIData_expand(CTX ctx, knh_MPIData_t *data, int *count, int *inc)
{
	if (count <= 0) {
		*count = 0;  // invalid param
		*inc = 0;
		return;
	}
	int cur_size = MPID_SIZE(data);
	int new_size = MPID_POFS(data) + *count;
	int capacity = knh_MPIData_getCapacity(data);
	if (new_size <= cur_size) {
		*inc = 0; // no need to incl
		return;
	}
	if (new_size > capacity) {
		switch (MPID_DCID(data)) {
		case CLASS_Bytes: {
			int exp_size = k_grow(capacity);
			if (exp_size < new_size) exp_size = k_goodsize(new_size);
			knh_Bytes_expands(ctx, data->ba, exp_size);
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
	*inc = new_size - cur_size;
}

int knh_MPIData_getSize(knh_MPIData_t *data)
{
	switch (MPID_DCID(data)) {
	case CLASS_Array:
		return knh_Array_size(data->a);
	case CLASS_Bytes:
		return BA_size(data->ba);
	case CLASS_String:
		return S_size(data->s);
	}
	return 0;
}

int knh_MPIData_incSize(knh_MPIData_t *data, int count)
{
	if (count <= 0) return 0;
	switch (MPID_DCID(data)) {
	case CLASS_Array: {
		knh_Array_size(data->a) += count;
		return count;
	}
	case CLASS_Bytes: {
		BA_size(data->ba) += count;
		return count;
	}
	}
	return 0;
}

int knh_MPIData_getCapacity(knh_MPIData_t *data)
{
	switch (MPID_DCID(data)) {
	case CLASS_Array:
		return data->a->dim->capacity;
	case CLASS_Bytes:
		return data->ba->dim->capacity;
	}
	return -1;
}

void  knh_MPIData_checkCount(knh_MPIData_t *data, int *count)
{
	int size = MPID_SIZE(data);
	int pofs = MPID_POFS(data);
	if (*count > size - pofs) {
		// cut down count number.
		*count = size - pofs;
	}
}
