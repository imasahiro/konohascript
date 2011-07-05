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
#include"../../include/konoha1/konohalang.h"
/* copied from "../lang/commons.h" */
#define TT_(tk)          SP(tk)->tt
#define STT_(stmt)       SP(stmt)->stt
#define tkNN(stmt, n)    (stmt)->tokens[(n)]
#define stmtNN(stmt, n)  (stmt)->stmts[(n)]

/* copied from "../lang/typing.c" */
#define Token_fn(ctx, tk) FN_UNMASK(Token_fnq(ctx, tk))

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#ifndef K_USING_MINGW_
#include <sys/mman.h>
#endif


/* 
 * Contributors
 *  Shinpei Nakata <shinpei.nakata(at)gmail.com>
 */

typedef struct {
	knh_type_t type;
	knh_short_t sfpidx;
	void *conv_func;
} knh_ffiparam_t;

/*
static void dumpBinary(unsigned char* ptr, size_t size);
*/

/* ------------------------------------------------------------------------ */
// Memory allocation
// xmalloc freelist. each size is 
#define XBLOCK_SIZE (128)
#define XBLOCK_PAGESIZE (sysconf(_SC_PAGESIZE))
#define XBLOCK_NUMBER (XBLOCK_PAGESIZE / XBLOCK_SIZE)

#define XMEM_TOTAL_SIZE (1024 * 64)
	
typedef struct knh_xmem_allocator {
	void *root;
	size_t totalSize;
	size_t usedSize;
	void *freelist;
} knh_xmem_allocator;

static knh_xmem_allocator g_xmem_allocator = {0};

static void initXmemAllocator(CTX ctx)
{
	knh_xmem_allocator *xalc = &g_xmem_allocator;
	void *ptr = (void *)KNH_VALLOC(ctx, XMEM_TOTAL_SIZE);
#ifndef K_USING_MINGW_
	int mret = mprotect(ptr, XMEM_TOTAL_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC);
#else
	int mret = -1;
#endif
	if (mret != -1) {
		xalc->root = ptr;
		xalc->totalSize = XMEM_TOTAL_SIZE;
		xalc->usedSize = 0;
		xalc->freelist = ptr;
	}
}

#define XMEM_IS_PROPSIZE(size) (size <= XMEM_TOTAL_SIZE)
#define XMEM_DOES_FIT(xalc, size) 	(size <= (xalc->totalSize - xalc->usedSize))
	
void *knh_xmalloc(CTX ctx, size_t size)
{
	KNH_ASSERT(size >= 0);
	knh_xmem_allocator *xalc = &g_xmem_allocator;
	if (unlikely(xalc->totalSize == 0)) {
		initXmemAllocator(ctx);
	}
	if (XMEM_IS_PROPSIZE(size)) {
		if (XMEM_DOES_FIT(xalc, size)) {
			// It fits.
			xalc->usedSize += size;
			void *ptr = xalc->freelist;
			xalc->freelist = (knh_uchar_t*)((intptr_t)xalc->freelist + (intptr_t)size);
			bzero(ptr, size);
			return ptr;
		}
	}
	fprintf(stderr,
			"Reach the limit allocation for executable memory!!\n"
			"You're using:%dbytes, and allocating additional %dbytes\n", (int)xalc->usedSize, (int)size); 
	return NULL;
}


static inline void knh_xfree(CTX ctx, void* block, size_t size)
{
	knh_vfree(ctx, block, size);
}




