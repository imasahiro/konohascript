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

knh_NameSpace_t* new_NameSpace(CTX ctx, knh_NameSpace_t *parent)
{
	knh_NameSpace_t* ns = new_(NameSpace);
	DBG_ASSERT(IS_NameSpace(parent));
	KNH_INITv(ns->parentNULL, parent);
	KNH_SETv(ctx, DP(ns)->nsname, DP(parent)->nsname);
	KNH_SETv(ctx, ns->path, parent->path);
	//LANG_LOG("ns=%p, rpath='%s'", ns, S_totext(ns->path->urn));
	return ns;
}

knh_class_t knh_NameSpace_getcid(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t sname)
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

knh_bool_t knh_NameSpace_isInsideScope(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid)
{
	return (knh_bytes_startsWith(S_tobytes(ClassTBL(cid)->lname), S_tobytes(DP(ns)->nsname)));
}

/* ------------------------------------------------------------------------ */
/* [stmt] */

knh_flag_t knh_Stmt_flag_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, knh_flag_t flag)
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
//void NameSpace_setFuncClass(CTX ctx, knh_NameSpace_t *ns, knh_methodn_t mn, knh_class_t c)
//{
//	if(!MN_isGETTER(mn) && !MN_isSETTER(mn)) {
//		if(!IS_DictSet(DP(ns)->func2cidDictSet)) {
//			KNH_SETv(ctx, DP(ns)->func2cidDictSet, new_DictSet(ctx, 0));
//		}
//		knh_DictSet_set(ctx, DP(ns)->func2cidDictSet, knh_getFieldName(ctx, MN_toFN(mn)), (knh_uintptr_t)(c+1));
//	}
//}

/* ------------------------------------------------------------------------ */

knh_class_t knh_NameSpace_getFuncClass(CTX ctx, knh_NameSpace_t *ns, knh_methodn_t mn)
{
//	if(!MN_isGETTER(mn) && !MN_isSETTER(mn)) {
//		knh_bytes_t name = S_tobytes(knh_getFieldName(ctx, MN_toFN(mn)));
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

knh_type_t knh_NameSpace_gettype(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t name)
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

knh_type_t knh_NameSpace_tagcid(CTX ctx, knh_NameSpace_t *o, knh_class_t cid, knh_bytes_t tag)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_class_t bcid = ClassTBL(cid)->bcid;
	knh_printf(ctx, cwb->w, "%C:%B", bcid, tag);
	cid = knh_NameSpace_getcid(ctx, o, knh_cwb_tobytes(cwb));
	knh_cwb_close(cwb);
	return cid;
}

/* ------------------------------------------------------------------------ */
/* [include] */

static knh_Token_t * new_TokenEVALED(CTX ctx)
{
	knh_Token_t *tk = new_(Token);
	TT_(tk) = TT_CONST;
	KNH_SETv(ctx, tk->data, ctx->evaled);
	tk->type = O_cid(ctx->evaled);
	return tk;
}

static void *knh_open_gluelink(CTX ctx, knh_Stmt_t *stmt, knh_NameSpace_t *ns, knh_bytes_t libname)
{
	void *p = NULL;
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_buff_addpath(ctx, cwb->ba, cwb->pos, 0, B(ns->path->ospath));
	knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
	knh_Bytes_putc(ctx, cwb->ba, 0); // to avoid concat;
	p = knh_dlopen(ctx, knh_cwb_tochar(ctx, cwb));
	if(p == NULL) {
		knh_Stmt_toERR(ctx, stmt, ERROR_NotFound(ctx, "gluelink", knh_cwb_tochar(ctx, cwb)));
	}
	if(p != NULL) {
		knh_Fpkginit pkginit = (knh_Fpkginit)knh_dlsym(ctx, p, "init", libname.text, 1/*isTest*/);
		if(pkginit != NULL) {
			const knh_PackageDef_t *pkgdef = pkginit(ctx, knh_getPackageLoaderAPI());
			LOGSFPDATA = {sDATA("package_name", pkgdef->name),
					iRANGE("buildid", K_BUILDID, pkgdef->buildid), iRANGE("crc32", K_API2_CRC32, pkgdef->crc32)};
			if((long)pkgdef->crc32 == (long)K_API2_CRC32) {
				LIB_OK("gluelink");
			}
			else {
				LIB_Failed("gluelink", NULL);
				p = NULL;
			}
		}
		else {
			p = NULL;
		}
		if(p == NULL) {
			knh_Stmt_toERR(ctx, stmt, ERROR_NotFound(ctx, "compatible gluelink", knh_cwb_tochar(ctx, cwb)));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	knh_cwb_close(cwb);
	return p;
}

static void *knh_open_ffilink(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t libname)
{
	void *p = NULL;
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	libname = knh_cwb_ensure(ctx, cwb, libname, K_PATHMAX);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
	knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
	if(p == NULL && !knh_bytes_startsWith(libname, STEXT("lib"))) {
		knh_cwb_clear2(cwb, 0);
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT("lib"));
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
		knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
		p = knh_dlopen(ctx, knh_cwb_tochar(ctx, cwb));
	}
	knh_cwb_close(cwb);
	return p;
}

static void INCLUDE_ffilink(CTX ctx, knh_Stmt_t *stmt, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t libname = knh_bytes_next(path, ':');
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
			knh_Stmt_toERR(ctx, stmt, ERROR_NotFound(ctx, "library", libname.text));
		}
	}
}

