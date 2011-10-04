include "lib:gluelink";

@Public void System.disableLog(); // for ac
@Public Float System.getMPIWtime(); // for MPI_Wtime

/* ======================================================================== */
/* Array Extra API */
@Public int[] Array.getShape();
@Public void Array.reshape(int[] shape);
@Public dynamic Array.cols(int start, int end);
@Public dynamic Array.rows(int start, int end);
@Public dynamic Array.block(int rank, int size);
@Public dynamic Array.cycle(int rank, int size);
@Public dynamic Array.trans();

/* ======================================================================== */
/* Basic Class API */

/* --- Communicator ------------------------------------------------------- */
@Native class MPIComm;
Int    MPIComm.getRank();
Int    MPIComm.getSize();
String MPIComm.getProcessorName();
Int    MPIComm.barrier();

@Native class MPIRequest;
Int    MPIRequest.wait();
Int    MPIRequest.cancel();
/* --- Operator ----------------------------------------------------------- */
@Native class MPIOp;
MPIOp MPIOp.new(Func<dynamic,dynamic> func, Boolean commutable);


/* ======================================================================== */
/* Point-to-Point Communication API */

/* -- send ---------------------------------------------------------------- */
Int MPIComm.send(dynamic sdata, Int dest_rank, Int tag);

Int MPIComm.sendBytes(byte[] sdata, Int count, Int dest_rank, Int tag);
Int MPIComm.sendInt(int[] sdata, Int count, Int dest_rank, Int tag);
Int MPIComm.sendFloat(float[] sdata, Int count, Int dest_rank, Int tag);

/* --- recv --------------------------------------------------------------- */
Int MPIComm.recv(dynamic rdata, Int src_rank, Int tag);

Int MPIComm.recvBytes(byte[] rdata, Int count, Int src_rank, Int tag);
Int MPIComm.recvInt(int[] rdata, Int count, Int src_rank, Int tag);
Int MPIComm.recvFloat(float[] rdata, Int count, Int src_rank, Int tag);

/* --- sendrecv ----------------------------------------------------------- */
Int MPIComm.sendrecv(dynamic sdata, Int dest_rank, dynamic rdata, Int src_rank, Int dest_tag, Int src_tag);

Int MPIComm.sendrecvBytes(byte[] sdata, Int dest_rank, byte[] rdata, Int count, Int src_rank, Int dest_tag, Int src_tag);
Int MPIComm.sendrecvInt(int[] sdata, Int dest_rank, int[] rdata, Int count, Int src_rank, Int dest_tag, Int src_tag);
Int MPIComm.sendrecvFloat(float[] sdata, Int dest_rank, float[] rdata, Int count, Int src_rank, Int dest_tag, Int src_tag);

/* --- isend -------------------------------------------------------------- */
MPIRequest MPIComm.iSend(dynamic sdata, Int dest_rank, Int tag, MPIRequest _);

MPIRequest MPIComm.iSendBytes(byte[] sdata, Int count, Int dest_rank, Int tag, MPIRequest _);
MPIRequest MPIComm.iSendInt(int[] sdata, Int count, Int dest_rank, Int tag, MPIRequest _);
MPIRequest MPIComm.iSendFloat(float[] sdata, Int count, Int dest_rank, Int tag, MPIRequest _);

/* --- irecv -------------------------------------------------------------- */
MPIRequest MPIComm.iRecv(dynamic rdata, Int src_rank, Int tag, MPIRequest _);

MPIRequest MPIComm.iRecvBytes(byte[] rdata, Int count, Int src_rank, Int tag, MPIRequest _);
MPIRequest MPIComm.iRecvInt(int[] rdata, Int count, Int src_rank, Int tag, MPIRequest _);
MPIRequest MPIComm.iRecvFloat(float[] rdata, Int count, Int src_rank, Int tag, MPIRequest _);


/* ======================================================================== */
/* Collective Communication API */

/* --- bcast -------------------------------------------------------------- */
Int MPIComm.bcast(dynamic sdata, Int root_rank);

Int MPIComm.bcastBytes(byte[] sdata, Int count, Int root_rank);
Int MPIComm.bcastInt(int[] sdata, Int count, Int root_rank);
Int MPIComm.bcastFloat(float[] sdata, Int count, Int root_rank);

/* --- scatter ------------------------------------------------------------ */
Int MPIComm.scatter(dynamic sdata, dynamic rdata, Int root_rank);

Int MPIComm.scatterBytes(byte[] sdata, Int count, byte[] rdata, Int root_rank);
Int MPIComm.scatterInt(int[] sdata, Int count, int[] rdata, Int root_rank);
Int MPIComm.scatterFloat(float[] sdata, Int count, float[] rdata, Int root_rank);

/* --- gather ------------------------------------------------------------- */
Int MPIComm.gather(dynamic sdata, dynamic rdata, Int root_rank);

Int MPIComm.gatherBytes(byte[] sdata, Int count, byte[] rdata, Int root_rank);
Int MPIComm.gatherInt(int[] sdata, Int count, int[] rdata, Int root_rank);
Int MPIComm.gatherFloat(float[] sdata, Int count, float[] rdata, Int root_rank);

/* --- allgather ---------------------------------------------------------- */
Int MPIComm.allGather(dynamic sdata, dynamic rdata);

Int MPIComm.allGatherBytes(byte[] sdata, Int count, byte[] rdata);
Int MPIComm.allGatherInt(int[] sdata, Int count, int[] rdata);
Int MPIComm.allGatherFloat(float[] sdata, Int count, float[] rdata);

/* --- all2all ------------------------------------------------------------ */
Int MPIComm.allToAll(dynamic sdata, dynamic rdata);

Int MPIComm.allToAllBytes(byte[] sdata, Int count, byte[] rdata);
Int MPIComm.allToAllInt(int[] sdata, Int count, int[] rdata);
Int MPIComm.allToAllFloat(float[] sdata, Int count, float[] rdata);

/* --- reduce ------------------------------------------------------------- */
Int MPIComm.reduce(dynamic sdata, dynamic rdata, MPIOp op, Int root_rank);

Int MPIComm.reduceBytes(byte[] sdata, byte[] rdata, Int count, MPIOp op, Int root_rank);
Int MPIComm.reduceInt(int[] sdata, int[] rdata, Int count, MPIOp op, Int root_rank);
Int MPIComm.reduceFloat(float[] sdata, float[] rdata, Int count, MPIOp op, Int root_rank);

/* --- allreduce ---------------------------------------------------------- */
Int MPIComm.allReduce(dynamic sdata, dynamic rdata, MPIOp op);

Int MPIComm.allReduceBytes(byte[] sdata, byte[] rdata, Int count, MPIOp op);
Int MPIComm.allReduceInt(int[] sdata, int[] rdata, Int count, MPIOp op);
Int MPIComm.allReduceFloat(float[] sdata, float[] rdata, Int count, MPIOp op);

