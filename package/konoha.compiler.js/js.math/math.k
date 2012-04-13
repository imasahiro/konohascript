include "lib:gluelink";

@Singleton @Native class Math;

@Native @FastCall int Math.abs(int x);
@Native @FastCall float Math.fabs(float x);
@Native float Math.pow(float x,float y);
@Native float Math.ldexp(float x,int e);
@Native float Math.modf(float x,double y);
@Native float Math.frexp(float x,int y);
@Native float Math.fmod(float x,float d);
@Native @FastCall float Math.ceil(float x);
//@Native float Math.round(float x);
//@Native float Math.nearbyint(float x);
@Native @FastCall float Math.floor(float x);
@Native @FastCall float Math.sqrt(float x);
@Native @FastCall float Math.exp(float x);
@Native @FastCall float Math.log10(float x);
@Native @FastCall float Math.log(float x);
@Native @FastCall float Math.sin(float x);
@Native @FastCall float Math.cos(float x);
@Native @FastCall float Math.tan(float x);
@Native @FastCall float Math.asin(float x);
@Native @FastCall float Math.acos(float x);
@Native @FastCall float Math.atan(float x);
@Native @FastCall float Math.atan2(float x,float y);
@Native @FastCall float Math.sinh(float x);
@Native @FastCall float Math.cosh(float x);
@Native @FastCall float Math.tanh(float x);
