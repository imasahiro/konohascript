
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

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsTextItem: public QGraphicsTextItem, public KObject {
public:
	KQGraphicsTextItem() : QGraphicsTextItem(), KObject() {
	}
};

//## QGraphicsTextItem.new()
KMETHOD QGraphicsTextItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsTextItem *p = new KQGraphicsTextItem();
	//qDebug() << p->font();
	RETURN_QObject(new KQGraphicsTextItem());
	//knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	//KObject *ko = dynamic_cast<KObject*>(p);
	//ko->kself = o;
	//RETURN_(o);
}

//## void QGraphicsTextItem.setPos (String t)
KMETHOD QGraphicsTextItem_setPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		obj->setPos(x, y);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.adjustSize ()
KMETHOD QGraphicsTextItem_adjustSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		obj->adjustSize();
	}
	RETURNvoid_();
}

//## QColor QGraphicsTextItem.defaultTextColor ()
KMETHOD QGraphicsTextItem_defaultTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		QColor ret = obj->defaultTextColor();
		RETURN_(&ret);
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## void QGraphicsTextItem.setDefaultTextColor (QColor col)
KMETHOD QGraphicsTextItem_setDefaultTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		const QColor *col = QPtr_to(const QColor *, sfp[1]);
		obj->setDefaultTextColor(*col);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.setHtml (String text)
KMETHOD QGraphicsTextItem_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		QString text = String_to(QString, sfp[1]);
		obj->setHtml(text);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.setPlainText (String text)
KMETHOD QGraphicsTextItem_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		QString text = String_to(QString, sfp[1]);
		//qDebug() << "text: " << text;
		obj->setPlainText(text);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.setTabChangesFocus (Boolean bool)
KMETHOD QGraphicsTextItem_setTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		bool b = Boolean_to(bool, sfp[1]);
		obj->setTabChangesFocus(b);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.setTextCursor (QTextCursor cursor)
KMETHOD QGraphicsTextItem_setTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		const QTextCursor *cursor = QPtr_to(const QTextCursor *, sfp[1]);
		obj->setTextCursor(*cursor);
	}
	RETURNvoid_();
}

//## void QGraphicsTextItem.setTextWidth (qreal width)
KMETHOD QGraphicsTextItem_setTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		obj->setTextWidth(width);
	}
	RETURNvoid_();
}

//## qreal QGraphicsTextItem.textWidth ()
KMETHOD QGraphicsTextItem_textWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	qreal ret = -1;
	if (obj != NULL) {
		ret = obj->textWidth();
	}
	RETURNf_(ret);
}

//## String QGraphicsTextItem.toHtml ()
KMETHOD QGraphicsTextItem_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		QString ret = obj->toHtml();
		RETURN_(&ret);
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## String QGraphicsTextItem.toPlainText ()
KMETHOD QGraphicsTextItem_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	if (obj != NULL) {
		QString ret = obj->toPlainText();
		//qDebug() << ret;
		//RETURN_(&ret);
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## Boolean QGraphicsTextItem.contains (int point_x, int point_y)
KMETHOD QGraphicsTextItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		int point_x = Int_to(int, sfp[1]);
		int point_y = Int_to(int, sfp[2]);
		QPoint* point = new QPoint(point_x, point_y);
		ret = obj->contains(*point);
	}
	RETURNb_(ret);
}

//## Boolean QGraphicsTextItem.isObscuredBy (QGraphicsItem item)
KMETHOD QGraphicsTextItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		const QGraphicsItem * item = QPtr_to(const QGraphicsItem *, sfp[1]);
		ret = obj->isObscuredBy(item);
	}
	RETURNb_(ret);
}

//## virtual int QGraphicsTextItem.type ()
KMETHOD QGraphicsTextItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsTextItem *obj = QPtr_to(QGraphicsTextItem* ,sfp[0]);
	int ret = -1;
	if (obj != NULL) {
		ret = obj->type();
	}
	RETURNi_(ret);
}

#ifdef __cplusplus
}
#endif
