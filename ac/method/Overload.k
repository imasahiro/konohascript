
@Overload int f(int a, int b, int c) {
	print "int:", a, b, c;
	return a+b+c;
}

@Overload float f(float a, float b, float c) {
	print "float:", a, b, c;
	return a+b+c;
}

@Overload String f(String a, String b, String c) {
	print "String:", a, b, c;
	return "s:"+a+b+c;
}

assure "Method Overload" {
	assert f(10, 20, 30) == 60;
	assert f(10.1, 20.2, 30.3) == 60.6;
	assert f("10", "20", "30") == "s:102030";
}
