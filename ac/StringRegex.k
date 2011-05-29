/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

 
String text = """
 
""";
 
String date = "04/20/2009";

  
assure "StringRegex" {
	String abc = "abcdefg";
	assert abc in? $/def/;
	assert not abc in? $/xxx/;
}

assure "StringRegex:i" {
	String abc = "abcdefg";
	assert abc in? $/ABC/i;
	assert not abc in? $/XXX/i;
}

assure "StringRegexSearch" {
	String abc = "abcdefg";
	assert abc.search($/xxx/) == -1;
	assert abc.search($/abc/) == 0;
	assert abc.search($/D.f/i) == 3;
}

assure "StringRegexMatch" {
	String text = "1 plus 2 equal 3";
	res = text.match($/\d+/);
	print res;
	res = text.match($/\d+/g);
	print res;
}

assure "StringRegexSplit" {
	String text = "abc<br>def<br><br>";
	res = text.split($/<br>/);  // ["abc", "def", "", ""]
	print res;
	assert typeof(res) == String[];
	res = text.split("<br>");  // ["abc", "def", "", ""]
	print res;
	res = "1,2, 3 , 4 ,5".split($/\s*,\s*/);
	print res;
	assert |res| == 5;
	assert res[4] == "5";
}

assure "StringRegexReplace" {
	String ab = "aaabbb";
	assert ab.replace($/a*/, "AAA") == "AAAbbb";
	assert ab.replace($/z*/, "AAA") == "AAAaaabbb";
	assert ab.replace($/$/, "AAA") == "aaabbbAAA";
	String str = "this is konoha";
	assert str.replace($/this is (.+?)$/, "that is $1") == "that is konoha";
	assert str.replace($/this is (.+?)$/, "$1 is this") == "konoha is this";
	assert str.replace($/((t)(h)(i)(s))( )(i)(s)( )(.+?)$/, "$1 is $10") == "this is konoha";
	String text = "abc\"def\"gh";
	res = text.replace($/"([^"]*)"/, "``$1''");
	print res;
	assert res == "abc``def''gh";
}

assure "ParserRegex" {
	Regex pattern = $/\\/;
	pattern = $/\//;
	pattern = $/\d{2,4}/;
	pattern = $/[^"*]/;
	pattern = $/(['"])[^'"]*\1/;
	pattern = $/([Jj]ava[Ss]cript)\sis\sis\sfun/;
}

