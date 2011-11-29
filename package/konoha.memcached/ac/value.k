using konoha.memcached.*

m = new Memcache("localhost", 11211);

assure "Memcache.increment" {
	m.set("value", "123", 0, 0);
	value = m.increment("value", 1);
	assert value == 124;
}

assure "Memcache.decrement" {
	value = m.decrement("value", 1);
	assert value == 123;
}
