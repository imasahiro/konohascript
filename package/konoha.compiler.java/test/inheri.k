class A {
    @Virtual int f() {
			OUT.println("A.f");
			return 0;
		}
		int x;
}
class B extends A {
    @Virtual int f() {
			OUT.println("B.f");
			return 1;
		}
		int y;
}
class C extends A {
    @Virtual int f() {
			OUT.println("C.f");
			return 2;
		}
		int z;
}
class D extends C {
    @Virtual int f() {
			OUT.println("D.f");
			return 3;
		}
		int w;
}

void main() {
	A a = new A();
	A b = new B();
	A c = new C();
	A d = new D();

	a.f();
	b.f();
	c.f();
	d.f();

	A aa = new A();
	B bb = new B();
	C cc = new C();
	D dd = new D();

	aa.x = 1;
	bb.x = 2;
	bb.y = 3;
	cc.x = 4;
	cc.z = 5;
	dd.x = 6;
	dd.z = 7;
	dd.w = 8;

	OUT.println(aa.x);
	OUT.println(bb.x);
	OUT.println(bb.y);
	OUT.println(cc.x);
	OUT.println(cc.z);
	OUT.println(dd.x);
	OUT.println(dd.z);
	OUT.println(dd.w);
}

