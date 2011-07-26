#include "../konoha_mpi.h"

int g_counter_tag;

#define K_MPI_SEND_TAG (g_counter_tag++)

/* ------------------------------------------------------------------------ */

static int knh_MPI_SendBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	BA(data, sdata);
	return (KNH_ON_MPI(comm)) ?
		MPI_Send(BA_buf(data), BA_size(data), BA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
}

static int knh_MPI_SendInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	IA(data, sdata);
	return (KNH_ON_MPI(comm)) ?
		MPI_Send(IA_buf(data), IA_size(data), IA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
}

static int knh_MPI_SendFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int dest_rank, int tag)
{
	(void)ctx;
	COMM(comm, c);
	FA(data, sdata);
	return (KNH_ON_MPI(comm)) ?
		MPI_Send(FA_buf(data), FA_size(data), FA_Type, dest_rank, tag, KNH_MPI_COMM(comm)) : -1;
}

static int knh_MPI_RecvBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int src_rank, int tag)
{
	COMM(comm, c);
	BA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			int count;
			MPI_Get_count(&stat, BA_Type, &count);
			KNH_BA_EXPAND(rdata, count);
			ret = MPI_Recv(BA_tail(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			BA_size(rdata) += count;
		}
	}
	return ret;
}

static int knh_MPI_RecvInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int src_rank, int tag)
{
	COMM(comm, c);
	IA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			int count;
			MPI_Get_count(&stat, IA_Type, &count);
			KNH_IA_EXPAND(rdata, count);
			ret = MPI_Recv(IA_tail(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			IA_size(rdata) += count;
		}
	}
	return ret;
}

static int knh_MPI_RecvFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int src_rank, int tag)
{
	COMM(comm, c);
	FA(rdata, data);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, tag, KNH_MPI_COMM(comm), &stat))) {
			int count;
			MPI_Get_count(&stat, FA_Type, &count);
			KNH_FA_EXPAND(rdata, count);
			ret = MPI_Recv(FA_tail(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), &stat);
			FA_size(rdata) += count;
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

static knh_MPIRequest_t* knh_MPI_iSendBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int dest_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	BA(sdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		MPI_Isend(BA_buf(sdata), BA_size(sdata), BA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
	}
	return mreq;
}

static knh_MPIRequest_t* knh_MPI_iSendInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int dest_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	IA(sdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		MPI_Isend(IA_buf(sdata), IA_size(sdata), IA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
	}
	return mreq;
}

static knh_MPIRequest_t* knh_MPI_iSendFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int dest_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	FA(sdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		MPI_Isend(FA_buf(sdata), FA_size(sdata), FA_Type, dest_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
	}
	return mreq;
}

static knh_MPIRequest_t* knh_MPI_iRecvBytes(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	BA(rdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, BA_Type, &count);
			}
		}
		KNH_BA_EXPAND(rdata, count);
		MPI_Irecv(BA_tail(rdata), count, BA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
		BA_size(rdata) += count;
	}
	return mreq;
}

static knh_MPIRequest_t* knh_MPI_iRecvInt(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	IA(rdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, IA_Type, &count);
			}
		}
		KNH_IA_EXPAND(rdata, count);
		MPI_Irecv(IA_tail(rdata), count, IA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
		IA_size(rdata) += count;
	}
	return mreq;
}

static knh_MPIRequest_t* knh_MPI_iRecvFloat(CTX ctx, knh_Object_t *c, knh_Object_t *data, int count, int src_rank, int tag, knh_NameSpace_t *ns)
{
	COMM(comm, c);
	FA(rdata, data);
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(comm)) {
		if (count == 0) {
			int flag;
			MPI_Status stat;
			MPI_Iprobe(src_rank, tag, KNH_MPI_COMM(comm), &flag, &stat);
			if (flag) {
				MPI_Get_count(&stat, FA_Type, &count);
			}
		}
		KNH_FA_EXPAND(rdata, count);
		MPI_Irecv(FA_tail(rdata), count, FA_Type, src_rank, tag, KNH_MPI_COMM(comm), mreq->mpi_req);
		FA_size(rdata) += count;
	}
	return mreq;
}

/* ------------------------------------------------------------------------ */

//## method Int MPICommunicator.send(dynamic sdata, Int dest_rank);
METHOD MPICommunicator_send(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	int ret = -1;
	if (IS_IArray(sdata)) {
		ret = knh_MPI_SendInt(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG);
	} else if (IS_FArray(sdata)) {
		ret = knh_MPI_SendFloat(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG);
	} else if (IS_Bytes(sdata)) {
		ret = knh_MPI_SendBytes(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG);
	}
	RETURNi_(ret);
}

//## method Int MPICommunicator.sendBytes(Bytes sdata, Int dest_rank);
METHOD MPICommunicator_sendBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG));
}

//## method Int MPICommunicator.sendInt(IArray sdata, Int dest_rank);
METHOD MPICommunicator_sendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG));
}

//## method Int MPICommunicator.sendFloat(FArray sdata, Int dest_rank);
METHOD MPICommunicator_sendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG));
}

