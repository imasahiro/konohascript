/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/


using konoha.sugar.*;
assure "Sugar: Lang.tokenize" {
	a = ("a + b").tokenize();
	print a;
}
assure "Sugar: Lang.tokenize" {
	a = Lang.tokenize("a + b");
	assert a.size == 3 && a[0].text == "a" && a[1].text == "+" && a[2].text == "b";
}
