using konoha.mpi.*;

world = MPICommunicator.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveReduceBytes" {
        world.reduceBytes((Bytes)"a", bdata, 1, MPIOp.OP_MAX, 0);
        assert (bdata.decode() == "z");
    }
} else if (rank == 1) {
    world.reduceBytes((Bytes)"D", bdata, 1, MPIOp.OP_MAX, 0);
} else {
    world.reduceBytes((Bytes)"z", bdata, 1, MPIOp.OP_MAX, 0);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveReduceInt" {
        world.reduceInt([1, 2, 3], idata, 3, MPIOp.OP_SUM, 0);
        assert (idata == [6, 12, 18]);
    }
} else if (rank == 1) {
    world.reduceInt([2, 4, 6], idata, 3, MPIOp.OP_SUM, 0);
} else {
    world.reduceInt([3, 6, 9], idata, 3, MPIOp.OP_SUM, 0);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveReduceFloat" {
        world.reduceFloat([0.1/1, 2.0/1, 3.0/1], fdata, 3, MPIOp.OP_MIN, 0);
        assert (fdata == [0.1/1, 1.0/10, 1.0/3]);
    }
} else if (rank == 1) {
    world.reduceFloat([1.0/1, 1.0/2, 1.0/3], fdata, 3, MPIOp.OP_MIN, 0);
} else {
    world.reduceFloat([1.0/1, 1.0/10, 1.0/1], fdata, 3, MPIOp.OP_MIN, 0);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveReduce" {
        world.reduce((Bytes)"AbC", bdata, MPIOp.OP_MAX, 0);
        world.reduce([1, 2], idata, MPIOp.OP_SUM, 0);
        world.reduce([0.1, 0.01], fdata, MPIOp.OP_MIN, 0);
        assert (bdata.decode() == "abc");
        assert (idata == [9, 12]);
        assert (fdata == [0.01, 0.001]);
    }
} else if (rank == 1) {
    world.reduce((Bytes)"aBC", bdata, MPIOp.OP_MAX, 0);
    world.reduce([3, 4], idata, MPIOp.OP_SUM, 0);
    world.reduce([0.01, 0.1], fdata, MPIOp.OP_MIN, 0);
} else {
    world.reduce((Bytes)"ABc", bdata, MPIOp.OP_MAX, 0);
    world.reduce([5, 6], idata, MPIOp.OP_SUM, 0);
    world.reduce([0.1, 0.001], fdata, MPIOp.OP_MIN, 0);
}
