/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/
 
N = 8;

SPACE = 0;
WHITE = 1;
BLACK = 2;
Place = Tuple<int,int>

void board_init(int[] b) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			b[i,j] = 0;
		}
	}
	b[N/2-1,N/2-1] = WHITE;
	b[N/2, N/2] = WHITE;
	b[N/2-1,N/2] = BLACK;
	b[N/2,N/2-1] = BLACK;
}

stone = [" .  ", "( ) ", "(@) "];

void board_print(int[] b, String p1, String p2) {
	int x, y, wc = 0, bc = 0;
	OUT <<< "    ";
	for(x = 0; x < N; x++) {
		OUT <<< "[" <<< x <<< "] ";
	}
	OUT <<< EOL;
	for(y = 0; y < N; y++) {
		OUT <<< "[" <<< y <<< "] ";
		for(x = 0; x < N; x++) {
			OUT <<< stone[b[x,y]];
			if(b[x,y] == WHITE) wc++;
			if(b[x,y] == BLACK) bc++;
		}
		OUT <<< EOL;
	}
	OUT <<< "Sum: " <<< (wc + bc) <<< "  ";
	OUT <<< p1 <<< ":" <<< stone[BLACK] <<< " " <<< bc <<< "  ";
	OUT <<< p2 <<< ":" <<< stone[WHITE] <<< " " <<<wc <<< EOL;
}

int counter_party(int color) {
	if(color == WHITE) return BLACK;
	return WHITE;
}

boolean board_is(int[] b, int x, int y, int color) {
	if(0 <= x && x < N && 0 <= y && y < N) {
		return (b[x,y] == color);
	}
	if(color == SPACE) return true;
	return false;
}

int board_dcount(int[] b, int x, int y, int dx, int dy, int color) {
	int c = 1;
	while(true) {
		if(board_is(b, x, y, color)) return c;
		if(board_is(b, x, y, SPACE)) break;
		x = x + dx; y = y + dy; c++;
	}
	return 0;
}

int board_count(int[] b, int x, int y, int color) {
	int dx, dy, c = 0, p = counter_party(color);
	if(b[x,y] != SPACE) return 0;
	for(dx = -1; dx < 2; dx++) {
		for(dy = -1; dy < 2; dy++) {
			if(board_is(b, x+dx, y+dy, p)) {
				c += board_dcount(b, x+dx, y+dy, dx, dy, color);
			}
		}
	}
	return c;
}

void board_dturn(int[] b, int x, int y, int dx, int dy, int color) {
	p = counter_party(color);
	while(board_is(b, x, y, p)) {
		b[x,y] = color;
		x = x + dx; y = y + dy;
	}
}

boolean board_put(int[] b, int x, int y, int color) {
	int dx, dy, c = 0, p = counter_party(color);
	if(board_count(b, x, y, color) > 0) {
		for(dx = -1; dx < 2; dx++) {
			for(dy = -1; dy < 2; dy++) {
				int xdx = x+dx, ydy = y+dy;
				if(board_is(b, xdx, ydy, p) && board_dcount(b, xdx, ydy, dx, dy, color) > 0) {
					board_dturn(b, xdx, ydy, dx, dy, color);
				}
			}
		}
		b[x,y] = color;
		return true;
	}
	return false;
}

int board_place(int[] b, int color) {
	int x, y, c, p = 0;
	for(x = 0; x < N; x++) {
		for(y = 0; y < N; y++) {
			c = board_count(b, x, y, color);
			if(c > 0) {
				p++;
			}
		}
	}
	return p;
}

function random(int[] b, int color) {
	int x, y;
	while(true) {
		x = Int.random(N);
		y = Int.random(N);
		if(board_count(b, x, y, color) > 0) {
			break;
		}
	}
	return (x, y);
}

function eager(int[] b, int color) {
	int x, y, max = 0, mx, my;
	for(x = 0; x < N; x++) {
		for(y = 0; y < N; y++) {
			c = board_count(b, x, y, color);
			if(c > max) {
				max = c;
				mx = x; my = y;
			}
		}
	}
	return (mx, my);
}

function minimum(int[] b, int color) {
	int x, y, min = Int.MAX, mx, my;
	for(x = 0; x < N; x++) {
		for(y = 0; y < N; y++) {
			c = board_count(b, x, y, color);
			if(c > 0 && c < min) {
				min = c;
				mx = x; my = y;
			}
		}
	}
	return (mx, my);
}

function human(int[] b, int color) {
	String prompt = " - Where are you going to place " + stone[color] + "? x, y ";
	String line = System.readLine(prompt);
	if(line != null) {
		t = line.match($/(\d)\D(\d)/);
		//print line, t, |t|;
		if(|t| == 3) {
			x = (int)t[1]; y = (int)t[2];
			print line, x, y;
			if(board_count(b, x, y, color) > 0) {
				return (x, y);
			}
		}
		return random(b, color);
	}
	else {
		System.exit(0);  // Ctrl-D
	}
}

//player = random;
Player = typeof(random);

boolean play_game(int[] b, String name, Player f, int color) {
	if(board_place(b, color) > 0) {
		p = f(b, color);
		board_put(b, p[0], p[1], color);
		//OUT <<< name <<< " put " <<< p[0] <<< ", " <<< p[1] <<< EOL;
		return true;
	}
	//OUT <<< name <<< " couldn't put anywhere!!" <<< EOL;
	return false;
}

int board_testcount(int[] b) {
	int c = 0;
	for(x = 0; x < N; x++) {
		for(y = 0; y < N; y++) {
			if(b[x,y] == WHITE) c++;
		}
	}
	return c;
}

void start_game(String pn1, Player f1, String pn2, Player f2) {
	boolean isPlaying = true;
	int[] b = new int[N, N];
	board_init(b);
	board_print(b, pn1, pn2);
	while(isPlaying) {
		isPlaying = false;
		if(play_game(b, pn1, f1, BLACK)) {
			//board_print(b, pn1, pn2);
			isPlaying = true;
		}
		if(play_game(b, pn2, f2, WHITE)) {
			//board_print(b, pn1, pn2);
			isPlaying = true;
		}
	}
	OUT <<< "** Results **" <<< EOL;
	board_print(b, pn1, pn2);
	assure "OthelloAlgorithm" {
		assert board_testcount(b) == 39;
	}
}

start_game("eager", eager, "minimum", minimum);
