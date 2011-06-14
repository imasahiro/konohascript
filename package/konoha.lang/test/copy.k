using konoha.lang.*;

void f() {
	print "this is f";
}

fc = f.kcode;

void g() {
	print "this is g";
}

f();
g();

gc = g.kcode;

f.kcode = gc;

g.kcode = fc;

f();
g();
