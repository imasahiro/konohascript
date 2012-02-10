using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) MPI.preventLog();

bdata = new byte[0];
if (rank == 0) {
    world.sendRecv((MPIData)(Bytes)"hello,", 6, 1, 0, (MPIData)bdata, 6, 1, 0);
    world.sendRecv((MPIData)bdata, 6, 1, 0, (MPIData)new byte[0], 0, 1, 0);
} else {
    assure "Pt2PtSendRecvBytes" {
        world.sendRecv((MPIData)(Bytes)"konoha", 6, 0, 0, (MPIData)bdata, 6, 0, 0);
        world.sendRecv((MPIData)new byte[0], 0, 0, 0, (MPIData)bdata+6, 6, 0, 0);
        print bdata.decode();
        assert (|bdata| == 12);
        assert (bdata.decode() == "hello,konoha");
    }
}

idata = new int[0];
if (rank == 0) {
    world.sendRecv((MPIData)[1, 2, 3], 3, 1, 0, (MPIData)idata, 3, 1, 0);
    world.sendRecv((MPIData)idata, 3, 1, 0, (MPIData)new int[0], 0, 1, 0);
} else {
    assure "Pt2PtSendRecvInt" {
        world.sendRecv((MPIData)[4, 5, 6], 3, 0, 0, (MPIData)idata, 3, 0, 0);
        world.sendRecv((MPIData)new int[0], 0, 0, 0, (MPIData)idata+3, 3, 0, 0);
        print idata;
        assert (|idata| == 6);
        assert (idata == [1, 2, 3, 4, 5, 6]);
    }
}

fdata = new float[0];
if (rank == 0) {
    world.sendRecv((MPIData)[1.2, 3.4, 5.6], 3, 1, 0, (MPIData)fdata, 3, 1, 0);
    world.sendRecv((MPIData)fdata, 3, 1, 0, (MPIData)new float[0], 0, 1, 0);
} else {
    assure "Pt2PtSendRecvFloat" {
        world.sendRecv((MPIData)[1.2, 3.4, 5.6], 3, 0, 0, (MPIData)fdata, 3, 0, 0);
        world.sendRecv((MPIData)new float[0], 0, 0, 0, (MPIData)fdata+3, 3, 0, 0);
        print fdata;
        assert (|fdata| == 6);
        assert (fdata == [1.2, 3.4, 5.6, 1.2, 3.4, 5.6]);
    }
}
