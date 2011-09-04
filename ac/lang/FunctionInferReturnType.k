/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

def f(int n) {
	return n+1;
}

def g(int n) {
	print n;
}

assure "ReturnTypeInference" {
	a = f(1);
	g(10);
	assert typeof(a) == Int;
}

