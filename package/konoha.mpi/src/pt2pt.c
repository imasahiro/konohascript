#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#endif

/* ------------------------------------------------------------------------ */
//## method int MPIComm.send(MPIData sdata, int count, int dest, int tag);

KMETHOD MPIComm_send(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int dest_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPID_CCHK(sdata, count);
	RETURNi_(MPI_Send(MPID_ADDR(sdata), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm)));
}

/* ------------------------------------------------------------------------ */
//## method int MPIComm.recv(MPIData rdata, int offset, int count, int src_rank, int tag);

KMETHOD MPIComm_recv(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(rdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPI_Status stat;
	MPID_WCHK(rdata);
	if (MPI_Probe(src_rank, tag, MPIC_COMM(comm), &stat) == MPI_SUCCESS) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (rcount >= 0 && count > rcount) {
			KNH_NOTE("requested: %d > recieved %d", count, rcount);
			count = rcount;
		}
	} else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "MPI_Probe failed", K_FAILED, KNH_LDATA(LOG_i("source rank", src_rank), LOG_i("message tag", tag)));
		count = 0;
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &count, &inc);
	knh_MPIData_incSize(rdata, inc);
	RETURNi_(MPI_Recv(MPID_ADDR(rdata), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), &stat));
}

/* ------------------------------------------------------------------------ */
//## method int MPIComm.sendrecv(MPIData sdata, int scount, int dest_rank, int stag, MPIData rdata, int rcount, int src_rank,  int rtag);

KMETHOD MPIComm_sendrecv(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int scount = Int_to(int, sfp[2]);
	int dest_rank = Int_to(int, sfp[3]);
	int stag = Int_to(int, sfp[4]);
	MPID(rdata, sfp[5].o);
	int rcount = Int_to(int, sfp[6]);
	int src_rank = Int_to(int, sfp[7]);
	int rtag = Int_to(int, sfp[8]);
	MPID_CCHK(sdata, scount);
	MPID_WCHK(rdata);
	MPI_Status stat;
	{
		int rrcount = 0;
		MPI_Sendrecv(&scount, 1, MPI_INT, dest_rank, stag, &rrcount, 1, MPI_INT, src_rank, rtag, MPIC_COMM(comm), &stat);
		if (rcount > rrcount) {
			KNH_NOTE("requested: %d > recieved %d", rcount, rrcount);
			rcount = rrcount;
		}
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	RETURNi_(MPI_Sendrecv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), dest_rank, stag,
						  MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), src_rank, rtag, MPIC_COMM(comm), &stat));
}

/* ------------------------------------------------------------------------ */
//## method MPIRequest MPIComm.iSend(MPIData sdata, int count, int dest_rank, int tag, MPIRequest _);

KMETHOD MPIComm_iSend(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int dest_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPIR(req, new_O(MPIRequest, O_cid(sfp[5].o)));
	MPIR_DATA(req) = sdata;
	MPID_CCHK(sdata, count);
	MPI_Isend(MPID_ADDR(sdata), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm), MPIR_REQ(req));
	RETURN_(req);
}

/* ------------------------------------------------------------------------ */
//## method MPIRequest MPIComm.iRecv(MPIData rdata, int count, int src_rank, int tag, MPIRequest _);

KMETHOD MPIComm_iRecv(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(rdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPIR(req, new_O(MPIRequest, O_cid(sfp[5].o)));
	MPIR_DATA(req) = rdata;
	int flag = 0;
	MPI_Status stat;
	MPID_WCHK(rdata);
	MPI_Iprobe(src_rank, tag, MPIC_COMM(comm), &flag, &stat);
	if (flag) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (rcount >= 0 && count > rcount) {
			KNH_NOTE("requested: %d > recieved %d", count, rcount);
			count = rcount;
		}
	} else {
		// TODO: cancel MPI_Irecv if no message recieved
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &count, &inc);
	MPIR_INC(req) = inc;
	MPI_Irecv(MPID_ADDR(rdata), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), MPIR_REQ(req));
	RETURN_(req);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.test();

KMETHOD MPIRequest_test(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIR(req, sfp[0].o);
	MPI_Status stat;
	int flag, ret = 0;
	MPI_Test(MPIR_REQ(req), &flag, &stat);
	if (flag) {
		int count = 0;
		MPI_Get_count(&stat, MPIR_TYPE(req), &count);
		if (count >= 0 && MPIR_INC(req) > 0) {
			knh_MPIData_incSize(MPIR_DATA(req), count);
			MPIR_INC(req) = 0;
		}
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.wait();

KMETHOD MPIRequest_wait(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIR(req, sfp[0].o);
	MPI_Status stat;
	int ret = 0;
	if (MPI_Wait(MPIR_REQ(req), &stat) == MPI_SUCCESS) {
		int count = 0;
		MPI_Get_count(&stat, MPIR_TYPE(req), &count);
		if (count >= 0 && MPIR_INC(req) > 0) {
			knh_MPIData_incSize(MPIR_DATA(req), count);
			MPIR_INC(req) = 0;
		}
		ret = 1;
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.cancel();

KMETHOD MPIRequest_cancel(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIR(req, sfp[0].o);
	RETURNb_(MPI_Cancel(MPIR_REQ(req)) == MPI_SUCCESS ? 1 : 0);
}