static void NameSpace_beginINCLUDE(CTX ctx, knh_NameSpace_t *newns, knh_NameSpace_t *oldns)
{
	knh_NameSpaceEX_t *tb = newns->b;
	void *tdlhdr = newns->gluehdr;
	newns->b = oldns->b;
	newns->gluehdr = oldns->gluehdr;
	oldns->b = tb;
	oldns->gluehdr = tdlhdr;
}

static void NameSpace_endINCLUDE(CTX ctx, knh_NameSpace_t *newns, knh_NameSpace_t *oldns)
{
	knh_NameSpaceEX_t *tb = newns->b;
	void *tdlhdr = newns->gluehdr;
	newns->b = oldns->b;
	newns->gluehdr = oldns->gluehdr;
	oldns->b = tb;
	oldns->gluehdr = tdlhdr;
}

knh_bool_t knh_NameSpace_include(CTX ctx, knh_NameSpace_t *ns, knh_Path_t *pth)
{
	knh_NameSpace_t *newns = new_NameSpace(ctx, ns);
	KNH_SETv(ctx, ctx->gma->scr->ns, newns);
	NameSpace_beginINCLUDE(ctx, newns, ns);
	knh_status_t res = knh_load(ctx, pth);
	NameSpace_endINCLUDE(ctx, newns, ns);
	KNH_SETv(ctx, ctx->gma->scr->ns, ns);
	return (res == K_CONTINUE);
}

static void SCRIPT_eval(CTX ctx, knh_Stmt_t *stmt, int isCompileOnly);

static void INCLUDE_file(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Token_t *tkRES = Tn_typing(ctx, stmt, 0, CLASS_Path, 0);
	if(TT_(tkRES) != TT_ERR) {
		if(!Tn_isCONST(stmt, 0)) {
			knh_Stmt_t *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 0), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				knh_Stmt_toERR(ctx, stmt, tkNN(stmt2, 0));
				return;
			}
			KNH_SETv(ctx, tkNN(stmt, 0), new_TokenEVALED(ctx));
		}
		knh_Path_t *pth = (knh_Path_t*)tkNN(stmt,0)->data;
		if(!knh_NameSpace_include(ctx, K_GMANS, pth)) {
			knh_Stmt_toERR(ctx, stmt, ERROR_NotFound(ctx, "include path:", S_totext(pth->urn)));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	else {
		knh_Stmt_toERR(ctx, stmt, tkRES);
	}
}

static void INCLUDE_eval(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Token_t *tkPATH = tkNN(stmt, 0);
	if(IS_bString(tkPATH->text) && knh_bytes_startsWith(S_tobytes(tkPATH->text), STEXT("lib:"))) {
		INCLUDE_ffilink(ctx, stmt, K_GMANS, S_tobytes(tkPATH->text));
	}
	else {
		INCLUDE_file(ctx, stmt);
	}
}

/* ------------------------------------------------------------------------ */
/* [package] */

static knh_bool_t isFoundPackage(CTX ctx, knh_Bytes_t* ba, size_t pos, knh_bytes_t tpath, knh_bytes_t bpath)
{
	knh_Bytes_clear(ba, pos);
	knh_buff_addospath(ctx, ba, pos, 0, tpath);
	knh_buff_addospath(ctx, ba, pos, 1, bpath); // konoha.math
	knh_buff_addospath(ctx, ba, pos, 1, knh_bytes_rnext(bpath, '.')); // math
	knh_buff_addospath(ctx, ba, pos, 0, STEXT(".k"));
	return knh_buff_isfile(ctx, ba, pos);
}

