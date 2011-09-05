#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */

static int knh_MPI_SendBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	if (IS_String(sdata)) {
		knh_String_t * s = (knh_String_t*)sdata;
		if (count == 0) count = s->str.len;
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(s->str.ubuf, count, BA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
	else {
		BA(data, sdata);
		if (count == 0) count = BA_size(data);
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(BA_buf(data), count, BA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
}

static int knh_MPI_SendInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	if (IS_IArray(sdata)) {
		IA(data, sdata);
		if (count == 0) count = IA_size(data);
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(IA_buf(data), count, IA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
	else { /* IS_Int(sdata) */
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(&O_data(sdata), 1, IA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
}

static int knh_MPI_SendFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	if (IS_FArray(sdata)) {
		FA(data, sdata);
		if (count == 0) count = FA_size(data);
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(FA_buf(data), count, FA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
	else { /* IS_Float(sdata) */
		return (KNH_ON_MPI(comm)) ?
			MPI_Send(&O_data(sdata), 1, FA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
	}
}

static int knh_MPI_RecvBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag)
{
	COMM(comm, c);
	BA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			if (count == 0) MPI_Get_count(&stat, BA_Type, &count);
			int incl = count - BA_size(rdata);
			if (incl <= 0) {
				ret = MPI_Recv(BA_buf(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			} else {
				KNH_BA_EXPAND(rdata, incl);
				ret = MPI_Recv(BA_buf(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
				BA_size(rdata) += incl;
			}
		}
	}
	return ret;
}

static int knh_MPI_RecvInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag)
{
	COMM(comm, c);
	IA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			if (count == 0) MPI_Get_count(&stat, IA_Type, &count);
			int incl = count - IA_size(rdata);
			if (incl <= 0) {
				ret = MPI_Recv(IA_buf(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			} else {
				KNH_IA_EXPAND(rdata, incl);
				ret = MPI_Recv(IA_buf(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
				IA_size(rdata) += incl;
			}
		}
	}
	return ret;
}

static int knh_MPI_RecvFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag)
{
	COMM(comm, c);
	FA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			if (count == 0) MPI_Get_count(&stat, FA_Type, &count);
			int incl = count - FA_size(rdata);
			if (incl <= 0) {
				ret = MPI_Recv(FA_buf(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			} else {
				KNH_FA_EXPAND(rdata, incl);
				ret = MPI_Recv(FA_buf(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
				FA_size(rdata) += incl;
			}
		}
	}
	return ret;
}

static int knh_MPI_Sendrecv_getRecvCount(knh_MPIComm_t *comm, int scount, int dest_rank, int src_rank, int dest_tag, int src_tag)
{
	knh_int_t rcount;
	MPI_Status stat;
	MPI_Sendrecv(&scount, 1, MPI_INT, dest_rank, dest_tag, &rcount, 1, MPI_INT, src_rank, src_tag, KNH_MPI_COMM(comm), &stat);
	return rcount;
}

static int knh_MPI_SendrecvBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, knh_Object_t *rdata, int count, int src_rank, int dest_tag, int src_tag)
{
	COMM(comm, c);
	BA(asdata, sdata);
	BA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (count == 0) {
			count = knh_MPI_Sendrecv_getRecvCount(comm, BA_size(asdata), dest_rank, src_rank, dest_tag, src_tag);
		}
		KNH_BA_EXPAND(ardata, count);
		ret = MPI_Sendrecv(BA_buf(asdata), BA_size(asdata), BA_Type, dest_rank, dest_tag,
						   BA_tail(ardata), count, BA_Type, src_rank, src_tag, KNH_MPI_COMM(comm), &stat);
		BA_size(ardata) += count;
	}
	return ret;
}

static int knh_MPI_SendrecvInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, knh_Object_t *rdata, int count, int src_rank, int dest_tag, int src_tag)
{
	COMM(comm, c);
	IA(asdata, sdata);
	IA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (count == 0) {
			count = knh_MPI_Sendrecv_getRecvCount(comm, IA_size(asdata), dest_rank, src_rank, dest_tag, src_tag);
		}
		KNH_IA_EXPAND(ardata, count);
		ret = MPI_Sendrecv(IA_buf(asdata), IA_size(asdata), IA_Type, dest_rank, dest_tag,
						   IA_tail(ardata), count, IA_Type, src_rank, src_tag, KNH_MPI_COMM(comm), &stat);
		IA_size(ardata) += count;
	}
	return ret;
}

static int knh_MPI_SendrecvFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, knh_Object_t *rdata, int count, int src_rank, int dest_tag, int src_tag)
{
	COMM(comm, c);
	FA(asdata, sdata);
	FA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (count == 0) {
			count = knh_MPI_Sendrecv_getRecvCount(comm, FA_size(asdata), dest_rank, src_rank, dest_tag, src_tag);
		}
		KNH_FA_EXPAND(ardata, count);
		ret = MPI_Sendrecv(FA_buf(asdata), FA_size(asdata), FA_Type, dest_rank, dest_tag,
						   FA_tail(ardata), count, FA_Type, src_rank, src_tag, KNH_MPI_COMM(comm), &stat);
		FA_size(ardata) += count;
	}
	return ret;
}

static void knh_MPI_iSendBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int dest_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	if (IS_Bytes(data)) {
		BA(sdata, data);
		if (count == 0) count = BA_size(sdata);
		if (KNH_ON_MPI(comm)) {
			MPI_Isend(BA_buf(sdata), count, BA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
	else { /* IS_String(data) */
		if (KNH_ON_MPI(comm)) {
			knh_String_t *s = (knh_String_t*)data;
			if (count == 0) count = s->str.len;
			MPI_Isend(s->str.ubuf, count, BA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
}

static void knh_MPI_iSendInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int dest_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	if (IS_IArray(data)) {
		IA(sdata, data);
		if (count == 0) count = IA_size(sdata);
		if (KNH_ON_MPI(comm)) {
			MPI_Isend(IA_buf(sdata), count, IA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
	else { /* IS_Int(data) */
		if (KNH_ON_MPI(comm)) {
			MPI_Isend(&O_data(data), 1, IA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
}

static void knh_MPI_iSendFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int dest_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	if (IS_FArray(data)) {
		FA(sdata, data);
		if (count == 0) count = FA_size(sdata);
		if (KNH_ON_MPI(comm)) {
			MPI_Isend(FA_buf(sdata), count, FA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
	else { /* IS_Float(data) */
		if (KNH_ON_MPI(comm)) {
			MPI_Isend(&O_data(data), 1, FA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq);
		}
	}
}

static void knh_MPI_iRecvBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	BA(rdata, data);
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, BA_Type, &count);
			} else {
				count = BA_size(rdata);
			}
		}
		int incl = count - BA_size(rdata);
		if (incl <= 0) {
			MPI_Irecv(BA_buf(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
		} else {
			KNH_BA_EXPAND(rdata, incl);
			MPI_Irecv(BA_buf(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
			BA_size(rdata) += incl;
		}
	}
}

static void knh_MPI_iRecvInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	IA(rdata, data);
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, IA_Type, &count);
			} else {
				count = IA_size(rdata);
			}
		}
		int incl = count - IA_size(rdata);
		if (incl <= 0) {
			MPI_Irecv(IA_buf(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
		} else {
			KNH_IA_EXPAND(rdata, incl);
			MPI_Irecv(IA_buf(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
			IA_size(rdata) += incl;
		}
	}
}

static void knh_MPI_iRecvFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, MPI_Request *mreq)
{
	COMM(comm, c);
	FA(rdata, data);
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, FA_Type, &count);
			} else {
				count = FA_size(rdata);
			}
		}
		int incl = count - FA_size(rdata);
		if (incl <= 0) {
			MPI_Irecv(FA_buf(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
		} else {
			KNH_FA_EXPAND(rdata, incl);
			MPI_Irecv(FA_buf(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq);
			FA_size(rdata) += incl;
		}
	}
}

/* ------------------------------------------------------------------------ */

//## method Int MPIComm.send(dynamic sdata, Int dest_rank, Int tag);
KMETHOD MPIComm_send(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	int ret = -1;
	if (IS_Int(sdata) || IS_IArray(sdata)) {
		ret = knh_MPI_SendInt(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	} else if (IS_Float(sdata) || IS_FArray(sdata)) {
		ret = knh_MPI_SendFloat(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	} else if (IS_String(sdata) || IS_Bytes(sdata)) {
		ret = knh_MPI_SendBytes(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	}
	RETURNi_(ret);
}

//## method Int MPIComm.sendBytes(Bytes sdata, Int count, Int dest_rank, Int tag);
KMETHOD MPIComm_sendBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.sendInt(IArray sdata, Int count, Int dest_rank, Int tag);
KMETHOD MPIComm_sendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.sendFloat(FArray sdata, Int count, Int dest_rank, Int tag);
KMETHOD MPIComm_sendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.recv(dynamic data, Int src_rank, Int tag);
KMETHOD MPIComm_recv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *data = sfp[1].o;
	int ret = -1;
	if (IS_IArray(data)) {
		ret = knh_MPI_RecvInt(ctx, sfp[0].o, data, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	} else if (IS_FArray(data)) {
		ret = knh_MPI_RecvFloat(ctx, sfp[0].o, data, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	} else if (IS_Bytes(data)) {
		ret = knh_MPI_RecvBytes(ctx, sfp[0].o, data, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]));
	}
	RETURNi_(ret);
}

//## method Int MPIComm.recvBytes(Bytes rdata, Int count, Int src_rank, Int tag);
KMETHOD MPIComm_recvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.recvInt(IArray rdata, Int count, Int src_rank, Int tag);
KMETHOD MPIComm_recvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.recvFloat(FArray rdata, Int count, Int src_rank, Int tag);
KMETHOD MPIComm_recvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4])));
}

//## method Int MPIComm.sendrecv(dynamic data, Int dest_rank, dynamic rdata, Int src_rank, int stag, int rtag);
KMETHOD MPIComm_sendrecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[3].o;
	int ret = -1;
	if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_SendrecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								  sfp[3].o, 0, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]));
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_SendrecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
									sfp[3].o, 0, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]));
	} else if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_SendrecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
									sfp[3].o, 0, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]));
	}
	RETURNi_(ret);
}

