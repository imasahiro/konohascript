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

#include <QWidget>
#include <QString>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif


//## QWidget QWidget.new(QWidget w)
KMETHOD QWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWidget *q = new QWidget(QWidget_parent(sfp[1]));
	RETURN_(new_ReturnQObject(ctx, sfp, q));
}

//## void QWidget.setLayout(QLayout layout);
KMETHOD QWidget_setLayout(CTX, knh_sfp_t *sfp _RIX)
{
	QWidget *w = QPtr_to(QWidget *, sfp[0]);
	if(w != NULL) {
		w->setLayout(QPtr_to(QLayout *, sfp[1]));
	}
	RETURNvoid_();
}

//## void QWidget.move(int x, int y);
KMETHOD QWidget_move(CTX, knh_sfp_t *sfp _RIX)
{
	QWidget *w = QPtr_to(QWidget*, sfp[0]);
	if(w != NULL) {
		w->move(Int_to(int, sfp[1]), Int_to(int, sfp[2]));
	}
	RETURNvoid_();
}

//## void QWidget.setWindowTitle(string title);
KMETHOD QWidget_setWindowTitle(CTX, knh_sfp_t *sfp _RIX)
{
	QWidget *w = QPtr_to(QWidget*, sfp[0]);
	if(w != NULL) {
		w->setWindowTitle(QString::QString(String_to(const char *, sfp[1])));
	}
	RETURNvoid_();
}

//## void QWidget.resize(int w, int h);
KMETHOD QWidget_resize(CTX, knh_sfp_t *sfp _RIX)
{
	QWidget *w = QPtr_to(QWidget*, sfp[0]);
	if(w != NULL) {
		w->resize(Int_to(int, sfp[1]), Int_to(int, sfp[2]));
	}
	RETURNvoid_();
}

//## void QWidget.show();
KMETHOD QWidget_show(CTX, knh_sfp_t *sfp _RIX)
{
	QWidget *q = QPtr_to(QWidget*, sfp[0]);
	if(q != NULL) {
		q->show();
	}
	RETURNvoid_();
}
	
#ifdef __cplusplus
}
#endif
