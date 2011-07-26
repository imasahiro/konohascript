include "lib:gluelink";

/* Class Name Replacement */
IArray = Array<Int>;
FArray = Array<Float>;
void System.disableLog(); // for ac

/* ======================================================================== */
/* Basic Class API */

/* --- Communicator ------------------------------------------------------- */
@Native class MPICommunicator;
Int MPICommunicator.getRank();
Int MPICommunicator.getSize();
String MPICommunicator.getProcessorName();
Int MPICommunicator.getWtime();
Int MPICommunicator.barrier();

/* --- Request ------------------------------------------------------------ */
@Native class MPIRequest;
Int MPIRequest.wait();
Int MPIRequest.cancel();

/* --- Operator ----------------------------------------------------------- */
@Native class MPIOp;
MPIOp MPIOp.new(Func<dynamic,dynamic> func, Boolean commutable);


/* ======================================================================== */
/* Point-to-Point Communication API */

/* -- send ---------------------------------------------------------------- */
Int MPICommunicator.send(dynamic sdata, Int dest_rank);

Int MPICommunicator.sendBytes(Bytes sdata, Int dest_rank);
Int MPICommunicator.sendInt(IArray sdata, Int dest_rank);
Int MPICommunicator.sendFloat(FArray sdata, Int dest_rank);

/* --- recv --------------------------------------------------------------- */
Int MPICommunicator.recv(dynamic rdata, Int src_rank);

Int MPICommunicator.recvBytes(Bytes rdata, Int src_rank);
Int MPICommunicator.recvInt(IArray rdata, Int src_rank);
Int MPICommunicator.recvFloat(FArray rdata, Int src_rank);

/* --- sendrecv ----------------------------------------------------------- */
Int MPICommunicator.sendrecv(dynamic sdata, Int dest_rank, dynamic rdata, Int src_rank);

Int MPICommunicator.sendrecvBytes(Bytes sdata, Int dest_rank, Bytes rdata, Int count, Int src_rank);
Int MPICommunicator.sendrecvInt(IArray sdata, Int dest_rank, IArray rdata, Int count, Int src_rank);
Int MPICommunicator.sendrecvFloat(FArray sdata, Int dest_rank, FArray rdata, Int count, Int src_rank);

/* --- isend -------------------------------------------------------------- */
MPIRequest MPICommunicator.iSend(dynamic sdata, Int dest_rank, NameSpace ns);

MPIRequest MPICommunicator.iSendBytes(Bytes sdata, Int dest_rank, NameSpace ns);
MPIRequest MPICommunicator.iSendInt(IArray sdata, Int dest_rank, NameSpace ns);
MPIRequest MPICommunicator.iSendFloat(FArray sdata, Int dest_rank, NameSpace ns);

/* --- irecv -------------------------------------------------------------- */
MPIRequest MPICommunicator.iRecv(dynamic rdata, Int src_rank, NameSpace ns);

MPIRequest MPICommunicator.iRecvBytes(Bytes rdata, Int count, Int src_rank, NameSpace ns);
MPIRequest MPICommunicator.iRecvInt(IArray rdata, Int count, Int src_rank, NameSpace ns);
MPIRequest MPICommunicator.iRecvFloat(FArray rdata, Int count, Int src_rank, NameSpace ns);


/* ======================================================================== */
/* Collective Communication API */

/* --- bcast -------------------------------------------------------------- */
Int MPICommunicator.bcast(dynamic sdata, Int root_rank);

Int MPICommunicator.bcastBytes(Bytes sdata, Int count, Int root_rank);
Int MPICommunicator.bcastInt(IArray sdata, Int count, Int root_rank);
Int MPICommunicator.bcastFloat(FArray sdata, Int count, Int root_rank);

/* --- scatter ------------------------------------------------------------ */
Int MPICommunicator.scatter(dynamic sdata, dynamic rdata, Int root_rank);

Int MPICommunicator.scatterBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPICommunicator.scatterInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPICommunicator.scatterFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

/* --- gather ------------------------------------------------------------- */
Int MPICommunicator.gather(dynamic sdata, dynamic rdata, Int root_rank);

Int MPICommunicator.gatherBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPICommunicator.gatherInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPICommunicator.gatherFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

/* --- allgather ---------------------------------------------------------- */
Int MPICommunicator.allGather(dynamic sdata, dynamic rdata);

Int MPICommunicator.allGatherBytes(Bytes sdata, Int count, Bytes rdata);
Int MPICommunicator.allGatherInt(IArray sdata, Int count, IArray rdata);
Int MPICommunicator.allGatherFloat(FArray sdata, Int count, FArray rdata);

/* --- all2all ------------------------------------------------------------ */
Int MPICommunicator.allToAll(dynamic sdata, dynamic rdata);

Int MPICommunicator.allToAllBytes(Bytes sdata, Int count, Bytes rdata);
Int MPICommunicator.allToAllInt(IArray sdata, Int count, IArray rdata);
Int MPICommunicator.allToAllFloat(FArray sdata, Int count, FArray rdata);

/* --- reduce ------------------------------------------------------------- */
Int MPICommunicator.reduce(dynamic sdata, dynamic rdata, MPIOp op, Int root_rank);

Int MPICommunicator.reduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op, Int root_rank);
Int MPICommunicator.reduceInt(IArray sdata, IArray rdata, Int count, MPIOp op, Int root_rank);
Int MPICommunicator.reduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op, Int root_rank);

/* --- allreduce ---------------------------------------------------------- */
Int MPICommunicator.allReduce(dynamic sdata, dynamic rdata, MPIOp op);

Int MPICommunicator.allReduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op);
Int MPICommunicator.allReduceInt(IArray sdata, IArray rdata, Int count, MPIOp op);
Int MPICommunicator.allReduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op);

