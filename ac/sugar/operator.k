/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/


using konoha.sugar.*;

assure "Parsing Plus Operator" {
	a = "a + b".tokenize();
	print a;
	assert a.size == 3 && a[0] == "a" && a[1] == "+" && a[2] == "b";
}

assure "Parsing Operator" {
	a = "a +b- c * d / e% f & g <h > i += j+.k!! l <> m ** n <= o != p".tokenize();
	print a;
	print |a|
	assert a.size == 31;
	assert a[ 1] == "+";
	assert a[ 3] == "-";
	assert a[ 5] == "*";
	assert a[ 7] == "/";
	assert a[ 9] == "%";
	assert a[11] == "&";
	assert a[13] == "<";
	assert a[15] == ">";
	assert a[17] == "+=";
	assert a[19] == "+.";
	assert a[21] == "!!";
	assert a[23] == "<>";
	assert a[25] == "**";
	assert a[27] == "<=";
	assert a[29] == "!=";
}

