/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

DEBUG = true;
val = 1;
//$konoha.os

void f() {

}

assure "BuiltinFunctionDefined" {
	int n;
	assert defined(DEBUG);
	assert not defined(NDEBUG);	
	assert defined(val);
	assert not defined(nval);
	assert defined(f);
	assert not defined(nf);
	assert defined(n);
	assert not defined(nn);
}

class C {
	String name;
}

assure "BuiltinFunctionDefined:ClassField" {
	C c = new C();
	assert defined(c.name);
	assert not defined(c.nname);
}

