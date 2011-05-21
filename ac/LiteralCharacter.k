/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "CharacterLiteral" {
	int ch = 'a';
	String s = 'a';
	Object o = 'a';     // this must be of int
	print ch, s, o;
	assert ch == 97;
	assert s == "a";
	assert o instanceof Int;
};

