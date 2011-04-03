
int f() { // comment
	/* comment */
	return 1;
}

assure "UnitTest:Comment" {
	assert f() == 1;
}

