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

#ifdef __cplusplus
extern "C" {
#endif

void qfree(void *p)
{
	QObject *q = QCAST(QObject*, p);
	delete q;
}

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
