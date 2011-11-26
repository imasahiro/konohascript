/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-		 Konoha Team konohaken@googlegroups.com
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
//	goccy -
//	kimio - Kimio Kuramitsu, Yokohama National University, Japan
//
// **************************************************************************

#include <konoha1.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "../third-party/ext/md5.h"

#define MD5_DIGEST_LENGTH 16

static kbool_t md5digest(CTX ctx, knh_conv_t *conv, const char* buf, size_t len, kBytes *tobuf)
{
	MD5_CTX md5_ctx;
	unsigned char md5buf[MD5_DIGEST_LENGTH] = {0};
	MD5_Init(&md5_ctx);
	MD5_Update(&md5_ctx, (char*)buf, len);
	MD5_Final(md5buf, &md5_ctx);
	knh_Bytes_write2(ctx, tobuf, (char*)md5buf, MD5_DIGEST_LENGTH);
	return 1;
}

static kbool_t md5string(CTX ctx, knh_conv_t *conv, const char* buf, size_t len, kBytes *tobuf)
{
	MD5_CTX md5_ctx;
	unsigned char md5buf[MD5_DIGEST_LENGTH] = {0};
	MD5_Init(&md5_ctx);
	MD5_Update(&md5_ctx, (char*)buf, len);
	MD5_Final(md5buf, &md5_ctx);
	{
		char dbuf[4];
		size_t i;
		for (i = 0; i< MD5_DIGEST_LENGTH; i++) {
			knh_snprintf(dbuf, sizeof(dbuf), "%02x", md5buf[i]);
			knh_Bytes_write2(ctx, tobuf, dbuf, 2);
		}
	}
	return 1;
}

static const knh_ConverterDPI_t md5Converter = {
	K_DSPI_CONVTO, "md5",
	NULL,
	md5digest,  // byte->byte     :conv
	md5digest,  // String->byte   :enc
	md5string,  // byte->String   :dec
	md5string,  // String->String :sconv
	NULL,
	NULL
};

const knh_ConverterDPI_t* knh_getMD5Converter()
{
	return &md5Converter;
}
