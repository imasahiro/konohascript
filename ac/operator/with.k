/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

class Person {
	String name;
	int age;
}

assure "with operator" {
	p = new Person();
	p with {
		name: "naruto";
		age: 17;
		friend: "sakura";
	}
	print p.name, p.age;
	assert p.name == "naruto";
	assert p.age == 17;
}

data = {
	name: "naruto";
	age: 17;
}

assure "with operator: data" {
	p = new Person();
	p with data;
	print p.name, p.age;
	assert p.name == "naruto";
	assert p.age == 17;
}

