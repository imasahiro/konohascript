//
using konoha.compiler.*;
int tarai(int x, int y, int z) {
       if (x > y)
               return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
       else
               return y;
}

OUT.println(tarai(14, 7, 0));
//print tarai(12, 6, 0);

