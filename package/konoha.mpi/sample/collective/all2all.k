using konoha.mpi.*;

int main(void)
{
    data = ["123", "abc", "ABC"];
    c = new MPIContext();
    if (c.size == |data|) {
        r = c.rank;
        rdata = new Bytes(0);
        c.allToAll((Bytes)data[r], 2, rdata);
        print rdata.decode();
    }
    return 0;
}

