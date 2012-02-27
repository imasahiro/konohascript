using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveReduceScatter" {
        world.reduceScatter((MPIData)[1, 2, 3], (MPIData)idata, [1,1,1], MPIOp.SUM);
        print idata;
        assert (|idata| == 1);
        assert (idata == [6]);
    }
} else if (rank == 1) {
    world.reduceScatter((MPIData)[2, 4, 6], (MPIData)idata, [1,1,1], MPIOp.SUM);
} else {
    world.reduceScatter((MPIData)[3, 6, 9], (MPIData)idata, [1,1,1], MPIOp.SUM);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveReduceScatterInt: data counting" {
        world.reduceScatter((MPIData)[1, 2, 3], (MPIData)idata, new int[0], MPIOp.SUM);
        print idata;
        assert (|idata| == 1);
        assert (idata == [6]);
    }
} else if (rank == 1) {
    world.reduceScatter((MPIData)[2, 4, 6], (MPIData)idata, new int[0], MPIOp.SUM);
} else {
    world.reduceScatter((MPIData)[3, 6, 9], (MPIData)idata, new int[0], MPIOp.SUM);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceScatterFloat" {
        world.reduceScatter((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, new int[0], MPIOp.MIN);
        print fdata;
        assert (|fdata| == 1);
        assert (fdata == [0.1/1]);
    }
} else if (rank == 1) {
    world.reduceScatter((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, new int[0], MPIOp.MIN);
} else {
    world.reduceScatter((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, new int[0], MPIOp.MIN);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceScatterFloat: data counting" {
        world.reduceScatter((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, new int[0], MPIOp.MIN);
        print fdata;
        assert (|fdata| == 1);
        assert (fdata == [0.1/1]);
    }
} else if (rank == 1) {
    world.reduceScatter((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, new int[0], MPIOp.MIN);
} else {
    world.reduceScatter((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, new int[0], MPIOp.MIN);
}
