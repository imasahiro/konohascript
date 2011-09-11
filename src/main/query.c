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

/* ------------------------------------------------------------------------ */
/* [Connection] */

void knh_Connection_open(CTX ctx, knh_Connection_t *c, knh_Path_t *path, knh_DictMap_t *conf)
{
	KNH_TODO("query");
//	knh_bytes_t u = S_tobytes(urn);
//	KNH_SETv(ctx, (c)->urn, urn);
//	(c)->dpi = knh_NameSpace_getQueryDPINULL(ctx, ns, S_tobytes(urn));
//	(c)->conn = (c)->dpi->qopen(ctx, u);
}

/* ------------------------------------------------------------------------ */

//knh_Connection_t* new_Connection(CTX ctx, knh_NameSpace_t *ns, knh_String_t *urn)
//{
//	knh_Connection_t *o = new_(Connection);
//	knh_Connection_open(ctx, o, ns, urn);
//	return o;
//}
//
///* ------------------------------------------------------------------------ */
//
//void knh_Connection_close(CTX ctx, knh_Connection_t *c)
//{
//	(c)->dpi->qclose(ctx, (c)->conn);
//	(c)->conn = NULL;
//	(c)->dpi = NULL;
//}

/* ------------------------------------------------------------------------ */
/* [ResultSet] */

