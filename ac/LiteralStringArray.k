
assure "UnitTest:LiteralStringArray" {
	a = ["true", "false"];
	assert typeof(a) == Array<String>;
	assert a[0] == "true";
}

