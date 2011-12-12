#!/usr/bin/python
import os, sys
import copy
from pygenlib2 import *

#------------------------------------------------------------------------------

INSTRUCTIONS = """
# OP       FLAG              ARGS
HALT       0
THCODE     0                 th:f uri:u
ENTER      0
VEXEC      0
YIELD      0                 n:sfpidx
FUNCCALL   0
TRY        0                 addr:addr hn:ro
TRYEND     0                 hn:ro
THROW      0                 start:sfpidx
ASSERT     0                 start:sfpidx uline:u
CATCH      _CONST            addr:addr en:ro eid:int
CHKIN      0                 on:ro checkin:f
CHKOUT     0                 on:ro checkout:f
ERROR      _CONST            start:sfpidx msg:String
P          _CONST            print:f flag:u  msg:String n:sfpidx2
PROBE      0                 sfpidx:sfpidx2 probe:f n:u n2:u
EXIT       0

NSET       _DEF|_JIT         a:rn n:int
NMOV       _DEF|_JIT         a:rn b:rn
@NNMOV     _DEF              a:rn b:rn c:rn d:rn
@NSET2     _DEF|_JIT         a:rn n:int n2:int
@NSET3     _DEF|_JIT         a:rn n:u n2:u n3:u
@NSET4     _DEF|_JIT         a:rn n:u n2:u n3:u n4:u

NMOVx      _DEF              a:rn  b:sfx
XNSET      0                 a:sfx b:int
XNMOV      0                 a:sfx b:rn
XNMOVx     0                 a:sfx b:sfx

@iINC      _DEF|_JIT         a:rn
@iDEC      _DEF|_JIT         a:rn

bNUL       _DEF|_JIT         c:rn a:ro
bNN        _DEF|_JIT         c:rn a:ro
bNOT       _DEF|_JIT         c:rn a:rn
iNEG       _DEF|_JIT         c:rn a:rn
fNEG       _DEF|_JIT         c:rn a:rn       
iTR        _DEF|_JIT         c:rn a:rn  inttr:f
fTR        _DEF|_JIT         c:rn a:rn  floattr:f

iADD       _DEF|_JIT         c:rn a:rn b:rn
iSUB       _DEF|_JIT         c:rn a:rn b:rn
iMUL       _DEF|_JIT         c:rn a:rn b:rn
iDIV       _DEF|_JIT         c:rn a:rn b:rn
iMOD       _DEF|_JIT         c:rn a:rn b:rn
iEQ        _DEF|_JIT         c:rn a:rn b:rn
iNEQ       _DEF|_JIT         c:rn a:rn b:rn
iLT        _DEF|_JIT         c:rn a:rn b:rn
iLTE       _DEF|_JIT         c:rn a:rn b:rn
iGT        _DEF|_JIT         c:rn a:rn b:rn
iGTE       _DEF|_JIT         c:rn a:rn b:rn
iAND       _DEF|_JIT         c:rn a:rn b:rn
iOR        _DEF|_JIT         c:rn a:rn b:rn
iXOR       _DEF|_JIT         c:rn a:rn b:rn
iLSFT      _DEF|_JIT         c:rn a:rn b:rn
iRSFT      _DEF|_JIT         c:rn a:rn n:rn

iADDC      _DEF|_JIT         c:rn a:rn n:int
iSUBC      _DEF|_JIT         c:rn a:rn n:int
iMULC      _DEF|_JIT         c:rn a:rn n:int
iDIVC      _DEF|_JIT         c:rn a:rn n:int
iMODC      _DEF|_JIT         c:rn a:rn n:int
iEQC       _DEF|_JIT         c:rn a:rn n:int
iNEQC      _DEF|_JIT         c:rn a:rn n:int
iLTC       _DEF|_JIT         c:rn a:rn n:int
iLTEC      _DEF|_JIT         c:rn a:rn n:int
iGTC       _DEF|_JIT         c:rn a:rn n:int
iGTEC      _DEF|_JIT         c:rn a:rn n:int
iANDC      _DEF|_JIT         c:rn a:rn n:int
iORC       _DEF|_JIT         c:rn a:rn n:int
iXORC      _DEF|_JIT         c:rn a:rn n:int
iLSFTC     _DEF|_JIT         c:rn a:rn n:int
iRSFTC     _DEF|_JIT         c:rn a:rn n:int

fADD       _DEF|_JIT         c:rn a:rn b:rn  
fSUB       _DEF|_JIT         c:rn a:rn b:rn  
fMUL       _DEF|_JIT         c:rn a:rn b:rn  
fDIV       _DEF|_JIT         c:rn a:rn b:rn  
fEQ        _DEF|_JIT         c:rn a:rn b:rn  
fNEQ       _DEF|_JIT         c:rn a:rn b:rn  
fLT        _DEF|_JIT         c:rn a:rn b:rn  
fLTE       _DEF|_JIT         c:rn a:rn b:rn  
fGT        _DEF|_JIT         c:rn a:rn b:rn  
fGTE       _DEF|_JIT         c:rn a:rn b:rn  

fADDC      _DEF|_JIT         c:rn a:rn n:float 
fSUBC      _DEF|_JIT         c:rn a:rn n:float 
fMULC      _DEF|_JIT         c:rn a:rn n:float 
fDIVC      _DEF|_JIT         c:rn a:rn n:float 
fEQC       _DEF|_JIT         c:rn a:rn n:float 
fNEQC      _DEF|_JIT         c:rn a:rn n:float 
fLTC       _DEF|_JIT         c:rn a:rn n:float 
fLTEC      _DEF|_JIT         c:rn a:rn n:float 
fGTC       _DEF|_JIT         c:rn a:rn n:float 
fGTEC      _DEF|_JIT         c:rn a:rn n:float 

RCINC      _JIT              a:ro
RCDEC      _JIT              a:ro

@OSET      _DEF|_JIT|_CONST  a:ro o:Object
@OMOV      _DEF|_JIT         a:ro b:ro
@OOMOV     _DEF|_JIT         a:ro b:ro c:ro d:ro
@ONMOV     _DEF|_JIT         a:ro b:ro c:rn d:rn
@OSET2     _JIT|_CONST       a:ro v:Object v2:Object
@OSET3     _JIT|_CONST       a:ro v:Object v2:Object v3:Object
@OSET4     _JIT|_CONST       a:ro v:Object v2:Object v3:Object v4:Object

RCINCx     0                 a:sfx
RCDECx     0                 a:sfx
@OMOVx     _DEF|_JIT         a:ro b:sfx
@XMOV      _JIT              a:sfx b:ro
@XOSET     _JIT|_CONST       a:sfx b:Object
@XMOVx     0                 a:sfx b:sfx

#MOVe   a:sfpidx xspidx:u

CHKSTACK   0                 n:sfpidx
LDMTD      0                 thisidx:sfpidx loadmtd:f cache:hcache mtdNC:mtd
CALL       _DEF|_JIT         a:r thisidx:sfpidx espshift:sfpidx
SCALL      _DEF|_JIT         a:r thisidx:sfpidx espshift:sfpidx mtdNC:mtd
VCALL      _DEF|_JIT         a:r thisidx:sfpidx espshift:sfpidx mtdNC:mtd
VCALL_     _DEF|_JIT         a:r thisidx:sfpidx espshift:sfpidx mtdNC:mtd
FASTCALL0  _DEF|_JIT         a:r thisidx:sfpidx rix:i espshift:sfpidx fcall:f
RET        _JIT

TR         _DEF|_JIT         a:r  b:sfpidx rix:i cid:cid tr:f

SCAST      _DEF              a:r b:sfpidx rix:i espshift:sfpidx cast:tmr
TCAST      _DEF              a:r b:sfpidx rix:i espshift:sfpidx cast:tmr
ACAST      _DEF              a:r b:sfpidx rix:i espshift:sfpidx cast:tmr
iCAST      _DEF|_JIT         a:rn b:rn
fCAST      _DEF|_JIT         a:rn b:rn

SAFEPOINT  _JIT              espshift:sfpidx
JMP        _JIT              addr:addr
JMP_       _JIT              addr:addr
JMPF       0                 addr:addr a:rn
NEXT       _DEF              addr:addr a:r b:sfpidx rix:i espshift:sfpidx

BGETIDX    _DEF|_JIT         c:rn a:ro n:rn 
BSETIDX    _DEF|_JIT         c:rn a:ro n:rn  v:rn
BGETIDXC   _DEF|_JIT         c:rn a:ro n:u 
BSETIDXC   _DEF|_JIT         c:rn a:ro n:u  v:rn

NGETIDX    _DEF|_JIT         c:rn a:ro n:rn 
NSETIDX    _DEF|_JIT         c:rn a:ro n:rn v:rn
NGETIDXC   _DEF|_JIT         c:rn a:ro n:u 
NSETIDXC   _DEF|_JIT         c:rn a:ro n:u  v:rn

@OGETIDX    _DEF|_JIT         c:ro a:ro n:rn
@OSETIDX    _DEF|_JIT         c:ro a:ro n:rn v:ro  
@OGETIDXC   _DEF|_JIT         c:ro a:ro n:u 
@OSETIDXC   _DEF|_JIT         c:ro a:ro n:u  v:ro 

# level 3 instruction

bJNUL     _DEF|_JIT   addr:addr a:ro
bJNN      _DEF|_JIT   addr:addr a:ro

bJNOT     _DEF|_JIT   addr:addr a:rn
iJEQ      _DEF|_JIT   addr:addr a:rn b:rn
iJNEQ     _DEF|_JIT   addr:addr a:rn b:rn
iJLT      _DEF|_JIT   addr:addr a:rn b:rn
iJLTE     _DEF|_JIT   addr:addr a:rn b:rn
iJGT      _DEF|_JIT   addr:addr a:rn b:rn
iJGTE     _DEF|_JIT   addr:addr a:rn b:rn
iJEQC     _DEF|_JIT   addr:addr a:rn n:int
iJNEQC    _DEF|_JIT   addr:addr a:rn n:int
iJLTC     _DEF|_JIT   addr:addr a:rn n:int
iJLTEC    _DEF|_JIT   addr:addr a:rn n:int
iJGTC     _DEF|_JIT   addr:addr a:rn n:int
iJGTEC    _DEF|_JIT   addr:addr a:rn n:int

fJEQ      _DEF|_JIT   addr:addr a:rn b:rn
fJNEQ     _DEF|_JIT   addr:addr a:rn b:rn
fJLT      _DEF|_JIT   addr:addr a:rn b:rn
fJLTE     _DEF|_JIT   addr:addr a:rn b:rn
fJGT      _DEF|_JIT   addr:addr a:rn b:rn
fJGTE     _DEF|_JIT   addr:addr a:rn b:rn
fJEQC     _DEF|_JIT   addr:addr a:rn n:float
fJNEQC    _DEF|_JIT   addr:addr a:rn n:float
fJLTC     _DEF|_JIT   addr:addr a:rn n:float
fJLTEC    _DEF|_JIT   addr:addr a:rn n:float
fJGTC     _DEF|_JIT   addr:addr a:rn n:float
fJGTEC    _DEF|_JIT   addr:addr a:rn n:float

CHKIDX     _JIT              a:ro n:rn
CHKIDXC    _JIT              a:ro n:u

NOP       0

"""

