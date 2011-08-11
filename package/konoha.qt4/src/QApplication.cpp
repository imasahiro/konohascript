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

#include <QApplication>
#include <QTextCodec>
#include "qt4commons.hpp"


#ifdef __cplusplus
extern "C" {
#endif

static void qfree_(void *)
{
	//QApplication *q = (QApplication *)p;
	//fprintf(stderr, "freeing QApplication..%p \n", p);
	//delete q;  if delete qapplication, go wrong everything for other QObjects.
}

KonohaEval::KonohaEval(CTX ctx) {
	this->ctx = (knh_context_t*)ctx;
}

bool KonohaEval::event(QEvent *e) {
	KonohaEvalEvent *ke = (KonohaEvalEvent*)e;
	fprintf(stderr, "thread id=%ld, eval='%s'\n", pthread_self(), ke->script);
	const knh_context_t *lctx = knh_getCurrentContext();
	knh_eval(lctx, ke->script);   // use lctx
	return true;
}

KonohaEvalEvent::KonohaEvalEvent(char *script) : QEvent(QEvent::User) {
	this->script = script;
}

KonohaEvalEvent::~KonohaEvalEvent() {
	fprintf(stderr, "disposing KonohaEvalEvent: %s\n", this->script);
	if(this->script != NULL) {
		free(this->script);
	}
}

struct threadparam_t {
	knh_context_t* ctx;
	QApplication *qapp;
};

void *shellthread(void *arg)
{
	struct threadparam_t *p = (struct threadparam_t*)arg;
	knh_context_t* ctx = p->ctx;
	QApplication *qapp = p->qapp;
	KonohaEval* qeval = new KonohaEval(ctx);
	fprintf(stdout, "threadid=%ld, readline=%s\n", pthread_self(), ctx->spi->readlinespi);
	while(1) {
		char *ln = ctx->spi->readline(">>> ");
		if(ln == NULL) break;
		ctx->spi->add_history(ln);
		//QApplication::sendEvent(qeval, new KonohaEvalEvent(ln));
		QApplication::postEvent(qeval, new KonohaEvalEvent(ln));
		QApplication::sendPostedEvents();
	}
	delete qeval;
	fprintf(stdout, "\nbyebye..\n");
	qapp->quit();
	return NULL;
}

static void qshell(CTX ctx, QApplication *qapp)
{
	pthread_t threadid;
	static struct threadparam_t p = {(knh_context_t*)ctx, qapp};
	pthread_create(&threadid, NULL, shellthread, (void*)&p); // FIXME ?
	fprintf(stdout, "main threadid=%ld, created=%ld\n", pthread_self(), threadid);
}

/* ----------------------------------------------------------------------- */

//## QApplication QApplication.new()
KMETHOD QApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int dummy = 0;
	QApplication *app = new QApplication(dummy, NULL);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, qfree_);
	RETURN_(p);
}

//## void QApplication.exec(boolean isShell);
KMETHOD QApplication_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QApplication *q = QPtr_to(QApplication *, sfp[0]);
	if(q != NULL) {
		if(sfp[1].bvalue == 1 || CTX_isInteractive(ctx)) {
			qshell(ctx, q);
		}
		q->exec();
	}
	RETURNvoid_();
}

//## void QApplication.quit();
KMETHOD QApplication_quit(CTX, knh_sfp_t *sfp _RIX)
{
	QApplication *q = QPtr_to(QApplication *, sfp[0]);
	if(q != NULL) {
		q->quit();
	}
	RETURNvoid_();
}

DEFAPI(const knh_PackageDef_t*) init(CTX, const knh_PackageLoaderAPI_t *)
{
	RETURN_PKGINFO("Qt-4.7");
}

#ifdef __cplusplus
}
#endif
