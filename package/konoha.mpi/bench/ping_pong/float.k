/*                  pong.c Generic Benchmark code
 *               Dave Turner - Ames Lab - July of 1994+++
 *
 *  Most Unix timers can't be trusted for very short times, so take this
 *  into account when looking at the results.  This code also only times
 *  a single message passing event for each size, so the results may vary
 *  between runs.  For more accurate measurements, grab NetPIPE from
 *  http://www.scl.ameslab.gov/ .
 */

using konoha.mpi.*;

void main (String[] args)
{
    int i, size;
    float max_rate = 0.0, min_latency = 10e6;

    MPIComm world = MPIComm.WORLD;
    nprocs = world.getSize();
    myproc = world.getRank();

    if (nprocs != 2) exit (1);
    other_proc = (myproc + 1) % 2;

    OUT.println("Hello from "+myproc+" of "+nprocs);
    world.barrier();

/* Timer accuracy test */

    t0 = MPI.getWtime();
    t1 = MPI.getWtime();

    while (t1 == t0) t1 = MPI.getWtime();

    if (myproc == 0)
        OUT.println("Timer accuracy of ~"+((t1 - t0) * 1000000)+" usecs\n");

/* Communications between nodes 
 *   - Blocking sends and recvs
 *   - No guarantee of prepost, so might pass through comm buffer
 */

    world.barrier();
    for (size = 8; size <= 1048576; size *= 2) {
        a = new float[size/8];
        b = new float[size/8];
        for (i = 0; i < size / 8; i++) {
            a[i] = (float) i;
        }
        last = size / 8 - 1;

        world.barrier();
        t0 = MPI.getWtime();
        if (myproc == 0) {

            world.send((MPIData)a, size/8, other_proc);
            world.recv((MPIData)b, size/8, other_proc);

        } else {

            world.recv((MPIData)b, size/8, other_proc);
            b[0] += 1.0;
            if (last != 0)
                b[last] += 1.0;

            world.send((MPIData)b, size/8, other_proc);

        }
        t1 = MPI.getWtime();
        time = 1.e6 * (t1 - t0);
        world.barrier();

        if ((b[0] != 1.0 || b[last] != last + 1)) {
            OUT.println("ERROR - b[0] = "+b[0]+" b["+last+"] = "+b[last]);
            exit (1);
        }
        for (i = 1; i < last - 1; i++)
            if (b[i] != (float)i)
                OUT.println("ERROR - b["+i+"] = "+b[i]);
        if (myproc == 0 && time > 0.000001) {
            OUT.println(" "+"%7d"(size)+" bytes took "+"%9.0f"(time)+" usec ("+"%8.3f"(2.0 * size / time)+" MB/sec)");
            if (2 * size / time > max_rate) max_rate = 2 * size / time;
            if (time / 2 < min_latency) min_latency = time / 2;
        } else if (myproc == 0) {
            OUT.println(" "+"%7d"(size)+" bytes took less than the timer accuracy");
        }
    }

/* Async communications
 *   - Prepost receives to guarantee bypassing the comm buffer
 */

    world.barrier();
    if (myproc == 0) OUT.println("\n  Asynchronous ping-pong\n");

    for (size = 8; size <= 1048576; size *= 2) {
        a = new float[size/8];
        b = new float[size/8];
        for (i = 0; i < size / 8; i++) {
            a[i] = (float) i;
        }
        last = size / 8 - 1;

        request = world.iRecv((MPIData)b, size/8, other_proc);
        world.barrier();
        t0 = MPI.getWtime();

        if (myproc == 0) {

            world.send((MPIData)a, size/8, other_proc);
            request.wait();

        } else {

            request.wait();

            b[0] += 1.0;
            if (last != 0)
                b[last] += 1.0;

            world.send((MPIData)b, size/8, other_proc);
        }

        t1 = MPI.getWtime();

        time = 1.e6 * (t1 - t0);
        world.barrier();

        if ((b[0] != 1.0 || b[last] != last + 1))
            OUT.println("ERROR - b[0] = "+b[0]+" b["+last+"] = "+b[last]);

        for (i = 1; i < last - 1; i++)
            if (b[i] != (float) i)
                OUT.println("ERROR - b["+i+"] = "+b[i]);
        if (myproc == 0 && time > 0.000001) {
            OUT.println(" "+"%7d"(size)+" bytes took "+"%9.0f"(time)+" usec ("+"%8.3f"(2.0 * size / time)+" MB/sec)");
            if (2 * size / time > max_rate) max_rate = 2 * size / time;
            if (time / 2 < min_latency) min_latency = time / 2;
        } else if (myproc == 0) {
            OUT.println(" "+"%7d"(size)+" bytes took less than the timer accuracy");
        }
    }

/* Bidirectional communications
 *   - Prepost receives to guarantee bypassing the comm buffer
 */

    world.barrier();
    if (myproc == 0) OUT.println("\n  Bi-directional asynchronous ping-pong\n");

    for (size = 8; size <= 1048576; size *= 2) {
        a = new float[size/8];
        b = new float[size/8];
        for (i = 0; i < size / 8; i++) {
            a[i] = (float) i;
        }
        last = size / 8 - 1;

        request_b = world.iRecv((MPIData)b, size/8, other_proc);
        request_a = world.iRecv((MPIData)a, size/8, other_proc);

        world.barrier();

        t0 = MPI.getWtime();

        world.send((MPIData)a, size/8, other_proc);
        request_b.wait();

        b[0] += 1.0;
        if (last != 0)
            b[last] += 1.0;

        world.send((MPIData)b, size/8, other_proc);
        request_a.wait();

        t1 = MPI.getWtime();
        time = 1.e6 * (t1 - t0);
        world.barrier();

        if ((a[0] != 1.0 || a[last] != last + 1))
            OUT.println("ERROR - a[0] = "+a[0]+" a["+last+"] = "+a[last]);
        for (i = 1; i < last - 1; i++)
            if (a[i] != (double) i)
                OUT.println("ERROR - a["+i+"] = "+a[i]);
        if (myproc == 0 && time > 0.000001) {
            OUT.println(" "+"%7d"(size)+" bytes took "+"%9.0f"(time)+" usec ("+"%8.3f"(2.0 * size / time)+" MB/sec)");
            if (2 * size / time > max_rate) max_rate = 2 * size / time;
            if (time / 2 < min_latency) min_latency = time / 2;
        } else if (myproc == 0) {
            OUT.println(" "+"%7d"(size)+" bytes took less than the timer accuracy");
        }
    }

    if (myproc == 0)
        OUT.println("\n Max rate = "+max_rate+" MB/sec  Min latency = "+min_latency+" usec");

}
