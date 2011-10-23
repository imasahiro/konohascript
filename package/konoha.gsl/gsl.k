/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

include "lib:gluelink";

@Native class GslPolyComplexWorkspace;
@Native GslPolyComplexWorkspace GslPolyComplexWorkspace.new(int size);

@Singleton @Native class GslPoly;
@Native float GslPoly.eval(float[] c, float x);
//@Native complex GslPoly.complexEval(double[] c, complex z);
//@Native complex GslPoly.complexEval(complex[] c, complex z);
@Native int GslPoly.evalDerivs(float[] c, float x, float[] res);
@Native int GslPoly.ddInit(float[] dd, float[] xa, float[] ya);
@Native float GslPoly.ddEval(float[] dd, float[] xa, float x);
@Native int GslPoly.ddTaylor(float[] c, float xp, float[] dd, float[] xa, double[] w);
@Native Tuple<float,float> GslPoly.solveQuadratic(float a, float b, float c);
//@Native Tuple<complex,complex> GslPoly.complexSolveQuadratic(float a, float b, float c);
@Native Tuple<float,float,float> GslPoly.solveCubic(float a, float b, float c);
//@Native Tuple<complex,complex,complex> GslPoly.complecSolveCubic(float a, float b, float c);
@Native float[] GslPoly.complexSolve(float[] a, GslPolyComplexWorkspace ws);

@Singleton @Native class GslStats;
@Native float GslStats.mean(float[] data);

@Native class GslPerm;
@Native GslPerm GslPerm.new(int n);
@Native int GslPerm.get(int i);
@Native int GslPerm.swap(int i, int j);
@Native int GslPerm.size();
@Native Array<int> GslPerm.data();
@Native int GslPerm.valid();
@Native void GslPerm.reverse();
@Native GslPerm GslPerm.inverse();
@Native int GslPerm.next();
@Native int GslPerm.prev();
@Native GslPerm GslPerm.mul(GslPerm pb);
@Native void GslPerm.fprintf(OutputStream out, String formatter);
@Native GslPerm GslPerm.linearToCanonical();
@Native GslPerm GslPerm.canonicalToLinear();
@Native int GslPerm.inversions();
@Native int GslPerm.linearCycles();
@Native int GslPerm.canonicalCycles();

@Native class GslComb;
@Native GslComb GslComb.new(int n, int k);
@Native void GslComb.initFirst();
@Native void GslComb.initLast();
@Narive GslComb GslComb.memcpy();
@Narive int GslComb.get(int i);
@Narive int GslComb.getN();
@Narive int GslComb.getK();
@Narive Array<Int> GslComb.getData();
@Native int GslComb.valid();
@Native GslComb GslComb.next();
@Native GslComb GslComb.prev();

@Native class GslMulti;
@Native GslMulti GslMulti.new(int n, int k);
@Native void GslMulti.initFirst();
@Native void GslMulti.initLast();
@Native GslMulti GslMulti.copy();
@Native int GslMulti.get(int i);
@Native int GslMulti.range();
@Native int GslMulti.size();
@Native Array<Int> GslMulti.getData();
@Native boolean GslMulti.valid();
@Native GslMulti GslMulti.next();
@Native GslMulti GslMulti.prev();

@Singleton @Native class GslMath;
@Native boolean GslMath.isNan(float x);
@Native int GslMath.isInf(float x);
@Native boolean GslMath.isFinite(float x);
@Native float GslMath.log1p(float x);
@Native float GslMath.expm1(float x);
@Native float GslMath.hypot(float x, float y);
@Native float GslMath.hypot3(float x, float y, float z);
@Native float GslMath.acosh(float x);
@Native float GslMath.asinh(float x);
@Native float GslMath.atanh(float x);
@Native float GslMath.ldexp(float x, int e);
@Native Tuple<float,int> GslMath.frexp(float x);
@Native float GslMath.powInt(float x, int n);
@Native float GslMath.pow2(float x);
@Native float GslMath.pow3(float x);
@Native float GslMath.pow4(float x);
@Native float GslMath.pow5(float x);
@Native float GslMath.pow6(float x);
@Native float GslMath.pow7(float x);
@Native float GslMath.pow8(float x);
@Native float GslMath.pow9(float x);
@Native boolean GslMath.sign(float x);
@Native boolean GslMath.isOdd(int x);
@Native boolean GslMath.isEven(int x);
@Native int GslMath.fcmp(double x, double y, double epsilon);
