/*
 * scimark2 SparseCompRow bench
 */
using konoha.math.*;

RESOLUTION_DEFAULT = 2.0;  /*secs*/
RANDOM_SEED = 101010;

// default: small (cache-contained) problem sizes
//
FFT_SIZE = 1024;  // must be a power of two
SOR_SIZE =100; // NxN grid
SPARSE_SIZE_M = 1000;
SPARSE_SIZE_NZ = 5000;
LU_SIZE = 100;

// large (out-of-cache) problem sizes
//
LG_FFT_SIZE = 1048576;  // must be a power of two
LG_SOR_SIZE =1000; // NxN grid
LG_SPARSE_SIZE_M = 100000;
LG_SPARSE_SIZE_NZ =1000000;
LG_LU_SIZE = 1000;

// tiny problem sizes (used to mainly to preload network classes 
//                     for applet, so that network download times
//                     are factored out of benchmark.)
//
TINY_FFT_SIZE = 16;  // must be a power of two
TINY_SOR_SIZE =10; // NxN grid
TINY_SPARSE_SIZE_M = 10;
TINY_SPARSE_SIZE_N = 10;
TINY_SPARSE_SIZE_NZ = 50;
TINY_LU_SIZE = 10;
//package jnt.scimark2;

/* Random.java based on Java Numerical Toolkit (JNT) Random.UniformSequence
   class.  We do not use Java's own java.util.Random so that we can compare
   results with equivalent C and Fortran coces.
   */

MDIG = 32;
ONE = 1;
M1 = (ONE << (MDIG-2)) + ((ONE << (MDIG-2))-ONE);
M2 = ONE << (MDIG/2);

/* For mdig = 32 : M1 =          2147483647, M2 =      65536
   For mdig = 64 : M1 = 9223372036854775807, M2 = 4294967296 
 */


public class Random {


    /* ------------------------------------------------------------------------------
       CLASS VARIABLES
       ------------------------------------------------------------------------------ */

    int seed = 0;

    int[] m;
    int   i = 4;
    int   j = 16;

    double dM1 = 1.0 / (double) M1;

    boolean haveRange = false;
    double left  = 0.0;
    double right = 1.0;
    double width = 1.0;

    /* ------------------------------------------------------------------------------
       CONSTRUCTORS
       ------------------------------------------------------------------------------ */

    /**
      Initializes a sequence of uniformly distributed quasi random numbers with a
      seed based on the system clock.
      */
    @Overload public Random () {
        initialize( (int) System.getTime());
    }

    /**
      Initializes a sequence of uniformly distributed quasi random numbers on a
      given half-open interval [left,right) with a seed based on the system
      clock.

      @param <B>left</B> (double)<BR>

      The left endpoint of the half-open interval [left,right).

      @param <B>right</B> (double)<BR>

      The right endpoint of the half-open interval [left,right).
      */
    @Overload public Random ( double left, double right) {
        initialize( (int) System.getTime() );
        this.left = left;
        this.right = right;
        width = right - left;
        haveRange = true;
    }

    /**
      Initializes a sequence of uniformly distributed quasi random numbers with a
      given seed.

      @param <B>seed</B> (int)<BR>

      The seed of the random number generator.  Two sequences with the same
      seed will be identical.
      */
    @Overload public Random (int seed) {
        initialize( seed);
    }

    /**
      Initializes a sequence of uniformly distributed quasi random numbers
      with a given seed on a given half-open interval [left,right).

      @param <B>seed</B> (int)<BR>

      The seed of the random number generator.  Two sequences with the same
      seed will be identical.

      @param <B>left</B> (double)<BR>

      The left endpoint of the half-open interval [left,right).

      @param <B>right</B> (double)<BR>

      The right endpoint of the half-open interval [left,right).
      */
    @Overload public Random (int seed, double left, double right) {
        initialize( seed);
        this.left = left;
        this.right = right;
        width = right - left;
        haveRange = true;
    }

    /* ------------------------------------------------------------------------------
       PUBLIC METHODS
       ------------------------------------------------------------------------------ */

    /**
      Returns the next random number in the sequence.
      */
    public final double nextDouble () {

        int k;
        double nextValue;

        k = m[i] - m[j];
        if (k < 0) k += M1;
        m[j] = k;

        if (i == 0) 
            i = 16;
        else i--;

        if (j == 0) 
            j = 16 ;
        else j--;

        if (haveRange) 
            return  left +  dM1 * (double) k * width;
        else
            return dM1 * (double) k;

    } 

