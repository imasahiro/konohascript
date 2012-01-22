/*
 * object inheritance
 */
include "_bench.k";
N=1_000_000;

class A {
    @Virtual int f() { return 0; }
}
class B extends A {
    @Override int f() { return 1; }
}
class C extends A {
    @Virtual @Override int f() { return 2; }
}
class D extends C {
    @Override int f() { return 3; }
}

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "monomorphic";
    }
    @Override void run() {
        A a = new A();
        A b = new B();
        A c = new C();
        A d = new D();
        for (int i=0; i < N; i++) {
            a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
            c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
        }
    }
}
class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "bimorphic";
    }
    @Override void run() {
        A a = new A();
        A b = new B();
        A c = new C();
        A d = new D();
        for (int i=0; i < N; i++) {
            a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
            c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
        }
    }
}
class Bench3 extends BenchMarkTask {
    Bench3() {
        this.name = "polymorphic";
    }
    @Override void run() {
        A a = new A();
        A b = new B();
        A c = new C();
        A d = new D();
        for (int i=0; i < N; i++) {
            a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
            c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
        }
    }
}
class Bench4 extends BenchMarkTask {
    Bench4() {
        this.name = "polymorphic ver2";
    }
    @Override void run() {
        A[] array = new A[20];
        for (int i=0; i < 20; i++) {
            if (i % 4 == 0)
                array[i] = new A();
            else if (i % 4 == 1)
                array[i] = new B();
            else if (i % 4 == 2)
                array[i] = new C();
            else if (i % 4 == 3)
                array[i] = new D();
        }
        for (int i=0; i < N; i++) {
            for (int j=0; j < 20; j++) {
                A a = array[j];
                a.f();
            }
        }
    }
}

void main (String[] args) {
    BenchMark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.addTask new Bench3();
    bm.addTask new Bench4();
    bm.run();
}
