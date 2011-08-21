/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

/* these funcitons are related to _EXPRCALL in term.c */

assure "ParserLiteralCall" {
	assert "abc"[0] == "a";
	assert [0, 1][1] == 1;
}

