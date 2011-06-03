using konoha.mpi.*;

IArray = Array<Int>;
FArray = Array<Float>;

void do_ibytes(MPIContext c)
{
    if (c.rank == 0) {
        data = new Bytes(0);
        print "RECV: sleep 1 sec.";
        exec "sleep 1";
        req = c.iRecv(data, 16, 1);
        req.wait();
        print data.decode();
    } else {
        data = (Bytes)"this is konoha.";
        c.iSend(data, 0);
    }
}

void do_iint(MPIContext c)
{
    if (c.rank == 0) {
        data = new IArray(0);
        print "RECV: sleep 1 sec.";
        exec "sleep 1";
        req = c.iRecvInt(data, 3, 1);
        req.wait();
        print data;
    } else {
        data = [1, 3, 5];
        c.iSendInt(data, 0);
    }
}

void do_ifloat(MPIContext c)
{
    if (c.rank == 0) {
        data = new FArray(0);
        print "RECV: sleep 1 sec.";
        exec "sleep 1";
        req = c.iRecvFloat(data, 3, 1);
        req.wait();
        print data;
    } else {
        data = [0.1, 2.4, 8.16];
        c.iSendFloat(data, 0);
    }
}

int main(void)
{
    c = new MPIContext();
    if (c.size == 2) {
        do_ibytes(c);
        do_iint(c);
        do_ifloat(c);
    }
    return 0;
}
