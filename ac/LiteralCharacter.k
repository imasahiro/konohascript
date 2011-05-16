/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "UnitTest:LiteralCharacter" {
	int ch = 'a';
	String s = 'a';
	Object o = 'a';
	print ch, s, o;
	assert ch == 97;
	assert s == "a";
	assert o instanceof Int;
};

