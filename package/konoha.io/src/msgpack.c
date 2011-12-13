/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us
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

#include <msgpack.h>

#define K_INTERNAL 1
#define USE_STRUCT_InputStream
#define USE_STRUCT_OutputStream

#include <konoha1.h>
#include <konoha1/inlinelibs.h>

#ifdef __cplusplus
extern "C" {
#endif

static void *msgpack_init(CTX ctx, kpackAPI_t *pk)
{
	pk->sbuffer = msgpack_sbuffer_new();
	pk->pk = msgpack_packer_new(pk->sbuffer, msgpack_sbuffer_write);
	return pk;
}

static void msgpack_flushfree(CTX ctx, kpackAPI_t *pk)
{
	msgpack_sbuffer *sbuffer = pk->sbuffer;
	kbytes_t t = {{sbuffer->data}, sbuffer->size};
	knh_OutputStream_write(ctx, pk->w, t);
	knh_OutputStream_flush(ctx, pk->w); /* TODO need flush? */
	msgpack_sbuffer_free(pk->sbuffer);
	msgpack_packer_free(pk->pk);
}

static void msgpack_null(CTX ctx, void *pkp)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_nil(pk->pk);
}

static void msgpack_bool(CTX ctx, void *pkp, int b)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	(b) ? msgpack_pack_true(pk->pk) : msgpack_pack_false(pk->pk);
}

static void msgpack_int(CTX ctx, void *pkp, kint_t i)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_int64(pk->pk, i);
}

static void msgpack_float(CTX ctx, void *pkp, kfloat_t f)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_double(pk->pk, f);
}

static void msgpack_string(CTX ctx, void *pkp, const char *str, size_t len)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_raw(pk->pk, len + 1);
	msgpack_pack_raw_body(pk->pk, str, len + 1);
}

static void msgpack_raw(CTX ctx, void *pkp, const char *str, size_t len)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_raw(pk->pk, len + 1);
	msgpack_pack_raw_body(pk->pk, str, len + 1);
}

static void msgpack_putc(CTX ctx, void *pk, int ch)
{
}

static void msgpack_array(CTX ctx, void *pkp, size_t array_size)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_array(pk->pk, array_size);
}

static void msgpack_array_end(CTX ctx, void *pkp)
{
}

static void msgpack_map(CTX ctx, void *pkp, size_t map_size)
{
	kpackAPI_t *pk = (kpackAPI_t *)pkp;
	msgpack_pack_map(pk->pk, map_size);
}

static void msgpack_map_end(CTX ctx, void *pkp)
{
}

static ktype_t msgpack_read(CTX ctx, msgpack_object obj, ksfp_t *sfp)
{
	switch (obj.type) {
	case MSGPACK_OBJECT_NIL:
		KNH_SETv(ctx, sfp[0].o, KNH_NULL);
		return CLASS_Tdynamic;
	case MSGPACK_OBJECT_BOOLEAN:
		sfp[0].bvalue = obj.via.boolean;
		return CLASS_Boolean;
	case MSGPACK_OBJECT_NEGATIVE_INTEGER:
		sfp[0].ivalue = obj.via.i64;
		return CLASS_Int;
	case MSGPACK_OBJECT_POSITIVE_INTEGER:
		sfp[0].uvalue = obj.via.u64;
		return CLASS_Int;
	case MSGPACK_OBJECT_DOUBLE:
		sfp[0].fvalue = obj.via.dec;
		return CLASS_Float;
	case MSGPACK_OBJECT_RAW:
		KNH_SETv(ctx, sfp[0].o, new_String(ctx, obj.via.raw.ptr));
		return CLASS_String;
	case MSGPACK_OBJECT_ARRAY:
	{
		msgpack_object *a = obj.via.array.ptr;
		size_t asize = obj.via.array.size;
		const msgpack_object *array_end = obj.via.array.ptr + asize;
		KNH_SETv(ctx, sfp[0].o, new_Array(ctx, CLASS_Tdynamic, asize));
		for (; a < array_end; a++) {
			ktype_t type = msgpack_read(ctx, *a, sfp+1);
			knh_boxing(ctx, sfp+1, type);
			knh_Array_add(ctx, sfp[0].a, sfp[1].o);
		}
		return CLASS_Array;
	}
	case MSGPACK_OBJECT_MAP:
		{
			if (obj.via.map.size == 0) break;
			msgpack_object_kv *map = obj.via.map.ptr;
			msgpack_object_kv *map_end = obj.via.map.ptr + obj.via.map.size;
			KNH_SETv(ctx, sfp[0].o, new_DataMap(ctx/*, obj.via.map.size*/));
			for (; map < map_end; map++) {
				const char *key = map->key.via.raw.ptr;
				ktype_t type = msgpack_read(ctx, map->val, sfp+1);
				knh_boxing(ctx, sfp+1, type);
				klr_setesp(ctx, sfp+2);
				knh_DataMap_set(ctx, sfp[0].m, new_String(ctx, key), sfp[1].o);
			}
			return CLASS_Map;
		}
	}
	return CLASS_Tvoid;
}

