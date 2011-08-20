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

#include"commons.h"
#include"../../include/konoha1/konoha_code_.h"
#include"../../include/konoha1/konohalang.h"

#if defined(K_USING_POSIX_)
#include<time.h>
#include<errno.h>
#include<unistd.h>
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

static const char* LOG__(int p)
{
	switch(p) {
	case LOG_EMERG:   return "PANIC ";
	case LOG_ALERT:   return "ALERT ";
	case LOG_CRIT:    return "CRIT ";
	case LOG_ERR:     return "ERROR ";
	case LOG_WARNING: return "WARNING ";
	case LOG_NOTICE:  return "NOTICE ";
	case LOG_INFO:    return "INFO ";
	case LOG_DEBUG:   return "DEBUG ";
	}
	return "";
}

//struct knh_data_t {
//	knh_short_t year; knh_short_t mon;
//	knh_short_t day;  knh_short_t hour;
//	knh_short_t min;  knh_short_t sec;
//	knh_intptr_t gmtoff;
//} knh_date_t ;

static const char* knh_format_w3cdtf(char *buf, size_t bufsiz, struct tm *tmp)
{
	// 2001-08-02T10:45:23+09:00
	knh_snprintf(buf, bufsiz, "%04d-%02d-%02dT%02d:%02d:%02d%+02d:%02d",
		(int)(tmp->tm_year + 1900), (int)(tmp->tm_mon + 1), tmp->tm_mday,
		tmp->tm_hour, tmp->tm_min, tmp->tm_sec, (int)(tmp->tm_gmtoff / (60 * 60)), 0);
	return (const char*)buf;
}

void knh_write_now(CTX ctx, knh_OutputStream_t *w)
{
	char buf[80];
	time_t t;
	struct tm tm;
	time(&t);
	localtime_r(&t, &tm);
	knh_write_ascii(ctx, w, knh_format_w3cdtf(buf, sizeof(buf), &tm));
}

void knh_fsyslog(FILE *fp, const char *group, const char *msg)
{
	if(group != NULL) {
		fputc('[', fp);
		fputs(group, fp);
		fputs("] ", fp);
	}
	fputs(msg, fp);
	fputs(K_OSLINEFEED, fp);
	fflush(fp);
}

/* ------------------------------------------------------------------------ */

static int isAudit         = 0;

#ifdef K_USING_DEBUG
static int isVerbose       = 1;
static int isVerboseLang   = 1;
static int isVerboseGC     = 1;
static int isVerbosePref   = 1;
static int isVerboseVM     = 1;
#else
static int isVerbose       = 0;
static int isVerboseLang   = 0;
static int isVerboseGC     = 0;
static int isVerbosePref   = 0;
static int isVerboseVM     = 0;
#endif

const char *logfile        = NULL;
static FILE *stdlog        = NULL;
#define K_LOGMSGSIZE         4096

void knh_logprintf(const char *group, int verbose, const char *fmt, ...)
{
	if(stdlog != stderr || verbose) {
		char buf[K_LOGMSGSIZE];
		va_list ap;
		va_start(ap , fmt);
		vsnprintf(buf, sizeof(buf), fmt, ap);
		knh_fsyslog(stdlog, group, buf);
		if(stdlog != stderr && verbose) {
			knh_fsyslog(stderr, group, buf);
		}
		va_end(ap);
	}
}

void pseudo_vsyslog(int p, const char *fmt, va_list ap)
{
	char buf[K_LOGMSGSIZE];
	vsnprintf(buf, sizeof(buf), fmt, ap);
	if(isVerbose && p <= LOG_ERR) {
		knh_fsyslog(stdlog, LOG__(p), buf);
	}
	if(isVerbose && stdlog != stderr) {
		knh_fsyslog(stdlog, LOG__(p), buf);
	}
}

void pseudo_syslog(int p, const char *fmt, ...)
{
	va_list ap;
	va_start(ap , fmt);
	pseudo_vsyslog(p, fmt, ap);
	va_end(ap);
}

static void opt_l(int m, const char *filename)
{
	const char *mode = "w";
	if(filename == NULL) {
		filename = "konoha.log";
		mode = "a";
	}
	if(filename[0] == '+') {
		mode = "a";
		filename++;
	}
	stdlog = fopen(filename, mode);
	if(stdlog == NULL) {
		fprintf(stderr, "cannot open logfile: %s\n", filename);
		exit(1);
	}
}

