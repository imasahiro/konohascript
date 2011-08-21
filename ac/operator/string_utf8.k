/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String konoha = "konohaこのは";
  
assure "StringConcatenation:UTF8" {
	String name = "narutoなると";
	assert konoha + name == "konohaこのはnarutoなると";
	assert konoha + "1.0" == "konohaこのは1.0";
	assert konoha + 1 == "konohaこのは1";
}

assure "StringIndexing:UTF8" {
	String name = "このはnarutoなると";
	int n = |name|;
	assert n == 12;
	assert name[0] == "こ";
	assert name[3] == "n";
	assert name[-1] == "と";
}
	
