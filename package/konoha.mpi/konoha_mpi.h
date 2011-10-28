#ifndef _KNH_ON_T2K
#ifndef KNH_INCLUDE_MPI
#define KNH_INCLUDE_MPI
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#endif /* _KNH_ON_T2K */

/**
 * @T2K include/konoha1/konoha_class.h
 */

#include <mpi.h>

/* ------------------------------------------------------------------------ */
/* Konoha Type */

//## type ArrayFloat Array 0 Float;

#ifndef IS_ArrayFloat
#define IS_ArrayFloat(o) (IS_bArray(o) && O_p1(o) == CLASS_Float)
#endif

/* ------------------------------------------------------------------------ */
/* MPI Communicator */

//## class MPIComm Object;

typedef struct {
	knh_hObject_t h;
	MPI_Comm comm;
	int myrank;
	int numprocs;
	char *proc_name;
} knh_MPIComm_t;

#define MPIC_COMM(c) ((c)->comm)
#define MPIC_RANK(c) ((c)->myrank)
#define MPIC_SIZE(c) ((c)->numprocs)
#define MPIC_PROC(d) ((d)->proc_name)
#define MPIC(v, o) knh_MPIComm_t *v = ((knh_MPIComm_t*)o)

/* ------------------------------------------------------------------------ */
/* MPI Data */

//## class MPIData Object;

typedef struct {
	knh_hObject_t h;
	union {
		knh_Object_t *o;
		knh_RawPtr_t *r;
		knh_Int_t    *i;
		knh_Float_t  *f;
		knh_Array_t  *a;
		knh_Bytes_t  *ba;
		knh_String_t *s;
	};
	MPI_Datatype type;
	knh_class_t cid;
	size_t offset;
} knh_MPIData_t;

#define MPID_ADDR(d) knh_MPIData_getAddr(d)
#define MPID_TYPE(d) ((d)->type)
#define MPID_DCID(d) ((d)->cid)
#define MPID_POFS(d) ((d)->offset)
#define MPID_SIZE(d) knh_MPIData_getSize(d)
#define MPID_WCHK(d) \
	{\
		if (knh_MPIData_getCapacity(d) == -1) {\
			knh_ldata_t ldata[] = {LOG_p("unwritable data", d), LOG_END};\
			KNH_NTHROW(ctx, sfp, "Script!!", "MPIData unwritable", K_FAILED, ldata);\
		}\
	}
#define MPID_CCHK(d, c) \
	{\
		int psize = MPID_SIZE(d) - MPID_POFS(d);\
		if (c > psize) c = psize;\
	}
#define MPID(v, o) knh_MPIData_t *v = ((knh_MPIData_t*)o)

void* knh_MPIData_getAddr(knh_MPIData_t *data);
void  knh_MPIData_expand(CTX ctx, knh_MPIData_t *data, int *count, int *inc);
int   knh_MPIData_getSize(knh_MPIData_t *data);
int   knh_MPIData_incSize(knh_MPIData_t *data, int count);
int   knh_MPIData_getCapacity(knh_MPIData_t *data);

/* ------------------------------------------------------------------------ */
/* MPI Request */

//## class MPIRequest Object;

typedef struct {
	knh_hObject_t h;
	MPI_Request reqt;
	knh_MPIData_t *data;
	int incflag;
} knh_MPIRequest_t;

#define MPIR_REQ(req) (&((req)->reqt))
#define MPIR_DATA(req) ((req)->data)
#define MPIR_TYPE(req) (MPID_TYPE(MPIR_DATA(req)))
#define MPIR_INC(req) ((req)->incflag)
#define MPIR(v, o) knh_MPIRequest_t *v = ((knh_MPIRequest_t*)o)

/* ------------------------------------------------------------------------ */
/* MPI Operator */

//## class MPIOp Object;

typedef struct {
	knh_hObject_t h;
	MPI_Op op;
	MPI_User_function *func;
} knh_MPIOp_t;

//## type MPIOpFunc    Func  0 MPIData MPIData Int;

#define MPIO_OP(o) ((o)->op)
#define MPIO_OPFUNC(o) ((o)->func)
#define KNH_MPI_OP_NULL(op) (MPIO_OP(op) = 0)
#define KNH_MPI_OP_IS_NULL(op) (MPIO_OP(op) == 0)
#define MPIO(v, op) knh_MPIOp_t *v = (knh_MPIOp_t*)op

#ifndef _KNH_ON_T2K
#endif /* KNH_INCLUDE_MPI */
#endif
