/*
 * for optimizer
 */
N=30_000_000;
void run1 () {
    int v = 0;
    for (int i=0; i < N; i++) {
        v += 2; v -= 1;
        v += 2; v -= 1;
        v += 2; v -= 1;
        v += 2; v -= 1;
    }
    OUT.println(v);
}
void run2() {
    float f = 0.0;
    for (int i=0; i < N; i++) {
        f += 0.2; f -= 0.1;
        f += 0.2; f -= 0.1;
        f += 0.2; f -= 0.1;
        f += 0.2; f -= 0.1;
    }
    OUT.println(f);
}
void main (String[] args) {
    run1();
    run2();
}

