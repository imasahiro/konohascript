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

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [object] */

int knh_Object_compareTo(Object *o1, Object *o2)
{
	knh_class_t cid1 = O_cid(o1);
	knh_class_t cid2 = O_cid(o2);
	int res;
	if(cid1 == cid2) {
		res = O_cTBL(o1)->cdef->compareTo(RAWPTR(o1), RAWPTR(o2));
	}
	else {
		res = (int)(o1 - o2);
		DBG_P("compared %s %s res=%d", O__(o1), O__(o2), res);
	}
	return res;
}

KNHAPI2(void) knh_Object_toNULL_(CTX ctx, Object *o)
{
	Object_setNullObject(o, 1);
}

/* ------------------------------------------------------------------------ */

knh_bool_t knh_invokeMethod0(CTX ctx, Object *o, knh_NameSpace_t *ns, unsigned long mnd, void **retval, ...)
{
	knh_methodn_t mn = mnd < 10000 ? (knh_methodn_t)mnd : knh_getmn(ctx, B((char*)mnd), MN_NONAME);
	knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, O_cid(o), mn);
	if(mtd != NULL) {
		BEGIN_LOCAL(ctx, lsfp, 0);
		size_t i, psize = knh_Method_psize(mtd), rtnidx = 0, thisidx = rtnidx + K_CALLDELTA;
		knh_class_t this_cid = O_cid(o);
		va_list ap;
		va_start(ap, retval);
		KNH_SETv(ctx, lsfp[thisidx].o, o);
		for(i = 0; i < psize; i++) {
			knh_type_t ptype = knh_Method_ptype(ctx, mtd, i, this_cid);
			switch(ptype) {
				case CLASS_Boolean: {
					lsfp[thisidx+1+i].bvalue = va_arg(ap, int);
					break;
				}
				case CLASS_Int : {
					lsfp[thisidx+1+i].ivalue = va_arg(ap, long);
					break;
				}
				case CLASS_Float : {
					lsfp[thisidx+1+i].ivalue = va_arg(ap, double);
					break;
				}
				case CLASS_String :  {
					const char *s = va_arg(ap, const char*);
					if(s == NULL) {
						KNH_SETv(ctx, lsfp[thisidx+1+i].o, KNH_TNULL(String));
					}
					else if(knh_isObject(ctx, (void*)s)) {
						DBG_ASSERT(IS_bString((Object*)s));
						KNH_SETv(ctx, lsfp[thisidx+1+i].o, (Object*)s);
					}
					else {
						KNH_SETv(ctx, lsfp[thisidx+1+i].o, new_String(ctx, s));
					}
					break;
				}
				default : {
					Object *v = va_arg(ap, Object *);
					if(v == NULL) {
						v = KNH_NULVAL(ptype);
					}
					else {
						DBG_ASSERT(O_cid(v) == ptype || ClassTBL_isa_(ctx, O_cTBL(v), ClassTBL(ptype)));
					}
					KNH_SETv(ctx, lsfp[thisidx+1+i].o, v);
				}
			}/*switch*/
		}/*for*/
		va_end(ap);
		KNH_SCALL(ctx, lsfp, rtnidx, mtd, psize);
		if(retval != NULL) {
			knh_type_t rtype = knh_Method_rtype(ctx, mtd, this_cid);
			switch(rtype) {
				case CLASS_Tvoid: retval[0] = NULL; break;
				case CLASS_Boolean: ((knh_bool_t*)retval)[0] = lsfp[rtnidx].bvalue; break;
				case CLASS_Int:     ((knh_int_t*)retval)[0] = lsfp[rtnidx].ivalue; break;
				case CLASS_Float:   ((knh_float_t*)retval)[0] = lsfp[rtnidx].fvalue; break;
				default: retval[0] = (void*)lsfp[rtnidx].o;
			}
		}
		END_LOCAL(ctx, lsfp);
		return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

static void nofree(void *p)
{
}

KNHAPI2(knh_RawPtr_t*) new_RawPtr(CTX ctx, const knh_ClassTBL_t *ct, void *rawptr)
{
	knh_RawPtr_t *npo = (knh_RawPtr_t*)new_hObject_(ctx, ct);
	npo->rawptr = rawptr;
	if(rawptr == NULL) {
		knh_Object_toNULL(ctx, npo);
	}
	npo->rawfree = nofree;
	return npo;
}

KNHAPI2(knh_Object_t*) new_ReturnObject(CTX ctx, knh_sfp_t *sfp)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	knh_type_t rtype = knh_ParamArray_rtype(DP(mtd)->mp);
	return new_Object_init2(ctx, ClassTBL(rtype));
}

KNHAPI2(knh_RawPtr_t*) new_ReturnCppObject(CTX ctx, knh_sfp_t *sfp, void *rawptr, knh_Frawfree pfree)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	knh_type_t rtype = knh_ParamArray_rtype(DP(mtd)->mp);
	knh_RawPtr_t *npo = (knh_RawPtr_t*)new_hObject_(ctx, ClassTBL(rtype));
	npo->rawptr = rawptr;
	if(rawptr == NULL) {
		knh_Object_toNULL(ctx, npo);
	}
	else {
		npo->rawfree = (pfree != NULL) ? pfree : nofree;
	}
	return npo;
}

knh_RawPtr_t *new_Pointer(CTX ctx, const char *name, void *rawptr, knh_Frawfree pfree)
{
	knh_RawPtr_t *npo = (knh_RawPtr_t*)new_hObject_(ctx, ClassTBL(CLASS_Tdynamic));
	npo->rawptr = rawptr;
	npo->DBG_NAME = name;
	npo->rawfree = (pfree != NULL) ? pfree : nofree;
	return npo;
}

KNHAPI2(void) knh_addConstPool(CTX ctx, knh_Object_t *o)
{
	knh_Array_add(ctx, ctx->share->constPools, o);
}

/* ------------------------------------------------------------------------ */
/* [ClassTBL] */

const char *SAFESTRUCT__(CTX ctx, knh_class_t bcid)
{
	if(bcid < ctx->share->sizeClassTBL) {
		return ClassTBL(bcid)->cdef->name;
	}
	KNH_P("unknown bcid=%d", bcid);
	return "UNKNOWN";
}

const char *SAFETYPE__(CTX ctx, knh_type_t type)
{
	knh_class_t cid = CLASS_t(type);
	if(type == TYPE_void) return "void";
	if(type == TYPE_var)  return "var";
	if(cid < ctx->share->sizeClassTBL) {
		return S_totext(ClassTBL(cid)->sname);
	}
	else {
		static char unsafebuf[20];
		knh_snprintf(unsafebuf, sizeof(unsafebuf), "type=%d", (int)type);
		return (const char*)unsafebuf;
	}
}

const char *SAFECLASS__(CTX ctx, knh_class_t cid)
{
	if(cid < ctx->share->sizeClassTBL) {
		return S_totext(ClassTBL(cid)->lname);
	}
	else {
		return "unknown";
	}
}

#ifdef K_USING_DEBUG
const knh_ClassTBL_t* DBG_ClassTBL(CTX ctx, knh_class_t cid)
{
	if(cid < ctx->share->sizeClassTBL) {
		return ctx->share->ClassTBL[cid];
	}
	DBG_ABORT("NOT CORRECT: cid=%d", cid);
	return NULL;
}
#endif

/* ------------------------------------------------------------------------ */

knh_Class_t *new_Type(CTX ctx, knh_type_t type)
{
	knh_class_t cid = CLASS_t(type);
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	if(ct->typeNULL == NULL) {
		knh_Class_t *o = new_(Class);
		o->cid = cid;
		o->type = cid;
		o->cTBL = ct;
		KNH_INITv(((knh_ClassTBL_t*)ct)->typeNULL, o);
		if(cid == CLASS_Tvoid) {
			Object_setNullObject(o, 1);
		}
	}
	return ct->typeNULL;
}

KNHAPI2(void) knh_write_cid(CTX ctx, knh_OutputStream_t *w, knh_class_t cid)
{
	const char *tname = NULL;
	switch(cid) {
	case TYPE_dynamic:  tname = "dynamic";    break;
	case TYPE_void: tname = "void";       break;
	case TYPE_var:  tname = "var";        break;
	case TYPE_This: tname = "This";       break;
	default :{
			if(cid > TYPE_This) {
				knh_write(ctx, w, STEXT("T"));
				knh_write_ifmt(ctx, w, K_INT_FMT, cid - TYPE_This);
			}
			else {
				knh_write(ctx, w, S_tobytes(ClassTBL(cid)->lname));
			}
			return ;
		}
	}
	knh_write_ascii(ctx, w, tname);
}

void knh_write_cname(CTX ctx, knh_OutputStream_t *w, knh_class_t cid)
{
	const char *tname = NULL;
	switch(cid) {
	case TYPE_dynamic:  tname = "dynamic";    break;
	case TYPE_void: tname = "void";       break;
	case TYPE_var:  tname = "var";        break;
	case TYPE_This: tname = "This";       break;
	default :{
			if(cid > TYPE_This) {
				knh_write(ctx, w, STEXT("T"));
				knh_write_ifmt(ctx, w, K_INT_FMT, cid - TYPE_This);
			}
			else {
				knh_write(ctx, w, S_tobytes(ClassTBL(cid)->sname));
			}
			return ;
		}
	}
	knh_write_ascii(ctx, w, tname);
}

KNHAPI2(void) knh_write_type(CTX ctx, knh_OutputStream_t *w, knh_type_t type)
{
	const char *tname = NULL;
	if(type > TYPE_This) {
		knh_write(ctx, w, STEXT("T"));
		knh_write_ifmt(ctx, w, K_INT_FMT, type - TYPE_This);
		return;
	}
	else if(type == TYPE_This) {
		knh_write_ascii(ctx, w, "This");
		return;
	}
	switch(type) {
	case TYPE_Boolean: tname = "boolean"; break;
	case TYPE_Int: tname = "int"; break;
	case TYPE_Float: tname = "float"; break;
	case TYPE_Bytes:  tname = "byte[]";    break;
	case TYPE_Array: tname = "dynamic" PTYPE_Array;  break;
	case TYPE_Iterator:  tname = "dynamic" PTYPE_Iterator;  break;
	case TYPE_KindOf: tname = "dynamic" PTYPE_KindOf; break;
	case TYPE_Immutable: tname = "dynamic" PTYPE_Immutable; break;
	default :
		tname = NULL;
	}
	if(tname != NULL) {
		knh_write_ascii(ctx, w, tname);
	}
	else {
		knh_write(ctx, w, S_tobytes(ClassTBL(CLASS_t(type))->sname));
	}
}

/* ------------------------------------------------------------------------ */

static knh_Object_t *Fdefnull_newValue(CTX ctx, knh_class_t cid);

void knh_setClassName(CTX ctx, knh_class_t cid, knh_String_t *lname, knh_String_t *snameNULL)
{
	DBG_ASSERT_cid(cid);
	knh_ClassTBL_t *ct = varClassTBL(cid);
	DBG_ASSERT(ct->lname == NULL);
	KNH_INITv(ct->lname, lname);
	if(snameNULL != NULL) {
		KNH_INITv(ct->sname, snameNULL);
	}
	else if(ct->bcid == cid) {
		KNH_INITv(ct->sname, new_T(ct->cdef->name));
	}
	if(ct->sname == NULL) {
		KNH_INITv(ct->sname, ct->lname);
	}
	OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
	{
		knh_bytes_t t = S_tobytes(lname);
		if(t.buf[t.len-1] != '>') {
			knh_DictSet_set(ctx, ctx->share->classNameDictSet, lname, (knh_uintptr_t)ct);
		}
		if(!class_isPrivate(cid) && S_startsWith(lname, STEXT("konoha."))) {
			knh_DictSet_append(ctx, ctx->share->classNameDictSet, ct->sname, (knh_uintptr_t)ct);
		}
	}
	OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);
	if(ct->fdefnull == NULL) {
		ct->fdefnull = Fdefnull_newValue;
	}
}

/* ------------------------------------------------------------------------ */
/* [name] */

knh_class_t knh_getcid(CTX ctx, knh_bytes_t lname)
{
	const knh_ClassTBL_t *ct = (const knh_ClassTBL_t *)knh_DictSet_get(ctx, ctx->share->classNameDictSet, lname);
	if(ct != NULL) return ct->cid;
#if defined(K_USING_SEMANTICS)
	if(lname.buf[lname.len-1] == '}') {
		return knh_findcidx(ctx, lname);
	}
#endif/*K_USING_SEMANTICS*/
	return CLASS_unknown;
}

/* ------------------------------------------------------------------------ */
/* [default] */

static knh_Object_t *Fdefnull_getConst(CTX ctx, knh_class_t cid)
{
	return ClassTBL(cid)->defnull;
}

static knh_Object_t *Fdefnull_newValue(CTX ctx, knh_class_t cid)
{
	knh_ClassTBL_t *ct = varClassTBL(cid);
	Object *v = new_Object_init2(ctx, (const knh_ClassTBL_t*)ct);
	Object_setNullObject(v, 1);
	KNH_ASSERT(ct->defnull == NULL);
	KNH_INITv(ct->defnull, v);
	ct->fdefnull = Fdefnull_getConst;
	DBG_P("create new default value of %s", CLASS__(cid));
	DBG_ASSERT(cid != CLASS_Class);  // for DEBUG
	return ct->defnull;
}

