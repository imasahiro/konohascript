/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 *  written by Masahiro Ide
 ***************************************************************************/

assure "DynamicType" {
	dynamic d = 1;
	int n = d;
	assert n == 1;
	float f = d;
	assert f == 1.0;
	boolean isCaught = false;
	try {
		String s = d;
	}
	catch(Script!! e) {
		print e;
		isCaught = true;
	}
	assert isCaught; // s is not assigned 
}

dynamic fibo (dynamic n) {
        if(n < 3) return 1;
        return fibo(n-1) + fibo(n-2);
}

assure "DynamicType" {
	n = fibo(10);
	assert typeof(n) == dynamic;
	assert n == 55;
}

assure "DynamicTypeCall" {
	dynamic d = "naruto";
	assert d.startsWith("n");
	assert not d.startsWith("A");
}

assure "TypedVariable + DynamicTypeVariable" {
	String s = "abcd";
	dynamic d = "1234";
	dynamic n = 1234;
	assert s + d == "abcd1234";
	assert d + 10 == "123410";
	assert n + 10 == 1244;
}
