/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

using konoha.math.*;

assure "PackageMath" {
	pi = Math.PI;
	st2 = Math.sqrt(2.0);
	assert(3.14 < pi and pi < 3.15);
	assert(1.4 < st2 and st2 < 1.5);
}

