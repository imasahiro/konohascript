///****************************************************************************
// * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
// *
// * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
// * All rights reserved.
// *
// * You may choose one of the following two licenses when you use konoha.
// * See www.konohaware.org/license.html for further information.
// *
// * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
// * (2) Konoha Software Foundation License 1.0
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
// * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
// ****************************************************************************/
//
//// **************************************************************************
//// LIST OF CONTRIBUTERS
////  goccy -
////  kimio - Kimio Kuramitsu, Yokohama National University, Japan
////
//// **************************************************************************
//
//#include <konoha1.h>
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//#define BASE64_LINESIZE 64
//static const unsigned char alphabet[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//#define EOL '\0'
//
//static kbool_t base64_enc(CTX ctx, knh_conv_t *conv, kbytes_t from, kBytes *tobuf)
//{
//	int cols, bits, c, char_count;
//	char f[BASE64_LINESIZE] = {0};
//	char t[BASE64_LINESIZE] = {0};
//	sprintf(f, "%s", (char *)from.buf);
//	char_count = 0;
//	bits = 0;
//	cols = 0;
//	int i = 0;
//	int j = 0;
//	while ((c = f[i]) != EOL) {
//		if (c > 255) {
//			DBG_P("encountered char > 255 (decimal %d)", c);
//		}
//		bits += c;
//		char_count++;
//		if (char_count == 3) {
//			t[j] = alphabet[bits >> 18];
//			t[j + 1] = alphabet[(bits >> 12) & 0x3f];
//			t[j + 2] = alphabet[(bits >> 6) & 0x3f];
//			t[j + 3] = alphabet[bits & 0x3f];
//			j += 4;
//			cols += 4;
//			if (cols == 72) {
//				putchar('\n');
//				cols = 0;
//				t[j] = '\n';
//				j++;
//			}
//			bits = 0;
//			char_count = 0;
//		} else {
//			bits <<= 8;
//		}
//		i++;
//	}
//
//	if (char_count != 0) {
//		bits <<= 16 - (8 * char_count);
//		t[j] = alphabet[bits >> 18];
//		t[j + 1] = alphabet[(bits >> 12) & 0x3f];
//		j += 2;
//		if (char_count == 1) {
//			t[j] = '=';
//			t[j + 1] = '=';
//			j += 2;
//		} else {
//			t[j] = alphabet[(bits >> 6) & 0x3f];
//			t[j + 1] = '=';
//			j += 2;
//		}
//		if (cols > 0) {
//			t[j] = '\n';
//			j += 1;
//		}
//	}
//	knh_write(ctx, tobuf, t, strlen(t));
//	return 1;
//}
//
//static kbool_t base64_dec(CTX ctx, knh_conv_t *conv, kbytes_t from, kBytes *tobuf)
//{
//	static char inalphabet[256], decoder[256];
//	int i, bits, c, char_count, errors = 0;
//	char f[BASE64_LINESIZE] = {0};
//	char t[BASE64_LINESIZE] = {0};
//	sprintf(f, "%s", (char *)from.buf);
//
//	for (i = (sizeof alphabet) - 1; i >= 0 ; i--) {
//		inalphabet[alphabet[i]] = 1;
//		decoder[alphabet[i]] = i;
//	}
//
//	char_count = 0;
//	bits = 0;
//	i = 0;
//	int j = 0;
//
//	while ((c = f[i]) != EOL) {
//		if (c == '=')
//			break;
//		if (c > 255 || ! inalphabet[c]) {
//			continue;
//		}
//		bits += decoder[c];
//		char_count++;
//		if (char_count == 4) {
//			t[j] = bits >> 16;
//			t[j + 1] = (bits >> 8) & 0xff;
//			t[j + 2] = bits & 0xff;
//			j += 3;
//			bits = 0;
//			char_count = 0;
//		} else {
//			bits <<= 6;
//		}
//		i++;
//	}
//	if (c == EOL) {
//		if (char_count) {
//			DBG_P("base64 encoding incomplete: at least %d bits truncated",
//					((4 - char_count) * 6));
//			errors++;
//		}
//	} else { /* c == '=' */
//		switch (char_count) {
//		case 1:
//			DBG_P("base64 encoding incomplete: at least 2 bits missing");
//			errors++;
//			break;
//		case 2:
//			t[j] = bits >> 10;
//			j++;
//			break;
//		case 3:
//			t[j] = bits >> 16;
//			t[j + 1] = (bits >> 8) & 0xff;
//			j += 2;
//			break;
//		}
//	}
//	knh_write(ctx, tobuf, t, strlen(t));
//	return 1;
//}
//
//static void base64_close(CTX ctx, knh_conv_t *conv)
//{
//
//}
//
//static knh_ConverterDSPI_t CONVTO_base64 = {
//		K_CONVTO_DSPI, "base64",
//		NULL, //base64_open,
//		base64_enc,  // byte->byte     :conv
//		base64_enc,  // String->byte   :enc
//		base64_enc,  // byte->String   :dec
//		base64_enc,  // String->String :sconv
//		base64_close,
//		NULL
//};
//
//static knh_ConverterDSPI_t CONVFROM_base64 = {
//		K_CONVFROM_DSPI, "base64",
//		NULL, //base64_open,
//		base64_dec,  // byte->byte     :conv
//		base64_dec,  // String->byte   :enc
//		base64_dec,  // byte->String   :dec
//		base64_dec,  // String->String :sconv
//		base64_close,
//		NULL,
//};
//
//void string_addBase64(CTX ctx, knh_LoaderAPI_t *kapi, char *dname, int isOVERRIDE)
//{
//	if(knh_isSelectedDSPI(dname, "base64")) {
//		kapi->addConverterDSPI(ctx, "base64", &CONVTO_base64, isOVERRIDE);
//		kapi->addConverterDSPI(ctx, "base64", &CONVFROM_base64, isOVERRIDE);
//	}
//}
//
//#ifdef __cplusplus
//}
//#endif

