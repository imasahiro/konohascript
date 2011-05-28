/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

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

assure "StringLiteral" {
	print |text|, |text2|, |text3|
	assert text == text2 + "\n";
	assert text2 == text3;
}

	
