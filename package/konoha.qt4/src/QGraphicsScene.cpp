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

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsScene : public QGraphicsScene, public KObject {
public:
	KQGraphicsScene(QObject* parent) : QGraphicsScene(parent), KObject() {
	}
};

//## QGraphicsScene QGraphicsScene.new()
KMETHOD QGraphicsScene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_QObject(new KQGraphicsScene(NULL));
}

//## void QGraphicsScene.setSceneRect(float x, float y, float width, float height);
KMETHOD QGraphicsScene_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		g->setSceneRect(x, y, width, height);
	}
	RETURNvoid_();
}

//## void QGraphicsScene.addItem(QGraphicsItem item);
KMETHOD QGraphicsScene_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		QGraphicsItem *item = QPtr_to(QGraphicsItem *, sfp[1]);
		g->addItem(item);
	}
	RETURNvoid_();
}
//## void QGraphicsScene.addLine(int x1, int y1, int x2, int y2, QPen pen);
KMETHOD QGraphicsScene_addLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		float x = Float_to(qreal, sfp[1]);
		float y = Float_to(qreal, sfp[2]);
		float width = Float_to(qreal, sfp[3]);
		float height = Float_to(qreal, sfp[4]);
		QPen *p = QPtr_to(QPen *, sfp[5]);
		g->addLine(x, y, width, height, *p);
	}
	RETURNvoid_();
}

//## void QGraphicsScene.addEllipse(int x, int y, int width, int height, qpen pen, qbrush b);
KMETHOD QGraphicsScene_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		float x = Float_to(qreal, sfp[1]);
		float y = Float_to(qreal, sfp[2]);
		float width = Float_to(qreal, sfp[3]);
		float height = Float_to(qreal, sfp[4]);
		QPen *p = QPtr_to(QPen *, sfp[5]);
		QBrush *b = QPtr_to(QBrush *, sfp[6]);
		g->addEllipse(x, y, width, height, *p, *b);
	}
	RETURNvoid_();
}

//## void QGraphicsScene.addRect(int x, int y, int width, int height, QPen pen, QBrush b);
KMETHOD QGraphicsScene_addRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		float x = Float_to(qreal, sfp[1]);
		float y = Float_to(qreal, sfp[2]);
		float width = Float_to(qreal, sfp[3]);
		float height = Float_to(qreal, sfp[4]);
		QPen *p = QPtr_to(QPen *, sfp[5]);
		QBrush *b = QPtr_to(QBrush *, sfp[6]);
		g->addRect(x, y, width, height, *p, *b);
	}
	RETURNvoid_();
}

//## void QGraphicsScene.addText(String text);
KMETHOD QGraphicsScene_addText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[0]);
	if(g != NULL) {
		QString text = String_to(QString, sfp[1]);
		g->addText(text);
	}
	RETURNvoid_();
}
#ifdef __cplusplus
}
#endif
