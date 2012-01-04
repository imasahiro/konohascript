#ifndef TJIT
#define TJIT
//#define TJIT
#define TJIT_DUMP
#define USE_NOPTABLE

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_NOPTABLE
#define ASM_NOP_MAX 7
static const unsigned char x86nops[] = {
	/* 1byte nop */ 0x90,
	/* 2byte nop */ 0x66, 0x90,
	/* 3byte nop */ 0x0f, 0x1f, 0x00,
	/* 4byte nop */ 0x0f, 0x1f, 0x40, 0x00,
	/* 5byte nop */ 0x0f, 0x1f, 0x44, 0x00, 0x00,
	/* 6byte nop */ 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00,
	/* 7byte nop */ 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char * x86_noptable[ASM_NOP_MAX+1] = {
	NULL,
	x86nops,
	x86nops + 1,
	x86nops + 1 + 2,
	x86nops + 1 + 2 + 3,
	x86nops + 1 + 2 + 3 + 4,
	x86nops + 1 + 2 + 3 + 4 + 5,
	x86nops + 1 + 2 + 3 + 4 + 5 + 6,
};

static void add_nops(void *insns, unsigned int len)
{
	const unsigned char **noptable = x86_noptable;
	while (len > 0) {
		unsigned int noplen = len;
		if (noplen > ASM_NOP_MAX)
			noplen = ASM_NOP_MAX;
		memcpy(insns, noptable[noplen], noplen);
		insns = (void*)((intptr_t)insns + noplen);
		len -= noplen;
	}
}
#endif

static unsigned char canJIT[] = {
	0/*HALT     */, 0/*THCODE   */, 0/*ENTER    */, 0/*VEXEC    */,
	0/*YIELD    */, 0/*FUNCCALL */, 0/*TRY      */, 0/*TRYEND   */,
	0/*THROW    */, 0/*ASSERT   */, 0/*CATCH    */, 0/*CHKIN    */,
	0/*CHKOUT   */, 0/*ERROR    */, 0/*P        */, 0/*PROBE    */,
	0/*EXIT     */, 1/*NSET     */, 1/*NMOV     */, 0/*NNMOV    */,
	1/*NSET2    */, 1/*NSET3    */, 1/*NSET4    */, 1/*NMOVx    */,
	1/*XNSET    */, 1/*XNMOV    */, 1/*XNMOVx   */, 1/*iINC     */,
	1/*iDEC     */, 1/*bNUL     */, 1/*bNN      */, 1/*bNOT     */,
	1/*iNEG     */, 0/*fNEG     */, 1/*iTR      */, 1/*fTR      */,
	1/*iADD     */, 1/*iSUB     */, 1/*iMUL     */, 0/*iDIV     */,
	1/*iMOD     */, 1/*iEQ      */, 1/*iNEQ     */, 1/*iLT      */,
	1/*iLTE     */, 1/*iGT      */, 1/*iGTE     */, 1/*iAND     */,
	1/*iOR      */, 1/*iXOR     */, 1/*iLSFT    */, 1/*iRSFT    */,
	1/*iADDC    */, 1/*iSUBC    */, 1/*iMULC    */, 1/*iDIVC    */,
	1/*iMODC    */, 1/*iEQC     */, 1/*iNEQC    */, 1/*iLTC     */,
	1/*iLTEC    */, 1/*iGTC     */, 1/*iGTEC    */, 1/*iANDC    */,
	1/*iORC     */, 1/*iXORC    */, 1/*iLSFTC   */, 1/*iRSFTC   */,
	1/*fADD     */, 1/*fSUB     */, 1/*fMUL     */, 1/*fDIV     */,
	1/*fEQ      */, 1/*fNEQ     */, 1/*fLT      */, 1/*fLTE     */,
	1/*fGT      */, 1/*fGTE     */, 1/*fADDC    */, 1/*fSUBC    */,
	1/*fMULC    */, 1/*fDIVC    */, 1/*fEQC     */, 1/*fNEQC    */,
	1/*fLTC     */, 1/*fLTEC    */, 1/*fGTC     */, 1/*fGTEC    */,
	1/*RCINC    */, 1/*RCDEC    */, 1/*OSET     */, 1/*OMOV     */,
	1/*OOMOV    */, 1/*ONMOV    */, 1/*OSET2    */, 1/*OSET3    */,
	1/*OSET4    */, 1/*RCINCx   */, 1/*RCDECx   */, 1/*OMOVx    */,
	1/*XMOV     */, 1/*XOSET    */, 1/*XMOVx    */, 0/*CHKSTACK */,
	1/*LDMTD    */, 0/*CALL     */, 0/*SCALL    */, 1/*VCALL    */,
	1/*VCALL    */, 1/*FASTCALL0*/, 0/*RET      */, 1/*TR       */,
	1/*SCAST    */, 1/*TCAST    */, 0/*ACAST    */, 1/*iCAST    */,
	1/*fCAST    */, 1/*SAFEPOINT*/, 1/*JMP      */, 0/*JMP2     */,
	0/*JMP      */, 0/*JMPF     */, 0/*NEXT     */, 1/*BGETIDX  */,
	1/*BSETIDX  */, 1/*BGETIDXC */, 1/*BSETIDXC */, 1/*NGETIDX  */,
	1/*NSETIDX  */, 1/*NGETIDXC */, 1/*NSETIDXC */, 1/*OGETIDX  */,
	1/*OSETIDX  */, 1/*OGETIDXC */, 1/*OSETIDXC */, 0/*bJNUL    */,
	0/*bJNN     */, 0/*bJNOT    */, 0/*iJEQ     */, 0/*iJNEQ    */,
	0/*iJLT     */, 0/*iJLTE    */, 0/*iJGT     */, 0/*iJGTE    */,
	0/*iJEQC    */, 0/*iJNEQC   */, 1/*iJLTC    */, 0/*iJLTEC   */,
	0/*iJGTC    */, 1/*iJGTEC   */, 0/*fJEQ     */, 0/*fJNEQ    */,
	0/*fJLT     */, 0/*fJLTE    */, 1/*fJGT     */, 0/*fJGTE    */,
	0/*fJEQC    */, 0/*fJNEQC   */, 1/*fJLTC    */, 0/*fJLTEC   */,
	0/*fJGTC    */, 0/*fJGTEC   */, 1/*CHKIDX   */, 1/*CHKIDXC  */,
	0/*NOP      */
};

/* ----------------------------------------------------------------- */
static void jit_dump(void *mem, int size)
{
#if defined(TJIT_DUMP)
	int i = 0;
	unsigned char *code = (unsigned char*) mem;
	fprintf(stderr, "code start=%p\n", code);
	for (i = 0; i < size; i++) {
		fprintf(stderr, " %02x", code[i]);
		if (i%16 == 15) {
			fprintf(stderr, "\n");
		}
	}
	if (i%16) 
		fprintf(stderr, "\n");
	fprintf(stderr, "code   end=%p\n", code + i);
	fprintf(stderr, "\n");
#endif
}
/* ----------------------------------------------------------------- */
struct code_stack {
	unsigned char *code;
	unsigned char *code_addr;
	unsigned char *code_pos;
	unsigned char *target;
	unsigned char *jmp_pos;
	int target_size;
	int reserved_size;
} cstack[64] = {};
int cindex = 0;

#define cstack_push(cstack, c, p, t, j, s, r) {\
	cstack[cindex].code_addr   = c; \
	cstack[cindex].code_pos    = p; \
	cstack[cindex].target      = t; \
	cstack[cindex].jmp_pos     = j; \
	cstack[cindex].target_size = s; \
	cstack[cindex].reserved_size = r; \
	cindex++;\
}
#define cstack_pop(cstack, c, p, t, j, s) {\
	p = cstack[cindex].code_pos;    \
	t = cstack[cindex].target;      \
	j = cstack[cindex].jmp_pos;     \
	s = cstack[cindex].target_size; \
	cindex--;\
}
#define cstack_clear(data) {\
	data->code        = (unsigned char *) 0xffffffff;\
	data->code_addr   = (unsigned char *) NULL;  \
	data->code_pos    = (unsigned char *) NULL;  \
	data->target      = (unsigned char *) NULL;  \
	data->jmp_pos     = (unsigned char *) NULL;  \
	data->target_size = 0;     \
}

