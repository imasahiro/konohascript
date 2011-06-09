/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

/* This case is based on bugs reported by Wakamatsu Yuuki */

assure "ParserSingleStatement" {
	a = 0;
	for(i = 0; i < 10; i++) {
		if(i == 5) break;
		a = 1;
	}
	assert a == 1;
}

