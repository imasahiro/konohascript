using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"konoha", 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes: correct case" {
        data = new byte[0];
        req = world.iRecv((MPIData)data, 6, 0);
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

if (rank == 0) {
    //req = world.iRecv((MPIData)new byte[0], 6, 0); // should be failed to append
} else {
    assure "Pt2PtNonBlockingBytes: invalid input offset" {
        boolean isCaught;
        try {
            world.iSend((MPIData)(Bytes)"thisiskonoha"+20, 6, 1); // bad input
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"thisiskonoha"+6, 12, 1); // over border
} else {
    assure "Pt2PtNonBlockingBytes: input beyond border" {
        data = (Bytes)"konoha";
        req = world.iRecv((MPIData)data+6, 12, 0); // should be appended as a part
        req.wait();
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "konohakonoha");
    }
}
world.barrier();

if (rank == 0) {
    //world.iSend((MPIData)(Bytes)"thisiskonoha"+6, 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes: invalid output offset" {
        boolean isCaught;
        try {
            data = (Bytes)"konoha";
            req = world.iRecv((MPIData)data+18, 6, 0); // bad offset
            req.wait();
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtNonBlockingInt: correct case" {
        data = new int[0];
        req = world.iRecv((MPIData)data, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}
world.barrier();

if (rank == 0) {
    //req = world.iRecv((MPIData)new int[0], 3, 0); // recieve 0 length
} else {
    assure "Pt2PtNonBlockingInt: invalid input offset" {
        boolean isCaught;
        try {
            world.iSend((MPIData)[1, 3, 5]+5, 3, 1); // bad input
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5]+2, 3, 1); // over border
} else {
    assure "Pt2PtNonBlockingInt: input beyond border" {
        data = [1, 2, 3];
        req = world.iRecv((MPIData)data+3, 3, 0); // recieve a part
        req.wait();
        print data;
        assert (|data| == 4);
        assert (data == [1, 2, 3, 5]);
    }
}
world.barrier();

if (rank == 0) {
    //world.iSend((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtNonBlockingInt: invalid output offset" {
        boolean isCaught;
        try {
            data = [1, 2, 3];
            req = world.iRecv((MPIData)data+5, 3, 0); // bad offset
            req.wait();
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat: correct case" {
        data = new float[0];
        req = world.iRecv((MPIData)data, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}
world.barrier();

if (rank == 0) {
    //req = world.iRecv((MPIData)new float[0], 3, 0); // recieve 0 length
} else {
    assure "Pt2PtNonBlockingFloat: invalid input offset" {
        boolean isCaught;
        try {
            req = world.iSend((MPIData)[1.2, 3.4, 5.6]+5, 3, 1); // bad input
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6]+2, 3, 1); // over border
} else {
    assure "Pt2PtNonBlockingFloat: input beyond border" {
        data = [1.2, 2.3, 3.4];
        req = world.iRecv((MPIData)data+3, 3, 0); // recieve a part
        req.wait();
        print data;
        assert (|data| == 4);
        assert (data == [1.2, 2.3, 3.4, 5.6]);
    }
}
world.barrier();

if (rank == 0) {
    //world.iSend((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat: invalid output offset" {
        boolean isCaught;
        try {
            data = [1.2, 2.3, 3.4];
            req = world.iRecv((MPIData)data+5, 3, 0); // bad offset
            req.wait();
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
world.barrier();
