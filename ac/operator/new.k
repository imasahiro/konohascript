/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

/* these funcitons are related to _EXPRCALL in term.c */

assure "ParserNewOperator:new byte[]" {
	b = new byte[0];
	assert typeof(b) == Bytes;
}

