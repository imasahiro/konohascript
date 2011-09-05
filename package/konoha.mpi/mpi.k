include "lib:gluelink";

/* Class Name Replacement */
IArray = Array<Int>;
FArray = Array<Float>;
@Public void System.disableLog(); // for ac
@Public Float System.getMPIWtime(); // for MPI_Wtime

/* ======================================================================== */
/* Basic Class API */

/* --- Communicator ------------------------------------------------------- */
@Native class MPIComm;
Int MPIComm.getRank();
Int MPIComm.getSize();
String MPIComm.getProcessorName();
Int MPIComm.barrier();
Int MPIComm.wait(Int request);
Int MPIComm.cancel(Int request);

/* --- Operator ----------------------------------------------------------- */
@Native class MPIOp;
MPIOp MPIOp.new(Func<dynamic,dynamic> func, Boolean commutable);


/* ======================================================================== */
/* Point-to-Point Communication API */

/* -- send ---------------------------------------------------------------- */
Int MPIComm.send(dynamic sdata, Int dest_rank, Int tag);

Int MPIComm.sendBytes(Bytes sdata, Int dest_rank, Int tag);
Int MPIComm.sendInt(IArray sdata, Int dest_rank, Int tag);
Int MPIComm.sendFloat(FArray sdata, Int dest_rank, Int tag);

/* --- recv --------------------------------------------------------------- */
Int MPIComm.recv(dynamic rdata, Int src_rank, Int tag);

Int MPIComm.recvBytes(Bytes rdata, Int src_rank, Int tag);
Int MPIComm.recvInt(IArray rdata, Int src_rank, Int tag);
Int MPIComm.recvFloat(FArray rdata, Int src_rank, Int tag);

/* --- sendrecv ----------------------------------------------------------- */
Int MPIComm.sendrecv(dynamic sdata, Int dest_rank, dynamic rdata, Int src_rank);

Int MPIComm.sendrecvBytes(Bytes sdata, Int dest_rank, Bytes rdata, Int count, Int src_rank);
Int MPIComm.sendrecvInt(IArray sdata, Int dest_rank, IArray rdata, Int count, Int src_rank);
Int MPIComm.sendrecvFloat(FArray sdata, Int dest_rank, FArray rdata, Int count, Int src_rank);

/* --- isend -------------------------------------------------------------- */
Int MPIComm.iSend(dynamic sdata, Int dest_rank, Int tag);

Int MPIComm.iSendBytes(Bytes sdata, Int dest_rank, Int tag);
Int MPIComm.iSendInt(IArray sdata, Int dest_rank, Int tag);
Int MPIComm.iSendFloat(FArray sdata, Int dest_rank, Int tag);

/* --- irecv -------------------------------------------------------------- */
Int MPIComm.iRecv(dynamic rdata, Int src_rank, Int tag);

Int MPIComm.iRecvBytes(Bytes rdata, Int count, Int src_rank, Int tag);
Int MPIComm.iRecvInt(IArray rdata, Int count, Int src_rank, Int tag);
Int MPIComm.iRecvFloat(FArray rdata, Int count, Int src_rank, Int tag);


/* ======================================================================== */
/* Collective Communication API */

/* --- bcast -------------------------------------------------------------- */
Int MPIComm.bcast(dynamic sdata, Int root_rank);

Int MPIComm.bcastBytes(Bytes sdata, Int count, Int root_rank);
Int MPIComm.bcastInt(IArray sdata, Int count, Int root_rank);
Int MPIComm.bcastFloat(FArray sdata, Int count, Int root_rank);

/* --- scatter ------------------------------------------------------------ */
Int MPIComm.scatter(dynamic sdata, dynamic rdata, Int root_rank);

Int MPIComm.scatterBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPIComm.scatterInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPIComm.scatterFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

/* --- gather ------------------------------------------------------------- */
Int MPIComm.gather(dynamic sdata, dynamic rdata, Int root_rank);

Int MPIComm.gatherBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);
Int MPIComm.gatherInt(IArray sdata, Int count, IArray rdata, Int root_rank);
Int MPIComm.gatherFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

/* --- allgather ---------------------------------------------------------- */
Int MPIComm.allGather(dynamic sdata, dynamic rdata);

Int MPIComm.allGatherBytes(Bytes sdata, Int count, Bytes rdata);
Int MPIComm.allGatherInt(IArray sdata, Int count, IArray rdata);
Int MPIComm.allGatherFloat(FArray sdata, Int count, FArray rdata);

/* --- all2all ------------------------------------------------------------ */
Int MPIComm.allToAll(dynamic sdata, dynamic rdata);

Int MPIComm.allToAllBytes(Bytes sdata, Int count, Bytes rdata);
Int MPIComm.allToAllInt(IArray sdata, Int count, IArray rdata);
Int MPIComm.allToAllFloat(FArray sdata, Int count, FArray rdata);

/* --- reduce ------------------------------------------------------------- */
Int MPIComm.reduce(dynamic sdata, dynamic rdata, MPIOp op, Int root_rank);

Int MPIComm.reduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op, Int root_rank);
Int MPIComm.reduceInt(IArray sdata, IArray rdata, Int count, MPIOp op, Int root_rank);
Int MPIComm.reduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op, Int root_rank);

/* --- allreduce ---------------------------------------------------------- */
Int MPIComm.allReduce(dynamic sdata, dynamic rdata, MPIOp op);

Int MPIComm.allReduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op);
Int MPIComm.allReduceInt(IArray sdata, IArray rdata, Int count, MPIOp op);
Int MPIComm.allReduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op);

