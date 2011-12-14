using konoha.compiler.*;
class A{
    int x;
    A(int n) {
        this.x = n;
    }
}
void main() {
    A a = new A(10);
    OUT.println(a);
    return;
}
