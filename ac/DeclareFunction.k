/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

function f(int n) {
	return n + 1;
}

int c = 0;
function g() {
	c++;
	print c;
}

assure "DeclareFunction" {
	assert f(0) == 1;
	g();
	assert c == 1;
}

