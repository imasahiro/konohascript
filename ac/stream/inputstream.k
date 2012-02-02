/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by chen_ji
 ***************************************************************************/

assure "InputStream.new:notexists" {
	InputStream ins = new InputStream(".__not_exist__");
	assert ins == null;
}

assure "InputStream.new:exists" {
	/* This may fail if the current directory is not a source repository */
	InputStream ins = new InputStream("README");
	assert ins != null;
}
