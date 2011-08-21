/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by twitter@imasahiro 
 ***************************************************************************/

boolean nearly_equal(float f1, float f2) {
	float diff;
	if (f1 < f2) diff = f2 - f1;
	else diff = f1 - f2;
	if (f1 - f2 < 2.2204460492503131e-16/*epsilon*/) {
		return true;
	}
	return false;
}
assure "FloatConstOperation" {
	assert nearly_equal(3.14159 + 10.0, 13.1416);
	assert nearly_equal(3.14159 - 10.0, -6.85841);
	assert nearly_equal(3.14159 * 10.0, 31.4159);
	assert nearly_equal(3.14159 / 10.0, 0.314159);
	assert ((3.14159 == 10.0) == false);
	assert ((3.14159 != 10.0) == true);
	assert ((3.14159 <  10.0) == true);
	assert ((3.14159 <= 10.0) == true);
	assert ((3.14159 >  10.0) == false);
	assert ((3.14159 >= 10.0) == false);
}

assure "FloatOperation" {
	float f1 = 3.14159;
	float f2 = 10.0000;
	assert nearly_equal(f1 + f2, 13.1416);
	assert nearly_equal(f1 - f2, -6.85841);
	assert nearly_equal(f1 * f2, 31.4159);
	assert nearly_equal(f1 / f2, 0.314159);
	assert ((f1 == f2) == false);
	assert ((f1 != f2) == true);
	assert ((f1 <  f2) == true);
	assert ((f1 <= f2) == true);
	assert ((f1 >  f2) == false);
	assert ((f1 >= f2) == false);
	assert ((f1 < 3.15) == true);
	assert nearly_equal(-f1, -1 * f1);

}

