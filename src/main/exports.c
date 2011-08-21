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
/* [CONST/PROPERTY DATA] */

static void loadData(CTX ctx, knh_NameSpace_t *ns, const char *dname, Object *value)
{
	if(dname[0] == '$') {
		knh_String_t *n = new_T(dname + 1);
		knh_DictMap_set_(ctx, DP(ctx->sys)->props, n, value);
	}
	else {
		knh_bytes_t n = {{dname}, knh_strlen(dname)};
		knh_index_t loc = knh_bytes_rindex(n, '.');
		knh_String_t *name = new_T(dname + (loc+1));
		knh_class_t cid = CLASS_Tdynamic;
		if(loc != -1) {
			cid = knh_NameSpace_getcid(ctx, ns, knh_bytes_first(n, loc));
			if(cid == CLASS_unknown) {
				KNH_LOG("unknown class constant: %s", dname);
				cid = CLASS_Tdynamic;
			}
		}
		knh_addClassConst(ctx, cid, name, value);
	}
}

static void loadIntData(CTX ctx, knh_NameSpace_t *ns, const knh_IntData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_Int(ctx, data->ivalue));
		loadData(ctx, ns, data->name, value);
		data++;
	}
}

static void loadFloatData(CTX ctx, knh_NameSpace_t *ns, const knh_FloatData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_Float(ctx, data->fvalue));
		loadData(ctx, ns, data->name, value);
		data++;
	}
}

static void loadStringData(CTX ctx, knh_NameSpace_t *ns, const knh_StringData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_String2(ctx, CLASS_String, data->value, knh_strlen(data->value), K_SPOLICY_TEXT|K_SPOLICY_ASCII));
		loadData(ctx, ns, data->name, value);
		data++;
	}
}

static void loadClassIntConst(CTX ctx, knh_class_t cid, const knh_IntData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_Int(ctx, data->ivalue));
		knh_addClassConst(ctx, cid, new_T(data->name), value);
		data++;
	}
}

static void loadClassFloatConst(CTX ctx, knh_class_t cid, const knh_FloatData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_Float(ctx, data->fvalue));
		knh_addClassConst(ctx, cid, new_T(data->name), value);
		data++;
	}
}

static void loadStringClassConst(CTX ctx, knh_class_t cid, const knh_StringData_t *data)
{
	while(data->name != NULL) {
		Object *value = UPCAST(new_T(data->value));
		knh_addClassConst(ctx, cid, new_String2(ctx, CLASS_String, data->name, knh_strlen(data->name), K_SPOLICY_TEXT), value);
		data++;
	}
}

static void setProperty(CTX ctx, const char *name, const char *data)
{
	char pname[256];
	const char *nsn = S_totext(DP(ctx->gma->scr->ns)->nsname);
	knh_snprintf(pname, sizeof(pname), "%s.%s", nsn, name);
	knh_DictMap_set(ctx, DP(ctx->sys)->props, new_String(ctx, pname), new_T(data));
}

static void setIntProperty(CTX ctx, const char *name, knh_int_t data)
{
	char pname[256];
	const char *nsn = S_totext(DP(ctx->gma->scr->ns)->nsname);
	knh_snprintf(pname, sizeof(pname), "%s.%s", nsn, name);
	knh_DictMap_set(ctx, DP(ctx->sys)->props, new_String(ctx, pname), new_Int(ctx, data));
}

static void setFloatProperty(CTX ctx, const char *name, knh_float_t data)
{
	char pname[256];
	const char *nsn = S_totext(DP(ctx->gma->scr->ns)->nsname);
	knh_snprintf(pname, sizeof(pname), "%s.%s", nsn, name);
	knh_DictMap_set(ctx, DP(ctx->sys)->props, new_String(ctx, pname), new_Float(ctx, data));
}


/* ------------------------------------------------------------------------ */

#define _MAX 1024

static knh_bytes_t knh_data_tobytes(knh_data_t data)
{
	char *p = (char*)data;
	return B(p);
}

