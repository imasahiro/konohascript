class A {
	String name;
	Int age;
}
assure "Expression with 'with' stmt" {
	A a = new A() with { name: "naruto", age:17};
	print a;
	assert a.name == "name" && a.age == 17;
}