static knh_bool_t knh_buff_addPackagePath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_bytes_t pkgname)
{
	char *epath = knh_getenv("KONOHA_PACKAGE");
	if(epath != NULL && isFoundPackage(ctx, ba, pos, B(epath), pkgname)) {
		return 1;
	}
	knh_String_t *tpath = knh_getPropertyNULL(ctx, STEXT("konoha.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), pkgname)) {
		return 1;
	}
	tpath = knh_getPropertyNULL(ctx, STEXT("user.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), pkgname)) {
		return 1;
	}
	return 0;
}

void knh_Script_setNSName(CTX ctx, knh_Script_t* scr, knh_String_t *nsname)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	KNH_SETv(ctx, DP(scr->ns)->nsname, nsname);
	knh_Bytes_write(ctx, cwb->ba, S_tobytes(nsname));
	knh_Bytes_write(ctx, cwb->ba, STEXT(".Script"));
	KNH_SETv(ctx, ((knh_ClassTBL_t*)O_cTBL(scr))->lname, knh_cwb_newString(ctx, cwb));
}

knh_status_t knh_loadPackage(CTX ctx, knh_bytes_t pkgname)
{
	knh_status_t status = K_CONTINUE;
	knh_DictMap_t *dmap = DP(ctx->sys)->PackageDictMap;
	knh_Script_t *scr = (knh_Script_t*)knh_DictMap_getNULL(ctx, dmap, pkgname);
	if(scr == NULL) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		if(knh_buff_addPackagePath(ctx, cwb->ba, cwb->pos, pkgname)) {
			FILE *fp = fopen(knh_cwb_tochar(ctx, cwb), "r");
			if(fp != NULL) {
				knh_String_t *pname = new_S(pkgname.text, pkgname.len);
				knh_Script_t *newscr = new_(Script);
				knh_Script_setNSName(ctx, newscr, pname);
				knh_DictMap_set(ctx, dmap, pname, newscr);
				knh_uri_t uri = knh_getURI(ctx, knh_cwb_tobytes(cwb));
				KNH_SETv(ctx, newscr->ns->path, new_Path(ctx, knh_buff_newRealPathString(ctx, cwb->ba, cwb->pos)));
				/* */
				knh_InputStream_t *in = new_InputStreamDPI(ctx, (knh_io_t)fp, NULL, newscr->ns->path);
				ULINE_setURI(in->uline, uri);
				DBG_P("rpath='%s'", newscr->ns->path->ospath);
				scr = ctx->gma->scr;
				KNH_SETv(ctx, ctx->gma->scr, newscr);
				status = knh_InputStream_load(ctx, in);
				KNH_SETv(ctx, ctx->gma->scr, scr);
			}
		}
		else {
			ERROR_NotFound(ctx, "package", pkgname.text);
			status = K_BREAK;
		}
		knh_cwb_close(cwb);
	}
	return status;
}

/* ------------------------------------------------------------------------ */

static void NameSpace_setcid(CTX ctx, knh_NameSpace_t *ns, knh_String_t *name, knh_class_t cid)
{
	if(DP(ns)->name2ctDictSetNULL == NULL) {
		KNH_INITv(DP(ns)->name2ctDictSetNULL, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "NameSpace.name2cid"));
	}
//	else {
//		const knh_ClassTBL_t *ct = (const knh_ClassTBL_t*)knh_DictSet_get(ctx, DP(ns)->name2ctDictSetNULL, S_tobytes(name));
//		if(oldcid != 0 && cid != oldcid - 1) {
//			WARN_AlreadyDefinedClass(ctx, cid, (knh_class_t)(oldcid - 1));
//			return;
//		}
//	}
	knh_DictSet_set(ctx, DP(ns)->name2ctDictSetNULL, name, (knh_uintptr_t)ClassTBL(cid));
}

