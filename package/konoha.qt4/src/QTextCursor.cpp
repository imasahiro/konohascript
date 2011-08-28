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

#ifdef __cplusplus
extern "C" {
#endif


//## void QTextCursor.movePosition(int pos, int mode)
KMETHOD QTextCursor_movePosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextCursor *tc = RawPtr_to(KQTextCursor *, sfp[0]);
	if (tc != NULL) {
		QTextCursor::MoveOperation op = Int_to(QTextCursor::MoveOperation, sfp[1]);
		QTextCursor::MoveMode mode = Int_to(QTextCursor::MoveMode, sfp[2]);
		tc->movePosition(op, mode);
	}
	RETURNvoid_();
}

//## void QTextCursor.deleteChar()
KMETHOD QTextCursor_deleteChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextCursor *tc = RawPtr_to(KQTextCursor *, sfp[0]);
	if (tc != NULL) {
		tc->deleteChar();
	}
	RETURNvoid_();
}

//## QTextDocument QTextCursor.document()
KMETHOD QTextCursor_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQTextCursor *tc = RawPtr_to(KQTextCursor *, sfp[0]);
	if (tc != NULL) {
		QTextDocument *d = tc->document();
		RETURN_QObject(new KQTextDocument(d));
	} else {
		RETURN_(KNH_NULL);
	}
}

static knh_IntData_t QTextCursorConstInt[] = {
	{"NoMove", QTextCursor::NoMove},
	{"Start", QTextCursor::Start},
	{"StartOfLine", QTextCursor::StartOfLine},
	{"StartOfBlock", QTextCursor::StartOfBlock},
	{"StartOfWord", QTextCursor::StartOfWord},
	{"PreviousBlock", QTextCursor::PreviousBlock},
	{"PreviousCharacter", QTextCursor::PreviousCharacter},
	{"PreviousWord", QTextCursor::PreviousWord},
	{"Up", QTextCursor::Up},
	{"Left", QTextCursor::Left},
	{"WordLeft", QTextCursor::WordLeft},
	{"End", QTextCursor::End},
	{"EndOfLine", QTextCursor::EndOfLine},
	{"EndOfWord", QTextCursor::EndOfWord},
	{"EndOfBlock", QTextCursor::EndOfBlock},
	{"NextBlock", QTextCursor::NextBlock},
	{"NextCharacter", QTextCursor::NextCharacter},
	{"NextWord", QTextCursor::NextWord},
	{"Down", QTextCursor::Down},
	{"Right", QTextCursor::Right},
	{"WordRight", QTextCursor::WordRight},
	{"NextCell", QTextCursor::NextCell},
	{"PreviousCell", QTextCursor::PreviousCell},
	{"NextRow", QTextCursor::NextRow},
	{"PreviousRow", QTextCursor::PreviousRow},
	{"MoveAnchor", QTextCursor::MoveAnchor},
	{"KeepAnchor", QTextCursor::KeepAnchor},
	{NULL, 0}
};

DEFAPI(void) constQTextCursor(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, QTextCursorConstInt);
}

#ifdef __cplusplus
}
#endif
