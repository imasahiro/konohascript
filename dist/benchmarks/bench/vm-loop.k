/*
 * loop
 */
N=100_000_000;
include "_bench.k";
class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "while-true-break loop";
    }
    @Override void run() {
        int i = 0;
        while (true) {
            if (i == N) {
                break;
            }
            i = i + 1;
        }
    }
}

class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "do-while-true-break loop";
    }
    @Override void run() {
        int i = 0;
        do {
            if (i == N) {
                break;
            }
            i = i + 1;
        } while (true);
    }
}
class Bench3 extends BenchMarkTask {
    Bench3() {
        this.name = "for-loop";
    }
    @Override void run() {
        int i = 0;
        for (; i < N; i++) {
        }
    }
}
A=1000;
B=100;
int f() {
    int n = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < B; k++) {
                n = n + k;
            }
        }
    }
    return n;
}
class Bench4 extends BenchMarkTask {
    Bench4() {
        this.name = "nested-loop";
    }
    @Override void run() {
        f();
    }
}
void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.addTask new Bench3();
    bm.addTask new Bench4();
    bm.run();
}
