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

#include "commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

void *knh_malloc(CTX ctx, size_t size)
{
	void *block = malloc(size);
	MEMLOG("malloc", "ptr=%p, size=%lu", block, size);
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	STAT_mem(ctx, size);
	return block;
}

void knh_free(CTX ctx, void *block, size_t size)
{
	MEMLOG("free", "ptr=%p, size=%lu", block, size);
	free(block);
	STAT_dmem(ctx, size);
}

void *knh_valloc(CTX ctx, size_t size)
{
#if defined(HAVE_POSIX_MEMALIGN)
	void *block = NULL;
	int ret = posix_memalign(&block, K_PAGESIZE, size);
	MEMLOG("valloc", "ptr=%p, size=%lu", block, size);
	if(ret != 0) {
		THROW_OutOfMemory(ctx, size);
	}
	STAT_mem(ctx, size);
	return block;
#elif defined(HAVE_MEMALIGN)
	void *block = memalign(K_PAGESIZE, size);
	MEMLOG("valloc", "ptr=%p, size=%lu", block, size);
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	return block;
#elif defined(K_USING_WINDOWS_)
	void *block = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	MEMLOG("valloc", "ptr=%p, size=%lu", block, size);
	if (unlikely(block == NULL)) {
		THROW_OutOfMemory(ctx, size);
	}
	return block;
#else
	void *block = malloc(size + K_PAGESIZE);
	MEMLOG("valloc", "ptr=%p, size=%lu", block, size);
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
	MEMLOG("vfree", "ptr=%p, size=%lu", block, size);
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

/* ------------------------------------------------------------------------ */
//typedef void knh_gcinfo_t;

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

static void ObjectPage_init(objpage_t *opage)
{
	size_t i;
	kObjectUnused *o = opage->slots;
	for(i = 0; i < K_PAGEOBJECTSIZE - 1; i++) {
		DBG_ASSERT(K_OPAGE(opage->slots + i) == opage);
		o[i].h.cTBL = NULL;
		o[i].ref = &(o[i+1]);
	}
	opage->slots[K_PAGEOBJECTSIZE-1].h.cTBL = NULL;
	opage->slots[K_PAGEOBJECTSIZE-1].ref = opage[1].slots;
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

static void knh_fastmemset(void *p, size_t n, kintptr_t M)
{
	size_t i, size = n / sizeof(kintptr_t);
	kintptr_t *np = (kintptr_t*)p;
	for(i = 0; i < size; i+=8) {
		np[0] = M; np[1] = M; np[2] = M; np[3] = M;
		np[4] = M; np[5] = M; np[6] = M; np[7] = M;
		np += 8;
	}
}

static void ObjectArenaTBL_init(CTX ctx, objpageTBL_t *oat, size_t arenasize)
{
	size_t object_count, bitmapsize = (arenasize/sizeof(kObjectUnused));
	objpage_t *opage = (objpage_t*)KNH_VALLOC(ctx, arenasize);
	kuintptr_t *bitmap = (kuintptr_t*)KNH_MALLOC(ctx, bitmapsize * K_NBITMAP);
	KNH_ASSERT((kuintptr_t)opage % K_PAGESIZE == 0);
	oat->head =   opage;
	oat->bottom = (objpage_t*)K_SHIFTPTR(opage, arenasize);
	oat->bitmap = bitmap;
	oat->arenasize = arenasize;
	oat->bitmapsize = bitmapsize;
	oat->tenure = (kuintptr_t*)K_SHIFTPTR(bitmap, bitmapsize);
	knh_fastmemset(oat->tenure, bitmapsize, ((kintptr_t)-1));
	object_count = (oat->bottom - oat->head);
	//knh_mlock(oat->bitmap, bitmapsize * K_NBITMAP);
	for(; opage < oat->bottom; opage++) {
		opage->h.bitmap = bitmap;
		opage->h.tenure = (kuintptr_t*)K_SHIFTPTR(bitmap, bitmapsize);
		bitmap += (K_PAGESIZE/sizeof(kObjectUnused))/sizeof(kuintptr_t);
		opage->h.ctx = NULL;
		ObjectPage_init(opage);
	}
	(opage-1)->slots[K_PAGEOBJECTSIZE - 1].ref = NULL;

	DBG_ASSERT((bitmap - oat->bitmap) * sizeof(kuintptr_t) == arenasize/sizeof(kObjectUnused));
	ctx->stat->gcObjectCount += (object_count * K_PAGEOBJECTSIZE);
	DBG_(ObjectArenaTBL_checkSize(oat, arenasize, object_count););
}

static kObjectUnused *new_ObjectArena(CTX ctx, size_t arenasize)
{
	OLD_LOCK(ctx, LOCK_MEMORY, NULL);
	objpageTBL_t *oat;
	kmemshare_t *memshare = ctx->memshare;
	size_t pageindex = memshare->sizeObjectArenaTBL;
	if(unlikely(!(pageindex < memshare->capacityObjectArenaTBL))) {
		size_t newsize = memshare->capacityObjectArenaTBL * 2;
		memshare->ObjectArenaTBL = (objpageTBL_t*)KNH_REALLOC(ctx, "ObjectArenaTBL", memshare->ObjectArenaTBL, memshare->capacityObjectArenaTBL, newsize, sizeof(objpageTBL_t));
		memshare->capacityObjectArenaTBL = newsize;
	}
	memshare->sizeObjectArenaTBL += 1;
	OLD_UNLOCK(ctx, LOCK_MEMORY, NULL);
	DBG_ASSERT(sizeof(objpage_t) == K_PAGESIZE);
	oat = &memshare->ObjectArenaTBL[pageindex];
	ObjectArenaTBL_init(ctx, oat, arenasize);
	GC_LOG("Allocated object arena id=%d region=(%p-%p), %d objects", pageindex, oat->head, oat->bottom, ((oat->bottom - oat->head) * K_PAGEOBJECTSIZE));
	{
		kObjectUnused *p = oat->head->slots;
		p->ref4_tail = &(((kObjectUnused*)(oat->bottom))[-1]);
		return p;
	}
}

kbool_t knh_isObject(CTX ctx, kObject *o)
{
	void *ptr = (void*) o;
	kuintptr_t n = (kuintptr_t)ptr;
	if(ptr != NULL && n % sizeof(kObjectUnused) == 0) {
		size_t i, size = ctx->memshare->sizeObjectArenaTBL;
		objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
		for(i = 0; i < size; i++) {
			if((void*)oat[i].head < ptr && ptr < (void*)oat[i].bottom) return 1;
		}
	}
	return 0;
}

static void knh_Object_finalfree(CTX ctx, kObjectUnused *o);

static void knh_ObjectObjectArenaTBL_free(CTX ctx, const objpageTBL_t *oat)
{
	objpage_t *opage = oat->head;
	while(opage < oat->bottom) {
		size_t i;
		for(i = 0; i < K_PAGEOBJECTSIZE; i++) {
			kObjectUnused *o = &opage->slots[i];
			if(O_cTBL(o) == NULL) continue;
			knh_Object_finalfree(ctx, o);
		}
		opage++;
	}
}

static void knh_ObjectArena_finalfree(CTX ctx, objpageTBL_t *oat, size_t oatSize)
{
	size_t i;
	DBG_ASSERT(oat != NULL);
	for(i = 0; i < oatSize; i++) {
		objpageTBL_t *t = oat + i;
		knh_ObjectObjectArenaTBL_free(ctx, t);
	}
}

static kObjectUnused* getMemBlock(CTX ctx, size_t mbsize);
static void xmem_freeall(CTX ctx);

void kmemshare_init(CTX ctx)
{
	WCTX(ctx)->memshare = (kmemshare_t*)KNH_MALLOC(ctx, sizeof(kmemshare_t));
	knh_bzero(ctx->memshare, sizeof(kmemshare_t));
	ctx->memshare->memlock = knh_mutex_malloc(ctx);
	initArena(ctx, ctx->memshare);
	kmemlocal_init(ctx);
	{
		kObjectUnused *p = getMemBlock(ctx, K_ARENASIZE);
		WCTX(ctx)->memlocal->freeObjectList = p;
		WCTX(ctx)->memlocal->freeObjectTail = p->ref4_tail;
		ctx->stat->gcObjectCount -= K_GC_MARGIN; // important
		ctx->stat->latestGcTime = knh_getTimeMilliSecond();
	}
}

void kmemshare_free(CTX ctx)
{
	xmem_freeall(ctx);
	knh_ObjectArena_finalfree(ctx, ctx->memshare->ObjectArenaTBL, ctx->memshare->sizeObjectArenaTBL);
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
		GC_LOG("Allocated MemoryArena id=%d region=(%p-%p)", pageindex, at->head, at->bottom);
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
		MEMLOG("fastmalloc", "ptr=%p, size=%lu", m, size);
		return (void*)m;
	}
	else {
		void *block = malloc(size);
		MEMLOG("fastmalloc", "ptr=%p, size=%lu", block, size);
		if (unlikely(block == NULL)) {
			THROW_OutOfMemory(ctx, size);
		}
		STAT_mem(ctx, size);
		return block;
	}
}

void knh_fastfree(CTX ctx, void *block, size_t size)
{
	MEMLOG("fastfree", "ptr=%p, size=%lu", block, size);
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
		MEMLOG("fastrealloc", "ptr=%p, size=%lu, newptr=%p, newsize=%lu", block, oldsize, newblock, newsize);
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
		MEMLOG("fastrealloc", "ptr=%p, size=%lu, newptr=%p, newsize=%lu", block, oldsize, newblock, newsize);
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
//#define DBG_CHECK_UNOBJECT(ctx) DBG_ASSERT(ctx->freeObjectListSize == 0)
//#define DBG_UNOBJinc(ctx, N) WCTX(ctx)->freeObjectListSize += N
//#define DBG_UNOBJdec(ctx, N) WCTX(ctx)->freeObjectListSize -= N

#ifndef K_USING_BMGC
static void DBG_checkOnArena(CTX ctx, void *used K_TRACEARGV)
{
	size_t i, size = ctx->memshare->sizeObjectArenaTBL;
	objpageTBL_t *t = ctx->memshare->ObjectArenaTBL;
	for(i = 0; i < size; i++) {
		if((void*)t->head <= used && used < (void*)t->bottom) return;
		t++;
	}
	TRACE_P("not paged object %p", used);
}
#endif

#else/*K_USING_DEBUG*/
#define DBG_CHECK_ONARENA(ctx, p)
//#define DBG_CHECK_UNOBJECT(ctx)
//#define DBG_UNOBJinc(ctx, N)
//#define DBG_UNOBJdec(ctx, N)
#endif

#ifndef K_USING_BMGC
#define K_MEMBLOCKPAGE			64
#define K_MEMBLOCKSIZE			(K_MEMBLOCKPAGE * K_PAGESIZE)
#define GET_PAGECTX(page)		((kcontext_t *)((page)->h.ctx))
#define SET_PAGECTX(page, ctx1)	(page)->h.ctx = (void *)(ctx1)

static kObjectUnused* getMemBlock(CTX ctx, size_t mbsize)
{
	KNH_MEMLOCK(ctx);
	objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
	objpage_t *page;
	size_t i, arenasize = ctx->memshare->sizeObjectArenaTBL;
	for(i = 0; i < arenasize; i++) {
		objpage_t *bottom = oat[i].bottom;
		for(page = oat[i].head; page < bottom; page += K_MEMBLOCKPAGE) {
			if(GET_PAGECTX(page) == NULL) {
				goto SETFLAG;
			}
		}
	}
	page = K_OPAGE(new_ObjectArena(ctx, K_ARENASIZE));
	SETFLAG:
	for(i=0; i<K_MEMBLOCKPAGE; i++) SET_PAGECTX(page + i, ctx);
	KNH_MEMUNLOCK(ctx);
	kObjectUnused *p = page->slots;
	p->ref4_tail = &(((kObjectUnused*)((page + K_MEMBLOCKPAGE)))[-1]);
	p->ref4_tail->ref = NULL;
	WCTX(ctx)->memlocal->freeObjectListSize += K_PAGEOBJECTSIZE * K_MEMBLOCKPAGE;
	return p;
}
#endif

#define CHECK_UNUSED_OBJECT(ctx) { \
		if(ctx->memlocal->freeObjectList == NULL) { \
			kObjectUnused *p = getMemBlock(ctx, K_MEMBLOCKSIZE);\
			WCTX(ctx)->memlocal->freeObjectList = p; \
			WCTX(ctx)->memlocal->freeObjectTail = p->ref4_tail;\
		} \
		DBG_CHECK_ONARENA(ctx, ctx->memlocal->freeObjectList);\
	} \

#define FREELIST_POP(o) {\
		o = ctx->memlocal->freeObjectList;\
		WCTX(ctx)->memlocal->freeObjectList = (o)->ref;\
		prefetch(o->ref);\
		/*TODO(imasahiro) measure GC performance */\
		o->ref = NULL;\
		/*DBG_UNOBJdec(ctx ,1);*/\
	}\

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

