//
//// Float Test
//
//assure "floatvalue"
//{
//	assert 1.0 == 1.000000;
//	assert -1.0 == -1.000000;
//}
//
//assure "floatvariables"
//{
//float f;
//	assert f == 0.000000;
//	assert (f = 1.0) == 1.000000;
//	assert (f = -1.0) == -1.000000;
//	assert (f = 2.1234567812345678) == 2.123457;
//	assert (f = 2.9876543219876543) == 2.987654;
//}
//
//assure "floatfourarithmeticoperations"
//{
//	float a = 2.0;
//	assert a == 2.000000;
//	assert a + a == 4.000000;
//	assert a + 1 == 3.000000;
//	assert a + -1 == 1.000000;
//	assert a - a == 0.000000;
//	assert a - 1 == 1.000000;
//	assert a - -1 == 3.000000;
//	assert a * a == 4.000000;
//	assert a * 1 == 2.000000;
//	assert a * -1 == -2.000000;
//	assert a / a == 1.000000;
//	assert a / 1 == 2.000000;
//	assert a / -1 == -2.000000;
//	float b = -2.0;
//	assert b == -2.000000;
//	assert b + b == -4.000000;
//	assert b - b == 0.000000;
//	assert b * b == 4.000000;
//	assert b / b == 1.000000;
//}
//
//assure "floataddsubstitution"
//{
//	a = 2.000000;
//	b = -2.000000;
//	assert (a += 1.0 ) == 3.000000;
//	assert (a += -1.0) == 2.000000;
//	assert (b += 1.0 ) == -1.000000;
//	assert (b += -1.0) == -2.000000;
//}
//
//assure "floatsubsubstitution"
//{
//	a = 2.000000;
//	b = -2.000000;
//	assert (a -= 1.0 ) == 1.000000;
//	assert (a -= -1.0) == 2.000000;
//	assert (b -= 1.0 ) == -3.000000;
//	assert (b -= -1.0) == -1.000000;
//}
//
//assure "floatmultisubstitution"
//{
//	a = 2.000000;
//	b = -2.000000;
//	assert (a *= 2.0 ) == 4.000000;
//	assert (a *= -2.0) == -4.000000;
//	assert (b *= 2.0 ) == -4.000000;
//	assert (b *= -2.0) == 4.000000;
//}
//
//assure "floatdivsubstitution"
//{
//	a = 2.000000;
//	b = -2.000000;
//	assert (a /= 2.0 ) == 1.000000;
//	assert (a /= -2.0) == -1.000000;
//	assert (b /= 2.0 ) == -1.000000;
//	assert (b /= -2.0) == 1.000000;
//}
//
//assure "floatincremental"
//{
//	a = 2.000000;
//	b = -2.000000;
//	assert a++ == 2.000000;
//	assert a == 3.000000;
//	assert ++a == 4.000000;
//	assert b++ == -2.000000;
//	assert b == -1.000000;
//	assert ++b == 0.000000;
//}
//
//assure "floatdecremental"
//{
//	float a = 4.000000;
//	float b = 0.000000;
//	assert a-- == 4.000000;
//	assert a == 3.000000;
//	assert --a == 2.000000;
//	assert b-- == 0.000000;
//	assert b == -1.000000;
//	assert --b == -2.000000;
//}
//
//assure "floatcast[int=>float]"
//{
//	int i = 1;
//	assert (float)i == 1.000000;
//	assert (i = -1) == -1;
//	assert (float)i == -1.000000;
//}
//
//assure "floatMapper[float=>int]"
//{
//	float a = 2.000000, b = -2.100000;
//	assert (int)a == 2;
//	assert (int)b == -2;
//}
//
//assure "floatMapper[String=>float]"
//{
//	String str = "1.0";
//	assert (float)str == 1.000000;
//}
//
//assure "floatMapper[float=>String]"
//{
//	float a = 2.000000;
//	str = (String)a;
//	assert str == "2.000000";
//}
//
//assure "floatcompare"
//{
//	assert 2.0 < 3.0 == true;
//	assert 3.0 < 2.0 == false;
//	assert 3.0 > 2.0 == true;
//	assert 2.0 > 3.0 == false;
//	assert 3.0 >= 2.0 == true;
//	assert 2.0 >= 3.0 == false;
//	assert 2.0 <= 3.0 == true;
//	assert 3.0 <= 2.0 == false;
//	float f2 = 2.0;
//	float f3 = 3.0;
//	assert f2 < 3.0 == true;
//	assert f3 < 2.0 == false;
//	assert f3 > 2.0 == true;
//	assert f2 > 3.0 == false;
//	assert f3 >= 2.0 == true;
//	assert f2 >= 3.0 == false;
//	assert f2 <= 3.0 == true;
//	assert f3 <= 2.0 == false;
//	assert f2 < f3 == true;
//	assert f3 < f2 == false;
//	assert f3 > f2 == true;
//	assert f2 > f3 == false;
//	assert f3 >= f2 == true;
//	assert f2 >= f3 == false;
//	assert f2 <= f3 == true;
//	assert f3 <= f2 == false;
//}
//
//assure "floatFormatter"
//{
//	f = 9.0;
//	assert "%bits"(f) == "01000000 00100010 00000000 00000000 00000000 00000000 00000000 00000000";
//	assert "%d"(f) == "9";
//	//assert "%data"(f) == "9.000000";
//	assert "%dump"(f) == "9.000000";
//	assert "%f"(f) == "9.000000";
//	assert "%k"(f) == "9.000000";
//	assert "%s"(f) == "9.000000";
//}
//
//assure "Float.floatToIntBits"
//{
/////assert Float.floatToIntBits(4.0)
/////4
/////
//assure "Float.intToFloatBits"
//{
/////assert Float.intToFloatBits(4)
/////4.000000
//
//assure "Float.random()"
//{
//	f = Float.random();
//	assert 0 < f && f < 1;
//true
//}
