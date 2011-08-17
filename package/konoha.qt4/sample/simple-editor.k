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
		editor.setKeyPressEvent(delegate(this, keyPressEvent));
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

	void keyPressEvent(QKeyEvent event) {
		if (event.modifiers() == QEvent.META) {
			//PressedCtrl
			switch (event.key()) {
			case QEvent.Key_A:
				cursor.movePosition(QTextCursor.StartOfLine, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_B:
				cursor.movePosition(QTextCursor.Left, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_D:
				cursor.deleteChar();
				break;
			case QEvent.Key_E:
				cursor.movePosition(QTextCursor.EndOfLine, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_F:
				cursor.movePosition(QTextCursor.Right, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_H:
				break;
			case QEvent.Key_K:
				break;
			case QEvent.Key_N:
				cursor.movePosition(QTextCursor.Down, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_P:
				cursor.movePosition(QTextCursor.Up, QTextCursor.MoveAnchor);
				break;
			case QEvent.Key_Y:
				break;
			case QEvent.Key_Return:
				//String script = cursor.document().toPlainText();
				String script = editor.toPlainText();
				eval(script);
				break;
			default:
				break;
			}
		}
		editor.setTextCursor(cursor);
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
