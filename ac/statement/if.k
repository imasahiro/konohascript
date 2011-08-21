/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


int f(int n, int m) {
	if(n == 0) {
		if(m == 1) return 1;
		return 0;
	}
	else if(n == 2) {
		if(m == 0) return 20;
		else return 21;
	}
	else {
		if(m == 1) {
			return 11;
		}else{
			return 10;
		}
	}
	return -1; // ERROR
}

assure "StatementIf" {
	assert f(0, 1) == 1;
	assert f(0, 0) == 0;
	assert f(1, 1) == 11;
	assert f(1, 0) == 10;
	assert f(2, 0) == 20;
	assert f(2, 1) == 21;
}

