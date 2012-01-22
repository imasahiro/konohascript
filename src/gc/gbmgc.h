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


#include <stdbool.h>

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

//#define GCSTAT 1
#if defined(GCDEBUG) && !defined(GCSTAT)
#define GCSTAT 1
#include <time.h>
#endif

	/* memory config */
#define ONE ((uintptr_t)1)
#define SEGMENT_SIZE (128 * KB_)
#define SUBHEAP_KLASS_MIN  6 /* 1 <<  6 == 64 */
#define SUBHEAP_KLASS_MAX 12 /* 1 << 12 == 4096 */
#define SUBHEAP_DEFAULT_SEGPOOL_SIZE (128)/* 128 * SEGMENT_SIZE(128k) = 16MB*/
#define MIN_ALIGN (ONE << SUBHEAP_KLASS_MIN)
#define SEGMENT_LEVEL 3

#define KlassBlockSize(klass) (ONE << klass)
#define SUBHEAP_KLASS_SIZE_MIN KlassBlockSize(SUBHEAP_KLASS_MIN)
#define SUBHEAP_KLASS_SIZE_MAX KlassBlockSize(SUBHEAP_KLASS_MAX)
#define BITMAP_FULL ((uintptr_t)(-1))
#define ALIGN(x,n)  (((x)+((n)-1))&(~((n)-1)))
#define PTR_SIZE (sizeof(void*))
#define BITS (PTR_SIZE * 8)
#ifdef K_USING_WIN64_
#define FFS(n) __builtin_ffsll(n)
#define CLZ(n) __builtin_clzll(n)
#define CTZ(n) __builtin_ctzll(n)
#else
#define FFS(n) __builtin_ffsl(n)
#define CLZ(n) __builtin_clzl(n)
#define CTZ(n) __builtin_ctzl(n)
#endif
#define BSR(n) CLZ(n)
//#define BSR(n) (CLZ(n) & 0x3f)
#define BM_SET(m, mask)  (m |= mask)
#define BM_TEST(m, mask) (m  & mask)

#ifdef unlikely
#undef unlikely
#endif

#ifdef likely
#undef likely
#endif

#define unlikely(x)   __builtin_expect(!!(x), 0)
#define likely(x)     __builtin_expect(!!(x), 1)
#define prefetch_(addr, rw, locality) __builtin_prefetch(addr, rw, locality)

#define for_each_heap(H, I, HEAPS) \
		for (I = SUBHEAP_KLASS_MIN, H = (HEAPS)+I; I <= SUBHEAP_KLASS_MAX; ++H, ++I)

	static inline void *do_malloc(size_t size);
	static inline void *do_realloc(void *ptr, size_t oldSize, size_t newSize);
	static inline void  do_free(void *ptr, size_t size);

	/* ARRAY */
#define ARRAY(T) ARRAY_##T##_t
#define DEF_ARRAY_STRUCT(T) \
		struct ARRAY(T) {\
			T *list;\
			int size;  \
			int capacity;  \
		}

#define DEF_ARRAY_T(T)              \
		struct ARRAY(T);                    \
	typedef struct ARRAY(T) ARRAY(T);   \
	DEF_ARRAY_STRUCT(T)

#define DEF_ARRAY_OP(T)\
		static inline ARRAY(T) *ARRAY_init_##T (ARRAY(T) *a) {\
			a->list = (T*) do_malloc(4 * sizeof(T));\
			a->capacity  = 4;\
			a->size  = 0;\
			return a;\
		}\
	static inline void ARRAY_##T##_add(ARRAY(T) *a, T v) {\
		if (a->size + 1 >= a->capacity) {\
			size_t os = sizeof(T) * a->capacity;\
			a->capacity *= 2;\
			a->list = (T*)do_realloc(a->list, os, sizeof(T) * a->capacity);\
		}\
		a->list[a->size++] = v;\
	}\
	static inline T ARRAY_##T##_get(ARRAY(T) *a, int idx) {\
		return a->list[idx];\
	}\
	static inline void ARRAY_##T##_set(ARRAY(T) *a, int idx, T v){ \
		a->list[idx] = v;\
	}\
	static inline void ARRAY_##T##_clear(ARRAY(T) *a) {\
		knh_bzero(a->list, sizeof(T) * a->size);\
		a->size = 0;\
	}\
	static inline void ARRAY_##T##_dispose(ARRAY(T) *a) {\
		do_free(a->list, sizeof(T) * a->capacity);\
		a->size     = 0;\
		a->capacity = 0;\
		a->list     = NULL;\
	}

#define DEF_ARRAY_T_OP(T) \
		DEF_ARRAY_T(T);\
	DEF_ARRAY_OP(T)

#define ARRAY_get(T, a, idx)    ARRAY_##T##_get(a, idx)
#define ARRAY_set(T, a, idx, v) ARRAY_##T##_set(a, idx, v)
#define ARRAY_add(T, a, v)      ARRAY_##T##_add(a, v)
#define ARRAY_clear(T, a)     ARRAY_##T##_clear(a)
#define ARRAY_dispose(T, a)     ARRAY_##T##_dispose(a)
#define ARRAY_init(T, a)        ARRAY_init_##T (a)
#define ARRAYp_n(a, n) ((a)->list[n])
#define ARRAY_n(a, n)  ((a).list[n])
#define ARRAYp_size(a) ((a)->size)
#define ARRAY_size(a)  ((a).size)
#define ARRAY_init_1(T, a, e1) do {\
	ARRAY_init(T, a);\
	ARRAY_add(T, a, e1);\
} while(0)

#define FOR_EACH_ARRAY_(a, i)  for(i=0; i < ARRAY_size(a); ++i)
#define FOR_EACH_ARRAY(a, x, i) \
		for(i=0, x = ARRAY_n(a, i); i < ARRAY_size(a); x = ARRAY_n(a,(++i)))

	/* struct gc */
#define GCDATA(ctx) ((HeapManager*)((ctx)->memlocal->freeObjectList))

	struct SubHeap;
//	struct Segment;
	union  AllocationBlock;
	struct HeapManager;

	typedef void BlkPtr;
	typedef uintptr_t bitmap_t;
	typedef struct SubHeap SubHeap;
	typedef struct Segment Segment;
	typedef struct HeapManager HeapManager;
	typedef union  AllocationBlock AllocationBlock;
	typedef HeapManager const GCInfo;

typedef struct BitPtr {
	uintptr_t idx;
	uintptr_t mask;
} BitPtr;

typedef struct AllocationPointer {
	BitPtr bitptrs[ SEGMENT_LEVEL];
	Segment *seg;
	BlkPtr *blkptr;
} AllocationPointer;

struct SubHeap {
	AllocationPointer p;
	int heap_klass;
	int isFull;
	Segment *freelist;
	Segment **seglist;
	int seglist_size;
	int seglist_max;
};

typedef Segment* SegmentPtr;
typedef void* VoidPtr;
DEF_ARRAY_T_OP(SegmentPtr);
DEF_ARRAY_T_OP(size_t);
DEF_ARRAY_T_OP(VoidPtr);

struct HeapManager {
	SubHeap heaps[SUBHEAP_KLASS_MAX+1];
	Segment *segmentList;
	bool isFull;
	ARRAY(SegmentPtr) segment_pool_a;
	ARRAY(size_t)     segment_size_a;
	ARRAY(VoidPtr)    managed_heap_a;
	ARRAY(VoidPtr)    managed_heap_end_a;
	ARRAY(size_t)     heap_size_a;
};

struct Segment {
	bitmap_t *base[ SEGMENT_LEVEL];
	struct Segment *next;
	int live_count;
	int heap_klass;
	const AllocationBlock *blk;
	bitmap_t *bitmap;
	bitmap_t *sbase[SEGMENT_LEVEL];
	bitmap_t *snapshot;
	int tenure_live_count;
	ARRAY(VoidPtr) remset;
#if GCDEBUG
	void  *managed_heap;
	void  *managed_heap_end;
#endif
};

typedef struct BlockHeader {
	Segment *seg;
	int klass;
} BlockHeader;

typedef struct gc_stat {
	size_t total_object;
	size_t object_count[SUBHEAP_KLASS_MAX+1];
	size_t gc_count;
	size_t marked[SUBHEAP_KLASS_MAX+1];
	size_t collected[SUBHEAP_KLASS_MAX+1];
	size_t markingTime;
	size_t sweepingTime;
	size_t current_request_size;
	AllocationBlock *managed_heap;
	AllocationBlock *managed_heap_end;
	FILE *fp;
} bmgc_stat;

#ifdef GCSTAT
static bmgc_stat global_gc_stat = {};
#endif

#define DEF_BM(size)  struct bm##size { uintptr_t bm[size]; }
DEF_BM(  1);DEF_BM(  2);DEF_BM(  4);
DEF_BM(  8);DEF_BM( 16);DEF_BM( 32);
DEF_BM( 64);DEF_BM(128);DEF_BM(256);
#define _BM_(size, name)  struct bm##size name
#define DEF_BITMAP_L2_S1(l0, l1, l2, s) _BM_(l0, m0);_BM_(s, S);_BM_(l1, m1);_BM_(l2, m2);
#define DEF_BITMAP_L1_S1(l0, l1, l2, s) _BM_(l0, m0);_BM_(s, S);_BM_(l1, m1);
#define DEF_BITMAP_L0_S1(l0, l1, l2, s) _BM_(l0, m0);_BM_(s, S);
#define DEF_BITMAP_L0_S0(l0, l1, l2, s) _BM_(l0, m0);

static const size_t SegmentBitMapCount[] = {
	0,0,0,0,0,0,
	32, 16, 8, 4, 2, 1, 1
};

// struct BM6 {
//	struct bm32 m0;
//	struct bm1  S;
//	struct bm1  m1;
//	struct bm0  m2;
// }

// struct BM6 {
//	struct bm32 m0;
//	struct bm1  S;
//	struct bm1  m1;
//	struct bm0  m2;
// }

//struct BM3  { DEF_BITMAP_L2_S1(256, 4, 1, 1/*sentinel*/); };
//struct BM4  { DEF_BITMAP_L2_S1(128, 2, 1, 1/*sentinel*/); };
//struct BM5  { DEF_BITMAP_L1_S1( 64, 1, 0, 1/*sentinel*/); };
struct BM6  { DEF_BITMAP_L1_S1( 32, 1, 0, 1/*sentinel*/); };
struct BM7  { DEF_BITMAP_L1_S1( 16, 1, 0, 1/*sentinel*/); };
struct BM8  { DEF_BITMAP_L1_S1(  8, 1, 0, 1/*sentinel*/); };
struct BM9  { DEF_BITMAP_L1_S1(  4, 1, 0, 1/*sentinel*/); };
struct BM10 { DEF_BITMAP_L1_S1(  2, 1, 0, 1/*sentinel*/); };
struct BM11 { DEF_BITMAP_L0_S1(  1, 0, 0, 1/*sentinel*/); };
struct BM12 { DEF_BITMAP_L0_S0(  1, 0, 0, 0/*sentinel*/); };

#define _BLOCK_(size)  struct blk##size{uint8_t m[size];} \
	b##size [SEGMENT_SIZE/(sizeof(struct blk##size))]
union AllocationBlock {
	_BLOCK_(8   );_BLOCK_(16  );_BLOCK_(32  );_BLOCK_(64  );
	_BLOCK_(128 );_BLOCK_(256 );_BLOCK_(512 );_BLOCK_(1024);
	_BLOCK_(2048);_BLOCK_(4096);
};

#define SEGMENT_BLOCK_COUNT(n) ((n >= SUBHEAP_KLASS_MIN)?(SEGMENT_SIZE / KlassBlockSize(n ) - 1):0)
static const size_t SegmentBlockCount[] = {
	0, 0, 0,
	SEGMENT_BLOCK_COUNT(3 ), SEGMENT_BLOCK_COUNT(4 ),
	SEGMENT_BLOCK_COUNT(5 ), SEGMENT_BLOCK_COUNT(6 ),
	SEGMENT_BLOCK_COUNT(7 ), SEGMENT_BLOCK_COUNT(8 ),
	SEGMENT_BLOCK_COUNT(9 ), SEGMENT_BLOCK_COUNT(10),
	SEGMENT_BLOCK_COUNT(11), SEGMENT_BLOCK_COUNT(12),
};

//#define BM_SENTINEL_L2_3  (BITMAP_FULL << (2))
//#define BM_SENTINEL_L2_4  (BITMAP_FULL << (1))
//#define BM_SENTINEL_L2_5  (BITMAP_FULL)
#define BM_SENTINEL_L2_6  (BITMAP_FULL)
#define BM_SENTINEL_L2_7  (BITMAP_FULL)
#define BM_SENTINEL_L2_8  (BITMAP_FULL)
#define BM_SENTINEL_L2_9  (BITMAP_FULL)
#define BM_SENTINEL_L2_10 (BITMAP_FULL)
#define BM_SENTINEL_L2_11 (BITMAP_FULL)
#define BM_SENTINEL_L2_12 (BITMAP_FULL)

//#define BM_SENTINEL_L1_3  (BITMAP_FULL << (63))
//#define BM_SENTINEL_L1_4  (BITMAP_FULL << (63))
//#define BM_SENTINEL_L1_5  (BITMAP_FULL << (63))
#define BM_SENTINEL_L1_6  (BITMAP_FULL << (32))
#define BM_SENTINEL_L1_7  (BITMAP_FULL << (16))
#define BM_SENTINEL_L1_8  (BITMAP_FULL << (8))
#define BM_SENTINEL_L1_9  (BITMAP_FULL << (2))
#define BM_SENTINEL_L1_10 (BITMAP_FULL << (1))
#define BM_SENTINEL_L1_11 (BITMAP_FULL)
#define BM_SENTINEL_L1_12 (BITMAP_FULL)

