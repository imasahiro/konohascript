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
	String path = "link:link";
	assert exists path;
	path = "naruto";
	assert not exists path;
}

assure "OperatorExists:Link" {
	String s = "link";
	assert exists link:: s;
	s = "die hard 4";
	assert not exists link:: s;
}

