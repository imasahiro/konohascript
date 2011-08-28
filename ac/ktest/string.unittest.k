
// Mini UnitTest for String
// Author: Utaro Hiraoka <utrhira at users.sourceforge.jp>
//

assure "stringliteral"
{
	assert "" == "";
	assert '' == "";
	assert `` == "";
	
	assert "string" == "string";
	assert 'string' == "string";
	assert `string` == "string";
	
		s = """
multiln
double
""";
	assert s == "multiln\ndouble\n";
		s = '''
multiln
single
''';
	assert s == "multiln\nsingle\n";
	s = ```
multiln
back
```;
	assert s == "multiln\nback\n";
	
	assert """a""" == "a";
	assert '''a''' == "a";
	assert ```a``` == "a";
	
	assert "''" == "''";
	assert "``" == "``";
	assert '""' == "\"\"";
	assert '``' == "``";
	assert `""` == "\"\"";
	assert `''` == "''";
	assert "'" == "'";
	assert "`" == "`";

	assert `"` == "\"";
	assert `'` == "'";

	// TODO
	//assert typeof('"') == Int;
	//assert typeof('`') == Int;
	
}

assure "stringvariables"
{
	String s0;
	s0 == "";
	String s1 = "initialize";
	assert s1 == "initialize";
	s1 = "substitute";
	assert s1 == "substitute";
}

assure "typeinferenceofString"
{
	assert String == String;
	si0 = "inference";
	assert typeof(si0) == String;
	si1 = si0;
	assert typeof(si1) == String;
	// TODO
	//sii = 'a';
	//assert typeof(sii) == Int;
}

///*============================================*/
// operator

assure "stringsizeoperator"
{
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

assure "stringsizeoperator:multi"
{
	String mbss = "ｓ";
	String mbsn = "ｓｔｒｉｎｇ";
	assert |"ｓｔｒｉｎｇ"| == 6;
	assert |mbss| == 1;
	assert |mbsn| == 6;
}

assure "stringgetoperator"
{
	String sn = "string";
	assert "string"[0] == "s";
	assert sn[2] == "r";
	assert sn[-2] == "n";
}

assure "stringgetoperator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[0] == "ｓ";
	assert mbsn[2] == "ｒ";
	assert mbsn[-2] == "ｎ";
}

assure "string+operator"
{
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

assure "string+operator:multi"
{
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

assure "string-operator"
{
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

assure "string-operator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ"
	assert "ｓｔｒｉｎｇ" - "ｓ" == "ｔｒｉｎｇ";
	assert mbsn - "ｓ" == "ｔｒｉｎｇ";
	assert mbsn - "" == "ｓｔｒｉｎｇ";
	assert mbsn - mbsn == "";
	assert "" - mbsn == "";
}

assure "stringtooperator"
{
	String sn = "string";
	assert "string"[1 to 3] == "tri";
	assert sn[1 to 3] == "tri";
	assert sn[to 3] == "stri";
	assert sn[1 to] == "tring";
	assert sn[3 to 3] == "i";
	assert sn[1 to -2] == "trin";
	// assert sn[3 to -5]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "stringtooperator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 to 3] == "ｔｒｉ";
	assert mbsn[1 to 3] == "ｔｒｉ";
	assert mbsn[to 3] == "ｓｔｒｉ";
	assert mbsn[1 to] == "ｔｒｉｎｇ";
	assert mbsn[3 to 3] == "ｉ";
	assert mbsn[1 to -2] == "ｔｒｉｎ";
	// assert mbsn[3 to -5]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "stringuntiloperator"
{
	String sn = "string";
	assert "string"[1 until 3] == "tr";
	assert sn[1 until 3] == "tr";
	assert sn[until 3] == "str";
	assert sn[1 until] == "tring";
	assert sn[1 until -2] == "tri";
	// assert sn[3 until 3]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
	// assert sn[3 until -4]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "stringuntiloperator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ"[1 until 3] == "ｔｒ";
	assert mbsn[1 until 3] == "ｔｒ";
	assert mbsn[until 3] == "ｓｔｒ";
	assert mbsn[1 until] == "ｔｒｉｎｇ";
	assert mbsn[1 until -2] == "ｔｒｉ";
	// assert mbsn[3 until 3]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
	// assert mbsn[3 until -4]
	// CRIT [knh:OutOfIndex!!] [(eval):1] ???
}

assure "string<operator"
{
	String sn = "string";
	assert "a" < "z" == true;
	assert "z" < "a" == false;
	assert "0" < "a" == true;
	assert " " < "0" == true;
	assert "" < sn == true;
	assert sn < "z" == true;
	assert "a" < sn == true;
}

assure "string>operator:multi"
{
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

assure "string>operator"
{
	String sn = "string";
	assert "z" > "a" == true;
	assert "a" > "z" == false;
	assert "a" > "0" == true;
	assert "0" > " " == true;
	assert "z" > sn == true;
	assert sn > "a" == true;
}

assure "string>operator:multi"
{
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

assure "string==operator"
{
	String sn = "string";
	assert "a" == "a" == true;
	assert "a" == "z" == false;
	assert sn == "string" == true;
	assert sn == "strings" == false;
	assert "" == "" == true;
}

assure "string==operator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" == "ａ" == true;
	assert "ｚ" == "ａ" == false;
	assert mbsn == "ｓｔｒｉｎｇ" == true;
	assert mbsn == "string" == false;
}


assure "string!=operator"
{
	String sn = "string"
	assert "a" != "A" == true;
	assert sn != "a" == true;
	assert "z" != sn == true;
	assert "string" != sn == false;
}

assure "string!=operator:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ａ" != "ａ" == false;
	assert "ｚ" != "ａ" == true;
	assert mbsn != "ｓｔｒｉｎｇ" == false;
	assert mbsn != "string" == true;
}

//*============================================*/
// method

assure "String.getSize"
{
	String sn = "string";
	assert "".getSize() == 0;
	assert sn.getSize() == 6;
}

assure "String.getSize:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.getSize() == 6;
}

assure "String.get"
{
	String sn = "string";
	// assert "".get()
	// CRIT [knh:OutOfIndex!!] [(eval):1] 0 not < 0
	assert sn.get() == "s";
}

assure "String.get:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.get() == "ｓ";
}

assure "String.equals"
{
	String sn = "string";
	assert sn.equals("string") == true;
	assert "".equals() == false;
	assert sn.equals() == false;
}

assure "String.equals:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.equals(mbsn) == true;
	assert mbsn.equals("ｓｔｒｉｎｇ") == true;
	assert mbsn.equals() == false;
}

