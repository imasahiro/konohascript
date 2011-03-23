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

#ifdef K_INCLUDE_BUILTINAPI

/* ------------------------------------------------------------------------ */
/* [new] */

//## @Virtual method This Object.new();

static METHOD Object_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */

//static void ObjectField_setValue(CTX ctx, knh_ObjectField_t *of, knh_index_t idx, knh_type_t type, Object *value)
//{
//	knh_class_t tcid = CLASS_t(type);
//	knh_class_t scid = O_cid(value);
//	DBG_ASSERT_cid(tcid);
//	DBG_ASSERT_cid(scid);
//	if(scid == tcid || knh_class_instanceof(ctx, scid, tcid)) {
//		goto L_SETVAL;
//	}
//	DBG_P("COERCION %s -> %s", CLASS__(scid), CLASS__(tcid));
//	TODO();
////		BEGIN_LOCAL(ctx, lsfp);
////		KNH_LPUSH(ctx, o);
////		VM_MAP(ctx, tcid);
////		o = ctx->esp[0].o;
////		END_LOCAL(ctx, lsfp);
//	return ;
//
//	L_SETVAL:;
//	if(IS_Tint(type)) {
//		knh_int_t *data = (knh_int_t*)(of->fields + idx);
//		data[0] = N_toint(value);
//	}
//	else if(IS_Tfloat(type)) {
//		knh_float_t *data = (knh_float_t*)(of->fields + idx);
//		data[0] = N_tofloat(value);
//	}
//	else if(IS_Tbool(type)) {
//		knh_boolean_t *data = (knh_boolean_t*)(of->fields +idx);
//		data[0] = N_tobool(value);
//	}
//	else {
//		DBG_ASSERT(of->fields[idx] != NULL);
//		KNH_SETv(ctx, of->fields[idx], value);
//	}
//}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Object.new:MAP(dynamic value, ...);

static METHOD Object_newMAP(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_ObjectField_t *of = (knh_ObjectField_t*)sfp[0].o;
//	knh_class_t cid = O_cid(of);
//	knh_sfp_t *v = sfp + 1;
//	size_t i, ac = knh_stack_argc(ctx, v);
//	for(i = 0; i < ac; i+= 2) {
//		if(IS_bString(v[i].s)) {
//			knh_fieldn_t fn = knh_getfnq(ctx, S_tobytes(v[i].s), FN_NONAME);
//			if(fn == FN_NONAME) continue;
//			knh_index_t idx = knh_Class_queryField(ctx, cid, fn);
//			if(idx == -1) continue;
//			knh_fields_t *cf = knh_Class_fieldAt(ctx, cid, idx);
//			knh_type_t type = knh_type_tocid(ctx, cf->type, cid);
//			if(type == TYPE_void) continue;
//			DBG_P("[%d] %s %s", (int)(idx), TYPE__(type), S_tochar(v[i].s));
//			ObjectField_setValue(ctx, of, idx, type, v[i+1].o);
//		}
//	}
//	RETURN_(of);
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.new(Int init);

static METHOD Bytes_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	size_t init = sfp[1].ivalue <= 0 ? 0 : k_goodsize(Int_to(size_t, sfp[1]));
	DBG_ASSERT(ba->dim->capacity == 0);
	ba->bu.ubuf = (knh_uchar_t*)KNH_MALLOC(ctx, init);
	knh_bzero(ba->bu.ubuf, init);
	ba->dim = new_dim(ctx, init, 1);
	ba->bu.len = 0;
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## method Bytes Bytes.new:ARRAY(Int init);

static METHOD Bytes_newARRAY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t size = sfp[1].ivalue <= 0 ? 0 : Int_to(size_t, sfp[1]);
	Bytes_new(ctx, sfp, rix);
	sfp[rix].ba->bu.len = size;
}

/* ------------------------------------------------------------------------ */
//## method String String.new(Bytes buf, StringDecoder c);

