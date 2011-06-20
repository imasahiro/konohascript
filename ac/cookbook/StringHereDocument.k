/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

String lyrics0 = '''
Peter Piper picked a peck of pickled peppers,
A peck of pickled peppers Peter Piper picked;
If Peter Piper picked a peck of pickled peppers,
Where's the peck of pickled peppers Peter Piper picked?
'''

String lyrics1() {
  return ## Peter Piper picked a peck of pickled peppers,
         ## A peck of pickled peppers Peter Piper picked;
         ## If Peter Piper picked a peck of pickled peppers,
         ## Where's the peck of pickled peppers Peter Piper picked?
         ##
}

assure "StringHereDocument" {
	String s = "Peter Piper picked a peck of pickled peppers,\nA peck of pickled peppers Peter Piper picked;\nIf Peter Piper picked a peck of pickled peppers,\nWhere's the peck of pickled peppers Peter Piper picked?\n";
	assert (s == lyrics0);
	assert (s == lyrics1());
}

assure "StringSharpLiteral" {
	String file = "pizza.txt";
	String cmd = ## echo $$file

	assert (cmd == "echo pizza.txt");
}
