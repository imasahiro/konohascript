using konoha.proc.*;

p = new Proc(["/bin/ls", "-l"]);
ins = p.getInputStream();
foreach (String s in ins) {
	OUT << s << EOL;
}

print p.wait();
