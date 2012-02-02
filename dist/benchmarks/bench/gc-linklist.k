/*
 * create link list
 */
include "_bench.k";
class A {
    A next;
}
COUNT = 10;
N = 100000;
LIST_SIZE = 100;

class BenchGC extends BenchMarkTask {
    BenchGC() {
        this.name = "link-list";
    }
    @Override void run() {
        A head = new A();
        for (int i=0; i < COUNT; i++) {
            for (int j=0; j < N; j++) {
                /* short live objects */
                for (int k=0; k < LIST_SIZE; k++) { new A(); }
                /* create link list */
                A a = new A();
                head.next = a;
                head = a;
            }
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new BenchGC();
    bm.run();
}
