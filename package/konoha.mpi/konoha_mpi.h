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
	kObjectHeader h;
	MPI_Comm comm;
	int myrank;
	int numprocs;
	char *proc_name;
} kMPIComm;

#define MPIC_COMM(c) ((c)->comm)
#define MPIC_RANK(c) ((c)->myrank)
#define MPIC_SIZE(c) ((c)->numprocs)
#define MPIC_PROC(d) ((d)->proc_name)
#define MPIC(v, o) kMPIComm *v = ((kMPIComm*)o)

/* ------------------------------------------------------------------------ */
/* MPI Data */

//## class MPIData Object;

typedef struct {
	kObjectHeader h;
	union {
		kObject *o;
		kRawPtr *r;
		kInt    *i;
		kFloat  *f;
		kArray  *a;
		kBytes  *ba;
		kString *s;
	};
	MPI_Datatype type;
	kclass_t cid;
	size_t offset;
} kMPIData;

#define MPID_ADDR(d) knh_MPIData_getAddr(d)
#define MPID_TYPE(d) ((d)->type)
#define MPID_DCID(d) ((d)->cid)
#define MPID_POFS(d) ((d)->offset)
#define MPID_SIZE(d) knh_MPIData_getSize(d)
#define MPID_WCHK(d) \
	{\
		if (knh_MPIData_getCapacity(d) == -1) {\
			KNH_NTHROW2(ctx, sfp, "Script!!", "MPIData unwritable", K_FAILED, \
					KNH_LDATA(LOG_p("unwritable data", d)));\
		}\
	}
#define MPID_CCHK(d, c) \
	{\
		int psize = MPID_SIZE(d) - MPID_POFS(d);\
		if (c > psize) c = psize;\
	}
#define MPID(v, o) kMPIData *v = ((kMPIData*)o)

void* knh_MPIData_getAddr(kMPIData *data);
void  knh_MPIData_expand(CTX ctx, kMPIData *data, int *count, int *inc);
int   knh_MPIData_getSize(kMPIData *data);
int   knh_MPIData_incSize(kMPIData *data, int count);
int   knh_MPIData_getCapacity(kMPIData *data);

/* ------------------------------------------------------------------------ */
/* MPI Request */

//## class MPIRequest Object;

typedef struct {
	kObjectHeader h;
	MPI_Request reqt;
	kMPIData *data;
	int incflag;
} kMPIRequest;

#define MPIR_REQ(req) (&((req)->reqt))
#define MPIR_DATA(req) ((req)->data)
#define MPIR_TYPE(req) (MPID_TYPE(MPIR_DATA(req)))
#define MPIR_INC(req) ((req)->incflag)
#define MPIR(v, o) kMPIRequest *v = ((kMPIRequest*)o)

/* ------------------------------------------------------------------------ */
/* MPI Operator */

//## class MPIOp Object;

typedef struct {
	kObjectHeader h;
	MPI_Op op;
	MPI_User_function *func;
} kMPIOp;

//## type MPIOpFunc    Func  0 MPIData MPIData Int;

#define MPIO_OP(o) ((o)->op)
#define MPIO_OPFUNC(o) ((o)->func)
#define KNH_MPI_OP_NULL(op) (MPIO_OP(op) = 0)
#define KNH_MPI_OP_IS_NULL(op) (MPIO_OP(op) == 0)
#define MPIO(v, op) kMPIOp *v = (kMPIOp*)op

#ifndef _KNH_ON_T2K
#endif /* KNH_INCLUDE_MPI */
#endif
