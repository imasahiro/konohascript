// reported by Wakamori

System.eval("void f() {\nprint \"hi\";\n}");

assure "System.eval:funccall" {
	for (i = 0; i < 300; i++) {
		eval("f()");
	}
	assert true;
}
