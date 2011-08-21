/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

line0 = LINE;
void line() {
	print LINE, ",", (line0+2);
	assert (LINE == line0 + 3);
}

line1 = LINE;
class A {

	void line() {
		print LINE, ",", (line1+4);
		//assert(LINE == line1+5);
	}
}

line2 = LINE;
assure "ParserLineCount" {
	a = new A();
	line()
	a.line();
	assert LINE == line2 + 5;
}

line3 = LINE;
assure "ParserMultiLine" {
	a = 1;
	if(a == 2)
		a = 3
	assert a == 1;
	assert line3 + 6 == LINE;
}


/** TODO: FAILED
line5 = LINE;
assure "ParserMultiLine" {
	a = 1;
	if(a == 2)
	a = 3;
	assert a == 3;
}
**/

line6 = LINE;
assure "ParserMultiLine:BackSlash" {
	a = 1;
	if(a == 2) \
	a = 2;
	assert a == 1;
	assert line6 + 6 == LINE;
}

line7 = LINE;
assure "ParserMultiLine:TripleQuote" {
	OUT <<< """
this is multi line
""" <<< EOL;
	assert line7+5 == LINE;
}

