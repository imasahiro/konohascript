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

#include"../include/konoha_query.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif
/* ------------------------------------------------------------------------ */
//## method This Connection.new(String urn);

KMETHOD Connection_new(CTX ctx, ksfp_t *sfp _RIX)
{
	kConnection *o = (kConnection*)sfp[0].o;
	knh_Connection_open(ctx, o, sfp[1].s);
	RETURN_(sfp[0].o);
}

/* ------------------------------------------------------------------------ */
//## method ResultSet! Connection.query(String query);

#define K_DEFAULT_DSPI          STEXT("")

KMETHOD Connection_query(CTX ctx, ksfp_t *sfp _RIX)
{
	kConnection *c = (kConnection*)sfp[0].o;
	kString *query = (kString*)sfp[1].o;
	kResultSet *rs = (kResultSet*)new_O(ResultSet, knh_getcid(ctx, STEXT("ResultSet")));
	KNH_RCSETv(ctx, sfp[2].o, rs);
	kqcur_t *qcur = (c)->dspi->qexec(ctx, (c)->conn, S_tobytes(query), rs);
	if(qcur != NULL) {
		DP(rs)->qcur = qcur;
		DP(rs)->qcurfree = (c)->dspi->qcurfree;
	}
	else {
		DP(rs)->qcur = NULL;
		DP(rs)->qcurfree = NULL;
		//DP(rs)->qcurfree = knh_getQueryDSPI(ctx, K_DEFAULT_DSPI)->qcurfree;
	}
	KNH_SETv(ctx, DP(rs)->conn, c);
	RETURN_(rs);
}

/* ------------------------------------------------------------------------ */
//## method void Connection.exec(String query);

