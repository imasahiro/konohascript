/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Shinpei Nakata  twitter: @shinpei_NKT
 ***************************************************************************/

using konoha.posix.*;

assure "FilePath" {
	Path p = file:FilePath.k;
	assert p != null;
}

