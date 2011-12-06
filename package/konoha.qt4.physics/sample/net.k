using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new (scene);
world.setGravity(0.0f, 0.0f);

void makeCage(int width, int height)
{
	QGraphicsRectItem left = new_StaticRect(0, 0, 5, height);
	QGraphicsRectItem right = new_StaticRect(width - 5, 0, 5, height);
	QGraphicsRectItem top = new_StaticRect(0, 0, width, 5);
	QGraphicsRectItem bottom = new_StaticRect(0, height - 5, width, 5);
	left.setBrush(new_QBrush(new_QColor("#00ff00")));
	right.setBrush(new_QBrush(new_QColor("#00ff00")));
	top.setBrush(new_QBrush(new_QColor("#00ff00")));
	bottom.setBrush(new_QBrush(new_QColor("#00ff00")));
	scene.addItem(left);
	scene.addItem(right);
	scene.addItem(top);
	scene.addItem(bottom);
	world.add(left);
	world.add(right);
	world.add(top);
	world.add(bottom);
}

void makeNet()
{
	QGraphicsEllipseItem[] pts = [];
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			QGraphicsEllipseItem e = new ();
			e.setBrush(new_QBrush(new_QColor("#ff00ff")));
			e.setDraggable(true);
			r = new QRectF();
			r.setRect(100 + x * 30, 100 + y * 30, 10, 10);
			e.setRect(r);
			e.setDensity(1);
			//e.setOpacity(0.01);
			scene.addItem(e);
			world.add(e);
			pts << e;
		}
	}
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 7; x++) {
			prev = pts[8 * y + x];
			next = pts[8 * y + x + 1];
			QDistanceJoint j = new QDistanceJoint(prev, next);
			j.setLength(30);
			//scene->addItem(j);
			world.add(j);
		}
	}
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 8; x++) {
			prev = pts[8 * y + x];
			next = pts[8 * (y+1) + x];
			QDistanceJoint j = new QDistanceJoint(prev, next);
			j.setLength(30);
			//scene->addItem(j);
			world.add(j);
		}
	}
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			prev = pts[8 * y + x];
			next = pts[8 * (y+1) + (x+1)];
			QDistanceJoint j = new QDistanceJoint(prev, next);
			j.setLength(40);
			//scene->addItem(j);
			world.add(j);
		}
	}
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			prev = pts[8 * y + x+1];
			next = pts[8 * (y+1) + x];
			QDistanceJoint j = new QDistanceJoint(prev, next);
			j.setLength(40);
			//scene->addItem(j);
			world.add(j);
		}
	}
}

makeCage(600, 600);
makeNet();
QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