static kintptr_t get_target_template(unsigned char *code, unsigned char **jmp_target)
{
	static unsigned char jmp_r[] = {0xff,0xe0};
	static unsigned char jmp[]   = {0xe9,0x00,0x00,0x00,0x00};
	assert(sizeof(jmp_r) == 2);
	assert(sizeof(jmp) == 5);
	int i, size = -1;

	for (i = 0; i < 128; i++) {
		/* check jump instruction with register */
		if (code[i] == jmp_r[0] && code[i+1] == jmp_r[1]) {
			size = (i + sizeof(jmp_r));
			break;
		}

		/* check jump instruction */
		if (code[i] == jmp[0]) {
			int32_t pos = ((int32_t*) &code[i+1])[0];
			unsigned char *target = code + i + 5 + pos;
			DBG_(jit_dump(&code[i], 8);jit_dump(target, 16););
			size = (i + sizeof(jmp));
			*jmp_target = target;
			break;
		}
	}
	DBG_P("code=%p %d", code, size);
	return size;
}
/* ----------------------------------------------------------------- */
static int fix_code_template(unsigned char *code, kintptr_t *size)
{
	static unsigned char jmp_r[]  = {0xff,0xe0};
	/* long conditional jmp */
	static unsigned char cond_l[] = {0x0f,0x80, 0x00, 0x00, 0x00, 0x00};
	/* short conditional jmp */
	static unsigned char cond_s[] = {0x77,0x00};
	static unsigned char fcmp0[]  = {0x66,0x42,0x0f,0x2e,0x04,0x30};
	static unsigned char test[]   = {0x85,0xc0};
#if 0
	/* TODO */
	static unsigned char fcmp1[]  = {0x66,0x0f,0x2e,0x42,0x28};
#endif
	int i, need_rewrite = 0;
	assert(sizeof(jmp_r) == 2);
	assert(sizeof(cond_l) == 6);
	assert(sizeof(cond_s) == 2);
	int check_shortcond = 0;

	for (i = 0; i < 128; i++) {
		/* check jump instruction with register */
		if (code[i] == jmp_r[0] && code[i+1] == jmp_r[1]) {
			*size = i + sizeof(jmp_r);
			break;
		}
		/* check conditional branch instruction */
		if (code[i] == cond_l[0] && 
				(0x84 <= code[i+1] && code[i+1] <= 0x8d)) {
			/* 0x0f 0x87 0xe8 0x08 0x00 0x00 */
			/* 0xe8 0x08 0x00 0x00 => 0x000008e8 */
			kintptr_t tsize;
			unsigned char *cur_pos = &code[i+2];
			int32_t pos = ((int32_t*) cur_pos)[0];
			unsigned char *target = code + i + sizeof(cond_l) + pos;
			unsigned char *jmp_target = NULL;
			//jit_dump(&code[i], 8);
			//jit_dump(target, 16);
			tsize = get_target_template(target, &jmp_target);
			cstack_push(cstack,code,cur_pos,target,jmp_target,tsize, sizeof(int32_t));
			DBG_P("code=%p, cur_pos=%p diff=%p",
					code, cur_pos, cur_pos - (intptr_t) code);
			need_rewrite = 1;
		}
		/* check compare instruction */
		if (code[i] == fcmp0[0] && code[i+1] == fcmp0[1]) {
			check_shortcond = 1;
		}
		/* check compare instruction */
		if (code[i] == test[0] && code[i+1] == test[1]) {
			check_shortcond = 1;
		}

		/* check short conditional branch instruction */
		if (check_shortcond && 0x74 <= code[i] && code[i] <= 0x8f) {
			kintptr_t tsize;
			unsigned char *cur_pos = &code[i+1];
			int8_t pos = ((int8_t*) cur_pos)[0];
			unsigned char *target = code + i + sizeof(cond_s) + pos;
			unsigned char *jmp_target = NULL;
			//jit_dump(&code[i], 8);
			//jit_dump(target, 16);
			tsize = get_target_template(target, &jmp_target);
			cstack_push(cstack,code,cur_pos,target,jmp_target,tsize, sizeof(int8_t));
			DBG_P("code=%p, cur_pos=%p diff=%p pos=%x, t=%p",
					code, cur_pos, cur_pos - (intptr_t) code,
					pos, target);
			need_rewrite = 1;
			/* TODO checking more than one conditional jump */
			check_shortcond = 0;
		}
	}
	if (need_rewrite == 0) {
		fprintf(stderr, "??????????????????\n");
		jit_dump(code, 0x40);
		asm volatile("int3");
	}
	return need_rewrite;
}

