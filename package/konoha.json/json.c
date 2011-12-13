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
//  uh - Yutaro Hiraoka, Yokohama National University, Japan
//  imasahiro - Masahiro Ide, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

#define K_INTERNAL

#define USE_STRUCT_InputStream
#define USE_STRUCT_OutputStream
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <json/json.h>
#include <json/json_object_private.h>

#define CLASSNAME_Json "konoha.json.Json"

#define CLASS_Json \
	knh_getcid(ctx, new_bytes(CLASSNAME_Json))

#define new_Json(ctx, o) \
	new_RawPtr(ctx, ClassTBL(CLASS_Json), o)

#define IS_Json(obj) (obj && !is_error(obj))

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
// [PRIVATE FUNCTIONS]

/* ------------------------------------------------------------------------ */
// translate [json_object -> kObject]
// @return kObject* NOT NULL

static kObject* json_object_json_to_knh(CTX ctx, json_object *obj)
{
	kObject *o = KNH_NULL;
	json_type obj_t = json_object_get_type(obj);
	if (obj_t == json_type_boolean)
	{
		o = (kObject*)new_Boolean(ctx, json_object_get_boolean(obj));
	}
	else if (obj_t == json_type_double)
	{
		o = (kObject*)new_Float(ctx, json_object_get_double(obj));
	}
	else if (obj_t == json_type_int)
	{
		o = (kObject*)new_Int(ctx, json_object_get_int(obj));
	}
	else if (obj_t == json_type_string)
	{
		const char *str = json_object_get_string(obj);
		o = (kObject*)new_String(ctx, str);
	}
	else if (obj_t == json_type_array)
	{
		int i, len = json_object_array_length(obj);
		kArray *a = new_Array0(ctx, len);
		for (i = 0; i < len; i++) {
			json_object *aobj = json_object_array_get_idx(obj, i);
			if (IS_Json(aobj)) {
				knh_Array_add(ctx, a, json_object_json_to_knh(ctx, aobj)); // recursive
			} else {
				DBG_P("Json translate_object", "illegal value of array index(%d) ==> 0");
				knh_Array_add(ctx, a, new_Int(ctx, 0));
			}
		}
		o = (kObject*)a;
	}
	else if (obj_t == json_type_object)
	{
		o = (kObject*)new_Json(ctx, obj);
	}
	else if (obj_t == json_type_null)
	{
		DBG_P("Json translate_object", "type of value is null ==> 0");
		o = (kObject*)new_Int(ctx, 0);
	}
	else
	{
		DBG_P("Json translate_object", "no such type of value: json_type(%d) ==> 0", obj_t);
		o = (kObject*)new_Int(ctx, 0);
	}
	return o;
}

static json_object* json_object_knhary_to_json(CTX ctx, kArray *array, int idx, kclass_t cid, int isGenerics);

/* ------------------------------------------------------------------------ */
// translate [kArray -> json_object]
// @return json_object* NOT NULL

static json_object* json_object_knhary_object_to_json(CTX ctx, kArray *a, kclass_t cid, int isGenerics)
{
	json_object *val = json_object_new_array();
	kclass_t gcid = (isGenerics) ? C_p1(cid) : CLASS_Array;
	int i, len = knh_Array_size(a);
	for (i = 0; i < len; i++) {
		kclass_t acid = (isGenerics) ? gcid : O_cid(a->list[i]);
		json_object *aobj = json_object_knhary_to_json(ctx, a, i, acid, isGenerics);
		if (IS_Json(aobj)) json_object_array_add(val, aobj);
	}
	return val;
}

/* ------------------------------------------------------------------------ */
// translate [kArray[idx] -> json_object]
// @return json_object* or NULL

