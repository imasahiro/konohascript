int f(int x) {
    int ret;
    switch (x) {
        case 0:
            ret = 10;
            break;
        case 1:
            ret = 20;
            break;
        default:
            ret = 40;
            break;
    }
    return ret;
}

void main (String[] args) {
    OUT.println(f(0));
    OUT.println(f(1));
    OUT.println(f(2));
}
