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

#include <unistd.h>
#ifndef K_USING_MINGW
#include <sys/mman.h>
#endif
/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_USING_FFIDSL

/* 
 * Generating a wrapper function.
 * Copyright Shinpei Nakata(c)2011
 */


void bough_dumpBinary(unsigned char* ptr, size_t size);

/* ------------------------------------------------------------------------ */
// Memory allocation
// xmalloc freelist. each size is 
#define XBLOCK_SIZE (128)
#define XBLOCK_PAGESIZE (_SC_PAGESIZE)
#define XBLOCK_NUMBER (XBLOCK_PAGESIZE / XBLOCK_SIZE)

static void *knh_xmalloc(CTX ctx, size_t pageNum)
{
	size_t pageSize = sysconf(XBLOCK_PAGESIZE);
	void *block = KNH_VALLOC(ctx, pageSize);
	if (unlikely(block == NULL)) {
		KNH_SYSLOG(ctx, LOG_CRIT, "OutOfMemory",
			"*requested=%dbytes, used=%dbytes", pageNum * pageSize, ctx->stat->usedMemorySize);
	}
	int mret = mprotect(block, pageSize, PROT_READ | PROT_WRITE | PROT_EXEC);
	if (mret != -1) {
		return block;
	}
	return NULL;
}

static inline void knh_xfree(CTX ctx, void* block, size_t size)
{
	knh_vfree(ctx, block, size);
}

typedef struct knh_xblock_t {
	unsigned char *block;
	struct knh_xblock_t *next;
} knh_xblock_t;

static knh_xblock_t* xfreelist = NULL;

static void* get_unused_xblock(CTX ctx)
{
	if (xfreelist->next == NULL) {
		unsigned char *xmem = (unsigned char*)knh_xmalloc(ctx, 1);
		knh_xblock_t *xblks = (knh_xblock_t*)knh_malloc(ctx, XBLOCK_NUMBER * sizeof(knh_xblock_t));
		size_t idx = 0;
		knh_xblock_t *p;
		for (idx = 0; idx < XBLOCK_NUMBER - 1; idx++) {
			p = &(xblks[idx]);
			p->block = xmem[idx * XBLOCK_SIZE];
			p->next = &(p[idx + 1]);
		}
		p[idx].block = xmem[idx * XBLOCK_SIZE];
		p[idx].next = NULL;
		xfreelist->next = p;
	}
	assert(xfreelist->next != NULL);
	knh_xblock_t *ret = xfreelist;
	xfreelist = xfreelist->next;
	return ret;
}


/* ------------------------------------------------------------------------ */
// generator
//  knh_Fmethod : void 

// (eax)
#define MOD_EADDR (0)
// (eax + disp8)
#define MOD_PLUS8 (1)
// (eax + disp32)
#define MOD_PLUS32 (2 )
// $eax
#define MOD_IMD (3 )

// Reg/opcode
#define _EAX (0)
#define _ECX (1)
#define _EDX (2)
#define _EBX (3)
#define _ESP (4)
#define _EBP (5)
#define _ESI (6)
#define _EDI (7)

#define R_EAX (0 << 3)
#define R_ECX (1 << 3)
#define R_EDX (2 << 3)
#define R_EBX (3 << 3)
#define R_ESP (4 << 3)
#define R_EBP (5 << 3)
#define E_ESI (6 << 3)
#define E_EDI (7 << 3)


#define FUNCTION function
#define FIDX fidx

#define WRITE_ASM(MOD, REG, RM) FUNCTION[FIDX++] = (MOD << 6) | (REG << 3) | RM
#define WRITE_HEX(hex) { FUNCTION[FIDX++] = hex; }

