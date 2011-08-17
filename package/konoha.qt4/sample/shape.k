using konoha.qt4.*;

app = new QApplication();
scene = new QGraphicsScene();
scene.setSceneRect(0, 0, 300, 300);
pen = new QPen(new QColor("red"));
pen.setWidth(2);
//pen.setCapStyle(Qt.RoundCap);
p = new QGraphicsPixmapItem();
p.setPixmap(new QPixmap("sample/ks_logo.png"));
r = new QGraphicsRectItem(50, 50, 200, 200);
l1 = new QGraphicsLineItem(50, 50, 250, 250);
l2 = new QGraphicsLineItem(50, 250, 250, 50);
e = new QGraphicsEllipseItem(50, 50, 200, 200);
t = new QGraphicsTextItem();
t.setPlainText("KonohaScript");
t.setPos(100, 100);
l1.setPen(pen);
l2.setPen(pen);
scene.addItem(r);
scene.addItem(e);
scene.addItem(l1);
scene.addItem(l2);
scene.addItem(p);
scene.addItem(t);
view = new QGraphicsView(scene);
view.show();
app.exec();

