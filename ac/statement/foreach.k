/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StatementForeach" {
	int c = 0;
	range = [0, 1, 2, 3, 4, 5];
	c = 0;
	foreach(int x in range) {
		print x;
		assert x == c;
		c++;
	}
}

assure "StatementForeach:local" {
	int x, c = 0;
	range = [0, 1, 2, 3, 4, 5];
	c = 0;
	foreach(x in range) {
		print x;
		assert x == c;
		c++;
	}
}

assure "StatementForeach:inference" {
	int c = 0;
	range = [0, 1, 2, 3, 4, 5];
	c = 0;
	foreach(x in range) {
		print x;
		assert x == c;
		c++;
	}
}

int x; // global

assure "StatementForeach:global" {
	int c = 0;
	range = [0, 1, 2, 3, 4, 5];
	c = 0;
	foreach(x in range) {
		print x;
		assert x == c;
		c++;
	}
}
