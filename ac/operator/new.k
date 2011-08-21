/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

/* these funcitons are related to _EXPRCALL in term.c */

assure "new: byte[]" {
	b = new byte[0];
	b2 = new byte[1024];
	assert typeof(b) == Bytes;
	assert |b2| == 1024;
}

