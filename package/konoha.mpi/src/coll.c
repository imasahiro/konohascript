#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.bcast(MPIData data, int count, int root_rank);

KMETHOD MPIComm_bcast(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(data, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int root_rank = Int_to(int, sfp[3]);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	if (MPIC_RANK(comm) == root_rank) {
		// if count > size, must cut down the number and bcast it
		if (count == 0) {
			count = MPID_SIZE(data);
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		ret = MPI_Bcast(MPID_ADDR(data), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
	} else {
		MPID_CHK_WRITABLE(data);
		if (count == 0) {
			MPI_Bcast(&count, 1, MPI_INT, root_rank, MPIC_COMM(comm)); /* bcast for buffer_length */
		}
		int inc = 0;
		knh_MPIData_expand(ctx, data, &count, &inc);
		knh_MPIData_incSize(data, inc);
		ret = MPI_Bcast(MPID_ADDR(data), count, MPID_TYPE(data), root_rank, MPIC_COMM(comm));
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Bcast", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("count", count), LOG_p("datatype", MPID_TYPE(data)), LOG_i("root_rank", root_rank)));
#endif
	RETURNb_(ret == MPI_SUCCESS);
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
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	MPID_CHK_WRITABLE(rdata);
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
	ret = MPI_Scatter(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Scatter", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("scount", scount), LOG_p("sdatatype", MPID_TYPE(sdata)),
						  LOG_i("rcount", rcount), LOG_p("rdatatype", MPID_TYPE(rdata)),
						  LOG_i("root_rank", root_rank)));
#endif
	RETURNb_(ret == MPI_SUCCESS);
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
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		if (MPIC_RANK(comm) == root_rank) {
			MPID_CHK_WRITABLE(rdata);
			int inc, rrcount = rcount * MPIC_SIZE(comm);
			knh_MPIData_expand(ctx, rdata,  &rrcount, &inc);
			knh_MPIData_incSize(rdata, inc);
			ret = MPI_Gather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata),
							 MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
		} else {
			ret = MPI_Gather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), NULL, 0, 0, root_rank, MPIC_COMM(comm));
		}
	} else {
		scount = MPID_SIZE(sdata);
		if (MPIC_RANK(comm) == root_rank) {
			MPID_CHK_WRITABLE(rdata);
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
			ret = MPI_Gatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata),
							  MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), root_rank, MPIC_COMM(comm));
		}
		else {
			MPI_Gather(&scount, 1, MPI_INT, NULL, 0, MPI_INT, root_rank, MPIC_COMM(comm));
			ret = MPI_Gatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), NULL, NULL, NULL, 0, root_rank, MPIC_COMM(comm));
		}
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Gather", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("scount", scount), LOG_p("sdatatype", MPID_TYPE(sdata)),
						  LOG_i("rcount", rcount), LOG_p("rdatatype", MPID_TYPE(rdata)),
						  LOG_i("root_rank", root_rank)));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.allGather(MPIData sdata, int scount, MPIData rdata, int rcount);

KMETHOD MPIComm_allGather(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	MPID_CHK_WRITABLE(rdata);
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		int inc, rrcount = rcount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		ret = MPI_Allgather(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
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
		ret = MPI_Allgatherv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Allgather", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("scount", scount), LOG_p("sdatatype", MPID_TYPE(sdata)),
						  LOG_i("rcount", rcount), LOG_p("rdatatype", MPID_TYPE(rdata))));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.allToAll(MPIData sdata, int scount, MPIData rdata, int rcount);

KMETHOD MPIComm_allToAll(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	MPID(rdata, sfp[3].o);
	int rcount = Int_to(int, sfp[4]);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	MPID_CHK_WRITABLE(rdata);
	if (scount > 0) {
		// if scount > size, must cut down the number and bcast it
		int inc, rrcount = scount * MPIC_SIZE(comm);
		knh_MPIData_expand(ctx, rdata, &rrcount, &inc);
		knh_MPIData_incSize(rdata, inc);
		ret = MPI_Alltoall(MPID_ADDR(sdata), scount, MPID_TYPE(sdata),
						   MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIC_COMM(comm));
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
		ret = MPI_Alltoallv(MPID_ADDR(sdata), scounts, sdispls, MPID_TYPE(sdata),
							MPID_ADDR(rdata), rcounts, rdispls, MPID_TYPE(rdata), MPIC_COMM(comm));
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Alltoall", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("scount", scount), LOG_p("sdatatype", MPID_TYPE(sdata)),
						  LOG_i("rcount", rcount), LOG_p("rdatatype", MPID_TYPE(rdata))));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.reduce(MPIData sdata, MPIData rdata, int count, MPIOp op, int root_rank);

