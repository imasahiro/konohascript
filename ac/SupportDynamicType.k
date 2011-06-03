/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "SupportDynamicType" {
	dynamic d = 1;
	int n = d;
	assert n == 1;
	float f = d;
	assert f == 1.0;
	Object o = d;
	boolean isCaught = false;
	try {
		String s = d;
	}
	catch(Script!! e) {
		print e;
		isCaught = true;
	}
	assert isCaught; // s is not assigned 
}

