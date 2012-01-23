/*
 * io write
 */
include "_bench.k";

K=1024;
M=K*K;
G=M*K;

String s(int l) {
    String ret = "";
    if(l/K == 0) {
        ret = l + "";
    } else if(l/M == 0) {
        ret = l/K + "k";
    } else if(l/G == 0) {
        ret = l/M + "m";
    } else {
        ret = l/G + "g";
    }
    return ret;

}

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "OutputStream.opSend";
    }
    @Override void run() {
        int[] len = [1*K, 2*K, 5*K, 1*M, 2*M, 5*M, 1*G];
        foreach(int n in len) {
            String f = s(n);
            OUT.println(f);
            OutputStream ous = new OutputStream("data." + f + ".txt", "w");
            for (int i=0; i < n; i++) {
                ous <<< "a";
            }
            ous.flush();
            ous.close();
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.run();
}
