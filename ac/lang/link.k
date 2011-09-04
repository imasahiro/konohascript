/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/

using konoha.lang.*;

assure "Link" {
	String name1 = "Int";
	String name2 = "konoha.Int";
	Class c1 = class:Int;
	Class c2 = class:: name1;
	Class c3 = class:konoha.Int;
	Class c4 = class:: name2;
	assert c1 == Int;
	assert c2 == Int;
	assert c3 == Int;
	assert c4 == Int;
}


