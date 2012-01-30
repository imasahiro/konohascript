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

#define _RETURN(s)    status = s; goto L_RETURN;

/* ------------------------------------------------------------------------ */
/* [namespace] */

kNameSpace* new_NameSpace(CTX ctx, kNameSpace *parent)
{
	kNameSpace* ns = new_(NameSpace);
	DBG_ASSERT(IS_NameSpace(parent));
	KNH_INITv(ns->parentNULL, parent);
	KNH_SETv(ctx, DP(ns)->nsname, DP(parent)->nsname);
	KNH_SETv(ctx, ns->path, parent->path);
	//LANG_LOG("ns=%p, rpath='%s'", ns, S_totext(ns->path->urn));
	return ns;
}

kclass_t knh_NameSpace_getcid(CTX ctx, kNameSpace *ns, kbytes_t sname)
{
	DBG_ASSERT(IS_NameSpace(ns));
	if(knh_bytes_equals(sname, STEXT("Script"))) {
		return O_cid(K_GMASCR);
	}
	L_TAIL:
	if(DP(ns)->name2ctDictSetNULL != NULL) {
		const knh_ClassTBL_t *ct = (knh_ClassTBL_t*)knh_DictSet_get(ctx, DP(ns)->name2ctDictSetNULL, sname);
		if(ct != NULL) return ct->cid;
	}
	if(ns->parentNULL != NULL) {
		ns = ns->parentNULL;
		goto L_TAIL;
	}
	return knh_getcid(ctx, sname);
}

kbool_t knh_NameSpace_isInsideScope(CTX ctx, kNameSpace *ns, kclass_t cid)
{
	return (knh_bytes_startsWith_(S_tobytes(ClassTBL(cid)->lname), S_tobytes(DP(ns)->nsname)));
}

/* ------------------------------------------------------------------------ */
/* [stmt] */

kflag_t knh_Stmt_flag_(CTX ctx, kStmtExpr *stmt, kbytes_t name, kflag_t flag)
{
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		Object *v = knh_DictMap_getNULL(ctx, DP(stmt)->metaDictCaseMap, name);
		return (v != NULL) ? flag : 0;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */
/* [function] */

//static
//void NameSpace_setFuncClass(CTX ctx, kNameSpace *ns, kmethodn_t mn, kclass_t c)
//{
//	if(!MN_isGETTER(mn) && !MN_isSETTER(mn)) {
//		if(!IS_DictSet(DP(ns)->func2cidDictSet)) {
//			KNH_SETv(ctx, DP(ns)->func2cidDictSet, new_DictSet(ctx, 0));
//		}
//		knh_DictSet_set(ctx, DP(ns)->func2cidDictSet, knh_getFieldName(ctx, MN_toFN(mn)), (kuintptr_t)(c+1));
//	}
//}

/* ------------------------------------------------------------------------ */

kclass_t knh_NameSpace_getFuncClass(CTX ctx, kNameSpace *ns, kmethodn_t mn)
{
//	if(!MN_isGETTER(mn) && !MN_isSETTER(mn)) {
//		kbytes_t name = S_tobytes(knh_getFieldName(ctx, MN_toFN(mn)));
//		L_TAIL:
//		if(DP(ns)->name2ctDictSetNULL != NULL) {
//			const knh_ClassTBL_t *ct = (const knh_ClassTBL_t*)knh_DictSet_get(ctx, DP(ns)->name2ctDictSetNULL, sname);
//			if(ct != NULL) return ct->cid;
//		}
//		if(ns->parentNULL != NULL) {
//			ns = ns->parentNULL;
//			goto L_TAIL;
//		}
//	}
	return CLASS_unknown; /* if not found */
}

ktype_t knh_NameSpace_gettype(CTX ctx, kNameSpace *ns, kbytes_t name)
{
	if(name.utext[0] == 'v') {
		if(name.len == 4 && name.utext[1] == 'o' &&
				name.utext[2] == 'i' && name.utext[3] == 'd') return TYPE_void;
		if(name.len == 3 && name.utext[1] == 'a' && name.utext[2] == 'r') {
			return TYPE_var;
		}
	}
	return knh_NameSpace_getcid(ctx, ns, name);
}

ktype_t kNameSpaceagcid(CTX ctx, kNameSpace *o, kclass_t cid, kbytes_t tag)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	kclass_t bcid = ClassTBL(cid)->bcid;
	knh_printf(ctx, cwb->w, "%C:%B", bcid, tag);
	cid = knh_NameSpace_getcid(ctx, o, CWB_tobytes(cwb));
	CWB_close(ctx, cwb);
	return cid;
}

/* ------------------------------------------------------------------------ */
/* [include] */

static kTerm * new_TermEVALED(CTX ctx)
{
	kTerm *tk = new_(Term);
	TT_(tk) = TT_CONST;
	KNH_SETv(ctx, tk->data, ctx->evaled);
	tk->type = O_cid(ctx->evaled);
	return tk;
}

