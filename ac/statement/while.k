/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "StatementWhile" {
	int n = 9, c0 = 0, c1 = 0;
	while(n < 10) {
		n++;
		c0++;
	}
	do {
		n++;
		c1++;
	} while(n < 10);
	assert c0 == 1;
	assert c1 == 1;
}

