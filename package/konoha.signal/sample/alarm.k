using konoha.signal.*;

void handler(int n) {
	throw new Script!!("signum=" + n);
}

Signal.signal(Signal.SIGALRM, handler);
Signal.alarm(1);

try {
	while (1) {
		print "hi";
	}
} catch (Exception!! e) {
	print e;
}
