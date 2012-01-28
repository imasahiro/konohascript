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

#if defined(HAVE_LIBMEMCACHED)
#include <libmemcached/memcached.h>
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
		kbytes_t t;
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
	case LOG_EMERG:   return "PANIC";
	case LOG_ALERT:   return "ALERT";
	case LOG_CRIT:    return "CRIT";
	case LOG_ERR:     return "ERROR";
	case LOG_WARNING: return "WARNING";
	case LOG_NOTICE:  return "NOTICE";
	case LOG_INFO:    return "INFO";
	case LOG_DEBUG:   return "DEBUG";
	}
	return "";
}

static const char* knh_format_w3cdtf(char *buf, size_t bufsiz, struct tm *tmp)
{
	// 2001-08-02T10:45:23+09:00
#if defined(K_USING_WINDOWS_)
	_tzset();
	int gmtoff = (int)(_timezone / (60 * 60));
#else
	int gmtoff = (int)(tmp->tm_gmtoff / (60 * 60));
#endif /* defined(K_USING_WINDOWS_) */
	knh_snprintf(buf, bufsiz, "%04d-%02d-%02dT%02d:%02d:%02d%+02d:%02d",
		(int)(tmp->tm_year + 1900), (int)(tmp->tm_mon + 1), tmp->tm_mday,
		tmp->tm_hour, tmp->tm_min, tmp->tm_sec, gmtoff, 0);
	return (const char*)buf;
}

void knh_write_now(CTX ctx, kOutputStream *w)
{
	char buf[80];
	time_t t;
	struct tm tm;
	time(&t);
#if defined(K_USING_WINDOWS_)
#if defined(K_USING_MINGW_)
	tm = *localtime(&t);
#else
	localtime_s(&tm, &t);
#endif /* defined(K_USING_MINGW_) */
#else
	localtime_r(&t, &tm);
#endif /* defined(K_USING_WINDOWS_) */
	knh_write_ascii(ctx, w, knh_format_w3cdtf(buf, sizeof(buf), &tm));
}

/* ------------------------------------------------------------------------ */

void knh_fsyslog(FILE *fp, const char *group, const char *msg)
{
	if(group != NULL) {
		fputs("[", fp);
		fputs(group, fp);
		fputs("] ", fp);
	}
	fputs(msg, fp);
	fputs(K_OSLINEFEED, fp);
	fflush(fp);
}

/* ------------------------------------------------------------------------ */

static int isAudit         = 0;
void (*knh_syslog)(int priority, const char *message, ...);
void (*knh_vsyslog)(int priority, const char *message, va_list args);

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
#define K_LOG_msgSIZE         4096

