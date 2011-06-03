/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

def Array.test() {
	return this.get(0);
}

assert "DeclareMethodAddition" {
	a = ["a", "b", "c"].test();
	b = [1, 2, 3].test();
	assert a == "a";
	assert b == 1;
}

