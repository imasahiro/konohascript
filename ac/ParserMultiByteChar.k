/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

/* This case is based on bugs reported by Okamoto Yuuki */

assure "ParserMultiByteChar" {
	int a = 1;　// 全角空白
	assert a == 1;
}

