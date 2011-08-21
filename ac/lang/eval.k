/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

a = 1;
a = eval("a+1");

assure "SupportEval" {
	assert a == 2;
}

