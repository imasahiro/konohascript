/*
 * field access
 */
using konoha.compiler.*;
N=100000;

class A {
    Int a;
    A() {
        a = 10;
    }
    Int b() {
        return a;
    }
}

void test1() {
    A a = new A();
    for (int i=0; i < N; i++) {
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
        a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a; a.a;
    }
}
void test2() {
    A a = new A();
    for (int i=0; i < N; i++) {
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
        a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b(); a.b();
    }
}

@Expando class B {}
void test3() {
    B b = new B();
    b.v = 100;
    for (int i=0; i < N; i++) {
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v; b.v;
        i++;
    }
}
void main (String[] args) {
    test1();
    test2();
    test3();
}

