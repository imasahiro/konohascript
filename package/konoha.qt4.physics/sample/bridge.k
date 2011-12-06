using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new (scene);


QGraphicsPixmapItem pixmap = new_QGraphicsPixmapItem("sample/qt.jpg", 50, 50);
pixmap.setPos(new_QPointF(100, 10));
pixmap.setDensity(1);
pixmap.setDraggable(true);
scene.addItem(pixmap);
world.add(pixmap);

QGraphicsRectItem prev = new_StaticRect(10, 200, 20, 10);
prev.setBrush(new_QBrush(new_QColor("#00eeee")));
scene.addItem(prev);
world.add(prev);
int i = 0;
for (int i = 1; i < 20; i++) {
	QGraphicsRectItem next = new_DynamicRect(10 + i * 20, 200, 20, 10);
	next.setBrush(new_QBrush(new_QColor("#00eeee")));
	next.setDraggable(true);
	scene.addItem(next);
	world.add(next);
	QRevoluteJoint j = new QRevoluteJoint(prev, next);
	world.add(j);
	prev = next;
}
QGraphicsRectItem next = new_StaticRect(10 + i * 20, 200, 20, 10);
next.setBrush(new_QBrush(new_QColor("#00eeee")));
scene.addItem(next);
world.add(next);
QRevoluteJoint j = new QRevoluteJoint(prev, next);
world.add(j);

QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
