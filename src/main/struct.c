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
#include"../../include/konoha1/konoha_code_.h"
#include"../../include/konoha1/konohalang.h"

#ifndef TYPE_BytesIm
#define CLASS_BytesIm CLASS_Bytes
#define TYPE_BytesIm  TYPE_Bytes
#endif

#ifndef TYPE_ArrayIm
#define CLASS_ArrayIm CLASS_Array
#define TYPE_ArrayIm  TYPE_Array
#endif

#ifndef TYPE_MapIm
#define CLASS_MapIm CLASS_Map
#define TYPE_MapIm  TYPE_Map
#endif

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* --------------- */
/* Data */
/* --------------- */

#define K_INCLUDE_BUILTINAPI
#include "dspi.c"

#ifdef K_USING_BMGC
#define knh_bodyfree(ctx, p, C)
#else
#define knh_bodymalloc(ctx, C)   (knh_##C##EX_t*)KNH_MALLOC(ctx, sizeof(knh_##C##EX_t))
#define knh_bodyfree(ctx, p, C)  KNH_FREE(ctx, p, sizeof(knh_##C##EX_t))
#endif

/* ------------------------------------------------------------------------ */
/* DEFAULT */

static void DEFAULT_init(CTX ctx, kRawPtr *o)
{
//	DBG_ASSERT((sizeof(kObjectUnused) - sizeof(kObjectHeader)) == sizeof(kintptr_t) * 4);
//	kintptr_t *p = (kintptr_t*)&(o->rawptr);
//	p[0] = KINT0; p[1] = KINT0; p[2] = KINT0; p[3] = KINT0;
}

static void DEFAULT_initcopy(CTX ctx, kRawPtr *dst, kRawPtr *src)
{
	KNH_TODO("copy operation");
}

kbool_t knh_class_canObjectCopy(CTX ctx, kclass_t cid)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	return (ct->cdef->initcopy != DEFAULT_initcopy);
}

static void DEFAULT_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
}

static void DEFAULT_free(CTX ctx, kRawPtr *o)
{
}

static void DEFAULT_checkin(CTX ctx, ksfp_t *sfp, kRawPtr *o)
{
}

static void DEFAULT_checkout(CTX ctx, kRawPtr *o, int isFailed)
{
}

static int DEFAULT_compareTo(kRawPtr *o1, kRawPtr *o2)
{
	return (int)((kintptr_t)o1 - (kintptr_t)o2);
}

static void DEFAULT_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	KNH_LOG("TODO: must be defined %s_p", O__(o));
	knh_write_type(ctx, w, O_cid(o));
	knh_putc(ctx, w, ':');
	knh_write_ptr(ctx, w, (void*)o);
}

static void knh_write_TObject(CTX ctx, kOutputStream *w, ktype_t type, Object **v, size_t i, int level)
{
	switch(type) {
		case CLASS_Boolean: {
			kbool_t *d = (kbool_t*)(v+i);
			knh_write_bool(ctx, w, d[0]);
			break;
		}
		case CLASS_Int: {
			kint_t *d = (kint_t*)(v+i);
			knh_write_ifmt(ctx, w, KINT_FMT, d[0]);
			break;
		}
		case CLASS_Float: {
			kfloat_t *d = (kfloat_t*)(v+i);
			knh_write_ffmt(ctx, w, KFLOAT_FMT, d[0]);
			break;
		}
		default:{
			knh_write_InObject(ctx, w, v[i], level);
		}
	}
}

static kString* DEFAULT_getkey(CTX ctx, ksfp_t *sfp)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_type(ctx, cwb->w, O_cid(sfp[0].o));
	knh_putc(ctx, cwb->w, ':');
	knh_write_ptr(ctx, cwb->w, sfp[0].o);
	return CWB_newString(ctx, cwb, 0);
}

static khashcode_t DEFAULT_hashCode(CTX ctx, kRawPtr *o)
{
	return ((khashcode_t)o) / (sizeof(void*) * 8);
}

static void DEFAULT_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{

}

#define DEFAULT_0 NULL
#define DEFAULT_1 NULL
#define DEFAULT_findTypeMapNULL NULL
#define DEFAULT_2 NULL
#define DEFAULT_3 NULL
#define DEFAULT_4 NULL
#define DEFAULT_5 NULL
//#define DEFAULT_6 NULL
#define sizeof_O(T) (sizeof(k##T))

static const kclassdef_t TvoidDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"void", CFLAG_Tvoid, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
};

static const kclassdef_t TvarDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"var", CFLAG_Tvar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
};

static const kclassdef_t TdynamicDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"dynamic", CFLAG_Tvar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
};

const kclassdef_t* knh_getDefaultClassDef(void)
{
	return &TdynamicDef;
}

void knh_ClassTBL_setConstPool(CTX ctx, const knh_ClassTBL_t *ct)
{
	if(ct->constPoolMapNULL == NULL) {
		KNH_INITv(((knh_ClassTBL_t*)ct)->constPoolMapNULL, new_PtrMap(ctx, 0));
	}
}

/* --------------- */
/* Object */

static void ObjectField_init(CTX ctx, kRawPtr *o)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->fsize > 0) {
		Object **v = &(of->smallobject);
		if(ct->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, ct->fsize * sizeof(kObject*));
		}
		of->fields = v;
		knh_memcpy(v, ct->protoNULL->fields, ct->fsize * sizeof(kObject*));
#ifdef K_USING_RCGC
		size_t i;
		for(i = 0; i < ct->fsize; i++) {
			if(!ct->fields[i].israw) {
				knh_Object_RCinc(v[i]);
			}
		}
#endif
	}
	else {
		of->fields = NULL;
	}
}

static void CppObject_init(CTX ctx, kRawPtr *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	o->rawptr = NULL;
	if(ct->fsize > 0) {
		o->kfields = (Object**)KNH_MALLOC(ctx, ct->fsize * sizeof(kObject*));
		knh_memcpy(o->kfields, ct->protoNULL->fields, ct->fsize * sizeof(kObject*));
#ifdef K_USING_RCGC
		size_t i;
		for(i = 0; i < ct->fsize; i++) {
			if(!ct->fields[i].israw) {
				knh_Object_RCinc(o->kfields[i]);
			}
		}
#endif
	}
	else {
		o->kfields = NULL;
	}
}

static void ObjectField_initcopy(CTX ctx, kRawPtr *o, kRawPtr *src)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(kObject*));
		}
		of->fields = v;
		knh_memcpy(v, src->rawptr, t->fsize * sizeof(kObject*));
#ifdef K_USING_RCGC
		size_t i;
		for(i = 0; i < t->fsize; i++) {
			if(!t->fields[i].israw) {
				knh_Object_RCinc(v[i]);
			}
		}
#endif
	}
	else {
		of->fields = NULL;
	}
}

static void ObjectField_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	size_t i;
	for(i = 0; i < ct->fsize; i++) {
		if(ct->fields[i].israw == 0) {
			KNH_ADDREF(ctx, of->fields[i]);
		}
	}
	KNH_SIZEREF(ctx);
}

static void CppObject_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	size_t i;
	for(i = 0; i < ct->fsize; i++) {
		if(ct->fields[i].israw == 0) {
			KNH_ADDREF(ctx, o->kfields[i]);
		}
	}
	KNH_SIZEREF(ctx);
}

static void ObjectField_free(CTX ctx, kRawPtr *o)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->fsize > K_SMALLOBJECT_FIELDSIZE) {
		KNH_FREE(ctx, of->fields, ct->fsize * sizeof(kObject*));
	}
	DBG_(of->fields = NULL);
}

static void CppObject_free(CTX ctx, kRawPtr *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->fsize > 0) {
		KNH_FREE(ctx, o->kfields, ct->fsize * sizeof(kObject*));
		o->kfields = NULL;
	}
	if(o->rawptr != NULL) {
//		DBG_P("freeing %s %p", o->DBG_NAME, o->rawptr);
		o->rawfree(o->rawptr);
		o->rawptr = NULL;
	}
}

static void CppObject_checkout(CTX ctx, kRawPtr *o, int isFailed)
{
//	if(o->rawfree != NULL) {
//		DBG_P("freeing %s %p", o->DBG_NAME, o->rawptr);
//		o->rawfree(o->rawptr);
//		o->rawptr = NULL;
//		o->rawfree = NULL;
//	}
}

static int ObjectField_compareTo(kRawPtr *o, kRawPtr *o2)
{
	return o - o2;
}

static void ObjectField_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	knh_putc(ctx, w, '{');
	{
		kfieldinfo_t *tf = O_cTBL(o)->fields;
		size_t i, fsize = O_cTBL(o)->fsize;
		Object **v = (Object**)o->rawptr;
		if(fsize > 0) {
			knh_write_fn(ctx, w, tf[0].fn);
			knh_write(ctx, w, STEXT(": "));
			knh_write_TObject(ctx, w, tf[0].type, v, 0, level);
		}
		for(i = 1; i < fsize; i++) {
			if(tf[i].type == TYPE_void) continue;
			knh_write_delim(ctx, w);
			knh_write_fn(ctx, w, tf[i].fn);
			knh_write(ctx, w, STEXT(": "));
			knh_write_TObject(ctx, w, tf[i].type, v, i, level);
		}
	}
	knh_putc(ctx, w, '}');
}

static kString* ObjectField_getkey(CTX ctx, ksfp_t *sfp)
{
	int keyidx = O_cTBL(sfp[0].o)->keyidx;
	if(keyidx != -1) {
		kObject *of = (kObject*)sfp[0].o;
		DBG_ASSERT(IS_bString(of->fields[keyidx]));
		return (kString*)of->fields[keyidx];
	}
	return DEFAULT_getkey(ctx, sfp);
}

static void pack_unbox(CTX ctx, void *pkr, kclass_t cid, kObject **v, const knh_PackSPI_t *packspi)
{
	knbody_t n = ((knbody_t*)(v))[0];
	if (IS_Tint(cid)) {
		packspi->pack_int(ctx, pkr, n.ivalue);
	} else if (IS_Tfloat(cid)) {
		packspi->pack_float(ctx, pkr, n.fvalue);
	} else {
		packspi->pack_bool(ctx, pkr, n.bvalue);
	}
}

static void Object_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	kObject *of = (kObject*) o;
	Object **v = of->fields;
	size_t i = 0, field_count = ct->fsize;
	DBLNDATA_(
			for (i = 0; i < ct->fsize; i++) {
			kfieldinfo_t *field = ct->fields + i;
			if (field->type == CLASS_Tvoid) {
			field_count--;
			}
	});

	// { "ks:class" : "main.Person", 
	packspi->pack_beginmap(ctx, pkr, field_count + 1);
	packspi->pack_string(ctx, pkr, "ks:class", knh_strlen("ks:class"));
	packspi->pack_putc(ctx, pkr, ':');
	packspi->pack_string(ctx, pkr, S_totext(ct->sname), S_size(ct->sname));
	packspi->pack_putc(ctx, pkr, ',');

	for (i = 0; i < ct->fsize; i++) {
		kfieldinfo_t *field = ct->fields + i;
		ktype_t type = field->type;
		kString *key;

		if (type == CLASS_Tvoid) continue;
		if (i != 0) {
			packspi->pack_putc(ctx, pkr, ',');
		}
		key = knh_getFieldName(ctx, field->fn);
		packspi->pack_string(ctx, pkr, S_totext(key), S_size(key));
		packspi->pack_putc(ctx, pkr, ':');
		if (IS_Tunbox(type)) {
			pack_unbox(ctx, pkr, type, v + i, packspi);
		} else {
			kObject *obj = v[i];
			O_cTBL(obj)->cdef->wdata(ctx, RAWPTR(obj), pkr, packspi);
		}
	}
	packspi->pack_endmap(ctx, pkr);
}

static const kclassdef_t ObjectDef = {
	ObjectField_init, ObjectField_initcopy, ObjectField_reftrace, ObjectField_free,
	DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
	ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
	"Object", CFLAG_Object, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
};

static void ObjectFieldN_init(CTX ctx, kRawPtr *o)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(kObject*));
		}
		of->fields = v;
		knh_memcpy(v, t->protoNULL->fields, t->fsize * sizeof(kObject*));
	}
	else {
		of->fields = NULL;
	}
}

static void ObjectFieldN_initcopy(CTX ctx, kRawPtr *o, kRawPtr *src)
{
	kObject *of = (kObject*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->fsize > 0) {
		Object **v = &(of->smallobject);
		if(ct->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, ct->fsize * sizeof(kObject*));
		}
		of->fields = v;
		knh_memcpy(v, src->rawptr, ct->fsize * sizeof(kObject*));
	}
	else {
		of->fields = NULL;
	}
}

