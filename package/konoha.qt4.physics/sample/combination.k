using konoha.qt4.*;
using konoha.qt4.physics.*;
using konoha.qt4.opencv.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new QWorld(scene);

QImage image = new QImage();
image.load("sample/AngryRedBird.png");
//image.load("sample/konohascript.png");
QSize size = new QSize();
size.setWidth(200);
size.setHeight(200);
image = image.scaled(size);
//QColor c = new QColor();
//c.setNamedColor("white");
image = image.permeabilization(c);
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

QGraphicsComplexItem body = new (pts_list[idx]);
//body.setBrush(new_QBrush(new_QColor("#00ff00")));
body.addToGroup(i);
body.setDensity(1);
body.setDraggable(true);
scene.addItem(body);
world.add(body);

QGraphicsRectItem ground = new_StaticRect(0, 400, 500, 50);
ground.setRestitution(0.3);
world.add(ground);
scene.addItem(ground);

QGraphicsView view = new ();
view.setScene(scene);
view.show();
world.start();
app.exec();
