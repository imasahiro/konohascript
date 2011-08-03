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

#include <QtWebKit>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

static void qfree(void *p)
{
	QWebView *q = (QWebView*)p;
	delete q;
}

//## QWebView QWebView.new()
KMETHOD QWebView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWebView *q = new QWebView(0);
	knh_RawPtr_t *p = new_ReturnRawPtr(ctx, sfp, q, qfree);
	RETURN_(p);
}

//## void QWebView.load(String path);
KMETHOD QWebView_load(CTX, knh_sfp_t *sfp _RIX)
{
	QWebView *q = RawPtr_to(QWebView*, sfp[0]);
	if(q != NULL) {
		QUrl url = QUrl(S_tochar(sfp[1].s));
		q->load(url);
	}
	RETURNvoid_();
}

//## void QWebView.show();
KMETHOD QWebView_show(CTX, knh_sfp_t *sfp _RIX)
{
	QWebView *q = RawPtr_to(QWebView*, sfp[0]);
	if(q != NULL) {
		q->show();
	}
	RETURNvoid_();
}
	
#ifdef __cplusplus
}
#endif