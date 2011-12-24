int fib(int n) {
    int res;
    if (n < 3) res = 1;
    else res = fib(n-1) + fib(n-2);
    return res;
}
void main (String[] args) {
    OUT.println(fib(40));
}
