/*

Modified 3/3/97 by David M. Doolin (dmd) doolin@cs.utk.edu
Fixed error in matgen() method. Added some comments.

Modified 1/22/97 by Paul McMahan mcmahan@cs.utk.edu
Added more MacOS options to form.

Optimized by Jonathan Hardwick (jch@cs.cmu.edu), 3/28/96
Compare to Linkpack.java.
Optimizations performed:
 - added "final" modifier to performance-critical methods.
 - changed lines of the form "a[i] = a[i] + x" to "a[i] += x".
 - minimized array references using common subexpression elimination.
 - eliminated unused variables.
 - undid an unrolled loop.
 - added temporary 1D arrays to hold frequently-used columns of 2D arrays.
 - wrote my own abs() method
See http://www.cs.cmu.edu/~jch/java/linpack.html for more details.


Ported to Java by Reed Wade  (wade@cs.utk.edu) 2/96
built using JDK 1.0 on solaris
using "javac -O Linpack.java"


Translated to C by Bonnie Toy 5/88
  (modified on 2/25/94  to fix a problem with daxpy  for
   unequal increments or equal increments not equal to 1.
     Jack Dongarra)

Translated to Konoha by Masahiro Ide

*/

using konoha.compiler.*;
@Public double System.currentTimeMillis() {
    return (double) System.getTime();
}

public class Linpack {
    double second_orig = -1;
    final double abs (double d);
    double second();
    double epslon(double v);
    void dmxpy(int n1, double[] y, int n2, int ldm, Array<double> x, Array<Array<double>> m);
    public void run_benchmark();
    final double matgen (Array<Array<double>> a, int lda, int n, double[] b);
    final int idamax(int n, double[] dx, int dx_off, int incx);
    final void dscal( int n, double da, double[] dx, int dx_off, int incx);
    final int dgefa(Array<Array<double>> a, int lda, int n, int[] ipvt)
    final double ddot( int n, double[] dx, int dx_off, int incx, double[] dy, int dy_off, int incy);
    final void dgesl(Array<Array<double>> a, int lda, int n, int[] ipvt, double[] b, int job);
    final void daxpy( int n, double da, double[] dx, int dx_off, int incx, double[] dy, int dy_off, int incy);
    final double ddot( int n, double[] dx, int dx_off, int incx, double[] dy, int dy_off, int incy);
    final void dscal( int n, double da, double[] dx, int dx_off, int incx);
    final int idamax(int n, double[] dx, int dx_off, int incx);
    final double epslon(double v);
}
final double Linpack.abs (double d)
{
    return (d >= 0) ? d : -d;
}

double Linpack.second()
{
    if (second_orig==-1) {
        second_orig = System.currentTimeMillis();
    }
    return (System.currentTimeMillis() - second_orig)/1000;
}

public void Linpack.run_benchmark() 
{
    double mflops_result = 0.0;
    double residn_result = 0.0;
    double time_result = 0.0;
    double eps_result = 0.0;

    Array<Array<double>> a = new Array<double> [200];
    Array<double> b = new double[200];
    Array<double> x = new double[200];
    double cray,ops,total,norma,normx;
    double resid,time;
    double kf;
    int n,i,ntimes,info,lda,ldaa,kflops;
    int[] ipvt = new int[200];

    for (i=0; i < 200; i++) {
        a[i] = new double[201];
    }
    //double mflops_result;
    //double residn_result;
    //double time_result;
    //double eps_result;

    lda = 201;
    ldaa = 200;
    cray = .056;
    n = 100;

    ops = (2.0e0*(n*n*n))/3.0 + 2.0*(n*n);

    norma = matgen(a,lda,n,b);
    time = second();
    info = dgefa(a,lda,n,ipvt);
    dgesl(a,lda,n,ipvt,b,0);
    total = second() - time;

    for (i = 0; i < n; i++) {
        x[i] = b[i];
    }
    norma = matgen(a,lda,n,b);
    for (i = 0; i < n; i++) {
        b[i] = -b[i];
    }
    dmxpy(n,b,n,lda,x,a);
    resid = 0.0;
    normx = 0.0;
    for (i = 0; i < n; i++) {
        resid = (resid > abs(b[i])) ? resid : abs(b[i]);
        normx = (normx > abs(x[i])) ? normx : abs(x[i]);
    }

    eps_result = epslon((double)1.0);
    /*

       residn_result = resid/( n*norma*normx*eps_result );
       time_result = total;
       mflops_result = ops/(1.0e6*total);

       return ("Mflops/s: " + mflops_result +
       "  Time: " + time_result + " secs" +
       "  Norm Res: " + residn_result +
       "  Precision: " + eps_result);
     */
    residn_result = resid/( n*norma*normx*eps_result );
    residn_result += 0.005; // for rounding
    residn_result = (int)(residn_result*100);
    residn_result /= 100;

    time_result = total;
    time_result += 0.005; // for rounding
    time_result = (int)(time_result*100);
    time_result /= 100;

    mflops_result = ops/(1.0e6*total);
    mflops_result += 0.0005; // for rounding
    mflops_result = (int)(mflops_result*1000);
    mflops_result /= 1000;

    System.out.println("Mflops/s: " + mflops_result +
            "  Time: " + time_result + " secs" +
            "  Norm Res: " + residn_result +
            "  Precision: " + eps_result);
}

