/* converted from java package java.math */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_lang_Enum;
class Java_lang_Number;
class Java_util_Random;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_math_BigDecimal extends Java_lang_Number;
class Java_math_BigInteger extends Java_lang_Number;
class Java_math_MathContext;
class Java_math_RoundingMode extends Java_lang_Enum;

/*------------------------------------------------------------*/
/* class java.math.BigDecimal */
class Java_math_BigDecimal extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload Java_math_BigDecimal abs();
	@Virtual @Overload Java_math_BigDecimal abs(Java_math_MathContext p0);
	@Virtual @Overload Java_math_BigDecimal add(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal add(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload int byteValueExact();
	@Virtual @Overload int compareTo(Java_math_BigDecimal p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0, int p1, int p2);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0, int p1, Java_math_RoundingMode p2);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0, int p1);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0, Java_math_RoundingMode p1);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal divide(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload Java_math_BigDecimal[] divideAndRemainder(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal[] divideAndRemainder(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload Java_math_BigDecimal divideToIntegralValue(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal divideToIntegralValue(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload int intValueExact();
	@Virtual @Overload long longValueExact();
	@Virtual @Overload Java_math_BigDecimal max(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal min(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal movePointLeft(int p0);
	@Virtual @Overload Java_math_BigDecimal movePointRight(int p0);
	@Virtual @Overload Java_math_BigDecimal multiply(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal multiply(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload Java_math_BigDecimal negate();
	@Virtual @Overload Java_math_BigDecimal negate(Java_math_MathContext p0);
	@Virtual @Overload Java_math_BigDecimal plus();
	@Virtual @Overload Java_math_BigDecimal plus(Java_math_MathContext p0);
	@Virtual @Overload Java_math_BigDecimal pow(int p0);
	@Virtual @Overload Java_math_BigDecimal pow(int p0, Java_math_MathContext p1);
	@Virtual @Overload int precision();
	@Virtual @Overload Java_math_BigDecimal remainder(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal remainder(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload Java_math_BigDecimal round(Java_math_MathContext p0);
	@Virtual @Overload int scale();
	@Virtual @Overload Java_math_BigDecimal scaleByPowerOfTen(int p0);
	@Virtual @Overload Java_math_BigDecimal setScale(int p0, Java_math_RoundingMode p1);
	@Virtual @Overload Java_math_BigDecimal setScale(int p0, int p1);
	@Virtual @Overload Java_math_BigDecimal setScale(int p0);
	@Virtual @Overload int shortValueExact();
	@Virtual @Overload int signum();
	@Virtual @Overload Java_math_BigDecimal stripTrailingZeros();
	@Virtual @Overload Java_math_BigDecimal subtract(Java_math_BigDecimal p0);
	@Virtual @Overload Java_math_BigDecimal subtract(Java_math_BigDecimal p0, Java_math_MathContext p1);
	@Virtual @Overload Java_math_BigInteger toBigInteger();
	@Virtual @Overload Java_math_BigInteger toBigIntegerExact();
	@Virtual @Overload String toEngineeringString();
	@Virtual @Overload String toPlainString();
	@Virtual @Overload Java_math_BigDecimal ulp();
	@Virtual @Overload Java_math_BigInteger unscaledValue();
	@Virtual @Overload Java_math_BigDecimal valueOf(long p0, int p1);
	@Virtual @Overload Java_math_BigDecimal valueOf(long p0);
	@Virtual @Overload Java_math_BigDecimal valueOf(double p0);
}
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int[] p0, int p1, int p2);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int[] p0, int p1, int p2, Java_math_MathContext p3);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int[] p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int[] p0, Java_math_MathContext p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(String p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(String p0, Java_math_MathContext p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(double p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(double p0, Java_math_MathContext p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(Java_math_BigInteger p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(Java_math_BigInteger p0, Java_math_MathContext p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(Java_math_BigInteger p0, int p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(Java_math_BigInteger p0, int p1, Java_math_MathContext p2);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(int p0, Java_math_MathContext p1);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(long p0);
@Overload Java_math_BigDecimal Java_math_BigDecimal.new(long p0, Java_math_MathContext p1);
/* class java.math.BigInteger */
class Java_math_BigInteger extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload Java_math_BigInteger abs();
	@Virtual @Overload Java_math_BigInteger add(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger and(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger andNot(Java_math_BigInteger p0);
	@Virtual @Overload int bitCount();
	@Virtual @Overload int bitLength();
	@Virtual @Overload Java_math_BigInteger clearBit(int p0);
	@Virtual @Overload int compareTo(Java_math_BigInteger p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_math_BigInteger divide(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger[] divideAndRemainder(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger flipBit(int p0);
	@Virtual @Overload Java_math_BigInteger gcd(Java_math_BigInteger p0);
	@Virtual @Overload int getLowestSetBit();
	@Virtual @Overload boolean isProbablePrime(int p0);
	@Virtual @Overload Java_math_BigInteger max(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger min(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger mod(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger modInverse(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger modPow(Java_math_BigInteger p0, Java_math_BigInteger p1);
	@Virtual @Overload Java_math_BigInteger multiply(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger negate();
	@Virtual @Overload Java_math_BigInteger nextProbablePrime();
	@Virtual @Overload Java_math_BigInteger not();
	@Virtual @Overload Java_math_BigInteger or(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger pow(int p0);
	@Virtual @Overload Java_math_BigInteger probablePrime(int p0, Java_util_Random p1);
	@Virtual @Overload Java_math_BigInteger remainder(Java_math_BigInteger p0);
	@Virtual @Overload Java_math_BigInteger setBit(int p0);
	@Virtual @Overload Java_math_BigInteger shiftLeft(int p0);
	@Virtual @Overload Java_math_BigInteger shiftRight(int p0);
	@Virtual @Overload int signum();
	@Virtual @Overload Java_math_BigInteger subtract(Java_math_BigInteger p0);
	@Virtual @Overload boolean testBit(int p0);
	@Virtual @Overload int[] toByteArray();
	@Virtual @Overload String toString(int p0);
	@Virtual @Overload Java_math_BigInteger valueOf(long p0);
	@Virtual @Overload Java_math_BigInteger xor(Java_math_BigInteger p0);
}
@Overload Java_math_BigInteger Java_math_BigInteger.new(int[] p0);
@Overload Java_math_BigInteger Java_math_BigInteger.new(int p0, int[] p1);
@Overload Java_math_BigInteger Java_math_BigInteger.new(String p0, int p1);
@Overload Java_math_BigInteger Java_math_BigInteger.new(String p0);
@Overload Java_math_BigInteger Java_math_BigInteger.new(int p0, Java_util_Random p1);
@Overload Java_math_BigInteger Java_math_BigInteger.new(int p0, int p1, Java_util_Random p2);
/* class java.math.MathContext */
class Java_math_MathContext {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int getPrecision();
	@Virtual @Overload Java_math_RoundingMode getRoundingMode();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
}
@Overload Java_math_MathContext Java_math_MathContext.new(int p0);
@Overload Java_math_MathContext Java_math_MathContext.new(int p0, Java_math_RoundingMode p1);
@Overload Java_math_MathContext Java_math_MathContext.new(String p0);
/* class java.math.RoundingMode */
class Java_math_RoundingMode extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload Java_math_RoundingMode valueOf(String p0);
	@Virtual @Overload Java_math_RoundingMode valueOf(int p0);
	@Virtual @Overload Java_math_RoundingMode[] values();
}

/*------------------------------------------------------------*/
/* short names */
BigDecimal = Java_math_BigDecimal
BigInteger = Java_math_BigInteger
MathContext = Java_math_MathContext
RoundingMode = Java_math_RoundingMode