/*
// for FFI DSL
typedef struct knh_xblock_t {
	unsigned char *block;
	struct knh_xblock_t *next;
} knh_xblock_t;


static knh_xblock_t* xfreelist = NULL;

static void* get_unused_xblock(CTX ctx)
{
	if (unlikely(xfreelist == NULL)) {
		unsigned char *xmem = (unsigned char*)knh_xmalloc(ctx, 1);
		assert(xmem != NULL);
		knh_xblock_t *p = (knh_xblock_t*)knh_malloc(ctx, XBLOCK_NUMBER * sizeof(knh_xblock_t));
		size_t idx = 0;
		for (idx = 0; idx < XBLOCK_NUMBER - 1; idx++) {
			p[idx].block = &(xmem[idx * XBLOCK_SIZE]);
			p[idx].next = &(p[idx + 1]);
			//			fprintf(stderr, "idx:%d, p:%p, block:%p, next:%p\n", idx, &(p[idx]), p[idx].block, p[idx].next);
		}
		p[idx].block = &(xmem[idx * XBLOCK_SIZE]);
		p[idx].next = NULL;
		xfreelist = p;
	}
	if (xfreelist->next == NULL) {
		unsigned char *xmem = (unsigned char*)knh_xmalloc(ctx, 1);
		knh_xblock_t *p = (knh_xblock_t*)knh_malloc(ctx, XBLOCK_NUMBER * sizeof(knh_xblock_t));
		size_t idx = 0;
		for (idx = 0; idx < XBLOCK_NUMBER - 1; idx++) {
			p[idx].block = &(xmem[idx * XBLOCK_SIZE]);
			p[idx].next = &(p[idx + 1]);
		}
		p[idx].block = &(xmem[idx * XBLOCK_SIZE]);
		p[idx].next = NULL;
		xfreelist->next = p;
	}
	assert(xfreelist->next != NULL);
	knh_xblock_t *ret = xfreelist;
	xfreelist = ret->next;
	return ret;
}
*/

/*
	// this supposed to be a libffi version
static knh_xblock_t *knh_generateWrapper(CTX ctx, void *callee, int argc, knh_ffiparam_t *argv)
{
  knh_xblock_t *blk = get_unused_xblock(ctx);
  void *function = blk->block;

  size_t fidx = 0;
  int i = 0;
  knh_ffiparam_t *t;

  for (i = 0; i < argc; i++) {
	t = &argv[i];
	if (t->sfpidx = -1) {
	  // it means arguments	
	  switch(t->type) {
	    case CLASS_Tvoid:
		  // do nothing
		  break;
	    case CLASS_Int:
		  break;
	  }
	}
  }
}
  */



/* ------------------------------------------------------------------------ */
// FFI DSL generator
//  knh_Fmethod : void 
#ifdef K_USING_FFIDSL

// (eax)
#define MOD_EADDR (0)
// (eax + disp8)
#define MOD_PLUS8 (1)
// (eax + disp32)
#define MOD_PLUS32 (2)
// $eax
#define MOD_IMD (3)

// Reg/opcode
#define _EAX (0)
#define _ECX (1)
#define _EDX (2)
#define _EBX (3)
#define _ESP (4)
#define _EBP (5)
#define _ESI (6)
#define _EDI (7)


#define FUNCTION function
#define FIDX fidx

#define WRITE_ASM(MOD, REG, RM) FUNCTION[FIDX++] = (MOD << 6) | (REG << 3) | RM
#define WRITE_HEX(hex) { FUNCTION[FIDX++] = hex; }


typedef struct knh_xcode_t {
	void *code;
	size_t codesize;
} knh_xcode_t;


