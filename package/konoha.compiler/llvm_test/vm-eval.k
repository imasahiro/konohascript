/*
 * code eval
 */
N=10;

class A {}
TEMPLATE = """
boolean A.test{{n}} (boolean b1, boolean b2) {
    return b1 == b2;
}
""";

boolean A.test9(boolean b1, boolean b2);
void main(String[] args) {
    for (int i=0; i < N; i++) {
        eval(TEMPLATE.replace("{{n}}", (to String)i));
    }
    OUT.println(A.test9(true, true) == true);
}

