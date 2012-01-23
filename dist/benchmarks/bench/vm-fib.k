/*
 * fibonacci 40
 */
include "_bench.k";
N = 40;

int fibo(int n) {
    if (n < 3) {
        return 1;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

//dynamic dyn_fibo(dynamic n) {
//    if (n < 3) {
//        return 1;
//    }
//    return dyn_fibo(n-1) + dyn_fibo(n-2);
//}

float float_fibo(float n) {
    if (n < 3) {
        return 1.0;
    }
    return float_fibo(n-1)+float_fibo(n-2);
}

String string_fibo(int n) {
    if (n < 3) {
        return "x";
    }
    return string_fibo(n-1) + string_fibo(n-2);
}

class FiboInt extends BenchMarkTask {
    FiboInt() {
        this.name = "fibo:int"+N;
    }
    @Override void run() {
        OUT.println("fibo :"+ fibo(N));
    }
}
class FiboFloat extends BenchMarkTask {
    FiboFloat() {
        this.name = "fibo:float"+N;
    }
    @Override void run() {
        OUT.println("fibo :"+ float_fibo(N));
    }
}
class FiboString extends BenchMarkTask {
    FiboString() {
        this.name = "fibo:string"+N;
    }
    @Override void run() {
        OUT.println("fibo :"+ string_fibo(N).size);
    }
}
//class FiboDyn extends BenchMarkTask {
//    FiboDyn() {
//        this.name = "fibo:dynamic"+N;
//    }
//    @Override void run() {
//        OUT.println("fibo :"+ dyn_fibo(N));
//    }
//}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new FiboInt();
    bm.addTask new FiboFloat();
    bm.addTask new FiboString();
    //bm.addTask new FiboDyn();
    bm.run();
}
