/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

String str = "I am Naruto Uzumaki";

assure "StringSubstring" {
	assert str.substring(5) == "Naruto Uzumaki";
	assert str.substring(5, 6) == "Naruto";
	assert str.substring(-7) == "Uzumaki";
	assert str[5 to 10] == "Naruto";
}