static knh_xblock_t* knh_generateWrapper(CTX ctx, void* callee, int argc, knh_ffiparam_t *argv)
{
	//unsigned char *FUNCTION = (unsigned char*)knh_xmalloc(ctx, 1);
	knh_xblock_t *blk = get_unused_xblock(ctx);
	unsigned char *function = blk->block;
	
	size_t fidx = 0;

	// magick word
	WRITE_HEX(0x55); // push ebp 
	WRITE_HEX(0x89); // mov esp->ebp
	WRITE_ASM(MOD_IMD, _ESP, _EBP);

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

			switch(t->type) {
			case CLASS_Tvoid:
				// do noting.
				break;
			case CLASS_Int:
				// its 64bit int
				//TODO: we need to call translater, but now, we ignore
				//TODO: assume we cast Int --> int;
				// add ebx[sfp] + sfpidx * 16;
				WRITE_HEX(0x83); //add
				WRITE_ASM(MOD_IMD,  _EAX , _EBX);
				WRITE_HEX((unsigned char)(t->sfpidx * 16));

				// move ivalue(offset is 8);
				WRITE_HEX(0x8b); // mov r+disp, r
				WRITE_ASM(MOD_PLUS8, _EAX, _EBX);
				WRITE_HEX(0x8);

				// move eax to local value
				//WRITE_HEX(0x89);
				//WRITE_ASM(MOD_IMD, _EBP, _EAX);
				//				WRITE_HEX(0xf4);
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
			function[fidx++] = 0x89; // mov r+disp r
			function[fidx++] = 0x45; // 0xXX(ebp)
			disp = default_disp + i * 4;
			disp = 0x100 - disp;
			function[fidx++] = disp; // -0x8
			//move to esp
			function[fidx++] = 0x89;
			function[fidx++] = 0x04;
			function[fidx++] = 0x24;
		}

	}

	//now call.
	// call foreign function
	//	intptr_t ucallee = (intptr_t)callee;
	//	intptr_t next_addr = (intptr_t)function + (intptr_t)fidx + 5 /*for call instruction */;
	//intptr_t rel = (ucallee > next_addr) ? ucallee - next_addr : next_addr - ucallee;
	//rel = -rel;
	//unsigned char *src = (unsigned char*)&rel;

	// absolute call
	unsigned char *src = (unsigned char*)&callee;
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
	WRITE_HEX(0x8b);
	WRITE_ASM(MOD_PLUS8, _EDX, _EBP);
	WRITE_HEX(0xfc);

	if (argv[0].sfpidx == -1) {
		switch(argv[0].type) {
		case CLASS_Tvoid:
			goto STEP_OUT;
			break;
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
	WRITE_HEX(0x8b);  // mov
	WRITE_ASM(MOD_PLUS8, _EAX, _EBP); // 0xXX(ebp) eax
	WRITE_HEX(0x8); // 8

	// get edx --> ebx
	WRITE_HEX(0x89);
	WRITE_ASM(MOD_IMD, _EDX, _EBX);

	// ebx[sfp] + 16 * rix
	// first, 16 * rix = 2^4 * rix
	WRITE_HEX(0xc1); // shl
	WRITE_ASM(MOD_IMD, _ESP, _EAX);
	WRITE_HEX(0x4);

	// second, add eax to ebx;
	WRITE_HEX(0x01); //add
	WRITE_ASM(MOD_IMD, _EAX, _EBX); // add eax -> ebx;

	// now at ebx is pointing to sfp[K_RIX];
	// copy retvalue to sfp[K_RIX].ivalue (offset is 0x8)
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
			WRITE_HEX(0xdd);
			WRITE_ASM(MOD_PLUS8, _EBX, _EBX);
			WRITE_HEX(0x8);
			break;
		}
	}

	// from here, closing this function
	// close stack; add 0xXX esp
 STEP_OUT:
	WRITE_HEX(0x83);
	WRITE_HEX(0xc4);
	WRITE_HEX((unsigned char)(stacksize + 0x8));

	// restore ebx
	WRITE_HEX(0x5b); // pop ebx
	WRITE_HEX(0x5d);	// pop ebp;

	// ret $0x4
	WRITE_HEX(0xc2); // ret
	WRITE_HEX(0x4);
	WRITE_HEX(0x0);

	//	return function;
	return blk;
}
#endif/*K_USING_FFIDSL*/
//typedef struct {
//	knh_type_t type;
//	knh_short_t sfpidx;
//	void *conv_func;
//} knh_ffiparam_t;  // for ffi
// sfp: -1 --> return
// sfp: 1+ --> arguments

#define FUNC_SIZE (256)

#ifndef __x86_64__