static METHOD String_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s;
	if(IS_NULL(sfp[2].o)) {
		s = new_S(ctx, BA_tobytes(sfp[1].ba));
	}
	else {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_StringDecoder_t *c = (knh_StringDecoder_t*)sfp[2].o;
		c->dspi->dec(ctx, c->conv, BA_tobytes(sfp[1].ba), cwb->ba);
		s = knh_cwb_newString(ctx, cwb);
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method Regex Regex.new(String pattern, String option, NameSpace ns);

static METHOD Regex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = (knh_Regex_t*)sfp[0].o;
	const char *ptn = S_tochar(sfp[1].s);
	const char *opt = IS_NULL(sfp[2].o) ? "" : S_tochar(sfp[2].s);
	KNH_SETv(ctx, re->pattern, sfp[1].s);
	knh_NameSpace_t *ns = IS_NULL(sfp[3].ns)?knh_getGammaNameSpace(ctx):sfp[3].ns;
	re->spi = DP(ns)->regexSPI;
	re->reg = re->spi->regmalloc(ctx, sfp[1].s);
	re->spi->regcomp(ctx, re->reg, ptn, re->spi->parse_cflags(ctx, opt));
	re->eflags = re->spi->parse_eflags(ctx, opt);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
//## @Const mapper String Regex!;

static METHOD String_Regex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = new_(Regex);
	const char *ptn = S_tochar(sfp[0].s);
	KNH_SETv(ctx, re->pattern, sfp[0].s);
	re->reg = re->spi->regmalloc(ctx, sfp[0].s);
	re->spi->regcomp(ctx, re->reg, ptn, 0);
	re->eflags = 0;
	RETURN_(re);
}

/* ------------------------------------------------------------------------ */
/* [Pair, Tuple, Range] */

//## @Hidden @Const method This Tuple.new:TUPLE(dynamic value, ...);

