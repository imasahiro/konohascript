/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "MapLiteral" {
	a = {}
	b = {name: "naruto", age: 17};
	assert typeof(a) == Map;
	assert typeof(b) == Map;
}

