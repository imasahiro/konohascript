using konoha.compiler.*;
int sum(Array<Int> a) {
    int res = 0;
    for (int i = 0; i < |a|; i++) {
        res += a[i];
    }
    return res;
}

void main() {
    a = [1, 2, 3, 4];
    OUT.println(sum(a));
}
