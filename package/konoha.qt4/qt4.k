/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  goccy54 - Masaaki Goshima, Yokohama National University, Japan
// **************************************************************************

include "lib:gluelink";

@Abstract class Qt extends C++;
class QObject extends C++;
class QApplication extends QObject;

class QPaintDevice extends QObject;
class QWidget extends QPaintDevice;

class QLineEdit extends QWidget;
class QProgressBar extends QWidget;

class QWebView extends QWidget;
class QWebPage extends QObject;
class QWebFrame extends QObject;
class QWebElement extends C++;

class QAbstractButton extends QWidget;
class QPushButton extends QAbstractButton;
class QFrame extends QWidget;
class QStackedWidget extends QFrame;
class QLabel extends QFrame;

@Abstract class QLayoutItem;
class QSizePolicy extends C++;
class QLayout extends QObject; // and QLayoutItem
class QBoxLayout extends QLayout;
class QHBoxLayout extends QBoxLayout;
class QVBoxLayout extends QBoxLayout;

class QSpacerItem extends QLayoutItem;

class QTimer extends QObject;

class QSslSocket extends QObject;

class QAbstractScrollArea extends QFrame;
@Native class QTextEdit extends QAbstractScrollArea;

@Native class QTextCursor;
class QTextDocument extends QObject;

class QTimer extends QObject;
class QTimerEvent;

class QRect;
class QPainter;
class QPaintEvent;
class QColor;
@Native class QEvent;
class QInputEvent extends QEvent;
class QKeyEvent extends QInputEvent;

class QPixmap;
class QGraphicsItem extends QObject;
class QGraphicsEllipseItem extends QGraphicsItem;
class QGraphicsLineItem extends QGraphicsItem;
class QGraphicsPixmapItem extends QGraphicsItem;
class QGraphicsRectItem extends QGraphicsItem;
class QGraphicsTextItem extends QGraphicsItem;
class QGraphicsView;
class QGraphicsScene;

class QPen;
class QBrush;

@Native QObject QObject.new(QObject parent);
@Native boolean QObject.connectValueChanged(Func<float> f);
@Native boolean QObject.connectClicked(Func<boolean> f);
@Native void QObject.disconnect();
@Native String QObject.objectName();
@Native void QObject.setObjectName(String text);

@Native QApplication QApplication.new();
@Native void QApplication.exec(boolean hasShell);
@Native void QApplication.quit();

@Native QWidget QWidget.new(QWidget parent);
@Native void QWidget.setLayout(QLayout layout);
@Native void QWidget.move(int x, int y);
@Native void QWidget.setFixedSize(int x, int y);
@Native void QWidget.resize(int w, int h);
@Native void QWidget.setWindowTitle(string title);
@Native void QWidget.show();
@Native void QWidget.hide();
@Native void QWidget.setFocus(int n);
@Native void QWidget.setStyleSheet(String style);
@Native void QWidget.setWindowOpacity(float opacity);

@Native void QStackedWidget.setCurrentIndex(int index);
@Native int QStackedWidget.addWidget ( QWidget widget );

@Native QLabel QLabel.new(String text, QWidget parent);
@Native String QLabel.text();
@Native void QLabel.setText(String text);
@Native void QLabel.setAlignment(int a);
@Native void QLabel.setWordWrap(boolean ft)

@Native QLineEdit QLineEdit.new(String text, QWidget parent);
@Native String QLineEdit.text();
@Native void QLineEdit.setText(String text);
@Native void QLineEdit.setEchoMode(int echo);

boolean QLineEdit.onTextChanged(Func<String> f) {
	return false;
}

boolean QLineEdit.onReturnPressed(Func<void> f) {
	return false;
}


@Native QProgressBar QProgressBar.new(QWidget parent);
@Native void QProgressBar.setValue(int value);

@Native void QLayout.setContentsMargins(int left, int top, int right, int bottom);
@Native void QLayout.addItem(QLayoutItem item);

@Native QBoxLayout QBoxLayout.new(int dir, QWidget parent);
@Native void QBoxLayout.addWidget(QWidget widget, int stretch, int allignment);
@Native void QBoxLayout.setSpacing(int n);

@Native QHBoxLayout QHBoxLayout.new(QWidget parent);
@Native QVBoxLayout QVBoxLayout.new(QWidget parent);

@Native QSpacerItem QSpacerItem.new(int w, int h, int hpolicy, int vpolicy);

@Native QWebView QWebView.new(QWidget parent);
@Native void QWebView.load(String url);
@Native String QWebView.url();
@Native QWebPage QWebView.page();

boolean QWebView.onLoadFinished(Func<boolean> f) {
	return false;
}

boolean QWebView.onLoadProgress(Func<int> f) {
	return false;
}

@Native QWebFrame QWebPage.mainFrame();
@Native QWebElement	QWebFrame.documentElement();
@Native QWebElement QWebElement.findFirst(String query);
@Native void QWebElement.removeFromDocument();
@Native void QWebElement.setAttribute(String name, String value);
@Native void QWebElement.setAttribute(String name, String value);
@Native dynamic QWebElement.evaluateJavaScript(String scriptSource);
@Native String QWebElement.toPlainText();

