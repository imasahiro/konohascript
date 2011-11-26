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

/* ======================================================================== */
// [struct]

typedef struct {
	const char *key;
	const char *secret;
	const char *rtoken;
	const char *rtoken_secret;
} AccessToken_t;

typedef struct {
	int argc;
	char **argv;
} Args_t;

/* ------------------------------------------------------------------------ */
// [private functions]

static void knh_freeArgs(Args_t *args)
{
	oauth_free_array(&args->argc, &args->argv);
}

static kMap *knh_parseReply(CTX ctx, char *reply)
{
	int rc;
	char **rv = NULL;
	kMap *rmap = NULL;
	DBG_P("HTTP-reply: %s", reply);
	rc = oauth_split_url_parameters(reply, &rv);
	knh_qsort(rv, rc, sizeof(char *), oauth_cmpstringp);
	if (rv != NULL) {
		rmap = new_DataMap(ctx);
		const char *key, *val;
		int i;
		for (i = 0; i < rc; i++) {
			DBG_P("rv[%d]=%s", i, rv[i]);
			val = strchr(rv[i], '=');
			if (val != NULL) {
				val += 1;
				key = rv[i];
				rv[i][val - rv[i] - 1] = '\0';
				knh_DataMap_setString(ctx, rmap, key, val);
			}
			free(rv[i]);
		}
		free(rv);
	}
	return rmap;
}

static void knh_getToken(ksfp_t *sfp, AccessToken_t *token)
{
	kObject *consumer = sfp[0].ox->fields[0];
	kObject *rtoken = sfp[0].ox->fields[1];
	if (IS_NOTNULL(consumer)) {
		kObject *of = (kObject *)consumer;
		token->key = S_totext((kString*)of->fields[0]);
		token->secret = S_totext((kString*)of->fields[1]);
	}
	if (IS_NOTNULL(rtoken)) {
		kObject *of = (kObject *)rtoken;
		token->rtoken = S_totext((kString *)of->fields[0]);
		token->rtoken_secret = S_totext((kString *)of->fields[1]);
	}
	DBG_P("consumer_key: %s, consumer_secret: %s", token->key, token->secret);
	DBG_P("request_token: %s, request_token_secret: %s", token->rtoken, token->rtoken_secret);
}

static char *knh_request(Args_t *args, const char *method, AccessToken_t *token)
{
	char *reply = NULL;
	if (knh_strncmp(method, "POST", 5) == 0) {
		char *postargs = NULL;
		char *req_url = oauth_sign_array2(
				&args->argc, // argcp
				&args->argv, // argvp
				&postargs, // postargs
				OA_HMAC, // method
				NULL, // http_method
				token->key, // c_key
				token->secret, // c_secret
				token->rtoken, // t_key
				token->rtoken_secret // t_secret
				);
		DBG_P("request URL(POST): %s?%s", req_url, postargs);
		reply = oauth_http_post(req_url, postargs);
		if (postargs) free(postargs);
		if (req_url) free(req_url);
	} else {
		char *req_url = oauth_sign_array2(
				&args->argc, // argcp
				&args->argv, // argvp
				NULL, // postargs
				OA_HMAC, // method
				NULL, // http_method
				token->key, // c_key
				token->secret, // c_secret
				token->rtoken, // t_key
				token->rtoken_secret // t_secret
				);
		DBG_P("request URL(GET): %s", req_url);
		reply = oauth_http_get(req_url, NULL);
		if (req_url) free(req_url);
	}
	return reply;
}

static void knh_setArgs(CTX ctx, Args_t *args, kMap *m)
{
	kDictMap *dmap = knh_toDictMap(ctx, m, 0);
	ksfp_t *lsfp = ctx->esp;
	knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	char buf[256] = {0};
	while(m->spi->next(ctx, m->mapptr, mitr, lsfp)) {
		const char *key = S_totext(lsfp[0].s);
		Object *o = knh_DictMap_getNULL(ctx, dmap, S_tobytes(lsfp[0].s));
		switch (O_cid(o)) {
		case CLASS_Int:
			knh_snprintf(buf, sizeof(buf), "%s=" KINT_FMT, key, N_toint(o));
			break;
		case CLASS_Float:
			knh_snprintf(buf, sizeof(buf), "%s=" KFLOAT_FMT, key, N_tofloat(o));
			break;
		case CLASS_Boolean:
			knh_snprintf(buf, sizeof(buf), "%s=%s",
					key, N_tobool(o) ? "true" : "false");
			break;
		case CLASS_String:
			knh_snprintf(buf, sizeof(buf), "%s=%s", key, S_totext((kString *)o));
			break;
		default:
			TODO();
			break;
		}
		DBG_P("m[%s] = {class:%s, struct:%s, o:%s}", S_totext(lsfp[0].s),
				CLASS__(O_cid(o)), STRUCT__(O_bcid(o)), O__(o));
		if (knh_strlen(buf) > 0) {
			DBG_P("param: \"%s\"", buf);
			oauth_add_param_to_array(&args->argc, &args->argv, buf);
		}
		buf[0] = '\0';
		klr_setesp(ctx, lsfp+1);
	}
}

/* ======================================================================== */
// [KMETHODS]

//## @Native Map<String,String> Client_request(String url, String method, Map params);
KMETHOD Client_request(CTX ctx, ksfp_t *sfp _RIX)
{
	kMap *rmap = NULL;
	AccessToken_t token = {NULL, NULL, NULL, NULL};
	Args_t args = {0, NULL};
	args.argc = oauth_split_url_parameters(String_to(const char *, sfp[1]), &args.argv);
	const char *method = String_to(const char *, sfp[2]);

	if (IS_NOTNULL(sfp[3].o)) {
		knh_setArgs(ctx, &args, sfp[3].m);
	}

	DBG_P("url: %s", args.argv[0]);
	DBG_P("method: %s", method);
	knh_getToken(sfp, &token);
	char *reply = knh_request(&args, method, &token);
	knh_freeArgs(&args);
	if (!reply) {
		// failed
		DBG_P("HTTP request for an oauth request-token failed.");
	} else {
		// parse reply
		rmap = knh_parseReply(ctx, reply);
		free(reply);
	}
	if (rmap) {
		RETURN_(rmap);
	} else {
		RETURN_(new_DataMap(ctx));
	}
}

/* ======================================================================== */
// [DEFAPI]

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.liboauth");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
