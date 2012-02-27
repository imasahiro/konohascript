using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveBcastBytes" {
        world.bcast((MPIData)bdata, 6, 1);
        print bdata.decode();
        assert (|bdata| == 6);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.bcast((MPIData)(Bytes)"konoha", 6, 1);
} else {
    world.bcast((MPIData)bdata, 6, 1);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveBcastBytes: data counting" {
        world.bcast((MPIData)bdata, 0, 1);
        print bdata.decode();
        assert (|bdata| == 11);
        assert (bdata.decode() == "hello,world");
    }
} else if (rank == 1) {
    world.bcast((MPIData)(Bytes)"hello,world", 0, 1);
} else {
    world.bcast((MPIData)bdata, 0, 1);
}

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveBcastInt" {
        world.bcast((MPIData)idata, 5, 1);
        print idata;
        assert (|idata| == 5);
        assert (idata == [1, 2, 3, 5, 7]);
    }
} else if (rank == 1) {
    world.bcast((MPIData)[1, 2, 3, 5, 7], 5, 1);
} else {
    world.bcast((MPIData)idata, 5, 1);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveBcastInt: data counting" {
        world.bcast((MPIData)idata, 0, 1);
        print idata;
        assert (|idata| == 4);
        assert (idata == [2, 4, 8, 16]);
    }
} else if (rank == 1) {
    world.bcast((MPIData)[2, 4, 8, 16], 0, 1);
} else {
    world.bcast((MPIData)idata, 0, 1);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveBcastFloat" {
        world.bcast((MPIData)fdata, 5, 1);
        print fdata;
        assert (|fdata| == 5);
        assert (fdata == [1.1, 2.2, 3.3, 4.4, 5.5]);
    }
} else if (rank == 1) {
    world.bcast((MPIData)[1.1, 2.2, 3.3, 4.4, 5.5], 5, 1);
} else {
    world.bcast((MPIData)fdata, 5, 1);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveBcastFloat: data counting" {
        world.bcast((MPIData)fdata, 0, 1);
        print fdata;
        assert (|fdata| == 4);
        assert (fdata == [2.2, 4.4, 6.6, 8.8]);
    }
} else if (rank == 1) {
    world.bcast((MPIData)[2.2, 4.4, 6.6, 8.8], 0, 1);
} else {
    world.bcast((MPIData)fdata, 0, 1);
}
