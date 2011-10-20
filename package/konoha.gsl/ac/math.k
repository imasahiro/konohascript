using konoha.gsl.*;
using konoha.math.*;

epsilon = 2.2204460492503131e-16;
rough_epsilon = 2.2204460492503131e-14;

boolean nearly_equal(float f1, float f2) {
	float diff;
	diff = (f1 < f2 ? f2 - f1 : f1 - f2);
	if (diff < epsilon) {
		return true;
	}
	print f1, f2;
	return false;
}
boolean roughly_nearly_equal(float f1, float f2) { //Compare two float values more roughly.
	float diff;
	diff = (f1 < f2 ? f2 - f1 : f1 - f2);
	if (diff < rough_epsilon) {
		return true;
	}
	print f1, f2;
	return false;
}

assure "GslMath.isNan" {
	assert GslMath.isNan(0.0/0.0) == true;
	assert GslMath.isNan(1.0) == false;
}

assure "GslMath.isInf" {
	assert GslMath.isInf(1.0/0.0) == 1; //Value is positive infinity.
	assert GslMath.isInf(-1.0/0.0) == -1; //Value is negative infinity.
	assert GslMath.isInf(1.0) == 0; //Value is finite.
}

assure "GslMath.isFinite" {
	assert GslMath.isFinite(1.0) == true;
	assert GslMath.isFinite(1.0/0.0) == false;
	assert GslMath.isFinite(-1.0/0.0) == false;
	assert GslMath.isFinite(0.0/0.0) == false;
}

assure "GslMath.log1p" {
	assert nearly_equal(GslMath.log1p(0.0), 0.0);
	assert nearly_equal(GslMath.log1p(Math.E - 1), 1.0);
}

assure "GslMath.expm1" {
	assert nearly_equal(GslMath.expm1(0.0), 0.0);
	assert nearly_equal(GslMath.expm1(1.0), Math.E - 1);
}

assure "GslMath.hypot" {
	assert nearly_equal(GslMath.hypot(0.0, 0.0), 0.0);
	assert nearly_equal(GslMath.hypot(3.0, 4.0), 5.0);
}

assure "GslMath.hypot3" {
	float f = GslMath.hypot3(1.0, 2.0, 3.0);
	assert roughly_nearly_equal(f * f, 1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0);
}

assure "GslMath.acosh" {
	assert nearly_equal(GslMath.acosh(1.0) , 0.0);
	assert nearly_equal(GslMath.acosh((Math.E + 1/Math.E)/2), 1.0);
}

assure "GslMath.asinh" {
	assert nearly_equal(GslMath.asinh(0.0) , 0.0);
	assert nearly_equal(GslMath.asinh((Math.E - 1/Math.E)/2), 1.0);
}

assure "GslMath.atanh" {
	assert nearly_equal(GslMath.atanh(0.0) , 0.0);
	assert nearly_equal(GslMath.atanh((Math.E - 1/Math.E)/(Math.E + 1/Math.E)), 1.0);
}

assure "GslMath.ldexp" {
	assert nearly_equal(GslMath.ldexp(0.0, 0), 0.0);
	assert nearly_equal(GslMath.ldexp(3.0, 2), 3.0 * 2 * 2);
}

assure "GslMath.frexp" {
	Tuple<float, int> t1 = GslMath.frexp(0.0);
	Tuple<float, int> t2 = GslMath.frexp(1.0);
	assert nearly_equal(t1[0], 0.0);
	assert t1[1] == 0;
	assert nearly_equal(t2[0], 0.5);
	assert t2[1] == 1;
}

assure "GslMath.powInt" {
	assert nearly_equal(GslMath.powInt(3.0, 3), 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow2" {
	assert nearly_equal(GslMath.pow2(3.0), 3.0 * 3.0);
}

assure "GslMath.pow3" {
	assert nearly_equal(GslMath.pow3(3.0), 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow4" {
	assert nearly_equal(GslMath.pow4(3.0), 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow5" {
	assert nearly_equal(GslMath.pow5(3.0), 3.0 * 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow6" {
	assert nearly_equal(GslMath.pow6(3.0), 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow7" {
	assert nearly_equal(GslMath.pow7(3.0), 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow8" {
	assert nearly_equal(GslMath.pow8(3.0), 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.pow9" {
	assert nearly_equal(GslMath.pow9(3.0), 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0);
}

assure "GslMath.sign" {
	assert GslMath.sign(1) == true;
	assert GslMath.sign(0) == true;
	assert GslMath.sign(-1) == false;
}

assure "GslMath.isOdd" {
	assert GslMath.isOdd(1) == true;
	assert GslMath.isOdd(2) == false;
	assert GslMath.isOdd(0) == false;
}

assure "GslMath.isEven" {
	assert GslMath.isEven(1) == false;
	assert GslMath.isEven(2) == true;
	assert GslMath.isEven(0) == true;
}

assure "GslMath.fcmp" {
	assert GslMath.fcmp(1.00000, 1.00001, 0.0001) == 0;
	assert GslMath.fcmp(1.00000, 1.00001, 0.000001) == -1;
	assert GslMath.fcmp(1.00000, 0.99999, 0.000001) == 1;
}
