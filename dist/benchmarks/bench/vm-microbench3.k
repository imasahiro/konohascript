/*
 * konoha microbench by kimio kuramitsu
 */

using konoha.math.*;
include "_bench.k";
N=100_000_000;

int testSimpleLoop() {
    int i;
    for(i = 0; i < N; i++) {
    }
    return i;
}

int testLocalVariable() {
    y = 0;
    for(i = 0; i < N; i++) {
        y = i;
    }
    return y;
}

global_x = 0;
global_y = 0;
global_z = 0;

int testGlobalVariable() {
    int j;
    for(i = 0; i < N; i++) {
        global_y = i;
        i = global_x + i + global_x;
    }
    return global_y;
}

String testStringAssignment() {
    s = "";
    for(i = 0; i < N; i++) {
        s = "A";
    }
    return s;
}

int testIntegerOperation() {
    y = 0;
    for(i = 0; i < N; i++) {
        y += 1;
    }
    return y;
}

float testFloatOperation() {
    f = 0.0;
    for(i = 0; i < N; i++) {
        f += 0.1;
    }
    return f;
}

void func0() {}

int testFunctionCall() {
    i=0;
    for(i = 0; i < N; i++) {
        func0();
    }
    return i;
}

int func1() { return 1; }

int testFunctionReturn() {
    res = 0;
    for(i = 0; i< N; i++) {
        res = func1();
    }
    return res;
}

int testMathFabs() {
    int i;
    for(i = 0; i< N; i++) {
        Math.fabs(-1.0);
    }
    return i;
}

int testCallFunctionObject() {
    int i;
    f = func0;
    for(i = 0; i< N; i++) {
        f();
    }
    return i;
}

int fibo(int n) {
    if(n < 3) return 1;
    return fibo(n-1) + fibo(n-2);
}

//

class Dim {
    int x;
    int y;
    int z;
    void f() {
    }
}

int testObjectCreation() {
    int i;
    for(i = 0; i < N; i++) {
        d = new Dim();
    }
    return i;
}

Dim testFieldVariable() {
    d = new Dim();
    for(i = 0; i < N; i++) {
        d.y = 1;
    }
    return d;
}

int testMethodCall() {
    int i;
    d = new Dim();
    for(i = 0; i < N; i++) {
        d.f();
    }
    return i;
}


class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "SimpleLoop";
    }
    @Override void run() {
        testSimpleLoop();
    }
}
class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "LocalVariable";
    }
    @Override void run() {
        testLocalVariable();
    }
}
class Bench3 extends BenchMarkTask {
    Bench3() {
        this.name = "GlobalVariable";
    }
    @Override void run() {
        testGlobalVariable();
    }
}
class Bench4 extends BenchMarkTask {
    Bench4() {
        this.name = "StringAssignment";
    }
    @Override void run() {
        testStringAssignment();
    }
}
class Bench5 extends BenchMarkTask {
    Bench5() {
        this.name = "IntegerOperation";
    }
    @Override void run() {
        testIntegerOperation();
    }
}
class Bench6 extends BenchMarkTask {
    Bench6() {
        this.name = "FloatOperation";
    }
    @Override void run() {
        testFloatOperation();
    }
}
class Bench7 extends BenchMarkTask {
    Bench7() {
        this.name = "FunctionCall";
    }
    @Override void run() {
        testFunctionCall();
    }
}
class Bench8 extends BenchMarkTask {
    Bench8() {
        this.name = "FunctionReturn";
    }
    @Override void run() {
        testFunctionReturn();
    }
}
class Bench9 extends BenchMarkTask {
    Bench9() {
        this.name = "NativeFunction";
    }
    @Override void run() {
        testMathFabs();
    }
}
class Bench10 extends BenchMarkTask {
    Bench10() {
        this.name = "CallFunctionObject";
    }
    @Override void run() {
        testCallFunctionObject();
    }
}
class Bench11 extends BenchMarkTask {
    Bench11() {
        this.name = "ObjectCreation";
    }
    @Override void run() {
        testObjectCreation();
    }
}
class Bench12 extends BenchMarkTask {
    Bench12() {
        this.name = "FieldVariable";
    }
    @Override void run() {
        testFieldVariable();
    }
}
class Bench13 extends BenchMarkTask {
    Bench13() {
        this.name = "MethodCall";
    }
    @Override void run() {
        testMethodCall();
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.addTask(new Bench2());
    bm.addTask(new Bench3());
    bm.addTask(new Bench4());
    bm.addTask(new Bench5());
    bm.addTask(new Bench6());
    bm.addTask(new Bench7());
    bm.addTask(new Bench8());
    bm.addTask(new Bench9());
    bm.addTask(new Bench10());
    bm.addTask(new Bench11());
    bm.addTask(new Bench12());
    bm.addTask(new Bench13());
    bm.run();

}