assure "String.subString"
{
	String sn = "string";
	assert sn.subString(2, 2) == "ri";
	assert sn.subString(2) == "ring";
	assert sn.subString() == "string";
}

assure "String.subString:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.subString(2, 2) == "ｒｉ";
	assert mbsn.subString(2) == "ｒｉｎｇ";
	assert mbsn.subString() == "ｓｔｒｉｎｇ";
}

assure "String.startsWith"
{
	String sn = "string";
	assert sn.startsWith("str") == true;
	assert sn.startsWith("srt") == false;
	assert "konoha".startsWith("str") == false;
	assert sn.startsWith("") == true;
	assert "konoha".startsWith("") == true;
	// assert sn.startsWith() == false;
	// assert "".startsWith() == false;
}

assure "String.startsWith:multi"
{
String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.startsWith("ｓｔｒ") == true;
	assert mbsn.startsWith("ｓｒｔ") == false;
	assert mbsn.startsWith("") == true;
	// assert mbsn.startsWith() == false;
}

assure "String.endsWith"
{
String sn = "string";
	assert sn.endsWith("ing") == true;
	assert sn.endsWith("nig") == false;
	assert sn.endsWith("") == true;
	// assert sn.endsWith() == false;
	// assert "".endsWith() == false;
}

assure "String.endsWith:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.endsWith("ｉｎｇ") == true;
	assert mbsn.endsWith("ｎｉｇ") == false;
	assert mbsn.endsWith("") == true;
	//assert mbsn.endsWith() == true;
}

assure "String.trim"
{
	assert "   string   ".trim() == "string";
	assert " ".trim() == "";
}

assure "String.trim:multi"
{
	String s = "　　ｓｔｒｉｎｇ　　";
	assert s.trim() == "ｓｔｒｉｎｇ"
}

assure "String.isASCII"
{
	String sn = "string";
	assert sn.isASCII() == true;
	assert "".isASCII() == true;
}

assure "String.isASCII:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.isASCII() == false;
	assert "あ".isASCII() == false;
	assert "aあ".isASCII() == false;
	assert "aaあ".isASCII() == false;
	assert "aaaあ".isASCII() == false;
	assert "aaaaあ".isASCII() == false;
	assert "aaaaaあ".isASCII() == false;
	assert "aaaaaaあ".isASCII() == false;
	assert "aaaaaaaあ".isASCII() == false;
	assert "aaaaaaaaあ".isASCII() == false;
}

assure "String.indexOf"
{
	String sn = "string";
	assert "string".indexOf("r") == 2;
	assert sn.indexOf("r") == 2;
	assert "string".indexOf("z") == -1;
	assert sn.indexOf("z") == -1;
	assert "string".indexOf("") == -1;
	assert sn.indexOf("") == -1;
	assert "string".indexOf() == -1;
	assert sn.indexOf() == -1;
}

assure "String.indexOf:multi"
{
String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ".indexOf("ｒ") == 2;
	assert mbsn.indexOf("ｒ") == 2;
	assert "ｓｔｒｉｎｇ".indexOf("r") == -1;
	assert mbsn.indexOf("r") == -1;
	assert "ｓｔｒｉｎｇ".indexOf("") == -1;
	assert mbsn.indexOf("") == -1;
	assert "ｓｔｒｉｎｇ".indexOf() == -1;
	assert mbsn.indexOf() == -1;
}

