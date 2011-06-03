using konoha.mpi.*;

void do_bcast(MPIContext c)
{
    data = (c.rank == 0) ? (Bytes)"this is konoha" : new Bytes(0);
    c.bcast(data, 4, 0);
    print data.decode();
}

void do_bcastEx(MPIContext c)
{
    data = (c.rank == 0) ? (Bytes)"this is konoha" : new Bytes(0);
    c.bcastEx(data, 0);
    print data.decode();
}

int main(void)
{
    c = new MPIContext();
    do_bcast(c);
    do_bcastEx(c);
    return 0;
}
