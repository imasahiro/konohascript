/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

assure "NumberRandom" {
	Int n = 6;
	Int ri = Int.random(n);
	Float rf = Float.random();
	assert 0 <= ri and ri < 6;
	assert 0.0 <= rf and rf < 1.0;
}

assure "FixedPatternRandom" {
	System.setRandomSeed(1);
	Int n = 6;
	Int[] ra0 = [], ra1 = [];
	ra0.add(Int.random(n));
	ra0.add(Int.random(n));
	ra0.add(Int.random(n));
	System.setRandomSeed(1);
	ra1.add(Int.random(n));
	ra1.add(Int.random(n));
	ra1.add(Int.random(n));
	for (i = 0; i < |ra0|; i++) {
		assert ra0[i] == ra1[i];
	}
}