static void *knh_generateCallbackFunc32(CTX ctx, void *tmpl, void *dest, knh_Func_t *fo)
{
  knh_uchar_t *function = NULL;
#if !defined(K_USING_WINDOWS) && !defined(K_USING_BTRON)
  function = (knh_uchar_t*)tmpl;
  //search -1
  int i, marker = -1, jmp_pos = -1, shrink_pos = -1;
  for (i = 0; i < FUNC_SIZE; i++) {
	//	fprintf(stderr, "dump:%02x\n", *(int*)&function[i]);
	if (*(int*)&function[i] == -1 && marker == -1) {
	  marker = i;
	  i += 3;
	}

	// for thunk.bx, they call thunk, and add.
	if (function[i] == 0xe8 && function[i+5] == 0x81 && function[i+6] == 0xc3){
	  shrink_pos = i;
	  continue;
	} else 	if (function[i] == 0xe8 && *(int*)&function[i+1] < 0 && jmp_pos < 0) {
	  jmp_pos = i;
	}
	// loop condition
	if (function[i] == 0x5d && function[i + 1] == 0xc3) {
	  i += 14;
	  break;
	}
	if (i != 0 && function[i] == 0x55 && function[i + 1] == 0x89 && function[i+2] == 0xe5) {
	  // next prologue
	  i -= 1;
	  break;
	}
  }
  //  fprintf(stderr, "i=%d\n", i);
  function = (knh_uchar_t*)knh_xmalloc(ctx, i);
  memcpy(function, tmpl, i);
  //  fprintf(stderr, "marker:%d, jmp:%d, shrink:%d\n", marker, jmp_pos, shrink_pos);
  knh_uchar_t buf[FUNC_SIZE]={0};
  //  dumpBinary(function, 48);
  size_t funcsize = i;
  if (shrink_pos > 0) {
	// shrinking call xxx, add xxx
	// they always moving ebx;
	memcpy(buf, &function[shrink_pos + 11], funcsize - (shrink_pos + 11));
	function[shrink_pos] = 0x90;
	memcpy(&function[shrink_pos + 1], buf, funcsize - (shrink_pos + 11));
	marker -= 10;
	jmp_pos -= 10;
	funcsize -= 10;
	//	fprintf(stderr, "marker:%d, jmp:%d, shrink:%d\n", marker, jmp_pos, shrink_pos);
  }

  if (marker > 0){
	*(intptr_t*)&function[marker] = (intptr_t)fo;
  }


  //  fprintf(stderr, "jpos:%x\n", *(int*)&function[jmp_pos]);
  if (jmp_pos > 0) {
	//	int disp =  (intptr_t)dest - (intptr_t)&function[jmp_pos + 5];
	// it is too far.. make far calling
	function[jmp_pos] = 0xb8;
	*(intptr_t*)&function[jmp_pos+1] = (intptr_t)dest;
	memcpy(buf, &function[jmp_pos + 5], funcsize - (jmp_pos + 5));
	// insert 2 values;
	//before jmp!
	size_t seekidx = jmp_pos + 5;
	function[seekidx] = 0x90;
	function[seekidx+1] = 0xff;
	function[seekidx+2] = 0xd0;
	// shift the rest;
	memcpy(&function[seekidx+3], buf, funcsize - (seekidx+3));
	//	dumpBinary(function, 48);
  }

#endif
  return function;
}
#endif

