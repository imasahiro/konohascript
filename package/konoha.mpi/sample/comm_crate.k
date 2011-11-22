using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.getRank();
com01 = world.create([0, 1]);
com20 = world.create([2, 0]);

if (rank == 0) {
    com01.barrier(); // sync [A]
    print "first task[0 & 1]";

    exec("sleep 1");

    com20.barrier(); // sync [B]
    print "second task[0 & 2]";
} else if (rank == 1) {
    com01.barrier(); // sync [A]
    print "first task[0 & 1]";
} else if (rank == 2) {
    com20.barrier(); // sync [B]
    print "second task[0 & 2]";
}
world.barrier();
