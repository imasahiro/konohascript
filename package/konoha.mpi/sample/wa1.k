using konoha.mpi.*;

world = MPIComm.WORLD;
myid = world.getRank();
nprocs = world.getSize();

dsendbuf = new float[1];
dsendbuf[0] = (float)myid;
OUT.println("myid:"+"%d"(myid)+" dsendbuf="+"%4.2f"(dsendbuf[0]));
drecvbuf = new float[1];

world.barrier();
t0 = getMPIWtime();

/* communicate with neighbors */
{
    if (myid != 0) {
        world.recvFloat(drecvbuf, 1, myid-1);
    }
    dsendbuf[0] = dsendbuf[0] + drecvbuf[0];
    if (myid != nprocs-1) {
        world.sendFloat(dsendbuf, 1, myid+1);
    } else {
        OUT.println("Total = "+"%4.2f"(dsendbuf[0]));
    }
}

world.barrier();
t1 = getMPIWtime();
t2 = t1 - t0;
t_w = new float[1];

world.reduce(t2, t_w, MPIOp.MAX, 0);
if (myid == 0) {
    OUT.println("Max Time = "+"%f"(t_w[0]));
}