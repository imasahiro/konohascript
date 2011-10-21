using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;

if (world.size != 3) exit();
if (rank != 0) disableLog();

void bytes_sum(MPIData din, MPIData din_out)
{
    if (din.getContentClass() != byte[] ||
        din_out.getContentClass() != byte[]) {
        return;
    }
    byte[] bin = (byte[])din;
    byte[] bin_out = (byte[])din_out;
    for (int i = 0; i < |bin|; i++) {
        int c = (bin[i] - '0') + (bin_out[i] - '0');
        bin_out[i] = '0' + (c % 10);
    }
}

int gcd(int x, int y)
{
    int m = x % y;
    return (m == 0) ? y : gcd(y, m);
}

void int_gcd(MPIData din, MPIData din_out)
{
    if (din.getContentClass() != int[] ||
        din_out.getContentClass() != int[]) {
        return;
    }
    int[] iin = (int[])din;
    int[] iin_out = (int[])din_out;
    for (int i = 0; i < |iin|; i++) {
        int x = iin[i], y = iin_out[i];
        iin_out[i] = (x > y) ? gcd(x, y) : gcd(y, x);
    }
}

void  float_div(MPIData din, MPIData din_out)
{
    if (din.getContentClass() != float[] ||
        din_out.getContentClass() != float[]) {
        return;
    }
    float[] fin = (float[])din;
    float[] fin_out = (float[])din_out;
    for (int i = 0; i < |fin|; i++) {
        fin_out[i] = 1 / (fin[i] + fin_out[i]);
    }
}

MPIOp op_bsum = new MPIOp(bytes_sum);
MPIOp op_igcd = new MPIOp(int_gcd);
MPIOp op_fdiv = new MPIOp(float_div);

bdata = new byte[0];
idata = new int[0];
fdata = new float[0];
if (rank == 0) {
    assure "CollectiveReduceNativeFunction" {
        world.reduce((MPIData)(Bytes)"123", (MPIData)bdata, 3, op_bsum, 0);
        world.reduce((MPIData)[1024, 896], (MPIData)idata, 2, op_igcd, 0);
        world.reduce((MPIData)[0.1, 0.01], (MPIData)fdata, 2, op_fdiv, 0);
        assert (bdata.decode() == "666");
        assert (idata == [128, 128]);
        assert (fdata == [1/(1/(0.1 + 0.01) + 0.1), 1/(1/(0.01 + 0.1) + 0.001)]);
    }
} else if (rank == 1) {
    world.reduce((MPIData)(Bytes)"222", (MPIData)bdata, 3, op_bsum, 0);
    world.reduce((MPIData)[384, 384], (MPIData)idata, 2, op_igcd, 0);
    world.reduce((MPIData)[0.01, 0.1], (MPIData)fdata, 2, op_fdiv, 0);
} else {
    world.reduce((MPIData)(Bytes)"321", (MPIData)bdata, 3, op_bsum, 0);
    world.reduce((MPIData)[896, 1024], (MPIData)idata, 2, op_igcd, 0);
    world.reduce((MPIData)[0.1, 0.001], (MPIData)fdata, 2, op_fdiv, 0);
}
