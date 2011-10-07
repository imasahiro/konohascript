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

int f(int n, int m)
{
	int sum = 0;
	for (int i = -n/2; i < n; i++) {
		sum += m;
	}
	return sum;
}

assure "StatementFor: check espidx in for_init expr" {
	assert 1500 == f(100, 10);
}
