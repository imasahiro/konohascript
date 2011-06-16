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

#ifndef KONOHA_GLUE_H_
#define KONOHA_GLUE_H_

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* driver */

typedef const struct {
	int   type;
	const char *name;
} knh_DSPI_t ;

#define K_DSPI_PATH             1
#define K_DSPI_CONVTO           2
#define K_DSPI_CONVFROM         3
#define K_DSPI_STREAM           4
#define K_DSPI_REGEX            5
#define K_DSPI_QUERY            6
#define K_DSPI_MAP              7

#define IS_DSPI(c)   (0 < c && c < 8)
#define K_DEFAULT_DSPI          STEXT("")

/* ------------------------------------------------------------------------ */
/* K_DSPI_PATH */


/* ------------------------------------------------------------------------ */
/* K_BCONV_DSPI */

typedef struct knh_ConvDSPI_t {
	int  type;
	const char *name;
	knh_conv_t* (*open)(CTX, const char*, const char*);
	knh_bool_t (*conv)(CTX, knh_conv_t *, knh_bytes_t t, knh_Bytes_t *);
	knh_bool_t (*enc)(CTX, knh_conv_t *, knh_bytes_t t, knh_Bytes_t *);
	knh_bool_t (*dec)(CTX, knh_conv_t *, knh_bytes_t t, knh_Bytes_t *);
	knh_bool_t (*sconv)(CTX, knh_conv_t *, knh_bytes_t t, knh_Bytes_t *);
	void (*close)(CTX ctx, knh_conv_t*);
	void (*setparam)(CTX ctx, knh_conv_t *, void *, void *);
} knh_ConvDSPI_t;

/* ------------------------------------------------------------------------ */
/* K_DSPI_STREAM */

#ifdef PATH_MAX
#define K_PATHMAX PATH_MAX
#else
#define K_PATHMAX 256
#endif

#define K_OUTBUF_MAXSIZ      (512L * 1024 * 1024)  // 512Mb

typedef struct knh_StreamDPI_t {
	int type;
	const char *name;
	size_t wbufsiz;  // write bufsize
	knh_io_t (*fopenSPI)(CTX, const char*, const char *);
	knh_io_t (*wopenSPI)(CTX, const char*, const char *);
	knh_intptr_t (*freadSPI)(CTX, knh_io_t, char *, size_t);
	knh_intptr_t (*fwriteSPI)(CTX, knh_io_t, const char *, size_t);
	void (*fcloseSPI)(CTX, knh_io_t);
} knh_StreamDPI_t;

/* ------------------------------------------------------------------------ */
/* K_DSPI_QUERY */

typedef struct knh_QueryDPI_t {
	int   type;
	const char *name;
	knh_qconn_t* (*qopen)(CTX ctx, knh_bytes_t);
	knh_qcur_t* (*qexec)(CTX ctx, knh_qconn_t *, knh_bytes_t, knh_ResultSet_t*);
	void   (*qclose)(CTX ctx, knh_qconn_t *);
	int    (*qcurnext)(CTX, knh_qcur_t *, knh_ResultSet_t*);
	void   (*qcurfree)(knh_qcur_t *);
} knh_QueryDSPI_t;

/* ------------------------------------------------------------------------ */
/* K_DSPI_MAP */

typedef struct knh_MapDSPI_t {
	int   type;
	const char *name;
	const struct knh_MapDSPI_t* (*config)(CTX, knh_class_t, knh_class_t);
	knh_map_t* (*init)(CTX, size_t, const char*, void *);
	void (*reftrace)(CTX, knh_map_t* FTRARG);
	void (*freemap)(CTX, knh_map_t*);
	// main
	knh_bool_t (*get)(CTX, knh_map_t*, knh_sfp_t*, knh_sfp_t *);
	void (*set)(CTX, knh_map_t*, knh_sfp_t *);
	void (*remove)(CTX, knh_map_t*, knh_sfp_t *);
	size_t (*size)(CTX, knh_map_t*);
	knh_bool_t (*next)(CTX, knh_map_t*, knh_mapitr_t *, knh_sfp_t *);
} knh_MapDSPI_t;



/* ------------------------------------------------------------------------ */
/* REGEX_SPI */

#ifndef K_REGEX_MATCHSIZE
#define K_REGEX_MATCHSIZE    16
#endif

typedef struct {
	int rm_so;   /* start of match */
	int rm_eo;   /* end of match */
	knh_bytes_t rm_name;  /* {NULL, 0}, if not NAMED */
} knh_regmatch_t;

