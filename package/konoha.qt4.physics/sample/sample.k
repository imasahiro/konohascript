using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

QGraphicsRectItem new_StaticRect(int x, int y, int width, int height)
{
	QGraphicsRectItem rect = new ();
	QRectF r = new QRectF();
	r.setRect(x, y, width, height);
	rect.setRect(r);
	QBrush brush = new QBrush();
	brush.setStyle(1);
	QColor syan = new QColor();
	syan.setNamedColor("#00ffff");
	brush.setColor(syan);
	rect.setBrush(brush);
	return rect;
}

QGraphicsRectItem new_DynamicRect(int x, int y, int width, int height)
{
	QGraphicsRectItem rect = new ();
	QRectF r = new QRectF();
	r.setRect(x, y, width, height);
	rect.setRect(r);
	QBrush brush = new QBrush();
	brush.setStyle(1);
	QColor syan = new QColor();
	syan.setNamedColor("#00ffff");
	brush.setColor(syan);
	rect.setBrush(brush);

	rect.setDensity(1);
	rect.setRestitution(0);
	return rect;
}

QGraphicsSimpleTextItem new_DynamicText(String text, QFont font, String color_name)
{
	QGraphicsSimpleTextItem ret = new ();
	ret.setText(text);
	ret.setFont(font);
	ret.setBrush(new_QBrush(new_QColor(color_name)));
	//ret.setRestitution(0.7);
	ret.setDensity(1);
	return ret;
}

String getRandomColor()
{
	String ret = "#";
	for (int i = 0; i < 3; i++) {
		int r = Int.random(155);
		ret += "%x"(100 + r);
	}
	return ret;
}

void beginContactEvent(QGraphicsItem a, QGraphicsItem b)
{
	//print "begin contact : (" + a.class + ", " + b.class + ")";
	if (a.class == QGraphicsEllipseItem) {
		((QGraphicsEllipseItem)a).setBrush(new_QBrush(new_QColor(getRandomColor())));
	} else if (b.class == QGraphicsEllipseItem) {
		((QGraphicsEllipseItem)b).setBrush(new_QBrush(new_QColor(getRandomColor())));
	}
}

void endContactEvent(QGraphicsItem a, QGraphicsItem b)
{
	//print "begin contact : (" + a.class + ", " + b.class + ")";
}

void main(String[] args)
{
	QApplication app = new ();
	QGraphicsRectItem ground = new_StaticRect(0, 500, 600, 20);
	QGraphicsRectItem rect = new_DynamicRect(100, 100, 50, 50);
	rect.setDraggable(true);
	QGraphicsEllipseItem e = new QGraphicsEllipseItem();
	e.setDensity(1);
	QRectF e_rect = new QRectF();
	e_rect.setRect(300, 100, 10, 10);
	e.setRect(e_rect);
	e.setRestitution(0.8);
	e.setDraggable(true);

	QGraphicsSimpleTextItem text = new_DynamicText("Hello World",
												   new_QFont("monaco", QFont.StyleItalic, 24), "#000000");
	text.setPos(new_QPointF(200, 200));
	text.setDraggable(true);

	QGraphicsPixmapItem pixmap = new_QGraphicsPixmapItem("sample/qt.jpg", 50, 50);
	pixmap.setPos(new_QPointF(100, 50));
	pixmap.setDensity(1);
	pixmap.setRestitution(0.5);
	pixmap.setDraggable(true);

	QGraphicsScene scene = new ();
	QRectF r = new QRectF();
	r.setRect(0, 0, 600, 600);
	scene.setSceneRect(r);

	QWorld world = new QWorld(scene);
	world.addEvent("begin-contact-event", beginContactEvent);
	world.addEvent("end-contact-event", endContactEvent);

	world.add(ground);
	scene.addItem(ground);
	world.add(rect);
	scene.addItem(rect);
	world.add(e);
	scene.addItem(e);
	world.add(text);
	scene.addItem(text);
	world.add(pixmap);
	scene.addItem(pixmap);
	QGraphicsView view = new ();
	view.setScene(scene);
	view.setRenderHint(QPainter.Antialiasing);
	view.show();
	world.start();
	//world.showDebugDraw();
	app.exec();
}