void knh_logprintf(const char *group, int verbose, const char *fmt, ...)
{
	if(stdlog != stderr || verbose) {
		char buf[K_LOG_msgSIZE];
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

static void pseudo_vsyslog(int p, const char *fmt, va_list ap)
{
	if(stdlog != stderr) {
		char buf[K_LOG_msgSIZE];
		vsnprintf(buf, sizeof(buf), fmt, ap);
		knh_fsyslog(stdlog, LOG__(p), buf);
	}
}

static void pseudo_syslog(int p, const char *fmt, ...)
{
	va_list ap;
	va_start(ap , fmt);
	pseudo_vsyslog(p, fmt, ap);
	va_end(ap);
}

static void opt_a(int mode, const char *optstr)
{
	isAudit = (mode > 0) ? mode : 1;
#if defined(K_USING_SYSLOG)
//	((knh_ServiceSPI_t*)ctx->spi)->syslogspi = "syslog";
//	((knh_ServiceSPI_t*)ctx->spi)->syslog    = syslog;
//	((knh_ServiceSPI_t*)ctx->spi)->vsyslog   = vsyslog;
	knh_syslog = syslog;
	knh_vsyslog = vsyslog;
	openlog("konoha", LOG_PID, LOG_LOCAL7);
#else
	KNH_DIE("konoha: no available logging system.");
#endif
}

#if defined(HAVE_LIBMEMCACHED)

static memcached_st *memc = NULL;

/* added by Wakamori */
static void memcached_vsyslog(int p, const char *fmt, va_list ap)
{
	if(memc != NULL) {
		/* gettime */
		char date[256];
		time_t t;
		struct tm tm;
		time(&t);
#if defined(K_USING_WINDOWS_)
#if defined(K_USING_MINGW_)
		tm = *localtime(&t);
#else
		localtime_s(&tm, &t);
#endif /* defined(K_USING_MINGW_) */
#else
		localtime_r(&t, &tm);
#endif /* defined(K_USING_WINDOWS_) */
		knh_format_w3cdtf(date, 255, &tm);

		/* gethostname */
		char host[256];
		gethostname(host, 255);

		/* getpid */
		pid_t pid = getpid();

		char buf[K_LOG_msgSIZE];
		vsnprintf(buf, sizeof(buf), fmt, ap);
		const char *key = (const char *)buf;
		char *ptr = strchr(key, ' ');
		size_t key_len = ptr - key;

		const char *gkey = ptr + 1;
		ptr = strchr(gkey, ' ');
		size_t gkey_len = ptr - gkey;

		/* format log */
		char log[K_LOG_msgSIZE];
		snprintf(log, K_LOG_msgSIZE, "%s %s konoha[%d]: %s", date, host, pid, buf);
		//fprintf(stderr, "log=%s\n", log);

		memcached_return rc;
		time_t expire = 30 * 60; /* 30 minutes */
		rc = memcached_set_by_key(memc, gkey, gkey_len, key, key_len, log, strlen(log), expire, 0);
		DBG_ASSERT(rc == MEMCACHED_SUCCESS);
	}
}

/* added by Wakamori */
static void memcached_syslog(int p, const char *fmt, ...)
{
	va_list ap;
	va_start(ap , fmt);
	memcached_vsyslog(p, fmt, ap);
	va_end(ap);
}

#endif /* defined(HAVE_LIBMEMCACHED) */

/* added by Wakamori */
static void opt_logcached(int mode, const char *optstr)
{
#if defined(HAVE_LIBMEMCACHED)
	knh_syslog = memcached_syslog;
	knh_vsyslog = memcached_vsyslog;

	kbytes_t host_port = B(optstr);
	kbytes_t host = knh_bytes_head(host_port, ':');
	kint_t port;
	if (!knh_bytes_parseint(knh_bytes_next(host_port, ':'), &port)) {
		KNH_DIE("konoha: invalid arguments.");
	}
	memc = memcached_create(NULL);
	char tmp = host.buf[host.len];
	host.buf[host.len] = '\0';

	memcached_return rc;
	memcached_server_list_st servers;
	servers = memcached_server_list_append(NULL, host.text, port, &rc);
	if (rc != MEMCACHED_SUCCESS) {
		KNH_DIE("konoha: cannot append a memcached server.");
	}
	host.buf[host.len] = tmp;
	rc = memcached_server_push(memc, servers);
	if (rc != MEMCACHED_SUCCESS) {
		KNH_DIE("konoha: cannot push a memcached server.");
	}
	memcached_server_list_free(servers);
#else
	KNH_DIE("konoha: memcached library is not installed.");
#endif /* defined(HAVE_LIBMEMCACHED) */
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
		KNH_ASSERT(sizeof(kintptr_t) == sizeof(void*));
		KNH_ASSERT(sizeof(kint_t) <= sizeof(kfloat_t));
#ifdef K_USING_RBP_
		KNH_ASSERT(sizeof(krbp_t) * 2 == sizeof(ksfp_t));
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
/* added by Wakamori */
static char role[64] = {0};

/* added by Wakamori */
static kbool_t method_isPermissionAllowed(CTX ctx, kMethod *mtd)
{
	kDictMap *dmap = ctx->share->securityDictMap;
	CWB_t cwbbuf, *cwb = CWB_open0(ctx, &cwbbuf);
	CWB_write(ctx, cwb, S_tobytes(ClassTBL(mtd->cid)->sname));
	CWB_putc(ctx, cwb, '.');
	CWB_write(ctx, cwb, B(MN__(mtd->mn)));
	DBG_P("[methodname] : %s", CWB_tobytes(cwb).text);
	const char *idx, *p = role;
	while (p[0] != '\0') {
		idx = strchr((const char *)p, ',');
		kArray *a = NULL;
		if (idx != NULL) {
			a = (kArray *)knh_DictMap_getNULL(ctx, dmap, new_bytes2(p, idx - p));
			p = idx + 1;
		} else {
			a = (kArray *)knh_DictMap_getNULL(ctx, dmap, B(p));
			p += knh_strlen(p);
		}
		if (a != NULL) {
			int i;
			for (i = 0; i < knh_Array_size(a); i++) {
				const char *s = S_totext((kString*)knh_Array_n(a, i));
				if (strstr(s, CWB_tobytes(cwb).text) != NULL
					|| strstr(s, "all") != NULL) {
					// this method is allowed to be executed by this role
					CWB_close0(ctx, cwb);
					return 1;
				}
			}
		}
	}
	CWB_close0(ctx, cwb);
	return 0;
}

/* added by Wakamori */
void loadPolicy(CTX ctx)
{
	if (enforce_security == 0) return;
	// load $konoha.home.path/policy
	knh_setProperty(ctx, new_String(ctx, "role"), (dynamic *)new_String(ctx, role));
	CWB_t cwbbuf, *cwb = CWB_open0(ctx, &cwbbuf);
	kString *s = knh_getPropertyNULL(ctx, STEXT("konoha.home.path"));
	CWB_write(ctx, cwb, S_tobytes(s));
	CWB_write(ctx, cwb, STEXT("/policy"));
	kInputStream *is = new_InputStream(ctx, NULL, new_Path(ctx, CWB_newString0(ctx, cwb)));

	if (is == NULL) {
		DBG_P("policy file not found. All @Restricted annotated method is rescricted");
	}
	else {
		/*
		if (enforce_security == 0) {
			enforce_security = 1;
			knh_memcpy(role, "Default", 7);
			role[7] = '\0';
		}
		*/
		// parse policy file written in JSON
		// it must be refactored in the future
		kDictMap *dmap = ctx->share->securityDictMap;
		kString *line = knh_InputStream_readLine(ctx, is);
		while (IS_NOTNULL(line)) {
			//fprintf(stderr, "line=%s\n", S_totext(line));
			if (S_equals(line, STEXT("[")) || S_equals(line, STEXT("]"))) {
				/* ignore */
			} else {
				kString *key = NULL;
				kArray *a = new_Array(ctx, CLASS_String, 0);
				const char *idx = NULL;
				char *p = strstr(S_totext(line), "\"name\": \"");
				if (p != NULL) {
					p += 9; // == strlen("\"name\": \"")
					idx = strchr((const char *)p, '"');
					if (idx != NULL) {
						p[idx - p] = '\0';
						//fprintf(stderr, "name: %s\n", p);
						//knh_DictMap_set(ctx, dmap, new_String(ctx, "name"), new_String(ctx, p));
						key = new_String(ctx, p);
						p = (char *)idx + 1;
					}
				}
				p = strstr((const char *)p, "\"permission\": [");
				if (p != NULL) {
					p += 16; // == strlen("\"permission\": \[\"")
					idx = strchr((const char *)p, '"');
					while (idx != NULL) {
						p[idx - p] = '\0';
						if (strstr((const char *)p, ", ") == NULL) {
							//fprintf(stderr, "permission: %s\n", p);
							knh_Array_add(ctx, a, new_String(ctx, p));
						}
						p = (char *)idx + 1;
						idx = strchr((const char *)p, '"');
					}
				}
				if (key != NULL) {
					knh_DictMap_set(ctx, dmap, key, a);
				}
			}
			line = knh_InputStream_readLine(ctx, is);
		}
		knh_InputStream_close(ctx, is);
	}
}

/* modified by Wakamori */
void knh_enforceSecurity(CTX ctx, kMethod *mtd)
{
	if (enforce_security == 0) {
		Method_setRestricted(mtd, 0);
	} else if (Method_isRestricted(mtd)) {
		DBG_P("=== enforce security ===");
		DBG_P("[      role] : %s", role);

		if (method_isPermissionAllowed(ctx, mtd)) {
			Method_setRestricted(mtd, 0);
			DBG_P("[permission] : Allowed");
		}
		else {
			Method_setRestricted(mtd, 1);
			DBG_P("[permission] : Restricted");
		}
		DBG_P("========================");
	}
}

/* modified by Wakamori */
static void opt_enforce_security(int mode, const char *optstr)
{
	if(optstr != NULL) {
		int len = knh_strlen(optstr);
		if (len < 64) {
			knh_memcpy(role, optstr, len);
			role[len] = '\0';
		}
	}
	else {
		knh_memcpy(role, "Default", 7);
		role[7] = '\0';
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
#if defined(K_USING_MINGW_)
#define RECDATA
#define RECARG
#else
#define RECDATA , si, sc
#define RECARG , siginfo_t* si, void *sc
#endif

static void record_signal(CTX ctx, int sn RECARG)
{
#if defined(K_USING_MINGW_)
	fprintf(stderr, "signal number = %d", sn);
#else
	fprintf(stderr, "signal number = %d, signal errno = %d, signal code = %d", si->si_signo,si->si_errno, si->si_code);
	fprintf(stderr, "senders' pid = %x, sender's uid = %d\n", si->si_pid, si->si_uid);
#endif /* defined(K_USING_MINGW_) */
}

static void trapSIGINT(int sig RECARG)
{
	CTX ctx = knh_getCurrentContext();
//	record_signal(ctx, sig RECDATA);
	if(ctx != NULL) {
//#if defined(K_USING_MINGW_)
//		knh_ldata_t ldata[] = {LOG_END};
//#else
//		knh_ldata_t ldata[] = {LOG_i("sender_pid", si->si_pid), LOG_i("sender_uid", si->si_uid), LOG_END};
//#endif /* defined(K_USING_MINGW_) */
//		KNH_NTRACE(ctx, "konoha:signal", K_NOTICE, ldata);
		KNH_NTRACE2(ctx, "konoha:signal", K_NOTICE,
#if defined(K_USING_MINGW_)
				KNH_LDATA0
#else
				KNH_LDATA(LOG_i("sender_pid", si->si_pid), LOG_i("sender_uid", si->si_uid))
#endif
		);
	}
	_Exit(0);
}

static void trapSIGFPE(int sig RECARG)
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
	record_signal(ctx, sig RECDATA);
	if(ctx != NULL) {
#if defined(K_USING_MINGW_)
		int si_code = 0;
#else
		int si_code = (si->si_code < 9) ? si->si_code : 0;
#endif /* defined(K_USING_MINGW_) */
		THROW_Arithmetic(ctx, NULL, emsg[si_code]);
	}
}

#ifndef K_USING_DEBUG
static void trapSEGV(int sig RECARG)
{
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig RECDATA);
#if !defined(K_USING_MINGW_)
	if (si->si_code == SEGV_ACCERR) {
		void* address = (void*)si->si_addr;
		fprintf(stderr, "address=%p\n", address);
	}
#endif /* defined(K_USING_MINGW_) */
#if 0
	if(ctx != NULL) {
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, "segmentation fault");
	}
#endif
	_Exit(EX_SOFTWARE);
}

static void trapILL(int sig RECARG)
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
	record_signal(ctx, sig RECDATA);
	if(ctx != NULL) {
#if defined(K_USING_MINGW_)
		int si_code = 0;
#else
		int si_code = (si->si_code < 9) ? si->si_code : 0;
#endif /* defined(K_USING_MINGW_) */
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, emsg[si_code]);
	}
	_Exit(EX_SOFTWARE);
}

