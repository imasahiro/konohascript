#include "konoha_mpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* ClassDef */

static void knh_MPIComm_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)o;
	MPIC_COMM(comm) = 0;
	MPIC_RANK(comm) = -1;
	MPIC_SIZE(comm) = -1;
	comm->proc_name = NULL;
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		char pname[MPI_MAX_PROCESSOR_NAME] = {0};
		int len = 0;
		MPI_Get_processor_name(pname, &len);
		if (len > 0)
			comm->proc_name = strdup(pname); // to be free
	}
}

static void knh_MPIComm_free(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)o;
	if (comm->proc_name != NULL)
		free(comm->proc_name); // allocated by strdup
}

static void knh_MPIData_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIData_t *data = (knh_MPIData_t*)o;
	data->v = NULL;
	data->type = MPI_BYTE;
}

static void knh_MPIData_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
	knh_MPIData_t *data = (knh_MPIData_t*)o;
	const knh_ClassTBL_t* tbl = ClassTBL(MPID_CID(data));
	knh_ClassDef_t *cdefbuf = (knh_ClassDef_t*)tbl->cdef;
	cdefbuf->p(ctx, w, (knh_RawPtr_t*)data->o, level);
}

static void knh_MPIOp_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIOp_t *op = (knh_MPIOp_t*)o;
	MPIO_OP(op) = 0;
}

static void knh_MPIRequest_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)o;
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
}

/* ------------------------------------------------------------------------ */
/* Const */

static void knh_MPI_initWorld(CTX ctx, knh_class_t cid)
{
	knh_MPIComm_t *world = new_O(MPIComm, cid);
	world->comm = MPI_COMM_WORLD;
	MPI_Comm_rank(world->comm, &MPIC_RANK(world));
	MPI_Comm_size(world->comm, &MPIC_SIZE(world));
	knh_addClassConst(ctx, cid, new_String(ctx, "WORLD"), (Object*)world);
}

static void knh_MPI_initSelf(CTX ctx, knh_class_t cid)
{
	knh_MPIComm_t *self = new_O(MPIComm, cid);
	self->comm = MPI_COMM_SELF;
	MPI_Comm_rank(self->comm, &MPIC_RANK(self));
	MPI_Comm_size(self->comm, &MPIC_SIZE(self));
	knh_addClassConst(ctx, cid, new_String(ctx, "SELF"), (Object*)self);
}

static void knh_MPI_initParent(CTX ctx, knh_class_t cid)
{
	knh_MPIComm_t *parent = new_O(MPIComm, cid);
	if (MPI_Comm_get_parent(&(parent->comm)) == MPI_SUCCESS) {
		MPI_Comm_rank(parent->comm, &MPIC_RANK(parent));
		MPI_Comm_size(parent->comm, &MPIC_SIZE(parent));
		knh_addClassConst(ctx, cid, new_String(ctx, "PARENT"), (Object*)parent);
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
		knh_MPIOp_t *op = new_O(MPIOp, cid);
		op->op = (MPI_Op)d->ivalue;
		op->func = NULL;
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
		KNH_NOTE("Process is not initialized as MPI Proc. MPI functions are disable");
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
