using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 2) exit();
if (rank == 0) disableLog();


Bytes bdata = new Bytes();
if (rank == 0) {
    world.sendRecvBytes(new Bytes(), 1, bdata, 6, 1);
    world.sendRecvBytes(bdata, 1, new Bytes(), 1, 1);
} else {
    assure "Pt2PtSendRecvBytes" {
        world.sendRecvBytes((Bytes)"konoha", 0, bdata, 6, 0);
        world.sendRecvBytes(new Bytes(), 0, bdata, 6, 0);
        assert (bdata.decode() == "konoha");
    }
}

IArray idata = new IArray();
if (rank == 0) {
    world.sendRecvInt(new IArray(), 1, idata, 3, 1);
    world.sendRecvInt(idata, 1, new IArray(), 1, 1);
} else {
    assure "Pt2PtSendRecvInt" {
        world.sendRecvInt([1, 3, 5], 0, idata, 3, 0);
        world.sendRecvInt(new IArray(), 0, idata, 3, 0);
        assert (idata == [1, 3, 5]);
    }
}

FArray fdata = new FArray();
if (rank == 0) {
    world.sendRecvFloat(new FArray(), 1, fdata, 3, 1);
    world.sendRecvFloat(fdata, 1, new FArray(), 1, 1);
} else {
    assure "Pt2PtSendRecvFloat" {
        world.sendRecvFloat([1.2, 3.4, 5.6], 0, fdata, 3, 0);
        world.sendRecvFloat(new FArray(), 0, fdata, 3, 0);
        assert (fdata == [1.2, 3.4, 5.6]);
    }
}


if (rank == 0) {
    world.sendRecv((Bytes)"this is an apple I like", 1, new Bytes(), 1);
    world.sendRecv([1, 1, 2, 3, 5, 8, 13, 21, 34, 55], 1, new IArray(), 1);
    world.sendRecv([1.414214, 1.732051, 2.0], 1, new FArray(), 1);
} else {
    assure "Pt2PtSendRecv" {
        Bytes bdata = new Bytes();
        world.sendRecv(new Bytes(), 0, bdata, 0);
        assert (bdata.decode() == "this is an apple I like");
        IArray idata = new IArray();
        world.sendRecv(new IArray(), 0, idata, 0);
        assert (idata == [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]);
        FArray fdata = new FArray();
        world.sendRecv(new FArray(), 0, fdata, 0);
        assert (fdata == [1.414214, 1.732051, 2.0]);
    }
}
