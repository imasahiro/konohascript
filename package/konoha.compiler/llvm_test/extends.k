class A {
    Int x;
    A(int n) {
        OUT.println("A");
        this.x = n;
    }
    void f() {
        OUT.println(this.class + ".f");
    }
}
class B extends A {
    Int y;
    B(int x, int y) {
        OUT.println("B");
        this.x = x;
        this.y = y;
    }
}
void main (String[] args) {
    A.f();
    B.f();
}
