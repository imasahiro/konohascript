/*
 * The Great Computer Language Shootout
 * http://shootout.alioth.debian.org/
 *
 */

N=12;
include "_bench.k";

int nsieve(int m, boolean[] isPrime)
{
    for (int i=2; i <= m; i++) {
        isPrime[i] = true;
    }
    int count = 0;

    for (int i=2; i <= m; i++) {
        if (isPrime[i]) {
            for (int k=i+i; k <= m; k+=i) {
                isPrime[k] = false;
            }
            count++;
        }
    }
    return count;
}

String padNumber(int number, int fieldLen) {
    String s = "" + number;
    int numSpaces = fieldLen - s.size;

    for (int i = 0; i < numSpaces; i++) {
        s = " " + s;
    }
    return s;
}

class NsieveBench extends BenchMarkTask {
    NsieveBench() {
        this.name = "nsieve12";
    }
    @Override void run() {
        int n = N;
        int m = (1<<n)*10000;
        boolean[] flags = new boolean[m+1];

        System.out.println("Primes up to " + padNumber(m, 8) + " " + padNumber(nsieve(m,flags), 8));
        m = (1<<(n-1))*10000;
        System.out.println("Primes up to " + padNumber(m, 8) + " " + padNumber(nsieve(m,flags), 8));
        m = (1<<(n-2))*10000;
        System.out.println("Primes up to " + padNumber(m, 8) + " " + padNumber(nsieve(m,flags), 8));
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new NsieveBench());
    bm.run();
}
