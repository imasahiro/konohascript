using konoha.mpi.*;

world = MPIComm.WORLD;
myid = world.getRank();
nprocs = world.getSize();

dsendbuf = new float[1];
dsendbuf[0] = (float)myid;
OUT.println("myid:"+"%d"(myid)+" dsendbuf="+"%4.2f"(dsendbuf[0]));

drecvbuf = new float[1];
if (myid != 0) {
    world.recvFloat(drecvbuf, 1, myid-1);
}

dsendbuf[0] = dsendbuf[0] + drecvbuf[0];

if (myid != nprocs-1) {
    world.sendFloat(dsendbuf, 1, myid+1);
} else {
    OUT.println("Total = "+"%4.2f"(dsendbuf[0]));
}

