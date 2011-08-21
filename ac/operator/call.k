/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

boolean query(String s, NameSpace ns) {
	print s, |s|;
	assert |s| == 50;
	assert ns == NS;
	return true;
}

assure "QueryCall" {
	assert query ## select name, age
	             ##   from database
	             ##   where age < 17;
}

assure "StaticCall" {
	assert Int.class == Int;
}

