/*
 * code eval
 */
include "_bench.k";
N=10000;

class A {}
TEMPLATE = """
boolean A.test{{n}} (boolean b1, boolean b2) {
    return b1 == b2;
}
""";

boolean A.test9999(boolean b1, boolean b2);
class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "eval";
    }
    @Override void run() {
        for (int i=0; i < N; i++) {
            eval(TEMPLATE.replace("{{n}}", (to String)i));
        }
        OUT.println(A.test9999(true, true) == true);
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.run();
}
