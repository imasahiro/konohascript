using konoha.lang.*;

void f() {
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	print "a=" + a;
	print "b=" + b;
	print "c=" + c;
	print "d=" + d;
}

a = f.kcode;

for (i = 0; i < a.size; i++) {
	a[i].dump();
	b = a[i].deflist;
	OUT <<< "[";
	for (j = 0; j < b.size; j++) {
		OUT <<< b[j] + ",";
	}
	OUT <<< "] [";
	b = a[i].uselist;
	for (j = 0; j < b.size; j++) {
		OUT <<< b[j] + ",";
	}
	OUT <<< "]" <<< EOL;
}
