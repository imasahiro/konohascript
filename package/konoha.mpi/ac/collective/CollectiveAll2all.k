using konoha.mpi.*;

world = MPICommunicator.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveAllToAllBytes" {
        world.allToAllBytes((Bytes)"koala", 2, bdata);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.allToAllBytes((Bytes)"nouns", 2, bdata);
} else {
    world.allToAllBytes((Bytes)"happy", 2, bdata);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveAllToAllInt" {
        world.allToAllInt([1, 2, 3], 1, idata);
        assert (idata == [1, 2, 3]);
    }
} else if (rank == 1) {
    world.allToAllInt([2, 4, 6], 1, idata);
} else {
    world.allToAllInt([3, 6, 9], 1, idata);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllToAllFloat" {
        world.allToAllFloat([1.0/1, 2.0/1, 3.0/1], 1, fdata);
        assert (fdata == [1.0/1, 1.0/1, 1.0/1]);
    }
} else if (rank == 1) {
    world.allToAllFloat([1.0/1, 1.0/2, 1.0/3], 1, fdata);
} else {
    world.allToAllFloat([1.0/1, 1.0/10, 1.0/100], 1, fdata);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllToAll" {
        world.allToAll((Bytes)"abouts", bdata);
        world.allToAll([1, 2, 4, 8, 16, 32], idata);
        world.allToAll([0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001], fdata);
        assert (bdata.decode() == "abcdef");
        assert (idata == [1, 2, 3, 4, 5, 6]);
        assert (fdata == [0.1, 0.01, 0.01, 0.1, 0.1, 0.11]);
    }
} else if (rank == 1) {
    world.allToAll((Bytes)"cd-rom", bdata);
    world.allToAll([3, 4, 5, 9, 16, 25], idata);
    world.allToAll([0.01, 0.1, 1.0, 10.0, 100.0, 1000.0], fdata);
} else {
    world.allToAll((Bytes)"effect", bdata);
    world.allToAll([5, 6, 10, 12, 50, 60], idata);
    world.allToAll([0.1, 0.11, 0.111, 0.1111, 0.11111, 0.111111], fdata);
}
