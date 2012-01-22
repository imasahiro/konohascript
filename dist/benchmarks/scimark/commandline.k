//package jnt.scimark2;
//
//import java.util.Properties;
include "kernel.k";
include "scimarkutil/Constants.k";
/**
SciMark2: A Java numerical benchmark measuring performance
of computational kernels for FFTs, Monte Carlo simulation,
sparse matrix computations, Jacobi SOR, and dense LU matrix
factorizations.  


*/


/* Benchmark 5 kernels with individual Mflops.
   "results[0]" has the average Mflop rate.

*/


public static void main(String[] args)
{
    // default to the (small) cache-contained version

    double min_time = RESOLUTION_DEFAULT;

    int fft_size = FFT_SIZE;
    int sor_size =  SOR_SIZE;
    int sparse_size_M = SPARSE_SIZE_M;
    int sparse_size_nz = SPARSE_SIZE_NZ;
    int lu_size = LU_SIZE;

    // look for runtime options

    if (args.size > 0) {
        if (args[0] == "-h" || args[0] == "-help") {
            System.out.println("Usage: [-large] [minimum_time]");
            return;
        }

        int current_arg = 0;
        if (args[current_arg] == "-large") {
            fft_size = LG_FFT_SIZE;
            sor_size =  LG_SOR_SIZE;
            sparse_size_M = LG_SPARSE_SIZE_M;
            sparse_size_NZ = LG_SPARSE_SIZE_NZ;
            lu_size = LG_LU_SIZE;

            current_arg++;
        }

        if (args.size > current_arg) {
            min_time = (double) (args[current_arg]);
        }
    }

    // run the benchmark

    double[] res = new double[6];
    Random r = new Random(RANDOM_SEED);

    res[1] = Kernel.measureFFT( fft_size, min_time, r);
    res[2] = Kernel.measureSOR( sor_size, min_time, r);
    res[3] = Kernel.measureMonteCarlo(min_time, r);
    res[4] = Kernel.measureSparseMatmult( sparse_size_M, sparse_size_NZ, min_time, r);
    res[5] = Kernel.measureLU( lu_size, min_time, r);


    res[0] = (res[1] + res[2] + res[3] + res[4] + res[5]) / 5;


    // print out results

    System.out.println();
    System.out.println("SciMark 2.0a");
    System.out.println();
    System.out.println("Composite Score: " + res[0]);
    System.out.print("FFT ("+fft_size+"): ");
    if (res[1]==0.0)
        System.out.println(" ERROR, INVALID NUMERICAL RESULT!");
    else
        System.out.println(res[1]);

    System.out.println("SOR ("+sor_size+"x"+ sor_size+"): "
            + "  " + res[2]);
    System.out.println("Monte Carlo : " + res[3]);
    System.out.println("Sparse matmult (N="+ sparse_size_M+ 
            ", nz=" + sparse_size_NZ + "): " + res[4]);
    System.out.print("LU (" + lu_size + "x" + lu_size + "): ");
    if (res[5]==0.0)
        System.out.println(" ERROR, INVALID NUMERICAL RESULT!");
    else
        System.out.println(res[5]);

    //// print out System info
    //System.out.println();
    //System.out.println("java.vendor: " + System.getProperty("java.vendor"));
    //System.out.println("java.version: " + System.getProperty("java.version"));
    //System.out.println("os.arch: " + System.getProperty("os.arch"));
    //System.out.println("os.name: " + System.getProperty("os.name"));
    //System.out.println("os.version: " + System.getProperty("os.version"));
}