void knh_closelog(void)
{
	if(stdlog != stderr) {
		fflush(stdlog);
		fclose(stdlog);
		stdlog = stderr;
	}
}

/* ------------------------------------------------------------------------ */

void opt_a(CTX ctx, int mode, const char *optstr)
{
	isAudit = 1;
#if defined(K_USING_SYSLOG)
	((knh_ServiceSPI_t*)ctx->spi)->syslogspi = "syslog";
	((knh_ServiceSPI_t*)ctx->spi)->syslog    = syslog;
	((knh_ServiceSPI_t*)ctx->spi)->vsyslog   = vsyslog;
	openlog("konoha", LOG_PID, LOG_LOCAL7);
	//KNH_SYSLOG(ctx, NULL, LOG_NOTICE, "init", "version='%s', rev=%d, auditlevel=%d", K_VERSION, K_REVISION, auditLevel);
#else
	if(knh_openlog(ctx)) {
		((knh_ServiceSPI_t*)ctx->spi)->syslogspi = "konohalog";
	}
	else {
		fprintf(stdout, "konoha: no available logging system.\n");
		exit(0);
	}
#endif

#ifdef K_DEOS_TRACE
	char *trace = knh_getenv(K_DEOS_TRACE);
	if(trace != NULL) {
		LOGSFPDATA = {sDATA("traceid", trace)};
		NOTE_OK("trace");
	}
#endif
}

KNHAPI2(int) knh_isVerbose(void)
{
	return isVerbose;
}

static void opt_v(int mode, const char *optstr)
{
	if(mode == 0) {
		isVerboseLang   = 1;
		isVerboseGC     = 1;
		isVerbosePref   = 1;
		isVerboseVM     = 1;
		dump_sysinfo(NULL, NULL, 1/*isALL*/);
		KNH_ASSERT(sizeof(knh_intptr_t) == sizeof(void*));
		KNH_ASSERT(sizeof(knh_Token_t) <= sizeof(knh_Object_t));
		KNH_ASSERT(sizeof(knh_Stmt_t) <= sizeof(knh_Object_t));
		KNH_ASSERT(sizeof(knh_int_t) <= sizeof(knh_float_t));
#ifdef K_USING_RBP_
		KNH_ASSERT(sizeof(knh_rbp_t) * 2 == sizeof(knh_sfp_t));
#endif
	}
	isVerbose = 1;
}

int knh_isVerboseLang(void)
{
	return isVerboseLang;
}

void opt_verbose_lang(int mode, const char *optstr)
{
	isVerboseLang = 1;
}

int knh_isVerboseGC(void)
{
	return isVerboseGC;
}

static void opt_verbose_gc(int mode, const char *optstr)
{
	isVerboseGC = 1;
}

int knh_isVerbosePref(void)
{
	return isVerbosePref;
}

static void opt_verbose_pref(int mode, const char *optstr)
{
	isVerbosePref = 1;
}

static int enforce_security = 0;

void knh_enforceSecurity(CTX ctx, knh_Method_t *mtd)
{
	Method_setRestricted(mtd, enforce_security);
}

static void opt_enforce_security(int mode, const char *optstr)
{
	if(optstr != NULL) {
		fprintf(stdout, "security policy is unsupported\n");
		exit(0);
	}
	enforce_security = 1;
}

void knh_PleaseLetUsKnowYourOS(CTX ctx, const char *msg, const char *file, int line)
{
	if(CTX_isInteractive(ctx)) {
	fprintf(stderr,
		"\n\t==================================================================="
		"\n\t\t@%s:%d"
		"\n\t\t%s"
		"\n\t\tPlease let us know your platform (os, version, etc.)"
		"\n\t\t\t email: %s"
		"\n\t===================================================================\n",
		file, line, msg, K_EMAIL_BUG_REPORT);
	}
}

/* ------------------------------------------------------------------------ */
/* [signal] */

// http://www.ibm.com/developerworks/jp/linux/library/l-sigdebug/index.html

static void record_signal(CTX ctx, int sn , siginfo_t* si, void *sigdata)
{
	fprintf(stderr, "signal number = %d, signal errno = %d, signal code = %d", si->si_signo,si->si_errno, si->si_code);
	fprintf(stderr, "senders' pid = %x, sender's uid = %d\n", si->si_pid, si->si_uid);
}

