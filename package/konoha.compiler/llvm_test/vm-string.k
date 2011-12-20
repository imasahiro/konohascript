/*
 * string ops
 */
N=100000;
U=1000;
T=100;

void test1() {
    String str = "1234567890";
    String zero = "0";
    String one = "1";
    // str.size = 60;
    for (int i=0; i < T; i++) {
        String newstr = "";
        for (int j=0; j < U; j++) {
            newstr = newstr + str + zero + one;
        }
        newstr = null;
    }
}

void test2() {
    String empty10 = "          ";
    String s = empty10 + "1234567890" + empty10;
    String v = "";
    for(int i = 0; i < N; i++) {
        v = s.trim();
    }
    OUT.println(v);
}

void main (String[] args) {
    test1();
    test2();
}

