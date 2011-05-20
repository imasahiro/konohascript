/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StatementSwap" {
	int[] a = [0, 1];
	b, c = 1, 2;
	assert c == 2;
	b, c = c, b;
	assert c == 1;
	a[0],a[1] = a[1], a[0];
	assert a[0] == 1;
	assert a[1] == 0;
}

