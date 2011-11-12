/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/


using konoha.sugar.*;

assure "Sugar: Parsing Digit" {
	assert "10".tokenize()[0] == "10";
}

assure "Sugar: Parsing Negative Digit" {
	a = "-10".tokenize();
	assert a.size == 2 && a[0] == "-" && a[1] == "10";
}

assure "Sugar: Parsing HexDigit" {
	assert "0x10".tokenize()[0] == "0x10";
}

assure "Sugar: Parsing Number" {
	assert "3.14".tokenize()[0] == "3.14";
}

assure "Sugar: Parsing Negative Number" {
	a = "-3.14".tokenize();
	assert a.size == 2 && a[0] == "-" && a[1] == "3.14";
}

assure "Sugar: Parsing Number with Expornent" {
	assert "3.14e2".tokenize()[0] == "3.14e2";
}

assure "Sugar: Parsing Number with Positive Expornent" {
	assert "3.14e+2".tokenize()[0] == "3.14e2";
}

assure "Sugar: Parsing Number with Negative Expornent" {
	assert "3.14e-2".tokenize()[0] == "3.14e-2";
}

