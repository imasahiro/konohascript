/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "ParserWrongGenericType" {
	String<String> s;
	assert typeof(s) == String;
}
