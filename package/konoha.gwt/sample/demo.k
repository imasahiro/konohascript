using konoha.gwt.*;

class Demo {
	Scene window;
	Application app;
	World world;
	Point[] gravity_pattern;
	int pattern_count;
	int width;
	int height;

	Demo() {
		app = new Application();
		window = new Scene();
		width = 1200;
		height = 700;
		world = new World(width, height);
		window.setItemIndexMethod(Scene.NoIndex);
		window.setSceneRect(0, 0, width, height);
		setCage();
		Texture banner = new Texture("sample/ks_logo_green.png");
		banner.setRect(new Rect(900, 450, 250, 200));
		window.addItem(banner);
		Timer t = new Timer(5000, delegate(this, changeGravity));
		t.start();
		gravity_pattern <<< new Point(0, 100);
		gravity_pattern <<< new Point(-100, 0);
		gravity_pattern <<< new Point(0, -100);
		gravity_pattern <<< new Point(100, 0);
		addDynamicObject();
	}

	void addDynamicObject() {
		for (int i = 0; i < 10; i++) {
			int r = Int.random(100);
			Rect rect = new Rect(350 - r, 300 - r, 50, 50);
			rect.setDensity(1);
			rect.setRestitution(0.5);
			rect.setColor(getRandomColor());
			world.add(rect);
			window.addItem(rect);
		}
		for (int i = 0; i < 7; i++) {
			int r = Int.random(100);
			Ellipse e = new Ellipse();
			e.setRect(new Rect(250 - r, 300 - r, 50, 50));
			e.setColor(getRandomColor());
			e.setDensity(1.0);
			world.add(e);
			window.addItem(e);
		}
		Text text = new Text("KonohaScript");
		text.setPosition(300, 100);
		text.setDensity(1.0);
		Texture texture = new Texture("sample/ks_logo.png");
		texture.setRect(new Rect(400, 300, 200, 200));
		texture.setDensity(1);
		world.add(text);
		window.addItem(text);
		world.add(texture);
		window.addItem(texture);
	}

	Color getRandomColor() {
		String color = "#";
		for (int i = 0; i < 3; i++) {
			color += "%x"(50 + Int.random(206));
		}
		return new Color(color);
	}

	void setCage() {
		Rect top = new Rect(0, 0, width, 10);
		Rect left = new Rect(0, 0, 10, height);
		Rect right = new Rect(width, 0, 10, height - 10);
		Rect bottom = new Rect(0, height - 10, width, 10);
		Color c = new Color("#90ee90");
		top.setColor(c);
		left.setColor(c);
		right.setColor(c);
		bottom.setColor(c);
		window.addItem(top);
		window.addItem(left);
		window.addItem(right);
		window.addItem(bottom);
		world.add(top);
		world.add(right);
		world.add(left);
		world.add(bottom);
	}

	void changeGravity(TimerEvent event) {
		if (pattern_count > 3) pattern_count = 0;
		Point p = gravity_pattern[pattern_count];
		world.setGravity(p.x, p.y);
		pattern_count++;
	}

	void show() {
		View view = new View(window);
		view.setViewportUpdateMode(View.FullViewportUpdate);
		view.setRenderHint(Painter.Antialiasing);
		view.show();
		world.start();
		app.exec();
	}
}

void main(String[] args)
{
	Demo d = new Demo();
	d.show();
}
