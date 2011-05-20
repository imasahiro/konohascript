/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StatementAssignment" {
	int[] a = [0];
	int n = 1;
	n += 1;
	assert n == 2;
	a[0] = 1;
	assert a[0] == 1;
	a[0] += 1;
	assert a[0] == 2;
}