    /**
      Returns the next N random numbers in the sequence, as
      a vector.
      */
    public final void nextDoubles (double[] x)
    {

        int n = x.size;
        int remainder = n & 3;		// N mod 4

        if (haveRange)
        {
            for (int count=0; count<n; count++)
            {
                int k = m[i] - m[j];

                if (i == 0) i = 16;
                else i--;

                if (k < 0) k += M1;
                m[j] = k;

                if (j == 0) j = 16;
                else j--;

                x[count] = left + dM1 * (double) k * width;
            }

        }
        else
        {

            for (int count=0; count<remainder; count++)
            {
                int k = m[i] - m[j];

                if (i == 0) i = 16;
                else i--;

                if (k < 0) k += M1;
                m[j] = k;

                if (j == 0) j = 16;
                else j--;


                x[count] = dM1 * (double) k;
            }

            for (int count=remainder; count<n; count+=4)
            {
                int k = m[i] - m[j];
                if (i == 0) i = 16;
                else i--;
                if (k < 0) k += M1;
                m[j] = k;
                if (j == 0) j = 16;
                else j--;
                x[count] = dM1 * (double) k;


                k = m[i] - m[j];
                if (i == 0) i = 16;
                else i--;
                if (k < 0) k += M1;
                m[j] = k;
                if (j == 0) j = 16;
                else j--;
                x[count+1] = dM1 * (double) k;


                k = m[i] - m[j];
                if (i == 0) i = 16;
                else i--;
                if (k < 0) k += M1;
                m[j] = k;
                if (j == 0) j = 16;
                else j--;
                x[count+2] = dM1 * (double) k;


                k = m[i] - m[j];
                if (i == 0) i = 16;
                else i--;
                if (k < 0) k += M1;
                m[j] = k;
                if (j == 0) j = 16;
                else j--;
                x[count+3] = dM1 * (double) k;
            }
        }
    }

    static public int min(int n, int m) {
        if (n < m) {
            return n;
        }
        return m;
    }
    static public int abs(int n) {
        if (n > 0) {
            return n;
        } else {
            return -n;
        }
    }


    /*----------------------------------------------------------------------------
      PRIVATE METHODS
      ------------------------------------------------------------------------ */

    void initialize (int seed) {

        int jseed, k0, k1, j0, j1, iloop;

        this.seed = seed;

        m = new int[17];

        jseed = min(abs(seed),M1);
        if (jseed % 2 == 0) --jseed;
        k0 = 9069 % M2;
        k1 = 9069 / M2;
        j0 = jseed % M2;
        j1 = jseed / M2;
        for (iloop = 0; iloop < 17; ++iloop) 
        {
            jseed = j0 * k0;
            j1 = (jseed / M2 + j0 * k1 + j1 * k0) % (M2 / 2);
            j0 = jseed % M2;
            m[iloop] = j0 + M2 * j1;
        }
        i = 4;
        j = 16;

    }
}

//package jnt.scimark2;

public class SparseCompRow
{
    /* multiple iterations used to make kernel have roughly
       same granulairty as other Scimark kernels. */

    public static double num_flops(int n, int nz, int num_iterations)
    {
        /* Note that if nz does not divide N evenly, then the
           actual number of nonzeros used is adjusted slightly.
           */
        int actual_nz = (nz/n) * n;
        return ((double)actual_nz) * 2.0 * ((double) num_iterations);
    }


    /* computes  a matrix-vector multiply with a sparse matrix
       held in compress-row format.  If the size of the matrix
       in MxN with nz nonzeros, then the val[] is the nz nonzeros,
       with its ith entry in column col[i].  The integer vector row[]
       is of size M+1 and row[i] points to the begining of the
       ith row in col[].  
       */

    public static void matmult( double[] y, double[] val, int[] row,
            int[] col, double[] x, int num_iterations)
    {
        int m = row.size - 1;

        for (int reps=0; reps<num_iterations; reps++)
        {

            for (int r=0; r<m; r++)
            {
                double sum = 0.0; 
                int rowR = row[r];
                int rowRp1 = row[r+1];
                for (int i=rowR; i<rowRp1; i++)
                    sum += x[ col[i] ] * val[i];
                y[r] = sum;
            }
        }
    }

}

static double[] randomVector(int n, Random r)
{
    double[] a = new double[n];

    for (int i=0; i<n; i++) {
        a[i] = r.nextDouble();
    }
    return a;
}

void run() {
    Random r = new Random(RANDOM_SEED);
    int n = SPARSE_SIZE_M;
    int nz = SPARSE_SIZE_NZ;
    // initialize vector multipliers and storage for result
    // y = A*y;

    double[] x = randomVector(n, r);
    double[] y = new double[n];

    // initialize square sparse matrix
    //
    // for this test, we create a sparse matrix wit M/nz nonzeros
    // per row, with spaced-out evenly between the begining of the
    // row to the main diagonal.  Thus, the resulting pattern looks
    // like
    //             +-----------------+
    //             +*                +
    //             +***              +
    //             +* * *            +
    //             +** *  *          +
    //             +**  *   *        +
    //             +* *   *   *      +
    //             +*  *   *    *    +
    //             +*   *    *    *  + 
    //             +-----------------+
    //
    // (as best reproducible with integer artihmetic)
    // note that the first nr rows will have elements past
    // the diagonal.

    int nr = nz/n; 		// average number of nonzeros per row
    int anz = nr *n;   // _actual_ number of nonzeros

    double[] val = randomVector(anz, r);
    int[] col = new int[anz];
    int[] row = new int[n+1];

    row[0] = 0;
    for (int r=0; r<n; r++) {
        // initialize elements for row r

        int rowr = row[r];
        row[r+1] = rowr + nr;
        int step = r/ nr;
        if (step < 1) {
            step = 1;   // take at least unit steps
        }

        for (int i=0; i<nr; i++) {
            col[rowr+i] = i*step;
        }
    }
    SparseCompRow.matmult(y, val, row, col, x, 400);
}

void main(String[] args) {
    run();
}
