/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// Some students are confused when they declare array type. 

assure "UnitTest:DeclareCStyleArray" {
	int a, b[];
	b = new int[10];
	assert a == 0;
	assert b[0] == 0;
}

