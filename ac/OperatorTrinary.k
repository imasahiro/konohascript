/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "OperatorTrinary" {
	int a = 1;
	n = (a == 2) ? 10 : 100;
	assert n == 100;
	n = (a == 1) ? 10 : 100;
	assert n == 10;
}

