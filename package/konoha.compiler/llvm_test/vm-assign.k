/*
 * field access
 */
using konoha.compiler.*;
N=10000;

class A {
    Int     a;
    Float   b;
    boolean c;
    String  d;
    Object  e;
    A() {
        a = 10;
        b = 10.0;
        c = true;
        d = "10";
        e = new OutputStream();
    }
}
void test1() {
    A a = new A();
    for (int i=0; i < N; i++) {
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
        a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2; a.a=2;
    }
}
void test2() {
    A a = new A();
    for (int i=0; i < N; i++) {
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
        a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1; a.b=1;
    }
}
void test3() {
    A a = new A();
    for (int i=0; i < N; i++) {
        boolean c;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
    }
}
void test4() {
    String d;
    for (int i=0; i < N; i++) {
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
    }
}
void test5() {
    A a = new A();
    for (int i=0; i < N; i++) {
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
        a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e; a.e=a.e;
    }
}
void main (String[] args) {
    test1();
    test2();
    test3();
    test4();
    test5();
}

