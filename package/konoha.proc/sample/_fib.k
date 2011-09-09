int fib(int n) {
	if (n < 3) return 1;
	return fib(n - 1) + fib(n - 2);
}

for (int i = 1; i <= 36; i++) {
	print "fib(" + i + ")=" + fib(i);
}
