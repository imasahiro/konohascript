/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// Konoha one liner 

f = function(int n) {
	return n+1;
}

function genf() {
	return function(int n) {
		return n+1;
	}
}

g = genf();

assure "Function" {
	h = function() {
		return 0;
	}
	assert f(0) == 1;
	assert g(0) == 1;
	assert h() == 0;
}
