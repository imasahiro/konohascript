/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  uh    - Yutaro Hiraoka, Yokohama National University, Japan
//  yoan  - Motoki Yoan, Yokohama National University, Japan
// **************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/konoha_query.h"

#ifdef K_USING_MYSQL
extern knh_QueryDSPI_t DB__mysql;
#endif
//#define USE_cwb_open      1

/* ======================================================================== */
/* [private function] */
/* ------------------------------------------------------------------------ */
/* K_DSPI_QUERY */

static void NOP_qfree(knh_qcur_t *qcur)
{
}
static knh_qconn_t *NOP_qopen(CTX ctx, knh_bytes_t url)
{
	return NULL;
}
static knh_qcur_t *NOP_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
{
	return NULL;
}
static void NOP_qclose(CTX ctx, knh_qconn_t *hdr)
{
}
static int NOP_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
{
	return 0;  /* NOMORE */
}

static knh_QueryDSPI_t NOP_DSPI = {
	K_DSPI_QUERY, "NOP",
	NOP_qopen, NOP_query, NOP_qclose, NOP_qnext, NOP_qfree
};

typedef struct knh_DSPI_t{
	int type;
	const char* name;
}knh_DSPI_t;

const knh_DSPI_t *knh_getDSPINULL(CTX ctx, int type, knh_bytes_t path)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_index_t idx = knh_bytes_index(path, ':');
	if (idx == -1) {
		knh_write(ctx, cwb->w, path);
	}
	else {
		knh_write(ctx, cwb->w, knh_bytes_first(path, idx));
	}
	knh_putc(ctx, cwb->w, ':');
	knh_write_ifmt(ctx, cwb->w, K_INT_FMT, type);
	OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
	const knh_DSPI_t *p = (const knh_DSPI_t*)knh_DictSet_get(ctx, ctx->share->urnDictSet, CWB_tobytes(cwb));
	OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);
	CWB_close(cwb);
	return p;
}

knh_QueryDSPI_t *knh_getQueryDSPI(CTX ctx, knh_bytes_t path)
{
	if(path.len == 0) {
		return &NOP_DSPI;
	}
	else {
		knh_QueryDSPI_t *p = (knh_QueryDSPI_t *)knh_getDSPINULL(ctx, K_DSPI_QUERY, path);
		if(p == NULL) {
			//SYSLOG_UnknownPathType(ctx, path);
			p = &NOP_DSPI;
		}
		return p;
	}
}
/* ------------------------------------------------------------------------ */
/* [Connection] */

void knh_Connection_open(CTX ctx, knh_Connection_t *c, knh_String_t *urn)
{
	knh_bytes_t u = S_tobytes(urn);
	KNH_SETv(ctx, (c)->urn, urn);
#ifdef K_USING_MYSQL
	(c)->dspi = &DB__mysql;
#else
	(c)->dspi = &NOP_DSPI;
#endif
	(c)->conn = (c)->dspi->qopen(ctx, u);
	KNH_INITv((c)->urn, urn);
}

knh_Connection_t* new_Connection(CTX ctx, knh_String_t *urn)
{
	knh_Connection_t *o = (knh_Connection_t *)new_O(Connection, knh_getcid(ctx, STEXT("Connection")));
	knh_Connection_open(ctx, o, urn);
	return o;
}

void knh_Connection_close(CTX ctx, knh_Connection_t *c)
{
	(c)->dspi->qclose(ctx, (c)->conn);
	(c)->conn = NULL;
	(c)->dspi = NULL;
}

/* ------------------------------------------------------------------------ */
/* [ResultSet] */

knh_bool_t knh_ResultSet_next(CTX ctx, knh_ResultSet_t *o)
{
	if(DP(o)->qcur != NULL) {
		if(DP(o)->conn->dspi->qcurnext(ctx, DP(o)->qcur, o)) {
			DP(o)->count += 1;
			return 1;
		}
		else {
			knh_bytes_t t = {{""}, 0};
			DP(o)->qcurfree(DP(o)->qcur);
			DP(o)->qcur = NULL;
			DP(o)->qcurfree = knh_getQueryDSPI(ctx, t)->qcurfree;
		}
	}
	return 0;
}

void knh_ResultSet_close(CTX ctx, knh_ResultSet_t *o)
{
	if(DP(o)->qcur != NULL) {
		knh_bytes_t t = {{""}, 0};
		DP(o)->qcurfree(DP(o)->qcur);
		DP(o)->qcur = NULL;
		DP(o)->qcurfree = knh_getQueryDSPI(ctx, t)->qcurfree;
	}
	KNH_SETv(ctx, DP(o)->conn, KNH_NULL);
}

