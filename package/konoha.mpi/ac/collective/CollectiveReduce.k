using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) disableLog();

/* ------------------------------------------------------------------------ */

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveReduceBytes" {
        world.reduce((MPIData)(Bytes)"a", 0, (MPIData)bdata, 0, 1, MPIOp.MAX, 0);
        print bdata.decode();
        assert (|bdata| == 1);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.reduce((MPIData)(Bytes)"D", 0, (MPIData)bdata, 0, 1, MPIOp.MAX, 0);
} else {
    world.reduce((MPIData)(Bytes)"z", 0, (MPIData)bdata, 0, 1, MPIOp.MAX, 0);
}

bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveReduceBytes: data counting" {
        world.reduce((MPIData)(Bytes)"a", 0, (MPIData)bdata, 0, 0, MPIOp.MAX, 0);
        print bdata.decode();
        assert (|bdata| == 1);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.reduce((MPIData)(Bytes)"D", 0, (MPIData)bdata, 0, 0, MPIOp.MAX, 0);
} else {
    world.reduce((MPIData)(Bytes)"z", 0, (MPIData)bdata, 0, 0, MPIOp.MAX, 0);
}

/* ------------------------------------------------------------------------ */

idata = new int[0];
if (rank == 0) {
    assure "CollectiveReduceInt" {
        world.reduce((MPIData)[1, 2, 3], 0, (MPIData)idata, 0, 3, MPIOp.SUM, 0);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)[2, 4, 6], 0, (MPIData)idata, 0, 3, MPIOp.SUM, 0);
} else {
    world.reduce((MPIData)[3, 6, 9], 0, (MPIData)idata, 0, 3, MPIOp.SUM, 0);
}

idata = new int[0];
if (rank == 0) {
    assure "CollectiveReduceInt" {
        world.reduce((MPIData)[1, 2, 3], 0, (MPIData)idata, 0, 0, MPIOp.SUM, 0);
        print idata;
        assert (|idata| == 3);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)[2, 4, 6], 0, (MPIData)idata, 0, 0, MPIOp.SUM, 0);
} else {
    world.reduce((MPIData)[3, 6, 9], 0, (MPIData)idata, 0, 0, MPIOp.SUM, 0);
}

/* ------------------------------------------------------------------------ */

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceFloat" {
        world.reduce((MPIData)[0.1/1, 2.0/1, 3.0/1], 0, (MPIData)fdata, 0, 3, MPIOp.MIN, 0);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)[1.0/1, 1.0/2, 1.0/3], 0, (MPIData)fdata, 0, 3, MPIOp.MIN, 0);
} else {
    world.reduce((MPIData)[1.0/1, 1.0/10, 1.0/1], 0, (MPIData)fdata, 0, 3, MPIOp.MIN, 0);
}

fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceFloat: data counting" {
        world.reduce((MPIData)[0.1/1, 2.0/1, 3.0/1], 0, (MPIData)fdata, 0, 0, MPIOp.MIN, 0);
        print fdata;
        assert (|fdata| == 3);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)[1.0/1, 1.0/2, 1.0/3], 0, (MPIData)fdata, 0, 0, MPIOp.MIN, 0);
} else {
    world.reduce((MPIData)[1.0/1, 1.0/10, 1.0/1], 0, (MPIData)fdata, 0, 0, MPIOp.MIN, 0);
}
