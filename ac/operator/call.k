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

assure "query call" {
	assert query ## select name, age
	             ##   from database
	             ##   where age < 17;
}

assure "static call" {
	assert Int.class == Int;
}

