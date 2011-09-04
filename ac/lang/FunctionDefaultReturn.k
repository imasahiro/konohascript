/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// Too simple. This must be imporved in the future.

int f(int n) {
	if(n==1) 2;
}

assure "FunctionDefaultReturn" {
	assert f(1) == 2;
	assert f(2) == 0;
}

