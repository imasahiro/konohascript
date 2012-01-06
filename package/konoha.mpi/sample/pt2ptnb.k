
using konoha.mpi.*;

MPIComm world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

if (size != 2) exit(0);

if (rank == 0) {
    buf = (Bytes)"this is konoha";
    world.iSend((MPIData)buf, |buf|, 1 /* dest_rank */);
    print "SEND: " + buf.decode();
}
else { /* rank == 1 */
    buf = new Bytes();
    req = world.iRecv((MPIData)buf, 14, 0 /* src_rank */);
    req.wait();
    print "RECV: " + buf.decode();
}

world.barrier();