CTYPE = {
	'sfpidx' : 'ksfpidx_t', 
	'sfpidx2' : 'ksfpidx_t', 
	'sfx' :    'ksfx_t',
	'int':     'kint_t',
	'float':   'kfloat_t',
	'cid':     'const knh_ClassTBL_t*',
	'hcache':  'kcachedata_t',
	'mtd':     'kMethod*',
	'tmr':     'kTypeMap*',
	'addr':    'knh_KLRInst_t*',
	'u':       'kuintptr_t',
	'i':       'kintptr_t',
	'rn':      'kregN_t',
	'ro':      'kregO_t',
	'r':       'kreg_t',
}

def getctype(t, v):
	if CTYPE.has_key(t): return CTYPE[t]
	if t == 'f': return 'klr_F%s' % (v)
	return 'k%s*' % t

def getVMT(t):
	tt = ', VMT_%s' % (t.upper())
	if t == 'sfx': tt = tt + ', VMT_VOID'
	if t == 'int': tt = tt + ' VMTX_INT'
	if t == 'float': tt = tt + ' VMTX_FLOAT'
	return tt

def getsize(t):
	if t == 'sfx': return '+1'
	if t == 'int': return '+VMTSIZE_int'
	if t == 'float': return '+VMTSIZE_float'
	return ''

