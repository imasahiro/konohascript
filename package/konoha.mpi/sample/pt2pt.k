using konoha.mpi.*;

world = MPIComm.WORLD;
r = world.rank;
s = world.size;

if (s != 2) exit(1);

{
    buf = new int[0];
    if (r == 0) {
        world.send((MPIData)[1,2,3], 3, 1);
        world.recv((MPIData)buf, 3, 1);
    }
    else {
        world.recv((MPIData)buf, 3, 0);
        buf.reverse();
        world.send((MPIData)buf, 3, 0);
    }
    OUT.println("@" + r + ": " + buf);
}

{
    buf = new float[0];
    if (r == 0) {
        world.send((MPIData)[1.2,3.4,4.5], 3, 1);
        world.recv((MPIData)buf, 3, 1);
    }
    else {
        world.recv((MPIData)buf, 3, 0);
        buf.reverse();
        world.send((MPIData)buf, 3, 0);
    }
    OUT.println("@" + r + ": " + buf);
}

{
    buf = new byte[0];
    if (r == 0) {
        world.send((MPIData)(Bytes)"konoha", 6, 1);
        world.recv((MPIData)buf, 6, 1);
    }
    else {
        world.recv((MPIData)buf, 6, 0);
        world.send((MPIData)buf, 6, 0);
    }
    OUT.println("@" + r + ": " + buf.decode());
}

{
    buf = new int[0];
    rq = world.iRecv((MPIData)buf, 3, 1-r);
    if (r == 0) {
        world.send((MPIData)[1,2,3], 3, 1);
        rq.wait();
    }
    else {
        rq.wait();
        buf.reverse();
        world.send((MPIData)buf, 3, 0);
    }
    OUT.println("#" + r + ": " + buf);
}

{
    buf = new float[0];
    rq = world.iRecv((MPIData)buf, 3, 1-r);
    if (r == 0) {
        world.send((MPIData)[1.2,2.4,3.6], 3, 1);
        rq.wait();
    }
    else {
        rq.wait();
        buf.reverse();
        world.send((MPIData)buf, 3, 0);
    }
    OUT.println("#" + r + ": " + buf);
}

{
    buf = new byte[0];
    rq = world.iRecv((MPIData)buf, 6, 1-r);
    if (r == 0) {
        world.send((MPIData)(Bytes)"konoha", 6, 1);
        rq.wait();
    }
    else {
        rq.wait();
        world.send((MPIData)buf, 6, 0);
    }
    OUT.println("#" + r + ": " + buf.decode());
}
