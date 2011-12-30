class A {
    int x;
}
class B extends A {
    String v = "hello";
    void f() {
        OUT.println("ok"+v);
    }
}
void main (String[] args) {
    A a = new B();
    B b = (B) a;
    OUT.println(b);
    b.f();
}
