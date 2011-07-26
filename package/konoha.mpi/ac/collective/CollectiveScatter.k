using konoha.mpi.*;

world = MPICommunicator.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveScatterBytes" {
        world.scatterBytes(new Bytes(), 2, bdata, 1);
        assert (bdata.decode() == "ko");
    }
} else if (rank == 1) {
    world.scatterBytes((Bytes)"konoha", 2, bdata, 1);
} else {
    world.scatterBytes(new Bytes(), 2, bdata, 1);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveScatterInt" {
        world.scatterInt(new IArray(), 2, idata, 1);
        assert (idata == [1, 2]);
    }
} else if (rank == 1) {
    world.scatterInt([1, 2, 3, 5, 7, 11], 2, idata,  1);
} else {
    world.scatterInt(new IArray(), 2, idata, 1);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveScatterFloat" {
        world.scatterFloat(new FArray(), 2, fdata, 1);
        assert (fdata == [1.1, 2.2]);
    }
} else if (rank == 1) {
    world.scatterFloat([1.1, 2.2, 3.3, 4.4, 5.5, 6.6], 2, fdata, 1);
} else {
    world.scatterFloat(new FArray(), 2, fdata, 1);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveScatter" {
        world.scatter(new Bytes(), bdata, 1);
        world.scatter(new IArray(), idata, 1);
        world.scatter(new FArray(), fdata, 1);
        assert (bdata.decode() == "This is ");
        assert (idata == [1, 1, 2, 3]);
        assert (fdata == [1.414214]);
    }
} else if (rank == 1) {
    world.scatter((Bytes)"This is an apple I like.", bdata, 1);
    world.scatter([1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144], idata, 1);
    world.scatter([1.414214, 1.732051, 2.0], fdata, 1);
} else {
    world.scatter(new Bytes(), bdata, 1);
    world.scatter(new IArray(), idata, 1);
    world.scatter(new FArray(), fdata, 1);
}
