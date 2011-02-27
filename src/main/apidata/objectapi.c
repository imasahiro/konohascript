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

#ifdef K_USING_DEFAULTAPI

/* ------------------------------------------------------------------------ */
//## @Const method Class! Object.getClass();

static METHOD Object_getClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_Type(ctx, O_cid(sfp[0].o)));
}

/* ------------------------------------------------------------------------ */
//## method Int Object.hashCode();

static METHOD Object_hashCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_hashcode_t h = ClassTBL(O_bcid(sfp[0].o))->cspi2->hashCode(ctx, sfp);
	RETURNi_(h);
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden method Boolean Object.isNull();

static METHOD Object_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(IS_NULL(sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden method Boolean Object.isNotNull();

static METHOD Object_isNotNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(IS_NOTNULL(sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## @Const @Virtual method String Object.getKey();

static METHOD Object_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = ClassTBL(O_bcid(sfp[0].o))->cspi2->getkey(ctx, sfp);
	KNH_ASSERT(IS_String(s));
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const @Hidden method This Object.copy();

static METHOD Object_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *src = sfp[0].o;
	knh_class_t cid = O_cid(src);
	if(knh_class_canObjectCopy(ctx, cid) && IS_NOTNULL(src)) {
		const knh_ClassTBL_t *ct = O_cTBL(src);
		knh_Object_t *o = new_hObject_(ctx, ct);
		o->h.magicflag = src->h.magicflag;
		ct->cspi2->initcopy(ctx, o, src);
		src = o;
	}
	sfp[rix].ndata = sfp[0].ndata;
	RETURN_(src);
}


///* ------------------------------------------------------------------------ */
////## @Hidden method Array! Class.domain();
//
//static METHOD Class_domain(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	RETURN_(knh_getClassDomain(ctx, (sfp[0].c)->cid));
//}

/* ------------------------------------------------------------------------ */
/* [Method] */

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Method.isAbstract();

static METHOD Method_isAbstract_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(Method_isAbstract(sfp[0].mtd));
}

/* ------------------------------------------------------------------------ */
//## @Const method String Method.getName();

static METHOD Method_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_write_mn(ctx, cwb->w, (sfp[0].mtd)->mn);
	RETURN_(knh_cwb_newString(ctx, cwb));
}


///* ------------------------------------------------------------------------ */
////## @Const method void Method.setTrace(Int trace);
//
//static METHOD Method_setTrace(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	
//	knh_Method_trace(ctx, sfp[0].mtd, (int)sfp[1].ivalue);
//	RETURNvoid_();
//}

/* ------------------------------------------------------------------------ */
//## @Hidden @Private method dynamic Func.invoke(dynamic x);

static METHOD Func_invoke(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Func_t* fo = sfp[0].fo;
	if(fo->baseNULL != NULL) {
		KNH_SETv(ctx, sfp[0].o, fo->baseNULL);
	}
	klr_setmtdNC(ctx, sfp[K_MTDIDX], fo->mtd);
	KNH_SELFCALL(ctx, sfp, fo->mtd, rix);
}

///* ------------------------------------------------------------------------ */
////## method T1 Thunk.eval();
//
//static METHOD Thunk_eval(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	
//	knh_Thunk_t *thk = (knh_Thunk_t*)sfp[0].o;
//	size_t i;
//	if((thk)->envsize > 0) {
//		for(i = 2; i < (thk)->envsize; i++) {
//			KNH_SETv(ctx, sfp[i].o, (thk)->envsfp[i].o);
//			sfp[i].ndata = (thk)->envsfp[i].ndata;
//		}
//		KNH_SCALL(ctx, sfp, 1, (thk)->envsfp[1].mtd, ((thk)->envsize-3));
//		KNH_SETv(ctx, (thk)->envsfp[0].o, sfp[1].o);
//		(thk)->envsfp[0].ndata = sfp[1].ndata;
//		Thunk_setEvaluated(thk, 1);
//	}
//	KNH_SETv(ctx, sfp[-1].o, (thk)->envsfp[0].o);
//	sfp[-1].ndata = (thk)->envsfp[0].ndata;
//}

///* ------------------------------------------------------------------------ */
////## method T1 Thunk.value();
//
//static METHOD Thunk_value(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Thunk_t *thk = (knh_Thunk_t*)sfp[0].o;
//	if(Thunk_isEvaluated(thk)) {
//		KNH_SETv(ctx, sfp[-1].o, (thk)->envsfp[0].o);
//		sfp[-1].ndata = (thk)->envsfp[0].ndata;
//	}
//	else {
//		Thunk_eval(ctx, sfp);
//	}
//}

#endif/* K_USING_DEFAULTAPI*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
