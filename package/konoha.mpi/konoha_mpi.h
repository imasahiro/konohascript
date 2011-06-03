
#ifndef KNH_INCLUDE_MPI
#define KNH_INCLUDE_MPI

#include <konoha1.h>
#include <mpi.h>

/* ------------------------------------------------------------------------ */
/* konoha */

#define KNH_BYTES_EXPAND(data, count) \
	{\
		size_t _capacity = (data)->dim->capacity;\
		size_t _new_cap = BA_size(data) + count;\
		if (_new_cap >= _capacity) {\
			size_t _newsize = k_grow(_capacity);\
			if (_newsize < _new_cap) _newsize = k_goodsize(_new_cap);\
			knh_Bytes_expands(ctx, (data), _newsize);\
		}\
		BA_size(data) += count;\
	}\

#define KNH_ARRAY_EXPAND(data, count) \
	knh_Array_grow(ctx, (data), ((data)->dim->capacity)+(count), (count))

//##    IS_Bytes(o)
#define IS_IArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Int)
#define IS_FArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Float)
#define BA_buf(data) ((data)->bu.buf)
#define IA_buf(data) ((data)->ilist)
#define FA_buf(data) ((data)->flist)
//##    BA_size(data) ((data)->bu.len) /* defined in konoha1.h */
#define IA_size(data) knh_Array_size(data)
#define FA_size(data) knh_Array_size(data)
#define BA_tail(data) (&BA_buf(data)[BA_size(data)])
#define IA_tail(data) (&IA_buf(data)[IA_size(data)])
#define FA_tail(data) (&FA_buf(data)[FA_size(data)])
#define BA_Type MPI_CHAR
#define IA_Type MPI_UNSIGNED_LONG
#define FA_Type MPI_DOUBLE

/* ------------------------------------------------------------------------ */
/* MPI */

typedef struct {
	knh_hObject_t h;
	int mpi_rank;
	int mpi_size;
	char *proc_name;
} knh_MPIContext_t;

#define KNH_MPI_SIZE(mctx) ((mctx)->mpi_size)
#define KNH_MPI_RANK(mctx) ((mctx)->mpi_rank)
#define KNH_NOT_ON_MPI(mctx)  KNH_MPI_RANK(mctx) = -1
#define KNH_ON_MPI(mctx)  (KNH_MPI_RANK(mctx) != -1)
#define KNH_MPI_SUCCESS(res) ((res) == MPI_SUCCESS) /* defined in mpi.h */
#define KNH_MPI_IS_OP(op) ((op) >= MPI_MAX && (op) <= MPI_REPLACE) /* defined in mpi.h */

typedef struct {
	knh_hObject_t h;
	MPI_Request *mpi_req;
} knh_MPIRequest_t;

#define KNH_MPI_REQUEST(req) ((req)->mpi_req)
#define KNH_MPI_REQUEST_IS_NULL(req) (*KNH_MPI_REQUEST(req) == MPI_REQUEST_NULL) /* defined in mpi.h */

/* ------------------------------------------------------------------------ */

#endif /* KNH_INCLUDE_MPI */
