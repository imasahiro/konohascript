using konoha.gwt.*;

class PhysicsWorld {
	World world;
	Scene scene;
	View view;
	float rotate_duration;
	Transform trans;
	Rect ground;
	Group group;

	PhysicsWorld() {
		//world.setBeginContactEvent(delegate(this, beginContact));
		//world.setEndContactEvent(delegate(this, endContact));
		scene = new Scene();
		world = new World(scene);
		scene.setSceneRect(0, 0, 600, 600);
		//scene.setBackgroundColor(new Color("black"));
	}
	
	void addStaticObject() {
		Color static_block_color = new Color("#90ee90");
		ground = new Rect(150, 400, 300, 40);
		ground.setColor(static_block_color);
		ground.setShadow(new Shadow());
		Rect left_block = new Rect(150, 300, 10, 100);
		left_block.setColor(static_block_color);
		Rect right_block = new Rect(450 - 10, 300, 10, 100);
		right_block.setColor(static_block_color);
		right_block.setShadow(new Shadow());
		ground.setRestitution(0);
		scene.addItem(ground);
		scene.addItem(left_block);
		scene.addItem(right_block);
		world.add(left_block);
		world.add(right_block);
		world.add(ground);
	}

	void addDynamicObject() {
		for (int i = 0; i < 500; i++) {
			int r = Int.random(100);
			Ellipse e = new Ellipse();
			e.setRect(new Rect(350 - r, 300 - r, 5, 5));
			e.setDensity(1);
			e.setRestitution(0);
			e.setColor(new Color("#87ceeb"));//155 - r, 200 - r, 255 - r));
			world.add(e);
			scene.addItem(e);
		}
	}

	void fountain() {
		
	}

	void show() {
		view = new View(scene);
		view.setRenderHint(Painter.Antialiasing);
		view.show();
		world.start();
	}

	Color getRandomColor() {
		String color = "#";
		for (int i = 0; i < 3; i++) {
			color += "%x"(50 + Int.random(206));
		}
		return new Color(color);
	}

	void beginContact(dynamic obj1, dynamic obj2) {
		//print "beginContact";
		Color color1 = getRandomColor();
		Color color2 = getRandomColor();
		if (obj1.class == Rect) {
			Rect r = (Rect)obj1;
			if (!r.isStatic()) {
				r.setColor(color1);
			}
		} else if (obj1.class == Ellipse) {
			Ellipse e = (Ellipse)obj1;
			e.setColor(color1);
			e.setGlow();
		} else if (obj1.class == Texture) {
			Texture t = (Texture)obj1;
			t.setColor(color1);
		}
		if (obj2.class == Rect) {
			Rect r = (Rect)obj2;
			if (!r.isStatic()) {
				r.setColor(color2);
			}
		} else if (obj2.class == Ellipse) {
			Ellipse e = (Ellipse)obj2;
			e.setColor(color2);
			e.setGlow();
		} else if (obj2.class == Texture) {
			Texture t = (Texture)obj2;
			t.setColor(color2);
		}
	}

	void endContact(dynamic obj1, dynamic obj2) {
		//print "endContact";
		//print obj1.class;
		//print obj2.class;
	}
}

void main(String[] args)
{
	Application app = new Application();
	PhysicsWorld world = new PhysicsWorld();
	world.addStaticObject();
	world.addDynamicObject();
	world.show();
	app.exec();
}
