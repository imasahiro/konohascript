using konoha.lang.*;

void f() {
	i = 10;
	if (i < 3) {
		print "< 3";
	} else if (i > 3) {
		print "this is f";
	}
}

void g() { print "this is g"; }

{
	f();
	print f;
	fc = f.kcode;
	KCode.print(fc);
	print "f.klrcode";
	print fc;
	print "g.klrcode";
	gc = g.kcode;
	print gc;
	f.kcode = gc;
	g.kcode = fc;
	f.print();
	g.print();
	f();
	g();
}

//fc[1].jump = 6;

//fc.print();

/*
g.klrcode = fc;
f.klrcode = gc;

g.print();

g();
*/