//## method Int MPIComm.sendrecvBytes(Bytes sdata, Int dest_rank, Bytes rdata, Int count, Int src_rank, int stag, int rtag);
KMETHOD MPIComm_sendrecvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								   sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]), Int_to(int, sfp[7])));
}

//## method Int MPIComm.sendrecvInt(IArray sdata, Int dest_rank, IArray rdata, Int count, Int src_rank, int stag, int rtag);
KMETHOD MPIComm_sendrecvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								 sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]), Int_to(int, sfp[7])));
}

//## method Int MPIComm.sendrecvFloat(FArray sdata, Int dest_rank, FArray rdata, Int count, Int src_rank, int stag, int rtag);
KMETHOD MPIComm_sendrecvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								   sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), Int_to(int, sfp[6]), Int_to(int, sfp[7])));
}

//## method Int MPIComm.iSend(dynamic sdata, Int rrank, Int tag);
KMETHOD MPIComm_iSend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	MPI_Request req = 0;
	if (IS_Int(sdata) || IS_IArray(sdata)) {
		knh_MPI_iSendInt(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	} else if (IS_Float(sdata) || IS_FArray(sdata)) {
		knh_MPI_iSendFloat(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	} else if (IS_String(sdata) || IS_Bytes(sdata)) {
		knh_MPI_iSendBytes(ctx, sfp[0].o, sdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	}
	RETURNi_(req);
}

//## method Int MPIComm.iSendBytes(Bytes sdata, Int count, Int rrank, Int tag);
KMETHOD MPIComm_iSendBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iSendBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}

//## method Int MPIComm.iSendInt(IArray sdata, Int count, Int rrank, Int tag);
KMETHOD MPIComm_iSendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iSendInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}