static void *knh_open_gluelink(CTX ctx, kStmtExpr *stmt, kNameSpace *ns, kbytes_t libname)
{
	void *p = NULL;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_buff_addpath(ctx, cwb->ba, cwb->pos, 0, B(ns->path->ospath));
	knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
	knh_Bytes_putc(ctx, cwb->ba, 0); // to avoid concat;
	p = knh_dlopen(ctx, CWB_totext(ctx, cwb));
	if(p == NULL) {
		kStmtExproERR(ctx, stmt, ERROR_NotFound(ctx, "gluelink", CWB_totext(ctx, cwb)));
	}
	if(p != NULL) {
		knh_Fpkginit pkginit = (knh_Fpkginit)knh_dlsym(ctx, p, "init", libname.text, 1/*isTest*/);
		if(pkginit != NULL) {
			const knh_PackageDef_t *pkgdef = pkginit(ctx, knh_getLoaderAPI());
			if((long)pkgdef->crc32 == (long)K_API2_CRC32) {
				KNH_NTRACE2(ctx, "konoha:opengluelink", K_OK,
						KNH_LDATA(LOG_s("package_name", pkgdef->name),
							LOG_i("package_buildid", pkgdef->buildid),
							LOG_u("package_crc32", pkgdef->crc32)));
			}
			else {
				KNH_NTRACE2(ctx, "konoha:opengluelink", K_FAILED,
						KNH_LDATA(LOG_s("package_name", pkgdef->name),
							LOG_i("package_buildid", pkgdef->buildid),
							LOG_u("package_crc32", pkgdef->crc32)));
				p = NULL;
			}
		}
		else {
			p = NULL;
		}
		if(p == NULL) {
			kStmtExproERR(ctx, stmt, ERROR_NotFound(ctx, "compatible gluelink", CWB_totext(ctx, cwb)));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	CWB_close(ctx, cwb);
	return p;
}

static void *knh_open_ffilink(CTX ctx, kNameSpace *ns, kbytes_t libname)
{
	void *p = NULL;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	libname = CWB_ensure(ctx, cwb, libname, K_PATHMAX);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
	knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
	if(p == NULL && !knh_bytes_startsWith_(libname, STEXT("lib"))) {
		CWB_clear(cwb, 0);
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT("lib"));
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
		knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
		p = knh_dlopen(ctx, CWB_totext(ctx, cwb));
	}
	CWB_close(ctx, cwb);
	return p;
}

static void INCLUDE_ffilink(CTX ctx, kStmtExpr *stmt, kNameSpace *ns, kbytes_t path)
{
	kbytes_t libname = knh_bytes_next(path, ':');
	if(libname.text[0] == '*' || knh_bytes_equals(libname, STEXT("gluelink"))) {
		ns->gluehdr = knh_open_gluelink(ctx, stmt, ns, libname);
	}
	else {
		void *p = knh_open_ffilink(ctx, ns, libname);
		if(p != NULL) {
			if(DP(ns)->ffilinksNULL == NULL) {
				KNH_INITv(DP(ns)->ffilinksNULL, new_Array0(ctx, 0));
			}
			knh_Array_add(ctx, DP(ns)->ffilinksNULL, new_Pointer(ctx, "dl", p, NULL));
			knh_Stmt_done(ctx, stmt);
		}
		else {
			kStmtExproERR(ctx, stmt, ERROR_NotFound(ctx, "library", libname.text));
		}
	}
}

static void NameSpace_beginINCLUDE(CTX ctx, kNameSpace *newns, kNameSpace *oldns)
{
	knh_NameSpaceEX_t *tb = DP(newns);
	void *tdlhdr = newns->gluehdr;
#ifdef K_USING_BMGC
	knh_NameSpaceEX_t tmp;
	knh_memcpy(&tmp, tb, sizeof(knh_NameSpaceEX_t));
	knh_memcpy(DP(newns), DP(oldns), sizeof(knh_NameSpaceEX_t));
	knh_memcpy(DP(oldns), &tmp, sizeof(knh_NameSpaceEX_t));
	newns->gluehdr = oldns->gluehdr;
	oldns->gluehdr = tdlhdr;
#else
	newns->b = oldns->b;
	newns->gluehdr = oldns->gluehdr;
	oldns->b = tb;
	oldns->gluehdr = tdlhdr;
#endif
}

static void NameSpace_endINCLUDE(CTX ctx, kNameSpace *newns, kNameSpace *oldns)
{
	knh_NameSpaceEX_t *tb = DP(newns);
	void *tdlhdr = newns->gluehdr;
#ifdef K_USING_BMGC
	knh_NameSpaceEX_t tmp;
	knh_memcpy(&tmp, tb, sizeof(knh_NameSpaceEX_t));
	knh_memcpy(DP(newns), DP(oldns), sizeof(knh_NameSpaceEX_t));
	knh_memcpy(DP(oldns), &tmp, sizeof(knh_NameSpaceEX_t));
	newns->gluehdr = oldns->gluehdr;
	oldns->gluehdr = tdlhdr;
#else
	newns->b = oldns->b;
	newns->gluehdr = oldns->gluehdr;
	oldns->b = tb;
	oldns->gluehdr = tdlhdr;
#endif
}

kbool_t knh_NameSpace_include(CTX ctx, kNameSpace *ns, kPath *pth)
{
	kNameSpace *newns = new_NameSpace(ctx, ns);
	KNH_SETv(ctx, ctx->gma->scr->ns, newns);
	NameSpace_beginINCLUDE(ctx, newns, ns);
	kstatus_t res = knh_load(ctx, pth);
	NameSpace_endINCLUDE(ctx, newns, ns);
	KNH_SETv(ctx, ctx->gma->scr->ns, ns);
	return (res == K_CONTINUE);
}

static void SCRIPT_eval(CTX ctx, kStmtExpr *stmt, int isCompileOnly);

static void INCLUDE_file(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkRES = Tn_typing(ctx, stmt, 0, CLASS_Path, 0);
	if(TT_(tkRES) != TT_ERR) {
		if(!Tn_isCONST(stmt, 0)) {
			kStmtExpr *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 0), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				kStmtExproERR(ctx, stmt, tkNN(stmt2, 0));
				return;
			}
			KNH_SETv(ctx, tkNN(stmt, 0), new_TermEVALED(ctx));
		}
		kPath *pth = (kPath*)tkNN(stmt,0)->data;
		if(!knh_NameSpace_include(ctx, K_GMANS, pth)) {
			kStmtExproERR(ctx, stmt, ERROR_NotFound(ctx, "include path:", S_totext(pth->urn)));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	else {
		kStmtExproERR(ctx, stmt, tkRES);
	}
}

static void INCLUDE_eval(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkPATH = tkNN(stmt, 0);
	if(IS_bString(tkPATH->text) && knh_bytes_startsWith_(S_tobytes(tkPATH->text), STEXT("lib:"))) {
		INCLUDE_ffilink(ctx, stmt, K_GMANS, S_tobytes(tkPATH->text));
	}
	else {
		INCLUDE_file(ctx, stmt);
	}
}

/* ------------------------------------------------------------------------ */
/* [package] */

static kbool_t isFoundPackage(CTX ctx, kBytes* ba, size_t pos, kbytes_t tpath, kbytes_t bpath)
{
	knh_Bytes_clear(ba, pos);
	knh_buff_addospath(ctx, ba, pos, 0, tpath);
	knh_buff_addospath(ctx, ba, pos, 1, bpath); // konoha.math
	knh_buff_addospath(ctx, ba, pos, 1, knh_bytes_rnext(bpath, '.')); // math
	knh_buff_addospath(ctx, ba, pos, 0, STEXT(".k"));
	return knh_buff_isfile(ctx, ba, pos);
}

static kbool_t knh_buff_addPackagePath(CTX ctx, kBytes *ba, size_t pos, kbytes_t pkgname)
{
	char *epath = knh_getenv("KONOHA_PACKAGE");
	if(epath != NULL && isFoundPackage(ctx, ba, pos, B(epath), pkgname)) {
		return 1;
	}
	kString *tpath = knh_getPropertyNULL(ctx, STEXT("konoha.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), pkgname)) {
		return 1;
	}
	tpath = knh_getPropertyNULL(ctx, STEXT("user.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), pkgname)) {
		return 1;
	}
	return 0;
}

void knh_Script_setNSName(CTX ctx, kScript* scr, kString *nsname)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	KNH_SETv(ctx, DP(scr->ns)->nsname, nsname);
	knh_Bytes_write(ctx, cwb->ba, S_tobytes(nsname));
	knh_Bytes_write(ctx, cwb->ba, STEXT(".Script"));
	KNH_SETv(ctx, ((knh_ClassTBL_t*)O_cTBL(scr))->lname, CWB_newString(ctx, cwb, SPOL_ASCII));
}

typedef void (*knh_Fpkgcomplete)(CTX);

/* ------------------------------------------------------------------------ */
kstatus_t knh_loadPackage(CTX ctx, kbytes_t pkgname)
{
	kstatus_t status = K_CONTINUE;
	kDictMap *dmap = ctx->share->packageDictMap;
	kScript *scr = (kScript*)knh_DictMap_getNULL(ctx, dmap, pkgname);
	if(scr == NULL) {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		if(knh_buff_addPackagePath(ctx, cwb->ba, cwb->pos, pkgname)) {
			FILE *fp = fopen(CWB_totext(ctx, cwb), "r");
			if(fp != NULL) {
				kString *pname = new_S(pkgname.text, pkgname.len);
				kScript *newscr = new_(Script);
				knh_Script_setNSName(ctx, newscr, pname);
				knh_DictMap_set(ctx, dmap, pname, newscr);
				kuri_t uri = knh_getURI(ctx, CWB_tobytes(cwb));
				kline_t uline = 1;
				ULINE_setURI(uline, uri);
				KNH_SETv(ctx, newscr->ns->path, new_Path(ctx, knh_buff_newRealPathString(ctx, cwb->ba, cwb->pos)));
				/* */
				kInputStream *in = new_InputStream(ctx, new_FILE(ctx, fp, 256), newscr->ns->path);
				DBG_P("rpath='%s'", newscr->ns->path->ospath);
				scr = ctx->gma->scr;
				KNH_SETv(ctx, ctx->gma->scr, newscr);
				status = knh_InputStream_load(ctx, in, uline);
				if (newscr->ns->gluehdr) {
					void *p = newscr->ns->gluehdr;
					knh_Fpkgcomplete pkgcomplete = (knh_Fpkgcomplete) knh_dlsym(ctx, p, "complete", NULL, 1/*isTest*/);
					if (pkgcomplete)
						pkgcomplete(ctx);
				}
				KNH_SETv(ctx, ctx->gma->scr, scr);
			}
		}
		else {
			ERROR_NotFound(ctx, "package", pkgname.text);
			status = K_BREAK;
		}
		CWB_close(ctx, cwb);
	}
	return status;
}

/* ------------------------------------------------------------------------ */

static void NameSpace_setcid(CTX ctx, kNameSpace *ns, kString *name, kclass_t cid)
{
	if(DP(ns)->name2ctDictSetNULL == NULL) {
		KNH_INITv(DP(ns)->name2ctDictSetNULL, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "NameSpace.name2cid"));
	}
	knh_DictSet_set(ctx, DP(ns)->name2ctDictSetNULL, name, (kuintptr_t)ClassTBL(cid));
}

static void NameSpace_setDPI(CTX ctx, kNameSpace *ns, kbytes_t pkgname, kDictSet *ds)
{
	size_t i, size = knh_Map_size(ds);
	for(i = 0; i < size; i++) {
		kString *name = knh_DictSet_keyAt(ds, i);
		kbytes_t key = S_tobytes(name);
		if(key.text[pkgname.len] == '.' && knh_bytes_startsWith_(key, pkgname)) {
			kbytes_t t = knh_bytes_last(key, pkgname.len+1);
			if(knh_bytes_index(t, '.') == -1) {
				knh_DictMap_set(ctx, DP(ns)->name2dpiNameDictMapNULL, new_String2(ctx, CLASS_String, t.text, t.len, SPOL_POOLALWAYS), name);
			}
		}
	}
}

static void NameSpace_addDPI(CTX ctx, kNameSpace *ns, kbytes_t pkgname)
{
	if(DP(ns)->name2dpiNameDictMapNULL == NULL) {
		KNH_INITv(DP(ns)->name2dpiNameDictMapNULL, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "NameSpace.name2dpiName"));
	}
	NameSpace_setDPI(ctx, ns, pkgname, ctx->share->streamDpiDictSet);
	NameSpace_setDPI(ctx, ns, pkgname, ctx->share->mapDpiDictSet);
	NameSpace_setDPI(ctx, ns, pkgname, ctx->share->convDpiDictSet);
}

