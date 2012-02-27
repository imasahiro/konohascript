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
    int     j_start, j_end;
    int     np;

    world = MPIComm.WORLD;
    myid = world.getRank();
    numprocs = world.getSize();
    np   = N/numprocs;

    double[] a = new double[np, N];
    double[] b = new double[N, np];
    double[] c = new double[np, N];

    /* matrix generation --------------------------*/
    if (DEBUG == 1) {
        for(j=0; j<np; j++) {
            for(i=0; i<N; i++) {
                a[j,i] = 1.0;
                b[i,j] = 1.0;
                c[j,i] = 0.0;
            }
        }
    } else {
        for(j=0; j<np; j++) {
            for(i=0; i<N; i++) {
                a[j][i] = Float.random();
                b[i][j] = Float.random();
                c[j][i] = 0.0;
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
        for(j=0; j<np; j++) {
            for(i=0; i<N; i++) {
                if (Math.fabs(c[j, i] - (double)N) > EPS) {
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
    int  i, j, k, l;
    int np = n / numprocs;
    int dest, src;
    int i_start, i_end;
    int jstart;

    b_t = new double[n, np];

    dest = (myid == 0) ? (numprocs-1) : (myid-1);
    src  = (myid == numprocs-1) ?   0 : (myid+1);
    i_start = myid * np;
    i_end = i_start + np;
    for (l = 0; l < numprocs; l++) {
        /* np x np */
        jstart = np * ((myid+l)%numprocs);
        for (i = 0; i < np; i++) {
            for (j = 0; j < np; j++) {
                cidx = i * n + (jstart + j);
                for (k = 0; k < n; k++) {
                    //c[i, jstart+j] += a[i, k] * b[k, j];
                    c[cidx] += a[i * n + k] * b[k * np + j];
                }
            }
        }
        /* communication */
        if (l != numprocs -1) {
            if (myid % 2 == 0) {
                world.send((MPIData)b, np * n, dest, l);
                world.recv((MPIData)b_t, np * n, src, l+numprocs);
            } else {
                world.recv((MPIData)b_t, np * n, src, l);
                world.send((MPIData)b, np * n, dest, l+numprocs);
            }
            /* copy B_T to B*/
            for (i = 0; i < n; i++) {
                for (j = 0; j < np; j++) {
                    //b[i, j] = b_t[i, j];
                    bidx = i * np + j;
                    b[bidx] = b_t[bidx];
                }
            }
        }
    }
}
