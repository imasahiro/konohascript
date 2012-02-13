#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
/* TYPEMAP */

TYPEMAP Int_MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, new_Int(ctx, sfp[1].ivalue), MPI_LONG, CLASS_Int, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP int___MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, sfp[1].a, MPI_LONG, CLASS_Array, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP Float_MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, new_Float_(ctx, CLASS_Float, sfp[1].fvalue), MPI_DOUBLE, CLASS_Float, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP float___MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, sfp[1].a, MPI_DOUBLE, CLASS_Array, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP Bytes_MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, sfp[1].ba, MPI_CHAR, CLASS_Bytes, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP String_MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(data, sfp[1].s, MPI_CHAR, CLASS_String, O_cid(sfp[1].o));
	RETURN_(data);
}

TYPEMAP MPIData_int__(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (MPID_CID(data) != CLASS_Array || MPID_DCID(data) != CLASS_ArrayInt) {
		NTHROW_CAST_MPID(ctx, sfp, data);
	}
	RETURN_(data->a);
}

TYPEMAP MPIData_float__(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	//if (MPID_CID(data) != CLASS_Array || MPID_DCID(data) != CLASS_ArrayFloat) {
	if (MPID_CID(data) != CLASS_Array || MPID_TYPE(data) != MPI_DOUBLE) {
		NTHROW_CAST_MPID(ctx, sfp, data);
	}
	RETURN_(data->a);
}

TYPEMAP MPIData_Bytes(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[1].o);
	if (MPID_CID(data) != CLASS_Bytes || MPID_DCID(data) != CLASS_Bytes) {
		NTHROW_CAST_MPID(ctx, sfp, data);
	}
	RETURN_(data->ba);
}

/* ------------------------------------------------------------------------ */

static kMethod* knh_loadMethodNULL(CTX ctx, ksfp_t *sfp, kbytes_t clsnm, kbytes_t mtdnm)
{
	kclass_t cid = knh_getcid(ctx, clsnm);
	kmethodn_t mn = knh_getmn(ctx, mtdnm, MN_NONAME);
	return knh_NameSpace_getMethodNULL(ctx, NULL, cid, mn);
}

