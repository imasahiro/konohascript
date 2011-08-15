using konoha.qt4.*;

qapp = new QApplication();

wview = new QWebView();
wview.load("http://www.konohascript.org/");
wview.show();

qapp.exec();
