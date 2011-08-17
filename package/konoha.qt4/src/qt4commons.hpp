/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

/*
 * qt4commons.hpp
 *
 *  Created on: Aug 3, 2011
 *      Author: kimio
 */

#ifndef QT4COMMONS_HPP_
#define QT4COMMONS_HPP_

#include <QtCore/QObject>
#include <QtCore/QEvent>
#define K_INTERNAL
#include <konoha1.h>

//#define QCAST(T, p)     dynamic_cast<T>(p)
//#define QPtr_to(T, a)   dynamic_cast<T>((a).p->rawptr)
#define QCAST(T, p)     (static_cast<T>(p))
#define QPtr_to(T, a)   konoha::object_cast<T>((a).p)
namespace konoha {
template <class T>
inline T object_cast(knh_RawPtr_t *po) {
	return static_cast<T>(po->rawptr);
}
}

#define QObject_parent(FP)  IS_NULL(FP.o) ? NULL : QPtr_to(QObject*, FP)
#define QWidget_parent(FP)  IS_NULL(FP.o) ? NULL : QPtr_to(QWidget*, FP)
#define new_ReturnQObject(ctx, sfp, q)   new_ReturnCppObject(ctx, sfp, q, qfree)

//using namespace std;

class KObject {
	public:
	knh_RawPtr_t *kself;
	KObject() : kself(NULL) {
	}
	~KObject() {
		fprintf(stderr, "disposing KObject this=%p, kself=%p", this, kself);
		if(kself != NULL) {
			kself->rawptr = NULL;
		}
	}
	private:
	KObject(const KObject &);
	KObject operator=(const KObject &);
};

#define RETURN_newKQObject(ko)  RETURN_KQObject_(ctx, sfp, ko, K_RIX)
#define RETURN_QObject(qo)      RETURN_QObject_(ctx, sfp, qo, K_RIX)

extern "C" {
//	void qfree(void *p);
	void RETURN_KQObject_(CTX ctx, knh_sfp_t *sfp, KObject *ko _RIX);
	void RETURN_QObject_(CTX ctx, knh_sfp_t *sfp, QObject *qo _RIX);
}

/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
class Connector;
class KonohaEvalEvent : public QEvent {
//	Q_OBJECT;

public:
	char *script;
	KonohaEvalEvent(char *);
	~KonohaEvalEvent();

};

class KonohaEval : public QObject {
	Q_OBJECT;

public:
	knh_context_t *ctx;
	KonohaEval(CTX);
	bool event(QEvent *e);

};

#include <QTextEdit>
//============ Common Wrapper Class =================
class KQTextCursor : public QTextCursor, public KObject {
public:
	KQTextCursor(QTextCursor cursor) : QTextCursor(cursor) {
	}

};

class KQTextDocument : public QTextDocument, public KObject {
public:
	KQTextDocument(QTextDocument *d) : QTextDocument(d) {
	}

};

class KQRect : public QRect, public KObject {
public:
	KQRect(QRect r) : QRect(r) {
		
	}

};

#include <QTimer>
class KQTimer : public QTimer, public KObject {
	Q_OBJECT;
private:
	Connector *c;
	knh_Func_t *timer_event_func;
public:
	KQTimer(knh_Func_t *fo, QObject *parent);
	void timerEvent(QTimerEvent *event);
signals:
	void emitTimerEvent(QTimerEvent *event);
};

class KQTextEdit : public QTextEdit, public KObject {
	Q_OBJECT;
private:
	Connector *c;
	knh_Func_t *paint_event_func;
	knh_Func_t *key_press_event_func;
public:
	KQTextEdit(QWidget *parent);
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void setPaintEvent(knh_Func_t *fo);
	void setKeyPressEvent(knh_Func_t *fo);
signals:
	void emitPaintEvent(QPaintEvent *event);
	void emitKeyPressEvent(QKeyEvent *event);
};

class KQWidget : public QWidget, public KObject {
public:
	KQWidget(QWidget * w) : QWidget(w), KObject() {
	}
};

class Connector : public QObject {
	Q_OBJECT;

public:
	knh_context_t *ctx;
	knh_Func_t *fo;
	knh_Func_t *timer_event_func;
	knh_Func_t *paint_event_func;
	knh_Func_t *key_press_event_func;

	Connector(CTX, knh_Func_t *fo);
	Connector(void){}
	bool connectValueChanged(CTX, QObject *);
	bool connectClicked(CTX, QObject *);
	void timerEvent(KQTimer *t, knh_Func_t *fo);
	void paintEvent(KQTextEdit *t, knh_Func_t *fo);
	void keyPressEvent(KQTextEdit *t, knh_Func_t *fo);
public slots:
	void slotValueChanged(qreal);
	// QAbstractButton
	void slotClicked(bool);
	void timerEventSlot(QTimerEvent *event);
	void paintEventSlot(QPaintEvent *event);
	void keyPressEventSlot(QKeyEvent *event);
};

#endif /* QT4COMMONS_HPP_ */