static int StmtUSINGCLASS_eval(CTX ctx, kStmtExpr *stmt, size_t n)
{
	kTerm *tkPKG = tkNN(stmt, n), *tkN;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Bytes_write(ctx, cwb->ba, S_tobytes((tkPKG)->text));
	while(1) {
		tkN = tkNN(stmt, ++n);
		if(TT_(tkN) == TT_ASIS) break;
		if(TT_(tkN) == TT_DOT) continue;
		if(TT_(tkN) == TT_NAME) {
			knh_Bytes_putc(ctx, cwb->ba, '.');
			knh_Bytes_write(ctx, cwb->ba, S_tobytes((tkN)->text));
			continue;
		}
		break;
	}
	KNH_SETv(ctx, (tkPKG)->data, CWB_newString(ctx, cwb, SPOL_ASCII));
	if(knh_loadPackage(ctx, S_tobytes((tkPKG)->text)) == K_CONTINUE) {
		kNameSpace *ns = K_GMANS;
		if(TT_(tkN) == TT_MUL) {
			kbytes_t pkgname = S_tobytes((tkPKG)->text);
			size_t cid;
			for(cid = 0; cid < ctx->share->sizeClassTBL; cid++) {
				if(ClassTBL(cid)->lname == NULL) continue;
				if(class_isPrivate(cid) && C_isGenerics(cid)) continue;
				kbytes_t cname = S_tobytes(ClassTBL(cid)->lname);
				if(cname.utext[pkgname.len] == '.' && isupper(cname.utext[pkgname.len+1]) && knh_bytes_startsWith_(cname, pkgname)) {
					NameSpace_setcid(ctx, ns, ClassTBL(cid)->sname, (kclass_t)cid);
				}
			}
			NameSpace_addDPI(ctx, ns, pkgname);
		}
		else if(TT_(tkN) == TT_UNAME) {
			kclass_t newcid;
			kString* cname = (tkN)->text;
			CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
			knh_Bytes_write(ctx, cwb->ba, S_tobytes((tkPKG)->text));
			knh_Bytes_putc(ctx, cwb->ba, '.');
			knh_Bytes_write(ctx, cwb->ba, S_tobytes(cname));
			newcid = knh_getcid(ctx, CWB_tobytes(cwb));
			if(newcid == CLASS_unknown) {
				KNH_SETv(ctx, (tkPKG)->data, CWB_newString(ctx, cwb, SPOL_ASCII));
				CWB_close(ctx, cwb);
				goto L_ERROR;
			}
			else {
				NameSpace_setcid(ctx, ns, cname, newcid);
			}
			CWB_close(ctx, cwb);
		}
		knh_Stmt_done(ctx, stmt);
		return 1;
	}
	L_ERROR:;
	while(n + 1 < DP(stmt)->size) {
		if(TT_(tkNN(stmt, n)) == TT_OR) return 0;
		n++;
	}
	kStmtExproERR(ctx, stmt, ERROR_NotFound(ctx, "package", S_totext((tkPKG)->text)));
	return 0;
}