#define OBJECT_REUSE(used) { \
		DBG_CHECK_ONARENA(ctx, used);\
		K_OZERO(used);\
		FREELIST_PUSH(used);\
	}\

/* ------------------------------------------------------------------------ */
/* [hObject] */


kObject *new_hObject_(CTX ctx, const knh_ClassTBL_t *ct)
{
	kObjectUnused *o = NULL;
	CHECK_UNUSED_OBJECT(ctx);
	FREELIST_POP(o);
	prefetch_tenure(o);
	o->h.magicflag = ct->magicflag;
	knh_Object_RCset(o, K_RCGC_INIT);
	o->h.cTBL = ct;
	O_unset_tenure(o); // collectable
	WCTX(ctx)->memlocal->freeObjectListSize -= 1;
	if(ctx->memlocal->freeObjectListSize == 0) {
		SAFEPOINT_SETGC(ctx);
	}
	STAT_Object(ctx, ct);
	MEMLOG("new", "ptr=%p, cid=%d", o, ct->cid);
	return (kObject*)o;
}

kObject *new_Object_init2(CTX ctx, const knh_ClassTBL_t *ct)
{
	kObjectUnused *o = NULL;
	CHECK_UNUSED_OBJECT(ctx);
	FREELIST_POP(o);
	o->h.magicflag = ct->magicflag;
	knh_Object_RCset(o, K_RCGC_INIT);
	o->h.cTBL = ct;
	ct->cdef->init(ctx, RAWPTR(o));
	O_unset_tenure(o); // collectable
	WCTX(ctx)->memlocal->freeObjectListSize -= 1;
	if(ctx->memlocal->freeObjectListSize == 0) {
		SAFEPOINT_SETGC(ctx);
	}
	STAT_Object(ctx, ct);
	MEMLOG("new", "ptr=%p, cid=%d", o, ct->cid);
	return (kObject*)o;
}

