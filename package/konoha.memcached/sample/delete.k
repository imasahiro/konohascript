using konoha.memcached.*

Memcache mcd = new Memcache("localhost", 11211);
mcd.set("hoge1", "1", 0, 0);
mcd.set("hoge2", "2", 0, 0);
mcd.set("hoge3", "3", 0, 0);
String[] keys = ["hoge1", "hoge2", "hoge3"];
values = mcd.mGet(keys);
print values;
mcd.delete("hoge1");
values = mcd.mGet(keys);
print values;