static void ObjectField1_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kObject *of = (kObject*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 1);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField2_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kObject *of = (kObject*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 2);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_ADDREF(ctx, of->fields[1]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField3_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kObject *of = (kObject*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 3);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_ADDREF(ctx, of->fields[1]);
	KNH_ADDREF(ctx, of->fields[2]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField4_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kObject *of = (kObject*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 4);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_ADDREF(ctx, of->fields[1]);
	KNH_ADDREF(ctx, of->fields[2]);
	KNH_ADDREF(ctx, of->fields[3]);
	KNH_SIZEREF(ctx);
#endif
}

static const kclassdef_t ObjectNDef[] = {
	{
		ObjectFieldN_init,
		ObjectFieldN_initcopy,
		DEFAULT_reftrace,
		ObjectField_free,
		DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
		ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
		DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
		"Object", CFLAG_Object, 0, NULL,
		NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
	},
	{
		ObjectField_init, ObjectField_initcopy, ObjectField1_reftrace, ObjectField_free,
		DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
		ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
		DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
		"Object", CFLAG_Object, 0, NULL,
		NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
	},
	{
		ObjectField_init, ObjectField_initcopy, ObjectField2_reftrace, ObjectField_free,
		DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
		ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
		DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
		"Object", CFLAG_Object, 0, NULL,
		NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
	},
	{
		ObjectField_init, ObjectField_initcopy, ObjectField3_reftrace, ObjectField_free,
		DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
		ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
		DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
		"Object", CFLAG_Object, 0, NULL,
		NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
	},
	{
		ObjectField_init, ObjectField_initcopy, ObjectField4_reftrace, ObjectField_free,
		DEFAULT_checkin, DEFAULT_checkout, ObjectField_compareTo, ObjectField_p,
		ObjectField_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
		DEFAULT_findTypeMapNULL, Object_wdata, DEFAULT_2, DEFAULT_3,
		"Object", CFLAG_Object, 0, NULL,
		NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
	}
};

void knh_ClassTBL_setObjectCSPI(CTX ctx, knh_ClassTBL_t *ct)
{
	size_t c, i;
	ct->struct_size = sizeof(void*) * ct->fsize;
	for(c = 0; c < ct->fsize; c++) {
		if(ct->fields[c].israw == 1) break;
	}
	for(i = c + 1; i < ct->fsize; i++) {
		if(ct->fields[i].israw == 0) {
			knh_setClassDef(ctx, ct, &ObjectDef);
			return;
		}
	}
	if(c <= 4) {
		DBG_P("%s: SIZE OF OBJECT FIELD: %d", S_totext(ct->lname), c);
		knh_setClassDef(ctx, ct, ObjectNDef + c);
	}
	else {
		knh_setClassDef(ctx, ct, &ObjectDef);
	}
}

static const kclassdef_t CppObjectDef = {
	CppObject_init, DEFAULT_initcopy, CppObject_reftrace, CppObject_free,
	DEFAULT_checkin, CppObject_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"dynamic", 0, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Object), 0,
};

const kclassdef_t* knh_getCppClassDef(void)
{
	return &CppObjectDef;
}

/* --------------- */
/* Boolean */

static void NDATA_init(CTX ctx, kRawPtr *o)
{
	kNumber *no = (kNumber*)o;
	no->n.ivalue = 0;
}

static void NDATA_initcopy(CTX ctx, kRawPtr *o, kRawPtr *src)
{
	kNumber *no = (kNumber*)o;
	kNumber *so = (kNumber*)src;
	no->n.data = so->n.data;
}

static void NDATA_free(CTX ctx, kRawPtr *o)
{
	if(O_cTBL(o)->constPoolMapNULL != NULL) {
		knh_PtrMap_rmI(ctx, O_cTBL(o)->constPoolMapNULL, (kInt*)o);
	}
}

static kint_t Int_toint(CTX ctx, ksfp_t *sfp)
{
	return sfp[0].ivalue;
}

static kfloat_t Int_tofloat(CTX ctx, ksfp_t *sfp)
{
	return (kfloat_t)sfp[0].ivalue;
}

static kint_t Float_toint(CTX ctx, ksfp_t *sfp)
{
	return (kint_t)sfp[0].fvalue;
}

static kfloat_t Float_tofloat(CTX ctx, ksfp_t *sfp)
{
	return sfp[0].fvalue;
}

static khashcode_t NDATA_hashCode(CTX ctx, kRawPtr *o)
{
	return (khashcode_t)((kInt*)o)->n.data;
}

static int Int_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kint_t f = ((kNumber*)o)->n.ivalue;
	kint_t f2 = ((kNumber*)o2)->n.ivalue;
	return (f < f2) ? -1 : ((f == f2) ? 0 : 1);
}

static int Float_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kfloat_t f = ((kNumber*)o)->n.fvalue;
	kfloat_t f2 = ((kNumber*)o2)->n.fvalue;
	return (f < f2) ? -1 : ((f == f2) ? 0 : 1);
}

static void Boolean_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	knh_write_bool(ctx, w, ((kNumber*)o)->n.bvalue);
}

static void Int_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
#if defined(K_USING_SEMANTICS)
	kSemantics *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_intx(ctx, sfp[0].w, u, sfp[1].ivalue);
#else
	knh_write_ifmt(ctx, w, KINT_FMT, ((kNumber*)o)->n.ivalue);
#endif
}

static void Float_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
#if defined(K_USING_SEMANTICS)
	kSemantics *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_floatx(ctx, sfp[0].w, u, sfp[1].fvalue);
#else
	knh_write_ffmt(ctx, w, KFLOAT_FMT, ((kNumber*)o)->n.fvalue);
#endif
}

static void Boolean_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	packspi->pack_bool(ctx, pkr, ((kBoolean *)o)->n.bvalue);
}

static void Int_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	packspi->pack_int(ctx, pkr, ((kInt *)o)->n.ivalue);
}

static void Float_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	packspi->pack_float(ctx, pkr, ((kFloat *)o)->n.fvalue);
}

static const kclassdef_t BooleanDef = {
	NDATA_init, NDATA_initcopy, DEFAULT_reftrace, NDATA_free,
	DEFAULT_checkin, DEFAULT_checkout, Int_compareTo, Boolean_p,
	ObjectField_getkey, NDATA_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, Boolean_wdata, DEFAULT_2, DEFAULT_3,
	"Boolean", CFLAG_Boolean, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Boolean), 0,
};

static const kclassdef_t NumberDef = {
	NDATA_init, NDATA_initcopy, DEFAULT_reftrace, NDATA_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	ObjectField_getkey, NDATA_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Number", CFLAG_Number, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Number), 0,
};

static const kclassdef_t IntDef = {
	NDATA_init, NDATA_initcopy, DEFAULT_reftrace, NDATA_free,
	DEFAULT_checkin, DEFAULT_checkout, Int_compareTo, Int_p,
	ObjectField_getkey, NDATA_hashCode, Int_toint, Int_tofloat,
	DEFAULT_findTypeMapNULL, Int_wdata, DEFAULT_2, DEFAULT_3,
	"Int", CFLAG_Int, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Int), 0,
};

static const kclassdef_t FloatDef = {
	NDATA_init, NDATA_initcopy, DEFAULT_reftrace, NDATA_free,
	DEFAULT_checkin, DEFAULT_checkout, Float_compareTo, Float_p,
	ObjectField_getkey, NDATA_hashCode, Float_toint, Float_tofloat,
	DEFAULT_findTypeMapNULL, Float_wdata, DEFAULT_2, DEFAULT_3,
	"Float", CFLAG_Float, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Float), 0,
};

/* --------------- */
/* Date */

static void Date_init(CTX ctx, kRawPtr *o)
{
	kDate *dt = (kDate*)o;
	time_t t;
	struct tm tm;
	time(&t);
#if defined(K_USING_WINDOWS_)
#if defined(K_USING_MINGW_)
	tm = *localtime(&t);
#else
	localtime_s(&tm, &t);
#endif /* defined(K_USING_MINGW_) */
#else
	localtime_r(&t, &tm);
#endif /* defined(K_USING_WINDOWS_) */
	dt->dt.year  = (kshort_t)(tm.tm_year + 1900);
	dt->dt.month = (kshort_t)(tm.tm_mon + 1);
	dt->dt.day   = (kshort_t)(tm.tm_mday);
	dt->dt.hour  = (kshort_t)(tm.tm_hour);
	dt->dt.min   = (kshort_t)(tm.tm_min);
	dt->dt.sec   = (kshort_t)(tm.tm_sec);
#if defined(K_USING_MINGW_)
	_tzset();
	dt->dt.gmtoff = (kshort_t)(_timezone / (60 * 60));
#else
	dt->dt.gmtoff = (kshort_t)(tm.tm_gmtoff / (60 * 60));
#endif /* defined(K_USING_MINGW_) */
	dt->dt.isdst = (kshort_t)(tm.tm_isdst);
}

static int Date_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kDate *dt1 = (kDate*)o;
	kDate *dt2 = (kDate*)o2;
	kintptr_t res = dt1->dt.year - dt2->dt.year;
	if(res != 0) return res;
	res = dt1->dt.month - dt2->dt.month;
	if(res == 0) { // TODO: adjustment of summer time
		kintptr_t n1 = ((((kintptr_t)dt1->dt.day * 24) + dt1->dt.hour) * 60) * dt1->dt.min;
		kintptr_t n2 = ((((kintptr_t)dt2->dt.day * 24) + dt2->dt.hour) * 60) * dt2->dt.min;
		n1 = (n1 + dt1->dt.gmtoff) * 60 + dt1->dt.sec;
		n2 = (n2 + dt2->dt.gmtoff) * 60 + dt2->dt.sec;
		return (n1 - n2);
	}
	return res;
}

static void Date_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kDate *dt = (kDate*)o;
	char buf[80];
	knh_snprintf(buf, sizeof(buf), "%04d-%02d-%02dT%02d:%02d:%02d%+02d:%02d",
		(int)(dt->dt.year), (int)(dt->dt.month), (int)dt->dt.day,
		(int)(dt->dt.hour), (int)(dt->dt.min), (int)dt->dt.sec, (int)(dt->dt.gmtoff / 60), (int)(dt->dt.gmtoff % 60));
	knh_write_ascii(ctx, w, buf);
}

static khashcode_t Date_hashCode(CTX ctx, kRawPtr *o)
{
	kDate *dt = (kDate*)o;
	khashcode_t n1 = ((((khashcode_t)dt->dt.day * 24) + dt->dt.hour) * 60) * dt->dt.min;
	n1 = (n1 + dt->dt.gmtoff) * 60 + dt->dt.sec;
	n1 = n1 + ((dt->dt.year) * 365) + dt->dt.month;
	return n1;
}

static void Date_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
//	kDate *s = (kDate *)o;
//	packspi->pack_string(ctx, pkr, S_totext(s), S_size(s));
}

static const kclassdef_t DateDef = {
	Date_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, Date_compareTo, Date_p,
	DEFAULT_getkey, Date_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, Date_wdata, DEFAULT_2, DEFAULT_3,
	"Date", CFLAG_Date, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Date), 0,
};


/* --------------- */
/* String */

static void String_init(CTX ctx, kRawPtr *o)
{
	kString *s = (kString*)o;
	s->str.text = "";
	s->str.len = 0;
	s->hashCode = 0;
	String_setTextSgm(s, 1);
}

static void String_free(CTX ctx, kRawPtr *o)
{
	kString *s = (kString*)o;
#ifdef K_USING_STRINGPOOL
	if(String_isPooled(s) && O_cTBL(o)->constPoolMapNULL != NULL) {
		knh_PtrMap_rmS(ctx, O_cTBL(o)->constPoolMapNULL, s);
	}
#endif
	if(!String_isTextSgm(s)) {
		KNH_FREE(ctx, s->str.ubuf, KNH_SIZE(S_size(s) + 1));
	}
}

static int String_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kString *s1 = (kString*)o;
	kString *s2 = (kString*)o2;
#if defined(K_USING_SEMANTICS)
	if(s1->h.cid != CLASS_String && s2->h.cid != CLASS_String) {
		kSemantics *u = knh_getSemantics(ctx, s1->h.cid);
		return DP(u)->fscmp(u, S_tobytes(s1), S_tobytes(s2));
	}
#else
	return knh_bytes_strcmp(S_tobytes(s1) ,S_tobytes(s2));
#endif
}

static void String_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kString *s = (kString*)o;
	if(IS_FMTs(level)) {
		knh_write_utf8(ctx, w, S_tobytes(s), !String_isASCII(s));
	}
	else {
		knh_write_quote(ctx, w, '"', S_tobytes(s), !String_isASCII(s));
	}
}

static kString* String_getkey(CTX ctx, ksfp_t *sfp)
{
	return sfp[0].s;
}

static khashcode_t String_hashCode(CTX ctx, kRawPtr *o)
{
	return ((kString*)o)->hashCode;
}

static void String_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	kString *s = (kString *)o;
	packspi->pack_string(ctx, pkr, S_totext(s), S_size(s));
}

static const kclassdef_t StringDef = {
	String_init, DEFAULT_initcopy, DEFAULT_reftrace, String_free,
	DEFAULT_checkin, DEFAULT_checkout, String_compareTo, String_p,
	String_getkey, String_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, String_wdata, DEFAULT_2, DEFAULT_3,
	"String", CFLAG_String, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(String), 0,
};

