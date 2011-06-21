/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// this function doesn't work if inlining failed.

int succ(int n) {
	return n+1;
}

assure "CompilerInlineFunction" {
	int n2 = succ(1);
	assert n2 == 2;
}

String hi(String s) {
	return "hi, " + s;
}

assure "CompilerInlineFunction" {
	String msg = hi("naruto");
	assert msg == "hi, naruto";
}

