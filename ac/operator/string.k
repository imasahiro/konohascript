/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String konoha = "konoha";
  
assure "String:x+y" {
	String name = "naruto";
	assert konoha + name == "konohanaruto";
	assert konoha + "1.0" == "konoha1.0";
	assert konoha + 1 == "konoha1";
}

assure "String:x+y with line feed" {
	print "1" + "\n" + "2";
	assert "1" + "\n" + "2" == "1\n2";
}

assure "String:x[n]" {
	String name = "naruto";
	int n = |name|;
	assert n == 6;
	assert name[0] == "n";
	assert name[-1] == "o";
}

assure "String:x[n]" {
	String sn = "string";
	assert "string"[0] == "s";
	assert sn[2] == "r";
	assert sn[-2] == "n";
}
	
assure "String:|x|" {
	String ss = "s";
	String sn = "string";
	String sm = "s"; for(int i=0;i< 8;i++) { sm += sm; }
	String sl = "s"; for(int i=0;i<12;i++) { sl += sl; }
	assert |"string"| == 6;
	assert |""| == 0;
	assert |ss| == 1;
	assert |sn| == 6;
	assert |sm| == 256;
	assert |sl| == 4096;
}

assure "String:x[n]:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[0] == "ｓ";
	assert mbsn[2] == "ｒ";
	assert mbsn[-2] == "ｎ";
}

assure "String:x+y" {
	String ss = "s";
	String sn = "string";
	String sm = "s"; for(int i=0;i< 8;i++) { sm += sm; }
	String sl = "s"; for(int i=0;i<12;i++) { sl += sl; }
	assert "this is " + "string" == "this is string";
	assert "this is " + sn == "this is string";
	assert sn + " is this" == "string is this";
	assert ss + sn == "sstring";
	assert "" + sn == "string";
	assert "" + "" + "" == "";
	assert "" + 7 == "7";
	assert "" + 7.0 == "7.000000";
	assert "" + true == "true";
	assert "" + 0 + false + 1.23 == "0false1.230000";
	assert |ss + sm| == 257;
	assert |ss + sl| == 4097;
	assert |sn + sm| == 262;
	assert |sn + sl| == 4102;
	assert |sm + sm| == 512;
	assert |sm + sl| == 4352;
	assert |sl + sm| == 4352;
	assert |sl + sl| == 8192;
}


assure "String:x-y" {
	String sn = "string";
	assert "string" - "s" == "tring";
	assert "this is string" - "s" == "thi i tring"
	assert sn - "s" == "tring";
	assert sn - "z" == "string";
	assert sn - "" == "string";
	assert sn - sn == "";
	assert "" - sn == "";
	assert "" - "" - "" == "";
}

assure "String:x[n to m]" {
	String sn = "string";
	assert "string"[1 to 3] == "tri";
	assert sn[1 to 3] == "tri";
	// assert sn[to 3] == "stri"; // port to BUGS
	assert sn[1 to] == "tring";
	assert sn[3 to 3] == "i";
	assert sn[1 to -2] == "trin";
	// assert sn[3 to -5]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "String:x[n until m]" {
	String sn = "string";
	assert "string"[1 until 3] == "tr";
	assert sn[1 until 3] == "tr";
	// assert sn[until 3] == "str"; // port to BUGS
	assert sn[1 until] == "tring";
	assert sn[1 until -2] == "tri";
	// assert sn[3 until 3]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
	// assert sn[3 until -4]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}


assure "String:x<y" {
	String sn = "string";
	assert "a" < "z" == true;
	assert "z" < "a" == false;
	assert "0" < "a" == true;
	assert " " < "0" == true;
	assert "" < sn == true;
	assert sn < "z" == true;
	assert "a" < sn == true;
}


assure "String:x>y" {
	String sn = "string";
	assert "z" > "a" == true;
	assert "a" > "z" == false;
	assert "a" > "0" == true;
	assert "0" > " " == true;
	assert "z" > sn == true;
	assert sn > "a" == true;
}

assure "String:x==y" {
	String sn = "string";
	assert "a" == "a" == true;
	assert "a" == "z" == false;
	assert sn == "string" == true;
	assert sn == "strings" == false;
	assert "" == "" == true;
}

assure "String:x!=y" {
	String sn = "string"
	assert "a" != "A" == true;
	assert sn != "a" == true;
	assert "z" != sn == true;
	assert "string" != sn == false;
}

