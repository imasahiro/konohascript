using konoha.qt4.*;
using konoha.qt4.physics.*;
using konoha.qt4.opencv.*;
using konoha.math.*;
include "sample/util.k";
float game_scale = 0.5f;
float max_distance = 100 / game_scale;
QPointF fire_point;

class AngryBird {
	QGraphicsComplexItem bird;
	QGraphicsPixmapItem pixmap;
	int width;
	int height;
	int force_power;
	QWorld world;
	QGraphicsItemGroup contents;
	QGraphicsScene scene;
	QPointF edge1;
	QPointF edge2;
	QGraphicsPathItem path1;
	QGraphicsPathItem path2;
	QTimer camera_move_timer;

	AngryBird(int x, int y, int width, int height) {
		_width = width;
		_height = height;
		_force_power = 25;
		QImage image = new QImage();
		image.load("sample/AngryRedBird.png");
		QSize size = new QSize();
		size.setWidth(width);
		size.setHeight(height);
		image = image.scaled(size);
		QPointF[][] pts_list = image.edgePointsUsingAlpha;
		QPixmap pixmap = new QPixmap();
		pixmap = pixmap.fromImageOL(image);
		QGraphicsPixmapItem i = new QGraphicsPixmapItem();
		i.setPixmap(pixmap);
		i.setZValue(-1);
		int max = 0;
		int idx = 0;
		for (int i = 0; i < pts_list.size; i++) {
			QPointF[] pts = pts_list[i];
			int size = |pts|;
			if (max < size) {
				max = size;
				idx = i;
			}
		}
		_pixmap = i;
		bird = new (pts_list[idx]);
		bird.setZValue(0);
		bird.addToGroup(i);
		bird.setDensity(1);
		bird.setPos(new_QPointF(x, y));
		bird.addEvent("mouse-press-event", delegate(this, mousePressEvent));
		bird.addEvent("mouse-move-event", delegate(this, mouseMoveEvent));
		bird.addEvent("mouse-release-event", delegate(this, mouseReleaseEvent));
	}

	void setScene(QGraphicsScene scene) {
		_scene = scene;
		scene.addItem(bird);
	}

	void setWorld(QWorld world) {
		_world = world;
	}

	void setContents(QGraphicsItemGroup contents) {
		_contents = contents;
		contents.addToGroup(bird);
	}

	void setEdgePoint(QPointF edge1, QPointF edge2) {
		_edge1 = edge1;
		_edge2 = edge2;
	}

	void mousePressEvent(QGraphicsComplexItem bird, QGraphicsSceneMouseEvent event) {
		QPointF pos = event.scenePos();
		float x = pos.x - width/2;
		float y = pos.y - height/2;
		bird.setPos(new_QPointF(x, y));
		path1 = new ();
		path2 = new ();
		path1.setPen(new_QPen("black", 5));
		path1.setZValue(1);
		path2.setPen(new_QPen("black", 5));
		path2.setZValue(-2);
		scene.addItem(path1);
		scene.addItem(path2);
	}

	void mouseMoveEvent(QGraphicsComplexItem bird, QGraphicsSceneMouseEvent event) {
		QPointF pos = event.scenePos();
		float x = pos.x - width/2;
		float y = pos.y - height/2;
		float dx = fire_point.x - width/2 - x;
		float dy = fire_point.y - height/2 - y;
		float d = Math.sqrt(dx * dx + dy * dy);
		if (d < max_distance) {
			bird.setPos(new_QPointF(x, y));
			QPainterPath path = new ();
			path.moveTo(edge1);
			dx = pos.x - fire_point.x;
			dy = pos.y - fire_point.y;
			d = Math.sqrt(dx * dx + dy * dy);
			r = width/2;
			x = (d + r) * dx / d + fire_point.x;
			y = (d + r) * dy / d + fire_point.y;
			path.lineTo(new_QPointF(x, y));
			path1.setPath(path);
			path = new ();
			path.moveTo(edge2);
			path.lineTo(new_QPointF(x, y));
			path2.setPath(path);
		} else {
			x = fire_point.x - width/2 - max_distance * dx / d;
			y = fire_point.y - height/2 - max_distance * dy / d;
			bird.setPos(new_QPointF(x, y));
			dx = x + width/2 - fire_point.x;
			dy = y + height/2 - fire_point.y;
			d = Math.sqrt(dx * dx + dy * dy);
			r = width/2;
			x = (d + r) * dx / d + fire_point.x;
			y = (d + r) * dy / d + fire_point.y;
			QPainterPath path = new ();
			path.moveTo(edge1);
			path.lineTo(new_QPointF(x, y));
			path1.setPath(path);
			path = new ();
			path.moveTo(edge2);
			path.lineTo(new_QPointF(x, y));
			path2.setPath(path);
		}
	}

