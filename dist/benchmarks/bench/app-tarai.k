/*
 * tarai 12 6 0
 */
include "_bench.k";
int tarai(int x, int y, int z) {
	if (y >= x) {
		return y;
	} else {
		return tarai(
				tarai(x - 1, y, z),
				tarai(y - 1, z, x),
				tarai(z - 1, x, y));
	}
}

class BenchTarai extends BenchMarkTask {
	BenchTarai() {
		this.name = "tarai";
	}
	@Override void run() {
		OUT.println(tarai(12, 6, 0));
	}
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new BenchTarai();
    bm.run();
}
