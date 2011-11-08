using konoha.json.*;
void main (String[] args) {
	OutputStream ous = new OutputStream("___hoge.json");
	ous << """
[{"hello" : "world"}, {"key0" : {"hello" : "world"}}]
""";
	ous.close();
	InputStream ins = new InputStream("___hoge.json");
	Array a = ins.readJson();
	print a;
	print a[0];
	print a[0]["hello"];
}
