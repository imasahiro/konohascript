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

//knh_String_t *knh_Object_getkey(CTX ctx, Object *o)
//{
//	knh_sfp_t lsfp;
//	lsfp.o = o;
//	lsfp.data = ((knh_Int_t*)o)->n.data;
//	return (knh_String_t*)ClassTBL(O_bcid(o))->cspi->hashkey(ctx, &lsfp, KNH_FOBJECT_KEY);
//}

//knh_hashcode_t knh_Object_hashCode(CTX ctx, Object *o)
//{
//	knh_sfp_t lsfp;
//	lsfp.o = o;
//	lsfp.data = ((knh_Int_t*)o)->n.data;
//	return (knh_hashcode_t)ClassTBL(O_bcid(o))->cspi->hashkey(ctx, &lsfp, KNH_FOBJECT_HASH);
//}

/* ------------------------------------------------------------------------ */

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

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_Object_toNULL_(CTX ctx, Object *o)
{
	Object_setNullObject(o, 1);
}

/* ------------------------------------------------------------------------ */

static void nofree(void *p)
{
}

KNHAPI2(knh_RawPtr_t*) new_RawPtr(CTX ctx, knh_RawPtr_t *po, void *rawptr)
{
	knh_RawPtr_t *npo = (knh_RawPtr_t*)new_hObject_(ctx, O_cTBL(po));
	npo->rawptr = rawptr;
	if(rawptr == NULL) {
		knh_Object_toNULL(ctx, npo);
	}
	npo->rawfree = nofree;
	return npo;
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
		return S_tochar(ClassTBL(cid)->sname);
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
		return S_tochar(ClassTBL(cid)->lname);
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
	const knh_ClassTBL_t *t = ClassTBL(cid);
	if(t->typeNULL == NULL) {
		knh_Class_t *o = new_(Class);
		o->cid = cid;
		o->type = cid;
		o->cTBL = t;
		KNH_INITv(((knh_ClassTBL_t*)t)->typeNULL, o);
	}
	return t->typeNULL;
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
			DBG_P("cid=%d, cname='%s', typename=%s", cid, S_tochar(ct->lname), S_tochar(ct->sname));
			knh_DictSet_set(ctx, DP(ctx->sys)->ClassNameDictSet, lname, cid+1);
		}
		if(!class_isPrivate(cid) && S_startsWith(lname, STEXT("konoha."))) {
			knh_DictSet_append(ctx, DP(ctx->sys)->ClassNameDictSet, ct->sname, cid+1);
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
	knh_uintptr_t cid = knh_DictSet_get(ctx, DP(ctx->sys)->ClassNameDictSet, lname);
	if(cid > 0) return (knh_class_t)(cid-1);
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

//knh_class_t knh_class_p(CTX ctx, knh_class_t cid, size_t n)
//{
//	knh_ParamArray_t *pa = ClassTBL(cid)->cparam;
//	if(n-1 < pa->psize) {
//		knh_param_t *p = knh_ParamArray_get(pa, n-1);
//		return p->type;
//	}
//	return TYPE_void;
//}

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
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_String_t *lname, *sname;
		knh_make_cname(ctx, cwb->w, cid);
		lname = knh_cwb_newString(ctx, cwb);
		knh_make_tname(ctx, cwb->w, cid);
		sname = knh_cwb_newString(ctx, cwb);
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
			END_LOCAL_(ctx, lsfp);
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

/* ------------------------------------------------------------------------ */

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

//void knh_ParamArray_radd(CTX ctx, knh_ParamArray_t *pa, knh_param_t p, int old)
//{
//	knh_ParamArray_add(ctx, pa, p);
//	pa->psize -= 1;
//	pa->rsize += 1;
//}

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
//	else {
//		knh_param_t *p = knh_ParamArray_rget(pa, 0);
//		p->type = type;
//	}
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_param_t*) knh_ParamArray_get(knh_ParamArray_t *pa, size_t n)
{
	size_t size = pa->psize + pa->rsize;
	DBG_ASSERT(n < size);
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

/* ------------------------------------------------------------------------ */

knh_type_t knh_ParamArray_getptype(knh_ParamArray_t *pa, size_t n)
{
	if(!(n < pa->psize)) {
		if(pa->psize == 0) return TYPE_dyn;
		n = pa->psize-1;
	}
	return knh_ParamArray_get(pa, n)->type;
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

/* ------------------------------------------------------------------------ */

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
	KNH_SETv(ctx, DP(mtd)->mp, new_ParamArrayP1(ctx, type, type, FN_v));
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
	if(isCHECK) {
		size_t i;
		for(i = 0; i < knh_Array_size(a); i++) {
			knh_Method_t *mtd2 = a->methods[i];
			if((mtd2)->mn == (mtd)->mn) {
				LOGSFPDATA = {sDATA("msg", "redefined method"), MDATA("method", CLASS__((mtd)->cid), MN__((mtd)->mn)), __TRACE__};
				NOTE_Failed("konoha");
			}
		}
	}
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

knh_Method_t* knh_ClassTBL_findMethodNULL(CTX ctx, const knh_ClassTBL_t *t, knh_methodn_t mn, int isGEN)
{
	{
		knh_class_t cid = t->cid;
		knh_hashcode_t h = hashcode_mtd(cid, mn, K_MTDCACHE_SIZE);
		knh_mtdcache_t *mcache = ctx->mtdcache + h;
		if(mcache->cid == t->cid && mcache->mn == mn) {
			//DBG_P("HIT h=%d mcache=%d.%d %d.%d", h, mcache->cid, mcache->mn, t->cid, mn);
			KNH_ASSERT(IS_Method(mcache->mtd));
			return mcache->mtd;
		}
	}
	{
		const knh_ClassTBL_t *p, *t0 = t;
		do {
			size_t i;
			knh_Array_t *a = t0->methods;
			for(i = 0; i < knh_Array_size(a); i++) {
				knh_Method_t *mtd = a->methods[i];
				if((mtd)->mn == mn) {
					return Cache_setMethod(ctx->mtdcache, t->cid, mn, mtd);
				}
			}
			p = t0;
			t0 = t0->supTBL;
		}
		while(p != t0);
	}
	if(t->fsize > 0) {
		if(MN_isGETTER(mn) || MN_isISBOOL(mn)) {
			knh_index_t idx;
			knh_fieldn_t fn = MN_toFN(mn);
			for(idx = (knh_index_t)t->fsize - 1; idx >= 0 ; idx--) {
				knh_fields_t *cf = t->fields + idx;
				if(cf->fn == fn) {
					if(MN_isISBOOL(mn) && !IS_Tbool(cf->type)) {
						continue;
					}
					if(!FLAG_is(cf->flag, FLAG_Field_Getter)) {
						continue;
					}
					knh_Method_t *mtd = new_GetterMethod(ctx, t->cid, mn, cf->type, idx);
					knh_ClassTBL_addMethod(ctx, t, mtd, 0);
					return Cache_setMethod(ctx->mtdcache, t->cid, mn, mtd);
				}
			}
			goto L_NoSuchMethod;
		}
		if(MN_isSETTER(mn)) {
			knh_index_t idx;
			knh_fieldn_t fn = MN_toFN(mn);
			for(idx = (knh_index_t)t->fsize - 1; idx >= 0 ; idx--) {
				knh_fields_t *cf = t->fields + idx;
				if(cf->fn == fn) {
					if(!FLAG_is(cf->flag, FLAG_Field_Setter)) {
						continue;
					}else {
						knh_Method_t *mtd = new_SetterMethod(ctx, t->cid, mn, cf->type, idx);
						knh_ClassTBL_addMethod(ctx, t, mtd, 0);
						return Cache_setMethod(ctx->mtdcache, t->cid, mn, mtd);
					}
				}
			}
		}
	}
	L_NoSuchMethod:;
	if(isGEN) {
		if(MN_isFMT(mn)) {
			DBG_P("Generating %%empty: cid=%s mn=%%%s", CLASS__(t->cid), MN__(mn));
			return ClassTBL_getMethodNULL(ctx, t, MN__empty);
		}
		else {
			knh_Method_t *mtd = new_NoSuchMethod(ctx, t->cid, mn);
			knh_ClassTBL_addMethod(ctx, t, mtd, 0);
			return Cache_setMethod(ctx->mtdcache, t->cid, mn, mtd);
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
	knh_Method_t *mtd = ClassTBL_getMethodNULL(ctx, ClassTBL(cid), mn);
	return mtd;
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
	//DBG_P("%s=>%s", CLASS__(tmr->scid), CLASS__(tmr->tcid));
	knh_Array_add(ctx, ClassTBL(cid)->typemaps, tmr);
	if(initCache) {
		Cache_setTypeMap(ctx, tmr->scid, tmr->tcid, tmr);
	}
}

KNHAPI2(void) knh_TypeMap_exec(CTX ctx, knh_TypeMap_t *tmr, knh_sfp_t *sfp _RIX)
{
	if(IS_NULL(sfp[0].o)) {
		KNH_SETv(ctx, sfp[K_RIX].o, KNH_NULVAL(tmr->tcid))
		sfp[K_RIX].ivalue = 0;
	}
	else {
		if(!TypeMap_isFastCall(tmr)) {
			sfp[K_TMRIDX].tmrNC = tmr;
		}
		tmr->ftypemap_1(ctx, sfp, K_RIX);
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

///* ------------------------------------------------------------------------ */
//
//static TYPEMAP Ftypemap_method(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Method_t *mtd = DP(sfp[0].trlNC)->mtd;
//	DBG_ASSERT(IS_Method(mtd));
//	KNH_SETv(ctx, sfp[1+K_CALLDELTA].o, sfp[0].o);
//	KNH_SCALL(ctx, sfp, 1, mtd, /*argc*/, 0);
//	RETURN(ctx, sfp, rtnidx, sfp[1+K_CALLDELTA].o);
//}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_TypeMap_t*) new_TypeMap(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func)
{
	knh_TypeMap_t* tmr = new_(TypeMap);
	tmr->h.magicflag |= (knh_uintptr_t)flag;
	tmr->scid = scid;
	tmr->tcid = tcid;
	tmr->ftypemap_1 = (func == NULL) ? Ftypemap_null : func;
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
	lsfp[0+K_CALLDELTA+1].ndata = sfp[0].ndata;
	KNH_SCALL(ctx, lsfp, 0, mtd, 1);
	KNH_SETv(ctx, sfp[K_RIX].o, lsfp[0].o);
	sfp[K_RIX].ndata = lsfp[0].ndata;
	DBG_P("maped cid=%s ivalue=%d", CLASS__(O_cid(sfp[K_RIX].o)), sfp[K_RIX].ivalue);
}

knh_TypeMap_t *new_TypeMapMethod(CTX ctx, knh_flag_t flag, knh_Method_t *mtd)
{
	knh_class_t scid = knh_ParamArray_get(DP(mtd)->mp, 0)->type, tcid = knh_ParamArray_rtype(DP(mtd)->mp);
	knh_TypeMap_t *tmr = new_TypeMap(ctx, flag, scid, tcid, Ftypemap_method);
	KNH_SETv(ctx, tmr->mtd, mtd);
	return tmr;
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

//static TYPEMAP Ftypemap_asis(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SWAPMOV(ctx, sfp, rix, 0);
//}
//
//static knh_TypeMap_t* new_TypeMapASIS(CTX ctx, knh_class_t scid, knh_class_t tcid)
//{
//	return new_TypeMap(ctx, 0, scid, tcid, Ftypemap_asis);
//}
//
//static knh_TypeMap_t* new_TypeMapNull(CTX ctx, knh_class_t scid, knh_class_t tcid)
//{
//	return new_TypeMap(ctx, 0, scid, tcid, NULL);
//}

///* ------------------------------------------------------------------------ */
////## mapper Iterator Iterator;
//
//static TYPEMAP Iterator_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_TODO(__FUNCTION__);
//
//}
//
///* ------------------------------------------------------------------------ */
////## mapper Array Array;
//
//
///* ------------------------------------------------------------------------ */
////## mapper Iterator Array;
//
//static TYPEMAP Iterator_Array(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	RETURN_(knh_Iterator_toArray(ctx, sfp[0].it));
//}
//
///* ------------------------------------------------------------------------ */
///* [Array] */
////## mapper Array Iterator;
////## method T1.. Array.opITR();
//
//static TYPEMAP Array_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	RETURN_(new_ArrayIterator(ctx, sfp[0].a));
//}
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

//static knh_TypeMap_t *new_TypeMapNested(CTX ctx, knh_TypeMap_t *tmr, knh_TypeMap_t *tmr2)
//{
//	KNH_TODO(__FUNCTION__);
//	return NULL;
//}

//static knh_TypeMap_t *knh_findParam1TypeMapNULL(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct, int isT)
//{
//	if(sct->p1 == tct->p1) { // Iterator<T> => Array<T> //fixed by shinpei_NKT
//		return knh_findTypeMap1NULL(ctx, sct->baseTBL, tct->bcid, isT);
//	}
//	else if(sct->bcid == tct->bcid) { // Array<S> => Array<T>
//		knh_TypeMap_t *tmr = knh_findTypeMap1NULL(ctx, sct->baseTBL, tct->bcid, isT);
//		if(tmr != NULL) {
//			knh_TypeMap_t *tmr2 = knh_findTypeMapNULL(ctx, sct->p1, tct->p2, isT);
//			if(tmr2 != NULL) {
//				tmr = new_TypeMapNested(ctx, tmr, tmr2);
//				return tmr;
//			}
//		}
//	}
//	else {  // Array<S> => Iterator<T>
//		knh_TypeMap_t *tmr = knh_findTypeMap1NULL(ctx, sct->baseTBL, tct->bcid, isT);
//		if(tmr != NULL) {
//			knh_TypeMap_t *tmr2 = knh_findTypeMapNULL(ctx, sct->p1, tct->p1, isT);
//			if(tmr2 != NULL) {
//				tmr = new_TypeMapNested(ctx, tmr, tmr2);
//				return tmr;
//			}
//		}
//	}
//	return NULL;
//}

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

knh_TypeMap_t *knh_findTypeMapNULL(CTX ctx, knh_class_t scid0, knh_class_t tcid0)
{
	knh_TypeMap_t *tmr = NULL;
	DBG_P("finding.. %s ==> %s",CLASS__(scid0), CLASS__(tcid0));
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
	frule = knh_getTypeMapRule(ctx, CLASS_Tdynamic, tct->bcid);
	if(frule != NULL) {
		tmr = frule(ctx, sct, tct);
		knh_addTypeMap(ctx, tmr, 0/*initCache*/);
		if(tmr != NULL) return Cache_setTypeMap(ctx, sct->cid, tct->cid, tmr);
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

static knh_TypeMap_t *knh_inferIteratorIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
//	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	return NULL;
}


static knh_TypeMap_t *knh_inferDynamicIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	return NULL;
}



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
	if(IS_TypeMap(tmr->tmr1)) {
		DBG_P("@@ COPY and TMAP");
		tmr = tmr->tmr1;
		KNH_SETv(ctx, lsfp[0].o, TS_EMPTY);  // set nonnull for unbox map
		for(i = 0; i < tsize; i++) {
			sa->api->get(ctx, sa, i, lsfp);
			klr_setesp(ctx, lsfp+1); //added
			knh_TypeMap_exec(ctx, tmr, lsfp, +1);
			ta->api->add(ctx, ta, lsfp+1);
		}
	}
	else if(Array_isNDATA(sa)) {
		const knh_ClassTBL_t *ct = ClassTBL(O_cTBL(sa)->p1);
		DBG_P("@@ COPY tsize=%d and BOXING(%s)", tsize, CLASS__(ct->cid));
		for(i = 0; i < tsize; i++) {
			sa->api->get(ctx, sa, i, lsfp);
			KNH_SETv(ctx, lsfp[0].o, new_Boxing(ctx, lsfp, ct));
			ta->api->add(ctx, ta, lsfp);
		}
	}
	else {
		DBG_P("@@ COPY ");
		for(i = 0; i < tsize; i++) {
			sa->api->get(ctx, sa, i, lsfp);
			ta->api->add(ctx, ta, lsfp);
		}
	}
	RETURN_(ta);
}

static TYPEMAP DArray_Array(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *tmr = sfp[K_TMRIDX].tmrNC;
	knh_Array_t *sa = sfp[0].a;
	knh_Array_t *ta = (knh_Array_t*)new_Object_init2(ctx, ClassTBL(tmr->tcid));
	size_t i, tsize = knh_Array_size(sa);
	if(tsize > 0) {
		knh_Array_grow(ctx, ta, tsize, 8);
	}
	const knh_ClassTBL_t *tct = ClassTBL(O_cTBL(ta)->p1);
	knh_sfp_t *lsfp = ctx->esp + 1;
	if(Array_isNDATA(ta)) {
		for(i = 0; i < tsize; i++) {
			sa->api->get(ctx, sa, i, lsfp);
			const knh_ClassTBL_t *sct = O_cTBL(lsfp[0].o);
			if(tct->cid == sct->cid || ClassTBL_isa_(ctx, sct, tct)) {
				lsfp[1].ndata = O_ndata(lsfp[0].o);
			}
			else {
				knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sct->cid, tct->cid);
				if(tmr != NULL) {
					klr_setesp(ctx, lsfp+1); //added
					lsfp[0].ndata = O_ndata(lsfp[0].o); // unbox
					knh_TypeMap_exec(ctx, tmr, lsfp, +1);
				}
				else {
					lsfp[1].ivalue = 0;  // null
				}
			}
			ta->api->add(ctx, ta, lsfp+1);
		}
	}
	else {
		for(i = 0; i < tsize; i++) {
			sa->api->get(ctx, sa, i, lsfp);
			const knh_ClassTBL_t *sct = O_cTBL(lsfp[0].o);
			if(tct->cid == sct->cid || ClassTBL_isa_(ctx, sct, tct)) {
				ta->api->add(ctx, ta, lsfp);
				continue;
			}
			knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sct->cid, tct->cid);
			if(tmr != NULL) {
				klr_setesp(ctx, lsfp+1); //added
				lsfp[0].ndata = O_ndata(lsfp[0].o); // unbox
				knh_TypeMap_exec(ctx, tmr, lsfp, +1);
			}
			else {
				KNH_SETv(ctx, lsfp[1].o, KNH_NULVAL(tct->cid));
			}
			ta->api->add(ctx, ta, lsfp+1);
		}
	}
	RETURN_(ta);
}


static knh_TypeMap_t *knh_inferArrayArray(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	if(ClassTBL_isa_(ctx, ClassTBL(sp1), ClassTBL(tp1)) || tp1 == CLASS_Tdynamic) {
		return new_TypeMap(ctx, 0, sct->cid, tct->cid, Array_Array);
	}
	else {
		knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, sp1, tp1);
		if(tmr != NULL) {
			return new_TypeMapData(ctx, 0, sct->cid, tct->cid, Array_Array, UPCAST(tmr));
		}
		if(sp1 == CLASS_Tdynamic) {
			return new_TypeMap(ctx, 0, sct->cid, tct->cid, DArray_Array);
		}
	}
	return NULL;
}

static knh_TypeMap_t *knh_inferArrayIterator(CTX ctx, const knh_ClassTBL_t *sct, const knh_ClassTBL_t *tct)
{
//	knh_class_t sp1 = sct->p1, tp1 = tct->p1;
	DBG_P("Rule(%s=>%s)", TYPE__(sct->cid), TYPE__(tct->cid));
	return NULL;
}

void knh_loadSystemTypeMapRule(CTX ctx)
{
	knh_addTypeMapRule(ctx, CLASS_Iterator, CLASS_Iterator, knh_inferIteratorIterator);
	knh_addTypeMapRule(ctx, CLASS_Tdynamic, CLASS_Iterator, knh_inferDynamicIterator);
	knh_addTypeMapRule(ctx, CLASS_Array,    CLASS_Iterator, knh_inferArrayIterator);
	knh_addTypeMapRule(ctx, CLASS_Array,    CLASS_Array,    knh_inferArrayArray);
}

/* ------------------------------------------------------------------------ */

void knh_NameSpace_setLinkClass(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t linkname, const knh_ClassTBL_t *ct)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Bytes_write(ctx, cwb->ba, knh_bytes_head(linkname, ':'));
	knh_Bytes_putc(ctx, cwb->ba, ':');
	if(DP(ns)->name2ctDictSetNULL == NULL) {
		KNH_INITv(DP(ns)->name2ctDictSetNULL, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "NameSpace.name2cid"));
	}
	knh_DictSet_set(ctx, DP(ns)->name2ctDictSetNULL, knh_cwb_newString(ctx, cwb), (knh_uintptr_t)ct);
}

const knh_ClassTBL_t *knh_NameSpace_getLinkClassTBLNULL(CTX ctx, knh_NameSpace_t *ns, knh_String_t *path)
{
	knh_bytes_t scheme = knh_bytes_head(S_tobytes(path), ':'); scheme.len += 1; //include 'class:'
	knh_class_t cid = knh_NameSpace_getcid(ctx, ns, scheme);
	if(cid == CLASS_unknown) {
		scheme.len -= 1;
		cid = knh_NameSpace_getcid(ctx, ns, scheme);
		if(cid != CLASS_unknown) {
			knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, cid, MN_opLINK);
			if(mtd != NULL) return ClassTBL(cid);
		}
		return NULL;
	}
	return ClassTBL(cid);
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
	const knh_ClassTBL_t *ct = knh_NameSpace_getLinkClassTBLNULL(ctx, ns, path);
	Object *value = NULL;
	if(ct == NULL) {
		DBG_P("not found: %s as %s", S_tochar(path), CLASS__(tcid));
		if(tcid == CLASS_Boolean) return KNH_FALSE;
		return KNH_NULVAL(tcid);
	}
	else {
		knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, ns, ct->cid, MN_opLINK);
		DBG_ASSERT(mtd != NULL);
		BEGIN_LOCAL(ctx, lsfp, 3 + K_CALLDELTA);
		long rtnidx = 0, thisidx = rtnidx + K_CALLDELTA;
		KNH_SETv(ctx, lsfp[thisidx+1].o, path);
		KNH_SETv(ctx, lsfp[thisidx+2].o, ns);
		KNH_SCALL(ctx, lsfp, rtnidx, mtd, (3));
		if(IS_Tunbox(ct->cid)) {
			KNH_SETv(ctx, lsfp[0].o, new_Boxing(ctx, lsfp, ct));
		}
		value = lsfp[rtnidx].o;
		END_LOCAL_(ctx, lsfp);
	}
	if(O_cid(value) == tcid || ClassTBL_isa_(ctx, O_cTBL(value), ClassTBL(tcid))) {
		return value;
	}
	knh_TypeMap_t *tmr = knh_findTypeMapNULL(ctx, O_cid(value), tcid);
	if(tmr == NULL) {
		if(tcid == CLASS_Boolean) {
			value = (IS_NULL(value)) ? KNH_FALSE : KNH_TRUE;
		}
		return KNH_NULVAL(tcid);
	}
	else {
		BEGIN_LOCAL(ctx, lsfp, 1);
		KNH_SETv(ctx, lsfp[0].o, value);
		lsfp[0].ndata = O_ndata(value);
		klr_setesp(ctx, lsfp+1);
		knh_TypeMap_exec(ctx, tmr, lsfp, 0);
		if(IS_Tunbox(tmr->tcid)) {
			KNH_SETv(ctx, lsfp[0].o, new_Boxing(ctx, lsfp, ClassTBL(tmr->tcid)));
		}
		value = lsfp[0].o;
		END_LOCAL_(ctx, lsfp);
	}
	return value;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
