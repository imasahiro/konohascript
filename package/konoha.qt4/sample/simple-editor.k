using konoha.qt4.*;

class SimpleTextEditor {
	QTextEdit editor;
	QTextCursor cursor;
	boolean isCurVisible;
	boolean isKeyPress;
	QTimer timer;
	QPainter painter;
	QColor white;

	SimpleTextEditor() {
		String style = "";
		style += "background-color:black;";
		style += "color:white;";
		style += "font-family:monaco;";
		editor = new QTextEdit();
		editor.resize(600, 600);
		editor.setWindowOpacity(0.9);
		editor.setStyleSheet(style);
		//editor.setLineWrapMode(QTextEdit.NoWrap);
		//editor.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff);
		editor.setCursorWidth(0);
		cursor = editor.textCursor();
		editor.setTabStopWidth(4);
		editor.setTextCursor(cursor);
		timer = new QTimer(delegate(this, blinkCursor));
		timer.setInterval(500);
		editor.setPaintEvent(delegate(this, paintEvent));
		white = new QColor("white");
	}
	
	void blinkCursor(QTimerEvent event) {
		if (isCurVisible) {
			isCurVisible = false;
		} else {
			isCurVisible = true;
		}
		isKeyPress = false;
	}

	void paintEvent(QPaintEvent event) {
		if (isKeyPress || isCurVisible) {
			if (painter != null) {
				painter = new QPainter(editor.viewport());
			}
			drawCursor();
		}
		//editor.setCursorWidth(0);
		editor.setCursorWidth(10);
	}

	void drawCursor() {
		QRect r = editor.cursorRect();
		r.setWidth(10);
		painter.setOpacity(0.6);
		painter.fillRect(r);
	}

	void show() {
		timer.start();
		editor.show();
	}
}

void main(String[] args)
{
	QApplication app = new QApplication();
	SimpleTextEditor te = new SimpleTextEditor();
	te.show();
	app.exec();
}
