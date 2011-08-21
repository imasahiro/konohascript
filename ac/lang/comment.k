/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int f() { // comment
	/* comment */
	assert LINE == 8;
	return 1;
}

assure "Comment" {
	assert f() == 1;
}

assure "Comment" {
    int i = -1;
    /*/parse_comment=10;i = 20;*/
    print i;
    assert(i == -1 /* */);
    assert LINE == 21;
}

a = 0;
b = 0;

/* 
a = 1;
b = 2;  /* nested comment */
*/

assure "NestedComment" {
	assert (a == 0);
	assert (b == 0);
}

