using konoha.compiler.*;
void f() {
    for (l = 0; l < 10; l++) {
        if (l % 2 == 0) {
            if (l == 1) {
                l+=3;
            } else {
                l+=2;
            }
        }
    }
    return;
}
