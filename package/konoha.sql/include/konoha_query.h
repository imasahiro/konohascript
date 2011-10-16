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

typedef void knh_qcur_t;

/* ======================================================================== */
/* [struct] */
/* ------------------------------------------------------------------------ */
/* [Channel] */

//typedef struct knh_Channel_t {
//	knh_hObject_t h;
//	knh_intptr_t sd;
//	struct knh_String_t *urn;
//	struct knh_InputStream_t  *in;
//	struct knh_OutputStream_t *out;
//} knh_Channel_t;
/* ------------------------------------------------------------------------ */
/* [Connection] */

struct _knh_QueryDPI_t;

typedef struct knh_Connection_t {
	knh_hObject_t h;
	knh_qconn_t              *conn;
	struct _knh_QueryDPI_t   *dspi;
	knh_String_t             *urn;
} knh_Connection_t;
/* ------------------------------------------------------------------------ */
/* [ResultSet] */

typedef struct {
	knh_type_t type;
	knh_ushort_t ctype;
	knh_String_t *name;
	size_t start;
	size_t len;
	int dbtype;
} knh_dbschema_t;

typedef struct {
	struct knh_Connection_t *conn;
	knh_qcur_t              *qcur;
	void   (*qcurfree)(knh_qcur_t *); /* necessary if conn is closed before */
	knh_String_t            *tableName;
	knh_class_t              tcid;
	knh_ushort_t             column_size;
	knh_dbschema_t          *column;
	knh_Bytes_t             *databuf;
	size_t                   count;
} knh_ResultSetEX_t;

typedef struct knh_ResultSet_t {
	knh_hObject_t h;
	knh_ResultSetEX_t *b;
} knh_ResultSet_t;

/* ------------------------------------------------------------------------ */
/* [prototype define] */

void knh_Connection_open(CTX ctx, knh_Connection_t *c, knh_String_t *urn);
void knh_Connection_close(CTX ctx, knh_Connection_t *c);
knh_bool_t knh_ResultSet_next(CTX ctx, knh_ResultSet_t *o);
knh_String_t *knh_ResultSet_getName(CTX ctx, knh_ResultSet_t *o, size_t n);
int knh_ResultSet_findColumn(CTX ctx, knh_ResultSet_t *o, knh_bytes_t name);
knh_String_t* knh_ResultSet_getString(CTX ctx, knh_ResultSet_t *o, size_t n);
void knh_ResultSet_close(CTX ctx, knh_ResultSet_t *o);

KMETHOD knh_ResultSet_initColumn(CTX ctx, knh_ResultSet_t *o, size_t column_size);
KMETHOD ResultSet_setBlob(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t);
KMETHOD ResultSet_setFloat(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_float_t value);
KMETHOD ResultSet_setInt(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_int_t value);
KMETHOD ResultSet_setNULL(CTX ctx, knh_ResultSet_t *o, size_t n);
KMETHOD ResultSet_setName(CTX ctx, knh_ResultSet_t *o, size_t n, knh_String_t *name);
KMETHOD ResultSet_setText(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t);
/* ------------------------------------------------------------------------ */
/* [driver] */
/* [TODO] ResultSet driver is global value */
/* but it should be shared using anything without global value */

typedef struct knh_ResultSetDef_t {
	KMETHOD (*initColumn)(CTX ctx, knh_ResultSet_t *o, size_t column_size);
	KMETHOD (*setBlob)(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t);
	KMETHOD (*setFloat)(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_float_t value);
	KMETHOD (*setInt)(CTX ctx, knh_ResultSet_t *rs, size_t n, knh_int_t value);
	KMETHOD (*setNULL)(CTX ctx, knh_ResultSet_t *o, size_t n);
	KMETHOD (*setName)(CTX ctx, knh_ResultSet_t *o, size_t n, knh_String_t *name);
	KMETHOD (*setText)(CTX ctx, knh_ResultSet_t *o, size_t n, knh_bytes_t t);
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
	knh_qconn_t* (*qopen)(CTX ctx, knh_bytes_t);
	knh_qcur_t* (*qexec)(CTX ctx, knh_qconn_t *, knh_bytes_t, knh_ResultSet_t*);
	void   (*qclose)(CTX ctx, knh_qconn_t *);
	int    (*qcurnext)(CTX, knh_qcur_t *, knh_ResultSet_t*);
	void   (*qcurfree)(knh_qcur_t *);
} knh_QueryDSPI_t;

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
/* [inlinelibs] */

static inline knh_bytes_t new_bytes2(const char *text, size_t len)
{
	knh_bytes_t v;
	v.text = text;
	v.len = len;
	return v;
}

#ifdef __cplusplus
}
#endif
