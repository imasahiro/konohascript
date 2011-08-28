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
String g() {
	s = "hi";
	print s;
	return s;
}


assure "ScriptVariable" {
	n = f();
	print n;
	assert n == 1;
	assert s == "hi";
	assert s == g();
}

String gstr = "";
class A {
	void f() {
		assert gstr == "abcd";
	}

	void g() {
		assert gstr == "abcd";
	}
}

//assure "BUG:GlobalScopeVariable in ClassMethod" {
//	gstr = "abcd";
//	A.g();
//	A.f();
//}

