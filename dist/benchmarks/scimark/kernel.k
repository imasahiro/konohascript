//package jnt.scimark2;
include "scimarkutil/Random.k";
include "scimarkutil/Stopwatch.k";
include "FFT.k";
include "LU.k";
include "SOR.k";
include "MonteCarlo.k";
include "SparseCompRow.k";
EPS_FFT = 1.0e-10;
EPS_LU = 1.0e-12;
public class Kernel
{
    // each measurement returns approx Mflops


    public static double measureFFT(int n, double mintime, Random r)
    {
        // initialize FFT data as complex (n real/img pairs)

        double[] x = randomVector(2*n, r);
        double[] oldx = newVectorCopy(x);
        long cycles = 1;
        Stopwatch q = new Stopwatch();

        while(true)
        {
            q.start();
            for (int i=0; i<cycles; i++)
            {
                FFT.transform(x);	// forward transform
                FFT.inverse(x);		// backward transform
            }
            q.stop();
            if (q.read() >= mintime)
                break;

            cycles *= 2;
        }
        // approx Mflops

        if ( FFT.test(x) / n > EPS_FFT )
            return 0.0;

        return FFT.num_flops(n)*cycles/ q.read() * 1.0e-6;
    }


    public static double measureSOR(int n, double min_time, Random r)
    {
        double[][] g = randomMatrix(n, n, r);

        Stopwatch q = new Stopwatch();
        int cycles=1;
        while(true)
        {
            q.start();
            SOR.execute(1.25, g, cycles);
            q.stop();
            if (q.read() >= min_time) break;

            cycles *= 2;
        }
        // approx Mflops
        return SOR.num_flops(n, n, cycles) / q.read() * 1.0e-6;
    }

    public static double measureMonteCarlo(double min_time, Random r)
    {
        Stopwatch q = new Stopwatch();

        int cycles=1;
        while(true)
        {
            q.start();
            MonteCarlo.integrate(cycles);
            q.stop();
            if (q.read() >= min_time) break;

            cycles *= 2;
        }
        // approx Mflops
        return MonteCarlo.num_flops(cycles) / q.read() * 1.0e-6;
    }


    public static double measureSparseMatmult(int n, int nz, 
            double min_time, Random r)
    {
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
        for (int r=0; r<n; r++)
        {
            // initialize elements for row r

            int rowr = row[r];
            row[r+1] = rowr + nr;
            int step = r/ nr;
            if (step < 1) step = 1;   // take at least unit steps


            for (int i=0; i<nr; i++)
                col[rowr+i] = i*step;

        }

        Stopwatch q = new Stopwatch();

        int cycles=1;
        while(true)
        {
            q.start();
            SparseCompRow.matmult(y, val, row, col, x, cycles);
            q.stop();
            if (q.read() >= min_time) break;

            cycles *= 2;
        }
        // approx Mflops
        return SparseCompRow.num_flops(n, nz, cycles) / q.read() * 1.0e-6;
    }


    public static double measureLU(int n, double min_time, Random r)
    {
        // compute approx Mlfops, or O if LU yields large errors

        double[][] a  = randomMatrix(n, n,  r);
        double[][] lu = new double[][n];
        int[] pivot = new int[n];

        for (int i=0; i<n; i++) {
            lu[i] = new double[n];
        }

        Stopwatch q = new Stopwatch();

        int cycles=1;
        while(true)
        {
            q.start();
            for (int i=0; i<cycles; i++)
            {
                copyMatrix(lu, a);
                LU.factor(lu, pivot);
            }
            q.stop();
            if (q.read() >= min_time) break;

            cycles *= 2;
        }


        // verify that LU is correct
        double[] b = randomVector(n, r);
        double[] x = newVectorCopy(b);

        LU.solve(lu, pivot, x);

        if ( normabs(b, matvec(a,x)) / n > EPS_LU )
            return 0.0;


        // else return approx Mflops
        //
        return LU.num_flops(n) * cycles / q.read() * 1.0e-6;
    }


    static double[] newVectorCopy(double[] x)
    {
        int n = x.size;

        double[] y = new double[n];
        for (int i=0; i<n; i++)
            y[i] = x[i];

        return y;
    }

    static void copyVector(double[] b, double[] a)
    {
        int n = a.size;

        for (int i=0; i<n; i++)
            b[i] = a[i];
    }


    static double normabs(double[] x, double[] y)
    {
        int n = x.size;
        double sum = 0.0;

        for (int i=0; i<n; i++)
            sum += Math.abs(x[i]-y[i]);

        return sum;
    }

    static void copyMatrix(double[][] b, double[][] a)
    {
        int m = a.size;
        int n = a[0].size;

        int remainder = n & 3;		 // n mod 4;

        for (int i=0; i<m; i++)
        {
            double[] bi = b[i];
            double[] ai = a[i];
            for (int j=0; j<remainder; j++)
                bi[j] = ai[j];
            for (int j=remainder; j<n; j+=4)
            {
                bi[j]   = ai[j];
                bi[j+1] = ai[j+1];
                bi[j+2] = ai[j+2];
                bi[j+3] = ai[j+3];
            }
        }
    }

    static double[][] randomMatrix(int m, int n, Random r)
    {
        double[][] a = new double[][m];

        for (int i=0; i<n; i++) {
            a[i] = new double[n];
            for (int j=0; j<n; j++) {
                a[i][j] = r.nextDouble();
            }
        }
        return a;
    }

    static double[] randomVector(int n, Random r)
    {
        double[] a = new double[n];

        for (int i=0; i<n; i++)
            a[i] = r.nextDouble();
        return a;
    }

    @Overload static double[] matvec(double[][] a, double[] x)
    {
        int n = x.size;
        double[] y = new double[n];

        matvec(a, x, y);

        return y;
    }

    @Overload static void matvec(double[][] a, double[] x, double[] y)
    {
        int m = a.size;
        int n = a[0].size;

        for (int i=0; i<m; i++)
        {
            double sum = 0.0;
            double[] ai = a[i];
            for (int j=0; j<n; j++)
                sum += ai[j] * x[j];

            y[i] = sum;
        }
    }

}
