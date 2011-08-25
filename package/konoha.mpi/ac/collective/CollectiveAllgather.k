using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveAllGatherBytes" {
        world.allGatherBytes((Bytes)"koala", 2, bdata);
        assert (bdata.decode() == "konoha");
    }
} else if (rank == 1) {
    world.allGatherBytes((Bytes)"nouns", 2, bdata);
} else {
    world.allGatherBytes((Bytes)"happy", 2, bdata);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveAllGatherInt" {
        world.allGatherInt([1, 2, 3], 1, idata);
        assert (idata == [1, 2, 3]);
    }
} else if (rank == 1) {
    world.allGatherInt([2, 4, 6], 1, idata);
} else {
    world.allGatherInt([3, 6, 9], 1, idata);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllGatherFloat" {
        world.allGatherFloat([1.0/1, 2.0/1, 3.0/1], 1, fdata);
        assert (fdata == [1.0/1, 1.0/1, 1.0/1]);
    }
} else if (rank == 1) {
    world.allGatherFloat([1.0/1, 1.0/2, 1.0/3], 1, fdata);
} else {
    world.allGatherFloat([1.0/1, 1.0/10, 1.0/100], 1, fdata);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveAllGather" {
        world.allGather((Bytes)"ab", bdata);
        world.allGather([1, 2], idata);
        world.allGather([0.1, 0.01], fdata);
        assert (bdata.decode() == "abcdef");
        assert (idata == [1, 2, 3, 4, 5, 6]);
        assert (fdata == [0.1, 0.01, 0.01, 0.1, 0.1, 0.11]);
    }
} else if (rank == 1) {
    world.allGather((Bytes)"cd", bdata);
    world.allGather([3, 4], idata);
    world.allGather([0.01, 0.1], fdata);
} else {
    world.allGather((Bytes)"ef", bdata);
    world.allGather([5, 6], idata);
    world.allGather([0.1, 0.11], fdata);
}
