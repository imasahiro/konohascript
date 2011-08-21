/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "TypeAliasLong" {
	boolean b;
	assert typeof(b) == Boolean;
}

assure "TypeAliasLong" {
	int n;
	long l;
	assert typeof(n) == Int;
	assert typeof(l) == Int;
}

assure "TypeAliasDouble" {
	float n;
	double l;
	assert typeof(n) == Float;
	assert typeof(l) == Float;
}

assure "TypeAliasByte" {
	byte b;
	byte[] buf;
	assert typeof(b) == Int;
	assert typeof(buf) == Bytes;
}

assure "TypeAliasMap" {
	Map<String> m;
	print m.class;
	assert typeof(m) == Map<String,String>;
}