//#define BM_SENTINEL_L0_3  (BITMAP_FULL)
//#define BM_SENTINEL_L0_4  (BITMAP_FULL)
//#define BM_SENTINEL_L0_5  (BITMAP_FULL)
#define BM_SENTINEL_L0_6  (BITMAP_FULL)
#define BM_SENTINEL_L0_7  (BITMAP_FULL)
#define BM_SENTINEL_L0_8  (BITMAP_FULL)
#define BM_SENTINEL_L0_9  (BITMAP_FULL)
#define BM_SENTINEL_L0_10 (BITMAP_FULL)
#define BM_SENTINEL_L0_11 (BITMAP_FULL)
#define BM_SENTINEL_L0_12 (BITMAP_FULL << (32))

static bitmap_t bitmap_empty = BITMAP_FULL;
static bitmap_t *bitmap_dummy = &bitmap_empty;
static Segment segment_dummy = {};

#define DEF_BM_OP0(N, L0, L1, L2)\
	static inline void BITPTRS_SET_BASE##N (bitmap_t **base, bitmap_t *bitmap)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	base[0] = (bitmap_t*)(&bm->m0.bm);\
	base[1] = (bitmap_t*) bitmap_dummy;\
	base[2] = (bitmap_t*) bitmap_dummy;\
}\
static inline void BITMAP_SET_LIMIT##N (bitmap_t *const bitmap)\
{\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
}\
static inline void BITMAP_SET_LIMIT_AND_CPY_BM##N (bitmap_t *const bitmap, bitmap_t *const snapshot)\
{\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
}\

#define DEF_BM_OP1(N, L0, L1, L2)\
	static inline void BITPTRS_SET_BASE##N (bitmap_t **base, bitmap_t *bitmap)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	base[0] = (bitmap_t*)(&bm->m0.bm);\
	base[1] = (bitmap_t*)(&bm->m1.bm);\
	base[2] = (bitmap_t*)bitmap_dummy;\
}\
static inline void BITMAP_SET_LIMIT##N (bitmap_t *const bitmap)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
	bm->m1.bm[L1-1] = BM_SENTINEL_L1_##N;\
}\
static inline void BITMAP_SET_LIMIT_AND_CPY_BM##N (bitmap_t *const bitmap, bitmap_t *const snapshot)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	struct BM##N *ss = (struct BM##N *)snapshot;\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
	bm->m1.bm[L1-1] = BM_SENTINEL_L1_##N | ss->m1.bm[L1-1];\
}\

#define DEF_BM_OP2(N, L0, L1, L2)\
	static inline void BITPTRS_SET_BASE##N (bitmap_t **base, bitmap_t *bitmap)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	base[0] = (bitmap_t*)(&bm->m0.bm);\
	base[1] = (bitmap_t*)(&bm->m1.bm);\
	base[2] = (bitmap_t*)(&bm->m2.bm);\
}\
static inline void BITMAP_SET_LIMIT##N (bitmap_t *const bitmap)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
	bm->m1.bm[L1-1] = BM_SENTINEL_L1_##N;\
	bm->m2.bm[L2-1] = BM_SENTINEL_L2_##N;\
}\
static inline void BITMAP_SET_LIMIT_AND_CPY_BM##N (bitmap_t *const bitmap, bitmap_t *const snapshot)\
{\
	struct BM##N *bm = (struct BM##N *)bitmap;\
	struct BM##N *ss = (struct BM##N *)snapshot;\
	bitmap[L0-1] = BM_SENTINEL_L0_##N;\
	bm->m1.bm[L1-1] = BM_SENTINEL_L1_##N | ss->m1.bm[L1-1];\
	bm->m2.bm[L2-1] = BM_SENTINEL_L2_##N | ss->m2.bm[L2-1];\
}\

//DEF_BM_OP2( 3, 256+1/*sentinel*/, 4, 1);
//DEF_BM_OP2( 4, 128+1/*sentinel*/, 2, 1);
//DEF_BM_OP1( 5,  64+1/*sentinel*/, 1, 0);
DEF_BM_OP1( 6,  32+1/*sentinel*/, 1, 0);
DEF_BM_OP1( 7,  16+1/*sentinel*/, 1, 0);
DEF_BM_OP1( 8,   8+1/*sentinel*/, 1, 0);
DEF_BM_OP1( 9,   4+1/*sentinel*/, 1, 0);
DEF_BM_OP1(10,   2+1/*sentinel*/, 1, 0);
DEF_BM_OP0(11,   1+1/*sentinel*/, 0, 0);
DEF_BM_OP0(12,   1, 0, 0);

#define COND(C, T, F) ((C) ? T : F)
#define _MASK_(N, L0, L1, L2) {COND(L0 > 0, 1, 0), COND(L1 > 0, 1, 0), COND(L2 > 0, 1, 0)}
static const size_t BITMAP_DEFAULT_MASK[][SEGMENT_LEVEL] = {
	_MASK_( 3, 256, 4, 1),
	_MASK_( 4, 128, 2, 1),
	_MASK_( 5,  64, 1, 0),
	_MASK_( 6,  32, 1, 0),
	_MASK_( 7,  16, 1, 0),
	_MASK_( 8,   8, 1, 0),
	_MASK_( 9,   4, 1, 0),
	_MASK_(10,   2, 1, 0),
	_MASK_(11,   1, 0, 0),
	_MASK_(12,   1, 0, 0),
};

typedef void (*fBITPTRS_SET_BASE)(bitmap_t *base[SEGMENT_LEVEL], bitmap_t *bm);
static void BITPTRS_SET_BASE_(bitmap_t *base[SEGMENT_LEVEL], bitmap_t *bm) {}
static const fBITPTRS_SET_BASE BITPTRS_SET_BASE[] = {
	BITPTRS_SET_BASE_, BITPTRS_SET_BASE_, BITPTRS_SET_BASE_,  BITPTRS_SET_BASE_,
	BITPTRS_SET_BASE_, BITPTRS_SET_BASE_, BITPTRS_SET_BASE6,  BITPTRS_SET_BASE7,
	BITPTRS_SET_BASE8, BITPTRS_SET_BASE9, BITPTRS_SET_BASE10, BITPTRS_SET_BASE11,
	BITPTRS_SET_BASE12
};

typedef void (*fBITMAP_SET_LIMIT)(bitmap_t *const bm);
static void BITMAP_SET_LIMIT_(bitmap_t *const bm) { (void)bm; }
static const fBITMAP_SET_LIMIT BITMAP_SET_LIMIT__[] = {
	BITMAP_SET_LIMIT_, BITMAP_SET_LIMIT_, BITMAP_SET_LIMIT_,  BITMAP_SET_LIMIT_,
	BITMAP_SET_LIMIT_, BITMAP_SET_LIMIT_, BITMAP_SET_LIMIT6,  BITMAP_SET_LIMIT7,
	BITMAP_SET_LIMIT8, BITMAP_SET_LIMIT9, BITMAP_SET_LIMIT10, BITMAP_SET_LIMIT11,
	BITMAP_SET_LIMIT12
};

static inline void BITMAP_SET_LIMIT(bitmap_t *const bitmap, size_t klass)
{
	BITMAP_SET_LIMIT__[klass](bitmap);
	BM_SET(bitmap[0], 1);
}

typedef void (*fBITMAP_SET_LIMIT_AND_CPY_BM)(bitmap_t *const bm, bitmap_t *const ss);
static void BITMAP_SET_LIMIT_AND_CPY_BM_(bitmap_t *const bm, bitmap_t *const ss) { (void)bm; }
static const fBITMAP_SET_LIMIT_AND_CPY_BM BITMAP_SET_LIMIT_AND_CPY_BM__[] = {
	BITMAP_SET_LIMIT_AND_CPY_BM_, BITMAP_SET_LIMIT_AND_CPY_BM_, BITMAP_SET_LIMIT_AND_CPY_BM_,  
	BITMAP_SET_LIMIT_AND_CPY_BM_, BITMAP_SET_LIMIT_AND_CPY_BM_, BITMAP_SET_LIMIT_AND_CPY_BM_, 
	BITMAP_SET_LIMIT_AND_CPY_BM6, BITMAP_SET_LIMIT_AND_CPY_BM7, BITMAP_SET_LIMIT_AND_CPY_BM8, 
	BITMAP_SET_LIMIT_AND_CPY_BM9, BITMAP_SET_LIMIT_AND_CPY_BM10, BITMAP_SET_LIMIT_AND_CPY_BM11,
	BITMAP_SET_LIMIT_AND_CPY_BM12
};

static inline void BITMAP_SET_LIMIT_AND_CPY_BM(bitmap_t *const bitmap, bitmap_t *const snapshot, size_t klass)
{
	BITMAP_SET_LIMIT_AND_CPY_BM__[klass](bitmap, snapshot);
	BM_SET(bitmap[0], 1);
	BM_SET(snapshot[0], 1);
}
static inline void BITPTRS_INIT(BitPtr bitptrs[SEGMENT_LEVEL], Segment *seg, size_t klass)
{
	size_t i;
	BITPTRS_SET_BASE[klass](seg->base, seg->bitmap);
	for (i = 0; i < SEGMENT_LEVEL; ++i) {
		bitptrs[i].idx = 0;
		bitptrs[i].mask = BITMAP_DEFAULT_MASK[klass][i];
	}
}

static inline void SNAPSHOT_INIT(Segment *seg, size_t klass)
{
	BITPTRS_SET_BASE[klass](seg->sbase, seg->snapshot);
}


static const size_t BM_SIZE[] = {
	0, 0, 0, 0, 0, 0,
	sizeof(struct BM6),
	sizeof(struct BM7),  sizeof(struct BM8),
	sizeof(struct BM9),  sizeof(struct BM10),
	sizeof(struct BM11), sizeof(struct BM12),
};

static const size_t BLK_SIZE[] = {
	0, 0, 0, 0, 0, 0,
	SEGMENT_SIZE / sizeof(struct blk8), SEGMENT_SIZE / sizeof(struct blk16),
	SEGMENT_SIZE / sizeof(struct blk32), SEGMENT_SIZE / sizeof(struct blk64),
	SEGMENT_SIZE / sizeof(struct blk128), SEGMENT_SIZE / sizeof(struct blk256),
	SEGMENT_SIZE / sizeof(struct blk512), SEGMENT_SIZE / sizeof(struct blk1024),
	SEGMENT_SIZE / sizeof(struct blk2048), SEGMENT_SIZE / sizeof(struct blk4096),
};

#define AllocBitMap(n)      ((bitmap_t*)(do_malloc(BM_SIZE[n])))
#define DeleteBitMap(bm, n) ((do_free((void*)bm, BM_SIZE[n])))
#define ClearBitMap(bm, n)  (do_bzero((void*)bm, BM_SIZE[n]))

