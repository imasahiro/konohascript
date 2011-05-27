/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "ParserMultiLine" {
	a = 1;
	if(a == 2)
		a = 3
	assert a == 1;
}

/** TODO: FAILED
assure "ParserMultiLine" {
	a = 1;
	if(a == 2)
	a = 3;
	assert a == 3;
}
**/

assure "ParserMultiLine:BackSlash" {
	a = 1;
	if(a == 2) \
	a = 2;
	assert a == 1;
}

assure "ParserMultiLine:TripleQuote" {
	OUT <<< """
this is multi line
""" <<< EOL;
}

