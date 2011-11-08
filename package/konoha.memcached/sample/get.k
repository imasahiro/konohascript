using konoha.memcached.*

Memcache mcd = new Memcache("localhost", 11211);
mcd.set("hoge1", "1", 0, 0);
value1 = mcd.get("hoge1");
print value1;
mcd.set("hoge2", "2", 0, 0);
value2 = mcd.getByKey(null, "hoge2");
print value2;
mcd.set("hoge3", "3", 0, 0);
String[] keys = ["hoge1", "hoge2", "hoge3"];
print keys;
String[] values1 = mcd.mGet(keys);
keys.remove(0);
print values1;
String[] values2 = mcd.mGetByKey(null, keys);
print values2;
