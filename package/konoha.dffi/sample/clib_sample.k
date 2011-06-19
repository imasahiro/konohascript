using konoha.dffi.*;

Clib c = new Clib("/usr/lib/libm.dylib");
Dglue d = c.genGlue();

Func<Float=>Float> sin = d.getFunc("sin"); /* typing */
print sin(1.5);

Func<Float=>Float> cos = d.getFunc("cos");
print cos(1.0);
