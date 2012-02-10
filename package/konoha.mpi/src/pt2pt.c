#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.send(MPIData sdata, int count, int dest_rank, int tag);

KMETHOD MPIComm_send(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(sdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int dest_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPID_CCHK(sdata, count);
	double _begin = MPI_Wtime();
	int ret = MPI_Send(MPID_ADDR(sdata), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm));
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Send", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish),
						  LOG_f("duration", _duration), LOG_i("myrank", MPIC_RANK(comm)),
						  LOG_i("count", count), LOG_p("datatype", MPID_TYPE(sdata)), LOG_i("dest_rank", dest_rank), LOG_i("tag", tag)));
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.recv(MPIData rdata, int count, int src_rank, int tag);

KMETHOD MPIComm_recv(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIC(comm, sfp[0].o);
	MPID(rdata, sfp[1].o);
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	int tag = Int_to(int, sfp[4]);
	MPI_Status stat;
	MPID_WCHK(rdata);
	double _begin = MPI_Wtime();
	if (MPI_Probe(src_rank, tag, MPIC_COMM(comm), &stat) == MPI_SUCCESS) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (count <= 0) {
			count = rcount;
		} else if (rcount >= 0 && count > rcount) {
			KNH_NOTE("requested: %d > recieved %d", count, rcount);
			count = rcount;
		}
		tag = MPIS_TAG(stat);
	} else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "MPI_Probe failed", K_FAILED, KNH_LDATA(LOG_i("source rank", src_rank), LOG_i("message tag", tag)));
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &count, &inc);
	knh_MPIData_incSize(rdata, inc);
	double _ready = MPI_Wtime();
	int ret = MPI_Recv(MPID_ADDR(rdata), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), &stat);
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Recv", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("ready", _ready), LOG_f("finish", _finish),
						  LOG_f("duration", _duration), LOG_i("myrank", MPIC_RANK(comm)),
						  LOG_i("count", count), LOG_p("datatype", MPID_TYPE(rdata)), LOG_i("src_rank", src_rank), LOG_i("tag", tag)));
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIComm.sendrecv(MPIData sdata, int scount, int dest_rank, int stag, MPIData rdata, int rcount, int src_rank,  int rtag);

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
	double _begin = MPI_Wtime();
	MPI_Status stat;
	{
		int rrcount = 0;
		MPI_Sendrecv(&scount, 1, MPI_INT, dest_rank, stag, &rrcount, 1, MPI_INT, src_rank, rtag, MPIC_COMM(comm), &stat);
		if (rcount > rrcount) {
			KNH_NOTE("assigned count is greater than recieved (%d > %d): use recieved count", rcount, rrcount);
			rcount = rrcount;
		}
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &rcount, &inc);
	knh_MPIData_incSize(rdata, inc);
	double _ready = MPI_Wtime();
	int ret = MPI_Sendrecv(MPID_ADDR(sdata), scount, MPID_TYPE(sdata), dest_rank, stag,
						   MPID_ADDR(rdata), rcount, MPID_TYPE(rdata), src_rank, rtag, MPIC_COMM(comm), &stat);
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Sendrecv", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("ready", _ready), LOG_f("finish", _finish),
						  LOG_f("duration", _duration), LOG_i("myrank", MPIC_RANK(comm)),
						  LOG_i("scount", scount), LOG_p("sdatatype", MPID_TYPE(sdata)), LOG_i("dest_rank", dest_rank), LOG_i("stag", stag),
						  LOG_i("rcount", rcount), LOG_p("rdatatype", MPID_TYPE(rdata)), LOG_i("src_rank", src_rank), LOG_i("rtag", rtag)));
	RETURNb_(ret == MPI_SUCCESS);
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
	double _begin = MPI_Wtime();
	MPI_Isend(MPID_ADDR(sdata), count, MPID_TYPE(sdata), dest_rank, tag, MPIC_COMM(comm), &MPIR_REQ(req));
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Isend", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish),
						  LOG_f("duration", _duration), LOG_i("myrank", MPIC_RANK(comm)),
						  LOG_i("scount", count), LOG_p("sdatatype", MPID_TYPE(sdata)), LOG_i("dest_rank", dest_rank), LOG_i("stag", tag)));
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
	double _begin = MPI_Wtime();
	MPI_Iprobe(src_rank, tag, MPIC_COMM(comm), &flag, &stat);
	if (flag) {
		int rcount = 0;
		MPI_Get_count(&stat, MPID_TYPE(rdata), &rcount);
		if (rcount >= 0 && count > rcount) {
			KNH_NOTE("requested: %d > recieved %d", count, rcount);
			count = rcount;
		}
	} else if (count > 0) {
		KNH_NOTE("MPI_Iprobe failed: cancel confirming number of count");
	} else {
		KNH_NTHROW2(ctx, sfp, "Script!!", "MPI_Irecv: number of count is zero", K_FAILED, KNH_LDATA0);
	}
	int inc = 0;
	knh_MPIData_expand(ctx, rdata, &count, &inc);
	MPIR_INC(req) = inc;
	double _ready = MPI_Wtime();
	MPI_Irecv(MPID_ADDR(rdata), count, MPID_TYPE(rdata), src_rank, tag, MPIC_COMM(comm), &MPIR_REQ(req));
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Irecv", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("ready", _ready), LOG_f("finish", _finish),
						  LOG_f("duration", _duration), LOG_i("myrank", MPIC_RANK(comm)),
						  LOG_i("count", count), LOG_p("datatype", MPID_TYPE(rdata)), LOG_i("src_rank", src_rank), LOG_i("tag", tag)));
	RETURN_(req);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.test();

KMETHOD MPIRequest_test(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIR(req, sfp[0].o);
	MPI_Status stat;
	int flag, ret = 0;
	MPI_Test(&MPIR_REQ(req), &flag, &stat);
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
	double _begin = MPI_Wtime();
	int ret = MPI_Wait(&MPIR_REQ(req), &stat);
	int count = -1;
	MPI_Get_count(&stat, MPIR_TYPE(req), &count);
	if (count >= 0 && MPIR_INC(req) > 0) {
		knh_MPIData_incSize(MPIR_DATA(req), count);
		MPIR_INC(req) = 0;
	}
	double _finish = MPI_Wtime();
	double _duration = _finish - _begin;
	KNH_NTRACE2(ctx, "MPI_Wait", K_NOTICE,
				KNH_LDATA(LOG_f("begin", _begin), LOG_f("finish", _finish), LOG_f("duration", _duration),
						  LOG_i("count", count), LOG_p("datatype", MPIR_TYPE(req)),
						  LOG_i("src_rank", MPIS_SRC(stat)), LOG_i("tag", MPIS_TAG(stat))));
	RETURNb_(ret == MPI_SUCCESS);
}

/* ------------------------------------------------------------------------ */
//## method boolean MPIRequest.cancel();

KMETHOD MPIRequest_cancel(CTX ctx, ksfp_t *sfp _RIX)
{
	MPIR(req, sfp[0].o);
	RETURNb_(MPI_Cancel(&MPIR_REQ(req)) == MPI_SUCCESS ? 1 : 0);
}
