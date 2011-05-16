
assure "UnitTest:BuiltInFunction:typeof" {
	int[] a;
	float f;
	assert typeof(a) == int[];
	assert typeof(a[0]) == int;
	assert typeof(f) == Float;
}


