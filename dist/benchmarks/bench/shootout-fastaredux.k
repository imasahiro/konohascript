/*
 * The Computer Language Benchmarks Game
 * http://shootout.alioth.debian.org/
 *
 */

LINE_LENGTH = 60;
OUT_BUFFER_SIZE = 256*1024;
LOOKUP_SIZE = 4*1024;
LOOKUP_SCALE = (LOOKUP_SIZE - 1) * 1.0;
N = 25000000;

include "_bench.k";

int min(int n, int m) {
    if (n < m) {
        return n;
    }
    return m;
}

void arraycopy(byte[] src, int srcPos, byte[] dest, int destPos, int length) {
    for (int i=0; i < length; i++) {
        dest[i+destPos] = src[i + srcPos];
    }
}
class Freq {
    int c;
    double p;
    Freq(int cc, double pp) {c = cc;p = pp;}
}

ALU = "GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG" + 
 "GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA" +
 "CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT" +
 "ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA" +
 "GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG" +
 "AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC" +
 "AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";
Freq[] iub = [
    new Freq('a', 0.27),
    new Freq('c', 0.12),
    new Freq('g', 0.12),
    new Freq('t', 0.27),
    new Freq('B', 0.02),
    new Freq('D', 0.02),
    new Freq('H', 0.02),
    new Freq('K', 0.02),
    new Freq('M', 0.02),
    new Freq('N', 0.02),
    new Freq('R', 0.02),
    new Freq('S', 0.02),
    new Freq('V', 0.02),
    new Freq('W', 0.02),
    new Freq('Y', 0.02)];
Freq[] homosapiens = [
    new Freq('a', 0.3029549426680),
    new Freq('c', 0.1979883004921),
    new Freq('g', 0.1975473066391),
    new Freq('t', 0.3015094502008)];

IM = 139968;
IA = 3877;
IC = 29573;
SCALE = LOOKUP_SCALE / IM;

class Random {
    int last;
    Random() {
        last = 42;
    }
    double next() {
        last = (last * IA + IC) % IM;
        return SCALE * last;
    }
}

class Io {
    byte[] buf;
    int lim;
    int ct;
    OutputStream stream;
    Io(OutputStream writer) {
        buf = new byte[OUT_BUFFER_SIZE];
        lim = OUT_BUFFER_SIZE - 2 * LINE_LENGTH - 1;
        ct = 0;
        stream = writer;
    }
    void checkFlush() {
        if (ct >= lim) {
            stream.write(buf, 0, ct);
            ct = 0;
        }
    }

    void close() {
        stream.write(buf, 0, ct);ct = 0;
        //stream.close();
    }
}


class Fasta {
    @static void sumAndScale(Freq[] a) {
        double p = 0;
        for (int i = 0; i < a.size; i++)
            a[i].p = (p += a[i].p) * LOOKUP_SCALE;
        a[a.size - 1].p = LOOKUP_SCALE;
    }
}
Random rand = new Random();
class RandomFasta {
    Freq[] lookup;
    Io ous;
    RandomFasta(OutputStream writer) {
        lookup = new Freq[LOOKUP_SIZE];
        ous    = new Io(writer);
    }
    void makeLookup(Freq[] a) {
        int i, j;
        for (; i < LOOKUP_SIZE; i++) {
            while (a[j].p < i) j++;
            lookup[i] = a[j];
        }
    }

    void addLine(int bytes) {
        ous.checkFlush();
        int lct=ous.ct;
        while(lct<ous.ct+bytes){
            float r = rand.next();
            int  ai = (int) r;
            while (lookup[ai].p < r) { ai++; }
            ous.buf[lct] = lookup[ai].c;
            lct++;
        }
        ous.buf[lct] = '\n';
        lct++;
        ous.ct=lct;
    }

    void make(String desc, Freq[] a, int n) {
        int nn = n;
        makeLookup(a);
        arraycopy(desc.encode(), 0, ous.buf, ous.ct, desc.size);
        ous.ct+=desc.size;

        while (nn > 0) {
            int bytes = min(LINE_LENGTH, nn);
            addLine(bytes);
            nn -= bytes;
        }
        ous.close();
    }
}

class RepeatFasta {
    Io ous;
    RepeatFasta(OutputStream writer) {
        ous = new (writer);
    }

    void make(String desc, byte[] alu, int n) {
        int nn = n;
        arraycopy(desc.encode(), 0, ous.buf, ous.ct, desc.size);
        ous.ct += desc.size;

        byte[] buf = new byte[alu.size + LINE_LENGTH];
        for (int i = 0; i < buf.size; i += alu.size) {
            int min = min(alu.size, buf.size - i);
            arraycopy(alu, 0, buf, i, min);
        }
        int pos = 0;
        while (nn > 0) {
            int bytes = min(LINE_LENGTH, nn);
            ous.checkFlush();
            arraycopy(buf, pos, ous.buf, ous.ct, bytes);
            ous.ct += bytes;

            ous.buf[ous.ct] = '\n';
            ous.ct += 1;
            pos = (pos + bytes) % alu.size;
            nn -= bytes;
        }
        ous.close();
    }
}


class Fastaredux extends BenchMarkTask {
    Fastaredux() {
        this.name = "Fastaredux";
    }
    @Override void run() {
        int n = N;
        Fasta.sumAndScale(iub);
        Fasta.sumAndScale(homosapiens);
        OutputStream ous = new OutputStream("tmp.fastaredux");
        RepeatFasta f1 = new RepeatFasta(ous);
        f1.make(">ONE Homo sapiens alu\n", ALU.encode(), n * 2);
        RandomFasta f2 = new RandomFasta(ous);
        f2.make(">TWO IUB ambiguity codes\n", iub, n * 3);
        RandomFasta f3 = new RandomFasta(ous);
        f3.make(">THREE Homo sapiens frequency\n", homosapiens, n * 5);
        ous.flush();
        ous.close();
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Fastaredux());
    bm.run();
}
