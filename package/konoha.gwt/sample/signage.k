using konoha.gwt.*;
include "sample/ar.k";

class Particle {
	Ellipse e;
	int life;

	Particle(int lifetime) {
		e = new Ellipse();
		life = lifetime;
	}
	
	void setPosition(int x, int y) {
		e.setPosition(x, y);
	}
	
	void setRect(Rect r) {
		e.setRect(r);
	}
	
	void setColor(Color c) {
		e.setColor(c);
		//e.setGlow();
	}
	
	boolean isDead() {
		if (life < 0) {
			return true;
		}
		return false;
	}
}

Vector = Tuple<int,int>;
Vector[] directions = [];
Particle[] particles = [];
Scene scene;
Group group;
int window_width = 1200;
int window_height = 600;
Timer spawn_particle_timer;
Timer move_particle_timer;
int spawn_particle_timer_id;
int move_particle_timer_id;

void move(TimerEvent event)
{
	int i = 0;
	foreach (p in particles) {
		Vector direction = directions[i];
		p.setPosition(direction[0], direction[1]);
		p.life -= 1;
		if (p.isDead()) {
			particles.remove(i);
			directions.remove(i);
			scene.removeItem(p.e);
			//group.removeFromGroup(p.e);
		}
		i++;
	}
}

void addParticle(TimerEvent event)
{
	for (int i = 0; i < 5; i++) {
		int x = Int.random(window_width);
		int y = Int.random(window_height);
		int width = Int.random(30);
		int direction_x = 5 + Int.random(10);
		int direction_y = 5 + Int.random(10);
		if (Int.random(2) == 1) {
			direction_x = -direction_x;
			if (Int.random(2) == 1) {
				direction_x = 0;
			}
		}
		if (Int.random(2) == 1) {
			direction_y = -direction_y;
			if (Int.random(2) == 1) {
				direction_y = 0;
			}
		}
		if (direction_x == 0 && direction_y == 0) {
			direction_x = 10;
		}
		int life_point = Int.random(400);
		p = new Particle(life_point);
		p.setRect(new Rect(x, y, width, width));
		p.setColor(new Color("#5f9ea0"));
		particles << p;
		directions << (direction_x, direction_y);
		//group.addToGroup(p.e);
		scene.addItem(p.e);
	}
}

Texture logo;
float scale = 0.0f;
Point prev_center;
int logo_width;
int logo_height;
float opcity = 0.0f;
float subtitle_opcity = 0.0f;
Text subtitle;
Rect background;
float scene_scale = 0.0f;

void scaleEffect(float val)
{
	Transform trans = new Transform();
	scale += 0.05;
	opcity += 0.05;
	float width = logo_width * scale;
	float height = logo_height * scale;
	logo.setSize(width, height);
	Point center = logo.getCenter();
	int div_x = prev_center.x - center.x;
	int div_y = prev_center.y - center.y;
	//print "(" + div_x + ", " + div_y + ")";
	trans.translate(div_x + window_width / 2, div_y + window_height / 2);
	trans.scale(scale, scale);
	logo.setTransform(trans);
	logo.setOpacity(opcity);
}

void opacityEffect(float val)
{
	subtitle_opcity += 0.05;
	subtitle.setOpacity(subtitle_opcity);
}

void arStart()
{
	move_particle_timer.stop(move_particle_timer_id);
	foreach (Particle p in particles) {
		scene.removeItem(p.e);
	}
	particles = [];
	directions = [];
	World world = new World();
	ar = new AR(scene, world);
	world.start();
}

