
assure "UnitTest:LiteralBooleanArray" {
	a = [true, false ...];
	assert typeof(a) == Array<Boolean>;
	assert a[0];
	assert not a[1];
}

