//package jnt.scimark2;
using konoha.math.*;
/**
  LU matrix factorization. (Based on TNT implementation.)
  Decomposes a matrix A  into a triangular lower triangular
  factor (L) and an upper triangular factor (U) such that
  A = L*U.  By convnetion, the main diagonal of L consists
  of 1's so that L and U can be stored compactly in
  a NxN matrix.


*/
int min(int n, int m) {
    if (n < m) {
        return n;
    }
    return m;
}


public class LU 
{
    private double[][] lu_;
    private int[] pivot_;

    /**
      Returns a <em>copy</em> of the compact LU factorization.
      (useful mainly for debugging.)

      @return the compact LU factorization.  The U factor
      is stored in the upper triangular portion, and the L
      factor is stored in the lower triangular portion.
      The main diagonal of L consists (by convention) of
      ones, and is not explicitly stored.
      */


    public static final double num_flops(int n)
    {
        // rougly 2/3*N^3

        double nd = (double) n;

        return (2.0 * nd *nd *nd/ 3.0);
    }

    @Overload static double[] new_copy(double[] x)
    {
        int n = x.size;
        double[] t = new double[n];
        for (int i=0; i<n; i++) {
            t[i] = x[i];
        }
        return t;
    }


    @Overload static double[][] new_copy(double[][] a)
    {
        int m = a.size;
        int n = a[0].size;

        double[][] t = new double[][m];

        for (int i=0; i<m; i++)
        {
            t[i] = new double[n];
            double[] ti = t[i];
            double[] ai = a[i];
            for (int j=0; j<n; j++)
                ti[j] = ai[j];
        }

        return t;
    }



    @Overload public static int[] new_copy(int[] x)
    {
        int   n = x.size;
        int[] t = new int[n];
        for (int i=0; i<n; i++)
            t[i] = x[i];
        return t;
    }

    static final void insert_copy(double[][] b, double[][] a)
    {
        int m = a.size;
        int n = a[0].size;

        int remainder = n & 3; // N mod 4;

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
    public double[][] getLU()
    {
        return new_copy(lu_);
    }

    /**
      Returns a <em>copy</em> of the pivot vector.

      @return the pivot vector used in obtaining the
      LU factorzation.  Subsequent solutions must
      permute the right-hand side by this vector.

*/
    public int[] getPivot()
    {
        return new_copy(pivot_);
    }

    /**
      Initalize LU factorization from matrix.

      @param A (in) the matrix to associate with this
      factorization.
      */
    public LU( double[][] a)
    {
        int m = a.size;
        int n = a[0].size;

        //if ( lu_ == null || lu_.size != M || lu_[0].size != N)
        lu_ = new double[][m];
        for (int i=0; i<n; i++) {
            lu_[i] = new double[n];
        }

        insert_copy(lu_, a);

        //if (pivot_.size != M)
        pivot_ = new int[m];

        factor(lu_, pivot_);
    }

    /**
      Solve a linear system, with pre-computed factorization.

      @param b (in) the right-hand side.
      @return solution vector.
      */
    @Overload public double[] solve(double[] b)
    {
        double[] x = new_copy(b);

        solve(lu_, pivot_, x);
        return x;
    }


    /**
      LU factorization (in place).

      @param A (in/out) On input, the matrix to be factored.
      On output, the compact LU factorization.

      @param pivit (out) The pivot vector records the
      reordering of the rows of A during factorization.

      @return 0, if OK, nozero value, othewise.
      */
    public static int factor(double[][] a,  int[] pivot)
    {

        int n = a.size;
        int m = a[0].size;

        int minMN = min(m,n);

        for (int j=0; j<minMN; j++)
        {
            // find pivot in column j and  test for singularity.

            int jp=j;

            double t = Math.abs(a[j][j]);
            for (int i=j+1; i<m; i++)
            {
                double ab = Math.fabs(a[i][j]);
                if ( ab > t)
                {
                    jp = i;
                    t = ab;
                }
            }

            pivot[j] = jp;

            // jp now has the index of maximum element 
            // of column j, below the diagonal

            if ( a[jp][j] == 0 )                 
                return 1;       // factorization failed because of zero pivot


            if (jp != j)
            {
                // swap rows j and jp
                double[] tA = a[j];
                a[j] = a[jp];
                a[jp] = tA;
            }

            if (j<m-1)                // compute elements j+1:M of jth column
            {
                // note A(j,j), was A(jp,p) previously which was
                // guarranteed not to be zero (Label #1)
                //
                double recp =  1.0 / a[j][j];

                for (int k=j+1; k<m; k++)
                    a[k][j] *= recp;
            }


            if (j < minMN-1)
            {
                // rank-1 update to trailing submatrix:   E = E - x*y;
                //
                // E is the region A(j+1:M, j+1:N)
                // x is the column vector A(j+1:M,j)
                // y is row vector A(j,j+1:N)


                for (int ii=j+1; ii<m; ii++)
                {
                    double[] aii = a[ii];
                    double[] aj = a[j];
                    double aiiJ = aii[j];
                    for (int jj=j+1; jj<n; jj++)
                        aii[jj] -= aiiJ * aj[jj];

                }
            }
        }

        return 0;
    }


    /**
      Solve a linear system, using a prefactored matrix
      in LU form.


      @param LU (in) the factored matrix in LU form. 
      @param pivot (in) the pivot vector which lists
      the reordering used during the factorization
      stage.
      @param b    (in/out) On input, the right-hand side.
      On output, the solution vector.
      */
    @Overload public static void solve(double[][] lu, int[] pvt, double[] b)
    {
        int m = lu.size;
        int n = lu[0].size;
        int ii=0;

        for (int i=0; i<m; i++)
        {
            int ip = pvt[i];
            double sum = b[ip];

            b[ip] = b[i];
            if (ii==0)
                for (int j=ii; j<i; j++)
                    sum -= lu[i][j] * b[j];
            else 
                if (sum == 0.0)
                    ii = i;
            b[i] = sum;
        }

        for (int i=n-1; i>=0; i--)
        {
            double sum = b[i];
            for (int j=i+1; j<n; j++)
                sum -= lu[i][j] * b[j];
            b[i] = sum / lu[i][i];
        }
    }
}
