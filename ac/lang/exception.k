/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "Exception" {
	e = new Exception();
	e2 = new Security!!("Permission Denied");
	assert e <: "Exception";
	assert e2 <: "Security";
	assert e2 <: "Security";
	assert e2 <: Security!!;
	assert not e2 <: "Assertion";
	assert e2 <: "Exception";
}