#if !defined(K_USING_MINGW_)
static void trapBUS(int sig RECARG)
{
	static const char *emsg[] = {
			/* BUS_NOOP	  0*/ "BUS_NOOP",
			/* BUS_ADRALN 1*/ "invalid address alignment",
			/* BUS_ADRERR 2*/ "nonexistent physical address",
			/* BUS_OBJERR 3*/ "object-specific HW error"};
	CTX ctx = knh_getCurrentContext();
	record_signal(ctx, sig RECDATA);
	if(ctx != NULL) {
		int si_code = (si->si_code < 4) ? si->si_code : 1;
		WCTX(ctx)->signal = sig;
		THROW_Halt(ctx, NULL, emsg[si_code]);
	}
	_Exit(EX_SOFTWARE);
}
#endif /* !defined(K_USING_MINGW_) */

#endif

#if defined(K_USING_MINGW_)
#define KNH_SIGNAL(T, handler) do {      \
	if(SIG_ERR == signal(T, handler)) {    \
		KNH_NTRACE2(ctx, "signal", K_PERROR, \
				KNH_LDATA(LOG_i("signal", T)));  \
	} \
} while (0)

#else
#define KNH_SIGACTION(T, sa, sa_orig, n) do {                \
	if(T < n  && sigaction(T, sa, sa_orig + T) != 0 ) {        \
		KNH_NTRACE2(ctx, "sigaction", K_PERROR, \
				KNH_LDATA(LOG_i("signal", T)));        \
	}                                                          \
	knh_bzero(sa, sizeof(struct sigaction));                   \
} while (0)