#if GCDEBUG
#define gc_info(fmt, ...)  fprintf(stderr, "(%s:%d) " fmt "\n" , __func__, __LINE__,  ## __VA_ARGS__)
#define gc_debug(fmt, ...) fprintf(stderr, "(%s:%d) " fmt "\n" , __func__, __LINE__, ## __VA_ARGS__)
#define gc_stat(fmt, ...)  gc_debug(fmt, ##__VA_ARGS__);\
	fprintf(global_gc_stat.fp, "(%s:%d) " fmt "\n" , __func__, __LINE__,  ## __VA_ARGS__)
#else
#define gc_info(fmt, ...)
#define gc_debug(fmt, ...)
#define gc_stat(fmt, ...)  fprintf(global_gc_stat.fp, "(%s:%d) " fmt "\n" , __func__, __LINE__,  ## __VA_ARGS__)
#endif
/* ------------------------------------------------------------------------ */

#define K_OPAGE(o)    ((objpage_t*)((((kuintptr_t)(o)) / K_PAGESIZE) * K_PAGESIZE))
#define K_SHIFTPTR(p, size)   ((char*)p + size)
#define K_MEMSIZE(p, p2)      (((char*)p) - ((char*)p2))

#define K_PAGEOBJECTSIZE ((K_PAGESIZE / sizeof(kObjectUnused)) - 1)

#define K_ARENATBL_INITSIZE     32
#define K_NBITMAP 2

#ifdef K_USING_RCGC
#define K_ARENASIZE             (sizeof(kObjectUnused) * K_PAGESIZE)
#else
#define K_ARENASIZE             ((sizeof(kObjectUnused) * K_PAGESIZE) * 16) /*4MB*/
#endif

#define XMEM_PAGESIZE (1024 * 64)

#define KNH_MEMLOCK(ctx)   knh_mutex_lock(ctx->memshare->memlock)
#define KNH_MEMUNLOCK(ctx) knh_mutex_unlock(ctx->memshare->memlock)

typedef struct xmemlist_t {
	size_t size;
	struct xmemlist_t *next;
} xmemlist_t;

typedef struct kObjectUnused {
	kObjectHeader h;
	struct kObjectUnused *ref;
	void *ref2_unused;
	void *ref3_unused;
	struct kObjectUnused *ref4_tail;
} kObjectUnused ;

typedef struct objpageH_t {
	kObjectHeader h;
	kuintptr_t *bitmap;
	kuintptr_t *tenure;
	kcontext_t *ctx;
	void *unused;
} objpageH_t;

typedef struct objpage_t {
	objpageH_t h;
	kObjectUnused  slots[K_PAGEOBJECTSIZE];
} objpage_t;

typedef struct objpageTBL_t {
	objpage_t      *head;
	objpage_t      *bottom;
	size_t          arenasize;
	kuintptr_t     *bitmap;
	kuintptr_t      bitmapsize;
	kuintptr_t     *tenure;
} objpageTBL_t ;

typedef struct mempage_t {
	union {
		struct mempage_t *ref;
		char body[K_FASTMALLOC_SIZE];
	};
} mempage_t;

typedef struct mempageTBL_t {
	mempage_t *head;
	mempage_t *bottom;
} mempageTBL_t ;

typedef struct kmemshare_t {
	objpageTBL_t     *ObjectArenaTBL;
	size_t            sizeObjectArenaTBL;
	size_t            capacityObjectArenaTBL;
	//	struct kObject           *freeObjectList;
	//	struct kObject           *freeObjectTail;
	//
	//	// reserved
	//	objpageTBL_t     *YoungArenaTBL;
	//	size_t                    sizeYoungArenaTBL;
	//	size_t                    capacityYoungArenaTBL;
	//	struct kObject           *freeYoungList;
	//	struct kObject           *freeYoungTail;

	mempageTBL_t             *MemoryArenaTBL;
	size_t                    sizeMemoryArenaTBL;
	size_t                    capacityMemoryArenaTBL;
	//	struct mempage_t         *freeMemoryList;
	//	struct mempage_t         *freeMemoryTail;

	char                     *xmem_root;    // xmalloc
	char                     *xmem_top;
	char                     *xmem_freelist;

	kmutex_t                 *memlock;
} kmemshare_t ;

typedef struct kmemlocal_t {
	struct kObjectUnused        *freeObjectList;
	struct kObjectUnused        *freeObjectTail;
	size_t                       freeObjectListSize;
	mempage_t                   *freeMemoryList;
	mempage_t                   *freeMemoryTail;

	struct kObject             **refs;
	size_t                       ref_size;
	struct kObject             **ref_buf;        // allocated body
	size_t                       ref_capacity;

	struct kObject             **queue;
	size_t                       queue_capacity;
	size_t                       queue_log2;
} kmemlocal_t;


/* ------------------------------------------------------------------------ */
/* prototype declaration */
static kObject *bm_malloc_internal(CTX, HeapManager *mng, size_t n);
void *bm_malloc(CTX ctx, size_t n);
void *bm_realloc(CTX ctx, void *ptr, size_t os, size_t ns);
void bm_free(CTX ctx, void *ptr, size_t n);
static void BMGC_dump(GCInfo *info);
static void bitmapMarkingGC(CTX ctx, HeapManager *mng, int isTenure);
#if GCDEBUG
static void dumpBM(uintptr_t bm) CC_UNUSED;
#endif
static void HeapManager_init(CTX ctx, HeapManager *mng, size_t heap_size);
static void HeapManager_delete(CTX ctx, HeapManager *mng);
static void HeapManager_final_free(CTX ctx, HeapManager *mng);
static inline void bmgc_Object_free(CTX ctx, kObject *o);
static void xmem_freeall(CTX ctx);
static bool findNextFreeBlock(AllocationPointer *p);
static void BMGC_exit(CTX ctx, HeapManager *mng);
/* ------------------------------------------------------------------------ */
/* bmgc */

void *knh_malloc(CTX ctx, size_t size)
{
	void *block = malloc(size);
	MEMLOG(ctx, "malloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	STAT_mem(ctx, size);
	return block;
}

void knh_free(CTX ctx, void *block, size_t size)
{
	MEMLOG(ctx, "free", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	free(block);
	STAT_dmem(ctx, size);
}

void *knh_valloc(CTX ctx, size_t size)
{
#if defined(HAVE_POSIX_MEMALIGN)
	void *block = NULL;
	int ret = posix_memalign(&block, K_PAGESIZE, size);
	MEMLOG(ctx, "valloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if(ret != 0) {
		THROW_OutOfMemory(ctx, size);
	}
	STAT_mem(ctx, size);
	return block;
#elif defined(HAVE_MEMALIGN)
	void *block = memalign(K_PAGESIZE, size);
	MEMLOG(ctx, "valloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	return block;
#elif defined(K_USING_WINDOWS_)
	void *block = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	MEMLOG(ctx, "valloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	return block;
#else
	void *block = malloc(size + K_PAGESIZE);
	MEMLOG(ctx, "valloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	if((kuintptr_t)block % K_PAGESIZE != 0) {
		char *t2 = (char*)((((kuintptr_t)block / K_PAGESIZE) + 1) * K_PAGESIZE);
		void **p = (void**)(t2 + size);
		DBG_ASSERT((char*)p < ((char*)block) + size + K_PAGESIZE);
		p[0] = block;
		block = (void*)t2;
		DBG_ASSERT((kuintptr_t)block % K_PAGESIZE == 0);
	}
	else {
		void **p = (void**)((char*)block + size);
		p[0] = block;
	}
	STAT_mem(ctx, size + K_PAGESIZE);
	return block;
#endif
}

void knh_vfree(CTX ctx, void *block, size_t size)
{
	MEMLOG(ctx, "vfree", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
#if defined(HAVE_POSIX_MEMALIGN) || defined(HAVE_MEMALIGN)
	free(block);
	STAT_dmem(ctx, size);
#elif defined(K_USING_WINDOWS_)
	VirtualFree(block, 0, MEM_RELEASE);
	STAT_dmem(ctx, size);
#else
	void **p = (void**)((char*)block + size);
	block = p[0];
	free(block);
	STAT_dmem(ctx, size + K_PAGESIZE);
#endif
}

#if defined(K_USING_TRACEMALLOC)
void *TRACE_malloc(CTX ctx, size_t size K_TRACEARGV)
{
	DBG_ASSERT(size != 0);
	size_t *block = (size_t*)malloc(size + sizeof(size_t));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	STAT_mem(ctx, size);
	block[0] = size;
	return (void*)(block + 1);
}

void TRACE_free(CTX ctx, void *p, size_t size K_TRACEARGV)
{
	DBG_ASSERT(size != 0);
	size_t *block = ((size_t*)p) - 1;
	if(unlikely(size != block[0])) {
		fprintf(stderr, "%s:%d(%s) ptr = %p, block.size = %d, free.size=%d\n",
				_file, _line, _func, p, (int)block[0], (int)size);
		KNH_ABORT();
	}
	knh_bzero(block, size + sizeof(size_t));
	free(block);
	STAT_dmem(ctx, size);
}

void *TRACE_realloc(CTX ctx, void *p, size_t os, size_t ns, size_t wsize K_TRACEARGV)
{
	size_t oldsize = os * wsize, newsize = ns * wsize;
	size_t *block = (size_t*)malloc(newsize + sizeof(size_t));
	knh_bzero(block, newsize + sizeof(size_t));
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, newsize);
	}
	STAT_mem(ctx, newsize);
	block[0] = newsize;
	if(p != NULL) {
		DBG_ASSERT(os > 0);
		knh_memcpy(block+1, p, oldsize);
	}
	else {
		DBG_ASSERT(os == 0);
	}
	void *newp = (void*)(block+1);
	if(p != NULL) {
		block = ((size_t*)p) - 1;
		if(unlikely(oldsize != block[0])) {
			fprintf(stderr, "%s:%d(%s) ptr = %p, block.size = %d, free.size=%d\n",
					_file, _line, _func, p, (int)block[0], (int)oldsize);
			KNH_ABORT();
		}
		knh_bzero(block, oldsize + sizeof(size_t));
		free(block);
		STAT_dmem(ctx, oldsize);
	}
	return newp;
}

#endif/*TRACE_MALLOC*/

static void initArena(CTX ctx, kmemshare_t *memshare)
{
	memshare->ObjectArenaTBL = (objpageTBL_t*)KNH_MALLOC(ctx, K_ARENATBL_INITSIZE * sizeof(objpageTBL_t));
	knh_bzero(memshare->ObjectArenaTBL, K_ARENATBL_INITSIZE * sizeof(objpageTBL_t));
	memshare->sizeObjectArenaTBL = 0;
	memshare->capacityObjectArenaTBL = K_ARENATBL_INITSIZE;

	memshare->MemoryArenaTBL = (mempageTBL_t*)KNH_MALLOC(ctx, K_ARENATBL_INITSIZE * sizeof(mempageTBL_t));
	knh_bzero(memshare->MemoryArenaTBL, K_ARENATBL_INITSIZE * sizeof(mempageTBL_t));
	memshare->sizeMemoryArenaTBL = 0;
	memshare->capacityMemoryArenaTBL = K_ARENATBL_INITSIZE;
}

static void freeArena(CTX ctx, kmemshare_t *memshare)
{
	size_t i;
	DBG_ASSERT(memshare->ObjectArenaTBL != NULL);
	for(i = 0; i < memshare->sizeObjectArenaTBL; i++) {
		objpageTBL_t *oat = memshare->ObjectArenaTBL + i;
		DBG_ASSERT(K_MEMSIZE(oat->bottom, oat->head) == oat->arenasize);
		KNH_FREE(ctx, oat->bitmap, oat->bitmapsize * K_NBITMAP);
		KNH_VFREE(ctx, oat->head, oat->arenasize);
	}
	KNH_FREE(ctx, memshare->ObjectArenaTBL, memshare->capacityObjectArenaTBL * sizeof(objpageTBL_t));
	memshare->ObjectArenaTBL = NULL;
	for(i = 0; i < memshare->sizeMemoryArenaTBL; i++) {
		mempageTBL_t *at = memshare->MemoryArenaTBL + i;
		KNH_FREE(ctx, at->head, K_MEMSIZE(at->bottom, at->head));
	}
	KNH_FREE(ctx, memshare->MemoryArenaTBL, memshare->capacityMemoryArenaTBL * sizeof(mempageTBL_t));
	memshare->MemoryArenaTBL = NULL;
}

#ifdef K_USING_DEBUG
static void ObjectArenaTBL_checkSize(objpageTBL_t *oat, size_t arenasize, size_t object_count)
{
	size_t cnt2=0;
	kObjectUnused *p = oat->head->slots;
	while(p->ref != NULL) {
		objpage_t *opage = K_OPAGE(p);
		DBG_ASSERT(oat->bitmap <= opage->h.bitmap && opage->h.bitmap < oat->bitmap + ((arenasize/sizeof(kObjectUnused))/sizeof(kuintptr_t)));
		cnt2++;
		p = (kObjectUnused*) p->ref;
	}
	DBG_ASSERT(cnt2 + 1 == object_count * K_PAGEOBJECTSIZE);
}
#endif

//static void knh_fastmemset(void *p, size_t n, kintptr_t M)
//{
//	size_t i, size = n / sizeof(kintptr_t);
//	kintptr_t *np = (kintptr_t*)p;
//	for(i = 0; i < size; i+=8) {
//		np[0] = M; np[1] = M; np[2] = M; np[3] = M;
//		np[4] = M; np[5] = M; np[6] = M; np[7] = M;
//		np += 8;
//	}
//}

void knh_initFirstObjectArena(CTX ctx);

void kmemshare_init(CTX ctx)
{
	WCTX(ctx)->memshare = (kmemshare_t*)KNH_MALLOC(ctx, sizeof(kmemshare_t));
	knh_bzero(ctx->memshare, sizeof(kmemshare_t));
	ctx->memshare->memlock = knh_mutex_malloc(ctx);
	initArena(ctx, ctx->memshare);
	kmemlocal_init(ctx);
	{
		knh_initFirstObjectArena(ctx);
	}
}

void kmemshare_free(CTX ctx)
{
	xmem_freeall(ctx);
	BMGC_exit(ctx, GCDATA(ctx));
	((kcontext_t*)ctx)->memlocal->freeObjectList = NULL;
	freeArena(ctx, ctx->memshare);
	knh_mutex_free(ctx, ctx->memshare->memlock);
	KNH_FREE(ctx, ctx->memshare, sizeof(kmemshare_t));
	WCTX(ctx)->memshare = NULL;
}

void kmemlocal_init(CTX ctx)
{
	WCTX(ctx)->memlocal = KNH_MALLOC(ctx, sizeof(kmemlocal_t));
	knh_bzero(ctx->memlocal, sizeof(kmemlocal_t));
}

void kmemlocal_free(CTX ctx)
{
	if(ctx->memlocal != NULL) {
		if(ctx->memlocal->queue_capacity > 0) {
			KNH_FREE(ctx, ctx->memlocal->queue,  (ctx->memlocal->queue_capacity + 1) * sizeof(kObject*));
			ctx->memlocal->queue = NULL;
			ctx->memlocal->queue_capacity = 0;
		}
		if(ctx->memlocal->ref_capacity > 0) {
			KNH_FREE(ctx, ctx->memlocal->ref_buf, ctx->memlocal->ref_capacity * sizeof(kObject*));
			ctx->memlocal->ref_buf = NULL;
			ctx->memlocal->refs = NULL;
			ctx->memlocal->ref_capacity = 0;
		}
		KNH_FREE(ctx, ctx->memlocal, sizeof(kmemlocal_t));
		WCTX(ctx)->memlocal = NULL;
	}
}

// xmalloc

static char* new_xmemarena(CTX ctx, size_t size)
{
	if(size < XMEM_PAGESIZE) size = XMEM_PAGESIZE;
	xmemlist_t *ptr = (xmemlist_t*)KNH_VALLOC(ctx, size);
	int mret;
#ifdef K_USING_POSIX_
	mret = mprotect(ptr, size, PROT_READ | PROT_WRITE | PROT_EXEC);
#elif K_USING_WINDOWS_
	/* TODO(@imasahiro) need debug 
	 * http://msdn.microsoft.com/ja-jp/library/cc430214.aspx
	 */
	DWORD old_protect;
	if (VirtualProtect(ptr, size, PAGE_EXECUTE_READWRITE, &old_protect) != 0) {
		mret = -1;
	}
#else
	mret = -1;
#endif
	if(mret == -1) {
		KNH_DIE("mprotect is not working.");
	}
	ptr->size = size;
	ptr->next = NULL;
	return (char*)ptr;
}

#define XMEM_BSIZE   sizeof(void*)

void *knh_xmalloc(CTX ctx, size_t size)
{
	size_t freesize = ctx->memshare->xmem_freelist - ctx->memshare->xmem_top;
	size_t asize = (size % XMEM_BSIZE == 0) ? size : ((size / XMEM_BSIZE) + 1) * XMEM_BSIZE;
	if(!(freesize > asize + sizeof(xmemlist_t))) {
		char *p = new_xmemarena(ctx, asize);
		if(ctx->memshare->xmem_root == NULL) {
			ctx->memshare->xmem_root = p;
		}
		else {
			xmemlist_t *xmeminfo = (xmemlist_t*)ctx->memshare->xmem_top;
			xmeminfo->next = (xmemlist_t*)p;
		}
		ctx->memshare->xmem_top = p;
		ctx->memshare->xmem_freelist = p + sizeof(xmemlist_t);
	}
	void *p = (void*)ctx->memshare->xmem_freelist;
	ctx->memshare->xmem_freelist += asize;
	return p;
}

static void xmem_freeall(CTX ctx)
{
	xmemlist_t *xmeminfo = (xmemlist_t*)ctx->memshare->xmem_root;
	while(xmeminfo != NULL) {
		void *p     = xmeminfo;
		size_t size = xmeminfo->size;
		xmeminfo    = xmeminfo->next;
		KNH_VFREE(ctx, p, size);
	}
}

/* ------------------------------------------------------------------------ */
/* [fastmalloc] */

static mempage_t *new_FastMemoryList(CTX ctx)
{
	KNH_MEMLOCK(ctx);
	kmemshare_t *memshare = ctx->memshare;
	size_t pageindex = memshare->sizeMemoryArenaTBL;
	if(unlikely(!(pageindex < memshare->capacityMemoryArenaTBL))) {
		size_t newsize = memshare->capacityMemoryArenaTBL * 2;
		memshare->MemoryArenaTBL = (mempageTBL_t*)KNH_REALLOC(ctx, "MemoryArenaTBL", memshare->MemoryArenaTBL, memshare->capacityMemoryArenaTBL, newsize, sizeof(mempageTBL_t));
		memshare->capacityMemoryArenaTBL = newsize;
	}
	memshare->sizeMemoryArenaTBL += 1;
	KNH_MEMUNLOCK(ctx);
	{
		mempageTBL_t *at = &memshare->MemoryArenaTBL[pageindex];
		mempage_t *mslot = (mempage_t*)KNH_MALLOC(ctx, K_PAGESIZE * 8);
		knh_bzero(mslot, K_PAGESIZE * 8);
		at->head =   mslot;
		at->bottom = (mempage_t*)K_SHIFTPTR(mslot, (K_PAGESIZE * 8));
		DBG_ASSERT(ctx->memlocal->freeMemoryList == NULL);
		WCTX(ctx)->memlocal->freeMemoryList = mslot;
		for(;mslot < at->bottom; mslot++) {
			mslot->ref = (mslot + 1);
		}
		(mslot-1)->ref = NULL;
		//GC_LOG("Allocated MemoryArena id=%d region=(%p-%p)", pageindex, at->head, at->bottom);
	}
	return ctx->memlocal->freeMemoryList;
}

void *knh_fastmalloc(CTX ctx, size_t size)
{
	DBG_ASSERT(size != 0);
	if(size <= K_FASTMALLOC_SIZE) {
		mempage_t *m;
		if(ctx->memlocal->freeMemoryList == NULL) {
			WCTX(ctx)->memlocal->freeMemoryList = new_FastMemoryList(ctx);
		}
		m = ctx->memlocal->freeMemoryList;
		WCTX(ctx)->memlocal->freeMemoryList = m->ref;
		m->ref = NULL;
		MEMLOG(ctx, "fastmalloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", m), LOG_u("size", size)));
		return (void*)m;
	}
	else {
		void *block = malloc(size);
		MEMLOG(ctx, "fastmalloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
		if (unlikely(block == NULL)) {
			THROW_OutOfMemory(ctx, size);
		}
		STAT_mem(ctx, size);
		return block;
	}
}

void knh_fastfree(CTX ctx, void *block, size_t size)
{
	MEMLOG(ctx, "fastfree", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", size)));
	if(size <= K_FASTMALLOC_SIZE) {
		mempage_t *m = (mempage_t*)block;
		KNH_FREEZERO(m, K_FASTMALLOC_SIZE);
		m->ref = ctx->memlocal->freeMemoryList;
		WCTX(ctx)->memlocal->freeMemoryList = m;
	}
	else {
		KNH_FREEZERO(block, size);
		free(block);
		STAT_dmem(ctx, size);
	}
}

void* knh_fastrealloc(CTX ctx, void *block, size_t os, size_t ns, size_t wsize)
{
	size_t oldsize = os * wsize, newsize = ns * wsize;
	if(oldsize <= K_FASTMALLOC_SIZE) {
		void *newblock = knh_fastmalloc(ctx, newsize);
		if(oldsize > 0) {
			knh_memcpy(newblock, block, oldsize);
			knh_bzero((char*)newblock + oldsize, newsize - oldsize);
			knh_fastfree(ctx, block, oldsize);
		}
		else {
			DBG_ASSERT(block == NULL);
			knh_bzero(newblock, newsize);
		}
		MEMLOG(ctx, "fastrealloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", oldsize), LOG_p("ptr", newblock), LOG_u("size", newsize)));
		return newblock;
	}
	else {
		void *newblock = realloc(block, newsize);
		DBG_ASSERT(newsize > oldsize);
		if (unlikely(newblock == NULL)) {
			THROW_OutOfMemory(ctx, newsize);
		}
		STAT_mem(ctx, (newsize - oldsize));
		knh_bzero((char*)newblock + oldsize, (newsize - oldsize));
		MEMLOG(ctx, "fastrealloc", K_NOTICE, KNH_LDATA(LOG_p("ptr", block), LOG_u("size", oldsize), LOG_p("ptr", newblock), LOG_u("size", newsize)));
		return newblock;
	}
}

/* ------------------------------------------------------------------------ */
/* [Object] */

#define K_OPAGEOFFSET(o, opage)\
	(((kuintptr_t)o) / sizeof(kObjectUnused)) % (K_PAGESIZE / sizeof(kObjectUnused))

#define UINTPTR8 (sizeof(kuintptr_t) * 8)
#define INDEX2OFFSET(index_) ((index_) / UINTPTR8)
#if defined(__i386__) || defined(__power__)
#define INDEX2MASK(n) (((kuintptr_t)1) << (n % UINTPTR8))
#else
#define INDEX2MASK(n) (((kuintptr_t)1) << (n /*% UINTPTR8*/))
#endif

#define bit_test(b, offset)   (b[INDEX2OFFSET(offset)] & INDEX2MASK(offset))
#define bit_set(b, offset)    (b[INDEX2OFFSET(offset)] |= INDEX2MASK(offset))
#define bit_unset(b, offset)  (b[INDEX2OFFSET(offset)] &= ~(INDEX2MASK(offset)))

#define prefetch_bitmap(o)   prefetch(K_OPAGE(o)->h.bitmap)
#define prefetch_tenure(o)   prefetch(K_OPAGE(o)->h.tenure)

#define O_set_tenure(o) {\
	objpage_t *opage = K_OPAGE(o);\
	kuintptr_t *tenure = opage->h.tenure;\
	size_t offset = K_OPAGEOFFSET(o, opage);\
	bit_set(tenure, offset);\
}\

#define O_unset_tenure(o) {\
	objpage_t *opage = K_OPAGE(o);\
	kuintptr_t *tenure = opage->h.tenure;\
	size_t offset = K_OPAGEOFFSET(o, opage);\
	bit_unset(tenure, offset);\
}\


