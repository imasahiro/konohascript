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
//  goccy54
// **************************************************************************

include "lib:gluelink";

class QObject extends C++;
class QWidget extends QObject;
class QApplication extends QObject;

class QWebView extends QWidget;
class QAbstractButton extends QWidget;
class QPushButton extends QAbstractButton;
class QFrame extends QWidget;

class QLabel extends QFrame;
class QLineEdit extends QWidget;

class QLayout extends QObject; // and QLayoutItem
class QBoxLayout extends QLayout;
class QHBoxLayout extends QBoxLayout;

@Native boolean QObject.connectValueChanged(Func<float> f);
@Native boolean QObject.connectClicked(Func<boolean> f);

@Native QApplication QApplication.new();
@Native void QApplication.exec(boolean hasShell);
@Native void QApplication.quit();

@Native QWidget QWidget.new(QWidget parent);
@Native void QWidget.setLayout(QLayout layout);
@Native void QWidget.move(int x, int y);
@Native void QWidget.resize(int w, int h);
@Native void QWidget.setWindowTitle(string title);
@Native void QWidget.show();

@Native QWebView QWebView.new(QWidget parent);
@Native void QWebView.load(String url);

@Native QLabel QLabel.new(String text, QWidget parent);

@Native QLineEdit QLineEdit.new(String text, QWidget parent);

@Native QHBoxLayout QHBoxLayout.new(QWidget parent);

@Native QBoxLayout QBoxLayout.new(int dir, QWidget parent);
@Native void QBoxLayout.addWidget(QWidget widget, int stretch, int allignment);

// AbstractButton

boolean QAbstractButton.onClicked(Func<boolean> f) {
	return connectClicked(f);
}

@Native QPushButton QPushButton.new(String text, QWidget parent);