	void mouseReleaseEvent(QGraphicsComplexItem bird, QGraphicsSceneMouseEvent event) {
		world.add(bird);
		QMassData data = bird.massData;
		//data.setMass(data.mass);
		bird.setMassData(data);
		QPointF pos = bird.pos;
		bird.setXForm(pos, 0);
		float xforce = fire_point.x - width/2 - pos.x;
		float yforce = fire_point.y - height/2 - pos.y;
		QPointF force = new_QPointF(xforce * force_power, yforce * force_power);
		bird.applyForce(force, new_QPointF(pos.x + data.centerPos.x, pos.y + data.centerPos.y));
		scene.removeItem(path1);
		scene.removeItem(path2);
		camera_move_timer.start(1000/30);
	}
}

class GameManager {
	QGraphicsScene scene;
	QGraphicsView view;
	QGraphicsItem[] items;
	QWorld world;
	AngryBird bird;
	float game_scale;
	int x;
	int y;
	int width;
	int height;
	QPointF edge1;
	QPointF edge2;
	float camera_pos;
	QTimer timer;

	GameManager(int x, int y, int width, int height) {
		camera_pos = 0.0f;
		game_scale = 0.5f;
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		scene = new ();
		items = [];
		QRectF r = new QRectF();
		r.setRect(x, y, _width / game_scale, _height /game_scale);
		scene.setSceneRect(r);
		world = new QWorld(scene);
		world.setGravity(0.0f, -5.0f);
		fire_point = new_QPointF((100 + 50)/game_scale, (300 + 50)/game_scale);
		AngryBird bird = new AngryBird(100/game_scale, 300/game_scale, 100, 100);
		bird.setScene(scene);
		bird.setWorld(world);
		items << bird.bird;
		timer = new QTimer();
		timer.addEvent("timer-event", delegate(this, timerEvent));
		bird.camera_move_timer = timer;
		_bird = bird;
		QGraphicsEllipseItem bird_center = new QGraphicsEllipseItem();
		bird_center.setRect(new_QRectF(fire_point.x - 200, fire_point.y - 200, 400, 400));
		bird_center.setZValue(-3);
		scene.addItem(bird_center);
		QGraphicsRectItem ground = new QGraphicsRectItem();
		ground.setRect(new_QRectF(-width, height / game_scale - 50, 3 * width / game_scale, 50));
		ground.setBrush(new_QBrush(new_QColor("#90ee90")));
		items << ground;
		scene.addItem(ground);
		world.add(ground);
		edge1 = new_QPointF(fire_point.x - 20, fire_point.y + 20);
		edge2 = new_QPointF(fire_point.x + 10, fire_point.y + 10);
		bird.setEdgePoint(edge1, edge2);
	}

	void mouseWheelEvent(QGraphicsView view, QWheelEvent event) {
		int delta = event.delta();
		game_scale += delta * 0.0001;
		if (game_scale < 0.1) {
			game_scale = 0.1;
		} else if (game_scale > 1.0) {
			game_scale = 1.0;
		}
		p = view.pos();
		QTransform trans = new ();
		trans.translate(p.x + width/2, p.y + height/2);
		trans.scale(game_scale, game_scale);
		trans.translate(-p.x - width/2, -p.y - height/2);
		view.setTransform(trans);
	}

	void mousePressEvent(QGraphicsView view, QGraphicsSceneMouseEvent event) {
		
	}

	void timerEvent(QTimer timer, QTimerEvent event) {
		camera_pos += 60;
		if (camera_pos > 6000) {
			timer.stop();
		}
		view.centerOn(new_QPointF(camera_pos, 0));
	}
	
	void startGameEngine() {
		view = new ();
		view.addEvent("wheel-event", delegate(this, mouseWheelEvent));
		view.addEvent("mouse-press-event", delegate(this, mousePressEvent));
		QPixmap p = new QPixmap();
		p.load("sample/sky.jpg");
		QBrush b = new QBrush();
		view.setBackgroundBrush(new_QBrush(new_QColor("#add8e6")));
		b.setTexture(p);
		view.setScene(scene);
		QTransform trans = new ();
		trans.translate(x + width/2, y + height/2);
		trans.scale(game_scale, game_scale);
		trans.translate(-x - width/2, -y - height/2);
		view.setViewportUpdateMode(QGraphicsView.FullViewportUpdate);
		view.centerOn(new_QPointF(0, 0));
		view.show();
		view.setTransform(trans);
		world.start();
	}
}

QApplication app = new ();
GameManager manager = new (0, 0, 2200, 600);
manager.startGameEngine();
app.exec();
