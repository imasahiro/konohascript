/*
 * object inheritance
 */
N=1_000_00;

class A {
    @Virtual int f() { return 0; }
}
class B extends A {
    @Override int f() { return 1; }
}
class C extends A {
    @Virtual @Override int f() { return 2; }
}
class D extends C {
    @Override int f() { return 3; }
}

void test1() {
    A a = new A();
    A b = new B();
    A c = new C();
    A d = new D();
    for (int i=0; i < N; i++) {
        a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
        c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
    }
}
void test2() {
    A a = new A();
    A b = new B();
    A c = new C();
    A d = new D();
    for (int i=0; i < N; i++) {
        a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
        c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
    }
}
void test3() {
    A a = new A();
    A b = new B();
    A c = new C();
    A d = new D();
    for (int i=0; i < N; i++) {
        a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f();
        c.f(); d.f(); a.f(); b.f(); c.f(); d.f(); a.f(); b.f(); c.f(); d.f();
    }
}
void test4() {
    A[] array = new A[20];
    for (int i=0; i < 20; i++) {
        if (i % 4 == 0)
            array[i] = new A();
        else if (i % 4 == 1)
            array[i] = new B();
        else if (i % 4 == 2)
            array[i] = new C();
        else if (i % 4 == 3)
            array[i] = new D();
    }
    for (int i=0; i < N; i++) {
        for (int j=0; j < 20; j++) {
            A a = array[j];
            a.f();
        }
    }
}
void main (String[] args) {
    test1();
    test2();
    test3();
    test4();
}

