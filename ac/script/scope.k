/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

val = 1
String name = "naruto";
int age = 17;

class C {
	int val;
	void testLocalVariable() {
		int val = 3;
		print __val, _val, val;
		assert __val == 1;
		assert _val == 0;
		assert val == 3;
	}
	void testScriptVariable() {
		print name, age;
		assert name == "naruto";
		assert age == 17;
	}
	void testScriptVariable2(int n) {
		print __name, __age;
		assert __name == "naruto";
		assert __age == 17;
	}
	void testScriptVariable3() {
		age = 16;
		assert __age == 16;
	}
}

assure "ScriptVariableScope" {
	c = new C();
	c.testLocalVariable()
	c.testScriptVariable()
	c.testScriptVariable2(0)
	c.testScriptVariable3()
}

