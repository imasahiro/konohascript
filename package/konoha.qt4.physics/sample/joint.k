using konoha.qt4.*;
using konoha.qt4.physics.*;
using konoha.posix.*;
include "sample/util.k";

QWorld world;
QGraphicsScene scene;

void mousePressEvent(QGraphicsItem i, QGraphicsSceneMouseEvent event)
{
	scene.removeItem(i);
	world.remove(i);//joint : auto delete
}

void addDistanceJoint(QGraphicsScene scene, QWorld world)
{
	QGraphicsRectItem r1 = new_StaticRect(100, 100, 50, 50);
	QGraphicsRectItem r2 = new_DynamicRect(100, 200, 50, 50);
	r1.addEvent("mouse-press-event", mousePressEvent);
	r2.setDraggable(true);
	scene.addItem(r1);
	scene.addItem(r2);
	world.add(r1);
	world.add(r2);
//===== must call world.add(QGraphicsItem) previously ====
	QDistanceJoint j = new QDistanceJoint(r1, r2);
	scene.addItem(j);
	world.add(j);
}

void addRevoluteJoint(QGraphicsScene scene, QWorld world)
{
	QGraphicsRectItem r1 = new_StaticRect(300, 100, 50, 50);
	QGraphicsRectItem r2 = new_DynamicRect(300, 200, 50, 50);
	r1.addEvent("mouse-press-event", mousePressEvent);
	r2.setDraggable(true);
	scene.addItem(r1);
	scene.addItem(r2);
	world.add(r1);
	world.add(r2);
//===== must call world.add(QGraphicsItem) previously ====
	QRevoluteJoint j = new QRevoluteJoint(r1, r2);
	scene.addItem(j);
	world.add(j);
}

void addPrismaticJoint(QGraphicsScene scene, QWorld world)
{
	QGraphicsRectItem r1 = new_StaticRect(100, 300, 50, 50);
	QGraphicsRectItem r2 = new_DynamicRect(100, 400, 50, 50);
	r1.addEvent("mouse-press-event", mousePressEvent);
	r2.setDraggable(true);
	scene.addItem(r1);
	scene.addItem(r2);
	world.add(r1);
	world.add(r2);
	System.sleep(1);
//===== must call world.add(QGraphicsItem) previously ====
	QPrismaticJoint j = new QPrismaticJoint(r1, r2);
	scene.addItem(j);
	world.add(j);
}

void addPulleyJoint(QGraphicsScene scene, QWorld world)
{
	QGraphicsRectItem r1 = new_DynamicRect(300, 400, 50, 50);
	QPointF p1 = new_QPointF(300, 300);
	QGraphicsRectItem r2 = new_DynamicRect(400, 400, 50, 50);
	QPointF p2 = new_QPointF(400, 300);
	r1.setDraggable(true);
	r2.setDraggable(true);
	scene.addItem(r1);
	scene.addItem(r2);
	world.add(r1);
	world.add(r2);
//===== must call world.add(QGraphicsItem) previously ====
	QPulleyJoint j = new QPulleyJoint(r1, p1, r2, p2);
	scene.addItem(j);
	world.add(j);
}

QApplication app = new ();
scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
world = new (scene);

addDistanceJoint(scene, world);
addRevoluteJoint(scene, world);
addPrismaticJoint(scene, world);
addPulleyJoint(scene, world);

QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
