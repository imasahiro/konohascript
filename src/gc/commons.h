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

#ifndef COMMONS_H_
#define COMMONS_H_
#define K_INTERNAL  1
#include "../../include/konoha1.h"
#include "../../include/konoha1/inlinelibs.h"

#ifndef EX_SOFTWARE
#define EX_SOFTWARE  70
#endif

#ifdef K_USING_POSIX_
#include <sys/mman.h>
#define knh_mlock(p, size)   mlock(p, size)
#define knh_unmlock(p)       unmlock(p)
#endif

#ifndef knh_mlock
#define knh_mlock(p, size)
#define knh_unmlock(p)
#endif

//#ifdef K_USING_DEBUG
//#define K_USING_CTRACE 1
//#endif

#ifdef K_USING_CTRACE
#define _GNU_SOURCE
#define __USE_GNU
#include <dlfcn.h>
#include <execinfo.h>
#endif

#define KB_   (1024)
#define MB_   (KB_*1024)
#define GB_   (MB_*1024)

#define K_USING_MEMSTAT  1
//#define K_USING_MEMLOG   1

#ifdef K_USING_MEMLOG
//static kuint64_t memlog_start = 0;
//#define MEMLOG_INIT()  memlog_start = knh_getTimeMilliSecond()

#define MEMLOG(ctx, action, pe, ...) KNH_NTRACE2(ctx, action, pe, ## __VA_ARGS__)

#else
//#define MEMLOG_INIT()
#define MEMLOG(ctx, action, pe, ...)
#endif

#define KNH_ATOMIC_ADD(a, b) __sync_add_and_fetch(&(a), b)
#define KNH_ATOMIC_SUB(a, b) __sync_sub_and_fetch(&(a), b)

#ifdef K_USING_MEMSTAT
#define STAT_mem(ctx, SIZE) { \
		kstatinfo_t *stat = ctx->stat;\
		KNH_ATOMIC_ADD(stat->usedMemorySize, (SIZE));\
		if(stat->usedMemorySize > stat->maxMemoryUsage) stat->maxMemoryUsage = stat->usedMemorySize;\
	}\

#define STAT_dmem(ctx, SIZE)   KNH_ATOMIC_SUB((ctx->stat)->usedMemorySize, (SIZE))

#define STAT_Object(ctx, ct) { \
		((knh_ClassTBL_t*)ct)->count += 1; \
		((knh_ClassTBL_t*)ct)->total += 1; \
	}\

#define STAT_dObject(ctx, ct) \
	((knh_ClassTBL_t*)ct)->count -= 1; \


#else
#define STAT_mem(ctx, SIZE)
#define STAT_dmem(ctx, SIZE)
#define STAT_Object(ctx, ct)
#define STAT_dObject(ctx, ct)

#endif

#endif /*COMMONS_H_*/