//## method Int MPICommunicator.recv(dynamic data, Int src_rank);
METHOD MPICommunicator_recv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *data = sfp[1].o;
	int ret = -1;
	if (IS_IArray(data)) {
		ret = knh_MPI_RecvInt(ctx, sfp[0].o, data, Int_to(int, sfp[2]), MPI_ANY_TAG);
	} else if (IS_FArray(data)) {
		ret = knh_MPI_RecvFloat(ctx, sfp[0].o, data, Int_to(int, sfp[2]), MPI_ANY_TAG);
	} else if (IS_Bytes(data)) {
		ret = knh_MPI_RecvBytes(ctx, sfp[0].o, data, Int_to(int, sfp[2]), MPI_ANY_TAG);
	}
	RETURNi_(ret);
}

//## method Int MPICommunicator.recvBytes(Bytes rdata, Int src_rank);
METHOD MPICommunicator_recvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), MPI_ANY_TAG));
}

//## method Int MPICommunicator.recvInt(IArray rdata, Int src_rank);
METHOD MPICommunicator_recvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), MPI_ANY_TAG));
}

//## method Int MPICommunicator.recvFloat(FArray rdata, Int src_rank);
METHOD MPICommunicator_recvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_RecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), MPI_ANY_TAG));
}

//## method Int MPICommunicator.sendrecv(dynamic data, Int dest_rank, dynamic rdata, Int src_rank);
METHOD MPICommunicator_sendrecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[3].o;
	int ret = -1;
	if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_SendrecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								  sfp[3].o, 0, Int_to(int, sfp[4]), K_MPI_SEND_TAG, MPI_ANY_TAG);
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_SendrecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
									sfp[3].o, 0, Int_to(int, sfp[4]), K_MPI_SEND_TAG, MPI_ANY_TAG);
	} else if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_SendrecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
									sfp[3].o, 0, Int_to(int, sfp[4]), K_MPI_SEND_TAG, MPI_ANY_TAG);
	}
	RETURNi_(ret);
}

//## method Int MPICommunicator.sendrecvBytes(Bytes sdata, Int dest_rank, Bytes rdata, Int count, Int src_rank);
METHOD MPICommunicator_sendrecvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								   sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), K_MPI_SEND_TAG, MPI_ANY_TAG));
}

//## method Int MPICommunicator.sendrecvInt(IArray sdata, Int dest_rank, IArray rdata, Int count, Int src_rank);
METHOD MPICommunicator_sendrecvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								 sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), K_MPI_SEND_TAG, MPI_ANY_TAG));
}

//## method Int MPICommunicator.sendrecvFloat(FArray sdata, Int dest_rank, FArray rdata, Int count, Int src_rank);
METHOD MPICommunicator_sendrecvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_SendrecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]),
								   sfp[3].o, Int_to(int, sfp[4]), Int_to(int, sfp[5]), K_MPI_SEND_TAG, MPI_ANY_TAG));
}

//## method MPIRequest MPICommunicator.iSend(dynamic sdata, Int rrank, NameSpace ns);
METHOD MPICommunicator_iSend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_MPIRequest_t *mreq;
	if (IS_IArray(sdata)) {
		mreq = knh_MPI_iSendInt(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else if (IS_FArray(sdata)) {
		mreq = knh_MPI_iSendFloat(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else if (IS_Bytes(sdata)) {
		mreq = knh_MPI_iSendBytes(ctx, sfp[0].o, sdata, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else {
		mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, sfp[3].ns, "MPIRequest");
	}
	RETURN_(mreq);
}

//## method MPIRequest MPICommunicator.iSendBytes(Bytes sdata, Int rrank, NameSpace ns);
METHOD MPICommunicator_iSendBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iSendBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns));
}

//## method MPIRequest MPICommunicator.iSendInt(IArray sdata, Int rrank, NameSpace ns);
METHOD MPICommunicator_iSendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iSendInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns));
}

//## method MPIRequest MPICommunicator.iSendFloat(FArray sdata, Int rrank, NameSpace ns);
METHOD MPICommunicator_iSendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iSendFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns));
}

//## method MPIRequest MPICommunicator.iRecv(dynamic rdata, Int srank, NameSpace ns);
METHOD MPICommunicator_iRecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *rdata = sfp[1].o;
	knh_MPIRequest_t *mreq;
	if (IS_IArray(rdata)) {
		mreq = knh_MPI_iRecvInt(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else if (IS_FArray(rdata)) {
		mreq = knh_MPI_iRecvFloat(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else if (IS_Bytes(rdata)) {
		mreq = knh_MPI_iRecvBytes(ctx, sfp[0].o, rdata, 0, Int_to(int, sfp[2]), K_MPI_SEND_TAG, sfp[3].ns);
	} else {
		mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, sfp[3].ns, "MPIRequest");
	}
	RETURN_(mreq);
}

//## method MPIRequest MPICommunicator.iRecvBytes(Bytes rdata, Int count, Int srank, NameSpace ns);
METHOD MPICommunicator_iRecvBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iRecvBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), K_MPI_SEND_TAG, sfp[4].ns));
}

//## method MPIRequest MPICommunicator.iRecvInt(IArray rdata, Int count, Int srank, NameSpace ns);
METHOD MPICommunicator_iRecvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iRecvInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), K_MPI_SEND_TAG, sfp[4].ns));
}

//## method MPIRequest MPICommunicator.iRecvFloat(FArray rdata, Int count, Int srank, NameSpace ns);
METHOD MPICommunicator_iRecvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(knh_MPI_iRecvFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3]), K_MPI_SEND_TAG, sfp[4].ns));
}
