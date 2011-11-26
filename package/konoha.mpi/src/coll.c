#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#endif

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.bcast(MPIData data, int count, int root_rank);

KMETHOD MPIComm_bcast(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(data, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
	if (MPIC_RANK(comm) == root_rank) {
		// if count > size, must cut down the number and bcast it
		if (count == 0) {
			count = MPID_SIZE(data);
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		MPI_Bcast(MPID_ADDR(data), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
		ret = 1;
	} else {
		MPID_WCHK(data);
		if (count == 0) {
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		int inc = 0;
		knh_MPIData_expand(ctx, data, &count, &inc);
		knh_MPIData_incSize(data, inc);
		MPI_Bcast(MPID_ADDR(data), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.scatter(MPIData sdata, int scount, MPIData rdata, int rcount, int root_rank);

KMETHOD MPIComm_scatter(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	MPID_WCHK(rdata);
	// if scount > size, must cut down the number and bcast it
	if (scount == 0) {
		if (MPIC_RANK(comm) == root_rank) {
			int ssize = MPID_SIZE(sdata);
			scount = ssize / MPIC_SIZE(comm);
			if (ssize % MPIC_SIZE(comm) != 0) scount++;
		}
		MPI_Bcast(&scount, 1, MPI_INT, root_rank, MPIC_COMM(comm));
	}
	if (rcount == 0) rcount = scount;
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	MPI_Scatter(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
	ret = 1;
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.gather(MPIData sdata, int scount, MPIData rdata, int rcount, int root_rank);

KMETHOD MPIComm_gather(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		if (MPIC_RANK(comm) == root_rank) {
			MPID_WCHK(rdata);
			int inc, rrcount = rcount * MPIC_SIZE(comm);
			knh_MPIData_expand(ctx, rdata,  &rrcount, &inc);
			knh_MPIData_incSize(rdata, inc);
			MPI_Gather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata),
					   MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
			ret = 1;
		} else {
			MPI_Gather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), NULL, 0, 0, root_rank, MPIC_COMM(comm));
			ret = 1;
		}
	} else {
		scount = MPID_SIZE(sdata);
		if (MPIC_RANK(comm) == root_rank) {
			MPID_WCHK(rdata);
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
			knh_MPIData_expand(ctx, rdata, &rsum, &inc);
			knh_MPIData_incSize(rdata, inc);
			if (rsum == 0) { // if modified in knh_MPIData_expand
				for (i = 0; i < MPIC_SIZE(comm); i++) {
					rcounts[i] = 0;
					rdispls[i] = 0;
				}
			}
			MPI_Gatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata),
						MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
			ret = 1;
		}
		else {
			MPI_Gather(&scount, 1, MPI_INT, NULL, 0, MPI_INT, root_rank, MPIC_COMM(comm));
			MPI_Gatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), NULL, NULL, NULL, 0, root_rank, MPIC_COMM(comm));
			ret = 1;
		}
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGather(MPIData sdata, int scount, MPIData rdata, int rcount);

KMETHOD MPIComm_allGather(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int ret = 0;
	MPID_WCHK(rdata);
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		int inc, rrcount = rcount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Allgather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	} else {
		int rcounts[MPIC_SIZE(comm)];
		int rdispls[MPIC_SIZE(comm)];
		scount = MPID_SIZE(sdata);
		MPI_Allgather(&scount, 1, MPI_INT, rcounts, 1, MPI_INT, MPIC_COMM(comm));
		int i, rsum = 0;
		for (i = 0; i < MPIC_SIZE(comm); i++) {
			int rc = rcounts[i];
			rdispls[i] = rsum;
			rsum += rc;
		}
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, &rsum, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Allgatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAll(MPIData sdata, int scount, MPIData rdata, int rcount);

KMETHOD MPIComm_allToAll(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int ret = 0;
	MPID_WCHK(rdata);
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		int inc, rrcount = scount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Alltoall(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	} else {
		scount = MPID_SIZE(sdata);
		size_t size = MPIC_SIZE(comm);
		int scounts[size], sdispls[size], rcounts[size], rdispls[size];
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
		knh_MPIData_expand(ctx, rdata, &rsum, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Alltoallv(MPID_ADDR(sdata), scounts, sdispls, MPID_TYPE(sdata), MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduce(MPIData sdata, MPIData rdata, int count, MPIOp op, int root_rank);

KMETHOD MPIComm_reduce(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	int count = Int_to(int, sfp[3]);
	MPIO(op, sfp[4].o);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
	if (count == 0) {
		int size = MPID_SIZE(sdata);
		MPI_Allreduce(&size, &count, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	if (MPIC_RANK(comm) == root_rank) {
		MPID_WCHK(rdata);
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, &count, &inc);
		knh_MPIData_incSize(rdata, inc);
		MPI_Reduce(MPID_ADDR(sdata), MPID_ADDR(rdata), count, MPID_TYPE(sdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
		ret = 1;
	} else {
		MPI_Reduce(MPID_ADDR(sdata), NULL, count, MPID_TYPE(sdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduce(MPIData sdata, MPIData rdata, int rcount, MPIOp op);

KMETHOD MPIComm_allReduce(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	int rcount = Int_to(int, sfp[3]);
	MPIO(op, sfp[4].o);
	int ret = 0;
	MPID_WCHK(rdata);
	if (rcount == 0) {
		int size = MPID_SIZE(sdata);
		MPI_Allreduce(&size, &rcount, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	int inc;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	MPI_Allreduce(MPID_ADDR(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIO_OP(op), MPIC_COMM(comm));
	ret = 1;
	RETURNb_(ret);
}
