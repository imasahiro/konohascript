#include "konoha_mpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

//## method void System.disableLog();
KMETHOD System_disableLog(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_closelog();
	RETURNvoid_();
}

//## method Float System.getMPIWtime();
KMETHOD System_getMPIWtime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(MPI_Wtime());
}

/* ------------------------------------------------------------------------ */

static void knh_MPIComm_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIComm_t *comm = (knh_MPIComm_t*)o;
	KNH_NOT_ON_MPI(comm);
	KNH_MPI_SIZE(comm) = -1;
	comm->proc_name = NULL;
}

static void knh_MPIOp_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_MPIOp_t *op = (knh_MPIOp_t*)o;
	KNH_MPI_OP(op) = 0;
}

static void knh_MPI_initWorld(CTX ctx, knh_class_t cid)
{
	int len;
	knh_MPIComm_t *world = new_O(MPIComm, cid);
	static char proc_name[MPI_MAX_PROCESSOR_NAME] = {0};
	world->comm = MPI_COMM_WORLD;
	world->proc_name = (char*)&proc_name;
	MPI_Comm_rank(world->comm, &KNH_MPI_RANK(world));
	MPI_Comm_size(world->comm, &KNH_MPI_SIZE(world));
	MPI_Get_processor_name(world->proc_name, &len);
	knh_addClassConst(ctx, cid, new_String(ctx, "WORLD"), (Object*)world);
}

static void knh_MPI_initSelf(CTX ctx, knh_class_t cid)
{
	int len;
	knh_MPIComm_t *self = new_O(MPIComm, cid);
	static char proc_name[MPI_MAX_PROCESSOR_NAME] = {0};
	self->comm = MPI_COMM_SELF;
	self->proc_name = (char*)&proc_name;
	MPI_Comm_rank(self->comm, &KNH_MPI_RANK(self));
	MPI_Comm_size(self->comm, &KNH_MPI_SIZE(self));
	MPI_Get_processor_name(self->proc_name, &len);
	knh_addClassConst(ctx, cid, new_String(ctx, "SELF"), (Object*)self);
}

static void knh_MPI_initParent(CTX ctx, knh_class_t cid)
{
	int len;
	knh_MPIComm_t *parent = new_O(MPIComm, cid);
	static char proc_name[MPI_MAX_PROCESSOR_NAME] = {0};
	if (MPI_Comm_get_parent(&(parent->comm)) == 0) {
		parent->proc_name = (char*)&proc_name;
		MPI_Comm_rank(parent->comm, &KNH_MPI_RANK(parent));
		MPI_Comm_size(parent->comm, &KNH_MPI_SIZE(parent));
		MPI_Get_processor_name(parent->proc_name, &len);
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

DEFAPI(void) defMPIComm(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIComm";
	cdef->init = knh_MPIComm_init;
}

DEFAPI(void) defMPIRequest(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIRequest";
}

DEFAPI(void) defMPIOp(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "MPIOp";
	cdef->init = knh_MPIOp_init;
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

DEFAPI(void) constMPIOp(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) knh_MPI_initOp(ctx, cid);
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	int init = 0;
	MPI_Initialized(&init);
	if (init) {
		MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	} else {
		KNH_NOTE("process not initialized with mpirun: MPI methods are unusable");
	}
	kapi->setPackageProperty(ctx, "name", "mpi");
	kapi->setPackageProperty(ctx, "version", "1.0");
	RETURN_PKGINFO("konoha.mpi");
}

#endif /* _SETUP */

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
