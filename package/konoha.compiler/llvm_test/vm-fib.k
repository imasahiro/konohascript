/*
 * fibonacci 40
 */
N = 10;

int fibo(int n) {
    if (n < 3) {
        return 1;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

dynamic dyn_fibo(dynamic n) {
    if (n < 3) {
        return 1;
    }
    return dyn_fibo(n-1) + dyn_fibo(n-2);
}

float float_fibo(float n) {
    if (n < 3) {
        return 1.0;
    }
    return float_fibo(n-1)+float_fibo(n-2);
}

String string_fibo(int n) {
    if (n < 3) {
        return "x";
    }
    return string_fibo(n-1) + string_fibo(n-2);
}

void test1() {
    OUT.println("fibo :int="+ fibo(N));
}
void test2() {
    OUT.println("fibo :float="+ float_fibo(N));
}
void test3() {
    OUT.println("fibo :string="+ string_fibo(N).size);
}
void test4() {
    //TODO
    //OUT.println("fibo :dyn="+ dyn_fibo(N));
}
void main (String[] args) {
    test1();
    test2();
    test3();
    test4();
}