static int StmtUSINGCLASS_eval(CTX ctx, knh_Stmt_t *stmt, size_t n)
{
	knh_Token_t *tkPKG = tkNN(stmt, n), *tkN;
	{
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
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
		KNH_SETv(ctx, (tkPKG)->data, knh_cwb_newString(ctx, cwb));
	}
	if(knh_loadPackage(ctx, S_tobytes((tkPKG)->text)) == K_CONTINUE) {
		knh_NameSpace_t *ns = K_GMANS;
		if(TT_(tkN) == TT_MUL) {
			knh_bytes_t pkgname = S_tobytes((tkPKG)->text);
			size_t cid;
			for(cid = 0; cid < ctx->share->sizeClassTBL; cid++) {
				if(ClassTBL(cid)->lname == NULL) continue;
				if(class_isPrivate(cid) && C_isGenerics(cid)) continue;
				knh_bytes_t cname = S_tobytes(ClassTBL(cid)->lname);
				if(knh_bytes_startsWith(cname, pkgname)
						&& cname.utext[pkgname.len] == '.' && isupper(cname.utext[pkgname.len+1])) {
					NameSpace_setcid(ctx, ns, ClassTBL(cid)->sname, (knh_class_t)cid);
				}
			}
		}
		else if(TT_(tkN) == TT_UNAME) {
			knh_class_t newcid;
			knh_String_t* cname = (tkN)->text;
			knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
			knh_Bytes_write(ctx, cwb->ba, S_tobytes((tkPKG)->text));
			knh_Bytes_putc(ctx, cwb->ba, '.');
			knh_Bytes_write(ctx, cwb->ba, S_tobytes(cname));
			newcid = knh_getcid(ctx, knh_cwb_tobytes(cwb));
			if(newcid == CLASS_unknown) {
				KNH_SETv(ctx, (tkPKG)->data, knh_cwb_newString(ctx, cwb));
				knh_cwb_close(cwb);
				goto L_ERROR;
			}
			else {
				NameSpace_setcid(ctx, ns, cname, newcid);
			}
			knh_cwb_close(cwb);
		}
		knh_Stmt_done(ctx, stmt);
		return 1;
	}
	L_ERROR:;
	while(n + 1 < DP(stmt)->size) {
		if(TT_(tkNN(stmt, n)) == TT_OR) return 0;
		n++;
	}
	knh_Stmt_toERR(ctx, stmt, ERROR_NotFound(ctx, "package", S_totext((tkPKG)->text)));
	return 0;
}

static void USING_eval(CTX ctx, knh_Stmt_t *stmt)
{
	size_t n = 0;
	L_TRYAGAIN:; {
		knh_Token_t *tkF = tkNN(stmt, n);
		if(TT_(tkF) == TT_NAME) {
			if(StmtUSINGCLASS_eval(ctx, stmt, n)) {
				goto L_RETURN;
			}
		}
	}
	while(n + 1 < DP(stmt)->size) {  // find next or
		knh_Token_t *tkF = tkNN(stmt, n);
		n++;
		if(TT_(tkF) == TT_OR) goto L_TRYAGAIN;
	}
	L_RETURN:;
	if(STT_(stmt) != STT_ERR) {
		knh_Stmt_done(ctx, stmt);
	}
}

/* ------------------------------------------------------------------------ */

static knh_Method_t *Script_getEvalMethod(CTX ctx, knh_Script_t *scr, knh_type_t it_type)
{
	knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, O_cid(scr), MN_);
	if(mtd == NULL) {
		knh_ParamArray_t *pa = new_(ParamArray);
		knh_ParamArray_addParam(ctx, pa, it_type, FN_it);
		knh_ParamArray_addReturnType(ctx, pa, TYPE_void);
		mtd = new_Method(ctx, FLAG_Method_Hidden, O_cid(scr), MN_LAMBDA, NULL);
		KNH_SETv(ctx, DP(mtd)->mp, pa);
		knh_NameSpace_addMethod(ctx, O_cid(scr), mtd);
	}
	else {
		knh_param_t *p = knh_ParamArray_get(DP(mtd)->mp, 0);
		p->type = it_type;
		//p = knh_ParamArray_rget(DP(mtd)->mp, 0);
		/*p->type = TYPE_void;*/
	}
	return mtd;
}

void SCRIPT_asm(CTX ctx, knh_Stmt_t *stmtITR);

static void SCRIPT_eval(CTX ctx, knh_Stmt_t *stmtORIG, int isCompileOnly)
{
	BEGIN_LOCAL(ctx, lsfp, 5);
	knh_Script_t *scr = K_GMASCR;
	knh_class_t cid =  O_cid(ctx->evaled);
	knh_Method_t *mtd = Script_getEvalMethod(ctx, scr, cid);
	knh_Stmt_t *stmt = stmtORIG;
	if(STT_isExpr(STT_(stmt)) && STT_(stmt) != STT_LET) {
		stmt = new_Stmt2(ctx, STT_RETURN, stmt, NULL);
	}
	if(STT_(stmt) == STT_RETURN) {
		Stmt_setImplicit(stmt, 1);
	}
	KNH_SETv(ctx, lsfp[0].o, stmt);
	knh_Method_asm(ctx, mtd, stmt, typingMethod2);
	if(STT_(stmt) == STT_ERR) {
		if(stmt != stmtORIG) {
			knh_Stmt_toERR(ctx, stmtORIG, tkNN(stmt, 0));
		}
		END_LOCAL_(ctx, lsfp);
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
		WCTX(ctx)->isEvaled = 0;
		if(knh_VirtualMachine_launch(ctx, lsfp + thisidx)) {
			//DBG_P("returning sfpidx=%d, rtnidx=%d, %s %lld %ld %f", sfpidx_, sfpidx_ + rtnidx, O__(lsfp[rtnidx].o), lsfp[rtnidx].ivalue, lsfp[rtnidx].bvalue, lsfp[rtnidx].fvalue);
			if(STT_(stmt) == STT_RETURN && !Stmt_isImplicit(stmt)) {
				cid = O_cid(lsfp[rtnidx].o);
				KNH_SETv(ctx, WCTX(ctx)->evaled, lsfp[rtnidx].o);
				WCTX(ctx)->isEvaled = 0;
			}
		}
		else {
			KNH_TODO("VirtualMachine return error status");
		}
	}
	knh_Stmt_done(ctx, stmtORIG);
	END_LOCAL_(ctx, lsfp);
}

