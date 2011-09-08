
using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

if (size != 2) exit(0);

if (rank == 0) {
    buf = (Bytes)"this is konoha";
    world.send(buf, 1 /* dest_rank */);
    print "SEND: " + buf.decode();
}
else { /* rank == 1 */
    buf = new Bytes();
    world.recv(buf, 0 /* src_rank */);
    print "RECV: " + buf.decode();
}
