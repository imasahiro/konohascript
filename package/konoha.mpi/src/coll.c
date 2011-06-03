#include "../konoha_mpi.h"

//## method Int MPIContext.barrier();
METHOD MPIContext_barrier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	RETURNi_(KNH_ON_MPI(mctx) ? MPI_Barrier(MPI_COMM_WORLD) : 0);
}

//## method Int MPIContext.bcast(Bytes sdata, Int count, Int root_rank);
METHOD MPIContext_bcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *data = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			ret = MPI_Bcast(BA_buf(data), count, BA_Type, root_rank, MPI_COMM_WORLD);
		} else {
			KNH_BYTES_EXPAND(data, count);
			ret = MPI_Bcast(BA_tail(data), count, BA_Type, root_rank, MPI_COMM_WORLD);
			BA_size(data) += count;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.bcastInt(IArray sdata, Int count, Int root_rank);
METHOD MPIContext_bcastInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *data = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(data)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			ret = MPI_Bcast(IA_buf(data), count, IA_Type, root_rank, MPI_COMM_WORLD);
		} else {
			KNH_ARRAY_EXPAND(data, count);
			ret = MPI_Bcast(IA_tail(data), count, IA_Type, root_rank, MPI_COMM_WORLD);
			IA_size(data) += count;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.bcastFloat(FArray sdata, Int count, Int root_rank);
METHOD MPIContext_bcastFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *data = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(data)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			ret = MPI_Bcast(FA_buf(data), count, FA_Type, root_rank, MPI_COMM_WORLD);
		} else {
			KNH_ARRAY_EXPAND(data, count);
			ret = MPI_Bcast(FA_tail(data), count, FA_Type, root_rank, MPI_COMM_WORLD);
			FA_size(data) += count;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.scatter(Bytes sdata, Int count, Bytes rdata, Int root_rank);
METHOD MPIContext_scatter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	knh_Bytes_t *rdata = sfp[3].ba;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		KNH_BYTES_EXPAND(rdata, count);
		ret = MPI_Scatter(BA_buf(sdata), count, BA_Type, BA_tail(rdata), count, BA_Type, root_rank, MPI_COMM_WORLD);
		BA_size(rdata) += count;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.scatterInt(IArray sdata, Int count, IArray rdata, Int root_rank);
METHOD MPIContext_scatterInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_IArray(rdata)) {
		KNH_ARRAY_EXPAND(rdata, count);
		ret = MPI_Scatter(IA_buf(sdata), count, IA_Type, IA_tail(rdata), count, IA_Type, root_rank, MPI_COMM_WORLD);
		IA_size(rdata) += count;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.scatterFloat(FArray sdata, Int count, FArray rdata, Int root_rank);
METHOD MPIContext_scatterFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata)) {
		KNH_ARRAY_EXPAND(rdata, count);
		ret = MPI_Scatter(FA_buf(sdata), count, FA_Type, FA_tail(rdata), count, FA_Type, root_rank, MPI_COMM_WORLD);
		FA_size(rdata) += count;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.gather(Bytes sdata, Int count, Bytes rdata, Int root_rank);
METHOD MPIContext_gather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	knh_Bytes_t *rdata = sfp[3].ba;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			int rcount = count * KNH_MPI_SIZE(mctx);
			KNH_BYTES_EXPAND(rdata, rcount);
			ret = MPI_Gather(BA_buf(sdata), count, BA_Type, BA_tail(rdata), count, BA_Type, root_rank, MPI_COMM_WORLD);
			BA_size(rdata) += rcount;
		} else {
			ret = MPI_Gather(BA_buf(sdata), count, BA_Type, NULL, count, BA_Type, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.gatherInt(IArray sdata, Int count, IArray rdata, Int root_rank);
METHOD MPIContext_gatherInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_IArray(rdata)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			int rcount = count * KNH_MPI_SIZE(mctx);
			KNH_ARRAY_EXPAND(rdata, rcount);
			ret = MPI_Gather(IA_buf(sdata), count, IA_Type, IA_tail(rdata), count, IA_Type, root_rank, MPI_COMM_WORLD);
			IA_size(rdata) += rcount;
		} else {
			ret = MPI_Gather(IA_buf(sdata), count, IA_Type, NULL, count, IA_Type, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.gatherFloat(FArray sdata, Int count, FArray rdata, Int root_rank);
METHOD MPIContext_gatherFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			int rcount = count * KNH_MPI_SIZE(mctx);
			KNH_ARRAY_EXPAND(rdata, rcount);
			ret = MPI_Gather(FA_buf(sdata), count, FA_Type, FA_tail(rdata), count, FA_Type, root_rank, MPI_COMM_WORLD);
			FA_size(rdata) += rcount;
		} else {
			ret = MPI_Gather(FA_buf(sdata), count, FA_Type, NULL, count, FA_Type, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allGather(Bytes sdata, Int count, Bytes rdata);
METHOD MPIContext_allGather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	knh_Bytes_t *rdata = sfp[3].ba;
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_BYTES_EXPAND(rdata, rcount);
		ret = MPI_Allgather(BA_buf(sdata), count, BA_Type, BA_tail(rdata), count, BA_Type, MPI_COMM_WORLD);
		BA_size(rdata) += rcount;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allGatherInt(IArray sdata, Int count, IArray rdata);
METHOD MPIContext_allGatherInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_FArray(rdata)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_ARRAY_EXPAND(rdata, rcount);
		ret = MPI_Allgather(IA_buf(sdata), count, IA_Type, IA_tail(rdata), count, IA_Type, MPI_COMM_WORLD);
		IA_size(rdata) += rcount;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allGatherFloat(FArray sdata, Int count, FArray rdata);
METHOD MPIContext_allGatherFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_ARRAY_EXPAND(rdata, rcount);
		ret = MPI_Allgather(FA_buf(sdata), count, FA_Type, FA_tail(rdata), count, FA_Type, MPI_COMM_WORLD);
		FA_size(rdata) += rcount;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allToAll(Bytes sdata, Int count, Bytes rdata);
METHOD MPIContext_allToAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	knh_Bytes_t *rdata = sfp[3].ba;
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_BYTES_EXPAND(rdata, rcount);
		ret = MPI_Alltoall(BA_buf(sdata), count, BA_Type, BA_tail(rdata), count, BA_Type, MPI_COMM_WORLD);
		BA_size(rdata) += rcount;
	}
	RETURNi_(0);
}

//## method Int MPIContext.allToAllInt(IArray sdata, Int count, IArray rdata);
METHOD MPIContext_allToAllInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_IArray(rdata)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_ARRAY_EXPAND(rdata, rcount);
		ret = MPI_Alltoall(IA_buf(sdata), count, IA_Type, IA_tail(rdata), count, IA_Type, MPI_COMM_WORLD);
		IA_size(rdata) += rcount;
	}
	RETURNi_(0);
}