static void USING_eval(CTX ctx, kStmtExpr *stmt)
{
	size_t n = 0;
	L_TRYAGAIN:; {
		kTerm *tkF = tkNN(stmt, n);
		if(TT_(tkF) == TT_NAME) {
			if(StmtUSINGCLASS_eval(ctx, stmt, n)) {
				goto L_RETURN;
			}
		}
	}
	while(n + 1 < DP(stmt)->size) {  // find next or
		kTerm *tkF = tkNN(stmt, n);
		n++;
		if(TT_(tkF) == TT_OR) goto L_TRYAGAIN;
	}
	L_RETURN:;
	if(STT_(stmt) != STT_ERR) {
		knh_Stmt_done(ctx, stmt);
	}
}

/* ------------------------------------------------------------------------ */

static kMethod *Script_getEvalMethod(CTX ctx, kScript *scr, ktype_t it_type)
{
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, O_cid(scr), MN_);
	if(mtd == NULL) {
		kParam *pa = new_(Param);
		knh_Param_addParam(ctx, pa, it_type, FN_it);
		knh_Param_addReturnType(ctx, pa, TYPE_void);
		mtd = new_Method(ctx, FLAG_Method_Hidden, O_cid(scr), MN_LAMBDA, NULL);
		KNH_SETv(ctx, DP(mtd)->mp, pa);
		knh_NameSpace_addMethod(ctx, O_cid(scr), mtd);
	}
	else {
		kparam_t *p = knh_Param_get(DP(mtd)->mp, 0);
		p->type = it_type;
		//p = knh_Param_rget(DP(mtd)->mp, 0);
		/*p->type = TYPE_void;*/
	}
	return mtd;
}

void SCRIPT_asm(CTX ctx, kStmtExpr *stmtITR);

static void SCRIPT_eval(CTX ctx, kStmtExpr *stmtORIG, int isCompileOnly)
{
	BEGIN_LOCAL(ctx, lsfp, 5);
	kScript *scr = K_GMASCR;
	kclass_t cid =  O_cid(ctx->evaled);
	kMethod *mtd = Script_getEvalMethod(ctx, scr, cid);
	kStmtExpr *stmt = stmtORIG;
	WCTX(ctx)->isEvaled = 0;
	if(STT_isExpr(STT_(stmt)) && STT_(stmt) != STT_LET) {
		stmt = new_Stmt2(ctx, STT_RETURN, stmt, NULL);
	}
	if(STT_(stmt) == STT_RETURN) {
		Stmt_setImplicit(stmt, 1);
	}
	KNH_SETv(ctx, lsfp[0].o, stmt);
	// CompilerAPI
	{
		void *compilerAPI = ctx->share->compilerAPI;
		ctx->wshare->compilerAPI = NULL;
		knh_Method_asm(ctx, mtd, stmt, typingMethod2);
		ctx->wshare->compilerAPI = compilerAPI;
	}
	if(STT_(stmt) == STT_ERR) {
		if(stmt != stmtORIG) {
			kStmtExproERR(ctx, stmtORIG, tkNN(stmt, 0));
		}
		END_LOCAL(ctx, lsfp);
		return;
	}
	if(!isCompileOnly) {
		int rtnidx=3+1, thisidx = rtnidx + K_CALLDELTA;
		DP(mtd)->uri = ULINE_uri(stmt->uline);
		KNH_SETv(ctx, lsfp[1+1].o, DP(mtd)->kcode);
		lsfp[thisidx+K_PCIDX].pc = NULL;
		klr_setmtdNC(ctx, lsfp[thisidx+K_MTDIDX], mtd);
		KNH_SETv(ctx, lsfp[thisidx].o, scr);
		KNH_SETv(ctx, lsfp[thisidx+1].o, ctx->evaled);
		lsfp[thisidx+1].ndata = O_data(ctx->evaled);
		klr_setesp(ctx, lsfp + thisidx+2);
		if(knh_VirtualMachine_launch(ctx, lsfp + thisidx)) {
			//DBG_P("returning sfpidx=%d, rtnidx=%d, %s %lld %ld %f", sfpidx_, sfpidx_ + rtnidx, O__(lsfp[rtnidx].o), lsfp[rtnidx].ivalue, lsfp[rtnidx].bvalue, lsfp[rtnidx].fvalue);
			if(STT_(stmt) == STT_RETURN && !Stmt_isImplicit(stmt)) {
				cid = O_cid(lsfp[rtnidx].o);
				KNH_SETv(ctx, WCTX(ctx)->evaled, lsfp[rtnidx].o);
				WCTX(ctx)->isEvaled = 1;
			}
		}
		else {
			KNH_TODO("VirtualMachine return error status");
		}
	}
	knh_Stmt_done(ctx, stmtORIG);
	END_LOCAL(ctx, lsfp);
}

