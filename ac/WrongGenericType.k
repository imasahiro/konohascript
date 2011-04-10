
assure "UnitTest:WrongGenericType" {
	String<String> s;
	assert typeof(s) == String;
}
