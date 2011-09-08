
#ifndef KNH_INCLUDE_MPI
#define KNH_INCLUDE_MPI

#define K_INTERNAL
#include <konoha1.h>
#include <mpi.h>

/* ------------------------------------------------------------------------ */
/* konoha */

#define KNH_BA_EXPAND(data, count) \
	{\
		size_t _capacity = (data)->dim->capacity;\
		size_t _new_cap = BA_size(data) + count;\
		if (_new_cap >= _capacity) {\
			size_t _newsize = k_grow(_capacity);\
			if (_newsize < _new_cap) _newsize = k_goodsize(_new_cap);\
			knh_Bytes_expands(ctx, (data), _newsize);\
		}\
	}

#define KNH_IA_EXPAND(data, count) \
	knh_Array_grow(ctx, (data), ((data)->dim->capacity)+(count), (count))

#define KNH_FA_EXPAND(data, count) \
	knh_Array_grow(ctx, (data), ((data)->dim->capacity)+(count), (count))

#define BA_new(l) new_Bytes(ctx, NULL, (l))
#define IA_new(l) new_Array(ctx, CLASS_Int, (l))
#define FA_new(l) new_Array(ctx, CLASS_Float, (l))

//##    IS_Bytes(o) /* defined @ konoha1.h */
#define IS_IArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Int)
//##    IS_Int(o)
#define IS_FArray(o) (IS_bArray(o) && O_p1(o) == CLASS_Float)
//##    IS_Float(o)
#define BA_buf(data) ((data)->bu.buf)

#define SV_buf(data) ((data)->str.ubuf)
#define IA_buf(data) ((data)->ilist)
#define IV_buf(data) &O_data(data)
#define FA_buf(data) ((data)->flist)
#define FV_buf(data) &O_data(data)

//##    BA_size(data) ((data)->bu.len) /* defined @ konoha1.h */
#define SV_size(data) data->str.len
#define IA_size(data) knh_Array_size(data)
#define FA_size(data) knh_Array_size(data)
//
#define BA_Class knh_Bytes_t
#define SV_Class knh_String_t
#define IA_Class knh_Array_t
#define IV_Class knh_Int_t
#define FA_Class knh_Array_t
#define FV_Class knh_Float_t

#define BA_Type MPI_CHAR
#define SV_Type BA_Type
#define IA_Type MPI_UNSIGNED_LONG
#define IV_Type IA_Type
#define FA_Type MPI_DOUBLE
#define FV_Type FA_Type

#define BA(v, o) BA_Class *v = ((BA_Class*)o)
#define SV(v, o) SV_Class *v = ((SV_Class*)o)
#define IA(v, o) IA_Class *v = ((IA_Class*)o)
#define IV(v, o) IV_Class *v = ((IV_Class*)o)
#define FA(v, o) FA_Class *v = ((FA_Class*)o)
#define FV(v, o) FV_Class *v = ((FV_Class*)o)

/* ------------------------------------------------------------------------ */
/* MPI */
/* Communicator */
typedef struct {
	knh_hObject_t h;
	MPI_Comm comm;
	int mpi_rank;
	int mpi_size;
	char *proc_name;
} knh_MPIComm_t;

#define KNH_MPI_SIZE(c) ((c)->mpi_size)
#define KNH_MPI_RANK(c) ((c)->mpi_rank)
#define KNH_MPI_COMM(c) ((c)->comm)
#define KNH_NOT_ON_MPI(c) \
	{\
		KNH_MPI_RANK(c) = -1;\
		KNH_MPI_COMM(c) = 0;\
	}

#define KNH_ON_MPI(c) ((KNH_MPI_RANK(c) != -1) && (KNH_MPI_COMM(c) != 0))
#define KNH_MPI_SUCCESS(res) ((res) == MPI_SUCCESS) /* defined in mpi.h */
#define COMM(v, o) knh_MPIComm_t *v = ((knh_MPIComm_t*)o)

typedef struct {
	knh_hObject_t h;
	MPI_Request reqt;
} knh_MPIRequest_t;

#define KNH_MPI_REQ(req) ((req)->reqt)
#define KNH_MPI_REQ_IS_NULL(req) (KNH_MPI_REQ(req) == MPI_REQUEST_NULL)

/* Op */
typedef struct {
	knh_hObject_t h;
	MPI_Op op;
	MPI_User_function *func;
} knh_MPIOp_t;

#define KNH_MPI_OP(o) ((o)->op)
#define KNH_MPI_OPFUNC(o) ((o)->func)
#define KNH_MPI_OP_NULL(op) (KNH_MPI_OP(op) = 0)
#define KNH_MPI_OP_IS_NULL(op) (KNH_MPI_OP(op) == 0)
#define OP(v, op) knh_MPIOp_t *v = (knh_MPIOp_t*)op

#define REDUCE_CLOSURE(XA, btype, iv, iov, vl) \
	{\
		CLOSURE_start(2);\
		CTX ctx = lctx;\
		XA##_Class *o1 = XA##_new(vl);\
		knh_memcpy(XA##_buf(o1), (btype*)(iv), sizeof(btype) * (vl));\
		XA##_size(o1) = (vl);\
		XA##_Class *o2 = XA##_new(vl);\
		knh_memcpy(XA##_buf(o2), (btype*)(iov), sizeof(btype) * (vl));\
		XA##_size(o2) = (vl);\
		lsfp[1].o = (Object*)o1;\
		lsfp[2].o = (Object*)o2;\
		CLOSURE_call(fo);\
		knh_memcpy((iov), (void*)XA##_buf(o2), sizeof(btype) * (vl));\
		CLOSURE_end(return);\
	}

/* ------------------------------------------------------------------------ */

#endif /* KNH_INCLUDE_MPI */
