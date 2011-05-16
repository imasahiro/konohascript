/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "UnitTest:LiteralMap" {
	a = {}
	b = {name: "naruto", age: 17};
	assert typeof(a) == Map;
	assert typeof(b) == Map;
}

