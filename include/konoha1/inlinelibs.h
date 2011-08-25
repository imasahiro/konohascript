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

static inline knh_bytes_t new_bytes(char *c_buf)
{
	DBG_ASSERT(c_buf != NULL);
	knh_bytes_t t;
	t.ubuf = (knh_uchar_t*)c_buf;
	t.len = knh_strlen(t.text);
	return t;
}

static inline knh_bytes_t new_bytes2(const char *text, size_t len)
{
	knh_bytes_t v;
	v.text = text;
	v.len = len;
	return v;
}

/* ------------------------------------------------------------------------ */

static inline knh_bool_t knh_bytes_equals(knh_bytes_t v1, knh_bytes_t v2)
{
	return (v1.len == v2.len && knh_strncmp(v1.text, v2.text, v1.len) == 0);
}

static inline knh_bool_t knh_bytes_equalsIgnoreCase(knh_bytes_t v1, knh_bytes_t v2)
{
	return (v1.len == v2.len && knh_strncasecmp(v1.text, v2.text, v1.len) == 0);
}

static inline int knh_bytes_startsWith(knh_bytes_t v1, knh_bytes_t v2)
{
	if(v1.len < v2.len) return 0;
	return (knh_strncmp(v1.text, v2.text, v2.len) == 0);
}

static inline knh_bool_t knh_bytes_endsWith(knh_bytes_t v1, knh_bytes_t v2)
{
	if(v1.len < v2.len) return 0;
	knh_text_t *p = v1.text + (v1.len-v2.len);
	return (knh_strncmp(p, v2.text, v2.len) == 0);
}

static inline knh_index_t knh_bytes_index(knh_bytes_t v, int ch)
{
	size_t i;
	for(i = 0; i < v.len; i++) {
		if(v.utext[i] == ch) return (knh_index_t)i;
	}
	return -1;
}

static inline knh_index_t knh_bytes_rindex(knh_bytes_t v, int ch)
{
	knh_index_t i;
	for(i = v.len - 1; i >= 0; i--) {
		if(v.utext[i] == ch) return i;
	}
	return -1;
}

static inline knh_bytes_t knh_bytes_head(knh_bytes_t t, int ch)
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

static inline knh_bytes_t knh_bytes_rhead(knh_bytes_t t, int ch)
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

static inline knh_bytes_t knh_bytes_next(knh_bytes_t v, int ch)
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

static inline knh_bytes_t knh_bytes_rnext(knh_bytes_t v, int ch)
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

static inline knh_bytes_t knh_bytes_first(knh_bytes_t t, knh_intptr_t loc)
{
	knh_bytes_t t2 = {{t.text}, loc};
	return t2;
}

static inline knh_bytes_t knh_bytes_last(knh_bytes_t t, knh_intptr_t loc)
{
	knh_bytes_t t2 = {{t.text + loc}, t.len - loc};
	return t2;
}

static inline knh_hashcode_t knh_hash(knh_hashcode_t h, const char *p, size_t len)
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

static inline void CWB_close0(CWB_t *cwb)
{
	size_t pos = cwb->pos - 1;
	DBG_ASSERT(cwb->pos > 0);
	DBG_ASSERT(cwb->ba->bu.buf[pos] == 0);
	knh_Bytes_clear(cwb->ba, pos);
	cwb->ba = NULL;
	cwb->w = NULL;
	cwb->pos = 0;
}

static inline knh_String_t *CWB_newString0(CTX ctx, CWB_t *cwb)
{
	knh_String_t *s = TS_EMPTY;
	if(cwb->pos < (cwb->ba)->bu.len) {
		s = new_String2(ctx, CLASS_String, (cwb->ba)->bu.text + cwb->pos, (cwb->ba)->bu.len - cwb->pos, 0);
	}
	CWB_close0(cwb);
	return s;
}

static inline CWB_t *CWB_open(CTX ctx, CWB_t *cwb)
{
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void CWB_close(CWB_t *cwb)
{
	knh_Bytes_clear(cwb->ba, cwb->pos);
}

static inline void CWB_putc(CTX ctx, CWB_t *cwb, int ch)
{
	knh_Bytes_putc(ctx, (cwb->ba), ch);
}

static inline void CWB_write(CTX ctx, CWB_t *cwb, knh_bytes_t t)
{
	knh_Bytes_write(ctx, (cwb->ba), t);
}

static inline size_t CWB_size(CWB_t *cwb)
{
	return (cwb->ba)->bu.len - cwb->pos;
}

static inline knh_bytes_t CWB_tobytes(CWB_t *cwb)
{
	knh_bytes_t t;
	t.text = (cwb->ba)->bu.text + cwb->pos;
	t.len =  (cwb->ba)->bu.len - cwb->pos;
	return t;
}

/* ------------------------------------------------------------------------ */

static inline size_t knh_array_index(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t size)
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

static inline knh_uint_t knh_time(void)
{
#if defined(K_USING_WINDOWS_)
	return (knh_uint_t)time(NULL);
#elif defined(K_USING_POSIX_)
	return (knh_uint_t)time(NULL);
#else
	return K_INT_MAX;
#endif
}

static inline knh_uint64_t knh_getTimeMilliSecond(void)
{
#if defined(K_USING_WINDOWS_)
	DWORD tickCount = GetTickCount();
	return (knh_int64_t)tickCount;
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
	return (knh_uint64_t)((current - start) & 0x7fffffff);
#else
	return 0;
#endif
}

#ifdef __cplusplus
}
#endif

#endif /*INLINELIBS_H_*/
