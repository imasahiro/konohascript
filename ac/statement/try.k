/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

void throwException() {
	throw new Security!!();
}

void throwException2() {
	try {
		throw new Security!!();
	} catch(IO!! e) {
		print "failed!!";
	}
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

	a = b = c = 0;
	try {
		a = 1;
		throwException2();
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

