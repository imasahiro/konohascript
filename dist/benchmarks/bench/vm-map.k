/*
 * code eval
 */
include "_bench.k";

N=40000;
M=5;/* word similarity 1 <= M <= 5 */

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "map";
    }
    @Override void run() {
        Map<String, String> ma = {};
        InputStream ins = new InputStream("/usr/share/dict/words");
        String[] a = [];
        foreach (String line in ins) {
            a.add(line);
        }

        for (int i=0; i <= N*M; i=i+M) {
            if (ma.get(a[i]) == null /*always true*/) {
                ma.set(a[i], a[i+M]);
                //print "*", a[i], a[i+M];
            }
        }
        String key = a[0];
        String last = a[N*M];
        int i = 0;
        while (key != last) {
            Map<String, String> tmp = {};
            String[] a = key.split();
            foreach (String v in a) {
                tmp[v] = v;
            }
            //print key, ma[key];
            key = ma[key];
            i++;
            tmp = null;
        }
        OUT.println((ma.size == N+1)+":"+ i);
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.run();
}
