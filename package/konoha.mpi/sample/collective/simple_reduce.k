using konoha.mpi.*;

IArray = Array<Int>;
N = 8;

int main(void)
{
    c = new MPIContext();
    rdata = new IArray(N);
    sdata = new IArray(N);
    for (int i = 0; i < N; i++) {
        sdata <<< i;
    }
    c.reduceInt(sdata, rdata, N, MPIContext.OP_SUM, 0);
    if (c.rank == 0) {
        print rdata;
    }
    return 0;
}
