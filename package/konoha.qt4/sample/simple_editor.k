using konoha.qt4.*;

QApplication app = new QApplication();

QWidget w = new QWidget();
QTextEdit e = new QTextEdit();
QVBoxLayout l = new QVBoxLayout();
l.addWidget(e);
w.setLayout(l);
w.show();

app.exec();