/* --------------- */
/* Bytes */

static const kdim_t dimINIT = {
	0, 0, 0, 0, 0, 0, 0,
};

static void Bytes_init(CTX ctx, kRawPtr *o)
{
	kBytes *ba = (kBytes*)o;
	ba->bu.len = 0;
	ba->bu.ubuf = NULL;
	ba->dim = &dimINIT;
	ba->DBG_name = NULL;
}

static const kdim_t* dim_copy(CTX ctx, const kdim_t *dim_src)
{
	if(dim_src->capacity == 0) {
		return dim_src;
	}
	else {
		kdim_t *dim = (kdim_t*)KNH_MALLOC(ctx, sizeof(kdim_t));
		/* copy dim_src to dim. @imasahiro */
		dim->capacity = dim_src->capacity;
		dim->wsize    = dim_src->wsize;
		dim->sorted   = dim_src->sorted;
		dim->dim      = dim_src->dim;
		dim->x        = dim_src->x;
		dim->xy       = dim_src->xy;
		dim->xyz      = dim_src->xyz;
		return (const kdim_t*)dim;
	}
}

static void Bytes_initcopy(CTX ctx, kRawPtr *o, kRawPtr *src)
{
	kBytes *ba = (kBytes*)o, *ba_src = (kBytes*)src;
	if(ba_src->dim->capacity > 0) {
		ba->bu.len = ba_src->bu.len;
		ba->bu.ubuf = (kchar_t*)KNH_MALLOC(ctx, ba_src->dim->capacity);
		knh_memcpy(ba->bu.ubuf, ba_src->bu.ubuf, ba_src->dim->capacity);
	}
	else {
		ba->bu.len = 0;
		ba->bu.ubuf = NULL;
	}
	ba->dim = dim_copy(ctx, ba_src->dim);
}

static void Bytes_free(CTX ctx, kRawPtr *o)
{
	kBytes *ba = (kBytes*)o;
	knh_dimfree(ctx, ba->bu.ubuf, ba->dim);
}

static int Bytes_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kBytes *s1 = (kBytes*)o;
	kBytes *s2 = (kBytes*)o2;
	return knh_bytes_strcmp(BA_tobytes(s1) , BA_tobytes(s2));
}

static void Bytes_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kBytes *ba = (kBytes*)o;
	if(IS_FMTs(level)) {
		knh_printf(ctx, w, "byte[%d]", BA_size(ba));
	}
	else if(IS_FMTdump(level)) {
		size_t i, j, n;
		char buf[40];
		for(j = 0; j * 16 < ba->bu.len; j++) {
			knh_snprintf(buf, sizeof(buf), "%08x", (int)(j*16));
			knh_write(ctx, w, B(buf));
			for(i = 0; i < 16; i++) {
				n = j * 16 + i;
				if(n < ba->bu.len) {
					knh_snprintf(buf, sizeof(buf), " %2x", (int)ba->bu.utext[n]);
					knh_write(ctx, w, B(buf));
				}
				else {
					knh_write(ctx, w, STEXT("   "));
				}
			}
			knh_write(ctx, w, STEXT("    "));
			for(i = 0; i < 16; i++) {
				n = j * 16 + i;
				if(n < ba->bu.len && isprint(ba->bu.utext[n])) {
					knh_snprintf(buf, sizeof(buf), "%c", (int)ba->bu.utext[n]);
					knh_write(ctx, w, B(buf));
				}
				else {
					knh_write(ctx, w, STEXT(" "));
				}
			}
			knh_write_EOL(ctx, w);
		}
	}
}

static khashcode_t Bytes_hashCode(CTX ctx, kRawPtr *o)
{
	kBytes *ba = (kBytes*)o;
	return knh_hash(0, ba->bu.text, ba->bu.len);
}

static const kclassdef_t BytesDef = {
	Bytes_init, Bytes_initcopy, DEFAULT_reftrace, Bytes_free,
	DEFAULT_checkin, DEFAULT_checkout, Bytes_compareTo, Bytes_p,
	DEFAULT_getkey, Bytes_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Bytes", CFLAG_Bytes, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Bytes), 0,
};

/* --------------- */
/* Pointer */

static void Pointer_init(CTX ctx, kRawPtr *o)
{
	kPointer *p = (kPointer*)o;
	p->ptr = NULL;
	p->size = 0;
	p->wsize = 0;
	KNH_INITv(p->gcref, KNH_NULL);
}

static void Pointer_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kPointer *p = (kPointer*)o;
	KNH_ADDREF(ctx, p->gcref);
	KNH_SIZEREF(ctx);
}

static int Pointer_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kPointer *p1 = (kPointer*)o;
	kPointer *p2 = (kPointer*)o2;
	return (int)((kintptr_t)(p1)->ptr - (kintptr_t)p2->ptr);
}

static void Pointer_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kPointer *p = (kPointer*)o;
	if(IS_FMTs(level)) {
		knh_write_ptr(ctx, w, p->ptr);
	}
	else if(IS_FMTdump(level)) {
		knh_write_ptr(ctx, w, p->ptr);
	}
}

static khashcode_t Pointer_hashCode(CTX ctx, kRawPtr *o)
{
	kPointer *p = (kPointer*)o;
	return (khashcode_t)(p->ptr) / sizeof(void*);
}

static const kclassdef_t PointerDef = {
	Pointer_init, DEFAULT_initcopy, Pointer_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, Pointer_compareTo, Pointer_p,
	DEFAULT_getkey, Pointer_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Pointer", CFLAG_Pointer, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Pointer), 0,
};

/* --------------------------------------------------------------------------*/
/* Tuple */

static void Tuple_init(CTX ctx, kRawPtr *o)
{
	kTuple *of = (kTuple*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(kObject*));
		}
		of->fields = v;
		knh_memcpy(v, t->defnull->fields, t->fsize * sizeof(kObject*));
#ifdef K_USING_RCGC
		size_t i;
		for(i = 0; i < t->fsize; i++) {
			if(t->fields[i].israw == 0) {
				knh_Object_RCinc(of->fields[i]);
			}
		}
#endif
	}
	else {
		of->fields = NULL;
	}
}

static void TUPLE_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	knh_putc(ctx, w, '(');
	{
		kfieldinfo_t *tf = O_cTBL(o)->fields;
		size_t i, fsize = O_cTBL(o)->fsize;
		Object **v = (Object**)o->rawptr;
		knh_write_TObject(ctx, w, tf[0].type, v, 0, level);
		for(i = 1; i < fsize; i++) {
			if(tf[i].type == TYPE_void) continue;
			knh_write_delim(ctx, w);
			knh_write_TObject(ctx, w, tf[i].type, v, i, level);
		}
	}
	knh_putc(ctx, w, ')');
}

static const kclassdef_t TupleDef = {
	Tuple_init, ObjectField_initcopy, ObjectField_reftrace, ObjectField_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, TUPLE_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Tuple", 0, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Tuple), 0,
};

/* --------------- */
/* Range */

static void Range_init(CTX ctx, kRawPtr *o)
{
	kRange *rng = (kRange*)o;
	kclass_t p1 = O_p1(rng);
	if(IS_Tunbox(p1)) {
		Range_setNDATA(rng, 1);
		rng->nstart = 0;
		rng->nend = 0;
	}
	else {
		KNH_INITv(rng->ostart, KNH_NULVAL(O_p1(rng)));
		KNH_INITv(rng->oend, rng->ostart);
	}
}

static void Range_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kRange *rng = (kRange*)o;
	if(!Range_isNDATA(o)) {
		KNH_ADDREF(ctx, rng->ostart);
		KNH_ADDREF(ctx, rng->oend);
		KNH_SIZEREF(ctx);
	}
}

static void Range_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kRange *range = (kRange*)o;
	kclass_t p1 = O_p1(range);
	knh_putc(ctx, w, '[');
	knh_write_TObject(ctx, w, p1, &range->ostart, 0, level);
	knh_write(ctx, w, STEXT(" to "));
	knh_write_TObject(ctx, w, p1, &range->oend, 0, level);
	knh_putc(ctx, w, ']');
}

static const kclassdef_t RangeDef = {
	Range_init, DEFAULT_initcopy, Range_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Range_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Range", CFLAG_Range, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Range), 0,
};

/* --------------- */
/* Array */

static void Array_init(CTX ctx, kRawPtr *o)
{
	kArray *a = (kArray*)o;
	knh_Array_initAPI(ctx, a);
	a->dim = &dimINIT;
	a->list = NULL;
	a->size = 0;
}

static void Array_initcopy(CTX ctx, kRawPtr *o, kRawPtr *src)
{
	kArray *a = (kArray*)o, *a_src = (kArray*)src;
	a->api = a_src->api;
	if(a_src->dim->capacity > 0) {
		a->size = a_src->size;
		a->list = (kObject**)KNH_MALLOC(ctx, a_src->dim->capacity * a_src->dim->wsize);
		knh_memcpy(a->list, a_src->list, a_src->dim->capacity * a_src->dim->wsize);
		Array_setNDATA(a, Array_isNDATA(a_src));
		if(!Array_isNDATA(a)) {
			size_t i;
			for(i = 0; i < a->size; i++) {
				knh_Object_RCinc(a->list[i]);
			}
		}
	}
	else {
		a->list = NULL;
		a->size = 0;
	}
	a->dim = dim_copy(ctx, a_src->dim);
}

static void Array_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kArray *a = (kArray*)o;
	if(!Array_isNDATA(a)) {
#ifdef K_USING_FASTREFS_
		KNH_SETREF(ctx, a->list, a->size);
#else
		size_t i;
		for(i = 0; i < a->size; i++) {
			KNH_ADDREF(ctx, a->list[i]);
		}
		KNH_SIZEREF(ctx);
#endif
	}
}

static void Array_free(CTX ctx, kRawPtr *o)
{
	kArray *a = (kArray*)o;
	knh_dimfree(ctx, a->list, a->dim);
}

static int Array_compareTo(kRawPtr *o, kRawPtr *o2)
{
	if(O_cTBL(o) == O_cTBL(o2)) {
		kArray *a = (kArray*)o;
		kArray *a2 = (kArray*)o2;
		size_t i, asize = knh_Array_size(a), asize2 = knh_Array_size(a2);
		if(Array_isNDATA(a)) {
			for(i = 0; i < asize; i++) {
				if(!(i < asize2)) return -1;
				if(a->nlist[i] == a2->nlist[i]) continue;
				if(O_cTBL(a)->p1 == CLASS_Float) {
					kfloat_t dim = a->flist[i] - a2->flist[i];
					if(dim < 0) return -1;
					return (dim > 0) ? 1: 0;
				}
				else {
					kint_t dim = a->ilist[i] - a2->ilist[i];
					if(dim < 0) return -1;
					return (dim > 0) ? 1: 0;
				}
			}
		}
		else {
			for(i = 0; i < asize; i++) {
				if(!(i < asize2)) return -1;
				if(a->list[i] == a2->list[i]) continue;
				int res = knh_Object_compareTo(a->list[i], a2->list[i]);
				if(res != 0) return res;
			}
		}
		return (asize == asize2) ? 0 : 1;
	}
	return (int)(o - o2);
}

static void Array_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	knh_putc(ctx, w, '[');
	{
		kArray *a = (kArray*)o;
		kclass_t p1 = O_p1(a);
		size_t c, size = knh_Array_size(a);
		if(size > 0) {
			if(IS_Tunbox(p1)) {
				if(IS_Tint(p1)) {
					knh_write_ifmt(ctx, w, KINT_FMT, a->ilist[0]);
					if(IS_FMTline(level)) {
						knh_write_delimdots(ctx, w);
					}
					else {
						for(c = 1; c < size; c++) {
							knh_write_delim(ctx, w);
							knh_write_ifmt(ctx, w, KINT_FMT, a->ilist[c]);
						}
					}
				}
				else if(p1 == TYPE_Boolean) {
					knh_write_bool(ctx, w, (int)a->ilist[0]);
					if(IS_FMTline(level)) {
						knh_write_delimdots(ctx, w);
					}
					else {
						for(c = 1; c < knh_Array_size(a); c++) {
							knh_write_delim(ctx, w);
							knh_write_bool(ctx, w, (int)a->ilist[c]);
						}
					}
				}
				else { /* IS_Tfloat(p1) */
					knh_write_ffmt(ctx, w, KFLOAT_FMT, a->flist[0]);
					if(IS_FMTline(level)) {
						knh_write_delimdots(ctx, w);
					}
					else {
						for(c = 1; c < knh_Array_size(a); c++) {
							knh_write_delim(ctx, w);
							knh_write_ffmt(ctx, w, KFLOAT_FMT, a->flist[c]);
						}
					}
				}
			}
			else {
				knh_write_InObject(ctx, w, a->list[0], level);
				if(IS_FMTline(level)) {
					knh_write_delimdots(ctx, w);
				}
				else {
					for(c = 1; c < size; c++) {
						knh_write_delim(ctx, w);
						knh_write_InObject(ctx, w, a->list[c], level);
					}
				}
			}
		}
	}
	knh_putc(ctx, w, ']');
}

