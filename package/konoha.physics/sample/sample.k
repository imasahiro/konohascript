using konoha.qt4.*;
using konoha.physics.*;

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

void main(String[] args)
{
	QApplication app = new ();
	QGraphicsRectItem ground = new_StaticRect(0, 500, 400, 20);
	print ground.isStatic();
	QGraphicsRectItem rect = new_DynamicRect(100, 100, 50, 50);
	QGraphicsEllipseItem e = new QGraphicsEllipseItem();
	e.setDensity(1);
	QRectF e_rect = new QRectF();
	e_rect.setRect(200, 100, 10, 10);
	e.setRect(e_rect);
	e.setRestitution(0.8);
	QGraphicsScene scene = new ();
	QRectF r = new QRectF();
	r.setRect(0, 0, 600, 600);
	scene.setSceneRect(r);
	QWorld world = new QWorld(scene);

	world.add(ground);
	scene.addItem(ground);
	world.add(rect);
	scene.addItem(rect);
	world.add(e);
	scene.addItem(e);

	QGraphicsView view = new ();
	view.setScene(scene);
	view.setRenderHint(QPainter.Antialiasing);
	view.show();
	world.start();
	app.exec();
}
