using konoha.compiler.*;
N = 10;
int f() {
    String s = "123";
    return (int)s;
}
int g() {
    double d = 1.0;
    double e = 1.0;
    return (int) d + (int) e;
}

double h() {
    int i = 1;
    int j = 2;
    return (double)i + (double)j + (double)N;
}

boolean i() {
    int i = 0;
    int j = 1;
    return i == j;
}

double j() {
    double d = 1.9;
    double e = 2.0;
    return d/e;
}