static void StmtITR_eval(CTX ctx, kStmtExpr *stmtITR);

static void IF_eval(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkRES = Tn_typing(ctx, stmt, 0, TYPE_Boolean, 0);
	if(TT_(tkRES) != TT_ERR) {
		int isTrue = 1;
		if(!Tn_isCONST(stmt, 0)) {
			kStmtExpr *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 0), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				kStmtExproERR(ctx, stmt, tkNN(stmt2, 0)); return;
			}
			isTrue = IS_TRUE(ctx->evaled) ? 1 : 0;
		}
		else {
			isTrue = (Tn_isTRUE(stmt, 0)) ? 1: 0;
		}
		kStmtExpr *stmtIN = stmtNN(stmt, isTrue ? 1 : 2);
		StmtITR_eval(ctx, stmtIN);
		if(STT_(stmtIN) == STT_ERR) {
			kStmtExproERR(ctx, stmt, tkNN(stmtIN, 0));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	else {
		kStmtExproERR(ctx, stmt, tkRES);
	}
}

Object *knh_NameSpace_getConstNULL(CTX ctx, kNameSpace *ns, kbytes_t name)
{
	L_TAIL:
	if(DP(ns)->constDictCaseMapNULL != NULL) {
		kindex_t idx = knh_DictMap_index(DP(ns)->constDictCaseMapNULL, name);
		if(idx != -1) return knh_DictMap_valueAt(DP(ns)->constDictCaseMapNULL, idx);
	}
	if(ns->parentNULL != NULL) {
		ns = ns->parentNULL;
		goto L_TAIL;
	}
	return knh_getClassConstNULL(ctx, DP(ctx->gma)->this_cid, name);
}

static void CONST_decl(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkN = tkNN(stmt, 0), *tkRES = NULL;
	kclass_t cid = knh_Term_cid(ctx, tkN, CLASS_unknown);
	kNameSpace *ns = K_GMANS;
	Object *value = knh_NameSpace_getConstNULL(ctx, ns, TK_tobytes(tkN));
	if(cid != CLASS_unknown || value != NULL) {
		WARN_AlreadyDefined(ctx, "const", UPCAST(tkN));
		knh_Stmt_done(ctx, stmt);
		return;
	}
	tkRES = Tn_typing(ctx, stmt, 1, TYPE_dyn, 0);
	if(TT_(tkRES) != TT_ERR) {
		if(Tn_isCONST(stmt, 1)) {
			value = Tn_const(stmt, 1);
		}
		else {
			kStmtExpr *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 1), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				kStmtExproERR(ctx, stmt, tkNN(stmt2, 0)); return;
			}
			value = ctx->evaled;
		}
		if(IS_Class(value)) {
			NameSpace_setcid(ctx, ns, tkN->text, ((kClass*)value)->cid);
		}
		else {
			if(DP(ns)->constDictCaseMapNULL == NULL) {
				KNH_INITv(DP(ns)->constDictCaseMapNULL,
					new_DictMap0(ctx, 0, 1/*isCaseMap*/, "NameSpace.lconstDictMap"));
			}
			knh_DictMap_set_(ctx, DP(ns)->constDictCaseMapNULL, tkN->text, value);
		}
		knh_Stmt_done(ctx, stmt);
	}
	else {
		kStmtExproERR(ctx, stmt, tkRES);
	}
}

//static kstatus_t METHODWITH_eval(CTX ctx, kStmtExpr *stmt)
//{
//	kstatus_t status = K_CONTINUE;
//	if(StmtMETHOD_isFFI(stmt)) {
//		kTerm *tkRES = Tn_typing(ctx, stmt, 4, TYPE_Map, 0);
//		if(TT_(tkRES) != TT_ERR) {
//			if(!Tn_isCONST(stmt, 4)) {
//				kStmtExpr *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 4), NULL);
//				status = SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
//				if(status != K_CONTINUE) return status;
//				KNH_SETv(ctx, tkNN(stmt, 4), new_TermEVALED(ctx));
//			}
//		}
//		else {
//			kStmtExproERR(ctx, stmt, tkRES);
//			return K_BREAK;
//		}
//	}
//	return status;
//}

/* ------------------------------------------------------------------------ */
/* [CLASS] */

static kflag_t knh_StmtCLASS_flag(CTX ctx, kStmtExpr *stmt)
{
	kflag_t flag = 0;
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		flag |= knh_Stmt_flag(ctx, stmt, "Final",     FLAG_Class_Final);
		flag |= knh_Stmt_flag(ctx, stmt, "Singleton", FLAG_Class_Singleton);
		flag |= knh_Stmt_flag(ctx, stmt, "Immutable", FLAG_Class_Immutable);
		flag |= knh_Stmt_flag(ctx, stmt, "Expando",   FLAG_Class_Expando);
	}
	return flag;
}


