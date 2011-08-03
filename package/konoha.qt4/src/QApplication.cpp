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

static void qfree(void *p)
{
	QApplication *q = (QApplication *)p;
	//fprintf(stderr, "freeing QApplication..%p \n", p);
	//delete q;  if delete qapplication, go wrong everything for other QObjects.
}

//## QApplication QApplication.new()
KMETHOD QApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int dummy = 0;
	QApplication *app = new QApplication(dummy, NULL);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, qfree);
	RETURN_(p);
}

//## void QApplication.exec();
KMETHOD QApplication_exec(CTX, knh_sfp_t *sfp _RIX)
{
	QApplication *q = QPtr_to(QApplication *, sfp[0]);
	if(q != NULL) {
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