void TR_NEW(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	kObjectUnused *o = NULL;
	CHECK_UNUSED_OBJECT(ctx);
	FREELIST_POP(o);
	o->h.magicflag = ct->magicflag;
	knh_Object_RCset(o, K_RCGC_INIT);
	o->h.cTBL = ct;
	ct->cdef->init(ctx, RAWPTR(o));
	O_unset_tenure(o); // collectable
	WCTX(ctx)->memlocal->freeObjectListSize -= 1;
	if(ctx->memlocal->freeObjectListSize == 0) {
		SAFEPOINT_SETGC(ctx);
	}
	STAT_Object(ctx, ct);
	MEMLOG("new", "ptr=%p, cid=%d", o, ct->cid);
	KNH_SETv(ctx, sfp[c].o, o);
}

/* ------------------------------------------------------------------------ */

static void knh_Object_finalfree(CTX ctx, kObjectUnused *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	RCGC_(DBG_ASSERT(Object_isRC0(o)));
	MEMLOG("~Object", "ptr=%p, cid=%d", o, ct->cid);
	if(Object_isXData(o)) {
		knh_PtrMap_rm(ctx, ctx->share->xdataPtrMap, o);
		Object_setXData(o, 0);
	}
	ct->cdef->free(ctx, RAWPTR(o));
	OBJECT_REUSE(o);
	WCTX(ctx)->memlocal->freeObjectListSize += 1;
	STAT_dObject(ctx, ct);
	O_set_tenure(o); // uncollectable
}

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
#elif defined(K_USING_BMGC)
#include "bmgc.c"
#else


