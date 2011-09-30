using konoha.gwt.*;
using konoha.math.*;
using konoha.posix.*;

class Particle {
	Ellipse e;
	Texture image;
	int life;
	float opacity;

	Particle(int lifetime) {
		e = new Ellipse();
		life = lifetime;
		opacity = 1.0f;
	}

	/*
	Particle(Texture image, int lifetime) {
		life = lifetime;
		_image = image;
		opacity = 1.0f;
	}
	*/

	void setPosition(int x, int y) {
		e.setPosition(x, y);
		//image.setPosition(x, y);
	}
	
	void setRect(Rect r) {
		e.setRect(r);
		//image.setRect(r);
	}
	
	void setColor(Color c) {
		e.setColor(c);
		e.setGlow();
	}

	boolean isDead() {
		if (life < 0) {
			return true;
		}
		return false;
	}
}

Vector = Tuple<float,float>;
Emitter = Ellipse;

class Glow {
	Scene scene;
	Vector[] directions = [];
	Particle[] particles = [];
	Emitter emitter;
	Timer move_particle_timer;
	boolean mousePressed;
	Timer mouse_hold_timer;
	int mouse_hold_timer_id;
	Point point;
	float opacity;
	Texture[] images;

	Glow() {
		mousePressed = false;
		scene = new Scene();
		emitter = new Ellipse();
		emitter.setRect(new Rect(0, 0, 40, 40));
		emitter.setColor(new Color("#00ff00"));
		emitter.setGlow();
		scene.addItem(emitter);
		scene.setSceneRect(0, 0, 600, 600);
		scene.setBackgroundColor(new Color("black"));
		scene.setMousePressEvent(delegate(this, mousePressEvent));
		scene.setMouseReleaseEvent(delegate(this, mouseReleaseEvent));
		scene.setMouseMoveEvent(delegate(this, mouseMoveEvent));
		move_particle_timer = new Timer(1000 / 60, delegate(this, moveParticle));
		move_particle_timer_id = move_particle_timer.start();
	}

	void mousePressEvent(Scene scene, MouseEvent event) {
		mouse_hold_timer = new Timer(1000 / 20, delegate(this, mouseHoldEvent));
		mouse_hold_timer_id = mouse_hold_timer.start();
		point = event.scenePos();
		//print point.x + ", " + point.y;
		emitter.setPosition(point.x / 2 - 10, point.y / 2 - 10);
		mousePressed = true;
	}

	void mouseMoveEvent(Scene scene, MoveEvent event) {
		Point point = event.scenePos();
		if (!isMousePressed()) {
			emitter.setPosition(point.x - 20, point.y - 20);
		}
	}

	boolean isMousePressed() {
		return mousePressed;
	}

	void mouseReleaseEvent(Scene scene, MouseEvent event) {
		Point point = event.scenePos();
		emitter.setColor(new Color("#00ff00"));
		emitter.setPosition(point.x / 2 - 10, point.y / 2 - 10);
		emitter.setGlow();
		mousePressed = false;
		mouse_hold_timer.stop(mouse_hold_timer_id);
	}

	void mouseHoldEvent(TimerEvent event) {
		Point point = point;
		int x = point.x;
		int y = point.y;
		emitter.setColor(new Color("#ffa500"));
		//emitter.setPosition(150, 150);
		emitter.setPosition(point.x / 2 - 10, point.y / 2 - 10);
		emitter.setGlow();
		int width = 5;
		//foreach (Particle p in particles) {
		//scene.removeItem(p.e);
		//}
		//particles = [];
		//directions = [];
		if (|particles| > 0) return;
		for (int angle = 0; angle < 360; angle+=8) {
			float dx = Math.sin(Math.PI * angle / 180);
			float dy = Math.cos(Math.PI * angle / 180);
			for (int i = 0; i < 6; i++) {
				float direction_x = dx * i * 5;
				float direction_y = dy * i * 5;
				//print "(" + direction_x + ", " + direction_y + ")";
				//int life_point = Int.random(100);
				Particle p = new Particle(20);
				p.setRect(new Rect(x, y, width, width));
				//rand = Int.random(238);
				//p.setColor(new Color("#ff" + "%x"(rand + 17) + "00"));
				switch (i) {
				case 0:
					p.setColor(new Color("#ffffff"));//white
					break;
				case 1:
					p.setColor(new Color("#ffffff"));//white
					break;
				case 2:
					p.setColor(new Color("#ffff00"));//yellow
					break;
				case 3:
					p.setColor(new Color("#ff6347"));//tomato
					break;
				case 4:
					p.setColor(new Color("#ff0000"));//red
					break;
				case 5:
					p.setColor(new Color("#ff1493"));//hotpink
					break;
				default:
					break;
				}
				scene.addItem(p.e);
				//scene.addItem(p.image);
				particles << p;
				directions << (direction_x, direction_y);
			}
		}
	}

	void moveParticle(TimerEvent event) {
		int i = 0;
		foreach (p in particles) {
			Vector direction = directions[i];
			//int accel = 3;
			//direction[0] *= Int.random(accel);
			//direction[1] *= Int.random(accel);
			direction[0] *= 1.1;
			direction[1] *= 1.1;
			p.setPosition(direction[0], direction[1]);
			p.life -= 1;
			p.opacity -= 0.1;
			//p.e.setOpacity(p.opacity);
			if (p.isDead()) {
				particles.remove(i);
				directions.remove(i);
				scene.removeItem(p.e);
				//scene.removeItem(p.image);
			}
			i++;
		}
		scene.update(0, 0, 600, 600);
	}

	void show() {
		view = new View(scene);
		view.setMouseTracking(true);
		view.setRenderHint(Painter.Antialiasing);
		view.show();
	}

}

void main(String[] args)
{
	Application app = new ();
	glow = new Glow();
	glow.show();
	app.exec();
}
