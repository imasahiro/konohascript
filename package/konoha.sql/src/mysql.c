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
//  shinpei_nkt  - Shinpei Nakata, Yokohama National University, Japan (ntrace)
// **************************************************************************

#ifdef __cplusplus 
extern "C" {
#endif

#include "../include/konoha_query.h"

#ifdef K_USING_MYSQL

#define MYSQL_USER_MAXLEN 16
#define MYSQL_PASS_MAXLEN 255
#define MYSQL_HOST_MAXLEN 255
#define MYSQL_DBNM_MAXLEN 64

/* ======================================================================== */

/*
static void knh_mysql_perror(CTX ctx, MYSQL *db, int r)
{
//	KNH_SYSLOG(ctx, LOG_WARNING, "MysqlError", "'%s'", mysql_error(db));
}
*/
static inline knh_bytes_t knh_bytes_last(knh_bytes_t t, knh_intptr_t loc)
{
	knh_bytes_t t2 = {{t.text + loc}, t.len - loc};
	return t2;
}
/* ------------------------------------------------------------------------ */
// url mysql://uname:passwd@host:port/dbname

//static knh_qconn_t *MYSQL_qopen(CTX ctx, knh_bytes_t url)
knh_qconn_t *MYSQL_qopen(CTX ctx, knh_bytes_t url)
{
	char *puser, user[MYSQL_USER_MAXLEN+1] = {0};
	char *ppass, pass[MYSQL_PASS_MAXLEN+1] = {0}; // temporary defined
	char *phost, host[MYSQL_HOST_MAXLEN+1] = {0};
	unsigned int port = 0;
	char *pdbnm, dbnm[MYSQL_DBNM_MAXLEN+1] = {0};
	
	knh_bytes_t bt = knh_bytes_last(url, 8); // skip: mysql://
	const char *btstr = bt.text;
	sscanf(btstr, "%16[^ :\r\n\t]:%255[^ @\r\n\t]@%255[^ :\r\n\t]:%5d/%64[^ \r\n\t]",
		   (char*)&user, (char*)&pass, (char*)&host, &port, (char*)&dbnm); // consider to buffer over run
	
	puser = (user[0]) ? user : NULL;
	ppass = (pass[0]) ? pass : NULL;
	phost = (host[0]) ? host : NULL;
	pdbnm = (dbnm[0]) ? dbnm : NULL;
	
	MYSQL *db = mysql_init(NULL);
	knh_ldata_t ldata[] = {LOG_END};
	KNH_NTRACE(ctx, "mysql_init", (db != NULL) ? K_OK : K_FAILED, ldata);
	knh_ldata_t ldata2[] = {LOG_s("host", phost), LOG_s("user", puser), /* LOG_s("passwd", ppass), */
							LOG_s("dbname", pdbnm), LOG_i("port", port), LOG_i("errno", mysql_errno(db)), 
							LOG_s("error", mysql_error(db)), LOG_END};
	db = mysql_real_connect(db, phost, puser, ppass, pdbnm, port, NULL, 0);
	KNH_NTRACE(ctx, "mysql_real_connect", (db != NULL) ? K_OK : K_FAILED, ldata2);
	/*	if (!mysql_real_connect(db, phost, puser, ppass, pdbnm, port, NULL, 0)) {
		knh_mysql_perror(ctx, db, 0);
		mysql_close(db);
		db = NULL;
		}*/
	return (knh_qconn_t*)db;
}
/* ------------------------------------------------------------------------ */

static inline knh_bytes_t new_bytes(char *c_buf)
{
	DBG_ASSERT(c_buf != NULL);
	knh_bytes_t t;
	t.ubuf = (knh_uchar_t*)c_buf;
	t.len = knh_strlen(t.text);
	return t;
}

//static int MYSQL_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
int MYSQL_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
{
	MYSQL_ROW row;
	knh_ldata_t ldata[] = {LOG_END};
	if ((row = mysql_fetch_row((MYSQL_RES*)qcur)) != NULL) {
		KNH_NTRACE(ctx, "mysql_fetch_row", K_OK, ldata);
		int i;		
		knh_int_t ival;
		knh_float_t fval;
		for (i = 0; i < DP(rs)->column_size; i++) {
			if (row[i] == NULL) {
				ResultSet_setNULL(ctx, rs, i);
				continue;
			}
			switch (DP(rs)->column[i].dbtype) {
			case MYSQL_TYPE_TINY:			case MYSQL_TYPE_SHORT:
			case MYSQL_TYPE_INT24:			case MYSQL_TYPE_LONG:
			//case MYSQL_TYPE_LONGLONG:
			case MYSQL_TYPE_YEAR:
				knh_bytes_parseint(B(row[i]), &ival);
				ResultSet_setInt(ctx, rs, i, ival);
				break;
			case MYSQL_TYPE_FLOAT:			case MYSQL_TYPE_DOUBLE:
				knh_bytes_parsefloat(B(row[i]), &fval);
				ResultSet_setFloat(ctx, rs, i, fval);
				break;
			case MYSQL_TYPE_NEWDECIMAL:			case MYSQL_TYPE_STRING:
			case MYSQL_TYPE_VAR_STRING:			case MYSQL_TYPE_TINY_BLOB:
			case MYSQL_TYPE_BLOB:			case MYSQL_TYPE_MEDIUM_BLOB:
			case MYSQL_TYPE_LONG_BLOB:			case MYSQL_TYPE_BIT:
			case MYSQL_TYPE_TIME:			case MYSQL_TYPE_DATE:
			case MYSQL_TYPE_DATETIME:			case MYSQL_TYPE_TIMESTAMP:
				ResultSet_setText(ctx, rs, i, B(row[i]));
				break;
			case MYSQL_TYPE_NULL:
			default:
				//KNH_SYSLOG(ctx, LOG_WARNING, "mysql", "mysql_qnext(dbtype)='unknown datatype [%d]'", DP(rs)->column[i].dbtype);
				ResultSet_setNULL(ctx, rs, i);
				break;
			}
		} /* for */
		return 1; /* CONTINUE */
	} else {
		KNH_NTRACE(ctx, "mysql_fetch_row", K_FAILED, ldata);
	}
	return 0; /* NOMORE */
}
/* ------------------------------------------------------------------------ */

//static knh_qcur_t *MYSQL_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
knh_qcur_t *MYSQL_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
{
	MYSQL_RES *res = NULL;
	MYSQL *db = (MYSQL*)hdr;
	if (db == NULL) {
		/* return NULL */
	}
	else if (rs == NULL) {
		/* Connection.exec */
		int r = mysql_query(db, sql.text);
		knh_ldata_t ldata[] = {LOG_s("query", sql.text), LOG_i("errno", mysql_errno(db)), LOG_END};
		KNH_NTRACE(ctx, "mysql_query", (r == 0) ? K_OK : K_FAILED, ldata);
		/*if(r > 0) {
			knh_mysql_perror(ctx, (MYSQL*)db, r);
			}*/
	}
	else {
		/* Connection.query */
		int r = mysql_query((MYSQL*)db, sql.text);
		knh_ldata_t ldata[] = {LOG_s("query", sql.text), LOG_i("errno", mysql_errno(db)),
							   LOG_s("error", mysql_error(db)), LOG_END};
		KNH_NTRACE(ctx, "mysql_query", (r == 0) ? K_OK : K_FAILED, ldata);
		if (r == 0) { 
			res = mysql_store_result((MYSQL*)db);
			knh_ldata_t ldata2[] = {LOG_i("errno", mysql_errno(db)), LOG_s("error", mysql_error(db)),
									LOG_END};
			if (res == NULL) { // NULL RESULT
				if (mysql_errno(db) != 0) {
				  mysql_free_result(res);
				  KNH_NTRACE(ctx, "mysql_store_result", K_FAILED, ldata2);
				} else {
				  KNH_NTRACE(ctx, "mysql_store_result", K_OK, ldata2);
				}
			}
			else {
				knh_ResultSet_initColumn(ctx, rs, (size_t)mysql_num_fields(res));
				KNH_NTRACE(ctx, "mysql_store_result", K_OK, ldata2);
				int i = 0;
				MYSQL_FIELD *field = NULL;
				while((field = mysql_fetch_field(res))) {
					DP(rs)->column[i].dbtype = field->type;
					knh_String_t *s = new_String(ctx, field->name);
					ResultSet_setName(ctx, rs, i, s);
					i++;
				}
			}
		}
	}
	return (knh_qcur_t *) res;
}
/* ------------------------------------------------------------------------ */

//static void MYSQL_qclose(CTX ctx, knh_qconn_t *hdr)
void MYSQL_qclose(CTX ctx, knh_qconn_t *hdr)
{
	mysql_close((MYSQL*)hdr);
}

/* ------------------------------------------------------------------------ */

//static void MYSQL_qfree(knh_qcur_t *qcur)
void MYSQL_qfree(knh_qcur_t *qcur)
{
	if (qcur != NULL) {
		MYSQL_RES *res = (MYSQL_RES*)qcur;
		mysql_free_result(res);
	}
}

const knh_QueryDSPI_t DB__mysql = {
	K_DSPI_QUERY, "mysql",
	MYSQL_qopen, MYSQL_query, MYSQL_qclose, MYSQL_qnext, MYSQL_qfree
};


/* ------------------------------------------------------------------------ */
/* [DEFAPI] */

//#endif /* MYSQL ifdef */

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.sql");
}

#endif


#endif /* K_USING_MYSQL */
#ifdef __cplusplus 
}
#endif
