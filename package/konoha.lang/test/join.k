using konoha.lang.*;

void f() {
	print "hi";
}

void g() {
	print "hello";
}

fc = f.kcode;
KCode.print(fc);
gc = g.kcode;
KCode.print(gc);
newc = KCode.join(fc, gc);
KCode.print(newc);

/*
for (i = 0; i < newc.size; i++) {
	newc[i].dump();
}
*/

f.kcode = newc;
f();
