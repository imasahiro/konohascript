/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
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

#define USE_bytes_rindex  1
#define USE_cwb_open      1

#include"commons.h"
#include"../../include/konoha1/konoha_code_.h"

#ifndef K_USED_TO_BE_ON_LKM
#include<time.h>
#endif

#ifdef K_USED_TO_BE_ON_LKM
#include<linux/errno.h>
static int errno;
#else

#ifdef K_USING_POSIX_
#include<errno.h>
#elif !defined(K_USING_WINTHREAD_)
static int errno_WHO_ADDED_THIS;      //@ Who added this? (kimio)
#endif
#endif

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [file] */

const char* knh_sfile(const char *file)
{
	if(file != NULL) {
		knh_bytes_t t;
		t.text = file; t.len = knh_strlen(file);
		int loc = knh_bytes_rindex(t, '/');
		if(loc == -1) {
			return file;
		}
		return t.text + loc + 1;
	}
	return "(unknown)";
}

/* ------------------------------------------------------------------------ */

void dbg_p(const char *file, const char *func, int line, const char *fmt, ...)
{
#ifndef K_USING_DEBUG
	if(knh_isSystemVerbose()) {
#endif
		va_list ap;
		va_start(ap , fmt);
		fflush(stdout);
		fprintf(stderr, "DEBUG(%s:%d) ", func, line);
		vfprintf(stderr, fmt, ap);
		fprintf(stderr, "\n");
		va_end(ap);
#ifndef K_USING_DEBUG
	}
#endif
}

/* ------------------------------------------------------------------------ */

void todo_p(const char *file, const char *func, int line, const char *fmt, ...)
{
	va_list ap;
	va_start(ap , fmt);
	fflush(stdout);
	fprintf(stderr, "TODO(%s:%d) ", knh_sfile(file), line);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}

/* ------------------------------------------------------------------------ */

static void knh_write_cline(CTX ctx, knh_OutputStream_t *w, const char *file, knh_uintptr_t line)
{
	knh_putc(ctx, w, '(');
	knh_write_text(ctx, w, knh_sfile(file));
	knh_putc(ctx, w, ':');
	knh_write_dfmt(ctx, w, K_INTPTR_FMT, line);
	knh_putc(ctx, w, ')');
	knh_putc(ctx, w, ' ');
}

void knh_write_uline(CTX ctx, knh_OutputStream_t *w, knh_uline_t uline)
{
	knh_uri_t uri = ULINE_uri(uline);
	knh_uintptr_t line = ULINE_line(uline);
	if(uline == 0 || uri == URI_unknown || line == 0) {
		//knh_write_text(ctx, w, "");
	}
	else {
		knh_write_cline(ctx, w, FILENAME__(uri), line);
	}
}

static const char* knh_format_uline(CTX ctx, char *buf, size_t bufsiz, knh_uline_t uline)
{
	knh_uri_t uri = ULINE_uri(uline);
	knh_uintptr_t line = ULINE_line(uline);
	if(uline == 0 || uri == URI_unknown || line == 0) {
		buf[0] = 0;
	}
	else {
		snprintf(buf, bufsiz, "(%s:%d) ", knh_sfile(FILENAME__(uri)), (int)line);
	}
	return (const char*)buf;
}

/* ------------------------------------------------------------------------ */
/* [throw] */

static knh_bool_t isCalledMethod(CTX ctx, knh_sfp_t *sfp)
{
	knh_Method_t *mtd = sfp[0].mtdNC;
	if(knh_isObject(ctx, mtd) && IS_Method(mtd)) {
		//DBG_P("FOUND mtdNC: shift=%d, pc=%d", sfp[-2].shift, sfp[-1].pc);
		return 1;
	}
	return 0;
}

static knh_uline_t sfp_uline(CTX ctx, knh_sfp_t *sfp)
{
	knh_opline_t *pc = sfp[K_PCIDX].pc;
	DBG_ASSERT(isCalledMethod(ctx, sfp + K_MTDIDX));
	if(pc == NULL) return 0;
	{
		int line = (pc-1)->line;
		while(pc->opcode != OPCODE_THCODE) pc--;
		knh_uri_t uri = ((klr_THCODE_t*)pc)->uri;
		return new_ULINE(uri, line);
	}
}

