using konoha.gsl.*;

print "P(x) : 1 + 2x + 3x^2";
c = [ 1.0, 2.0, 3.0 ];
print "P(1.0) = " + GslPoly.eval(c, 1.0);
print "P(2.0) = " + GslPoly.eval(c, 2.0);
print "P(3.0) = " + GslPoly.eval(c, 3.0);

res = new float[4];
GslPoly.evalDerivs(c, 1.0, res);
print "P(1.0) = " + res[0];
print "P'(1.0) = " + res[1];
print "P''(1.0) = " + res[2];
print "P'''(1.0) = " + res[3];

float[] xa = [-2.0, 0, 1, 3];
float[] ya = [-39.0, 3, 6, 36];
float[] dd = new float[xa.size];
GslPoly.ddInit(dd, xa, ya);
print "ddInit ", dd;
print "ddEval ", GslPoly.ddEval(dd, xa, 0.0);
float[] w = new float[xa.size];
GslPoly.ddTaylor(c, 0.0, dd, xa, w);
print "ddTaylor ", w;

print "x^2 - 3x + 2 == 0";
print "x = " + GslPoly.solveQuadratic(1.0, -3.0, 2.0);

print "x^3 - 6x^2 + 11x - 6 == 0";
print "x = " + GslPoly.solveCubic(-6.0, 11.0, -6.0);

print "x^4 - 1 == 0"
float[] a = [ -1.0, 0, 0, 0, 1];
//res = GslPoly.complexSolve(a, new GslPolyComplexWorkspace(a.size));
res = GslPoly.complexSolve(a);
for(i=0; i<res.size/2; i++){
	print "x = " + res[i*2] + " + " + res[i*2+1] + "i";
}

