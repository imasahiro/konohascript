using konoha.proc.*;

p = new Proc(["/usr/local/bin/konoha", "_printenv.k"], {"HOGE": "huga", "FOO": "bar"});

ins = p.getInputStream();

foreach (String s in ins) {
	print "out: " + s;
}
