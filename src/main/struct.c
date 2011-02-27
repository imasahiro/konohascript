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

#define USE_STEXT 1
#define USE_B     1
#define USE_bytes_first       1
#define USE_bytes_index       1
#define USE_bytes_last        1
#define USE_bytes_index       1
#define USE_bytes_rindex      1
#define USE_bytes_indexOf     1
#define USE_bytes_strcmp      1
#define USE_bytes_startsWith  1
#define USE_bytes_endsWith    1
#define USE_bytes_parseint    1
#define USE_bytes_parsefloat  1
//#define USE_bytes_subbytes    1

#define USE_cwb_open      1
#define USE_cwb_openinit  1
#define USE_cwb_tobytes   1
#define USE_cwb_write     1
#define USE_cwb_putc      1
#define USE_cwb_size      1

#define USE_array_index   1

#define K_PERROR_LIBNAME   "stdc"
#define USE_fopen   1
#define USE_fclose  1
#define USE_fread   1
#define USE_fwrite  1
#define USE_fflush  1
#define USE_fclose  1

#define USE_hash    1

#define USE_TIME_H
#define USE_getTimeMilliSecond 1

#include"commons.h"
#include"../../include/konoha1/konoha_code_.h"

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

#define K_USING_DEFAULTAPI
#include"apidata/dspi.c"

static TCAST Array_Iterator(CTX ctx, knh_sfp_t *sfp _RIX);
static TCAST Iterator_Array(CTX ctx, knh_sfp_t *sfp _RIX);

#define knh_bodymalloc(ctx, C)   (knh_##C##EX_t*)KNH_MALLOC(ctx, sizeof(knh_##C##EX_t))
#define knh_bodyfree(ctx, p, C)  KNH_FREE(ctx, p, sizeof(knh_##C##EX_t))

/* ------------------------------------------------------------------------ */
/* DEFAULT */

static void DEFAULT_init(CTX ctx, Object *o)
{
	DBG_ASSERT((sizeof(knh_Object_t) - sizeof(knh_hObject_t)) == sizeof(knh_intptr_t) * 4);
	knh_intptr_t *p = (knh_intptr_t*)&(o->ref);
	p[0] = K_INT0; p[1] = K_INT0; p[2] = K_INT0; p[3] = K_INT0;
}

static void ABSTRACT_init(CTX ctx, Object *o)
{
	KNH_P("ABSTRACT CLASS? %s", O__(o));
}

static void DEFAULT_initcopy(CTX ctx, Object *dst, const Object *src)
{
	KNH_TODO("copy operation");
}

knh_bool_t knh_class_canObjectCopy(CTX ctx, knh_class_t cid)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	return (ct->cspi2->initcopy != DEFAULT_initcopy);
}

void NONE_reftrace(CTX ctx, Object *o FTRARG)
{
}

static void DEFAULT_free(CTX ctx, Object *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->cspi2->size > 0) {
		DBG_P("FREE? %s", O__(o));
		KNH_FREE(ctx, o->ref, ct->cspi2->size);
	}
}

static int DEFAULT_compareTo(const Object *o1, const Object *o2)
{
	return (int)((knh_intptr_t)o1 - (knh_intptr_t)o2);
}

static knh_String_t* DEFAULT_getkey(CTX ctx, knh_sfp_t *sfp)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_write_type(ctx, cwb->w, O_cid(sfp[0].o));
	knh_putc(ctx, cwb->w, ':');
	knh_write__p(ctx, cwb->w, sfp[0].o);
	return knh_cwb_newString(ctx, cwb);
}

static knh_hashcode_t DEFAULT_hashCode(CTX ctx, knh_sfp_t *sfp)
{
	return ((knh_hashcode_t)sfp[0].o) / sizeof(knh_Object_t);
}

static knh_TypeMap_t* DEFAULT_findTypeMapNULL(CTX ctx, knh_class_t scid, knh_class_t tcid, int mode)
{
	//DBG_P("set default value cid=%d", cid);
	return NULL;
}

static void DEFAULT_checkin(CTX ctx, Object *o) {
}

static void DEFAULT_checkout(CTX ctx, Object *o, int isFailed) {
}

static void Tuple_init(CTX ctx, Object *o)
{
	knh_Tuple_t *of = (knh_Tuple_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(knh_Object_t*));
		}
		of->fields = v;
		knh_memcpy(v, t->defnull->ref, t->fsize * sizeof(knh_Object_t*));
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

static void ObjectField_initcopy(CTX ctx, Object *o, const Object *src);
static void ObjectField_reftrace(CTX ctx, Object *o FTRARG);
static void ObjectField_free(CTX ctx, Object *o);

static knh_ObjectSPI2_t Tvoid_SPI = {
	"void", 0, CFLAG_Tvoid_,
	Tuple_init, ObjectField_initcopy, ObjectField_reftrace, ObjectField_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t Tvar_SPI = {
	"var", 0, CFLAG_Tvoid_,
	DEFAULT_init, DEFAULT_initcopy, NONE_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Object */

static void ObjectField_init(CTX ctx, Object *o)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(knh_Object_t*));
		}
		of->fields = v;
		knh_memcpy(v, t->protoNULL->fields, t->fsize * sizeof(knh_Object_t*));
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

static void ObjectField_initcopy(CTX ctx, Object *o, const Object *src)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(knh_Object_t*));
		}
		of->fields = v;
		knh_memcpy(v, src->ref, t->fsize * sizeof(knh_Object_t*));
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

static void ObjectField_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	size_t i;
	for(i = 0; i < ct->fsize; i++) {
		if(ct->fields[i].israw == 0) {
			KNH_ADDREF(ctx, of->fields[i]);
		}
	}
	KNH_SIZEREF(ctx);
}

static void ObjectField_free(CTX ctx, Object *o)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
		KNH_FREE(ctx, of->fields, t->fsize * sizeof(knh_Object_t*));
	}
	DBG_(of->fields = NULL);
}

static int ObjectField_compareTo(const Object *o, const Object *o2)
{
	return o - o2;
}

static knh_String_t* ObjectField_getkey(CTX ctx, knh_sfp_t *sfp)
{
	int keyidx = O_cTBL(sfp[0].o)->keyidx;
	if(keyidx != -1) {
		knh_ObjectField_t *of = (knh_ObjectField_t*)sfp[0].o;
		DBG_ASSERT(IS_bString(of->fields[keyidx]));
		return (knh_String_t*)of->fields[keyidx];
	}
	return DEFAULT_getkey(ctx, sfp);
}

static knh_ObjectSPI2_t ObjectSPI = {
	"Object", 0, CFLAG_Object,
	ObjectField_init, ObjectField_initcopy, ObjectField_reftrace, ObjectField_free,
	ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static void ObjectFieldN_init(CTX ctx, Object *o)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	if(t->fsize > 0) {
		Object **v = &(of->smallobject);
		if(t->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, t->fsize * sizeof(knh_Object_t*));
		}
		of->fields = v;
		knh_memcpy(v, t->protoNULL->fields, t->fsize * sizeof(knh_Object_t*));
	}
	else {
		of->fields = NULL;
	}
}

static void ObjectFieldN_initcopy(CTX ctx, Object *o, const Object *src)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->fsize > 0) {
		Object **v = &(of->smallobject);
		if(ct->fsize > K_SMALLOBJECT_FIELDSIZE) {
			v = (Object**)KNH_MALLOC(ctx, ct->fsize * sizeof(knh_Object_t*));
		}
		of->fields = v;
		knh_memcpy(v, src->ref, ct->fsize * sizeof(knh_Object_t*));
	}
	else {
		of->fields = NULL;
	}
}

static void ObjectField1_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 1);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField2_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 2);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_ADDREF(ctx, of->fields[1]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField3_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
#ifdef K_USING_FASTREFS_
	KNH_SETREF(ctx, of->fields, 3);
#else
	KNH_ADDREF(ctx, of->fields[0]);
	KNH_ADDREF(ctx, of->fields[1]);
	KNH_ADDREF(ctx, of->fields[2]);
	KNH_SIZEREF(ctx);
#endif
}
static void ObjectField4_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ObjectField_t *of = (knh_ObjectField_t*)o;
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

static knh_ObjectSPI2_t ObjectNSPI[] = {
	{"Object", 0, CFLAG_Object,
		ObjectFieldN_init, ObjectFieldN_initcopy, NONE_reftrace, ObjectField_free,
		ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL,
	},
	{"Object", 0, CFLAG_Object,
		ObjectField_init, ObjectField_initcopy, ObjectField1_reftrace, ObjectField_free,
		ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL,
	},
	{"Object", 0, CFLAG_Object,
		ObjectField_init, ObjectField_initcopy, ObjectField2_reftrace, ObjectField_free,
		ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL,
	},
	{"Object", 0, CFLAG_Object,
		ObjectField_init, ObjectField_initcopy, ObjectField3_reftrace, ObjectField_free,
		ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL,
	},
	{"Object", 0, CFLAG_Object,
		ObjectField_init, ObjectField_initcopy, ObjectField4_reftrace, ObjectField_free,
		ObjectField_compareTo, ObjectField_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL,
	},
};