typedef struct knh_RegexSPI_t {
	const char *name;
	knh_regex_t* (*regmalloc)(CTX, knh_String_t *);
	int (*parse_cflags)(CTX, const char *opt);
	int (*parse_eflags)(CTX, const char *opt);
	int (*regcomp)(CTX, knh_regex_t *, const char *, int);
	int (*regexec)(CTX, knh_regex_t *, const char *, size_t, knh_regmatch_t*, int);
	size_t (*regerror)(int, knh_regex_t *, char *, size_t);
	void (*regfree)(CTX, knh_regex_t *);
	// this must be defined by uh for named grouping
	int (*regexec2)(CTX, knh_regex_t *, const char *, ...);
} knh_RegexSPI_t;

/* ------------------------------------------------------------------------ */
/* ConstData  */
/* ------------------------------------------------------------------------ */

typedef const struct {
	const char *name;
	knh_int_t ivalue;
} knh_IntData_t;

typedef const struct {
	const char *name;
	knh_float_t fvalue;
} knh_FloatData_t;

typedef const struct {
	const char *name;
	const char *value;
} knh_StringData_t;

typedef const struct {
	const char *name;
	void *ptr;
} knh_NamedPointerData_t;

#define _DATA(s)    (knh_intptr_t)(s)
#define DATA_END      0
#define DATA_STRUCT0   1
#define DATA_CLASS0    2
#define DATA_CPARAM    3
#define DATA_GENERICS  4
#define DATA_EXPT      5
#define DATA_METHOD0   6
#define DATA_METHOD    7
#define DATA_TYPEMAP     8
#define DATA_PARAM     9

typedef knh_intptr_t knh_data_t;

/* ------------------------------------------------------------------------ */

typedef struct knh_PackageLoaderAPI_t {
	/* global */
	void (*loadData)(CTX, const knh_data_t *, knh_ParamArray_t **);
	/* constant */
	void (*loadIntData)(CTX, knh_NameSpace_t *ns, const knh_IntData_t *);
	void (*loadFloatData)(CTX, knh_NameSpace_t *ns, const knh_FloatData_t *);
	void (*loadStringData)(CTX, knh_NameSpace_t *ns, const knh_StringData_t *);
	void (*loadIntClassConst)(CTX, knh_class_t cid, const knh_IntData_t *);
	void (*loadFloatClassConst)(CTX, knh_class_t cid, const knh_FloatData_t *);
	void (*loadStringClassConst)(CTX, knh_class_t cid, const knh_StringData_t *);
	void (*setPackageProperty)(CTX, const char*, const char*);
	void (*setPackageIntProperty)(CTX, const char*, knh_int_t);
	void (*setPackageFloatProperty)(CTX, const char*, knh_float_t);
	/* namespace */
//	void (*setRegexSPI)(CTX, knh_NameSpace_t *ns, const knh_RegexSPI_t *);
	void (*addLinkDPI)(CTX, knh_NameSpace_t *ns, const char*, const knh_LinkDPI_t *);
	void (*addStreamDPI)(CTX, knh_NameSpace_t *ns, const char*, const knh_StreamDPI_t *);
	void (*addQueryDSPI)(CTX, knh_NameSpace_t *ns, const char *, const knh_QueryDSPI_t *);
	void (*addConvDSPI)(CTX, knh_NameSpace_t *ns, const char *, const knh_ConvDSPI_t*);
} knh_PackageLoaderAPI_t;

#define RETURN_PKGINFO(NAME) {\
		static const knh_PackageDef_t pkginfo_ = {K_BUILDID, K_API2_CRC32, NAME};\
		return &pkginfo_;\
	}\

typedef struct {
	size_t buildid;
	size_t crc32;
	const char *name;     /* pacakge name */
} knh_PackageDef_t;

typedef const knh_PackageDef_t* (*knh_Fpkginit)(CTX, const knh_PackageLoaderAPI_t *);
typedef void (*knh_Fpkgload)(CTX, const knh_PackageLoaderAPI_t *, knh_NameSpace_t *ns);
typedef void (*knh_Fclassdef)(CTX, knh_class_t, knh_ClassDef_t*);
typedef void (*knh_Fconstdef)(CTX, knh_class_t, const knh_PackageLoaderAPI_t*);

typedef const knh_LinkDPI_t* (*knh_Flinkdef)(CTX);

