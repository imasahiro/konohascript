/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f() { // comment
	/* comment */
	return 1;
}

assure "UnitTest:Comment" {
	assert f() == 1;
}

