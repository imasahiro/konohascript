/*
 * Start a memcached daemon before executing this script.
 * e.g.)
 * $ memcached -m 64m -d
 */

using konoha.memcached.*;

m = Map.open("memcached:localhost:11211");
print m;
m["hoge"] = "1";
m["fuga"] = "2";
m["foo"] = "3";
m["bar"] = "4";
m["buz"] = "5";
print m;
print m.size
m.remove("hoge");
print m;
foreach (String s in m.keys()) {
	print s, m[s];
}
