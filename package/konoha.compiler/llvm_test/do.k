int f() {
    int i = 0;
    do {
        int j = 0;
        do {
            i++;
            j++;
        } while (j < 20);
    } while(i < 10);
    return i;
}