/* ------------------------------------------------------------------------ */

//#define BSHIFT ((K_PAGESIZE / sizeof(kObject)) / (sizeof(kuintptr_t) * 8))

static inline int bit_test_and_set(kuintptr_t *b, size_t offset)
{
	int x = INDEX2OFFSET(offset);
	kuintptr_t mask = INDEX2MASK(offset);
	if (!(b[x] & mask)) {
		b[x] |= mask;
		return 0;
	}
	return 1;
}

static void gc_init(CTX ctx)
{
	objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
	size_t atindex, size = ctx->memshare->sizeObjectArenaTBL;
	for(atindex = 0; atindex < size; atindex++) {
		knh_memcpy(oat->bitmap, oat->tenure, oat->bitmapsize);
		oat++;
	}
	STAT_(ctx->stat->markedObject = 0;)
}

static void mark_ostack(CTX ctx, kObject *ref, knh_ostack_t *ostack)
{
	objpage_t *opage = K_OPAGE(ref);
	prefetch(opage);
	size_t n = K_OPAGEOFFSET(ref, opage);
	kuintptr_t *b = opage->h.bitmap;
	if(!(bit_test_and_set(b, n))) {
		STAT_(ctx->stat->markedObject++;)
		if(O_hasRef(ref)) {
			ostack_push(ctx, ostack, ref);
		}
	}
}

