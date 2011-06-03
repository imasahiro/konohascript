using konoha.mpi.*;

int main(void)
{
    c = new MPIContext();
    if (c.size == 2) {
        if (c.rank == 0) {
            data = new Bytes(0);
            print "RECV: sleep 1 sec.";
            exec "sleep 1";
            req = c.iRecv(data, 16, 1);
            print "RECV: iRecv called"
            exec "sleep 1";
            req.wait();
            print "RECV: " + data.decode();
        } else {
            data = (Bytes)"this is konoha.";
            c.iSend(data, 0);
            print "SEND: " + data.decode();
        }
    }
    return 0;
}