static kMPIData* knh_MPIData_serialize(CTX ctx, ksfp_t *sfp, kObject* target)
{
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	const char *objtype = NULL;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	{
		kMethod *wmsg = NULL;
		kBytes *ba = NULL;
		do {
			if ((wmsg = knh_loadMethodNULL(ctx, sfp, STEXT("Bytes"), STEXT("writeMsgPack"))) != NULL) {
				ba = new_B(ctx, "mpiobj:msgpack", K_FASTMALLOC_SIZE);
				break;
			}
			if ((wmsg = knh_loadMethodNULL(ctx, sfp, STEXT("Bytes"), STEXT("writeJson"))) != NULL) {
				ba = new_B(ctx, "mpiobj:json", K_FASTMALLOC_SIZE);
				break;
			}
			KNH_NTHROW2(ctx, sfp, "Script!!", "serialize method not found", K_FAILED, KNH_LDATA0);
		} while(0);
		objtype = ba->DBG_name;
		{
			CLOSURE_start(1);
			KNH_SETv(ctx, lsfp[K_CALLDELTA+0].o, ba);
			KNH_SETv(ctx, lsfp[K_CALLDELTA+1].o, target);
			KNH_SCALL(ctx, lsfp, 0, wmsg, 1);
			CLOSURE_end();
		}
		MPID_INIT(data, ba, MPI_CHAR, CLASS_Bytes, O_cid(target));
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPIData_serialize", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_s("objtype", objtype), LOG_i("size", MPID_SIZE(data))));
#endif
	return data;
}

static kObject* knh_MPIData_deserialize(CTX ctx, ksfp_t *sfp, kMPIData* target)
{
	double _begin = MPI_Wtime();
	const char *objtype = NULL;
	kObject *obj;
	{
		kclass_t rcid = MPID_DCID(target);
		obj = KNH_NULVAL(rcid);
		kMethod *rmsg = NULL;
		do {
			if ((rmsg = knh_loadMethodNULL(ctx, sfp, STEXT("Bytes"), STEXT("readMsgPack"))) != NULL) {
				objtype = "mpiobj:msgpack";
				break;
			}
			if ((rmsg = knh_loadMethodNULL(ctx, sfp, STEXT("Bytes"), STEXT("readJson"))) != NULL) {
				objtype = "mpiobj:json";
				break;
			}
			KNH_NTHROW2(ctx, sfp, "Script!!", "deserialize method not found", K_FAILED, KNH_LDATA0);
		} while(0);
		{
			CLOSURE_start(3);
			KNH_SETv(lctx, lsfp[K_CALLDELTA+0].o, target->ba);
			lsfp[K_CALLDELTA+1].ivalue = 0;
			lsfp[K_CALLDELTA+2].ivalue = 0;
			KNH_SETv(lctx, lsfp[K_CALLDELTA+3].c, new_Type(lctx, rcid));
			KNH_SCALL(lctx, lsfp, 0, rmsg, 3);
			obj = lsfp[K_CALLDELTA+K_RTNIDX].o;
			CLOSURE_end();
		}
	}
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPIData_deserialize", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_s("objtype", objtype), LOG_i("size", MPID_SIZE(target))));
	return obj;
}

TYPEMAP Object_MPIData(CTX ctx, ksfp_t *sfp _RIX)
{
	kObject *obj = sfp[1].o;
	kMPIData *serialized = knh_MPIData_serialize(ctx, sfp, obj);
	if (serialized == NULL) {
		KNH_NTHROW2(ctx, sfp, "Script!!", "object serialization failed", K_FAILED,
					KNH_LDATA(LOG_s("class", SAFECLASS__(ctx, O_cid(obj)))));
	}
	RETURN_(serialized);
}

//## method Tvar MPIData.decode(Class _);

KMETHOD MPIData_decode(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	kclass_t dcid = MPID_DCID(data);
	if (MPID_CID(data) != CLASS_Bytes || dcid == CLASS_Bytes) {
		NTHROW_CAST_MPID(ctx, sfp, data);
	}
	kclass_t rcid = knh_Class_cid(sfp[1].c);
	if (dcid != rcid) {
		if (dcid != O_cid(data)) {
			THROW_TypeError(ctx, sfp, dcid, rcid);
		}
		MPID_DCID(data) = rcid; // IS_MPIData
	}
	kObject *obj = knh_MPIData_deserialize(ctx, sfp, data);
	if (obj == NULL) {
		KNH_NTHROW2(ctx, sfp, "Script!!", "object deserialization failed", K_FAILED,
					KNH_LDATA(LOG_s("class", SAFECLASS__(ctx, dcid))));
	}
	RETURN_(obj);
}

/* ------------------------------------------------------------------------ */

void* knh_MPIData_getAddr(kMPIData *data)
{
	switch (MPID_CID(data)) {
	case CLASS_Int:
		return &O_data(data->i);
	case CLASS_Float:
		return &O_data(data->f);
	case CLASS_Array:
		if (MPID_DCID(data) == CLASS_ArrayInt)
			return data->a->ilist + MPID_POFS(data);
		//else if (MPID_DCID(data) == CLASS_ArrayFloat)
		else if (MPID_TYPE(data) == MPI_DOUBLE)
			return data->a->flist + MPID_POFS(data);
	case CLASS_Bytes:
		return data->ba->bu.buf + MPID_POFS(data);
	case CLASS_String:
		return data->s->str.buf + MPID_POFS(data);
	default:
		return (data->ba) ? data->ba->bu.buf + MPID_POFS(data) : NULL;
	}
}

void knh_MPIData_expand(CTX ctx, kMPIData *data, int *count, int *inc)
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
		switch (MPID_CID(data)) {
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

int knh_MPIData_getSize(kMPIData *data)
{
	switch (MPID_CID(data)) {
	case CLASS_Array:
		return knh_Array_size(data->a);
	case CLASS_Bytes:
		return BA_size(data->ba);
	case CLASS_String:
		return S_size(data->s);
	default:
		return (data->ba) ? BA_size(data->ba) : 0;
	}
}

int knh_MPIData_incSize(kMPIData *data, int count)
{
	if (count <= 0) return 0;
	switch (MPID_CID(data)) {
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

int knh_MPIData_getCapacity(kMPIData *data)
{
	switch (MPID_CID(data)) {
	case CLASS_Array:
		return data->a->dim->capacity;
	case CLASS_Bytes:
		return data->ba->dim->capacity;
	default:
		break;
	}
	return -1;
}

void  knh_MPIData_checkCount(kMPIData *data, int *count)
{
	int size = MPID_SIZE(data);
	int pofs = MPID_POFS(data);
	if (*count > size - pofs) {
		// cut down count number.
		*count = size - pofs;
	}
}

/* ------------------------------------------------------------------------ */
//## method MPIData MPIData.new(Class class);

KMETHOD MPIData_new(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	kBytes *ba = new_B(ctx, "mpiobj", K_FASTMALLOC_SIZE);
	MPID_INIT(data, ba, MPI_CHAR, CLASS_Bytes, knh_Class_cid(sfp[1].c));
	RETURN_(data);
}

/* ------------------------------------------------------------------------ */
//## method int MPIData.getDataType();

KMETHOD MPIData_getDataType(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	RETURNi_((kint_t)MPID_TYPE(data));
}

/* ------------------------------------------------------------------------ */
//## method Class MPIData.getDataClass();

KMETHOD MPIData_getDataClass(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	kclass_t cid = MPID_CID(data);
	kclass_t dcid = MPID_DCID(data);
	RETURN_(new_Type(ctx, (cid == CLASS_Bytes || cid == CLASS_Array) ? dcid : cid));
}

/* ------------------------------------------------------------------------ */
//## method int MPIData.getSize();

KMETHOD MPIData_getSize(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	RETURNi_(MPID_SIZE(data));
}

/* ------------------------------------------------------------------------ */
//## method dynamic MPIData.get(int n);

KMETHOD MPIData_get(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	kObject *ret = UPCAST(data);
	if (MPID_CID(data) == CLASS_Array) {
		kArray *a = data->a;
		size_t idx = knh_array_index(ctx, sfp, Int_to(kint_t, sfp[1]), knh_Array_size(a));
		if (MPID_DCID(data) == CLASS_ArrayInt) {
			ret = UPCAST(new_Int(ctx, a->ilist[idx]));
		}
		else { // if (MPID_DCID(data) == CLASS_ArrayFloat) {
			ret = UPCAST(new_Float(ctx, a->flist[idx]));
		}
	}
	else if (MPID_CID(data) == CLASS_Bytes && MPID_DCID(data) == CLASS_Bytes) {
		kBytes *ba = data->ba;
		size_t idx = knh_array_index(ctx, sfp, Int_to(kint_t, sfp[1]), ba->bu.len);
		ret = UPCAST(new_Int(ctx, ba->bu.utext[idx]));
	}
	else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "index access not allowed", K_FAILED, KNH_LDATA0);
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method void MPIData.set(int n, dynamic d);

KMETHOD MPIData_set(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	MPID_CHK_WRITABLE(data);
	if (MPID_CID(data) == CLASS_Array) {
		kArray *a = data->a;
		size_t idx = knh_array_index(ctx, sfp, Int_to(kint_t, sfp[1]), knh_Array_size(a));
		if (MPID_DCID(data) == CLASS_ArrayInt) {
			a->ilist[idx] = Int_to(kint_t, sfp[2]);
		}
		else { // if (MPID_DCID(data) == CLASS_ArrayFloat) {
			a->flist[idx] = Float_to(kfloat_t, sfp[2]);
		}
	}
	else if (MPID_CID(data) == CLASS_Bytes && MPID_DCID(data) == CLASS_Bytes) {
		kBytes *ba = data->ba;
		size_t idx = knh_array_index(ctx, sfp, Int_to(kint_t, sfp[1]), ba->bu.len);
		ba->bu.ubuf[idx] = Int_to(kchar_t, sfp[2]);
	}
	else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "index access not allowed", K_FAILED, KNH_LDATA0);
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method MPIData MPIData.opADD(int offset);

KMETHOD MPIData_opADD(CTX ctx, ksfp_t *sfp _RIX)
{
	MPID(data, sfp[0].o);
	MPID(newdata, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	MPID_INIT(newdata, data->o, MPID_TYPE(data), MPID_CID(data), MPID_DCID(data));
	int ofs = Int_to(int, sfp[1]);
	if (ofs < 0 || MPID_SIZE(data) < ofs) {
		ofs = 0;
		KNH_NTHROW2(ctx, sfp, "Script!!", "invalid offset value", K_FAILED, KNH_LDATA(LOG_i("offset", ofs)));
	}
	MPID_POFS(newdata) = MPID_POFS(data) + ofs;
	RETURN_(newdata);
}