static void StmtITR_eval(CTX ctx, knh_Stmt_t *stmtITR);

static void IF_eval(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Token_t *tkRES = Tn_typing(ctx, stmt, 0, TYPE_Boolean, 0);
	if(TT_(tkRES) != TT_ERR) {
		int isTrue = 1;
		if(!Tn_isCONST(stmt, 0)) {
			knh_Stmt_t *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 0), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				knh_Stmt_toERR(ctx, stmt, tkNN(stmt2, 0)); return;
			}
			isTrue = IS_TRUE(ctx->evaled) ? 1 : 0;
		}
		else {
			isTrue = (Tn_isTRUE(stmt, 0)) ? 1: 0;
		}
		knh_Stmt_t *stmtIN = stmtNN(stmt, isTrue ? 1 : 2);
		StmtITR_eval(ctx, stmtIN);
		if(STT_(stmtIN) == STT_ERR) {
			knh_Stmt_toERR(ctx, stmt, tkNN(stmtIN, 0));
		}
		else {
			knh_Stmt_done(ctx, stmt);
		}
	}
	else {
		knh_Stmt_toERR(ctx, stmt, tkRES);
	}
}

Object *knh_NameSpace_getConstNULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t name)
{
	L_TAIL:
	if(DP(ns)->constDictCaseMapNULL != NULL) {
		knh_index_t idx = knh_DictMap_index(DP(ns)->constDictCaseMapNULL, name);
		if(idx != -1) return knh_DictMap_valueAt(DP(ns)->constDictCaseMapNULL, idx);
	}
	if(ns->parentNULL != NULL) {
		ns = ns->parentNULL;
		goto L_TAIL;
	}
	return knh_getClassConstNULL(ctx, DP(ctx->gma)->this_cid, name);
}

static void CONST_decl(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Token_t *tkN = tkNN(stmt, 0), *tkRES = NULL;
	knh_class_t cid = knh_Token_cid(ctx, tkN, CLASS_unknown);
	knh_NameSpace_t *ns = K_GMANS;
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
			knh_Stmt_t *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 1), NULL);
			SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
			if(STT_(stmt2) == STT_ERR) {
				knh_Stmt_toERR(ctx, stmt, tkNN(stmt2, 0)); return;
			}
			value = ctx->evaled;
		}
		if(IS_Class(value)) {
			NameSpace_setcid(ctx, ns, tkN->text, ((knh_Class_t*)value)->cid);
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
		knh_Stmt_toERR(ctx, stmt, tkRES);
	}
}

//static knh_status_t METHODWITH_eval(CTX ctx, knh_Stmt_t *stmt)
//{
//	knh_status_t status = K_CONTINUE;
//	if(StmtMETHOD_isFFI(stmt)) {
//		knh_Token_t *tkRES = Tn_typing(ctx, stmt, 4, TYPE_Map, 0);
//		if(TT_(tkRES) != TT_ERR) {
//			if(!Tn_isCONST(stmt, 4)) {
//				knh_Stmt_t *stmt2 = new_Stmt2(ctx, STT_RETURN, stmtNN(stmt, 4), NULL);
//				status = SCRIPT_eval(ctx, stmt2, 0/*isCompileOnly*/);
//				if(status != K_CONTINUE) return status;
//				KNH_SETv(ctx, tkNN(stmt, 4), new_TokenEVALED(ctx));
//			}
//		}
//		else {
//			knh_Stmt_toERR(ctx, stmt, tkRES);
//			return K_BREAK;
//		}
//	}
//	return status;
//}

/* ------------------------------------------------------------------------ */
/* [CLASS] */

static knh_flag_t knh_StmtCLASS_flag(CTX ctx, knh_Stmt_t *stmt)
{
	knh_flag_t flag = 0;
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		flag |= knh_Stmt_flag(ctx, stmt, "Final",     FLAG_Class_Final);
		flag |= knh_Stmt_flag(ctx, stmt, "Interface", FLAG_Class_Interface);
		flag |= knh_Stmt_flag(ctx, stmt, "Singleton", FLAG_Class_Singleton);
		flag |= knh_Stmt_flag(ctx, stmt, "Immutable", FLAG_Class_Immutable);
//		flag |= knh_Stmt_flag(ctx, stmt, "Release",   FLAG_Class_Release);
	}
	return flag;
}


