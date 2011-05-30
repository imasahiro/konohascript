/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

String url = "http://konoha.sourceforge.jp/";

assure "StringSplit" {
	String[] a0 = url.split($/\//);
	String[] a1 = url.split($/\./);
	String[] a2 = url.split($/\/|\.|:/);
	assert a0[0] == "http:";
	assert a0[1] == "";
	assert a0[2] == "konoha.sourceforge.jp";
	assert a0[3] == "";
	assert a1[0] == "http://konoha";
	assert a1[1] == "sourceforge";
	assert a1[2] == "jp/";
	assert a2[0] == "http";
	assert a2[1] == "";
	assert a2[2] == "";
	assert a2[3] == "konoha";
	assert a2[4] == "sourceforge";
	assert a2[5] == "jp";
	assert a2[6] == "";
}
