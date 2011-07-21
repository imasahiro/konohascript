/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

class Person(String name);

namespace {
	class Dog(String name);
	assure "ScriptNameSpace" {
		assert defined(Person);
		assert defined(Dog);	
	}
}

assure "ScriptNameSpace" {
	assert defined(Person);
	assert !defined(Dog);
}

