/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String konoha = "konoha";
  
assure "StringConcatenation" {
	String name = "naruto";
	assert konoha + name == "konohanaruto";
	assert konoha + "1.0" == "konoha1.0";
	assert konoha + 1 == "konoha1";
}

assure "StringIndexing" {
	String name = "naruto";
	int n = |name|;
	assert n == 6;
	assert name[0] == "n";
	assert name[-1] == "o";
}
	
