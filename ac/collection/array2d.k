/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

X = 4;
Y = 3;

assure "Array2D" {
	int[] a = new int[X, Y];
	int[] b = new int[X, Y];
	int x, y;
	for(x = 0; x < X; x++) {
		y = 0;
		for(y = 0; y < Y; y++) {
			a[x, y] = X;
			b[x, y] = y;
		}
	}
	for(x = 0; x < X; x++) {
		for(y = 0; y < Y; y++) {
			assert a[x,y] == X;
			assert b[x,y] == y;
		}
	}
}

