/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

a = 1;
a = "string"; // type error 

assure "TypeCheck" {
	assert a == 1;
}

