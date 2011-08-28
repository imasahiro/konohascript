//// Mini UnitTest for String
//// Author: Utaro Hiraoka <utrhira at users.sourceforge.jp>
//// moved from ktest by shinpei
//
//assure "string literal"
//{
//
//	assert "" == "";
//	assert '' == "";
//	assert `` == "";
//	
//	assert "string" == "string";
//	assert 'string' == "string";
//	assert `string` == "string";
//	
//		s = """
//multiln
//double
//""";
//	assert s == "multiln\ndouble\n";
//		s = '''
//multiln
//single
//''';
//	assert s == "multiln\nsingle\n";
//	s = ```
//multiln
//back
//```;
//	assert s == "multiln\nback\n";
//	
//	assert """a""" == "a";
//	assert '''a''' == "a";
//	assert ```a``` == "a";
//	
//	assert "''" == "''";
//	assert "``" == "``";
//	assert '""' == "\"\"";
//	assert '``' == "``";
//	assert `""` == "\"\"";
//	assert `''` == "''";
//	assert "'" == "'";
//	assert "`" == "`";
//
//	assert typeof('"') == Int;
//	assert typeof('`') == Int;
//}
//
//
//assure "string - operator"
//{
//	String sn = "string";
//	assert "string" - "s" == "tring";
//	assert "this is string" - "s" == "thi i tring"
//	assert sn - "s" == "tring";
//	assert sn - "z" == "string";
//	assert sn - "" == "string";
//	assert sn - sn == "";
//	assert "" - sn == "";
//	assert "" - "" - "" == "";
//}
//
//assure "string - operator : multi"
//{
//	String mbsn = "ｓｔｒｉｎｇ"
//	assert "ｓｔｒｉｎｇ" - "ｓ" == "ｔｒｉｎｇ";
//	assert mbsn - "ｓ" == "ｔｒｉｎｇ";
//	assert mbsn - "" == "ｓｔｒｉｎｇ";
//	assert mbsn - mbsn == "";
//	assert "" - mbsn == "";
//}
//
//assure "string to operator"
//	{
//	String sn = "string";
//	assert "string"[1 to 3] == "tri";
//	assert sn[1 to 3] == "tri";
//	assert sn[to 3] == "stri";
//	assert sn[1 to] == "tring";
//	assert sn[3 to 3] == "i";
//	assert sn[1 to -2] == "trin";
//	// assert sn[3 to -5]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//}
//
//assure "string to operator : multi"
//{
//	String mbsn = "ｓｔｒｉｎｇ";
//	assert "ｓｔｒｉｎｇ"[1 to 3] == "ｔｒｉ";
//	assert mbsn[1 to 3] == "ｔｒｉ";
//	assert mbsn[to 3] == "ｓｔｒｉ";
//	assert mbsn[1 to] == "ｔｒｉｎｇ";
//	assert mbsn[3 to 3] == "ｉ";
//	assert mbsn[1 to -2] == "ｔｒｉｎ";
//	// assert mbsn[3 to -5]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//}
//
//assure "string until operator" {	
//String sn = "string";
//	assert "string"[1 until 3] == "tr";
//	assert sn[1 until 3] == "tr";
//	assert sn[until 3] == "str";
//	assert sn[1 until] == "tring";
//	assert sn[1 until -2] == "tri";
//	// TODO
//	//assert (sn[3 until 3]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//	//assert sn[3 until -4]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//}
//
//
//assure "string until operator : multi"
//{	String mbsn = "ｓｔｒｉｎｇ";
//	assert "ｓｔｒｉｎｇ"[1 until 3] == "ｔｒ";
//	assert mbsn[1 until 3] == "ｔｒ";
//	assert mbsn[until 3] == "ｓｔｒ";
//	assert mbsn[1 until] == "ｔｒｉｎｇ";
//	assert mbsn[1 until -2] == "ｔｒｉ";
//	assert mbsn[3 until 3]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//	//assert mbsn[3 until -4]
//	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
//}
//
//assure "string < operator"
//{
//	String sn = "string";
//	assert "a" < "z" == true;
//	assert "z" < "a" == false;
//	assert "0" < "a" == true;
//	assert " " < "0" == true;
//	assert "" < sn == true;
//	assert sn < "z" == true;
//	assert "a" < sn == true;
//}
//
//assure "string > operator : multi"
//{
//	String mbsn = "ｓｔｒｉｎｇ";
//	assert "ａ" < "ｚ" == true;
//	assert "a" < "ａ" == true;
//	assert "ｚ" < "a" == false;
//	assert "あ" < "お" == true;
//	assert "ａ" < "あ" == false;
//	assert "" < mbsn == true;
//	assert mbsn < "ｚ" == true;
//	assert "a" < mbsn == true;
//}
//
//assure "string > operator"
//{	
//String sn = "string";
//	assert "z" > "a" == true;
//	assert "a" > "z" == false;
//	assert "a" > "0" == true;
//	assert "0" > " " == true;
//	assert "z" > sn == true;
//	assert sn > "a" == true;
//}
//
//assure "string > operator : multi"
//{	
//String mbsn = "ｓｔｒｉｎｇ";
//	assert "ａ" > "ｚ" == false;
//	assert "a" > "ａ" == false;
//	assert "ｚ" > "a" == true;
//	assert "あ" > "お" == false;
//	assert "ａ" > "あ" == true;
//	assert "" > mbsn == false;
//	assert mbsn > "ｚ" == false;
//	assert "a" > mbsn == false;
//}
//
//assure "string != operator"
//{	String sn = "string"
//	assert "a" != "A" == true;
//	assert sn != "a" == true;
//	assert "z" != sn == true;
//	assert "string" != sn == false;
//}
//
//assure "string != operator : multi"
//{
//	String mbsn = "ｓｔｒｉｎｇ";
//	assert "ａ" != "ａ" == false;
//	assert "ｚ" != "ａ" == true;
//	assert mbsn != "ｓｔｒｉｎｇ" == false;
//	assert mbsn != "string" == true;
//}
//
//assure "string backslash bug (appears only '\' is at the beginning of the string)"
//{
//	String s0, s1, s2;
//	assert s0 = "ab\n" == "ab\n";
//	assert s1 = "a\nb" == "a\nb";
//	assert s2 = "\nab" == "\nab";
//}
