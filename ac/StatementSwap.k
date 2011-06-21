/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StatementSwap" {
	b, c = 1, 2;
	assert c == 2;
	b, c = c, b;
	assert c == 1;
	assert b == 2;
}

assure "StatementSwap" {
	b, c = 1, 2;
	b, c = c, b + c;
	assert c == 2;
	assert b == 3;
}

assure "StatementSwap:Array" {
	int[] a = [0, 1];
	a[0], a[1] = a[1], a[0];
	assert a[0] == 1;
	assert a[1] == 0;
}

class P {
	int x;
	int y;
	P(x, y) {
		_x = x;
		_y = y;
	}
}

assure "StatementSwap:Field" {
	p = new P(0, 1);
	p.x, p.y = p.y, p.x
	assert p.x == 1;
	assert p.y == 0;
}
