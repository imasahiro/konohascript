
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

#include <QGraphicsPixmapItem>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsPixmapItem : public QGraphicsPixmapItem, public KObject {
public:
	KQGraphicsPixmapItem() : QGraphicsPixmapItem(), KObject() {
	}
};

//## QGraphicsPixmapItem.new()
KMETHOD QGraphicsPixmapItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsPixmapItem *p = new KQGraphicsPixmapItem();
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	KObject *ko = dynamic_cast<KObject*>(p);
	ko->kself = o;
	RETURN_(o);
}

//## QPixmap QGraphicsPixmapItem.pixmap ()
KMETHOD QGraphicsPixmapItem_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	if (obj != NULL) {
		QPixmap ret = obj->pixmap();
		RETURN_(&ret);
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## void QGraphicsPixmapItem.setOffset (qreal x, qreal y)
KMETHOD QGraphicsPixmapItem_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	if (obj != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		obj->setOffset(x, y);
	}
	RETURNvoid_();
}

//## void QGraphicsPixmapItem.setPixmap (QPixmap pixmap)
KMETHOD QGraphicsPixmapItem_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	if (obj != NULL) {
		const QPixmap *pixmap = QPtr_to(const QPixmap *, sfp[1]);
		obj->setPixmap(*pixmap);
	}
	RETURNvoid_();
}

//## Boolean QGraphicsPixmapItem.contains (int point_x, int point_y)
KMETHOD QGraphicsPixmapItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		int point_x = Int_to(int, sfp[1]);
		int point_y = Int_to(int, sfp[2]);
		QPoint* point = new QPoint(point_x, point_y);
		ret = obj->contains(*point);
	}
	RETURNb_(ret);
}

//## Boolean QGraphicsPixmapItem.isObscuredBy (QGraphicsItem item)
KMETHOD QGraphicsPixmapItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		const QGraphicsItem * item = QPtr_to(const QGraphicsItem *, sfp[1]);
		ret = obj->isObscuredBy(item);
	}
	RETURNb_(ret);
}

//## virtual int QGraphicsPixmapItem.type ()
KMETHOD QGraphicsPixmapItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsPixmapItem *obj = QGraphicsItemChild_to(QGraphicsPixmapItem*, sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		ret = obj->type();
	}
	RETURNi_(ret);
}

#ifdef __cplusplus
}
#endif
