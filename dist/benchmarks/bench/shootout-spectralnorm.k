/*
 * The Computer Language Benchmarks Game
 * http://shootout.alioth.debian.org/
 *
 */

using konoha.math.*;
include "_bench.k";
N=5500;

class Spectralnorm {
    /* return element i,j of infinite matrix A */
    double a(int i, int j){
        return 1.0/((i+j)*(i+j+1)/2 +i+1);
    }

    /* multiply vector v by matrix A */
    void multiplyAv(int n, double[] v, double[] av){
        for (int i=0; i<n; i++){
            av[i] = 0;
            for (int j=0; j<n; j++) av[i] += a(i,j)*v[j];
        }
    }

    /* multiply vector v by matrix A transposed */
    void multiplyAtv(int n, double[] v, double[] atv){
        for (int i=0;i<n;i++){
            atv[i] = 0;
            for (int j=0; j<n; j++) atv[i] += a(j,i)*v[j];
        }
    }

    /* multiply vector v by matrix A and then by matrix A transposed */
    void multiplyAtAv(int n, double[] v, double[] atAv){
        double[] u = new double[n];
        multiplyAv(n,v,u);
        multiplyAtv(n,u,atAv);
    }

    double approximate(int n) {
        // create unit vector
        double[] u = new double[n];
        for (int i=0; i<n; i++) u[i] =  1;

        // 20 steps of the power method
        double[] v = new double[n];
        for (int i=0; i<n; i++) v[i] = 0;

        for (int i=0; i<10; i++) {
            multiplyAtAv(n,u,v);
            multiplyAtAv(n,v,u);
        }

        // B=AtA         A multiplied by A transposed
        // v.Bv /(v.v)   eigenvalue of v
        double vBv = 0, vv = 0;
        for (int i=0; i<n; i++) {
            vBv += u[i]*v[i];
            vv  += v[i]*v[i];
        }
        return Math.sqrt(vBv/vv);
    }
}

class SpectralnormBench extends BenchMarkTask {
    SpectralnormBench() {
        this.name = "Spectralnorm";
    }
    @Override void run() {
        int n = N;
        float res = new Spectralnorm().approximate(n);
        System.out.println(res.format("%0.9f"));
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new SpectralnormBench());
    bm.run();
}
