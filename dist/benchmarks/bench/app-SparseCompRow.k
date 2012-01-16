/*
 * scimark2 SparseCompRow bench
 */
using konoha.math.*;
include "./scimark/scimarkutil/Constants.k";
include "./scimark/scimarkutil/Random.k";
include "_bench.k";
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

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "SparseCompRow";
    }
    @Override void run() {
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
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.run();
}