final double Linpack.matgen (Array<Array<double>> a, int lda, int n, double[] b)
{
    double norma;
    int init, i, j;

    init = 1325;
    norma = 0.0;
    /*  Next two for() statements switched.  Solver wants
        matrix in column order. --dmd 3/3/97
     */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            init = 3125*init % 65536;
            a[j][i] = (init - 32768.0)/16384.0;
            norma = (a[j][i] > norma) ? a[j][i] : norma;
        }
    }
    for (i = 0; i < n; i++) {
        b[i] = 0.0;
    }
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            b[i] += a[j][i];
        }
    }

    return norma;
}

final int Linpack.dgefa(Array<Array<double>> a, int lda, int n, int[] ipvt)
{
    double[] col_k, col_j;
    double t;
    int j,k,kp1,l,nm1;
    int info;

    // gaussian elimination with partial pivoting

    info = 0;
    nm1 = n - 1;
    if (nm1 >=  0) {
        for (k = 0; k < nm1; k++) {
            col_k = a[k];
            kp1 = k + 1;

            // find l = pivot index

            l = idamax(n-k,col_k,k,1) + k;
            ipvt[k] = l;

            // zero pivot implies this column already triangularized

            if (col_k[l] != 0) {

                // interchange if necessary

                if (l != k) {
                    t = col_k[l];
                    col_k[l] = col_k[k];
                    col_k[k] = t;
                }

                // compute multipliers

                t = -1.0/col_k[k];
                dscal(n-(kp1),t,col_k,kp1,1);

                // row elimination with column indexing

                for (j = kp1; j < n; j++) {
                    col_j = a[j];
                    t = col_j[l];
                    if (l != k) {
                        col_j[l] = col_j[k];
                        col_j[k] = t;
                    }
                    daxpy(n-(kp1),t,col_k,kp1,1,
                            col_j,kp1,1);
                }
            }
            else {
                info = k;
            }
        }
    }
    ipvt[n-1] = n-1;
    if (a[(n-1)][(n-1)] == 0) info = n-1;

    return info;
}

final void Linpack.dgesl(Array<Array<double>> a, int lda, int n, int[] ipvt, double[] b, int job)
{
    double t;
    int k,kb,l,nm1,kp1;

    nm1 = n - 1;
    if (job == 0) {

        // job = 0 , solve  a * x = b.  first solve  l*y = b

        if (nm1 >= 1) {
            for (k = 0; k < nm1; k++) {
                l = ipvt[k];
                t = b[l];
                if (l != k){
                    b[l] = b[k];
                    b[k] = t;
                }
                kp1 = k + 1;
                daxpy(n-(kp1),t,a[k],kp1,1,b,kp1,1);
            }
        }

        // now solve  u*x = y

        for (kb = 0; kb < n; kb++) {
            k = n - (kb + 1);
            b[k] /= a[k][k];
            t = -b[k];
            daxpy(k,t,a[k],0,1,b,0,1);
        }
    }
    else {

        // job = nonzero, solve  trans(a) * x = b.  first solve  trans(u)*y = b

        for (k = 0; k < n; k++) {
            t = ddot(k,a[k],0,1,b,0,1);
            b[k] = (b[k] - t)/a[k][k];
        }

        // now solve trans(l)*x = y 

        if (nm1 >= 1) {
            for (kb = 1; kb < nm1; kb++) {
                k = n - (kb+1);
                kp1 = k + 1;
                b[k] += ddot(n-(kp1),a[k],kp1,1,b,kp1,1);
                l = ipvt[k];
                if (l != k) {
                    t = b[l];
                    b[l] = b[k];
                    b[k] = t;
                }
            }
        }
    }
}



