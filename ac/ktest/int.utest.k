assure "int.format(%d)" {
  i123 = 123
  assert (((123).format("%d")) == "123" );
  assert (((i123).format("%d")) == "123" );
  assert (((-i123).format("%d")) == "-123" );
  assert (((i123).format("%#d")) == "123" );
  assert (((i123).format("%6d")) == "   123" );
  assert (((i123).format("%06d")) == "000123" );
  assert (((i123).format("%-6d")) == "123   " );
  assert (((i123).format("%-06d")) == "123   " );
  assert (((i123).format("%+6d")) == "  +123" );
  assert (((-i123).format("%+6d")) == "  -123" );
}

assure "Int.format(%u)" {

  i1 = 1
  assert (((i1).format("%u")) == "1" );
  assert (((-i1).format("%u")) == "18446744073709551615" );
}

assure "Int.format(%x)" {
  i1 = 1
  assert (((10).format("%x")) == "a" );
  assert (((16).format("%x")) == "10" );
  assert (((10).format("%#x")) == "0xa" );
  assert (((16).format("%#x")) == "0x10" );
  assert (((-1).format("%x")) == "ffffffffffffffff" );
  assert (((-1).format("%#x")) == "0xffffffffffffffff" );
}
