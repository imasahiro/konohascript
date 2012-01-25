using konoha.compiler.java.*;

KeyListener = Java_awt_event_KeyListener
KeyEvent = Java_awt_event_KeyEvent
Frame = Java_awt_Frame
Graphics = Java_awt_Graphics
Canvas = Java_awt_Canvas
Color = Java_awt_Color
Thread = Java_lang_Thread

MINO_W = 4;
MINO_H = 4;
MINO_TYPES = 7;
int[] mino;
int minoX;
int minoY;
STAGE_W = 10;
STAGE_H = 20;
int[] stage;
Canvas cv;
BLKSIZE = 24;

void setMinoBlock(int x, int y, int c) {
	mino[y*4+x] = c;
}

void initMino(int type) {
	mino = new int[MINO_W * MINO_H];
	minoX = (STAGE_W - MINO_W) / 2;
	minoY = 0;
	type += 1;
	if(type == 1) {
		setMinoBlock(1, 1, 1);
		setMinoBlock(1, 2, 1);
		setMinoBlock(2, 1, 1);
		setMinoBlock(2, 2, 1);
	} else if(type == 2) {
		setMinoBlock(1, 1, 2);
		setMinoBlock(1, 2, 2);
		setMinoBlock(2, 2, 2);
		setMinoBlock(2, 3, 2);
	} else if(type == 3) {
		setMinoBlock(3, 1, 3);
		setMinoBlock(3, 2, 3);
		setMinoBlock(2, 2, 3);
		setMinoBlock(1, 2, 3);
	} else if(type == 4) {
		setMinoBlock(1, 1, 4);
		setMinoBlock(1, 2, 4);
		setMinoBlock(1, 3, 4);
		setMinoBlock(2, 3, 4);
	} else if(type == 5) {
		setMinoBlock(2, 1, 5);
		setMinoBlock(2, 2, 5);
		setMinoBlock(2, 3, 5);
		setMinoBlock(1, 3, 5);
	} else if(type == 6) {
		setMinoBlock(2, 1, 6);
		setMinoBlock(2, 2, 6);
		setMinoBlock(1, 2, 6);
		setMinoBlock(3, 2, 6);
	} else if(type == 7) {
		setMinoBlock(1, 0, 7);
		setMinoBlock(1, 1, 7);
		setMinoBlock(1, 2, 7);
		setMinoBlock(1, 3, 7);
	}
}

int getMinoBlock(int x, int y) {
	if(x < 0 || x >= STAGE_W) return -1;
	if(y < 0 || y >= STAGE_H) return -1;
	return stage[y * STAGE_W + x];
}

int getStageOrMinoBlock(int x, int y) {
	int n = getMinoBlock(x, y);
	if(n != 0) return n;

	x -= minoX;
	y -= minoY;
	if(x < 0 || x >= MINO_W) return 0;
	if(y < 0 || y >= MINO_H) return 0;
	return mino[y * MINO_W + x];
}

boolean tryMove(int dx, int dy, int[] m) {
	int x = minoX + dx;
	int y = minoY + dy;
	for(int i=0; i<MINO_W; i++) {
		for(int j=0; j<MINO_H; j++) {
			if(m[j*MINO_W+i] != 0 && getMinoBlock(x+i, y+j) != 0) return false;
		}
	}
	minoX += dx;
	minoY += dy;
	return true;
}

void putMino(int[] m) {
	for(int i=0; i<MINO_W; i++) {
		for(int j=0; j<MINO_H; j++) {
			int m = m[j * MINO_W + i];
			if(m != 0) {
				int x = minoX + i;
				int y = minoY + j;
				if(x >= 0 && x < STAGE_W && y >= 0 && y < STAGE_H) {
					stage[y * STAGE_W + x] = m;
				}
			}
		}
	}
}

boolean tryRotateLeft() {
	int[] m = new int[MINO_W * MINO_H];
	for(int j=0; j<MINO_H; j++) {
		for(int i=0; i<MINO_W; i++) {
			m[j * MINO_W + MINO_H-i-1] = mino[i * MINO_W + j];
		}
	}
	if(tryMove(0, 0, m)) {
		mino = m;
		return true;
	} else {
		return false;
	}
}

void shiftLine(int n) {
	for(int y=n; y>=1; y--) {
		int b = y * STAGE_W;
		for(int x=0; x<STAGE_W; x++) {
			stage[b+x] = stage[b-STAGE_W+x];
		}
	}
	for(int x=0; x<STAGE_W; x++) {
		stage[x] = 0;
	}
}

void clearLines() {
	for(int y=STAGE_H-1; y>=0; y--) {
		boolean fill = true;
		for(int i=0; i<STAGE_W; i++) {
			if(getMinoBlock(i, y) == 0) {
				fill = false;
				break;
			}
		}
		if(fill) {
			shiftLine(y);
			y++;
		}
	}
}

class Lis extends KeyListener {
	@Override @Overload void keyPressed(KeyEvent e) {
		int n = e.getKeyChar();
		boolean rep = false;
		if(n == 104) {
			rep = tryMove(-1, 0, mino);
		} else
		if(n == 106) {
			rep = tryMove(0, 1, mino);
		} else
		if(n == 107) {
			rep = tryRotateLeft();
		} else
		if(n == 108) {
			rep = tryMove(1, 0, mino);
		}
		if(rep) {
			cv.repaint();
		}
	}
	@Override @Overload void keyReleased(KeyEvent e) {}
	@Override @Overload void keyTyped(KeyEvent e){}
}


class TetCanvas extends Canvas {
	TetCanvas(){} // TODO
	@Override @Overload void update(Graphics g) {
		paint(g);
	}
	@Override @Overload void paint(Graphics g) {
		g.clearRect(0, 0, BLKSIZE * STAGE_W, BLKSIZE * STAGE_H);
		for(int y=0; y<STAGE_H; y++) {
			for(int x=0; x<STAGE_W; x++) {
				int b = getStageOrMinoBlock(x, y);
				if(b != 0) {
					g.setColor(new Color(0, 0, 0));
				} else {
					g.setColor(new Color(255,255,255));
				}
				g.fillRect(BLKSIZE*x, BLKSIZE*y, BLKSIZE, BLKSIZE);
			}
		}
	}
}


void mainloop() {
	initMino(int.random(MINO_TYPES));
	while(true) {
		if(!tryMove(0, 1, mino)) {
			putMino(mino);
			clearLines();
			initMino(int.random(MINO_TYPES));
			if(!tryMove(0, 0, mino)) {
				OUT.println("GameOver");
				Java_lang_System.exit(0);
			}
		}
		cv.repaint();
		Thread.sleep(400);
	}
}

void main() {
	stage = new int[STAGE_W * STAGE_H];
	cv = new TetCanvas();
	cv.addKeyListener(new Lis());

	Frame frame = new Frame();
	frame.add(cv);
	frame.setSize(400, 600);
	frame.setVisible(true);
	
	mainloop();
}

