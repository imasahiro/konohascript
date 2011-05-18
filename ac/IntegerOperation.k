
assure "UnitTest:Integer Literal" {
	int i;
	i = 0x0;
	assert i == 0;
	i = 0x1;
	assert i == 1;
	i = 0xf;
	assert i == 15;
	i = 0xff;
	assert i == 255;

	assert ((0b0)  == 0);
	assert ((0b1)  == 1);
	assert ((0b10) == 2);
	assert ((0b11) == 3);
	assert (0b11 == 0x03);

}

assure "UnitTest:Integer Comparator" {
	int i1 = 1;
	int i2 = 2;
	assert ((i1 == i2) == false);
	assert ((i1 != i2) == true );
	assert ((i1 == 1)  == true );
	assert ((i1 != 1)  == false);
	assert ((i1 > i2)  == false);
	assert ((i1 < i2)  == true );
	assert ((i1 >= i2) == false);
	assert ((i1 <= i2) == true );
	assert ((i1 == 2)  == false);
	assert ((i1 != 2)  == true );
	assert ((i1 >  2)  == false);
	assert ((i1 <  2)  == true );
	assert ((i1 >= 2)  == false);
	assert ((i1 <= 2)  == true );
}

assure "UnitTest: Integer instanceof" {
	Int i1 = 0;
	assert((i1 instanceof Integer) == true);
	assert((i1 instanceof Int) == true);
	assert((i1 instanceof Object) == true);
}

assure "UnitTest: Integer negative operator" {
  int i0 = 0;
  int i1 = 1;
  assert ((-1) == -1 );
  assert ((-(1)) == -1 );
  assert ((-i0) == 0 );
  assert ((-i1) == -1 );
}

assure "Integer increment operator" {
  int i = 0;
  assert ((i) == 0);
  assert ((i++) == 0);
  assert ((i) == 1);
  assert ((i++) == 1);
  assert ((i) == 2);
}

assure "Integer increment operator" {
  int i = 0;
  assert ((i) == 0 );
  assert ((++i) == 1 );
  assert ((i) == 1 );
  assert ((++i) == 2 );
  assert ((i) == 2 );
}

assure "Integer decrement operator" {
  int i = 0;
  assert ((i) == 0 );
  assert ((i--) == 0 );
  assert ((i) == -1 );
  assert ((i--) == -1 );
  assert ((i) == -2 );
}

assure "Integer decrement operator" {
  int i = 0;
  assert ((i) == 0);
  assert ((--i) == -1);
  assert ((i) == -1);
  assert ((--i) == -2);
  assert ((i) == -2);
}

assure "Integer operator" {
  int i0 = 0;
  int i1 = 1;
  int i5 = 5;
  assert ((0 + 1) == 1 );
  assert ((0 + i1) == 1 );
  assert ((i0 + 1) == 1 );
  assert ((i0 + i1) == 1 );
  assert ((i0 + i1 + i5) == 6 );
  assert ((i0 + 0 + 1 + 5 + i1 + i5) == 12 );

  i0 = 0;
  i1 = 1;
  i5 = 5;
  assert ((0 - 1) == -1 );
  assert ((0 - i1) == -1 );
  assert ((i0 - 1) == -1 );
  assert ((i0 - i1) == -1 );
  assert ((i0 - i1 - i5) == -6 );
  assert ((i0 - 0 - 1 - 5 - i1 - i5) == -12 );

  i0 = 0;
  i1 = 1;
  i2 = 2;
  assert ((1 * 2) == 2 );
  assert ((1 * i2) == 2 );
  assert ((i2 * 1) == 2 );
  assert ((i1 * i2) == 2 );
  assert ((i1 * i2 * i0) == 0 );
  assert ((i1 * -2 * i2 * 3 * 4) == -48 );

  i1 = 1;
  i2 = 2;
  i4 = 4;
  assert ((4 / 2) == 2 );
  assert ((4 / i2) == 2 );
  assert ((i4 / 2) == 2 );
  assert ((i4 / i2) == 2 );
  assert ((i4 / i2 / i1) == 2 );
  assert ((48 / i2 / 2 / i4) == 3 );

//{
//  @UnitTest "int zero division"
//  TODO();
//  //assert ((1 / 0) == ZeroDivision!! );
//}
//

  @UnitTest ## int % operator
  i1 = 1;
  i2 = 2;
  i3 = 3;
  assert ((3 % 2) == 1 );
  assert ((i3 % 2) == 1 );
  assert ((3 % i2) == 1 );
  assert ((i3 % i2) == 1 );
  assert ((i3 % i2 % i1) == 0 );
  assert ((49 % i3 % 5 % i2) == 1 );


  i1 = 1;
  i2 = 2;
  i3 = 3;
  assert ((i3 mod 2) == 1 );
  assert ((3 mod i2) == 1 );
  assert ((i3 mod 2) == 1 );
  assert ((i3 mod i2) == 1 );
  assert ((i3 mod i2 mod i1) == 0 );
  assert ((49 mod i3 mod 5 mod i2) == 1 );

  i1 = 1;
  i2 = 2;
  i3 = 3;
  assert ((2 | 1) == 3 );
  assert ((i2 | 1) == 3 );
  assert ((2 | i1) == 3 );
  assert ((i2 | i1) == 3 );
  assert ((i2 | i3 | i1) == 3 );
  assert ((4 | i3 | 1 | i2) == 7 );

  i1 = 1;
  i2 = 2;
  i3 = 3;
  assert ((1 & 2) == 0 );
  assert ((i1 & 2) == 0 );
  assert ((1 & i2) == 0 );
  assert ((i1 & i2) == 0 );
  assert ((i3 & i1) == 1 );
  assert ((i3 & i1 & i2) == 0 );
  assert ((7 & i1 & 4 & i2) == 0 );

  i1 = 1;
  i2 = 2;
  i3 = 3;
  assert ((3 ^ 2) == 1 );
  assert ((3 ^ i2) == 1 );
  assert ((i3 ^ i2) == 1 );
  assert ((i3 ^ i2 ^ i1) == 0 );
  assert ((7 ^ i3 ^ 2 ^ i1) == 7 );

  i1 = 1;
  i3 = 3;
  i7 = 7;
  assert ((3 << 1) == 6 );
  assert ((i3 << 1) == 6 );
  assert ((3 << i1) == 6 );
  assert ((i3 << i1) == 6 );
  assert ((i7 << i1 << i3) == 112 );
  assert (((i7 << i1) << i3) == 112 );

  i1 = 1;
  i4 = 4;
  i8 = 8;
  assert ((8 >> 1) == 4 );
  assert ((i8 >> 1) == 4 );
  assert ((8 >> i1) == 4 );
  assert ((i8 >> i1) == 4 );
  assert ((i8 >> i1 >> i1) == 2 );
  assert (((i8 >> i1) >> i1) == 2 );
}

