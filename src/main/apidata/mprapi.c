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
/* [toInt] */

//## @Const @Final mapper Float Int;

static TCAST Float_Int(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bFloat(sfp[K_TRLIDX].o));
	knh_int_t v = (knh_int_t)(sfp[K_TRLIDX].f)->n.fvalue;
	RETURNi_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const @Final mapper String Int;

static TCAST String_Int(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_int_t v = 0;
	if(!knh_bytes_parseint(S_tobytes(sfp[K_TRLIDX].s), &v)) {
		KNH_SETv(ctx, sfp[rix].o, KNH_NULVAL(CLASS_Int));
	}
	RETURNi_(v);
}

/* ------------------------------------------------------------------------ */
/* [toFloat] */

//## @Const @Final mapper Int Float;

static TCAST Int_Float(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bInt(sfp[K_TRLIDX].o));
	knh_float_t v = (knh_float_t)(sfp[K_TRLIDX].i)->n.ivalue;
	RETURNf_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const @Final mapper String Float;

static TCAST String_Float(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_float_t v = 0.0;
	if(!knh_bytes_parsefloat(S_tobytes(sfp[K_TRLIDX].s), &v)) {
		KNH_SETv(ctx, sfp[rix].o, KNH_NULVAL(CLASS_Float));
	}
	RETURNf_(v);
}


/* ------------------------------------------------------------------------ */
/* [toString] */

/* ------------------------------------------------------------------------ */
//## @Const @Final @LossLess mapper Boolean String;

static TCAST Boolean_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = (Boolean_to(int, (sfp[K_TRLIDX]))) ? TS_true : TS_false;
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const @Final @LossLess mapper Int String;

static TCAST Int_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[256];
	knh_snprintf(buf, sizeof(buf), K_INT_FMT, sfp[K_TRLIDX].ivalue);
	RETURN_(new_S(ctx, B(buf)));
}

/* ------------------------------------------------------------------------ */
//## @Const @Final @LossLess mapper Float String;

static TCAST Float_String(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[256];
	knh_snprintf(buf, sizeof(buf), K_FLOAT_FMT, sfp[K_TRLIDX].fvalue);
	RETURN_(new_S(ctx, B(buf)));
}

///* ------------------------------------------------------------------------ */
////## @Const @Final mapper Bytes String;
//
//static TCAST Bytes_String(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_bytes_t t = knh_Bytes_tobytes((knh_Bytes_t*)sfp[K_TRLIDX].o);
//	knh_String_t *s = TS_EMPTY;
//	if(knh_bytes_checkENCODING(t)) {
//		s = new_S(ctx, t);
//	}
//	RETURN_(s);
//}

/* ------------------------------------------------------------------------ */
/* [toBytes] */

/* ------------------------------------------------------------------------ */
//## @Const @Final mapper String Bytes;

static TCAST String_Bytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *b = new_Bytes(ctx, S_size(sfp[K_TRLIDX].s) + 1);
	knh_Bytes_write(ctx, b, S_tobytes(sfp[K_TRLIDX].s));
	RETURN_(b);
}

/* ------------------------------------------------------------------------ */
/* [Iterator] */

/* ------------------------------------------------------------------------ */
//## @Const mapper Object Iterator!;
//## method This.. Object.opITR();

static TCAST Object_Iterator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	Object *o = sfp[K_TRLIDX].o;
	RETURN_(new_Iterator(ctx, O_cid(o), o, NULL));
}

/* ------------------------------------------------------------------------ */
/* [Iterator] */

//void knh_stack_boxing(CTX ctx, knh_sfp_t *sfp)
//{
//	knh_class_t bcid = O_bcid(sfp[0].o);
//	if(CLASS_Boolean <= bcid && bcid <= CLASS_Float && sfp[0].ndata != O_data(sfp[0].o)) {
//		KNH_SETv(ctx, sfp[0].o, new_Boxing(ctx, O_cid(sfp[0].o), sfp));
//	}
//}

/* ------------------------------------------------------------------------ */
//## mapper Iterator Array!;

static TCAST Iterator_Array(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KNH_TODO("Iterator_Array");
//	knh_Iterator_t *it = sfp[K_TRLIDX].it;
//	knh_Array_t *a = new_Array(ctx, knh_class_p1(it->h.cid), 0);
//	while(it->fnext_1(ctx, sfp, 1)) {
//		knh_stack_boxing(ctx, sfp + 1);
//		knh_Array_add_(ctx, a, sfp[1].o);
//	}
//	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
/* [Stream] */

/* ------------------------------------------------------------------------ */
//## mapper Bytes InputStream;

static TCAST Bytes_InputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = (knh_Bytes_t*)sfp[K_TRLIDX].o;
	RETURN_(new_BytesInputStream(ctx, ba));
}

/* ------------------------------------------------------------------------ */

#endif/* K_USING_DEFAULTAPI*/

#ifdef __cplusplus
}
#endif