class KCODE:
	def __init__(self, opcode, line):
		self.tokens = line.split()
		self.name = self.tokens[0].replace('@', '')
		self.flag = self.tokens[1]
		self.NAME = self.name.upper()
		self.opcode = opcode
		self.OPCODE = 'OPCODE_%s' % self.name
		self.OPLABEL = 'L_%s' % self.name
		self.ctype = 'klr_%s_t' % self.name		
		self.level=''
		self.ifdef = 'CASE'
		self.size = '%d' % len(self.tokens[2:])
		self.struct = '{'
		for a in self.tokens[2:]:
			if a.startswith('#') :
				self.ifdef = a[1:]
				self.size = '%d' % len(self.tokens[2:]) - 1
				continue
			if len(a.split(':')) == 1: print line
			n, t = a.split(':')
			ctype = getctype(t, n)
			self.struct = self.struct + getVMT(t)
			self.size = self.size + getsize(t)
		self.struct += ', VMT_VOID}'
		self.struct = self.struct.replace('{,', '{')

#####################################################################

CPROTO = []

KCODE_LIST = []
KSTRUCT_LIST = []
KCODE_STRUCT ={}

c = 0
for line in INSTRUCTIONS.split('\n'):
	if line.startswith("#") or len(line) == 0: continue
	if len(line.split()) > 1:
		kc = KCODE(c, line)
		KCODE_LIST.append(kc)
		c += 1

