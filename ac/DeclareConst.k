
int zero() {
	return 0;
}

ZERO = zero(); // definition
ZERO = 1; // ERROR: TO CHECK ZERO is not rewritten 

assure "UnitTest:Const" {
	assert ZERO == 0;
}

