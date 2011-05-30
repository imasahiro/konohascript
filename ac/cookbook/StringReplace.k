/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

String s = "hello, konoha";

assure "StringReplace" {
	assert s.replace($/hello/, "aloha") == "aloha, konoha";
	assert s.replace("hello", "aloha") == "aloha, konoha";
}
