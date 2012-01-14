class A {
    int x;
    A(int x) {
        this.x = x;
    }
    void f(int v) {
        print x, v;
    }
}

void main (String[] args) {
    a = new A(10);
    f = delegate(a, f);
    f(100);
}