#ifdef __x86_64__
enum last_inst {
	jmp_only,
	leave_jmp,
	call_leave_ret
};
static void *knh_generateCallbackFunc64(CTX ctx, void *tmpl, void *dest, knh_Func_t *fo)
{
	knh_uchar_t *function = NULL;
#if !defined(K_USING_WINDOWS) && !defined(K_USING_BTRON)
	function = (knh_uchar_t*)tmpl;
	// search -1 (0xfffffff0fffffff0)
	int i, marker = -1, jmp_pos = -1;
	enum last_inst lastInst = call_leave_ret;
	for (i = 0; i < FUNC_SIZE; i++) {
		if (*(intptr_t*)&function[i] == 0xfffffff0fffffff0 && marker == -1) {
			marker = i;
			i += 8;
		}
		// XXX ??? function[i] == 0xe8 && 0x66
		/* jmp instruction
		 * e8 00 00 00  */
		if (function[i] == 0xe8 /*&& function[i] == 0x66*/) {
			jmp_pos = i;
		}
		// jmppos for x86_64
		// c9 : leave
		// e9 xxxxxxxx : jmp xxxxxxxx
		if(function[i] == 0xc9 && function[i + 1] == 0xe9) {
			lastInst = leave_jmp;
			jmp_pos = i + 1;
			i += 4; // rel address is 4 bytes
			break; 
		}
		//linux amd64
		if (function[i] == 0xe9 && *(int*)&function[i+1] < 0) {
			lastInst = jmp_only;
			jmp_pos = i;
			i += 5 + 4;
			break;
		}

		// typical epilogue.
		if (function[i] == 0xc9 && function[i+1] == 0xc3) {
			i += 2;
			break;
		}
	}
	// copy function
	size_t funcsize = i;
	function = (knh_uchar_t*)knh_xmalloc(ctx, funcsize);
	memcpy(function, tmpl, i);
	if (marker > 0) {
		memcpy(&function[marker], &fo, sizeof(void*));
	}
	// now, patch
	if (jmp_pos > 0) {
		//linux
		// happend to use rax
		// movq 0x(dest) %rax
		function[jmp_pos+0] = 0x48;
		function[jmp_pos+1] = 0xb8;
		union {
			unsigned char code[sizeof(intptr_t)];
			intptr_t v;
		} code;
		code.v = (intptr_t) dest;
		memcpy(function+(jmp_pos+2), code.code, sizeof(code));

		size_t seekidx = jmp_pos + 2 + sizeof(intptr_t);
		// call
		switch (lastInst) {
		case leave_jmp:
			/* leave */
			//function[seekidx++] = 0xc9;
			/* fall through */
		case jmp_only: /*case leave_jmp:*/
			/* jmp *%rax */
			function[seekidx+0] = 0xff;
			function[seekidx+1] = 0xe0;
			break;
		case call_leave_ret:
			/* callq *%rax */
			function[seekidx+0] = 0xff;
			function[seekidx+1] = 0xd0;
			/* leave */
			function[seekidx+2] = 0xc9;
			/* ret */
			function[seekidx+3] = 0xc3;
			break;
		}
	}

#endif /* tron, lkm */
	return function;
}
#endif /*__x86_64__ */

void *knh_copyCallbackFunc(CTX ctx, void *tmpl, void *dest, knh_Func_t *fo)
{
	void *function = NULL;
#ifdef __x86_64__
	function = knh_generateCallbackFunc64(ctx, tmpl, dest, fo);
#else
	function = knh_generateCallbackFunc32(ctx, tmpl, dest, fo);
#endif
	return function;
}

/*
static void dumpBinary(unsigned char *ptr, size_t size)
{
	int i = 0;
	unsigned char byte;
	for (i = 0; i < size; i++) {
		byte = ptr[i];
		fprintf(stderr, "%02x ", byte);
		if (i % 16 == 15) fprintf(stderr, "\n");
	}
}
*/

static void* knh_lookupLibraryFunc(CTX ctx, knh_bytes_t libfunc)
{
	void *cfunc = NULL;
//	knh_index_t loc = knh_bytes_index(libfunc, ':');
//	if(loc != -1) {
//		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
//		knh_bytes_t libname = knh_bytes_first(libfunc, loc);
//		knh_bytes_t funcname = knh_bytes_last(libfunc, loc+1);
//		knh_Bytes_write(ctx, cwb->ba, libname);
//		void *p = knh_path_dlopen(ctx, LOG_DEBUG, cwb);
//		if(p != NULL) {
//			cfunc = knh_dlsym(ctx, LOG_DEBUG, p, funcname.text);
//		}
//		knh_cwb_close(cwb);
//	}
	fprintf(stderr, "Hey!, Shinpei, If you want to use this, email me!\n");
	return cfunc;
}

static void* knh_fficonv(CTX ctx, knh_type_t type, knh_bytes_t t)
{
	return NULL;
}

