using konoha.mpi.*;
using konoha.math.*;

N =     480;
DEBUG = 1;
EPS =   1.0e-18;

MPIComm world;
int     myid, numprocs;

void myMatMat(double[] c, double[] a, double[] b, int n);

void main(String[] args) {

    double  t0, t1, t2;
    double  dc_inv, d_mflops;

    int     i, j;
    int     iflag; int[] iflag_t = [1];

    world = MPIComm.WORLD;
    myid = world.getRank();
    numprocs = world.getSize();

    a = new double[N,N];
    b = new double[N,N];
    c = new double[N,N];

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
    t1 = MPI.getWtime();

    myMatMat(c, a, b, N);

    world.barrier();
    t2 = MPI.getWtime();
    t0 =  t2 - t1;
    t_w = new float[1];
    world.reduce((MPIData)t0, (MPIData)t_w, 1, MPIOp.MAX, 0);
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
        for(j=0; j<N; j++) {
            for(i=0; i<N; i++) {
                if (Math.fabs(c[j,i] - (double)N) > EPS) {
                    OUT.println(" Error! in ( "+"%d"(j)+" , "+"%d"(i)+" ) th argument.");
                    iflag = 1;
                    break;
                }
            }
        }
        /* ------------------------------------- */
        world.reduce((MPIData)iflag, (MPIData)iflag_t, 1, MPIOp.SUM, 0);
        if (myid == 0) {
            if (iflag_t[0] == 0) OUT.println(" OK! ");
        }

    }

}

void myMatMat(double[] c, double[] a, double[] b, int n)
{
    int  i, j, k;
    for(i=0; i<N; i++) {
        for(j=0; j<n; j++) {
            cidx = i * n + j;
            for(k=0; k<n; k++) {
                //c[i,j] += a[i,k] * b[k,j];
                c[cidx] += a[i * n + k] * b[k * n + j];
            }
        }
    }
}
