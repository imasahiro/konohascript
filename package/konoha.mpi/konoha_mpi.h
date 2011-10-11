
#ifndef KNH_INCLUDE_MPI
#define KNH_INCLUDE_MPI

#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <mpi.h>

/* ------------------------------------------------------------------------ */
/* Konoha Type */

//## type IArray Array 0 Int;

//## type FArray Array 0 Float;

#ifndef IS_IArray
#define IS_IArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Int)
#endif
#ifndef IS_FArray
#define IS_FArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Float)
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

#define MPIC_SIZE(c) ((c)->numprocs)
#define MPIC_RANK(c) ((c)->myrank)
#define MPIC_COMM(c) ((c)->comm)

#define KNH_MPI_SUCCESS(res) ((res) == MPI_SUCCESS) /* defined in mpi.h */
#define MPIC(v, o) knh_MPIComm_t *v = ((knh_MPIComm_t*)o)

/* ------------------------------------------------------------------------ */
/* MPI Data */

//## class MPIData Object;

typedef struct {
	knh_hObject_t h;
	union {
		knh_Object_t *o;
		knh_Int_t    *i;
		knh_Float_t  *f;
		knh_Array_t  *a;
		knh_Bytes_t  *b;
		knh_String_t *s;
		void *v;
	};
	MPI_Datatype type;
	knh_class_t cid;
} knh_MPIData_t;

#define MPID_TYPE(data) (data->type)
#define MPID_CID(data) (data->cid)
#define MPID_ADDR(data, offset) knh_MPIData_getAddr(data, offset)
#define MPID_SIZE(data) knh_MPIData_getSize(data)
#define MPID_INITCID(data) (MPID_CID(data) = O_cid(data->o))
#define MPID(v, o) knh_MPIData_t *v = ((knh_MPIData_t*)o)

void* knh_MPIData_getAddr(knh_MPIData_t *data, int offset);
void  knh_MPIData_expand(CTX ctx, knh_MPIData_t *data, int offset, int *count, int *inc);
int   knh_MPIData_getSize(knh_MPIData_t *data);
int   knh_MPIData_incSize(knh_MPIData_t *data, int count);
int   knh_MPIData_getCapacity(knh_MPIData_t *data);
void  knh_MPIData_checkCount(knh_MPIData_t *data, int offset, int *count);


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
#define Request_new(ctx, req) (req) = new_O(MPIRequest, O_cid(req))

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

#endif /* KNH_INCLUDE_MPI */
