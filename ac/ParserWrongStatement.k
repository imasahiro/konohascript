/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f(int f) {

assure "ParserWrongStatment" {
	print defined(f);
}


assure "ParserWrongStatement:Assignment" {
	a=;
}

