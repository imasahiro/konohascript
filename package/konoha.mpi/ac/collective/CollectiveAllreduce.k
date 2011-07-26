using konoha.mpi.*;

world = MPICommunicator.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveAllReduceBytes" {
        world.allReduceBytes((Bytes)"a", bdata, 1, MPIOp.OP_MAX);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.allReduceBytes((Bytes)"D", bdata, 1, MPIOp.OP_MAX);
} else {
    world.allReduceBytes((Bytes)"z", bdata, 1, MPIOp.OP_MAX);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveAllReduceInt" {
        world.allReduceInt([1, 2, 3], idata, 3, MPIOp.OP_SUM);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.allReduceInt([2, 4, 6], idata, 3, MPIOp.OP_SUM);
} else {
    world.allReduceInt([3, 6, 9], idata, 3, MPIOp.OP_SUM);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllReduceFloat" {
        world.allReduceFloat([0.1/1, 2.0/1, 3.0/1], fdata, 3, MPIOp.OP_MIN);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.allReduceFloat([1.0/1, 1.0/2, 1.0/3], fdata, 3, MPIOp.OP_MIN);
} else {
    world.allReduceFloat([1.0/1, 1.0/10, 1.0/1], fdata, 3, MPIOp.OP_MIN);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllReduce" {
        world.allReduce((Bytes)"AbC", bdata, MPIOp.OP_MAX);
        world.allReduce([1, 2], idata, MPIOp.OP_SUM);
        world.allReduce([0.1, 0.01], fdata, MPIOp.OP_MIN);
        assert (bdata.decode() == "abc");
        assert (idata == [9, 12]);
        assert (fdata == [0.01, 0.001]);
    }
} else if (rank == 1) {
    world.allReduce((Bytes)"aBC", bdata, MPIOp.OP_MAX);
    world.allReduce([3, 4], idata, MPIOp.OP_SUM);
    world.allReduce([0.01, 0.1], fdata, MPIOp.OP_MIN);
} else {
    world.allReduce((Bytes)"ABc", bdata, MPIOp.OP_MAX);
    world.allReduce([5, 6], idata, MPIOp.OP_SUM);
    world.allReduce([0.1, 0.001], fdata, MPIOp.OP_MIN);
}
