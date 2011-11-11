using konoha.json.*;

OutputStream ous = new OutputStream("__write.json");
ous.writeJson({"a": 1});
ous.close();
InputStream ins = new InputStream("__write.json");
Map m = ins.readJson();
print m["a"]

ous = new OutputStream("__write.json");
ous.writeJson([{"hello": "world"}, {"key0": {"hello": "world"}}]);
ous.close();
InputStream ins = new InputStream("__write.json");
Array a = ins.readJson();
print a[0]
print a[0]["hello"]
