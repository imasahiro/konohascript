using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

/*
bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveAllReduceBytes" {
        world.allReduce((MPIData)(Bytes)"a", (MPIData)bdata, 1, MPIOp.MAX);
        print bdata.decode();
        assert (|bdata| == 1);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.allReduce((MPIData)(Bytes)"D", (MPIData)bdata, 1, MPIOp.MAX);
} else {
    world.allReduce((MPIData)(Bytes)"z", (MPIData)bdata, 1, MPIOp.MAX);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveAllReduceBytes: data counting" {
        world.allReduce((MPIData)(Bytes)"a", (MPIData)bdata, 0, MPIOp.MAX);
        print bdata.decode();
        assert (|bdata| == 1);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.allReduce((MPIData)(Bytes)"D", (MPIData)bdata, 0, MPIOp.MAX);
} else {
    world.allReduce((MPIData)(Bytes)"z", (MPIData)bdata, 0, MPIOp.MAX);
}
*/

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveAllReduceInt" {
        world.allReduce((MPIData)[1, 2, 3], (MPIData)idata, 3, MPIOp.SUM);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.allReduce((MPIData)[2, 4, 6], (MPIData)idata, 3, MPIOp.SUM);
} else {
    world.allReduce((MPIData)[3, 6, 9], (MPIData)idata, 3, MPIOp.SUM);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveAllReduceInt: data counting" {
        world.allReduce((MPIData)[1, 2, 3], (MPIData)idata, 0, MPIOp.SUM);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.allReduce((MPIData)[2, 4, 6], (MPIData)idata, 0, MPIOp.SUM);
} else {
    world.allReduce((MPIData)[3, 6, 9], (MPIData)idata, 0, MPIOp.SUM);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveAllReduceFloat" {
        world.allReduce((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, 3, MPIOp.MIN);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.allReduce((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, 3, MPIOp.MIN);
} else {
    world.allReduce((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, 3, MPIOp.MIN);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveAllReduceFloat: data counting" {
        world.allReduce((MPIData)[0.1/1, 2.0/1, 3.0/1], (MPIData)fdata, 0, MPIOp.MIN);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.allReduce((MPIData)[1.0/1, 1.0/2, 1.0/3], (MPIData)fdata, 0, MPIOp.MIN);
} else {
    world.allReduce((MPIData)[1.0/1, 1.0/10, 1.0/1], (MPIData)fdata, 0, MPIOp.MIN);
}