#------------------------------------------------------------------------------

def write_KCODE_h(f, kc):
	f.write('''
#define %s ((kopcode_t)%d)''' % (kc.OPCODE, kc.opcode))
	f.write('''
typedef struct %s {
	KCODE_HEAD;''' % kc.ctype)
	for a in kc.tokens[2:]:
		n, t = a.split(':')
		if t == "addr" : 
			f.write('''
	kopl_t  *jumppc;''')
		else: 
			f.write('''
	%s %s;''' % (getctype(t, n), n))
	f.write('''
} %s;
''' % kc.ctype)

def write_define_h(f):
	for p in CPROTO:
		f.write(p + ';\n')
	for kc in KCODE_LIST:
		write_KCODE_h(f,kc)
	n = len(KCODE_LIST)
	f.write('''
#define OPCODE_MAX ((kopcode_t)%d)

#define VMT_VOID     0
#define VMT_ADDR     1
#define VMT_SFPIDX   2
#define VMT_R        3
#define VMT_RN       4
#define VMT_RO       5
#define VMT_SFPIDX2  6
#define VMT_SFX      7
#define VMT_U        8
#define VMT_I        9
#define VMT_F        10
#define VMT_CID      11
#define VMT_HCACHE   12
#define VMT_MTD      13
#define VMT_TMR      14
#define VMT_OBJECT   15
#define VMT_STRING   16
#define VMT_INT      17
#define VMT_FLOAT    18

''' % (n))

#------------------------------------------------------------------------------

def write_common_c(f):
	write_chapter(f, '[common]')
	f.write('''
#define K_USING_VMINLINE
#include "vminline.c"
''')

