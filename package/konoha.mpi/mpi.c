#include "konoha_mpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

#ifdef _SETUP

static void knh_MPIContext_init(CTX ctx, Object *o)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)o;
	KNH_NOT_ON_MPI(mctx);
	mctx->mpi_size = -1;
	mctx->proc_name = NULL;
}

DEFAPI(const knh_ClassDef_t*) MPIContext(CTX ctx)
{
	static knh_ClassDef_t cdef;
	cdef = *(knh_getDefaultClassDef());
	cdef.init = knh_MPIContext_init;
	cdef.name = "MPIContext";
	return &cdef;
}

static void knh_MPIRequest_init(CTX ctx, Object *o)
{
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)o;
	mreq->mpi_req = (MPI_Request*)KNH_MALLOC(ctx, sizeof(MPI_Request));
}

static void knh_MPIRequest_free(CTX ctx, Object *o)
{
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)o;
	if (!KNH_MPI_REQUEST_IS_NULL(mreq)) {
		MPI_Request_free(mreq->mpi_req);
		KNH_FREE(ctx, mreq->mpi_req, sizeof(MPI_Request));
	}
}

/*
static void knh_MPIContext_errhandler(MPI_Comm *comm, int *errcode, ...)
{
	//va_list args;
	//va_start(args, errcode);
	//int ival;
	//ival = va_arg(args, int);
	static char errmsg[MPI_MAX_ERROR_STRING] = {0};
	int msglen, class, code = *errcode;
	MPI_Error_string(code, errmsg, &msglen);
	MPI_Error_class(code, &class);
	switch (class) {
	case MPI_ERR_TRUNCATE:
		UHD("hogehoge%d", class);
		*errcode = MPI_SUCCESS;
		break;
	default:
		break;
	}
	//va_end(args);
}
*/

DEFAPI(const knh_ClassDef_t*) MPIRequest(CTX ctx)
{
	static knh_ClassDef_t cdef;
	cdef = *(knh_getDefaultClassDef());
	cdef.init = knh_MPIRequest_init;
	cdef.free = knh_MPIRequest_free;
	cdef.name = "MPIRequest";
	return &cdef;
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx)
{
	int flag = 0;
	MPI_Initialized(&flag);
	if (flag) {
		/* init err_handler */
		//static MPI_Errhandler err_hdr;
		//MPI_Errhandler_create(knh_MPIContext_errhandler, &err_hdr);
		//MPI_Errhandler_set(MPI_COMM_WORLD, err_hdr);
		MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	}
	static const knh_PackageDef_t pkgdef = KNH_PKGINFO("mpi", "0.1", "Konoha MPI Package", NULL);
	return &pkgdef;
}

#endif /* _SETUP */

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

