/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "ArrayLiteral" {
	a = [1, 1.0];
	b = [];
	Array c = [];
	assert typeof(a) == Array;
	assert typeof(b) == Array;
	assert typeof(c) == Array;
	assert a[0] == 1;
	assert a[1] == 1.0;
}


assure "ArrayLiteral:BooleanArray" {
	a = [true, false];
	boolean[] b = [];
	assert typeof(a) == boolean[];
	assert typeof(b) == boolean[];
	assert a[0]
	assert not a[1];
}

assure "ArrayLiteral:StringArray" {
	a = ["true", "false"];
	String[] b = [];
	assert typeof(a) == Array<String>;
	assert typeof(b) == Array<String>;
	assert a[0] == "true";
	assert a[1] == "false";
}

