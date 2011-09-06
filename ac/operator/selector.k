/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

t = ("naruto", 17);
s, n = t;

assure "Selector" {
	assert s == "naruto";
	assert n == 17;
	assert typeof(s) == String;
	assert typeof(n) == Int;
}

assure "Selector" {
	t1 = ("naruto", 17);
	s1, n1 = t1;
	assert s1 == "naruto";
	assert n1 == 17;
	assert typeof(s1) == String;
	assert typeof(n1) == Int;
}

