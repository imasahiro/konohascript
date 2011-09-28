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
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

#define K_INTERNAL
#include <konoha1.h>
#include <oauth.h>

#ifdef __cplusplus
extern "C" {
#endif

static knh_Map_t *parseReply(CTX ctx, char *reply)
{
	int rc;
	char **rv = NULL;
	knh_Map_t *ret = NULL;
	DBG_P("HTTP-reply:%s", reply);
	rc = oauth_split_url_parameters(reply, &rv);
	knh_qsort(rv, rc, sizeof(char *), oauth_cmpstringp);
	if (rv != NULL) {
		ret = new_DataMap(ctx);
		const char *key, *val;
		int i;
		for (i = 0; i < rc; i++) {
			DBG_P("rv[%d]=%s", i, rv[i]);
			val = strchr(rv[i], '=');
			if (val != NULL) {
				val += 1;
				key = rv[i];
				rv[i][val - rv[i] - 1] = '\0';
				knh_DataMap_setString(ctx, ret, key, val);
			}
			free(rv[i]);
		}
		free(rv);
	}
	return ret;
}

/* ------------------------------------------------------------------------ */

//# @Native Map<String,String> Client_request(String url, String method);
KMETHOD Client_request(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *consumer = sfp[0].ox->fields[0];
	knh_Object_t *rtoken = sfp[0].ox->fields[1];
	knh_Map_t *ret = NULL;
	const char *url = String_to(const char *, sfp[1]);
	char url2[256] = {0};
	const char *method = IS_NULL(sfp[2].o) ? NULL : String_to(const char *, sfp[2]);
	const char *consumer_key = NULL;
	const char *consumer_secret = NULL;
	const char *request_token = NULL;
	const char *request_token_secret = NULL;

	if (!IS_NULL(consumer)) {
		knh_ObjectField_t *of = (knh_ObjectField_t *)consumer;
		consumer_key = S_totext((knh_String_t*)of->fields[0]);
		consumer_secret = S_totext((knh_String_t*)of->fields[1]);
	}
	if (!IS_NULL(rtoken)) {
		knh_ObjectField_t *of = (knh_ObjectField_t *)rtoken;
		request_token = S_totext((knh_String_t *)of->fields[0]);
		request_token_secret = S_totext((knh_String_t *)of->fields[1]);
		if (!IS_NULL(of->fields[2])) {
			strncat(url2, url, knh_strlen(url));
			strncat(url2, "?oauth_verifier=", 16);
			knh_String_t *verifier = (knh_String_t *)of->fields[2];
			if (knh_strlen(url2) + S_size(verifier) < 256) {
				strncat(url2, S_totext(verifier), S_size(verifier));
			}
			url = url2;
		}
	}

	DBG_P("consumer_key: %s, consumer_secret: %s", consumer_key, consumer_secret);
	DBG_P("request_token: %s, request_token_secret: %s", request_token == NULL ? "NULL" : request_token , request_token_secret == NULL ? "NULL" : request_token_secret);
	DBG_P("url: %s", url);

	char *reply = NULL;
	if (method != NULL && knh_strncmp(method, "POST", 5)) {
		char *postargs = NULL;
		char *req_url = oauth_sign_url2(
				url, // url
				&postargs, // postargs
				OA_HMAC, // method
				NULL, // http_method
				consumer_key, // c_key
				consumer_secret, // c_secret
				request_token, // t_key
				request_token_secret // t_secret
				);
		DBG_P("request URL:%s", req_url);
		reply = oauth_http_post(req_url, postargs);
		if (postargs) free(postargs);
		if (req_url) free(req_url);
	} else {
		char *req_url = oauth_sign_url2(
				url, // url
				NULL, // postargs
				OA_HMAC, // method
				NULL, // http_method
				consumer_key, // c_key
				consumer_secret, // c_secret
				request_token, // t_key
				request_token_secret // t_secret
				);
		DBG_P("request URL:%s", req_url);
		reply = oauth_http_get(req_url, NULL);
		if (req_url) free(req_url);
	}

	if (!reply) {
		// failed
		DBG_P("HTTP request for an oauth request-token failed.");
	} else {
		// parse reply
		ret = parseReply(ctx, reply);
		free(reply);
	}

	if (ret) {
		RETURN_(ret);
	} else {
		RETURN_(new_DataMap(ctx));
	}
}

/* ------------------------------------------------------------------------ */

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.liboauth");
}

#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
