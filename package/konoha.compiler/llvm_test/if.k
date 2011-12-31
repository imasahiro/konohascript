int f(int j) {
    int i = 0;
    for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
            i++;
        } 
        if (j == 0) {
            i = 1;
        }
    }
    return i;
}
int g(int x) {
    if (x >= 10) {
        if (x > 100) {
            return 10;
        } else {
            return 20;
        }
    } else {
        return 30;
    }
}
void main (String[] args) {
    OUT.println(g(1000));
    OUT.println(g(10));
    OUT.println(g(1));
}
