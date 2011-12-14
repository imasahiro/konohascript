/*
 * code eval
 */
using konoha.compiler.*;
N=1000;

class A {}
TEMPLATE = """
boolean A.test{{n}} (boolean b1, boolean b2) {
    return b1 == b2;
}
""";

boolean A.test9999(boolean b1, boolean b2);
void main(String[] args) {
    for (int i=0; i < N; i++) {
        eval(TEMPLATE.replace("{{n}}", (to String)i));
    }
    OUT.println(A.test9999(true, true) == true);
}

