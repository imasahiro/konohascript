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
/* [Map] */

/* ------------------------------------------------------------------------ */
//## method Boolean Map.opHAS(T1 key);

static METHOD Map_opHAS(CTX ctx, knh_sfp_t *sfp, long rix)
{
	knh_Map_t *m = sfp[0].m;
	RETURNb_(m->dspi->get(ctx, m->dmap, sfp + 1, sfp + rix));
}

/* ------------------------------------------------------------------------ */
//## method T2 Map.get(T1 key);

static METHOD Map_get(CTX ctx, knh_sfp_t *sfp, long rix)
{
	knh_Map_t *m = sfp[0].m;
	if(!m->dspi->get(ctx, m->dmap, sfp + 1, sfp + rix)) {
		RETURNa_(KNH_NULVAL(knh_class_p2(O_cid(m))));
	}
}

/* ------------------------------------------------------------------------ */
//## method void Map.set(T1 key, T2 value);

static METHOD DictMap_set(CTX ctx, knh_sfp_t *sfp, long rix)
{
	knh_Map_t *m = sfp[0].m;
	m->dspi->set(ctx, m->dmap, sfp + 1);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Map.remove(T1 key);

static METHOD DictMap_remove(CTX ctx, knh_sfp_t *sfp, long rix)
{
	knh_Map_t *m = sfp[0].m;
	m->dspi->remove(ctx, m->dmap, sfp + 1);
	RETURNvoid_();
}

///* ------------------------------------------------------------------------ */
////## method T1[] Map.keys();
//
//static METHOD Map_keys(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_DictMap_t *o = (knh_DictMap_t*)sfp[0].o;
//	knh_Array_t *a = new_Array(ctx, CLASS_String, o->size);
//	size_t i;
//	for(i=0; i < o->size; i++) {
//		knh_Array_add_(ctx, a, UPCAST(o->list[i].key));
//	}
//	RETURN_(UPCAST(a));
//}

///* ------------------------------------------------------------------------ */
////## method T1[] Map.values();
//
//static METHOD Map_values(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_DictMap_t *o = (knh_DictMap_t*)sfp[0].o;
//	knh_Array_t *a = new_Array0(ctx, o->size);
//	size_t i;
//	for(i=0; i < o->size; i++) {
//		knh_Array_add_(ctx, a, UPCAST(o->list[i].value));
//	}
//	RETURN_(UPCAST(a));
//}

/* ------------------------------------------------------------------------ */

#endif/*K_USING_DEFAULTAPI*/

#ifdef __cplusplus
}
#endif
