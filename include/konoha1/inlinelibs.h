#ifndef INLINELIBS_H_
#define INLINELIBS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [RCinc] */

static inline void RCinc(CTX ctx CC_UNUSED, Object *o)
{
	knh_Object_RCinc(o);
}

/* ------------------------------------------------------------------------ */
/* [bytes] */

static inline kbytes_t new_bytes(char *c_buf)
{
	DBG_ASSERT(c_buf != NULL);
	kbytes_t t;
	t.ubuf = (kchar_t*)c_buf;
	t.len = knh_strlen(t.text);
	return t;
}

static inline kbytes_t new_bytes2(const char *text, size_t len)
{
	kbytes_t v;
	v.text = text;
	v.len = len;
	return v;
}

/* ------------------------------------------------------------------------ */

static inline kbool_t knh_bytes_equals(kbytes_t v1, kbytes_t v2)
{
	return (v1.len == v2.len && knh_strncmp(v1.text, v2.text, v1.len) == 0);
}

static inline kbool_t knh_bytes_equalsIgnoreCase(kbytes_t v1, kbytes_t v2)
{
	return (v1.len == v2.len && knh_strncasecmp(v1.text, v2.text, v1.len) == 0);
}

#define knh_bytes_startsWith(t, T)   knh_bytes_startsWith_(t, STEXT(T))
static inline int knh_bytes_startsWith_(kbytes_t v1, kbytes_t v2)
{
	if(v1.len < v2.len) return 0;
	return (knh_strncmp(v1.text, v2.text, v2.len) == 0);
}

#define knh_bytes_endsWith(t, T)   knh_bytes_endsWith_(t, STEXT(T))
static inline kbool_t knh_bytes_endsWith_(kbytes_t v1, kbytes_t v2)
{
	if(v1.len < v2.len) return 0;
	kascii_t *p = v1.text + (v1.len-v2.len);
	return (knh_strncmp(p, v2.text, v2.len) == 0);
}

static inline kindex_t knh_bytes_index(kbytes_t v, int ch)
{
	size_t i;
	for(i = 0; i < v.len; i++) {
		if(v.utext[i] == ch) return (kindex_t)i;
	}
	return -1;
}

static inline kindex_t knh_bytes_rindex(kbytes_t v, int ch)
{
	kindex_t i;
	for(i = v.len - 1; i >= 0; i--) {
		if(v.utext[i] == ch) return i;
	}
	return -1;
}

static inline kbytes_t knh_bytes_head(kbytes_t t, int ch)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if(t.utext[i] == ch) {
			t.len = i;
			break;
		}
	}
	return t;
}

static inline kbytes_t knh_bytes_rhead(kbytes_t t, int ch)
{
	long i;
	for(i = t.len - 1; i >= 0; i--) {
		if(t.utext[i] == ch) {
			t.len = i;
			break;
		}
	}
	return t;
}

static inline kbytes_t knh_bytes_next(kbytes_t v, int ch)
{
	size_t i;
	for(i = 0; i < v.len; i++) {
		if(v.utext[i] == ch) {
			v.text = v.text + (i+1);
			v.len = v.len - (i+1);
			break;
		}
	}
	return v;
}

static inline kbytes_t knh_bytes_rnext(kbytes_t v, int ch)
{
	long i;
	for(i = v.len - 1; i >= 0; i--) {
		if(v.utext[i] == ch) {
			v.text = v.text + (i+1);
			v.len = v.len - (i+1);
			break;
		}
	}
	return v;
}

static inline kbytes_t knh_bytes_first(kbytes_t t, kintptr_t loc)
{
	kbytes_t t2 = {{t.text}, loc};
	return t2;
}

static inline kbytes_t knh_bytes_last(kbytes_t t, kintptr_t loc)
{
	kbytes_t t2 = {{t.text + loc}, t.len - loc};
	return t2;
}

