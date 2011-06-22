/* The Computer Language Benchmarks Game
   http://shootout.alioth.debian.org/
   contributed by Stefan Krause
   slightly modified by Chad Whipkey
*/

BUFFER_SIZE = 8192

class Mandelbrot {
    int size;
    OutputStream out;
    Bytes buf;
    int bufLen = 0;
    double fac;
    int shift;


    Mandelbrot(int size) {
        this.size = size;
        fac = 2.0 / size;
        out = new OutputStream("Mandelbrot.ppm");//OUT;System.out;
        shift = (size % 8 == 0) ? 0 : (8- size % 8);
        buf = new byte[BUFFER_SIZE];
    }
    void compute() {
        //out.format("P4\n%d %d\n",size,size);
        out <<< "P4" <<< EOL <<< size <<< " " <<< size <<< EOL;
        for (int y = 0; y<size; y++) {
            computeRow(y);
        }
        out.write( buf, 0, bufLen);
        out.close();
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
            } while (!(ziN + zrN > 4.0) && --i > 0);

            bits = bits << 1;
            if (i == 0) bits++;

            if (x % 8 == 7) {
                //bufLocal[bufLen++] = (int) bits;
                //print x, bits;
                bufLocal[bufLen++] = bits;
                if ( bufLen == BUFFER_SIZE) {
                    out.write(bufLocal, 0, BUFFER_SIZE);
                    bufLen = 0;
                }
                bits = 0;
            }
        }
        if (shift!=0) {
            //print shift, bufLen;
            bits = bits << shift;
            //bufLocal[bufLen++] = (int) bits;
            bufLocal[bufLen++] = bits;
            if ( bufLen == BUFFER_SIZE) {
                out.write(bufLocal, 0, BUFFER_SIZE);
                bufLen = 0;
            }
        }
    }
}

void main(String[] args) {
    int n = 16000; // 200
    if (args.size > 0) n = (int)args[0];
    new Mandelbrot(n).compute();
}

