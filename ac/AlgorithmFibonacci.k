/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int fibo(int n) {
  if(n < 3) return 1;
  return fibo(n-1)+fibo(n-2);
}

assure "AlgorithmFibonacci" {
  n = fibo(36);
  print n;
  assert n == 14930352;
}