#define CONTEXT_REFINIT(ctx) \
	WCTX(ctx)->memlocal->refs = ctx->memlocal->ref_buf;\
	WCTX(ctx)->memlocal->ref_size = 0;

static void gc_mark(CTX ctx, int needsCStackTrace)
{
	long i;
	knh_ostack_t ostackbuf, *ostack = ostack_init(ctx, &ostackbuf);
	kObject *ref = NULL, **reftail = NULL;

	knh_ensurerefs(ctx, ctx->memlocal->ref_buf, K_PAGESIZE);
	CONTEXT_REFINIT(ctx);
	reftail = knh_reftraceRoot(ctx, ctx->memlocal->refs);
	if (unlikely(needsCStackTrace)) {
		cstack_mark(ctx, reftail);
	}
	//fprintf(stderr, "%s first refs %ld\n", __FUNCTION__, ctx->memlocal->ref_size);
	goto L_INLOOP;
	while((ref = ostack_next(ostack)) != NULL) {
		const knh_ClassTBL_t *ct = O_cTBL(ref);
		DBG_ASSERT(O_hasRef(ref));
		CONTEXT_REFINIT(ctx);
		ct->cdef->reftrace(ctx, RAWPTR(ref), ctx->memlocal->refs);
		if(ctx->memlocal->ref_size > 0) {
			L_INLOOP:;
			prefetch(ctx->memlocal->refs[0]);
			for(i = ctx->memlocal->ref_size - 1; i >= 0; --i) {
				mark_ostack(ctx, ctx->memlocal->refs[i], ostack);
			}
		}
	}
	ostack_free(ctx, ostack);
}

static void gc_move(CTX ctx, int needsCStackTrace)
{
	// yoan
}

static inline void Object_MSfree(CTX ctx, kObjectUnused *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	MEMLOG("~Object", "ptr=%p, cid=%d", o, ct->cid);
	if(unlikely(Object_isXData(o))) {
		knh_PtrMap_rm(ctx, ctx->share->xdataPtrMap, o);
		Object_setXData(o, 0);
	}
	ct->cdef->free(ctx, RAWPTR(o));
	OBJECT_REUSE(o);
	WCTX(ctx)->memlocal->freeObjectListSize += 1;
	STAT_dObject(ctx, ct);
	O_set_tenure(o); // uncollectable
}

static void gc_extendMemBlock(CTX ctx)
{
	kObjectUnused *block = getMemBlock(ctx, K_MEMBLOCKSIZE);
	kObjectUnused *tail = block->ref4_tail;
	tail->ref = ctx->memlocal->freeObjectList;
	WCTX(ctx)->memlocal->freeObjectList = block;
}