static knh_ParamArray_t *knh_loadScriptParamArray(CTX ctx, const knh_data_t **d, knh_uintptr_t uflag, int step)
{
	knh_ParamArray_t *pa = new_ParamArray(ctx);
	const knh_data_t *data = (*d) + step;
	long i, psize = (long)data[0];
	long rsize = (long)data[1];
	data += 2;
	for(i = 0; i < psize+rsize; i++) {
		knh_type_t type = (data[0] < _MAX || (TYPE_This <= data[0] && data[0] <= TYPE_T3)) ?
			(knh_type_t)data[0] : knh_NameSpace_gettype(ctx, K_GMANS, knh_data_tobytes(data[0]));
		knh_fieldn_t fn = (data[1] < _MAX) ?
			(knh_fieldn_t)data[1] : knh_getfnq(ctx, knh_data_tobytes(data[1]), FN_NEWID);
		knh_param_t p = {type, fn};
		knh_ParamArray_add(ctx, pa, p);
		data += 2;
	}
	pa->psize = (knh_ushort_t)psize;
	pa->rsize = (knh_ushort_t)rsize;
	*d = data;
	pa->h.magicflag |= uflag;
	return pa;
}

#define _CID(d)  (d < _MAX) ? (knh_class_t)(d) : knh_NameSpace_getcid(ctx, K_GMANS, knh_data_tobytes(d))
#define _EXPTID(d)  (d < _MAX) ? (knh_event_t)(d) : knh_geteid(ctx, knh_data_tobytes(d))

static void knh_loadSystemData(CTX ctx, const knh_data_t *data, knh_ParamArray_t **buf)
{
	size_t c = 0;
	while(1) {
		long datatype = (long)data[0]; data++;
		switch(datatype) {
		case DATA_END: return;
		case DATA_STRUCT0: {
			knh_class_t cid0 = _CID(data[0]);
			knh_ClassDef_t *cspi = (knh_ClassDef_t*)data[1];
			knh_flag_t cflag = (knh_flag_t)data[2];
			data += 3;
			knh_class_t cid = new_ClassId(ctx);
			knh_ClassTBL_t *t = varClassTBL(cid);
			KNH_ASSERT(cid == cid0);
			t->bcid = cid;
			knh_setClassDef(ctx, t, cspi);
			t->cflag = cflag;
			t->magicflag = KNH_MAGICFLAG(cflag);
			break;
		}
		//{"Object", FLAG_Object, CLASS_ObjectField, CLASS_Object, a},
		case DATA_CLASS0: {
			knh_class_t cid0 = _CID(data[0]);
			char *name = (char*)data[1];
			knh_ClassTBL_t *ct = varClassTBL(cid0);
			if(ct == NULL) {
				knh_class_t cid = new_ClassId(ctx);
				ct = varClassTBL(cid);
				KNH_ASSERT(cid == cid0);
			}
			ct->cflag = (knh_flag_t)data[2];
			ct->magicflag = KNH_MAGICFLAG(ct->cflag);
			ct->bcid = _CID(data[3]);
			ct->baseTBL = ClassTBL(ct->bcid);
			if(cid0 != ct->bcid) {
				knh_setClassDef(ctx, ct, ClassTBL(ct->bcid)->cdef);
			}
			DBG_ASSERT(ct->cdef != NULL);
			ct->supcid = _CID(data[4]);
			ct->supTBL = ClassTBL(ct->supcid);
			knh_setClassName(ctx, cid0, new_T(name), NULL);
			DBG_ASSERT(ct->methods == NULL);
			if(data[5] > 0/* || cid0 == CLASS_Tvoid*/) {
				KNH_INITv(ct->methods, new_Array0(ctx, data[5]));
			}
			else {
				KNH_INITv(ct->methods, K_EMPTYARRAY);
			}
			if(ct->typemaps == NULL) {
				KNH_INITv(ct->typemaps, K_EMPTYARRAY);
			}
			data += 6;
			break;
		}
		case DATA_CPARAM: {
			knh_class_t cid = _CID(data[0]);
			const char *lname = (const char*)data[1];
			//const char *sname = (const char*)data[2];
			knh_ClassTBL_t *ct = varClassTBL(cid);
			knh_ParamArray_t *pa = knh_loadScriptParamArray(ctx, &data, 0/*hflag*/, +3);
			knh_setClassParam(ctx, ct, pa);
			KNH_SETv(ctx, ct->lname, new_T(lname));
			//KNH_SETv(ctx, ct->sname, new_T(sname));
			break;
		}
		case DATA_GENERICS: {
			knh_class_t bcid = _CID(data[0]);
			knh_ParamArray_t *mp = knh_loadScriptParamArray(ctx, &data, 0/*hflag*/, +1);
			knh_addGenericsClass(ctx, CLASS_newid, bcid, mp);
			break;
		}
		case DATA_EXPT: {
			char *name = (char*)data[0];
			knh_flag_t flag = (knh_flag_t)data[1];
//			knh_event_t eid = _EXPTID(data[2]);
			knh_event_t pid = _EXPTID(data[3]);
			knh_addEvent(ctx, flag, new_T(name), pid);
			data += 4;
			break;
		}
		//{Int_opPREV, FLAG_Method_Const, CLASS_Int, MN_opPREV, 0, 20, NULL},
		//{cid, mn, flag, func, mpidx, psize, rsize}
		case DATA_METHOD0:
		case DATA_METHOD : {
			knh_class_t cid = _CID(data[0]);
			knh_methodn_t mn = (datatype == DATA_METHOD)
				? knh_getmn(ctx, knh_data_tobytes(data[1]), MN_NEWID) : (knh_methodn_t)data[1];
			knh_flag_t flag = (knh_flag_t)data[2];
			knh_Fmethod func = (knh_Fmethod)data[3];
			knh_Method_t *mtd;
			if(class_isSingleton(cid)) {
				flag = flag | FLAG_Method_Static;
			}
			mtd = new_Method(ctx, flag, cid, mn, func);
			knh_ClassTBL_addMethod(ctx, ClassTBL(cid), mtd, 0);
			data += 4;
			if(datatype == DATA_METHOD0) {
				KNH_SETv(ctx, DP(mtd)->mp, buf[data[0]]);
				DBG_ASSERT(IS_ParamArray(DP(mtd)->mp));
				data++;
			}
			else {
				knh_ParamArray_t *mp = knh_loadScriptParamArray(ctx, &data, 0/*hflag*/, +0);
				KNH_SETv(ctx, DP(mtd)->mp, mp);
			}
			break;
		}
		case DATA_TYPEMAP: { //{scid, tcid, flag, func},
			knh_class_t scid = _CID(data[0]);
			knh_class_t tcid = _CID(data[1]);
			knh_flag_t  flag = (knh_flag_t)data[2];
			knh_Ftypemap func = (knh_Ftypemap)data[3];
			knh_addTypeMapFunc(ctx, flag, scid, tcid, func, KNH_NULL);
			data += 4;
			break;
		}
		case DATA_PARAM: {
			knh_uintptr_t flag = (knh_uintptr_t)data[0];
			data++;
			buf[c] = knh_loadScriptParamArray(ctx, &data, flag, +0);
			c++;
			break;
		}/*case DATA_PARAM*/
		default :
			KNH_DIE("unknown datatype=%d", (int)datatype);
		}/*switch*/
	}
}

