using konoha.qt4.*;

void clicked(QGraphicsScene scene, QGraphicsSceneMouseEvent event) {
	print "clicked";
	print event.scenePos().x;
	print event.scenePos().y;
	gc();
}

void time() {
	print "timer";
	gc();
}

QApplication app = new QApplication(0, NULL);
print app;
QGraphicsScene s = new QGraphicsScene();
s.addEvent("mouse-press-event", clicked);
s.addEvent("timer-event", time);
QGraphicsView v = new QGraphicsView();
v.setScene(s);
v.show();
s.startTimer(1000);

app.exec();

