

assure "UnitTest:DeclareCStyleArray" {
	int a, b[];
	b = new int[10];
	assert a == 0;
	assert b[0] == 0;
}

