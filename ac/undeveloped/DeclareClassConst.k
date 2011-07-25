/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

print "This grammar should be depricated";

Int.ZERO = 0; // definition

assure "ClassConst" {
	assert Int.MAX == 9223372036854775807;
	assert Int.ZERO == 0;
}