/* ------------------------------------------------------------------------ */
/* [cstack trace] */

#ifdef K_USING_CTRACE
#define K_TRACE_LENGTH 128
static const char* addr_to_name(void* p)
{
	Dl_info info;
	if (dladdr(p, &info) != 0) {
		return info.dli_sname;
	}
	return NULL;
}

static void dumpObject(CTX ctx, kuintptr_t* p)
{
	kObject* o = (kObject*)(*p);
	if (knh_isObject(ctx, (void*) o) && O_cTBL(o) != NULL) {
		if (O_cid(o) < K_CLASS_INITSIZE) {
			knh_putc(ctx, KNH_STDERR, '\t');
			knh_write_Object(ctx, KNH_STDERR, o, FMT_s);
		}
		else {
			knh_printf(ctx, KNH_STDERR, "\t%p %p %s\n", p, o, S_totext(O_cTBL(o)->sname));
		}
	}
}

static void knh_dump_cstack(CTX ctx)
{
	void *trace[K_TRACE_LENGTH];
	int i = 1;
	backtrace(trace, K_TRACE_LENGTH);
	void* bottom = ctx->cstack_bottom;
	void* stack = __builtin_frame_address(0);
	knh_printf(ctx, KNH_STDERR, "========== backtrace start ==========\n");
	for (; stack < bottom; stack++) {
		kuintptr_t** ptr = (kuintptr_t**) stack;
		dumpObject(ctx, (kuintptr_t*) ptr);
		if (trace[i] == *ptr) {
			knh_printf(ctx, KNH_STDERR, "TRACE: %p %s\n", trace[i], addr_to_name(trace[i]));
			i++;
		}
	}
	knh_printf(ctx, KNH_STDERR, "========== backtrace end ==========\n");
	knh_flush(ctx, KNH_STDERR);
}
#endif /* K_USING_CTRACE */

#ifdef __GNUC__
#define C_STACK_TOP(ctx) ((void**) __builtin_frame_address(0))
#else
#define C_STACK_TOP(ctx) ((void**) &ctx)
#endif
static void cstack_mark(CTX ctx FTRARG)
{
	void** stack  = C_STACK_TOP(ctx);
	void** bottom = (void**) ctx->cstack_bottom;
	for (; stack < bottom; ++stack) {
		kObject *o = (kObject*)(*stack);
		if (knh_isObject(ctx, o)) {
			KNH_ADDREF(ctx, o);
		}
	}
	KNH_SIZEREF(ctx);
}

/* ------------------------------------------------------------------------ */

#ifdef K_USING_DEBUG
#define DBG_CHECK_ONARENA(ctx, p) DBG_checkOnArena(ctx, p K_TRACEPOINT)
#else
#define DBG_CHECK_ONARENA(ctx, p)
#endif

#define FREELIST_PUSH(o) {\
	o->ref = ctx->memlocal->freeObjectList;\
	WCTX(ctx)->memlocal->freeObjectList = o;\
	/*DBG_UNOBJinc((ctx), 1);*/\
}\

#define K_OZERO(o) do {\
	o->h.cTBL = NULL;\
} while(0)


#define K_OZERO2(o) {\
	kintptr_t *p = (kintptr_t*)o;\
	p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = KINT0;\
}\

/* ------------------------------------------------------------------------ */
/* [hObject] */

#define OBJECT_INIT(o, ct) do {\
	o->fields = NULL;\
	o->h.magicflag = ct->magicflag;\
	o->h.cTBL = ct;\
	knh_Object_RCset(o, K_RCGC_INIT);\
} while(0)

kObject *new_hObject_(CTX ctx, const knh_ClassTBL_t *ct)
{
	DBG_ASSERT(ct->struct_size > 0);
	kObject *o = bm_malloc_internal(ctx, GCDATA(ctx), ct->struct_size);
	OBJECT_INIT(o, ct);
	STAT_Object(ctx, ct);
	MEMLOG(ctx, "new", K_NOTICE, KNH_LDATA(LOG_p("ptr", o), LOG_u("size", ct->cid)));
	return o;
}

kObject *new_Object_init2(CTX ctx, const knh_ClassTBL_t *ct)
{
	DBG_ASSERT(ct->struct_size > 0);
	kObject *o = bm_malloc_internal(ctx, GCDATA(ctx), ct->struct_size);
	OBJECT_INIT(o, ct);
	ct->cdef->init(ctx, RAWPTR(o));
	STAT_Object(ctx, ct);
	MEMLOG(ctx, "new", K_NOTICE, KNH_LDATA(LOG_p("ptr", o), LOG_u("size", ct->cid)));
	return o;
}

void TR_NEW(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	DBG_ASSERT(ct->struct_size > 0);
	kObject *o = bm_malloc_internal(ctx, GCDATA(ctx), ct->struct_size);
	OBJECT_INIT(o, ct);
	ct->cdef->init(ctx, RAWPTR(o));
	STAT_Object(ctx, ct);
	MEMLOG(ctx, "new", K_NOTICE, KNH_LDATA(LOG_p("ptr", o), LOG_u("size", ct->cid)));
	KNH_SETv(ctx, sfp[c].o, o);
}

#ifdef GCSTAT
static void stat_report_memory_usage(CTX ctx)
{
	/* stat instance object */
	size_t i, sizeClassTBL = ctx->share->sizeClassTBL;
	for (i = 0; i < sizeClassTBL; ++i) {
		const knh_ClassTBL_t *ct = ClassTBL(i);
		if (ct->count) {
			//fprintf(stderr, "%s\n");
			//((knh_ClassTBL_t*)ct)->count;
		}
	}
}
#endif

/* ------------------------------------------------------------------------ */
/* [ostack] */

typedef struct knh_ostack_t {
	kObject **stack;
	size_t cur;
	size_t tail;
	size_t capacity;
	size_t capacity_log2;
} knh_ostack_t;

static knh_ostack_t *ostack_init(CTX ctx, knh_ostack_t *ostack)
{
	ostack->capacity = ctx->memlocal->queue_capacity;
	ostack->stack = ctx->memlocal->queue;
	ostack->capacity_log2  = ctx->memlocal->queue_log2;
	if(ostack->capacity == 0) {
		ostack->capacity_log2 = 12;
		ostack->capacity = (1 << ostack->capacity_log2) - 1;
		DBG_ASSERT(K_PAGESIZE == 1 << 12);
		ostack->stack = (kObject**)KNH_MALLOC(ctx, sizeof(kObject*) * (ostack->capacity + 1));
	}
	ostack->cur  = 0;
	ostack->tail = 0;
	return ostack;
}

static void ostack_push(CTX ctx, knh_ostack_t *ostack, kObject *ref)
{
	size_t ntail = (ostack->tail + 1 ) & ostack->capacity;
	if(unlikely(ntail == ostack->cur)) {
		size_t capacity = 1 << ostack->capacity_log2;
		ostack->stack = (kObject**)KNH_REALLOC(ctx, "ostack", ostack->stack, capacity, capacity * 2, sizeof(kObject*));
		ostack->capacity_log2 += 1;
		ostack->capacity = (1 << ostack->capacity_log2) - 1;
		ntail = (ostack->tail + 1) & ostack->capacity;
	}
	ostack->stack[ostack->tail] = ref;
	ostack->tail = ntail;
}

