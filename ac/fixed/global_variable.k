/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/

Int     a = 10;
Float   b = 10.0;
boolean c = true;
String  d = "10";
void f(int x, int y, int z) {
    int x = 20;
    String s = "hi";
    b=1;
}
class A {
    int i;
    void run(int x, int y, int z) {
        int x = 20;
        String s = "hi";
        i = 200;
        a = 1000;
    }
}
void f () {
    A.run();
    print a, b, c, d;
    assert a == 1000;
}
assure "global variable" {
    f();
}