void knh_setClassDefaultValue_(CTX ctx, knh_class_t cid, Object *value, knh_Fdefnull f)
{
	DBG_ASSERT_cid(cid);
	knh_ClassTBL_t *t = varClassTBL(cid);
	if(value == NULL) {
		if(f == NULL) f = Fdefnull_newValue;
	}
	else {
		KNH_ASSERT(t->defnull == NULL);
		KNH_INITv(t->defnull, value);
		if(f == NULL) f = Fdefnull_getConst;
	}
	t->fdefnull = f;
}

KNHAPI2(Object*) knh_getClassDefaultValue(CTX ctx, knh_class_t cid)
{
	return ClassTBL(cid)->fdefnull(ctx, cid);
}

void knh_setClassDef(CTX ctx, knh_ClassTBL_t *ct, const knh_ClassDef_t *cdef)
{
	//DBG_P("setClassDef(%s)", cdef->name);
	ct->cdef = cdef;
	if(cdef->fields != NULL) {
		KNH_ASSERT(ct->fields == NULL);
		ct->fields = cdef->fields;
		ct->fsize = cdef->struct_size / sizeof(void*);
		ct->fcapacity = 0;
	}
	if(cdef->getDefaultNull != NULL) {
		ct->fdefnull = cdef->getDefaultNull;
	}
#ifdef K_USING_BMGC
	ct->struct_size = cdef->struct_size;
#endif
}

/* ------------------------------------------------------------------------ */
/* [instaceof] */

knh_bool_t ClassTBL_isa_(CTX ctx, const knh_ClassTBL_t *ct, const knh_ClassTBL_t *ct2)
{
	knh_class_t reqt = ct2->cid;
	if(reqt == CLASS_Object || reqt == CLASS_Tdynamic || ct->cid == reqt) return 1;
	DBG_ASSERT(ct->cid != CLASS_Tvoid); DBG_ASSERT(ct->cid != CLASS_Tvar);
	//if(cid == CLASS_Tvoid) return 0;
//  if(ClassTBL(scid)->bcid == tcid) return 1; /* Int:km Int */
	if(ct->bcid == CLASS_Tuple && ct2->bcid == CLASS_Tuple) {
		if(ct2->cparam->psize < ct->cparam->psize) {
			size_t i;
			for(i = 0; i < ct2->cparam->psize; i++) {
				knh_param_t *p = knh_ParamArray_get(ct->cparam, i);
				knh_param_t *p2 = knh_ParamArray_get(ct2->cparam, i);
				if(p->type != p2->type) return 0;
			}
			return 1;
		}
		return 0;
	}
	if(ct->bcid == CLASS_Func && ct2->bcid == CLASS_Func) {
		if(ct->cparam->psize <= ct2->cparam->psize) {
			size_t i;
			for(i = 0; i < ct->cparam->psize; i++) {
				knh_param_t *p = knh_ParamArray_get(ct->cparam, i);
				knh_param_t *p2 = knh_ParamArray_get(ct2->cparam, i);
				if(p->type != p2->type) return 0;
			}
			if(ct->cparam->rsize == ct2->cparam->rsize) {
				if(ct->cparam->rsize == 1) {
					knh_param_t *r = knh_ParamArray_rget(ct->cparam, 0);
					knh_param_t *r2 = knh_ParamArray_rget(ct2->cparam, 0);
					if(r->type != r2->type) return 0;
				}
				return 1;
			}
		}
		return 0;
	}
	while(ct->cid != CLASS_Object) {
		knh_Array_t *a = ct->typemaps;
		size_t i;
		for(i = 0; i < knh_Array_size(a); i++) {
			knh_TypeMap_t *tmr = a->trans[i];
			if(tmr->tcid == reqt && TypeMap_isInterface(tmr)) return 1;
		}
		if(ct == ct->supTBL) return 0;
		ct = ct->supTBL;
		if(ct->cid == reqt) return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */
/* [class param] */

int knh_class_isGenerics(CTX ctx, knh_class_t cid)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	return (ct->cparam != NULL);
}

knh_bytes_t knh_class_bname(CTX ctx, knh_class_t bcid)
{
	return knh_bytes_head(S_tobytes(ClassTBL(bcid)->lname), '<');
}

static void knh_make_cname(CTX ctx, knh_OutputStream_t *w, knh_class_t cid)
{
	DBG_ASSERT(cid < ctx->share->sizeClassTBL);
	DBG_ASSERT(C_isGenerics(cid));
	knh_class_t bcid = C_bcid(cid);
	size_t i;
	knh_ParamArray_t *pa = ClassTBL(cid)->cparam;
	knh_bytes_t bname = knh_class_bname(ctx, bcid);
	knh_write(ctx, w, bname);
	knh_putc(ctx, w, '<');
	for(i = 0; i < pa->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		if(i > 0) knh_putc(ctx, w, ',');
		knh_write_cid(ctx, w, p->type);
	}
	if(pa->rsize > 0) {
		if(pa->psize == 0) knh_write(ctx, w, STEXT("void"));
		knh_write(ctx, w, STEXT("=>"));
	}
	for(i = 0; i < pa->rsize; i++) {
		knh_param_t *p = knh_ParamArray_rget(pa, i);
		if(i > 0) knh_putc(ctx, w, ',');
		knh_write_cid(ctx, w, p->type);
	}
	knh_putc(ctx, w, '>');
}

static void knh_make_tname(CTX ctx, knh_OutputStream_t *w, knh_class_t cid)
{
	DBG_ASSERT(cid < ctx->share->sizeClassTBL);
	DBG_ASSERT(C_isGenerics(cid));
	knh_class_t bcid = C_bcid(cid);
	knh_ParamArray_t *pa = ClassTBL(cid)->cparam;
	knh_class_t p1   = knh_ParamArray_get(pa, 0)->type;
	if(bcid == CLASS_Array) {
		knh_write_type(ctx, w, p1);
		knh_write(ctx, w, STEXT(PTYPE_Array));
	}
	else if(bcid == CLASS_Iterator) {
		knh_write_type(ctx, w, p1);
		knh_write(ctx, w, STEXT(PTYPE_Iterator));
	}
	else if(bcid == CLASS_KindOf) {
		knh_write_type(ctx, w, p1);
		knh_write(ctx, w, STEXT(PTYPE_KindOf));
	}
	else if(bcid == CLASS_Immutable) {
		knh_write_type(ctx, w, p1);
		knh_write(ctx, w, STEXT(PTYPE_Immutable));
	}
	else if(C_isGenerics(cid)) {
		size_t i;
		knh_bytes_t bname = knh_bytes_head(S_tobytes(ClassTBL(bcid)->sname), '<');
		knh_write(ctx, w, bname);
		knh_putc(ctx, w, '<');
		for(i = 0; i < pa->psize; i++) {
			knh_param_t *p = knh_ParamArray_get(pa, i);
			if(i > 0) knh_putc(ctx, w, ',');
			knh_write_type(ctx, w, p->type);
		}
		if(pa->rsize > 0) {
			if(pa->psize == 0) knh_write(ctx, w, STEXT("void"));
			knh_write(ctx, w, STEXT("=>"));
		}
		for(i = 0; i < pa->rsize; i++) {
			knh_param_t *p = knh_ParamArray_rget(pa, i);
			if(i > 0) knh_putc(ctx, w, ',');
			knh_write_type(ctx, w, p->type);
		}
		knh_putc(ctx, w, '>');
	}
}

/* ------------------------------------------------------------------------ */

static void SimTBL_append(CTX ctx, knh_class_t cid, knh_ClassTBL_t *newt)
{
	knh_ClassTBL_t *t = varClassTBL(cid);
	while(t->simTBL != NULL) {
		t = (knh_ClassTBL_t*)t->simTBL;
	}
	t->simTBL = (const knh_ClassTBL_t*)newt;
}

void knh_setClassParam(CTX ctx, knh_ClassTBL_t *t, knh_ParamArray_t *pa)
{
	size_t i, size = pa->psize + pa->rsize;
	KNH_INITv(t->cparam, pa);
	if(pa->psize > 0) {
		knh_param_t *p = knh_ParamArray_get(pa, 0);
		t->p1 = CLASS_t(p->type);
	}
	if(pa->psize > 1) {
		knh_param_t *p = knh_ParamArray_get(pa, 1);
		t->p2 = CLASS_t(p->type);
	}
	for(i = 0; i < size; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		if((p->type) >= TYPE_T1) {
			t->cflag |= FLAG_Class_TypeVariable;
		}
	}
}

static void ClassTBL_addTuple(CTX ctx, knh_ClassTBL_t *ct, const knh_ClassTBL_t *bct, knh_ParamArray_t *pa)
{
	size_t i, fi = 0;
	ct->magicflag  = bct->magicflag;
	ct->cflag  = bct->cflag;
	knh_setClassDef(ctx, ct, bct->cdef);
	ct->bcid   = bct->cid;
	ct->baseTBL = bct;
	ct->supcid = bct->supcid;
	ct->supTBL = ClassTBL(ct->supcid);
	knh_setClassParam(ctx, ct, pa);
	SimTBL_append(ctx, bct->cid, ct);

	knh_Tuple_t *tpl = (knh_Tuple_t*)new_hObject_(ctx, (knh_ClassTBL_t*)ct);
	Object_setNullObject(tpl, 1);
	knh_setClassDefaultValue(ctx, ct->cid, tpl, NULL);
	ct->fcapacity = pa->psize;
	DBLNDATA_(for(i = 0; i < pa->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		if(IS_Tunbox(p->type)) ct->fcapacity += 1;
	})
	ct->fsize = ct->fcapacity;
	ct->fields = (knh_fields_t*)KNH_MALLOC(ctx, sizeof(knh_fields_t) * ct->fcapacity);
	if(ct->fcapacity <= K_SMALLOBJECT_FIELDSIZE) {
		tpl->fields = &(tpl->smallobject);
	}
	else {
		tpl->fields = (knh_Object_t**)KNH_MALLOC(ctx, sizeof(knh_Object_t*) * ct->fcapacity);
	}
	knh_bzero(tpl->fields, sizeof(knh_Object_t*) * ct->fcapacity);
	for(i = 0; i < pa->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		ct->fields[fi].flag = FLAG_Field_Getter;
		ct->fields[fi].type = p->type;
		ct->fields[fi].fn = FN_key;
		ct->fields[fi].israw = 0;
		if(IS_Tunbox(p->type)) {
			ct->fields[fi].israw = 1;
			DBLNDATA_(fi++;
				ct->fields[fi].flag = 0;
				ct->fields[fi].fn = FN_NONAME;
				ct->fields[fi].type = TYPE_void;
				ct->fields[fi].israw = 1;)
		}
		else {
			KNH_INITv(tpl->fields[fi], KNH_NULVAL(CLASS_t(p->type)));
		}
		fi++;
	}
	KNH_INITv(ct->methods, bct->methods);
	KNH_INITv(ct->typemaps, K_EMPTYARRAY);
}

knh_class_t knh_addGenericsClass(CTX ctx, knh_class_t cid, knh_class_t bcid, knh_ParamArray_t *pa)
{
	if(cid == CLASS_newid) cid = new_ClassId(ctx);
	DBG_ASSERT(bcid < cid);
	knh_ClassTBL_t *ct = varClassTBL(cid);
	if(bcid == CLASS_Tuple) {
		ClassTBL_addTuple(ctx, ct, ClassTBL(bcid), pa);
	}
	else {
		const knh_ClassTBL_t *bct = ClassTBL(bcid);
		ct->magicflag  = bct->magicflag;
		ct->cflag  = bct->cflag;
		knh_setClassDef(ctx, ct, bct->cdef);
		ct->bcid   = bcid;
		ct->baseTBL = bct;
		ct->supcid = bct->supcid;
		ct->supTBL = ClassTBL(ct->supcid);
		knh_setClassParam(ctx, ct, pa);
		SimTBL_append(ctx, bcid, ct);
		ct->fields = bct->fields;
		ct->fsize  = bct->fsize;
		ct->fcapacity = bct->fcapacity;
		KNH_INITv(ct->methods, bct->methods);
		KNH_INITv(ct->typemaps, K_EMPTYARRAY);
	}
	{
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_String_t *lname, *sname;
		knh_make_cname(ctx, cwb->w, cid);
		lname = CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER|K_SPOLICY_ASCII);
		knh_make_tname(ctx, cwb->w, cid);
		sname = CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER|K_SPOLICY_ASCII);
		knh_setClassName(ctx, cid, lname, sname);
	}
	return cid;
}

/* ------------------------------------------------------------------------ */

knh_class_t knh_class_Generics(CTX ctx, knh_class_t bcid, knh_ParamArray_t *pa)
{
	const knh_ClassTBL_t *t = ClassTBL(bcid);
	while(t != NULL) {
		if(t->cparam != NULL && knh_ParamArray_equalsType(pa, t->cparam)) {
			return t->cid;
		}
		t = t->simTBL;
	}
	if(bcid == CLASS_Immutable) {
		knh_class_t p1 = knh_ParamArray_get(pa,0)->type;
		if(p1 < ctx->share->sizeClassTBL && class_isImmutable(p1)) return p1;
	}
	return knh_addGenericsClass(ctx, CLASS_newid, bcid, pa);
}

