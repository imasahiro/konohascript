using konoha.memcached.*

m = new Memcache("localhost", 11211);

assure "Memcache.delete" {
	m.set("delete", "hoge", 0, 0);
	m.delete("delete");
	value = m.get("delete");
	assert value == null;
}

m.serverAdd("localhost" ,11212);


assure "Memcache.deleteByKey" {
	m.setByKey("1", "delete", "hoge", 0, 0);
	m.setByKey("2", "delete", "hoge", 0, 0);
	m.deleteByKey("1", "delete");
	value1 = m.getByKey("1", "delete");
	value2 = m.getByKey("2", "delete");
	assert value1 == null;
	assert value2.equals("hoge");
}