assure "type inference of Integer"
{
  Int i;
  newvar_i = 0
  assert ((newvar_i) == 0 );
  assert ((typeof(newvar_i)) == Int );
  newvar_i2 = i
  assert ((typeof(newvar_i2)) == Int );
}

assure "Integer operator with increment" {
  i1 = 1
  i2 = 2
  assert ((i1++ + 1) == 2 );
  assert ((i1) == 2 );
  i1 = 1;
  assert ((1 + i1++) == 2 );
  assert ((i1) == 2 );
  i1 = 1;
  assert ((i1++ + i2++) == 3 );
  assert ((i1) == 2 );
  assert ((i2) == 3 );
  i1 = 1;
  i2 = 2;
}

assure "Integer operator with increment" {
  i1 = 1
  i2 = 2
  assert ((++i1 + 1) == 3 );
  assert ((i1) == 2 );
  i1 = 1;
  assert ((1 + ++i1) == 3 );
  assert ((i1) == 2 );
  i1 = 1;
  assert ((++i1 + ++i2) == 5 );
  assert ((i1) == 2 );
  assert ((i2) == 3 );
  i1 = 1;
  i2 = 2;
}

assure "Integer assignment operators"
{
  i = 1;
  assert ((i += 1) == 2 );
  assert ((i) == 2 );
  i = 2
  assert ((i -= 1) == 1 );
  assert ((i) == 1 );
  i = 1;
  assert ((i *= 1) == 1 );
  assert ((i) == 1 );
  i = 4;
  assert ((i /= 2) == 2 );
  assert ((i) == 2 );
  i = 2;
  assert ((i %= 5) == 2 );
  assert ((i) == 2 );
  i = 2;
  assert ((i |= 1) == 3 );
  assert ((i) == 3 );
  i = 3;
  assert ((i &= 1) == 1 );
  assert ((i) == 1 );
  //i = 3;
  //assert ((i ^= 1) == 1 );
  //assert ((i) == 1 );
  i = 1;
  assert ((i <<= 1) == 2 );
  assert ((i) == 2 );
  i = 2;
  assert ((i >>= 1) == 1 );
  assert ((i) == 1 );
}