//knh_bool_t knh_ResultSet_next(CTX ctx, knh_ResultSet_t *o)
//{
//	if(DP(o)->qcur != NULL) {
//		if(DP(o)->conn->dpi->qcurnext(ctx, DP(o)->qcur, o)) {
//			DP(o)->count += 1;
//			return 1;
//		}
//		else {
//			knh_bytes_t t = {{""}, 0};
//			DP(o)->qcurfree(DP(o)->qcur);
//			DP(o)->qcur = NULL;
//			DP(o)->qcurfree = knh_NameSpace_getQueryDPINULL(ctx, NULL, t)->qcurfree;
//		}
//	}
//	return 0;
//}
//
///* ------------------------------------------------------------------------ */
//
//void knh_ResultSet_close(CTX ctx, knh_ResultSet_t *o)
//{
//	if(DP(o)->qcur != NULL) {
//		knh_bytes_t t = {{""}, 0};
//		DP(o)->qcurfree(DP(o)->qcur);
//		DP(o)->qcur = NULL;
//		DP(o)->qcurfree = knh_NameSpace_getQueryDPINULL(ctx, NULL, t)->qcurfree;
//	}
//	KNH_SETv(ctx, DP(o)->conn, KNH_NULL);
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) knh_ResultSet_initColumn(CTX ctx, knh_ResultSet_t *o, size_t column_size)
//{
//	size_t i;
//	if(DP(o)->column_size != 0) {
//		for(i = 0; i < DP(o)->column_size; i++) {
//			KNH_FINALv(ctx, DP(o)->column[i].name);
//		}
//		KNH_FREE(ctx, DP(o)->column, sizeof(knh_dbschema_t) * DP(o)->column_size);
//		DP(o)->column = NULL;
//		if(DP(o)->qcur != NULL) {
//			DP(o)->qcurfree(DP(o)->qcur);
//			DP(o)->qcur = NULL;
//		}
//	}
//	DP(o)->column_size = column_size;
//	if(column_size > 0) {
//		DP(o)->column = (knh_dbschema_t*)KNH_MALLOC(ctx, sizeof(knh_dbschema_t) * DP(o)->column_size);
//		for(i = 0; i < DP(o)->column_size; i++) {
//			DP(o)->column[i].type = CLASS_Object;
//			KNH_INITv(DP(o)->column[i].name, TS_EMPTY);
//			DP(o)->column[i].start = 0;
//			DP(o)->column[i].len = 0;
//		}
//	}
//	DP(o)->count = 0;
//}
//
///* ------------------------------------------------------------------------ */
///* [meta] */
//
//void knh_ResultSet_initTargetClass(knh_ResultSet_t *o, knh_class_t tcid)
//{
//	DP(o)->tcid = tcid;
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setName(CTX ctx, knh_ResultSet_t *o, size_t n, knh_String_t *name)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	KNH_SETv(ctx, DP(o)->column[n].name, name);
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_String_t *knh_ResultSet_getName(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	return DP(o)->column[n].name;
//}
//
///* ------------------------------------------------------------------------ */
//
//int knh_ResultSet_findColumn(CTX ctx, knh_ResultSet_t *o, knh_bytes_t name)
//{
//	size_t i = 0;
//	for(i = 0; i < DP(o)->column_size; i++) {
//		if(knh_bytes_strcasecmp(S_tobytes(DP(o)->column[i].name), name) == 0) return i;
//	}
//	return -1;
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_type_t knh_ResultSet_get_type(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	return DP(o)->column[n].type;
//}
//
///* ------------------------------------------------------------------------ */
///* [set] */
//
//void knh_ResultSet_initData(CTX ctx, knh_ResultSet_t *rs)
//{
//	size_t i = 0;
//	for(i = 0; i < DP(rs)->column_size; i++) {
//		DP(rs)->column[i].ctype = 0;
//		DP(rs)->column[i].start = 0;
//		DP(rs)->column[i].len = 0;
//	}
//	knh_Bytes_clear(DP(rs)->databuf, 0);
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setInt(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_int_t value)
//{
//	KNH_ASSERT(n < DP(rs)->column_size);
//	knh_bytes_t t = {{(const char*)(&value)}, sizeof(knh_int_t)};
//	DP(rs)->column[n].ctype = knh_ResultSet_CTYPE__integer;
//	DP(rs)->column[n].start = BA_size(DP(rs)->databuf);
//	DP(rs)->column[n].len = sizeof(knh_int_t);
//	knh_Bytes_write(ctx, DP(rs)->databuf, t);
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setFloat(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_float_t value)
//{
//	KNH_ASSERT(n < DP(rs)->column_size);
//	knh_bytes_t t = {{(const char*)(&value)}, sizeof(knh_float_t)};
//	DP(rs)->column[n].ctype = knh_ResultSet_CTYPE__float;
//	DP(rs)->column[n].start = BA_size(DP(rs)->databuf);
//	DP(rs)->column[n].len = sizeof(knh_float_t);
//	knh_Bytes_write(ctx, DP(rs)->databuf, t);
//	int i, c = t.len % sizeof(void*);
//	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(rs)->databuf, 0);    /* zero */
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setText(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__text;
//	DP(o)->column[n].start = BA_size(DP(o)->databuf);
//	DP(o)->column[n].len = t.len;
//	knh_Bytes_write(ctx, DP(o)->databuf, t);
//	int i, c = t.len % sizeof(void*);
//	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(o)->databuf, 0);    /* zero */
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setBlob(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__bytes;
//	DP(o)->column[n].start = BA_size(DP(o)->databuf);
//	DP(o)->column[n].len = t.len;
//	knh_Bytes_write(ctx, DP(o)->databuf, t);
//	int i, c = t.len % sizeof(void*);
//	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(o)->databuf, 0);    /* zero */
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) ResultSet_setNULL(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__null;
//	DP(o)->column[n].start = BA_size(DP(o)->databuf);
//	DP(o)->column[n].len = 0;
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_int_t knh_ResultSet_getInt(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
//	switch(DP(o)->column[n].ctype) {
//	case knh_ResultSet_CTYPE__null :
//		return 0;
//	case knh_ResultSet_CTYPE__integer :
//		return (knh_int_t)(*((knh_int_t*)p));
//	case knh_ResultSet_CTYPE__float :
//		return (knh_int_t)(*((knh_float_t*)p));
//	case knh_ResultSet_CTYPE__bytes :
//		TODO();
////		return knh_bytes_toint(B2(p, DP(o)->column[n].len));
//	}
//	return 0;
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_float_t knh_ResultSet_getFloat(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
//	switch(DP(o)->column[n].ctype) {
//	case knh_ResultSet_CTYPE__null :
//		return K_FLOAT_ZERO;
//	case knh_ResultSet_CTYPE__integer :
//		return (knh_float_t)(*((knh_int_t*)p));
//	case knh_ResultSet_CTYPE__float :
//		return (knh_float_t)(*((knh_float_t*)p));
//	case knh_ResultSet_CTYPE__bytes :
//		TODO();
////		return knh_bytes_tofloat(B2(p, DP(o)->column[n].len));
//	}
//	return K_FLOAT_ZERO;
//}
//
///* ------------------------------------------------------------------------ */
//
//static knh_String_t *new_String__int(CTX ctx, knh_int_t n)
//{
//	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//	knh_write_ifmt(ctx, cwb->w, K_INT_FMT, n);
//	return CWB_newString(ctx, cwb, K_SPOLICY_POOLALWAYS|K_SPOLICY_ASCII);
//}
//
//static knh_String_t *new_String__float(CTX ctx, knh_float_t n)
//{
//	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//	knh_write_ffmt(ctx, cwb->w, K_FLOAT_FMT, n);
//	return CWB_newString(ctx, cwb, K_SPOLICY_POOLALWAYS|K_SPOLICY_ASCII);
//}
//
//knh_String_t* knh_ResultSet_getString(CTX ctx, knh_ResultSet_t *o, size_t n)
//{
//	KNH_ASSERT(n < DP(o)->column_size);
//	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
//	switch(DP(o)->column[n].ctype) {
//	case knh_ResultSet_CTYPE__integer :
//		return new_String__int(ctx, (knh_int_t)(*((knh_int_t*)p)));
//	case knh_ResultSet_CTYPE__float :
//		return new_String__float(ctx, (knh_float_t)(*((knh_float_t*)p)));
//	case knh_ResultSet_CTYPE__text :
//		return new_String2(ctx, CLASS_String, p, DP(o)->column[n].len, 0);
//	case knh_ResultSet_CTYPE__null :
//		break;
//	}
//	return KNH_TNULL(String);
//}
//
//static void NOP_qfree(knh_qcur_t *qcur)
//{
//}
//static knh_qconn_t *NOP_qopen(CTX ctx, knh_bytes_t url)
//{
//	return NULL;
//}
//static knh_qcur_t *NOP_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
//{
//	return NULL;
//}
//static void NOP_qclose(CTX ctx, knh_qconn_t *hdr)
//{
//}
//static int NOP_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
//{
//	return 0;  /* NOMORE */
//}
//
//static const knh_QueryDPI_t QUERY_NOP = {
//	K_DSPI_QUERY, "NOP",
//	NOP_qopen, NOP_query, NOP_qclose, NOP_qnext, NOP_qfree
//};
//
//const knh_QueryDPI_t *knh_getDefaultQueryDPI(void)
//{
//	return &QUERY_NOP;
//}
//
//
//#ifdef K_USING_SQLITE3
//
//#include<sqlite3.h>
//
//static void knh_sqlite3_perror(CTX ctx, sqlite3 *db, int r)
//{
//	const char *msg = "sqlite3";
//	if(r == SQLITE_PERM || r == SQLITE_AUTH) {
//		msg = "Security";
//	}
//	KNH_LOG("sqlite3_error='%s', '%s'", msg, sqlite3_errmsg(db));
//}
//
//static knh_qconn_t *SQLITE3_qopen(CTX ctx, knh_Path_t *path)
//{
//	sqlite3 *db = NULL;
//	url = knh_bytes_next(url, ':');
//	int r = sqlite3_open(url.text, &db);
//	if (r != SQLITE_OK) {
//		return NULL;
//	}
//	return (knh_qconn_t*)db;
//}
//
//static int SQLITE3_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
//{
//	sqlite3_stmt *stmt = (sqlite3_stmt*)qcur;
//	int r = sqlite3_step(stmt);
//	if(SQLITE_ROW == r) {
//		size_t i;
//		knh_ResultSet_initData(ctx, rs);
//		for(i = 0; i < DP(rs)->column_size; i++) {
//			int type = sqlite3_column_type(stmt, i);
//			switch(type) {
//				case SQLITE_INTEGER: {
//					ResultSet_setInt(ctx, rs, i, (knh_int_t)sqlite3_column_int64(stmt, i));
//					break;
//				}
//				case SQLITE_FLOAT: {
//					ResultSet_setFloat(ctx, rs, i, (knh_float_t)sqlite3_column_double(stmt, i));
//					break;
//				}
//				case SQLITE_TEXT: {
//					knh_bytes_t t = {{(const char*)sqlite3_column_text(stmt,i)}, sqlite3_column_bytes(stmt, i)};
//					ResultSet_setText(ctx, rs, i, t);
//					break;
//				}
//				case SQLITE_BLOB: {
//					knh_bytes_t t = {{(const char*)sqlite3_column_blob(stmt,i)}, sqlite3_column_bytes(stmt, i)};
//					ResultSet_setBlob(ctx, rs, i, t);
//					break;
//				}
//				case SQLITE_NULL:
//				default: {
//					ResultSet_setNULL(ctx, rs, i);
//				}
//			}
//		}
//		return 1;
//	}
//	else if (r != SQLITE_DONE) {
//	   //
//	}
//	return 0;  /* NOMORE */
//}
//
//static knh_qcur_t *SQLITE3_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
//{
//	if(rs == NULL) {
//		int r = sqlite3_exec((sqlite3*)hdr, sql.text, NULL, NULL, NULL);
//		if(r != SQLITE_OK) {
//			knh_sqlite3_perror(ctx, (sqlite3*)hdr, r);
//		}
//		return NULL;
//	}
//	else {
//		sqlite3_stmt *stmt = NULL;
//		sqlite3_prepare((sqlite3*)hdr, sql.text, sql.len, &stmt, NULL);
//		size_t column_size = (size_t)sqlite3_column_count(stmt);
//		knh_ResultSet_initColumn(ctx, rs, column_size);
//		if(column_size > 0) {
//			size_t i;
//			for(i = 0; i < DP(rs)->column_size; i++) {
//				const char *n = (const char*)sqlite3_column_name(stmt, i);
//				if(n != NULL) {
//					ResultSet_setName(ctx, rs, i, new_S(n, knh_strlen(n)));
//				}
//			}
//		}
//		return (knh_qcur_t*)stmt;
//	}
//}
//
//static ITRNEXT SQLITE3_nextData(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Iterator_t *itr = ITR(sfp);
//	sqlite3_stmt *stmt = DP(itr)->m.nptr;
//	int r = sqlite3_step(stmt);
//	if(SQLITE_ROW == r) {
//		knh_Map_t *dmap = new_DataMap(ctx);
//		size_t i, column_size = (size_t)sqlite3_column_count(stmt);
//		for(i = 0; i < column_size; i++) {
//			const char *name = (const char*)sqlite3_column_name(stmt, i);
//			int type = sqlite3_column_type(stmt, i);
//			switch(type) {
//				case SQLITE_INTEGER: {
//					knh_DataMap_setInt(ctx, dmap, name, (knh_int_t)sqlite3_column_int64(stmt, i));
//					break;
//				}
//				case SQLITE_FLOAT: {
//					knh_DataMap_setFloat(ctx, dmap, name, (knh_float_t)sqlite3_column_double(stmt, i));
//					break;
//				}
//				case SQLITE_TEXT: {
//					knh_DataMap_setString(ctx, dmap, name, (const char*)sqlite3_column_text(stmt,i));
//					break;
//				}
//				case SQLITE_BLOB: {
//					knh_DataMap_setBlob(ctx, dmap, name, (const char*)sqlite3_column_blob(stmt,i), sqlite3_column_bytes(stmt, i));
//					break;
//				}
////				case SQLITE_NULL:
////				default: {
////					ResultSet_setNULL(ctx, rs, i);
////				}
//			}
//		}
//		ITRNEXT_(dmap);
//	}
//	else {
//		DP(itr)->m.nfree((void*)stmt);
//		ITREND_();
//	}
//}
//
//static void SQLITE3_qclose(CTX ctx, knh_qconn_t *hdr)
//{
//	sqlite3_close((sqlite3*)hdr);
//}
//
//static void SQLITE3_qfree(void *qcur)
//{
//	sqlite3_stmt *stmt = (sqlite3_stmt*)qcur;
//	sqlite3_finalize(stmt);
//}
//
//static const knh_QueryDPI_t QUERY_SQLITE3 = {
//	K_DSPI_QUERY, "sqlite3",
//	SQLITE3_qopen, SQLITE3_query, SQLITE3_qclose, SQLITE3_qnext, SQLITE3_qfree,
//	SQLITE3_nextData,
//};
//
//#endif/*K_USING_SQLITE3*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