KMETHOD MPIComm_reduce(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	int count = Int_to(int, sfp[3]);
	MPIO(op, sfp[4].o);
	int root_rank = Int_to(int, sfp[5]);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	if (count == 0) {
		int size = MPID_SIZE(sdata);
		MPI_Allreduce(&size, &count, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	if (MPIC_RANK(comm) == root_rank) {
		MPID_CHK_WRITABLE(rdata);
		int inc = 0;
		knh_MPIData_expand(ctx, rdata, &count, &inc);
		knh_MPIData_incSize(rdata, inc);
		ret = MPI_Reduce(MPID_ADDR(sdata), MPID_ADDR(rdata), count, MPID_TYPE(sdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
	} else {
		ret = MPI_Reduce(MPID_ADDR(sdata), NULL, count, MPID_TYPE(sdata), MPIO_OP(op), root_rank, MPIC_COMM(comm));
	}
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Reduce", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("count", count), LOG_p("datatype", MPID_TYPE(sdata)), LOG_i("root_rank", root_rank)));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.scan(MPIData sdata, MPIData rdata, int rcount, MPIOp op);

KMETHOD MPIComm_scan(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	int rcount = Int_to(int, sfp[3]);
	MPIO(op, sfp[4].o);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	MPID_CHK_WRITABLE(rdata);
	if (rcount == 0) {
		int size = MPID_SIZE(sdata);
		MPI_Allreduce(&size, &rcount, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	int inc;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	ret = MPI_Scan(MPID_ADDR(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIO_OP(op), MPIC_COMM(comm));
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Scan", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("count", rcount), LOG_p("datatype", MPID_TYPE(sdata))));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.allReduce(MPIData sdata, MPIData rdata, int rcount, MPIOp op);

KMETHOD MPIComm_allReduce(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	int rcount = Int_to(int, sfp[3]);
	MPIO(op, sfp[4].o);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	MPID_CHK_WRITABLE(rdata);
	if (rcount == 0) {
		int size = MPID_SIZE(sdata);
		MPI_Allreduce(&size, &rcount, 1, MPI_INT, MPI_MIN, MPIC_COMM(comm)); /* get mininum data cont */
	}
	int inc;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	ret = MPI_Allreduce(MPID_ADDR(sdata), MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), MPIO_OP(op), MPIC_COMM(comm));
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Allreduce", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("count", rcount), LOG_p("datatype", MPID_TYPE(sdata))));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.reduceScatter(MPIData sdata, MPIData rdata, int[] rcounts, MPIOp op);

KMETHOD MPIComm_reduceScatter(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	MPID(rdata, sfp[2].o);
	kArray *rcs = sfp[3].a;
	MPIO(op, sfp[4].o);
	int ret = 0;
#ifdef KNH_MPI_PROFILE
	double _begin = MPI_Wtime();
#endif
	size_t rsize = knh_Array_size(rcs);
	size_t csize = MPIC_SIZE(comm);
	int i, rcount, rsum, rcounts[csize];
	if (rsize == csize) {
		for (i = 0, rsum = 0; i < rsize; i++) {
			int rc_n = (int)((kint_t)knh_Array_n(rcs, i));
			rsum += rc_n;
			rcounts[i] = rc_n;
		}
		if (rsum > MPID_SIZE(sdata)) {
			KNH_NTHROW2(ctx, sfp, "Script!!", "MPIComm.reduceScatter: sdata < rcounts", K_FAILED,
						KNH_LDATA(LOG_i("size of sdata", MPID_SIZE(sdata)), LOG_i("sum of rcount", rsum)));
		}
	} else if(rsize == 0) {
		size_t dsize = MPID_SIZE(sdata);
		int d = (dsize / csize) + 1;
		int m = dsize % csize;
		for (i = 0; i < m; rcounts[i++] = d) ;
		for (d--; i < csize; rcounts[i++] = d) ;
	} else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "MPIComm.reduceScatter: |comm| < |rcounts|", K_FAILED,
					KNH_LDATA(LOG_i("size of comm", MPIC_SIZE(comm)), LOG_i("size of rcount", rsize)));
	}
	MPID_CHK_WRITABLE(rdata);
	rcount = rcounts[MPIC_RANK(comm)];
	int inc;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	ret = MPI_Reduce_scatter(MPID_ADDR(sdata), MPID_ADDR(rdata), &rcounts[0], MPID_TYPE(sdata), MPIO_OP(op), MPIC_COMM(comm));
#ifdef KNH_MPI_PROFILE
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Reduce_scatter", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("rcount", rcount), LOG_p("datatype", MPID_TYPE(sdata))));
#endif
	RETURNb_(ret == MPI_SUCCESS);
}
