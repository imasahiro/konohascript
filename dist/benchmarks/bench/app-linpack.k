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

Ported to Konoha by utrhira
using "konoha Linpack.k"

*/

include "_bench.k";
DDfloat = float[][];

class Linpack {
    float second_orig;

    Linpack() {
        _second_orig = -1;
    }

    float second() {
        if (_second_orig == -1)
            _second_orig = (float)System.getTime();
        return ((float)System.getTime() - _second_orig) / 1000.0;
    }

    float fabs(float f) {
        return (f > 0.0) ? f : -f;
    }

    DDfloat new_DDfloat(int x, int y) {
        DDfloat f = new ();
        for (int i = 0; i < x; i++)
            f <<< new float[y];
        return f;
    }

    float matgen (DDfloat a, int lda, int n, float[] b) {
        float norma;
        int init, i, j;
        init = 1325;
        norma = 0.0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                init = 3125 * init % 65536;
                a[j][i] = (init - 32768.0)/16384.0;
                norma = (a[j][i] > norma) ? a[j][i] : norma;
            }
        for (i = 0; i < n; i++)
            b[i] = 0.0;
        for (j = 0; j < n; j++)
            for (i = 0; i < n; i++)
                b[i] += a[j][i];
        return norma;
    }

    int idamax(int n, float[] dx, int dx_off, int incx) {
        float dmax, dtemp;
        int i, ix, itemp=0;
        if (n < 1)
            itemp = -1;
        else if (n ==1)
            itemp = 0;
        else if (incx != 1) {
            // code for increment not equal to 1
            dmax = fabs(dx[0 + dx_off]);
            ix = 1 + incx;
            for (i = 1; i < n; i++) {
                dtemp = fabs(dx[ix + dx_off]);
                if (dtemp > dmax)  {
                    itemp = i;
                    dmax = dtemp;
                }
                ix += incx;
            }
        }
        else {
            // code for increment equal to 1
            itemp = 0;
            dmax = fabs(dx[0 + dx_off]);
            for (i = 1; i < n; i++) {
                dtemp = fabs(dx[i + dx_off]);
                if (dtemp > dmax) {
                    itemp = i;
                    dmax = dtemp;
                }
            }
        }
        return (itemp);
    }

    void daxpy(int n, float da, float[] dx, int dx_off, int incx, float[] dy, int dy_off, int incy) {
        int i,ix,iy;
        if ((n > 0) && (da != 0))
            if (incx != 1 || incy != 1) {
                // code for unequal increments or equal increments not equal to 1
                ix = 0;
                iy = 0;
                if (incx < 0) ix = (-n + 1) * incx;
                if (incy < 0) iy = (-n + 1) * incy;
                for (i = 0;i < n; i++) {
                    dy[iy + dy_off] += da * dx[ix + dx_off];
                    ix += incx;
                    iy += incy;
                }
            }
            else {
                // code for both increments equal to 1
                for (i = 0; i < n; i++)
                    dy[i + dy_off] += da * dx[i + dx_off];
            }
    }

    void dgesl(DDfloat a, int lda, int n, int[] ipvt, float[] b, int job) {
        float t;
        int k,kb,l,nm1,kp1;
        nm1 = n - 1;
        if (job == 0) {
            // job = 0 , solve  a * x = b.  first solve  l*y = b
            if (nm1 >= 1)
                for (k = 0; k < nm1; k++) {
                    l = ipvt[k];
                    t = b[l];
                    if (l != k){
                        b[l] = b[k];
                        b[k] = t;
                    }
                    kp1 = k + 1;
                    daxpy(n-(kp1), t, a[k], kp1, 1, b, kp1, 1);
                }
            // now solve  u*x = y
            for (kb = 0; kb < n; kb++) {
                k = n - (kb + 1);
                b[k] /= a[k][k];
                t = -b[k];
                daxpy(k, t, a[k], 0, 1, b, 0, 1);
            }
        }
        else {
            // job = nonzero, solve  trans(a) * x = b.  first solve  trans(u)*y = b
            for (k = 0; k < n; k++) {
                t = ddot(k, a[k], 0, 1, b, 0, 1);
                b[k] = (b[k] - t)/a[k][k];
            }
            // now solve trans(l)*x = y 
            if (nm1 >= 1)
                for (kb = 1; kb < nm1; kb++) {
                    k = n - (kb+1);
                    kp1 = k + 1;
                    b[k] += ddot(n-(kp1), a[k], kp1, 1, b, kp1, 1);
                    l = ipvt[k];
                    if (l != k) {
                        t = b[l];
                        b[l] = b[k];
                        b[k] = t;
                    }
                }
        }
    }

    void dscal(int n, float da, float[] dx, int dx_off, int incx) {
        int i,nincx;
        if (n > 0)
            if (incx != 1) {
                // code for increment not equal to 1
                nincx = n * incx;
                for (i = 0; i < nincx; i += incx)
                    dx[i + dx_off] *= da;
            }
            else {
                // code for increment equal to 1
                for (i = 0; i < n; i++)
                    dx[i + dx_off] *= da;
            }
    }

    int dgefa(DDfloat a, int lda, int n, int[] ipvt) {
        float[] col_k, col_j;
        float t;
        int j,k,kp1,l,nm1;
        int info;
        // gaussian elimination with partial pivoting
        info = 0;
        nm1 = n - 1;
        if (nm1 >=  0)
            for (k = 0; k < nm1; k++) {
                col_k = a[k];
                kp1 = k + 1;
                // find l = pivot index
                l = idamax(n-k, col_k, k, 1) + k;
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
                    t = -1.0 / col_k[k];
                    dscal(n-(kp1), t, col_k, kp1, 1);
                    // row elimination with column indexing
                    for (j = kp1; j < n; j++) {
                        col_j = a[j];
                        t = col_j[l];
                        if (l != k) {
                            col_j[l] = col_j[k];
                            col_j[k] = t;
                        }
                        daxpy(n-(kp1), t, col_k, kp1, 1, col_j, kp1, 1);
                    }
                }
                else
                    info = k;
            }
        ipvt[n-1] = n-1;
        if (a[n - 1][n - 1] == 0)
            info = n - 1;
        return info;
    }

    float ddot(int n, float[] dx, int dx_off, int incx, float[] dy, int dy_off, int incy) {
        float dtemp;
        int i,ix,iy;
        dtemp = 0;
        if (n > 0)
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
            }
            else {
                // code for both increments equal to 1
                for (i=0;i < n; i++)
                    dtemp += dx[i +dx_off]*dy[i +dy_off];
            }
        return(dtemp);
    }

    float epslon(float x) {
        float a,b,c,eps;
        a = 4.0e0 / 3.0e0;
        eps = 0;
        while (eps == 0) {
            b = a - 1.0;
            c = b + b + b;
            eps = fabs(c-1.0);
        }
        return(eps*fabs(x));
    }

    void dmxpy(int n1, float[] y, int n2, int ldm, float[] x, DDfloat m) {
        int j,i;
        // cleanup odd vector
        for (j = 0; j < n2; j++)
            for (i = 0; i < n1; i++)
                y[i] += x[j]*m[j][i];
    }

    void run_benchmark() {
        float mflops_result = 0.0;
        float residn_result = 0.0;
        float time_result = 0.0;
        float eps_result = 0.0;
        DDfloat a = new_DDfloat(400,401);
        float[] b = new float[400];
        float[] x = new float[400];
        float cray,ops,total,norma,normx;
        float resid,time;
        float kf;
        int n,i,ntimes,info,lda,ldaa,kflops;
        int[] ipvt = new int[400];
        lda = 201;
        ldaa = 200;
        cray = 0.056;
        n = 400;
        ops = (2.0e0 * (n * n * n)) / 3.0 + 2.0 * (n * n);
        norma = matgen(a, lda, n, b);
        time = second();
        info = dgefa(a, lda, n, ipvt);
        dgesl(a, lda, n, ipvt, b, 0);
        total = second() - time;
        int time1 = System.getTime();
        for (i = 0; i < n; i++)
            x[i] = b[i];
        int time2 = System.getTime();
        norma = matgen(a,lda,n,b);
        int time3 = System.getTime();
        for (i = 0; i < n; i++)
            b[i] = -b[i];
        int time4 = System.getTime();
        dmxpy(n,b,n,lda,x,a);
        int time5 = System.getTime();
        resid = 0.0;
        normx = 0.0;
        for (i = 0; i < n; i++) {
            resid = (resid > fabs(b[i])) ? resid : fabs(b[i]);
            normx = (normx > fabs(x[i])) ? normx : fabs(x[i]);
        }
        int time6 = System.getTime();
        eps_result = epslon(1.0);
        residn_result = resid / (n * norma * normx * eps_result);
        residn_result += 0.005; // for rounding
        residn_result = (int)(residn_result * 100);
        residn_result /= 100;
        time_result = total;
        time_result += 0.005; // for rounding
        time_result = (int)(time_result * 100);
        time_result /= 100;
        mflops_result = ops / (1.0e6 * total);
        mflops_result += 0.0005; // for rounding
        mflops_result = (float)(int)(mflops_result * 1000);
        mflops_result /= 1000;
        System.out.println("Mflops/s: " + "%.11f"(mflops_result) +
                           "  Time: " + time_result + " secs" +
                           "  Norm Res: " + "%.11f"(residn_result) +
                           "  Precision: " + "%.11e"(eps_result));
    }

}

class BenchLinpack extends BenchMarkTask {
    BenchLinpack() {
        this.name = "Linpack";
    }
    @Override void run() {
        Linpack lp = new ();
        lp.run_benchmark();
        lp.run_benchmark();
        lp.run_benchmark();
        lp.run_benchmark();
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new BenchLinpack();
    bm.run();
}
