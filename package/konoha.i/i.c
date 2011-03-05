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
//
// **************************************************************************

/* inlinelibs */
//#define USE_B
//#define USE_STEXT
//#define USE_bytes_strcmp
//#define USE_cwb_tobytes
//#define USE_cwb_size

#include <konoha1.h>

#ifdef __cplusplus 
extern "C" {
#endif

#ifdef _SETUP

//static knh_FloatData_t FloatConstData[] = {
//	{"Math.E", M_E},
//	{"Math.LOG2E",M_LOG2E},
//	{"Math.LOG10E",M_LOG10E},
//	{"Math.LN2",M_LN2},
//	{"Math.LN10",M_LN10},
//	{"Math.PI", M_PI},
//	{"Math.PI_2",M_PI_2},
//	{"Math.PI_4",M_PI_4},
//	{"Math.SQRT2",M_SQRT2},
//	{NULL, K_FLOAT_ZERO}
//};


const knh_PackageDef_t* setup(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
{
	static const knh_PackageDef_t pkgdef =
		KNH_PKGINFO("i", "1.0", "Konoha Shell Extension", NULL);
	if(ns == NULL) {
		kapi->loadFloatData(ctx, FloatConstData);
	}
	return &pkgdef;
}
#endif



#ifdef __cplusplus
}
#endif