static void knh_loadNativeClass(CTX ctx, const char *cname, knh_ClassTBL_t *ct)
{
	char fname[256];
	kNameSpace *ns = K_GMANS;
	const kclassdef_t *cdef = NULL;
	if(ns->gluehdr != NULL) {
		knh_snprintf(fname, sizeof(fname), "def%s", cname);
		knh_Fclassdef classdef = (knh_Fclassdef)knh_dlsym(ctx, ns->gluehdr, fname, cname, 0/*isTest*/);
		if(classdef != NULL) {
			kclassdef_t *cdefbuf = (kclassdef_t*)KNH_MALLOC(ctx, sizeof(kclassdef_t));
			knh_memcpy(cdefbuf, knh_getDefaultClassDef(), sizeof(kclassdef_t));
			LANG_LOG("loading glue func: %s", fname);
			classdef(ctx, ct->cid, cdefbuf);
			cdefbuf->asize = sizeof(kclassdef_t);
			cdef = (const kclassdef_t*)cdefbuf;
		}
	}
	if(cdef == NULL) {
		cdef = knh_getCppClassDef(); // this might be C++ Object
		WARN_NotFound(ctx, _("ClassDef function"), fname);
	}
	ct->bcid = ct->cid;
	ct->baseTBL = ct;
	ct->cflag = ct->cflag | cdef->cflag;
	knh_setClassDef(ctx, ct, cdef);
	ct->magicflag = KNH_MAGICFLAG(ct->cflag);
	if(ns->gluehdr != NULL) {
		knh_snprintf(fname, sizeof(fname), "const%s", cname);
		knh_Fconstdef constdef = (knh_Fconstdef)knh_dlsym(ctx, ns->gluehdr, fname, NULL, 0/*isTest*/);
		if(constdef != NULL) {
			LANG_LOG("loading glue func: %s", fname);
			constdef(ctx, ct->cid, knh_getLoaderAPI());
		}
	}
}

/* ------------------------------------------------------------------------ */

static void ClassTBL_inherit(CTX ctx, knh_ClassTBL_t *ct, const knh_ClassTBL_t *supct) {
	ct->supTBL = ClassTBL(ct->supcid);
	ct->keyidx = supct->keyidx;
	ct->xdataidx = supct->xdataidx;
	((knh_ClassTBL_t*)supct)->subclass += 1;
	ct->bcid = supct->bcid;
	ct->baseTBL = ClassTBL(supct->bcid);

}

static knh_ClassTBL_t *CLASSNAME_decl(CTX ctx, kStmtExpr *stmt, kTerm *tkC, kTerm *tkE)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_Bytes_write(ctx, cwb->ba, S_tobytes(DP(K_GMANS)->nsname));
	knh_Bytes_putc(ctx, cwb->ba, '.');
	knh_Bytes_write(ctx, cwb->ba, TK_tobytes(tkC));
	kclass_t cid = knh_getcid(ctx, CWB_tobytes(cwb));
	knh_ClassTBL_t *ct = NULL;
	if(cid == CLASS_unknown) {  // new class //
		cid = new_ClassId(ctx);
		ct = varClassTBL(cid);
		knh_setClassName(ctx, cid, CWB_newString(ctx, cwb, SPOL_ASCII), (tkC)->text);
		ct->cflag  = knh_StmtCLASS_flag(ctx, stmt);
		ct->magicflag  = KNH_MAGICFLAG(ct->cflag);
		NameSpace_setcid(ctx, K_GMANS, (tkC)->text, cid);
		KNH_INITv(ct->methods, K_EMPTYARRAY);
		KNH_INITv(ct->typemaps, K_EMPTYARRAY);

		// class C extends E ..
		if(TT_(tkE) == TT_NEXT) { // class C extends C++
			ct->supcid = CLASS_Tdynamic;
			ClassTBL_inherit(ctx, ct, ClassTBL(ct->supcid));
			knh_setClassDef(ctx, ct, knh_getCppClassDef());
		}
		else {
			ct->supcid = knh_Term_cid(ctx, tkE, CLASS_unknown);
			if(ct->supcid == CLASS_unknown) {
				kStmtExproERR(ctx, stmt, ERROR_Undefined(ctx, "class", ct->supcid, tkE));
				return ct;
			}
			if(class_isFinal(ct->supcid)) {
				kStmtExproERR(ctx, stmt, ERROR_TermIs(ctx, tkE, "final"));
				return ct;
			}
			ClassTBL_inherit(ctx, ct, ClassTBL(ct->supcid));
			knh_setClassDef(ctx, ct, ct->baseTBL->cdef);
		}
	}
	else {
		ct = varClassTBL(cid);
		if(ct->bcid == CLASS_Object || ct->bcid == CLASS_CppObject) {
			if(ct->supTBL->fsize == ct->fsize) goto L_RETURN;  // class C;
		}
		kStmtExproERR(ctx, stmt, ERROR_AlreadyDefined(ctx, "class", (tkC)->data));
	}
	L_RETURN:;
	(tkC)->cid = cid;
	CWB_close(ctx, cwb);
	return ct;
}

static void CLASS_decl(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkC = tkNN(stmt, 0); // CNAME
	kTerm *tkE = tkNN(stmt, 2); // extends
	knh_ClassTBL_t *ct = CLASSNAME_decl(ctx, stmt, tkC, tkE);
	if(STT_(stmt) == STT_ERR) return;
	if(knh_StmtMETA_is(ctx, stmt, "Native")) {
		knh_loadNativeClass(ctx, S_totext((tkC)->text), ct);
	}
	if(ct->protoNULL == NULL && (ct->bcid == CLASS_Object || ct->bcid == CLASS_CppObject)) {
		kObject *nulval = new_hObject_(ctx, ct);
		kObject *defval = new_hObject_(ctx, ct);
		KNH_ASSERT(nulval->fields == NULL);
		KNH_ASSERT(defval->fields == NULL);
		Object_setNullObject(nulval, 1);
		knh_setClassDefaultValue(ctx, ct->cid, nulval, NULL);
		KNH_INITv(ct->protoNULL, defval);
	}
	if(DP(stmt)->size == 4 && TT_(tkNN(stmt, 1)) == TT_ASIS) {
		knh_Stmt_done(ctx, stmt);
	}
}

