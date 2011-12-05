/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide
 ***************************************************************************/

assure "OutputStream.println(s) : s > 4096" {
	String a = "";
	for (int i = 0; i < 4500; i++) {
		a += "a";
	}
	OutputStream ous = new OutputStream("aaa");
	ous.println(a);
	ous.flush();
	ous.close();
}

