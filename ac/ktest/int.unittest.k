
assure "inthexicalliteral"
{
	int i;
	i = 0x0;
	assert i == 0 ;
	i = 0x1;
	assert i == 1 ;
	i = 0xf;
	assert i == 15 ;
	i = 0xff;
	assert i == 255 ;
}


assure "intcomparator"
{
	int i1 = 1;
	int i2 = 2;
	assert ((i1 == i2) == false);
	assert ((i1 != i2) == true );
	assert ((i1 == 1) == true  );
	assert ((i1 != 1) == false );
	assert ((i1 > i2) == false );
	assert ((i1 < i2) == true  );
	assert ((i1 >= i2) == false);
	assert ((i1 <= i2) == true );
	assert ((i1 == 2) == false );
	assert ((i1 != 2) == true  );
	assert ((i1 > 2) == false  );
	assert ((i1 < 2) == true   );
	assert ((i1 >= 2) == false );
	assert ((i1 <= 2) == true  );
}

assure "intbinaryliteral"
{
  assert ((0b0) == 0 );
  assert ((0b1) == 1 );
  assert ((0b10) == 2 );
  assert ((0b11) == 3 );
}

assure "intvariable"
{
  int i;
  assert ((i) == 0 );
  assert ((i = 1) == 1 );
  assert ((i = i) == 1 );
  Int i = 0;
  assert ((i) == 0 );
  assert ((i = 1) == 1 );
  assert ((i = i) == 1 );
}

assure "intinstanceofInt"
{
	// by nakata
	i1 = 0;
	assert ((i1 instanceof Integer) == true );
	assert ((i1 instanceof Int) == true );
}

assure "intcomparator"
{
  // by nakata
  int i1 = 1;
  int i2 = 2;
  assert ((i1 == i2) == false );
  assert ((i1 != i2) == true );
  assert ((i1 == 1) == true );
  assert ((i1 != 1) == false );
  assert ((i1 > i2) == false );
  assert ((i1 < i2) == true );
  assert ((i1 >= i2) == false );
  assert ((i1 <= i2) == true );
  assert ((i1 == 2) == false );
  assert ((i1 != 2) == true );
  assert ((i1 > 2) == false );
  assert ((i1 < 2) == true );
  assert ((i1 >= 2) == false );
  assert ((i1 <= 2) == true );
}

assure "intnegativeoperator"
{
  i0 = 0
  i1 = 1
  assert ((-1) == -1 );
  assert ((-(1)) == -1 );
  assert ((-i0) == 0 );
  assert ((-i1) == -1 );
}

assure "inti++operator"
{
  i = 0
  assert ((i) == 0 );
  assert ((i++) == 0 );
  assert ((i) == 1 );
  assert ((i++) == 1 );
  assert ((i) == 2 );
}

assure "int++ioperator"
{
  i = 0
  assert ((i) == 0 );
  assert ((++i) == 1 );
  assert ((i) == 1 );
  assert ((++i) == 2 );
  assert ((i) == 2 );
}

assure "inti--operator"
{
  // by nakata
  i = 0;
  assert ((i) == 0 );
  assert ((i--) == 0 );
  assert ((i) == -1 );
  assert ((i--) == -1 );
  assert ((i) == -2 );
}

assure "int--ioperator"
{
  // by nakata
  i = 0;
  assert ((i) == 0 );
  assert ((--i) == -1 );
  assert ((i) == -1 );
  assert ((--i) == -2 );
  assert ((i) == -2 );
}

assure "int+operator"
{
  i0 = 0
  i1 = 1
  i5 = 5
  assert ((0 + 1) == 1 );
  assert ((0 + i1) == 1 );
  assert ((i0 + 1) == 1 );
  assert ((i0 + i1) == 1 );
  assert ((i0 + i1 + i5) == 6 );
  assert ((i0 + 0 + 1 + 5 + i1 + i5) == 12 );
}

assure "int-operator"
{
  i0 = 0
  i1 = 1
  i5 = 5
  assert ((0 - 1) == -1 );
  assert ((0 - i1) == -1 );
  assert ((i0 - 1) == -1 );
  assert ((i0 - i1) == -1 );
  assert ((i0 - i1 - i5) == -6 );
  assert ((i0 - 0 - 1 - 5 - i1 - i5) == -12 );
}

assure "int*operator"
{
  i0 = 0;
  i1 = 1;
  i2 = 2;
  assert ((1 * 2) == 2 );
  assert ((1 * i2) == 2 );
  assert ((i2 * 1) == 2 );
  assert ((i1 * i2) == 2 );
  assert ((i1 * i2 * i0) == 0 );
  assert ((i1 * -2 * i2 * 3 * 4) == -48 );
}

assure "int/operator"
{
  // by nakata
  i1 = 1;
  i2 = 2;
  i4 = 4;
  assert ((4 / 2) == 2 );
  assert ((4 / i2) == 2 );
  assert ((i4 / 2) == 2 );
  assert ((i4 / i2) == 2 );
  assert ((i4 / i2 / i1) == 2 );
  assert ((48 / i2 / 2 / i4) == 3 );
}

