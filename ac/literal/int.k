/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by @imasahiro
 *  added   by @konohakun  
 ***************************************************************************/

assure "IntegerLiteral" {
	int i;
	i = 0x0;
	assert i == 0;
	i = 0x1;
	assert i == 1;
	i = 0xf;
	assert i == 15;
	i = 0xff;
	assert i == 255;
	i = 10_000;
	assert i == 10000;
	
	assert ((0b0)  == 0);
	assert ((0b1)  == 1);
	assert ((0b10) == 2);
	assert ((0b11) == 3);
	assert (0b11 == 0x03);

}

