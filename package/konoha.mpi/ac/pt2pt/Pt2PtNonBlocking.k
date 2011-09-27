using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 2) exit();
if (rank == 0) disableLog();

if (rank == 0) {
    world.iSendbytes((Bytes)"konoha", 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes" {
        Bytes data = new Bytes();
        req = world.iRecvBytes(data, 6, 0);
        req.wait();
        assert (data.decode() == "konoha");
    }
}
world.barrier();

if (rank == 0) {
    world.iSendInt([1, 3, 5], 3, 1);
} else {
    assure "Pt2PtNonBlockingInt" {
        IArray data = new IArray();
        req = world.iRecvInt(data, 3, 0);
        req.wait();
        assert (data == [1, 3, 5]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSendFloat([1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat" {
        FArray data = new FArray();
        req = world.iRecvFloat(data, 3, 0);
        req.wait();
        assert (data == [1.2, 3.4, 5.6]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((Bytes)"this is an apple I like", 1);
    world.iSend([1, 1, 2, 3, 5, 8, 13, 21, 34, 55], 1);
    world.iSend([1.414214, 1.732051, 2.0], 1);
} else {
    assure "Pt2PtNonBlocking" {
        Bytes bdata = new Bytes();
        r1 = world.iRecv(bdata, 0);
        IArray idata = new IArray();
        r2 = world.iRecv(idata, 0);
        FArray fdata = new FArray();
        r3 = world.iRecv(fdata, 0);
        r1.wait();
        assert (bdata.decode() == "this is an apple I like");
        r2.wait();
        assert (idata == [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]);
        r3.wait();
        assert (fdata == [1.414214, 1.732051, 2.0]);
    }
}
world.barrier();
