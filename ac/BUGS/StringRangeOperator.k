/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String konoha = "konoha";

assure "String:x[n to m]" {
	String sn = "string";
	assert "string"[1 to 3] == "tri";
	assert sn[1 to 3] == "tri";
	assert sn[to 3] == "stri"; // Assertion!!
    assert sn[0 to 0] == "s"; // Assertion!! "string";
}

assure "String:x[n until m]" {
	String sn = "string";
	assert "string"[1 until 3] == "tr";
	assert sn[1 until 3] == "tr";
	assert sn[until 3] == "str"; // Assertion!!
}

assure "String:x[n to m]:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 to 3] == "ｔｒｉ";
	assert mbsn[1 to 3] == "ｔｒｉ";
	assert mbsn[to 3] == "ｓｔｒｉ"; // Assertion!!
}

assure "String:x[n until m]:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 until 3] == "ｔｒ";
	assert mbsn[1 until 3] == "ｔｒ";
	assert mbsn[until 3] == "ｓｔｒ"; // Assertion!!
}
