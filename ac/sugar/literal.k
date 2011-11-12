/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/

using konoha.sugar.*;

String triple = """\"\"\"
abcdefgh
\"\"\"
""";
assure "Sugar: String Literal" {
	assert "\"abcd\"".tokenize()[0] == "abcd";
	assert "\'abcd\'".tokenize()[0] == "abcd";
	print triple;
	print triple.tokenize()[0];
}

// FIXME
assure "Sugar: Regex Token" {
	assert "/abcd/".tokenize()[0] == "/abcd/";
}
