/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f(n) {
	return 0;
}

assure "FunctionInferParameter" {
	a = f(1);
	assert a == 0;
}

