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
//  goccy54 - Masaaki Goshima Yokohama National University, Japan
// **************************************************************************

//#include <QTextEdit>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

KQTimer::KQTimer(knh_Func_t *fo, QObject *parent) : QTimer(parent)
{
	timer_event_func = fo;
	c = new Connector();
	c->timerEvent(this, fo);
}

void KQTimer::timerEvent(QTimerEvent *event)
{
	emit emitTimerEvent(event);
}

//## QTimer QTimer.new(QObject parent)
KMETHOD QTimer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t *fo = sfp[1].fo;
	QObject *parent = QObject_parent(sfp[2]);
	//RETURN_newKQObject(new KQTimer(fo, parent));
	RETURN_QObject(new KQTimer(fo, parent));
}

//## void QTimer.setInterval(int interval)
KMETHOD QTimer_setInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTimer *t = RawPtr_to(KQTimer *, sfp[0]);
	if (t != NULL) {
		t->setInterval(Int_to(int, sfp[1]));
	}
	RETURNvoid_();
}

KMETHOD QTimer_start(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	KQTimer *t = RawPtr_to(KQTimer *, sfp[0]);
	if (t != NULL) {
		int interval = Int_to(int, sfp[1]);
		(interval) ? t->start(interval) : t->start();
	}
	RETURNvoid_();
}

#ifdef __cplusplus
}
#endif
