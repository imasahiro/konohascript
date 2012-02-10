#include "konoha_mpi.h"

#ifdef __cplusplus
BEGIN_EXTERN_C
#endif

/* ======================================================================== */
/* ClassDef API (defClass & constClass) */

/* ------------------------------------------------------------------------ */
/* class MPI */

DEFAPI(void) defMPI(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPI";
}

DEFAPI(void) constMPI(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	/* dummy */;
}

/* ------------------------------------------------------------------------ */
/* class MPIComm */

static void knh_MPIComm_init(CTX ctx, kRawPtr *o)
{
	MPIC(comm, o);
	MPIC_COMM(comm) = 0;
	MPIC_RANK(comm) = -1;
	MPIC_SIZE(comm) = -1;
	MPIC_PROC(comm) = NULL;
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		char pname[MPI_MAX_PROCESSOR_NAME] = {0};
		int len = 0;
		MPI_Get_processor_name(pname, &len);
		if (len) MPIC_PROC(comm) = strdup(pname); // to be free
	}
}

static void knh_MPIComm_free(CTX ctx, kRawPtr *o)
{
	MPIC(comm, o);
	if (MPIC_PROC(comm)) free(comm->proc_name); // allocated by strdup
}

DEFAPI(void) defMPIComm(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIComm";
	cdef->init = knh_MPIComm_init;
	cdef->free = knh_MPIComm_free;
}

DEFAPI(void) constMPIComm(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		MPIC(world, new_O(MPIComm, cid));
		MPIC_INITV(world, MPI_COMM_WORLD);
		knh_addClassConst(ctx, cid, new_String(ctx, "WORLD"), (kObject*)world);
		knh_setClassDefaultValue(ctx, cid, world, NULL);
	}
}

/* ------------------------------------------------------------------------ */
/* class MPIData */

static void knh_MPIData_init(CTX ctx, kRawPtr *o)
{
	MPID(data, o);
	MPID_INIT(data, NULL, MPI_BYTE, CLASS_Object, CLASS_Object);
	MPID_POFS(data) = 0;
}

static void knh_MPIData_reftrace(CTX ctx, kRawPtr *p FTRARG)
{
	MPID(data, p);
	if (data->o != NULL) {
		KNH_ENSUREREF(ctx, 1);
		KNH_ADDREF(ctx, data->o);
		KNH_SIZEREF(ctx);
	}
}

static void knh_MPIData_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	MPID(data, o);
	ClassTBL(MPID_CID(data))->cdef->p(ctx, w, data->r, level);
	if (MPID_POFS(data) > 0) knh_printf(ctx, w, "(+%d)offset", MPID_POFS(data));
}

DEFAPI(void) defMPIData(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIData";
	cdef->init = knh_MPIData_init;
	cdef->reftrace = knh_MPIData_reftrace;
	cdef->p = knh_MPIData_p;
}

static knh_IntData_t MPIDataConstInt[] = {
	{"CHAR", (kint_t)MPI_CHAR},
	{"LONG", (kint_t)MPI_LONG},
	{"DOUBLE", (kint_t)MPI_DOUBLE}
};

DEFAPI(void) constMPIData(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, MPIDataConstInt);
}

/* ------------------------------------------------------------------------ */
/* class MPIOp */

static void knh_MPIOp_init(CTX ctx, kRawPtr *o)
{
	MPIO(op, o);
	MPIO_OP(op) = 0;
	MPIO_OPFUNC(op) = NULL;
}

static void knh_MPIOp_reftrace(CTX ctx, kRawPtr *p FTRARG)
{
	MPIO(op, p);
	if (MPIO_OPFUNC(op) != NULL) {
		KNH_ENSUREREF(ctx, 1);
		KNH_ADDREF(ctx, MPIO_OPFUNC(op));
		KNH_SIZEREF(ctx);
	}
}

DEFAPI(void) defMPIOp(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIOp";
	cdef->init = knh_MPIOp_init;
	cdef->reftrace = knh_MPIOp_reftrace;
}

static knh_IntData_t MPIConstOp[] = {
	{"MAX",  (kint_t)MPI_MAX},
	{"MIN",  (kint_t)MPI_MIN},
	{"SUM",  (kint_t)MPI_SUM},
	{"PROD", (kint_t)MPI_PROD},
	{"LAND", (kint_t)MPI_LAND},
	{"BAND", (kint_t)MPI_BAND},
	{"LOD",  (kint_t)MPI_LOR},
	{"BOR",  (kint_t)MPI_BOR},
	{"LXOR", (kint_t)MPI_LXOR},
	{"BXOR", (kint_t)MPI_BXOR},
	{NULL, 0},
};

DEFAPI(void) constMPIOp(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		knh_IntData_t *d;
		for (d = &MPIConstOp[0]; d->ivalue > 0; d++) {
			MPIO(op, new_O(MPIOp, cid));
			MPIO_OP(op) = (MPI_Op)d->ivalue;
			MPIO_OPFUNC(op) = NULL;
			knh_addClassConst(ctx, cid, new_String(ctx, d->name), (Object*)op);
		}
	}
}

/* ------------------------------------------------------------------------ */
/* class MPIRequest */

static void knh_MPIRequest_init(CTX ctx, kRawPtr *o)
{
	MPIR(req, o);
	MPIR_INC(req) = 0;
}

DEFAPI(void) defMPIRequest(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIRequest";
	cdef->init = knh_MPIRequest_init;
}

DEFAPI(void) constMPIRequest(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	/* dummy */;
}


/* ======================================================================== */
/* PackageDef API (init) */

static void knh_MPI_errhandler(MPI_Comm *comm, int *err, ...)
{
	int ecode = *err;
	if (ecode != MPI_SUCCESS) {
		CTX ctx = knh_getCurrentContext();
		char errstr[MPI_MAX_ERROR_STRING] = {0};
		int errlen = 0;
		MPI_Error_string(ecode, errstr, &errlen);
		KNH_NTRACE2(ctx, "MPI_Error", K_FAILED,
					KNH_LDATA(LOG_i("ecode", ecode), LOG_s("errmsg", errstr)));
	}
}

void knh_MPI_initArrayFuncData(CTX ctx);
void knh_MPI_initArrayPrintFunc(CTX ctx);

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		MPI_Errhandler errfn;
		MPI_Comm_create_errhandler(knh_MPI_errhandler, &errfn);
		MPI_Errhandler_set(MPI_COMM_WORLD, errfn);
	} else {
		KNH_NOTE("process is not initialized for MPI: MPI functions are NOT available");
	}
	knh_MPI_initArrayFuncData(ctx);
	knh_MPI_initArrayPrintFunc(ctx);
	kapi->setPackageProperty(ctx, "name", "mpi");
	kapi->setPackageProperty(ctx, "version", "1.0");
	RETURN_PKGINFO("konoha.mpi");
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
END_EXTERN_C
#endif