static kObject *ostack_next(knh_ostack_t *ostack)
{
	kObject *ref = NULL;
	if(likely(ostack->cur != ostack->tail)) {
		ostack->tail -=1;
		ref = ostack->stack[ostack->tail];
		prefetch(ref);
	}
	return ref;
}

static void ostack_free(CTX ctx, knh_ostack_t *ostack)
{
	kcontext_t *wctx = (kcontext_t*)ctx;
	wctx->memlocal->queue_capacity = ostack->capacity;
	wctx->memlocal->queue = ostack->stack;
	wctx->memlocal->queue_log2 = ostack->capacity_log2;
}

kObject** knh_ensurerefs(CTX ctx, kObject** tail, size_t size)
{
	size_t ref_size = tail - ctx->memlocal->ref_buf;
	if(unlikely(ctx->memlocal->ref_capacity < size + ref_size)) {
		kcontext_t *wctx = (kcontext_t*)ctx;
		size_t newsize = (ctx->memlocal->ref_capacity == 0) ? 8 : ctx->memlocal->ref_capacity * 2;
		while(newsize < size + ref_size) {
			newsize *= 2;
		}
		wctx->memlocal->ref_buf = (kObject**)KNH_REALLOC(ctx, "ctx->memlocal->ref_buf", ctx->memlocal->ref_buf, ctx->memlocal->ref_capacity, newsize, sizeof(kObject*));
		wctx->memlocal->ref_capacity = newsize;
		wctx->memlocal->refs = ctx->memlocal->ref_buf;
		tail = ctx->memlocal->ref_buf + ref_size;
	}
	return tail;
}

void knh_sizerefs(CTX ctx, kObject** tail)
{
	ctx->memlocal->ref_size = (tail - ctx->memlocal->ref_buf);
}

void knh_setrefs(CTX ctx, kObject** list, size_t size)
{
	ctx->memlocal->refs = list;
	ctx->memlocal->ref_size = size;
}


#ifdef K_USING_RCGC
static void deref_ostack(CTX ctx, kObject *ref, knh_ostack_t *ostack)
{
	if (knh_Object_RCdec(ref) == 1) {
		ostack_push(ctx, ostack, ref);
	}
}

void knh_Object_RCfree(CTX ctx, Object *o)
{
#define ctx_update_refs(ctx, buf, size) \
	WCTX(ctx)->refs = buf;\
	WCTX(ctx)->ref_size = size;

	long i;
	kObject *ref;
	knh_ostack_t ostackbuf, *ostack = ostack_init(ctx, &ostackbuf);
	knh_ensurerefs(ctx, ctx->memlocal->ref_buf, K_PAGESIZE);
	ostack_push(ctx, ostack, o);
	while((ref = ostack_next(ostack)) != NULL) {
		ctx_update_refs(ctx, ctx->memlocal->ref_buf, 0);
		O_cTBL(ref)->cdef->reftrace(ctx, RAWPTR(ref), ctx->memlocal->refs);
		if (ctx->memlocal->ref_size > 0) {
			for(i = ctx->memlocal->ref_size - 1; prefetch(ctx->memlocal->refs[i-1]), i >= 0; i--)
				//for (i = 0; prefetch(ctx->memlocal->refs[i+1]), i < ctx->memlocal->ref_size; i++) /* slow */
			{
				deref_ostack(ctx, ctx->memlocal->refs[i], ostack);
			}
		}
		knh_Object_finalfree(ctx, ref);
	}
	ostack_free(ctx, ostack);
}

void knh_Object_RCsweep(CTX ctx, Object *o)
{
	knh_Object_RCdec(o);
	if(Object_isRC0(o)) {
		knh_Object_RCfree(ctx, o);
	}
}

#endif
/* ------------------------------------------------------------------------ */
/* malloc */

static void *call_malloc_aligned(CTX ctx, size_t size, size_t align)
{
	void *block = NULL;
#if defined(HAVE_POSIX_MEMALIGN)
	int ret = posix_memalign(&block, align, size);
	if(ret != 0)
		goto L_OutOfMemory;
#elif defined(HAVE_MEMALIGN)
	block = memalign(align, size);
	if (unlikely(block == NULL))
		goto L_OutOfMemory;
#elif defined(K_USING_WINDOWS_)
	block = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (unlikely(block == NULL))
		goto L_OutOfMemory;
#else
	block = malloc(size + align);
	if (unlikely(block == NULL))
		goto L_OutOfMemory;
	if((uintptr_t)block % align != 0) {
		char *t2 = (char*)((((kuintptr_t)block / align) + 1) * align);
		void **p = (void**)(t2 + size);
		DBG_ASSERT((char*)p < ((char*)block) + size + align);
		p[0] = block;
		block = (void*)t2;
		DBG_ASSERT((kuintptr_t)block % align == 0);
	}
	else {
		void **p = (void**)((char*)block + size);
		p[0] = block;
	}
#endif
	return block;
L_OutOfMemory:
	THROW_OutOfMemory(ctx, size);
	abort();
	return NULL;
}
static void call_free_aligned(CTX ctx, void *block, size_t size)
{
#if defined(HAVE_POSIX_MEMALIGN) || defined(HAVE_MEMALIGN)
	free(block);
#elif defined(K_USING_WINDOWS_)
	VirtualFree(block, 0, MEM_RELEASE);
#else
	void **p = (void**)((char*)block + size);
	block = p[0];
	free(block);
#endif
}

#if GCDEBUG
static size_t malloced_size = 0;
#define DBG_CHECK_MALLOCED_SIZE()      DBG_ASSERT(malloced_size == 0)
#define DBG_CHECK_MALLOCED_INC_SIZE(n) (malloced_size += (n))
#define DBG_CHECK_MALLOCED_DEC_SIZE(n) (malloced_size -= (n))
#else
#define DBG_CHECK_MALLOCED_SIZE()
#define DBG_CHECK_MALLOCED_INC_SIZE(n)
#define DBG_CHECK_MALLOCED_DEC_SIZE(n)
#endif

static inline void do_bzero(void *ptr, size_t size)
{
	memset(ptr, 0, size);
}

static inline void do_memcpy(void *s1, void *s2, size_t size)
{
	memcpy(s1, s2, size);
}

static inline void *do_malloc(size_t size)
{
	void *ptr = malloc(size);
	do_bzero(ptr, size);
	DBG_CHECK_MALLOCED_INC_SIZE(size);
	return ptr;
}

static inline void *do_realloc(void *ptr, size_t oldSize, size_t newSize)
{
	char *newptr = (char *) realloc(ptr, newSize);
	do_bzero(newptr+oldSize, newSize-oldSize);
	DBG_CHECK_MALLOCED_INC_SIZE(newSize - oldSize);
	return (void *) newptr;
}

static inline void do_free(void *ptr, size_t size)
{
#if GCDEBUG
	memset(ptr, 0xa, size);
#endif
	DBG_CHECK_MALLOCED_DEC_SIZE(size);
	free(ptr);
}

static GCInfo *BMGC_init(CTX ctx)
{
	HeapManager *mng = (HeapManager*) do_malloc(sizeof(*mng));
#ifdef GCSTAT
	global_gc_stat.fp = fopen("KONOHA_BMGC_INFO", "a");
	time_t timer;
	timer = time(NULL);
	char buf[128];
	char* stime = &buf[0];
	stime = ctime(&timer);
	size_t eol = strlen(stime);
	stime[eol-1] = '\0';
	gc_stat("/**********************************************************/");
	gc_stat("/* %s", stime);
	gc_stat("/**********************************************************/");
#endif
	size_t default_size = SUBHEAP_DEFAULT_SEGPOOL_SIZE;
#ifdef GC_CONFIG
	char *poolsize = knh_getenv("KONOHA_DEFAULT_MEMPOOL_SIZE");
	if (poolsize) {
		kint_t tmp;
		if (knh_bytes_parseint(B(poolsize), &tmp))
			default_size = (size_t) tmp;
	}
#endif
	HeapManager_init(ctx, mng, default_size);
	return (GCInfo *) mng;
}

static void BMGC_exit(CTX ctx, HeapManager *mng)
{
#ifdef GCSTAT
	dump_memstat();
#endif
	HeapManager_final_free(ctx, mng);
	HeapManager_delete(ctx, mng);
	do_free(mng, sizeof(*mng));
	DBG_CHECK_MALLOCED_SIZE();
#ifdef GCSTAT
	fclose(global_gc_stat.fp);
#endif
}

static inline size_t SizeToKlass(size_t n) {
	size_t size = ALIGN(n, MIN_ALIGN);
	size_t size_w = size - 1;
	return (BITS - BSR(size_w));
}

#define SEGMENTLIST_NEXT(seg, list) do {\
	seg  = (list);\
	DBG_ASSERT(seg != NULL);\
	(list) = seg->next;\
	seg->next = NULL;\
} while(0)

#define BM_IS_FULL(BM) (~(BM) == 0)
#define SEG_BITMAP_N(seg, n, idx) ((bitmap_t*)((seg->base[n])+idx))
#define SEG_SNAPSHOT_N(seg, n, idx) ((bitmap_t*)((seg->sbase[n])+idx))
#define AP_BITMAP_N(ap, n, idx) ((bitmap_t*)((ap->seg->base[n])+idx))

static Segment *allocSegment(HeapManager *mng, int klass)
{
	Segment *seg = NULL;
	if (mng->segmentList) {
		SEGMENTLIST_NEXT(seg, mng->segmentList);
		gc_debug("klass=%d seg=%p mng->seg=%p", klass, seg, mng->segmentList);
	}
	return seg;
}
static void findBlockOfLastSegment(Segment *seg, SubHeap *h, size_t size)
{
	const AllocationBlock *blk = seg->blk;
	BlockHeader *head = (BlockHeader *) blk;
	head->seg   = seg;
	head->klass = seg->heap_klass;
	gc_info("seg=%p, blk=(%p,%p)", seg, blk, blk+1);
	h->p.blkptr = (AllocationBlock*)((char*)blk+(size));
}

static bool newSegment(HeapManager *mng, SubHeap *h)
{
	size_t klass = h->heap_klass;
	Segment *seg = allocSegment(mng, klass);
	DBG_ASSERT(h->freelist == NULL);

	if (!seg) {
		return false;
	}
	DBG_ASSERT(seg->live_count == 0);
	if (h->seglist_size == h->seglist_max) {
		size_t newSize, oldSize;
		oldSize = sizeof(Segment**)*h->seglist_max;
		newSize = sizeof(Segment**)*h->seglist_max * 2;
		h->seglist_max *= 2;
		h->seglist = (Segment**)(do_realloc(h->seglist, oldSize, newSize));
	}
	seg->bitmap = AllocBitMap(klass);
	seg->snapshot = AllocBitMap(klass);
	seg->heap_klass = klass;
	ARRAY_init(VoidPtr, &seg->remset);
	h->seglist[h->seglist_size++] = seg;

	h->p.seg = seg;
	findBlockOfLastSegment(seg, h, KlassBlockSize(klass));
	BITPTRS_INIT(h->p.bitptrs, seg, klass);
	SNAPSHOT_INIT(seg, klass);
	BITMAP_SET_LIMIT(seg->bitmap, klass);

	return true;
}

static inline Segment *freelist_pop(SubHeap *h)
{
	Segment *seg = h->freelist;
	h->freelist = seg->next;
	return seg;
}

static inline bool freelist_isEmpty(SubHeap *h)
{
	return (h->freelist == NULL);
}

static bool fetchSegment(SubHeap *h, size_t klass)
{
	Segment *seg;
	if (freelist_isEmpty(h))
		return false;
	seg = freelist_pop(h);
	h->p.seg = seg;
	BITPTRS_INIT(h->p.bitptrs, seg, klass);
	return true;
}

static bool nextSegment(HeapManager *mng, SubHeap *h, AllocationPointer *p)
{
	Segment *seg;
	while (h->freelist != NULL) {
		seg = freelist_pop(h);
		DBG_ASSERT(seg->live_count < SegmentBlockCount[h->heap_klass]);
		p->seg = seg;
		BITPTRS_INIT(h->p.bitptrs, seg, h->heap_klass);
		if (findNextFreeBlock(p)) {
			gc_info("h[%d], seg=%p", h->heap_klass, seg);
			return true;
		}
	}

	if (newSegment(mng, h)) {
		findNextFreeBlock(p);
		return true;
	}

	return false;
}

#define BP(p, n) ((p)->bitptrs[n])
static void BitPtr0_inc(AllocationPointer *p)
{
	uintptr_t bpidx  = BP(p, 0).idx;
	uintptr_t bpmask = BP(p, 0).mask;
	bitmap_t *bm = AP_BITMAP_N(p, 0, bpidx);
	BM_SET(*bm, bpmask);
	uintptr_t rot = bpmask >> (BITS - 1);

	BP(p, 0).idx  = bpidx + rot;
	BP(p, 0).mask = (bpmask << 1) | rot;
}

static void inc(AllocationPointer *p, SubHeap *h)
{
	int size = KlassBlockSize(h->heap_klass);
	p->blkptr = (AllocationBlock*)((char*)p->blkptr+size);
	BitPtr0_inc(p);
	p->seg->live_count++;
}

static bool isMarked(AllocationPointer *p)
{
	uintptr_t idx  = BP(p, 0).idx;
	uintptr_t mask = BP(p, 0).mask;
	bitmap_t *bm = AP_BITMAP_N(p, 0, idx);
	return (BM_TEST(*bm, mask));
}

#define BITPTR_INIT_(bpidx, bpmask, idx) do {\
	bpidx  = idx / BITS;\
	bpmask = ONE << (idx % BITS);\
} while(0)

static BitPtr *BitPtr_init(BitPtr *bp, uintptr_t idx)
{
	BITPTR_INIT_(bp->idx, bp->mask, idx);
	return bp;
}

