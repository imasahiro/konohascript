/*
 * for optimizer
 */
include "_bench.k";
N=30_000_000;

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "Float+0.1-0.1";
    }
    @Override void run() {
        float f = 0.0;
        for (int i=0; i < N; i++) {
            f += 0.1; f -= 0.1;
            f += 0.1; f -= 0.1;
            f += 0.1; f -= 0.1;
            f += 0.1; f -= 0.1;
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.run();
}
