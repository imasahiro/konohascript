
assure "UnitTest:LiteralTuple" {
	t2 = ("naruto", 17);
	t3 = ("naruto", 17, "rasengan");
	assert t2 instanceof Tuple<String,Int>;
	assert t3 instanceof Tuple<String,Int,String>;
}
