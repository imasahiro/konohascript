
// Scala-style class

class Person(String name, int age);

assure "UnitTest:DeclareScalaClass" {
	Person p1 = new Person("naruto", 17);
	assert p1.name == "naruto";
	assert p1.age == 17;
}

