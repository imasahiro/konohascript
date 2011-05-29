/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

void f(int n) {
	f(n+1);
}

assure "SupportStackOverflow" {
	boolean isCaught = false;
	try {
		f(0);
	}
	catch(Script!! e) {
		isCaught = true;
	}
	catch(StackOverflow!! e) {
		isCaught = true;
	}
	assert isCaught;
}

