using konoha.thread.*;

int fib(int n) {
	if(n < 3) return 1;
	else return fib(n-1) + fib(n-2);
}

void main() {
	for(i = 30; i <= 40; i++) {
		Thread.spawn(function(int n){
			print "fib(" + n + ") = " + fib(n);
		}, [i]);
	}
	print "spawn finish";
}

