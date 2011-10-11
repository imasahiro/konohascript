#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method int MPIComm.send(MPIData sdata, int offset, int count, int dest, int tag);

KMETHOD MPIComm_send(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int offset = Int_to(int, sfp[2]);
	int count = Int_to(int, sfp[3]);
	int dest_rank = Int_to(int, sfp[4]);
	int tag = Int_to(int, sfp[5]);
	/*
	 * "............."  = SIZE   (must be > 0)
	 * "....|           = offset (must be < SIZE)
	 *      |===>       = count  (must be <= scount)
	 *      |===>...."  = scount (must be > 0) (if scount < count, count = scount)
	 */
	knh_MPIData_checkCount(sdata, offset, &count);
	RETURNi_(MPI_Send(MPID_ADDR(sdata, offset), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm)));
}

/* ------------------------------------------------------------------------ */
//## method int MPIComm.recv(MPIData rdata, int offset, int count, int src_rank, int tag);

KMETHOD MPIComm_recv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(rdata, sfp[1].o);
	int offset = Int_to(int, sfp[2]);
	int count = Int_to(int, sfp[3]);
	int src_rank = Int_to(int, sfp[4]);
	int tag = Int_to(int, sfp[5]);
	/*
	 * "aaaa"            = SIZE
	 *
	 * (case 1: capacity < offset + count)
	 * "aaaa"...         = capacity
	 * "aa|              = offset   (must be < SIZE)
	 *    |========>     = count    (must be < rcount) (if count > rcount, count = rcount)
	 *    |========>---> = rcount
	 *          ===>     = incl     (need to expand)
	 * "...........>     = newsize  (= capacity + incl > SIZE)
	 *
	 * (case 2: capacity > offset + count)
	 * "aaaa".........   = capacity
	 * "aa|              = offset   (must be < SIZE)
	 *    |====>         = count    (must be < rcount) (if count > rcount, count = rcount)
	 *    |====>--->     = rcount
	 *              <=   = incl     (need to expand)
	 * "...........>     = newsize  (= capacity + incl > SIZE)
	 */
	MPI_Status stat;
	if (MPI_Probe(src_rank, tag, MPIC_COMM(comm), &stat) == MPI_SUCCESS) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (count > rcount) count = rcount;
	} else {
		count = 0;
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, offset, &count, &inc);
	knh_MPIData_incSize(rdata, inc);
	RETURNi_(MPI_Recv(MPID_ADDR(rdata, offset), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), &stat));
}

/* ------------------------------------------------------------------------ */
//## method int MPIComm.sendrecv(MPIData sdata, int soffset, int scount, int dest_rank, int stag,
//##                             MPIData rdata, int roffset, int rcount, int src_rank,  int rtag);

KMETHOD MPIComm_sendrecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int soffset = Int_to(int, sfp[2]);
	int scount = Int_to(int, sfp[3]);
	int dest_rank = Int_to(int, sfp[4]);
	int stag = Int_to(int, sfp[5]);
	MPID(rdata, sfp[6].o);
	int roffset = Int_to(int, sfp[7]);
	int rcount = Int_to(int, sfp[8]);
	int src_rank = Int_to(int, sfp[9]);
	int rtag = Int_to(int, sfp[10]);
	/*
	 * "........"   = SIZE(sdata) (must be > 0)
	 * "..|         = soffset     (must be < SIZE(sdata))
	 *    |==>      = scount      (must be < sscount)
	 *    |==>.."   = sscount     (must be > 0) (if sscount < scount, scount = sscount)
	 *
	 * "aaaa"           = SIZE(rdata)
	 * "aaaa"...        = capacity
	 * "aa|             = roffset     (must be < SIZE(rdata))
	 *    |========>    = rcount      (must be < rrcount) (if rcount > rrcount, rcount = rrcount)
	 *    |========>--> = rrcount
	 *          ===>    = incl        (need to expand)
	 * "...........>    = newsize     (= capacity + incl)
	 */
	knh_MPIData_checkCount(sdata, soffset, &scount);
	MPI_Status stat;
	{
		int rrcount = 0;
		MPI_Sendrecv(&scount, 1, MPI_INT, dest_rank, stag, &rrcount, 1, MPI_INT, src_rank, rtag, MPIC_COMM(comm), &stat);
		if (rcount > rrcount) rcount = rrcount;
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, roffset, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	RETURNi_(MPI_Sendrecv(MPID_ADDR(sdata, soffset), scount, MPID_TYPE(sdata), dest_rank, stag,
						  MPID_ADDR(rdata, roffset), rcount, MPID_TYPE(rdata), src_rank, rtag, MPIC_COMM(comm), &stat));
}

/* ------------------------------------------------------------------------ */
//## method MPIRequest MPIComm.iSend(MPIData sdata, int offset, int count, int dest_rank, int tag, MPIRequest _);

KMETHOD MPIComm_iSend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int offset = Int_to(int, sfp[2]);
	int count = Int_to(int, sfp[3]);
	int dest_rank = Int_to(int, sfp[4]);
	int tag = Int_to(int, sfp[5]);
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)sfp[6].o;

	Request_new(ctx, req);
	MPIR_DATA(req) = sdata;
	knh_MPIData_checkCount(sdata, offset, &count);
	MPI_Isend(MPID_ADDR(sdata, offset), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm), MPIR_REQ(req));
	RETURN_(req);
}

/* ------------------------------------------------------------------------ */
//## method MPIRequest MPIComm.iRecv(MPIData rdata, int offset, int count, int src_rank, int tag, MPIRequest _);

KMETHOD MPIComm_iRecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(rdata, sfp[1].o);
	int offset = Int_to(int, sfp[2]);
	int count = Int_to(int, sfp[3]);
	int src_rank = Int_to(int, sfp[4]);
	int tag = Int_to(int, sfp[5]);
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)sfp[6].o;

	Request_new(ctx, req);
	MPIR_DATA(req) = rdata;
	int flag = 0;
	MPI_Status stat;
	MPI_Iprobe(src_rank, tag, MPIC_COMM(comm), &flag, &stat);
	if (flag) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (count > rcount) count = rcount;
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, offset, &count, &inc);
	MPIR_INC(req) = inc;
	MPI_Irecv(MPID_ADDR(rdata, offset), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), MPIR_REQ(req));
	RETURN_(req);
}

/* ======================================================================== */
/* Request */

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.test();

KMETHOD MPIRequest_test(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)sfp[0].o;
	MPI_Status stat;
	int flag, ret = 0;
	MPI_Test(MPIR_REQ(req), &flag, &stat);
	if (flag) {
		int count;
		MPI_Get_count(&stat, MPIR_TYPE(req), &count);
		if (MPIR_INC(req) > 0) {
			knh_MPIData_incSize(MPIR_DATA(req), count);
			MPIR_INC(req) = 0;
		}
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.wait();

KMETHOD MPIRequest_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)sfp[0].o;
	MPI_Status stat;
	int ret = 0;
	if (MPI_Wait(MPIR_REQ(req), &stat) == MPI_SUCCESS) {
		int count;
		MPI_Get_count(&stat, MPIR_TYPE(req), &count);
		if (MPIR_INC(req) > 0) {
			knh_MPIData_incSize(MPIR_DATA(req), count);
			MPIR_INC(req) = 0;
		}
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.cancel();

KMETHOD MPIRequest_cancel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIRequest_t *req = (knh_MPIRequest_t*)sfp[0].o;
	RETURNb_(MPI_Cancel(MPIR_REQ(req)) == MPI_SUCCESS ? 1 : 0);
}
