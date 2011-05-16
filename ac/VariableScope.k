/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 1

class C {
	int val = 2;
	void testLocalVariable() {
		int val = 3;
		print __val, _val, val;
		assert __val == 1;
		assert _val == 2;
		assert val == 3;
	}
}

assert "UnitTest:VariableScope" {
	c = new C();
	c.testLocalVariable()
}