static void trapSIGINT(int sig, siginfo_t* si, void *sc)
{
	CTX ctx = knh_getCurrentContext();
//	record_signal(ctx, sig, si, sc);
	if(ctx != NULL) {
		LOGSFPDATA = {iDATA("sender_pid", si->si_pid), iDATA("sender_uid", si->si_uid)};
		CRIT_Failed("konoha", "Interrupted!!");
	}
	_Exit(0);
}

static void trapSIGFPE(int sig, siginfo_t* si, void *sc)
{
	static const char *emsg[] = {
			/* FPE_NOOP	  0*/ "SIGFPE",
			/* FPE_FLTDIV 1*/ "floating point divide by zero",
			/* FPE_FLTOVF 2*/ "floating point overflow",
			/* FPE_FLTUND 3*/ "floating point underflow",
			/* FPE_FLTRES 4*/ "floating point inexact result",
			/* FPE_FLTINV	5	*/ "invalid floating point operation",
			/* FPE_FLTSUB	6	*/ "subscript out of range",
			/* FPE_INTDIV	7	*/ "integer divide by zero",
			/* FPE_INTOVF	8	*/ "integer overflow"};
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig, si, sc);
	if(ctx != NULL) {
		int si_code = (si->si_code < 9) ? si->si_code : 0;
		THROW_Arithmetic(ctx, NULL, emsg[si_code]);
	}
}

#ifndef K_USING_DEBUG
static void trapSEGV(int sig, siginfo_t* si, void* sc)
{
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig, si, sc);
	if (si->si_code == SEGV_ACCERR) {
		void* address = (void*)si->si_addr;
		fprintf(stderr, "address=%p\n", address);
	}
	if(ctx != NULL) {
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, "segmentation fault");
	}
	_Exit(EX_SOFTWARE);
}

static void trapILL(int sig, siginfo_t* si, void* sc)
{
	static const char *emsg[] = {
			/* FPE_NOOP	  0*/ "SIGILL",
			/* ILL_ILLOPC 1*/ "illegal opcode",
			/* ILL_ILLTRP 2*/ "illegal trap",
			/* ILL_PRVOPC 3*/ "privileged opcode",
			/* ILL_ILLOPN 4*/ "illegal operand",
			/* 	5	*/ "illegal addressing mode",
			/* 	6	*/ "privileged register",
			/* 	7	*/ "coprocessor error",
			/* 	8	*/ "internal stack error"};
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig, si, sc);
	if(ctx != NULL) {
		int si_code = (si->si_code < 9) ? si->si_code : 0;
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, emsg[si_code]);
	}
	_Exit(EX_SOFTWARE);
}

static void trapBUS(int sig, siginfo_t* si, void* sc)
{
	static const char *emsg[] = {
			/* BUS_NOOP	  0*/ "BUS_NOOP",
			/* BUS_ADRALN 1*/ "invalid address alignment",
			/* BUS_ADRERR 2*/ "nonexistent physical address",
			/* BUS_OBJERR 3*/ "object-specific HW error"};
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig, si, sc);
	if(ctx != NULL) {
		int si_code = (si->si_code < 4) ? si->si_code : 1;
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, emsg[si_code]);
	}
	_Exit(EX_SOFTWARE);
}

#endif

#define KNH_SIGACTION(T, sa, sa_orig, n)                       \
	if(T < n  && sigaction(T, sa, sa_orig + T) != 0 ) {        \
		LOGSFPDATA = {iDATA("signal", T), __ERRNO__};          \
		NOTE_Failed("sigaction");                              \
	}                                                          \
	knh_bzero(sa, sizeof(struct sigaction));                   \

static void knh_setsignal(CTX ctx, void *block, size_t n)
{
	struct sigaction sa = {};
	struct sigaction *sa_orig = (struct sigaction*)block;
	WCTX(ctx)->signal = 0;
	WCTX(ctx)->siginfo = NULL;

#ifndef K_USING_DEBUG
	sa.sa_sigaction = trapSEGV;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGSEGV, &sa, sa_orig, n);
	sa.sa_sigaction = trapILL;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGILL, &sa, sa_orig, n);
	sa.sa_sigaction = trapBUS;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGBUS, &sa, sa_orig, n);

