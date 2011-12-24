int fib(int n) {
    int res;
    if (n < 3) res = 1;
    else res = fib(n-1) + fib(n-2);
    return res;
}
for (int i = 0; i < 11; i++) {
    OUT.println(fib(i));
}
