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

#include "qt4commons.hpp"
#include <QInputEvent>
#ifdef __cplusplus
extern "C" {
#endif


//## int QInputEvent.modifiers()
KMETHOD QInputEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QInputEvent *e = RawPtr_to(QInputEvent *, sfp[0]);
	int ret = -1;
	if (e != NULL) {
		ret = e->modifiers();
	}
	RETURNi_(ret);
}

KMETHOD QKeyEvent_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QKeyEvent *e = RawPtr_to(QKeyEvent *, sfp[0]);
	int ret = -1;
	if (e != NULL) {
		ret = e->key();
	}
	RETURNi_(ret);
}

static knh_IntData_t QEventConstInt[] = {
	{"NoModifier", Qt::NoModifier},
	{"ShiftModifier", Qt::ShiftModifier},
	{"ControlModifier", Qt::ControlModifier},
	{"AltModifier", Qt::AltModifier},
	{"MetaModifier", Qt::MetaModifier},
	{"KeypadModifier", Qt::KeypadModifier},
	{"GroupSwitchModifier", Qt::GroupSwitchModifier},
	{"SHIFT", Qt::SHIFT},
	{"META", Qt::META},
	{"CTRL", Qt::CTRL},
	{"ALT", Qt::ALT},
	{"UNICODE_ACCEL", Qt::UNICODE_ACCEL},
	{"Key_A", Qt::Key_A},
	{"Key_B", Qt::Key_B},
	{"Key_C", Qt::Key_C},
	{"Key_D", Qt::Key_D},
	{"Key_E", Qt::Key_E},
	{"Key_F", Qt::Key_F},
	{"Key_G", Qt::Key_G},
	{"Key_H", Qt::Key_H},
	{"Key_I", Qt::Key_I},
	{"Key_J", Qt::Key_J},
	{"Key_K", Qt::Key_K},
	{"Key_L", Qt::Key_L},
	{"Key_M", Qt::Key_M},
	{"Key_N", Qt::Key_N},
	{"Key_O", Qt::Key_O},
	{"Key_P", Qt::Key_P},
	{"Key_Q", Qt::Key_Q},
	{"Key_R", Qt::Key_R},
	{"Key_S", Qt::Key_S},
	{"Key_T", Qt::Key_T},
	{"Key_U", Qt::Key_U},
	{"Key_V", Qt::Key_V},
	{"Key_W", Qt::Key_W},
	{"Key_X", Qt::Key_X},
	{"Key_Y", Qt::Key_Y},
	{"Key_Z", Qt::Key_Z},
	{"Key_Return", Qt::Key_Return},
	{NULL, 0}
};

DEFAPI(void) constQEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, QEventConstInt);
}

#ifdef __cplusplus
}
#endif