void* knh_generateWrapper(CTX ctx, void* callee, int argc, knh_ffiparam_t *argv)
		//knh_xblock_t* knh_generateWrapper(CTX ctx, void* callee, int argc, knh_ffiparam_t *argv)
{
	unsigned char *FUNCTION = (unsigned char*)knh_xmalloc(ctx, 1);
	//  knh_xblock_t *blk = get_unused_xblock(ctx);
	//  unsigned char *function = blk->block;
	size_t fidx = 0;

	// magick word
	WRITE_HEX(0x55);
	WRITE_HEX(0x89);
	WRITE_ASM(MOD_IMD, _ESP, _EBP);
	//  WRITE_ASM(function, fidx, 0x55); // push ebp
	//  WRITE_ASM(function, fidx, 0x89);
	//  WRITE_ASM(function, fidx, (MOD_IMD | L_ESP | R_EBP));

	// incase we use ebp, store it.
	WRITE_HEX(0x53); // push ebx


	// we need stack argc * 8bytes at most
	size_t stacksize = argc * 8;
	// allocate stack (sub esp 0x38)
	WRITE_HEX(0x83);
	WRITE_HEX(0xec);
	WRITE_HEX((unsigned char)(stacksize + 0x8));

	// before going, we need edx to be store;
	// mov edx --> -0x4(ebp)
	WRITE_HEX(0x89); // mov r+disp r
	WRITE_ASM(MOD_PLUS8, _EDX, _EBP);
	WRITE_HEX(0xfc);

	//now, process first argument;
	int i;
	knh_ffiparam_t *t;

	for (i = 0; i < argc; i++) {
		t = &(argv[i]);
		if (t->sfpidx != -1) {
			// if sfpidx == -1, its ret value;
			// prepare ebx (put sfp from edx);
			WRITE_HEX(0x89);
			WRITE_ASM(MOD_IMD, _EDX, _EBX);
			//	  WRITE_ASM(function, fidx, (MOD_IMD) | L_EDX | R_EBX);

			switch(t->type) {
			case CLASS_Int:
				// its 64bit int
				//TODO: we need to call translater, but now, we ignore
				//TODO: assume we cast Int --> int;
				// add ebx[sfp] + sfpidx * 16;
				//		WRITE_ASM(function, fidx, 0x83); //add
				//		WRITE_ASM(function, fidx, MOD_IMD | L_EBX | R_EAX);
				//		WRITE_ASM(function, fidx, (unsigned char)(t->sfpidx * 16));

				// move ivalue(offset is 8);
				//		WRITE_ASM(function, fidx, 0x8b); // mov r+disp, r
				//		WRITE_ASM(function, fidx, MOD_PLUS8 | L_EBX | R_EAX);
				//		WRITE_ASM(function, fidx, 0x8);

				// move eax to local value
				//		WRITE_ASM(function, fidx, 0x89);
				//		WRITE_ASM(function, fidx, (MOD_IMD | L_EAX | R_EBP));
				//		WRITE_ASM(function, fidx, 0xf4);
				break;
			case CLASS_Float:
				WRITE_HEX(0x83);
				WRITE_ASM(MOD_IMD, _EAX, _EBX);
				WRITE_HEX((unsigned char)(t->sfpidx * 16));

				// load fvalue;
				WRITE_HEX(0xdd);// fld 64bit
				WRITE_HEX(0x43);// eax
				WRITE_HEX(0x8); // offset

				// push it to eax;
				WRITE_HEX(0xdd); // fstp : store & pop 64
				WRITE_HEX(0x1c);
				WRITE_HEX(0x24);

				break;
			default:
				break;
			}
		} else continue; // if its ret value
	}

	// now, call foreign function
	// NOT SURE??? since konoha is using FASTCALL,
	// call convension is always Fastcall.

	unsigned char default_disp = 0x8;
	unsigned char disp = 0x0;

	// argc contains ret value. remeber...
	// TODO :only for a single argument...
	for (i = argc - 1; i > 0; i--) {
		// push aruguments on the stack;
		// mov argument to eax!
		// TODO : now, we only consider 32 bit values

		if (argv[i].type == CLASS_Int) {
			function[fidx++] = 0x8b; // mov r+disp r
			function[fidx++] = 0x45; // 0xXX(ebp)
			disp = default_disp + i * 4;
			disp = 0x100 - disp;
			function[fidx++] = disp; // -0x8
			//move to esp
			function[fidx++] = 0x89;
			function[fidx++] = 0x04;
			function[fidx++] = 0x24;
		}
		/*	else if (argv[i].type == CLASS_Float) {
		function[fidx++] = 0xdd; // fstp : store & pop 64
		function[fidx++] = 0x1c; 
		function[fidx++] = 0x20;
		}*/
	}

	//now call.
	// call foreign function
	intptr_t ucallee = (intptr_t)callee;
	intptr_t next_addr = (intptr_t)function + (intptr_t)fidx + 5 /*for call instruction */;
	intptr_t rel = (ucallee > next_addr) ? ucallee - next_addr : next_addr - ucallee;
	rel = -rel;
	intptr_t dst = (intptr_t)function + (intptr_t)fidx;
	unsigned char *src = (unsigned char*)&rel;
	//  function[fidx++] = 0xe8;
	//  function[fidx++] = src[0];
	//  function[fidx++] = src[1];
	//  function[fidx++] = src[2];
	//  function[fidx++] = src[3];

	// absolute call
	src = (unsigned char*)&callee;
	// mov this to eax;
	WRITE_HEX(0xb8); // mov to eax
	WRITE_HEX(src[0]);
	WRITE_HEX(src[1]);
	WRITE_HEX(src[2]);
	WRITE_HEX(src[3]);

	// now call
	WRITE_HEX(0xff);
	WRITE_HEX(0xd0);

	//  function[fidx++] = 0xcc;
	// after calling, restore edx;
	// restore edx;
	//  WRITE_HEX(0x8b);
	//  WRITE_ASM(MOD_PLUS8, _EBP, _EDX);
	//  WRITE_HEX(0xfc);
	function[fidx++] = 0x8b; // mov r r+ disp
	function[fidx++] = 0x55; //(ebp):edx
	function[fidx++] = 0xfc; // -0x4

	if (argv[0].sfpidx == -1) {
		switch(argv[0].type) {
		case CLASS_Int:
			// get return value, and give it to Konoha
			// ret value is on eax;
			// push eax
			function[fidx++] = 0x50; // push eax
			break;
		case CLASS_Float:
			// it is on FPU. we need no concern.
			break;
		}
	}

	// get rix (at 0x8(ebp)) --> eax
	function[fidx++] = 0x8b; // mov
	function[fidx++] = 0x45; // 0xXX(ebp) eax
	function[fidx++] = 0x08; // 8

	//  function[fidx++] = 0xcc; // int3;
	// get edx --> ebx
	function[fidx++] = 0x89; // mov
	function[fidx++] = 0xd3; // edx --> ebx

	// ebx[sfp] + 16 * rix
	// first, 16 * rix = 2^4 * rix
	function[fidx++] = 0xc1; // shl
	function[fidx++] = 0xe0; //eax
	function[fidx++] = 0x4; // 4

	// second, add eax to ebx;
	function[fidx++] = 0x01; // add
	function[fidx++] = 0xc3; // add eax to ebx;

	// now at ebx is pointing to sfp[rix];
	// copy retvalue to sfp[rix].ivalue (offset is 0x8)
	// pop eax;


	// offset is different for each types
	if (argv[0].sfpidx == -1) {
		switch (argv[0].type) {
		case CLASS_Int:
			function[fidx++] = 0x58; // pop eax
			// mov eax --> 0x8(%ebx)
			function[fidx++] = 0x89; // mov r+disp r
			function[fidx++] = 0x43; // eax: ebx
			function[fidx++] = 0x8; // 0x8
			break;
		case CLASS_Float:
			//fstpl 0x8(ebx)
			function[fidx++] = 0xdd;
			function[fidx++] = 0x5b;
			function[fidx++] = 0x8;
			break;
		}
	}

	// from here, closing this function
	// close stack; add 0xXX esp
	function[fidx++] = 0x83;
	function[fidx++] = 0xc4;
	function[fidx++] = (unsigned char)(stacksize + 0x8); // 0x8 is default size

	// restore ebx
	function[fidx++] = 0x5b; // pop ebx
	// pop ebp;
	function[fidx++] = 0x5d; // pop ebp
	// ret $0x4
	function[fidx++] = 0xc2; // ret
	function[fidx++] = 0x4;
	function[fidx++] = 0x0;

	return function;
}