void knh_ClassTBL_setObjectCSPI(knh_ClassTBL_t *ct)
{
	size_t c, i;
	for(c = 0; c < ct->fsize; c++) {
		if(ct->fields[c].israw == 1) break;
	}
	for(i = c + 1; i < ct->fsize; i++) {
		if(ct->fields[i].israw == 0) {
			knh_ClassTBL_setCSPI2(ct, &ObjectSPI);
			return;
		}
	}
	if(c <= 4) {
		DBG_P("NO OBJECT FIELD: %s c=%d", S_tochar(ct->lname), c);
		knh_ClassTBL_setCSPI2(ct, ObjectNSPI + c);
	}
	else {
		knh_ClassTBL_setCSPI2(ct, &ObjectSPI);
	}
}

/* --------------- */
/* Boolean */

static void NDATA_initcopy(CTX ctx, Object *o, const Object *src)
{
	o->ref = src->ref;
	o->ref2_unused = src->ref2_unused;
	o->ref3_unused = src->ref3_unused;
	o->ref4_tail = src->ref4_tail;
}

static knh_ObjectSPI2_t BooleanSPI = {
	"Boolean", 0, CFLAG_Boolean,
	ABSTRACT_init, NDATA_initcopy, NONE_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Number */

static knh_ObjectSPI2_t NumberSPI = {
	"Number", 0, CFLAG_Number,
	ABSTRACT_init, DEFAULT_initcopy,
	NONE_reftrace, DEFAULT_free, DEFAULT_compareTo,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_checkin, DEFAULT_checkout,
	 DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Int */

//static int Int_compareTo(CTX ctx, Object *o, Object *o2)
//{
//	return (int)(knh_Object_data(o) - knh_Object_data(o2));
////	if(o->h.cid == CLASS_Int || o2->h.cid == CLASS_Int) {
////		return (int)(o->n.ivalue - o2->n.ivalue);
////	}
////	else {
////		knh_Semantics_t *u = knh_getSemantics(ctx, o->h.cid);
////		return DP(u)->ficmp(u, o->n.ivalue, o2->n.ivalue);
////	}
//}
//
//static void* Int_hashkey(CTX ctx, knh_sfp_t *lsfp, int opt)
//{
//	if(opt == KNH_FOBJECT_KEY) {
//		char buf[40];
//#ifdef K_USING_INT32
//		knh_snprintf(buf, sizeof(buf), "%016lu", lsfp[0].uvalue);
//#else
//		//18446744073709551615ULL
//		knh_snprintf(buf, sizeof(buf), "%020llu", lsfp[0].uvalue);
//#endif
//		return (void*)new_S(ctx, B(buf));
//	}
//	else {
//		return (void*)((knh_intptr_t)lsfp[0].uvalue);
//	}
//}

static knh_int_t Int_toint(CTX ctx, knh_sfp_t *sfp)
{
	return sfp[0].ivalue;
}

static knh_float_t Int_tofloat(CTX ctx, knh_sfp_t *sfp)
{
	return (knh_float_t)sfp[0].ivalue;
}

static knh_NumberSPI_t IntSPI = {
	{
		"Int", 0, CFLAG_Int,
		DEFAULT_init, NDATA_initcopy, NONE_reftrace,  DEFAULT_free,
		DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL, NULL, 0,
	},
	K_NUMBERCSPI_MAGIC,
	Int_toint, Int_tofloat,
};

/* --------------- */
/* Float */

//static int Float_compareTo(CTX ctx, Object *o, Object *o2)
//{
//	knh_float_t f = (knh_float_t)knh_Object_data(o);
//	knh_float_t f2 = (knh_float_t)knh_Object_data(o2);
//	if(f == f2) return 0;
//	if(f < f2) return -1; else return 1;
//}

static knh_int_t Float_toint(CTX ctx, knh_sfp_t *sfp)
{
	return (knh_int_t)sfp[0].fvalue;
}

static knh_float_t Float_tofloat(CTX ctx, knh_sfp_t *sfp)
{
	return sfp[0].fvalue;
}

static knh_NumberSPI_t FloatSPI = {
	{
		"Float", 0, CFLAG_Float,
		DEFAULT_init, NDATA_initcopy, NONE_reftrace,  DEFAULT_free,
		DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
		DEFAULT_checkin, DEFAULT_checkout,
		DEFAULT_findTypeMapNULL, NULL, 0,
	},
	K_NUMBERCSPI_MAGIC,
	Float_toint, Float_tofloat,
};

/* --------------- */
/* String */

static void String_init(CTX ctx, Object *o)
{
	knh_String_t *s = (knh_String_t*)o;
	s->str.text = "";
	s->str.len = 0;
	s->hashCode = 0;
	String_setTextSgm(s, 1);
}

static void String_free(CTX ctx, knh_Object_t *o)
{
	knh_String_t *s = (knh_String_t*)o;
//	DBG_P("s='%s', isTextSgm=%d", s->str.text, String_isTextSgm(s));
	if(!String_isTextSgm(s)) {
		KNH_FREE(ctx, s->str.ubuf, KNH_SIZE(S_size(s) + 1));
	}
}

static int String_compareTo(const knh_Object_t *o, const knh_Object_t *o2)
{
	knh_String_t *s1 = (knh_String_t*)o;
	knh_String_t *s2 = (knh_String_t*)o2;
#if defined(K_USING_SEMANTICS)
	if(s1->h.cid != CLASS_String && s2->h.cid != CLASS_String) {
		knh_Semantics_t *u = knh_getSemantics(ctx, s1->h.cid);
		return DP(u)->fscmp(u, S_tobytes(s1), S_tobytes(s2));
	}
#else
	return knh_bytes_strcmp(S_tobytes(s1) ,S_tobytes(s2));
#endif
}

static knh_String_t* String_getkey(CTX ctx, knh_sfp_t *sfp)
{
	return sfp[0].s;
}

static knh_hashcode_t String_hashCode(CTX ctx, knh_sfp_t *sfp)
{
	knh_bytes_t k = S_tobytes(sfp[0].s);
	return knh_hash(0, k.text, k.len);
}

static knh_ObjectSPI2_t StringSPI = {
	"String", 0, CFLAG_String,
	String_init, DEFAULT_initcopy, NONE_reftrace, String_free,
	String_compareTo, String_getkey, String_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Bytes */

static const knh_dim_t dimINIT = {
	0, 0, 0, 0, 0, 0, 0,
};

static void Bytes_init(CTX ctx, Object *o)
{
	knh_Bytes_t *ba = (knh_Bytes_t*)o;
	ba->bu.len = 0;
	ba->bu.ubuf = NULL;
	ba->dim = &dimINIT;
}

static const knh_dim_t* dim_copy(CTX ctx, const knh_dim_t *dim_src)
{
	if(dim_src->capacity == 0) {
		return dim_src;
	}
	else {
		knh_dim_t *dim = (knh_dim_t*)KNH_MALLOC(ctx, sizeof(knh_dim_t));
		dim = (knh_dim_t*)dim_src;
		return (const knh_dim_t*)dim;
	}
}

static void Bytes_initcopy(CTX ctx, Object *o, const Object *src)
{
	knh_Bytes_t *ba = (knh_Bytes_t*)o, *ba_src = (knh_Bytes_t*)src;
	if(ba_src->dim->capacity > 0) {
		ba->bu.len = ba_src->bu.len;
		ba->bu.ubuf = (knh_uchar_t*)KNH_MALLOC(ctx, ba_src->dim->capacity);
		knh_memcpy(ba->bu.ubuf, ba_src->bu.ubuf, ba_src->dim->capacity);
	}
	else {
		ba->bu.len = 0;
		ba->bu.ubuf = NULL;
	}
	ba->dim = dim_copy(ctx, ba_src->dim);
}

static void Bytes_free(CTX ctx, Object *o)
{
	knh_Bytes_t *ba = (knh_Bytes_t*)o;
	knh_dimfree(ctx, ba->bu.ubuf, ba->dim);
}

static knh_ObjectSPI2_t BytesSPI = {
	"Bytes", 0, CFLAG_Bytes,
	Bytes_init, Bytes_initcopy, NONE_reftrace, Bytes_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t BytesImSPI = {
	"BytesIm", 0, CFLAG_BytesIm,
	Bytes_init, Bytes_initcopy, NONE_reftrace, Bytes_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Range */

static void Range_init(CTX ctx, Object *o)
{
	knh_Range_t *rng = (knh_Range_t*)o;
	if(Range_isNDATA(o)) {
		rng->nstart = 0;
		rng->nend = 0;
	}
	else {
		KNH_INITv(rng->ostart, KNH_NULVAL(O_p1(rng)));
		KNH_INITv(rng->oend, rng->ostart);
	}
}

static void Range_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Range_t *rng = (knh_Range_t*)o;
	if(!Range_isNDATA(o)) {
		KNH_ADDREF(ctx, rng->ostart);
		KNH_ADDREF(ctx, rng->oend);
		KNH_SIZEREF(ctx);
	}
}

//static TCAST Range_Iterator(CTX ctx, knh_sfp_t *sfp _RIX);
#define FLAG_TypeMap_Iteration (FLAG_TypeMap_Total)

//static knh_TypeMap_t* knh_Range_genmap(CTX ctx, knh_class_t cid, knh_class_t tcid)
//{
////	if(knh_class_bcid(tcid) == CLASS_Iterator) {
////		knh_class_t p1 = knh_class_p1(cid); //Range<p1>
////		knh_class_t tp1 = knh_class_p1(tcid);  //Iterator<tp2>
////		if(p1 == tp1 || tp1 == CLASS_Tdynamic || knh_class_instanceof(ctx, p1, tp1)) {
////			return new_TypeMap(ctx, FLAG_TypeMap_Iteration, cid, tcid, Range_Iterator);
////		}
////	}
//	return NULL;
//}

static knh_ObjectSPI2_t RangeSPI = {
	"Range", 0, CFLAG_Range,
	Range_init, DEFAULT_initcopy, Range_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Array */

static void Array_init(CTX ctx, Object *o)
{
	knh_Array_t *a = (knh_Array_t*)o;
	knh_Array_initAPI(ctx, a);
	a->dim = &dimINIT;
	a->list = NULL;
	a->size = 0;
}

static void Array_initcopy(CTX ctx, Object *o, const Object *src)
{
	knh_Array_t *a = (knh_Array_t*)o, *a_src = (knh_Array_t*)src;
	a->api = a_src->api;
	if(a_src->dim->capacity > 0) {
		a->size = a_src->size;
		a->list = (knh_Object_t**)KNH_MALLOC(ctx, a_src->dim->capacity * a_src->dim->wsize);
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

static void Array_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Array_t *a = (knh_Array_t*)o;
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

static void Array_free(CTX ctx, Object *o)
{
	knh_Array_t *a = (knh_Array_t*)o;
	knh_dimfree(ctx, a->list, a->dim);
}

//static knh_TypeMap_t* knh_Array_findTransNULL(CTX ctx, knh_class_t cid, knh_class_t tcid)
//{
//	if(knh_class_bcid(tcid) == CLASS_Iterator) {
//		knh_class_t p1 = knh_class_p1(cid);
//		knh_class_t tp1 = knh_class_p1(tcid);
//		if(p1 == tp1 || tp1 == CLASS_Tdynamic || knh_class_instanceof(ctx, p1, tp1)) {
//			return new_TypeMap(ctx, FLAG_TypeMap_Iteration, cid, tcid, Array_Iterator);
//		}
//	}
//	return NULL;
//}

static knh_ObjectSPI2_t ArraySPI = {
	"Array", 0, CFLAG_Array,
	Array_init, Array_initcopy, Array_reftrace, Array_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t ArrayImSPI = {
	"ArrayIm", 0, CFLAG_ArrayIm,
	Array_init, Array_initcopy, Array_reftrace, Array_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Iterator */

static ITRNEXT Fitrnext_single(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
	knh_Iterator_t *it = sfp[0].it;
	if(DP(it)->pos == 0) {
		DP(it)->pos = 1;
		ITRNEXT_(DP(it)->source);
	}
	ITREND_();
}

static void Iterator_init(CTX ctx, Object *o)
{
	knh_Iterator_t *it = (knh_Iterator_t*)o;
	knh_IteratorEX_t *b = knh_bodymalloc(ctx, Iterator);
	b->fnext  =  Fitrnext_single;
	KNH_INITv(b->source, KNH_NULL);
	b->pos      =  0;
	b->ref      =  NULL;
	b->freffree = NULL;
	it->b = b;
}

static void Iterator_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Iterator_t *it = (knh_Iterator_t*)o;
	KNH_ADDREF(ctx, DP(it)->source);
	KNH_SIZEREF(ctx);
}

static void Iterator_free(CTX ctx, Object *o)
{
	knh_Iterator_t *it = (knh_Iterator_t*)o;
	knh_Iterator_close(ctx, it);
	knh_bodyfree(ctx, it->b, Iterator);
}

//static ITRNEXT knh_Iterator_filterNext(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	knh_Iterator_t *itr2 = (knh_Iterator_t*)DP(sfp[0].it)->source;
//	knh_class_t cid = O_p1(sfp[0].it);
//	DBG_ASSERT(IS_bIterator(itr2));
//	sfp = sfp + 1;
//	rtnidx = rtnidx - 1;
//	KNH_SETv(ctx, sfp[0].o, itr2);
//	int res = SP(itr2)->fnext_1(ctx, sfp, rtnidx);
//	while(res != 0) {
//		if(knh_class_instanceof(ctx, O_cid(sfp[rtnidx].o), cid)) break;
//		res = SP(itr2)->fnext_1(ctx, sfp, rtnidx);
//	}
//	return res;
//}
//
//static TCAST Iterator_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_TypeMap_t *trl = sfp[K_TRLIDX].trlNC;
//	RETURN_(new_Iterator(ctx, knh_class_p1(SP(trl)->tcid), sfp[K_TRLIDX].o, knh_Iterator_filterNext));
//}
//
//static knh_TypeMap_t* knh_Iterator_genmap(CTX ctx, knh_class_t cid, knh_class_t tcid)
//{
//	if(cid == CLASS_Iterator && knh_class_bcid(cid) == CLASS_Iterator) {
//		return new_TypeMap(ctx, FLAG_TypeMap_Iteration, CLASS_Iterator, cid, Iterator_Iterator);
//	}
//	if(knh_class_bcid(tcid) == CLASS_Array) {
//		knh_class_t p1 = knh_class_p1(cid);
//		knh_class_t tp1 = knh_class_p1(tcid);
//		if(p1 == tp1 || tp1 == CLASS_Tdynamic || knh_class_instanceof(ctx, p1, tp1)) {
//			return new_TypeMap(ctx, FLAG_TypeMap_Iteration, cid, tcid, Iterator_Array);
//		}
//	}
//	return NULL;
//}

static knh_ObjectSPI2_t IteratorSPI = {
	"Iterator", sizeof(knh_IteratorEX_t), CFLAG_Iterator,
	Iterator_init, DEFAULT_initcopy, Iterator_reftrace, Iterator_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Map */

static const knh_MapDSPI_t* nullmap_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static knh_map_t *nullmap_init(CTX ctx, size_t init, const char *path, void *option)
{
	return NULL;
}
static void nullmap_reftrace(CTX ctx, knh_map_t *m FTRARG){}
static void nullmap_free(CTX ctx, knh_map_t *m){}
static knh_bool_t nullmap_get(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	return 0;
}
static void nullmap_set(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp){}
static void nullmap_remove(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp) {}

static size_t nullmap_size(CTX ctx, knh_map_t* m)
{
	return 0;
}
static knh_bool_t nullmap_setIterator(CTX ctx, knh_map_t* m, knh_Iterator_t *it)
{
	return 0;
}

static const knh_MapDSPI_t NULLMap = {
	K_DSPI_MAP, "nullmap",
	nullmap_config, nullmap_init, nullmap_reftrace, nullmap_free,
	nullmap_get, nullmap_set, nullmap_remove, nullmap_size,
	nullmap_setIterator,
};

static const knh_MapDSPI_t* nullmap_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	return &NULLMap;
}

static void Map_init(CTX ctx, Object *o)
{
	knh_Map_t *m = (knh_Map_t*)o;
	m->dspi = &NULLMap;
	m->map = NULL;
}

static void Map_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Map_t *m = (knh_Map_t*)o;
	m->dspi->reftrace(ctx, m->map FTRDATA);
}

static void Map_free(CTX ctx, Object *o)
{
	knh_Map_t *m = (knh_Map_t*)o;
	m->dspi->freemap(ctx, m->map);
}

static knh_ObjectSPI2_t MapSPI = {
	"Map", 0, CFLAG_Map,
	Map_init, DEFAULT_initcopy,
	Map_reftrace, Map_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,

	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t MapImSPI = {
	"MapIm", 0, CFLAG_MapIm,
	Map_init, DEFAULT_initcopy,
	Map_reftrace, Map_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,

	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Class */

static int Class_compareTo(const knh_Object_t *o, const knh_Object_t *o2)
{
	knh_Class_t *c = (knh_Class_t*)o;
	knh_Class_t *c2 = (knh_Class_t*)o2;
	return knh_strcmp(S_tochar(c->cTBL->lname), S_tochar(c2->cTBL->lname));
}

static knh_String_t *Class_getkey(CTX ctx,knh_sfp_t *sfp)
{
	knh_Class_t *c = (knh_Class_t*)sfp[0].o;
	return ClassTBL(c->cid)->lname;
}

static knh_hashcode_t Class_hashCode(CTX ctx,knh_sfp_t *sfp)
{
	knh_Class_t *c = (knh_Class_t*)sfp[0].o;
	return (knh_hashcode_t)c->cid;
}

static knh_ObjectSPI2_t ClassSPI = {
	"Class", 0, CFLAG_Class,
	DEFAULT_init, NDATA_initcopy, NONE_reftrace, DEFAULT_free,
	Class_compareTo, Class_getkey, Class_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* ParamArray */

static void ParamArray_init(CTX ctx, Object *o)
{
	knh_ParamArray_t *pa = (knh_ParamArray_t*)o;
	pa->psize = 0;
	pa->rsize = 0;
	pa->params = NULL;
	pa->capacity = 0;
}

static void ParamArray_free(CTX ctx, Object *o)
{
	knh_ParamArray_t *pa = (knh_ParamArray_t*)o;
	if(pa->psize + pa->rsize > 3) {
		KNH_FREE(ctx, pa->params, pa->capacity * sizeof(knh_param_t));
	}
}

static knh_ObjectSPI2_t ParamArraySPI = {
	"ParamArray", 0, CFLAG_ParamArray,
	ParamArray_init, DEFAULT_initcopy, NONE_reftrace, ParamArray_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Method */

static void Method_init(CTX ctx, Object *o)
{
	knh_Method_t *mtd = (knh_Method_t*)o;
	knh_MethodEX_t *b = knh_bodymalloc(ctx, Method);
	KNH_INITv(b->mp, KNH_NULVAL(CLASS_ParamArray));
	KNH_INITv(b->kcode, KNH_NULL);
//	b->flag   = 0;
//	b->delta  = 0;
//	b->uri  = 0;  b->domain = 0;
	mtd->b = b;
}

static void Method_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Method_t *mtd = (knh_Method_t*)o;
	knh_MethodEX_t *b = DP(mtd);
	KNH_ADDREF(ctx, b->mp);
	KNH_ADDREF(ctx, b->kcode);
	KNH_SIZEREF(ctx);
}

static void Method_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, Method);
}

static knh_ObjectSPI2_t MethodSPI = {
	"Method", sizeof(knh_MethodEX_t), CFLAG_Method,
	Method_init, DEFAULT_initcopy, Method_reftrace, Method_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* TypeMap */

static void TypeMap_init(CTX ctx, Object *o)
{
	knh_TypeMap_t *tmap = (knh_TypeMap_t*)o;
	knh_TypeMapEX_t *b = knh_bodymalloc(ctx, TypeMap);
	b->flag = 0;
	SP(tmap)->scid = CLASS_Object;
	SP(tmap)->tcid = CLASS_Object;
	KNH_INITv(b->mapdata, KNH_NULL);
	KNH_INITv(b->trl2, KNH_NULL);
	tmap->b = b;
}

static void TypeMap_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_TypeMap_t *tmap = (knh_TypeMap_t*)o;
	knh_TypeMapEX_t *b = DP(tmap);
	KNH_ADDREF(ctx, b->mapdata);
	KNH_ADDREF(ctx, (b->trl2));
	KNH_SIZEREF(ctx);
}

static void TypeMap_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, TypeMap);
}

static knh_ObjectSPI2_t TypeMapSPI = {
	"TypeMap", sizeof(knh_TypeMapEX_t), CFLAG_TypeMap,
	TypeMap_init, DEFAULT_initcopy, TypeMap_reftrace, TypeMap_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Func */

static METHOD Fmethod_funcRTYPE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_type_t rtype = knh_ParamArray_rtype(DP(sfp[K_MTDIDX].mtdNC)->mp);
	if(rtype != TYPE_void) {
		if(IS_Tunbox(rtype)) {
			RETURNi_(K_INT0);  // same results in Float, Boolean
		}
		else {
			RETURN_(KNH_NULVAL(CLASS_t(rtype)));
		}
	}
}

static void Func_init(CTX ctx, Object *o)
{
	knh_Func_t *fo = (knh_Func_t*)o;
	const knh_ClassTBL_t *t = O_cTBL(o);
	const knh_Method_t *mtd;
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

static void Func_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Func_t *fo = (knh_Func_t*)o;
	KNH_ADDREF(ctx, (fo->mtd));
	KNH_ADDNNREF(ctx, fo->baseNULL);
//		size_t i, stacksize = (fo)->hstacksize[-1];
//		for(i = 0; i < stacksize; i++) {
//			KNH_ADDREF(ctx, (fo)->envsfp[i].o);
//		}
	KNH_SIZEREF(ctx);
}

static void Func_free(CTX ctx, Object *o)
{
//	knh_Func_t *cc = (knh_Func_t*)o;
//	if(Func_isStoredEnv(cc)) {
//		size_t stacksize = (cc)->hstacksize[-1];
//		KNH_FREE(ctx, (cc)->envsfp, (sizeof(knh_sfp_t) * stacksize) + sizeof(size_t));
//		(cc)->envsfp = NULL;
//		Func_setStoredEnv(cc, 0);
//	}
}

static knh_ObjectSPI2_t FuncSPI = {
	"Func", 0, CFLAG_Func,
	Func_init, DEFAULT_initcopy, Func_reftrace, Func_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Thunk */

static void Thunk_init(CTX ctx, Object *o)
{
	knh_Thunk_t *thunk = (knh_Thunk_t*)o;
	thunk->envsfp = NULL;
	thunk->envsize = 0;
}

static void Thunk_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Thunk_t *thunk = (knh_Thunk_t*)o;
	if(thunk->envsize > 0) {
		size_t i;
		for(i = 0; i < (thunk)->envsize; i++) {
			KNH_ADDREF(ctx, (thunk)->envsfp[i].o);
		}
		KNH_SIZEREF(ctx);
	}
}

static void Thunk_free(CTX ctx, Object *o)
{
	knh_Thunk_t *thunk = (knh_Thunk_t*)o;
	if(thunk->envsize > 0) {
		KNH_FREE(ctx, thunk->envsfp, sizeof(knh_sfp_t) * thunk->envsize);
		thunk->envsize = 0;
		thunk->envsfp = NULL;
	}
}

static knh_ObjectSPI2_t ThunkSPI = {
	"Thunk", 0, CFLAG_Thunk,
	Thunk_init, DEFAULT_initcopy, Thunk_reftrace, Thunk_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Exception */

static void Exception_init(CTX ctx, Object *o)
{
	knh_ExceptionEX_t *b = knh_bodymalloc(ctx, Exception);
	b->eid  = 1; b->flag = 0;
	KNH_INITv(b->event, O_cTBL(o)->sname);
	KNH_INITv(b->msg, TS_EMPTY);
	KNH_INITv(b->bag, KNH_NULL);
	b->tracesNULL = NULL;
	b->uline = 0;
	b->sysloglevel = LOG_ERR;
	o->ref = b;
}

static void Exception_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ExceptionEX_t *b = DP((knh_Exception_t*)o);
	KNH_ADDREF(ctx, b->event);
	KNH_ADDREF(ctx, b->msg);
	KNH_ADDREF(ctx, b->bag);
	KNH_ADDNNREF(ctx, b->tracesNULL);
	KNH_SIZEREF(ctx);
}

static void Exception_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, Exception);
}

static knh_ObjectSPI2_t ExceptionSPI = {
	"Exception", sizeof(knh_ExceptionEX_t), CFLAG_Exception,
	Exception_init, DEFAULT_initcopy, Exception_reftrace, Exception_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* ExceptionHandler */

static void ExceptionHandler_init(CTX ctx, Object *o)
{
	knh_ExceptionHandler_t *hdr = (knh_ExceptionHandler_t*)o;
	knh_ExceptionHandlerEX_t *b = knh_bodymalloc(ctx, ExceptionHandler);
	knh_bzero(b, sizeof(knh_ExceptionHandlerEX_t));
	o->ref = b;
	KNH_INITv(hdr->stacklist, new_Array0(ctx, 0));
}

static void ExceptionHandler_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_ExceptionHandler_t *hdr = (knh_ExceptionHandler_t*)o;
	KNH_ADDREF(ctx, hdr->stacklist);
	KNH_SIZEREF(ctx);
}

static void ExceptionHandler_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, ExceptionHandler);
}

static knh_ObjectSPI2_t ExceptionHandlerSPI = {
	"ExceptionHandler", 0, CFLAG_ExceptionHandler,
	ExceptionHandler_init, DEFAULT_initcopy, ExceptionHandler_reftrace, ExceptionHandler_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Regex */

static void Regex_init(CTX ctx, Object *o)
{
	knh_Regex_t *re = (knh_Regex_t*)o;
	KNH_INITv(re->pattern, TS_EMPTY);
	re->spi = knh_getStrRegexSPI();
	re->reg = (knh_regex_t*)TS_EMPTY;
}

static void Regex_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Regex_t *re = (knh_Regex_t*)o;
	KNH_ADDREF(ctx, (re->pattern));
	KNH_SIZEREF(ctx);
}

static void Regex_free(CTX ctx, Object *o)
{
	knh_Regex_t *re = (knh_Regex_t*)o;
	if(re->reg != NULL) {
		re->spi->regfree(ctx, re->reg);
		re->spi = NULL;
		re->reg = NULL;
	}
}

static knh_ObjectSPI2_t RegexSPI = {
	"Regex", 0, CFLAG_Regex,
	Regex_init, DEFAULT_initcopy, Regex_reftrace, Regex_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_findTypeMapNULL,
};


/* --------------- */
/* StringEncoder */

static knh_bool_t conv_NOCONV(CTX ctx, knh_conv_t *c, knh_bytes_t t, knh_Bytes_t *tobuf)
{
	knh_Bytes_write(ctx, tobuf, t);  // this is necessary for default StringEncoder
	return 1;
}

static knh_ConvDSPI_t NOCONV_DSPI = {
	K_DSPI_CONVTO, "NOP",
	NULL,
	conv_NOCONV,
	conv_NOCONV,
	conv_NOCONV,
	conv_NOCONV,
	NULL/*knh_close_NOCONV*/,
	NULL/*knh_conv_NOSET*/,
};

static void Converter_init(CTX ctx, Object *o)
{
	knh_StringEncoder_t *bc = (knh_StringEncoder_t*)o;
	bc->conv = NULL;
	bc->dspi = &NOCONV_DSPI;
}

static void Converter_free(CTX ctx, Object *o)
{
	knh_StringEncoder_t *bc = (knh_StringEncoder_t*)o;
	if(bc->conv != NULL) {
		bc->dspi->close(ctx, bc->conv);
		bc->conv = NULL;
		bc->dspi = &NOCONV_DSPI;
	}
}

static knh_ObjectSPI2_t ConverterSPI = {
	"Converter", 0, CFLAG_Converter,
	Converter_init, DEFAULT_initcopy, NONE_reftrace, Converter_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t StringEncoderSPI = {
	"StringEncoder", 0, CFLAG_StringEncoder,
	Converter_init, DEFAULT_initcopy, NONE_reftrace, Converter_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t StringDecoderSPI = {
	"StringEncoder", 0, CFLAG_StringDecoder,
	Converter_init, DEFAULT_initcopy, NONE_reftrace, Converter_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t StringConverterSPI = {
	"StringConverter", 0, CFLAG_StringConverter,
	Converter_init, DEFAULT_initcopy, NONE_reftrace, Converter_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Semantics */

#ifdef K_USING_SEMANTICS

static int knh_fichk__nop(knh_Semantics_t *u, knh_int_t v)
{
	return 1;
}

static int knh_ficmp__signed(knh_Semantics_t *u, knh_int_t v1, knh_int_t v2)
{
	return (int)(v1 - v2);
}

static int knh_ffchk__default(knh_Semantics_t *u, knh_float_t v)
{
	return 1;
}

static int knh_ffcmp__default(knh_Semantics_t *u, knh_float_t v1, knh_float_t v2)
{
	knh_float_t delta = v1 - v2;
	if(delta == K_FLOAT_ZERO) return 0;
	return delta < 0 ? -1 : 1;
}

static knh_String_t *knh_fsnew__default(CTX ctx, knh_class_t cid, knh_bytes_t t, knh_String_t *orig, int *foundError)
{
	return new_String_(ctx, cid, t, orig);
}

static int knh_fscmp__default(knh_Semantics_t *u, knh_bytes_t v1, knh_bytes_t v2)
{
	return knh_bytes_strcmp(v1, v2);
}

#define FUNC(f)     f
#else
#define FUNC(f)     NULL

#endif

static void knh_Semantics_init(CTX ctx, Object *o)
{
//	knh_Semantics_t *u = (knh_Semantics_t*)o;
	knh_SemanticsEX_t *b = knh_bodymalloc(ctx, Semantics);
	// common
	b->flag = 0;
	b->ucid  = 0;
	KNH_INITv(b->urn, TS_EMPTY);
	KNH_INITv(b->tag,  TS_EMPTY);
	b->ivalue = NULL;
	b->fvalue = NULL;
	b->svalue = NULL;

	// int
	b->imax  = K_INT_MAX;
	b->imin  = K_INT_MIN;
	b->fichk = FUNC(knh_fichk__nop);
	b->ficmp = FUNC(knh_ficmp__signed);

	// float
#ifndef K_USED_TO_BE_ON_LKM
	b->fstep = 0.001;
#else
	b->fstep = 1;
#endif
	b->fmax  = K_FLOAT_MAX;
	b->fmin  = K_FLOAT_MIN;
	b->ffchk = FUNC(knh_ffchk__default);
	b->ffcmp = FUNC(knh_ffcmp__default);
//	b->ffmt = knh_funitfmt__default;
//	b->FMT  = K_FLOAT_FMT;

	// String
	b->fsnew = FUNC(knh_fsnew__default);
	b->fscmp = FUNC(knh_fscmp__default);
	//b->fsconv = NULL;
	KNH_INITv(b->bconv, KNH_NULL);
	b->charlen = 0;
	b->bytelen = 0;
	KNH_INITv(b->pattern, KNH_NULL);
//	KNH_INITv(b->vocabDictIdx, KNH_NULL);
	o->ref = b;
}

static void knh_Semantics_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Semantics_t *u = (knh_Semantics_t*)o;
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

static void knh_Semantics_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, Semantics);
}

//static void* knh_Semantics_hashkey(CTX ctx, knh_sfp_t *sfp, int opt)
//{
//	if(opt == KNH_FOBJECT_KEY) {
//		return (void*)DP((knh_Semantics_t*)sfp[0].o)->urn;
//	}
//	return DEFAULT_hashkey(ctx, sfp, opt);
//}

static knh_ObjectSPI2_t SemanticsSPI = {
	"Semantics", sizeof(knh_SemanticsEX_t), CFLAG_Semantics,
	knh_Semantics_init, DEFAULT_initcopy, knh_Semantics_reftrace, knh_Semantics_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* InputStream */

static void InputStream_init(CTX ctx, Object *o)
{
	knh_InputStream_t *in = (knh_InputStream_t*)o;
	knh_InputStreamEX_t *b = knh_bodymalloc(ctx, InputStream);
	SP(in)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	b->fd = -1;
	KNH_INITv(b->ba, KNH_NULL);
	b->buf = NULL;
	b->bufpos = 0;
	b->bufend = 0;
	b->bufsiz = 0;
	b->decNULL = NULL;
	KNH_INITv(b->urn, TS_DEVNULL);
	b->size    = 0;
	b->prev    = '\n';
	in->b = b;
	in->uline = 1;
}

static void InputStream_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_InputStream_t *in = (knh_InputStream_t*)o;
	knh_InputStreamEX_t *b = DP(in);
	KNH_ADDREF(ctx, (b->ba));
	KNH_ADDNNREF(ctx, b->decNULL);
	KNH_ADDREF(ctx, (b->urn));
	KNH_SIZEREF(ctx);
}

static void InputStream_free(CTX ctx, Object *o)
{
	knh_InputStream_t *in = (knh_InputStream_t*)o;
	knh_InputStreamEX_t *b = DP(in);
	if(b->fd != IO_NULL) {
		SP(in)->dspi->fclose(ctx, b->fd);
		b->fd = IO_NULL;
	}
	knh_bodyfree(ctx, b, InputStream);
}

static knh_ObjectSPI2_t InputStreamSPI = {
	"InputStream", sizeof(knh_InputStreamEX_t), CFLAG_InputStream,
	InputStream_init, DEFAULT_initcopy, InputStream_reftrace, InputStream_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* OutputStream */

static void OutputStream_init(CTX ctx, Object *o)
{
	knh_OutputStream_t *w = (knh_OutputStream_t*)o;
	knh_OutputStreamEX_t *b = knh_bodymalloc(ctx, OutputStream);
	SP(w)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	b->fd = IO_NULL;
	KNH_INITv(b->ba, new_Bytes(ctx, K_PAGESIZE));
	b->encNULL = NULL;
	KNH_INITv(b->urn, TS_DEVNULL);
	b->size = 0;
	KNH_INITv(b->NEWLINE, TS_EOL);
	KNH_INITv(b->TAB, TS_TAB);
	b->indent = 0;
	w->uline = 0;
	w->b = b;
}

static void OutputStream_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_OutputStream_t *w = (knh_OutputStream_t*)o;
	knh_OutputStreamEX_t *b = DP(w);
	KNH_ADDREF(ctx, (b->ba));
	KNH_ADDNNREF(ctx, (b->encNULL));
	KNH_ADDREF(ctx, (b->urn));
	KNH_ADDREF(ctx, (b->NEWLINE));
	KNH_ADDREF(ctx, (b->TAB));
	KNH_SIZEREF(ctx);
}

static void OutputStream_free(CTX ctx, Object *o)
{
	knh_OutputStream_t *w = (knh_OutputStream_t*)o;
	knh_OutputStreamEX_t *b = DP(w);
	if(b->fd != IO_NULL) {
		SP(w)->dspi->fclose(ctx, b->fd);
		b->fd = IO_NULL;
	}
	knh_bodyfree(ctx, b, OutputStream);
}

static knh_ObjectSPI2_t OutputStreamSPI = {
	"OutputStream", sizeof(knh_InputStreamEX_t), CFLAG_OutputStream,
	OutputStream_init, DEFAULT_initcopy, OutputStream_reftrace, OutputStream_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Connection */

static void Connection_init(CTX ctx, Object *o)
{
	knh_Connection_t *c = (knh_Connection_t*)o;
	c->conn = NULL;
	c->dspi = knh_getQueryDSPI(ctx, K_DEFAULT_DSPI);
	KNH_INITv(c->urn, TS_EMPTY);
}

static void Connection_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Connection_t *c = (knh_Connection_t*)o;
	KNH_ADDREF(ctx, (c->urn));
	KNH_SIZEREF(ctx);
}

static void Connection_free(CTX ctx, Object *o)
{
	knh_Connection_t *c = (knh_Connection_t*)o;
	if(c->conn != NULL) {
		c->dspi->qclose(ctx, c->conn);
	}
}

static knh_ObjectSPI2_t ConnectionSPI = {
	"Connection", 0, CFLAG_Connection,
	Connection_init, DEFAULT_initcopy, Connection_reftrace, Connection_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* ResultSet */

static void ResultSet_init(CTX ctx, Object *o)
{
	knh_ResultSetEX_t *b = knh_bodymalloc(ctx, ResultSet);
	b->qcur = NULL;
	b->tcid = CLASS_ResultSet;
	b->column_size = 0;
	b->column = NULL;
	KNH_INITv(b->databuf, new_Bytes(ctx, 256));
	KNH_INITv(b->conn, KNH_NULL);
	b->qcurfree = knh_getQueryDSPI(ctx, K_DEFAULT_DSPI)->qcurfree;
	b->count = 0;
	o->ref = b;
}

static void ResultSet_reftrace(CTX ctx, Object *o FTRARG)
{
	size_t i = 0;
	knh_ResultSetEX_t *b = DP((knh_ResultSet_t*)o);
	KNH_ADDREF(ctx, (b->databuf));
	for(i = 0; i < b->column_size; i++) {
		KNH_ADDREF(ctx, (b->column[i].name));
	}
	KNH_ADDREF(ctx, (b->conn));
	KNH_SIZEREF(ctx);
}

static void ResultSet_free(CTX ctx, Object *o)
{
	knh_ResultSetEX_t *b = DP((knh_ResultSet_t*)o);
	if(b->column != NULL) {
		KNH_FREE(ctx, b->column, sizeof(knh_dbschema_t) * b->column_size);
		b->column = NULL;
	}
	if(b->qcur != NULL) {
		b->qcurfree(b->qcur);
		b->qcur = NULL;
	}
	knh_bodyfree(ctx, b, ResultSet);
}

static knh_ObjectSPI2_t ResultSetSPI = {
	"ResultSet", sizeof(knh_ResultSetEX_t), CFLAG_ResultSet,
	ResultSet_init, DEFAULT_initcopy, ResultSet_reftrace, ResultSet_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Script */

static void Script_init(CTX ctx, Object *o)
{
	knh_Script_t *scr = (knh_Script_t*)o;
	knh_class_t cid = new_ClassId(ctx);
	knh_ClassTBL_t *t = varClassTBL(cid);
	scr->h.cTBL = (const knh_ClassTBL_t*)t;
	DBG_ASSERT(t->cspi2 == NULL);
	t->cflag  = CFLAG_Script;
	t->magicflag = KNH_MAGICFLAG(t->cflag);
	t->bcid   = CLASS_Script;
	t->baseTBL = ClassTBL(CLASS_Script);
	t->supcid = CLASS_Script;
	t->supTBL = ClassTBL(CLASS_Script);
	knh_ClassTBL_setCSPI2(t, ClassTBL(CLASS_Script)->cspi2);
	KNH_INITv(t->methods, KNH_EMPTYLIST);
	KNH_INITv(t->tmaps, KNH_EMPTYLIST);
	knh_setClassName(ctx, cid, ClassTBL(CLASS_Script)->sname, ClassTBL(CLASS_Script)->sname);
	DBG_ASSERT(t->defnull == NULL);
	scr->fields = NULL;
	knh_setClassDefaultValue(ctx, cid, scr, NULL);
}

static knh_ObjectSPI2_t ScriptSPI = {
	"Script", 0, CFLAG_Script,
	Script_init, DEFAULT_initcopy, ObjectField_reftrace, ObjectField_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* NameSpace */

static void NameSpace_init(CTX ctx, Object *o)
{
	knh_NameSpaceEX_t *b = knh_bodymalloc(ctx, NameSpace);
	KNH_INITv(b->nsname, TS_main);
	b->parentNULL = NULL;
	b->aliasDictMapNULL = NULL;
	b->name2cidDictSetNULL = NULL;
	b->lconstDictCaseMapNULL = NULL;
	b->func2cidDictSetNULL = NULL;
	b->formattersNULL = NULL;
	b->methodsNULL = NULL;
	b->strregexSPI = knh_getStrRegexSPI();
	b->regexSPI = knh_getRegexSPI();
	o->ref = b;
}

static void NameSpace_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_NameSpaceEX_t *b = DP((knh_NameSpace_t*)o);
	KNH_ADDREF(ctx, (b->nsname));
	KNH_ADDNNREF(ctx, (b->parentNULL));
	KNH_ADDNNREF(ctx, (b->aliasDictMapNULL));
	KNH_ADDNNREF(ctx, (b->name2cidDictSetNULL));
	KNH_ADDNNREF(ctx, (b->func2cidDictSetNULL));
	KNH_ADDNNREF(ctx, (b->lconstDictCaseMapNULL));
	KNH_ADDNNREF(ctx, (b->formattersNULL));
	KNH_ADDNNREF(ctx, (b->methodsNULL));
	KNH_SIZEREF(ctx);
}

static void NameSpace_free(CTX ctx, Object *o)
{
	knh_bodyfree(ctx, o->ref, NameSpace);
}

static knh_ObjectSPI2_t NameSpaceSPI = {
	"NameSpace", sizeof(knh_NameSpaceEX_t), CFLAG_NameSpace,
	NameSpace_init, DEFAULT_initcopy, NameSpace_reftrace, NameSpace_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Package */

static void Package_init(CTX ctx, Object *o)
{
	knh_Package_t *pkg = (knh_Package_t*)o;
	pkg->ns = NULL;
	pkg->script = NULL;
	pkg->hdlr = NULL;
}

static void Package_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Package_t *pkg = (knh_Package_t*)o;
	KNH_ADDNNREF(ctx, pkg->ns);
	KNH_ADDNNREF(ctx, pkg->script);
	KNH_SIZEREF(ctx);
}

static knh_ObjectSPI2_t PackageSPI = {
	"Package", 0, CFLAG_Package,
	Package_init, DEFAULT_initcopy, Package_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* System */

static knh_uintptr_t knh_autoSystemId = 0;

#ifdef K_USING_NOFILE
#define stdin  NULL
#define stdout NULL
#define stderr NULL
#endif

static void System_init(CTX ctx, Object *o)
{
	knh_SystemEX_t *sys = knh_bodymalloc(ctx, System);
	sys->sysid = knh_autoSystemId++;
	sys->ctxcount = 0;

	KNH_INITv(sys->ClassNameDictSet, new_DictSet0(ctx, 128, 0/*isCaseMap*/, "System.ClassNameDictSet"));
	KNH_INITv(sys->EventDictCaseSet, new_DictSet0(ctx, 32, 1/*isCaseMap*/, "System.EventDictSet"));
	KNH_INITv(sys->enc,   new_T(knh_getSystemEncoding()));
	KNH_INITv(sys->in,    new_InputStream__stdio(ctx, stdin, sys->enc));
	KNH_INITv(sys->out,   new_OutputStream__stdio(ctx, stdout, sys->enc));
	KNH_INITv(sys->err,   new_OutputStream__stdio(ctx, stderr, sys->enc));

	KNH_INITv(sys->props, new_DictMap0(ctx, 20, 1/*isCaseMap*/, "System.props"));
	KNH_INITv(sys->nameDictCaseSet, new_DictSet0(ctx, K_TFIELD_SIZE + 10, 1/*isCaseMap*/, "System.nameDictSet"));
	sys->namecapacity = k_goodsize2(K_TFIELD_SIZE + 10, sizeof(knh_nameinfo_t));
	sys->nameinfo = (knh_nameinfo_t*)KNH_REALLOC(ctx, NULL, 0, sys->namecapacity, sizeof(knh_nameinfo_t));
	KNH_INITv(sys->urnDictSet, new_DictSet0(ctx, 0, 0/*isCaseMap*/, "System.urnDictSet"));
	KNH_INITv(sys->urns, new_Array0(ctx, 1));
	KNH_INITv(sys->tokenDictSet, new_DictSet0(ctx, (TT_MAX - STT_MAX), 0/*isCaseMap*/, "System.tokenDictSet"));
	KNH_INITv(sys->dspiDictSet, new_DictSet0(ctx, 32, 0/*isCaseMap*/, "System.dspiDictSet"));
	KNH_INITv(sys->PackageDictMap, new_DictMap0(ctx, 0, 0/*isCaseMap*/, "System.PackageDictMap"));
	KNH_INITv(sys->URNAliasDictMap, new_DictMap0(ctx, 0, 0/*isCaseMap*/, "System.URNAliasDictMap"));
	o->ref = sys;
}

static void System_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_SystemEX_t *sys = DP((knh_System_t*)o);
	size_t i, size = knh_DictSet_size(sys->nameDictCaseSet);
	KNH_ADDREF(ctx, (sys->enc));
	KNH_ADDREF(ctx, (sys->in));
	KNH_ADDREF(ctx, (sys->out));
	KNH_ADDREF(ctx, (sys->err));
	KNH_ADDREF(ctx, (sys->props));
	KNH_ADDREF(ctx, (sys->EventDictCaseSet));
	KNH_ADDREF(ctx, (sys->ClassNameDictSet));
	KNH_ADDREF(ctx, (sys->nameDictCaseSet));
	KNH_ADDREF(ctx, (sys->urnDictSet));
	KNH_ADDREF(ctx, (sys->urns));
	KNH_ADDREF(ctx, (sys->tokenDictSet));
	KNH_ADDREF(ctx, (sys->PackageDictMap));
	KNH_ADDREF(ctx, (sys->URNAliasDictMap));
	KNH_ADDREF(ctx, (sys->dspiDictSet));
	KNH_ENSUREREF(ctx, size);
	for(i = 0; i < size; i++) {
		KNH_ADDREF(ctx, sys->nameinfo[i].name);
	}
	KNH_SIZEREF(ctx);
}

static void System_free(CTX ctx, Object *o)
{
	knh_SystemEX_t *sys = DP((knh_System_t*)o);
	KNH_FREE(ctx, sys->nameinfo, sizeof(knh_nameinfo_t) * sys->namecapacity);
	sys->nameinfo = NULL;
	knh_bodyfree(ctx, sys, System);
}

static knh_ObjectSPI2_t SystemSPI = {
	"System", sizeof(knh_SystemEX_t), CFLAG_System,
	System_init, DEFAULT_initcopy, System_reftrace, System_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Context */

static void Context_init(CTX ctx, Object *o)
{
	THROW_Halt(ctx, NULL, "Context can be only instatiated in new_Context()");
}

static knh_ObjectSPI2_t ContextSPI = {
	"Context", 0, CFLAG_Context,
	Context_init, DEFAULT_initcopy, NONE_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Goal */

static void Goal_init(CTX ctx, Object *o)
{
	static knh_uintptr_t docuid = 0;
	knh_Goal_t *g = (knh_Goal_t*)o;
	KNH_INITv(g->type, TS_EMPTY);
	KNH_INITv(g->msg, TS_EMPTY);
	g->id = docuid++;
}

static void Goal_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Goal_t *g = (knh_Goal_t*)o;
	KNH_ADDREF(ctx, g->type);
	KNH_ADDREF(ctx, g->msg);
	KNH_SIZEREF(ctx);
}

static void Goal_checkin(CTX ctx, Object *o)
{
	knh_Goal_t *g = (knh_Goal_t*)o;
	KNH_SYSLOG(ctx, LOG_NOTICE, "CHECKIN", "G%d %s", g->id, S_tochar(g->msg));
}

static void Goal_checkout(CTX ctx, Object *o, int isFailed)
{
	knh_Goal_t *g = (knh_Goal_t*)o;
	if(isFailed) {
		KNH_SYSLOG(ctx, LOG_WARNING, "FAILED", "G%d %s", g->id, S_tochar(g->msg));
	}
	else {
		KNH_SYSLOG(ctx, LOG_NOTICE, "CHECKOUT", "G%d %s", g->id, S_tochar(g->msg));
	}
}

static knh_ObjectSPI2_t GoalSPI = {
	"Goal", 0, CFLAG_Goal,
	Goal_init, DEFAULT_initcopy, Goal_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	Goal_checkin, Goal_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* UnitTest */

static void UnitTest_init(CTX ctx, Object *o)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)o;
	KNH_INITv(ut->msg, TS_EMPTY);
}

static void UnitTest_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)o;
	KNH_ADDREF(ctx, ut->msg);
	KNH_SIZEREF(ctx);
}

static void UnitTest_checkin(CTX ctx, Object *o)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)o;
	ut->stime = knh_getTimeMilliSecond();
}

static void UnitTest_checkout(CTX ctx, Object *o, int isFailed)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)o;
	size_t t = knh_getTimeMilliSecond() - ut->stime;
	if(isFailed) {
		KNH_SYSLOG(ctx, LOG_WARNING, "FAILED", "%s (%dms)", S_tochar(ut->msg), t);
	}
	else {
		KNH_SYSLOG(ctx, LOG_NOTICE, "PASSED", "%s (%dms)", S_tochar(ut->msg), t);
	}
}

