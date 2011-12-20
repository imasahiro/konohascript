int f(int n) {
	int res = 0;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			res += j * i;
		}
		if (j == 5) {
			continue;
		}
	}
	return res;
}