knh_class_t knh_class_P1(CTX ctx, knh_class_t bcid, knh_type_t p1)
{
	const knh_ClassTBL_t *ct = ClassTBL(bcid);
	while(ct != NULL) {
		if(ct->p1 == p1) return ct->cid;
		ct = ct->simTBL;
	}
	if(bcid == CLASS_Immutable && p1 < ctx->share->sizeClassTBL && class_isImmutable(p1)) {
		return p1;
	}
	{
		knh_ParamArray_t *bpa = ClassTBL(bcid)->cparam;
		knh_param_t *bp = knh_ParamArray_get(bpa, 0);
		knh_ParamArray_t *pa = new_ParamArray(ctx);
		knh_param_t p = {p1, bp->fn};
		knh_ParamArray_add(ctx, pa, p);
		return knh_addGenericsClass(ctx, CLASS_newid, bcid, pa);
	}
}

knh_class_t knh_class_P2(CTX ctx, knh_class_t bcid, knh_type_t p1, knh_type_t p2)
{
	const knh_ClassTBL_t *ct = ClassTBL(bcid);
	while(ct != NULL) {
		if(ct->p2 == p2 && ct->p1 == p1) return ct->cid;
		ct = ct->simTBL;
	}
	{
		knh_ParamArray_t *bpa = ClassTBL(bcid)->cparam;
		knh_param_t *bp = knh_ParamArray_get(bpa, 0);
		knh_ParamArray_t *pa = new_ParamArray(ctx);
		knh_param_t p = {p1, bp->fn};
		knh_ParamArray_add(ctx, pa, p);
		bp = knh_ParamArray_get(bpa, 1);
		p.type = p2; p.fn = bp->fn;
		knh_ParamArray_add(ctx, pa, p);
		return knh_addGenericsClass(ctx, CLASS_newid, bcid, pa);
	}
}

/* ------------------------------------------------------------------------ */

knh_bool_t knh_ParamArray_hasTypeVar(knh_ParamArray_t *pa)
{
	size_t i, size = pa->psize + pa->rsize;
	for(i = 0; i < size; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		if(!(p->type < TYPE_T0)) return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

void knh_ParamArray_tocid(CTX ctx, knh_ParamArray_t *pa, knh_class_t this_cid, knh_ParamArray_t *npa)
{
	size_t i, size = pa->psize + pa->rsize;
	for(i = 0; i < size; i++) {
		knh_param_t *cp = knh_ParamArray_get(pa, i);
		knh_param_t np = *cp;
		np.type = knh_type_tocid(ctx, np.type, this_cid);
		knh_ParamArray_add(ctx, npa, np);
	}
	npa->psize = pa->psize;
	npa->rsize = pa->rsize;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_class_t) knh_type_tocid(CTX ctx, knh_type_t ptype, knh_class_t this_cid)
{
	if(ptype == TYPE_This) {
		return this_cid;
	}
	else if(ptype > TYPE_This) {
		long ti = (long)ptype - (long)TYPE_T1;
		knh_ParamArray_t *tpa = ClassTBL(this_cid)->cparam;
		if(tpa != NULL && ti < (tpa)->psize + (tpa)->rsize) {
			knh_param_t *p = knh_ParamArray_get(tpa, ti);
			//DBG_P("this_cid=%d, p%d=%d", this_cid, ti+1, p->type);
			return CLASS_t(p->type);
		}
		return CLASS_Tvoid;
	}
	else {
		knh_class_t pcid = CLASS_t(ptype);
		if(C_isGenerics(pcid)) { /* Iterator<This> */
			BEGIN_LOCAL(ctx, lsfp, 1);
			knh_ParamArray_t *npa = new_ParamArray(ctx);
			KNH_SETv(ctx, lsfp[0].o, npa);
			knh_ParamArray_tocid(ctx, ClassTBL(pcid)->cparam, this_cid, npa);
			pcid = knh_class_Generics(ctx, C_bcid(pcid), npa);
			END_LOCAL(ctx, lsfp);
		}
		return pcid;
	}
}

/* ------------------------------------------------------------------------ */
/* [ParamArray] */

knh_ParamArray_t *new_ParamArrayR0(CTX ctx, knh_type_t t)
{
	knh_ParamArray_t *pa = new_ParamArray(ctx);
	knh_ParamArray_addReturnType(ctx, pa, t);
	return pa;
}

#define RTYPE_set(t)    TYPE_void

knh_ParamArray_t *new_ParamArrayP1(CTX ctx, knh_type_t rtype, knh_type_t p1, knh_fieldn_t fn1)
{
	knh_ParamArray_t *pa = new_ParamArray(ctx);
	knh_ParamArray_addParam(ctx, pa, p1, fn1);
	knh_ParamArray_addReturnType(ctx, pa, rtype);
	return pa;
}

/* ------------------------------------------------------------------------ */

void knh_ParamArray_add(CTX ctx, knh_ParamArray_t *pa, knh_param_t p)
{
	size_t size = pa->psize + pa->rsize;
	if(size == 0) {
		pa->p0 = p;
		pa->p2 = p;  // last
	}
	else if(size == 1) {
		pa->p1 = p;
		pa->p2 = p;  // last
	}
	else if(size == 2) {
		pa->p2 = p;
	}
	else if(size == 3) {
		knh_param_t *params = (knh_param_t*)KNH_MALLOC(ctx, K_FASTMALLOC_SIZE);
		params[0] = pa->p0;
		params[1] = pa->p1;
		params[2] = pa->p2;
		params[3] = p;
		pa->capacity = K_FASTMALLOC_SIZE / sizeof(knh_param_t);
		pa->params = params;
	}
	else {
		if(pa->capacity == size) {
			pa->params = (knh_param_t*)KNH_REALLOC(ctx, NULL, pa->params, pa->capacity, pa->capacity*2, sizeof(knh_param_t));
			pa->capacity *= 2;
		}
		pa->params[size] = p;
	}
	pa->psize += 1;
}

void knh_ParamArray_addParam(CTX ctx, knh_ParamArray_t *pa, knh_type_t type, knh_fieldn_t fn)
{
	knh_param_t p = {type, fn};
	knh_ParamArray_add(ctx, pa, p);
}

void knh_ParamArray_addReturnType(CTX ctx, knh_ParamArray_t *pa, knh_type_t type)
{
	if(type != TYPE_void) {
		knh_param_t p = {type, FN_return};
		knh_ParamArray_add(ctx, pa, p);
		pa->psize -= 1;
		pa->rsize += 1;
	}
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_param_t*) knh_ParamArray_get(knh_ParamArray_t *pa, size_t n)
{
	size_t size = pa->psize + pa->rsize;
	DBG_ASSERT(n <= size);
	if(size <= 3) {
		switch(n) {
			case 0: return &pa->p0;
			case 1: return &pa->p1;
			case 2: return &pa->p2;
			default: return &pa->p2;
		}
	}
	else {
		return pa->params + n;
	}
}

//knh_type_t knh_ParamArray_getptype(knh_ParamArray_t *pa, size_t n)
//{
//	if(!(n < pa->psize)) {
//		if(pa->psize == 0) return TYPE_dyn;
//		n = pa->psize-1;
//	}
//	return knh_ParamArray_get(pa, n)->type;
//}

KNHAPI2(knh_type_t) knh_Method_rtype(CTX ctx, knh_Method_t *mtd, knh_class_t this_cid)
{
	if(DP(mtd)->mp->rsize != 0) {
		knh_type_t rtype = knh_ParamArray_rget(DP(mtd)->mp, 0)->type;
		if(rtype >= TYPE_This) {
			return knh_type_tocid(ctx, rtype, this_cid);
		}
		return rtype;
	}
	return TYPE_void;
}

KNHAPI2(size_t) knh_Method_psize(knh_Method_t *mtd)
{
	return DP(mtd)->mp->psize;
}

KNHAPI2(knh_type_t) knh_Method_ptype(CTX ctx, knh_Method_t *mtd, size_t n, knh_class_t this_cid)
{
	knh_type_t ptype = knh_ParamArray_get(DP(mtd)->mp, n)->type;
	if(ptype >= TYPE_This) {
		return knh_type_tocid(ctx, ptype, this_cid);
	}
	return ptype;
}


/* ------------------------------------------------------------------------ */

knh_bool_t knh_ParamArray_equalsType(knh_ParamArray_t *pa, knh_ParamArray_t *pa2)
{
	size_t i;
	if(pa->psize != pa2->psize || pa->rsize != pa2->rsize) return 0;
	for(i = 0; i < pa->psize; i++) {
		knh_param_t *p = knh_ParamArray_get(pa, i);
		knh_param_t *p2 = knh_ParamArray_get(pa2, i);
		if(p->type != p2->type) return 0;
	}
	for(i = 0; i < pa->rsize; i++) {
		knh_param_t *p = knh_ParamArray_rget(pa, i);
		knh_param_t *p2 = knh_ParamArray_rget(pa2, i);
		if(p->type != p2->type) return 0;
	}
	return 1;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_type_t) knh_ParamArray_rtype(knh_ParamArray_t *pa)
{
	if(pa->rsize != 0) {
		knh_param_t *p = knh_ParamArray_rget(pa, 0);
		return p->type;
	}
	return (ParamArray_isRVAR(pa)) ? TYPE_var : TYPE_void;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_write_mn(CTX ctx, knh_OutputStream_t *w, knh_methodn_t mn)
{
	knh_bytes_t t = B(MN__(mn));
	if(MN_isFMT(mn)) {
		knh_putc(ctx, w, '%');
		knh_write(ctx, w, t);
	}
	else if(MN_isISBOOL(mn)) {
		knh_write(ctx, w, STEXT("is"));
		knh_write_cap(ctx, w, t, 0);
	}
	else if(MN_isGETTER(mn)) {
		knh_write(ctx, w, STEXT("get"));
		knh_write_cap(ctx, w, t, 0);
	}
	else if(MN_isSETTER(mn)) {
		knh_write(ctx, w, STEXT("set"));
		knh_write_cap(ctx, w, t, 0);
	}
	else {
		knh_write(ctx, w, t);
	}
}

/* ------------------------------------------------------------------------ */
/* [Method] */

static KMETHOD Fmethod_abstract(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	knh_type_t rtype = knh_type_tocid(ctx, knh_ParamArray_rtype(DP(mtd)->mp), O_cid(sfp[0].o));
	//KNH_SYSLOG(ctx, LOG_NOTICE, "AbstractMethod", "%C.%M", mtd->cid, mtd->mn);
	if(rtype != TYPE_void) {
		if(IS_Tunbox(rtype)) {
			RETURNi_(K_INT0);
		}
		else {
			RETURN_(KNH_NULVAL(CLASS_t(rtype)));
		}
	}
}

KNHAPI2(knh_bool_t) Method_isAbstract(knh_Method_t *mtd)
{
	return (mtd->fcall_1 == Fmethod_abstract);
}

void knh_Method_setFunc(CTX ctx, knh_Method_t *mtd, knh_Fmethod func)
{
	func = (func == NULL) ? Fmethod_abstract : func;
	(mtd)->fcall_1 = func;
	(mtd)->pc_start = CODE_FUNCCALL;
	DBG_ASSERT((mtd)->pc_start != NULL);
}

void knh_Method_toAbstract(CTX ctx, knh_Method_t *mtd)
{
	KNH_SETv(ctx, DP(mtd)->kcode, KNH_NULL);
	DP(mtd)->cfunc = NULL;
	knh_Method_setFunc(ctx, mtd, Fmethod_abstract);
}

/* ------------------------------------------------------------------------ */

knh_Method_t* new_Method(CTX ctx, knh_flag_t flag, knh_class_t cid, knh_methodn_t mn, knh_Fmethod func)
{
	knh_Method_t* mtd = new_(Method);
	DP(mtd)->flag  = flag;
	(mtd)->cid     = cid;
	(mtd)->mn      = mn;
	knh_Method_setFunc(ctx, mtd, func);
	return mtd;
}


/* ------------------------------------------------------------------------ */
/* [VirtualField] */

static KMETHOD Fmethod_getter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	RETURN_((sfp[0].ox)->fields[delta]);
}
static KMETHOD Fmethod_ngetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	knh_ndata_t *data = (knh_ndata_t*)(&(sfp[0].ox->fields[delta]));
	RETURNd_(data[0]);
}
static KMETHOD Fmethod_setter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	KNH_SETv(ctx, (sfp[0].ox)->fields[delta], sfp[1].o);
	RETURN_(sfp[1].o);
}
static KMETHOD Fmethod_nsetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	knh_ndata_t *ndata = (knh_ndata_t*)(&((sfp[0].ox)->fields[delta]));
	ndata[0] = sfp[1].ndata;
	RETURNd_(ndata[0]);
}
static KMETHOD Fmethod_kgetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	RETURN_((sfp[0].p)->kfields[delta]);
}
static KMETHOD Fmethod_kngetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	knh_ndata_t *data = (knh_ndata_t*)(&(sfp[0].p->kfields[delta]));
	RETURNd_(data[0]);
}
static KMETHOD Fmethod_ksetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	KNH_SETv(ctx, (sfp[0].p)->kfields[delta], sfp[1].o);
	RETURN_(sfp[1].o);
}
static KMETHOD Fmethod_knsetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int delta = DP(sfp[K_MTDIDX].mtdNC)->delta;
	knh_ndata_t *ndata = (knh_ndata_t*)(&((sfp[0].p)->kfields[delta]));
	ndata[0] = sfp[1].ndata;
	RETURNd_(ndata[0]);
}

static knh_Fmethod accessors[8] = {
	Fmethod_getter, Fmethod_setter, Fmethod_ngetter, Fmethod_nsetter,
	Fmethod_kgetter, Fmethod_ksetter, Fmethod_kngetter, Fmethod_knsetter,
};