static knh_uline_t knh_stack_uline(CTX ctx, knh_sfp_t *sfp)
{
	if(sfp != NULL) {
		DBG_ASSERT(isCalledMethod(ctx, sfp + K_MTDIDX));
		return sfp_uline(ctx, sfp);
	}
	else {
		//DBG_P("Find Called Method.. ");
		sfp = ctx->esp;
		while(ctx->stack + 3 < sfp) {
			if(sfp[K_MTDIDX].mtdNC != NULL && isCalledMethod(ctx, sfp + K_MTDIDX)) {
				return sfp_uline(ctx, sfp);
			}
			sfp--;
		}
	}
	return 0;
}

static void knh_Exception_addStackTrace(CTX ctx, knh_Exception_t *e, knh_sfp_t *sfp)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	if((mtd)->mn != MN_LAMBDA) {
		int i = 0, psize = knh_Method_psize(mtd);
		knh_uline_t uline = knh_stack_uline(ctx, sfp);
		knh_mtdcache_t mcache = {0, 0, NULL};
		knh_write_uline(ctx, cwb->w, uline);
		knh_write_type(ctx, cwb->w, (mtd)->cid);
		knh_putc(ctx, cwb->w, '.');
		knh_write_mn(ctx, cwb->w, (mtd)->mn);
		knh_putc(ctx, cwb->w, '(');
		for(i = 0; i < psize; i++) {
			knh_param_t *p = knh_ParamArray_get(DP(mtd)->mp, i);
			knh_type_t type = knh_type_tocid(ctx, p->type, O_cid(sfp[0].o));
			if(i > 0) {
				knh_putc(ctx, cwb->w, ',');
			}
			knh_write_fn(ctx, cwb->w, p->fn);
			knh_putc(ctx, cwb->w, '=');
			if(!knh_write_ndata(ctx, cwb->w, type, sfp[i+1].ndata)) {
				knh_write_Object(ctx, cwb->w, ctx->esp, &mcache, sfp[i+1].o, MN__k);
			}
		}
		knh_putc(ctx, cwb->w, ')');
		if(DP(e)->tracesNULL == NULL) {
			KNH_INITv(DP(e)->tracesNULL, new_Array(ctx, CLASS_String, 0));
		}
		knh_Array_add(ctx, DP(e)->tracesNULL, knh_cwb_newString(ctx, cwb));
	}
}

/* ------------------------------------------------------------------------ */

void knh_throw(CTX ctx, knh_sfp_t *sfp, long start)
{
	if(IS_Exception(ctx->e)) {
		knh_sfp_t *sp = (sfp == NULL) ? ctx->esp : sfp + start;
		knh_ExceptionHandler_t *hdr = ctx->ehdrNC;
		if(DP(ctx->e)->uline == 0) {
			DP(ctx->e)->uline = knh_stack_uline(ctx, sfp);
		}
		while(ctx->stack <= sp) {
			if(sp[0].mtdNC != NULL && isCalledMethod(ctx, sp)) {
				knh_Exception_addStackTrace(ctx, ctx->e, sp+1);
				sp[0].mtdNC = 0;
			}
			if(sp[0].hdr == hdr) {
				size_t i = 0, size = knh_Array_size(hdr->stacklist);
				for(i = 0; i < size; i++) {
					knh_Object_t *o = knh_Array_n(hdr->stacklist, i);
					O_cTBL(o)->ospi->checkout(ctx, o, 1);
				}
				knh_Array_trimSize(ctx, hdr->stacklist, 0);
				//DBG_ASSERT(DP(hdr)->return_address != NULL);
#ifdef K_USING_SETJMP_
				knh_longjmp(DP(hdr)->jmpbuf, 1);
#else
				knh_ExceptionHandler_longjmp(ctx, hdr);
#endif
				goto L_NOCATCH;
			}
			sp--;
		}
		L_NOCATCH:;
		{
			knh_mtdcache_t mcache = {0, 0, NULL};
			knh_write_Object(ctx, KNH_STDERR, sfp, &mcache, UPCAST(ctx->e), MN__dump);
		}
		knh_exit(ctx, 0);
	}
}

