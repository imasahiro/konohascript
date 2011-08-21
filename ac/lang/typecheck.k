/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// We need more tests for character conversion. 

a = 1;
a = "string"; // type error 

assure "SupportTypeCheck" {
	assert a == 1;
}

