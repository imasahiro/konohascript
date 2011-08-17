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

#include <QObject>
#include "qt4commons.hpp"
#include <konoha1/inlinelibs.h>

#ifdef __cplusplus
extern "C" {
#endif

void qfree(void *p)
{
	QObject *q = QCAST(QObject*, p);
	if(q->parent() == NULL) {
		delete q;
	}
}

void RETURN_KQObject_(CTX ctx, knh_sfp_t *sfp, KObject *ko _RIX)
{
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, ko, qfree);
	ko->kself = o;
	//fprintf(stderr, "ko(qo)=%p, o=%p\n", ko, o);
	RETURN_(o);
}

void RETURN_QObject_(CTX ctx, knh_sfp_t *sfp, QObject *qo _RIX)
{
	KObject *ko = dynamic_cast<KObject*>(qo);
	//fprintf(stderr, "ko=%p, qo=%p\n", ko, qo);
	if(ko == NULL) {
		knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, qo, NULL/*qfree*/);
		RETURN_(o);
	}
	else if(ko->kself == NULL) {
		knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, qo, qfree);
		ko->kself = o;
		//fprintf(stderr, "ko(qo)=%p, o=%p\n", ko, o);
		RETURN_(o);
	}
	else {
		RETURN_(ko->kself);
	}
}

/* ------------------------------------------------------------------------ */

class KQObject : public QObject, public KObject {
public:
	KQObject(QObject * p) : QObject(p), KObject() {
	}
};

//## QObject QObject.new(QObject parent);
KMETHOD QObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_newKQObject(new KQObject(IS_NULL(sfp[1].o) ? NULL : QCAST(QObject*, sfp[1].p->rawptr)));
}

/****
QGenericArgument K_ARG(knh_type_t ptype, knh_sfp_t *sfp, int n)
{
	switch(ptype) {
		case CLASS_Boolean: return Q_ARG(bool, (bool)sfp[n].bvalue);
		case CLASS_Int:     return Q_ARG(int, (int)sfp[n].ivalue);
		case CLASS_Float:   return Q_ARG(double, (double)sfp[n].fvalue);
		case CLASS_String:  return Q_ARG(QString, S_tochar(sfp[n].s));
		default:  return Q_ARG(QObject, (QObject*)(sfp[n].p->rawptr));
	}
}

//## void QObject.missing();
KMETHOD missing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QObject *qo = QPtr_to(QObject*, sfp[0]);
	bool ok = false;
	if (qo != NULL) {
		knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
		knh_ParamArray_t *pa = DP(mtd)->mp;
		char mbuf[80];
		const char *message = knh_format_mn(ctx, mtd->mn, mbuf, sizeof(mbuf));
		knh_class_t this_cid = O_cid(sfp[0].o);
		//	QVariant returnValue;
		int retval;
		QGenericReturnArgument ret = Q_RETURN_ARG(int, retval);
		switch(pa->psize) {
		case 0:
			ok = QMetaObject::invokeMethod(qo, message, ret);
			break;
		case 1:
			ok = QMetaObject::invokeMethod(qo, message, ret,
					K_ARG(knh_ParamArray_ptype(ctx, pa, 0, this_cid), sfp, 1));
			break;
		}//switch
	}
	if(ok) {

	}
	else {

	}
	RETURNvoid_();
}
*************/

/* ------------------------------------------------------------------------ */

Connector::Connector(CTX ctx, knh_Func_t *fo) {
	this->ctx = (knh_context_t*)ctx;
	this->fo = fo;
}

static void RETURNb(CTX ctx, knh_sfp_t *sfp, Connector *c, bool isConnected _RIX)
{
	if(isConnected) {
		knh_addConstPool(ctx, UPCAST(c->fo));
	}
	else {
		delete c;
	}
	RETURNb_(isConnected);
}

bool Connector::connectValueChanged(CTX, QObject *so)
{
	return connect(so, SIGNAL(valueChanged(qreal)), this, SLOT(slotValueChanged(qreal)));
}

void Connector::slotValueChanged(qreal val)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	lsfp[K_CALLDELTA+1].fvalue = (knh_float_t)val;
	knh_Func_invoke(lctx, this->fo, lsfp, 1/*argc*/);
}

void Connector::timerEvent(KQTimer *t, knh_Func_t *fo)
{
	timer_event_func = fo;
	connect(t, SIGNAL(emitTimerEvent(QTimerEvent *)), this, SLOT(timerEventSlot(QTimerEvent *)));
}

void Connector::timerEventSlot(QTimerEvent *event)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	//lsfp[K_CALLDELTA+1].fvalue = (knh_float_t)val;
	//KNH_SETv(lctx, lsfp[K_CALLDELTA+1], event);
	knh_Func_invoke(lctx, this->timer_event_func, lsfp, 1/*argc*/);
}

void Connector::paintEvent(KQTextEdit *t, knh_Func_t *fo)
{
	paint_event_func = fo;
	connect(t, SIGNAL(emitPaintEvent(QPaintEvent *)), this, SLOT(paintEventSlot(QPaintEvent *)));
}

void Connector::paintEventSlot(QPaintEvent *event)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	//lsfp[K_CALLDELTA+1].fvalue = (knh_float_t)val;
	//KNH_SETv(lctx, lsfp[K_CALLDELTA+1], event);
	knh_Func_invoke(lctx, this->paint_event_func, lsfp, 1/*argc*/);
}

void Connector::keyPressEvent(KQTextEdit *t, knh_Func_t *fo)
{
	key_press_event_func = fo;
	connect(t, SIGNAL(emitKeyPressEvent(QKeyEvent *)), this, SLOT(keyPressEventSlot(QKeyEvent *)));
}

void Connector::keyPressEventSlot(QKeyEvent *event)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	knh_class_t cid = knh_getcid(lctx, STEXT("QKeyEvent"));
	const knh_ClassTBL_t *ct = lctx->share->ClassTBL[cid];
	knh_RawPtr_t *p = (knh_RawPtr_t*)new_Object_init2(lctx, ct);
    p->rawptr = event;
    KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p));
	knh_Func_invoke(lctx, this->key_press_event_func, lsfp, 1/*argc*/);
}

//## void QObject.connectValueChanged(Func<float> f)
KMETHOD QObject_connectValueChanged(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QObject *so = RawPtr_to(QObject*, sfp[0]);
	Connector *c = new Connector(ctx, sfp[1].fo); // FIXME?: leaked
	RETURNb(ctx, sfp, c, c->connectValueChanged(ctx, so), K_RIX);
}

bool Connector::connectClicked(CTX, QObject *so)
{
	return connect(so, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

void Connector::slotClicked(bool val)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	lsfp[K_CALLDELTA+1].bvalue = (knh_bool_t)val;
	knh_Func_invoke(lctx, this->fo, lsfp, 1/*argc*/);
}

//## void QObject.connectClicked(Func<bool> f)
KMETHOD QObject_connectClicked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QObject *so = RawPtr_to(QObject*, sfp[0]);
	Connector *c = new Connector(ctx, sfp[1].fo); // FIXME?: leaked
	RETURNb(ctx, sfp, c, c->connectClicked(ctx, so), K_RIX);
}

#ifdef __cplusplus
}
#endif
