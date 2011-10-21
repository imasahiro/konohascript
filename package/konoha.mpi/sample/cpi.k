using konoha.mpi.*;
using konoha.math.*;

PI25DT = 3.141592653589793238462643;
N = 1000000

world = MPIComm.WORLD;
myid = world.getRank();
numprocs = world.getSize();

h = 1.0 / N;
sum  = 0.0;
for (i = myid+1; i <= N; i += numprocs) {
    x = h * (i - 0.5);
    sum += 4.0 / (1.0 + x*x);
}
mypi = h * sum;

pi = new float[1];
world.reduce((MPIData)[mypi], (MPIData)pi, 1, MPIOp.SUM, 0);

if (myid == 0) {
    OUT.println("  pi is approximately: ","%18.16f"(pi[0]),
                " Error is: ","%18.16f"(Math.fabs(pi[0]-PI25DT)));
}