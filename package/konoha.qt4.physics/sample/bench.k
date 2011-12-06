using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

QApplication app = new ();
QGraphicsScene scene = new ();
QRectF r = new QRectF();
r.setRect(0, 0, 600, 600);
scene.setSceneRect(r);
QWorld world = new (scene);
//world.setGravity(0.0f, 0.0f);
int particles_num = 0;

QGraphicsSimpleTextItem text = new ();
text.setText("particle:0");
text.setFont(new_QFont("monaco", QFont.StyleNormal, 24));
text.setBrush(new_QBrush(new_QColor("black")));
text.setPos(new_QPointF(400, 10));
text.setZValue(1);
scene.addItem(text);

QGraphicsEllipseItem[] createParticles(QPointF pos)
{
	QGraphicsEllipseItem[] ret = [];
	for (int i = 0; i < 10; i++) {
		QGraphicsEllipseItem e = new QGraphicsEllipseItem();
		r = new QRectF();
		int size = Int.random(10) + 3;
		r.setRect(pos.x, pos.y, size, size);
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
		ret << e;
	}
	particles_num += 10;
	text.setText("particle:" + (String)particles_num);
	return ret;
}

QPointF prev_pos = null;

void mousePressEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event)
{
	QPointF pos = event.scenePos();
	createParticles(pos);
	prev_pos = pos;
}

void mouseMoveEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event)
{
	QPointF pos = event.scenePos();
	QGraphicsEllipseItem[] particles = createParticles(pos);
	int x = prev_pos.x - pos.x;
	int y = prev_pos.y - pos.y;
	foreach (QGraphicsEllipseItem e in particles) {
		e.applyForce(new_QPointF(x, y), pos);
	}
	prev_pos = pos;
}

void mouseReleaseEvent(QGraphicsScene scene, QGraphicsSceneMouseEvent event)
{

}

scene.addEvent("mouse-press-event", mousePressEvent);
scene.addEvent("mouse-move-event", mouseMoveEvent);
scene.addEvent("mouse-release-event", mouseReleaseEvent);

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
QGLWidget w = new QGLWidget();
//view.setViewport(w);
view.setViewportUpdateMode(QGraphicsView.FullViewportUpdate);
view.setRenderHint(QPainter.Antialiasing);
	
view.show();
world.start();
app.exec();
