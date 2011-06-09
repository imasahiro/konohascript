/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "BuiltinFunctionDelegate" {
	String s = "naruto";
	f = delegate(s, startsWith);
	assert f("naru");
	assert not f("saku");	
}

assure "BuiltinFunctionDelegate:StaticMethod" {
	f = delegate(Int, random);
	print f();
	assert f(1) == 0;
}

@Iterative InputStream.readLine();
String.. itr = new InputStream().readLine()..;

(new InputStream()!!).readLine();

"hoge".readLine

itr = (as Iterator)ins.readLine();

while((line = ins.readLine() != null) {

}
(to Iterator<>)a;
a.. ==> (iterate (CALL a)
foreach(String line from ins.readLine()..) {
}
ins.readLine)


