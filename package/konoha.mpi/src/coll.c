#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.bcast(MPIData data, int offset, int count, int root_rank);

KMETHOD MPIComm_bcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(data, sfp[1].o);
	int offset = Int_to(int, sfp[2]);
	int count = Int_to(int, sfp[3]);
	int root_rank = Int_to(int, sfp[4]);
	int ret = 0;
	if (MPIC_RANK(comm) == root_rank) {
		if (count == 0) {
			count = MPID_SIZE(data) - offset;
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		MPI_Bcast(MPID_ADDR(data, offset), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
		ret = 1;
	} else {
		if (count == 0) {
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		int inc = 0;
		knh_MPIData_expand(ctx, data, offset, &count, &inc);
		knh_MPIData_incSize(data, inc);
		MPI_Bcast(MPID_ADDR(data, offset), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.scatter(MPIData sdata, int soffset, int scount, MPIData rdata, int roffset, int rcount, int root_rank);

KMETHOD MPIComm_scatter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	int scount = Int_to(int, sfp[3]);
	MPID(rdata, sfp[4].o);
	int roffset = Int_to(int, sfp[5]);
	int rcount = Int_to(int, sfp[6]);
	int root_rank = Int_to(int, sfp[7]);
	int ret = 0;
	if (scount == 0) {
		if (MPIC_RANK(comm) == root_rank) {
			int ssize = MPID_SIZE(sdata) - soffset;
			scount = ssize / MPIC_SIZE(comm);
			if (ssize % MPIC_SIZE(comm) != 0) scount++;
		}
		MPI_Bcast(&scount, 1, MPI_INT, root_rank, MPIC_COMM(comm));
	}
	if (rcount == 0) rcount = scount;
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, roffset, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	MPI_Scatter(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
	ret = 1;
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.gather(MPIData sdata, int soffset, int scount,
//##                               MPIData rdata, int roffset, int rcount, int root_rank);

KMETHOD MPIComm_gather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	int scount = Int_to(int, sfp[3]);
	MPID(rdata, sfp[4].o);
	int roffset = Int_to(int, sfp[5]);
	int rcount = Int_to(int, sfp[6]);
	int root_rank = Int_to(int, sfp[7]);
	int ret = 0;
	if (scount > 0) {
		if (MPIC_RANK(comm) == root_rank) {
			knh_MPIData_checkCount(sdata, soffset, &scount);
			int inc, rrcount = rcount * MPIC_SIZE(comm);
			knh_MPIData_expand(ctx, rdata, roffset, &rrcount, &inc);
			knh_MPIData_incSize(rdata, inc);
			MPI_Gather(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata),
					   MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
			ret = 1;
		} else {
			knh_MPIData_checkCount(sdata, soffset, &scount);
			MPI_Gather(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), NULL, 0, 0, root_rank, MPIC_COMM(comm));
			ret = 1;
		}
	} else {
		scount = MPID_SIZE(sdata) - soffset;
		if (MPIC_RANK(comm) == root_rank) {
			knh_MPIData_checkCount(sdata, soffset, &scount);
			int rcounts[MPIC_SIZE(comm)];
			int rdispls[MPIC_SIZE(comm)];
			MPI_Gather(&scount, 1, MPI_INT, rcounts, 1, MPI_INT, root_rank, MPIC_COMM(comm));
			int i, rsum = 0;
			for (i = 0; i < MPIC_SIZE(comm); i++) {
				int rc = rcounts[i];
				rdispls[i] = rsum;
				rsum += rc;
			}
			int inc;
			knh_MPIData_expand(ctx, rdata, roffset, &rsum, &inc);
			knh_MPIData_incSize(rdata, inc);
			if (rsum == 0) { // if modified in knh_MPIData_expand
				for (i = 0; i < MPIC_SIZE(comm); i++) {
					rcounts[i] = 0;
					rdispls[i] = 0;
				}
			}
			MPI_Gatherv(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata),
						MPID_ADDR(rdata, roffset), rcounts, rdispls, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
			ret = 1;
		}
		else {
			knh_MPIData_checkCount(sdata, soffset, &scount);
			MPI_Gather(&scount, 1, MPI_INT, NULL, 0, MPI_INT, root_rank, MPIC_COMM(comm));
			MPI_Gatherv(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), NULL, NULL, NULL, 0, root_rank, MPIC_COMM(comm));
			ret = 1;
		}
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGather(MPIData sdata, int soffset, int scount, MPIData rdata, int roffset, int rcount);

KMETHOD MPIComm_allGather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	int scount = Int_to(int, sfp[3]);
	MPID(rdata, sfp[4].o);
	int roffset = Int_to(int, sfp[5]);
	int rcount = Int_to(int, sfp[6]);
	int ret = 0;
	if (scount > 0) {
		knh_MPIData_checkCount(sdata, soffset, &scount);
		int inc, rrcount = rcount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, roffset, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Allgather(MPID_ADDR(sdata ,soffset), scount, MPID_TYPE(sdata), MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	} else {
		int rcounts[MPIC_SIZE(comm)];
		int rdispls[MPIC_SIZE(comm)];
		scount = MPID_SIZE(sdata) - soffset;
		knh_MPIData_checkCount(sdata, soffset, &scount);
		MPI_Allgather(&scount, 1, MPI_INT, rcounts, 1, MPI_INT, MPIC_COMM(comm));
		int i, rsum = 0;
		for (i = 0; i < MPIC_SIZE(comm); i++) {
			int rc = rcounts[i];
			rdispls[i] = rsum;
			rsum += rc;
		}
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, roffset, &rsum, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Allgatherv(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), MPID_ADDR(rdata, roffset), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAll(MPIData sdata, int soffset, int scount, MPIData rdata, int roffset, int rcount);

KMETHOD MPIComm_allToAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	int scount = Int_to(int, sfp[3]);
	MPID(rdata, sfp[4].o);
	int roffset = Int_to(int, sfp[5]);
	int rcount = Int_to(int, sfp[6]);
	int ret = 0;
	if (scount > 0) {
		knh_MPIData_checkCount(sdata, soffset, &scount);
		int inc, rrcount = scount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, roffset, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Alltoall(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	} else {
		size_t size = MPIC_SIZE(comm);
		int scounts[size];
		int sdispls[size];
		int rcounts[size];
		int rdispls[size];
		scount = MPID_SIZE(sdata) - soffset;
		knh_MPIData_checkCount(sdata, soffset, &scount);
		int quot = scount / size;
		int mod = scount % size;
		int r, rsum = 0;
		for (r = 0, rsum = 0; r < size; r++) {
			int wc = quot + ((r < mod) ? 1 : 0);
			scounts[r] = wc;
			sdispls[r] = rsum;
			rsum += wc;
		}
		MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, MPIC_COMM(comm));
		for (r = 0, rsum = 0; r < size; r++) {
			int wc = rcounts[r];
			rdispls[r] = rsum;
			rsum += wc;
		}
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, roffset, &rsum, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Alltoallv(MPID_ADDR(sdata, soffset), scounts, sdispls, MPID_TYPE(sdata), MPID_ADDR(rdata, roffset), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduce(MPIData sdata, int soffset, MPIData rdata, int roffset, int count, MPIOp op, int root_rank);

KMETHOD MPIComm_reduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int roffset = Int_to(int, sfp[4]);
	int rcount = Int_to(int, sfp[5]);
	MPIO(op, sfp[6].o);
	int root_rank = Int_to(int, sfp[7]);
	int ret = 0;
	if (rcount == 0) {
		int size = MPID_SIZE(sdata) - soffset;
		knh_MPIData_checkCount(sdata, soffset, &size);
		MPI_Allreduce(&size, &rcount, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	if (MPIC_RANK(comm) == root_rank) {
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, roffset, &rcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Reduce(MPID_ADDR(sdata, soffset), MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
		ret = 1;
	} else {
		MPI_Reduce(MPID_ADDR(sdata, soffset), NULL, rcount, MPID_TYPE(sdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduce(MPIData sdata, int soffset, MPIData rdata, int roffset, int rcount, MPIOp op);

KMETHOD MPIComm_allReduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int roffset = Int_to(int, sfp[4]);
	int rcount = Int_to(int, sfp[5]);
	MPIO(op, sfp[6].o);
	int ret = 0;
	if (rcount == 0) {
		int size = MPID_SIZE(sdata) - soffset;
		MPI_Allreduce(&size, &rcount, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	int inc;
	knh_MPIData_expand(ctx, rdata, roffset, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	MPI_Allreduce(MPID_ADDR(sdata, soffset), MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), MPIO_OP(op), MPIC_COMM(comm));
	ret = 1;
	RETURNb_(ret);
}
