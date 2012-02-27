using konoha.mpi.*;

world = MPIComm.WORLD;
myid = world.getRank();
nprocs = world.getSize();

dsendbuf = new float[1];
dsendbuf[0] = (float)myid;
OUT.println("myid:"+"%d"(myid)+" dsendbuf="+"%4.2f"(dsendbuf[0]));
drecvbuf = new float[1];

world.barrier();
t0 = MPI.getWtime();

/* communicate with neighbors */
{
    if (myid != 0) {
        world.recv((MPIData)drecvbuf, 1, myid-1);
    }
    dsendbuf[0] = dsendbuf[0] + drecvbuf[0];
    if (myid != nprocs-1) {
        world.send((MPIData)dsendbuf, 1, myid+1);
    } else {
        OUT.println("Total = "+"%4.2f"(dsendbuf[0]));
    }
}

world.barrier();
t1 = MPI.getWtime();
t2 = t1 - t0;
t_w = new float[1];

world.reduce((MPIData)[t2], (MPIData)t_w, 1, MPIOp.MAX, 0);
if (myid == 0) {
    OUT.println("Max Time = "+"%f"(t_w[0]));
}
