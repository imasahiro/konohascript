using konoha.qt4.*;

QApplication app = new ();

void myPaint(QGraphicsRectItem r, QPainter painter, QStyleOptionGraphicsItem option, QWidget widget) {
	print "call func";
//	QRectF rf = new ();
//	rf.setRect(10, 10, 10, 10);
//	painter.drawRoundedRect(rf, 5, 5, 0);

	QPointF pf = new ();
	pf.setX(30);
	pf.setY(30);
	painter.drawText(pf, "aaa");
}

QGraphicsRectItem gr = new ();
QRectF rf = new ();
rf.setRect(10, 10, 10, 10);
gr.setRect(rf);
//gr.addEvent("paint", myPaint);

QGraphicsScene s = new ();
s.addItem(gr);

QGraphicsView v = new ();
v.setScene(s);
v.show();

app.exec();

//r.paint();
//r.paint();