def write_data_c(f):
	write_chapter(f, '[data]')
	f.write('''
#define _CONST 1
#define _JIT   (1<<1)
#define _DEF   (1<<2)
typedef struct {
	const char *name;
	kflag_t   flag;
	kushort_t size;
	kushort_t types[6];
} knh_OPDATA_t;

static const knh_OPDATA_t OPDATA[] = {''')
	for kc in KCODE_LIST:
		n = kc.name
		if n.endswith("_"): n = n[:-1]
		f.write('''
	{"%s", %s, %s, %s}, ''' % (n, kc.flag, kc.size, kc.struct))
	f.write('''
};

void knh_opcode_check(void)
{''')
	for kc in KCODE_LIST:
		f.write('''
	KNH_ASSERT(sizeof(%s) <= sizeof(kopl_t));''' % (kc.ctype))
	f.write('''
}

/* ------------------------------------------------------------------------ */
const char *OPCODE__(kopcode_t opcode)
{
	if(opcode < OPCODE_MAX) {
		return OPDATA[opcode].name;
	}
	else {
		DBG_P("opcode=%d", (int)opcode);
		return "OPCODE_??";
	}
}

/* ------------------------------------------------------------------------ */
size_t knh_opcode_size(kopcode_t opcode)
{
	return OPDATA[opcode].size;
}

/* ------------------------------------------------------------------------ */
kbool_t knh_opcode_hasjump(kopcode_t opcode)
{
	return (OPDATA[opcode].types[0] == VMT_ADDR);
}
/* ------------------------------------------------------------------------ */
kbool_t knh_opcode_usedef(kopcode_t opcode, int i)
{
	kushort_t type = OPDATA[opcode].types[i];
	if ((type == VMT_SFPIDX) || (type == VMT_R) ||
			(type == VMT_RN) || (type == VMT_RO)) {
		return 1;
	}
	return 0;
}
/* ------------------------------------------------------------------------ */

kObject** knh_opline_reftrace(CTX ctx, kopl_t *c FTRARG)
{
	if(FLAG_is(OPDATA[c->opcode].flag, _CONST)) {
		size_t i, size = OPDATA[c->opcode].size;
		for(i = 0; i < size; i++) {
			kushort_t vtype = OPDATA[c->opcode].types[i];
			if(vtype == VMT_OBJECT || vtype == VMT_STRING) {
				KNH_ADDREF(ctx, c->p[i]);
			}
		}
	}
	return tail_;
}
/* ------------------------------------------------------------------------ */

#define RBP_ASSERT0(N) do {\\
	if((N % 2) != 0) {\\
		DBG_P("r=%d", N); \\
		DBG_ASSERT((N % 2) == 0);\\
	}\\
} while (0)

#define RBP_ASSERT1(N) do {\\
	if((N % 2) == 0) {\\
		DBG_P("r=%d", N);\\
		DBG_ASSERT((N % 2) != 0);\\
	}\\
} while (0)

void knh_opcode_dump(CTX ctx, kopl_t *c, kOutputStream *w, kopl_t *pc_start)
{
	size_t i, size = OPDATA[c->opcode].size;
	const kushort_t *vmt = OPDATA[c->opcode].types;
	if(pc_start == NULL) {
		knh_printf(ctx, w, "[%p:%d] %s(%d)", c, c->line, OPCODE__(c->opcode), (kintptr_t)c->opcode);
	}
	else {
		knh_printf(ctx, w, "L%d(%d): %s(%d)", c - pc_start, c->line, OPCODE__(c->opcode), (kintptr_t)c->opcode);
	}
	for(i = 0; i < size; i++) {
		knh_putc(ctx, w, ' '); 
		switch(vmt[i]) {
		case VMT_VOID: break;
		case VMT_ADDR: 
			if(pc_start == NULL) {
				knh_printf(ctx, w, "%p", c->p[i]); break;
			}
			else {
				knh_printf(ctx, w, "L%d", (kopl_t*)c->p[i] - pc_start); break;
			}
		case VMT_SFPIDX2:
			knh_printf(ctx, w, "sfp[%d]", c->data[i]); 
			break;
		case VMT_RN: 
			RBP_ASSERT1(c->data[i]);
			if(((kintptr_t)c->data[i]) < 0) {
				knh_printf(ctx, w, "r(%d)", c->data[i]); 
			}
			else {
				knh_printf(ctx, w, "r%d", c->data[i]); 
			}
			break;
		case VMT_SFX:
			RBP_ASSERT0(c->data[i]);
			knh_printf(ctx, w, "r%d(+%d)", c->data[i], c->data[i+1]); 
			break;
		case VMT_SFPIDX: 
		case VMT_RO:
			RBP_ASSERT0(c->data[i]);
		case VMT_R: 
			if(((kintptr_t)c->data[i]) < 0) {
				knh_printf(ctx, w, "r(%d)", c->data[i]); 
			}
			else {
				knh_printf(ctx, w, "r%d", c->data[i]); 
			}
			break;
		case VMT_U: case VMT_I:
			knh_write_dfmt(ctx, w, K_INTPTR_FMT, c->data[i]); break;
		case VMT_F:
			knh_write_vmfunc(ctx, w, c->p[i]); break;
		case VMT_CID:
			knh_write_cname(ctx, w, ((knh_ClassTBL_t*)c->data[i])->cid); break;
		case VMT_HCACHE: {
			kcachedata_t *hc = (kcachedata_t*)&(c->p[i]);
			knh_write_cname(ctx, w, hc->cid); 
			knh_putc(ctx, w, '/');
			knh_write_mn(ctx, w, hc->mn); 
		}
		break;
		case VMT_MTD: if(c->p[i] != NULL) {
			kMethod *mtd = (kMethod*)c->p[i];
			knh_write_cname(ctx, w, (mtd)->cid); knh_putc(ctx, w, '.');
			knh_write_mn(ctx, w, (mtd)->mn); 
		}
		else {
			knh_write_ascii(ctx, w, "NULL");
		}
		break;
		case VMT_TMR:
		case VMT_OBJECT:
		case VMT_STRING: {
			knh_write_Object(ctx, w, UPCAST(c->p[i]), FMT_line);
			break;
		}
		case VMT_INT: {
			kint_t n = ((kint_t*)(&(c->p[i])))[0];
			knh_write_ifmt(ctx, w, KINT_FMT, n); break;
		}
		case VMT_FLOAT:
			knh_write_ffmt(ctx, w, KFLOAT_FMT, *((kfloat_t*)&(c->p[i]))); break;
		}
	}
	knh_write_EOL(ctx, w);
}

void knh_opcode_shift(kopl_t *c, int shift)
{
	size_t i, size = OPDATA[c->opcode].size;
	const kushort_t *vmt = OPDATA[c->opcode].types;
	for(i = 0; i < size; i++) {
		switch(vmt[i]) {
			case VMT_SFPIDX: case VMT_R: case VMT_RN: case VMT_RO: case VMT_SFX: 
				c->data[i] = c->data[i] + (shift * 2); break;
			case VMT_SFPIDX2:
				c->data[i] = c->data[i] + (shift); break;
		}
	}
}

''')

