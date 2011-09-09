using konoha.proc.*;

p = new Proc(["/usr/local/bin/konoha", "_fib.k"]);
ins = p.getInputStream();

while (p.isAlive()) {
	foreach (String s in ins) {
		print s;
	}
}