@Native QPushButton QPushButton.new(String text, QWidget parent);
@Native void QPushButton.setText(String text);
@Native void QPushButton.setEnabled(boolean tf);
@Native void QPushButton.setDefault(boolean tf);

// AbstractButton

boolean QAbstractButton.onClicked(Func<boolean> f) {
	return connectClicked(f);
}

@Native @Static void QTimer.singleShot(int msec, Func<void> f);

//@Native @Static boolean QSslSocket.supportsSsl();


// compatibility to QString

@Public boolean String.isEmpty() {
	return (|this| == 0);
}

//QAbstractScrollArea
@Native QWidget QAbstractScrollArea.viewport();

//TextEdit
@Native QTextEdit QTextEdit.new(QWidget parent);
@Native void QTextEdit.setLineWrapMode(int mode);
@Native void QTextEdit.setCursorWidth(int width);
@Native void QTextEdit.setTabStopWidth(int width);
@Native QTextCursor QTextEdit.textCursor();
@Native void QTextEdit.setTextCursor(QTextCursor cursor);
@Native QRect QTextEdit.cursorRect();
@Native void QTextEdit.setPaintEvent(Func<QPaintEvent> f);
@Native void QTextEdit.setKeyPressEvent(Func<QKeyEvent> f);
@Native String QTextEdit.toPlainText();

//QTimer
@Native QTimer QTimer.new(Func<QTimerEvent> f, QObject parent);
@Native void QTimer.setInterval(int interval);
@Native void QTimer.start(int interval);

//QRect
@Native void QRect.setWidth(int width);

//QPainter
@Native QPainter QPainter.new(QPaintDevice device);
@Native void QPainter.setOpacity(float opacity);
@Native void QPainter.fillRect(QRect r, QColor c);

//QColor
@Native QColor QColor.new(String color);

//QTextCursor
@Native void QTextCursor.movePosition(int pos, int mode);
@Native void QTextCursor.deleteChar();
@Native QTextDocument QTextCursor.document();

//QTextDocument
@Native String QTextDocument.toPlainText();

//QInputEvent
@Native int QInputEvent.modifiers();

//QKeyEvent
@Native int QKeyEvent.key();

//QPen
@Native QPen QPen.new(QColor color);
@Native int QPen.capStyle();
@Native QColor QPen.color();
@Native float QPen.dashOffset();
@Native Boolean QPen.isSolid();
@Native int QPen.joinStyle();
@Native void QPen.setCapStyle(int style);
@Native void QPen.setColor(QColor color);
@Native void QPen.setWidth(int width);

//QPixmap
@Native QPixmap QPixmap.new(String filepath);

//QGraphicsView
@Native QGraphicsView QGraphicsView.new(QGraphicsScene scene);
@Native void QGraphicsView.setRenderHints(int hint);
@Native void QGraphicsView.show();

//QGraphicsScene
@Native QGraphicsScene QGraphicsScene.new();
@Native void QGraphicsScene.setSceneRect(float x, float y, float w, float h);
@Native void QGraphicsScene.addItem(QGraphicsItem item);
@Native void QGraphicsScene.addEllipse(int x, int y, int w, int h, QPen pen, QBrush b);
@Native void QGraphicsScene.addLine(int x1, int y1, int x2, int y2, QPen pen);
@Native void QGraphicsScene.addRect(int x, int y, int w, int h, QPen pen, QBrush b);
@Native void QGraphicsScene.addText(String text);

//QGraphicsPixmapItem
@Native QGraphicsPixmapItem QGraphicsPixmapItem.new();
@Native void QGraphicsPixmapItem.setPixmap(QPixmap pm);

//QGraphicsTextItem
@Native QGraphicsTextItem QGraphicsTextItem.new(String t);
@Native void QGraphicsTextItem.setPos(float x, float y);
@Native void QGraphicsTextItem.setPlainText(String t);
@Native String QGraphicsTextItem.toPlainText();
@Native void QGraphicsTextItem.setWidth(float w);
//QGraphicsRectItem
@Native QGraphicsRectItem QGraphicsRectItem.new(float x, float y, float w, float h);
//@Native QRectF QGraphicsRectItem.rect ();
void QGraphicsRectItem.setRect (float x, float y, float w, float h);
@Native QRectF QGraphicsRectItem.boundingRect ();
@Native Boolean QGraphicsRectItem.contains (int point_x, int point_y);

//QGraphicsEllipseItem
@Native QGraphicsEllipseItem QGraphicsEllipseItem.new(float x, float y, float w, float h);
void QGraphicsEllipseItem.setRect (int x, int y, int w, int h);
@Native void QGraphicsEllipseItem.setSpanAngle(int angle);
@Native void QGraphicsEllipseItem.setStartAngle(int angle);
@Native Boolean QGraphicsEllipseItem.contains (int point_x, int point_y);

//QGraphicsLineItem
@Native QGraphicsLineItem QGraphicsLineItem.new(float x1, float y2, float x2, float y2);
@Native QPen QGraphicsLineItem.pen();
@Native void QGraphicsLineItem.setLine(float x1, float y1, float x1, float y2);
@Native void QGraphicsLineItem.setPen(QPen pen);

