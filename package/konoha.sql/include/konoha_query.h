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

//#define USE_cwb_open      1
//
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

#define K_USING_MYSQL

#ifdef K_USING_MYSQL
#include <mysql.h>
#endif

/* ======================================================================== */
/* [struct] */
/* ------------------------------------------------------------------------ */
/* [Channel] */

//typedef struct knh_Channel_t {
//	kObjectHeader h;
//	kintptr_t sd;
//	struct kString *urn;
//	struct kInputStream  *in;
//	struct kOutputStream *out;
//} knh_Channel_t;
/* ------------------------------------------------------------------------ */
/* [Connection] */

struct _knh_QueryDPI_t;

typedef struct kConnection {
	kObjectHeader h;
	kconn_t              *conn;
	struct _knh_QueryDPI_t   *dspi;
	kString             *urn;
} kConnection;
/* ------------------------------------------------------------------------ */
/* [ResultSet] */

typedef struct {
	ktype_t type;
	kushort_t ctype;
	kString *name;
	size_t start;
	size_t len;
	int dbtype;
} kDBschema;

typedef void kqcur_t;

typedef struct {
	kConnection *conn;
	kqcur_t              *qcur;
	void   (*qcurfree)(kqcur_t *); /* necessary if conn is closed before */
	kString            *tableName;
	kclass_t              tcid;
	kushort_t             column_size;
	kDBschema          *column;
	kBytes             *databuf;
	size_t                   count;
} kResultSetEX;

typedef struct kResultSet {
	kObjectHeader h;
	kResultSetEX KNH_EX_REF b;
} kResultSet;

/* ------------------------------------------------------------------------ */
/* [prototype define] */

void knh_Connection_open(CTX ctx, kConnection *c, kString *urn);
void knh_Connection_close(CTX ctx, kConnection *c);
kbool_t knh_ResultSet_next(CTX ctx, kResultSet *o);
kString *knh_ResultSet_getName(CTX ctx, kResultSet *o, size_t n);
int knh_ResultSet_findColumn(CTX ctx, kResultSet *o, kbytes_t name);
kString* knh_ResultSet_getString(CTX ctx, kResultSet *o, size_t n);
void knh_ResultSet_close(CTX ctx, kResultSet *o);

KMETHOD knh_ResultSet_initColumn(CTX ctx, kResultSet *o, size_t column_size);
KMETHOD ResultSet_setBlob(CTX ctx, kResultSet *o, size_t n, kbytes_t t);
KMETHOD ResultSet_setFloat(CTX ctx, kResultSet *rs, size_t n, kfloat_t value);
KMETHOD ResultSet_setInt(CTX ctx, kResultSet *rs, size_t n, kint_t value);
KMETHOD ResultSet_setNULL(CTX ctx, kResultSet *o, size_t n);
KMETHOD ResultSet_setName(CTX ctx, kResultSet *o, size_t n, kString *name);
KMETHOD ResultSet_setText(CTX ctx, kResultSet *o, size_t n, kbytes_t t);

kconn_t *MYSQL_qopen(CTX ctx, kbytes_t url);
int MYSQL_qnext(CTX ctx, kqcur_t *qcur, struct kResultSet *rs);
kqcur_t *MYSQL_query(CTX ctx, kconn_t *hdr, kbytes_t sql, struct kResultSet *rs);
void MYSQL_qclose(CTX ctx, kconn_t *hdr);
void MYSQL_qfree(kqcur_t *qcur);
/* ------------------------------------------------------------------------ */
/* [driver] */
/* [TODO] ResultSet driver is global value */
/* but it should be shared using anything without global value */

typedef struct knh_ResultSetDef_t {
	KMETHOD (*initColumn)(CTX ctx, kResultSet *o, size_t column_size);
	KMETHOD (*setBlob)(CTX ctx, kResultSet *o, size_t n, kbytes_t t);
	KMETHOD (*setFloat)(CTX ctx, kResultSet *rs, size_t n, kfloat_t value);
	KMETHOD (*setInt)(CTX ctx, kResultSet *rs, size_t n, kint_t value);
	KMETHOD (*setNULL)(CTX ctx, kResultSet *o, size_t n);
	KMETHOD (*setName)(CTX ctx, kResultSet *o, size_t n, kString *name);
	KMETHOD (*setText)(CTX ctx, kResultSet *o, size_t n, kbytes_t t);
} knh_ResultSetDef_t;

static const knh_ResultSetDef_t ResultSetDef = {
	knh_ResultSet_initColumn,
	ResultSet_setBlob,
	ResultSet_setFloat,
	ResultSet_setInt,
	ResultSet_setNULL,
	ResultSet_setName,
	ResultSet_setText,
};
/* ------------------------------------------------------------------------ */
/* K_DSPI_QUERY */

typedef struct _knh_QueryDPI_t {
	int   type;
	const char *name;
	kconn_t* (*qopen)(CTX ctx, kbytes_t);
	kqcur_t* (*qexec)(CTX ctx, kconn_t *, kbytes_t, kResultSet*);
	void   (*qclose)(CTX ctx, kconn_t *);
	int    (*qcurnext)(CTX, kqcur_t *, kResultSet*);
	void   (*qcurfree)(kqcur_t *);
} knh_QueryDSPI_t;

//struct _knh_QueryDPI_t DB__mysql = {
//	K_DSPI_QUERY, "mysql",
//	MYSQL_qopen, MYSQL_query, MYSQL_qclose, MYSQL_qnext, MYSQL_qfree
//};

/* ------------------------------------------------------------------------ */
/* [Macros] */
#define knh_ResultSet_CTYPE__null    0
#define knh_ResultSet_CTYPE__integer 1
#define knh_ResultSet_CTYPE__float   2
#define knh_ResultSet_CTYPE__text    3  /* UTF-8*/
#define knh_ResultSet_CTYPE__bytes   4
#define knh_ResultSet_CTYPE__Object  5

//#define ResultSet_setBlob   ResultSetDef.setBlob
//#define ResultSet_setFloat  ResultSetDef.setFloat
//#define ResultSet_setInt    ResultSetDef.setInt
//#define ResultSet_setNULL   ResultSetDef.setNULL
//#define ResultSet_setName   ResultSetDef.setName
//#define ResultSet_setText   ResultSetDef.setText
/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