#define _SETTER  1
#define _NDATA   2
#define _CPPOBJ  4

static knh_Method_t *new_GetterMethod(CTX ctx, knh_class_t cid, knh_methodn_t mn, knh_type_t type, int idx)
{
	//knh_Fmethod f = (IS_Tunbox(type)) ? Fmethod_ngetter : Fmethod_getter;
	knh_Fmethod f = accessors[(IS_Tunbox(type)?_NDATA:0)|((ClassTBL(cid)->bcid==CLASS_CppObject)?_CPPOBJ:0)];
	knh_Method_t *mtd = new_Method(ctx, 0, cid, mn, f);
	DP(mtd)->delta = idx;
	KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayR0(ctx, type));
	return mtd;
}

static knh_Method_t *new_SetterMethod(CTX ctx, knh_class_t cid, knh_methodn_t mn, knh_type_t type, int idx)
{
	//knh_Fmethod f = (IS_Tunbox(type)) ? Fmethod_nsetter : Fmethod_setter;
	knh_Fmethod f = accessors[_SETTER|(IS_Tunbox(type)?_NDATA:0)|((ClassTBL(cid)->bcid==CLASS_CppObject)?_CPPOBJ:0)];
	knh_Method_t *mtd = new_Method(ctx, 0, cid, mn, f);
	DP(mtd)->delta = idx;
	KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayP1(ctx, RTYPE_set(type), type, FN_UNMASK(mn)));
	return mtd;
}

knh_index_t knh_Method_indexOfGetterField(knh_Method_t *o)
{
	knh_Fmethod f = SP(o)->fcall_1;
	if(f== Fmethod_getter || f == Fmethod_ngetter) {
		return (knh_index_t)DP(o)->delta;
	}
	return -1;
}

knh_index_t knh_Method_indexOfSetterField(knh_Method_t *o)
{
	knh_Fmethod f = SP(o)->fcall_1;
	if(f == Fmethod_setter || f == Fmethod_nsetter) {
		return (knh_index_t)DP(o)->delta;
	}
	return -1;
}

/* ------------------------------------------------------------------------ */

knh_DictMap_t* knh_Object_getXData(CTX ctx, knh_Object_t *o)
{
	knh_DictMap_t *m;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->xdataidx != -1) {
		knh_Object_t **v = (ct->bcid == CLASS_Object) ? ((knh_ObjectField_t*)o)->fields : ((knh_RawPtr_t*)o)->kfields;
		m = (knh_DictMap_t*)v[ct->xdataidx];
		if(IS_NULL(m)) {
			m = new_DictMap0(ctx, 0, 1/*isCaseMap*/, "xdata");
			KNH_SETv(ctx, v[ct->xdataidx], m);
		}
	}
	else {
		if(!Object_isXData(o)) {
			m = new_DictMap0(ctx, 0, 1/*isCaseMap*/, "xdata");
			Object_setXData(o, 1);
			knh_PtrMap_add(ctx, ctx->share->xdataPtrMap, o, m);
		}
		else {
			m = (knh_DictMap_t*)knh_PtrMap_get(ctx, ctx->share->xdataPtrMap, o);
			DBG_ASSERT(m != NULL);
		}
	}
	return m;
}

static KMETHOD Fmethod_xgetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	if(Object_isXData(sfp[0].o) || O_cTBL(sfp[0].o)->xdataidx != -1) {
		knh_fieldn_t fn = DP(mtd)->delta;
		knh_String_t *n = knh_getFieldName(ctx, fn);
		knh_DictMap_t *m = knh_Object_getXData(ctx, sfp[0].o);
		Object *v = knh_DictMap_getNULL(ctx, m, S_tobytes(n));
		if(v != NULL) {
			RETURN_(v);
		}
	}
	knh_type_t rtype = knh_ParamArray_rtype(DP(mtd)->mp);
	RETURN_(KNH_NULVAL(rtype));
}

static KMETHOD Fmethod_xngetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	if(Object_isXData(sfp[0].o) || O_cTBL(sfp[0].o)->xdataidx != -1) {
		knh_fieldn_t fn = DP(mtd)->delta;
		knh_String_t *n = knh_getFieldName(ctx, fn);
		knh_DictMap_t *m = knh_Object_getXData(ctx, sfp[0].o);
		Object *v = knh_DictMap_getNULL(ctx, m, S_tobytes(n));
		if(v != NULL) {
			RETURNd_(O_ndata(v));
		}
	}
	RETURNd_(0);
}

static KMETHOD Fmethod_xsetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	knh_fieldn_t fn = DP(mtd)->delta;
	knh_String_t *n = knh_getFieldName(ctx, fn);
	knh_DictMap_t *m = knh_Object_getXData(ctx, sfp[0].o);
	knh_DictMap_set(ctx, m, n, sfp[1].o);
	RETURN_(sfp[1].o);
}

static KMETHOD Fmethod_xnsetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	knh_fieldn_t  fn = DP(mtd)->delta;
	knh_String_t  *n = knh_getFieldName(ctx, fn);
	knh_DictMap_t *m = knh_Object_getXData(ctx, sfp[0].o);
	knh_type_t p1 = knh_ParamArray_get(DP(mtd)->mp, 0)->type;
	knh_DictMap_set(ctx, m, n, new_Boxing(ctx, sfp+1, ClassTBL(p1)));
	RETURNd_(sfp[1].ndata);
}

void knh_ClassTBL_addXField(CTX ctx, const knh_ClassTBL_t *ct, knh_type_t type, knh_fieldn_t fn)
{
	knh_Fmethod f = (IS_Tunbox(type)) ? Fmethod_xngetter : Fmethod_xgetter;
	knh_Method_t *mtd = new_Method(ctx, 0, ct->cid, (type == CLASS_Boolean) ? MN_toISBOOL(fn) : MN_toGETTER(fn), f);
	DP(mtd)->delta = fn;
	KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayR0(ctx, type));
	knh_ClassTBL_addMethod(ctx, ct, mtd, 0/*isCheck*/);

	f = (IS_Tunbox(type)) ? Fmethod_xnsetter : Fmethod_xsetter;
	mtd = new_Method(ctx, 0, ct->cid, MN_toSETTER(fn), f);
	DP(mtd)->delta = fn;
	KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayP1(ctx, RTYPE_set(type), type, fn));
	knh_ClassTBL_addMethod(ctx, ct, mtd, 0/*isCheck*/);
}

knh_Method_t *knh_NameSpace_addXSetter(CTX ctx, knh_NameSpace_t *ns, const knh_ClassTBL_t *ct, knh_type_t type, knh_methodn_t mn_setter)
{
	if(FLAG_is(ct->cflag, FLAG_Class_Expando)) {
		knh_fieldn_t fn = FN_UNMASK(mn_setter);
		knh_methodn_t mn = (type == CLASS_Boolean) ? MN_toISBOOL(fn) : MN_toGETTER(fn);
		knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, ct->cid, mn);
		if(mtd == NULL) {
			knh_Fmethod f = (IS_Tunbox(type)) ? Fmethod_xngetter : Fmethod_xgetter;
			mtd = new_Method(ctx, 0, ct->cid, mn, f);
			DP(mtd)->delta = fn;
			KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayR0(ctx, type));
			knh_ClassTBL_addMethod(ctx, ct, mtd, 0/*isCheck*/);

			f = (IS_Tunbox(type)) ? Fmethod_xnsetter : Fmethod_xsetter;
			mtd = new_Method(ctx, 0, ct->cid, mn_setter, f);
			DP(mtd)->delta = fn;
			KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayP1(ctx, RTYPE_set(type), type, fn));
			knh_ClassTBL_addMethod(ctx, ct, mtd, 0/*isCheck*/);
			return mtd;
		}
	}
	return NULL;
}


/* ------------------------------------------------------------------------ */

static KMETHOD Fmethod_NoSuchMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[K_MTDIDX].mtdNC;
	KNH_ASSERT(IS_Method(mtd));
	knh_class_t cid = Method_isStatic(mtd) ? (mtd)->cid : O_cid(sfp[0].o);
	THROW_NoSuchMethod(ctx, sfp, cid, (mtd)->mn);
}

static knh_Method_t* new_NoSuchMethod(CTX ctx, knh_class_t cid, knh_methodn_t mn)
{
	knh_Method_t *mtd = new_Method(ctx, 0, cid, mn, Fmethod_NoSuchMethod);
	return mtd;
}

/* ------------------------------------------------------------------------ */

static inline knh_Method_t *Cache_setMethod(knh_mtdcache_t *mcache, knh_class_t cid, knh_methodn_t mn, knh_Method_t *mtd)
{
	DBG_ASSERT(mtd != NULL);
	knh_hashcode_t h = hashcode_mtd(cid, mn, K_MTDCACHE_SIZE);
	mcache = mcache + h;
	DBG_(
	if(mcache->cid != cid || mcache->mn != mn) {
		if(mcache->cid != 0 && mcache->mn != 0) {
			//DBG_P("MISSED h=%d mcache=%d.%d %d.%d", h, mcache->cid, mcache->mn, cid, mn);
		}
	});
	mcache->cid = cid;
	mcache->mn  = mn;
	mcache->mtd = mtd;
	return mtd;
}

void knh_ClassTBL_addMethod(CTX ctx, const knh_ClassTBL_t *t, knh_Method_t *mtd, int isCHECK)
{
	DBG_ASSERT(IS_Method(mtd));
	knh_Array_t *a = t->methods;
	if(unlikely(a == K_EMPTYARRAY)) {
		KNH_ASSERT(knh_Array_size(a) == 0);
		a = new_Array0(ctx, K_FASTMALLOC_SIZE/sizeof(knh_Method_t*));
		KNH_SETv(ctx, ((knh_ClassTBL_t*)t)->methods, a);
	}
//	if(isCHECK) {
//		size_t i;
//		for(i = 0; i < knh_Array_size(a); i++) {
//			knh_Method_t *mtd2 = a->methods[i];
//			if((mtd2)->mn == (mtd)->mn) {
//				knh_ldata_t ldata[] = {LOG_s("msg", "redefined method"), MDATA("method", CLASS__((mtd)->cid), MN__((mtd)->mn)), __TRACE__};
//				KNH_NTRACE(ctx, ("konoha");
//			}
//		}
//	}
	if(FLAG_is(t->cflag, FLAG_Class_Singleton)) {
		DP(mtd)->flag = DP(mtd)->flag | FLAG_Method_Static;
	}
	if(FLAG_is(t->cflag, FLAG_Class_Immutable)) {
		DP(mtd)->flag = DP(mtd)->flag | FLAG_Method_Immutable;
	}
	knh_enforceSecurity(ctx, mtd);
	knh_Array_add(ctx, a, mtd);
	Cache_setMethod(ctx->mtdcache, mtd->cid, mtd->mn, mtd);
}



knh_Method_t* knh_ClassTBL_findMethodNULL(CTX ctx, const knh_ClassTBL_t *ct, knh_methodn_t mn, int isGEN)
{
	{
		knh_class_t cid = ct->cid;
		knh_hashcode_t h = hashcode_mtd(cid, mn, K_MTDCACHE_SIZE);
		knh_mtdcache_t *mcache = ctx->mtdcache + h;
		if(mcache->cid == ct->cid && mcache->mn == mn) {
			//DBG_P("HIT h=%d mcache=%d.%d %d.%d", h, mcache->cid, mcache->mn, t->cid, mn);
			KNH_ASSERT(IS_Method(mcache->mtd));
			return mcache->mtd;
		}
	}
	{
		const knh_ClassTBL_t *p, *t0 = ct;
		do {
			size_t i;
			knh_Array_t *a = t0->methods;
			for(i = 0; i < knh_Array_size(a); i++) {
				knh_Method_t *mtd = a->methods[i];
				if((mtd)->mn == mn) {
					return Cache_setMethod(ctx->mtdcache, ct->cid, mn, mtd);
				}
			}
			p = t0;
			t0 = t0->supTBL;
		}
		while(p != t0);
	}
	if(MN_isSETTER(mn)) {
		knh_index_t idx;
		knh_fieldn_t fn = MN_toFN(mn);
		for(idx = (knh_index_t)ct->fsize - 1; idx >= 0 ; idx--) {
			knh_fields_t *cf = ct->fields + idx;
			if(cf->fn == fn) {
				if(!FLAG_is(cf->flag, FLAG_Field_Setter)) {
					continue;
				}else {
					knh_Method_t *mtd = new_SetterMethod(ctx, ct->cid, mn, cf->type, idx);
					knh_ClassTBL_addMethod(ctx, ct, mtd, 0);
					return Cache_setMethod(ctx->mtdcache, ct->cid, mn, mtd);
				}
			}
		}
		if(FLAG_is(ct->cflag, FLAG_Class_Expando)) {

		}
	}
	if(MN_isGETTER(mn) || MN_isISBOOL(mn)) {
		knh_index_t idx;
		knh_fieldn_t fn = MN_toFN(mn);
		for(idx = (knh_index_t)ct->fsize - 1; idx >= 0 ; idx--) {
			knh_fields_t *cf = ct->fields + idx;
			if(cf->fn == fn) {
				if(MN_isISBOOL(mn) && !IS_Tbool(cf->type)) {
					continue;
				}
				if(!FLAG_is(cf->flag, FLAG_Field_Getter)) {
					continue;
				}
				knh_Method_t *mtd = new_GetterMethod(ctx, ct->cid, mn, cf->type, idx);
				knh_ClassTBL_addMethod(ctx, ct, mtd, 0);
				return Cache_setMethod(ctx->mtdcache, ct->cid, mn, mtd);
			}
		}
		goto L_NoSuchMethod;
	}
	L_NoSuchMethod:;
	if(isGEN) {
		if(MN_isFMT(mn)) {
			DBG_P("Generating %%empty: cid=%s mn=%%%s", CLASS__(ct->cid), MN__(mn));
			return ClassTBL_getMethodNULL(ctx, ct, MN__empty);
		}
		else {
			knh_Method_t *mtd = new_NoSuchMethod(ctx, ct->cid, mn);
			knh_ClassTBL_addMethod(ctx, ct, mtd, 0);
			return Cache_setMethod(ctx->mtdcache, ct->cid, mn, mtd);
		}
	}
	else {
		return NULL;
	}
}

