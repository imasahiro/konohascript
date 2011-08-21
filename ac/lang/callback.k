/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Shinpei Nakata twitter: @shinpei_NKT 
 ***************************************************************************/

/**
ia = [1,3,2];
int cmp_i(int a, int b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

assure "SupportNativeCallback Int" {
	ia.sort(cmp_i);
	assert ia[0] == 1;
	assert ia[1] == 2;
	assert ia[2] == 3;
}

fa = [1.0, 3.0, 2.0];

int cmp_f (float a, float b) {
	if (a < b) return -1.0;
	if (a > b) return 1.0;
	return 0.0;
}

assure "SupportNativeCallback Float" {
	fa.sort(cmp_f);
	assert fa[0] == 1.0;
	assert fa[1] == 2.0;
	assert fa[2] == 3.0;
}

sa = ["1.0", "3.0", "2.0"];

int cmp_s (String a, String b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

assure "SupportNativeCallback String" {
	sa.sort(cmp_s);
	assert sa[0] == "1.0";
	assert sa[1] == "2.0";
	assert sa[2] == "3.0";
}
**/