static void Array_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	kArray *a = (kArray *)o;
	packspi->pack_beginarray(ctx, pkr, a->size);
	size_t i = 0;
	kclass_t p1 = O_p1(a);
	if (Array_isNDATA(a)) {
		for (i = 0; i < a->size; i++) {
			if (i != 0)
				packspi->pack_putc(ctx, pkr, ',');
			pack_unbox(ctx, pkr, p1, (kObject**)(a->ilist+i), packspi);
		}
	} else {
		for (i = 0; i < a->size; i++) {
			if (i != 0)
				packspi->pack_putc(ctx, pkr, ',');
			O_cTBL(a->list[i])->cdef->wdata(ctx, RAWPTR(a->list[i]), pkr, packspi);
		}
	}
	packspi->pack_endarray(ctx, pkr);
}

static const kclassdef_t ArrayDef = {
	Array_init, Array_initcopy, Array_reftrace, Array_free,
	DEFAULT_checkin, DEFAULT_checkout, Array_compareTo, Array_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, Array_wdata, DEFAULT_2, DEFAULT_3,
	"Array", CFLAG_Array, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Array), 0,
};

/* --------------- */
/* Iterator */

static ITRNEXT Fitrnext_single(CTX ctx, ksfp_t *sfp _RIX)
{
	kIterator *itr = ITR(sfp);
	if(DP(itr)->m.index == 0) {
		DP(itr)->m.index = 1;
		ITRNEXT_(DP(itr)->source);
	}
	ITREND_();
}

static void Iterator_init(CTX ctx, kRawPtr *o)
{
	kIterator *itr = (kIterator*)o;
	knh_IteratorEX_t *b;
#ifdef K_USING_BMGC
	b = DP(itr);
#else
	b = knh_bodymalloc(ctx, Iterator);
	itr->b = b;
#endif
	itr->fnext_1  =  Fitrnext_single;
	KNH_INITv(b->source, KNH_NULL);
	b->mtdNULL  =  NULL;
	b->m.nptr   =  NULL;
	b->m.index  = 0;
	b->m.max    = 0;
	b->m.nfree = NULL;
}

static void Iterator_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kIterator *itr = (kIterator*)o;
	KNH_ADDREF(ctx, DP(itr)->source);
	KNH_ADDNNREF(ctx, DP(itr)->mtdNULL);
	KNH_SIZEREF(ctx);
}

static void Iterator_free(CTX ctx, kRawPtr *o)
{
	kIterator *itr = (kIterator*)o;
	knh_Iterator_close(ctx, itr);
#ifndef K_USING_BMGC
	knh_bodyfree(ctx, itr->b, Iterator);
#endif
}

static void Iterator_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kIterator *it = (kIterator*)o;
	kclass_t p1 = O_p1(it);
	if(IS_FMTdump(level)) {
		ksfp_t *lsfp = ctx->esp;
		KNH_SETv(ctx, lsfp[1].o, it);
		klr_setesp(ctx, lsfp + 2);
		size_t c = 0;
		while(it->fnext_1(ctx, lsfp+1, -1)) {
			if(c > 0) {
				knh_write_EOL(ctx, w);
			}
			if(IS_Tint(p1)) {
				knh_write_ifmt(ctx, w, KINT_FMT, lsfp[0].ivalue);
			}
			else if(IS_Tfloat(p1)) {
				knh_write_ffmt(ctx, w, KFLOAT_FMT, lsfp[0].fvalue);
			}
			else {
				knh_write_Object(ctx, w, lsfp[0].o, FMT_data);
			}
			c++;
			KNH_SETv(ctx, lsfp[1].o, it);
			klr_setesp(ctx, lsfp + 2);
		}
	}
}

static const kclassdef_t IteratorDef = {
	Iterator_init, DEFAULT_initcopy, Iterator_reftrace, Iterator_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Iterator_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Iterator", CFLAG_Iterator, sizeof(knh_IteratorEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Iterator), 0,
};

/* --------------- */
/* Map */

static const knh_MapDPI_t* NULLMAP_config(CTX ctx, kclass_t p1, kclass_t p2);
static kmapptr_t *NULLMAP_init(CTX ctx, size_t init, const char *path, struct kDictMap *opt) { return NULL; }
static void NULLMAP_reftrace(CTX ctx, kmapptr_t *m FTRARG){}
static void NULLMAP_free(CTX ctx, kmapptr_t *m){}
static kbool_t NULLMAP_get(CTX ctx, kmapptr_t* m, ksfp_t *ksfp, ksfp_t *rsfp) { return 0; }
static void NULLMAP_set(CTX ctx, kmapptr_t* m, ksfp_t *ksfp) {}
static void NULLMAP_remove(CTX ctx, kmapptr_t* m, ksfp_t *ksfp) {}
static size_t NULLMAP_size(CTX ctx, kmapptr_t* m) { return 0; }
static kbool_t NULLMAP_next(CTX ctx, kmapptr_t* m, knitr_t *mitr, ksfp_t *rsfp) { return 0; }

static const knh_MapDPI_t NULLMAP = {
	K_DSPI_MAP, "NULL",
	NULLMAP_config, NULLMAP_init, NULLMAP_reftrace, NULLMAP_free,
	NULLMAP_get, NULLMAP_set, NULLMAP_remove, NULLMAP_size, NULLMAP_next,
};

static const knh_MapDPI_t* NULLMAP_config(CTX ctx, kclass_t p1, kclass_t p2)
{
	return &NULLMAP;
}

static void Map_init(CTX ctx, kRawPtr *o)
{
	kMap *m = (kMap*)o;
	m->spi = &NULLMAP;
	m->mapptr = NULL;
}

static void TODO_initcopy(CTX ctx, kRawPtr *d, kRawPtr *s)
{
	KNH_TODO(__FUNCTION__);
}

static void Map_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kMap *m = (kMap*)o;
	m->spi->reftrace(ctx, m->mapptr FTRDATA);
}

static void Map_free(CTX ctx, kRawPtr *o)
{
	kMap *m = (kMap*)o;
	m->spi->freemap(ctx, m->mapptr);
}

static void Map_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kMap *m = (kMap*)o;
	size_t n = m->spi->size(ctx, m->mapptr);
	knh_putc(ctx, w, '{');
	if(n > 0) {
		BEGIN_LOCAL(ctx, lsfp, 2);
		kclass_t p1 = O_cTBL(o)->p1, p2 = O_cTBL(o)->p2;
		knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
		if(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
			knh_write_sfp(ctx, w, p1, lsfp, FMT_line);
			knh_write(ctx, w, STEXT(": "));
			knh_write_sfp(ctx, w, p2, lsfp+1, FMT_data);
			if(!IS_FMTline(level)) {
				while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
					knh_write(ctx, w, STEXT(", "));
					knh_write_sfp(ctx, w, p1, lsfp, FMT_line);
					knh_write(ctx, w, STEXT(": "));
					knh_write_sfp(ctx, w, p2, lsfp+1, FMT_data);
				}
			}
			else {
				knh_write_delimdots(ctx, w);
			}
		}
		END_LOCAL(ctx, lsfp);
	}
	knh_putc(ctx, w, '}');
}

static void pack_sfp(CTX ctx, void *pkr, kclass_t cid, ksfp_t *sfp, const knh_PackSPI_t *packspi)
{
	if (IS_Tunbox(cid)) {
		if (IS_Tint(cid)) {
			packspi->pack_int(ctx, pkr, sfp[0].ivalue);
		} else if (IS_Tfloat(cid)) {
			packspi->pack_float(ctx, pkr, sfp[0].fvalue);
		} else {
			packspi->pack_bool(ctx, pkr, sfp[0].bvalue);
		}
	} else {
		O_cTBL(sfp[0].o)->cdef->wdata(ctx, RAWPTR(sfp[0].o), pkr, packspi);
	}
}


static void Map_wdata(CTX ctx, kRawPtr *o, void *pkr, const knh_PackSPI_t *packspi)
{
	kMap *m = (kMap*)o;
	size_t i = 0, n = m->spi->size(ctx, m->mapptr);

	packspi->pack_beginmap(ctx, pkr, n + 1);
	if(n > 0) {
		BEGIN_LOCAL(ctx, lsfp, 2);
		kclass_t p1 = O_cTBL(o)->p1, p2 = O_cTBL(o)->p2;
		knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
		while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
			if (i++ != 0) {
				packspi->pack_putc(ctx, pkr, ',');
			}
			pack_sfp(ctx, pkr, p1, lsfp, packspi);
			packspi->pack_putc(ctx, pkr, ':');
			pack_sfp(ctx, pkr, p2, lsfp+1, packspi);
		}
		END_LOCAL(ctx, lsfp);
	}
	packspi->pack_endmap(ctx, pkr);
}


static const kclassdef_t MapDef = {
	Map_init, TODO_initcopy, Map_reftrace, Map_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Map_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, Map_wdata, DEFAULT_2, DEFAULT_3,
	"Map", CFLAG_Map, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Map), 0,
};

/* --------------- */
/* Class */

static int Class_compareTo(kRawPtr *o, kRawPtr *o2)
{
	kClass *c = (kClass*)o;
	kClass *c2 = (kClass*)o2;
	return knh_strcmp(S_totext(c->cTBL->lname), S_totext(c2->cTBL->lname));
}

static kString *Class_getkey(CTX ctx,ksfp_t *sfp)
{
	kClass *c = (kClass*)sfp[0].o;
	return ClassTBL(c->cid)->lname;
}

static khashcode_t Class_hashCode(CTX ctx, kRawPtr *o)
{
	kClass *c = (kClass*)o;
	return (khashcode_t)c->cid;
}

static void Class_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	knh_write_cid(ctx, w, knh_Class_cid((kClass*)o));
}

static const kclassdef_t ClassDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, Class_compareTo, Class_p,
	Class_getkey, Class_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Class", CFLAG_Class, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Class), 0,
};

/* --------------- */
/* Param */

static void Param_init(CTX ctx, kRawPtr *o)
{
	kParam *pa = (kParam*)o;
	pa->psize = 0;
	pa->rsize = 0;
	pa->params = NULL;
	pa->capacity = 0;
}

static void Param_free(CTX ctx, kRawPtr *o)
{
	kParam *pa = (kParam*)o;
	if(pa->psize + pa->rsize > 3) {
		KNH_FREE(ctx, pa->params, pa->capacity * sizeof(kparam_t));
	}
}

static void Param_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kParam *pa = (kParam*)o;
	size_t i;
	for(i = 0; i < pa->psize; i++) {
		kparam_t *p = knh_Param_get(pa, i);
		if(i > 0) knh_write_delim(ctx, w);
		knh_write_type(ctx, w, p->type);
		if(IS_FMTdump(level)) {
			knh_putc(ctx, w, ' ');
			knh_write_fn(ctx, w, p->fn);
		}
	}
	if(pa->rsize > 0) {
		knh_write(ctx, w, STEXT(" => "));
		for(i = 0; i < pa->rsize; i++) {
			kparam_t *p = knh_Param_rget(pa, i);
			knh_write_type(ctx, w, p->type);
		}
	}
}

static const kclassdef_t ParamDef = {
	Param_init, TODO_initcopy, DEFAULT_reftrace, Param_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Param_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Param", CFLAG_Param, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Param), 0,
};

/* --------------- */
/* Method */

static void Method_init(CTX ctx, kRawPtr *o)
{
	kMethod *mtd = (kMethod*)o;
	knh_MethodEX_t *b;
#ifndef K_USING_BMGC
	b = knh_bodymalloc(ctx, Method);
	mtd->b = b;
#else
	b = DP(mtd);
#endif
	KNH_INITv(b->mp, KNH_NULVAL(CLASS_Param));
	KNH_INITv(b->kcode, KNH_NULL);
	KNH_INITv(b->tsource, KNH_NULL);
	b->paramsNULL = NULL;
//	b->flag   = 0;
//	b->delta  = 0;
//	b->uri  = 0;  b->domain = 0;
}

static void Method_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kMethod *mtd = (kMethod*)o;
	knh_MethodEX_t *b = DP(mtd);
	KNH_ADDREF(ctx, b->mp);
	KNH_ADDREF(ctx, b->kcode);
	KNH_ADDREF(ctx, b->tsource);
	KNH_ADDNNREF(ctx, b->paramsNULL);
	KNH_SIZEREF(ctx);
}

static void BODY_free(CTX ctx, kRawPtr *o)
{
#ifndef K_USING_BMGC
	const knh_ClassTBL_t *ct = O_cTBL(o);
	DBG_ASSERT(ct->cdef->struct_size > 0);
	KNH_FREE(ctx, o->rawptr, ct->cdef->struct_size);
#endif
}