static json_object* json_object_knhary_to_json(CTX ctx, kArray *array, int idx, kclass_t cid, int isGenerics)
{
	json_object *val = NULL;
	switch (cid) {
	case CLASS_Boolean:
	{
		boolean b = (isGenerics) ? array->ilist[idx] : N_toint(array->list[idx]);
		val = json_object_new_boolean(b);
		break;
	}
	case CLASS_Float:
	{
		double d = (isGenerics) ? array->flist[idx] : N_tofloat(array->list[idx]);
		val = json_object_new_double(d);
		break;
	}
	case CLASS_Int:
	{
		int i = (isGenerics) ? array->ilist[idx] : N_toint(array->list[idx]);
		val = json_object_new_int(i);
		break;
	}
	case CLASS_String:
	{
		kString *s = array->strings[idx];
		val = json_object_new_string_len(S_totext(s), S_size(s));
		break;
	}
	case CLASS_Array:
	{
		kArray *a = (kArray*)array->list[idx];
		val = json_object_knhary_object_to_json(ctx, a, cid, 0);
		break;
	}
	default:
	{
		if (C_bcid(cid) == CLASS_Array)  // case Array Generics:
		{
			kArray *a = (kArray*)array->list[idx];
			val = json_object_knhary_object_to_json(ctx, a, cid, 1);
		}
		else if (O_cid(array->list[idx]) == CLASS_Json) // case Json object:
		{
			kRawPtr *p = (kRawPtr*)array->list[idx];
			val = (json_object*)p->rawptr;
		}
		else
		{
			DBG_P("[WARNING] Json set cannot set this array object");
		}
		break;
	}
	}
	return val;
}

/* ------------------------------------------------------------------------ */
// translate [kObject -> json_object]
// @return json_object* or NULL

static json_object *json_object_knh_to_json(CTX ctx, kObject *o, kunbox_t n)
{
	json_object *val = NULL;
	kclass_t cid = O_cid(o);
	switch (cid) {
	case CLASS_Boolean:
	{
		kbool_t b = (kbool_t) n;
		val = json_object_new_boolean(!(b));
		break;
	}
	case CLASS_Float:
	{
		val = json_object_new_double(N_tofloat(o));
		break;
	}
	case CLASS_Int:
	{
		val = json_object_new_int(N_toint(o));
		break;
	}
	case CLASS_String:
	{
		kString *s = (kString *) o;
		val = json_object_new_string_len(S_totext(s), S_size(s));
		//val = json_object_new_string(S_totext(s));
		break;
	}
	case CLASS_Array:
	{
		kArray *a = (kArray *) o;
		val = json_object_knhary_object_to_json(ctx, a, cid, 0);
		break;
	}
	default:
	{
		if (C_bcid(cid) == CLASS_Array) // case Array Generics:
		{
			kArray *a = (kArray *) o;
			val = json_object_knhary_object_to_json(ctx, a, cid, 1);
		}
		else if (cid == CLASS_Json) // case Json object:
		{
			kRawPtr *p = (kRawPtr *) o;
			val = (json_object*)p->rawptr;
		}
		else
		{
			DBG_P("[WARNING] Json set cannot set this sfp object");
		}
		break;
	}
	}
	return val;
}

/* ======================================================================== */
// [API METHODS]

/* ------------------------------------------------------------------------ */
//## @Static Json Json.new();

KMETHOD Json_new(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = json_object_new_object();
	DBG_P("Json_new[%p]", obj);
	RETURN_(new_ReturnRawPtr(ctx, sfp, obj));
}

/* ------------------------------------------------------------------------ */
//## @Static Json Json.parse(String str);

KMETHOD Json_parse(CTX ctx, ksfp_t *sfp _RIX)
{
	char *buf = String_to(char *, sfp[1]);
	json_object *obj = json_tokener_parse(buf);
	if (!IS_Json(obj)) {
		DBG_P("[ERROR] Json parse failed to parse ==> new Json()");
		obj = json_object_new_object();
	}
	kRawPtr *r = new_Json(ctx, obj);
	RETURN_(r);
}

/* ------------------------------------------------------------------------ */
//## String Json.stringify();

KMETHOD Json_stringify(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	char *obj_str = (char*)json_object_to_json_string(obj);
	RETURN_(new_String(ctx, obj_str));
}

/* ------------------------------------------------------------------------ */
//## dynamic Json.get(String key);

KMETHOD Json_get(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	kObject *o = KNH_NULL;
	if (IS_Json(obj)){
		if (IS_String(sfp[1].o)) {
			char *key = String_to(char *, sfp[1]);
			json_object *val = json_object_object_get(obj, key);
			if (IS_Json(val)) {
				o = json_object_json_to_knh(ctx, val);
				goto RET_SUCCESS;
			} else {
				DBG_P("[WARNING] Json get no such value: this[\"%s\"] ==> 0", key);
			}
		} else {
			DBG_P("[WARNING] Json get invalid type of key ==> 0");
		}
	} else {
		DBG_P("[ERROR] Json get this object is error ==> 0");
	}
	o = (kObject*)new_Int(ctx, 0);
	
	RET_SUCCESS:;
	RETURN_(o);
}

/* ------------------------------------------------------------------------ */
//## void Json.set(String key, dynamic value);

