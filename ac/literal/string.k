/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
               Utaro Hiraoka <utrhira at users.sourceforge.jp>
 ***************************************************************************/

assure "StringLiteral" {
	assert "" == "";
	assert "string" == "string";
		s = """
multiln
double
""";
	assert s == "multiln\ndouble\n";
	// FIXME: assert """a""" == "a";
}

String text = """
Peter Piper picked a peck of pickled pepper.
A peck of pickled pepper Peter Piper picked.
If Peter Piper picked a peck of pickled pepper.
Where's the peck of pickled pepper Peter Piper picked?
"""
String text2 = ## Peter Piper picked a peck of pickled pepper.
        ## A peck of pickled pepper Peter Piper picked.
        ## If Peter Piper picked a peck of pickled pepper.
        ## Where's the peck of pickled pepper Peter Piper picked?
String text3 = "Peter Piper picked a peck of pickled pepper."
	"A peck of pickled pepper Peter Piper picked."
	"If Peter Piper picked a peck of pickled pepper."
	"Where's the peck of pickled pepper Peter Piper picked?"

assure "StringLiteralHereDocument" {
	print |text|, |text2|, |text3|
	assert text == text2 + "\n";
	assert text2 == text3;
}

assure "StringLiteralSingleQuote" {
	assert '' == "";
	assert 'string' == "string";
		s = '''
multiln
single
''';
	assert s == "multiln\nsingle\n";
	assert '''a''' == "a";
	// FIXME: assert '\'' == "'";
}

assure "FUTURE:StringLiteralBackQuote" {
	assert `` == "";
	assert `string` == "string";
	s = ```
multiln
back
```;
	assert s == "multiln\nback\n";
	assert ```a``` == "a";
}

assure "TODO:EscapeSequence" {
	// somebody adds this!!
	s = "\n\t";
}
