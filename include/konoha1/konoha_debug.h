#ifndef KONOHA_DEBUG_H_
#define KONOHA_DEBUG_H_

#ifdef K_USING_SYSLOG
#include<syslog.h>
#endif

/* ------------------------------------------------------------------------ */
/* SYSLOG */

#ifndef LOG_EMERG
#define LOG_EMERG    0 /* system is unusable */
#define LOG_ALERT    1 /* action must be taken immediately */
#define LOG_CRIT     2 /* critical conditions */
#define LOG_ERR      3 /* error conditions */
#define LOG_WARNING  4 /* warning conditions */
#define LOG_NOTICE   5 /* normal but significant condition */
#define LOG_INFO     6 /* informational */
#define LOG_DEBUG    7 /* debug-level messages */
#endif

#define KNH_DIE(fmt, ...) {\
		knh_logprintf("DIE", 1 /*verbose*/, "[%s:%d] " fmt K_OSLINEFEED, __FUNCTION__, __LINE__, ## __VA_ARGS__);\
		exit(70);  /* EX_SOFTWARE */ \
	}\

#define KNH_NOTE(fmt, ...) {\
		knh_logprintf("konoha", 1 /*verbose*/, "[%s:%d] " fmt K_OSLINEFEED, __FUNCTION__, __LINE__, ## __VA_ARGS__);\
	}\

#define KNH_LOG(fmt, ...) \
		knh_logprintf("DEBUG", 0, "[%s:%d] " fmt K_OSLINEFEED, __FUNCTION__, __LINE__, ## __VA_ARGS__);

#define MEM_LOG(fmt, ...) if(knh_isVerboseGC()){ \
		knh_logprintf("MEMORY", 0, fmt K_OSLINEFEED,  ## __VA_ARGS__);\
	} \

#define LANG_LOG(fmt, ...) if(knh_isVerboseLang()){ \
		knh_logprintf("KONOHA", 0, fmt K_OSLINEFEED,  ## __VA_ARGS__);\
	} \

/* ------------------------------------------------------------------------ */
/* [DBGMODE] */

#define K_TRACEARGV          ,const char *_file, int _line, const char *_func
#define K_TRACEPOINT         ,__FILE__, (int)__LINE__, __FUNCTION__
#define K_TRACEDATA          ,_file, _line, _func

#ifdef K_USING_DEBUG0
#undef K_USING_DEBUG
#define KNH_ASSERT(c)
#define KNH_ABORT() {\
		KNH_SYSLOG(ctx, LOG_ERR, "Emergency Exit at %s", __FUNCTION__);\
		exit(1); \
	} \

//#define SAFE_(stmt)

#else/*KNH_FASTMODE*/
#define KNH_ASSERT(c)    assert(c)
#define KNH_ABORT()      abort()
#endif/*KNH_FASTMODE*/

#ifdef K_USING_DEBUG
#define DBG_(stmt)     stmt
#define DBG_ASSERT(c)  KNH_ASSERT(c)
#define DBG_ABORT(fmt, ...)  DBG_P(fmt, ## __VA_ARGS__); KNH_ABORT()
#else
#define DBG_(stmt)
#define DBG_ASSERT(c)
#define DBG_ABORT(fmt, ...)
#endif

#define STRICT_(stmt)     //stmt

/* MALLOC */
//#define K_USING_TRACEMALLOC 1

#define KNH_FREEZERO(p, size)            knh_bzero(p, size)

#ifdef K_EXPORTS
	#define KNH_MALLOC(ctx, size)       ctx->spi->mallocSPI(ctx, size)
	#define KNH_FREE(ctx, p, size)      ctx->spi->freeSPI(ctx, p, size)
#else
#if defined(K_USING_TRACEMALLOC)
	#define KNH_MALLOC(ctx, size)       TRACE_malloc(ctx, size K_TRACEPOINT)
	#define KNH_FREE(ctx, p, size)      TRACE_free(ctx, p, size K_TRACEPOINT)
	#define KNH_REALLOC(ctx, p, os, ns, wsize) TRACE_realloc(ctx, p, os, ns, wsize K_TRACEPOINT)