int background_div_x;
int background_div_y;
float angle = 0.0f;
void sceneChangeRotateEffect(float val)
{
	if (angle > 180) {
		if (logo != null) {
			scene.removeItem(logo);
			spawn_particle_timer.stop(spawn_particle_timer_id);
			logo = null;
			TimeLine arStartTimeline = new TimeLine();
			arStartTimeLine.setDuration(4000);
			arStartTimeLine.setFinishedFunc(arStart);
			arStartTimeLine.start();
		}
		return;
	} else if (angle > 90) {
		logo.setZValue(-1);
	}
	Transform t = new Transform();
	Transform logo_trans = new Transform();
	t.translate(window_width / 2, window_height / 2);
	t.rotate(angle, Gwt.YAxis);
	t.scale(scene_scale, scene_scale);
	background.setTransform(t);
	//logo_trans.translate(-logo.center.x + window_width / 2, -logo.center.y + window_height / 2);
	//logo_trans.translate(logo.center.x / 2, logo.center.y / 2);
	logo_trans.translate(-logo.center.x + window_width / 2, -logo.center.y + window_height / 2);
	logo_trans.rotate(angle, Gwt.YAxis);
	logo_trans.scale(scene_scale, scene_scale);
	logo.setTransform(logo_trans);
	subtitle.setTransform(t);
	angle += 15;
}

void sceneChangeScaleEffect(float val)
{
	Transform background_trans = new Transform();
	Transform logo_trans = new Transform();
	scene_scale -= 0.01;
	float background_width = window_width * scene_scale;
	float background_height = window_height * scene_scale;
	float logo_width = logo_width * scene_scale;
	float logo_height = logo_height * scene_scale;
	//print background_width;
	//print background_height;
	background.setSize(background_width, background_height);
	logo.setSize(logo_width, logo_height);
	Point background_center = background.getCenter();
	Point logo_center = logo.getCenter();
	background_div_x = window_width - background_width;
	background_div_y = window_height - background_height;
	logo_div_x = -logo_center.x;
	logo_div_y = -logo_center.y;
	background_trans.translate(window_width / 2, window_height / 2);
	background_trans.scale(scene_scale, scene_scale);
	background.setTransform(background_trans);
	logo_trans.translate(logo_div_x + window_width / 2, logo_div_y + window_height / 2);
	logo_trans.scale(scene_scale, scene_scale);
	logo.setTransform(logo_trans);
	subtitle.setTransform(background_trans);
}

void sceneChangeScaleUpEffect(float val)
{
	Transform background_trans = new Transform();
	Transform logo_trans = new Transform();
	scene_scale += 0.01;
	float background_width = window_width * scene_scale;
	float background_height = window_height * scene_scale;
	float logo_width = logo_width * scene_scale;
	float logo_height = logo_height * scene_scale;
	//print background_width;
	//print background_height;
	background.setSize(background_width, background_height);
	//logo.setSize(logo_width, logo_height);
	Point background_center = background.getCenter();
	//Point logo_center = logo.getCenter();
	background_div_x = window_width - background_width;
	background_div_y = window_height - background_height;
	//logo_div_x = -logo_center.x;
	//logo_div_y = -logo_center.y;
	//print "(" + background_div_x + ", " + background_div_y + ")";
	//print "(" + logo_div_x + ", " + logo_div_y + ")";
	background_trans.translate(window_width / 2, window_height / 2);
	background_trans.scale(scene_scale, scene_scale);
	background.setTransform(background_trans);
	//logo_trans.translate(logo_div_x + window_width / 2, logo_div_y + window_height / 2);
	//logo_trans.scale(scene_scale, scene_scale);
	//logo.setTransform(logo_trans);
	//subtitle.setTransform(background_trans);
}

void sceneChange3()
{
	TimeLine t = new TimeLine();
	t.setDuration(1000);
	t.setCurveShape(TimeLine.EaseInOutCurve);
	Connector.connect(t, TimeLine.ValueChanged, sceneChangeScaleUpEffect);
	t.start();
}

void sceneChange2()
{
	TimeLine t = new TimeLine();
	t.setDuration(2000);
	t.setCurveShape(TimeLine.EaseInOutCurve);
	Connector.connect(t, TimeLine.ValueChanged, sceneChangeRotateEffect);
	t.setFinishedFunc(sceneChange3);
	t.start();
}

