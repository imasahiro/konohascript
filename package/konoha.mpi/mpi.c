#ifndef _KNH_ON_T2K
#include "konoha_mpi.h"
#endif

/**
 * @T2K src/main/struct.c
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* ClassDef */

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

static void knh_MPIData_init(CTX ctx, kRawPtr *o)
{
	MPID(data, o);
	data->o = NULL;
	MPID_TYPE(data) = MPI_BYTE;
	MPID_DCID(data) = CLASS_Object;
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
	ClassTBL(MPID_DCID(data))->cdef->p(ctx, w, data->r, level);
	if (MPID_POFS(data) > 0) knh_printf(ctx, w, "(+%d)offset", MPID_POFS(data));
}

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

static void knh_MPIRequest_init(CTX ctx, kRawPtr *o)
{
	MPIR(req, o);
	MPIR_INC(req) = 0;
}

#ifdef _KNH_ON_T2K

static const kclassdef_t MPICommDef = {
	knh_MPIComm_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"MPIComm", CFLAG_Tvar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6,
};

static const kclassdef_t MPIOpDef = {
	knh_MPIOp_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"MPIOp", CFLAG_Tvar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6,
};

static const kclassdef_t MPIRequestDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"MPIRequest", CFLAG_Tvar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6,
};

#else /* ifdef _KNH_ON_T2K */

DEFAPI(void) defMPIComm(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIComm";
	cdef->init = knh_MPIComm_init;
	cdef->free = knh_MPIComm_free;
}

DEFAPI(void) defMPIData(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIData";
	cdef->init = knh_MPIData_init;
	cdef->reftrace = knh_MPIData_reftrace;
	cdef->p = knh_MPIData_p;
}

DEFAPI(void) defMPIRequest(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIRequest";
	cdef->init = knh_MPIRequest_init;
}

DEFAPI(void) defMPIOp(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "MPIOp";
	cdef->init = knh_MPIOp_init;
	cdef->reftrace = knh_MPIOp_reftrace;
}

#endif /* _KNH_ON_T2K */

/* ------------------------------------------------------------------------ */
/* Const */

static void knh_MPI_initWorld(CTX ctx, kclass_t cid)
{
	MPIC(world, new_O(MPIComm, cid));
	MPIC_COMM(world) = MPI_COMM_WORLD;
	MPI_Comm_rank(MPIC_COMM(world), &MPIC_RANK(world));
	MPI_Comm_size(MPIC_COMM(world), &MPIC_SIZE(world));
	knh_addClassConst(ctx, cid, new_String(ctx, "WORLD"), (kObject*)world);
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

static void knh_MPI_initOp(CTX ctx, kclass_t cid)
{
	knh_IntData_t *d;
	for (d = &MPIConstOp[0]; d->ivalue > 0; d++) {
		MPIO(op, new_O(MPIOp, cid));
		MPIO_OP(op) = (MPI_Op)d->ivalue;
		MPIO_OPFUNC(op) = NULL;
		knh_addClassConst(ctx, cid, new_String(ctx, d->name), (Object*)op);
	}
}

#ifndef _KNH_ON_T2K

static void knh_MPI_initSelf(CTX ctx, kclass_t cid)
{
	MPIC(self, new_O(MPIComm, cid));
	MPIC_COMM(self) = MPI_COMM_SELF;
	MPI_Comm_rank(MPIC_COMM(self), &MPIC_RANK(self));
	MPI_Comm_size(MPIC_COMM(self), &MPIC_SIZE(self));
	knh_addClassConst(ctx, cid, new_String(ctx, "SELF"), (kObject*)self);
}

static void knh_MPI_initParent(CTX ctx, kclass_t cid)
{
	MPIC(parent, new_O(MPIComm, cid));
	if (MPI_Comm_get_parent(&MPIC_COMM(parent)) == MPI_SUCCESS) {
		MPI_Comm_rank(MPIC_COMM(parent), &MPIC_RANK(parent));
		MPI_Comm_size(MPIC_COMM(parent), &MPIC_SIZE(parent));
		knh_addClassConst(ctx, cid, new_String(ctx, "PARENT"), (kObject*)parent);
	}
}

DEFAPI(void) constMPIComm(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		knh_MPI_initWorld(ctx, cid);
		//knh_MPI_initSelf(ctx, cid);
		//knh_MPI_initParent(ctx, cid);
	}
}

DEFAPI(void) constMPIData(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	;
}

DEFAPI(void) constMPIRequest(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	;
}

DEFAPI(void) constMPIOp(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) knh_MPI_initOp(ctx, cid);
}

#ifdef _SETUP

void knh_MPI_initArrayFuncData(CTX ctx);
void knh_MPI_initArrayPrintFunc(CTX ctx);

void knh_MPI_errhandler(MPI_Comm *comm, int *err, ...)
{
	if (*err != MPI_SUCCESS) {
		char errstr[MPI_MAX_ERROR_STRING] = {0};
		int errlen = 0;
		MPI_Error_string(*err, errstr, &errlen);
		fprintf(stderr, "MPI error == %s\n", errstr);
	}
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		//MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
		MPI_Errhandler errfn;
		MPI_Comm_create_errhandler(knh_MPI_errhandler, &errfn);
		MPI_Errhandler_set(MPI_COMM_WORLD, errfn);
	} else {
		KNH_NOTE("Process is not initialized as MPI Proc.: MPI functions are NOT available");
	}
	knh_MPI_initArrayFuncData(ctx);
	knh_MPI_initArrayPrintFunc(ctx);
	kapi->setPackageProperty(ctx, "name", "mpi");
	kapi->setPackageProperty(ctx, "version", "1.0");
	RETURN_PKGINFO("konoha.mpi");
}

#endif /* _SETUP */

#else /* ifndef _KNH_ON_T2K */

/**
 * @T2K src/main/struct.c:knh_loadScriptSystemData
 */

void knh_MPI_initArrayFuncData(CTX ctx);
void knh_MPI_initArrayPrintFunc(CTX ctx);

void knh_initMPI(CTX ctx)
{
	knh_MPI_initArrayFuncData(ctx);
	knh_MPI_initArrayPrintFunc(ctx);
	knh_MPI_initWorld(ctx, CLASS_MPIComm);
	knh_MPI_initOp(ctx, CLASS_MPIOp);
}

#endif /* _KNH_ON_T2K */

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
