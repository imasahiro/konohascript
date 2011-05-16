/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 2 

String f() {
	int a = 1;
	if(val == 1) {
		String n1;
		name = "naruto";
	}
	else {
		String n1;
		name = "sakura";
	}
	int b = 2;
	print a, name, b;
	assert not defined(n1);
	return name;
}

assure "FunctionScope" {
	assert f() == "sakura";
}


