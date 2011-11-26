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

#define USE_STRUCT_InputStream
#define USE_STRUCT_OutputStream

#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

///* ------------------------------------------------------------------------ */
////## void Bytes.putc(Int char);
//
//static KMETHOD Bytes_putc(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kBytes *o = (kBytes*)sfp[0].o;
//	knh_Bytes_putc(ctx, o, Int_to(size_t, sfp[1]));
//	RETURNvoid_();
//}
//
///* ------------------------------------------------------------------------ */
////## void Bytes.write(BytesIm buf, Int offset, Int length);
////## void Bytes.add(BytesIm buf, Int offset, Int length);
//
//static KMETHOD Bytes_write(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kBytes *ba = sfp[0].ba;
//	kbytes_t t = BA_tobytes(sfp[1].ba);
//	if(sfp[2].ivalue != 0) {
//		size_t n = knh_array_index(ctx, sfp, Int_to(kint_t, sfp[2]), t.len);
//		t = knh_bytes_last(t, n);
//	}
//	if(sfp[3].ivalue != 0) {
//		size_t l = Int_to(size_t, sfp[3]);
//		if(l < t.len) t.len = l;
//	}
//	knh_Bytes_write(ctx, ba, t);
//	RETURNvoid_();
//}

/* ------------------------------------------------------------------------ */

#ifdef _SETUP

static knh_IntData_t SystemConstInt[] = {
		{"EOF", -1},
		{NULL, 0}
};

extern const knh_ConverterDPI_t* knh_getMD5Converter();

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_System, SystemConstInt);
	kapi->setPackageProperty(ctx, "msgpack.version", msgpack_version());
	kapi->addConverterDPI(ctx, "md5", knh_getMD5Converter(), NULL);
	RETURN_PKGINFO("konoha.io");
}

#endif

#ifdef __cplusplus
}
#endif
