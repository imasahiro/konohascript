/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// this function doesn't work if inlining failed.

String hi(String s) {
	return "hi, " + s;
}

assure "CompilerInlineFunction" {
	String msg = hi("naruto");
	assert msg == "hi, naruto";
}

