/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

int ack(int x, int y) {
	if(x == 0) return y + 1;
	if(y == 0) return ack(x-1, 1);
	return ack(x-1, ack(x, y-1));
}

assure "SupportStackExtension" {
	print ack(3,6);
}

