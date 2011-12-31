class A {
    @Virtual void f() {
        OUT.println("hello");
    }
}

class B extends A {
    @Override void f() {
        OUT.println("world");
    }
}

void main (String[] args) {
    A a = new A();
    a.f();
    A b = new B();
    b.f();
}