static void StmtITR_eval(CTX ctx, kStmtExpr *stmtITR)
{
	BEGIN_LOCAL(ctx, lsfp, 3);
	kStmtExpr *stmt = stmtITR;
	KNH_SETv(ctx, lsfp[0].o, stmtITR); // lsfp[1] stmtNEXT
	while(stmt != NULL) {
		kStmtExpr *stmtNEXT = DP(stmt)->nextNULL;
		if(stmtNEXT != NULL) {
			KNH_SETv(ctx, lsfp[1].o, stmt);
			KNH_SETv(ctx, lsfp[2].o, stmtNEXT);
			KNH_FINALv(ctx, DP(stmt)->nextNULL);
			DP(stmt)->nextNULL = NULL;
		}
		ctx->gma->uline = stmt->uline;
		switch(STT_(stmt)) {
		case STT_NAMESPACE:
		{
			kNameSpace *ns = new_NameSpace(ctx, K_GMANS);
			kStmtExpr *stmtIN = stmtNN(stmt, 0);
			KNH_SETv(ctx, K_GMANS, ns);
			StmtITR_eval(ctx, stmtIN);
			DBG_ASSERT(K_GMANS == ns);
			DBG_ASSERT(ns->parentNULL != NULL);
			KNH_SETv(ctx, K_GMANS, ns->parentNULL);
			if(STT_(stmtIN) == STT_ERR) {
				kStmtExproERR(ctx, stmtITR, tkNN(stmtIN, 0));
				goto L_RETURN;
			}
			knh_Stmt_done(ctx, stmt);
			break;
		}
		case STT_IF: /* Conditional Compilation */
			IF_eval(ctx, stmt); break;
		case STT_INCLUDE:
			INCLUDE_eval(ctx, stmt); break;
		case STT_USING:
			USING_eval(ctx, stmt); break;
		case STT_CLASS:
			CLASS_decl(ctx, stmt); break;
//		case STT_METHOD:  /* with clause */
//			status = METHODWITH_eval(ctx, stmt); break;
		case STT_CONST:
			CONST_decl(ctx, stmt); break;
		case STT_BREAK:
			knh_Stmt_done(ctx, stmt);
			goto L_RETURN;
		}
		if(STT_(stmt) == STT_ERR) {
			if(stmt != stmtITR) {
				kStmtExproERR(ctx, stmtITR, tkNN(stmt, 0));
			}
			goto L_RETURN;
		}
		if(STT_(stmt) != STT_DONE) {
			SCRIPT_typing(ctx, stmt);
			SCRIPT_asm(ctx, stmt);
		}
		if(STT_(stmt) != STT_DONE) {
			SCRIPT_eval(ctx, stmt, knh_isCompileOnly(ctx));
			if(STT_(stmt) == STT_ERR) {
				if(stmt != stmtITR) {
					kStmtExproERR(ctx, stmtITR, tkNN(stmt, 0));
				}
				goto L_RETURN;
			}
		}
		stmt = stmtNEXT;
	}

	L_RETURN:;
	END_LOCAL(ctx, lsfp);
	ctx->gma->uline = 0;
}

#ifdef K_USING_SUGAR

kbool_t knh_beval2(CTX ctx, const char *script, kline_t uline)
{
	kbool_t tf;
	INIT_GCSTACK(ctx);
	kStmtExpr *stmt = knh_parseStmt(ctx, script, uline);
	WCTX(ctx)->isEvaled = 0;
	StmtITR_eval(ctx, stmt);
	tf = (STT_(stmt) != STT_ERR);
	RESET_GCSTACK(ctx);
	return tf;
}

#else
kbool_t knh_beval(CTX ctx, kInputStream *in, kline_t uline)
{
	BEGIN_LOCAL(ctx, lsfp, 2);
	kbool_t tf;
	KNH_SETv(ctx, lsfp[0].o, in);
	LOCAL_NEW(ctx, lsfp, 1, kStmtExpr *, stmt, knh_InputStream_parseStmt(ctx, in, &uline));
	WCTX(ctx)->isEvaled = 0;
	StmtITR_eval(ctx, stmt);
	tf = (STT_(stmt) != STT_ERR);
	END_LOCAL(ctx, lsfp);
	return tf;
}

#endif

KNHAPI2(kbool_t) knh_eval(CTX ctx, const char *script, kline_t uline, kOutputStream *w)
{
#ifdef K_USING_SUGAR
	KNH_SETv(ctx, ((kcontext_t*)ctx)->e, KNH_NULL);
	kbool_t tf = knh_beval2(ctx, script, uline);
	if(w != NULL && tf && ctx->isEvaled == 1) {
		knh_write_Object(ctx, w, ctx->evaled, FMT_dump);
	}
#else
	kInputStream *bin = new_BytesInputStream(ctx, script, knh_strlen(script));
	KNH_SETv(ctx, ((kcontext_t*)ctx)->e, KNH_NULL);
	kbool_t tf = knh_beval(ctx, bin, uline);
	if(w != NULL && ctx->isEvaled == 1) {
		knh_write_Object(ctx, w, ctx->evaled, FMT_dump);
	}
#endif
	return tf;

}

/* ------------------------------------------------------------------------ */

static int bytes_isempty(kbytes_t t)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if(!isspace(t.utext[i])) return 0;
	}
	return 1;
}

static kline_t Bytes_addQUOTE(CTX ctx, kBytes *ba, kInputStream *in, int quote, kline_t line)
{
	int ch, prev = quote;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		if(ch == '\n') line++;
		knh_Bytes_putc(ctx, ba, ch);
		if(ch == quote && prev != '\\') {
			return line;
		}
		prev = ch;
	}
	return line;
}

static kline_t Bytes_addCOMMENT(CTX ctx, kBytes *ba, kInputStream *in, kline_t line)
{
	int ch, prev = 0, level = 1;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		if(ch == '\n') line++;
		knh_Bytes_putc(ctx, ba, ch);
		if(prev == '*' && ch == '/') level--;
		if(prev == '/' && ch == '*') level++;
		if(level == 0) return line;
		prev = ch;
	}
	return line;
}

static kline_t readchunk(CTX ctx, kInputStream *in, kline_t line, kBytes *ba)
{
	int ch;
	int prev = 0, isBLOCK = 0;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		if(ch == '\n') line++;
		knh_Bytes_putc(ctx, ba, ch);
		if(prev == '/' && ch == '*') {
			line = Bytes_addCOMMENT(ctx, ba, in, line);
			continue;
		}
		if(ch == '\'' || ch == '"' || ch == '`') {
			line = Bytes_addQUOTE(ctx, ba, in, ch, line);
			continue;
		}
		if(isBLOCK != 1 && prev == '\n' && ch == '\n') {
			break;
		}
		if(prev == '{') {
			isBLOCK = 1;
		}
		if(prev == '\n' && ch == '}') {
			isBLOCK = 0;
		}
		prev = ch;
	}
	return line;
}

