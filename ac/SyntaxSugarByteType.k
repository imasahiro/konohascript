
assure "UnitTest:SyntaxSugarByteType" {
	byte b;
	byte[] buf;
	assert typeof(b) == Int;
	assert typeof(buf) == Bytes;
}

