using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) MPI.preventLog();

/* ------------------------------------------------------------------------ */

void bytes_sum(MPIData din, MPIData din_out)
{
    if (din.getDataClass() != byte[] ||
        din_out.getDataClass() != byte[]) {
        return;
    }
    for (int i = 0; i < |din|; i++) {
        int c = (din[i] - '0') + (din_out[i] - '0');
        din_out[i] = '0' + (c % 10);
    }
}

op_bsum = new MPIOp(bytes_sum);
bdata = new byte[0];
if (rank == 0) {
    assure "CollectiveReduceNativeFunctionBytes" {
        world.reduce((MPIData)(Bytes)"123", (MPIData)bdata, 3, op_bsum, 0);
        print bdata.decode();
        assert (bdata.decode() == "666");
    }
} else if (rank == 1) {
    world.reduce((MPIData)(Bytes)"222", (MPIData)bdata, 3, op_bsum, 0);
} else {
    world.reduce((MPIData)(Bytes)"321", (MPIData)bdata, 3, op_bsum, 0);
}

/* ------------------------------------------------------------------------ */

int gcd(int x, int y)
{
    int m = x % y;
    return (m == 0) ? y : gcd(y, m);
}

void int_gcd(MPIData din, MPIData din_out)
{
    if (din.getDataClass() != int[] ||
        din_out.getDataClass() != int[]) {
        return;
    }
    for (int i = 0; i < |din|; i++) {
        int x = din[i], y = din_out[i];
        din_out[i] = (x > y) ? gcd(x, y) : gcd(y, x);
    }
}

op_igcd = new MPIOp(int_gcd);
idata = new int[0];
if (rank == 0) {
    assure "CollectiveReduceNativeFunctionInt" {
        world.reduce((MPIData)[1024, 896], (MPIData)idata, 2, op_igcd, 0);
        print idata;
        assert (idata == [128, 128]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)[384, 384], (MPIData)idata, 2, op_igcd, 0);
} else {
    world.reduce((MPIData)[896, 1024], (MPIData)idata, 2, op_igcd, 0);
}

/* ------------------------------------------------------------------------ */

void  float_mul(MPIData din, MPIData din_out)
{
    if (din.getDataClass() != float[] ||
        din_out.getDataClass() != float[]) {
        return;
    }
    for (int i = 0; i < |din|; i++) {
        din_out[i] = din[i] * din_out[i];
    }
}

op_fmul = new MPIOp(float_mul);
fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceNativeFunctionFloat" {
        world.reduce((MPIData)[1.0, 1.0], (MPIData)fdata, 2, op_fmul, 0);
        print fdata;
        assert (fdata == [1.0 * 2.0 * 2.0, 1.0 * 0.5 * 0.5]);
    }
} else {
    world.reduce((MPIData)[2.0, 0.5], (MPIData)fdata, 2, op_fmul, 0);
}
