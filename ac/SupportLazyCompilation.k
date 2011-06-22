/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

function fact(n) {
	if(n == 1) return 1;
	return fact(n-1) * n;
}

assure "SupportLazyCompilation" {
	int n = fact(3);
	assert n == 6;
}

