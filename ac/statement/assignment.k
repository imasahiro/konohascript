/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "StatementAsignment" {
	int n = 1;
	n += 1;
	assert n == 2;
}

assure "StatementAsignment:Array" {
	int[] a = [1];
	a[0] += 1;
	assert a[0] == 2;
}

class P {
	int x;
	int y;
	P(x, y) {
		_x = x;
		_y = y;
	}
}

assure "StatementAssignment:Field" {
	p = new P(1, 2);
	p.x += 1;
	assert p.x == 2;
}

class Person(String name, int age);

assure "StatementAsignment:Select" {
	p = new Person("naruto", 17);
	name, age from p;
	assert "naruto" == name && age == 17;
	age, name from p;
	assert "naruto" == name && age == 17;
}

