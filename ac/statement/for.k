/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "StatementFor" {
	int i, sum = 0;
	for(i = 0; i < 10; i++) {
		sum += i;
	}
	print i, sum;
	assert i == 10;
	assert sum == 45;
}

