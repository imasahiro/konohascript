using konoha.mpi.*;

int main(void)
{
    c = new MPIContext();
    if (c.size > 1) {
        Bytes data;
        if (c.rank == 0) {
            data = (Bytes)"this is konoha";
        } else {
            data = new Bytes(0);
        }
        c.bcast(data, 16, 0);
        print "BCAST["+c.rank+"]: " + data.decode();
    }
    return 0;
}
