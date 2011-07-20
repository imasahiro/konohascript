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

// these are bad examples of typemap

String : (Person p) {
	return p.name;
}

@Semantic int : (Person p) {
	return p.age;
}

Person p = new ("naruto", 17);
print (to String)p;
print (int)p;

int age = p;
String name = p;

assure "DeclareTypeMap" {
	int age = p;
	assert (to String)p == "naruto";
	assert age == 17;
}
