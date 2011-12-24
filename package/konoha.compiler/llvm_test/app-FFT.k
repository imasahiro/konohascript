/*
 * scimark2 FFT bench
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

/** Computes FFT's of complex, double precision data where n is an integer power of 2.
 * This appears to be slower than the Radix2 method,
 * but the code is smaller and simpler, and it requires no extra storage.
 * <P>
 *
 * @author Bruce R. Miller bruce.miller@nist.gov,
 * @author Derived from GSL (Gnu Scientific Library), 
 * @author GSL's FFT Code by Brian Gough bjg@vvv.lanl.gov
 */

/* See {@link ComplexDoubleFFT ComplexDoubleFFT} for details of data layout.
*/

void arraycopy(double[] src, int srcPos, double[] dest, int destPos, int length) {
    for (int i=0; i < length; i++) {
        dest[i+destPos] = src[i + srcPos];
    }
}


public class FFT {

    public static final double num_flops(int n)
    {
        double nd = (double) n;
        double logN = (double) log2(n);

        return (5.0*nd-2)*logN + 2*(nd+1);
    }


    /** Compute Fast Fourier Transform of (complex) data, in place.*/
    public static void transform (double[] data) {
        transform_internal(data, -1);
    }

    /** Compute Inverse Fast Fourier Transform of (complex) data, in place.*/
    public static void inverse (double[] data) {
        transform_internal(data, +1);  
        // Normalize
        int nd=data.size;
        int n =nd/2;
        double norm=1/((double) n);
        for(int i=0; i<nd; i++)
            data[i] *= norm;
    }

    /** Accuracy check on FFT of data. Make a copy of data, Compute the FFT, then
     * the inverse and compare to the original.  Returns the rms difference.*/
    public static double test(double[] data){
        int nd = data.size;
        // Make duplicate for comparison
        double[] copy = new double[nd];
        arraycopy(data,0,copy,0,nd);
        // Transform & invert
        transform(data);
        inverse(data);
        // Compute RMS difference.
        double diff = 0.0;
        for(int i=0; i<nd; i++) {
            double d = data[i]-copy[i];
            diff += d*d; }
        return Math.sqrt(diff/nd);
    }

    /** Make a random array of n (complex) elements. */
    public static double[] makeRandom(int n){
        int nd = 2*n;
        double[] data = new double[nd];
        for(int i=0; i<nd; i++) {
            data[i]= Float.random();
        }
        return data;
    }

    /** Simple Test routine. */
    public static void main(String[] args){
        if (args.size == 0) {
            int n = 1024;
            System.out.println("n="+n+" => RMS Error="+test(makeRandom(n)));
        }
        for(int i=0; i<args.size; i++) {
            int n = (int) (args[i]);
            System.out.println("n="+n+" => RMS Error="+test(makeRandom(n)));
        }
    }
    /* ______________________________________________________________________ */

    static int log2 (int n){
        int log = 0;
        for(int k=1; k < n; k *= 2) { log++; }
        //if (n != (1 << log))
        //    throw new Error("FFT: Data length is not a power of 2!: "+n);
        return log;
    }

    static void transform_internal (double[] data, int direction) {
        if (data.size == 0) return;
        int n = data.size/2;
        if (n == 1) return;         // Identity operation!
        int logn = log2(n);

        /* bit reverse the input data for decimation in time algorithm */
        bitreverse(data);

        /* apply fft recursion */
        /* this loop executed log2(N) times */
        int dual = 1;
        for (int bit = 0; bit < logn; bit++) {
            double w_real = 1.0;
            double w_imag = 0.0;

            double theta = 2.0 * direction * Math.PI / (2.0 * (double) dual);
            double s = Math.sin(theta);
            double t = Math.sin(theta / 2.0);
            double s2 = 2.0 * t * t;

            /* a = 0 */
            for (int b = 0; b < n; b = b + 2 * dual) {
                int i = 2*b ;
                int j = 2*(b + dual);

                double wd_real = data[j] ;
                double wd_imag = data[j+1] ;

                data[j]   = data[i]   - wd_real;
                data[j+1] = data[i+1] - wd_imag;
                data[i]  += wd_real;
                data[i+1]+= wd_imag;
            }

            /* a = 1 .. (dual-1) */
            for (int a = 1; a < dual; a++) {
                /* trignometric recurrence for w-> exp(i theta) w */
                {
                    double tmp_real = w_real - s * w_imag - s2 * w_real;
                    double tmp_imag = w_imag + s * w_real - s2 * w_imag;
                    w_real = tmp_real;
                    w_imag = tmp_imag;
                }
                for (int b = 0; b < n; b += 2 * dual) {
                    int i = 2*(b + a);
                    int j = 2*(b + a + dual);

                    double z1_real = data[j];
                    double z1_imag = data[j+1];

                    double wd_real = w_real * z1_real - w_imag * z1_imag;
                    double wd_imag = w_real * z1_imag + w_imag * z1_real;

                    data[j]   = data[i]   - wd_real;
                    data[j+1] = data[i+1] - wd_imag;
                    data[i]  += wd_real;
                    data[i+1]+= wd_imag;
                }
            }

            dual *= 2;
        }
    }


    static void bitreverse(double[] data) {
        /* This is the Goldrader bit-reversal algorithm */
        int n=data.size/2;
        int nm1 = n-1;
        int i=0; 
        int j=0;
        for (; i < nm1; i++) {

            int ii = 2*i;
            //int ii = i << 1;

            int jj = 2*j;
            //int jj = j << 1;

            int k = n / 2 ;
            //int k = n >> 1;

            if (i < j) {
                double tmp_real    = data[ii];
                double tmp_imag    = data[ii+1];
                data[ii]   = data[jj];
                data[ii+1] = data[jj+1];
                data[jj]   = tmp_real;
                data[jj+1] = tmp_imag;
            }

            while (k <= j) {
                j = j - k ;
                //j -= k;

                k = k / 2 ; 
                //k >>= 1 ; 
            }
            j += k ;
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

void main (String[] args) {
    Random r = new Random(RANDOM_SEED);
    // initialize FFT data as complex (n real/img pairs)

    double[] x = randomVector(2*FFT_SIZE, r);
    int cycles = 600;
    for (int i=0; i<cycles; i++) {
        FFT.transform(x); // forward transform
        FFT.inverse(x);   // backward transform
    }
    OUT.println("RMS Error="+FFT.test(x));
}

