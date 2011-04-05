
assure "UnitTest:LiteralArray" {
	a = [1, 1.0, ...];
	b = [];
	assert typeof(a) == Array;
	assert typeof(b) == Array;
	assert a[0] instanceof Int;
	assert a[1] instanceof Float;
	
}

