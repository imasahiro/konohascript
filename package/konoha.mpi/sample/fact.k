using konoha.mpi.*;

data = [1];
world = MPIComm.WORLD;
myrank = world.getRank();
numprocs = world.getSize();

if (numprocs > 1) {
    dest = (myrank + 1) % numprocs;
    src = (myrank + numprocs - 1) % numprocs;
    if (myrank == 0) {
        world.send((MPIData)data, 0, 1, dest);
        world.recv((MPIData)data, 0, 1, src);
    } else {
        world.recv((MPIData)data, 0, 1, src);
        data[0] *= (myrank + 1);
        world.send((MPIData)data, 0, 1, dest);
    }

    if (myrank == 0)
        OUT.println("fact("+numprocs+") == " + data[0]);
}

