/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "UnitTest:WrongGenericType" {
	String<String> s;
	assert typeof(s) == String;
}
