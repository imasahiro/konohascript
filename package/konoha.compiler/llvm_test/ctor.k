class A {
    Int x;
    A(int n) {
        OUT.println("A");
        this.x = n;
    }
}
class B {
    A x;
    B(A a) {
        OUT.println("B");
        this.x = a;
    }
}
class C {
    A[] a;
    B[] b;
    C() {
        a = new A[100];
        a[0] = new A(100);
    }
}
void main (String[] args) {
    c = new C();
    OUT.println(c.a.isNull() == false);
    OUT.println(c.a.size == 100);
    OUT.println(c.a[0]);
}
