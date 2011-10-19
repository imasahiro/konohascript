using konoha.gsl.*

print "e = " + GslMath.E;
print "log_2(e) = " + GslMath.LOG2E;
print "log_10(e) = " + GslMath.LOG10E;
print "sqrt 2 = " + GslMath.SQRT2;
print "sqrt{1/2} = " + GslMath.SQRT1_2;
print "sqrt 3 = " + GslMath.SQRT3;
print "pi = " + GslMath.PI;
print "pi/2 = " + GslMath.PI_2;
print "pi/4 = " + GslMath.PI_4;
print "sqrt pi = " + GslMath.SQRTPI;
print "ln(10) = " + GslMath.LN10;
print "ln(2) = " + GslMath.LN2;
print "ln(pi) = " + GslMath.LNPI;
print "gamma = " + GslMath.EULER;

OUT <<< EOL;

print "Is '1.0/0.0' not a number?";
print GslMath.isNan(0.0/0.0);

OUT <<< EOL;

print "Is '1.0/0.0' infinite?";
print GslMath.isInf(1.0/0.0) + "(It means that '1.0/0.0' is positive infinity.)";

OUT <<< EOL;

print "Is '1.0/0.0' real number?"
print GslMath.finite(1.0/0.0);

OUT <<< EOL;

print "log(1 + 3.0) = " + GslMath.log1p(3.0);
print "exp(3.0) - 1 = " + GslMath.expm1(3.0);
print "sqrt{3.0^2 + 4.0^2} = " + GslMath.hypot(1.0, 3.0);
print "sqrt{1.0^2 + 3.0^2 + 5.0^2} = " + GslMath.hypot3(1.0, 3.0, 5.0);
print "arccosh(3.0) = " + GslMath.acosh(3.0);
print "arcsinh(3.0) = " + GslMath.asinh(3.0);
print "arctanh(3.0) = " + GslMath.atanh(3.0);
print "3.0 * 2^4 = " + GslMath.ldexp(3.0, 4);

OUT <<< EOL;

print "3.0 = f * 2^e and 0.5 <=f < 1";
Tuple<float, int> t = GslMath.frexp(3.0);
print "f = " + t[0], "e = " + t[1];

OUT <<< EOL;

print "3.0^12 = " + GslMath.powInt(3.0, 12);
print "3.0^2 = " + GslMath.pow2(3.0);
print "3.0^3 = " + GslMath.pow3(3.0);
print "3.0^4 = " + GslMath.pow4(3.0);
print "3.0^5 = " + GslMath.pow5(3.0);
print "3.0^6 = " + GslMath.pow6(3.0);
print "3.0^7 = " + GslMath.pow7(3.0);
print "3.0^8 = " + GslMath.pow8(3.0);
print "3.0^9 = " + GslMath.pow9(3.0);

OUT <<< EOL;

print "Is '3' larger than '0'?";
print GslMath.sign(3);

OUT <<< EOL;

print "Is '3' odd?";
print GslMath.isOdd(3);

OUT <<< EOL;

print "Is '4' even?";
print GslMath.isEven(4);

OUT <<< EOL;

print "Is '4.000' approximately equal to '4.001?";
print GslMath.fcmp(4.000, 4.001, 0.01) + "(It means that '4.000' is approximately equal to '4.001'.)";