static uintptr_t bitptrToIndex(uintptr_t bpidx, uintptr_t bpmask)
{
	return bpidx * BITS + FFS(bpmask) - 1;
}

static BlkPtr *blockAddress(Segment *s, uintptr_t idx, uintptr_t mask)
{
	size_t size = s->heap_klass;
	size_t offset = bitptrToIndex(idx, mask) << size;
	const BlkPtr *ptr = s->blk;
	return (AllocationBlock*)((char*)ptr+offset);
}

#define BP_NEXT_MASK(ap, bpidx, bpmask, j) do {\
	bitmap_t *bm   = AP_BITMAP_N(p, j, bpidx);\
	uintptr_t temp = *bm | (bpmask - ONE);\
	uintptr_t mask = (temp + ONE) & ~temp;\
	bpmask = mask;\
} while(0)

#if GCDEBUG
#define DBG_ALLOCATION_POINTER(p) do {\
	kObject *o = blockAddress(p->seg, BP(p, 0).idx, BP(p, 0).mask);\
	if (o->h.meta == NULL) {\
		fprintf(stderr, "o=%p, seg=%p\n", o, p->seg);\
		assert(o->h.meta == NULL);\
	}\
} while(0)
#else
#define DBG_ALLOCATION_POINTER(p)
#endif

static bool findNextFreeBlock(AllocationPointer *p)
{
	uintptr_t i, idx = BP(p, 0).idx;
	BP_NEXT_MASK(p, BP(p, 0).idx, BP(p, 0).mask, 0);
	if (BP(p, 0).mask == 0) {
		BitPtr *bp;
#if GCDEBUG
		gc_info("klass=%d, idx=%ld mask=%lx, seg=%p",
				(p->seg)?p->seg->heap_klass:-1,
				BP(p, 0).idx, BP(p, 0).mask, p->seg);
#endif
		for (i = 1; i < SEGMENT_LEVEL; ++i) {
			bp = BitPtr_init(&BP(p, i), idx);
			bitmap_t *bm = AP_BITMAP_N(p, i, bp->idx);
			BM_SET(*bm, bp->mask);
			BP_NEXT_MASK(p, bp->idx, bp->mask, i);
			if (bp->mask != 0)
				break;
			idx /= BITS;
		}
		if (i == SEGMENT_LEVEL)
			return false;
		do {
			--i;
			BP(p, i).idx  = bitptrToIndex(bp->idx, bp->mask);
			BP(p, i).mask = 1;
			BP_NEXT_MASK(p, BP(p, i).idx, BP(p,i).mask, i);
			gc_info("klass=%d, level=%lu idx=%ld mask=%lx",
					p->seg->heap_klass, i, BP(p, i).idx, BP(p, i).mask);
			DBG_ASSERT(BP(p, i).mask != 0);
			DBG_ALLOCATION_POINTER(p);
		} while(i > 0);
	}
	p->blkptr = blockAddress(p->seg, BP(p, 0).idx, BP(p, 0).mask);
	return true;
}

static void *tryAlloc(HeapManager *mng, SubHeap *h)
{
	AllocationPointer *p = &h->p;
	void *temp;
	if (isMarked(p)) {
		if (findNextFreeBlock(p) == false) {
			if (nextSegment(mng, h, p) == false) {
				return NULL;
			}
		}
	}
	temp = p->blkptr;
	prefetch_(temp, 0, 0);
	inc(p, h);
	return temp;
}

#define HEAP_SEGMENTLIST_INIT_SIZE 16
static bool Heap_init(HeapManager *mng, SubHeap *h, int klass)
{
	size_t i;

	h->heap_klass = klass;
	h->seglist_size = 0;
	h->seglist_max  = HEAP_SEGMENTLIST_INIT_SIZE;
	h->seglist  = (Segment**)(do_malloc(sizeof(Segment**)*h->seglist_max));
	h->freelist = NULL;
	h->p.bitptrs[0].mask = 1;
	h->p.seg = &segment_dummy;
	h->isFull = 0;
	for (i = 0; i < SEGMENT_LEVEL; ++i) {
		h->p.seg->base[i] = (bitmap_t*)bitmap_dummy;
	}
	return true;
}

static void Heap_dispose(SubHeap *h)
{
	if (h->seglist) {
		do_free(h->seglist, sizeof(Segment**)*h->seglist_max);
	}
	do_bzero(h, sizeof(*h));
}

static Segment *SegmentPool_init(size_t size, AllocationBlock *blk)
{
	size_t i;
	Segment *pool = (Segment*)(do_malloc(sizeof(Segment) * size));
	Segment *seg  = pool;
	Segment *next = seg+1, *tail = pool + size - 1;
	for (i = 0; i < size; ++i, ++blk, ++next, ++seg) {
		seg->blk  = blk;
		seg->next = next;
#if GCDEBUG
		seg->managed_heap = blk;
		seg->managed_heap_end = blk+1;
#endif
		gc_info("[%lu] seg=%p, next=%p, blk=%p, %p", i, seg, next,
				seg->managed_heap, seg->managed_heap_end);
	}
	tail->next = NULL;
	return pool;
}

static void SegmentPool_dispose(Segment *pool, size_t size)
{
	Segment *seg = NULL;
	size_t i;

	for (i = 0; i < size; i++) {
		seg = pool + i;
		if (seg->bitmap) {
			DeleteBitMap(seg->bitmap, seg->heap_klass);
			DeleteBitMap(seg->snapshot, seg->heap_klass);
		}
	}
	do_free(pool, sizeof(Segment) * size);
}

static void HeapManager_expandHeap(CTX ctx, HeapManager *mng, size_t list_size)
{
	// list_size: 2 ^ 8(256)
	Segment *segment_pool;

	size_t heap_size = list_size * SEGMENT_SIZE;
	// heap_size: 32 Mb
	void *managed_heap = call_malloc_aligned(ctx, heap_size, SEGMENT_SIZE);
	void *managed_heap_end = (char*)managed_heap + heap_size;
#if defined(GCDEBUG) && defined(GCSTAT)
	global_gc_stat.managed_heap = (AllocationBlock*) managed_heap;
	global_gc_stat.managed_heap_end = (AllocationBlock*) managed_heap_end;
#endif

	segment_pool = SegmentPool_init(list_size, (AllocationBlock*) managed_heap);
	mng->segmentList  = segment_pool;

	ARRAY_add(size_t,  &mng->heap_size_a, heap_size);
	ARRAY_add(VoidPtr, &mng->managed_heap_a    , (void*)managed_heap);
	ARRAY_add(VoidPtr, &mng->managed_heap_end_a, (void*)managed_heap_end);

	ARRAY_add(SegmentPtr, &mng->segment_pool_a, segment_pool);
	ARRAY_add(size_t, &mng->segment_size_a, list_size);
	DBG_(ctx->stat->usedMemorySize += heap_size);
#ifdef GCSTAT
	gc_stat("Expand Heap(%luMB)[%p, %p]", heap_size/MB_, managed_heap, managed_heap_end);
#endif
}

static void HeapManager_init(CTX ctx, HeapManager *mng, size_t list_size)
{
	size_t i;
	SubHeap *h;
	mng->isFull = false;
	ARRAY_init(size_t,  &mng->heap_size_a);
	ARRAY_init(VoidPtr, &mng->managed_heap_a);
	ARRAY_init(VoidPtr, &mng->managed_heap_end_a);
	ARRAY_init(SegmentPtr, &mng->segment_pool_a);
	ARRAY_init(size_t, &mng->segment_size_a);

	HeapManager_expandHeap(ctx, mng, list_size);
	for_each_heap(h, i, mng->heaps) {
		Heap_init(mng, (mng->heaps+i), i);
	}
}

static void HeapManager_delete(CTX ctx, HeapManager *mng)
{
	size_t i;
	Segment *x;
	void *p;
	SubHeap *h;
	for_each_heap(h, i, mng->heaps) {
		Heap_dispose(mng->heaps+i);
	}

	FOR_EACH_ARRAY(mng->segment_pool_a, x, i) {
		size_t size = ARRAY_n(mng->segment_size_a, i);
		SegmentPool_dispose(x, size);
	}
	ARRAY_dispose(SegmentPtr, &mng->segment_pool_a);
	ARRAY_dispose(size_t,     &mng->segment_size_a);

	FOR_EACH_ARRAY(mng->managed_heap_a, p, i) {
		size_t size = ARRAY_n(mng->heap_size_a, i);
		call_free_aligned(ctx, p, size);
	}
	ARRAY_dispose(size_t,  &mng->heap_size_a);
	ARRAY_dispose(VoidPtr, &mng->managed_heap_a);
	ARRAY_dispose(VoidPtr, &mng->managed_heap_end_a);
}

static SubHeap *findSubHeapBySize(HeapManager *mng, size_t n)
{
	size_t klass = SizeToKlass(n);
	DBG_ASSERT(n <= SUBHEAP_KLASS_SIZE_MAX);
	DBG_ASSERT(n != 0);
	return &(mng->heaps)[klass];
}


#ifdef GCDEBUG
#define CLEAR_GCINFO(o) (o)->h.gcinfo = NULL
#else
#define CLEAR_GCINFO(o)
#endif

#if GCDEBUG
static bool CHECK_OBJECT(SubHeap *h, kObject *o, size_t request_size)
{
	short *gcinfo = (short*) &o->h.gcinfo;
	if (gcinfo[0] > 0) {
		short x = gcinfo[0];
		short y = gcinfo[1];
		fprintf(stderr, "size=%lu temp=%p, [0]=%d, [1]=%d\n",
				KlassBlockSize(h->heap_klass), gcinfo, x, y);
		return true;
	}
	return false;
}
#else
#define CHECK_OBJECT(h, o, request_size)
#endif

#if GCDEBUG
static void DBG_CHECK_OBJECT(SubHeap *h, kObject *o, size_t request_size, bool write)
{
	short *gcinfo = (short*) &o->h.gcinfo;
	if (CHECK_OBJECT(h, o, request_size)) {
		short x = gcinfo[0];
		short y = gcinfo[1];
		assert(x==0&&y==0);
	}
	if (write) {
		gcinfo[0] = global_gc_stat.object_count[h->heap_klass];
		gcinfo[1] = request_size;
	}
}
#else
#define DBG_CHECK_OBJECT(h, o, request_size, write)
#endif

#if GCDEBUG
static bool DBG_CHECK_OBJECT_IN_SEGMENT(kObject *o, Segment *seg)
{
	kObject *s = (kObject *) seg->managed_heap;
	kObject *e = (kObject *) seg->managed_heap_end;
	return (s < o && o < e);
}

static bool DBG_CHECK_OBJECT_IN_HEAP(kObject *o, SubHeap *h)
{
	Segment *seg = h->p.seg;
	if (DBG_CHECK_OBJECT_IN_SEGMENT(o, seg))
		return true;
	/* TODO */
	// search from seglist;
	return false;
}
#else
#define DBG_CHECK_OBJECT_IN_SEGMENT(o, seg) true
#define DBG_CHECK_OBJECT_IN_HEAP(o, h) true
#endif

#define minorGC(ctx, mng) bitmapMarkingGC(ctx, mng GC_YOUNG)
#define majorGC(ctx, mng) bitmapMarkingGC(ctx, mng GC_TENURE)

static void deferred_sweep(CTX ctx, kObject *o)
{
	STAT_(ctx->stat->collectedObject++;)
	bmgc_Object_free(ctx, o);
	CLEAR_GCINFO(o);
}

#define GC_MARGIN 8
static kObject *bm_malloc_internal(CTX ctx, HeapManager *mng, size_t n)
{
	kObject *temp = NULL;
	SubHeap *h;

	DBG_ASSERT(n != 0);
#if GCDEBUG
	global_gc_stat.current_request_size = n;
#endif
	if (n > SUBHEAP_KLASS_SIZE_MAX)
		return do_malloc(n);
	h = findSubHeapBySize(mng, n);
	temp = tryAlloc(mng, h);

	Segment *seg = (&h->p)->seg;
	if ((mng->segmentList == NULL) && (h->freelist == NULL) && seg->live_count < SegmentBlockCount[h->heap_klass] - GC_MARGIN && !TFLAG_is(int, ctx->safepoint, SAFEPOINT_GC)) {
		SAFEPOINT_SETGC(ctx);
	}
	DBG_ASSERT(temp != NULL);
	DBG_ASSERT(DBG_CHECK_OBJECT_IN_HEAP(temp, h));
#if GCDEBUG
	global_gc_stat.total_object++;
	global_gc_stat.object_count[h->heap_klass]++;
#endif
	deferred_sweep(ctx, temp);
	DBG_CHECK_OBJECT(h, temp, n, true);
	return temp;
}

#define LOAD_SNAPSHOT(s)  { \
	do_memcpy(s->bitmap, s->snapshot, BM_SIZE[s->heap_klass]);\
} \

#define SAVE_SNAPSHOT(s)  { \
	do_memcpy(s->snapshot, s->bitmap, BM_SIZE[s->heap_klass]);\
} \

#define LOAD_LIVECOUNT(s) s->live_count = s->tenure_live_count
#define SAVE_LIVECOUNT(s) s->tenure_live_count = s->live_count

//static int check_allBitmap(HeapManager *mng)
//{
//	SubHeap* h;
//	size_t i, j, k;
//	for_each_heap(h, i, mng->heaps) {
//		for (j = 0; j < h->seglist_size; j++) {
//			Segment *s = h->seglist[j];
//			for (k = 0; k < BM_SIZE[s->heap_klass] / sizeof(uintptr_t); k++) {
//				bitmap_t *bm = SEG_BITMAP_N(s, 0, k);
//				bitmap_t *ss = SEG_SNAPSHOT_N(s, 0, k);
//				if (*bm != *ss) {
//					fprintf(stderr, "ERROR\n");
//					fprintf(stderr, "h[%d]->s[%p]->seglist[%lu][%lu] bm: %lu, ss: %lu\n", h->heap_klass, s, j, k, *bm, *ss);
//					return 0;
//				}
//			}
//		}
//	}
//	return 1;
//}

