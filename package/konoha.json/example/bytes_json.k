using konoha.json.*;

Bytes b = new Bytes();
b.writeJson({"ival": 10, "sval": "hoge", "fval": 1.234});
int len = |b|;
print len;

Map m = b.readJson(0, len);
print m;
print m["ival"];
print m["sval"];
print m["fval"];

class A {
	int x;
	float y;
	String z;
	A(Int x, float y, String z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
}

void main (String[] args) {
	A a = new A(10, 20.0, "hello world");
	OUT.writeJson(a);
	OUT.println("");
	Bytes b = new byte[0];
	b.writeJson(a);
	Map map = b.readJson();
	print map;
}
