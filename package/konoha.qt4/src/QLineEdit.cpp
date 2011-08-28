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
//  wakamori
// **************************************************************************

#include <QLineEdit>
#include <konoha1.h>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQLineEdit : public QLineEdit, public KObject {
public:
	KQLineEdit(QString & text, QWidget * w) : QLineEdit(text, w), KObject() {
	}
};

//## QLineEdit QLineEdit.new(String text, QWidget parent);
KMETHOD QLineEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QString text = QString(String_to(const char *, sfp[1]));
	RETURN_newKQObject(new KQLineEdit(text, QWidget_parent(sfp[2])));
}

static knh_IntData_t QLineEditConstInt[] = {
	{"Normal", QLineEdit::Normal},
	{"NoEcho", QLineEdit::NoEcho},
	{"Password", QLineEdit::Password},
	{"PasswordEchoOnEdit", QLineEdit::PasswordEchoOnEdit},
	{NULL, 0},
};

DEFAPI(void) constQLineEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, QLineEditConstInt);
}

#ifdef __cplusplus
}
#endif
