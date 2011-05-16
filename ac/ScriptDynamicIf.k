/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

DEBUG = true;

if(DEBUG) {
	TEST = 1;
}
else {
	TEST2 = 1;
}

assure "UnitTest:ScriptStaticIf" {
	assert defined(TEST);
	assert !defined(TEST2);
}

