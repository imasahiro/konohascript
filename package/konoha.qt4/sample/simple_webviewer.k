using konoha.qt4,*;

class SimpleWebViewer {
	QUrl url;
	QWebView web_view;
	QToolButton next;
	QToolButton prev;
	QLineEdit location_bar;
	QHBoxLayout hbl;
	QVBoxLayout vbl;
	QWidget body;

	SimpleWebViewer(String u) {
		url = new QUrl();
		url.setUrl(u);
//		url.setUrl("http://typing.sakura.ne.jp/sushida/");

		QWebSettings webSettings = QWebSettings.globalSettings();
		webSettings.setAttribute(QWebSettings.PluginsEnabled, true);
		web_view = new ();
		web_view.load(url);
//		print _web_view.page.mainFrame().toHtml();

		next = new ();
		next.setArrowType(3);
		prev = new ();
		prev.setArrowType(4);
		location_bar = new ();

		hbl = new ();
		hbl.addWidget(next);
		hbl.addWidget(prev);
		hbl.addWidget(location_bar);
		hbl.addStretch();

		vbl = new ();
		vbl.addLayout(hbl);
		vbl.addWidget(webView);

		body = new ();
		body.setLayout(vbl);
		next.signalConnect("clicked", delegate(web_view, back));
		prev.signalConnect("clicked", delegate(web_view, forward));
		webView.signalConnect("url-changed", delegate(this, updateLocationBar));
		location_bar.signalConnect("return-pressed", delegate(this, updateWebView));
	}

	void show() {
		body.show();
	}

	void updateLocationBar(QWebView w) {
		QUrl u = w.url;
		String host = u.host;
		String path = u.path;
		_location_bar.setText(host + path);
	}

	void updateWebView(QLineEdit le) {
		String path = le.text;
		_url.setUrl("http://" + path);
		_web_view.load(url);
//		print _web_view.page.mainFrame().toHtml();
	}
};

QApplication app = new ();
SimpleWebViewer viewer = new ("http://konoha.sourceforge.jp/");
viewer.show();
app.exec();
