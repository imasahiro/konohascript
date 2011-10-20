using konoha.gsl.*

OUT <<< "e = " + GslMath.E <<< EOL;
OUT <<< "log_2(e) = " + GslMath.LOG2E <<< EOL;
OUT <<< "log_10(e) = " + GslMath.LOG10E <<< EOL;
OUT <<< "sqrt 2 = " + GslMath.SQRT2 <<< EOL;
OUT <<< "sqrt{1/2} = " + GslMath.SQRT1_2 <<< EOL;
OUT <<< "sqrt 3 = " + GslMath.SQRT3 <<< EOL;
OUT <<< "pi = " + GslMath.PI <<< EOL;
OUT <<< "pi/2 = " + GslMath.PI_2 <<< EOL;
OUT <<< "pi/4 = " + GslMath.PI_4 <<< EOL;
OUT <<< "sqrt pi = " + GslMath.SQRTPI <<< EOL;
OUT <<< "ln(10) = " + GslMath.LN10 <<< EOL;
OUT <<< "ln(2) = " + GslMath.LN2 <<< EOL;
OUT <<< "ln(pi) = " + GslMath.LNPI <<< EOL;
OUT <<< "gamma = " + GslMath.EULER <<< EOL;

OUT <<< EOL;

OUT <<< "Is '1.0/0.0' not a number?" <<< EOL;
OUT <<< GslMath.isNan(0.0/0.0) <<< EOL;

OUT <<< EOL;

OUT <<< "Is '1.0/0.0' infinite?" <<< EOL;
OUT <<< GslMath.isInf(1.0/0.0) + "(It means that '1.0/0.0' is positive infinity.)" <<< EOL;

OUT <<< EOL;

OUT <<< "Is '1.0/0.0' real number?" <<< EOL;
OUT <<< GslMath.isFinite(1.0/0.0) <<< EOL;

OUT <<< EOL;

OUT <<< "log(1 + 3.0) = " + GslMath.log1p(3.0) <<< EOL;
OUT <<< "exp(3.0) - 1 = " + GslMath.expm1(3.0) <<< EOL;
OUT <<< "sqrt{3.0^2 + 4.0^2} = " + GslMath.hypot(1.0, 3.0) <<< EOL;
OUT <<< "sqrt{1.0^2 + 3.0^2 + 5.0^2} = " + GslMath.hypot3(1.0, 3.0, 5.0) <<< EOL;
OUT <<< "arccosh(3.0) = " + GslMath.acosh(3.0) <<< EOL;
OUT <<< "arcsinh(3.0) = " + GslMath.asinh(3.0) <<< EOL;
OUT <<< "arctanh(3.0) = " + GslMath.atanh(3.0) <<< EOL;
OUT <<< "3.0 * 2^4 = " + GslMath.ldexp(3.0, 4) <<< EOL;

OUT <<< EOL;

OUT <<< "3.0 = f * 2^e and 0.5 <=f < 1" <<< EOL;
Tuple<float, int> t = GslMath.frexp(3.0);
OUT <<< "f = " + t[0], "e = " + t[1] <<< EOL;

OUT <<< EOL;

OUT <<< "3.0^12 = " + GslMath.powInt(3.0, 12) <<< EOL;
OUT <<< "3.0^2 = " + GslMath.pow2(3.0) <<< EOL;
OUT <<< "3.0^3 = " + GslMath.pow3(3.0) <<< EOL;
OUT <<< "3.0^4 = " + GslMath.pow4(3.0) <<< EOL;
OUT <<< "3.0^5 = " + GslMath.pow5(3.0) <<< EOL;
OUT <<< "3.0^6 = " + GslMath.pow6(3.0) <<< EOL;
OUT <<< "3.0^7 = " + GslMath.pow7(3.0) <<< EOL;
OUT <<< "3.0^8 = " + GslMath.pow8(3.0) <<< EOL;
OUT <<< "3.0^9 = " + GslMath.pow9(3.0) <<< EOL;

OUT <<< EOL;

OUT <<< "Is '3' larger than '0'?" <<< EOL;
OUT <<< GslMath.sign(3) <<< EOL;

OUT <<< EOL;

OUT <<< "Is '3' odd?" <<< EOL;
OUT <<< GslMath.isOdd(3) <<< EOL;

OUT <<< EOL;

OUT <<< "Is '4' even?" <<< EOL;
OUT <<< GslMath.isEven(4) <<< EOL;

OUT <<< EOL;

OUT <<< "Is '4.000' approximately equal to '4.001?" <<< EOL;
OUT <<< GslMath.fcmp(4.000, 4.001, 0.01) + "(It means that '4.000' is approximately equal to '4.001'.)" <<< EOL;

