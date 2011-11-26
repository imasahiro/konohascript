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

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [perror] */

#define ERR_   0
#define WARN_  1
#define INFO_  2
#define DEBUG_ 3

static void write_eline(CTX ctx, kOutputStream *w, kline_t uline, int lpos)
{
	if(uline != 0 /*&& uri != URI_unknown && line != 0*/) {
		kuri_t uri = ULINE_uri(uline);
		kuintptr_t line = ULINE_line(uline);
		knh_putc(ctx, w, '(');
		knh_write_ascii(ctx, w, knh_sfile(FILENAME__(uri)));
		knh_putc(ctx, w, ':');
		knh_write_dfmt(ctx, w, K_INTPTR_FMT, line);
		if(lpos != -1) {
			knh_putc(ctx, w, '+');
			knh_write_dfmt(ctx, w, K_INTPTR_FMT, (kintptr_t)lpos);
		}
		knh_putc(ctx, w, ')');
		knh_putc(ctx, w, ' ');
	}
}

static void knh_vperror(CTX ctx, int level, kline_t uline, int lpos, const char *fmt, va_list ap)
{
	int isPRINT = 0;
	const char *emsg = "(unknown) ";
	switch(level) {
		case ERR_:
			emsg =  "(error) "; isPRINT = 1;
			break;
		case WARN_:
			emsg = "(warning) "; isPRINT = 1;
			break;
		case INFO_:
			emsg = "(info) ";
			if((CTX_isInteractive(ctx) || knh_isCompileOnly(ctx)) || CTX_isDebug(ctx)) {
				isPRINT = 1;
			}
			break;
		case DEBUG_:
			emsg = "(debug) ";
			if(CTX_isDebug(ctx)) {
				isPRINT = 1;
			}
	}
	if(isPRINT == 1) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		write_eline(ctx, cwb->w, uline, lpos);
		knh_write_ascii(ctx, cwb->w, emsg);
		knh_vprintf(ctx, cwb->w, fmt, ap);
		kString *msg = CWB_newString(ctx, cwb, SPOL_POOLNEVER);
		knh_Array_add(ctx, ctx->errmsgs, msg);
		knh_logprintf("konoha", 0, S_totext(msg));
		fprintf(stderr, "%s - %s%s\n", TERM_BNOTE(ctx, level), S_totext(msg), TERM_ENOTE(ctx, level));
	}
}

void knh_perror(CTX ctx, int level, kline_t uline, int lpos, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	knh_vperror(ctx, level, uline, lpos, fmt, ap);
	va_end(ap);
}

static int knh_errno(CTX ctx)
{
	return knh_Array_size(ctx->errmsgs);
}

static kString* knh_strerror(CTX ctx, int kerrno)
{
	size_t i;
	for(i = kerrno; i < knh_Array_size(ctx->errmsgs); i++) {
		kString *emsg = (kString*)knh_Array_n(ctx->errmsgs, i);
		if(strstr(S_totext(emsg), "(error)") != NULL) {
			return emsg;
		}
	}
	DBG_P("kerrno=%d, |errmsgs|=%d", kerrno, knh_Array_size(ctx->errmsgs));
	return NULL;
}

static void DEBUG_TokenAlias(CTX ctx, kline_t uline, int lpos, kbytes_t t, kString *alias)
{
	if(CTX_isDebug(ctx)) {
		char buf[256] = {0};
		if(t.len < 256) {
			memcpy(buf, t.buf, t.len);
			knh_perror(ctx, INFO_, uline, lpos, "rewrite '%s' to '%s'", buf, S_totext(alias));
		}
	}
}

static void WARN_LiteralMustCloseWith(CTX ctx, kline_t uline, int lpos, int quote)
{
	char buf[8];
	knh_snprintf(buf, sizeof(buf), "%c", quote);
	knh_perror(ctx, WARN_, uline, lpos, "Literal must close with %s", buf);
}

static void IGNORE_UnxpectedMultiByteChar(CTX ctx, kline_t uline, int lpos, char *text, size_t len)
{
	int ch = text[len];
	text[len] = 0;
	knh_perror(ctx, WARN_, uline, lpos, "unexpected multi-byte character: %s", text);
	text[len] = ch; // danger a little
}

static void ERROR_NotFoundCloseToken(CTX ctx, kToken *tk, int closech)
{
	char buf[8];
	knh_snprintf(buf, sizeof(buf), "%c", closech);
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "'%s' is not closed with '%s'", S_totext(tk->text), buf);
}

static kbool_t ERROR_SyntaxError(CTX ctx, kline_t uline)
{
	knh_perror(ctx, ERR_, uline, 0, "syntax error");
	return 0;
}

static kbool_t ERROR_TokenError(CTX ctx, kToken *tk)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "syntax error: token '%s' is unavailable", S_totext(tk->text));
	return 0;
}

static kbool_t ERROR_TokenMustBe(CTX ctx, kToken *tk, const char *token)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "syntax error: '%s' must be %s", S_totext(tk->text), token);
	return 0;
}

static kExpr *ERROR_TokenUndefinedMethod(CTX ctx, kToken *tk, kclass_t cid)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "undefined method: %T.%s", cid, S_totext(tk->text));
	return NULL;
}

void WARN_TokenMuchBetter(CTX ctx, kToken *tk, const char *token)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "%s is much better than %s", S_totext(tk->text), token);
}

void WARN_TokenOverflow(CTX ctx, kToken *tk)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "%s is overflow", S_totext(tk->text));
}


#ifdef __cplusplus
}
#endif