void sceneChange()
{
	//print "scene change!!";
	scene_scale = 1.0;
	prev_center = new Point(0, 0);
	TimeLine t = new TimeLine();
	t.setDuration(500);
	t.setCurveShape(TimeLine.EaseInOutCurve);
	Connector.connect(t, TimeLine.ValueChanged, sceneChangeScaleEffect);
	t.setFinishedFunc(sceneChange2);
	t.start();
}

void finish()
{
	TimeLine t = new TimeLine();
	t.setDuration(1000);
	t.setCurveShape(TimeLine.EaseInOutCurve);
	Connector.connect(t, TimeLine.ValueChanged, opacityEffect);
	t.start();
	subtitle.setOpacity(0);
	scene.addItem(subtitle);
	TimeLine sceneChangeTimeLine = new TimeLine();
	sceneChangeTimeLine.setDuration(4000);
	sceneChangeTimeLine.setFinishedFunc(sceneChange);
	sceneChangeTimeLine.start();
}

void main(String[] args)
{
	app = new Application();
	scene = new Scene();
	scene.setSceneRect(0, 0, window_width, window_height);
	scene.setBackgroundColor(new Color("black"));
	group = new Group();
	Transform background_trans = new Transform();
	background_trans.translate(window_width / 2, window_height / 2);
	background = new Rect(-window_width / 2, -window_height / 2,
						  window_width, window_height);
	background.setColor(new Color("white"));

	background.setTransform(background_trans);
	scene.addItem(background);

	logo = new Texture("sample/konohascript_logo.png");
	logo_width = 350;
	logo_height = 300;
	logo.setRect(new Rect(-logo_width / 2, -logo_height / 2, logo_width, logo_height));
	
	prev_center = logo.getCenter();
	timeline = new TimeLine();
	timeline.setDuration(1000);
	timeline.setCurveShape(TimeLine.EaseInOutCurve);
	timeline.setFinishedFunc(finish);
	//timeline.setCurveShape(TimeLine.LinearCurve);
	Transform trans = new Transform();
	float width = logo_width * 0.1;
	float height = logo_height * 0.1;
	logo.setSize(width, height);
	Point center = logo.getCenter();
	int div_x = prev_center.x - center.x;
	int div_y = prev_center.y - center.y;
	trans.translate(div_x + window_width / 2, div_y + window_height / 2);

	trans.scale(0.1, 0.1);
	logo.setTransform(trans);
	logo.setZValue(10);
	logo.setOpacity(0.0f);
	Connector.connect(timeline, TimeLine.ValueChanged, scaleEffect);

	//group.addToGroup(logo);
	scene.addItem(logo);

	subtitle = new Text("静的型付け言語 KonohaScriptのすべて");
	subtitle.setPosition(window_width / 2 - 220, window_height - 150);

	Font font = new Font("monaco");
	font.setPointSize(24);
	font.setStyle(Font.StyleItalic);
	font.setFixedPitch(true);
	subtitle.setColor(new Color("#5f9ea0"));
	subtitle.setFont(font);

	for (int i = 0; i < 30; i++) {
		int x = Int.random(window_width);
		int y = Int.random(window_height);
		int width = Int.random(30);
		int direction_x = 5 + Int.random(10);
		int direction_y = 5 + Int.random(10);
		if (Int.random(2) == 1) {
			direction_x = -direction_x;
		}
		if (Int.random(2) == 1) {
			direction_y = -direction_y;
		}
		p = new Particle(Int.random(400));
		p.setRect(new Rect(x, y, width, width));
		p.setColor(new Color("#5f9ea0"));
		particles << p;
		directions << (direction_x, direction_y);
		//group.addToGroup(p.e);
		scene.addItem(p.e);
	}
	scene.addItem(group);
	view = new View(scene);
	//view.setShadow(new Shadow());
	view.setViewportUpdateMode(View.FullViewportUpdate);
	view.setRenderHint(Painter.Antialiasing);
	move_particle_timer = new Timer(1000 / 30, move);
	move_particle_timer_id = move_particle_timer.start();
	spawn_particle_timer = new Timer(1000 / 30, addParticle);
	spawn_particle_timer_id = spawn_particle_timer.start();
	timeline.start();
	view.show();
	app.exec();
}
