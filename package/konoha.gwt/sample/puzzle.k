using konoha.gwt.*;
using konoha.math.*;

MAX_PANEL_NUM = 36;
HALF_PANEL_NUM = (int)Math.sqrt(MAX_PANEL_NUM);
PANEL_SIZE = 50;
PANEL_OFFSET = 100;

class Puzzle {
	Scene window;
	Application app;
	Camera c;
	Video v;
	int timer_id;
	Point prev_point;
	Rect[] panels;
	//Rect panels;
	//World world;
	
	Puzzle() {
		app = new Application();
		window = new Scene();
		//world = new World();
		window.setItemIndexMethod(Scene.NoIndex);
		window.setSceneRect(0, 0, 1200, 700);
		//window.setBackgroundColor(new Color("black"));
		Timer t = new Timer(1000 / 40, delegate(this, capture));
		c = new Camera(0);
		panels = [];
		//v = new Video("sample/sample.avi");
		for (int i = 0; i < MAX_PANEL_NUM; i++) {
			Rect panel = new Rect(0, 0, PANEL_SIZE, PANEL_SIZE);
			panel.setMousePressEvent(delegate(this, mousePressEvent));
			panel.setMouseReleaseEvent(delegate(this, mouseReleaseEvent));
			panel.setMouseMoveEvent(delegate(this, mouseMoveEvent));
			panels.add(panel);
			window.addItem(panel);
			//panel.setDensity(1);
			//world.add(panel);
		}
		//ground = new Rect(0, 590, 600, 10);
		//world.add(ground);
		//window.addItem(ground);
		int panel_num = 0;
		for (int i = 0; i < HALF_PANEL_NUM; i++) {
			for (int j = 0; j < HALF_PANEL_NUM; j++) {
				if (panel_num > MAX_PANEL_NUM) break;
				panels[panel_num].translate(PANEL_OFFSET * i + PANEL_SIZE,
											PANEL_OFFSET * j + PANEL_SIZE);
				panel_num++;
			}
		}
		timer_id = t.start();
	}

	void show() {
		View view = new View(window);
		view.setViewportUpdateMode(View.FullViewportUpdate);
		view.setRenderHint(Painter.Antialiasing);
		view.show();
		app.exec();
	}

	void capture(TimerEvent event) {
		//Texture t = v.queryFrame();
		Texture t = c.queryFrame();
		Texture[] textures = t.split(HALF_PANEL_NUM, HALF_PANEL_NUM);
		for (int i = 0; i < |textures|; i++) {
			textures[i].setRect(new Rect(0, 0, PANEL_SIZE, PANEL_SIZE));
			panels[i].setTexture(textures[i]);
		}
	}

	void mousePressEvent(Rect o, MouseEvent event) {
		Point p = event.lastScreenPos();
		prev_point = p;
	}
	
	void mouseMoveEvent(Rect o, MouseEvent event) {
		Point p = event.lastScreenPos();
		int dx = p.x - prev_point.x;
		int dy = p.y - prev_point.y;
		o.translate(dx, dy);
		prev_point = p;
	}

	void mouseReleaseEvent(Rect o, MouseEvent event) {
		//Point p = event.lastScreenPos();
	}
}

void main(String[] args)
{
	Puzzle p = new Puzzle();
	p.show();
}
