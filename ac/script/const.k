/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int zero() {
	return 0;
}

ZERO = zero(); // definition
ZERO = 1; // ERROR: TO CHECK ZERO is not rewritten 

assure "DeclareConst" {
	assert ZERO == 0;
}

