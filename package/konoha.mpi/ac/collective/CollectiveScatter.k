using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveScatterBytes" {
        world.scatter(null, 2, (MPIData)bdata, 2, 1);
        print bdata.decode();
        assert (|bdata| == 2);
        assert (bdata.decode() == "ko");
    }
} else if (rank == 1) {
    world.scatter((MPIData)(Bytes)"konoha", 2, (MPIData)bdata, 2, 1);
} else {
    world.scatter(null, 2, (MPIData)bdata, 2, 1);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveScatterBytes: data counting" {
        world.scatter(null, 0, (MPIData)bdata, 0, 1);
        print bdata.decode();
        assert (|bdata| == 2);
        assert (bdata.decode() == "ko");
    }
} else if (rank == 1) {
    world.scatter((MPIData)(Bytes)"konoha", 0, (MPIData)bdata, 0, 1);
} else {
    world.scatter(null, 0, (MPIData)bdata, 0, 1);
}

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveScatterInt" {
        world.scatter(null, 2, (MPIData)idata, 2, 1);
        print idata;
        assert (|idata| == 2);
        assert (idata == [1, 2]);
    }
} else if (rank == 1) {
    world.scatter((MPIData)[1, 2, 3, 5, 7, 11], 2, (MPIData)idata, 2, 1);
} else {
    world.scatter(null, 2, (MPIData)idata, 2, 1);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveScatterInt: data counting" {
        world.scatter(null, 0, (MPIData)idata, 0, 1);
        print idata;
        assert (|idata| == 2);
        assert (idata == [1, 2]);
    }
} else if (rank == 1) {
    world.scatter((MPIData)[1, 2, 3, 5, 7, 11], 0, (MPIData)idata, 0, 1);
} else {
    world.scatter(null, 0, (MPIData)idata, 0, 1);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveScatterFloat" {
        world.scatter(null, 2, (MPIData)fdata, 2, 1);
        print fdata;
        assert (|fdata| == 2);
        assert (fdata == [1.1, 2.2]);
    }
} else if (rank == 1) {
    world.scatter((MPIData)[1.1, 2.2, 3.3, 4.4, 5.5, 6.6], 2, (MPIData)fdata, 2, 1);
} else {
    world.scatter(null, 2, (MPIData)fdata, 2, 1);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveScatterFloat: data counting" {
        world.scatter(null, 0, (MPIData)fdata, 0, 1);
        print fdata;
        assert (|fdata| == 2);
        assert (fdata == [1.1, 2.2]);
    }
} else if (rank == 1) {
    world.scatter((MPIData)[1.1, 2.2, 3.3, 4.4, 5.5, 6.6], 0, (MPIData)fdata, 0, 1);
} else {
    world.scatter(null, 0, (MPIData)fdata, 0, 1);
}
