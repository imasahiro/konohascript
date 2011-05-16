/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

class C {
	String s1 = "naruto";
	String s0;
	int n1 = 100;
	int n0;
	float f1 = 100.0;
	float f0;
}

assure "DeclareClassField" {
	C c = new C();
	print c.s1, c.n1, c.f1;
	print c.s0, c.n0, c.f0;
	assert c.s1 == "naruto";
	assert c.s0 == null;
	assert c.n1 == 100;
	assert c.n0 == 0;
	assert c.f1 == 100.0;
	assert c.f0 == 0.0;
}