//## method Int MPIComm.iSendFloat(FArray sdata, Int count, Int rrank, Int tag);
KMETHOD MPIComm_iSendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iSendFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}

//## method Int MPIComm.iRecv(dynamic rdata, Int srank, Int tag);
KMETHOD MPIComm_iRecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *rdata = sfp[1].o;
	MPI_Request req = 0;
	if (IS_IArray(rdata)) {
		knh_MPI_iRecvInt(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	} else if (IS_FArray(rdata)) {
		knh_MPI_iRecvFloat(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	} else if (IS_Bytes(rdata)) {
		knh_MPI_iRecvBytes(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), Int_to(int, sfp[3]), &req);
	}
	RETURNi_(req);
}

//## method Int MPIComm.iRecvBytes(Bytes rdata, Int count, Int srank, Int tag);
KMETHOD MPIComm_iRecvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iRecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}

//## method Int MPIComm.iRecvInt(IArray rdata, Int count, Int srank, Int tag);
KMETHOD MPIComm_iRecvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iRecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}

//## method Int MPIComm.iRecvFloat(FArray rdata, Int count, Int srank, Int tag);
KMETHOD MPIComm_iRecvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Request req = 0;
	knh_MPI_iRecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), Int_to(int, sfp[4]), &req);
	RETURNi_(req);
}
