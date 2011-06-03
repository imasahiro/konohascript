/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "OperatorExists" {
	Array a = [1,2];
	assert exists a;
	a = null;
	assert not exists a;
}

assure "OperatorExists:String" {
	String path = "script:nofile";
	print "path", path, exists path;
	assert exists path == script:nofile;
}

assure "OperatorExists:Link" {
	print "charset:UTF8", charset:UTF8;
	assert exists charset:UTF8 == charset:UTF8;
	print "charset:: UTF8", charset:: "UTF8";
	assert exists charset:: "UTF8" == charset:UTF8;
}