static void knh_loadNativeClass(CTX ctx, const char *cname, knh_ClassTBL_t *ct)
{
	char fname[256];
	knh_NameSpace_t *ns = K_GMANS;
	const knh_ClassDef_t *cdef = NULL;
	if(ns->gluehdr != NULL) {
		knh_snprintf(fname, sizeof(fname), "def%s", cname);
		knh_Fclassdef classdef = (knh_Fclassdef)knh_dlsym(ctx, ns->gluehdr, fname, cname, 0/*isTest*/);
		if(classdef != NULL) {
			knh_ClassDef_t *cdefbuf = (knh_ClassDef_t*)KNH_MALLOC(ctx, sizeof(knh_ClassDef_t));
			knh_memcpy(cdefbuf, knh_getDefaultClassDef(), sizeof(knh_ClassDef_t));
			LANG_LOG("loading glue func: %s", fname);
			classdef(ctx, ct->cid, cdefbuf);
			cdefbuf->asize = sizeof(knh_ClassDef_t);
			cdef = (const knh_ClassDef_t*)cdefbuf;
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
			constdef(ctx, ct->cid, knh_getPackageLoaderAPI());
		}
	}
}

/* ------------------------------------------------------------------------ */

void knh_RefTraverse(CTX ctx, knh_Ftraverse ftr)
{
#ifdef K_USING_RCGC
	int i;
	for(i = ctx->ref_size - 1; i >= 0; i--) {
		knh_Object_t *ref = ctx->refs[i];
		ftr(ctx, ref);
	}
#endif
}

static void ClassTBL_inherit(CTX ctx, knh_ClassTBL_t *ct, const knh_ClassTBL_t *supct) {
	ct->supTBL = ClassTBL(ct->supcid);
	ct->keyidx = supct->keyidx;
	ct->metaidx = supct->metaidx;
	((knh_ClassTBL_t*)supct)->subclass += 1;
	ct->bcid = supct->bcid;
	ct->baseTBL = ClassTBL(supct->bcid);

}

static knh_ClassTBL_t *CLASSNAME_decl(CTX ctx, knh_Stmt_t *stmt, knh_Token_t *tkC, knh_Token_t *tkE)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Bytes_write(ctx, cwb->ba, S_tobytes(DP(K_GMANS)->nsname));
	knh_Bytes_putc(ctx, cwb->ba, '.');
	knh_Bytes_write(ctx, cwb->ba, TK_tobytes(tkC));
	knh_class_t cid = knh_getcid(ctx, knh_cwb_tobytes(cwb));
	knh_ClassTBL_t *ct = NULL;
	if(cid == CLASS_unknown) {  // new class //
		cid = new_ClassId(ctx);
		ct = varClassTBL(cid);
		knh_setClassName(ctx, cid, knh_cwb_newString(ctx, cwb), (tkC)->text);
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
			ct->supcid = knh_Token_cid(ctx, tkE, CLASS_unknown);
			if(ct->supcid == CLASS_unknown) {
				knh_Stmt_toERR(ctx, stmt, ERROR_Undefined(ctx, "class", ct->supcid, tkE));
				return ct;
			}
			if(class_isFinal(ct->supcid)) {
				knh_Stmt_toERR(ctx, stmt, ERROR_TokenIs(ctx, tkE, "final"));
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
		knh_Stmt_toERR(ctx, stmt, ERROR_AlreadyDefined(ctx, "class", (tkC)->data));
	}
	L_RETURN:;
	(tkC)->cid = cid;
	knh_cwb_close(cwb);
	return ct;
}

static void CLASS_decl(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Token_t *tkC = tkNN(stmt, 0); // CNAME
	knh_Token_t *tkE = tkNN(stmt, 2); // extends
	knh_ClassTBL_t *ct = CLASSNAME_decl(ctx, stmt, tkC, tkE);
	if(STT_(stmt) == STT_ERR) return;
	if(knh_StmtMETA_is(ctx, stmt, "Native")) {
		knh_loadNativeClass(ctx, S_totext((tkC)->text), ct);
	}
	if(ct->protoNULL == NULL && (ct->bcid == CLASS_Object || ct->bcid == CLASS_CppObject)) {
		knh_Object_t *nulval = new_hObject_(ctx, ct);
		knh_Object_t *defval = new_hObject_(ctx, ct);
		KNH_ASSERT(nulval->ref == NULL);
		KNH_ASSERT(defval->ref == NULL);
		Object_setNullObject(nulval, 1);
		knh_setClassDefaultValue(ctx, ct->cid, nulval, NULL);
		KNH_INITv(ct->protoNULL, defval);
	}
	if(DP(stmt)->size == 4 && TT_(tkNN(stmt, 1)) == TT_ASIS) {
		knh_Stmt_done(ctx, stmt);
	}
}

