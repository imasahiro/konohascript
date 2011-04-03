class Person {
  String name;
  int age;
  Person(String name, age) {
    this.name = name;
    _age = age;
  }
}

assure "UnitTest:ClassDefinition" {
	Person p1 = new("naruto", 17);
	p2 = new Person("sakura", 16);
	Person p3 = new Person("sasuke", 17);
	p2.age = 17;
	assert p1.age == p3.age;
	assert p2.age == p3.age;
}


