/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int x; // global

assure "StatementForeach" {
	int c = 0;
	range = [0, 1, 2, 3, 4, 5];
	c = 0;
	foreach(x in range) {
		print x;
		assert x == c;
		c++;
	}
	c = 0;
	foreach(y in range) {
		print y;
		assert y == c;
		c++;
	}
}