knh_Method_t *knh_ClassTBL_getFmtNULL(CTX ctx, const knh_ClassTBL_t *t, knh_methodn_t mn0)
{
	knh_methodn_t mn = mn0;
	knh_Method_t *mtd = knh_ClassTBL_findMethodNULL(ctx, t, mn, 0);
	if(mtd != NULL) {
		return Cache_setMethod(ctx->mtdcache, t->cid, mn0, mtd);
	}
	return NULL;
}

knh_Method_t *knh_ClassTBL_getFmt(CTX ctx, const knh_ClassTBL_t *t, knh_methodn_t mn0)
{
	knh_Method_t *mtd = knh_ClassTBL_getFmtNULL(ctx, t, mn0);
	if(mtd == NULL) {
		mtd = knh_ClassTBL_findMethodNULL(ctx, ClassTBL(CLASS_Object), MN__empty, 1);
		mtd = Cache_setMethod(ctx->mtdcache, t->cid, mn0, mtd);
	}
	//DBG_P("%s.%s => %s.%s", CLASS__(t->cid), MN__(mn0), CLASS__(mtd->cid), MN__(mtd->mn));
	return mtd;
}

/* ------------------------------------------------------------------------ */

void knh_NameSpace_addMethod(CTX ctx, knh_class_t mtd_cid, knh_Method_t *mtd)
{
	DBG_ASSERT(mtd_cid == mtd->cid);
	if(Method_isPrivate(mtd)) {
		KNH_TODO("Private Method");
	}
	else {
		//DBG_P("mtd=%p, %s.%s", mtd, CLASS__(mtd_cid), MN__(mtd->mn));
		knh_ClassTBL_addMethod(ctx, ClassTBL(mtd_cid), mtd, 0);
	}
}

knh_Method_t* knh_NameSpace_getMethodNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_methodn_t mn)
{
	while(ns != NULL) {
		if(DP(ns)->methodsNULL != NULL) {
			size_t i;
			knh_Array_t *methods = DP(ns)->methodsNULL;
			for(i = 0; i < knh_Array_size(methods); i++) {
				knh_Method_t *mtd = methods->methods[i];
				if(mtd->cid == cid && mtd->mn == mn) {
					return mtd;
				}
			}
		}
		ns = ns->parentNULL;
	}
	return ClassTBL_getMethodNULL(ctx, ClassTBL(cid), mn);
}

knh_Method_t* knh_NameSpace_getFmtNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_methodn_t mn)
{
	L_TAIL:;
	if(DP(ns)->formattersNULL != NULL) {
		knh_Array_t *a = DP(ns)->formattersNULL;
		size_t i;
		for(i = 0; i < knh_Array_size(a); i++) {
			knh_Method_t *mtd = a->methods[i];
			if((mtd)->cid == cid && (mtd)->mn == mn) {
				return mtd;
			}
		}
	}
	if(ns->parentNULL != NULL) {
		ns = ns->parentNULL;
		goto L_TAIL;
	}
	return knh_ClassTBL_getFmtNULL(ctx, ClassTBL(cid), mn);
}

void knh_NameSpace_addFmt(CTX ctx, knh_NameSpace_t *ns, knh_Method_t *mtd)
{
	if(DP(ns)->formattersNULL == NULL) {
		KNH_INITv(DP(ns)->formattersNULL, new_Array0(ctx, 0));
	}
	knh_Array_add(ctx, DP(ns)->formattersNULL, mtd);
}

KNHAPI2(void) knh_Func_invoke(CTX ctx, knh_Func_t *fo, knh_sfp_t *rtnsfp, int argc)
{
	knh_sfp_t *sfp = rtnsfp + K_CALLDELTA;
	if(fo->baseNULL != NULL) {
		KNH_SETv(ctx, sfp[0].o, fo->baseNULL);
	}
	klr_setmtdNC(ctx, sfp[K_MTDIDX], fo->mtd);
	((knh_context_t*)ctx)->esp = sfp + (argc + 1);
	(fo->mtd)->fcall_1(ctx, sfp, -K_CALLDELTA);
	((knh_context_t*)ctx)->esp = rtnsfp;
}

/* ------------------------------------------------------------------------ */
/* [MapType] */

static inline knh_TypeMap_t *Cache_getTypeMap(CTX ctx, knh_class_t scid, knh_class_t tcid)
{
	knh_hashcode_t h = hashcode_tmr(scid, tcid, K_TMAPCACHE_SIZE);
	knh_tmrcache_t *cache = ctx->tmrcache + h;
	if(cache->scid  == scid && cache->tcid == tcid) {
		return cache->tmr;
	}
	return NULL;
}

static inline knh_TypeMap_t *Cache_setTypeMap(CTX ctx, knh_class_t scid, knh_class_t tcid, knh_TypeMap_t *tmr)
{
	knh_hashcode_t h = hashcode_tmr(scid, tcid, K_TMAPCACHE_SIZE);
	knh_tmrcache_t *cache = ctx->tmrcache + h;
	cache->scid = scid;
	cache->tcid = tcid;
	cache->tmr = tmr;
	DBG_P("SETCACHE (%s=>%s) TMR %s=>%s",CLASS__(scid), CLASS__(tcid), TYPE__(tmr->scid), TYPE__(tmr->tcid));
	return tmr;
}

static void knh_readyTransMapList(CTX ctx, knh_class_t cid)
{
	DBG_ASSERT_cid(cid);
	knh_ClassTBL_t *t = varClassTBL(cid);
	if(t->typemaps == K_EMPTYARRAY) {
		KNH_ASSERT(knh_Array_size(t->typemaps) == 0);
		KNH_SETv(ctx, t->typemaps, new_Array0(ctx, 0));
	}
}

KNHAPI2(void) knh_addTypeMap(CTX ctx, knh_TypeMap_t *tmr, int initCache)
{
	knh_class_t cid = tmr->scid;
	knh_readyTransMapList(ctx, cid);
	knh_Array_add(ctx, ClassTBL(cid)->typemaps, tmr);
	if(initCache) {
		Cache_setTypeMap(ctx, tmr->scid, tmr->tcid, tmr);
	}
}

KNHAPI2(void) knh_TypeMap_exec(CTX ctx, knh_TypeMap_t *tmr, knh_sfp_t *sfp _RIX)
{
	if(TypeMap_isNDATA(tmr)) {
		KNH_SETv(ctx, sfp[K_TMRIDX].tmr, tmr);
		tmr->ftypemap_1(ctx, sfp, K_RIX);
	}
	else {
		KNH_SAFEPOINT(ctx, sfp);
		if(IS_NULL(sfp[0].o)) {
			KNH_SETv(ctx, sfp[K_RIX].o, KNH_NULVAL(tmr->tcid))
			sfp[K_RIX].ivalue = 0;
		}
		else {
			sfp[K_TMRIDX].tmrNC = tmr;
			tmr->ftypemap_1(ctx, sfp, K_RIX);
		}
	}
}

/* ------------------------------------------------------------------------ */

void knh_addTypeMapFunc(CTX ctx, knh_flag_t flag, knh_type_t stype, knh_type_t ttype, knh_Ftypemap fTYPEMAP, Object *mapdata)
{
	knh_class_t cid = CLASS_t(stype);
	DBG_ASSERT_cid(cid);
	knh_readyTransMapList(ctx, cid);
	knh_Array_add(ctx, ClassTBL(cid)->typemaps, new_TypeMap(ctx, flag, CLASS_t(stype), CLASS_t(ttype), fTYPEMAP));
}

/* ------------------------------------------------------------------------ */

static TYPEMAP Ftypemap_null(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KNH_TODO("null translator");
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_TypeMap_t*) new_TypeMap(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func)
{
	knh_TypeMap_t* tmr = new_(TypeMap);
	tmr->h.magicflag |= (knh_uintptr_t)flag;
	tmr->scid = scid;
	tmr->tcid = tcid;
	tmr->ftypemap_1 = (func == NULL) ? Ftypemap_null : func;
	if(IS_Tunbox(scid)) {
		TypeMap_setNDATA(tmr, 1);
	}
	return tmr;
}

KNHAPI2(knh_TypeMap_t*) new_TypeMapData(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func, Object *mapdata)
{
	knh_TypeMap_t* tmr = new_(TypeMap);
	tmr->h.magicflag |= (knh_uintptr_t)flag;
	tmr->scid = scid;
	tmr->tcid = tcid;
	tmr->ftypemap_1 = (func == NULL) ? Ftypemap_null : func;
	KNH_SETv(ctx, tmr->mapdata, mapdata);
	if(IS_Tunbox(scid)) {
		TypeMap_setNDATA(tmr, 1);
	}
	return tmr;
}

static TYPEMAP Ftypemap_method(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr = sfp[K_TMRIDX].tmrNC;
	knh_Method_t *mtd = tmr->mtd;
	knh_sfp_t *lsfp = ctx->esp;
	DBG_ASSERT(IS_Method(mtd));
	DBG_ASSERT(sfp < lsfp);
	KNH_SETv(ctx, lsfp[0+K_CALLDELTA+1].o, sfp[0].o);
//	lsfp[0+K_CALLDELTA+1].ndata = sfp[0].ndata;  // no necessary
	KNH_SCALL(ctx, lsfp, 0, mtd, 1);
	KNH_SETv(ctx, sfp[K_RIX].o, lsfp[0].o);
	sfp[K_RIX].ndata = lsfp[0].ndata;
}

static TYPEMAP Ftypemap_methodN(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr = sfp[K_TMRIDX].tmr;
	knh_Method_t *mtd = tmr->mtd;
	knh_sfp_t *lsfp = ctx->esp;
	DBG_ASSERT(IS_Method(mtd));
	DBG_ASSERT(sfp < lsfp);
//	KNH_SETv(ctx, lsfp[0+K_CALLDELTA+1].o, sfp[0].o); // no necessary
	lsfp[0+K_CALLDELTA+1].ndata = sfp[0].ndata;
	KNH_SCALL(ctx, lsfp, 0, mtd, 1);
	KNH_SETv(ctx, sfp[K_RIX].o, lsfp[0].o);
	sfp[K_RIX].ndata = lsfp[0].ndata;
}

knh_TypeMap_t *new_TypeMapMethod(CTX ctx, knh_flag_t flag, knh_Method_t *mtd)
{
	knh_class_t scid = knh_ParamArray_get(DP(mtd)->mp, 0)->type, tcid = knh_ParamArray_rtype(DP(mtd)->mp);
	knh_Ftypemap f = IS_Tunbox(scid) ? Ftypemap_methodN : Ftypemap_method;
	knh_TypeMap_t *tmr = new_TypeMap(ctx, flag, scid, tcid, f);
	KNH_SETv(ctx, tmr->mtd, mtd);
	return tmr;
}

static TYPEMAP Ftypemap_asis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(sfp[0].o);
}
static TYPEMAP FtypemapN_asis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNd_(sfp[0].ndata);
}
static TYPEMAP Ftypemap_unbox(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNd_(O_ndata(sfp[0].o));
}
static TYPEMAP FtypemapN_box(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr = sfp[K_TMRIDX].tmr; // N
	RETURN_(new_Boxing(ctx, sfp, ClassTBL(tmr->scid)));
}
static TYPEMAP Ftypemap_dcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0= sfp[K_TMRIDX].tmrNC;
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, O_cid(sfp[0].o), tmr0->tcid);
	if(tmr != NULL /*&& TypeMap_isSemantic(tmr)*/) {
		sfp[0].ndata = O_ndata(sfp[0].o);
		knh_TypeMap_exec(ctx, tmr, sfp, K_RIX);
	}
	else {
		sfp[K_RIX].ndata = 0;
		RETURN_(KNH_NULVAL(tmr0->scid));
	}
}

static knh_TypeMap_t *knh_getSubtypeMap(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_Ftypemap f = NULL;
	if(sct->cid == tct->cid || ClassTBL_isa_(ctx, sct, tct) || tct->cid == CLASS_Tdynamic) {
		if(IS_Tunbox(sct->cid)) {
			f = (IS_Tunbox(tct->cid)) ? FtypemapN_asis : FtypemapN_box;
		}
		else {
			f = (IS_Tunbox(tct->cid)) ? Ftypemap_unbox : Ftypemap_asis;
		}
	}
	else if(sct->cid == CLASS_Tdynamic) {
		f = Ftypemap_dcast;
	}
	if(f != NULL) {
		return new_TypeMap(ctx, FLAG_TypeMap_Semantic|FLAG_TypeMap_Interface, sct->cid, tct->cid, f);
	}
	return NULL;
}

