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


