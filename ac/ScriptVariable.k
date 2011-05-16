/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 1;

int f() {
	print val;
	return val;
}

assure "ScriptVariable" {
	n = f();
	print n;
	assert n == 1;
}

