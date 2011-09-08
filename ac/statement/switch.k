/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Masahiro Ide  twitter: @imasahiro
 ***************************************************************************/

int fswitch0(int n) {
	switch (n) {
		case 0:
			return 1;
			break;
		default:
			return 2;
			break;
	}
	return n;
}

assure "StatementSwitch" {
	assert fswitch0(0) == 1;
	assert fswitch0(1) == 2;
	assert fswitch0(2) == 2;
}
int fswitch1(int n, int m) {
	switch (n) {
		case 0:
			return 1;
			break;
		case 1:
			switch (m) {
				case 1:
					n += 1;
					break;
				case 2:
					n += 2;
					break;
			}
			return n;
			break;
		default:
			return 2;
			break;
	}
	return n;
}

assure "StatementSwitch:Nested" {
	assert fswitch1(0, 0) == 1;
	assert fswitch1(1, 0) == 1;
	assert fswitch1(1, 1) == 2;
	assert fswitch1(1, 2) == 3;
	assert fswitch1(2, 0) == 2;
	assert fswitch1(3, 0) == 2;
}

ZERO = 0;
int fswitch2(int n) {
	switch (n) {
		case ZERO:
			return 1;
			break;
		case 1:
		case 2:
			n += 2;
			break;
		case 3:
			n += 3;
		case 4:
			n += 4;
			break;
	}
	return n;
}

assure "StatementSwitch:FALL_THROUGH" {
	assert fswitch2(0) == 1;
	assert fswitch2(1) == 3;
	assert fswitch2(2) == 4;
	assert fswitch2(3) == 10;
	assert fswitch2(4) == 8;
	assert fswitch2(5) == 5;
}

