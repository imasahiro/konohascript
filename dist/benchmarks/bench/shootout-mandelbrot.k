/*
 * The Computer Language Benchmarks Game
 * http://shootout.alioth.debian.org/
 *
 */

BUFFER_SIZE = 8192;
include "_bench.k";

class Mandelbrot {
    int size;
    OutputStream ous;
    Bytes buf;
    int bufLen = 0;
    double fac;
    int shift;

    Mandelbrot(int size) {
        this.size = size;
        fac = 2.0 / size;
        ous = new OutputStream("Mandelbrot.ppm");
        if (size % 8 == 0) {
            shift = 0;
        } else {
            shift = 8 - (size % 8);
        }
        buf = new byte[BUFFER_SIZE];
    }
    void compute() {
        ous.println("P4" + EOL + size + " " + size);
        for (int y = 0; y<size; y++) {
            computeRow(y);
        }
        ous.write( buf, 0, bufLen);
        ous.close();
    }

    void computeRow(int y) {
        int bits = 0;

        double ci = (y*fac - 1.0);
        Bytes bufLocal = buf;
        for (int x = 0; x<size;x++) {
            double zr = 0.0;
            double zi = 0.0;
            double cr = (x*fac - 1.5);
            int i = 50;
            double zrN = 0;
            double ziN = 0;
            do {
                zi  = 2.0 * zr * zi + ci;
                zr  = zrN - ziN + cr;
                ziN = zi * zi;
                zrN = zr * zr;
                if (ziN + zrN > 4.0) {
                    break;
                }
                i = i - 1;
            } while (i > 0);

            bits = bits << 1;
            if (i == 0) bits++;

            if (x % 8 == 7) {
                bufLocal[bufLen] = bits;
                bufLen += 1;
                if ( bufLen == BUFFER_SIZE) {
                    ous.write(bufLocal, 0, BUFFER_SIZE);
                    bufLen = 0;
                }
                bits = 0;
            }
        }
        if (shift!=0) {
            bits = bits << shift;
            bufLocal[bufLen] = bits;
            bufLen += 1;
            if ( bufLen == BUFFER_SIZE) {
                ous.write(bufLocal, 0, BUFFER_SIZE);
                bufLen = 0;
            }
        }
    }
}

class MandelbrotBench extends BenchMarkTask {
    MandelbrotBench() {
        this.name = "Mandelbrot";
    }
    @Override void run() {
        int n = 16000;
        new Mandelbrot(n).compute();
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new MandelbrotBench());
    bm.run();
}