//typedef struct {
//	knh_type_t type;
//	knh_short_t sfpidx;
//	void *conv_func;
//} knh_ffiparam_t;  // for ffi
// sfp: -1 --> return
// sfp: 1+ --> arguments


const char *hex_map[256] = {
  "00","01","02","03","04","05","06","07","08","09","0a","0b","0c","0d","0e","0f",
  "10","11","12","13","14","15","16","17","18","19","1a","1b","1c","1d","1e","1f",
  "20","21","22","23","24","25","26","27","28","29","2a","2b","2c","2d","2e","2f",
  "30","31","32","33","34","35","36","37","38","39","3a","3b","3c","3d","3e","3f",
  "40","41","42","43","44","45","46","47","48","49","4a","4b","4c","4d","4e","4f",
  "50","51","52","53","54","55","56","57","58","59","5a","5b","5c","5d","5e","5f",
  "60","61","62","63","64","65","66","67","68","69","6a","6b","6c","6d","6e","6f",
  "70","71","72","73","74","75","76","77","78","79","7a","7b","7c","7d","7e","7f",
  "80","81","82","83","84","85","86","87","88","89","8a","8b","8c","8d","8e","8f",
  "90","91","92","93","94","95","96","97","98","99","9a","9b","9c","9d","9e","9f",
  "a0","a1","a2","a3","a4","a5","a6","a7","a8","a9","aa","ab","ac","ad","ae","af",
  "b0","b1","b2","b3","b4","b5","b6","b7","b8","b9","ba","bb","bc","bd","be","bf",
  "c0","c1","c2","c3","c4","c5","c6","c7","c8","c9","ca","cb","cc","cd","ce","cf",
  "d0","d1","d2","d3","d4","d5","d6","d7","d8","d9","da","db","dc","dd","de","df",
  "e0","e1","e2","e3","e4","e5","e6","e7","e8","e9","ea","eb","ec","ed","ee","ef",
  "f0","f1","f2","f3","f4","f5","f6","f7","f8","f9","fa","fb","fc","fd","fe","ff",
};

void bough_dumpBinary(unsigned char *ptr, size_t size)
{
	int i = 0;
	unsigned char byte;
	for (i = 0; i < size; i++) {
		byte = ptr[i];
		fprintf(stderr, "%s ", hex_map[byte]);
		if (i % 16 == 15) fprintf(stderr, "\n");
	}
}

#endif/*K_USING_FFIDSL*/

knh_Fmethod knh_makeFmethod(CTX ctx, void *func, int argc, knh_ffiparam_t *argv)
{
#ifdef K_USING_FFIDSL
	void* f = knh_generateWrapper(ctx, (void*)func, argc, argv);
	//knh_xblock_t* blk = knh_generateWrapper(ctx, (void*)func, argc, argv);

	if (f != NULL) {
		//	bough_dumpBinary(blk->block, 128);
		return (void*)f;
	}
#endif
	return NULL; /* if FAILED */
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