//## method Int MPIContext.allToAllFloat(FArray sdata, Int count, FArray rdata);
METHOD MPIContext_allToAllFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	knh_Array_t *rdata = sfp[3].a;
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata)) {
		int rcount = count * KNH_MPI_SIZE(mctx);
		KNH_ARRAY_EXPAND(rdata, rcount);
		ret = MPI_Alltoall(FA_buf(sdata), count, FA_Type, FA_tail(rdata), count, FA_Type, MPI_COMM_WORLD);
		FA_size(rdata) += rcount;
	}
	RETURNi_(0);
}

//## method Int MPIContext.reduce(Bytes sdata, Bytes rdata, Int count, Int op, Int root_rank);
METHOD MPIContext_reduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	knh_Bytes_t *rdata = sfp[2].ba;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && KNH_MPI_IS_OP(op)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			KNH_BYTES_EXPAND(rdata, count);
			ret = MPI_Reduce(BA_buf(sdata), BA_tail(rdata), count, BA_Type, op, root_rank, MPI_COMM_WORLD);
			BA_size(rdata) += count;
		} else {
			ret = MPI_Reduce(BA_buf(sdata), NULL, count, BA_Type, op, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.reduceInt(IArray sdata, IArray rdata, Int count, Int op, Int root_rank);
METHOD MPIContext_reduceInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	knh_Array_t *rdata = sfp[2].a;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_IArray(rdata) && KNH_MPI_IS_OP(op)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			KNH_ARRAY_EXPAND(rdata, count);
			ret = MPI_Reduce(IA_buf(sdata), IA_tail(rdata), count, IA_Type, op, root_rank, MPI_COMM_WORLD);
			IA_size(rdata) += count;
		} else {
			ret = MPI_Reduce(IA_buf(sdata), NULL, count, IA_Type, op, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.reduceFloat(FArray sdata, FArray rdata, Int count, Int op, Int root_rank);
METHOD MPIContext_reduceFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	knh_Array_t *rdata = sfp[2].a;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata) && KNH_MPI_IS_OP(op)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			KNH_ARRAY_EXPAND(rdata, count);
			ret = MPI_Reduce(FA_buf(sdata), FA_tail(rdata), count, FA_Type, op, root_rank, MPI_COMM_WORLD);
			FA_size(rdata) += count;
		} else {
			ret = MPI_Reduce(FA_buf(sdata), NULL, count, FA_Type, op, root_rank, MPI_COMM_WORLD);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allReduce(Bytes sdata, Bytes rdata, Int count, Int op);
METHOD MPIContext_allReduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	knh_Bytes_t *rdata = sfp[2].ba;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && KNH_MPI_IS_OP(op)) {
		KNH_BYTES_EXPAND(rdata, count);
		ret = MPI_Allreduce(BA_buf(sdata), BA_tail(rdata), count, BA_Type, op, MPI_COMM_WORLD);
		BA_size(rdata) += count;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allReduceInt(IArray sdata, IArray rdata, Int count, Int op);
METHOD MPIContext_allReduceInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	knh_Array_t *rdata = sfp[2].a;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata) && IS_IArray(rdata) && KNH_MPI_IS_OP(op)) {
		KNH_ARRAY_EXPAND(rdata, count);
		ret = MPI_Allreduce(IA_buf(sdata), IA_tail(rdata), count, IA_Type, op, MPI_COMM_WORLD);
		IA_size(rdata) += count;
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allReduceFloat(FArray sdata, FArray rdata, Int count, Int op);
METHOD MPIContext_allReduceFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	knh_Array_t *rdata = sfp[2].a;
	int count = Int_to(int, sfp[3]);
	MPI_Op op = Int_to(MPI_Op, sfp[4]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata) && IS_FArray(rdata) && KNH_MPI_IS_OP(op)) {
		KNH_ARRAY_EXPAND(rdata, count);
		ret = MPI_Allreduce(FA_buf(sdata), FA_tail(rdata), count, FA_Type, op, MPI_COMM_WORLD);
		FA_size(rdata) += count;
	}
	RETURNi_(ret);
}




