/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "TupleLiteral" {
	t2 = ("naruto", 17);
	t3 = ("naruto", 17, "rasengan");
	assert typeof(t2) == Tuple<String,Int>;
	assert typeof(t3) == Tuple<String,Int,String>;
}
