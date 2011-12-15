using konoha.compiler.*;
class A {
    String a;
    Int b;
    Float c;
    String d;
    A(String a, Int b, Float c, String d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
}
void main (String[] args) {
    A a = new A("10", 20, 30.0, "40");
    OUT.println(a);
    OUT.println(a.a);
    OUT.println(a.b);
    OUT.println(a.c);
}