static inline khashcode_t knh_hash(khashcode_t h, const char *p, size_t len)
{
	// TODO: Looking for good hash http://burtleburtle.net/bob/hash/doobs.html
	size_t i;
	for(i = 0; i < len; i++) {
		h = p[i] + 31 * h;
	}
	return h;
}

/* ------------------------------------------------------------------------ */
/* [cwb] */

static inline CWB_t *CWB_open0(CTX ctx, CWB_t *cwb)
{
	knh_Bytes_putc(ctx, ctx->bufa, 0);  // FIXME CWB_close()
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void CWB_close0(CTX ctx, CWB_t *cwb)
{
	size_t pos = cwb->pos - 1;
	DBG_ASSERT(cwb->pos > 0);
	DBG_ASSERT(cwb->ba->bu.buf[pos] == 0);
	knh_Bytes_clear(cwb->ba, pos);
	cwb->ba = NULL;
	cwb->w = NULL;
	cwb->pos = 0;
}

static inline kString *CWB_newString0(CTX ctx, CWB_t *cwb)
{
	kString *s = TS_EMPTY;
	if(cwb->pos < (cwb->ba)->bu.len) {
		s = new_String2(ctx, CLASS_String, (cwb->ba)->bu.text + cwb->pos, (cwb->ba)->bu.len - cwb->pos, 0);
	}
	CWB_close0(ctx, cwb);
	return s;
}

static inline CWB_t *CWB_open(CTX ctx, CWB_t *cwb)
{
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void CWB_close(CTX ctx, CWB_t *cwb)
{
	knh_Bytes_clear(cwb->ba, cwb->pos);
}

static inline void CWB_putc(CTX ctx, CWB_t *cwb, int ch)
{
	knh_Bytes_putc(ctx, (cwb->ba), ch);
}

static inline void CWB_write(CTX ctx, CWB_t *cwb, kbytes_t t)
{
	knh_Bytes_write(ctx, (cwb->ba), t);
}

static inline size_t CWB_size(CWB_t *cwb)
{
	return (cwb->ba)->bu.len - cwb->pos;
}

static inline kbytes_t CWB_tobytes(CWB_t *cwb)
{
	kbytes_t t;
	t.text = (cwb->ba)->bu.text + cwb->pos;
	t.len =  (cwb->ba)->bu.len - cwb->pos;
	return t;
}

/* ------------------------------------------------------------------------ */

static inline size_t knh_array_index(CTX ctx, ksfp_t *sfp, kint_t n, size_t size)
{
	size_t idx = (n < 0) ? size + n : n;
	if(unlikely(!(idx < size))) {
		THROW_OutOfRange(ctx, sfp, n, size);
	}
	return idx;
}

/* ------------------------------------------------------------------------ */
/* [TIME] */

#if defined(K_USING_POSIX_)
#include<time.h>
#include<sys/time.h>
#elif defined(K_USING_WINDOWS_)
#include<windows.h>
#include <time.h>
#elif defined(K_USING_BTRON)
#include <btron/datetime.h>
#include <btron/event.h>
#endif

static inline kuint_t knh_time(void)
{
#if defined(K_USING_WINDOWS_)
	return (kuint_t)time(NULL);
#elif defined(K_USING_POSIX_)
	return (kuint_t)time(NULL);
#else
	return KINT_MAX;
#endif
}

static inline kuint64_t knh_getTimeMilliSecond(void)
{
#if defined(K_USING_WINDOWS_)
	DWORD tickCount = GetTickCount();
	return (kint64_t)tickCount;
#elif defined(K_USING_POSIX_)
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#elif defined(K_USING_BTRON)
	/* FIXME: thread safety */
	static volatile int first = 1;
	static UW start = 0;
	UW current;
	if (first) {
		get_etm(&start);
		first = 0;
	}
	get_etm(&current);
	return (kuint64_t)((current - start) & 0x7fffffff);
#else
	return 0;
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*INLINELIBS_H_*/