static void Method_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kMethod *mtd = (kMethod*)o;
	if(!(IS_FMTline(level))) {
		if(Method_isAbstract(mtd)) {
			knh_write(ctx, w, STEXT("@Abstract")); knh_putc(ctx, w, ' ');
		}
		if(Method_isPrivate(mtd)) {
			knh_write(ctx, w, STEXT("@Private"));  knh_putc(ctx, w, ' ');
		}
		if(Method_isStatic(mtd)) {
			knh_write(ctx, w, STEXT("@Static"));   knh_putc(ctx, w, ' ');
		}
		knh_write_type(ctx, w, knh_Param_rtype(DP(mtd)->mp));
		knh_putc(ctx, w, ' ');
	}
	knh_write_cname(ctx, w, (mtd)->cid);
	knh_putc(ctx, w, '.');
	knh_write_mn(ctx, w, (mtd)->mn);
	if(!(IS_FMTline(level))) {
		size_t i;
		knh_putc(ctx, w, '(');
		for(i = 0; i < knh_Method_psize(mtd); i++) {
			kparam_t *p = knh_Param_get(DP(mtd)->mp, i);
			if(i > 0) {
				knh_write_delim(ctx, w);
			}
			knh_write_type(ctx, w, p->type);
			knh_putc(ctx, w, ' ');
			knh_write(ctx, w, B(FN__(p->fn)));
		}
		if(Param_isVARGs(DP(mtd)->mp)) {
			knh_write_delimdots(ctx, w);
		}
		knh_putc(ctx, w, ')');
	}
	if(IS_FMTdump(level)) {
		if(!IS_NULL(DP(mtd)->objdata)) {
			knh_write_EOL(ctx, w);
			knh_write_InObject(ctx, w, DP(mtd)->objdata, level);
		}
	}
}

static const kclassdef_t MethodDef = {
	Method_init, TODO_initcopy, Method_reftrace, BODY_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Method_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Method", CFLAG_Method, sizeof(knh_MethodEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Method), 0,
};

/* --------------- */
/* TypeMap */

static void TypeMap_init(CTX ctx, kRawPtr *o)
{
	kTypeMap *tmr = (kTypeMap*)o;
	tmr->scid = 0;
	tmr->tcid = 0;
	KNH_INITv(tmr->mapdata, KNH_NULL);
	KNH_INITv(tmr->tmr2, KNH_NULL);
}

static void TypeMap_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kTypeMap *tmr = (kTypeMap*)o;
	KNH_ADDREF(ctx, tmr->mapdata);
	KNH_ADDREF(ctx, tmr->tmr2);
	KNH_SIZEREF(ctx);
}

static void TypeMap_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kTypeMap *tmr = (kTypeMap*)o;
	knh_write_type(ctx, w, tmr->scid);
	knh_write(ctx, w, STEXT("=>"));
	knh_write_type(ctx, w, tmr->tcid);
}

static const kclassdef_t TypeMapDef = {
	TypeMap_init, TODO_initcopy, TypeMap_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, TypeMap_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"TypeMap", CFLAG_TypeMap, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(TypeMap), 0,
};

/* --------------- */
/* Func */

static KMETHOD Fmethod_funcRTYPE(CTX ctx, ksfp_t *sfp _RIX)
{
	ktype_t rtype = knh_Param_rtype(DP(sfp[K_MTDIDX].mtdNC)->mp);
	if(rtype != TYPE_void) {
		if(IS_Tunbox(rtype)) {
			RETURNi_(KINT0);  // same results in Float, Boolean
		}
		else {
			RETURN_(KNH_NULVAL(CLASS_t(rtype)));
		}
	}
}

static void Func_init(CTX ctx, kRawPtr *o)
{
	kFunc *fo = (kFunc*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	kMethod *mtd;
	if(t->defnull == NULL) {
		mtd = new_Method(ctx, 0, O_cid(o), MN_LAMBDA, Fmethod_funcRTYPE);
		KNH_SETv(ctx, DP(mtd)->mp, t->cparam);
	}
	else {
		mtd = t->deffunc->mtd;
	}
	KNH_INITv(fo->mtd, mtd);
	fo->baseNULL = NULL;
}

static void Func_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kFunc *fo = (kFunc*)o;
	KNH_ADDREF(ctx, (fo->mtd));
	KNH_ADDNNREF(ctx, fo->baseNULL);
//		size_t i, stacksize = (fo)->hstacksize[-1];
//		for(i = 0; i < stacksize; i++) {
//			KNH_ADDREF(ctx, (fo)->envsfp[i].o);
//		}
	KNH_SIZEREF(ctx);
}

static void Func_free(CTX ctx, kRawPtr *o)
{
//	kFunc *cc = (kFunc*)o;
//	if(Func_isStoredEnv(cc)) {
//		size_t stacksize = (cc)->hstacksize[-1];
//		KNH_FREE(ctx, (cc)->envsfp, (sizeof(ksfp_t) * stacksize) + sizeof(size_t));
//		(cc)->envsfp = NULL;
//		Func_setStoredEnv(cc, 0);
//	}
}

static void Func_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
    kMethod *mtd = ((kFunc*)o)->mtd;
    knh_write_cname(ctx, w, (mtd)->cid);
    knh_putc(ctx, w, '.');
    knh_write_mn(ctx, w, (mtd)->mn);
}

static const kclassdef_t FuncDef = {
	Func_init, TODO_initcopy, Func_reftrace, Func_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Func_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Func", CFLAG_Func, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Func), 0,
};

/* --------------- */
/* Thunk */

static void Thunk_newenv(CTX ctx, kThunk *thk, size_t envsize)
{
	size_t i;
	thk->envsize = envsize;
	thk->envsfp = (ksfp_t*)KNH_MALLOC(ctx, sizeof(ksfp_t) * envsize);
	for(i = 0; i < envsize; i++) {
		KNH_INITv((thk)->envsfp[i].o, KNH_NULL);
		(thk)->envsfp[i].ndata = 0;
	}
}

static void Thunk_init(CTX ctx, kRawPtr *o)
{
	kThunk *thk = (kThunk*)o;
	kMethod *mtd = ClassTBL_getMethodNULL(ctx, ClassTBL(CLASS_Thunk), MN_);
	DBG_ASSERT(mtd != NULL);
	Thunk_newenv(ctx, thk, K_CALLDELTA);
	KNH_SETv(ctx, thk->envsfp[0].o, KNH_NULVAL(O_p1(thk)));
	thk->envsfp[K_CALLDELTA+K_MTDIDX].mtdNC = mtd;
}

kThunk* new_Thunk(CTX ctx, kclass_t p1, size_t envsize)
{
	kclass_t cid = knh_class_P1(ctx, CLASS_Thunk, p1);
	kThunk *thk = (kThunk*)new_hObject_(ctx, ClassTBL(cid));
	Thunk_newenv(ctx, thk, envsize);
	return thk;
}

static void Thunk_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kThunk *thk = (kThunk*)o;
	size_t i;
	for(i = 0; i < (thk)->envsize; i++) {
		KNH_ADDREF(ctx, (thk)->envsfp[i].o);
	}
	KNH_SIZEREF(ctx);
}

static void Thunk_free(CTX ctx, kRawPtr *o)
{
	kThunk *thunk = (kThunk*)o;
	KNH_FREE(ctx, thunk->envsfp, sizeof(ksfp_t) * thunk->envsize);
	thunk->envsfp = NULL;
	thunk->envsize = 0;
}

static const kclassdef_t ThunkDef = {
	Thunk_init, TODO_initcopy, Thunk_reftrace, Thunk_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Thunk", CFLAG_Thunk, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Thunk), 0,
};

/* --------------- */
/* Exception */

static void Exception_init(CTX ctx, kRawPtr *o)
{
	kException *e = (kException*)o;
	KNH_INITv(e->emsg, TS_EMPTY);
	e->tracesNULL = NULL;
	e->uline = 0;
}

static void Exception_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kException *e = (kException*)o;
	KNH_ADDREF(ctx, e->emsg);
	KNH_ADDNNREF(ctx, e->tracesNULL);
	KNH_SIZEREF(ctx);
}

static void Exception_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kException *e = (kException*)o;
	if(e->uline != 0 && IS_FMTdump(level)) {
		knh_write_uline(ctx, w, e->uline);
	}
	knh_write(ctx, w, S_tobytes(e->emsg));
	if(e->tracesNULL != NULL && IS_FMTdump(level)) {
		kArray *a = e->tracesNULL;
		size_t i, size = knh_Array_size(a), c = 0;
		kbytes_t prev = STEXT("?");
		knh_write_EOL(ctx, w);
		for(i = 0; i < size; i++) {
			kString *s = a->strings[i];
			if(S_startsWith(s, prev)) {
				c++; continue;
			}
			if(c > 0) {
				knh_write_EOL(ctx, w);
				knh_printf(ctx, w, "  *** called %d times recursively ***", c);
				c = 0;
			}
			knh_write_EOL(ctx, w);
			knh_printf(ctx, w, "  at %s", S_totext(s));
			prev = S_tobytes(s);
			prev = knh_bytes_first(prev, knh_bytes_rindex(prev, '('));
		}
		knh_write_EOL(ctx, w);
	}
}

static const kclassdef_t ExceptionDef = {
	Exception_init, TODO_initcopy, Exception_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Exception_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Exception", CFLAG_Exception, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Exception), 0,
};

/* --------------- */
/* ExceptionHandler */

static void ExceptionHandler_init(CTX ctx, kRawPtr *o)
{
	kExceptionHandler *hdr = (kExceptionHandler*)o;
	knh_ExceptionHandlerEX_t *b;
#ifdef K_USING_BMGC
	b = DP(hdr);
#else
	b = knh_bodymalloc(ctx, ExceptionHandler);
	o->rawptr = b;
#endif
	knh_bzero(b, sizeof(knh_ExceptionHandlerEX_t));
	KNH_INITv(hdr->stacklist, new_Array0(ctx, 0));
}

static void ExceptionHandler_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kExceptionHandler *hdr = (kExceptionHandler*)o;
	KNH_ADDREF(ctx, hdr->stacklist);
	KNH_SIZEREF(ctx);
}

static const kclassdef_t ExceptionHandlerDef = {
	ExceptionHandler_init, TODO_initcopy, ExceptionHandler_reftrace, BODY_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"ExceptionHandler", CFLAG_ExceptionHandler, sizeof(knh_ExceptionHandlerEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(ExceptionHandler), 0,
};

/* --------------- */
/* Regex */

static void Regex_init(CTX ctx, kRawPtr *o)
{
	kRegex *re = (kRegex*)o;
	KNH_INITv(re->pattern, TS_EMPTY);
	re->spi = knh_getStrRegexSPI();
	re->reg = (kregex_t*)TS_EMPTY;
}

static void Regex_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kRegex *re = (kRegex*)o;
	KNH_ADDREF(ctx, (re->pattern));
	KNH_SIZEREF(ctx);
}

static void Regex_free(CTX ctx, kRawPtr *o)
{
	kRegex *re = (kRegex*)o;
	if(re->reg != NULL) {
		re->spi->regfree(ctx, re->reg);
		re->spi = NULL;
		re->reg = NULL;
	}
}

static void Regex_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kRegex *re = (kRegex*)o;
	kbytes_t t = S_tobytes(re->pattern);
	size_t i;
	knh_putc(ctx, w, '/');
	for(i = 0; i < t.len; i++) {
		int ch = t.buf[i];
		if(ch == '/') {
			knh_putc(ctx, w, '\\');
		}
		knh_putc(ctx, w, ch);
	}
	knh_putc(ctx, w, '/');
}

static const kclassdef_t RegexDef = {
	Regex_init, DEFAULT_initcopy, Regex_reftrace, Regex_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Regex_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Regex", CFLAG_Regex, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Regex), 0,
};

/* --------------- */
/* StringEncoder */

static kbool_t conv_NOCONV(CTX ctx, knh_conv_t *c, const char *t, size_t s, kBytes *tobuf)
{
	knh_Bytes_write2(ctx, tobuf, t, s);  // this is necessary for default StringEncoder
	return 1;
}

static knh_ConverterDPI_t NOCONV_DSPI = {
	K_DSPI_CONVTO, "NOP",
	NULL,
	conv_NOCONV,
	conv_NOCONV,
	conv_NOCONV,
	conv_NOCONV,
	NULL/*knh_close_NOCONV*/,
	NULL/*knh_conv_NOSET*/,
};

static void Converter_init(CTX ctx, kRawPtr *o)
{
	kConverter *bc = (kConverter*)o;
	bc->conv = NULL;
	bc->dpi = &NOCONV_DSPI;
}

static void Converter_free(CTX ctx, kRawPtr *o)
{
	kConverter *bc = (kConverter*)o;
	if(bc->conv != NULL) {
		bc->dpi->close(ctx, bc->conv);
		bc->conv = NULL;
		bc->dpi = &NOCONV_DSPI;
	}
}

static const kclassdef_t ConverterDef = {
	Converter_init, DEFAULT_initcopy, DEFAULT_reftrace, Converter_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Converter", CFLAG_Converter, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Converter), 0,
};

