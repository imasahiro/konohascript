/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "UnitTest:SyntaxSugarMapType" {
	Map<String> m;
	print m.class;
	assert m instanceof Map<String,String>;
}