static void setTenureBitMapsAndCount(HeapManager *mng, SubHeap *h)
{
	size_t i;
	for (i = 0; i < h->seglist_size; i++) {
		Segment *s = h->seglist[i];
		ClearBitMap(s->bitmap, h->heap_klass);
		LOAD_SNAPSHOT(s);
		LOAD_LIVECOUNT(s);
		//DBG_P("klass(%lu)[%lu] load livecount: %d", s->heap_klass, i, s->tenure_live_count);
		BITMAP_SET_LIMIT_AND_CPY_BM(s->bitmap, s->snapshot, h->heap_klass);
		gc_info("klass=%d, seg[%lu]=%p count=%d",
				s->heap_klass, i, s, s->live_count);
	}
}

static void clearAllBitMapsAndCount(HeapManager *mng, SubHeap *h)
{
	size_t i;

	for (i = 0; i < h->seglist_size; i++) {
		Segment *s = h->seglist[i];
		ClearBitMap(s->bitmap, h->heap_klass);
		BITMAP_SET_LIMIT(s->bitmap, h->heap_klass);
		gc_info("klass=%d, seg[%lu]=%p count=%d",
				s->heap_klass, i, s, s->live_count);
		s->live_count = 0;
	}
}

#define NEXT_MASK(bm, mask) do {\
	uintptr_t temp;\
	temp = bm | (mask - ONE);\
	mask = (temp + ONE) & ~temp;\
	BM_SET(bm, mask);\
} while(0)

static kObject *indexToAddr(Segment *seg, uintptr_t idx, uintptr_t mask)
{
	const BlkPtr *ptr = seg->blk;
	size_t size = seg->heap_klass;
	size_t n = idx * BITS + FFS(mask) - 1;
	size_t offset = n << size;
	return (kObject*)((char*)ptr+offset);
}

static void b0_final_sweep(CTX ctx, bitmap_t bm, size_t idx, Segment *seg)
{
	kObject *o;
	bitmap_t mask = 1;
	NEXT_MASK(bm, mask);
	while (mask) {
		o = indexToAddr(seg, idx, mask);
#if GCDEBUG
		if (O_cTBL(o)) {
			global_gc_stat.collected[seg->heap_klass] += 1;
		}
#endif
		bmgc_Object_free(ctx, o);
		NEXT_MASK(bm, mask);
	}
}

static void HeapManager_final_free(CTX ctx, HeapManager *mng)
{
	size_t i, j;
	SubHeap *h;
	for_each_heap(h, j, mng->heaps) {
		clearAllBitMapsAndCount(mng, h);
		for (i = 0; i < h->seglist_size; i++) {
			Segment *s = h->seglist[i];
			bitmap_t *bm0;
			bitmap_t *b0 = (bitmap_t *) s->base[0];
			bitmap_t *l0 = b0 + SegmentBitMapCount[j];
			for (bm0 = b0; bm0 < l0; ++bm0) {
				b0_final_sweep(ctx, *bm0, bm0 - b0, s);
			}
		}
		gc_info("heap[%d] collected %lu",
				h->heap_klass,
				global_gc_stat.collected[h->heap_klass]);
	}
}

#if GCDEBUG
static void dumpBM(uintptr_t bm)
{
	int i;
	uintptr_t mask;
	fprintf(stderr, "                 ");
	for (i = 63; i >= 0; i--) {
		if (i %10 == 0) {
			fprintf(stderr, "%d", i / 10);
		} else {
			fprintf(stderr, " ");
		}
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "%16lx ", bm);
	for (i = 63; i >= 0; i--) {
		fprintf(stderr, "%d", i % 10);
	}
	fprintf(stderr, "\n                 ");
	for (mask = ONE << 63; mask; mask >>= 1) {
		fprintf(stderr, "%d", (bm & mask)?1:0);
	}
	fprintf(stderr, "\n");
}

enum heap_dump_mode {
	HEAP_DUMP_INFO,
	HEAP_DUMP_VERBOSE
};

static void Heap_dump(const SubHeap *h, enum heap_dump_mode mode)
{
	gc_info("klass[%2d] object_count=%lu segment_list=(%d) ",
			h->heap_klass, global_gc_stat.object_count[h->heap_klass],
			h->seglist_size);
	//for (i = 0; i < h->seglist_size; ++i) {
	//    fprintf(stderr, "seg[%d]=%p ", i, h->seglist[i]);
	//}
	//fprintf(stderr, "\n");
	//for (i = 0; i < SEGMENT_LEVEL; i++) {
	//    BitPtr p = h->p.bitptrs[i];
	//    fprintf(stderr, "bit_ptr[%lu]\nidx=%lu\n", i, p.idx);
	//    dumpBM(p.mask);
	//}
	//if (mode == HEAP_DUMP_VERBOSE) {
	//    fprintf(stderr, "current bitmap status\n");
	//    for (i = 0; i < SEGMENT_LEVEL; i++) {
	//        fprintf(stderr, "bitmap[%d]\n", i);
	//        uintptr_t idx = h->p.bitptrs[i].idx;
	//        bitmap_t *bm  = h->p.base[0]+idx;
	//        dumpBM(*bm);
	//    }
	//}
}

#endif /* GCDEBUG */

#ifdef GCDEBUG
static void BMGC_dump(GCInfo *info)
{
	size_t i;
	HeapManager *mng = (HeapManager *) info;
	gc_info("********************************");
	gc_info("* Heap Information");
	gc_info("********************************");
	gc_info("total allocated object count=%lu",
			global_gc_stat.total_object);
	for (i = SUBHEAP_KLASS_MIN; i <= SUBHEAP_KLASS_MAX; i++) {
	}
	//gc_info("HeapManager=%p segment_pool_size=%lu",
	//        mng, mng->segment_pool_size);
	for (i = SUBHEAP_KLASS_MIN; i <= SUBHEAP_KLASS_MAX; i++) {
		SubHeap *h = mng->heaps + i;
		Heap_dump(h, HEAP_DUMP_INFO);
	}
	gc_info("\n");
}

static bool DBG_CHECK_BITMAP(Segment *seg, bitmap_t *bm)
{
	bitmap_t *b0 = (bitmap_t *)seg->base[0];
	bitmap_t *l0 = (bitmap_t *)seg->base[0] + SegmentBitMapCount[seg->heap_klass];
	return (b0 <= bm && bm <= l0);
}
#else
static void BMGC_dump(GCInfo *info) {}
#define DBG_CHECK_BITMAP(seg, bm) true
#endif

#ifdef K_USING_GCDEBUG
//static void dump_segBM_(HeapManager *mng, SubHeap *h)
//{
//	size_t i, k;
//	fprintf(stderr, "********************* BITMAP: %d ***********************\n", h->heap_klass);
//	for (i = 0; i < h->seglist_size; i++) {
//		Segment *s = h->seglist[i];
//		fprintf(stderr, "[ ");
//		for (k = 0; k < BM_SIZE[s->heap_klass] / sizeof(uintptr_t); k++) {
//			bitmap_t *bm = SEG_BITMAP_N(s, 0, k);
//			fprintf(stderr, "%lu ", *bm);
//			if (k % 8 == 0) {
//				fprintf(stderr, "\n");
//			}
//		}
//		fprintf(stderr, " ]\n");
//	}
//}
//
//static void dump_segSS_(HeapManager *mng, SubHeap *h)
//{
//	size_t i, k;
//	fprintf(stderr, "********************* SNAPSHOT: %d *********************\n", h->heap_klass);
//	for (i = 0; i < h->seglist_size; i++) {
//		Segment *s = h->seglist[i];
//		fprintf(stderr, "[ ");
//		for (k = 0; k < BM_SIZE[s->heap_klass] / sizeof(uintptr_t); k++) {
//			bitmap_t *ss = SEG_SNAPSHOT_N(s, 0, k);
//			fprintf(stderr, "%lu ", *ss);
//			if (k % 8 == 0) {
//				fprintf(stderr, "\n");
//			}
//		}
//		fprintf(stderr, " ]\n");
//	}
//}

#define DUMP_SEGBM(mng, h) dump_segBM_(mng, h)
#define DUMP_SEGSS(mng, h) dump_segSS_(mng, h)
#else /* K_USING_GCDEBUG */
#define DUMP_SEGBM(mng, h)
#define DUMP_SEGSS(mng, h)
#endif

static void bmgc_gc_init(CTX ctx, HeapManager *mng, int isTenure)
{
	size_t i;
	SubHeap *h;
	STAT_(ctx->stat->markedObject = 0;)
		BMGC_dump(mng);
	void(*init_bit) (HeapManager *mng, SubHeap *h);
	init_bit = (isTenure) ? clearAllBitMapsAndCount : setTenureBitMapsAndCount;
	for_each_heap(h, i, mng->heaps) {
		//DUMP_SEGBM(mng, h);
		//DUMP_SEGSS(mng, h);
		init_bit(mng, h);
	}
	//DBG_ASSERT(check_allBitmap(mng));
}

#define OBJECT_LOAD_BLOCK_INFO(o, seg, index, klass) do {\
	uintptr_t addr, offset;\
	addr   = ((uintptr_t)o) & ~(SEGMENT_SIZE - ONE);\
	offset = ((uintptr_t)o) &  (SEGMENT_SIZE - ONE);\
	BlockHeader *head = (BlockHeader*) addr;\
	seg   = head->seg;\
	klass = head->klass;\
	index = offset >> klass;\
} while(0)

static void bitmap_mark(bitmap_t bm, Segment *seg, uintptr_t idx, uintptr_t mask)
{
	if (BM_IS_FULL(bm)) {
		size_t i;
		for (i = 1; i < SEGMENT_LEVEL-1; ++i) {
			uintptr_t bpidx, bpmask;
			BITPTR_INIT_(bpidx, bpmask, idx);
			bitmap_t *bm1 = SEG_BITMAP_N(seg, i, bpidx);
			BM_SET(*bm1, bpmask);
			if (!BM_IS_FULL(*bm1))
				break;
			idx /= BITS;
		}
	}
}

static void mark_ostack(CTX ctx, HeapManager *mng, kObject *o, knh_ostack_t *ostack)
{
	Segment *seg;
	int index, klass;
	uintptr_t bpidx, bpmask;
	OBJECT_LOAD_BLOCK_INFO(o, seg, index, klass);
	BITPTR_INIT_(bpidx, bpmask, index);
	bitmap_t *bm  = SEG_BITMAP_N(seg, 0, bpidx);
	prefetch_(SEG_BITMAP_N(seg, 1, 0), 1, 1);

	DBG_ASSERT(DBG_CHECK_OBJECT_IN_SEGMENT(o, seg));
	DBG_ASSERT(DBG_CHECK_BITMAP(seg, bm));
	if (!BM_TEST(*bm, bpmask)) {
		BM_SET(*bm, bpmask);
		setTenure(o);
		bitmap_mark(*bm, seg, bpidx, bpmask);
		++(seg->live_count);
		ostack_push(ctx, ostack, o);
		STAT_(++(ctx->stat->markedObject););
#ifdef GCSTAT
		global_gc_stat.marked[klass]++;
#endif
#if GCDEBUG
		o->h.meta = (void*)((uintptr_t)o->h.meta + 0x1);
#endif
	}
}

#define context_reset_refs(memlocal) do {\
	memlocal->refs = memlocal->ref_buf;\
	memlocal->ref_size = 0;\
} while (0)

#define getBlockHeader(o) (BlockHeader*)(((uintptr_t)(o) / SEGMENT_SIZE) * SEGMENT_SIZE)
#define OBJECT_TO_SEG_AND_KLASS(o, seg, klass) {\
	BlockHeader *head_ = (BlockHeader *)getBlockHeader(o);\
	seg = head_->seg;\
	klass = head_->klass;\
}\

void setRemSet_(kObject *o)
{
	Segment* s;
	BlockHeader *head = (BlockHeader*)getBlockHeader(o);
	s = head->seg;
	ARRAY_add(VoidPtr, &s->remset, (void*)o);
}

kObject **remset_reftrace(CTX ctx, HeapManager *mng FTRARG)
{
	size_t i, j, k;
	SubHeap* h;
	Segment* s;
	for_each_heap(h, i, mng->heaps) {
		for (j = 0; j < h->seglist_size; j++) {
			s = h->seglist[j];
			size_t size = ARRAY_size(s->remset);
			if (size == 0) {
				continue;
			}
			KNH_ENSUREREF(ctx, size);
			//DBG_P("remset size: %lu", size);
//#ifdef K_USING_FASTREFS_
//			KNH_SETREF(ctx, s->remset.list, size);
//#else
			FOR_EACH_ARRAY_(s->remset, k) {
				kObject* o =  (kObject *)ARRAY_n(s->remset, k);
				KNH_ADDREF(ctx, o);
			}
//#endif
		}
	}
	KNH_SIZEREF(ctx);
	return tail_;
}

static void clear_remset(CTX ctx, HeapManager *mng)
{
	size_t i, j;
	SubHeap* h;
	Segment* s;
	for_each_heap(h, i, mng->heaps) {
		for (j = 0; j < h->seglist_size; j++) {
			s = h->seglist[j];
			ARRAY_clear(VoidPtr, &s->remset);
		}
	}
}

static void bmgc_gc_mark(CTX ctx, HeapManager *mng, int needsCStackTrace, int isTenure)
{
	long i;
	knh_ostack_t ostackbuf, *ostack = ostack_init(ctx, &ostackbuf);
	kObject *ref = NULL, **reftail = NULL;
	kmemlocal_t *memlocal = ctx->memlocal;

	knh_ensurerefs(ctx, memlocal->ref_buf, K_PAGESIZE);
	context_reset_refs(memlocal);
	reftail = knh_reftraceRoot(ctx, memlocal->refs);
	if (!isTenure) {
		reftail = remset_reftrace(ctx, mng, reftail);
	}
	if (needsCStackTrace) {
		cstack_mark(ctx, reftail);
	}
	goto L_INLOOP;
	while((ref = ostack_next(ostack)) != NULL) {
		const knh_ClassTBL_t *ct = O_cTBL(ref);
		context_reset_refs(memlocal);
		ct->cdef->reftrace(ctx, RAWPTR(ref), memlocal->refs);
		if(memlocal->ref_size > 0) {
L_INLOOP:;
			prefetch_(memlocal->refs[0], 0, 1);
			for(i = memlocal->ref_size - 1; i >= 0; --i) {
				mark_ostack(ctx, mng, memlocal->refs[i], ostack);
			}
		}
	}
	clear_remset(ctx, mng);
	ostack_free(ctx, ostack);
}