///* ------------------------------------------------------------------------ */
///* [MapMap] */
//
//static TYPEMAP knh_Ftypemap_mapmap(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_TypeMap_t *trl = sfp[K_TMRIDX].trlNC;
//	DBG_ASSERT(IS_TypeMap(trl));
//	knh_TypeMap_t *m1 = DP(trl)->m1, *m2 = DP(trl)->m2;
//	DBG_ASSERT(IS_TypeMap(m1));
//	KNH_SETv(ctx, sfp[1].o, m1);
//	(m1)->ftypemap_1(ctx, sfp);
//	if(IS_NOTNULL(sfp[0].o)) {
//		DBG_ASSERT(IS_TypeMap(m2));
//		KNH_SETv(ctx, sfp[1].o, m2);
//		(m2)->ftypemap_1(ctx, sfp);
//	}
//}
//
///* ------------------------------------------------------------------------ */
//
//static knh_TypeMap_t* new_MapMap(CTX ctx, knh_TypeMap_t *m1, knh_TypeMap_t *m2)
//{
//	knh_TypeMap_t* trl = (knh_TypeMap_t*)new_Object_bcid(ctx, CLASS_TypeMap, 0);
//	KNH_SYSLOG(ctx, LOG_NOTICE, "generated mapper: %C => %C => %C", DP(m1)->scid, DP(m1)->tcid, DP(m2)->tcid);
//	DP(trl)->size = 0;
//	DP(trl)->flag = DP(m1)->flag | DP(m2)->flag;
//	SP(trl)->scid = DP(m1)->scid;
//	SP(trl)->tcid = DP(m2)->tcid;
//	DBG_ASSERT(IS_TypeMap(m1));
//	KNH_SETv(ctx, DP(trl)->m1, m1);
//	DBG_ASSERT(IS_TypeMap(m2));
//	KNH_SETv(ctx, DP(trl)->m2, m2);
//	trl->h.flag = m1->h.flag & m2->h.flag;
//	trl->ftypemap_1 = knh_Ftypemap_mapmap;
//	return trl;
//	return NULL;
//}


//
//
///* ------------------------------------------------------------------------ */
///* [RangeInt] */
//
////## @Semantic @Const mapper RangeInt ArrayInt;
//
//static TYPEMAP RangeInt_ArrayInt(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Range_t *rng = (knh_Range_t*)sfp[0].o;
//	knh_Array_t *a = new_Array(ctx, CLASS_Int, (rng->nend - rng->nstart) + 1);
//	knh_intptr_t i = 0, n;
//	for(n = (knh_intptr_t)rng->nstart; n <= (knh_intptr_t)rng->nend; n++) {
//		a->nlist[i] = n;
//		i++;
//	}
//	RETURN_(a);
//}


knh_bool_t TypeMap_isNoSuchMapping(knh_TypeMap_t *tmr)
{
	return ((tmr)->ftypemap_1 == Ftypemap_null);
}

void knh_addTypeMapRule(CTX ctx, knh_class_t scid, knh_class_t tcid, knh_Ftypemaprule func)
{
	knh_hashcode_t hkey = (knh_hashcode_t)scid;
	hkey = (hkey << (sizeof(knh_class_t) * 8)) + tcid;
	void *f = knh_PtrMap_get(ctx, ctx->share->inferPtrMap, (void*)hkey);
	if(f != NULL) {

	}
	knh_PtrMap_add(ctx, ctx->share->inferPtrMap, (void*)hkey, (void*)func);
}

static knh_Ftypemaprule knh_getTypeMapRule(CTX ctx, knh_class_t scid, knh_class_t tcid)
{
	knh_hashcode_t hkey = (knh_hashcode_t)scid;
	hkey = (hkey << (sizeof(knh_class_t) * 8)) + tcid;
	return (knh_Ftypemaprule)knh_PtrMap_get(ctx, ctx->share->inferPtrMap, (void*)hkey);
}

static knh_TypeMap_t *knh_findTypeMap1NULL(CTX ctx, const knh_ClassTBL_t *sct, knh_class_t tcid)
{
	knh_class_t scid = sct->cid;
	knh_TypeMap_t *tmr = Cache_getTypeMap(ctx, scid, tcid);
	if(tmr == NULL) {
		while(1) {
			size_t i;
			knh_Array_t *a = sct->typemaps;
			for(i = 0; i < (a)->size; i++) {
				tmr = (a)->trans[i];
				//DBG_P("?(%s,%s) looking %s=>%s..", TYPE__(scid), TYPE__(tcid), TYPE__(sct->cid), TYPE__(tmr->tcid));
				if(SP(tmr)->tcid == tcid) {
					return Cache_setTypeMap(ctx, scid, tcid, tmr);
				}
			}
			if(sct->supTBL == sct) return NULL;
			sct = sct->supTBL;
		}
		tmr = NULL;
	}
	return tmr;
}

KNHAPI2(knh_TypeMap_t*) knh_findTypeMapNULL(CTX ctx, knh_class_t scid0, knh_class_t tcid0)
{
	knh_TypeMap_t *tmr = NULL;
	DBG_P("finding.. %s ==> %s",CLASS__(scid0), CLASS__(tcid0));
	DBG_ASSERT(scid0 != tcid0);
	//if(scid0 == CLASS_Tvoid) return NULL;
	DBG_ASSERT(scid0 != CLASS_Tvar);
	{
		knh_hashcode_t h = hashcode_tmr(scid0, tcid0, K_TMAPCACHE_SIZE);
		knh_tmrcache_t *cache = ctx->tmrcache + h;
		if(cache->scid  == scid0 && cache->tcid == tcid0) {
			DBG_P("?(%s=>%s) HIT %s=>%s",CLASS__(scid0), CLASS__(tcid0), TYPE__(cache->tmr->scid), TYPE__(cache->tmr->tcid));
			return cache->tmr;
		}
	}
	DBG_ASSERT_cid(scid0); DBG_ASSERT_cid(tcid0);
	const knh_ClassTBL_t *sct = ClassTBL(scid0), *tct = ClassTBL(tcid0);
	while(1) {
		//DBG_P("finding3.. %s ==> %s",CLASS__(sct->cid), CLASS__(tct->cid));
		tmr = knh_findTypeMap1NULL(ctx, sct, tct->cid);
		if(tmr != NULL) return tmr;
		if(tct == tct->supTBL) break;
		tct = tct->supTBL;
	}

	tct = ClassTBL(tcid0);
	knh_Ftypemaprule frule = knh_getTypeMapRule(ctx, sct->bcid, tct->bcid);
	if(frule != NULL) {
		tmr = frule(ctx, sct, tct);
		if(tmr != NULL) {
			knh_addTypeMap(ctx, tmr, 0/*initCache*/);
			return Cache_setTypeMap(ctx, sct->cid, tct->cid, tmr);
		}
	}
	tmr = knh_getSubtypeMap(ctx, sct, tct);
	if(tmr != NULL) {
		return Cache_setTypeMap(ctx, sct->cid, tct->cid, tmr);
	}
//	size_t i;
//	knh_Array_t *a = sct->typemaps;
//	for(i = 0; i < (a)->size; i++) {
//		knh_TypeMap_t *tmr = (a)->trans[i], *tmr2;
//		if(!TypeMap_isSemantic(tmr)) continue;
//		tmr2 = knh_findTypeMapNULL(ctx, tmr->tcid, tcid0, isT);
//		if(tmr2 != NULL && TypeMap_isSemantics(tmr2)) {
//			tmr = new_TypeMap2(ctx, tmr, tmr2);
//			knh_addTypeMap(ctx, tmr);
//			goto L_SETCACHE;
//		}
//	}
	return NULL;
}

/* ------------------------------------------------------------------------ */
/* [TypeMapRule] */

/* Iterator => Iterator */

static ITRNEXT Iterator_Onext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *this_itr = ITR(sfp);
	knh_TypeMap_t *tmr = DP(this_itr)->tmrNULL;
	knh_Iterator_t *src_itr = (knh_Iterator_t*)DP(this_itr)->source;
	KNH_SETv(ctx, sfp[1].o, src_itr);
	while(1) {
		klr_setesp(ctx, sfp+2);
		if(src_itr->fnext_1(ctx, sfp + 1, 1)) { // => sfp[2]
			klr_setesp(ctx, sfp+3);
			sfp[2].ndata = O_ndata(sfp[2].o);   // unbox
			KNH_SETv(ctx, sfp[3].o, TS_EMPTY);  // set nonnull
			knh_TypeMap_exec(ctx, tmr, sfp+2, +1);
			if(IS_NULL(sfp[3].o)) continue;
			sfp[K_RIX].ndata = O_ndata(sfp[3].o);
			ITRNEXT_(sfp[3].o);
		}
		break;
	}
	ITREND_();
}

static ITRNEXT Iterator_Nnext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *this_itr = ITR(sfp);
	knh_TypeMap_t *tmr = DP(this_itr)->tmrNULL;
	knh_Iterator_t *src_itr = (knh_Iterator_t*)DP(this_itr)->source;
	KNH_SETv(ctx, sfp[1].o, src_itr);
	while(1) {
		klr_setesp(ctx, sfp+2);
		if(src_itr->fnext_1(ctx, sfp + 1, 1)) { // => sfp[2]
			klr_setesp(ctx, sfp+3);
			knh_TypeMap_exec(ctx, tmr, sfp+2, +1);
			sfp[K_RIX].ndata = sfp[3].ndata;
			KNH_SETv(ctx, sfp[3].o, new_Boxing(ctx, sfp+3, ClassTBL(tmr->scid)));
			ITRNEXT_(sfp[3].o);
		}
	}
	ITREND_();
}

static knh_Iterator_t* new_IteratorIterator(CTX ctx, knh_class_t cid, knh_Iterator_t *s)
{
	knh_Iterator_t *it = new_O(Iterator, cid);
	KNH_SETv(ctx, DP(it)->source, s);
	it->fnext_1 = Iterator_isNDATA(s) ? Iterator_Nnext : Iterator_Onext;
	knh_class_t sp1 = O_p1(s), tp1 = O_p1(it);
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
	KNH_ASSERT(tmr != NULL);
	KNH_INITv(DP(it)->tmrNULL, tmr);
	return it;
}

static TYPEMAP Iterator_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0 = sfp[K_TMRIDX].tmrNC;
	RETURN_(new_IteratorIterator(ctx, tmr0->scid, sfp[0].it));
}

static knh_TypeMap_t *knh_inferIteratorIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
	if(tmr != NULL) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Iterator_Iterator);
	}
	return NULL;
}

/* Array => Array */

static TYPEMAP Array_Array(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr = sfp[K_TMRIDX].tmrNC;
	knh_Array_t *sa = sfp[0].a;
	knh_Array_t *ta = (knh_Array_t*)new_Object_init2(ctx, ClassTBL(tmr->tcid));
	size_t i, tsize = knh_Array_size(sa);
	if(tsize > 0) {
		knh_Array_grow(ctx, ta, tsize, 8);
	}
	knh_sfp_t *lsfp = ctx->esp + 1;
	tmr = tmr->tmr1;
	//KNH_SETv(ctx, lsfp[0].o, TS_EMPTY);  // set nonnull for unbox map
	for(i = 0; i < tsize; i++) {
		sa->api->get(ctx, sa, i, lsfp);
		klr_setesp(ctx, lsfp+1); //added
		knh_TypeMap_exec(ctx, tmr, lsfp, +1);
		ta->api->add(ctx, ta, lsfp+1);
	}
	RETURN_(ta);
}

static knh_TypeMap_t *knh_inferArrayArray(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
	if(tmr != NULL) {
		return new_TypeMapData(ctx, 0, sct->cid, tct->cid, Array_Array, UPCAST(tmr));
	}
	return NULL;
}

/* Array => Iterator */

static knh_Array_t* new_ArrayClass(CTX ctx, knh_class_t cid, size_t capacity)
{
	knh_Array_t *a = (knh_Array_t*)new_Object_init2(ctx, ClassTBL(cid));
	if(capacity > 0) {
		knh_Array_grow(ctx, a, capacity, 8);
	}
	return a;
}

static ITRNEXT Array_nextO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_Array_t *a = (knh_Array_t*)DP(itr)->source;
	size_t pos = (size_t)DP(itr)->m.index;
	if(pos < a->size) {
		DP(itr)->m.index = pos + 1;
		ITRNEXT_(a->list[pos]);
	}
	ITREND_();
}

static ITRNEXT Array_nextN(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_Array_t *a = (knh_Array_t*)DP(itr)->source;
	size_t pos = (size_t)DP(itr)->m.index;
	if(pos < a->size) {
		DP(itr)->m.index = pos+1;
		ITRNEXTd_(a->nlist[pos]);
	}
	ITREND_();
}

knh_Iterator_t* new_ArrayIterator(CTX ctx, knh_Array_t *a)
{
	knh_class_t cid = O_p1(a);
	knh_Fitrnext fnext = Array_isNDATA(a) ? Array_nextN : Array_nextO;
	return new_IteratorG(ctx, knh_class_P1(ctx, CLASS_Iterator, cid), UPCAST(a), fnext);
}

knh_bool_t knh_isArrayIterator(knh_Iterator_t *itr)
{
	return (itr->fnext_1 == Array_nextO || itr->fnext_1 == Array_nextN);
}

static TYPEMAP Array_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0 = sfp[K_TMRIDX].tmrNC;
	knh_Fitrnext fnext = Array_isNDATA(sfp[0].a) ? Array_nextN : Array_nextO;
	RETURN_(new_IteratorG(ctx, tmr0->tcid, sfp[0].o, fnext));
}

