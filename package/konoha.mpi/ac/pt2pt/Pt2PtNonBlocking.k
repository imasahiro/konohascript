using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) disableLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"konoha", 0, 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes: correct case" {
        data = new byte[0];
        req = world.iRecv((MPIData)data, 0, 6, 0);
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"thisiskonoha", 20, 6, 1); // bad input
} else {
    assure "Pt2PtNonBlockingBytes: invalid input offset" {
        data = (Bytes)"konoha";
        req = world.iRecv((MPIData)data, 6, 6, 0); // must be failed to append
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"thisiskonoha", 6, 12, 1); // over border
} else {
    assure "Pt2PtNonBlockingBytes: input beyond border" {
        data = (Bytes)"konoha";
        req = world.iRecv((MPIData)data, 6, 12, 0); // must be appended as a part
        req.wait();
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "konohakonoha");
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"thisiskonoha", 6, 6, 1);
} else {
    assure "Pt2PtNonBlockingBytes: invalid output offset" {
        data = (Bytes)"konoha";
        req = world.iRecv((MPIData)data, 18, 6, 0); // bad offset
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)(Bytes)"thisiskonoha", 16, 6, 1); // bad offset
} else {
    assure "Pt2PtNonBlockingBytes: int/out beyond borders" {
        data = (Bytes)"konoha";
        req = world.iRecv((MPIData)data, 18, 6, 0); // bad offset
        req.wait();
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 0, 3, 1);
} else {
    assure "Pt2PtNonBlockingInt: correct case" {
        data = new int[0];
        req = world.iRecv((MPIData)data, 0, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 5, 3, 1); // bad input
} else {
    assure "Pt2PtNonBlockingInt: invalid input offset" {
        data = [1, 2, 3];
        req = world.iRecv((MPIData)data, 3, 3, 0); // recieve 0 length
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 2, 3, 1); // over border
} else {
    assure "Pt2PtNonBlockingInt: input beyond border" {
        data = [1, 2, 3];
        req = world.iRecv((MPIData)data, 3, 3, 0); // recieve a part
        req.wait();
        print data;
        assert (|data| == 4);
        assert (data == [1, 2, 3, 5]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 0, 3, 1);
} else {
    assure "Pt2PtNonBlockingInt: invalid output offset" {
        data = [1, 2, 3];
        req = world.iRecv((MPIData)data, 5, 3, 0); // bad offset
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1, 3, 5], 5, 3, 1); // bad offset
} else {
    assure "Pt2PtNonBlockingInt: in/out beyond border" {
        data = [1, 2, 3];
        req = world.iRecv((MPIData)data, 5, 3, 0); // bad offset
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}
world.barrier();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 0, 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat: correct case" {
        data = new float[0];
        req = world.iRecv((MPIData)data, 0, 3, 0);
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 5, 3, 1); // bad input
} else {
    assure "Pt2PtNonBlockingFloat: invalid input offset" {
        data = [1.2, 2.3, 3.4];
        req = world.iRecv((MPIData)data, 3, 3, 0); // recieve 0 length
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 2, 3, 1); // over border
} else {
    assure "Pt2PtNonBlockingFloat: input beyond border" {
        data = [1.2, 2.3, 3.4];
        req = world.iRecv((MPIData)data, 3, 3, 0); // recieve a part
        req.wait();
        print data;
        assert (|data| == 4);
        assert (data == [1.2, 2.3, 3.4, 5.6]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 0, 3, 1);
} else {
    assure "Pt2PtNonBlockingFloat: invalid output offset" {
        data = [1.2, 2.3, 3.4];
        req = world.iRecv((MPIData)data, 5, 3, 0); // bad offset
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}
world.barrier();

if (rank == 0) {
    world.iSend((MPIData)[1.2, 3.4, 5.6], 5, 3, 1); // bad offset
} else {
    assure "Pt2PtNonBlockingFloat: in/out beyond border" {
        data = [1.2, 2.3, 3.4];
        req = world.iRecv((MPIData)data, 5, 3, 0); // bad offset
        req.wait();
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}
world.barrier();