#endif /* defined(K_USING_MINGW_) */

#if defined(K_USING_MINGW_)
static void knh_setsignal(CTX ctx)
#else
static void knh_setsignal(CTX ctx, void *block, size_t n)
#endif /* defined(K_USING_MINGW_) */
{
#if !defined(K_USING_MINGW_)
	struct sigaction sa = {};
	struct sigaction *sa_orig = (struct sigaction*)block;
#endif /* !defined(K_USING_MINGW_) */
	WCTX(ctx)->signal = 0;
	WCTX(ctx)->siginfo = NULL;

#ifndef K_USING_DEBUG
#if defined(K_USING_MINGW_)
	KNH_SIGNAL(SIGSEGV, trapSEGV);
	KNH_SIGNAL(SIGILL, trapILL);
#else
	sa.sa_sigaction = trapSEGV;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGSEGV, &sa, sa_orig, n);
	sa.sa_sigaction = trapILL;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGILL, &sa, sa_orig, n);
	sa.sa_sigaction = trapBUS;
	sa.sa_flags     = SA_SIGINFO;
	KNH_SIGACTION(SIGBUS, &sa, sa_orig, n);
#endif /* defined(K_USING_MINGW_) */
#endif

#if defined(K_USING_MINGW_)
	KNH_SIGNAL(SIGFPE, trapSIGFPE);
#else
	sa.sa_sigaction = trapSIGFPE;
	sa.sa_flags     = SA_SIGINFO|SA_NODEFER;
	KNH_SIGACTION(SIGFPE, &sa, sa_orig, n);
#endif /* defined(K_USING_MINGW_) */
	if(CTX_isInteractive(ctx)) {
		DBG_P("set SIGINT This is not so good");
#if defined(K_USING_MINGW_)
		KNH_SIGNAL(SIGINT, trapSIGINT);
#else
		sa.sa_sigaction = trapSIGINT;
		sa.sa_flags     = SA_SIGINFO|SA_NODEFER;
		KNH_SIGACTION(SIGINT, &sa, sa_orig, n);
#endif /* defined(K_USING_MINGW_) */
	}
}

#if defined(K_USING_MINGW_)
#define KNH_SIGACTION2(T, sa_orig, n) KNH_SIGNAL(T, SIG_DFL)
#else
#define KNH_SIGACTION2(T, sa_orig, n) do {                   \
	if(T < n  && sigaction(T, sa_orig + T, NULL) != 0 ) {      \
		KNH_NTRACE2(ctx, "sigaction", K_PERROR, \
				KNH_LDATA(LOG_i("signal", T)));     \
	}                                         \
} while (0)

#endif /* defined(K_USING_MINGW_) */

#if defined(K_USING_MINGW_)
static void knh_unsetsignal(CTX ctx)
#else
static void knh_unsetsignal(CTX ctx, void *block, size_t n)
#endif /* defined(K_USING_MINGW_) */
{
#if !defined(K_USING_MINGW_)
	struct sigaction *sa_orig = (struct sigaction*)block;
	if(sa_orig != NULL) {
#endif /* !defined(K_USING_MINGW_) */
#ifndef K_USING_DEBUG
		KNH_SIGACTION2(SIGILL,  sa_orig, n);
#if !defined(K_USING_MINGW_)
		KNH_SIGACTION2(SIGBUS,  sa_orig, n);
#endif /* !defined(K_USING_MINGW_) */
		KNH_SIGACTION2(SIGSEGV, sa_orig, n);
#endif
		KNH_SIGACTION2(SIGFPE, sa_orig, n);
		if(CTX_isInteractive(ctx)) {
			KNH_SIGACTION2(SIGINT, sa_orig, n);
		}
#if !defined(K_USING_MINGW_)
	}
#endif /* !defined(K_USING_MINGW_) */
	WCTX(ctx)->signal = 0;
	WCTX(ctx)->siginfo = NULL;
}