static void knh_loadFuncData(CTX ctx, const knh_FuncData_t *d)
{
	knh_DictSet_t *ds = ctx->share->funcDictSet;
	while(d->name != NULL) {
		knh_DictSet_append(ctx, ds, new_String2(ctx, CLASS_String, d->name, knh_strlen(d->name), K_SPOLICY_TEXT|K_SPOLICY_POOLNEVER), (knh_uintptr_t)d->ptr);
		d++;
	}
	knh_DictSet_sort(ctx, ds);
}

/* ------------------------------------------------------------------------ */

static void addLink(CTX ctx, knh_NameSpace_t *ns, const char *scheme, knh_class_t cid)
{
	knh_NameSpace_setLinkClass(ctx, ns, B(scheme), ClassTBL(cid));
}

static void knh_addStreamDPI(CTX ctx, knh_NameSpace_t *ns, const char *scheme, const knh_StreamDPI_t *d)
{
	knh_NameSpace_addDSPI(ctx, ns, scheme, (knh_DSPI_t*)d);
}

static void knh_addQueryDSPI(CTX ctx, knh_NameSpace_t *ns, const char *scheme, const knh_QueryDSPI_t *d)
{
	knh_NameSpace_addDSPI(ctx, ns, scheme, (knh_DSPI_t*)d);
}

static void knh_addConvDSPI(CTX ctx, knh_NameSpace_t *ns, const char *scheme, const knh_ConverterDPI_t *d)
{
	knh_NameSpace_addDSPI(ctx, ns, scheme, (knh_DSPI_t*)d);
}

const knh_PackageLoaderAPI_t* knh_getPackageLoaderAPI(void)
{
	static knh_PackageLoaderAPI_t pkgapi = {
		knh_loadSystemData, knh_loadFuncData,
		loadIntData, loadFloatData, loadStringData,
		loadClassIntConst, loadClassFloatConst, loadStringClassConst,
		setProperty, setIntProperty, setFloatProperty,
		addLink, knh_addStreamDPI, knh_addQueryDSPI, knh_addConvDSPI,
	};
	return &pkgapi;
}

void knh_initBuiltInPackage(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	knh_initClass(ctx, kapi);

}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
