/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

assure "MapLiteral" {
	a = {}
	b = {name: "naruto", age: 17};
	assert typeof(a) == Map;
	assert typeof(b) == Map;
}

assure "MapLiteral" {
	d = {
		x: 1;
		y: 2
		z: 3,
	}
	print LINE, d["x"], d["y"], d["z"];
	print typeof(d);
	assert typeof(d) == Map;
	assert typeof(d["x"]) == dynamic;
}

assure "MapLiteral:Array" {
	d = {
		x: 1;
		y: 2
		z: 3,
		dim: 1, 2, 3
		dim2: 1, 2, 3;
		dim3: 1, 2, 3,
	}
	assert typeof(d) == Map;
	assert d["dim"] == d["dim2"];
	assert d["dim"] == d["dim3"];
	assert |d["dim"]| == 3;
}

