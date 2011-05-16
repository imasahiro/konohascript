/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// This is very useful  
IArray = int[];
Dict = Map<String,String>;

assure "UnitTest:DeclareAliasType" {
	IArray a;
	Dict m;
	assert typeof(a[0]) == int;
	assert typeof(m[""]) == String;
}