knh_bool_t isCATCH(CTX ctx, knh_rbp_t *rbp, int en, knh_String_t *event)
{
	knh_Exception_t *e = ctx->e;
	int res = 0;
	if(knh_bytes_strcasecmp(S_tobytes(event), S_tobytes(DP(e)->event)) != 0) {
		knh_ebi_t eid = knh_geteid(ctx, S_tobytes(event), EBI_unknown);
		if(eid != EBI_unknown) {
			res = expt_isa(ctx, DP(e)->eid, eid);
		}
	}
	if(res == 1) {
		KNH_SETv(ctx, rbp[en].o, e);
		KNH_SETv(ctx, ((knh_context_t*)ctx)->e, KNH_NULL);
	}
	return res;
}

void Context_push(CTX ctx, knh_Object_t *o)
{
	knh_Array_t *a = ctx->ehdrNC->stacklist;
	knh_Array_add(ctx, a, o);
}

knh_Object_t *Context_pop(CTX ctx)
{
	knh_Array_t *a = ctx->ehdrNC->stacklist;
	DBG_ASSERT(a->size > 0);
	a->size -= 1;
	{
		knh_Object_t *o = a->list[a->size];
		KNH_FINALv(ctx, a->list[a->size]);
		return o;
	}
}

/* ------------------------------------------------------------------------ */
/* [syslog] */

int knh_errno(int pe)
{
	int errno_ = errno;
	return (errno_ != 13) ? pe : LOG_ALERT;
}

const char *knh_strerror(void)
{
	int errno_ = errno;
#if !defined(K_USING_WINTHREAD_) || defined(K_USING_MINGW)
	return strerror(errno_);
#else
	const char emsg[256];
	strerror_s(emsg, 256, errno_);
	return emsg;
#endif
}

#define K_EVENT_FORMAT " <%s:%s> "

static void knh_traceCFMT(CTX ctx, int pe, int isThrowable, const char *ns, const char *event, knh_uline_t uline, knh_sfp_t *sfp, const char *fmt, va_list ap)
{
	char newfmt[256];
	char linefmt[80];
	knh_format_uline(ctx, linefmt, sizeof(linefmt), uline);
	knh_snprintf(newfmt, sizeof(newfmt), "%s+" K_INT_FMT K_EVENT_FORMAT "%s%s", ctx->trace, ctx->seq, ns, event, linefmt, fmt);
	ctx->spi->vsyslog(pe, newfmt, ap);
	if(ctx->ehdrNC != NULL && isThrowable) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_vprintf(ctx, cwb->w, fmt, ap);
		knh_Exception_t *e = new_Error(ctx, EBI_Fatal, knh_cwb_newString(ctx, cwb));
		DP(e)->uline = uline;
		CTX_setThrowingException(ctx, e);
		knh_throw(ctx, sfp, 0);
	}
}

static void knh_tracePERROR(CTX ctx, int pe, int isThrowable, const char *ns, const char *event, knh_uline_t uline, knh_sfp_t *sfp, const char *fmt, va_list ap)
{
	int errno_ = errno;
#if !defined(K_USING_WINTHREAD_) || defined(K_USING_MINGW)
	char *emsg = strerror(errno_);
#else
	char emsg[256];
	strerror_s(emsg, 256, errno_);
#endif
	char newfmt[512];
	char linefmt[80];
	knh_format_uline(ctx, linefmt, sizeof(linefmt), uline);
	knh_snprintf(newfmt, sizeof(newfmt), "%s+" K_INT_FMT K_EVENT_FORMAT "%s%s ERRNO=%d, ERR='%s'",
			ctx->trace, ctx->seq, ns, event, linefmt, fmt, errno, emsg);
	ctx->spi->vsyslog(pe, newfmt, ap);
	if(ctx->ehdrNC != NULL && isThrowable) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_vprintf(ctx, cwb->w, fmt, ap);
		knh_Exception_t *e = new_Error(ctx, EBI_Fatal, knh_cwb_newString(ctx, cwb));
		DP(e)->uline = uline;
		CTX_setThrowingException(ctx, e);
		knh_throw(ctx, sfp, 0);
	}
}

