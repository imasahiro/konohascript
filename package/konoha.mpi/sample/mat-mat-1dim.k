
using konoha.mpi.*;
using konoha.math.*;

N =     256;//64;
DEBUG = 1;
EPS =   1.0e-18

/* Please define the matrices in here */
a = new double[N,N];
b = new double[N,N];
c = new double[N,N];

int     myid, numprocs;

void myMatMat(double[] c, double[] a, double[] b, int n);

void main(String[] args) {

    double  t0, t1, t2;
    double  dc_inv, d_mflops;

    int     ierr;
    int     i, j;
    int     iflag;
    int     j_start, j_end;

    world = MPIComm.WORLD;
    myid = world.getRank();
    numprocs = world.getSize();

    /* matrix generation --------------------------*/
    if (DEBUG == 1) {
        for(j=0; j<N; j++) {
            for(i=0; i<N; i++) {
                a[j,i] = 1.0;
                b[j,i] = 1.0;
                c[j,i] = 0.0;
            }
        }
    } else {
        for(j=0; j<N; j++) {
            for(i=0; i<N; i++) {
                a[j,i] = Float.random();
                b[j,i] = Float.random();
                c[j,i] = 0.0;
            }
        }
    } /* end of matrix generation --------------------------*/

    /* Start of mat-vec routine ----------------------------*/
    world.barrier();
    t1 = getMPIWtime();

    MyMatMat(c, a, b, N);

    world.barrier();
    t2 = getMPIWtime();
    t0 =  t2 - t1;
    t_w = new float[1];
    world.reduce(t0, t_w, MPIOp.MAX, 0);
    /* End of mat-vec routine --------------------------- */

    if (myid == 0) {

        OUT.println("N  = "+N);
        OUT.println("Mat-Mat time  = "+"%f"(t_w[0])+" [sec.]");

        d_mflops = 2.0 * (double)N * (double)N * (double)N / t_w[0];
        d_mflops = d_mflops * 1.0e-6;
        OUT.println(" "+"%f"(d_mflops)+" [MFLOPS]");
    }

    if (DEBUG == 1) {
        /* Verification routine ----------------- */
        iflag = 0;
        j_start = N/numprocs * myid;
        j_end = j_start + N/numprocs;
        for(j=j_start; j<j_end; j++) {
            for(i=0; i<N; i++) {
                if (Math.fabs(c[j,i] - (double)N) > EPS) {
                    OUT.println(" Error! in ( "+"%d"(j)+" , "+"%d"(i)+" ) th argument.");
                    iflag = 1;
                    break;
                }
            }
        }
        /* ------------------------------------- */

        iflag_t = new int[1];
        world.reduce(iflag, iflag_t, MPIOp.SUM, 0);
        if (myid == 0) {
            if (iflag_t[0] == 0) OUT.println(" OK! ");
        }

    }

}

void myMatMat(double[] c, double[] a, double[] b, int n)
{
    int  i, j, k;
    int  i_start, i_end;
    i_start = n/numprocs * myid;
    i_end = i_start + n/numprocs;
    for(i=i_start; i<i_end; i++) {
        for(j=0; j<n; j++) {
            cidx = i * n + j;
            for(k=0; k<n; k++) {
                c[cidx] += a[i * n + k] * b[k * n + j];
                //c[i,j] += a[i,k] * b[k,j];
            }
        }
    }
}
