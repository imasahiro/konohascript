/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
 
using konoha.lang.*;
using js.dom.*;
using js.jquery.*;
using js.websocket.*;

/* N must less than 10 */
N = 8;

SPACE = 0;
WHITE = 1;
BLACK = 2;
class Context {
	int[] b = null;
	int myColor;
	int currentColor;
	boolean start;
	WebSocket ws;
	void init() {
		b = new int[N, N];
		myColor = WHITE;
		currentColor = WHITE;
		start = false;
		ws = new WebSocket("ws://localhost:8080/", "othello-protocol");
	}
}
Context ctx = new Context();
ctx.init();
class Point {
	int x;
	int y;
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
String cssColor(int m) {
	if (m == 0) {
		return "#888888";
	} 
	if (m == 1) {
		return "white";
	}
	return "black";
}
String stone(int n) {
	if (n == SPACE) {
		return " .  ";
	} else if (n == WHITE) {
		return "( ) ";
	}
	return "(@) ";
}
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
			OUT <<< stone(b[x,y]);
			if(b[x,y] == WHITE) wc++;
			if(b[x,y] == BLACK) bc++;
		}
		OUT <<< EOL;
	}
	OUT <<< "Sum: " <<< (wc + bc) <<< "  ";
	OUT <<< p1 <<< ":" <<< stone(BLACK) <<< " " <<< bc <<< "  ";
	OUT <<< p2 <<< ":" <<< stone(WHITE) <<< " " <<<wc <<< EOL;
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
		JQuery jquery = new JQuery("#" + (x + "") + (y + ""));
		jquery.css("background-color", cssColor(color));
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
@Public void Element.onclick(JEvent e) {
	if (ctx.myColor != ctx.currentColor || (ctx.start == false)) return;
	JQuery jquery = new JQuery(this);
	int x = (Int)jquery.getAttr("x");
	int y = (Int)jquery.getAttr("y");
	if (board_count(ctx.b, x, y, ctx.myColor) > 0) {
		JQuery jquery = new JQuery("#" + (x + "") + (y + ""));
		jquery.css("background-color", cssColor(ctx.currentColor));
		board_put(ctx.b, x, y, ctx.myColor);
		ctx.currentColor = counter_party(ctx.currentColor);
		ctx.ws.send((ctx.myColor-1) + ":" + x + ", " + y);
	}
}
void board_init(int[] b) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			b[i,j] = SPACE;
		}
	}
	b[N/2-1,N/2-1] = WHITE;
	b[N/2, N/2] = WHITE;
	b[N/2-1,N/2] = BLACK;
	b[N/2,N/2-1] = BLACK;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			JQuery jquery = new JQuery("<div></div>");
			jquery.attr("x", j + "");
			jquery.attr("y", i + "");
			jquery.attr("id", (j + "") + (i + ""));
			jquery.css("background-color", cssColor(b[i, j]));
			jquery.css("position", "absolute");
			jquery.css("width", "40px");
			jquery.css("height", "40px");
			jquery.css("border", "4px solid green");
			jquery.css("top", 50 * (int)(i) + 5 + "");
			jquery.css("left", 50 * j + 5 + "");
			jquery.click(method:Element.onclick);
			new JQuery("body").append(jquery);
		}
	}
}
@Public void Element.onMessage(MessageEvent e) {
	String data = e.getData();
	if (data.startsWith("id")) {
		/* message = "id:0 | id:1" */
		ctx.myColor = ((int)e.getData()[3]) + 1;
	} else if (data.equals("start")) {
		ctx.start = true;
	} else if (data.equals("end")) {
		ctx.start = false;
	} else {
		/* message = "x, y" (x, y > 10)*/
		int x = (Int)data[0];
		int y = (Int)data[3];
		JQuery jquery = new JQuery("#" + (x + "") + (y + ""));
		jquery.css("background-color", cssColor(ctx.currentColor));
		board_put(ctx.b, x, y, ctx.currentColor);
		ctx.currentColor = counter_party(ctx.currentColor);
	}
}
void start_game(String pn1, String pn2) {
	board_init(ctx.b);
	ctx.ws.setOnMessage(method:Element.onMessage);
}
start_game("enemy", "you");