assure "String.lastIndexOf"
{
	String sn = "string";
	assert "string".lastIndexOf("r") == 2;
	assert sn.lastIndexOf("r") == 2;
	assert "string".lastIndexOf("z") == -1;
	assert sn.lastIndexOf("z") == -1;
	assert "string".lastIndexOf("") == -1;
	assert sn.lastIndexOf("") == -1;
	assert "string".lastIndexOf() == -1;
	assert sn.lastIndexOf() == -1;
}

assure "String.lastIndexOf:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ".lastIndexOf("ｒ") == 2;
	assert mbsn.lastIndexOf("ｒ") == 2;
	assert "ｓｔｒｉｎｇ".lastIndexOf("r") == -1;
	assert mbsn.lastIndexOf("r") == -1;
	assert "ｓｔｒｉｎｇ".lastIndexOf("") == -1;
	assert mbsn.lastIndexOf("") == -1;
	assert "ｓｔｒｉｎｇ".lastIndexOf() == -1;
	assert mbsn.lastIndexOf() == -1;
}

assure "String.replace"
{
String sn = "string";
	assert "a".replace("a", "b") == "b";
	assert "a".replace("", "b") == "a";
	assert sn.replace("str", "script") == "scripting";
	assert sn.replace("str") == "ing";
	assert "".replace("test") == "";
	assert sn.replace("", "test") == "string";
	assert "".replace("", "test") == "";
	assert sn.replace() == "string";
	assert "".replace() == "";
}

assure "String.replace:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert mbsn.replace("ｓｔｒ", "ｓｃｒｉｐｔ") == "ｓｃｒｉｐｔｉｎｇ";
	assert mbsn.replace("ｓｔｒ") == "ｉｎｇ";
	assert mbsn.replace("", "ｔｅｓｔ") == "ｓｔｒｉｎｇ";
	assert mbsn.replace() == "ｓｔｒｉｎｇ";
}


assure "String.match"
{
	String sn = "string";
	assert "string".match("str") == ["str"];
	assert sn.match("str") == ["str"];
	//assert "string".match("") == [];
	//assert sn.match("") == [];
	//assert "string".match() == [];
	//assert sn.match() == [];
}


assure "String.search"
{
String sn = "string";
	assert "string".search("ing") == 3;
	assert sn.search("ing") == 3;
	assert "string".search("") == -1;
	assert sn.search("") == -1;
	assert "string".search() == -1;
	assert sn.search() == -1;
}

assure "String.split"
{
String sn = "string";
	assert "string".split("r") == ["st", "ing"];
	assert sn.split("r") == ["st", "ing"];
	assert "string".split("z") == ["string"];
	assert sn.split("z") == ["string"];
	assert "string".split("") == ["s", "t", "r", "i", "n", "g"];
	assert sn.split("") == ["s", "t", "r", "i", "n", "g"];
	assert "string".split() == ["s", "t", "r", "i", "n", "g"];
	assert sn.split() == ["s", "t", "r", "i", "n", "g"];
	assert "".split() == [];
}

assure "String.split:multi"
{
	String mbsn = "ｓｔｒｉｎｇ";
	assert "ｓｔｒｉｎｇ".split("ｒ") == ["ｓｔ", "ｉｎｇ"];
	assert mbsn.split("ｒ") == ["ｓｔ", "ｉｎｇ"];
	assert "ｓｔｒｉｎｇ".split("r") == ["ｓｔｒｉｎｇ"];
	assert mbsn.split("r") == ["ｓｔｒｉｎｇ"];
	assert "ｓｔｒｉｎｇ".split("") == ["ｓ", "ｔ", "ｒ", "ｉ", "ｎ", "ｇ"];
	assert mbsn.split("") == ["ｓ", "ｔ", "ｒ", "ｉ", "ｎ", "ｇ"];
	// assert "ｓｔｒｉｎｇ".split() ==  ["ｓ", "ｔ", "ｒ", "ｉ", "ｎ", "ｇ"];
	// assert mbsn.split() ==  ["ｓ", "ｔ", "ｒ", "ｉ", "ｎ", "ｇ"];
}

//*============================================*/
// converter


assure "stringto:upperconverter"
{
	String sn = "string";
	assert "a".convert(to:upper) == "A";
	assert "A".convert(to:upper) == "A";
	assert "1".convert(to:upper) == "1";
	assert "this is STRING.".convert(to:upper) == "THIS IS STRING.";
	assert sn.convert(to:upper) == "STRING";
	assert "".convert(to:upper) == "";
}

assure "stringto:lowerconverter"
{
	assert "a".convert(to:lower) == "a";
	assert "A".convert(to:lower) == "a";
	assert "1".convert(to:lower) == "1";
	assert "this is STRING".convert(to:lower) == "this is string";
	assert "".convert(to:lower) == "";
}

// escape 
assure "stringbackslashbug(appearsonly'\'isatthebeginningofthestring)"
{
	String s0, s1, s2;
	s0 = "ab\n";
	s1 = "a\nb";
	s2 = "\nab";
	assert s0 == "ab\n";
	assert s1 == "a\nb";
	assert s2 == "\nab";
}