#if !defined(__GNUC__) || !defined(HAVE_BUILTIN_CTZLL)
static void gc_sweep(CTX ctx)
{
	objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
	size_t collected=0, moved = 0, atindex, size = ctx->memshare->sizeObjectArenaTBL;
	size_t listSize = 0;
	(void)moved;
	for(atindex = 0; atindex < size; atindex++) {
		objpage_t *opage = oat[atindex].head;
		for(;opage < oat[atindex].bottom; opage++) {
			if(ctx == GET_PAGECTX(opage)) {
				kuintptr_t i, *b = opage->h.bitmap;
				for(i = 1; i <= K_PAGEOBJECTSIZE; i++) {
					kObjectUnused *o = &opage->slots[i-1];
					if(!bit_test(b, (i))) {
						//prefetch(o);
						Object_MSfree(ctx, o);
						collected++;
					}
				}
			}
		}
	}
	if(ctx->memlocal->freeObjectListSize < listSize / 4) { // 75%
		gc_extendMemBlock(ctx);
	}
	STAT_(
		ctx->stat->collectedObject = collected;
		ctx->stat->movedObject = moved;
	)
}

#else/*GNUC*/

#define CLEAR(b,n)     (b &= ~(INDEX2MASK(n)))
#ifndef CTZ
#define CTZ(x)    __builtin_ctzl(x)
#endif

static void gc_sweep(CTX ctx)
{
	objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
	size_t collected = 0, moved = 0, atindex, size = ctx->memshare->sizeObjectArenaTBL;
	size_t listSize = 0;
	(void)moved;
	for(atindex = 0; atindex < size; atindex++) {
		objpage_t *opage, *bottom = oat[atindex].bottom;
		for (opage = oat[atindex].head; opage < bottom; opage++) {
			kuintptr_t i, *bitmap = opage->h.bitmap;
			if(GET_PAGECTX(opage) == ctx) {
				listSize += K_PAGEOBJECTSIZE;
				for(i = 0; i <= K_PAGEOBJECTSIZE/UINTPTR8; i++) {
					kuintptr_t b = ~bitmap[i];
					while (b != 0) {
						kuintptr_t n = CTZ(b);
						register kObjectUnused *o = &(opage->slots[i * UINTPTR8 + n - 1]);
						Object_MSfree(ctx, o);
						collected++;
						CLEAR(b, n);
					}
				}
			}
		}
	}
	if(ctx->memlocal->freeObjectListSize < listSize/4) { // 75%
		gc_extendMemBlock(ctx);
		listSize += K_PAGEOBJECTSIZE * K_MEMBLOCKPAGE;
	}
	STAT_(
		ctx->stat->collectedObject = collected;
		ctx->stat->movedObject = moved;
	)
}
#endif

//#ifndef K_USING_RCGC
//static void gc_extendObjectArena(CTX ctx)
//{
//	kshare_t *ctxshare = (kshare_t*) ctx->share;
//	objpageTBL_t *oat = ctxshare->ObjectArenaTBL + (ctxshare->sizeObjectArenaTBL - 1);
//	size_t arenasize = oat->arenasize;
//	kuint64_t stime = knh_getTimeMilliSecond();
////	const knh_sysinfo_t *sysinfo = knh_getsysinfo();
////	size_t max = (sysinfo->hw_usermem > 0) ? sysinfo->hw_usermem / 20 : 64 * (1024 * 1024);
////	if(arenasize <= max) arenasize *= 2;
//	kObject *newobj = getMemBlock(ctx, arenasize);
//	kObject *p = ctx->freeObjectList;
//	if(p == NULL) {
//		WCTX(ctx)->freeObjectList = newobj;
//		WCTX(ctx)->memlocal->freeObjectTail = newobj->ref4_tail;
//	}
//	else {
//		p = ctx->memlocal->freeObjectTail;
//		p->ref = newobj;
//		WCTX(ctx)->memlocal->freeObjectTail = newobj->ref4_tail;
//	}
//	GC_LOG("extendObjectArena: id=%d newarena=%luMb, used_memory=%luMb extending_time=%dms",
//			(int)(ctx->share->sizeObjectArenaTBL - 1),
//			(arenasize / MB_), (ctx->stat->usedMemorySize / MB_),
//			(int)(knh_getTimeMilliSecond()-stime));
//}
//#endif

static void gc_freeMemBlock(CTX ctx, kcontext_t *deadCtx)
{
	objpageTBL_t *oat = ctx->memshare->ObjectArenaTBL;
	size_t collected=0, moved = 0, atindex, size = ctx->memshare->sizeObjectArenaTBL;
	(void)collected;
	(void)moved;
	for(atindex = 0; atindex < size; atindex++) {
		objpage_t *opage = oat[atindex].head;
		for(;opage < oat[atindex].bottom; opage++) {
			if(deadCtx == GET_PAGECTX(opage)) {
				SET_PAGECTX(opage, ctx);
			}
		}
	}
}

