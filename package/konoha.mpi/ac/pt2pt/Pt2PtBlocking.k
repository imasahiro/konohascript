using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) disableLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha", 6, 6, 1);
} else {
    assure "Pt2PtBlockingBytes: correct case" {
        data = (Bytes)"hello,";
        world.recv((MPIData)data, 6, 6, 0);
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "hello,konoha");
    }
}

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha", 20, 6, 1); // bad input
} else {
    assure "Pt2PtBlockingBytes: invalid input offset" {
        data = (Bytes)"konoha";
        world.recv((MPIData)data, 6, 6, 0); // must be failed to append
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha", 6, 12, 1); // over border
} else {
    assure "Pt2PtBlockingBytes: input beyond border" {
        data = (Bytes)"konoha";
        world.recv((MPIData)data, 6, 12, 0); // must be appended as a part
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "konohakonoha");
    }
}

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha", 6, 6, 1);
} else {
    assure "Pt2PtBlockingBytes: invalid output offset" {
        data = (Bytes)"konoha";
        world.recv((MPIData)data, 18, 6, 0); // bad offset
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha", 16, 6, 1); // bad offset
} else {
    assure "Pt2PtBlockingBytes: int/out beyond borders" {
        data = (Bytes)"konoha";
        world.recv((MPIData)data, 18, 6, 0); // bad offset
        print data.decode();
        assert (|data| == 6);
        assert (data.decode() == "konoha");
    }
}

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 0, 3, 1);
} else {
    assure "Pt2PtBlockingInt: correct case" {
        data = new int[0];
        world.recv((MPIData)data, 0, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 5, 3, 1); // bad input
} else {
    assure "Pt2PtBlockingInt: invalid input offset" {
        data = [1, 2, 3];
        world.recv((MPIData)data, 3, 3, 0); // recieve 0 length
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 2, 3, 1); // over border
} else {
    assure "Pt2PtBlockingInt: input beyond border" {
        data = [1, 2, 3];
        world.recv((MPIData)data, 3, 3, 0); // recieve a part
        print data;
        assert (|data| == 4);
        assert (data == [1, 2, 3, 5]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 0, 3, 1);
} else {
    assure "Pt2PtBlockingInt: invalid output offset" {
        data = [1, 2, 3];
        world.recv((MPIData)data, 5, 3, 0); // bad offset
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 5, 3, 1); // bad offset
} else {
    assure "Pt2PtBlockingInt: in/out beyond border" {
        data = [1, 2, 3];
        world.recv((MPIData)data, 5, 3, 0); // bad offset
        print data;
        assert (|data| == 3);
        assert (data == [1, 2, 3]);
    }
}


/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 0, 3, 1);
} else {
    assure "Pt2PtBlockingFloat: correct case" {
        data = new float[0];
        world.recv((MPIData)data, 0, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 5, 3, 1); // bad input
} else {
    assure "Pt2PtBlockingFloat: invalid input offset" {
        data = [1.2, 2.3, 3.4];
        world.recv((MPIData)data, 3, 3, 0); // recieve 0 length
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 2, 3, 1); // over border
} else {
    assure "Pt2PtBlockingFloat: input beyond border" {
        data = [1.2, 2.3, 3.4];
        world.recv((MPIData)data, 3, 3, 0); // recieve a part
        print data;
        assert (|data| == 4);
        assert (data == [1.2, 2.3, 3.4, 5.6]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 0, 3, 1);
} else {
    assure "Pt2PtBlockingFloat: invalid output offset" {
        data = [1.2, 2.3, 3.4];
        world.recv((MPIData)data, 5, 3, 0); // bad offset
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 5, 3, 1); // bad offset
} else {
    assure "Pt2PtBlockingFloat: in/out beyond border" {
        data = [1.2, 2.3, 3.4];
        world.recv((MPIData)data, 5, 3, 0); // bad offset
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 2.3, 3.4]);
    }
}

