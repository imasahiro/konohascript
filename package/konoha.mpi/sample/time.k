using konoha.mpi.*;

world = MPIComm.WORLD;
myid = world.getRank();
numprocs = world.getSize();

world.barrier();
t1 = getMPIWtime();

print "hello world from "+ myid;

world.barrier();
t2 = getMPIWtime();
t0 = t2 - t1;
t_w = new float[0];
world.reduce(t0, t_w, MPIOp.MAX, 0);

if (myid == 0) {
    print "Maximum Time: "+t_w[0];
}
