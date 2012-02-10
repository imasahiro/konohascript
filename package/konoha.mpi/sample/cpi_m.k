/*
c**********************************************************************
c   pi.c - compute pi by integrating f(x) = 4/(1 + x**2)     
c     
c   Each node: 
c    1) receives the number of rectangles used in the approximation.
c    2) calculates the areas of it's rectangles.
c    3) Synchronizes for a global summation.
c   Node 0 prints the result.
c
c  Variables:
c
c    pi  the calculated result
c    n   number of points of integration.  
c    x           midpoint of each rectangle's interval
c    f           function to integrate
c    sum,pi      area of rectangles
c    tmp         temporary scratch space for global summation
c    i           do loop index
c****************************************************************************
*/

using konoha.mpi.*;
using konoha.math.*;

PI25DT = 3.141592653589793238462643;

world = MPIComm.WORLD;
myid = world.getRank();
numprocs = world.getSize();

/*
  sizetype   = 1;
  sumtype    = 2;
*/
nd = new int[1];
if (myid == 0) {
    OUT.println("Enter the number of intervals");
    nd[0] = (int)IN.readLine();
    OUT.println("n="+"%d"(nd[0]));
}

world.bcast((MPIData)nd, 0, 0);
n = nd[0];

world.barrier();
t1 = MPI.getWtime();

/* check for quit signal */

if (n <= 0) exit(0);

/* calculate the interval size */
h = 1.0 / n;
sum  = 0.0;
for (i = myid+1; i<=n; i+= numprocs) {
    x = h * (i - 0.5);
    sum = sum + 4.0 / (1.0 + x*x);
}
mypi = h * sum;

/* collect all the partial sums */
pi = new float[1];
world.reduce((MPIData)mypi, (MPIData)pi, 1, MPIOp.SUM, 0);

world.barrier();
t2 = MPI.getWtime();
t0 =  t2 - t1;
t_w = new float[1];
world.reduce((MPIData)t0, (MPIData)t_w, 1, MPIOp.MAX, 0);

/* node 0 prints the answer. */
if (myid == 0) {
    OUT.println("  pi is approximately: "+"%18.16f"(pi[0])+" Error is: "+"%18.16f"(Math.fabs(pi[0]-PI25DT)));
    OUT.println("  execution time = : "+"%8.4f"(t_w[0])+"  [sec.]");
}
