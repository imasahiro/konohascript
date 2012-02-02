using konoha.compiler.java.*;

KeyListener = Java_awt_event_KeyListener
KeyEvent = Java_awt_event_KeyEvent
Frame = Javax_swing_JFrame
Canvas = Javax_swing_JComponent
Graphics = Java_awt_Graphics
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
Frame frame;
BLKSIZE = 24;
Color[] colors;

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
		setMinoBlock(2, 1, 3);
		setMinoBlock(2, 2, 3);
		setMinoBlock(1, 2, 3);
		setMinoBlock(1, 3, 3);
	} else if(type == 4) {
		setMinoBlock(1, 0, 4);
		setMinoBlock(1, 1, 4);
		setMinoBlock(1, 2, 4);
		setMinoBlock(2, 2, 4);
	} else if(type == 5) {
		setMinoBlock(2, 0, 5);
		setMinoBlock(2, 1, 5);
		setMinoBlock(2, 2, 5);
		setMinoBlock(1, 2, 5);
	} else if(type == 6) {
		setMinoBlock(2, 1, 6);
		setMinoBlock(1, 2, 6);
		setMinoBlock(2, 2, 6);
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
			int block = m[j * MINO_W + i];
			if(block != 0) {
				int x = minoX + i;
				int y = minoY + j;
				if(x >= 0 && x < STAGE_W && y >= 0 && y < STAGE_H) {
					stage[y * STAGE_W + x] = block;
				}
			}
		}
	}
}

boolean tryRotateRight() {
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
			stage[b+x] = stage[b+x-STAGE_W];
		}
	}
	for(int x=0; x<STAGE_W; x++) {
		stage[x] = 0;
	}
}

int clearLines() {
	int lines = 0;
	for(int y=STAGE_H-1; y>=0; y--) {
		int x;
		for(x=0; x<STAGE_W; x++) {
			if(getMinoBlock(x, y) == 0) {
				break;
			}
		}
		if(x >= STAGE_W) {
			shiftLine(y);
			y++;
			lines++;
		}
	}
	return lines
}

class VimBindKeyListener extends KeyListener {
	@Override @Overload void keyPressed(KeyEvent e) {
		int n = e.getKeyChar();
		boolean rep = false;
		if(n == 104) { // LEFT: h
			rep = tryMove(-1, 0, mino);
		} else
		if(n == 106) { // DOWN: j
			rep = tryMove(0, 1, mino);
		} else
		if(n == 107) { // UP: k
			rep = tryRotateRight();
		} else
		if(n == 108) { // RIGHT: l
			rep = tryMove(1, 0, mino);
		}
		if(n == 113) { // q
			Java_lang_System.exit(0);
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
	@Override @Overload void paintComponent(Graphics g) {
		g.clearRect(0, 0, BLKSIZE * STAGE_W, BLKSIZE * STAGE_H);
		for(int y=0; y<STAGE_H; y++) {
			for(int x=0; x<STAGE_W; x++) {
				int b = getStageOrMinoBlock(x, y);
				g.setColor(colors[b]);
				g.fill3DRect(BLKSIZE*x, BLKSIZE*y, BLKSIZE, BLKSIZE, true);
			}
		}
	}
}

void mainloop() {
	int lines = 0;
	frame.setTitle("lines = " + lines);
	initMino(int.random(MINO_TYPES));
	while(true) {
		if(!tryMove(0, 1, mino)) {
			putMino(mino);
			lines += clearLines();
			frame.setTitle("lines = " + lines);
			initMino(int.random(MINO_TYPES));
			if(!tryMove(0, 0, mino)) {
				Javax_swing_JOptionPane.showMessageDialog(frame, "GameOver!");
				Java_lang_System.exit(0);
			}
		}
		cv.repaint();
		Thread.sleep(333);
	}
}

void main() {
	colors = new Color[8];
	colors[0] = new Color(230, 230, 230);
	colors[1] = new Color(200, 120, 120);
	colors[2] = new Color(120, 200, 120);
	colors[3] = new Color(120, 120, 200);
	colors[4] = new Color(120, 200, 200);
	colors[5] = new Color(200, 120, 200);
	colors[6] = new Color(200, 200, 120);
	colors[7] = new Color(120, 120, 120);
	
	stage = new int[STAGE_W * STAGE_H];
	cv = new TetCanvas();
	cv.setPreferredSize(new Java_awt_Dimension(STAGE_W * BLKSIZE, STAGE_H * BLKSIZE));
	frame = new Frame();
	frame.addKeyListener(new VimBindKeyListener());
	frame.add(cv);
	frame.pack();
	frame.setVisible(true);
	
	mainloop();
}