static void gc_freeCtx(CTX ctx)
{
	int i;
	kshare_t *share = ctx->wshare;
	for(i = knh_Array_size(share->contextListNULL) - 1; i >= 0; i--) {
		kcontext_t *c = WCTX(((kContext *)knh_Array_n(share->contextListNULL, i))->ctx);
		if(!IS_RUNNING(c)) {
			gc_freeMemBlock(ctx, c);
			knh_Context_free(ctx, c);
			knh_Array_remove(ctx, share->contextListNULL, i);
		}
	}
}

static int stop_the_world(CTX ctx)
{
	kshare_t *share = ctx->wshare;
	KNH_SYSLOCK(ctx);
	if(share->gcStopCounter == 0) {
		size_t i, size = knh_Array_size(share->contextListNULL);
		share->gcStopCounter = 1;
		share->stopCounter++;
		if(size > 1) {
			for(i = 0; i < size; i++) {
				kContext *c = (kContext *)knh_Array_n(share->contextListNULL, i);
				if(ctx != c->ctx) {
					SAFEPOINT_SETGC(c->ctx);
				}
			}
			gc_freeCtx(ctx);
			while(share->stopCounter != share->threadCounter) {
				kthread_cond_wait(share->start_cond, share->syslock);
			}
		}
		return 1;
	}else{
		share->stopCounter++;
		share->gcStopCounter++;
		if(share->stopCounter == share->threadCounter) {
			kthread_cond_signal(share->start_cond);
		}
		kthread_cond_wait(share->stop_cond, share->syslock);
		KNH_SYSUNLOCK(ctx);
		return 0;
	}
}

static void start_the_world(CTX ctx)
{
	ctx->wshare->stopCounter -= ctx->share->gcStopCounter;
	ctx->wshare->gcStopCounter = 0;
	kthread_cond_broadcast(ctx->share->stop_cond);
	KNH_SYSUNLOCK(ctx);
}
#endif /* K_USING_BMGC */


#define GCLOCK(ctx)
#define GCUNLOCK(ctx)

void knh_System_gc(CTX ctx, int needsCStackTrace)
{
	kstatinfo_t *ctxstat = ctx->stat;
	size_t avail = ctx->memlocal->freeObjectListSize;
	kuint64_t start_time = knh_getTimeMilliSecond(), mark_time = 0, sweep_time= 0, intval;
	if(stop_the_world(ctx)) {
#ifdef K_USING_CTRACE
		knh_dump_cstack(ctx);
#endif
		gc_init(ctx);
		gc_mark(ctx, needsCStackTrace);
		gc_move(ctx, needsCStackTrace);
		mark_time = knh_getTimeMilliSecond();
		start_the_world(ctx);
	}
	gc_sweep(ctx);
	sweep_time = knh_getTimeMilliSecond();
	intval = start_time - ctxstat->latestGcTime;
//	if(knh_isVerboseGC()) {
//		STAT_(
		GC_LOG("GC(%dMb): marked=%lu, collected=%lu, avail=%lu=>%lu, interval=%dms, marking_time=%dms, sweeping_time=%dms",
				ctxstat->usedMemorySize/ MB_,
				ctxstat->markedObject, ctxstat->collectedObject,
				avail, ctx->memlocal->freeObjectListSize,
				(int)(intval), (int)(mark_time-start_time), (int)(sweep_time-mark_time));
//		)
//	}
	//STAT_(KNH_ASSERT(ctxstat->markedObject == ctxstat->usedObjectSize);)
	//MSGC_(if(ctxstat->gcObjectCount < K_ARENASIZE/sizeof(kObject)) {
//	MSGC_(if(!(ctxstat->usedObjectSize < ((ctxstat->gcBoundary * 3) / 4))) { /* 75%*/
//		gc_extendObjectArena(ctx);
//	})
	ctxstat->gcCount++;
	ctxstat->markingTime += (mark_time-start_time);
	ctxstat->sweepingTime += (sweep_time-mark_time);
	ctxstat->latestGcTime = knh_getTimeMilliSecond();
	ctxstat->gcTime += (ctxstat->latestGcTime - start_time);
}


/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
