using konoha.lang.*;

void f() {
	a = 1;
	if (a < 0) print "hi";
	else print "hello";
}

a = f.kcode;

for (i = 0; i < a.size; i++) {
	print a[i].jump;
	a[i].jump = i;
}

for (i = 0; i < a.size; i++) {
	print a[i].jump;
}
