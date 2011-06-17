#ifndef INLINELIBS_H_
#define INLINELIBS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [RCinc] */

#if defined(USE_RCinc) && defined(K_USING_RCGC)
static void RCinc(CTX ctx, Object *o)
{
	knh_Object_RCinc(o);
}
#endif

/* ------------------------------------------------------------------------ */
/* [bytes] */

#if defined(USE_new_bytes) || defined(USE_B) || defined(USE_bytes)
static inline knh_bytes_t new_bytes(char *c_buf) CC_UNUSED;
static knh_bytes_t new_bytes(char *c_buf)
{
	DBG_ASSERT(c_buf != NULL);
	knh_bytes_t t;
	t.ubuf = (knh_uchar_t*)c_buf;
	t.len = knh_strlen(t.text);
	return t;
}
#endif

#if defined(USE_new_bytes2) || defined(USE_STEXT) || defined(USE_bytes)
static inline knh_bytes_t new_bytes2(const char *text, size_t len) CC_UNUSED;
static knh_bytes_t new_bytes2(const char *text, size_t len)
{
	knh_bytes_t v;
	v.text = text;
	v.len = len;
	return v;
}
#endif

/* ------------------------------------------------------------------------ */

#if defined(USE_bytes) || defined(USE_bytes_equals)
static inline knh_bool_t knh_bytes_equals(knh_bytes_t v1, knh_bytes_t v2) CC_UNUSED;
static knh_bool_t knh_bytes_equals(knh_bytes_t v1, knh_bytes_t v2)
{
	return (v1.len == v2.len && knh_strncmp(v1.text, v2.text, v1.len) == 0);
}
#endif

#if defined(USE_bytes) || defined(USE_bytes_equalsIgnoreCase)
static inline knh_bool_t knh_bytes_equalsIgnoreCase(knh_bytes_t v1, knh_bytes_t v2) CC_UNUSED;
static knh_bool_t knh_bytes_equalsIgnoreCase(knh_bytes_t v1, knh_bytes_t v2)
{
	return (v1.len == v2.len && knh_strncasecmp(v1.text, v2.text, v1.len) == 0);
}
#endif


#if defined(USE_bytes) || defined(USE_bytes_startsWith)
static inline int knh_bytes_startsWith(knh_bytes_t v1, knh_bytes_t v2) CC_UNUSED;
static int knh_bytes_startsWith(knh_bytes_t v1, knh_bytes_t v2)
{
	if(v1.len < v2.len) return 0;
	return (knh_strncmp(v1.text, v2.text, v2.len) == 0);
}
#endif

#if defined(USE_bytes) || defined(USE_bytes_endsWith)
static inline knh_bool_t knh_bytes_endsWith(knh_bytes_t v1, knh_bytes_t v2) CC_UNUSED;
static knh_bool_t knh_bytes_endsWith(knh_bytes_t v1, knh_bytes_t v2)
{
	if(v1.len < v2.len) return 0;
	knh_text_t *p = v1.text + (v1.len-v2.len);
	return (knh_strncmp(p, v2.text, v2.len) == 0);
}
#endif

#if defined(USE_bytes_index) || defined(USE_bytes)
static inline knh_index_t knh_bytes_index(knh_bytes_t v, int ch) CC_UNUSED;
static knh_index_t knh_bytes_index(knh_bytes_t v, int ch)
{
	size_t i;
	for(i = 0; i < v.len; i++) {
		if(v.utext[i] == ch) return (knh_index_t)i;
	}
	return -1;
}
#endif

#if defined(USE_bytes_rindex) || defined(USE_bytes)
static inline knh_index_t knh_bytes_rindex(knh_bytes_t v, int ch) CC_UNUSED;
static knh_index_t knh_bytes_rindex(knh_bytes_t v, int ch)
{
	knh_index_t i;
	for(i = v.len - 1; i >= 0; i--) {
		if(v.utext[i] == ch) return i;
	}
	return -1;
}
#endif

#if defined(USE_bytes) || defined(USE_bytes_head)
static inline knh_bytes_t knh_bytes_head(knh_bytes_t t, int ch) CC_UNUSED;
static knh_bytes_t knh_bytes_head(knh_bytes_t t, int ch)
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
#endif

#if defined(USE_bytes) || defined(USE_bytes_next)
static inline knh_bytes_t knh_bytes_next(knh_bytes_t v, int ch) CC_UNUSED;
static knh_bytes_t knh_bytes_next(knh_bytes_t v, int ch)
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
#endif

#if defined(USE_bytes) || defined(USE_bytes_rnext)
static inline knh_bytes_t knh_bytes_rnext(knh_bytes_t v, int ch) CC_UNUSED;
static knh_bytes_t knh_bytes_rnext(knh_bytes_t v, int ch)
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
#endif

#if defined(USE_bytes) || defined(USE_bytes_first)
static inline knh_bytes_t knh_bytes_first(knh_bytes_t t, knh_intptr_t loc) CC_UNUSED;
static knh_bytes_t knh_bytes_first(knh_bytes_t t, knh_intptr_t loc)
{
	knh_bytes_t t2 = {{t.text}, loc};
	return t2;
}
#endif

#if defined(USE_bytes) || defined(USE_bytes_last)
static inline knh_bytes_t knh_bytes_last(knh_bytes_t t, knh_intptr_t loc) CC_UNUSED;
static knh_bytes_t knh_bytes_last(knh_bytes_t t, knh_intptr_t loc)
{
	knh_bytes_t t2 = {{t.text + loc}, t.len - loc};
	return t2;
}
#endif