/* ----------------------------------------------------------------- */
static kintptr_t knh_jit_write(CTX ctx, CWB_t *cwb, kopcode_t op, void **s, void **e)
{
	unsigned char *start = (unsigned char *) s[op];
	unsigned char *end   = (unsigned char *) e[op];
	int need_rewrite = 0;

	kintptr_t size = end - start;
	DBG_P("%s %p - %p, %d", OPCODE__(op), start, end, size);
	if (op == OPCODE_JMP || op == OPCODE_JMP2) {
		unsigned char *jmp_target = NULL;
		size = get_target_template(start, &jmp_target);
		//fprintf(stderr, "**regenerate template!!! %s %p %ld\n",
		//		OPCODE__(op), start, size);
	}
	if (size > 0x100) {
		DBG_P("****warn template is too big!!! %s %p %d", OPCODE__(op), start, size);
		jit_dump(start, 0x100);
		asm volatile("int3");
	}

	if (size < 0) {
		DBG_P("%s(%d)", OPCODE__(op), op);
		need_rewrite = fix_code_template(start, &size);
		if (size < 0) {
			abort();
		}
	}
	if (need_rewrite) {
		intptr_t len = CWB_size(cwb);
		DBG_P("size=%x\n", (unsigned int) len);
		cstack[cindex-1].code = (unsigned char*) len;
	}
	knh_Bytes_write(ctx, cwb->ba, new_bytes2((char*)start, size));
	return size;
}

