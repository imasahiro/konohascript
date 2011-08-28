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
//  goccy54 - Masaaki Goshima Yokohama National University, Japan
// **************************************************************************

//#include <QTextEdit>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif


KQTextEdit::KQTextEdit(QWidget *parent) : QTextEdit(parent)
{
}

void KQTextEdit::setPaintEvent(knh_Func_t *fo)
{
	paint_event_func = fo;
	c = new Connector();
	c->paintEvent(this, fo);
}

void KQTextEdit::setKeyPressEvent(knh_Func_t *fo)
{
	key_press_event_func = fo;
	c = new Connector();
	c->keyPressEvent(this, fo);
}

void KQTextEdit::paintEvent(QPaintEvent *event)
{
	emit emitPaintEvent(event);
	QTextEdit::paintEvent(event);
}

void KQTextEdit::keyPressEvent(QKeyEvent *event)
{
	emit emitKeyPressEvent(event);
	QTextEdit::keyPressEvent(event);
}

//## QTextEdit QTextEdit.new(QObject parent)
KMETHOD QTextEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWidget *parent = QWidget_parent(sfp[1]);
	//RETURN_newKQObject(new KQTextEdit(parent));
	RETURN_QObject(new KQTextEdit(parent));
}

KMETHOD QTextEdit_setPaintEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		te->setPaintEvent(sfp[1].fo);
	}
	RETURNvoid_();
}

KMETHOD QTextEdit_setKeyPressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		te->setKeyPressEvent(sfp[1].fo);
	}
	RETURNvoid_();
}

//## void QTextEdit.setLineWrapMode(int policy)
KMETHOD QTextEdit_setLineWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		te->setLineWrapMode(Int_to(QTextEdit::LineWrapMode, sfp[1]));
	}
	RETURNvoid_();
}

//## void QTextEdit.setCursorWidth(int width)
KMETHOD QTextEdit_setCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		te->setCursorWidth(Int_to(int, sfp[1]));
	}
	RETURNvoid_();
}

//## QTextCursor QTextEdit.textCursor()
KMETHOD QTextEdit_textCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		QTextCursor cursor = te->textCursor();
		KQTextCursor *c = new KQTextCursor(cursor);
		knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, c, NULL);
		KObject *ko = dynamic_cast<KObject*>(c);
		ko->kself = o;
		//fprintf(stderr, "ko(qo)=%p, o=%p\n", ko, o);
		RETURN_(o);
		//RETURN_QObject(new KQTextCursor(cursor));
	} else {
		RETURN_(KNH_NULL);
	}
}

//## void QTextEdit.setTabStopWidth()
KMETHOD QTextEdit_setTabStopWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		te->setTabStopWidth(Int_to(int, sfp[1]));
	}
	RETURNvoid_();
}

//## void QTextEdit.setTextCursor()
KMETHOD QTextEdit_setTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		QTextCursor *cursor = RawPtr_to(QTextCursor *, sfp[1]);//UPCAST
		te->setTextCursor(*cursor);
	}
	RETURNvoid_();
}

//## String QTextEdit.toPlainText()
KMETHOD QTextEdit_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		QString text = te->toPlainText();
		const char *t = text.toLocal8Bit().data();
		RETURN_(new_String(ctx, t));
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QRect QTextEdit.cursorRect()
KMETHOD QTextEdit_cursorRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextEdit *te = RawPtr_to(KQTextEdit *, sfp[0]);
	if (te != NULL) {
		QRect r = te->cursorRect();
		KQRect *qo = new KQRect(r);
		knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, qo, NULL);
		KObject *ko = dynamic_cast<KObject*>(qo);
		ko->kself = o;
		RETURN_(o);
		//RETURN_QObject(new KQRect(r));
		//RETURN_newKQObject(new KQRect(r));
	} else {
		RETURN_(KNH_NULL);
	}
}

static knh_IntData_t QTextEditConstInt[] = {
	{"NoWrap", QTextEdit::NoWrap},
	{"WidgetWidth", QTextEdit::WidgetWidth},
	{"FixedPixelWidth", QTextEdit::FixedPixelWidth},
	{"FixedColumnWidth", QTextEdit::FixedColumnWidth},
	{NULL, 0}
};

DEFAPI(void) constQTextEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, QTextEditConstInt);
}

#ifdef __cplusplus
}
#endif
