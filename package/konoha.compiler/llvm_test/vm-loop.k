/*
 * loop
 */
N=100_000_00;
void test1() {
    int i = 0;
    while (true) {
        if (i == N) {
            break;
        }
        i = i + 1;
    }
}
void test2() {
    int i = 0;
    do {
        if (i == N) {
            break;
        }
        i = i + 1;
    } while (true);
}
void test3() {
    int i = 0;
    for (; i < N; i++) {
    }
}
A=1000;
B=100;
int f() {
    int n = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < B; k++) {
                n = n + k;
            }
        }
    }
    return n;
}
void test4() {
    OUT.println(f());
}
void main (String[] args) {
    test1();
    test2();
    test3();
    test4();
}

