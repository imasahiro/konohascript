#include "konoha_mpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* ClassDef */

static void knh_MPIComm_init(CTX ctx, knh_RawPtr_t *o)
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

static void knh_MPIComm_free(CTX ctx, knh_RawPtr_t *o)
{
	MPIC(comm, o);
	if (MPIC_PROC(comm)) free(comm->proc_name); // allocated by strdup
}

static void knh_MPIData_init(CTX ctx, knh_RawPtr_t *o)
{
	MPID(data, o);
	data->o = NULL;
	MPID_TYPE(data) = MPI_BYTE;
	MPID_DCID(data) = CLASS_Object;
	MPID_POFS(data) = 0;
}

static void knh_MPIData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	MPID(data, p);
	if (data->o != NULL) {
		KNH_ENSUREREF(ctx, 1);
		KNH_ADDREF(ctx, data->o);
		KNH_SIZEREF(ctx);
	}
}

static void knh_MPIData_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
	MPID(data, o);
	ClassTBL(MPID_DCID(data))->cdef->p(ctx, w, data->r, level);
	if (MPID_POFS(data) > 0) knh_printf(ctx, w, "(+%d)offset", MPID_POFS(data));
}

static void knh_MPIOp_init(CTX ctx, knh_RawPtr_t *o)
{
	MPIO(op, o);
	MPIO_OP(op) = 0;
	MPIO_OPFUNC(op) = NULL;
}

static void knh_MPIOp_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	MPIO(op, p);
	if (MPIO_OPFUNC(op) != NULL) {
		KNH_ENSUREREF(ctx, 1);
		KNH_ADDREF(ctx, MPIO_OPFUNC(op));
		KNH_SIZEREF(ctx);
	}
}

static void knh_MPIRequest_init(CTX ctx, knh_RawPtr_t *o)
{
	MPIR(req, o);
	MPIR_INC(req) = 0;
}

DEFAPI(void) defMPIComm(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIComm";
	cdef->init = knh_MPIComm_init;
	cdef->free = knh_MPIComm_free;
}

DEFAPI(void) defMPIData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIData";
	cdef->init = knh_MPIData_init;
	cdef->reftrace = knh_MPIData_reftrace;
	cdef->p = knh_MPIData_p;
}

DEFAPI(void) defMPIRequest(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIRequest";
	cdef->init = knh_MPIRequest_init;
}

DEFAPI(void) defMPIOp(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIOp";
	cdef->init = knh_MPIOp_init;
	cdef->reftrace = knh_MPIOp_reftrace;
}

/* ------------------------------------------------------------------------ */
/* Const */

static void knh_MPI_initWorld(CTX ctx, knh_class_t cid)
{
	MPIC(world, new_O(MPIComm, cid));
	MPIC_COMM(world) = MPI_COMM_WORLD;
	MPI_Comm_rank(MPIC_COMM(world), &MPIC_RANK(world));
	MPI_Comm_size(MPIC_COMM(world), &MPIC_SIZE(world));
	knh_addClassConst(ctx, cid, new_String(ctx, "WORLD"), (knh_Object_t*)world);
}

static void knh_MPI_initSelf(CTX ctx, knh_class_t cid)
{
	MPIC(self, new_O(MPIComm, cid));
	MPIC_COMM(self) = MPI_COMM_SELF;
	MPI_Comm_rank(MPIC_COMM(self), &MPIC_RANK(self));
	MPI_Comm_size(MPIC_COMM(self), &MPIC_SIZE(self));
	knh_addClassConst(ctx, cid, new_String(ctx, "SELF"), (knh_Object_t*)self);
}

static void knh_MPI_initParent(CTX ctx, knh_class_t cid)
{
	MPIC(parent, new_O(MPIComm, cid));
	if (MPI_Comm_get_parent(&MPIC_COMM(parent)) == MPI_SUCCESS) {
		MPI_Comm_rank(MPIC_COMM(parent), &MPIC_RANK(parent));
		MPI_Comm_size(MPIC_COMM(parent), &MPIC_SIZE(parent));
		knh_addClassConst(ctx, cid, new_String(ctx, "PARENT"), (knh_Object_t*)parent);
	}
}

static knh_IntData_t MPIConstOp[] = {
	{"MAX",  (knh_int_t)MPI_MAX},
	{"MIN",  (knh_int_t)MPI_MIN},
	{"SUM",  (knh_int_t)MPI_SUM},
	{"PROD", (knh_int_t)MPI_PROD},
	{"LAND", (knh_int_t)MPI_LAND},
	{"BAND", (knh_int_t)MPI_BAND},
	{"LOD",  (knh_int_t)MPI_LOR},
	{"BOR",  (knh_int_t)MPI_BOR},
	{"LXOR", (knh_int_t)MPI_LXOR},
	{"BXOR", (knh_int_t)MPI_BXOR},
	{NULL, 0},
};

static void knh_MPI_initOp(CTX ctx, knh_class_t cid)
{
	knh_IntData_t *d;
	for (d = &MPIConstOp[0]; d->ivalue > 0; d++) {
		MPIO(op, new_O(MPIOp, cid));
		MPIO_OP(op) = (MPI_Op)d->ivalue;
		MPIO_OPFUNC(op) = NULL;
		knh_addClassConst(ctx, cid, new_String(ctx, d->name), (Object*)op);
	}
}

DEFAPI(void) constMPIComm(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		knh_MPI_initWorld(ctx, cid);
		knh_MPI_initSelf(ctx, cid);
		knh_MPI_initParent(ctx, cid);
	}
}

DEFAPI(void) constMPIData(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
}

DEFAPI(void) constMPIRequest(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
}

DEFAPI(void) constMPIOp(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) knh_MPI_initOp(ctx, cid);
}

#ifdef _SETUP

void knh_MPI_initArrayFuncData(CTX ctx);
void knh_MPI_initArrayPrintFunc(CTX ctx);

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
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

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
