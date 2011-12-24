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
