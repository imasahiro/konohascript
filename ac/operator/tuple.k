/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "x[n]: tuple" {
	t2 = ("naruto", 17);
	t3 = ("naruto", 17, "rasengan");
	assert |t2| == 2;
	assert t2[0] == "naruto";
	assert t2[1] == 17;
	assert |t3| == 3;
	assert t3[-1] == "rasengan";
//	assert t3[-2] == 17;
	assert t3[-3] == "naruto";
}
