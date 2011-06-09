using konoha.posix.*;

assure "PackagePosix:Dir" {
	Dir d = System.opendir("./");
	assert d.isNotNull();
	d.close();

	d = System.opendir("./");
	Map m = d.read();
	print m;
	assert m["d_name"] == ".";
	d.close();

	d = System.opendir("./");
	String s;
	String[] list;
	while ((s = d.readName()) != null) {
		print s;
		list <<< s;
	}
	assert "." in? list && ".." in? list;
	d.close();
}

