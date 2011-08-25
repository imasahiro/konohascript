using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    assure "CollectiveGatherBytes" {
        world.gatherBytes((Bytes)"%s"(rank), 1, bdata, 0);
        assert (bdata.decode() == "012");
    }
} else {
    world.gatherBytes((Bytes)"%s"(rank), 1, bdata, 0);
}

IArray idata = new IArray();
if (rank == 0) {
    assure "CollectiveGatherInt" {
        world.gatherInt([rank], 1, idata, 0);
        assert (idata == [0, 1, 2]);
    }
} else {
    world.gatherInt([rank], 1, idata, 0);
}

FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveGatherFloat" {
        world.gatherFloat([1.0 / (rank+1)], 1, fdata, 0);
        assert (fdata == [1.0/1, 1.0/2, 1.0/3]);
    }
} else {
    world.gatherFloat([1.0 / (rank+1)], 1, fdata, 0);
}

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveGather" {
        world.gather((Bytes)"konoha", bdata, 0);
        world.gather([1, 2, 3], idata, 0);
        world.gather([1.111111, 2.222222, 3.333333], fdata, 0);
        assert (bdata.decode() == "konoha, konoha, konoha");
        assert (idata == [1, 2, 3, 1, 2, 3, 1, 2, 3]);
        assert (fdata == [1.111111, 2.222222, 3.333333, 1.111111, 2.222222, 3.333333, 1.111111, 2.222222, 3.333333]);
    }
} else {
    world.gather((Bytes)", konoha", bdata, 0);
    world.gather([1, 2, 3], idata, 0);
    world.gather([1.111111, 2.222222, 3.333333], fdata, 0);
}
