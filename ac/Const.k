
int zero() {
	return 0;
}

ZERO = zero(); // definition
ZERO = 1; // this is ignored due to an error

assure "UnitTest:Const" {
	assert ZERO == 0;
}

