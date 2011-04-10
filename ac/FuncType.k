
assure "UnitTest:FuncType" {
	Func f;
	Func<int,int=>void> f2;
	Func<void=>int> f3;
	print f.class;
	print f2.class;
	assert f instanceof Func<void>;
	assert f2 instanceof Func<int,int>;
	f();
	f2();
	n = f3();
	assert n == 0;
}

