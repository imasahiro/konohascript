/*
 * field access
 */
include "_bench.k";
N=1000000;

class A {
    Int a;
    A() {
        a = 10;
    }
    Int b() {
        return a;
    }
}

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "field read";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
            a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        }
    }
}
class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "field read with script defined getter";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
            a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        }
    }
}

@Expando class B {}
class Bench3 extends BenchMarkTask {
    Bench3() {
        this.name = "field read with expando";
    }
    @Override void run() {
        B b = new B();
        b.v = 100;
        for (int i=0; i < N; i++) {
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
            i++;
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.addTask new Bench3();
    bm.run();
}
