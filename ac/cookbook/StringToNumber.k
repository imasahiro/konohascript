/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StringToNumber" {
	String s = "9898";
	assert (to int)s == 9898;
	assert (to int)s + 2 == 9900;
	s = "98.98";
	assert (to float)s == 98.980000;
	assert (to float)s + 2 == 100.980000;
	assert (int)"9898" == 9898;
	assert (float)"98.98" == 98.980000;
}
