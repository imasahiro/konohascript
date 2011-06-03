using konoha.mpi.*;

IArray = Array<Int>;
FArray = Array<Float>;

void do_reduce(MPIContext c, int r, int s)
{
    count = 8;
    rdata = new Bytes(count);
    sdata = new Bytes(count);
    for (int i = 0; i < count; i++) {
        sdata.putc(i);
    }
    c.reduce(sdata, rdata, count, MPIContext.OP_SUM, 0);
    if (r == 0) {
        print "%dump"(rdata);
    }
}

void do_reduceInt(MPIContext c, int r, int s)
{
    count = 8;
    rdata = new IArray(count);
    sdata = new IArray(count);
    for (int i = 0; i < count; i++) {
        sdata <<< i;
    }
    c.reduceInt(sdata, rdata, count, MPIContext.OP_SUM, 0);
    if (r == 0) {
        print rdata;
    }
}

void do_reduceFloat(MPIContext c, int r, int s)
{
    count = 8;
    rdata = new FArray(0);
    sdata = new FArray(count);
    for (int i = 0; i < count; i++) {
        sdata <<< (float)i;
    }
    c.reduceFloat(sdata, rdata, count, MPIContext.OP_SUM, 0);
    if (r == 0) {
        print rdata;
    }
}

int main(void)
{
    c = new MPIContext();
    r = c.rank;
    s = c.getSize();

    do_reduce(c, r, s);
    do_reduceInt(c, r, s);
    do_reduceFloat(c, r, s);
    return 0;
}