/* ------------------------------------------------------------------------ */
/* new version */

#define Boolean_to(T, a)           ((T)a.bvalue)
#define Int_to(T, a)               ((T)a.ivalue)
#define Float_to(T, a)             ((T)a.fvalue)
#define String_to(T, a)            ((T)S_tochar(a.s))
#define StringNull_to(T, a, def)   ((T)(IS_bString(a.o) ? S_tochar(a.s) : def))
#define RawPtr_to(T, a)            ((T)((a.p)->rawptr))
//#define RawPtrNull_to(T, a, def)   (IS_bRawPtr(a.o) ? ((T)((a.p)->rawptr)) : (def))
#define Class_tocid(a)             ((a.c)->cid)

/* ------------------------------------------------------------------------ */
/* closure macros, added by @shinpei_NKT */
#define CLOSURE_start(argc)			   \
  CTX lctx = (CTX)knh_getCurrentContext(); \
  knh_intptr_t thisidx = K_CALLDELTA; \
  BEGIN_LOCAL(lctx, lsfp, thisidx + argc + 1);


#define CLOSURE_putInt(idx, val) \
  lsfp[idx].ivalue = val

#define CLOSURE_putFloat(idx, val) \
  lsfp[idx].fvalue = val

#define CLOSURE_putArg(idx, type, val) \
  CLOSURE_put##type(idx, val)


#define CLOSURE_call(fo) \
  if (fo->baseNULL != NULL) {					\
	KNH_SETv(lctx, fo, fo->baseNULL);			\
  }												\
  klr_setmtdNC(lctx, lsfp[K_MTDIDX], fo->mtd);	\
  KNH_SELFCALL(lctx, lsfp, fo->mtd, K_RTNIDX);


#define CLOSURE_getInt() \
  lsfp[K_RTNIDX].ivalue

#define CLOSURE_getFloat() \
  lsfp[K_RTNIDX].fvalue

#define CLOSURE_getReturn(type) \
  CLOSURE_get##type()


#define CLOSURE_end(exp) \
  END_LOCAL_(lctx, lsfp); \
  exp

/* ------------------------------------------------------------------------ */

#ifdef K_EXPORTS

#define RETURN_(vv) {\
		ctx->spi->setsfpSPI(ctx, sfp+_rix, vv);\
		return; \
	}\

#define RETURNa_(v) {\
		Object *vv_ = (Object*)v;\
		ctx->spi->setsfpSPI(ctx, sfp+_rix, vv_);\
		sfp[_rix].ndata = O_data(vv_);\
		return; \
	}\

#else

#define RETURN_(vv) {\
		KNH_SETv(ctx, sfp[_rix].o, vv);\
		return; \
	}\

#define RETURNa_(v) {\
		Object *vv_ = (Object*)v;\
		KNH_SETv(ctx, sfp[_rix].o, vv_);\
		sfp[_rix].ndata = O_data(vv_);\
		return; \
	}\

#endif

#define RETURNd_(d) {\
		sfp[_rix].ndata = d; \
		return; \
	}\

#define RETURNb_(c) {\
		sfp[_rix].bvalue = c; \
		return; \
	}\

#define RETURNi_(c) {\
		sfp[_rix].ivalue = c; \
		return; \
	}\

#define RETURNf_(c) {\
		sfp[_rix].fvalue = c; \
		return; \
	}\

#define RETURNvoid_() {\
		return; \
	}\


#ifdef K_EXPORTS

#define ITREND_() {\
		ctx->spi->closeItrSPI(ctx, sfp[0].it);\
		return 0; \
	}\

#define ITRNEXT_(vv) {\
		ctx->spi->setsfpSPI(ctx, sfp+rix_, vv);\
		return 1; \
	}\

#else

#define ITREND_() {\
		knh_Iterator_close(ctx, sfp[0].it);\
		return 0; \
	}\

#define ITRNEXT_(vv) {\
		KNH_SETv(ctx, sfp[_rix].o, vv);\
		return 1; \
	}\

#endif

#define ITRNEXTd_(d) {\
		sfp[_rix].ndata = d;\
		return 1; \
	}\

#define ITRNEXTi_(n) {\
		sfp[_rix].ivalue = n;\
		return 1; \
	}\

#define ITRNEXTf_(n) {\
		sfp[_rix].fvalue = n;\
		return 1; \
	}\

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

#endif /*KONOHA_GLUE_H_*/
