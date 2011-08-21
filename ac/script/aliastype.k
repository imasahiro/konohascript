/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// This is very useful  

IArray = int[];
Dict = Map<String,String>;
aa = [1, 2];
A = typeof(aa);

assure "AliasType" {
	IArray a;
	Dict m;
	A a2;
	assert typeof(a[0]) == int;
	assert typeof(m[""]) == String;
	assert typeof(a2[0]) == int;
}

