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

assure "ClassDefinition" {
	Person p1 = new("naruto", 17);
	p2 = new Person("sakura", 16);
	Person p3 = new Person("sasuke", 17);
	p2.age = 17;
	print p1.age, p2.age, p3.age;
	assert p1.age == p3.age;
	assert p2.age == p3.age;
}

class Rectangle {
	int width;
	int height;
	Rectangle(int width, int height) {
		this.width = width;
		this.height = height;
	}
	@Virtual int getArea() {
		return width * height;
	}
}

class Triangle extends Rectangle {
	@Override int getArea() {
		return this.width * this.height / 2;
	}
}

assure "SubClassDefinition" {
	Rectangle r = new Rectangle(80, 60);
	Triangle t = new Triangle(80, 60);
	print "Rectangle", r.area
	print "Triangle", t.area
}

class C {
	String s1 = "naruto";
	String s0;
	int n1 = 100;
	int n0;
	float f1 = 100.0;
	float f0;
}

assure "ClassFieldDefinition" {
	C c = new C();
	print c.s1, c.n1, c.f1;
	print c.s0, c.n0, c.f0;
	assert c.s1 == "naruto";
	assert c.s0 == null;
	assert c.n1 == 100;
	assert c.n0 == 0;
	assert c.f1 == 100.0;
	assert c.f0 == 0.0;
}


