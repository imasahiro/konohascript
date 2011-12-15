using konoha.compiler.*;
void main(int n) {
	while(n < 10) {
		while (n < 5) {
			n++;
		}
		n++;
		if (n == 7) continue;
	}
	OUT.println(n);
}
