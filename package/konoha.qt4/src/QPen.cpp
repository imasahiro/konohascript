
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

#include <QPen>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif


class KQPen : public QPen, public KObject {
public:
	KQPen(QColor & color) : QPen(color), KObject() {
	}
};

//## C++:           QPen::QPen () 
//## konohascript:  QPen.new (const QColor  color)
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QColor * color = QPtr_to(QColor *, sfp[1]);
	KQPen *p = new KQPen(*color);
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	KObject *ko = dynamic_cast<KObject*>(p);
	ko->kself = o;
	RETURN_(o);
}

//## C++:          Qt::PenCapStyle QPen::capStyle () const
//## konohascript: int QPen.capStyle ()
KMETHOD QPen_capStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	if (obj != NULL) {
		Qt::PenCapStyle ret = obj->capStyle();
		RETURNi_(ret);
	}
	else {
		RETURNi_(0);
	}
}

//## C++:          QColor QPen::color () const
//## konohascript: QColor QPen.color ()
KMETHOD QPen_color(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	if (obj != NULL) {
		QColor ret = obj->color();
		RETURN_(&ret);
	}
	else {
		RETURN_(KNH_NULL);
	}
}

//## C++:          qreal QPen::dashOffset () const
//## konohascript: float QPen.dashOffset ()
KMETHOD QPen_dashOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	qreal ret = -1;
	if (obj != NULL) {
		ret = obj->dashOffset();
	}
	RETURNf_(ret);
}

//## C++:          bool QPen::isSolid () const
//## konohascript: Boolean QPen.isSolid ()
KMETHOD QPen_isSolid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	bool ret = false;
	if (obj != NULL) {
		ret = obj->isSolid();
	}
	RETURNb_(false);
}

//## C++:          Qt::PenJoinStyle QPen::joinStyle () const
//## konohascript: int QPen.joinStyle ()
KMETHOD QPen_joinStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	if (obj != NULL) {
		Qt::PenJoinStyle ret = obj->joinStyle();
		RETURNi_(ret);
	}
	else {
		RETURNi_(0);
	}
}

//## C++:          void QPen::setCapStyle () 
//## konohascript: void QPen.setCapStyle (int style)
KMETHOD QPen_setCapStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	if (obj != NULL) {
		Qt::PenCapStyle style = Int_to(Qt::PenCapStyle, sfp[1]);
		obj->setCapStyle(style);
	}
	RETURNvoid_();
}

//## C++:          void QPen::setColor () 
//## konohascript: void QPen.setColor (const QColor  color)
KMETHOD QPen_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	if (obj != NULL) {
		QColor * color = QPtr_to(QColor *, sfp[1]);
		obj->setColor(*color);
	}
	RETURNvoid_();
}


//## C++:          void QPen::setWidth () 
//## konohascript: void QPen.setWidth (int width)
KMETHOD QPen_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QPen *obj = QPtr_to(QPen* ,sfp[0]);
	int width = Int_to(int, sfp[1]);
	if (obj != NULL) {
		obj->setWidth(width);
	}
	RETURNvoid_();
}

#ifdef __cplusplus
}
#endif