def write_kcftr(f, kc):
	pass
	
def write_kcdump(f, kc):
	##########
	f.write('''
static void %s_dump(CTX ctx, kopl_t *c, kOutputStream *w)
{
	%s *op = (%s*)c; 
	knh_write_opcode(ctx, w, op->opcode);''' % (kc.name, kc.ctype, kc.ctype))
	c = 1
	for a in kc.tokens[2:]:
		f.write('''
	''')
		f.write(getfmt(a) % ('(op->a%d)' % c))
		c += 1	
	f.write('''
}
''')

def write_kcshift(f, kc):
	##########
	f.write('''
static void %s_shift(CTX ctx, kopl_t *c, int shift, int pcshift)
{
	%s *op = (%s*)c; ''' % (kc.name, kc.ctype, kc.ctype))
	c = 1
	for a in kc.tokens[2:]:
		if a == 'addr':
			f.write('''
	char *newpc = ((char*)op->a%d) + pcshift;
	op->a%d = (knh_KLRInst_t*)newpc;
	THREADEDCODE(op->codeaddr = NULL;)''' % (c, c))
		if a == 'sfpidx':
			f.write('''
	op->a%d += shift;''' % c)
		if a == 'sfx':
			f.write('''
	op->a%d.i += shift;''' % c)
		c += 1	
	f.write('''
}
''')

def write_inst_c(f):
	write_common_c(f)
	write_data_c(f)

#############################################################################

