#include "../konoha_mpi.h"

//## method Int MPIContext.send(Bytes sdata, Int dest_rank);
METHOD MPIContext_send(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int dest_rank = Int_to(int, sfp[2]);
	RETURNi_(KNH_ON_MPI(mctx) ?
			 MPI_Send(BA_buf(sdata), BA_size(sdata), BA_Type, dest_rank, 0, MPI_COMM_WORLD) : -1);
}

//## method Int MPIContext.sendInt(IArray sdata, Int dest_rank);
METHOD MPIContext_sendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int dest_rank = Int_to(int, sfp[2]);
	DBG_ASSERT(sizeof(knh_int_t) == sizeof(unsigned long int));
	RETURNi_((KNH_ON_MPI(mctx) && IS_IArray(sdata)) ?
			 MPI_Send(IA_buf(sdata), IA_size(sdata), IA_Type, dest_rank, 0, MPI_COMM_WORLD) : -1);
}

//## method Int MPIContext.sendFloat(FArray sdata, Int dest_rank);
METHOD MPIContext_sendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int dest_rank = Int_to(int, sfp[2]);
	DBG_ASSERT(sizeof(knh_int_t) == sizeof(unsigned long int));
	RETURNi_((KNH_ON_MPI(mctx) && IS_FArray(sdata)) ?
			 MPI_Send(FA_buf(sdata), FA_size(sdata), FA_Type, dest_rank, 0, MPI_COMM_WORLD) : -1);
}

//## method Int MPIContext.recv(Bytes rdata, Int src_rank);
METHOD MPIContext_recv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *rdata = sfp[1].ba;
	int src_rank = Int_to(int, sfp[2]);
	int ret = 0;
	if (KNH_ON_MPI(mctx)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat))) {
			int count;
			MPI_Get_count(&stat, BA_Type, &count);
			KNH_BYTES_EXPAND(rdata, count);
			ret = MPI_Recv(BA_buf(rdata), count, BA_Type, src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.recvInt(IArray rdata, Int src_rank);
METHOD MPIContext_recvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *rdata = sfp[1].a;
	int src_rank = Int_to(int, sfp[2]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_IArray(rdata)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat))) {
			int count;
			MPI_Get_count(&stat, IA_Type, &count);
			KNH_ARRAY_EXPAND(rdata, count);
			ret = MPI_Recv(IA_tail(rdata), count, IA_Type, src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);
			IA_size(rdata) += count;
		}
	}
	RETURNi_(ret);
}

//## method Int MPIContext.recvFloat(FArray rdata, Int src_rank);
METHOD MPIContext_recvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *rdata = sfp[1].a;
	int src_rank = Int_to(int, sfp[2]);
	int ret = 0;
	if (KNH_ON_MPI(mctx) && IS_FArray(rdata)) {
		MPI_Status stat;
		if (KNH_MPI_SUCCESS(MPI_Probe(src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat))) {
			int count;
			MPI_Get_count(&stat, FA_Type, &count);
			KNH_ARRAY_EXPAND(rdata, count);
			ret = MPI_Recv(FA_tail(rdata), count, FA_Type, src_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);
			FA_size(rdata) += count;
		}
	}
	RETURNi_(ret);
}

//## method MPIRequest MPIContext.iSend(Bytes sdata, Int rrank, NameSpace ns);
METHOD MPIContext_iSend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *sdata = sfp[1].ba;
	int dest_rank = Int_to(int, sfp[2]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[3].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx)) {
		MPI_Isend(BA_buf(sdata), BA_size(sdata), BA_Type, dest_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
	}
	RETURN_(mreq);
}

//## method MPIRequest MPIContext.iSendInt(IArray sdata, Int rrank, NameSpace ns);
METHOD MPIContext_iSendInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int dest_rank = Int_to(int, sfp[2]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[3].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx) && IS_IArray(sdata)) {
		MPI_Isend(IA_buf(sdata), IA_size(sdata), IA_Type, dest_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
	}
	RETURN_(mreq);
}

//## method MPIRequest MPIContext.iSendFloat(FArray sdata, Int rrank, NameSpace ns);
METHOD MPIContext_iSendFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *sdata = sfp[1].a;
	int dest_rank = Int_to(int, sfp[2]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[3].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx) && IS_FArray(sdata)) {
		MPI_Isend(FA_buf(sdata), FA_size(sdata), FA_Type, dest_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
	}
	RETURN_(mreq);
}

//## method MPIRequest MPIContext.iRecv(Bytes rdata, Int count, Int srank, NameSpace ns);
METHOD MPIContext_iRecv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Bytes_t *rdata = sfp[1].ba;
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[4].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx)) {
		KNH_BYTES_EXPAND(rdata, count);
		MPI_Irecv(BA_buf(rdata), count, BA_Type, src_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
	}
	RETURN_(mreq);
}

//## method MPIRequest MPIContext.iRecvInt(IArray rdata, Int count, Int srank, NameSpace ns);
METHOD MPIContext_iRecvInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *rdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[4].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx) && IS_IArray(rdata)) {
		KNH_ARRAY_EXPAND(rdata, count);
		MPI_Irecv(IA_tail(rdata), count, IA_Type, src_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
		IA_size(rdata) += count;
	}
	RETURN_(mreq);
}

//## method MPIRequest MPIContext.iRecvFloat(FArray rdata, Int count, Int srank, NameSpace ns);
METHOD MPIContext_iRecvFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_MPIContext_t *mctx = (knh_MPIContext_t*)sfp[0].o;
	knh_Array_t *rdata = sfp[1].a;
	int count = Int_to(int, sfp[2]);
	int src_rank = Int_to(int, sfp[3]);
	knh_NameSpace_t *ns = (knh_NameSpace_t*)sfp[4].ns;
	knh_MPIRequest_t *mreq = (knh_MPIRequest_t*)new_ObjectNS(ctx, ns, "MPIRequest");
	if (KNH_ON_MPI(mctx) && IS_FArray(rdata)) {
		KNH_ARRAY_EXPAND(rdata, count);
		MPI_Irecv(FA_tail(rdata), count, FA_Type, src_rank, 0, MPI_COMM_WORLD, mreq->mpi_req);
		FA_size(rdata) += count;
	}
	RETURN_(mreq);
}
