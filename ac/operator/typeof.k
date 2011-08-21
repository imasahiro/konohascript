/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "typeof" {
	int[] a;
	float f;
	assert typeof(a) == int[];
	assert typeof(a[0]) == int;
	assert typeof(f) == Float;
}

