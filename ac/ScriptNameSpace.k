
class Person(String name);

namespace {
	class Dog(String name);
	assure "UnitTest:ScriptNameSpace" {
		assert defined(Person);
		assert defined(Dog);	
	}
}

assure "UnitTest:ScriptNameSpace" {
	assert defined(Person);
	assert !defined(Dog);
}

