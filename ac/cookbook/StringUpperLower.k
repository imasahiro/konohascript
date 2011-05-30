/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String s = "I Love Konoha";
String sl = "i love konoha";
String su = "I LOVE KONOHA";

assure "StringUpperLower" {
	assure (s.(to:lower) == sl);
	assure (s.(to:upper) == su);
	assure (s.convert(to:lower) == sl);
	assure (s.convert(to:upper) == su);
}
