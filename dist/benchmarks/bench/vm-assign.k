/*
 * field access
 */
include "_bench.k";
N=1000000;

class A {
    Int     a;
    Float   b;
    boolean c;
    String  d;
    Object  e;
    A() {
        a = 10;
        b = 10.0;
        c = true;
        d = "10";
        e = new OutputStream();
    }
}
class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "field assign:int const";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
            a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        }
    }
}
class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "field assign:float const";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
            a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        }
    }
}
class Bench3 extends BenchMarkTask {
    Bench3() {
        this.name = "field assign:boolean const";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            boolean c;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
            c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        }
    }
}
class Bench4 extends BenchMarkTask {
    Bench4() {
        this.name = "field assign:string const";
    }
    @Override void run() {
        A a = new A();
        String d;
        for (int i=0; i < N; i++) {
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
            d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        }
    }
}
class Bench5 extends BenchMarkTask {
    Bench5() {
        this.name = "field assign:object";
    }
    @Override void run() {
        A a = new A();
        for (int i=0; i < N; i++) {
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
            a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.addTask new Bench3();
    bm.addTask new Bench4();
    bm.addTask new Bench5();
    bm.run();
}