static const kclassdef_t StringEncoderDef = {
	Converter_init, DEFAULT_initcopy, DEFAULT_reftrace, Converter_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"StringEncoder", CFLAG_StringEncoder, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(StringEncoder), 0,
};

static const kclassdef_t StringDecoderDef = {
	Converter_init, DEFAULT_initcopy, DEFAULT_reftrace, Converter_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"StringDecoder", CFLAG_StringDecoder, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(StringDecoder), 0,
};

static const kclassdef_t StringConverterDef = {
	Converter_init, DEFAULT_initcopy, DEFAULT_reftrace, Converter_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"StringConverter", CFLAG_StringConverter, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(StringConverter), 0,
};

/* --------------- */
/* Semantics */

#ifdef K_USING_SEMANTICS

static int knh_fichk__nop(kSemantics *u, kint_t v)
{
	return 1;
}

static int knh_ficmp__signed(kSemantics *u, kint_t v1, kint_t v2)
{
	return (int)(v1 - v2);
}

static int knh_ffchk__default(kSemantics *u, kfloat_t v)
{
	return 1;
}

static int knh_ffcmp__default(kSemantics *u, kfloat_t v1, kfloat_t v2)
{
	kfloat_t delta = v1 - v2;
	if(delta == KFLOAT_ZERO) return 0;
	return delta < 0 ? -1 : 1;
}

static kString *knh_fsnew__default(CTX ctx, kclass_t cid, kbytes_t t, kString *orig, int *foundError)
{
	return new_String_(ctx, cid, t, orig);
}

static int knh_fscmp__default(kSemantics *u, kbytes_t v1, kbytes_t v2)
{
	return knh_bytes_strcmp(v1, v2);
}

#define FUNC(f)     f
#else
#define FUNC(f)     NULL

#endif

static void Semantics_init(CTX ctx, kRawPtr *o)
{
	knh_SemanticsEX_t *b;
#ifdef K_USING_BMGC
	b = DP((kSemantics*)o);
#else
	b = knh_bodymalloc(ctx, Semantics);
	o->rawptr = b;
#endif
	// common
	b->flag = 0;
	b->ucid  = 0;
	KNH_INITv(b->urn, TS_EMPTY);
	KNH_INITv(b->tag,  TS_EMPTY);
	b->ivalue = NULL;
	b->fvalue = NULL;
	b->svalue = NULL;

	// int
	b->imax  = KINT_MAX;
	b->imin  = KINT_MIN;
	b->fichk = FUNC(knh_fichk__nop);
	b->ficmp = FUNC(knh_ficmp__signed);

	// float
#ifndef K_USED_TO_BE_ON_LKM
	b->fstep = 0.001;
#else
	b->fstep = 1;
#endif
	b->fmax  = KFLOAT_MAX;
	b->fmin  = KFLOAT_MIN;
	b->ffchk = FUNC(knh_ffchk__default);
	b->ffcmp = FUNC(knh_ffcmp__default);
//	b->ffmt = knh_funitfmt__default;
//	b->FMT  = KFLOAT_FMT;

	// String
	b->fsnew = FUNC(knh_fsnew__default);
	b->fscmp = FUNC(knh_fscmp__default);
	//b->fsconv = NULL;
	KNH_INITv(b->bconv, KNH_NULL);
	b->charlen = 0;
	b->bytelen = 0;
	KNH_INITv(b->pattern, KNH_NULL);
//	KNH_INITv(b->vocabDictIdx, KNH_NULL);
}

static void Semantics_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kSemantics *u = (kSemantics*)o;
	knh_SemanticsEX_t *b = DP(u);
	KNH_ADDREF(ctx, (b->urn));
	KNH_ADDREF(ctx, (b->tag));
	KNH_ADDNNREF(ctx, (b->ivalue));
	KNH_ADDNNREF(ctx, (b->fvalue));
	KNH_ADDNNREF(ctx, (b->svalue));
	KNH_ADDREF(ctx, (b->bconv));
	KNH_ADDREF(ctx, (b->pattern));
//	KNH_ADDREF(ctx, (b->vocabDictIdx));
	KNH_SIZEREF(ctx);
}

static const kclassdef_t SemanticsDef = {
	Semantics_init, TODO_initcopy, Semantics_reftrace, BODY_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Semantics", CFLAG_Semantics, sizeof(knh_SemanticsEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Semantics), 0,
};

/* Path */

static void Path_init(CTX ctx, kRawPtr *o)
{
	kPath *pth = (kPath*)o;
	KNH_INITv(pth->urn, TS_EMPTY);
	pth->ospath = S_totext(pth->urn);
	pth->asize = 0;
	pth->dpi = knh_getDefaultPathStreamDPI();
}

static void Path_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kPath *pth = (kPath*)o;
	KNH_ADDREF(ctx, pth->urn);
	KNH_SIZEREF(ctx);
}

static void Path_free(CTX ctx, kRawPtr *o)
{
	kPath *pth = (kPath*)o;
	if(pth->asize > 0) {
		KNH_FREE(ctx, (void*)pth->ospath, pth->asize);
		pth->ospath = NULL;
		pth->asize = 0;
	}
}

static void Path_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kPath *pth = (kPath*)o;
	knh_write(ctx, w, S_tobytes(pth->urn));
}

static const kclassdef_t PathDef = {
	Path_init, TODO_initcopy, Path_reftrace, Path_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Path_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Path", CFLAG_Path, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Path), 0,
};

/* --------------- */
/* InputStream */

static void InputStream_init(CTX ctx, kRawPtr *o)
{
	kInputStream *in = (kInputStream*)o;
	in->decNULL = NULL;
	in->io2 = io2_null();
	KNH_INITv(in->path, ctx->share->cwdPath);
}

static void InputStream_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kInputStream *in = (kInputStream*)o;
	KNH_ADDREF(ctx,   in->path);
	KNH_ADDNNREF(ctx, in->decNULL);
	KNH_SIZEREF(ctx);
}

static void InputStream_free(CTX ctx, kRawPtr *o)
{
	kInputStream *in = (kInputStream*)o;
	io2_free(ctx, in->io2);
}

static void InputStream_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kInputStream *in = (kInputStream*)o;
	knh_write_quote(ctx, w, '\'', S_tobytes(in->path->urn), !String_isASCII(in->path->urn));
}

static const kclassdef_t InputStreamDef = {
	InputStream_init, DEFAULT_initcopy, InputStream_reftrace, InputStream_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, InputStream_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"InputStream", CFLAG_InputStream, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(InputStream), 0,
};

/* --------------- */
/* OutputStream */

static void OutputStream_init(CTX ctx, kRawPtr *o)
{
	kOutputStream *w = (kOutputStream*)o;
	w->io2 = io2_null();
	KNH_INITv(w->path, ctx->share->cwdPath);
	w->encNULL = NULL;
	w->bufferNULL = NULL;
}

static void OutputStream_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kOutputStream *w = (kOutputStream*)o;
	KNH_ADDNNREF(ctx, (w->encNULL));
	KNH_ADDNNREF(ctx, (w->bufferNULL));
	KNH_ADDREF(ctx, (w->path));
	KNH_SIZEREF(ctx);
}

static void OutputStream_free(CTX ctx, kRawPtr *o)
{
	kOutputStream *w = (kOutputStream*)o;
	io2_free(ctx, w->io2);
}

static void OutputStream_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kOutputStream *ous = (kOutputStream*)o;
	knh_write_quote(ctx, w, '\'', S_tobytes(ous->path->urn) , !String_isASCII(ous->path->urn));
}

static const kclassdef_t OutputStreamDef = {
	OutputStream_init, DEFAULT_initcopy, OutputStream_reftrace, OutputStream_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, OutputStream_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"OutputStream", CFLAG_OutputStream, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(OutputStream), 0,
};

/* --------------- */
/* Connection */

static void View_init(CTX ctx, kRawPtr *o)
{
	kView *rel = (kView*)rel;
	KNH_INITv(rel->path,  KNH_NULL);
	KNH_INITv(rel->conf, KNH_NULL);
}

static void View_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kView *rel = (kView*)rel;
	KNH_ADDREF(ctx, rel->path);
	KNH_ADDREF(ctx, rel->conf);
	KNH_SIZEREF(ctx);
}

static const kclassdef_t ViewDef = {
	View_init, DEFAULT_initcopy, View_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"View", CFLAG_View, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(View), 0,
};

/* --------------- */
/* Script */

static void Script_init(CTX ctx, kRawPtr *o)
{
	kScript *scr = (kScript*)o;
	kclass_t cid = new_ClassId(ctx);
	knh_ClassTBL_t *ct = varClassTBL(cid);
	scr->h.cTBL = (const knh_ClassTBL_t*)ct;
	DBG_ASSERT(ct->cdef == NULL);
	ct->cflag  = CFLAG_Script;
	ct->magicflag = KNH_MAGICFLAG(ct->cflag);
	ct->bcid   = CLASS_Script;
	ct->baseTBL = ClassTBL(CLASS_Script);
	ct->supcid = CLASS_Script;
	ct->supTBL = ClassTBL(CLASS_Script);
	knh_setClassDef(ctx, ct, ClassTBL(CLASS_Script)->cdef);
	KNH_INITv(ct->methods, K_EMPTYARRAY);
	KNH_INITv(ct->typemaps, K_EMPTYARRAY);
	knh_setClassName(ctx, cid, ClassTBL(CLASS_Script)->sname, ClassTBL(CLASS_Script)->sname);
	DBG_ASSERT(ct->defnull == NULL);
	scr->fields = NULL;
	knh_setClassDefaultValue(ctx, cid, scr, NULL);
	KNH_INITv(scr->ns, new_NameSpace(ctx, ctx->share->rootns));
}

static void Script_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	if(IS_FMTdump(level)) {
		const knh_ClassTBL_t *ct = O_cTBL(o);
		kScript *scr = (kScript*)o;
		size_t i;
		for(i = 0; i < ct->fsize; i++) {
			kfieldinfo_t *cf = ct->fields + i;
			if(cf->type == TYPE_void) continue;
			{
				ktype_t type = ktype_tocid(ctx, cf->type, ct->cid);
				knh_printf(ctx, w, "[%d] %T %s=", i, type, FN__(cf->fn));
				knh_write_TObject(ctx, w, type, scr->fields, i, FMT_line);
				knh_write_EOL(ctx, w);
			}
		}
	}
	else {
		ObjectField_p(ctx, w, o, level);
	}
}

static void Script_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kScript *scr = (kScript*)o;
	KNH_ADDREF(ctx, scr->ns);
	ObjectField_reftrace(ctx, o FTRDATA);
}

static const kclassdef_t ScriptDef = {
	Script_init, DEFAULT_initcopy, Script_reftrace, ObjectField_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Script_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Script", CFLAG_Script, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Script), 0,
};

/* --------------- */
/* NameSpace */

static void NameSpace_init(CTX ctx, kRawPtr *o)
{
	kNameSpace *ns = (kNameSpace*)o;
	knh_NameSpaceEX_t *b;
#ifdef K_USING_BMGC
	b = DP(ns);
#else
	b = knh_bodymalloc(ctx, NameSpace);
	ns->b = b;
#endif
	knh_bzero(b, sizeof(knh_NameSpaceEX_t));
	KNH_INITv(b->nsname, TS_main);
	KNH_INITv(ns->path, ctx->share->cwdPath);
	ns->parentNULL          = NULL;
	b->ffilinksNULL         = NULL;
	b->linkDictMapNULL      = NULL;
	b->name2ctDictSetNULL  = NULL;
	b->constDictCaseMapNULL = NULL;
	b->formattersNULL       = NULL;
	b->methodsNULL          = NULL;
	ns->gluehdr = NULL;
}

static void NameSpace_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kNameSpace *ns = (kNameSpace*)o;
	knh_NameSpaceEX_t *b = DP(ns);
	KNH_ADDREF(ctx, b->nsname);
	KNH_ADDREF(ctx, ns->path);
	KNH_ADDNNREF(ctx, ns->parentNULL);
	KNH_ADDNNREF(ctx, b->ffilinksNULL);
	KNH_ADDNNREF(ctx, b->linkDictMapNULL);
	KNH_ADDNNREF(ctx, b->name2ctDictSetNULL);
	KNH_ADDNNREF(ctx, b->name2dpiNameDictMapNULL);
	KNH_ADDNNREF(ctx, b->constDictCaseMapNULL);
	KNH_ADDNNREF(ctx, b->formattersNULL);
	KNH_ADDNNREF(ctx, b->methodsNULL);
	KNH_SIZEREF(ctx);
}

static void NameSpace_free(CTX ctx, kRawPtr *o)
{
	BODY_free(ctx, o);
}

static void NameSpace_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kNameSpace *ns = (kNameSpace*)o;
	knh_write_ascii(ctx, w, "ns:");
	knh_write(ctx, w, S_tobytes(ns->path->urn));
}

