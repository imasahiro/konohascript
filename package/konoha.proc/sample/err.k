using konoha.proc.*;

p = new Proc(["/usr/local/bin/konoha", "_throw.k"]);

ins = p.getInputStream();
err = p.getErrorInputStream();

foreach (String s in ins) {
	print "out: " + s;
}

foreach (String s in err) {
	print "err: " + s;
}
