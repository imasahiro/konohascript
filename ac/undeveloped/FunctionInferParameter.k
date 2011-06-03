/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f(n) {
	if(n == 1) return 1;
	return f(n-1)*n;
}

assure "FunctionInferParameter" {
	a = f(1);
	assert a == 1;
	assert f(2) == 2;
}

