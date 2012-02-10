using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveAllToAllBytes" {
        world.allToAll((MPIData)(Bytes)"koala", 2, (MPIData)bdata, 2);
        print bdata.decode();
        assert (|bdata| == 6);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.allToAll((MPIData)(Bytes)"nouns", 2, (MPIData)bdata, 2);
} else {
    world.allToAll((MPIData)(Bytes)"happy", 2, (MPIData)bdata, 2);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveAllToAllBytes: data counting" {
        world.allToAll((MPIData)(Bytes)"koala", 0, (MPIData)bdata, 0);
        print bdata.decode();
        assert (|bdata| == 6);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.allToAll((MPIData)(Bytes)"nouns", 0, (MPIData)bdata, 0);
} else {
    world.allToAll((MPIData)(Bytes)"happy", 0, (MPIData)bdata, 0);
}

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveAllToAllInt" {
        world.allToAll((MPIData)[1, 2, 3], 1, (MPIData)idata, 1);
        print idata;
        assert (|idata| == 3);
        assert (idata == [1, 2, 3]);
    }
} else if (rank == 1) {
    world.allToAll((MPIData)[2, 4, 6], 1, (MPIData)idata, 1);
} else {
    world.allToAll((MPIData)[3, 6, 9], 1, (MPIData)idata, 1);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveAllToAllInt: data counting" {
        world.allToAll((MPIData)[1, 2, 3], 0, (MPIData)idata, 0);
        print idata;
        assert (|idata| == 3);
        assert (idata == [1, 2, 3]);
    }
} else if (rank == 1) {
    world.allToAll((MPIData)[2, 4, 6], 0, (MPIData)idata, 0);
} else {
    world.allToAll((MPIData)[3, 6, 9], 0, (MPIData)idata, 0);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveAllToAllFloat" {
        world.allToAll((MPIData)[1.0/1, 2.0/1, 3.0/1], 1, (MPIData)fdata, 1);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [1.0/1, 1.0/1, 1.0/1]);
    }
} else if (rank == 1) {
    world.allToAll((MPIData)[1.0/1, 1.0/2, 1.0/3], 1, (MPIData)fdata, 1);
} else {
    world.allToAll((MPIData)[1.0/1, 1.0/10, 1.0/100], 1, (MPIData)fdata, 1);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveAllToAllFloat: data counting" {
        world.allToAll((MPIData)[1.0/1, 2.0/1, 3.0/1], 0, (MPIData)fdata, 0);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [1.0/1, 1.0/1, 1.0/1]);
    }
} else if (rank == 1) {
    world.allToAll((MPIData)[1.0/1, 1.0/2, 1.0/3], 0, (MPIData)fdata, 0);
} else {
    world.allToAll((MPIData)[1.0/1, 1.0/10, 1.0/100], 0, (MPIData)fdata, 0);
}
