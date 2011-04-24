
a = 1;

if(a == 1) {
	TEST = 1;
}
else {
	TEST2 = 1;
}

assure "UnitTest:ScriptDynamicIf" {
	assert defined(TEST);
	assert !defined(TEST2);
}

