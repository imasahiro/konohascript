/*
 * tarai 12 6 0
 */
int tarai(int x, int y, int z) {
    if (y >= x) {
        return y;
    } else {
        return tarai(
                tarai(x - 1, y, z),
                tarai(y - 1, z, x),
                tarai(z - 1, x, y));
    }
}

void main(String[] args) {
    OUT.println(tarai(12, 6, 0));
}