#endif

	sa.sa_sigaction = trapSIGFPE;
	sa.sa_flags     = SA_SIGINFO|SA_NODEFER;
	KNH_SIGACTION(SIGFPE, &sa, sa_orig, n);
	if(CTX_isInteractive(ctx)) {
		DBG_P("set SIGINT This is not so good");
		sa.sa_sigaction = trapSIGINT;
		sa.sa_flags     = SA_SIGINFO|SA_NODEFER;
		KNH_SIGACTION(SIGINT, &sa, sa_orig, n);
	}
}

#define KNH_SIGACTION2(T, sa_orig, n)                          \
	if(T < n  && sigaction(T, sa_orig + T, NULL) != 0 ) {      \
		LOGSFPDATA = {iDATA("signal", T), __ERRNO__};          \
		NOTE_Failed("sigaction");                              \
	}                                                          \

static void knh_unsetsignal(CTX ctx, void *block, size_t n)
{
	struct sigaction *sa_orig = (struct sigaction*)block;
	if(sa_orig != NULL) {
#ifndef K_USING_DEBUG
		KNH_SIGACTION2(SIGILL,  sa_orig, n);
		KNH_SIGACTION2(SIGBUS,  sa_orig, n);
		KNH_SIGACTION2(SIGSEGV, sa_orig, n);
#endif
		KNH_SIGACTION2(SIGFPE, sa_orig, n);
		if(CTX_isInteractive(ctx)) {
			KNH_SIGACTION2(SIGINT, sa_orig, n);
		}
	}
	WCTX(ctx)->signal = 0;
	WCTX(ctx)->siginfo = NULL;
}

knh_bool_t knh_VirtualMachine_launch(CTX ctx, knh_sfp_t *sfp)
{
#ifdef K_USING_SIGNAL
	struct sigaction sa_orig[32];
	knh_bzero(sa_orig, sizeof(struct sigaction) * 32);
	knh_setsignal(ctx, sa_orig, 32);
	knh_bool_t b = (knh_VirtualMachine_run(ctx, sfp, CODE_LAUNCH) == NULL);
	if(ctx->signal != 0) {
		if(ctx->signal == SIGSEGV || ctx->signal == SIGBUS || ctx->signal == SIGILL) {
			_Exit(EX_SOFTWARE);
		}
	}
	knh_unsetsignal(ctx, sa_orig, 32);
	return b;
#else
	knh_bool_t b = (knh_VirtualMachine_run(ctx, sfp, CODE_LAUNCH) == NULL);
#endif
	if(ctx->signal == SIGKILL) {
		_Exit(EX_SOFTWARE);
	}
	return b;
}

/* ------------------------------------------------------------------------ */

#define OPT_EMPTY    0
#define OPT_NUMBER   1
#define OPT_STRING   2
#define OPT_(O)      O, (sizeof(O)-1)

typedef struct {
	const char *name;
	size_t len;
	int type;
	void (*setopt)(int, const char *);
} knh_optdata_t ;

static knh_optdata_t optdata[] = {
	{OPT_("-v"), OPT_NUMBER, opt_v},
	{OPT_("-l"), OPT_STRING, opt_l},
	{OPT_("--enforce-security"), OPT_STRING, opt_enforce_security},
	{OPT_("--verbose:gc"), OPT_EMPTY, opt_verbose_gc},
	{OPT_("--verbose:lang"), OPT_EMPTY, opt_verbose_lang},
	{OPT_("--verbose:pref"), OPT_EMPTY, opt_verbose_pref},
	{NULL, 0, OPT_EMPTY, NULL}, // END
};

static knh_optdata_t *knh_getoptdata(const char *name)
{
	knh_optdata_t *d = optdata;
	while(d->name != NULL) {
		if(knh_strncmp(d->name, name, d->len) == 0) {
			return d;
		}
		d++;
	}
	return NULL;
}

