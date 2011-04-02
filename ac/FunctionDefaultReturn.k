
int f(int n) {
	if(n==1) 2;
}

assure "UnitTest:FunctionDefaultReturn" {
	assert f(1) == 2;
	assert f(2) == 0;
}