/* ----------------------------------------------------------------- */
static unsigned char *write_target_code(unsigned char *code, int len, unsigned char *tcode , int tsize)
{
	unsigned char *target = code + len;
	DBG_P("target=%p, code=%p, len=%d", target, code, len);
	memcpy(target, tcode, tsize);
	return target;
}
#define toint(a) (intptr_t)(a)
#define toaddr(a) (void *)(a)
#define intadd(a,b) ((kintptr_t)(a) + (kintptr_t)(b))
static void rewrite_jmp_target(unsigned char *code, int *len, struct code_stack* cdata)
{
	int size = *len;
	intptr_t diff = toint(cdata->code_pos) - toint(cdata->code_addr);
	unsigned char *p = code + toint(cdata->code) + diff;
	unsigned char *target = write_target_code(code, size, cdata->target, cdata->target_size);
	intptr_t jmp;
	DBG_P("diff=0x%x, p=%p, target=%p, cdata=%p", diff, p, target, cdata);
	if(cdata->reserved_size == sizeof(int8_t)) {
		jmp = (intptr_t)target - (intptr_t)p - 1;
		//DBG_P("jmp=%p p[0]=0x%x", jmp, ((int8_t*) p)[0]);
		((int8_t*) p)[0] = (int8_t) jmp;
	}
	else if(cdata->reserved_size == sizeof(int32_t)) {
		jmp = (intptr_t)target - (intptr_t)p - sizeof(int32_t);
		((int32_t*) p)[0] = jmp;
	}
	else {
		jmp = (intptr_t)target - (intptr_t)p - 4;
		((int32_t*) p)[0] = jmp;
	}
	if (cdata->jmp_pos) jit_dump(cdata->jmp_pos, 16);

	*len += cdata->target_size;

	DBG_(jit_dump(code, *len));

	/* clear used code info */
	cstack_clear(cdata);
}

