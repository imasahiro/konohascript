using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveGatherBytes" {
        world.gather((MPIData)(Bytes)"%s"(rank), 1, (MPIData)bdata, 1, 0);
        print bdata.decode();
        assert (|bdata| == 3);
        assert (bdata.decode() == "012");
    }
} else {
    world.gather((MPIData)(Bytes)"%s"(rank), 1, null, 0, 0);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveGatherBytes: data counting" {
        world.gather((MPIData)(Bytes)"%s"(rank), 0, (MPIData)bdata, 0, 0);
        print bdata.decode();
        assert (|bdata| == 3);
        assert (bdata.decode() == "012");
    }
} else {
    world.gather((MPIData)(Bytes)"%s"(rank), 0, null, 0, 0);
}

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveGatherInt" {
        world.gather((MPIData)[rank], 1, (MPIData)idata, 1, 0);
        print idata;
        assert (|idata| == 3);
        assert (idata == [0, 1, 2]);
    }
} else {
    world.gather((MPIData)[rank], 1, null, 0, 0);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveGatherInt: data counting" {
        world.gather((MPIData)[rank], 0, (MPIData)idata, 0, 0);
        print idata;
        assert (|idata| == 3);
        assert (idata == [0, 1, 2]);
    }
} else {
    world.gather((MPIData)[rank], 0, null, 0, 0);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveGatherFloat" {
        world.gather((MPIData)[1.0 / (rank+1)], 1, (MPIData)fdata, 1, 0);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [1.0/1, 1.0/2, 1.0/3]);
    }
} else {
    world.gather((MPIData)[1.0 / (rank+1)], 1, null, 0, 0);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveGatherFloat: data counting" {
        world.gather((MPIData)[1.0 / (rank+1)], 0, (MPIData)fdata, 0, 0);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [1.0/1, 1.0/2, 1.0/3]);
    }
} else {
    world.gather((MPIData)[1.0 / (rank+1)], 0, null, 0, 0);
}
