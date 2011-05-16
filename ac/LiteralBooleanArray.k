
assure "UnitTest:LiteralBooleanArray" {
	a = [true, false];
	assert typeof(a) == boolean[];
	assert a[0]
	assert not a[1];
}

