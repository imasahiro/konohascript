using konoha.qt4.*;

void pressed(QPushButton b) {
	print "pressed";
	print b;
}

void released(QPushButton b) {
	print "released";
	print b;
}

QApplication app = new QApplication();
QPushButton b = new QPushButton();
b.signalConnect("pressed", pressed);
b.signalConnect("released", released);
b.show();
app.exec();
