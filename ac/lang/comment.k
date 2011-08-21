/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f() { // comment
	/* comment */
	return 1;
}

assure "ParserComment" {
	assert f() == 1;
}

assure "ParserComment2" {
    int i = -1;
    /*/parse_comment=10;i = 20;*/
    print i;
    print i;
    assert(i == -1);
}
