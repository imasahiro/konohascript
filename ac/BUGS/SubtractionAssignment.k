/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by chen_ji twitter: @chen_ji
 ***************************************************************************/

assure "SubtractionAssignment(-=)" {
	int a = 1;
	a -= 5 - 3;
	assert (a == -1);
}
