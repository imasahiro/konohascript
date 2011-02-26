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

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__i386__)
#define reg(r) "%%e" r
#elif defined(__x86_64__)
#define reg(r) "%%r" r
#endif
/*
 * we verified setjmp, longjmp at 
 *  * MacOSX x86_64 GCC 4.0.1/4.2.1 (-O0/-O1/-O2)
 *  * MacOSX i386   GCC 4.0.1 (-O2)
 */

/* ------------------------------------------------------------------------ */
knh_ExceptionHandler_t* ExceptionHandler_setjmp(CTX ctx, knh_ExceptionHandler_t *hdr)
{
#if defined(__GNUC__)
	knh_uintptr_t rsp;
	asm volatile ("mov " reg("sp") ", %0;" : "=r" (rsp));
	DP(hdr)->return_address = __builtin_return_address(0);
	DP(hdr)->frame_address = __builtin_frame_address(1);
#if defined(__i386__)
	DP(hdr)->stack_pointer = rsp + 0x08;
#elif defined(__x86_64__)
	DP(hdr)->stack_pointer = rsp + 0x10;
#endif
#endif
	return NULL;
}

/* ------------------------------------------------------------------------ */
knh_ExceptionHandler_t *knh_ExceptionHandler_longjmp(CTX ctx, knh_ExceptionHandler_t *hdr)
{
#if defined(__GNUC__)
#if defined(__i386__)
	asm volatile(
			"pop %%ebp;"
			"mov 0x10(%%eax),%%esi;" /* esi = DP(hdr) */
			"mov 0x08(%%esi),%%edx;" /* edx = DP(hdr)->return_address */
			"mov 0x0c(%%esi),%%ebp;" /* ebp = DP(hdr)->frame_address */
			"mov 0x10(%%esi),%%esp;" /* esp = DP(hdr)->stack_pointer */
			"pop %%esi;"
			"jmp *%%edx;"
			::
			"a"(hdr)
			: "%esi", "%edx");
#elif defined(__x86_64__)
	asm volatile(
			"pop %%rbp;"
			"mov %0,%%rsi;"
			"mov %%rsi,%%rbp;"
			"mov %2,%%rsp;"
			"mov %3,%%rax;"
			"mov %4, %%rsi;"
			"mov %%rsi, %%rdi;"
			"jmp *%1;"
			::
			"r"(DP(hdr)->frame_address),
			"r"(DP(hdr)->return_address),
			"r"(DP(hdr)->stack_pointer),
			"r"(hdr),
			"r"(ctx)
			: "%rax", "%rsi", "%rdi");
#endif
#endif
	return hdr;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