void konoha_ginit(int argc, const char **argv)
{
	int n;
	stdlog = stderr;
	for(n = 1; n < argc; n++) {
		const char *t = argv[n];
		if(t[0] == '-' && (isalnum(t[1]) || t[1] == '-')) {
			knh_optdata_t *d = knh_getoptdata(t);
			int optnum = 1;              // default
			const char* optstr = NULL;   // default
			if(d == NULL) continue;
			if(d->type == OPT_NUMBER) {
				t += d->len;
				if(t[0] == '=') t++;
				if(isalnum(t[0])) {
					knh_int_t v = 0;
					knh_bytes_parseint(B((char*)t), &v);
					optnum = (int)v;
				}
			}
			else if(d->type == OPT_STRING) {
				t += d->len;
				if(t[0] == '=') {
					optstr = t + 1;
				}
				else if(t[0] != 0) {
					optstr = t;
				}
				else if(n + 1 < argc) {
					n++;
					optstr = argv[n];
					if(optstr[0] == '-') {
						n--; optstr = NULL;
					}
					if(knh_bytes_endsWith(B(optstr), STEXT(".k"))) {
						break;
					}
				}
			}
			d->setopt(optnum, optstr);
			continue;
		}
	}
}

/* ------------------------------------------------------------------------ */

