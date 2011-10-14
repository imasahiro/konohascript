using konoha.gsl.*;

boolean nearly_equal(float f1, float f2) {
	float diff;
	if (f1 < f2) diff = f2 - f1;
	else diff = f1 - f2;
	if (diff < 2.2204460492503131e-16/*epsilon*/) {
		return true;
	}
	print f1, f2;
	return false;
}

assure "GslPoly.eval" {
	float[] c = [ 1.0, 2.0, 3.0 ];
	assert nearly_equal(GslPoly.eval(c, 1.0), 6.0);
}

assure "GslPoly.evalDerivs" {
	float[] c = [ 1.0, 2.0, 3.0 ];
	res = new float[4];
	GslPoly.evalDerivs(c, 1.0, res);
	assert nearly_equal(res[0], 6.0);
	assert nearly_equal(res[1], 8.0);
	assert nearly_equal(res[2], 6.0);
	assert nearly_equal(res[3], 0.0);
}

float[] xa = [-2.0, 0, 1, 3];
float[] ya = [-39.0, 3, 6, 36];
float[] dd = new float[xa.size];

assure "GslPoly.ddInit" {
	GslPoly.ddInit(dd, xa, ya);
	assert nearly_equal(dd[0], -39.0);
	assert nearly_equal(dd[1], 21.0);
	assert nearly_equal(dd[2], -6.0);
	assert nearly_equal(dd[3], 2.0);
}

assure "GslPoly.ddEval" {
	assert nearly_equal(GslPoly.ddEval(dd, xa, 0.0), 3.0);
}

assure "GslPoly.ddTaylor" {
	float[] w = new float[xa.size];
	float[] c = new float[xa.size];
	GslPoly.ddTaylor(c, 1.0, dd, xa, w);
	assert nearly_equal(w[0], 0.0);
	assert nearly_equal(w[1], 3.0);
	assert nearly_equal(w[2], 4.0);
	assert nearly_equal(w[3], 1.0);
	assert nearly_equal(c[0], 6.0);
	assert nearly_equal(c[1], 3.0);
	assert nearly_equal(c[2], 2.0);
	assert nearly_equal(c[3], 2.0);
}

assure "GslPoly.solveQuadratic" {
	// x^2 - 3*x + 2 == 0
	// x = 1, 2
	x, y = GslPoly.solveQuadratic(1.0, -3.0, 2.0);
	assert nearly_equal(x, 1.0);
	assert nearly_equal(y, 2.0);
}
	
assure "GslPoly.solveCubic" {
	// x^3 - 6x^2 + 11x - 6 == 0
	// x = 1, 2, 3
	x, y, z = GslPoly.solveCubic(-6.0, 11.0, -6.0);
	assert nearly_equal(x, 1.0);
	assert nearly_equal(y, 2.0);
	assert nearly_equal(z, 3.0);
}

assure "GslPoly.complexSolve" {
	float[] a = [ -1.0, 0.0, 0.0, 0.0, 1.0]; // x^4 - 1 == 0
	float[] res = GslPoly.complexSolve(a, new GslPolyComplexWorkspace(a.size));
	assert nearly_equal(res[0], -1.0);
	assert nearly_equal(res[1], 0.0);
	/* row accuracy */
	assert (to String)res[2] == "-0.000000";
	assert (to String)res[3] == "1.000000";
	assert (to String)res[4] == "-0.000000";
	assert (to String)res[5] == "-1.000000";
	assert nearly_equal(res[6], 1.0);
	assert nearly_equal(res[7], 0.0);
}

