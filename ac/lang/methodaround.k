/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int total(int n) {
	if (n == 1) return 1;
	return total(n-1)+n;
}

int c = 0;

@Around int total(int n) {
	c++;
	print n;
	return proceed();
}

assure "MethodAround" {
	n = total(2);
	assert n == 3;
	assert c == 2;
}

int total(int n) {
	if (n < 2) return n;
	return n + total(n-1);
}

@Around int total(int n) {
	if (n mod 2 == 0) return proceed(n-1);
	return proceed();
}

assure "MethodAround" {
	n = total(9);
	print n;
	assert n == 9 + 7 + 5 + 3 + 1;
}

