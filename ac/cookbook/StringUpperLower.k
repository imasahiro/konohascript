/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String s = "I Love Konoha";
String sl = "i love konoha";
String su = "I LOVE KONOHA";

assure "StringUpperLower" {
	assert (s.(to:lower) == sl);
	assert (s.(to:upper) == su);
	assert (s.convert(to:lower) == sl);
	assert (s.convert(to:upper) == su);
}