final void Linpack.daxpy( int n, double da, double[] dx, int dx_off, int incx, double[] dy, int dy_off, int incy)
{
    int i,ix,iy;

    if ((n > 0) && (da != 0)) {
        if (incx != 1 || incy != 1) {

            // code for unequal increments or equal increments not equal to 1

            ix = 0;
            iy = 0;
            if (incx < 0) ix = (-n+1)*incx;
            if (incy < 0) iy = (-n+1)*incy;
            for (i = 0;i < n; i++) {
                dy[iy +dy_off] += da*dx[ix +dx_off];
                ix += incx;
                iy += incy;
            }
            return;
        } else {

            // code for both increments equal to 1

            for (i=0; i < n; i++)
                dy[i +dy_off] += da*dx[i +dx_off];
        }
    }
}

final double Linpack.ddot( int n, double[] dx, int dx_off, int incx, double[] dy, int dy_off, int incy)
{
    double dtemp;
    int i,ix,iy;

    dtemp = 0;

    if (n > 0) {

        if (incx != 1 || incy != 1) {

            // code for unequal increments or equal increments not equal to 1

            ix = 0;
            iy = 0;
            if (incx < 0) ix = (-n+1)*incx;
            if (incy < 0) iy = (-n+1)*incy;
            for (i = 0;i < n; i++) {
                dtemp += dx[ix +dx_off]*dy[iy +dy_off];
                ix += incx;
                iy += incy;
            }
        } else {

            // code for both increments equal to 1

            for (i=0;i < n; i++)
                dtemp += dx[i +dx_off]*dy[i +dy_off];
        }
    }
    return(dtemp);
}

final void Linpack.dscal( int n, double da, double[] dx, int dx_off, int incx)
{
    int i,nincx;

    if (n > 0) {
        if (incx != 1) {

            // code for increment not equal to 1

            nincx = n*incx;
            for (i = 0; i < nincx; i += incx)
                dx[i +dx_off] *= da;
        } else {

            // code for increment equal to 1

            for (i = 0; i < n; i++)
                dx[i +dx_off] *= da;
        }
    }
}

final int Linpack.idamax(int n, double[] dx, int dx_off, int incx)
{
    double dmax, dtemp;
    int i, ix, itemp=0;

    if (n < 1) {
        itemp = -1;
    } else if (n ==1) {
        itemp = 0;
    } else if (incx != 1) {

        // code for increment not equal to 1

        dmax = abs(dx[0 +dx_off]);
        ix = 1 + incx;
        for (i = 1; i < n; i++) {
            dtemp = abs(dx[ix + dx_off]);
            if (dtemp > dmax)  {
                itemp = i;
                dmax = dtemp;
            }
            ix += incx;
        }
    } else {

        // code for increment equal to 1

        itemp = 0;
        dmax = abs(dx[0 +dx_off]);
        for (i = 1; i < n; i++) {
            dtemp = abs(dx[i + dx_off]);
            if (dtemp > dmax) {
                itemp = i;
                dmax = dtemp;
            }
        }
    }
    return (itemp);
}

final double Linpack.epslon(double v)
{
    double a,b,c,eps;

    a = 4.0e0/3.0e0;
    eps = 0;
    while (eps == 0) {
        b = a - 1.0;
        c = b + b + b;
        eps = abs(c-1.0);
    }
    return(eps*abs(v));
}

void Linpack.dmxpy(int n1, double[] y, int n2, int ldm, Array<double> x, Array<Array<double>> m)
{
    int j,i;

    // cleanup odd vector
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            y[i] += x[j]*m[j][i];
        }
    }
}



void main(String[] args)
{
    Linpack l = new Linpack();
    l.run_benchmark();
}


