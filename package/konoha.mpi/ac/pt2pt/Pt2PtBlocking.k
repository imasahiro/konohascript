using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha"+6, 6, 1);
} else {
    assure "Pt2PtBlockingBytes: correct case" {
        data = (Bytes)"hello,";
        world.recv((MPIData)data+6, 6, 0);
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "hello,konoha");
    }
}

if (rank == 0) {
    //world.recv((MPIData)new byte[0], 6, 0);
} else {
    assure "Pt2PtBlockingBytes: invalid input offset" {
        boolean isCaught;
        try {
            world.send((MPIData)(Bytes)"thisiskonoha"+20, 6, 1); // bad offset
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha"+6, 12, 1); // over border
} else {
    assure "Pt2PtBlockingBytes: input beyond border" {
        data = (Bytes)"konoha";
        world.recv((MPIData)data+6, 12, 0); // should be recieved as a part
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "konohakonoha");
    }
}

if (rank == 0) {
    //world.send((MPIData)(Bytes)"thisiskonoha"+6, 6, 1);
} else {
    assure "Pt2PtBlockingBytes: invalid output offset" {
        boolean isCaught;
        try {
            data = (Bytes)"konoha";
            world.recv((MPIData)data+18, 6, 0); // bad offset
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}

//* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtBlockingInt: correct case" {
        data = new int[0];
        world.recv((MPIData)data, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}

if (rank == 0) {
    //world.recv((MPIData)new int[0], 3, 0); // recieve 0 length
} else {
    assure "Pt2PtBlockingInt: invalid input offset" {
        boolean isCaught;
        try {
            world.send((MPIData)[1, 3, 5]+5, 3, 1); // bad input
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}

if (rank == 0) {
    world.send((MPIData)[1, 3, 5]+2, 3, 1); // over border
} else {
    assure "Pt2PtBlockingInt: input beyond border" {
        data = [1, 2, 3];
        world.recv((MPIData)data+3, 3, 0); // should be recieved as a part
        print data;
        assert (|data| == 4);
        assert (data == [1, 2, 3, 5]);
    }
}

if (rank == 0) {
    //world.send((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtBlockingInt: invalid output offset" {
        boolean isCaught;
        try {
            data = [1, 2, 3];
            world.recv((MPIData)data+5, 3, 0); // bad offset
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtBlockingFloat: correct case" {
        data = new float[0];
        world.recv((MPIData)data, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}

if (rank == 0) {
    //world.recv((MPIData)new float[0], 3, 0); // recieve 0 length
} else {
    assure "Pt2PtBlockingFloat: invalid input offset" {
        boolean isCaught;
        try {
            world.send((MPIData)[1.2, 3.4, 5.6]+5, 3, 1); // bad input
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6]+2, 3, 1); // over border
} else {
    assure "Pt2PtBlockingFloat: input beyond border" {
        data = [1.2, 2.3, 3.4];
        world.recv((MPIData)data+3, 3, 0); // should be recieved as a part
        print data;
        assert (|data| == 4);
        assert (data == [1.2, 2.3, 3.4, 5.6]);
    }
}

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtBlockingFloat: invalid output offset" {
        boolean isCaught;
        try {
            data = [1.2, 2.3, 3.4];
            world.recv((MPIData)data+5, 3, 0); // bad offset
        } catch (Script!! e) {
            isCaught = true;
        }
        assert isCaught;
    }
}