static ktype_t msgpack_unpackTo(CTX ctx, const char *buf, size_t size, ksfp_t *sfp)
{
	ktype_t type;
	msgpack_unpacker upk;
	msgpack_unpacked result;
	msgpack_unpacker_init(&upk, MSGPACK_UNPACKER_INIT_BUFFER_SIZE);
	msgpack_unpacker_reserve_buffer(&upk, size);
	memcpy(msgpack_unpacker_buffer(&upk), buf, size);
	msgpack_unpacker_buffer_consumed(&upk, size);
	msgpack_unpacked_init(&result);
	msgpack_unpacker_next(&upk, &result);
	type = msgpack_read(ctx, result.data, sfp);
	msgpack_unpacker_destroy(&upk);
	msgpack_unpacked_destroy(&result);
	return type;
}

static const knh_PackSPI_t pack = {
	"msgpack",
	msgpack_init,
	msgpack_flushfree,
	msgpack_null,
	msgpack_bool,
	msgpack_int,
	msgpack_float,
	msgpack_string,
	msgpack_raw,
	msgpack_putc,
	msgpack_array,
	msgpack_array_end,
	msgpack_map,
	msgpack_map_end,
	msgpack_unpackTo,
};

static const knh_PackSPI_t *knh_getMsgPackSPI()
{
	return &pack;
}

//## method void OutputStream.writeMsgPack(Object data);

KMETHOD OutputStream_writeMsgPack(CTX ctx, ksfp_t *sfp _RIX)
{
	kOutputStream *w = sfp[0].w;
	kRawPtr *o = sfp[1].p;
	const knh_PackSPI_t *packspi = knh_getMsgPackSPI();
	kpackAPI_t packer = {w, NULL, NULL};
	kpackAPI_t *pkr = packspi->pack_init(ctx, &packer);
	O_cTBL(o)->cdef->wdata(ctx, o, pkr, packspi);
	packspi->pack_flushfree(ctx, pkr);
	RETURNvoid_();
}

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

//## method Tvar InputStream.readMsgPack(Class _);

KMETHOD InputStream_readMsgPack(CTX ctx, ksfp_t *sfp _RIX)
{
	kInputStream *in = sfp[0].in;
	const knh_PackSPI_t *packspi = knh_getMsgPackSPI();
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	io2_readAll(ctx, in->io2, cwb->ba);
	kbytes_t blob = CWB_tobytes(cwb);
	ktype_t type = packspi->unpack(ctx, blob.text, blob.len, sfp+2);
	CWB_close(ctx, cwb);
	RETURN_T(ctx, sfp, type, (sfp[1].c)->cid, sfp+2, K_RIX);
}

//## method void Bytes.writeMsgPack(Object data);

KMETHOD Bytes_writeMsgPack(CTX ctx, ksfp_t *sfp _RIX)
{
	kRawPtr *o = sfp[1].p;
	const knh_PackSPI_t *packspi = knh_getMsgPackSPI();
	KNH_SETv(ctx, sfp[0].o, new_BytesOutputStream(ctx, sfp[0].ba));
	kpackAPI_t packer = {sfp[0].w, NULL, NULL};
	kpackAPI_t *pkr = packspi->pack_init(ctx, &packer);
	O_cTBL(o)->cdef->wdata(ctx, o, pkr, packspi);
	packspi->pack_flushfree(ctx, pkr);
	RETURNvoid_();
}

//## method Tvar Bytes.readMsgPack(int offset, int len, Class _);

KMETHOD Bytes_readMsgPack(CTX ctx, ksfp_t *sfp _RIX)
{
	kbytes_t b = BA_tobytes(sfp[0].ba);
	if(sfp[1].ivalue > 0 && sfp[1].ivalue < b.len) {
		b.text = b.text + (size_t)sfp[1].ivalue;
		b.len  = b.len - (size_t)sfp[1].ivalue;
	}
	if(sfp[2].ivalue > 0 && sfp[2].ivalue < b.len) {
		b.len = (size_t)sfp[2].ivalue;
	}
	const knh_PackSPI_t *packspi = knh_getMsgPackSPI();
	ktype_t type = packspi->unpack(ctx, b.text, b.len, sfp+4);
	RETURN_T(ctx, sfp, type, (sfp[3].c)->cid, sfp+4, K_RIX);
}

#ifdef __cplusplus
}
#endif