assure "Integer operation"
{
  i2 = 2;
  i3 = 3;
  i4 = 4;
  assert ((i2 + i3 - i4) == 1 );
  assert ((i2 + i3 / i4) == 2 );
  assert ((i2 + i3 * i4) == 14 );
  assert ((i2 + i3 % i4) == 5 );
  assert ((i2 + i3 mod i4) == 5 );
  assert ((i2 + i3 & i4) == 4 );
  assert ((i2 + i3 | i4) == 5 );
  assert ((i2 + i3 ^ i4) == 1 );
  assert ((i2 - i3 + i4) == 3 );
  assert ((i2 - i3 / i4) == 2 );
  assert ((i2 - i3 * i4) == -10 );
  assert ((i2 - i3 % i4) == -1 );
  assert ((i2 - i3 mod i4) == -1 );
  assert ((i2 - i3 & i4) == 4 );
  assert ((i2 - i3 | i4) == -1 );
  assert ((i2 - i3 ^ i4) == -5 );
  assert ((i2 / i3 + i4) == 4 );
  assert ((i2 / i3 - i4) == -4 );
  assert ((i2 / i3 * i4) == 0 );
  assert ((i2 / i3 % i4) == 0 );
  assert ((i2 / i3 mod i4) == 0 );
 //>>> (i2 / i3) & i4; /* zero division error */
 //0
  assert ((i2 / i3 | i4) == 4 );
  assert ((i2 / i3 ^ i4) == 4 );
  assert ((i2 * i3 + i4) == 10 );
  assert ((i2 * i3 - i4) == 2 );
  assert ((i2 * i3 / i4) == 1 );
  assert ((i2 * i3 % i4) == 2 );
  assert ((i2 * i3 mod i4) == 2 );
  assert ((i2 * i3 & i4) == 4 );
  assert ((i2 * i3 | i4) == 6 );
  assert ((i2 * i3 ^ i4) == 2 );
  assert ((i2 % i3 + i4) == 6 );
  assert ((i2 % i3 - i4) == -2 );
  assert ((i2 % i3 / i4) == 0 );
  assert ((i2 % i3 * i4) == 8 );
  assert ((i2 % i3 mod i4) == 2 );
 //>>> i2 % i3 & i4; /* zero division error */
 //0
  assert ((i2 % i3 | i4) == 6 );
  assert ((i2 % i3 ^ i4) == 6 );
  assert ((i2 mod i3 + i4) == 6 );
  assert ((i2 mod i3 - i4) == -2 );
  assert ((i2 mod i3 / i4) == 0 );
  assert ((i2 mod i3 * i4) == 8 );
  assert ((i2 mod i3 % i4) == 2 );
 //>>> i2 mod i3 & i4; /* zero division error */
 //0
  assert ((i2 mod i3 | i4) == 6 );
  assert ((i2 mod i3 ^ i4) == 6 );
  assert ((i2 & i3 + i4) == 2 );
  assert ((i2 & i3 - i4) == 2 );
  assert ((i2 & i3 / i4) == 0 );
  assert ((i2 & i3 * i4) == 0 );
  assert ((i2 & i3 % i4) == 2 );
  assert ((i2 & i3 mod i4) == 2 );
  assert ((i2 & i3 | i4) == 6 );
  assert ((i2 & i3 ^ i4) == 6 );
  assert ((i2 | i3 + i4) == 7 );
  assert ((i2 | i3 - i4) == -1 );
  assert ((i2 | i3 / i4) == 2 );
  assert ((i2 | i3 * i4) == 14 );
  assert ((i2 | i3 % i4) == 3 );
  assert ((i2 | i3 mod i4) == 3 );
  assert ((i2 | i3 & i4) == 2 );
  assert ((i2 | i3 ^ i4) == 7 );
  assert ((i2 ^ i3 + i4) == 5 );
  assert ((i2 ^ i3 - i4) == -3 );
  assert ((i2 ^ i3 / i4) == 2 );
  assert ((i2 ^ i3 * i4) == 14 );
  assert ((i2 ^ i3 % i4) == 1 );
  assert ((i2 ^ i3 mod i4) == 1 );
  assert ((i2 ^ i3 & i4) == 2 );
  assert ((i2 ^ i3 | i4) == 5 );
}

assure "Int.MAX" {
  assert ((max = Int.MAX) == 9223372036854775807 );
}

assure "Int.MIN" {
  assert ((min = Int.MIN) == -9223372036854775808 );
}


assure "Int boundary operation" {
  max = Int.MAX;
  min = Int.MIN;
  assert ((max + max) == -2 );
  assert ((max + min) == -1 );
  assert ((min + max) == -1 );
  assert ((min + min) == 0 );
  assert ((max - max) == 0 );
  assert ((max - min) == -1 );
  assert ((min - max) == 1 );
  assert ((min - min) == 0 );
  assert ((max * max) == 1 );
  assert ((max * min) == -9223372036854775808 );
  assert ((min * max) == -9223372036854775808 );
  assert ((min * min) == 0 );
  assert ((max / max) == 1 );
  assert ((max / min) == 0 );
  assert ((min / max) == -1 );
  assert ((min / min) == 1 );
  assert ((max++) == 9223372036854775807 );
  assert ((max) == -9223372036854775808 );
  assert ((min--) == -9223372036854775808 );
  assert ((min) == 9223372036854775807 );
}

