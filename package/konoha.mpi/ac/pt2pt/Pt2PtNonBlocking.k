using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"konoha", 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes" {
        data = new byte[0];
        req = world.iRecv((MPIData)data, 6, 0);
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtNonBlockingInt" {
        data = new int[0];
        req = world.iRecv((MPIData)data, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat" {
        data = new float[0];
        req = world.iRecv((MPIData)data, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}
world.barrier();
