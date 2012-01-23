/*
 * access global variable
 */
include "_bench.k";
N=1_000_000;
Int     a = 10;
Float   b = 10.0;
boolean c = true;
String  d = "10";
Object  e = new OutputStream();;

class Bench1 extends BenchMarkTask {
	Bench1() {
		this.name = "global assign:int const";
	}
	@Override void run() {
		for (int i=0; i < N; i++) {
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
			a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
		}
	}
}
class Bench2 extends BenchMarkTask {
	Bench2() {
		this.name = "global assign:float const";
	}
	@Override void run() {
		for (int i=0; i < N; i++) {
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
			b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
		}
	}
}
class Bench3 extends BenchMarkTask {
	Bench3() {
		this.name = "global assign:boolean const";
	}
	@Override void run() {
		for (int i=0; i < N; i++) {
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
			c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
		}
	}
}
class Bench4 extends BenchMarkTask {
	Bench4() {
		this.name = "global assign:string const";
	}
	@Override void run() {
		for (int i=0; i < N; i++) {
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
			d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
		}
	}
}
class Bench5 extends BenchMarkTask {
	Bench5() {
		this.name = "global assign:object";
	}
	@Override void run() {
		for (int i=0; i < N; i++) {
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
			e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
		}
	}
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.addTask new Bench2();
    bm.addTask new Bench3();
    bm.addTask new Bench4();
    bm.addTask new Bench5();
    bm.run();
}