KMETHOD knh_ResultSet_initColumn(CTX ctx, knh_ResultSet_t *o, size_t column_size)
{
	size_t i;
	if(DP(o)->column_size != 0) {
		for(i = 0; i < DP(o)->column_size; i++) {
			KNH_FINALv(ctx, DP(o)->column[i].name);
		}
		KNH_FREE(ctx, DP(o)->column, sizeof(knh_dbschema_t) * DP(o)->column_size);
		DP(o)->column = NULL;
		if(DP(o)->qcur != NULL) {
			DP(o)->qcurfree(DP(o)->qcur);
			DP(o)->qcur = NULL;
		}
	}
	DP(o)->column_size = column_size;
	if(column_size > 0) {
		DP(o)->column = (knh_dbschema_t*)KNH_MALLOC(ctx, sizeof(knh_dbschema_t) * column_size);
		for(i = 0; i < column_size; i++) {
			DP(o)->column[i].type = CLASS_Object;
			KNH_INITv(DP(o)->column[i].name, TS_EMPTY);
			DP(o)->column[i].start = 0;
			DP(o)->column[i].len = 0;
		}
	}
	DP(o)->count = 0;
}


void knh_ResultSet_initTargetClass(knh_ResultSet_t *o, knh_class_t tcid)
{
	DP(o)->tcid = tcid;
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setName(CTX ctx, knh_ResultSet_t *o, size_t n, knh_String_t *name)
{
	KNH_ASSERT(n < DP(o)->column_size);
	KNH_SETv(ctx, DP(o)->column[n].name, name);
}

/* ------------------------------------------------------------------------ */

knh_String_t *knh_ResultSet_getName(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	return DP(o)->column[n].name;
}

/* ------------------------------------------------------------------------ */

int knh_ResultSet_findColumn(CTX ctx, knh_ResultSet_t *o, knh_bytes_t name)
{
	size_t i = 0;
	for(i = 0; i < DP(o)->column_size; i++) {
		if(knh_bytes_strcasecmp(S_tobytes(DP(o)->column[i].name), name) == 0) return i;
	}
	return -1;
}

/* ------------------------------------------------------------------------ */

knh_type_t knh_ResultSet_get_type(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	return DP(o)->column[n].type;
}

/* ------------------------------------------------------------------------ */
/* [set] */

void knh_ResultSet_initData(CTX ctx, knh_ResultSet_t *rs)
{
	size_t i = 0;
	for(i = 0; i < DP(rs)->column_size; i++) {
		DP(rs)->column[i].ctype = 0;
		DP(rs)->column[i].start = 0;
		DP(rs)->column[i].len = 0;
	}
	knh_Bytes_clear(DP(rs)->databuf, 0);
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setInt(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_int_t value)
{
	KNH_ASSERT(n < DP(rs)->column_size);
	knh_bytes_t t = {{(const char*)(&value)}, sizeof(knh_int_t)};
	DP(rs)->column[n].ctype = knh_ResultSet_CTYPE__integer;
	DP(rs)->column[n].start = BA_size(DP(rs)->databuf);
	DP(rs)->column[n].len = sizeof(knh_int_t);
	knh_Bytes_write(ctx, DP(rs)->databuf, t);
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setFloat(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_float_t value)
{
	KNH_ASSERT(n < DP(rs)->column_size);
	knh_bytes_t t = {{(const char*)(&value)}, sizeof(knh_float_t)};
	DP(rs)->column[n].ctype = knh_ResultSet_CTYPE__float;
	DP(rs)->column[n].start = BA_size(DP(rs)->databuf);
	DP(rs)->column[n].len = sizeof(knh_float_t);
	knh_Bytes_write(ctx, DP(rs)->databuf, t);
	int i, c = t.len % sizeof(void*);
	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(rs)->databuf, 0);    /* zero */
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setText(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t)
{
	KNH_ASSERT(n < DP(o)->column_size);
	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__text;
	DP(o)->column[n].start = BA_size(DP(o)->databuf);
	DP(o)->column[n].len = t.len;
	knh_Bytes_write(ctx, DP(o)->databuf, t);
	int i, c = t.len % sizeof(void*);
	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(o)->databuf, 0);    /* zero */
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setBlob(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t)
{
	KNH_ASSERT(n < DP(o)->column_size);
	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__bytes;
	DP(o)->column[n].start = BA_size(DP(o)->databuf);
	DP(o)->column[n].len = t.len;
	knh_Bytes_write(ctx, DP(o)->databuf, t);
	int i, c = t.len % sizeof(void*);
	for(i = 0; i < c; i++) knh_Bytes_putc(ctx, DP(o)->databuf, 0);    /* zero */
}

/* ------------------------------------------------------------------------ */

KMETHOD ResultSet_setNULL(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	DP(o)->column[n].ctype = knh_ResultSet_CTYPE__null;
	DP(o)->column[n].start = BA_size(DP(o)->databuf);
	DP(o)->column[n].len = 0;
}

/* ------------------------------------------------------------------------ */

knh_int_t knh_ResultSet_getInt(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
	switch(DP(o)->column[n].ctype) {
	case knh_ResultSet_CTYPE__null :
		return 0;
	case knh_ResultSet_CTYPE__integer :
		return (knh_int_t)(*((knh_int_t*)p));
	case knh_ResultSet_CTYPE__float :
		return (knh_int_t)(*((knh_float_t*)p));
	case knh_ResultSet_CTYPE__bytes :
		TODO();
//		return knh_bytes_toint(B2(p, DP(o)->column[n].len));
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

knh_float_t knh_ResultSet_getFloat(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
	switch(DP(o)->column[n].ctype) {
	case knh_ResultSet_CTYPE__null :
		return K_FLOAT_ZERO;
	case knh_ResultSet_CTYPE__integer :
		return (knh_float_t)(*((knh_int_t*)p));
	case knh_ResultSet_CTYPE__float :
		return (knh_float_t)(*((knh_float_t*)p));
	case knh_ResultSet_CTYPE__bytes :
		TODO();
//		return knh_bytes_tofloat(B2(p, DP(o)->column[n].len));
	}
	return K_FLOAT_ZERO;
}

/* ------------------------------------------------------------------------ */

static knh_String_t *new_String__int(CTX ctx, knh_int_t n)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_ifmt(ctx, cwb->w, K_INT_FMT, n);
	return CWB_newString0(ctx, cwb);
}

static knh_String_t *new_String__float(CTX ctx, knh_float_t n)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_ffmt(ctx, cwb->w, K_FLOAT_FMT, n);
	return CWB_newString0(ctx, cwb);
}

/* ------------------------------------------------------------------------ */

knh_String_t* knh_ResultSet_getString(CTX ctx, knh_ResultSet_t *o, size_t n)
{
	KNH_ASSERT(n < DP(o)->column_size);
	const char *p = BA_totext(DP(o)->databuf) + DP(o)->column[n].start;
	switch(DP(o)->column[n].ctype) {
	case knh_ResultSet_CTYPE__integer :
		return new_String__int(ctx, (knh_int_t)(*((knh_int_t*)p)));
	case knh_ResultSet_CTYPE__float :
		return new_String__float(ctx, (knh_float_t)(*((knh_float_t*)p)));
	case knh_ResultSet_CTYPE__text : {
		knh_bytes_t t = {{p}, DP(o)->column[n].len};
		return new_S(t.text, t.len);
		}
	case knh_ResultSet_CTYPE__null :
		break;
	}
	return KNH_TNULL(String);
}

/* ------------------------------------------------------------------------ */
/* [DEFAPI] */
static void Connection_init(CTX ctx, knh_RawPtr_t *po)
{
	knh_Connection_t *o = (knh_Connection_t *)po;
	KNH_INITv(o->urn, KNH_NULL);
	//knh_Connection_open(ctx, o, "");
}

static void Connection_free(CTX ctx, knh_RawPtr_t *po)
{
	knh_Connection_t *c = (knh_Connection_t *)po;
	KNH_FREE(ctx, c->urn->str.ubuf, KNH_SIZE(S_size(c->urn) + 1));
	KNH_FREE(ctx, c, sizeof(knh_Object_t));
}

void mysql_qcurfree(knh_qcur_t* qcur)
{
}

#define RESULTSET_BUFSIZE 256

static void ResultSet_init(CTX ctx, knh_RawPtr_t *po)
{
	knh_ResultSet_t *o = (knh_ResultSet_t *)po;
	knh_ResultSetEX_t *b;
#ifdef K_USING_BMGC
	b = DP(o);
#else
	b = (knh_ResultSetEX_t*)KNH_MALLOC(ctx, sizeof(knh_ResultSet_t));
	o->b = b;
#endif
	b->qcur = NULL;
	b->column_size = 0;
	b->column = NULL;
	KNH_INITv(b->databuf, new_Bytes(ctx, NULL, RESULTSET_BUFSIZE));
	KNH_INITv(b->conn, KNH_NULL);
	b->qcurfree = NULL;
	b->count = 0;
}

static void ResultSet_free(CTX ctx, knh_RawPtr_t *po)
{
	knh_ResultSet_t *rs = (knh_ResultSet_t *)po;
	if (DP(rs) != NULL && DP(rs)->column_size > 0) {
		KNH_FREE(ctx, DP(rs)->column, sizeof(knh_dbschema_t) * DP(rs)->column_size);
	}
	KNH_FREE(ctx, DP(rs), sizeof(knh_ResultSetEX_t));
	KNH_FREE(ctx, rs, sizeof(knh_Object_t));
}

DEFAPI(void) defConnection(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Connection";
	cdef->init = Connection_init;
	cdef->free = Connection_free;
}

DEFAPI(void) defResultSet(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "ResultSet";
	cdef->init = ResultSet_init;
	cdef->free = ResultSet_free;
}
#ifdef __cplusplus
}
#endif
