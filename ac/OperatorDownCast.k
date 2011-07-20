/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/


assure "OperatorDownCast" {
	Object o = 1;
	int n = (int)o;
	assert n == 1;
}

assure "OperatorDownCast:Number" {
	Number o = 1;
	int n = (int)o;
	assert n == 1;
}

assure "OperatorDownCast:Dynamic" {
	dynamic d = 1;
	int n = (int)d;
	assert n == 1;
}

