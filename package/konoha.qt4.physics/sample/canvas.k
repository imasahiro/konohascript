using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

class Canvas {
	QWorld world;
	QGraphicsScene scene;
	QPointF[] pts;
	QGraphicsPathItem drawpath;
	QPointF prev_pos;

	Canvas() {
		scene = new QGraphicsScene();
		prev_pos = null;
		pts = [];
		r = new QRectF();
		r.setRect(0, 0, 600, 600);
		scene.setSceneRect(r);
		scene.addEvent("mouse-press-event", delegate(this, mousePressEvent));
		scene.addEvent("mouse-move-event", delegate(this, mouseMoveEvent));
		scene.addEvent("mouse-release-event", delegate(this, mouseReleaseEvent));
		world = new QWorld(scene);
		QGraphicsRectItem ground = new ();
		r.setRect(0, 500, 600, 10);
		ground.setBrush(new_QBrush(new_QColor("#00ffff")));
		ground.setRect(r);
		scene.addItem(ground);
		world.add(ground);
	}

	String getRandomColorName()	{
		String ret = "#";
		for (int i = 0; i < 3; i++) {
			int r = Int.random(155);
			ret += "%x"(100 + r);
		}
		return ret;
	}

	void mousePressEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event) {
		QPointF pos = event.scenePos();
		pts << pos;
		prev_pos = pos;
		drawpath = new QGraphicsPathItem();
		QPen pen = new_QPen(getRandomColorName(), 1);
		drawpath.setPen(pen);
		scene.addItem(drawpath);
	}

	void mouseMoveEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event) {
		QPointF pos = event.scenePos();
		pts << pos;
		QPainterPath p = drawpath.path;
		QPainterPath append_path = new QPainterPath();
		append_path.moveTo(prev_pos);
		append_path.lineTo(pos);
		p.addPath(append_path);
		drawpath.setPath(p);
		prev_pos = pos;
	}

	void mouseReleaseEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event) {
		QPointF pos = event.scenePos();
		pts << pos;
		QGraphicsComplexItem o = new (pts);
		if (o != null) {
			o.setDensity(1);
			o.setRestitution(0.2);
			o.setFriction(0.7);
			QPen pen = drawpath.pen;
			o.setBrush(pen.brush);
			scene.addItem(o);
			world.add(o);
		}
		pts = [];
		scene.removeItem(drawpath);
	}

	void show() {
		QGraphicsView view = new ();
		view.setScene(scene);
		view.show();
		world.start();
	}
}

QApplication app = new ();
Canvas canvas = new ();
canvas.show();
app.exec();
