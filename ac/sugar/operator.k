using konoha.sugar.*;

assure "Parsing Plus Operator" {
	a = "a + b".tokenize();
	print a;
	assert a.size == 3 && a[0] == "a" && a[1] == "+" && a[2] == "b";
}