static void knh_traceKFMT(CTX ctx, int pe, int isThrowable, const char *ns, const char *event, knh_uline_t uline, knh_sfp_t *sfp, const char *fmt, va_list ap)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_printf(ctx, cwb->w, "%s+%i" K_EVENT_FORMAT, ctx->trace, ctx->seq, ns, event);
	knh_write_uline(ctx, cwb->w, uline);
	knh_vprintf(ctx, cwb->w, fmt, ap);
	ctx->spi->syslog(pe, knh_cwb_tochar(ctx, cwb));
	if(ctx->ehdrNC != NULL && isThrowable) {
		knh_Exception_t *e = new_Error(ctx, EBI_Fatal, knh_cwb_newString(ctx, cwb));
		DP(e)->uline = uline;
		CTX_setThrowingException(ctx, e);
		knh_throw(ctx, sfp, 0);
	}
	knh_cwb_clear(cwb, 0);
}

void knh_trace(CTX ctx, knh_sfp_t *sfp, int pe,const char *ns, const char *event, int isThrowable, const char *fmt, ...)
{
	if(pe <= LOG_CRIT) isThrowable = 1;
	if(knh_isAuditLogging(pe)) {
		knh_uline_t uline = 0;
		va_list ap;
		va_start(ap , fmt);
		if(ctx->ehdrNC != NULL) {
			if(ctx->gma != NULL && SP(ctx->gma)->uline != 0) {
				uline = SP(ctx->gma)->uline;
			}
			else {
				uline = knh_stack_uline(ctx, sfp);
			}
		}
		//((knh_context_t*)ctx)->seq += 1;
		if(fmt[0] == '*') {
			knh_traceCFMT(ctx, pe, isThrowable, ns, event, uline, sfp, fmt+1, ap);
		}
		else if(fmt[0] == '!') {
			if(errno != 13) pe = LOG_ALERT;
			knh_tracePERROR(ctx, pe, isThrowable, ns, event, uline, sfp, fmt+1, ap);
		}
		else {
			KNH_ASSERT(ctx->bufa != NULL);
			knh_traceKFMT(ctx, pe, isThrowable, ns, event, uline, sfp, fmt, ap);
		}
		va_end(ap);
		if(pe == LOG_EMERG) {
			knh_exit(ctx, 0);
		}
	}
}

//void knh_stack_perror(CTX ctx, knh_sfp_t *sfp, const char *ns, const char *event)
//{
//	int errno_ = errno;
//	int p = (errno_ != 13) ? LOG_ERR : LOG_ALERT;
//#ifndef K_USING_WINTHREAD_
//	char *emsg = strerror(errno_);
//#else
//	char emsg[256];
//	strerror_s(emsg, 256, errno_);
//#endif
//	ctx->spi->syslog(p, K_EVENT_FORMAT "errno=%d, msg='%s'", ns, event, errno_, emsg);
//}

/* ------------------------------------------------------------------------ */

#ifndef LIBNAME
#define LIBNAME "konoha"
#endif

void THROW_Halt(CTX ctx, knh_sfp_t *sfp, const char *msg)
{
	KNH_THROW(ctx, sfp, LOG_CRIT, "InternalError!!", "InternalError!!: %s", msg);
}

void THROW_Arithmetic(CTX ctx, knh_sfp_t *sfp, const char *msg)
{
	KNH_THROW(ctx, sfp, LOG_CRIT, "Arithmetic!!", "Arithmetic!!: %s", msg);
}

void THROW_OutOfRange(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t max)
{
	KNH_THROW(ctx, sfp, LOG_CRIT, "Model!!", "OutOfRange!!: %i not < %i", n, (knh_int_t)max);
}

void THROW_NoSuchMethod(CTX ctx, knh_sfp_t *sfp, knh_class_t cid, knh_methodn_t mn)
{
	KNH_THROW(ctx, sfp, LOG_CRIT, "Type!!", "NoSuchMethod!! %C.%M", cid, mn);
}

void THROW_ParamTypeError(CTX ctx, knh_sfp_t *sfp, size_t n, knh_methodn_t mn, knh_class_t reqt, knh_class_t cid)
{
	KNH_THROW(ctx, sfp, LOG_CRIT, "Type!!", "Type!!: %d of %M NOT %T", n, mn, cid);
}

#ifdef __cplusplus
}
#endif