static METHOD Tuple_newTUPLE(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Tuple_t *tpl = (knh_Tuple_t*)sfp[0].o;
	knh_sfp_t *v = sfp + 1;
	size_t i, ti = 0, ac = knh_stack_argc(ctx, v);
	knh_fields_t *tf = O_cTBL(tpl)->fields;
	for(i = 0; i < ac; i++) {
		if(tf[ti].israw == 1) {
			knh_ndata_t *n = (knh_ndata_t*)(tpl->fields + ti);
			n[0] = v[i].ndata;
			ti++;
			DBLNDATA_(ti++);
		}
		else {
			KNH_SETv(ctx, tpl->fields[ti], v[i].o);
			ti++;
		}
	}
	RETURN_(tpl);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Const method This Range.new:LIST(T1 start, T1 end);

static METHOD Range_newLIST(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Range_t *rng = (knh_Range_t*)sfp[0].o;
	if(Range_isNDATA(rng)) {
		rng->nstart = sfp[1].ndata;
		rng->nend =   sfp[2].ndata;
	}
	else {
		KNH_SETv(ctx, rng->ostart, sfp[1].o);
		KNH_SETv(ctx, rng->oend, sfp[2].o);
	}
	RETURN_(rng);
}

/* ------------------------------------------------------------------------ */
/* [Array] */

//## method This Array.new(Int initCapacity);

static METHOD Array_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_grow(ctx, sfp[0].a, Int_to(size_t, sfp[1]), 0);
	DBG_ASSERT((sfp[0].a)->size == 0);
	RETURN_(sfp[0].a);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Array.new:ARRAY(Int size, ...);

static METHOD Array_newARRAY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t init, x = 0, y = 1, z = 1, w = 1;
	size_t dim = knh_stack_argc(ctx, sfp+1);
	switch(dim) {
		case 4: w = sfp[4].ivalue;
		case 3: z = sfp[3].ivalue;
		case 2: y = sfp[2].ivalue;
		case 1: x = sfp[1].ivalue;
	}
	init = x * y * z * w;
	if(0 <= init && init < LONG_MAX) {
		knh_Array_grow(ctx, a, (size_t)init, 0);
		a->size = (size_t)init;
		if(!Array_isNDATA(a)) {
			knh_class_t p1 = O_p1(a);
			Object *v = knh_getClassDefaultValue(ctx, p1);
			size_t i;
			for(i = 0; i < a->size; i++) {
				KNH_INITv(a->list[i], v);
			}
		}
	}
	else if(unlikely(init < 0)) {
		THROW_OutOfRange(ctx, sfp, init, 0);
	}
	if(init > 0 && dim > 1) {
		((knh_dim_t*)a->dim)->dim = dim;
		((knh_dim_t*)a->dim)->x = (size_t)x;
		((knh_dim_t*)a->dim)->xy = (size_t)(x * y);
		((knh_dim_t*)a->dim)->xyz = (size_t)(x * y * z);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Array.new:LIST(T1 value, ...);

static METHOD Array_newLIST(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	a->api->add(ctx, a, sfp+1);
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## method This Map.new(Int init, String path);

static METHOD Map_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *m = (knh_Map_t *)sfp[0].o;
	size_t init = sfp[1].ivalue <= 0 ? 0: Int_to(size_t, sfp[1]);
	knh_bytes_t path = S_tobytes(sfp[2].s);
	knh_class_t cid = O_cid(m);
	knh_MapDSPI_t *dspi = knh_getMapDSPI(ctx, path);
	m->dspi = dspi->config(ctx, knh_class_p1(cid), knh_class_p2(cid));
	m->map = m->dspi->init(ctx, init, path.text, NULL);
	RETURN_(m);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method This Map.new:MAP(T1 value, ...);

static METHOD Map_newMAP(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *o = (knh_Map_t*)sfp[0].o;
	knh_class_t cid = O_cid(o);
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	knh_class_t p1 = knh_class_p1(cid);
	knh_class_t p2 = knh_class_p2(cid);
	knh_MapDSPI_t *dspi = knh_getMapDSPIfromCID(ctx, p1, p2);
	o->dspi = dspi->config(ctx, p1, p2);
	o->map  = dspi->init(ctx, 0, dspi->name, NULL);
	for(i = 0; i < ac; i+=2) {
		if(IS_bString(v[i].s)) {
			//knh_stack_boxing(ctx, v + i + 1);
			o->dspi->set(ctx, o->map, v+i);
		}
	}
	RETURN_(o);
}

/* ------------------------------------------------------------------------ */
//## method Exception! Exception.new(String event, String msg, dynamic bag);

static METHOD Exception_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Exception_setup(ctx, sfp[0].e, sfp[1].s, sfp[2].s, sfp[3].o);
	RETURN_(sfp[0].e);
}

/* ------------------------------------------------------------------------ */
//## method This Func.new(dynamic base, Method method);

static METHOD Func_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t   *fo = sfp[0].fo;
	knh_Method_t *mtd = sfp[2].mtd;
	KNH_SETv(ctx, (fo)->mtd, sfp[2].mtd);
	if(!Method_isStatic(mtd)) {
		KNH_INITv((fo)->baseNULL, sfp[1].o);
	}
	//(sfp[0].cc)->envsfp = NULL;
	RETURN_(fo);
}

/* ------------------------------------------------------------------------ */
//## @Const method Goal Goal.new(String type, String msg);

static METHOD Goal_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Goal_t *goal = sfp[0].goal;
	KNH_SETv(ctx, goal->type, sfp[1].s);
	KNH_SETv(ctx, goal->msg, sfp[2].s);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
//## @Const method UnitTest UnitTest.new(String msg);

static METHOD UnitTest_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)sfp[0].o;
	KNH_SETv(ctx, ut->msg, sfp[1].s);
	RETURN_(sfp[0].o);
}


/* ------------------------------------------------------------------------ */

#endif/* K_INCLUDE_BUILTINAPI*/

#ifdef __cplusplus
}
#endif
