using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 2) exit();
if (rank == 0) disableLog();


if (rank == 0) {
    world.iSendbytes((Bytes)"konoha", 1);
} else {
    exec("sleep 0.3"); // take a bit time delay
    assure "Pt2PtNonBlockingBytes" {
        Bytes data = new Bytes();
        world.iRecvBytes(data, 0);
        assert (data.decode() == "konoha");
    }
}

if (rank == 0) {
    world.iSendInt([1, 3, 5], 1);
} else {
    exec("sleep 0.3"); // take a bit time delay
    assure "Pt2PtNonBlockingInt" {
        IArray data = new IArray();
        world.iRecvInt(data, 0);
        assert (data == [1, 3, 5]);
    }
}

if (rank == 0) {
    world.iSendFloat([1.2, 3.4, 5.6], 1);
} else {
    exec("sleep 0.3"); // take a bit time delay
    assure "Pt2PtNonBlockingFloat" {
        FArray data = new FArray();
        world.iRecvFloat(data, 0);
        assert (data == [1.2, 3.4, 5.6]);
    }
}

if (rank == 0) {
    world.iSend((Bytes)"this is an apple I like", 1);
    world.iSend([1, 1, 2, 3, 5, 8, 13, 21, 34, 55], 1);
    world.iSend([1.414214, 1.732051, 2.0], 1);
} else {
    exec("sleep 0.3"); // take a bit time delay
    assure "Pt2PtNonBlocking" {
        Bytes bdata = new Bytes();
        world.iRecv(bdata, 0);
        IArray idata = new IArray();
        world.iRecv(idata, 0);
        FArray fdata = new FArray();
        world.iRecv(fdata, 0);
        assert (bdata.decode() == "this is an apple I like");
        assert (idata == [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]);
        assert (fdata == [1.414214, 1.732051, 2.0]);
    }
}
