
def f(int n) {
	return n+1;
}

assure "UnitTest:InferenceReturnType" {
	a = f(1);
	assert a instanceof Int;
}