def getmacro(kc, label):
	m = 'KLR%s_%s(ctx' % (kc.level, kc.name)
	for a in kc.tokens[2:]:
		v, t = a.split(':')
		if t == 'addr':
			m += ', pc = op->jumppc, %s' % (label)
		else:
			m += ', op->%s' % (v)
	m += ')'
	return m

def write_exec(f):
	write_chapter(f, '[exec]')
	f.write('''

#include"../../include/konoha1/konoha_vm.h"

#ifdef K_USING_VMCOUNT_
#define VMCOUNT(op)    ((op)->count)++;
#else
#define VMCOUNT(op)
#endif

//#if (defined(K_USING_LINUX_) && (defined(__i386__) || defined(__x86_64__)) && (defined(__GNUC__) && __GNUC__ >= 3))
//#define K_USING_VMASMDISPATCH 1
//#endif

#ifdef K_USING_THCODE_
#define CASE(x)  L_##x : 
#define NEXT_OP   (pc->codeaddr)
#define JUMP      *(NEXT_OP)
#ifdef K_USING_VMASMDISPATCH
#define GOTO_NEXT()     \\
	asm volatile("jmp *%0;": : "g"(NEXT_OP));\\
	goto *(NEXT_OP)

#else
#define GOTO_NEXT()     goto *(NEXT_OP)
#endif
#define TC(c) 
#define DISPATCH_START(pc) goto *OPJUMP[pc->opcode]
#define DISPATCH_END(pc)
#define GOTO_PC(pc)        GOTO_NEXT()
#else/*K_USING_THCODE_*/
#define OPJUMP      NULL
#define CASE(x)     case OPCODE_##x : 
#define NEXT_OP     L_HEAD
#define GOTO_NEXT() goto NEXT_OP
#define JUMP        L_HEAD
#define TC(c)
#define DISPATCH_START(pc) L_HEAD:;switch(pc->opcode) {
#define DISPATCH_END(pc)   } KNH_DIE("unknown opcode=%d", (int)pc->opcode); 
#define GOTO_PC(pc)         GOTO_NEXT()
#endif/*K_USING_THCODE_*/

kopl_t* knh_VirtualMachine_run(CTX ctx, ksfp_t *sfp0, kopl_t *pc)
{
#ifdef K_USING_THCODE_
	static void *OPJUMP[] = {''')
	c = 0
	for kc in KCODE_LIST:
		if c % 4 == 0: f.write('\n\t\t')
		f.write('''&&%s, ''' % kc.OPLABEL)
		c += 1
	f.write('''
	};
#endif
	krbp_t *rbp = (krbp_t*)sfp0;
	USE_PROF(
	kuint64_t _utime = knh_getTime();
	static kuint64_t _UTIME[OPCODE_NOP+1] = {0};
	static size_t _UC[OPCODE_NOP+1] = {0};)
	DISPATCH_START(pc);
''')
	for kc in KCODE_LIST:
# DBG_P("%%p %%s", pc-1, OPCODE__((pc-1)->opcode));
		f.write('''
	%s(%s) {
		%s *op = (%s*)pc; (void)op;
		%s;
		pc++;
		GOTO_NEXT();
	} ''' % (kc.ifdef, kc.name, kc.ctype, kc.ctype, getmacro(kc, 'JUMP')))
	f.write('''
	DISPATCH_END(pc);
	L_RETURN:;
	return pc;
}

''')

#------------------------------------------------------------------------------

def gen_vm_c(bdir):
	fname = '%s/src/lang/vmcodelibs.c' % bdir
	f = open_c(fname, ['"commons.h"'])
	write_inst_c(f)
	write_exec(f)
	close_c(f, fname)
	
	f = open('include/konoha1/konoha_code_.h', 'w')
	f.write('#ifndef %s\n' % 'konoha_code_h_'.upper());
	f.write('#define %s\n' % 'konoha_code_h_'.upper());
	f.write('''// THIS FILE WAS AUTOMATICALLY GENERATED

//#include "konoha_vm.h"

''')
	write_define_h(f)
	f.write('#endif /* %s */\n' % 'konoha_code_h_'.upper());
	f.close()


#------------------------------------------------------------------------------

if __name__ == '__main__':
	bdir = '.'
	gen_vm_c(".")

