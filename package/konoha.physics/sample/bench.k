using konoha.qt4.*;
using konoha.physics.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new (scene);

for (int i = 0; i < 1000; i++) {
	QGraphicsEllipseItem e = new QGraphicsEllipseItem();
	r = new QRectF();
	r.setRect(Int.random(300), Int.random(300), 10, 10);
	e.setRect(r);
	e.setDensity(1);
	e.setRestitution(0.7);
	QPen pen = new QPen();
	pen.setStyle(Qt.NoPen);
	e.setPen(pen);
	e.setBrush(new_QBrush(new_QColor("#0000ff")));
	e.setDraggable(true);
	scene.addItem(e);
	world.add(e);
}

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

makeCage(600, 600);
QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
