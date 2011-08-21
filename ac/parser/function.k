/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

// Konoha one liner 

int f(int n => n+1);
int g(int n) => n+1;

assure "FunctionOneLiner" {
	assert f(0) == 1;
	assert g(0) == 1;
}
