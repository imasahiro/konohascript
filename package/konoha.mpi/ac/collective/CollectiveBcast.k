using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveBcastBytes" {
        world.bcastBytes(bdata, 6, 1);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.bcastBytes((Bytes)"konoha", 6, 1);
} else {
    world.bcastBytes(bdata, 6, 1);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveBcastInt" {
        world.bcastInt(idata, 5, 1);
        assert (idata == [1, 2, 3, 5, 7]);
    }
} else if (rank == 1) {
    world.bcastInt([1, 2, 3, 5, 7], 5, 1);
} else {
    world.bcastInt(idata, 5, 1);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveBcastFloat" {
        world.bcastFloat(fdata, 5, 1);
        assert (fdata == [1.1, 2.2, 3.3, 4.4, 5.5]);
    }
} else if (rank == 1) {
    world.bcastFloat([1.1, 2.2, 3.3, 4.4, 5.5], 5, 1);
} else {
    world.bcastFloat(fdata, 5, 1);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveBcast" {
        world.bcast(bdata, 1);
        world.bcast(idata, 1);
        world.bcast(fdata, 1);
        assert (bdata.decode() == "This is an apple I like");
        assert (idata == [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]);
        assert (fdata == [1.414214, 1.732051, 2.0]);
    }
} else if (rank == 1) {
    world.bcast((Bytes)"This is an apple I like", 1);
    world.bcast([1, 1, 2, 3, 5, 8, 13, 21, 34, 55], 1);
    world.bcast([1.414214, 1.732051, 2.0], 1);
} else {
    world.bcast(bdata, 1);
    world.bcast(idata, 1);
    world.bcast(fdata, 1);
}