static const kclassdef_t NameSpaceDef = {
	NameSpace_init, TODO_initcopy, NameSpace_reftrace, NameSpace_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, NameSpace_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"NameSpace", CFLAG_NameSpace, sizeof(knh_NameSpaceEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(NameSpace), 0,
};

/* --------------- */
/* System */

#ifdef K_USING_NOFILE
#define stdin  NULL
#define stdout NULL
#define stderr NULL
#endif

static const kclassdef_t SystemDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"System", CFLAG_System, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(System), 0,
};

/* --------------- */
/* Context */

static void Context_init(CTX ctx, kRawPtr *o)
{
	KNH_TODO(__FUNCTION__);
}

static void Context_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	//KNH_TODO(__FUNCTION__);
}

static void Context_free(CTX ctx, kRawPtr *o)
{
	//KNH_TODO(__FUNCTION__);
}

static const kclassdef_t ContextDef = {
	Context_init, DEFAULT_initcopy, Context_reftrace, Context_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Context", CFLAG_Context, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Context), 0,
};


/* --------------- */
/* Assurance */

static void Assurance_init(CTX ctx, kRawPtr *o)
{
	kAssurance *g = (kAssurance*)o;
	KNH_INITv(g->msg, TS_EMPTY);
	g->aid = 0;
	g->stime = 0;
}

static void Assurance_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kAssurance *g = (kAssurance*)o;
	KNH_ADDREF(ctx, g->msg);
	KNH_SIZEREF(ctx);
}

static void Assurance_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kAssurance *g = (kAssurance*)o;
	knh_write_quote(ctx, w, '\'', S_tobytes(g->msg), !String_isASCII(g->msg));
}

static void Assurance_checkin(CTX ctx, ksfp_t *sfp, kRawPtr *o)
{
	static kuintptr_t uid = 0;
	kAssurance *g = (kAssurance*)o;
	g->aid = uid++;
	g->sfp = sfp;
	g->stime = (knh_getTimeMilliSecond() / 1000);
	KNH_NTRACE2(ctx, "konoha:checkin", K_OK, KNH_LDATA(LOG_i("id", g->aid),
				LOG_s("case", S_totext(g->msg))));
	Assurance_setCheckedIn(g, 1);
}

static void Assurance_checkout(CTX ctx, kRawPtr *o, int isFailed)
{
	kAssurance *g = (kAssurance*)o;
	//ksfp_t *sfp = g->sfp;
	kintptr_t t = (knh_getTimeMilliSecond() / 1000) - g->stime;
	if(isFailed) {
		KNH_NTRACE2(ctx, "konoha:assure", K_FAILED, KNH_LDATA(LOG_i("id", g->aid),
					LOG_s("case", S_totext(g->msg)), LOG_i("elapsed_time:s", t)));
		knh_logprintf("ac", 0, "FAILED @%s", S_totext(g->msg));
	}
	else {
		KNH_NTRACE2(ctx, "konoha:assure", K_NOTICE, KNH_LDATA(LOG_i("id", g->aid),
					LOG_s("case", S_totext(g->msg)), LOG_i("elapsed_time:s", t)));
		knh_logprintf("ac", 0, "PASSED @%s", S_totext(g->msg));
	}
	Assurance_setCheckedIn(g, 0);
}

static const kclassdef_t AssuranceDef = {
	Assurance_init, DEFAULT_initcopy, Assurance_reftrace, DEFAULT_free,
	Assurance_checkin, Assurance_checkout, DEFAULT_compareTo, Assurance_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Assurance", CFLAG_Assurance, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Assurance), 0,
};


#include "../sugar/struct.h"

/* --------------- */
/* Term */

static void Term_init(CTX ctx, kRawPtr *o)
{
	kTerm *tk = (kTerm*)o;
	tk->tt        =  TT_ASIS;
	tk->type      =  TYPE_var;
	tk->uline     =   0;
	tk->flag0 = 0;
	tk->index = 0;
	KNH_INITv(tk->data, KNH_NULL);
}

static void Term_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kTerm *tk = (kTerm*)o;
	KNH_ADDREF(ctx, tk->data);
	KNH_SIZEREF(ctx);
}

const char* TT__(kterm_t tt);

static void Term_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kTerm *tk = (kTerm*)o;
	kterm_t tt = tk->tt;
	if(tt < TT_NUM) {
		knh_write_ascii(ctx, w, TT__(tt));
		if(tt == TT_PARENTHESIS || tt == TT_BRACE || tt == TT_BRANCET) {
			if(IS_Term(tk->data)) {
				knh_write_InObject(ctx, w, tk->data, level);
			}
			else if(IS_Array(tk->data)) {
				size_t i;
				for(i = 0; i < knh_Array_size(tk->list); i++) {
					if(i > 0) knh_putc(ctx, w, ' ');
					knh_write_InObject(ctx, w, tk->list->list[i], level);
				}
			}
			if(tt == TT_PARENTHESIS) {
				knh_putc(ctx, w, ']');
			}else if(tt == TT_BRACE) {
				knh_putc(ctx, w, '}');
			}else {
				knh_putc(ctx, w, ']');
			}
		}
	}
	else {
		kbytes_t t = S_tobytes(tk->text);
		int hasUTF8 = !(String_isASCII(tk->text));
		switch(tt) {
		case TT_NUM: knh_write(ctx, w, t); break;
		case TT_STR:  knh_write_quote(ctx, w, '"', t, hasUTF8); break;
		case TT_TSTR: knh_write_quote(ctx, w, '\'', t, hasUTF8); break;
		case TT_ESTR: knh_write_quote(ctx, w, '`', t, hasUTF8); break;
		case TT_REGEX: knh_write_quote(ctx, w, '/', t, hasUTF8); break;
//		case TT_DOC:
		case TT_METAN: knh_putc(ctx, w, '@'); knh_write(ctx, w, t); break;
		case TT_PROPN: knh_putc(ctx, w, '$'); knh_write(ctx, w, t); break;
		case TT_URN: case TT_TLINK:
			knh_write_utf8(ctx, w, t, hasUTF8); break;
		case TT_NAME: case TT_UNAME:
			if(Term_isDOT(tk)) knh_putc(ctx, w, '.');
			if(Term_isGetter(tk)) knh_write(ctx, w, STEXT("get_"));
			else if(Term_isSetter(tk)) knh_write(ctx, w, STEXT("set_"));
			else if(Term_isISBOOL(tk)) knh_write(ctx, w, STEXT("is_"));
			knh_write(ctx, w, t); //break;
			if(Term_isExceptionType(tk)) {
				knh_write(ctx, w, STEXT("!!"));
			}
			break;
		case TT_FUNCNAME: case TT_UFUNCNAME:
			knh_write(ctx, w, t); break;
		case TT_PTYPE: {
			kArray *a = tk->list;
			size_t i;
			knh_write_Object(ctx, w, a->list[0], FMT_line);
			knh_putc(ctx, w, '<');
			for(i = 1; i < a->size; i++) {
				if(i > 1) knh_putc(ctx, w, ',');
				knh_write_Object(ctx, w, a->list[i], FMT_line);
			}
			knh_putc(ctx, w, '>');
			break;
		}
		case TT_CID:
			knh_write_cid(ctx, w, tk->cid); break;
		case TT_MN:
			knh_write_mn(ctx, w, tk->mn); break;
		case TT_CONST:
			knh_write_Object(ctx, w, tk->data, FMT_line);
			break;
		case TT_SYSVAL: case TT_FVAR: case TT_LVAR:
			if(IS_FMTdump(level) || !IS_String(tk->data)) {
				knh_write_ascii(ctx, w, TT__(tt));
				knh_putc(ctx, w, '=');
				knh_write_ifmt(ctx, w, KINT_FMT, (kint_t)tk->index);
				break;
			}
		case TT_FIELD: case TT_LFIELD:
			if(IS_FMTdump(level) || !IS_String(tk->data)) {
				knh_write_ascii(ctx, w, TT__(tt));
				knh_putc(ctx, w, '=');
				if(IS_Term(tk->data)) {
					knh_write_ifmt(ctx, w, KINT_FMT, (kint_t)tk->index);
				}
				else {
					knh_putc(ctx, w, '0');
				}
				knh_putc(ctx, w, '+');
				knh_write_ifmt(ctx, w, KINT_FMT, (kint_t)tk->index);
				break;
			}
		case TT_ERR:
			knh_write(ctx, w, t); break;
		default:
			fprintf(stderr, "DEFINE %s in Term_stmt", TT__(tt));
		}
	}
	if(IS_FMTdump(level)) {
		if(SP(tk)->uline != 0) {
			knh_write(ctx, w, STEXT("+L"));
			knh_write_ifmt(ctx, w, KINT_FMT, ULINE_line(tk->uline));
		}
		if(SP(tk)->type != TYPE_var) {
			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
		}
	}
}

static const kclassdef_t TermDef = {
	Term_init, TODO_initcopy, Term_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Term_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Term", CFLAG_Term, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Term), 0,
};

/* --------------- */
/* Stmt */

static void StmtExpr_init(CTX ctx, kRawPtr *o)
{
	kStmtExpr *stmt = (kStmtExpr*)o;
	knh_StmtEX_t *b;
#ifdef K_USING_BMGC
	b = DP(stmt);
#else
	b = knh_bodymalloc(ctx, Stmt);
	o->rawptr = b;
#endif
	SP(stmt)->uline = 0;
	SP(stmt)->stt   = STT_DONE;
	SP(stmt)->type = TYPE_var;
	(stmt)->terms = NULL;
	b->flag0 = 0;
	b->espidx = 0;
	b->size = 0;
	b->capacity = 0;
	KNH_INITv(b->metaDictCaseMap,  KNH_NULL);
	b->nextNULL = NULL;
}

static void StmtExpr_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kStmtExpr *stmt = (kStmtExpr*)o;
	knh_StmtEX_t *b = DP((kStmtExpr*)o);
	KNH_ADDREF(ctx, (b->metaDictCaseMap));
	KNH_ADDNNREF(ctx, (b->nextNULL));
	if(stmt->terms != NULL) {
		size_t i;
		KNH_ENSUREREF(ctx, b->size);
		for(i = 0; i < b->size; i++) {
			KNH_ADDREF(ctx, stmt->terms[i]);
		}
	}
	KNH_SIZEREF(ctx);
}

static void StmtExpr_free(CTX ctx, kRawPtr *o)
{
	kStmtExpr *stmt = (kStmtExpr*)o;
	knh_StmtEX_t *b = DP((kStmtExpr*)o);
	if(stmt->terms != NULL) {
		KNH_FREE(ctx, stmt->terms, sizeof(kTerm*) * b->capacity);
		stmt->terms = NULL;
	}
	knh_bodyfree(ctx, b, Stmt);
}

static void StmtExpr_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kStmtExpr *stmt = (kStmtExpr*)o;
	kintptr_t i, size;
	L_TAILCALLED:;
	knh_putc(ctx, w, '(');
	if(!IS_FMTs(level)) {
		if(IS_Map(DP(stmt)->metaDictCaseMap)) {
			size = knh_Map_size(DP(stmt)->metaDictCaseMap);
			for(i = 0; i < size; i++) {
				kString *k = knh_DictMap_keyAt(DP(stmt)->metaDictCaseMap, i);
				kString *v = (kString*)knh_DictMap_valueAt(DP(stmt)->metaDictCaseMap, i);
				if(k == v) {
					knh_printf(ctx, w, "@%s ", S_totext(k));
				}
				else {
					knh_printf(ctx, w, "@%s(%O) ", S_totext(k), v);
				}
			}
		}
	}
	knh_write_ascii(ctx, w, TT__(stmt->stt));
	for(i = 0; i < DP(stmt)->size; i++) {
		knh_putc(ctx, w, ' ');
		knh_write_InObject(ctx, w, (Object*)(stmt->terms[i]), FMT_line);
	}
	knh_putc(ctx, w, ')');
	if(IS_FMTdump(level)) {
		if(SP(stmt)->type != TYPE_var) {
			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(stmt)->type);
		}
	}
	if(DP(stmt)->nextNULL != NULL) {
		if(IS_FMTdump(level)) {
			knh_write_EOL(ctx, w);
			stmt = DP(stmt)->nextNULL;
			goto L_TAILCALLED;
		}
		else {
			knh_write_dots(ctx, w);
		}
	}
}

