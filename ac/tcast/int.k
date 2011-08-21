/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "IntegerCast" {
	int a = 123;
	float f = a;
	print a, f;
	String s = (String)a;
	assert s == "123";
	assert (String)1 == "1";
}

