/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// This algorithm is used in the YNU lecture of "algorithm"

boolean ismember(int[] a, int n) {
  int i;
  for(i = 0; i < |a|; i++) {
    if(a[i] == n) return true;
  }
  return false;
}

void copytoset(int[] a, int[] b) {
  int i;
  for(i = 0; i < |a|; i++) {
    int n = a[i];
    if(not ismember(b, n)) {
      b.add(n);
    }
  }
}

assure "AlgorithmArraySet" {
	int[] a = [1, 3, 1, 2, 3, 5];
	int[] b = [];
	copytoset(a, b);
	assert |b| == 4;
	assert b[0] == 1;
	assert b[1] == 3;
	assert b[2] == 2;
	assert b[3] == 5;
}