static TYPEMAP Array_MIterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0 = sfp[K_TMRIDX].tmrNC;
	knh_Fitrnext fnext = Array_isNDATA(sfp[0].a) ? Array_nextN : Array_nextO;
	RETURN_(new_IteratorIterator(ctx, tmr0->scid, new_IteratorG(ctx, tmr0->tcid, sfp[0].o, fnext)));
}

static knh_TypeMap_t *knh_inferArrayIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	if(sp1 == tp1) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Array_Iterator);
	}
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
	if(tmr != NULL) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Array_MIterator);
	}

	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	return NULL;
}

/* Iterator => Array */

static knh_Array_t* Iterator_toArray(CTX ctx, knh_class_t tcid, knh_Iterator_t *itr)
{
	BEGIN_LOCAL(ctx, lsfp, 2);
	knh_Array_t *a = new_ArrayClass(ctx, tcid, 0);
	KNH_SETv(ctx, lsfp[0].o, a);
	KNH_SETv(ctx, lsfp[1].o, itr);
	klr_setesp(ctx, lsfp+2);
	while(itr->fnext_1(ctx, lsfp + 1, 1)) {
		a->api->add(ctx, a, lsfp + 2);
		klr_setesp(ctx, lsfp+2);
	}
	END_LOCAL(ctx, lsfp);
	return a;
}

static knh_Array_t* Iterator_toMArray(CTX ctx, knh_class_t tcid, knh_Iterator_t *itr, knh_TypeMap_t *tmr)
{
	BEGIN_LOCAL(ctx, lsfp, 2);
	knh_Array_t *a = new_ArrayClass(ctx, tcid, 0);
	KNH_SETv(ctx, lsfp[0].o, a);
	KNH_SETv(ctx, lsfp[1].o, itr);
	klr_setesp(ctx, lsfp+2);
	while(itr->fnext_1(ctx, lsfp + 1, 1)) {
		klr_setesp(ctx, lsfp+3);
		knh_TypeMap_exec(ctx, tmr, lsfp+2, +1);
		a->api->add(ctx, a, lsfp+3);
		klr_setesp(ctx, lsfp+2);
	}
	END_LOCAL(ctx, lsfp);
	return a;
}

static TYPEMAP Iterator_Array(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmrNC = sfp[K_TMRIDX].tmrNC;
	RETURN_(Iterator_toArray(ctx, tmrNC->tcid, sfp[0].it));
}

static TYPEMAP Iterator_MArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmrNC = sfp[K_TMRIDX].tmrNC;
	DBG_ASSERT(IS_TypeMap(tmrNC->tmr1));
	RETURN_(Iterator_toMArray(ctx, tmrNC->tcid, sfp[0].it, tmrNC->tmr1));
}

static knh_TypeMap_t *knh_inferIteratorArray(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	if(sp1 == tp1) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Iterator_Array);
	}
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
	if(tmr != NULL) {
		return new_TypeMapData(ctx, 0, sct->cid, tct->cid, Iterator_MArray, UPCAST(tmr));
	}
	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	return NULL;
}

static ITRNEXT Map_nextO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *itr = ITR(sfp);
	knh_Map_t *m = (knh_Map_t*)DP(itr)->source;
	knh_sfp_t *lsfp = ctx->esp;
	klr_setesp(ctx, lsfp+1);
	if(m->spi->next(ctx, m->mapptr, &(DP(itr)->m), lsfp)) {
		ITRNEXT_(lsfp[0].o);
	}
	else {
		ITREND_();
	}
}

static ITRNEXT Map_nextN(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Iterator_t *itr = ITR(sfp);
	knh_Map_t *m = (knh_Map_t*)DP(itr)->source;
	knh_sfp_t *lsfp = ctx->esp;
	klr_setesp(ctx, lsfp+1);
	if(m->spi->next(ctx, m->mapptr, &(DP(itr)->m), lsfp)) {
		ITRNEXTd_(lsfp[0].ndata);
	}
	else {
		ITREND_();
	}
}

static TYPEMAP Map_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0 = sfp[K_TMRIDX].tmrNC;
	knh_class_t p1 = O_p1(sfp[0].m);
	knh_Fitrnext fnext = IS_Tunbox(p1) ? Map_nextN : Map_nextO;
	RETURN_(new_IteratorG(ctx, tmr0->tcid, sfp[0].o, fnext));
}

static knh_TypeMap_t *knh_inferMapIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	if(sp1 == tp1) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Map_Iterator);
	}
	return NULL;
}

/* ------------------------------------------------------------------------- */

static knh_bool_t knh_NameSpace_dataCheck(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_sfp_t *sfp)
{
	knh_String_t *key = sfp[0].s;
	knh_Object_t *value = sfp[1].o;
	knh_methodn_t mn = knh_getmn(ctx, S_tobytes(key), MN_NEWID);
	DBG_P("key=%s", S_totext(key));
	knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, cid, MN_toSETTER(mn));
	if(mtd == NULL) {
		mtd = knh_NameSpace_addXSetter(ctx, ns, ClassTBL(cid), O_cid(value), MN_toSETTER(mn));
		if(mtd == NULL) return 0;
	}
	KNH_SETv(ctx, sfp[0].o, mtd); //
	if(knh_Method_psize(mtd) == 1) {
		knh_type_t ptype = knh_Method_ptype(ctx, mtd, 0, cid);
		if(ptype == O_cid(value) || ClassTBL_isa_(ctx, O_cTBL(value), ClassTBL(ptype))) {
			return 1; // ok
		}
		knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, O_cid(value), ptype);
		if(tmr != NULL) {
			klr_setesp(ctx, sfp+2);
			sfp[1].ndata = O_ndata(value); // unbox
			knh_TypeMap_exec(ctx, tmr, sfp+1, 0);
			knh_boxing(ctx, sfp+1, ptype);
			return 1;
		}
	}
	else {
		KNH_TODO("multi arguments");
	}
	return 0;
}

void knh_Object_fastset(CTX ctx, knh_Object_t *o, knh_Method_t *mtd, knh_Object_t *v)
{
	KNH_ASSERT(IS_Method(mtd));
	knh_index_t idx = knh_Method_indexOfSetterField(mtd);
	if(idx != -1) {
		knh_ObjectField_t *of = (knh_ObjectField_t*)o;
		if(IS_Tunbox(O_cid(v))) {
			knh_ndata_t *df = (knh_ndata_t*)(of->fields + idx);
			df[0] = O_ndata(v);
		}
		else {
			KNH_SETv(ctx, of->fields[idx], v);
		}
		return;
	}
	if(knh_Method_psize(mtd) == 1) {
		BEGIN_LOCAL(ctx, lsfp, 0);
		size_t rtnidx = 0, thisidx = rtnidx + K_CALLDELTA;
		KNH_SETv(ctx, lsfp[thisidx].o, o);
		KNH_SETv(ctx, lsfp[thisidx+1].o, v);
		lsfp[thisidx+1].ndata = O_ndata(v);
		KNH_SCALL(ctx, lsfp, rtnidx, mtd, 1);
		END_LOCAL(ctx, lsfp)
	}
}

void knh_Object_setData(CTX ctx, knh_Object_t *o, knh_Map_t *m, knh_NameSpace_t *ns, int Checked)
{
	knh_sfp_t *lsfp = ctx->esp;
	knh_nitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	if(Checked) {
		while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
			klr_setesp(ctx, lsfp+2);
			knh_Object_fastset(ctx, o, lsfp[0].mtd, lsfp[1].o);
			klr_setesp(ctx, lsfp+1);
		}
	}
	else {
		knh_class_t cid = O_cid(o);
		while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
			if(knh_NameSpace_dataCheck(ctx, ns, cid, lsfp)) {
				klr_setesp(ctx, lsfp+2);
				knh_Object_fastset(ctx, o, lsfp[0].mtd, lsfp[1].o);
			}
			klr_setesp(ctx, lsfp+1);
		}
	}
	klr_setesp(ctx, lsfp);
}

static TYPEMAP Map_Object(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr0 = sfp[K_TMRIDX].tmrNC;
	BEGIN_LOCAL(ctx, lsfp, 1);
	KNH_SETv(ctx, lsfp[0].o, new_Object_init2(ctx, ClassTBL(tmr0->tcid)));
	klr_setesp(ctx, lsfp+1);
	knh_Object_setData(ctx, lsfp[0].o, sfp[0].m, NULL, 0/*Checked*/);
	END_LOCAL(ctx, lsfp);
	RETURN_(lsfp[0].o);
}

static knh_TypeMap_t *knh_inferMapObject(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	if(sct->p1 == CLASS_String) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Map_Object);
	}
	return NULL;
}

static TYPEMAP Object_Map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	BEGIN_LOCAL(ctx, lsfp, 1);
	knh_DictMap_t *dm = new_DictMap0(ctx, 0, 1/*isCaseMap*/, NULL);
	KNH_SETv(ctx, lsfp[0].o, dm);
	size_t rtnidx = 1, thisidx = rtnidx + K_CALLDELTA;
	const knh_ClassTBL_t *ct = O_cTBL(sfp[0].o);
	knh_class_t this_cid = ct->cid;
	while(ct->cid != CLASS_Object) {
		size_t i, size = knh_Array_size(ct->methods);
		for(i = 0; i < size; i++) {
			knh_Method_t *mtd = ct->methods->methods[i];
			if(knh_Method_psize(mtd) == 0 && (MN_isGETTER(mtd->mn) || MN_isISBOOL(mtd->mn))) {
				knh_String_t *key = knh_getFieldName(ctx, FN_UNMASK(mtd->mn));
				DBG_P("key=%s", S_totext(key));
				KNH_SETv(ctx, lsfp[thisidx].o, sfp[0].o);
				KNH_SCALL(ctx, lsfp, rtnidx, mtd, 0);
				knh_type_t rtype = knh_Method_rtype(ctx, mtd, this_cid);
				knh_boxing(ctx, lsfp+rtnidx, rtype);
				knh_DictMap_append(ctx, dm, key, lsfp[rtnidx].o);
			}
		}
		ct = ct->supTBL;
	}
//	knh_DictMap_sort(ctx, dm);
	END_LOCAL(ctx, lsfp);
	RETURN_(dm);
}

static void ClassTBL_checkGetter(CTX ctx, const knh_ClassTBL_t *sct)
{
	size_t i;
	for(i = 0; i < sct->fsize; i++) {
		knh_type_t ftype = sct->fields[i].type;
		if(!FLAG_is(sct->fields[i].flag, FLAG_Field_Getter)) continue;
		if(ftype == TYPE_void) continue;
		knh_methodn_t mn = (ftype == TYPE_Boolean) ? MN_toISBOOL(sct->fields[i].fn) : MN_toGETTER(sct->fields[i].fn);
		knh_NameSpace_getMethodNULL(ctx, NULL, sct->cid, mn);
	}
}

static knh_TypeMap_t *knh_inferObjectMap(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	if(tct->p1 == CLASS_String && tct->p2 == CLASS_Tdynamic) {
		ClassTBL_checkGetter(ctx, sct);

		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Object_Map);
	}
	return NULL;
}

/* ------------------------------------------------------------------------ */

void knh_loadSystemTypeMapRule(CTX ctx)
{
	knh_addTypeMapRule(ctx, CLASS_Iterator, CLASS_Array,    knh_inferIteratorArray);
	knh_addTypeMapRule(ctx, CLASS_Iterator, CLASS_Iterator, knh_inferIteratorIterator);
//	knh_addTypeMapRule(ctx, CLASS_Tdynamic, CLASS_Iterator, knh_inferDynamicIterator);
	knh_addTypeMapRule(ctx, CLASS_Array,    CLASS_Iterator, knh_inferArrayIterator);
	knh_addTypeMapRule(ctx, CLASS_Array,    CLASS_Array,    knh_inferArrayArray);
	knh_addTypeMapRule(ctx, CLASS_Map,      CLASS_Iterator,    knh_inferMapIterator);
	knh_addTypeMapRule(ctx, CLASS_Map,      CLASS_Object,   knh_inferMapObject);
	knh_addTypeMapRule(ctx, CLASS_Object,   CLASS_Map,      knh_inferObjectMap);

}

/* ------------------------------------------------------------------------ */

void knh_NameSpace_setLinkClass(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t linkname, const knh_ClassTBL_t *ct)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Bytes_write(ctx, cwb->ba, knh_bytes_head(linkname, ':'));
	knh_Bytes_putc(ctx, cwb->ba, ':');
	if(DP(ns)->name2ctDictSetNULL == NULL) {
		KNH_INITv(DP(ns)->name2ctDictSetNULL, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "NameSpace.name2cid"));
	}
	knh_DictSet_set(ctx, DP(ns)->name2ctDictSetNULL, CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER|K_SPOLICY_ASCII), (knh_uintptr_t)ct);
}

const knh_ClassTBL_t *knh_NameSpace_getLinkClassTBLNULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path, knh_class_t tcid)
{
	if(path.text[0] == 't' && path.text[1] == 'o' && (path.text[2] == ':' || path.text[2] == 0)) {
		if(CLASS_Converter <= tcid && tcid <= CLASS_StringConverter) return ClassTBL(tcid);
		return ClassTBL(CLASS_Converter);
	}
	knh_bytes_t scheme = knh_bytes_head(path, ':');
	knh_class_t cid = CLASS_unknown; /* = knh_NameSpace_getcid(ctx, ns, scheme);*/
	if(islower(scheme.buf[0]) && scheme.len < 81) {
		char buf[128] = {0}; // zero clear
		knh_memcpy(buf, scheme.text, scheme.len);
		buf[scheme.len] = ':';
		cid = knh_NameSpace_getcid(ctx, ns, B(buf));
	}
	if(cid == CLASS_unknown) {
		cid = knh_NameSpace_getcid(ctx, ns, scheme);
	}
	if(cid != CLASS_unknown) {
		knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, cid, MN_opLINK);
		if(mtd != NULL) return ClassTBL(cid);
	}
	return NULL;
}

