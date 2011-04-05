
int f(int n => n+1);
int g(int n) => n+1;

assure "UnitTest:FunctionOneLine" {
	assert f(0) == 1;
	assert g(0) == 1;
}
