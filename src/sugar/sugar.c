/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved..
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

/* ************************************************************************ */

#include"commons.h"

/* ************************************************************************ */

#include "token.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [term] */

static knh_IntData_t TokenConstInt[] = {
	{"CODE", TK_CODE},
	{"USYMBOL", TK_USYMBOL},
	{"SYMBOL", TK_SYMBOL},
	{"OPERATOR", TK_OPERATOR},
	{"TEXT", TK_TEXT},
	{"STEXT", TK_STEXT},
	{"REGEX", TK_REGEX},
	{"INT", TK_INT},
	{"FLOAT", TK_FLOAT},
	{"URN", TK_URN},
	{"PROP", TK_PROP},
	{"META", TK_META},
	{"INDENT", TK_INDENT},
	{"WHITESPACE", TK_WHITESPACE},
	{NULL, 0},
};

#define FuncData(X) {#X , X}

static knh_FuncData_t FuncData[] = {
	FuncData(String_tokenize),
	FuncData(System_tokenize),
	{NULL, NULL},
};

void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_Token, TokenConstInt);
	kapi->loadFuncData(ctx, FuncData);
}

#ifdef __cplusplus
}
#endif