kbool_t knh_VirtualMachine_launch(CTX ctx, ksfp_t *sfp)
{
#ifdef K_USING_SIGNAL
#if defined(K_USING_MINGW_)
	knh_setsignal(ctx);
#else
	struct sigaction sa_orig[32];
	knh_bzero(sa_orig, sizeof(struct sigaction) * 32);
	knh_setsignal(ctx, sa_orig, 32);
#endif /* defined(K_USING_MINGW_) */
	kbool_t b = (knh_VirtualMachine_run(ctx, sfp, CODE_LAUNCH) == NULL);
	if(ctx->signal != 0) {
#if defined(K_USING_MINGW_)
		if(ctx->signal == SIGSEGV || ctx->signal == SIGILL) {
#else
		if(ctx->signal == SIGSEGV || ctx->signal == SIGBUS || ctx->signal == SIGILL) {
#endif /* defined(K_USING_MINGW_) */
			_Exit(EX_SOFTWARE);
		}
	}
#if defined(K_USING_MINGW_)
	knh_unsetsignal(ctx);
#else
	knh_unsetsignal(ctx, sa_orig, 32);
#endif /* defined(K_USING_MINGW_) */
	return b;
#else
	kbool_t b = (knh_VirtualMachine_run(ctx, sfp, CODE_LAUNCH) == NULL);
#endif
#if !defined(K_USING_MINGW_)
	if(ctx->signal == SIGKILL) {
		_Exit(EX_SOFTWARE);
	}
#endif /* !defined(K_USING_MINGW_) */
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
	{OPT_("-a"), OPT_NUMBER, opt_a},
	{OPT_("-l"), OPT_STRING, opt_l},
	{OPT_("--enforce-security"), OPT_STRING, opt_enforce_security},
	{OPT_("--logcached"), OPT_STRING, opt_logcached},
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
	knh_syslog = pseudo_syslog;
	knh_vsyslog = pseudo_vsyslog;
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
					kint_t v = 0;
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
					if(knh_bytes_endsWith_(B(optstr), STEXT(".k"))) {
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

static void knh_write_cline(CTX ctx, kOutputStream *w, const char *file, kuintptr_t line)
{
	knh_putc(ctx, w, '(');
	knh_write_ascii(ctx, w, knh_sfile(file));
	knh_putc(ctx, w, ':');
	knh_write_dfmt(ctx, w, K_INTPTR_FMT, line);
	knh_putc(ctx, w, ')');
	knh_putc(ctx, w, ' ');
}

void knh_write_uline(CTX ctx, kOutputStream *w, kline_t uline)
{
	kuri_t uri = ULINE_uri(uline);
	kuintptr_t line = ULINE_line(uline);
	if(uline != 0 && uri != URI_unknown && line != 0) {
		knh_write_cline(ctx, w, FILENAME__(uri), line);
	}
}

void knh_write_mline(CTX ctx, kOutputStream *w, kmethodn_t mn, kline_t uline)
{
	kuri_t uri = ULINE_uri(uline);
	kuintptr_t line = ULINE_line(uline);
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

static const char* knh_readuline(CTX ctx, kline_t uline, char *buf, size_t bufsiz)
{
	kuri_t uri = ULINE_uri(uline);
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

static kbool_t isCalledMethod(CTX ctx, ksfp_t *sfp)
{
	kMethod *mtd = sfp[0].mtdNC;
	if(knh_isObject(ctx, UPCAST(mtd)) && IS_Method(mtd)) {
		//DBG_P("FOUND mtdNC: shift=%d, pc=%d", sfp[-2].shift, sfp[-1].pc);
		return 1;
	}
	return 0;
}

static kline_t sfp_uline(CTX ctx, ksfp_t *sfp)
{
	kopl_t *pc = sfp[K_PCIDX].pc;
	DBG_ASSERT(isCalledMethod(ctx, sfp + K_MTDIDX));
	if(pc == NULL) return 0;
	{
		int line = (pc-1)->line;
		while(pc->opcode != OPCODE_THCODE) pc--;
		kuri_t uri = ((klr_THCODE_t*)pc)->uri;
		return new_ULINE(uri, line);
	}
}

static kline_t knh_stack_uline(CTX ctx, ksfp_t *sfp)
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

void knh_write_sfp(CTX ctx, kOutputStream *w, ktype_t type, ksfp_t *sfp, int level)
{
	if(IS_Tunbox(type)) {
		if(IS_Tint(type)) {
			knh_write_ifmt(ctx, w, KINT_FMT, sfp[0].ivalue);
		}
		else if(IS_Tfloat(type)) {
			knh_write_ffmt(ctx, w, KFLOAT_FMT, sfp[0].fvalue);
		}
		else {
			knh_write_bool(ctx, w, sfp[0].bvalue);
		}
	}
	else {
		knh_write_Object(ctx, w, sfp[0].o, level);
	}
}

static void knh_Exception_addStackTrace(CTX ctx, kException *e, ksfp_t *sfp)
{
	CWB_t cwbbuf, *cwb = CWB_open0(ctx, &cwbbuf);
	kMethod *mtd = sfp[K_MTDIDX].mtdNC;
	if((mtd)->mn != MN_LAMBDA) {
		int i = 0, psize = knh_Method_psize(mtd);
		kline_t uline = knh_stack_uline(ctx, sfp);
		knh_write_uline(ctx, cwb->w, uline);
		knh_write_type(ctx, cwb->w, (mtd)->cid);
		knh_putc(ctx, cwb->w, '.');
		knh_write_mn(ctx, cwb->w, (mtd)->mn);
		knh_putc(ctx, cwb->w, '(');
		for(i = 0; i < psize; i++) {
			kparam_t *p = knh_Param_get(DP(mtd)->mp, i);
			ktype_t type = ktype_tocid(ctx, p->type, O_cid(sfp[0].o));
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
		knh_Array_add(ctx, e->tracesNULL, CWB_newString0(ctx, cwb));
	}
}

/* ------------------------------------------------------------------------ */

void knh_throw(CTX ctx, ksfp_t *sfp, long start)
{
	if(IS_Exception(ctx->e)) {
		ksfp_t *sp = (sfp == NULL) ? ctx->esp : sfp + start;
		kExceptionHandler *hdr = ctx->ehdrNC;
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
					kObject *o = knh_Array_n(hdr->stacklist, i);
					O_cTBL(o)->cdef->checkout(ctx, RAWPTR(o), 1);
				}
				kArrayrimSize(ctx, hdr->stacklist, 0);
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

KNHAPI2(void) knh_nthrow(CTX ctx, ksfp_t *sfp, const char *fault, knh_ldata_t *ldata)
{
	if(ctx->ehdrNC != NULL) {
		kline_t uline = knh_stack_uline(ctx, sfp);
		kException *e =
			new_Error(ctx, uline, new_String2(ctx, CLASS_String, fault, strlen(fault), SPOL_ASCII | SPOL_POOLALWAYS));
		CTX_setThrowingException(ctx, e);
		knh_throw(ctx, sfp, 0);
	}
}

static kException* new_Assertion(CTX ctx, kline_t uline)
{
	kException* e = new_(Exception);
	char buf[256] = {'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', '!', '!', ':', ' '};
	char *mbuf = buf + 13;
	knh_readuline(ctx, uline, mbuf, sizeof(buf)-13);
	if(mbuf[0] == 0) {
		kuri_t uri = ULINE_uri(uline);
		size_t line = ULINE_line(uline);
		knh_snprintf(buf, sizeof(buf), "Assertion!!: %s at line %lu", FILENAME__(uri), line);
	}
	KNH_SETv(ctx, e->emsg, new_String2(ctx, CLASS_String, (const char*)buf, knh_strlen(buf), SPOL_ASCII));
	e->uline = uline;
	return e;
}

void knh_assert(CTX ctx, ksfp_t *sfp, long start, kline_t uline)
{
	CTX_setThrowingException(ctx, new_Assertion(ctx, uline));
	knh_throw(ctx, sfp, start);
}

//void knh_record(CTX ctx, ksfp_t *sfp, int op, int pe, const char *action, const char *emsg, const knh_logdata_t *data, size_t datasize)
//{
//	kline_t uline = 0;
//	KNH_ASSERT(ctx->bufa != NULL);
//	if(op > 0 || isVerbose) {
//		CWB_t cwbbuf, *cwb = CWB_open0(ctx, &cwbbuf);
//		if(ctx->gma != NULL && SP(ctx->gma)->uline != 0) {
//			uline = SP(ctx->gma)->uline;
//		}
//		else if(ctx->ehdrNC != NULL) {
//			uline = knh_stack_uline(ctx, sfp);
//		}
//		knh_write_ascii(ctx, cwb->w, ctx->trace);
//		knh_putc(ctx, cwb->w, '+');
//		knh_write_ifmt(ctx, cwb->w, KINT_FMT, ctx->seq);
//		knh_putc(ctx, cwb->w, ' ');
//		knh_write_uline(ctx, cwb->w, uline);
//		knh_putc(ctx, cwb->w, ' ');
//		knh_write_ascii(ctx, cwb->w, action);
//		if(FLAG_is(op, K_RECFAILED)) {
//			knh_write_ascii(ctx, cwb->w, "<<FAILED>> ");
//		}
//		else {
//			knh_putc(ctx, cwb->w, ' ');
//		}
//		knh_write_logdata(ctx, cwb->w, data, datasize);
//		ctx->spi->syslog(pe, CWB_totext(ctx, cwb));
//		((kcontext_t*)ctx)->seq += 1;
//		CWB_close0(cwb);
//	}
//	if(FLAG_is(op, K_RECFAILED) && ctx->ehdrNC != NULL) {
//		CWB_t cwbbuf, *cwb = CWB_open0(ctx, &cwbbuf);
//		if(FLAG_is(op, K_RECCRIT) || ctx->e == (kException*)TS_EMPTY) {
//			knh_write_ascii(ctx, cwb->w, emsg);
//			knh_putc(ctx, cwb->w, ':'); knh_putc(ctx, cwb->w, ' ');
//			knh_write_logdata(ctx, cwb->w, data, datasize);
//		}
//		else if(IS_String(ctx->e)) {
//			kString *emsg = (kString*)ctx->e;
//			knh_write(ctx, cwb->w, S_tobytes(emsg));
//			knh_putc(ctx, cwb->w, ':'); knh_putc(ctx, cwb->w, ' ');
//			knh_write_logdata(ctx, cwb->w, data, datasize);
//		}
//		if(CWB_size(cwb) > 0) {
//			kException *e = new_Error(ctx, uline, CWB_newString0(ctx, cwb));
//			CTX_setThrowingException(ctx, e);
//			knh_throw(ctx, sfp, 0);
//		}
//		CWB_close0(ctx, cwb);
//	}
//}

/* ------------------------------------------------------------------------ */
#ifndef K_USING_LOGPOOL

#define EBUFSIZ 4096

typedef struct {
	union {
		kintptr_t    type;
		const char     *key;
		kintptr_t   ivalue;
		kuintptr_t  uvalue;
		kfloatptr_t fvalue;
		const char    *svalue;
		void          *ptr;
		Object        *ovalue;
	};
} knh_ldata2_t;

static char *write_b(char *p, char *ebuf, const char *text, size_t len)
{
	if(ebuf - p > len) {
		knh_memcpy(p, text, len);
		return p+len;
	}
	else {
		return NULL;
	}
}

static char *write_s(char *p, char *ebuf, const knh_ldata2_t *d)
{
	const char *s = d->svalue;
	if(ebuf - p > strlen(s) * 2  + 1) {
		p[0] = '"'; p++;
		while(*s != 0) {
			if(*s == '"') {
				p[0] = '\"'; p++;
			}
			p[0] = s[0]; p++; s++;
		}
		p[0] = '"'; p++;
		return p;
	}
	else {
		if(p < ebuf) { p[0] = '"'; p++; }
		while(*s != 0) {
			if(*s == '"' && p < ebuf) {
				p[0] = '\"'; p++;
			}
			if(p < ebuf) {p[0] = s[0]; p++;}
			s++;
		}
		if(p < ebuf) { p[0] = '"'; p++; }
		else return NULL;
		return p;
	}
}

static char *write_key(char *p, char *ebuf, const char *key)
{
	if(ebuf - p < 32) return NULL;
	p[0] = '"'; p++;
	p = write_b(p, ebuf, key, strlen(key));
	if(p != NULL) {
		if(ebuf - p < 32) return NULL;
		p[0] = '"'; p++;
		p[0] = ':'; p++;
		p[0] = ' '; p++;
	}
	return p;
}

//static char *write_d(char *p, kuintptr_t uvalue)
//{
//	kuintptr_t d = uvalue / 10, r = uvalue % 10;
//	if(d != 0) {
//		p = write_d(p, d);
//	}
//	p[0] = ('0' + r);
//	return p + 1;
//}

static void reverse(char *const start, char *const end, const int len)
{
	int i, l = len / 2;
	register char *s = start;
	register char *e = end - 1;
	for (i = 0; i < l; i++) {
		char tmp = *s;
		tmp  = *s;
		*s++ = *e;
		*e-- = tmp;
	}
}

static char *write_d(char *const p, const char *const end, kuintptr_t uvalue)
{
	int i = 0;
	while (p + i < end) {
		int tmp = uvalue % 10;
		uvalue /= 10;
		p[i] = '0' + tmp;
		++i;
		if (uvalue == 0)
			break;
	}
	reverse(p, p + i, i);
	return p + i;
}

static char *write_i(char *p, char *ebuf, const knh_ldata2_t *d)
{
	if(ebuf - p < 32) return NULL;
	kuintptr_t uvalue = d->uvalue;
	if(d->ivalue < 0) {
		p[0] = '-'; p++;
		uvalue = -(d->ivalue);
	}
	kuintptr_t u = uvalue / 10, r = uvalue % 10;
	if(u != 0) {
		p = write_d(p, ebuf, u);
	}
	p[0] = ('0' + r);
	return p + 1;
}

static char *write_u(char *p, char *ebuf, const knh_ldata2_t *d)
{
	if(ebuf - p < 32) return NULL;
	kuintptr_t u = d->uvalue / 10, r = d->uvalue % 10;
	if(u != 0) {
		p = write_d(p, ebuf, u);
	}
	p[0] = ('0' + r);
	return p + 1;
}

static char *write_f(char *p, char *ebuf, const knh_ldata2_t *d)
{
	if(ebuf - p < 32) return NULL;
	kuintptr_t uvalue = (kuintptr_t)d->ivalue;
	if(d->ivalue < 0) {
		p[0] = '-'; p++;
	}
	kuintptr_t u = uvalue / 1000, r = uvalue % 1000;
	if(u != 0) {
		p = write_d(p, ebuf, u);
	}
	else {
		p[0] = '0'; p++;
	}
	p[0] = '.'; p++;
	u = r / 100;
	p[0] = ('0' + (u)); p++;
	p[0] = ('0' + (u / 10)); p++;
	p[0] = ('0' + (u % 10));
	return p + 1;
}

static char *write_o(char *p, char *ebuf, const knh_ldata2_t *d)
{
	return NULL; // TODO
}

typedef char* (*writedata)(char *, char *, const knh_ldata2_t *);

static writedata writeldata[] = {
	NULL,
	write_s, /*LOGT_s*/
	write_i, /*LOGT_i*/
	write_u, /*LOGT_u*/
	write_f, /*LOGT_f*/
	write_u, /*LOGT_p*/
	write_o, /*LOGT_o*/
};

static char *write_comma(char *p, char *ebuf, const knh_ldata2_t *d)
{
	if(d->type != 0) {
		p[0] = ','; p++;
		p[0] = ' '; p++;
	}
	return p;
}

static void ntrace(CTX ctx, const char *event, int pe, const knh_ldata2_t *d)
{
	char buf[EBUFSIZ], *p = buf, *ebuf =  p + (EBUFSIZ - 4);
	int logtype = LOG_NOTICE;
	p = write_b(p, ebuf, ctx->trace, strlen(ctx->trace));
	p[0] = '+'; p++;
	p = write_d(p, ebuf, ctx->seq);
	((kcontext_t*)ctx)->seq += 1;
	p[0] = ' '; p++;
	p = write_b(p, ebuf, event, strlen(event));
	if(pe % 2 == 1) {
		p = write_b(p, ebuf, "*FAILED* ", strlen("*FAILED* "));
		logtype = LOG_ERR;
	}
	else {
		p[0] = ' '; p++;
	}
	p[0] = '{'; p++;
	if(pe % 2 == 1 && ((pe & FLAG_TRACE_ERRNO) == FLAG_TRACE_ERRNO)) {
		int errno_ = errno;
		if(errno_ > 0) {
			p = write_key(p, ebuf, "errno");
			p = write_d(p, ebuf, errno_);
			p[0] = ','; p++; p[0] = ' '; p++;
			knh_ldata2_t d[1];
			d[0].svalue = strerror(errno_);
			if(d[0].svalue != NULL) {
				p = write_key(p, ebuf, "msg");
				p = write_s(p, ebuf, d);
				p[0] = ','; p++; p[0] = ' '; p++;
			}
		}
	}
	while(d->type != 0) {
		char *p2 = write_key(p, ebuf, d[1].key);
		if(p2 != NULL) {
			if(d->type == LOGT_sfp) {
				// TODO
				d+=2; continue;
			}
			DBG_ASSERT(d->type <= LOGT_o);
			p2 = writeldata[d->type](p2, ebuf, d+2);
			if(p2 != NULL) {
				p = write_comma(p2, ebuf, d+3);
			}
		}
		d += 3;
	}
	p[0] = '}'; p++;
	p[0] = 0;
	knh_syslog(logtype, (const char*)buf);
	if(isVerbose) {
		fputs(LOG__(logtype), stderr);
		fputs(" ", stderr);
		fputs(buf, stderr);
		fputs(K_OSLINEFEED, stderr);
		fflush(stderr);
	}
//	if(pe % 2 == 1) {
//
//	}
}
#endif

kbool_t knh_isTrace(CTX ctx, const char *event)
{
	if(isAudit > 1) return 1;
	return 0;
}

void knh_ntrace(CTX ctx, const char *event, int pe, knh_ldata_t *ldata)
{
#ifdef K_USING_LOGPOOL
	KNH_TODO(__FUNCTION__);
#else
	switch(pe) {
	case K_OK :
		if(knh_isTrace(ctx, event)) {
			ntrace(ctx, event, pe, (const knh_ldata2_t*)ldata);
		}
		break;
	case K_FAILED :
		ntrace(ctx, event, pe, (const knh_ldata2_t*)ldata);
		break;
	case 2:
		if(knh_isTrace(ctx, event)) {
			ntrace(ctx, event, pe, (const knh_ldata2_t*)ldata);
		}
		break;
	case K_PERROR :
	case K_NOTICE :
	case 6:
	case 7:
	case 8:
		ntrace(ctx, event, pe, (const knh_ldata2_t*)ldata);
		break;
	default :
		if(CTX_isDebug(ctx)) {
			ntrace(ctx, event, pe, (const knh_ldata2_t*)ldata);
		}
		break;
	}
#endif
}

void knh_dtrace(CTX ctx, const char *event, int pe, kDictMap *data)
{

}

/* ------------------------------------------------------------------------ */

void THROW_Halt(CTX ctx, ksfp_t *sfp, const char *msg)
{
	KNH_NTHROW2(ctx, sfp, "Panic!!", "konoha", K_FAILED, KNH_LDATA(LOG_msg(msg)));
}
void THROW_OutOfMemory(CTX ctx, size_t size)
{
	KNH_NTHROW2(ctx, NULL, "OutOfMemory!!", "malloc", K_FAILED, KNH_LDATA(LOG_u("requested_size:bytes", size), LOG_u("used_size", ctx->stat->usedMemorySize)));
}
void THROW_StackOverflow(CTX ctx, ksfp_t *sfp)
{
	KNH_NTHROW2(ctx, sfp, "Script!!", "konoha:stack", K_FAILED,
			KNH_LDATA(LOG_msg("stack overflow"), LOG_u("stacksize", (ctx->esp - ctx->stack))));
}
void THROW_Arithmetic(CTX ctx, ksfp_t *sfp, const char *msg)
{
	KNH_NTHROW2(ctx, sfp, "Script!!", "arithmetic_operator", K_FAILED, KNH_LDATA(LOG_msg(msg)));
}
KNHAPI2(void) THROW_OutOfRange(CTX ctx, ksfp_t *sfp, kint_t n, size_t max)
{
	KNH_NTHROW2(ctx, sfp, "Script!!", "array_indexing", K_FAILED, KNH_LDATA(LOG_msg("out of array range"), LOG_i("index", n), LOG_i("arraysize", max)));
}
void THROW_TypeError(CTX ctx, ksfp_t *sfp, ktype_t reqt, ktype_t type)
{
	KNH_NTHROW2(ctx, sfp, "Script!!: Type Error", "konoha:type", K_FAILED, KNH_LDATA(LOG_t("requested_type", reqt), LOG_t("given_type", type)));
}
void THROW_NoSuchMethod(CTX ctx, ksfp_t *sfp, kclass_t cid, kmethodn_t mn)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	char msg[256], mname[256];
	knh_printf(ctx, cwb->w, "Script!!: No Such Method: %T.%M", cid, mn);
	knh_snprintf(msg, sizeof(msg), "%s", CWB_totext(ctx, cwb));
	CWB_close(ctx, cwb);
	knh_printf(ctx, cwb->w, "%C.%M", cid, mn);
	knh_snprintf(mname, sizeof(mname), "%s", CWB_totext(ctx, cwb));
	CWB_close(ctx, cwb);
	KNH_NTHROW2(ctx, sfp, msg, "konoha:type", K_FAILED, KNH_LDATA(LOG_msg(msg), LOG_s("method", mname)));
}
void THROW_ParamTypeError(CTX ctx, ksfp_t *sfp, size_t n, kmethodn_t mn, kclass_t reqt, kclass_t cid)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	char msg[256], mname[256];
	knh_printf(ctx, cwb->w, "Script!!: Type Error: %T.%M(#%d)", cid, mn, (int)n);
	knh_snprintf(msg, sizeof(msg), "%s", CWB_totext(ctx, cwb));
	CWB_close(ctx, cwb);
	knh_printf(ctx, cwb->w, "%C.%M", cid, mn);
	knh_snprintf(mname, sizeof(mname), "%s", CWB_totext(ctx, cwb));
	CWB_close(ctx, cwb);
	KNH_NTHROW2(ctx, sfp, msg, "konoha:type", K_FAILED, KNH_LDATA(LOG_msg(msg), LOG_s("method", mname), LOG_i("argument", n), LOG_t("requested_type", reqt), LOG_t("given_type", cid)));
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
