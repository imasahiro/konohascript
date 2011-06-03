/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

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

assure "DeclareSubClass" {
	Rectangle r = new Rectangle(80, 60);
	Triangle t = new Triangle(80, 60);
	print "Rectangle", r.area
	print "Triangle", t.area
}

