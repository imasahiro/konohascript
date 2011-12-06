using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new (scene);

int[] xarray = [100, 0, 200, 100, 100, 0, 0, 100, 0, 100, 100, 0, 60, 140, 150];
int[] yarray = [0, 173, 173, 0, 173, 200, 0, 173, 0, 0, 100, 100, 200, 150, 100];
QPointF[] a = [];
for (int i = 0; i < xarray.size; i++) {
	a << new_QPointF(xarray[i], yarray[i]);
}

QGraphicsComplexItem c = new QGraphicsComplexItem(a);
c.setBrush(new_QBrush(new_QColor("#0000ff")));
c.setDensity(1);
c.setDraggable(true);
world.add(c);
scene.addItem(c);

QGraphicsRectItem ground = new_StaticRect(0, 400, 500, 50);
ground.setRestitution(0.3);
world.add(ground);
scene.addItem(ground);

QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
