
// Mini UnitTest for String
//

///*============================================*/
// operator


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
    assert "".get()
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
    assert "".equals() == true;
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
    assert s.trim() == "　　ｓｔｒｉｎｇ　　" // is it ok?
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
    assert "string".indexOf("") == 0;
    assert sn.indexOf("") == 0;
    assert "string".indexOf() == 0; // same as String.indexOf("")
    assert sn.indexOf() == 0; // same as indexOf("")
}

assure "String.indexOf:multi"
{
    String mbsn = "ｓｔｒｉｎｇ";
    assert "ｓｔｒｉｎｇ".indexOf("ｒ") == 2;
    assert mbsn.indexOf("ｒ") == 2;
    assert "ｓｔｒｉｎｇ".indexOf("r") == -1;
    assert mbsn.indexOf("r") == -1;
    assert "ｓｔｒｉｎｇ".indexOf("") == 0;
    assert mbsn.indexOf("") == 0;
    assert "ｓｔｒｉｎｇ".indexOf() == 0;
    assert mbsn.indexOf() == 0;
}

assure "String.lastIndexOf"
{
    String sn = "string";
    assert "string".lastIndexOf("r") == 2;
    assert sn.lastIndexOf("r") == 2;
    assert "string".lastIndexOf("z") == -1;
    assert sn.lastIndexOf("z") == -1;
    assert "string".lastIndexOf("") == 6;
    assert sn.lastIndexOf("") == 6;
    assert "string".lastIndexOf() == 6;
    assert sn.lastIndexOf() == 6;
}

assure "String.lastIndexOf:multi"
{
    String mbsn = "ｓｔｒｉｎｇ";
    assert "ｓｔｒｉｎｇ".lastIndexOf("ｒ") == 2;
    assert mbsn.lastIndexOf("ｒ") == 2;
    assert "ｓｔｒｉｎｇ".lastIndexOf("r") == -1;
    assert mbsn.lastIndexOf("r") == -1;
    assert "ｓｔｒｉｎｇ".lastIndexOf("") == 6;
    assert mbsn.lastIndexOf("") == 6;
    assert "ｓｔｒｉｎｇ".lastIndexOf() == 6;
    assert mbsn.lastIndexOf() == 6;
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
    assert "".split() == new String[]();
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
assure "string_backslash_bug(appears_only_'\'_is_at_the_beginning_of_the_string)"
{
    String s0, s1, s2;
    s0 = "ab\n";
    s1 = "a\nb";
    s2 = "\nab";
    assert s0 == "ab\n";
    assert s1 == "a\nb";
    assert s2 == "\nab";
}