KMETHOD Connection_exec(CTX ctx, ksfp_t *sfp _RIX)
{
	kConnection *c = (kConnection*)sfp[0].o;
	kString *query = sfp[1].s;
	(c)->dspi->qexec(ctx, (c)->conn, S_tobytes(query), NULL);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Connection.close();

KMETHOD Connection_close(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_Connection_close(ctx, (kConnection*)sfp[0].o);
	RETURNvoid_();
}

#ifdef K_USING_MYSQL
/* ------------------------------------------------------------------------ */
//## method Int Connection.getInsertId();

KMETHOD Connection_getInsertId(CTX ctx, ksfp_t *sfp _RIX)
{
	kConnection *c = (kConnection*)sfp[0].o;
	RETURNi_((kuint_t)mysql_insert_id((MYSQL*)c->conn));
}
#endif

/* ------------------------------------------------------------------------ */
//## method Int ResultSet.getSize();

KMETHOD ResultSet_getSize(CTX ctx, ksfp_t *sfp _RIX)
{
	kResultSet *o = (kResultSet*)sfp[0].o;
	RETURNi_(DP(o)->column_size);
}

/* ------------------------------------------------------------------------ */
//## method Boolean ResultSet.next();

KMETHOD ResultSet_next(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(knh_ResultSet_next(ctx, (kResultSet*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method String ResultSet.getName(Int n);

KMETHOD ResultSet_getName(CTX ctx, ksfp_t *sfp _RIX)
{
	kResultSet *o = (kResultSet*)sfp[0].o;
	size_t n = Int_to(size_t, sfp[1]);
	kString *v = TS_EMPTY;
	if(n < DP(o)->column_size) {
		v = knh_ResultSet_getName(ctx, o, n);
	}
	else {
		THROW_OutOfRange(ctx, sfp, sfp[1].ivalue, DP(o)->column_size);
	}
	RETURN_(v);
}

/* ------------------------------------------------------------------------ */

static int knh_ResultSet_indexof_(CTX ctx, ksfp_t *sfp)
{
	kResultSet *o = (kResultSet*)sfp[0].o;
	if(IS_bInt(sfp[1].o)) {
		size_t n = Int_to(size_t, sfp[1]);
		if(!(n < DP(o)->column_size)) {
			THROW_OutOfRange(ctx, sfp, sfp[1].ivalue, DP(o)->column_size);
			return -1;
		}
		return n;
	}
	else if(IS_bString(sfp[1].o)) {
		int loc = knh_ResultSet_findColumn(ctx, o, S_tobytes(sfp[1].s));
		if(loc == -1) {
			TODO();
			//KNH_STUPID(ctx, o, STUPID_NOTFOUND);
		}
		return loc;
	}
	TODO();
	//KNH_STUPID(ctx, o, STUPID_NOTFOUND);
	return -1;
}

/* ------------------------------------------------------------------------ */
//## method Int ResultSet.getInt(dynamic n);

KMETHOD ResultSet_getInt(CTX ctx, ksfp_t *sfp _RIX)
{
	int n = knh_ResultSet_indexof_(ctx, sfp);
	kint_t res = 0;
	if(n >= 0) {
		kResultSet *o = (kResultSet*)sfp[0].o;
		const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
		switch(DP(o)->column[n].ctype) {
		case knh_ResultSet_CTYPE__integer :
			res = *((kint_t*)p); break;
		case knh_ResultSet_CTYPE__float :
			res = (kint_t)(*((kfloat_t*)p)); break;
		case knh_ResultSet_CTYPE__null :
		default:
			KNH_SETv(ctx, sfp[_rix].o, KNH_NULVAL(CLASS_Int));
		}
	}
	RETURNi_(res);
}

/* ------------------------------------------------------------------------ */
//## method Float ResultSet.getFloat(dynamic n);

KMETHOD ResultSet_getFloat(CTX ctx, ksfp_t *sfp _RIX)
{
	
	int n = knh_ResultSet_indexof_(ctx, sfp);
	kfloat_t res = KFLOAT_ZERO;
	if(n >= 0) {
		kResultSet *o = (kResultSet*)sfp[0].o;
		const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
		switch(DP(o)->column[n].ctype) {
		case knh_ResultSet_CTYPE__integer :
			res = (kfloat_t)(*((kint_t*)p)); break;
		case knh_ResultSet_CTYPE__float :
			res = (*((kfloat_t*)p)); break;
		case knh_ResultSet_CTYPE__null :
		default:
			KNH_SETv(ctx, sfp[_rix].o, KNH_NULVAL(CLASS_Float));
		}
	}
	RETURNf_(res);
}

/* ------------------------------------------------------------------------ */
//## method String ResultSet.getString(dynamic n);

KMETHOD ResultSet_getString(CTX ctx, ksfp_t *sfp _RIX)
{
	
	int n = knh_ResultSet_indexof_(ctx, sfp);
	Object *v = KNH_NULL;
	if(n >= 0) {
		v = UPCAST(knh_ResultSet_getString(ctx, (kResultSet*)sfp[0].o, n));
	}
	RETURN_(v);
}

/* ------------------------------------------------------------------------ */
//## method dynamic ResultSet.get(dynamic n);

KMETHOD ResultSet_get(CTX ctx, ksfp_t *sfp _RIX)
{
	
	int n = knh_ResultSet_indexof_(ctx, sfp);
	Object *v = KNH_NULL;
	if(n >= 0) {
		kResultSet *o = (kResultSet*)sfp[0].o;
		const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
		switch(DP(o)->column[n].ctype) {
		case knh_ResultSet_CTYPE__integer :
			KNH_SETv(ctx, sfp[_rix].o, new_Int_(ctx, CLASS_Int, 0));
			RETURNi_((*((kint_t*)p)));
		case knh_ResultSet_CTYPE__float :
			KNH_SETv(ctx, sfp[_rix].o, new_Float_(ctx, CLASS_Float, 0.0));
			RETURNf_((*((kfloat_t*)p)));
		case knh_ResultSet_CTYPE__text : {
			kbytes_t t = {{BA_totext(DP(o)->databuf) + DP(o)->column[n].start}, DP(o)->column[n].len};
			v = UPCAST(new_S(t.text, t.len));
			break;
		}
		case knh_ResultSet_CTYPE__bytes :
			{
				kBytes *ba = new_Bytes(ctx, BA_totext(DP(o)->databuf) + DP(o)->column[n].start, DP(o)->column[n].len);
				kbytes_t t = {{BA_totext(DP(o)->databuf) + DP(o)->column[n].start}, DP(o)->column[n].len};
				knh_Bytes_write(ctx, ba, t);
				v = UPCAST(ba);
			}
			break;
		default:
			v = KNH_NULL;
		}
	}
	RETURN_(v);
}

///* ------------------------------------------------------------------------ */
////## method void ResultSet.%dump(OutputStream w, String m);
//
//static void knh_ResultSet__dump(CTX ctx, kResultSet *o, kOutputStream *w, kString *m)
//{
//	knh_putc(ctx, w, '{');
//	size_t n;
//	for(n = 0; n < DP(o)->column_size; n++) {
//		if(n > 0) {
//			knh_write_delim(ctx,w);
//		}
//		knh_write(ctx, w, S_tobytes(DP(o)->column[n].name));
//		knh_printf(ctx, w, "(%d): ", n);
//		char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
//		switch(DP(o)->column[n].ctype) {
//			case knh_ResultSet_CTYPE__null :
//				knh_write(ctx, w, STEXT("null"));
//				break;
//			case knh_ResultSet_CTYPE__integer :
//				knh_write_ifmt(ctx, w, KINT_FMT, (*((kint_t*)p)));
//				break;
//			case knh_ResultSet_CTYPE__float :
//				knh_write_ffmt(ctx, w, KFLOAT_FMT, (*((kfloat_t*)p)));
//				break;
//			case knh_ResultSet_CTYPE__text :
//				knh_write(ctx, w, B2(p, DP(o)->column[n].len));
//				break;
//			case knh_ResultSet_CTYPE__bytes :
//				knh_printf(ctx, w, "BLOB(%dbytes)", DP(o)->column[n].len);
//				break;
//		}
//	}
//	knh_putc(ctx, w, '}');
//}

/* ------------------------------------------------------------------------ */
//## method void ResultSet.close();

KMETHOD ResultSet_close(CTX ctx, ksfp_t *sfp _RIX)
{
	
	knh_ResultSet_close(ctx, (kResultSet*)sfp[0].o);
	RETURNvoid_();
}
#ifdef __cplusplus
}
#endif
