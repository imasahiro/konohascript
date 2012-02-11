using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 2) exit();
if (rank == 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)(Bytes)"thisiskonoha"+6, 6, 1);
} else {
    assure "Pt2PtBlockingBytes" {
        data = (Bytes)"hello,";
        world.recv((MPIData)data+6, 6, 0);
        print data.decode();
        assert (|data| == 12);
        assert (data.decode() == "hello,konoha");
    }
}

//* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1, 3, 5], 3, 1);
} else {
    assure "Pt2PtBlockingInt" {
        data = new int[0];
        world.recv((MPIData)data, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1, 3, 5]);
    }
}

/* ------------------------------------------------------------------------ */

if (rank == 0) {
    world.send((MPIData)[1.2, 3.4, 5.6], 3, 1);
} else {
    assure "Pt2PtBlockingFloat" {
        data = new float[0];
        world.recv((MPIData)data, 3, 0);
        print data;
        assert (|data| == 3);
        assert (data == [1.2, 3.4, 5.6]);
    }
}
