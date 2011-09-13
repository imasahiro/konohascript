/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

String konoha = "konohaこのは";
  
assure "String:x+y:UTF8" {
	String name = "narutoなると";
	assert konoha + name == "konohaこのはnarutoなると";
	assert konoha + "1.0" == "konohaこのは1.0";
	assert konoha + 1 == "konohaこのは1";
}

assure "String:x[n]:UTF8" {
	String name = "このはnarutoなると";
	int n = |name|;
	assert n == 12;
	assert name[0] == "こ";
	assert name[3] == "n";
	assert name[-1] == "と";
}
	
assure "String:|x|:UTF8"
{
	String mbss = "ｓ";
	String mbsn = "ｓｔｒｉｎｇ";
	assert |"ｓｔｒｉｎｇ"| == 6;
	assert |mbss| == 1;
	assert |mbsn| == 6;
}

assure "String:x+y:UTF8" {
	String sn = "string";
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｔｈｉｓ　ｉｓ　" + "ｓｔｒｉｎｇ" == "ｔｈｉｓ　ｉｓ　ｓｔｒｉｎｇ";
	assert mbsn + "　ｉｓ　ｔｈｉｓ" == "ｓｔｒｉｎｇ　ｉｓ　ｔｈｉｓ";
	assert "ｔｈｉｓ　ｉｓ　" + mbsn == "ｔｈｉｓ　ｉｓ　ｓｔｒｉｎｇ";
	assert sn + mbsn == "stringｓｔｒｉｎｇ";
	assert mbsn + sn == "ｓｔｒｉｎｇstring";
	assert mbsn + 7 == "ｓｔｒｉｎｇ7";
	assert mbsn + 1.23 == "ｓｔｒｉｎｇ1.230000";
	assert mbsn + true == "ｓｔｒｉｎｇtrue";
}

assure "String:x-y:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ"
	assert "ｓｔｒｉｎｇ" - "ｓ" == "ｔｒｉｎｇ";
	assert mbsn - "ｓ" == "ｔｒｉｎｇ";
	assert mbsn - "" == "ｓｔｒｉｎｇ";
	assert mbsn - mbsn == "";
	assert "" - mbsn == "";
}

assure "String:x[n to m]:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 to 3] == "ｔｒｉ";
	assert mbsn[1 to 3] == "ｔｒｉ";
	// assert mbsn[to 3] == "ｓｔｒｉ"; // port to BUGS
	assert mbsn[1 to] == "ｔｒｉｎｇ";
	assert mbsn[3 to 3] == "ｉ";
	assert mbsn[1 to -2] == "ｔｒｉｎ";
	// assert mbsn[3 to -5]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "String:x[n until m]:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 until 3] == "ｔｒ";
	assert mbsn[1 until 3] == "ｔｒ";
	// assert mbsn[until 3] == "ｓｔｒ"; // port to BUGS
	assert mbsn[1 until] == "ｔｒｉｎｇ";
	assert mbsn[1 until -2] == "ｔｒｉ";
	// assert mbsn[3 until 3]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
	// assert mbsn[3 until -4]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "String:x<y:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" < "ｚ" == true;
	assert "a" < "ａ" == true;
	assert "ｚ" < "a" == false;
	assert "あ" < "お" == true;
	assert "ａ" < "あ" == false;
	assert "" < mbsn == true;
	assert mbsn < "ｚ" == true;
	assert "a" < mbsn == true;
}

assure "String:x>y:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" > "ｚ" == false;
	assert "a" > "ａ" == false;
	assert "ｚ" > "a" == true;
	assert "あ" > "お" == false;
	assert "ａ" > "あ" == true;
	assert "" > mbsn == false;
	assert mbsn > "ｚ" == false;
	assert "a" > mbsn == false;
}
assure "String:x==y:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" == "ａ" == true;
	assert "ｚ" == "ａ" == false;
	assert mbsn == "ｓｔｒｉｎｇ" == true;
	assert mbsn == "string" == false;
}

assure "String:x!=y:UTF8" {
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" != "ａ" == false;
	assert "ｚ" != "ａ" == true;
	assert mbsn != "ｓｔｒｉｎｇ" == false;
	assert mbsn != "string" == true;
}
