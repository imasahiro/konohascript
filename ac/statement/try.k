/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

void throwException() {
	throw new Security!!();
}

assure "StatementTry" {
	int a, b, c;
	try {
		a = 1;
		throwException();
		b = 1;
	}
	catch(IO!! e) {
		c = 1;
	}
	catch(Security!! e) {
		c = 2;
	}
	finally {
		a = 2;
	}
	print a, b, c;
	assert a == 2;
	assert b == 0;
	assert c == 2;
}

