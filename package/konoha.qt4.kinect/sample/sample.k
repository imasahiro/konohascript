using konoha.qt4.*;
using konoha.qt4.physics.*;
using konoha.qt4.kinect.*;
include "sample/util.k";

class Sample {
	QGraphicsScene scene;
	QWorld world;
	QGraphicsComplexItem[] added_persons_body;
	QGraphicsPixmapItem prev_frame;
	QKinect kinect;
	QGraphicsPixmapItem[] leafs;

	Sample() {
		prev_frame = null;
		added_persons_body = [];
		scene = new ();
		QRectF r = new QRectF();
		r.setRect(0, 0, 600, 600);
		scene.setSceneRect(r);
		world = new (scene);
		world.setGravity(0.0f, 0.0f);
		scene.addEvent("timer-event", delegate(this, timerEvent));
		kinect = new QKinect("sample/Sample-Tracking.xml");
		kinect.setBackgroundImage("sample/forest.jpg");
	}

	void addLeafs() {
		for (int i = 0; i < 100; i++) {
			QGraphicsPixmapItem leaf = new_QGraphicsPixmapItem("sample/konohascript.png", 50, 40);
			leaf.setPos(new_QPointF(Int.random(600), Int.random(600)));
			leaf.setDensity(1);
			leaf.setZValue(2);
			scene.addItem(leaf);
			world.add(leaf);
		}
	}

	void timerEvent(QGraphicsScene scene, QTimerEvent event) {
		if (prev_frame != null) {
			scene.removeItem(prev_frame);
			prev_frame = null;
		}
		if (added_persons_body.size > 0) {
			foreach (QGraphicsComplexItem body in added_persons_body) {
				world.remove(body);
			}
		}
		added_persons_body = [];

		QGraphicsPixmapItem frame = new ();
		//QImage image = kinect.queryFrame();
		QImage image = kinect.queryBlendFrame();
		QPixmap pixmap = new QPixmap();
		pixmap = pixmap.fromImageOL(image);
		frame.setPixmap(pixmap);

		scene.addItem(frame);
		QPeople people = kinect.people;
		if (people != null) {
			QPerson[] persons = people.getPersons();
			foreach (QPerson person in persons) {
				QPointF[] pts = person.edgePoints;
				QGraphicsComplexItem body = new (pts);
				if (body != null) {
					//body.setBrush(new_QBrush(new_QColor("#0000ff")));
					added_persons_body << body;
					//scene.addItem(body);
					world.add(body);
				}
			}
		}
		kinect.update();
		prev_frame = frame;
		//System.gc();
	}

	void show() {
		QGraphicsView view = new ();
		view.setScene(scene);
		view.show();
		scene.startTimer(1000/30);
		world.start();
	}
}

QApplication app = new ();
Sample sample = new ();
sample.addLeafs();
sample.show();
app.exec();
