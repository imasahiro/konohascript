
using konoha.qt;

qapp = new QApplication();

wview = new QWebView();
wview.load("http://www.konohascript.org/");
wview.show();

qapp.exec();

