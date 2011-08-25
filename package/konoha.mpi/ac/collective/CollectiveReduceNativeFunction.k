using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.rank;
IArray = Array<Int>;
FArray = Array<Float>;

if (world.size != 3) exit();
if (rank != 0) disableLog();

void bytes_sum(dynamic din, dynamic din_out)
{
    if (din.class == Bytes && din_out.class == Bytes) {
        Bytes bin = (Bytes)din;
        Bytes bin_out = (Bytes)din_out;
        for (int i = 0; i < |bin|; i++) {
            int c = (bin[i] - '0') + (bin_out[i] - '0');
            bin_out[i] = '0' + (c % 10);
        }
    }
}

int gcd(int x, int y)
{
    int m = x % y;
    return (m == 0) ? y : gcd(y, m);
}

void int_gcd(dynamic din, dynamic din_out)
{
    if (din.class == IArray && din_out.class == IArray) {
        IArray iin = (IArray)din;
        IArray iin_out = (IArray)din_out;
        for (int i = 0; i < |iin|; i++) {
            int x = iin[i], y = iin_out[i];
            iin_out[i] = (x > y) ? gcd(x, y) : gcd(y, x);
        }
    }
}

void  float_div(dynamic din, dynamic din_out)
{
    if (din.class == FArray && din_out.class == FArray) {
        FArray fin = (FArray)din;
        FArray fin_out = (FArray)din_out;
        for (int i = 0; i < |fin|; i++) {
            fin_out[i] = 1 / (fin[i] + fin_out[i]);
        }
    }
}

MPIOp op_bsum = new MPIOp(bytes_sum);
MPIOp op_igcd = new MPIOp(int_gcd);
MPIOp op_fdiv = new MPIOp(float_div);

Bytes bdata = new Bytes();
IArray idata = new IArray();
FArray fdata = new FArray();
if (rank == 0) {
    assure "CollectiveReduceNativeFunction" {
        world.reduce((Bytes)"123", bdata, op_bsum, 0);
        world.reduce([1024, 896], idata, op_igcd, 0);
        world.reduce([0.1, 0.01], fdata, op_fdiv, 0);
        assert (bdata.decode() == "666");
        assert (idata == [128, 128]);
        assert (fdata == [1/(1/(0.1 + 0.01) + 0.1), 1/(1/(0.01 + 0.1) + 0.001)]);
    }
} else if (rank == 1) {
    world.reduce((Bytes)"222", bdata, op_bsum, 0);
    world.reduce([384, 384], idata, op_igcd, 0);
    world.reduce([0.01, 0.1], fdata, op_fdiv, 0);
} else {
    world.reduce((Bytes)"321", bdata, op_bsum, 0);
    world.reduce([896, 1024], idata, op_igcd, 0);
    world.reduce([0.1, 0.001], fdata, op_fdiv, 0);
}
