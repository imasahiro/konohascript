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