static void _THCODE_TJIT(CTX ctx, kopl_t *pc, void **codeaddr, void **codeend)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	kopl_t *op = pc;
	intptr_t curpos = 0;
	L_TRUE:
	while(1) {
		kopcode_t opcode = pc->opcode;
		DBG_P("%s %d %d\n", OPCODE__(opcode), opcode, canJIT[opcode]);
		if (opcode == OPCODE_VCALL) {
			opcode = OPCODE_VCALL_;
		}
		if(opcode == OPCODE_SCAST) {
			pc->count = (size_t) knh_TypeMap_exec;
		}
		if (canJIT[opcode] == 0) {
			/* we can not jit compile because current pc's template
			 * is broken */
			if (curpos > 0) {
				DBG_P("jmp to %s(%d)\n",OPCODE__(opcode), opcode);
				kintptr_t size = knh_jit_write(ctx, cwb, OPCODE_JMP2, codeaddr, codeend);
				curpos += size;
			}
			goto L_FALSE;
		} else {
			if (pc != op && opcode != OPCODE_RET &&
					!canJIT[(pc-1)->opcode] && !canJIT[(pc+1)->opcode]) {
				goto L_FALSE;
			}
			kintptr_t size;
			//fprintf(stderr, "%s %d %d\n", OPCODE__(opcode), opcode, canJIT[opcode]);
			size = knh_jit_write(ctx, cwb, opcode, codeaddr, codeend);
			pc->codeaddr = toaddr(curpos);
			DBG_(jit_dump(codeaddr[opcode], size););
			curpos += size;
		}
		if(opcode == OPCODE_RET) break;
		pc++;
	}
	goto L_FINAL;
	L_FALSE:
	/*pc = op;*/
	{
		DBG_ASSERT_OPCODE(pc->opcode);
		pc->codeaddr = codeaddr[pc->opcode];
		if(pc->opcode == OPCODE_RET) goto L_FINAL;
		pc++;
		goto L_TRUE;
	}
	L_FINAL:
	{
		kbytes_t codes = CWB_tobytes(cwb);
		unsigned char *mem;
		int i, len, maxlen, align = 0;
		len = maxlen = codes.len;
		for (i = 0; i < cindex; i++) {
			maxlen += cstack[i].target_size;
		}
		if (maxlen > 0) {
			align = (int) ((uint16_t)(0x10 - maxlen % 0x10));
			maxlen += align;
		}
		mem = (unsigned char *) knh_xmalloc(ctx, maxlen);
		memcpy(mem, codes.ubuf, len);
		DBG_P("len=%d, maxlen=%d, mem=%p align=%d",
				len, maxlen, mem, align);

		/* reindexing codeaddr */
		pc = op;
		while(1) {
			if (canJIT[pc->opcode]) {
				if (pc != op && pc->opcode != OPCODE_RET &&
						!canJIT[(pc-1)->opcode] && !canJIT[(pc+1)->opcode]) {
					/* skip */
					//kopcode_t o0, o1, o2;
					//o0 = (pc-1)->opcode;
					//o1 = (pc  )->opcode;
					//o2 = (pc+1)->opcode;
					//fprintf(stderr, "**%s %d %d\n", OPCODE__(o0), o0, canJIT[o0]);
					//fprintf(stderr, "**%s %d %d\n", OPCODE__(o1), o1, canJIT[o1]);
					//fprintf(stderr, "**%s %d %d\n", OPCODE__(o2), o2, canJIT[o2]);
				} else {
					void *pos = pc->codeaddr;
					pc->codeaddr = toaddr(intadd(mem, pc->codeaddr));
					int max = cindex;
					for (i = 0; i < max; i++) {
						DBG_P("pos=%p, c[%d].p=%p size=%x",
								pos, i, cstack[i].code, cstack[i].target_size);
						if (pos == cstack[i].code)
							rewrite_jmp_target(mem, &len, &cstack[i]);
					}
				}
			}
			if(pc->opcode == OPCODE_RET) break;
			pc++;
		}

		if (align > 0) {
			add_nops((void*)((intptr_t)mem + len), align);
			len += align;
		}

		//DBG_P("len=%d, maxlen=%d, mem=%p align=%d",
		//		len, maxlen, mem, align);
		KNH_ASSERT(len == maxlen);
		DBG_(jit_dump(mem, len););
		/* reset code stack */
		cindex = 0;
		return;
	}
}

/* ----------------------------------------------------------------- */
#ifdef __cplusplus
}
#endif

#endif /* TJIT */