void *bm_malloc(CTX ctx, size_t n)
{
	HeapManager *mng = GCDATA(ctx);
	return (void *) bm_malloc_internal(ctx, mng, n);
}

void bm_free(CTX ctx, void *ptr, size_t n)
{
	if (n <= SUBHEAP_KLASS_SIZE_MAX) {
		kObject *o = (kObject *) ptr;
		Segment *seg;
		uintptr_t bpidx, bpmask, index, klass;
		OBJECT_LOAD_BLOCK_INFO(o, seg, index, klass);
		BITPTR_INIT_(bpidx, bpmask, index);
		bitmap_t *bm = SEG_BITMAP_N(seg, 0, bpidx);
		DBG_ASSERT(DBG_CHECK_OBJECT_IN_SEGMENT(o, seg));
		DBG_ASSERT(DBG_CHECK_BITMAP(seg, bm));
		DBG_ASSERT(BM_TEST(*bm, bpmask));
		seg->live_count -= 1;
		KNH_TODO("");
		bitmap_mark(*bm, seg, bpidx, bpmask);
		CLEAR_GCINFO((kObject*)ptr);
	} else {
		do_free(ptr, n);
	}
}

void *bm_realloc(CTX ctx, void *ptr, size_t os, size_t ns)
{
	HeapManager *mng = GCDATA(ctx);
	if(os <= K_FASTMALLOC_SIZE) {
		void *newptr = (void *) bm_malloc_internal(ctx, mng, ns);
		if(os > 0) {
			do_memcpy(newptr, ptr, os);
			do_bzero((char*)newptr + os, ns - os);
			bm_free(ctx, ptr, os);
		}
		else {
			DBG_ASSERT(ptr == NULL);
			knh_bzero(newptr, ns);
		}
		return newptr;
	}
	else {
		void *newptr = realloc(ptr, ns);
		DBG_ASSERT(ns > os);
		if (unlikely(newptr == NULL)) {
			THROW_OutOfMemory(ctx, ns);
		}
		knh_bzero((char*)newptr + os, (ns - os));
		return newptr;
	}
}

#define LIST_PUSH(tail, e) do {\
	*tail = e;\
	tail  = &e->next;\
} while (0)

static bool rearrangeSegList(CTX ctx, SubHeap *h, size_t klass)
{
	size_t i, count_dead = 0;
	Segment *unfilled = NULL, **unfilled_tail = &unfilled;
	if (h->seglist_size <= 1)
		return false;
	for (i = 0; i < h->seglist_size; i++) {
		Segment *s = h->seglist[i];
		size_t dead = SegmentBlockCount[klass] - s->live_count;
		count_dead += dead;
		if (dead > 0) {
			LIST_PUSH(unfilled_tail, s);
		}
		SAVE_SNAPSHOT(s);
		SAVE_LIVECOUNT(s);
	}
	*unfilled_tail = NULL;
	h->freelist = unfilled;
	fetchSegment(h, klass);
	h->isFull = (count_dead < SegmentBlockCount[klass] && h->freelist == NULL);
	DBG_P("h[%lu]->isFull: %lu(count dead: %lu)", h->heap_klass, h->isFull, count_dead);
	//h->isFull = (count_dead < SegmentBlockCount[klass]);
	return h->isFull;
}

#define MINOR_GC_MIN_COUNT 5

static void bmgc_gc_sweep(CTX ctx, HeapManager *mng, int isTenure)
{
	mng->isFull = false;
	size_t i;
	SubHeap *h;

	for_each_heap(h, i, mng->heaps) {
		mng->isFull |= rearrangeSegList(ctx, h, i);
	}
	if (mng->isFull) {
		HeapManager_expandHeap(ctx, mng, SUBHEAP_DEFAULT_SEGPOOL_SIZE*2);
		for_each_heap(h, i, mng->heaps) {
			if (h->isFull) {
				newSegment(mng, h);
			}
		}
	}
}

#define getHeapManager(ctx) ((HeapManager*)ctx->memlocal->freeObjectList)

void invoke_gc_(CTX ctx)
{
	HeapManager* mng = getHeapManager(ctx);
	if (mng->isFull) {
		majorGC(ctx, mng);
	}
	else {
		minorGC(ctx, mng);
	}
}

#ifdef GCSTAT
void dump_memstat() {
	gc_stat("gc invoked %lu times, marking time: %lu[ms], sweeping time: %lu[ms], GC avarage time: %lf[ms/GC]", global_gc_stat.gc_count, global_gc_stat.markingTime, global_gc_stat.sweepingTime, (float)(global_gc_stat.markingTime + global_gc_stat.sweepingTime) / global_gc_stat.gc_count);
}
#endif

#define STACKTRACE 1

static void bitmapMarkingGC(CTX ctx, HeapManager *mng, int isTenure)
{
	bmgc_gc_init(ctx, mng, isTenure);
#ifdef GCSTAT
	size_t i = 0, marked = 0, collected = 0, heap_size = 0;
	FOR_EACH_ARRAY_(mng->heap_size_a, i) {
		heap_size += ARRAY_n(mng->heap_size_a, i);
	}
#endif
	STAT_(
		kstatinfo_t *ctxstat = ctx->stat;
		kuint64_t start_time = knh_getTimeMilliSecond();
		kuint64_t mark_time = 0;
	);

	bmgc_gc_mark(ctx, mng, STACKTRACE, isTenure);

	STAT_(mark_time = knh_getTimeMilliSecond());

	bmgc_gc_sweep(ctx, mng, isTenure);

	STAT_(
		ctxstat->gcCount++;
		ctxstat->markingTime += (mark_time-start_time);
		ctxstat->latestGcTime = knh_getTimeMilliSecond();
		ctxstat->gcTime += (ctxstat->latestGcTime - start_time);
		GC_LOG("GC(%dMb): marked:%d, collected:%d marking_time=%dms, sweeping_time=%dms",
			ctxstat->usedMemorySize/ MB_,
			ctxstat->markedObject, ctxstat->collectedObject, 
			(int)(mark_time - start_time));
		ctxstat->collectedObject = 0;
	);
#ifdef GCSTAT
	SubHeap *h;
	for_each_heap(h, i, mng->heaps) {
		marked    += global_gc_stat.marked[i];
		collected += global_gc_stat.collected[i];
		global_gc_stat.marked[i]    = 0;
		global_gc_stat.collected[i] = 0;
	}
	global_gc_stat.gc_count += 1;
	global_gc_stat.markingTime += (mark_time-start_time);

	if (isTenure) {
		gc_stat("MajorGC(%lu) HeapSize=%luMB, last_collected=%lu, marked=%lu",
				global_gc_stat.gc_count, (heap_size/MB_), collected, marked);
	}
	else {
		gc_stat("MinorGC(%lu) HeapSize=%luMB, last_collected=%lu, marked=%lu",
				global_gc_stat.gc_count, (heap_size/MB_), collected, marked);
	}
#endif
}
/* ------------------------------------------------------------------------ */
/* [Object] */

void knh_share_initArena(CTX ctx, kmemshare_t *share)
{
	share->MemoryArenaTBL = (mempageTBL_t*)KNH_MALLOC(ctx, K_ARENATBL_INITSIZE * sizeof(mempageTBL_t));
	knh_bzero(share->MemoryArenaTBL, K_ARENATBL_INITSIZE * sizeof(mempageTBL_t));
	share->sizeMemoryArenaTBL = 0;
	share->capacityMemoryArenaTBL = K_ARENATBL_INITSIZE;
}

void knh_share_freeArena(CTX ctx, kmemshare_t *share)
{
	size_t i;
	for(i = 0; i < share->sizeMemoryArenaTBL; i++) {
		mempageTBL_t *at = share->MemoryArenaTBL + i;
		KNH_FREE(ctx, at->head, K_MEMSIZE(at->bottom, at->head));
	}
	KNH_FREE(ctx, share->MemoryArenaTBL, share->capacityMemoryArenaTBL * sizeof(mempageTBL_t));
	share->MemoryArenaTBL = NULL;
}

void knh_initFirstObjectArena(CTX ctx)
{
	ctx->stat->gcObjectCount -= K_GC_MARGIN;
	ctx->stat->latestGcTime = knh_getTimeMilliSecond();
	((kcontext_t*)ctx)->memlocal->freeObjectList = (kObjectUnused *) BMGC_init(ctx);
}

kbool_t knh_isObject(CTX ctx, kObject *o)
{
	HeapManager *mng = (HeapManager*) GCDATA(ctx);

	size_t i;
	if ((uintptr_t) o % KlassBlockSize(SUBHEAP_KLASS_MIN) != 0)
		return false;
	FOR_EACH_ARRAY_(mng->managed_heap_a, i) {
		kObject *s = (kObject *) ARRAY_n(mng->managed_heap_a, i);
		kObject *e = (kObject *) ARRAY_n(mng->managed_heap_end_a, i);
		if (s < o && o < e) {
			Segment *seg;
			uintptr_t klass, index;
			OBJECT_LOAD_BLOCK_INFO(o, seg, index, klass);
			DBG_ASSERT((uintptr_t) o % KlassBlockSize(klass) == 0);
			uintptr_t bpidx, bpmask;
			BITPTR_INIT_(bpidx, bpmask, index);
			bitmap_t *bm = SEG_BITMAP_N(seg, 0, bpidx);
			if (BM_TEST(*bm, bpmask)) {
				return true;
			}
		}
	}
	return false;
}

/* ------------------------------------------------------------------------ */


static inline void bmgc_Object_free(CTX ctx, kObject *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if (ct) {
		MEMLOG(ctx, "~Object", K_NOTICE, KNH_LDATA(LOG_p("ptr", o), LOG_u("size", ct->cid)));
		//gc_info("~Object ptr=%p, cid=%d, o->h.meta=%p", o, ct->cid, o->h.meta);
		if(unlikely(Object_isXData(o))) {
			knh_PtrMap_rm(ctx, ctx->share->xdataPtrMap, o);
			Object_setXData(o, 0);
		}
		ct->cdef->free(ctx, RAWPTR(o));
		//ctx->stat->gcObjectCount += 1;
		K_OZERO(o);
		STAT_dObject(ctx, ct);
		setYoung(o);
#ifdef GCSTAT
		Segment *seg;
		uintptr_t klass;
		OBJECT_TO_SEG_AND_KLASS(o, seg, klass);
		//DBG_P("Object: %p, Segment: %p, klass: %lu, block: %p, seg->klass: %d", o, seg, klass, seg->blk, seg->heap_klass);
		DBG_ASSERT(seg != NULL);
		global_gc_stat.collected[seg->heap_klass] += 1;
#endif
	}
}

static bool stop_the_world(CTX ctx)
{
	return true;
}

static bool start_the_world(CTX ctx)
{
	return true;
}

/* ------------------------------------------------------------------------ */
#define CONTEXT_REFINIT(ctx) \
	WCTX(ctx)->memlocal->refs = ctx->memlocal->ref_buf;\
WCTX(ctx)->memlocal->ref_size = 0;

#define GCLOCK(ctx)
#define GCUNLOCK(ctx)

#define gc_init(ctx, mng)   bmgc_gc_init(ctx, mng, isTenure)
#define gc_mark(ctx, mng, trace) bmgc_gc_mark(ctx, mng, trace, isTenure)
#define gc_sweep(ctx, mng)  bmgc_gc_sweep(ctx, mng, isTenure)

void knh_System_gc(CTX ctx, int needsCStackTrace, int isTenure)
{
	kstatinfo_t *ctxstat = ctx->stat;
	size_t avail = ctx->memlocal->freeObjectListSize;
	kuint64_t start_time = knh_getTimeMilliSecond(), mark_time = 0, intval;
	if(stop_the_world(ctx)) {
#ifdef K_USING_CTRACE
		knh_dump_cstack(ctx);
#endif
		gc_init(ctx, (HeapManager *)GCDATA(ctx));
		gc_mark(ctx, (HeapManager *)GCDATA(ctx), needsCStackTrace);
		//gc_move(ctx, needsCStackTrace);
		mark_time = knh_getTimeMilliSecond();
		start_the_world(ctx);
	}
	gc_sweep(ctx, (HeapManager *)GCDATA(ctx));
	intval = start_time - ctxstat->latestGcTime;
	//	if(knh_isVerboseGC()) {
	//		STAT_(
	GC_LOG("GC(%dMb): marked=%lu, collected=%lu, avail=%lu=>%lu, interval=%dms, marking_time=%dms, sweeping_time=%dms",
			ctxstat->usedMemorySize/ MB_,
			ctxstat->markedObject, ctxstat->collectedObject,
			avail, ctx->memlocal->freeObjectListSize,
			(int)(intval), (int)(mark_time-start_time));
	//		)
	//	}
	//STAT_(KNH_ASSERT(ctxstat->markedObject == ctxstat->usedObjectSize);)
	//MSGC_(if(ctxstat->gcObjectCount < K_ARENASIZE/sizeof(kObject)) {
	//	MSGC_(if(!(ctxstat->usedObjectSize < ((ctxstat->gcBoundary * 3) / 4))) { /* 75%*/
	//		gc_extendObjectArena(ctx);
	//	})
	ctxstat->gcCount++;
	ctxstat->markingTime += (mark_time-start_time);
	ctxstat->latestGcTime = knh_getTimeMilliSecond();
	ctxstat->gcTime += (ctxstat->latestGcTime - start_time);
}

#ifdef __cplusplus
}
#endif
