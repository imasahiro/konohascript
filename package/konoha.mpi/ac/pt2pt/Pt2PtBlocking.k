using konoha.mpi.*;

world = MPICommunicator.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 2) exit();
if (rank == 0) disableLog();


if (rank == 0) {
    world.sendBytes((Bytes)"konoha", 1);
} else {
    assure "Pt2PtBlockingBytes" {
        Bytes data = new Bytes();
        world.recvBytes(data, 0);
        assert (data.decode() == "konoha");
    }
}

if (rank == 0) {
    world.sendInt([1, 3, 5], 1);
} else {
    assure "Pt2PtBlockingInt" {
        IArray data = new IArray();
        world.recvInt(data, 0);
        assert (data == [1, 3, 5]);
    }
}

if (rank == 0) {
    world.sendFloat([1.2, 3.4, 5.6], 1);
} else {
    assure "Pt2PtBlockingFloat" {
        FArray data = new FArray();
        world.recvFloat(data, 0);
        assert (data == [1.2, 3.4, 5.6]);
    }
}

if (rank == 0) {
    world.send((Bytes)"this is an apple I like", 1);
    world.send([1, 1, 2, 3, 5, 8, 13, 21, 34, 55], 1);
    world.send([1.414214, 1.732051, 2.0], 1);
} else {
    assure "Pt2PtBlocking" {
        Bytes bdata = new Bytes();
        world.recv(bdata, 0);
        IArray idata = new IArray();
        world.recv(idata, 0);
        FArray fdata = new FArray();
        world.recv(fdata, 0);
        assert (bdata.decode() == "this is an apple I like");
        assert (idata == [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]);
        assert (fdata == [1.414214, 1.732051, 2.0]);
    }
}
