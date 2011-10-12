using konoha.qt4.*;

void clicked() {
	print "clicked";
}

void time() {
	print "timer";
}

void main(String[] args)
{
	QApplication app = new QApplication();
	QGraphicsScene s = new QGraphicsScene();
	s.addEvent("mouse-press-event", clicked);
	s.addEvent("timer-event", time);
	QGraphicsView v = new QGraphicsView();
	v.setScene(s);
	v.show();
	s.startTimer(1000);
	app.exec();
}
