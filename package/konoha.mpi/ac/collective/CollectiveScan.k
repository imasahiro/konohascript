using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    world.scan((MPIData)[1, 2, 3], (MPIData)idata, 3, MPIOp.SUM);
} else if (rank == 1) {
    world.scan((MPIData)[2, 4, 6], (MPIData)idata, 3, MPIOp.SUM);
} else {
    assure "CollectiveScanInt" {
        world.scan((MPIData)[3, 6, 9], (MPIData)idata, 3, MPIOp.SUM);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
}

idata = new int[0];
if (rank == 0) {
    world.scan((MPIData)[1, 2, 3], (MPIData)idata, 0, MPIOp.SUM);
} else if (rank == 1) {
    world.scan((MPIData)[2, 4, 6], (MPIData)idata, 0, MPIOp.SUM);
} else {
    assure "CollectiveScanInt: data counting" {
        world.scan((MPIData)[3, 6, 9], (MPIData)idata, 0, MPIOp.SUM);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    world.scan((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, 3, MPIOp.MIN);
} else if (rank == 1) {
    world.scan((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, 3, MPIOp.MIN);
} else {
    assure "CollectiveScanFloat" {
        world.scan((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, 3, MPIOp.MIN);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
}

fdata = new float[0];
if (rank == 0) {
    world.scan((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, 0, MPIOp.MIN);
} else if (rank == 1) {
    world.scan((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, 0, MPIOp.MIN);
} else {
    assure "CollectiveScanFloat: data counting" {
        world.scan((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, 0, MPIOp.MIN);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
}
