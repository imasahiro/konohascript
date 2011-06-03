using konoha.mpi.*;

void do_bytes(MPIContext c)
{
    r = c.rank;
    if (c.rank == 0) {
        /* sender */
        data = (Bytes)"Peter Piper picked a peck of pickled peppers.";
        c.send(data, 1);
        print "SEND: " + data.decode();
    } else {
        /* reciever */
        data = new Bytes(0);
        c.recv(data, 0);
        print "RECV: " + data.decode();
    }
}

void do_int(MPIContext c)
{
    if (c.rank == 0) {
        /* reciever */
        a = [0];
        print a;
        c.recvInt(a, 1);
        print a;
        c.recvInt(a, 1);
        print a;
        c.recvInt(a, 1);
        print a;
    } else {
        /* sender */
        c.sendInt([1], 0);
        c.sendInt([2], 0);
        c.sendInt([3], 0);
    }
}

void do_float(MPIContext c)
{
    if (c.rank == 0) {
        /* reciever */
        a = [0.0];
        print a;
        c.recvFloat(a, 1);
        print a;
        c.recvFloat(a, 1);
        print a;
        c.recvFloat(a, 1);
        print a;
    } else {
        /* sender */
        c.sendFloat([1.2], 0);
        c.sendFloat([2.4], 0);
        c.sendFloat([3.6], 0);
    }
}

int main(void)
{
    c = new MPIContext();
    if (c.size == 2) {
        do_bytes(c);
        do_int(c);
        do_float(c);
    }
    return 0;
}

