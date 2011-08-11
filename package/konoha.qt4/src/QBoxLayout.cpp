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

#include <QBoxLayout>
#include <konoha1.h>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

static void qfree(void *p)
{
	QBoxLayout *b = (QBoxLayout*)p;
	delete b;
}

//## void QBoxLayout.addWidget(QWidget widget, int stretch, int allignment);
KMETHOD QBoxLayout_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QBoxLayout *b = QPtr_to(QBoxLayout *, sfp[0]);
	if (IS_NULL(sfp[2].o) && IS_NULL(sfp[3].o)) {
		b->addWidget(QPtr_to(QWidget *, sfp[1]));
	} else {
		b->addWidget(QPtr_to(QWidget *, sfp[1]), Int_to(int, sfp[2]), Int_to(Qt::Alignment, sfp[3]));
	}
	RETURNvoid_();
}

//## QBoxLayout QBoxLayout.new(int dir, QWidget parent);
KMETHOD QBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QBoxLayout *b;
	if (IS_NULL(sfp[2].o)) {
		b = new QBoxLayout(Int_to(QBoxLayout::Direction, sfp[1]), 0);
	} else {
		QWidget *parent = QPtr_to(QWidget *, sfp[2]);
		b = new QBoxLayout(Int_to(QBoxLayout::Direction, sfp[1]), parent);
	}
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, b, qfree);
	RETURN_(p);
}

/* ------------------------------------------------------------------------ */

static knh_IntData_t QBoxLayoutConstInt[] = {
	{"LeftToRight", QBoxLayout::LeftToRight},
	{"RightToLeft", QBoxLayout::RightToLeft},
	{"TopToBottom", QBoxLayout::TopToBottom},
	{"BottomToTop", QBoxLayout::BottomToTop},
	{NULL, 0}
};

DEFAPI(void) constQBoxLayout(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadIntClassConst(ctx, cid, QBoxLayoutConstInt);
}

#ifdef __cplusplus
}
#endif
