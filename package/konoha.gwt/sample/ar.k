using konoha.gwt.*;

class AR {
	Scene window;
	Application app;
	Camera c;
	int timer_id;
	Texture background;
	ComplexItem[] prev_list;
	World world;
	Texture prev_texture;
	//Rect[] default_objs;//for GC BUG

	AR(Scene win, World w) {
		_window = win;
		_world = w;
		//window.setItemIndexMethod(Scene.NoIndex);
		//window.setSceneRect(0, 0, 1200, 700);
		//window.setBackgroundColor(new Color("black"));
		//default_objs = [];
		Timer t = new Timer(1000 / 40, delegate(this, capture));
		c = new Camera(0);
		background = c.queryFrame();
		timer_id = t.start();
		window.addItem(background);
		for (int i = 0; i < 100; i++) {
			int rand_x = Int.random(1200);
			int rand_y = Int.random(200);
			Texture logo = new Texture("sample/konohascript.png");
			logo.setRect(new Rect(rand_x, rand_y, 80, 50));
			logo.setOpacity(0.9);
			logo.setDensity(1);
			//logo.setBullet(true);
			//rect.setFriction(0.3);
			logo.setRestitution(0.7);
			//rect.setColor(new Color("#87ceeb"));//155 - r, 200 - r, 255 - r));
			logo.setZValue(4);
			//default_objs.add(rect);
			world.add(logo);
			window.addItem(logo);
		}
		prev_list = [];
	}

	void show() {
		View view = new View(window);
		view.setViewportUpdateMode(View.FullViewportUpdate);
		view.setRenderHint(Painter.Antialiasing);
		view.show();
		world.start();
	}

	void capture(TimerEvent event) {
		if (prev_texture != null) {
			window.removeItem(prev_texture);
		}
		Texture t = c.queryFrame();
		Array<Array<Point>> objs = t.detectHuman(background);
		int objs_size = |objs|;
		//print objs_size;
		for (int i = 0; i < |prev_list|; i++) {
			//window.removeItem(prev_list[i]);
			world.remove(prev_list[i]);
		}
		prev_list = [];
		window.addItem(t);
		for (int i = 0; i < objs_size; i++) {
			Array<Point> obj = objs[i];
			int obj_size = |obj|;
			ComplexItem item = new ComplexItem(obj);
			item.setColor(new Color("#00ff00"));
			item.setBullet(true);
			//window.addItem(item);
			world.add(item);
			prev_list.add(item);
		}
		prev_texture = t;
	}
}

void main(String[] args)
{
	//app = new Application();
	window = new Scene();
	world = new World();
	AR ar = new AR(window, world);
	ar.show();
	//app.exec();
}
