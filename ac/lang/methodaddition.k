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

Person p1 = new("naruto", 17);

boolean Person.isChild() {
	return age < 13;
}

assure "MethodAddition" {
	assert not p1.isChild();
}

boolean Person.isChild() {
	return age < 20;
}

assure "MethodRewrite" {
	assert p1.isChild();
}
