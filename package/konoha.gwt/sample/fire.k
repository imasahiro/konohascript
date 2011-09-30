using konoha.gwt.*;
using konoha.math.*;

class Particle {
	Ellipse e;
	Texture image;
	int life;
	float opacity;

	Particle() {
		e = new Ellipse();
	}

	void setPosition(int x, int y) {
		e.setPosition(x, y);
	}
	
	void setRect(Rect r) {
		e.setRect(r);
	}
	
	void setColor(Color c) {
		e.setColor(c);
		e.setGlowCenterColor(c);
		e.setGlow();
	}
}

class ColorSmoke {
	Particle[] particles;
	Scene scene;

	ColorSmoke(int x, int y, Color c) {
		particles = [];
		int first_particle_width = 4;
		int first_block_width = 10;
		int first_block_height = 20;
		int first_block_width_half_size = first_block_width/2;
		//KONOHA's BUG !!!
		for (int i = -first_block_width_half_size; i < first_block_width_half_size; i++) {
			for (int j = -first_block_height/2; j < first_block_height/2; j++) {
				print x;
				float pos_x = x + i;
				float pos_y = y + j;
				//print x + ", " + i;
				//print pos_x + ", " + pos_y;
				Particle p = new Particle();
				p.setRect(new Rect(pos_x, pos_y, first_particle_width, first_particle_width));
				p.setColor(c);
				particles << p;
			}
		}
		int second_particle_width = 3;
		int second_block_width = 6;
		int second_block_height = 10;
		for (int i = -second_block_width/2; i < second_block_width/2; i++) {
			for (int j = -second_block_height/2; j < second_block_height/2; j++) {
				float pos_x = x + i + first_particle_width/2;
				float pos_y = y + j + first_block_height;
				Particle p = new Particle();
				p.setRect(new Rect(pos_x, pos_y, second_particle_width, second_particle_width));
				p.setColor(c);
				particles << p;
			}
		}
		int third_particle_width = 3;
		int third_block_width = 2;
		int third_block_height = 10;
		for (int i = -third_block_width/2; i < third_block_width/2; i++) {
			for (int j = -third_block_height/2; j < third_block_height/2; j++) {
				float pos_x = x + i + first_particle_width;
				float pos_y = y + j + first_block_height + second_block_height;
				Particle p = new Particle();
				p.setRect(new Rect(pos_x, pos_y, third_particle_width, third_particle_width));
				p.setColor(c);
				particles << p;
			}
		}
	}

	void addToScene(Scene scene) {
		_scene = scene;
		foreach (p in particles) {
			scene.addItem(p.e);
		}
		move_particle_timer = new Timer(1000 / 10, delegate(this, moveParticle));
		move_particle_timer_id = move_particle_timer.start();
	}

	void moveParticle(TimerEvent event) {
		int random_seed = 5;
		foreach (p in particles) {
			p.setPosition(Int.random(random_seed), Int.random(random_seed));
		}
	}
}

void main(String[] args)
{
	Application app = new ();
	scene = new Scene();
	scene.setSceneRect(0, 0, 600, 600);
	scene.setBackgroundColor(new Color("black"));

	green_smoke = new ColorSmoke(50, 50, new Color("#00ff00"));
	green_smoke.addToScene(scene);
	red_smoke = new ColorSmoke(100, 50, new Color("#ff0000"));
	red_smoke.addToScene(scene);
	yellow_smoke = new ColorSmoke(150, 50, new Color("#ffff00"));
	yellow_smoke.addToScene(scene);
	blue_smoke = new ColorSmoke(200, 50, new Color("#0000ff"));
	blue_smoke.addToScene(scene);
	white_smoke = new ColorSmoke(250, 50, new Color("#ffffff"));
	white_smoke.addToScene(scene);
	gray_smoke = new ColorSmoke(300, 50, new Color("#c9c9c9"));
	gray_smoke.addToScene(scene);

	view = new View(scene);
	view.setRenderHint(Painter.Antialiasing);
	view.show();
	app.exec();
}
