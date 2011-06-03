using konoha.mpi.*;


void do_gather(MPIContext c, Array<String> data)
{
    r = c.rank;
    rdata = new Bytes(0);
    c.gather((Bytes)data[r], 3, rdata, 0);
    if (r == 0) {
        print rdata.decode();
    }
}

void do_gatherEx(MPIContext c, Array<String> data)
{
    r = c.rank;
    rdata = new Bytes(0);
    c.gatherEx((Bytes)data[r], rdata, 0);
    if (r == 0) {
        print rdata.decode();
    }
}

void do_allgather(MPIContext c, Array<String> data)
{
    rdata = new Bytes(0);
    c.allgather((Bytes)data[c.rank], 4, rdata);
    print rdata.decode();
}

void do_allgatherEx(MPIContext c, Array<String> data)
{
    rdata = new Bytes(0);
    c.allgatherEx((Bytes)data[c.rank], rdata);
    print rdata.decode();
}

int main(void)
{
    strs = ["aaa", "bbbb", "ccccc"];
    c = new MPIContext();
    if (c.size <= |strs|) {
        do_gather(c, strs);
        do_gatherEx(c, strs);
        do_allgather(c, strs);
        do_allgatherEx(c, strs);
    }
    return 0;
}
