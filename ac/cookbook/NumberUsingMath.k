/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Takuma Wakamori  twitter: @chen_ji
 ***************************************************************************/

using konoha.math.*;

CN = 1000000

assure "NumberUsingMath" {
	assert (Int)(Math.sin(Math.PI / 2) * CN) == CN;
	assert (Int)(Math.cos(0) * CN) == CN;
	assert (Int)(Math.sqrt(2.0) * CN) == 1414213; // rounded
	assert (Int)(Math.E * CN) == 2718281; // rounded
	assert (Int)(Math.PI * CN) == 3141592; // rounded
}
