/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 1

class C {
	int val;
	void testLocalVariable() {
		int val = 3;
		print __val, _val, val;
		assert __val == 1;
		assert _val == 0;
		assert val == 3;
	}
}

assure "UnitTest:VariableScope" {
	c = new C();
	c.testLocalVariable()
}


