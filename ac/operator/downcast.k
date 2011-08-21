/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "downcast" {
	Object o = 1;
	int n = (int)o;
	assert n == 1;
}

assure "downcast: Number" {
	Number o = 1;
	int n = (int)o;
	assert n == 1;
}

assure "downcast: dynamic" {
	dynamic d = 1;
	int n = (int)d;
	assert n == 1;
}