#if defined(USE_bytes) || defined(USE_bytes_slice)
//static inline knh_bytes_t knh_bytes_slice(knh_bytes_t t, size_t s, size_t e)
//{
//	knh_bytes_t t2;
//	t2.utext = t.utext + s;
//	t2.len = e - s;
//	DBG_ASSERT(s + t2.len <= t.len);
//	return t2;
//}
#endif

#if defined(USE_bytes) || defined(USE_bytes_subbytes)
//static inline knh_bytes_t knh_bytes_subbytes(knh_bytes_t t, size_t off, size_t len)
//{
//	knh_bytes_t t2;
//	t2.utext = t.utext + off;
//	t2.len = len;
//	DBG_ASSERT(off + len <= t.len);
//	return t2;
//}
#endif

#if defined(USE_hash)
static knh_hashcode_t knh_hash(knh_hashcode_t h, const char *p, size_t len)
{
	// TODO: Looking for good hash http://burtleburtle.net/bob/hash/doobs.html
	size_t i;
	for(i = 0; i < len; i++) {
		h = p[i] + 31 * h;
	}
	return h;
}
#endif

/* ------------------------------------------------------------------------ */
/* [cwb] */

#if defined(USE_cwb_open0) || defined(USE_cwb)
static inline knh_cwb_t *knh_cwb_open0(CTX ctx, knh_cwb_t *cwb) CC_UNUSED ;
static knh_cwb_t *knh_cwb_open0(CTX ctx, knh_cwb_t *cwb)
{
	knh_Bytes_putc(ctx, ctx->bufa, 0);  // FIXME knh_cwb_close()
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void knh_cwb_close0(knh_cwb_t *cwb) CC_UNUSED ;
static void knh_cwb_close0(knh_cwb_t *cwb)
{
	size_t pos = cwb->pos - 1;
	DBG_ASSERT(pos > 0);
	DBG_ASSERT(cwb->ba->bu.buf[pos] == 0);
	knh_Bytes_clear(cwb->ba, pos);
	cwb->ba = NULL;
	cwb->w = NULL;
	cwb->pos = 0;
}

static knh_String_t *knh_cwb_newString0(CTX ctx, knh_cwb_t *cwb) CC_UNUSED ;
static knh_String_t *knh_cwb_newString0(CTX ctx, knh_cwb_t *cwb)
{
	knh_String_t *s = TS_EMPTY;
	if(cwb->pos < (cwb->ba)->bu.len) {
		knh_bytes_t t;
		t.text = (cwb->ba)->bu.text + cwb->pos;
		t.len =  (cwb->ba)->bu.len - cwb->pos;
		s = new_S(ctx, t);
	}
	knh_cwb_close0(cwb);
	return s;
}

#endif

#if defined(USE_cwb_open) || defined(USE_cwb)
static inline knh_cwb_t *knh_cwb_open(CTX ctx, knh_cwb_t *cwb) CC_UNUSED ;
static knh_cwb_t *knh_cwb_open(CTX ctx, knh_cwb_t *cwb)
{
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void knh_cwb_close(knh_cwb_t *cwb) CC_UNUSED ;
static void knh_cwb_close(knh_cwb_t *cwb)
{
	knh_Bytes_clear(cwb->ba, cwb->pos);
}
#endif

#if defined(USE_cwb_putc) || defined(USE_cwb)
static inline void knh_cwb_putc(CTX ctx, knh_cwb_t *cwb, int ch) CC_UNUSED ;
static void knh_cwb_putc(CTX ctx, knh_cwb_t *cwb, int ch)
{
	knh_Bytes_putc(ctx, (cwb->ba), ch);
}
#endif

#if defined(USE_cwb_write) || defined(USE_cwb)
static inline void knh_cwb_write(CTX ctx, knh_cwb_t *cwb, knh_bytes_t t) CC_UNUSED ;
static void knh_cwb_write(CTX ctx, knh_cwb_t *cwb, knh_bytes_t t)
{
	knh_Bytes_write(ctx, (cwb->ba), t);
}
#endif

#if defined(USE_cwb_size) || defined(USE_cwb)
static inline size_t knh_cwb_size(knh_cwb_t *cwb) CC_UNUSED ;
static size_t knh_cwb_size(knh_cwb_t *cwb)
{
	return (cwb->ba)->bu.len - cwb->pos;
}
#endif

#if defined(USE_cwb_tobytes) || defined(USE_cwb)
static inline knh_bytes_t knh_cwb_tobytes(knh_cwb_t *cwb) CC_UNUSED ;
static knh_bytes_t knh_cwb_tobytes(knh_cwb_t *cwb)
{
	knh_bytes_t t;
	t.text = (cwb->ba)->bu.text + cwb->pos;
	t.len =  (cwb->ba)->bu.len - cwb->pos;
	return t;
}
#endif


/* ------------------------------------------------------------------------ */

#if defined(USE_array_index)
static size_t knh_array_index(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t size)
{
	size_t idx = (n < 0) ? size + n : n;
	if(unlikely(!(idx < size))) {
		THROW_OutOfRange(ctx, sfp, n, size);
	}
	return idx;
}
#endif

/* ------------------------------------------------------------------------ */
/* [TIME] */

#ifdef USE_TIME_H
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
#endif

#ifdef USE_time
static knh_uint_t knh_time(void)
{
#if defined(K_USING_WINDOWS_)
	return (knh_uint_t)time(NULL);
#elif defined(K_USING_POSIX_)
	return (knh_uint_t)time(NULL);
#else
	return K_INT_MAX;
#endif
}
#endif

#ifdef USE_getTimeMilliSecond
static knh_uint64_t knh_getTimeMilliSecond(void)
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
#endif

#ifdef __cplusplus
}
#endif

#endif /*INLINELIBS_H_*/
