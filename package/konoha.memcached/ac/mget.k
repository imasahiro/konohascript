using konoha.memcached.*;

m = new Memcache("localhost", 11211);

assure "Memcache.mGet" {
	m.set("mget1", "hoge", 0, 0);
	m.set("mget2", "huga", 0, 0);
	String[] keys = ["mget1", "mget2"];
	values = m.mGet(keys);
	assert values[0] == "hoge";
	assert values[1] == "huga";
}

m.serverAdd("localhost", 11212);

assure "Memcache.mGetByKey" {
	m.setByKey("1", "mget1", "hoge", 0, 0);
	m.setByKey("1", "mget2", "huga", 0, 0);
	String[] keys = ["mget1", "mget2"];
	values = m.mGetByKey("1", keys);
	assert values[0] == "hoge";
	assert values[1] == "huga";
}
