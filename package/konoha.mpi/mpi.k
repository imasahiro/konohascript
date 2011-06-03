include nativelink;

@Native class MPIContext;
@Native class MPIRequest;

include func:MPICONST;

/* Class Name Replacement */
IArray = Array<Int>;
FArray = Array<Float>;

/* Basic API */
MPIContext MPIContext.new();
Int MPIContext.getRank();
Int MPIContext.getSize();
String MPIContext.getProcessorName();
Int MPIContext.getWtime();

/* Point-to-Point Communication API */
Int MPIContext.send(Bytes sdata, Int dest_rank);
Int MPIContext.sendInt(IArray sdata, Int dest_rank);
Int MPIContext.sendFloat(FArray sdata, Int dest_rank);

Int MPIContext.recv(Bytes rdata, Int src_rank);
Int MPIContext.recvInt(IArray rdata, Int src_rank);
Int MPIContext.recvFloat(FArray rdata, Int src_rank);

MPIRequest MPIContext.iSend(Bytes sdata, Int dest_rank, NameSpace ns);
MPIRequest MPIContext.iSendInt(IArray sdata, Int dest_rank, NameSpace ns);
MPIRequest MPIContext.iSendFloat(FArray sdata, Int dest_rank, NameSpace ns);

MPIRequest MPIContext.iRecv(Bytes rdata, Int count, Int src_rank, NameSpace ns);
MPIRequest MPIContext.iRecvInt(IArray rdata, Int count, Int src_rank, NameSpace ns);
MPIRequest MPIContext.iRecvFloat(FArray rdata, Int count, Int src_rank, NameSpace ns);

/* MPIRequest & barrier */
Int MPIRequest.wait();
Int MPIContext.barrier();

/* Collective Communication API */
Int MPIContext.bcast(Bytes sdata, Int count, Int root_rank);
Int MPIContext.bcastInt(IArray sdata, Int count, Int root_rank);
Int MPIContext.bcastFloat(FArray sdata, Int count, Int root_rank);

Int MPIContext.gather(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPIContext.gatherInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPIContext.gatherFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

Int MPIContext.scatter(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPIContext.scatterInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPIContext.scatterFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

Int MPIContext.allGather(Bytes sdata, Int count, Bytes rdata);
Int MPIContext.allGatherInt(IArray sdata, Int count, IArray rdata);
Int MPIContext.allGatherFloat(FArray sdata, Int count, FArray rdata);

Int MPIContext.allToAll(Bytes sdata, Int count, Bytes rdata);
Int MPIContext.allToAllInt(IArray sdata, Int count, IArray rdata);
Int MPIContext.allToAllFloat(FArray sdata, Int count, FArray rdata);

Int MPIContext.reduce(Bytes sdata, Bytes rdata, Int count, Int op, Int root_rank);
Int MPIContext.reduceInt(IArray sdata, IArray rdata, Int count, Int op, Int root_rank);
Int MPIContext.reduceFloat(FArray sdata, FArray rdata, Int count, Int op, Int root_rank);

Int MPIContext.allReduce(Bytes sdata, Bytes rdata, Int count, Int op);
Int MPIContext.allReduceInt(IArray sdata, IArray rdata, Int count, Int op);
Int MPIContext.allReduceFloat(FArray sdata, FArray rdata, Int count, Int op);


Int MPIContext.bcastEx(Bytes sdata, Int root_rank);                /* extra */
Int MPIContext.gatherEx(Bytes sdata, Bytes rdata, Int root_rank);  /* extra */
Int MPIContext.allGatherEx(Bytes sdata, Bytes rdata);              /* extra */
