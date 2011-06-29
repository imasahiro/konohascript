/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// this function doesn't work if the optimazaiton of tail recursion failed.

int gcd_calc(int u,int v){
	if(u > v){
  		return gcd_calc(u-v,v);
 	} else if(u < v) {
  		return gcd_calc(u,v-u);
 	}
 	return u;
}

assure "CompilerTailRecursion" {
	print gcd_calc(16,24);
}