static void StmtITR_eval(CTX ctx, knh_Stmt_t *stmtITR)
{
	BEGIN_LOCAL(ctx, lsfp, 3);
	knh_Stmt_t *stmt = stmtITR;
	KNH_SETv(ctx, lsfp[0].o, stmtITR); // lsfp[1] stmtNEXT
	while(stmt != NULL) {
		knh_Stmt_t *stmtNEXT = DP(stmt)->nextNULL;
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
			knh_NameSpace_t *ns = new_NameSpace(ctx, K_GMANS);
			knh_Stmt_t *stmtIN = stmtNN(stmt, 0);
			KNH_SETv(ctx, K_GMANS, ns);
			StmtITR_eval(ctx, stmtIN);
			DBG_ASSERT(K_GMANS == ns);
			DBG_ASSERT(ns->parentNULL != NULL);
			KNH_SETv(ctx, K_GMANS, ns->parentNULL);
			if(STT_(stmtIN) == STT_ERR) {
				knh_Stmt_toERR(ctx, stmtITR, tkNN(stmtIN, 0));
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
				knh_Stmt_toERR(ctx, stmtITR, tkNN(stmt, 0));
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
					knh_Stmt_toERR(ctx, stmtITR, tkNN(stmt, 0));
				}
				goto L_RETURN;
			}
		}
		stmt = stmtNEXT;
	}

	L_RETURN:;
	END_LOCAL_(ctx, lsfp);
	ctx->gma->uline = 0;
}

knh_bool_t knh_beval(CTX ctx, knh_InputStream_t *in)
{
	knh_bool_t tf;
	BEGIN_LOCAL(ctx, lsfp, 2);
	KNH_SETv(ctx, lsfp[0].o, in);
	LOCAL_NEW(ctx, lsfp, 1, knh_Stmt_t *, stmt, knh_InputStream_parseStmt(ctx, in));
	StmtITR_eval(ctx, stmt);
	tf = (STT_(stmt) != STT_ERR);
	END_LOCAL_(ctx, lsfp);
	return tf;
}

KNHAPI2(knh_bool_t) knh_eval(CTX ctx, const char *script, knh_OutputStream_t *w)
{
//	KNH_NOTE("gma->src=%p, nsname=%s", ctx->gma->scr, S_totext(DP(ctx->gma->scr->ns)->nsname));
//	KNH_NOTE("gma->src=%p, nsname=%s", ctx->share->script, S_totext(DP(ctx->share->script->ns)->nsname));
//	KNH_ASSERT(ctx->gma->scr == ctx->share->script);
	//fprintf(stderr, "gma=%p, share=%p\n", ctx->gma->scr, ctx->share->script);
	// KNH_SETv(ctx, ((knh_context_t*)ctx)->evaled, KNH_NULL);

	knh_InputStream_t *bin = new_StringInputStream(ctx, new_String(ctx, script));
	SP(bin)->uline = 1; // always line1
	KNH_SETv(ctx, ((knh_context_t*)ctx)->e, KNH_NULL);
	knh_bool_t tf = knh_beval(ctx, bin);
	if(w != NULL && ctx->isEvaled == 1) {
		knh_write_Object(ctx, w, ctx->evaled, FMT_dump);
	}
	return tf;
}

/* ------------------------------------------------------------------------ */

static int bytes_isempty(knh_bytes_t t)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if(!isspace(t.utext[i])) return 0;
	}
	return 1;
}

static void Bytes_addQUOTE(CTX ctx, knh_Bytes_t *ba, knh_InputStream_t *in, int quote)
{
	int ch, prev = quote;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		knh_Bytes_putc(ctx, ba, ch);
		if(ch == quote && prev != '\\') {
			return;
		}
		prev = ch;
	}
}

static void Bytes_addCOMMENT(CTX ctx, knh_Bytes_t *ba, knh_InputStream_t *in)
{
	int ch, prev = 0, level = 1;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		knh_Bytes_putc(ctx, ba, ch);
		if(prev == '*' && ch == '/') level--;
		if(prev == '/' && ch == '*') level++;
		if(level == 0) return;
		prev = ch;
	}
}

