/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "ParserNoSemicolon" {
	int a
	int b
	assert a == 0
	assert b == 0
}

assure "ParserNoSemicolon" {
	int[] a = [1,2]
	int[] b = []
	assert a != b
}
