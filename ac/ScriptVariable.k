/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 1;
String s;

int f() {
	s = "hi";
	print val;
	return val;
}

assure "ScriptVariable" {
	n = f();
	print n;
	assert n == 1;
	assert s == "hi";
}