knh_class_t knh_ClassTBL_linkType(CTX ctx, const knh_ClassTBL_t *ct, knh_class_t tcid)
{
	if(tcid == CLASS_String || tcid == CLASS_Boolean) return tcid;
	if(ct->cid == tcid || ClassTBL_isa_(ctx, ct, ClassTBL(tcid))) {
		return ct->cid;
	}
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, ct->cid, tcid);
	return (tmr != NULL) ? tmr->tcid : CLASS_unknown;
}

knh_Object_t *knh_NameSpace_newObject(CTX ctx, knh_NameSpace_t *ns, knh_String_t *path, knh_class_t tcid)
{
	if(tcid == CLASS_String) return UPCAST(path);
	const knh_ClassTBL_t *ct = knh_NameSpace_getLinkClassTBLNULL(ctx, ns, S_tobytes(path), tcid);
	Object *value = NULL;
	if(ct == NULL) {
		if(tcid == CLASS_Boolean) return KNH_FALSE;
		LANG_LOG("link not found: %s as %s", S_totext(path), CLASS__(tcid));
		return KNH_NULVAL(tcid);
	}
	else {
		BEGIN_LOCAL(ctx, lsfp, 3 + K_CALLDELTA);
		knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, ct->cid, MN_opLINK);
		DBG_ASSERT(mtd != NULL);
		long rtnidx = 0, thisidx = rtnidx + K_CALLDELTA;
		KNH_SETv(ctx, lsfp[thisidx+1].o, path);
		KNH_SETv(ctx, lsfp[thisidx+2].o, ns);
		KNH_SCALL(ctx, lsfp, rtnidx, mtd, (3));
		knh_boxing(ctx, lsfp + rtnidx, ct->cid);
		value = lsfp[rtnidx].o;
		END_LOCAL(ctx, lsfp);
	}
	if(O_cid(value) == tcid || ClassTBL_isa_(ctx, O_cTBL(value), ClassTBL(tcid))) {
		return value;
	}
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, O_cid(value), tcid);
	if(tmr == NULL) {
		if(tcid == CLASS_Boolean) {
			DBG_P("IS_NULL(value)=%d", IS_NULL(value));
			value = (IS_NULL(value)) ? KNH_FALSE : KNH_TRUE;
			return value;
		}
		return KNH_NULVAL(tcid);
	}
	else {
		BEGIN_LOCAL(ctx, lsfp, 1);
		KNH_SETv(ctx, lsfp[0].o, value);
		lsfp[0].ndata = O_ndata(value);
		klr_setesp(ctx, lsfp+1);
		knh_TypeMap_exec(ctx, tmr, lsfp, 1);
		knh_boxing(ctx, lsfp, tmr->tcid);
		value = lsfp[1].o;
		END_LOCAL(ctx, lsfp);
	}
	return value;
}

/* ------------------------------------------------------------------------ */

// boolean Object.hasMethod();
static KMETHOD Object_hasMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_methodn_t mn = knh_getmn(ctx, S_tobytes(sfp[1].s), MN_NONAME);
	knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, O_cid(sfp[0].o), mn);
	RETURNb_(mtd != NULL);
}

// dynamic Object.invokeMethod(String method, dynamic a, ...);
static KMETHOD Object_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_methodn_t mn = knh_getmn(ctx, S_tobytes(sfp[1].s), MN_NONAME);
	knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, O_cid(sfp[0].o), mn);
	if(mtd == NULL) {
		LANG_LOG("Object.invokeMethod: no such method %s.%s", S_totext(O_cTBL(sfp[0].o)->lname), S_totext(sfp[1].s));
		RETURN_(KNH_NULL);
	}
	size_t i, psize = knh_Method_psize(mtd), rtnidx = K_RIX;
	knh_class_t this_cid = O_cid(sfp[0].o);
	knh_sfp_t *esp = ctx->esp;
	for(i = 0; i < psize; i++) {
		knh_type_t ptype = knh_Method_ptype(ctx, mtd, i, this_cid);
		Object *v = sfp + (2+i) < esp ? sfp[2+i].o: KNH_NULVAL(ptype);
		knh_type_t vtype = O_cid(v);
		if(vtype == ptype || ClassTBL_isa_(ctx, O_cTBL(v), ClassTBL(ptype))) {
			if(IS_Tunbox(ptype)) {
				sfp[1+i].ndata = O_ndata(v);
			}
			else {
				KNH_SETv(ctx, sfp[1+i].o, v);
			}
			continue;
		}
		knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, vtype, ptype);
		if(tmr != NULL) {
			if(IS_Tunbox(vtype)) {
				esp[0].ndata = O_ndata(v);
			}
			else {
				KNH_SETv(ctx, esp[0].o, v);
			}
			knh_TypeMap_exec(ctx, tmr, esp, &sfp[i+1] - esp);
			continue;
		}
		LANG_LOG("Object.invokeMethod: type error %s.%s(#%d)", S_totext(O_cTBL(sfp[0].o)->lname), MN__(mn), i+1);
		RETURN_(KNH_NULL);
	}
	KNH_SCALL(ctx, sfp, rtnidx, mtd, psize);
}

static knh_bool_t ClassTBL_addXField(CTX ctx, const knh_ClassTBL_t *ct, knh_type_t type, knh_String_t *name)
{
	knh_fieldn_t fn = knh_getmn(ctx, S_tobytes(name), FN_NEWID);  // FIXME: NOIZE
	knh_Method_t *mtd = knh_ClassTBL_findMethodNULL(ctx, ct, MN_toSETTER(fn), 0);
	if(mtd != NULL) {
		LANG_LOG("already defined setter: %s.%s", S_totext(ct->lname), S_totext(name));
		return 0;
	}
	mtd = knh_ClassTBL_findMethodNULL(ctx, ct, (type == CLASS_Boolean) ? MN_toISBOOL(fn) : MN_isGETTER(fn), 0);
	if(mtd != NULL) {
		LANG_LOG("already defined getter: %s.%s", S_totext(ct->lname), S_totext(name));
		return 0;
	}
	knh_ClassTBL_addXField(ctx, ct, type, fn);
	return 1;
}

// boolean System.addClassField(Class c, Class type, String name)
static KMETHOD System_addClassField(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(ClassTBL_addXField(ctx, (sfp[1].c)->cTBL, (sfp[2].c)->type, sfp[3].s));
}

static knh_Array_t *new_MethodList(CTX ctx, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	knh_Array_t *ma = new_Array(ctx, CLASS_Method, knh_Array_size(ct->methods));
	size_t i;
	for(i = 0; i < knh_Array_size(ct->methods); i++) {
		knh_Method_t *mtd = ct->methods->methods[i];
		if(MN_isFMT(mtd->mn) || Method_isHidden(mtd)) continue;
		knh_Array_add(ctx, ma, mtd);
	}
	while(ns != NULL) {
		if(DP(ns)->methodsNULL != NULL) {
			knh_Array_t *methods = DP(ns)->methodsNULL;
			for(i = 0; i < knh_Array_size(methods); i++) {
				knh_Method_t *mtd = methods->methods[i];
				if(mtd->cid != ct->cid) continue;
				if(MN_isFMT(mtd->mn) || Method_isHidden(mtd)) continue;
				knh_Array_add(ctx, ma, mtd);
			}
		}
		ns = ns->parentNULL;
	}
	return ma;
}

// Method[] Object.getMethods(NameSpace _)
static KMETHOD Object_getMethods(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_MethodList(ctx, O_cTBL(sfp[0].o), sfp[1].ns));
}

// Method[] Object.getMethods(NameSpace _)
static KMETHOD Class_getMethods(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_MethodList(ctx, (sfp[0].c)->cTBL, sfp[1].ns));
}

// Class Class.opLINK(String path, NameSpace _)
static KMETHOD Class_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_NameSpace_t *ns = sfp[2].ns;
	knh_bytes_t bpath = knh_bytes_next(S_tobytes(sfp[1].s), ':');
	knh_class_t cid = knh_getcid(ctx, bpath);
	if(cid == CLASS_unknown) {
		bpath = knh_bytes_head(bpath, '<');
		cid = knh_getcid(ctx, bpath);
		if(cid == CLASS_unknown) {
			cid = CLASS_Tvoid;
		}
	}
	RETURN_(new_Type(ctx, cid));
}

// @Static Class[] Class.query(String query)
static KMETHOD Class_query(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i, csize = ctx->share->sizeClassTBL;
	knh_Array_t *ca = new_Array(ctx, CLASS_Class, csize);
	knh_bytes_t q = S_tobytes(sfp[1].s);
	for(i = 0; i < csize; i++) {
		knh_class_t cid = (knh_class_t)i;
		const knh_ClassTBL_t *ct = ClassTBL(cid);
		DBG_P("lname=%s", S_totext(ct->lname));
		if(!knh_bytes_startsWith_(S_tobytes(ct->lname), q)) continue;
		knh_Array_add(ctx, ca, new_Type(ctx, cid));
	}
	RETURN_(ca);
}

// Method Method.opLINK(String path, NameSpace _)
static KMETHOD Method_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_NameSpace_t *ns = sfp[2].ns;
	knh_bytes_t bpath = knh_bytes_next(S_tobytes(sfp[1].s), ':');
	knh_index_t loc = knh_bytes_rindex(bpath, '.');
	knh_Method_t *mtd = NULL;
	if(loc != -1) {
		knh_bytes_t cpath = knh_bytes_first(bpath, loc);
		knh_bytes_t mpath = knh_bytes_last(bpath, loc+1);
		knh_class_t cid = knh_NameSpace_getcid(ctx, ns, cpath);
		knh_methodn_t mn = knh_getmn(ctx, mpath, MN_NONAME);
		if(cid != CLASS_unknown && mn != MN_NONAME) {
			mtd = knh_NameSpace_getMethodNULL(ctx, ns, cid, mn);
		}
	}
	if(mtd == NULL) {
		mtd = KNH_TNULL(Method);
	}
	RETURN_(mtd);
}

// @Const Boolean Method.isAbstract();
static KMETHOD Method_isAbstract_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(Method_isAbstract(sfp[0].mtd));
}

// @Const Boolean Method.isPrivate();
static KMETHOD Method_isPrivate_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(Method_isPrivate(sfp[0].mtd));
}

// @Const String Method.getName();
static KMETHOD Method_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_mn(ctx, cwb->w, (sfp[0].mtd)->mn);
	RETURN_(CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER|K_SPOLICY_ASCII));
}

// @Const Class Method.getReturnType();
static KMETHOD Method_getReturnType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_type_t rtype = knh_ParamArray_rtype(DP(sfp[0].mtd)->mp);
	if(rtype >= TYPE_This) {
		rtype = knh_type_tocid(ctx, rtype, (sfp[0].mtd)->cid);
	}
	RETURN_(new_Type(ctx, rtype));
}

// @Const Class[] Method.getParamTypes();
static KMETHOD Method_getParamTypes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ParamArray_t *pa = DP(sfp[0].mtd)->mp;
	knh_Array_t *ma = new_Array(ctx, CLASS_Method, pa->psize);
	size_t i;
	for(i = 0; i < pa->psize; i++) {
		knh_type_t ptype = knh_ParamArray_get(pa, i)->type;
		if(ptype >= TYPE_This) {
			ptype = knh_type_tocid(ctx, ptype, (sfp[0].mtd)->cid);
		}
		knh_Array_add(ctx, ma, new_Type(ctx, ptype));
	}
	RETURN_(ma);
}

// @Const String[] Method.getParamNames();
static KMETHOD Method_getParamNames(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ParamArray_t *pa = DP(sfp[0].mtd)->mp;
	knh_Array_t *ma = new_Array(ctx, CLASS_String, pa->psize);
	size_t i;
	for(i = 0; i < pa->psize; i++) {
		knh_fieldn_t fn = knh_ParamArray_get(pa, i)->fn;
		knh_Array_add(ctx, ma, knh_getFieldName(ctx, fn));
	}
	RETURN_(ma);
}

// @Const String Method.getSourceCode();
static KMETHOD Method_getSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[0].mtd;
	knh_Term_t *tk = DP(mtd)->tsource;
	RETURN_(IS_Term(tk)
			? tk->text : KNH_TNULL(String));
}

#define FuncData(X) {#X , X}
static knh_FuncData_t FuncData[] = {
	FuncData(Object_hasMethod),
	FuncData(Object_invokeMethod),
	FuncData(System_addClassField),
	FuncData(Object_getMethods),
	FuncData(Class_getMethods),
	FuncData(Class_opLINK),
	FuncData(Class_query),
	FuncData(Method_opLINK),
	{"Method_isAbstract", Method_isAbstract_},
	{"Method_isPrivate", Method_isPrivate_},
	FuncData(Method_getName),
	FuncData(Method_getReturnType),
	FuncData(Method_getParamTypes),
	FuncData(Method_getParamNames),
	FuncData(Method_getSourceCode),
	{NULL, NULL},
};

void knh_initClassFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadFuncData(ctx, FuncData);
}


/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
