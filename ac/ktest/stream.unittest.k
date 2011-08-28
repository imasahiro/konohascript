//
//assure "InputStream.new"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	//'ktest/class/stream.ktest'
//
//}
//
//assure "InputStream.readLine"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	assert ins.readLine() == "{"
//}
//
//assure "InputStream.getChar"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	assert ins.getChar() == 62;
//}
//
//assure "InputStream.isClosed/close"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	assert ins.isClosed() == false;
//	ins.close();
//	assert ins.isClosed() == true;
//}
//
//assure "InputStreamnosuchfile"
//{
//	InputStream ins = new InputStream("")
//	ins.close();
//	assert ins.isClosed() == true;
//}
//
//assure "OutputStream.new"
//{
//	OutputStream out = new OutputStream("temp.txt","w")
//	//'temp.txt'
//	//assert out
//	//'temp.txt'
//}
//
//assure "operator"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	OutputStream out = new OutputStream("temp.txt","w")
//	out <<< "Hello World";
//	in = new InputStream("temp.txt","r")
//	//'temp.txt'
//	assert ins.readLine() == "Hello World"
//}
//
//assure "OutputStream.isClosed/close"
//{
//	OutputStream out = new OutputStream("temp.txt","w")
//	assert out.isClosed() == false;
//	assert out.close();
//	assert out.isClosed() == true;
//}
//
//assure "OutputStreamnosuchfile"
//{
//	OutputStream o = new OutputStream("");
//	o <<< "abcd";
//}
//
//assure "OutputStreamisAutoFlush"
//{
//	assert OUT.isAutoFlush() == false
//	assert OUT.setAutoFlush(true);
//	assert OUT.isAutoFlush() == true;
//}
//
//assure "fileopen"
//{
//	InputStream ins = new InputStream("ktest/class/stream.ktest","r")
//	//'ktest/class/stream.ktest'
//}
//
//assure "fileread"
//{
//	InputStream ins = file:ktest/class/stream.ktest;
//	assert c = ins.read() == 0;
//}
//
//assure "filewrite"
//{
//	out = new OutputStream("hoge.ktest")
//	//'hoge.ktest'
//}
//
//assure "fileclose"
//{
//	ins = new InputStream("ktest/class/stream.ktest")
//	ins.close()
//}
//
////{
//assure "filefeof"
//{
////// TODO
////}
//
//
//assure "filereadwithbuffer(#23626)"
//{
//	Bytes buf = new Bytes(128)
//	InputStream ins = new InputStream("ktest/class/stream.ktest")
//	//'ktest/class/stream.ktest'
//	assert ins.read(buf, 0, 256) == 256
//	assert ins.read(buf, 0, 256) == 256
//}
