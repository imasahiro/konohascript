using konoha.qt4.*;
using konoha.qt4.opencv.*;


QApplication app = new ();
QGraphicsScene scene = new ();
QBrush brush = new QBrush();
brush.setStyle(1);
QColor blue = new QColor();
blue.setNamedColor("blue");
brush.setColor(blue);
scene.setBackgroundBrush(brush);
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);

QImage image = new QImage();

//image.load("sample/konohascript.png");
//QSize size = new QSize();
//size.setWidth(300);
//size.setHeight(200);
//image = image.scaled(size);
image.load("sample/angry_bird.jpeg");

QColor c = new QColor();
c.setNamedColor("white");

//image = image.binarization(c);
//QPointF[][] pts_list = image.edgePoints;
image = image.permeabilization(c);
QPointF[][] pts_list = image.edgePointsUsingAlpha;

QPixmap pixmap = new QPixmap();
pixmap = pixmap.fromImageOL(image);
QGraphicsPixmapItem i = new QGraphicsPixmapItem();
i.setPixmap(pixmap);

scene.addItem(i);

QPen pen = new QPen();
QColor red = new QColor();
red.setNamedColor("red");
brush.setColor(red);
pen.setBrush(brush);
pen.setWidth(3);

for (int i = 0; i < pts_list.size; i++) {
	QPointF[] pts = pts_list[i];
	print |pts|;
	QGraphicsPathItem p = new ();
	p.setPen(pen);
	QPainterPath path = new ();
	if (|pts| < 1) continue;
	path.moveTo(pts[0]);
	for (int i = 1; i < |pts|; i++) {
		path.lineTo(pts[i]);
	}
	p.setPath(path);
	scene.addItem(p);
}


QGraphicsView view = new ();
view.setScene(scene);
view.show();
app.exec();