//## method Int MPIContext.bcastEx(Bytes sdata, Int root_rank);
METHOD MPIContext_bcastEx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *data = sfp[1].ba;
	int root_rank = Int_to(int, sfp[2]);
	int count, ret = 0;
	if (KNH_ON_MPI(mctx)) {
		if (KNH_MPI_RANK(mctx) == root_rank) {
			count = BA_size(data);
			MPI_Bcast(&count, 1, IA_Type, root_rank, MPI_COMM_WORLD); /* bcast for buffer_length */
			MPI_Bcast(BA_buf(data), count, BA_Type, root_rank, MPI_COMM_WORLD);
		} else {
			MPI_Bcast(&count, 1, IA_Type, root_rank, MPI_COMM_WORLD); /* bcast for buffer_length */
			KNH_BYTES_EXPAND(data, count);
			ret = MPI_Bcast(BA_tail(data), count, BA_Type, root_rank, MPI_COMM_WORLD);
			BA_size(data) += count;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.gatherEx(Bytes sdata, Bytes rdata, Int root_rank);
METHOD MPIContext_gatherEx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	knh_Bytes_t *rdata = sfp[2].ba;
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		int rcounts[KNH_MPI_SIZE(mctx)];
		int rdispls[KNH_MPI_SIZE(mctx)];
		size_t counts[KNH_MPI_SIZE(mctx)];
		ret = MPI_Allgather(&BA_size(sdata), 1, IA_Type, counts, 1, IA_Type, MPI_COMM_WORLD);
		if (KNH_MPI_SUCCESS(ret)) {
			int i, rcount = 0;
			for (i = 0; i < KNH_MPI_SIZE(mctx); i++) {
				rcounts[i] = (int)counts[i];
				rdispls[i] = rcount;
				rcount += (int)counts[i];
			}
			KNH_BYTES_EXPAND(rdata, rcount);
			ret = MPI_Gatherv(BA_buf(sdata), BA_size(sdata), BA_Type, BA_tail(rdata), rcounts, rdispls, BA_Type, root_rank, MPI_COMM_WORLD);
			BA_size(rdata) += rcount;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.allGatherEx(Bytes sdata, Bytes rdata);
METHOD MPIContext_allGatherEx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	knh_Bytes_t *rdata = sfp[2].ba;
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		int rcounts[KNH_MPI_SIZE(mctx)];
		int rdispls[KNH_MPI_SIZE(mctx)];
		size_t counts[KNH_MPI_SIZE(mctx)];
		ret = MPI_Allgather(&BA_size(sdata), 1, IA_Type, counts, 1, IA_Type, MPI_COMM_WORLD);
		if (KNH_MPI_SUCCESS(ret)) {
			int i, rcount = 0;
			for (i = 0; i < KNH_MPI_SIZE(mctx); i++) {
				rcounts[i] = (int)counts[i];
				rdispls[i] = rcount;
				rcount += (int)counts[i];
			}
			KNH_BYTES_EXPAND(rdata, rcount);
			ret = MPI_Allgatherv(BA_buf(sdata), BA_size(sdata), BA_Type, BA_tail(rdata), rcounts, rdispls, BA_Type, MPI_COMM_WORLD);
			BA_size(rdata) += rcount;
		}
	}
	RETURNi_(ret);
}