void dbg_p(const char *file, const char *func, int line, const char *fmt, ...)
{
#ifndef K_USING_DEBUG
	if(isVerbose) {
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
	knh_write_ascii(ctx, w, knh_sfile(file));
	knh_putc(ctx, w, ':');
	knh_write_dfmt(ctx, w, K_INTPTR_FMT, line);
	knh_putc(ctx, w, ')');
	knh_putc(ctx, w, ' ');
}

void knh_write_uline(CTX ctx, knh_OutputStream_t *w, knh_uline_t uline)
{
	knh_uri_t uri = ULINE_uri(uline);
	knh_uintptr_t line = ULINE_line(uline);
	if(uline != 0 && uri != URI_unknown && line != 0) {
		knh_write_cline(ctx, w, FILENAME__(uri), line);
	}
}

void knh_write_mline(CTX ctx, knh_OutputStream_t *w, knh_methodn_t mn, knh_uline_t uline)
{
	knh_uri_t uri = ULINE_uri(uline);
	knh_uintptr_t line = ULINE_line(uline);
	if(uline != 0 && uri != URI_unknown && line != 0) {
		if(mn == MN_) {
			knh_write_cline(ctx, w, FILENAME__(uri), line);
		}
		else {
			knh_putc(ctx, w, '(');
			knh_write_mn(ctx, w, mn);
			knh_putc(ctx, w, ':');
			knh_write_dfmt(ctx, w, K_INTPTR_FMT, line);
			knh_putc(ctx, w, ')');
			knh_putc(ctx, w, ' ');
		}
	}
}

static void readuline(FILE *fp, char *buf, size_t bufsiz)
{
	int ch;
	size_t p = 1;
	while((ch = fgetc(fp)) != -1) {
		if(ch == ' ' || ch == '\t') continue;
		break;
	}
	buf[0] = ch;
	while((ch = fgetc(fp)) != -1) {
		if(ch == '\n') break;
		buf[p] = ch; p++;
		if(!(p + 1 < bufsiz)) break;
	}
	buf[p] = 0;
}

static const char* knh_readuline(CTX ctx, knh_uline_t uline, char *buf, size_t bufsiz)
{
	knh_uri_t uri = ULINE_uri(uline);
	size_t line = ULINE_line(uline);
	buf[0] = 0;
	if(uline != 0 && uri > URI_EVAL && line != 0) {
		char const *fname = URI__(uri);
		FILE *fp = fopen(fname, "r");
		if(fp != NULL) {
			if(line == 1) {
				readuline(fp, buf, bufsiz);
			}
			else {
				size_t linec = 1;
				int ch;
				while((ch = fgetc(fp)) != -1) {
					if(ch == '\n') {
						linec++;
						if(linec == line) {
							readuline(fp, buf, bufsiz);
							break;
						}
					}
				}
			}
			fclose(fp);
		}
	}
	return (const char*)buf;
}

/* ------------------------------------------------------------------------ */
/* [throw] */

static knh_bool_t isCalledMethod(CTX ctx, knh_sfp_t *sfp)
{
	knh_Method_t *mtd = sfp[0].mtdNC;
	if(knh_isObject(ctx, UPCAST(mtd)) && IS_Method(mtd)) {
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

void knh_write_sfp(CTX ctx, knh_OutputStream_t *w, knh_type_t type, knh_sfp_t *sfp, int level)
{
	if(IS_Tunbox(type)) {
		if(IS_Tint(type)) {
			knh_write_ifmt(ctx, w, K_INT_FMT, sfp[0].ivalue);
		}
		else if(IS_Tfloat(type)) {
			knh_write_ffmt(ctx, w, K_FLOAT_FMT, sfp[0].fvalue);
		}
		else {
			knh_write_bool(ctx, w, sfp[0].bvalue);
		}
	}
	else {
		knh_write_Object(ctx, w, sfp[0].o, level);
	}
}

static void knh_Exception_addStackTrace(CTX ctx, knh_Exception_t *e, knh_sfp_t *sfp)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open0(ctx, &cwbbuf);
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	if((mtd)->mn != MN_LAMBDA) {
		int i = 0, psize = knh_Method_psize(mtd);
		knh_uline_t uline = knh_stack_uline(ctx, sfp);
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
			knh_write_sfp(ctx, cwb->w, type, &sfp[i+1], FMT_line);
		}
		knh_putc(ctx, cwb->w, ')');
		if(e->tracesNULL == NULL) {
			KNH_INITv(e->tracesNULL, new_Array(ctx, CLASS_String, 0));
		}
		knh_Array_add(ctx, e->tracesNULL, knh_cwb_newString0(ctx, cwb));
	}
}

/* ------------------------------------------------------------------------ */

void knh_throw(CTX ctx, knh_sfp_t *sfp, long start)
{
	if(IS_Exception(ctx->e)) {
		knh_sfp_t *sp = (sfp == NULL) ? ctx->esp : sfp + start;
		knh_ExceptionHandler_t *hdr = ctx->ehdrNC;
		if((ctx->e)->uline == 0) {
			(ctx->e)->uline = knh_stack_uline(ctx, sfp);
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
					O_cTBL(o)->cdef->checkout(ctx, RAWPTR(o), 1);
				}
				knh_Array_trimSize(ctx, hdr->stacklist, 0);
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
		knh_write_Object(ctx, KNH_STDERR, UPCAST(ctx->e), FMT_dump);
		knh_exit(ctx, 0);
	}
}

static knh_Exception_t* new_Assertion(CTX ctx, knh_uline_t uline)
{
	knh_Exception_t* e = new_(Exception);
	char buf[256] = {'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', '!', '!', ':', ' '};
	char *mbuf = buf + 13;
	knh_readuline(ctx, uline, mbuf, sizeof(buf)-13);
	if(mbuf[0] == 0) {
		knh_uri_t uri = ULINE_uri(uline);
		size_t line = ULINE_line(uline);
		knh_snprintf(buf, sizeof(buf), "Assertion!!: %s at line %ld", FILENAME__(uri), line);
	}
	KNH_SETv(ctx, e->emsg, new_String2(ctx, CLASS_String, (const char*)buf, knh_strlen(buf), K_SPOLICY_ASCII));
	e->uline = uline;
	return e;
}

void knh_assert(CTX ctx, knh_sfp_t *sfp, long start, knh_uline_t uline)
{
	CTX_setThrowingException(ctx, new_Assertion(ctx, uline));
	knh_throw(ctx, sfp, start);
}

/* ------------------------------------------------------------------------ */

static void knh_write_key(CTX ctx, knh_OutputStream_t *w, const char *key)
{
	knh_putc(ctx, w, '"');
	knh_write_ascii(ctx, w, key);
	knh_putc(ctx, w, '"');
	knh_putc(ctx, w, ':'); knh_putc(ctx, w, ' ');
}

static void knh_write_logdata(CTX ctx, knh_OutputStream_t *w, const knh_logdata_t *d, size_t max)
{
	int c = 0, p = 0, sch = '[', ech = ']';
	knh_putc(ctx, w, '{');
	while(p < max && d->key != NULL) {
		int ch = d->key[0];
		const char *key = d->key + 1;
		const knh_logdata_t *d1 = d+1;
		const knh_logdata_t *d2 = d+2;
		if(c > 0) {
			knh_putc(ctx, w, ','); knh_putc(ctx, w, ' ');
		}
		c++;
		knh_write_key(ctx, w, key);
		switch(ch) {
			case 'i': {
				knh_write_ifmt(ctx, w, K_INT_FMT, (knh_int_t)d1->ivalue);
				break;
			}
			case 'u': {
				knh_write_ifmt(ctx, w, K_UINT_FMT, (knh_uint_t)d1->uvalue);
				break;
			}
			case 'e': {
				int errno_ = errno;
				knh_write_ifmt(ctx, w, K_INT_FMT, (knh_int_t)errno);
				knh_putc(ctx, w, ','); knh_putc(ctx, w, ' ');
				knh_write_key(ctx, w, "strerror");
				knh_putc(ctx, w, '"');
				knh_write_ascii(ctx, w, strerror(errno_));
				knh_putc(ctx, w, '"');
				break;
			}
			case 'f': {
				knh_write_ffmt(ctx, w, K_FLOAT_FMT, (knh_float_t)d1->fvalue);
				break;
			}
			case 's': if(d1->svalue != NULL) {
				knh_bytes_t t = {{d1->svalue}, knh_strlen(d1->svalue)};
				knh_write_quote(ctx, w, '"', t, 1/*hasUTF8*/);
			}
			else {
				knh_write_ascii(ctx, w, "null");
			}
			break;
			case 'p': {
				knh_write_ptr(ctx, w, d1->ptr);
				break;
			}
			case 'o': {
				knh_write_Object(ctx, w, d1->ovalue, FMT_line);
				break;
			}
			case 'c': {
				knh_write_cid(ctx, w, (knh_class_t)d1->ivalue);
				break;
			}
			case 't': {
				knh_write_type(ctx, w, (knh_type_t)d1->ivalue);
				break;
			}
			case 'n': {
				knh_write_fn(ctx, w, (knh_fieldn_t)d1->ivalue);
				break;
			}
			case 'm': {
				knh_write_mn(ctx, w, (knh_methodn_t)d1->ivalue);
				break;
			}
			case 'I': {
				knh_putc(ctx, w, sch);
				knh_write_ifmt(ctx, w, K_INT_FMT, (knh_int_t)d1->ivalue);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_ifmt(ctx, w, K_INT_FMT, (knh_int_t)d2->ivalue);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'U': {
				knh_putc(ctx, w, sch);
				knh_write_ifmt(ctx, w, K_UINT_FMT, (knh_uint_t)d1->uvalue);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_ifmt(ctx, w, K_UINT_FMT, (knh_uint_t)d2->uvalue);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'F': {
				knh_putc(ctx, w, sch);
				knh_write_ffmt(ctx, w, K_FLOAT_FMT, (knh_float_t)d1->fvalue);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_ffmt(ctx, w, K_FLOAT_FMT, (knh_float_t)d2->fvalue);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'S': {
				knh_bytes_t t0 = {{d1->svalue}, knh_strlen(d1->svalue)};
				knh_bytes_t t =  {{d2->svalue}, knh_strlen(d2->svalue)};
				knh_putc(ctx, w, sch);
				knh_write_quote(ctx, w, '"', t0, 1/*hasUTF8*/);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_quote(ctx, w, '"', t, 1/*hasUTF8*/);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'P': {
				knh_putc(ctx, w, sch);
				knh_write_ptr(ctx, w, d1->ptr);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_ptr(ctx, w, d2->ptr);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'O': {
				knh_putc(ctx, w, sch);
				knh_write_Object(ctx, w, d1->ovalue, FMT_line);
				knh_putc(ctx, w, ','); 	knh_putc(ctx, w, ' ');
				knh_write_Object(ctx, w, d2->ovalue, FMT_line);
				knh_putc(ctx, w, ech);
				d++; p++;
				break;
			}
			case 'M': {
				knh_write_cname(ctx, w, (knh_class_t)d1->ivalue);
				knh_putc(ctx, w, '.');
				knh_write_mn(ctx, w, (knh_methodn_t)d2->ivalue);
				d++; p++;
				break;
			}
			case '+': {
				knh_write_logdata(ctx, w, d1->logger(ctx), 256);
			}
			default : {
				DBG_P("unknown key=%s", key); return;
			}
		}
		d += 2;
		p += 2;
	}
	knh_putc(ctx, w, '}');
}

void knh_record(CTX ctx, knh_sfp_t *sfp, int op, int pe, const char *action, const char *emsg, const knh_logdata_t *data, size_t datasize)
{
	knh_uline_t uline = 0;
	KNH_ASSERT(ctx->bufa != NULL);
	if(op > 0 || isVerbose) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open0(ctx, &cwbbuf);
		if(ctx->gma != NULL && SP(ctx->gma)->uline != 0) {
			uline = SP(ctx->gma)->uline;
		}
		else if(ctx->ehdrNC != NULL) {
			uline = knh_stack_uline(ctx, sfp);
		}
		knh_write_ascii(ctx, cwb->w, ctx->trace);
		knh_putc(ctx, cwb->w, '+');
		knh_write_ifmt(ctx, cwb->w, K_INT_FMT, ctx->seq);
		knh_putc(ctx, cwb->w, ' ');
		knh_write_uline(ctx, cwb->w, uline);
		knh_putc(ctx, cwb->w, ' ');
		knh_write_ascii(ctx, cwb->w, action);
		if(FLAG_is(op, K_RECFAILED)) {
			knh_write_ascii(ctx, cwb->w, "<<FAILED>> ");
		}
		else {
			knh_putc(ctx, cwb->w, ' ');
		}
		knh_write_logdata(ctx, cwb->w, data, datasize);
		ctx->spi->syslog(pe, knh_cwb_tochar(ctx, cwb));
		((knh_context_t*)ctx)->seq += 1;
		knh_cwb_close0(cwb);
	}
	if(FLAG_is(op, K_RECFAILED) && ctx->ehdrNC != NULL) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open0(ctx, &cwbbuf);
		if(FLAG_is(op, K_RECCRIT) || ctx->e == (knh_Exception_t*)TS_EMPTY) {
			knh_write_ascii(ctx, cwb->w, emsg);
			knh_putc(ctx, cwb->w, ':'); knh_putc(ctx, cwb->w, ' ');
			knh_write_logdata(ctx, cwb->w, data, datasize);
		}
		else if(IS_String(ctx->e)) {
			knh_String_t *emsg = (knh_String_t*)ctx->e;
			knh_write(ctx, cwb->w, S_tobytes(emsg));
			knh_putc(ctx, cwb->w, ':'); knh_putc(ctx, cwb->w, ' ');
			knh_write_logdata(ctx, cwb->w, data, datasize);
		}
		if(knh_cwb_size(cwb) > 0) {
			knh_Exception_t *e = new_Error(ctx, uline, knh_cwb_newString0(ctx, cwb));
			CTX_setThrowingException(ctx, e);
			knh_throw(ctx, sfp, 0);
		}
		knh_cwb_close0(cwb);
	}
}

/* ------------------------------------------------------------------------ */

void THROW_Halt(CTX ctx, knh_sfp_t *sfp, const char *msg)
{
	LOGDATA = {sDATA("msg", msg)};
	CRIT_Failed("konoha", "InternalError!!");
}
void THROW_OutOfMemory(CTX ctx, size_t size)
{
	LOGSFPDATA = {uDATA("requested_size(bytes)", size), uDATA("used_size", ctx->stat->usedMemorySize)};
	CRIT_Failed("malloc", "OutOfMemory!!");
}
void THROW_StackOverflow(CTX ctx, knh_sfp_t *sfp)
{
	LOGDATA = {sDATA("msg", "stack overflow"), uDATA("stacksize", (ctx->esp - ctx->stack))};
	CRIT_Failed("stack", "Script!!");
}
void THROW_Arithmetic(CTX ctx, knh_sfp_t *sfp, const char *msg)
{
	LOGDATA = {sDATA("msg", msg)};
	CRIT_Failed("arithmetics", "Script!!");
}
KNHAPI2(void) THROW_OutOfRange(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t max)
{
	LOGDATA = {sDATA("msg", "out of index range"), iDATA("idx", n), iDATA("max", max)};
	CRIT_Failed("range", "Script!!");
}
void THROW_TypeError(CTX ctx, knh_sfp_t *sfp, knh_type_t reqt, knh_type_t type)
{
	LOGDATA = {tDATA("requested_type", reqt), tDATA("given_type", type)};
	CRIT_Failed("typecheck", "Script!!");
}
void THROW_NoSuchMethod(CTX ctx, knh_sfp_t *sfp, knh_class_t cid, knh_methodn_t mn)
{
	LOGDATA = {tDATA("msg", "undefined method"), MDATA("method", cid, mn)};
	CRIT_Failed("typecheck", "Script!!");
}
void THROW_ParamTypeError(CTX ctx, knh_sfp_t *sfp, size_t n, knh_methodn_t mn, knh_class_t reqt, knh_class_t cid)
{
	LOGDATA = {MDATA("method", cid, mn), iDATA("argument", n), tDATA("requested_type", reqt), tDATA("given_type", cid)};
	CRIT_Failed("typecheck", "Script!!");
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
