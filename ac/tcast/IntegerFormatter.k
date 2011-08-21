/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "IntegerFormatter" {
	int n = 18;
	assert "%04d"(n) == "0018";
	assert "% 4d"(n) == "  18";
	assert "%x"(n) == "12";
}

assure "IntegerFormatter:bits" {
	int n = 0;
	int a = -1;
	String bits = "%bits"(a);
	print  bits;
	print  |bits|;
	assert |bits| == 71;
}