#else
	#define KNH_MALLOC(ctx, size)       knh_fastmalloc(ctx, size)
	#define KNH_FREE(ctx, p, size)      knh_fastfree(ctx, p, size)
	#define KNH_REALLOC(ctx, name, p, os, ns, wsize) knh_fastrealloc(ctx, p, os, ns, wsize)
#endif
#endif

#define KNH_VALLOC(ctx, size)        knh_valloc(ctx, size)
#define KNH_VFREE(ctx, p, size)      knh_vfree(ctx, p, size)

#ifdef K_EXPORTS
#define KNH_P(fmt, ...)   ctx->spi->pSPI(__FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define DBG_P(fmt, ...)   ctx->spi->pSPI(__FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)

#else/*not K_EXPORTS*/

#define KNH_P(fmt, ...)   dbg_p(__FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)

#ifdef K_USING_DEBUG
#define DBG_TRACE         ,const char* _file, const char* _func, int _line
#define DBG_P(fmt, ...)   dbg_p(__FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define TRACE_P(fmt, ...) dbg_p(_file, _func, _line, fmt, ## __VA_ARGS__)

#define KNH_LOCK(ctx, m)    ctx->spi->lockSPI(m, __FILE__, __FUNCTION__, __LINE__)
#define KNH_UNLOCK(ctx, m)  ctx->spi->unlockSPI(m, __FILE__, __FUNCTION__, __LINE__)

#else
#define DBG_TRACE
#define DBG_P(fmt, ...)
#define TRACE_P(fmt, ...)
#define TODO_P(fmt, ...)

#define KNH_LOCK(ctx, m)    ctx->spi->lockSPI(m)
#define KNH_UNLOCK(ctx, m)  ctx->spi->unlockSPI(m)

#endif
#endif/*K_EXPORTS*/

#define TODO0() {\
		fflush(stdout); \
		fprintf(stderr, "%s*TODO(%s:%d) TODO\n", __FUNCTION__, knh_sfile(__FILE__), __LINE__); \
	}\

#define TODO0_P(fmt, ...) {\
		fflush(stdout); \
		fprintf(stderr, "%s*TODO(%s:%d) ", __FUNCTION__, knh_sfile(__FILE__), __LINE__); \
		fprintf(stderr, fmt, ## __VA_ARGS__); \
		fprintf(stderr, "\n"); \
	}\

#ifdef K_USING_DEBUG
#define TODO          TODO0
#else
#define TODO()
#endif/*K_USING_DEBUG0*/

#define K_TODOMSG \
	"\n" \
	"* ------------------------------------------------------------ *\n" \
	"  You are the first person to use: %s.\n" \
	"  This function has been not implemented yet, unfortunately.\n" \
	"  Check out:\n\t%s in %s:%d\n" \
	"  Or, contact konoha development team via:\n" \
	"\thttp://codes.google.com/p/konoha.\n" \
	"\thttp://konoha.sourceforge.jp/.\n" \
	"  Thank you for using konoha. \n" \
	"* ------------------------------------------------------------ *\n" \

#define KNH_TODO(msg) \
	fprintf(stderr, K_TODOMSG, msg, __FUNCTION__, __FILE__, __LINE__);\
	KNH_ABORT();\


#define K_TESTMSG \
	"\n" \
	"* ------------------------------------------------------------ *\n" \
	"  You are the first person to try: %s.\n" \
	"  This function has been tested yet.\n" \
	"  Check out and remove this message at:\n\t%s in %s:%d\n" \
	"  Thank you for testing konoha. \n" \
	"* ------------------------------------------------------------ *\n" \

#define KNH_TEST(msg) \
	fprintf(stderr, K_TESTMSG, msg, __FUNCTION__, __FILE__, __LINE__);\

/* ------------------------------------------------------------------------ */

#define KNH_MAX(a,b)     (((a) > (b)) ? (a) : (b))
#define KNH_MIN(a,b)     (((a) < (b)) ? (a) : (b))
#define KNH_MID(a,b)     (((a) + (b)) / 2)

/* ------------------------------------------------------------------------ */

#endif /*KONOHA_DEBUG_H_*/
