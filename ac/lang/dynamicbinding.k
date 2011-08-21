/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

class C {
	@Virtual int f() {
		return 1;
	}
	@Virtual int g() {
		return 1;
	}
}

class D extends C {
	@Override int f() {
		return 2;
	}
	@Override @Virtual int g() {
		return 2;
	}
}

class E extends D {
	@Override int f() {
		return 3;
	}
	@Override int g() {
		return 3;
	}
}

assure "DynamicBinding" {
	C c = new C();
	D d = new D();
	E e = new E();
	assert c.f() + 1 == d.f();
	assert c.g() + 1 == d.g();
	assert e.f() == 2;
	assert e.g() == 3;
}

