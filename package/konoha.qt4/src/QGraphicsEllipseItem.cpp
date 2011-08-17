
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

#include <QGraphicsEllipseItem>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsEllipseItem : public QGraphicsEllipseItem, public KObject {
public:
	KQGraphicsEllipseItem(qreal x, qreal y, qreal w, qreal h) : QGraphicsEllipseItem(x, y, w, h), KObject() {
	}
};

//##  QGraphicsEllipseItem.new (float x, float y, float w, float h)
KMETHOD QGraphicsEllipseItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	qreal width = Float_to(qreal, sfp[3]);
	qreal height = Float_to(qreal, sfp[4]);
	KQGraphicsEllipseItem *p = new KQGraphicsEllipseItem(x, y, width, height);
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	KObject *ko = dynamic_cast<KObject*>(p);
	ko->kself = o;
	RETURN_(o);
}

//## C++:          void QGraphicsEllipseItem::setRect (qreal x, qreal y, qreal width, qreal height) 
//## konohascript: void QGraphicsEllipseItem.setRect (qreal x, qreal y, qreal width, qreal height)
KMETHOD QGraphicsEllipseItem_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	if (obj != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		obj->setRect(x, y, width, height);
	}
	RETURNvoid_();
}

//## C++:          void QGraphicsEllipseItem::setSpanAngle () 
//## konohascript: void QGraphicsEllipseItem.setSpanAngle (int angle)
KMETHOD QGraphicsEllipseItem_setSpanAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	if (obj != NULL) {
		int angle = Int_to(int, sfp[1]);
		obj->setSpanAngle(angle);
	}
	RETURNvoid_();
}

//## C++:          void QGraphicsEllipseItem::setStartAngle () 
//## konohascript: void QGraphicsEllipseItem.setStartAngle (int angle)
KMETHOD QGraphicsEllipseItem_setStartAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	if (obj != NULL) {
		int angle = Int_to(int, sfp[1]);
		obj->setStartAngle(angle);
	}
	RETURNvoid_();
}

//## C++:          int QGraphicsEllipseItem::spanAngle () const
//## konohascript: int QGraphicsEllipseItem.spanAngle ()
KMETHOD QGraphicsEllipseItem_spanAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		ret = obj->spanAngle();
	}
	RETURNi_(ret);
}

//## C++:          int QGraphicsEllipseItem::startAngle () const
//## konohascript: int QGraphicsEllipseItem.startAngle ()
KMETHOD QGraphicsEllipseItem_startAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		int ret = obj->startAngle();
	}
	RETURNi_(ret);
}

//## C++:          virtual bool QGraphicsEllipseItem::contains () const
//## konohascript: Boolean QGraphicsEllipseItem.contains (int point_x, int point_y)
KMETHOD QGraphicsEllipseItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		int point_x = Int_to(int, sfp[1]);
		int point_y = Int_to(int, sfp[2]);
		QPoint* point = new QPoint(point_x, point_y);
		bool ret = obj->contains(*point);
	}
	RETURNb_(ret);
}

//## C++:          virtual bool QGraphicsEllipseItem::isObscuredBy () const
//## konohascript: Boolean QGraphicsEllipseItem.isObscuredBy (const QGraphicsItem  item)
KMETHOD QGraphicsEllipseItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		const QGraphicsItem * item = QPtr_to(const QGraphicsItem *, sfp[1]);
		bool ret = obj->isObscuredBy(item);
	}
	RETURNb_(ret);
}

//## C++:          virtual int QGraphicsEllipseItem::type () const
//## konohascript: virtual int QGraphicsEllipseItem.type ()
KMETHOD QGraphicsEllipseItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsEllipseItem *obj = QGraphicsItemChild_to(QGraphicsEllipseItem*, sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		int ret = obj->type();
	}
	RETURNi_(ret);
}


#ifdef __cplusplus
}
#endif
