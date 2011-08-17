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

#include <QGraphicsView>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQGraphicsView : public QGraphicsView, public KObject {
public:
	KQGraphicsView(QGraphicsScene* scene) : QGraphicsView(scene), KObject() {
	}
};

//## QGraphicsView QGraphicsView.new(QGraphicsScene s, QWidget w)
KMETHOD QGraphicsView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsScene *g = QPtr_to(QGraphicsScene *, sfp[1]);
	KQGraphicsView *p = new KQGraphicsView(g);
	knh_RawPtr_t *o = new_ReturnCppObject(ctx, sfp, p, NULL);
	KObject *ko = dynamic_cast<KObject*>(p);
	ko->kself = o;
	RETURN_(o);
}

//## void QGraphicsView.setRenderHints(int hint);
KMETHOD QGraphicsView_setRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsView *g = QPtr_to(QGraphicsView *, sfp[0]);
	QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
	if(g != NULL) {
		g->setRenderHints(hint);
	}
	RETURNvoid_();
}

//## void QGraphicsView.show();
KMETHOD QGraphicsView_show(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsView *g = QPtr_to(QGraphicsView *, sfp[0]);
	if(g != NULL) {
		g->show();
	}
	RETURNvoid_();
}

#ifdef __cplusplus
}
#endif
