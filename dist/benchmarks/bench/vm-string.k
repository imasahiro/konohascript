/*
 * string ops
 */
N=10000000;
U=1000;
T=100;
include "_bench.k";

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "String.concat";
    }
    @Override void run() {
        String str = "1234567890";
        String zero = "0";
        String one = "1";
        // str.size = 60;
        for (int i=0; i < T; i++) {
            String newstr = "";
            for (int j=0; j < U; j++) {
                newstr = newstr + str + zero + one;
            }
            newstr = null;
        }
    }
}
class Bench2 extends BenchMarkTask {
    Bench2() {
        this.name = "String.trim";
    }
    @Override void run() {
        String empty10 = "          ";
        String s = empty10 + "1234567890" + empty10;
        String v = "";
        for(int i = 0; i < N; i++) {
            v = s.trim();
        }
        OUT.println(v);
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.run();
}
