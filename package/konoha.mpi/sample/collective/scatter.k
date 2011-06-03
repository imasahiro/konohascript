using konoha.mpi.*;

int main(void)
{
    c = new MPIContext();
    Bytes sdata;
    data = new Bytes(15);
    if (c.rank == 0) {
        sdata = (Bytes)"this is konoha";
    }
    c.scatter(sdata, 4, data, 0);
    print data.decode();
    return 0;
}

