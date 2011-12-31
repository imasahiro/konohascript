class A {
    double d = 10.0;
    double f(double v) {
        return d * v;
    }
}
void main (String[] args) {
    A a = new A();
    double v = - a.f(10.0);
    OUT.println(v);

}