static const kclassdef_t StmtExprDef = {
	StmtExpr_init, TODO_initcopy, StmtExpr_reftrace, StmtExpr_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, StmtExpr_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"StmtExpr", CFLAG_StmtExpr, sizeof(knh_StmtEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(StmtExpr), 0,
};

/* GammaBuilder */

static void GammaBuilder_init(CTX ctx, kRawPtr *o)
{
	knh_GammaBuilderEX_t *b;
#ifdef K_USING_BMGC
	b = DP((kGammaBuilder*)o);
#else
	b = knh_bodymalloc(ctx, GammaBuilder);
	o->rawptr = b;
#endif
	knh_bzero(b, sizeof(knh_GammaBuilderEX_t));
	b->cflag = FLAG_GammaBuilder_InlineFunction | FLAG_GammaBuilder_TailRecursion;
	KNH_INITv(b->mtd, KNH_NULL);
	KNH_INITv(b->stmt, KNH_NULL);
	KNH_INITv(b->lstacks, new_Array0(ctx, 0));
	KNH_INITv(b->insts, new_Array0(ctx, 0));
	KNH_INITv(b->errmsgs, new_Array0(ctx, 0));
	KNH_INITv(b->finallyStmt, KNH_NULL);
	KNH_INITv(((kGammaBuilder*)o)->scr, ctx->script);
}

static void GammaBuilder_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	size_t i;
	knh_GammaBuilderEX_t *b = DP((kGammaBuilder*)o);
	KNH_ENSUREREF(ctx, b->gcapacity * 3);
	for(i = 0; i < b->gcapacity; i++) {
		KNH_ADDREF(ctx, b->gf[i].tkIDX);
		KNH_ADDREF(ctx, b->gf[i].tk);
	}
	KNH_ADDREF(ctx, (b->mtd));
	KNH_ADDREF(ctx, (b->stmt));
	KNH_ADDREF(ctx, (b->lstacks));
	KNH_ADDREF(ctx, (b->insts));
	KNH_ADDREF(ctx, (b->errmsgs));
	KNH_ADDREF(ctx, (b->finallyStmt));
	KNH_ADDREF(ctx, ((kGammaBuilder*)o)->scr);
	KNH_SIZEREF(ctx);
}

static void GammaBuilder_free(CTX ctx, kRawPtr *o)
{
	knh_GammaBuilderEX_t *b = DP((kGammaBuilder*)o);
	if(b->gcapacity) {
		KNH_FREE(ctx, b->gf, b->gcapacity * sizeof(knh_gamma2_t));
	}
	knh_bodyfree(ctx, b, GammaBuilder);
}

static const kclassdef_t GammaBuilderDef = {
	GammaBuilder_init, TODO_initcopy, GammaBuilder_reftrace, GammaBuilder_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"GammaBuilder", CFLAG_GammaBuilder, sizeof(knh_GammaBuilderEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(GammaBuilder), 0,
};

/* --------------- */
/* BasicBlock */

static void BasicBlock_init(CTX ctx, kRawPtr *o)
{
	kBasicBlock *bb = (kBasicBlock*)o;
#ifndef K_USING_BMGC
	bb->b = knh_bodymalloc(ctx, BasicBlock);
#endif
	knh_bzero(DP(bb), sizeof(knh_BasicBlockEX_t));
	bb->listNC  = NULL;
	bb->nextNC  = NULL;
	bb->jumpNC  = NULL;
}

static void BasicBlock_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kBasicBlock *bb = (kBasicBlock*)o;
	size_t i;
	KNH_ENSUREREF(ctx, DP(bb)->size);
	for(i = 0; i < DP(bb)->size; i++) {
		tail_ = knh_opline_reftrace(ctx, DP(bb)->opbuf + i FTRDATA);
	}
	KNH_SIZEREF(ctx);
}

static void BasicBlock_free(CTX ctx, kRawPtr *o)
{
	kBasicBlock *bb = (kBasicBlock*)o;
	if(DP(bb)->capacity > 0) {
		KNH_FREE(ctx, DP(bb)->opbuf, DP(bb)->capacity * sizeof(kopl_t));
	}
	knh_bodyfree(ctx, DP(bb), BasicBlock);
}

static const kclassdef_t BasicBlockDef = {
	BasicBlock_init, TODO_initcopy, BasicBlock_reftrace, BasicBlock_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"BasicBlock", CFLAG_BasicBlock, sizeof(knh_BasicBlockEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(BasicBlock), 0,
};

/* --------------- */
/* KonohaCode */

static void KonohaCode_init(CTX ctx, kRawPtr *o)
{
	kKonohaCode *b = (kKonohaCode*)o;
	b->codesize = 0;
	b->code = NULL;
	b->uri = 0;
	KNH_INITv(b->source, TS_EMPTY);
}

static void KonohaCode_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kKonohaCode *b = (kKonohaCode*)o;
	kopl_t *pc = b->code;
	KNH_ADDREF(ctx, b->source);
	KNH_ENSUREREF(ctx, b->codesize / sizeof(kopl_t));
	while(pc->opcode != OPCODE_RET) {
		tail_ = knh_opline_reftrace(ctx, pc FTRDATA);
		pc++;
	}
	KNH_SIZEREF(ctx);
}

static void KonohaCode_free(CTX ctx, kRawPtr *o)
{
	kKonohaCode *b = (kKonohaCode*)o;
	KNH_FREE(ctx, b->code, b->codesize);
}

static void KonohaCode_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kKonohaCode *kcode = (kKonohaCode*)o;
	kopl_t *pc = kcode->code + 1;
	while(1) {
		knh_opcode_dump(ctx, pc, w, kcode->code + 1);
		if(pc->opcode == OPCODE_RET) break;
		pc++;
	}
}

static const kclassdef_t KonohaCodeDef = {
	KonohaCode_init, TODO_initcopy, KonohaCode_reftrace, KonohaCode_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, KonohaCode_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"KonohaCode", CFLAG_KonohaCode, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(KonohaCode), 0,
};

static const kclassdef_t ImmutableDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Immutable", CFLAG_Immutable, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Immutable), 0,
};

static const kclassdef_t KindOfDef = {
	DEFAULT_init, DEFAULT_initcopy, DEFAULT_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, DEFAULT_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"KindOf", CFLAG_KonohaCode, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(KindOf), 0,
};

/* --------------- */
/* @data*/

typedef struct {
	const char   *name;
	int           index;
} knh_StringData0_t ;

typedef struct {
	const char *name;
	ksymbol_t fn;
} kloadsymbol_t ;


#include"operator.c"
#include"structdata.h"

/* ------------------------------------------------------------------------ */

static Object *knh_Context_fdefault(CTX ctx, kclass_t cid)
{
	KNH_TODO(__FUNCTION__);
	return (Object*)ctx;
}

static void knh_setDefaultValues(CTX ctx)
{
	knh_setClassDefaultValue(ctx, CLASS_Object, KNH_NULL, NULL);
	knh_setClassDefaultValue(ctx, CLASS_Tdynamic, KNH_NULL, NULL);
	knh_setClassDefaultValue(ctx, CLASS_Boolean, KNH_FALSE, NULL);
	{
		kInt *io = new_H(Int);
		(io)->n.ivalue = 0;
		Object_setNullObject(io, 1);
		knh_setClassDefaultValue(ctx, CLASS_Int, io, NULL);
	}
	{
		kFloat *fo = new_H(Float);
		(fo)->n.fvalue = KFLOAT_ZERO;
		Object_setNullObject(fo, 1);
		knh_setClassDefaultValue(ctx, CLASS_Float, fo, NULL);
	}
	{
		kString *so = new_H(String);
		so->str.text = "";
		so->str.len = 0;
		so->hashCode = 0;
		String_setASCII(so, 1);
		String_setTextSgm(so, 1);
		Object_setNullObject(so, 1);
		knh_setClassDefaultValue(ctx, CLASS_String, so, NULL);
	}
	knh_setClassDefaultValue(ctx, CLASS_Path, ctx->share->cwdPath, NULL);
	knh_setClassDefaultValue(ctx, CLASS_Class, new_Type(ctx, CLASS_Tvoid), NULL);

#if defined(K_USING_SEMANTICS)
	{
		kSemantics *u = new_(Semantics);
		KNH_INITv(DP(u)->ivalue, KNH_INT0);
		KNH_INITv(DP(u)->fvalue, KNH_FLOAT0);
		KNH_INITv(DP(u)->svalue, TS_EMPTY);
		knh_setClassDefaultValue(ctx, CLASS_Semantics, u, NULL);
	}
#endif
	// load file/Channel/regex/db drivers
	knh_setClassDefaultValue(ctx, CLASS_Context, KNH_NULL, knh_Context_fdefault);
	knh_setClassDefaultValue(ctx, CLASS_NameSpace, UPCAST(ctx->share->rootns), NULL);
	knh_setClassDefaultValue(ctx, CLASS_Lang, UPCAST(ctx->share->corelang), NULL);
//	knh_setClassDefaultValue(ctx, CLASS_System, UPCAST(ctx->sys), NULL);
	knh_loadSystemDriver(ctx, ctx->share->rootns);
	{
		kTerm *tk = KNH_TNULL(Term);
		tk->tt = TT_FVAR;
		(tk)->index = 0;
	}
}

static void knh_loadScriptFieldNameData0(CTX ctx, kloadsymbol_t *data)
{
	while(data->name != NULL) {
		kString *name = new_T(data->name);
#if defined(K_USING_DEBUG)
		ksymbol_t fn = knh_addname(ctx, name, knh_DictSet_append);
		DBG_ASSERT(fn == data->fn - MN_OPSIZE);
#else
		knh_addname(ctx, name, knh_DictSet_append);
#endif
		data++;
	}
}

/* ------------------------------------------------------------------------ */
/* @data */

static const knh_IntData_t IntConstData0[] = {
	{"Int.MAX", KINT_MAX},
	{"Int.MIN", KINT_MIN},
	{NULL, 0}
};

static const knh_FloatData_t FloatConstData0[] = {
	{"Float.MAX", KFLOAT_MAX},
	{"Float.MIN", KFLOAT_MIN},
	{"Float.EPSLON", KFLOAT_EPSILON},
	{NULL, KFLOAT_ZERO}
};

static const knh_StringData_t StringConstData0[] = {
	{"$konoha.version", K_VERSION},
	{NULL, NULL},
};

#define FN_K FN_k
#define FN_V FN_v
#define FN_T FN_t
#define FN_U FN_u
#define FN_P FN_p
#define FN_R FN_r

#define _D(s)  (kloaddata_t)s
static const kloaddata_t CParamData0[] = {
	DATA_CPARAM, CLASS_Iterator,  _D("konoha.Iterator<dynamic>"), _D("dynamic" PTYPE_Iterator), 1, 0, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Range,     _D("konoha.Range<dynamic>"), _D("Range<dynamic>"), 1, 0, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Array,     _D("konoha.Array<dynamic>"), _D("dynamic" PTYPE_Array), 1, 0, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Map,       _D("konoha.Map<konoha.String,dynamic>"), _D("Map<String,dynamic>"), 2, 0, TYPE_String, FN_K, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Tuple,     _D("konoha.Map<konoha.String,dynamic>"), _D("Tuple<String,dynamic>"), 2, 0, TYPE_String, FN_K, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Func,      _D("konoha.Func<void>"), _D("Func<void>"), 0, 0,
	DATA_CPARAM, CLASS_Thunk,     _D("konoha.Thunk<dynamic>"), _D("Thunk<dynamic>"), 1, 0, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_Immutable, _D("konoha.Immutable<dynamic>"), _D("dynamic" PTYPE_Immutable), 1, 0, TYPE_dyn, FN_V,
	DATA_CPARAM, CLASS_KindOf,    _D("konoha.KindOf<void>"), _D("dynamic" PTYPE_KindOf), 1, 0, TYPE_void, FN_V,
	0,
};

void knh_loadScriptSystemStructData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadData(ctx, StructData0, NULL);
	{
		knh_ClassTBL_t *t = varClassTBL(CLASS_Tvoid);
		t->supcid = CLASS_Object;
		t->supTBL = ClassTBL(CLASS_Object);
		t = varClassTBL(CLASS_Tvar);
		t->supcid = CLASS_Object;
		t->supTBL = ClassTBL(CLASS_Object);
	}
}

void knh_loadScriptSystemString(CTX ctx)
{
	const char **data = StringData0;
	size_t i = 0;
	for(i = 0; *data != NULL; i++) {
		DBG_ASSERT(ctx->share->tString[i] == NULL);
		DBG_ASSERT(i < (SIZEOF_TSTRING / sizeof(kString*)));
		KNH_INITv(ctx->share->tString[i], new_T(*data));
		data++;
	}
}

void knh_loadScriptSystemData(CTX ctx, kNameSpace *ns, const knh_LoaderAPI_t *kapi)
{
	kapi->loadData(ctx, ClassData0, NULL);
	kapi->loadData(ctx, CParamData0, NULL);
	kapi->loadIntData(ctx, ns, IntConstData0);
	kapi->loadFloatData(ctx, ns, FloatConstData0);
	kapi->loadStringData(ctx, ns, StringConstData0);
	knh_getURI(ctx, STEXT("(eval)"));  // URI_EVAL
	knh_setDefaultValues(ctx);
	knh_loadScriptDefaultMapDSPI(ctx, ns);
}

void knh_loadScriptSystemMethod(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kParam *pools[K_PARAM0_SIZE];
	knh_loadScriptFieldNameData0(ctx, FieldNameData0);
	kapi->loadData(ctx, ParamData0, pools);
	kapi->loadData(ctx, APIData0, pools);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
