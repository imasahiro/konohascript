/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Shinpei Nakata twitter: @shinpei_NKT 
 ***************************************************************************/

a = [1,3,2];
int cmp(int a, int b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

assure "SupportNativeCallback" {
	a.sort(cmp);
	assert a[0] == 1;
	assert a[1] == 2;
	assert a[2] == 3;
}