KMETHOD Json_set(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	char *key = String_to(char *, sfp[1]);
	if (IS_Json(obj)) {
		json_object *val = json_object_knh_to_json(ctx, sfp[2].o, sfp[2].ndata);
		if (IS_Json(val)) {
			json_object_object_add(obj, key, val);
		} else {
			DBG_P("[WARNING] Json set cannnot set target object");
		}
	} else {
		DBG_P("[ERROR] Json set this object is error");
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## Boolean Json.opHAS(String key);

KMETHOD Json_opHAS(CTX ctx, ksfp_t *sfp _RIX)
{
	boolean b = 0;
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	char *key = String_to(char *, sfp[1]);
	if (IS_Json(obj)) {
		json_object *val = json_object_object_get(obj, key);
		b = (IS_Json(val));
	} else {
		DBG_P("[ERROR] Json get this object is error");
	}
	RETURNb_(b);
}

/* ------------------------------------------------------------------------ */
//## Array<String> Json.getKeys();

KMETHOD Json_getKeys(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	kArray *a = NULL;
	if (IS_Json(obj)) {
		lh_table *table = json_object_get_object(obj);
		a = new_Array(ctx, CLASS_String, table->count);
		struct lh_entry *entry = table->head;
		while (entry) {
			knh_Array_add(ctx, a, new_String(ctx, (char*)entry->k));
			entry = entry->next;
		}
		//lh_table_free(table); // no need
	} else {
		a = new_Array(ctx, CLASS_String, 0);
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## void Json.delete(String key);

KMETHOD Json_delete(CTX ctx, ksfp_t *sfp _RIX)
{
	json_object *obj = RawPtr_to(json_object *, sfp[0]);
	char *key = String_to(char *, sfp[1]);
	/*
	json_object *tval;
	lh_table *table = json_object_get_object(obj);
	struct lh_entry *entry = table->head;
	while (entry) {
		tval = (struct json_object*)entry->v;
		tval = json_object_put(tval); // decrement
		entry = entry->next;
	}
	*/
	if (IS_Json(obj)) json_object_object_del(obj, key);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//static void _json_set(CTX ctx, kString *str, kObject *o, json_object *json)
//{
//	char *key = (char *) S_totext(str);
//	json_object *val = json_object_knh_to_json(ctx, o, 0);
//	if (IS_Json(val)) {
//		json_object_object_add(json, key, val);
//	} else {
//		DBG_P("[WARNING] Json set cannnot set target object");
//	}
//}
/* ------------------------------------------------------------------------ */
/**
 * XXX
 * Map.toJson() is not thread safe.
 * TODO Thread safe 
 **/
//static int map_index = -1;
//static kString *json_key  = NULL;
//static json_object  *g_json    = NULL;
//static void map_traverse_init(json_object *json)
//{
//	map_index = -1;
//	json_key  = NULL;
//	g_json = json;
//}

/* ------------------------------------------------------------------------ */
//static void map_traverse(CTX ctx, kObject *o)
//{
//	json_object *json = g_json;
//	if (map_index % 2 == 0) {
//		_json_set(ctx, json_key, o, json);
//	} else {
//		json_key = (kString *) o;
//	}
//	map_index++;
//}

/* ------------------------------------------------------------------------ */
//## Json Map.toJson();

KMETHOD Map_toJson(CTX ctx, ksfp_t *sfp _RIX)
{
	//kMap *map = sfp[0].m;
	json_object *json = json_object_new_object();
	kRawPtr *ptr = new_Json(ctx, json);
	//map_traverse_init(json);
	//map->dspi->ftrmap(ctx, map->map, map_traverse);
	RETURN_(ptr);
}

static int _isFirstRead = 1;
static json_object *_json;

KMETHOD Map_toJsonString(CTX ctx, ksfp_t *sfp _RIX)
{
	//kMap *map = sfp[0].m;
	if (unlikely(_isFirstRead)) {
		_json = json_object_new_object();
	}
	//map_traverse_init(_json);
	//map->dspi->ftrmap(ctx, map->map, map_traverse);
	char *buf = (char*)json_object_to_json_string(_json);
	RETURN_(new_String(ctx, buf));
}

/* ======================================================================== */
// [PACK/UNPACK]

static ktype_t json_read(CTX ctx, json_object *json, ksfp_t *sfp)
{
	json_type type = json_object_get_type(json);
	switch (type) {
		case json_type_null:
			KNH_SETv(ctx, sfp[0].o, KNH_NULL);
			return CLASS_Tdynamic;
		case json_type_boolean:
			sfp[0].bvalue = json_object_get_boolean(json);
			return CLASS_Boolean;
		case json_type_int:
			sfp[0].ivalue = json_object_get_int(json);
			return CLASS_Int;
		case json_type_double:
			sfp[0].fvalue = json_object_get_double(json);
			return CLASS_Float;
		case json_type_string:
			KNH_SETv(ctx, sfp[0].o, new_String(ctx, json_object_get_string(json)));
			return CLASS_String;
		case json_type_array:
		{
			size_t i, length = json_object_array_length(json);
			KNH_SETv(ctx, sfp[0].o, new_Array(ctx, CLASS_Tdynamic, length));
			for (i = 0; i < length; ++i) {
				json_object *elem = json_object_array_get_idx(json, i);
				ktype_t type = json_read(ctx, elem, sfp+1);
				knh_boxing(ctx, sfp+1, type);
				knh_Array_add(ctx, sfp[0].a, sfp[1].o);
			}
			return CLASS_Array;
		}
		case json_type_object:
		{
			struct json_object_iter itr = {};
			KNH_SETv(ctx, sfp[0].o, new_DataMap(ctx));
			json_object_object_foreachC(json, itr) {
				ktype_t type = json_read(ctx, itr.val, sfp+1);
				knh_boxing(ctx, sfp+1, type);
				klr_setesp(ctx, sfp+2);
				knh_DataMap_set(ctx, sfp[0].m, new_String(ctx, itr.key), sfp[1].o);
			}
			return CLASS_Map;
		}
	}
	return CLASS_Tvoid;
}

static ktype_t json_unpackTo(CTX ctx, const char *buf, size_t size, ksfp_t *sfp)
{
	ktype_t type = CLASS_Tvoid;
	if (size > 0) {
		json_tokener *tok = json_tokener_new();
		json_object *json = json_tokener_parse_ex(tok, buf, size);
		if (tok->err != json_tokener_success) {
			KNH_NTRACE2(ctx, "json_unpack", K_FAILED,
					KNH_LDATA(LOG_i("json_tokener_error", tok->err)));
		} else {
			type = json_read(ctx, json, sfp);
			json_object_put(json);
		}
		json_tokener_free(tok);
	}
	return type;
}

static void *json_init(CTX ctx, kpackAPI_t *pk)
{
	return pk;
}

static void json_flushfree(CTX ctx, kpackAPI_t *pk)
{
	knh_OutputStream_flush(ctx, pk->w); /* TODO need flush? */
}

#define W(pkp) (((kpackAPI_t*)pkp)->w)
static void json_null(CTX ctx, void *pkp)
{
	kbytes_t t = STEXT("null");
	knh_OutputStream_write(ctx, W(pkp), t);
}

static void json_bool(CTX ctx, void *pkp, int b)
{
	kbytes_t t = STEXT("true");
	kbytes_t f = STEXT("false");
	knh_OutputStream_write(ctx, W(pkp), (b)?t:f);
}

static void json_int(CTX ctx, void *pkp, kint_t i)
{
	knh_write_ifmt(ctx, W(pkp), KINT_FMT, i);
}

static void json_float(CTX ctx, void *pkp, kfloat_t f)
{
	knh_write_ffmt(ctx, W(pkp), KFLOAT_FMT, f);
}

static void json_string(CTX ctx, void *pkp, const char *str, size_t len)
{
	kbytes_t t = {{str}, len};
	knh_putc(ctx, W(pkp), '"');
	knh_write(ctx, W(pkp), t);
	knh_putc(ctx, W(pkp), '"');
}

static void json_raw(CTX ctx, void *pkp, const char *str, size_t len)
{
	kbytes_t t = {{str}, len};
	knh_putc(ctx, W(pkp), '"');
	knh_write(ctx, W(pkp), t);
	knh_putc(ctx, W(pkp), '"');
}

static void json_putc(CTX ctx, void *pkp, int ch)
{
	knh_putc(ctx, W(pkp), ch);
}

static void json_array(CTX ctx, void *pkp, size_t array_size)
{
	knh_putc(ctx, W(pkp), '[');
}

static void json_array_end(CTX ctx, void *pkp)
{
	knh_putc(ctx, W(pkp), ']');
}

static void json_map(CTX ctx, void *pkp, size_t map_size)
{
	knh_putc(ctx, W(pkp), '{');
}

static void json_map_end(CTX ctx, void *pkp)
{
	knh_putc(ctx, W(pkp), '}');
}
#undef W

static const knh_PackSPI_t pack = {
	"json",
	json_init,
	json_flushfree,
	json_null,
	json_bool,
	json_int,
	json_float,
	json_string,
	json_raw,
	json_putc,
	json_array,
	json_array_end,
	json_map,
	json_map_end,
	json_unpackTo,
};

static void RETURN_T(CTX ctx, ksfp_t *sfp, kclass_t scid, kclass_t tcid, ksfp_t *vsfp _RIX)
{
	if(tcid != scid) {
		kTypeMap *tmr = knh_findTypeMapNULL(ctx, scid, tcid);
		if(tmr != NULL) {
			klr_setesp(ctx, vsfp+1);
			knh_TypeMap_exec(ctx, tmr, vsfp, sfp - vsfp + K_RIX);
			return;
		}
		else {
			sfp[K_RIX].ivalue = 0;
			RETURN_(KNH_NULVAL(tcid));
		}
	}
	sfp[K_RIX].ndata = vsfp[0].ndata;
	RETURN_(vsfp[0].o);
}

//## method @Native @Public Tvar InputStream.readJson(Class _);

KMETHOD InputStream_readJson(CTX ctx, ksfp_t *sfp _RIX)
{
	kInputStream *in = sfp[0].in;
	const knh_PackSPI_t *packspi = &pack;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	io2_readAll(ctx, in->io2, cwb->ba);
	kbytes_t blob = CWB_tobytes(cwb);
	ktype_t type = packspi->unpack(ctx, blob.text, blob.len, sfp+2);
	CWB_close(ctx, cwb);
	RETURN_T(ctx, sfp, type, (sfp[1].c)->cid, sfp+2, K_RIX);
}

//## method @Native @Public void OutputStream.writeJson(Object data);

KMETHOD OutputStream_writeJson(CTX ctx, ksfp_t *sfp _RIX)
{
	kOutputStream *w = sfp[0].w;
	kRawPtr *o = sfp[1].p;
	const knh_PackSPI_t *packspi = &pack;
	kpackAPI_t packer = {w, NULL, NULL};
	kpackAPI_t *pkr = packspi->pack_init(ctx, &packer);
	O_cTBL(o)->cdef->wdata(ctx, o, pkr, packspi);
	packspi->pack_flushfree(ctx, pkr);
	RETURNvoid_();
}

//## method @Native @Public void Bytes.writeJson(Object data);

KMETHOD Bytes_writeJson(CTX ctx, ksfp_t *sfp _RIX)
{
	kRawPtr *o = sfp[1].p;
	const knh_PackSPI_t *packspi = &pack;
	KNH_SETv(ctx, sfp[0].o, new_BytesOutputStream(ctx, sfp[0].ba));
	kpackAPI_t packer = {sfp[0].w, NULL, NULL};
	kpackAPI_t *pkr = packspi->pack_init(ctx, &packer);
	O_cTBL(o)->cdef->wdata(ctx, o, pkr, packspi);
	packspi->pack_flushfree(ctx, pkr);
	RETURNvoid_();
}

//## method @Native @Public Tvar Bytes.readJson(int offset, int len, Class _);

KMETHOD Bytes_readJson(CTX ctx, ksfp_t *sfp _RIX)
{
	kbytes_t b = BA_tobytes(sfp[0].ba);
	if(sfp[1].ivalue > 0 && sfp[1].ivalue < b.len) {
		b.text = b.text + (size_t)sfp[1].ivalue;
		b.len  = b.len - (size_t)sfp[1].ivalue;
	}
	if(sfp[2].ivalue > 0 && sfp[2].ivalue < b.len) {
		b.len = (size_t)sfp[2].ivalue;
	}
	const knh_PackSPI_t *packspi = &pack;
	ktype_t type = packspi->unpack(ctx, b.text, b.len, sfp+4);
	RETURN_T(ctx, sfp, type, (sfp[3].c)->cid, sfp+4, K_RIX);
}


/* ======================================================================== */
// [DEFAPI]

#ifdef _SETUP

static void Json_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void Json_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		DBG_P("Json_free[%p]", po->rawptr);
		json_object_put((json_object *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defJson(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Json";
	cdef->init = Json_init;
	cdef->free = Json_free;
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.json");
}

#endif /* _SETUP */

/* ======================================================================== */

#ifdef __cplusplus
}
#endif