#ifdef K_USING_SUGAR
kstatus_t knh_InputStream_load(CTX ctx, kInputStream *in, kline_t uline)
{
	kstatus_t status = K_BREAK;
	kBytes*ba = new_Bytes(ctx, "chunk", K_PAGESIZE);
	PUSH_GCSTACK(ctx, ba);
	kline_t linenum = uline;
	do {
		knh_Bytes_clear(ba, 0);
		if(!io2_isClosed(ctx, in->io2)) {
			status = K_CONTINUE;
			uline = linenum;
			linenum = readchunk(ctx, in, linenum, ba);
		}
		if(!bytes_isempty(ba->bu)) {
			DBG_(if(knh_isVerboseLang()) {
				fprintf(stderr, "\n>>>--------------------------------\n");
				fprintf(stderr, "%s<<<--------------------------------\n", knh_Bytes_ensureZero(ctx, ba));
			});
			status  = (kstatus_t)knh_beval2(ctx, knh_Bytes_ensureZero(ctx, ba), uline);
		}
	} while(BA_size(ba) > 0 && status == K_CONTINUE);
	if(!knh_isCompileOnly(ctx)) {
		KNH_NTRACE2(ctx, "konoha:load", K_NOTICE, KNH_LDATA(LOG_s("urn", S_totext(in->path->urn))));
	}
	return status;
}
#else
kstatus_t knh_InputStream_load(CTX ctx, kInputStream *in, kline_t uline)
{
	BEGIN_LOCAL(ctx, lsfp, 3);
	kstatus_t status = K_BREAK;
	LOCAL_NEW(ctx, lsfp, 0, kBytes*, ba, new_Bytes(ctx, "chunk", K_PAGESIZE));
	KNH_SETv(ctx, lsfp[1].o, in);
	kline_t linenum = uline;
	do {
		knh_Bytes_clear(ba, 0);
		if(!io2_isClosed(ctx, in->io2)) {
			status = K_CONTINUE;
			uline = linenum;
			linenum = readchunk(ctx, in, linenum, ba);
		}
		if(!bytes_isempty(ba->bu)) {
			kInputStream *bin = new_BytesInputStream(ctx, BA_totext(ba), BA_size(ba));
			KNH_SETv(ctx, lsfp[2].o, bin);
			DBG_(if(knh_isVerboseLang()) {
				fprintf(stderr, "\n>>>--------------------------------\n");
				fprintf(stderr, "%s<<<--------------------------------\n", knh_Bytes_ensureZero(ctx, ba));
			});
			status  = (kstatus_t)knh_beval(ctx, bin, uline);
		}
	} while(BA_size(ba) > 0 && status == K_CONTINUE);
	if(!knh_isCompileOnly(ctx)) {
		KNH_NTRACE2(ctx, "konoha:load", K_NOTICE, KNH_LDATA(LOG_s("urn", S_totext(in->path->urn))));
	}
	END_LOCAL(ctx, lsfp);
	return status;
}
#endif

kstatus_t knh_load(CTX ctx, kPath *pth)
{
	kio_t *io2 = pth->dpi->io2openNULL(ctx, pth, "r", NULL);
	if(io2 != NULL) {
		kline_t uline = 1;
		kInputStream *in = new_InputStream(ctx, io2, pth);
		kuri_t uri = knh_getURI(ctx, S_tobytes(pth->urn));
		ULINE_setURI(uline, uri);
		KNH_SETv(ctx, (K_GMANS)->path, pth);
		return knh_InputStream_load(ctx, in, uline);
	}
	return K_BREAK;
}

/* ------------------------------------------------------------------------ */

static void knh_buff_addStartPath(CTX ctx, kBytes *ba, size_t pos, kbytes_t path)
{
	if(!knh_isfile(ctx, path.text) && !knh_bytes_endsWith_(path, STEXT(".k"))) {
		kString *s = knh_getPropertyNULL(ctx, STEXT("konoha.script.path"));
		if(s != NULL) {
			knh_buff_addospath(ctx, ba, pos, 0, S_tobytes(s));
			knh_buff_addospath(ctx, ba, pos, 1/*sep*/, path);
			if(knh_isfile(ctx, knh_Bytes_ensureZero(ctx, ba) + pos)) {
				return ;
			}
			knh_Bytes_clear(ba, pos);
		}
	}
	knh_buff_addospath(ctx, ba, pos, 0, path);
}

kstatus_t knh_startScript(CTX ctx, const char *path)
{
	kstatus_t status = K_BREAK;
	KONOHA_BEGIN(ctx);
	kNameSpace *ns = K_GMANS;
	kline_t uline = 1;
	if(path[0] == '-' && path[1] == 0) {
		kInputStream *in = KNH_STDIN;
		kuri_t uri = knh_getURI(ctx, STEXT("stdin"));
		ULINE_setURI(uline, uri);
		status = knh_InputStream_load(ctx, in, uline);
	}
	else {
		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
		knh_buff_addStartPath(ctx, cwb->ba, cwb->pos, B(path));
		FILE *fp = fopen(CWB_totext(ctx, cwb), "r");
		if(fp != NULL) {
			kuri_t uri = knh_getURI(ctx, CWB_tobytes(cwb));
			KNH_SETv(ctx, ns->path, new_Path(ctx, knh_buff_newRealPathString(ctx, cwb->ba, cwb->pos)));
			kInputStream *in = new_InputStream(ctx, new_FILE(ctx, fp, 256), ns->path);
			ULINE_setURI(uline, uri);
			status = knh_InputStream_load(ctx, in, uline);
		}
		else {
			KNH_NOTE("script not found: %s", path);
		}
		CWB_close(ctx, cwb);
	}
	knh_stack_clear(ctx, ctx->stack);
	KONOHA_END(ctx);
	return status;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