static int readchunk(CTX ctx, knh_InputStream_t *in, knh_Bytes_t *ba)
{
	int ch;
	int prev = 0, isBLOCK = 0;
	int linenum = ULINE_line(in->uline);
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		knh_Bytes_putc(ctx, ba, ch);
		if(prev == '/' && ch == '*') {
			Bytes_addCOMMENT(ctx, ba, in);
			continue;
		}
		if(ch == '\'' || ch == '"' || ch == '`') {
			Bytes_addQUOTE(ctx, ba, in, ch);
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
	return linenum;
}

knh_status_t knh_InputStream_load(CTX ctx, knh_InputStream_t *in)
{
	knh_status_t status = K_BREAK;
	knh_Bytes_t *ba = new_Bytes(ctx, "chunk", K_PAGESIZE);
	BEGIN_LOCAL(ctx, lsfp, 3);
	LOCAL_NEW(ctx, lsfp, 1, knh_InputStream_t*, bin, new_BytesInputStream(ctx, ba));
	KNH_SETv(ctx, lsfp[0].o, in);
	if(!knh_isCompileOnly(ctx)) {
		LOGSFPDATA = {sDATA("urn", S_totext(DP(in)->path->urn))};
		NOTE_OK("script_start");
	}
	do {
		int linenum = 0;
		knh_Bytes_clear(ba, 0);
		if(!InputStream_isClosed(ctx, in)) {
			status = K_CONTINUE;
			linenum = readchunk(ctx, in, ba);
		}
		if(!bytes_isempty(ba->bu)) {
			knh_uri_t uri = ULINE_uri(in->uline);
			knh_InputStream_setpos(ctx, bin, 0, BA_size(ba));
			bin->uline = linenum;
			ULINE_setURI(bin->uline, uri);
			DBG_(if(knh_isVerboseLang()) {
				fprintf(stderr, "\n>>>--------------------------------\n");
				fprintf(stderr, "%s<<<--------------------------------\n", knh_Bytes_ensureZero(ctx, ba));
			});
			status  = knh_beval(ctx, bin);
		}
	} while(BA_size(ba) > 0 && status == K_CONTINUE);
	END_LOCAL_(ctx, lsfp);
	return status;
}

knh_status_t knh_load(CTX ctx, knh_Path_t *pth)
{
	knh_io_t fd = pth->dpi->fopenSPI(ctx, pth, "r");
	DBG_P("dpi->name=%s, fd=%d, ospath=%s", pth->dpi->name, fd, pth->ospath);
	if(fd != IO_NULL) {
		knh_InputStream_t *in = new_InputStreamDPI(ctx, fd, pth->dpi, pth);
		knh_uri_t uri = knh_getURI(ctx, S_tobytes(pth->urn));
		ULINE_setURI(in->uline, uri);
		KNH_SETv(ctx, (K_GMANS)->path, pth);
		return knh_InputStream_load(ctx, in);
	}
	return K_BREAK;
}

/* ------------------------------------------------------------------------ */

static void knh_buff_addStartPath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_bytes_t path)
{
	if(!knh_isfile(ctx, path.text) && !knh_bytes_endsWith(path, STEXT(".k"))) {
		knh_String_t *s = knh_getPropertyNULL(ctx, STEXT("konoha.script.path"));
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

knh_status_t knh_startScript(CTX ctx, const char *path)
{
	knh_status_t status = K_BREAK;
	KONOHA_BEGIN(ctx);
	knh_NameSpace_t *ns = K_GMANS;
	if(path[0] == '-' && path[1] == 0) {
		knh_InputStream_t *in = KNH_STDIN;
		knh_uri_t uri = knh_getURI(ctx, STEXT("stdin"));
		ULINE_setURI(in->uline, uri);
		status = knh_InputStream_load(ctx, in);
	}
	else {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_buff_addStartPath(ctx, cwb->ba, cwb->pos, B(path));
		FILE *fp = fopen(knh_cwb_tochar(ctx, cwb), "r");
		if(fp != NULL) {
			knh_uri_t uri = knh_getURI(ctx, knh_cwb_tobytes(cwb));
			KNH_SETv(ctx, ns->path, new_Path(ctx, knh_buff_newRealPathString(ctx, cwb->ba, cwb->pos)));
			knh_InputStream_t *in = new_InputStreamDPI(ctx, (knh_io_t)fp, NULL, ns->path);
			ULINE_setURI(in->uline, uri);
			status = knh_InputStream_load(ctx, in);
		}
		else {
			KNH_NOTE("script not found: %s", path);
		}
		knh_cwb_close(cwb);
	}
	knh_stack_clear(ctx, ctx->stack);
	KONOHA_END(ctx);
	return status;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
