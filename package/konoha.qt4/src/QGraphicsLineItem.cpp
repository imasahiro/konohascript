
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

#include <QGraphicsLineItem>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsLineItem : public QGraphicsLineItem, public KObject {
public:
	KQGraphicsLineItem(qreal x, qreal y, qreal w, qreal h) : QGraphicsLineItem(x, y, w, h), KObject() {
	}
};

//## QGraphicsLineItem.QGraphicsLineItem(float x1, float y1, float x2, float y2)
KMETHOD QGraphicsLineItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	qreal x1 = Float_to(qreal, sfp[1]);
	qreal y1 = Float_to(qreal, sfp[2]);
	qreal x2 = Float_to(qreal, sfp[3]);
	qreal y2 = Float_to(qreal, sfp[4]);
	KQGraphicsLineItem *p = new KQGraphicsLineItem(x1, y1, x2, y2);
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	KObject *ko = dynamic_cast<KObject*>(p);
	ko->kself = o;
	RETURN_(o);
}

//## QPen QGraphicsLineItem.pen ()
KMETHOD QGraphicsLineItem_pen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	if (obj != NULL) {
		QPen ret = obj->pen();
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## void QGraphicsLineItem.setLine (qreal x1, qreal y1, qreal x2, qreal y2)
KMETHOD QGraphicsLineItem_setLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	if (obj != NULL) {
		qreal x1 = Float_to(qreal, sfp[1]);
		qreal y1 = Float_to(qreal, sfp[2]);
		qreal x2 = Float_to(qreal, sfp[3]);
		qreal y2 = Float_to(qreal, sfp[4]);
		obj->setLine(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//## void QGraphicsLineItem.setPen (QPen pen)
KMETHOD QGraphicsLineItem_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	if (obj != NULL) {
		QPen *pen = QPtr_to(QPen *, sfp[1]);
		obj->setPen(*pen);
	}
	RETURNvoid_();
}

//## Boolean QGraphicsLineItem.contains (int point_x, int point_y)
KMETHOD QGraphicsLineItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		int point_x = Int_to(int, sfp[1]);
		int point_y = Int_to(int, sfp[2]);
		QPoint* point = new QPoint(point_x, point_y);
		ret = obj->contains(*point);
	}
	RETURNb_(ret);
}

//## Boolean QGraphicsLineItem.isObscuredBy (QGraphicsItem item)
KMETHOD QGraphicsLineItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		const QGraphicsItem * item = QPtr_to(const QGraphicsItem *, sfp[1]);
		ret = obj->isObscuredBy(item);
	}
	RETURNb_(ret);
}

//## virtual int QGraphicsLineItem.type ()
KMETHOD QGraphicsLineItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsLineItem *obj = QPtr_to(QGraphicsLineItem* ,sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		ret = obj->type();
	}
	RETURNi_(ret);
}

#ifdef __cplusplus
}
#endif
