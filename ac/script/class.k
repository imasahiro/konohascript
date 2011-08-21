/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

class Person {
  String name;
  int age;
  Person(String name, age) {
    this.name = name;
    _age = age;
  }
}

assure "DeclareClass" {
	Person p1 = new("naruto", 17);
	p2 = new Person("sakura", 16);
	Person p3 = new Person("sasuke", 17);
	p2.age = 17;
	print p1.age, p2.age, p3.age;
	assert p1.age == p3.age;
	assert p2.age == p3.age;
}

