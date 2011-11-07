using konoha.qt4.*;

QApplication app = new QApplication();

QWidget w = new QWidget();
QTextEdit e = new QTextEdit();
// QSize s = new QSize();
// s.setWidth(1);
// s.setHeight(300000000000000000);
// e.resize(s);
QVBoxLayout l = new QVBoxLayout();
l.addWidget(e);
w.setLayout(l);
w.show();

app.exec();
