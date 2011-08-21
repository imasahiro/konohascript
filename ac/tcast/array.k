/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "ArrayCast" {
	int[] a = [1, 2, 3];
	s1 = (String[])a;
	f1 = (float[])a;
	b = (Array)a;
	s2 = (String[])b;
	f2 = (float[])b;
	assert typeof(b) == Array;
	assert s1 == s2;
	assert f1 == f2;
}