static knh_ObjectSPI2_t UnitTestSPI = {
	"UnitTest", 0, CFLAG_UnitTest,
	UnitTest_init, DEFAULT_initcopy, UnitTest_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	UnitTest_checkin, UnitTest_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Token */

static void Token_init(CTX ctx, Object *o)
{
	knh_Token_t *tk = (knh_Token_t*)o;
	tk->tt        =  TT_ASIS;
	tk->type      =  TYPE_var;
	tk->uline     =   0;
	tk->flag0 = 0;
	tk->index = 0;
	KNH_INITv(tk->data, KNH_NULL);
}

static void Token_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Token_t *tk = (knh_Token_t*)o;
	KNH_ADDREF(ctx, tk->data);
	KNH_SIZEREF(ctx);
}

static knh_ObjectSPI2_t TermSPI = {
	"Term", 0, 0,
	ABSTRACT_init, DEFAULT_initcopy, NONE_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

static knh_ObjectSPI2_t TokenSPI = {
	"Token", 0, CFLAG_Token,
	Token_init, DEFAULT_initcopy, Token_reftrace, DEFAULT_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* Stmt */

static void Stmt_init(CTX ctx, Object *o)
{
	knh_Stmt_t *stmt = (knh_Stmt_t*)o;
	knh_StmtEX_t *b = knh_bodymalloc(ctx, Stmt);
	SP(stmt)->uline = 0;
	SP(stmt)->stt   = STT_DONE;
	SP(stmt)->type = TYPE_var;
	(stmt)->terms = NULL;
	b->flag0 = 0;
	b->espidx = 0;
	b->size = 0;
	b->capacity = 0;
	b->nextNULL = NULL;
	KNH_INITv(b->metaDictCaseMap,  KNH_NULL);
	o->ref = b;
}

static void Stmt_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Stmt_t *stmt = (knh_Stmt_t*)o;
	knh_StmtEX_t *b = DP((knh_Stmt_t*)o);
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

static void Stmt_free(CTX ctx, Object *o)
{
	knh_Stmt_t *stmt = (knh_Stmt_t*)o;
	knh_StmtEX_t *b = DP((knh_Stmt_t*)o);
	if(stmt->terms != NULL) {
		KNH_FREE(ctx, stmt->terms, sizeof(knh_Term_t*) * b->capacity);
	}
	knh_bodyfree(ctx, b, Stmt);
}

static knh_ObjectSPI2_t StmtSPI = {
	"Stmt", sizeof(knh_StmtEX_t), CFLAG_Stmt,
	Stmt_init, DEFAULT_initcopy,
	Stmt_reftrace, Stmt_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* Gamma */

static void Gamma_init(CTX ctx, Object *o)
{
	knh_GammaEX_t *b = knh_bodymalloc(ctx, Gamma);
	knh_bzero(b, sizeof(knh_GammaEX_t));
	b->cflag = FLAG_Gamma_InlineFunction | FLAG_Gamma_TailRecursion;
	KNH_INITv(b->ns, ctx->share->mainns);
	DBG_ASSERT(IS_NameSpace(b->ns));
	KNH_INITv(b->mtd, KNH_NULL);
	KNH_INITv(b->stmt, KNH_NULL);
	KNH_INITv(b->lstacks, new_Array0(ctx, 0));
	KNH_INITv(b->insts, new_Array0(ctx, 0));
	KNH_INITv(b->errmsgs, new_Array0(ctx, 0));
	KNH_INITv(b->finallyStmt, KNH_NULL);
	o->ref = b;
}

static void Gamma_reftrace(CTX ctx, Object *o FTRARG)
{
	size_t i;
	knh_GammaEX_t *b = DP((knh_Gamma_t*)o);
	KNH_ENSUREREF(ctx, b->gcapacity * 2);
	for(i = 0; i < b->gcapacity; i++) {
		//DBG_P("FTR %p gf[%d].value=%s(%p)", b->gf, i, O__(b->gf[i].value), b->gf[i].value);
		KNH_ADDREF(ctx, b->gf[i].value);
		KNH_ADDREF(ctx, b->gf[i].tkIDX);
	}
	KNH_ADDREF(ctx, (b->ns));
	KNH_ADDREF(ctx, (b->script));
	KNH_ADDREF(ctx, (b->mtd));
	KNH_ADDREF(ctx, (b->stmt));
	KNH_ADDREF(ctx, (b->lstacks));
	KNH_ADDREF(ctx, (b->insts));
	KNH_ADDREF(ctx, (b->errmsgs));
	KNH_ADDREF(ctx, (b->finallyStmt));
	KNH_ADDNNREF(ctx, b->symbolDictMap);
	KNH_ADDNNREF(ctx, b->constPools);
	KNH_SIZEREF(ctx);
}

static void Gamma_free(CTX ctx, Object *o)
{
	knh_GammaEX_t *b = DP((knh_Gamma_t*)o);
	if(b->gcapacity) {
		KNH_FREE(ctx, b->gf, b->gcapacity * sizeof(knh_gmafields_t));
	}
	knh_bodyfree(ctx, b, Gamma);
}

static knh_ObjectSPI2_t GammaSPI = {
	"Gamma", sizeof(knh_GammaEX_t), CFLAG_Gamma,
	Gamma_init, DEFAULT_initcopy, Gamma_reftrace, Gamma_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* BasicBlock */

static void BasicBlock_init(CTX ctx, Object *o)
{
	knh_BasicBlock_t *bb = (knh_BasicBlock_t*)o;
	bb->b = knh_bodymalloc(ctx, BasicBlock);
	knh_bzero(bb->b, sizeof(knh_BasicBlockEX_t));
	bb->listNC  = NULL;
	bb->nextNC  = NULL;
	bb->jumpNC  = NULL;
}

static void BasicBlock_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_BasicBlock_t *bb = (knh_BasicBlock_t*)o;
	size_t i;
	KNH_ENSUREREF(ctx, DP(bb)->size);
	for(i = 0; i < DP(bb)->size; i++) {
#ifdef K_USING_CSTACK_TRAVERSE_
		knh_opline_reftrace(ctx, DP(bb)->opbuf + i FTRDATA);
#else
		tail_ = knh_opline_reftrace(ctx, DP(bb)->opbuf + i FTRDATA);
#endif
	}
	KNH_SIZEREF(ctx);
}

static void BasicBlock_free(CTX ctx, Object *o)
{
	knh_BasicBlock_t *bb = (knh_BasicBlock_t*)o;
	if(DP(bb)->capacity > 0) {
		KNH_FREE(ctx, DP(bb)->opbuf, DP(bb)->capacity * sizeof(knh_opline_t));
	}
	knh_bodyfree(ctx, DP(bb), BasicBlock);
}

static knh_ObjectSPI2_t BasicBlockSPI = {
	"BasicBlock", 0, CFLAG_BasicBlock,
	BasicBlock_init, DEFAULT_initcopy, BasicBlock_reftrace, BasicBlock_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* KonohaCode */

static void KonohaCode_init(CTX ctx, Object *o)
{
	knh_KonohaCode_t *b = (knh_KonohaCode_t*)o;
	b->codesize = 0;
	b->code = NULL;
	b->uri = 0;
	KNH_INITv(b->source, TS_EMPTY);
}

static void KonohaCode_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_KonohaCode_t *b = (knh_KonohaCode_t*)o;
	knh_opline_t *pc = b->code;
	KNH_ADDREF(ctx, b->source);
	KNH_ENSUREREF(ctx, b->codesize / sizeof(knh_opline_t));
	while(pc->opcode != OPCODE_RET) {
#ifdef K_USING_CSTACK_TRAVERSE_
		knh_opline_reftrace(ctx, pc FTRDATA);
#else
		tail_ = knh_opline_reftrace(ctx, pc FTRDATA);
#endif
		pc++;
	}
	KNH_SIZEREF(ctx);
}

static void KonohaCode_free(CTX ctx, Object *o)
{
	knh_KonohaCode_t *b = (knh_KonohaCode_t*)o;
#ifdef K_USING_VMCOUNT
	knh_opline_t *pc = b->code;
	while(pc->opcode != OPCODE_RET) {
		knh_opcode_count(ctx, pc);
		pc++;
	}
#endif
	KNH_FREE(ctx, b->code, b->codesize);
}

static knh_ObjectSPI2_t KonohaCodeSPI = {
	"KonohaCode", 0, CFLAG_KonohaCode,
	KonohaCode_init, DEFAULT_initcopy, KonohaCode_reftrace, KonohaCode_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* dynamic */

static void DYNAMIC_init(CTX ctx, Object *o)
{
//	knh_RawPtr_t *g = (knh_RawPtr_t *)o;
//	ctx->api->RawPtr_init(ctx, g, NULL, NULL);
}

static void DYNAMIC_free(CTX ctx, Object *o)
{
//	knh_RawPtr_t *g = (knh_RawPtr_t *)o;
//	if((Object*)g == KNH_NULL) {
//		DBG_P("freeing null");
//	}
//	else {
//		g->pfree(ctx, g);
//	}
}

static knh_ObjectSPI2_t TdynamicSPI = {
	"dynamic", 0, CFLAG_Tdynamic,
	DYNAMIC_init, DEFAULT_initcopy, NONE_reftrace, DYNAMIC_free,
	DEFAULT_compareTo, DEFAULT_getkey, DEFAULT_hashCode,
	DEFAULT_checkin, DEFAULT_checkout,
	DEFAULT_findTypeMapNULL,
};

/* --------------- */
/* @data*/

typedef struct {
	const char   *name;
	int           index;
} knh_StringData0_t ;

typedef struct {
	const char *name;
	knh_fieldn_t fn;
} knh_FieldNameData0_t ;

/* --------------- */

#ifdef __cplusplus
}
#endif

#define K_USING_DEFAULTAPI

#include"apidata/newapi.c"
#include"apidata/objectapi.c"
#include"apidata/numberapi.c"
#include"apidata/stringapi.c"
#include"apidata/arrayapi.c"
#include"apidata/dictapi.c"

#include"apidata/systemapi.c"
#include"apidata/streamapi.c"
#include"apidata/dbapi.c"
#include"apidata/oprapi.c"
#include"apidata/mprapi.c"
#include"apidata/itrapi.c"
#include"apidata/fmtapi.c"
#include"apidata/compilerapi.c"
#include"apidata/narutoapi.c"

#include"apidata/structdata.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static Object *knh_Context_fdefault(CTX ctx, knh_class_t cid)
{
	return (Object*)ctx;
}
static Object *knh_NameSpace_fdefault(CTX ctx, knh_class_t cid)
{
	return UPCAST(ctx->share->mainns);
}
static void knh_setDefaultValues(CTX ctx)
{
	knh_setClassDefaultValue(ctx, CLASS_Object, KNH_NULL, NULL);
	knh_setClassDefaultValue(ctx, CLASS_Tdynamic, KNH_NULL, NULL);
	knh_setClassDefaultValue(ctx, CLASS_Boolean, KNH_FALSE, NULL);
#if defined(K_USING_SEMANTICS)
	{
		knh_Semantics_t *u = new_(Semantics);
		KNH_INITv(DP(u)->ivalue, KNH_INT0);
		KNH_INITv(DP(u)->fvalue, KNH_FLOAT0);
		KNH_INITv(DP(u)->svalue, TS_EMPTY);
		knh_setClassDefaultValue(ctx, CLASS_Semantics, u, NULL);
	}
#endif
	// load file/Channel/regex/db drivers
	knh_loadScriptDriver(ctx);
	knh_setClassDefaultValue(ctx, CLASS_Context, KNH_NULL, knh_Context_fdefault);
	knh_setClassDefaultValue(ctx, CLASS_NameSpace, KNH_NULL, knh_NameSpace_fdefault);
	knh_setClassDefaultValue(ctx, CLASS_System, UPCAST(ctx->sys), NULL);
	{
		knh_Token_t *tk = KNH_TNULL(Token);
		tk->tt = TT_FUNCVAR;
		(tk)->index = 0;
	}
}

static void knh_loadScriptFieldNameData0(CTX ctx, knh_FieldNameData0_t *data)
{
	while(data->name != NULL) {
		knh_String_t *name = new_T(data->name);
#if defined(K_USING_DEBUG)
		knh_fieldn_t fn = knh_addname(ctx, name, knh_DictSet_append);
		DBG_ASSERT(fn == data->fn - MN_OPSIZE);
#else
		knh_addname(ctx, name, knh_DictSet_append);
#endif
		data++;
	}
}

/* ------------------------------------------------------------------------ */
/* @data */

static knh_IntData_t IntConstData0[] = {
	{"Int.MAX", K_INT_MAX},
	{"Int.MIN", K_INT_MIN},
	{NULL, 0}
};

static knh_FloatData_t FloatConstData0[] = {
	{"Float.MAX", K_FLOAT_MAX},
	{"Float.MIN", K_FLOAT_MIN},
	{NULL, K_FLOAT_ZERO}
};

static knh_StringData_t StringConstData0[] = {
	{"$konoha.version", K_VERSION},
//	{"$konoha.os", KONOHA_OS},
//	{"$konoha.platform", CC_PLATFORM},
	{NULL, NULL},
};

static knh_data_t CParamData0[] = {
	DATA_CPARAM, CLASS_Iterator, 1, 0, TYPE_dynamic, FN_V,
	DATA_CPARAM, CLASS_Range, 1, 0, TYPE_dynamic, FN_V,
	DATA_CPARAM, CLASS_Array, 1, 0, TYPE_dynamic, FN_V,
	DATA_CPARAM, CLASS_Map, 2, 0, TYPE_String, FN_K, TYPE_dynamic, FN_V,
	DATA_CPARAM, CLASS_Func, 0, 0,
	0,
};

void knh_loadScriptSystemStructData(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
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
		DBG_ASSERT(i < (SIZEOF_TSTRING / sizeof(knh_String_t*)));
		KNH_INITv(ctx->share->tString[i], new_T(*data));
		data++;
	}
}

void knh_loadScriptSystemData(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadData(ctx, ClassData0, NULL);
	kapi->loadData(ctx, CParamData0, NULL);
	kapi->loadIntData(ctx, IntConstData0);
	kapi->loadFloatData(ctx, FloatConstData0);
	kapi->loadStringData(ctx, StringConstData0);
	knh_getURI(ctx, STEXT("(eval)"));  // URI_EVAL
	knh_setDefaultValues(ctx);
	knh_loadScriptDefaultMapDSPI(ctx);
}

void knh_loadScriptSystemMethod(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	knh_ParamArray_t *pools[K_PARAM0_SIZE];
	knh_loadScriptFieldNameData0(ctx, FieldNameData0);
	kapi->loadData(ctx, ParamArrayData0, pools);
	kapi->loadData(ctx, APIData0, pools);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
