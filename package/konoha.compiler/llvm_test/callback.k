int callback() {
    return 1;
}
int f(Func<void=>Int> callback) {
    return callback();
}
void main(String[] args) {
    OUT.println(f(callback));
}
