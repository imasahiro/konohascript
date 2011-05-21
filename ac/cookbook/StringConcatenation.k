/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String first = "Naruto";
String last  = "Uzumaki";
String name;

assure "StringConcatenation" {
	name = first + " " + last;
	assert name == "Naruto Uzumaki";
	name2 = "%s{#0} %s{#1}" (first, last);
	assert name == name2;
}