static void set_ffireturn(CTX ctx, knh_ffiparam_t *p, knh_Method_t *mtd, knh_Token_t *tkF)
{
	p->type = 	knh_ParamArray_rtype(DP(mtd)->mp);
	p->sfpidx = -1;
	if(tkF != NULL) {
		p->conv_func = knh_fficonv(ctx, p->type, S_tobytes(tkF->text));
	}
}

static knh_bool_t set_ffiparam(CTX ctx, knh_ffiparam_t *p, knh_Method_t *mtd, knh_Token_t *tkN)
{
	knh_Token_t *tkF = NULL;
	if(TT_(tkN) == STT_FUNCCALL) {
		knh_Stmt_t *stmtF = (knh_Stmt_t*)tkN;
		tkN = tkNN(stmtF, 2);
		tkF = tkNN(stmtF, 0);
	}
	if(TT_(tkN) == TT_NAME) {
		knh_fieldn_t fn = Token_fn(ctx, tkN);
		if(fn == FN_this) {
			p->sfpidx = 0;
			p->type = mtd->cid;
			if(tkF != NULL) {
				p->conv_func = knh_fficonv(ctx, p->type, S_tobytes(tkF->text));
			}
		}
		else {
			size_t i;
			knh_ParamArray_t *pa = DP(mtd)->mp;
			for(i = 0; i < pa->psize; i++) {
				knh_param_t *mp = knh_ParamArray_get(pa, i);
				if(mp->fn == fn) {
					p->sfpidx = 1 + i;
					p->type = mp->type;
					if(tkF != NULL) {
						p->conv_func = knh_fficonv(ctx, p->type, S_tobytes(tkF->text));
					}
					return 1;
				}
			}
		}
	}
	return 0;
}

static knh_Fmethod knh_makeFmethod(CTX ctx, void *func, int argc, knh_ffiparam_t *argv)
{
#ifdef K_USING_FFIDSL
//	void *f = knh_generateWrapper(ctx, (void*)func, argc, argv);
	knh_xblock_t* blk = knh_generateWrapper(ctx, (void*)func, argc, argv);
	void *f = blk->block;
	if (f != NULL) {
		//		dumpBinary(f, 128);
		return (void*)f;
	}
#endif
	return NULL; /* if FAILED */
}

const char* TT__(knh_term_t tt);
void Method_linkFFI(CTX ctx, knh_Method_t *mtd, knh_Stmt_t *stmt)
{
	int argc = 0;
	knh_ffiparam_t params[16] = {};
	knh_Token_t *tkF = NULL;
	if(STT_(stmt) != STT_FUNCCALL) goto L_ERROR;
	tkF = tkNN(stmt, 0);
	DBG_P("TT=%s, '%s'", TT__(tkF->tt), S_tochar(tkF->text));
	if(TT_(tkF) != TT_URN) {
		set_ffireturn(ctx, params, mtd, tkF);
		if(DP(stmt)->size != 3) {
			goto L_ERROR;
		}
		argc = 1;
		stmt = stmtNN(stmt, 2);
		tkF = tkNN(stmt, 0);
	}
	if(TT_(tkF) == TT_URN) {
		size_t i;
		void *cfunc = knh_lookupLibraryFunc(ctx, S_tobytes(tkF->text));
		if(cfunc == NULL) {
			goto L_ERROR;
		}
		if(argc == 0) {
			set_ffireturn(ctx, params + argc, mtd, NULL);
			argc = 1;
		}
		for(i = 2; (i < DP(stmt)->size && argc < 16); i++) {
			if(set_ffiparam(ctx, params + argc, mtd, tkNN(stmt, i))) {
				argc++;
			}
			else {
				goto L_ERROR;
			}
		}
		{
			knh_Fmethod fmethod = knh_makeFmethod(ctx, cfunc, argc, params);
			if(fmethod != NULL) {
				knh_Method_setFunc(ctx, mtd, fmethod);
				return;
			}
		}
	}
	L_ERROR:;
	DBG_P("ERROR");
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
