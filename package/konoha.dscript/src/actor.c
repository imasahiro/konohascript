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
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
//  goccy - Masaaki Goshima, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

/* ======================================================================== */
// [private functions]

/* ------------------------------------------------------------------------ */
// [actor]

typedef struct {
	const char *name;
	const char *host;
	int port;
} knh_actor_t;

static knh_actor_t *knh_actor_malloc(CTX ctx)
{
	return (knh_actor_t *)KNH_MALLOC(ctx, sizeof(knh_actor_t));
}

static void knh_actor_init(CTX ctx, knh_actor_t *a, const char *name, const char *host, int port)
{
	if (name != NULL) {
		size_t len = knh_strlen(name);
		a->name = (const char *)KNH_MALLOC(ctx, len);
		strncpy((char *)a->name, name, len);
	}
	if (host != NULL) {
		size_t len = knh_strlen(host);
		a->host = (const char *)KNH_MALLOC(ctx, len);
		strncpy((char *)a->host, host, len);
	}
	a->port = port;
}

static void knh_actor_free(CTX ctx, knh_actor_t *a)
{
	if (a->name != NULL) {
		KNH_FREE(ctx, (char *)a->name, strlen(a->name));
		a->name = NULL;
	}
	if (a->host != NULL) {
		KNH_FREE(ctx, (char *)a->host, strlen(a->host));
		a->host = NULL;
	}
	KNH_FREE(ctx, a, sizeof(knh_actor_t));
}

static void Actor_init(CTX ctx, kRawPtr *po)
{
	knh_actor_t *a = knh_actor_malloc(ctx);
	knh_actor_init(ctx, a, NULL, NULL, 0);
	po->rawptr = a;
}

static void Actor_free(CTX ctx, kRawPtr *po)
{
	knh_actor_t *a = (knh_actor_t *)po->rawptr;
	knh_actor_free(ctx, a);
	po->rawptr = NULL;
}

/* ======================================================================== */
// [KMETHODS]

//## @Native Actor Actor.new(String name, String host, int port);
KMETHOD Actor_new(CTX ctx, ksfp_t *sfp _RIX)
{
	kRawPtr *p = sfp[0].p;
	const char *name = String_to(const char *, sfp[1]);
	const char *host = String_to(const char *, sfp[2]);
	int port = Int_to(int, sfp[3]);
	knh_actor_init(ctx, (knh_actor_t *)p->rawptr, name, host, port);
	RETURN_(p);
}

//## @Native @Hidden Actor Actor.opLINK(String path, NameSpace _);
KMETHOD Actor_opLINK(CTX ctx, ksfp_t *sfp _RIX)
{
	kbytes_t host_port = knh_bytes_next(S_tobytes(sfp[1].s), ':');
	kindex_t idx = knh_bytes_index(host_port, ':');
	if (idx == -1) {
		KNH_NTRACE2(ctx, "konoha:format", K_FAILED,
				KNH_LDATA(LOG_s("path", host_port.text), LOG_s("type", "Actor")));
		kObjectoNULL(ctx, sfp[0].o);
		RETURN_(sfp[0].o);
	}
	kint_t port;
	if (!knh_bytes_parseint(knh_bytes_next(host_port, ':'), &port)) {
		KNH_NTRACE2(ctx, "konoha:format", K_FAILED,
				KNH_LDATA(LOG_s("path", host_port.text), LOG_s("type", "Actor")));
		kObjectoNULL(ctx, sfp[0].o);
		RETURN_(sfp[0].o);
	}
	knh_actor_t *actor = knh_actor_malloc(ctx);
	kbytes_t host = knh_bytes_first(host_port, idx);
	char tmp = host.buf[host.len];
	host.buf[host.len] = '\0';
	knh_actor_init(ctx, actor, NULL, host.text, port);
	host.buf[host.len] = tmp;
	DBG_P( "[actor] name=%s", actor->name);
	DBG_P( "[actor] host=%s", actor->host);
	DBG_P( "[actor] port=%d", actor->port);
	RETURN_(new_ReturnRawPtr(ctx, sfp, actor));
}

//## @Native String Actor.getName();
KMETHOD Actor_getName(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_actor_t *actor = RawPtr_to(knh_actor_t *, sfp[0]);
	if (actor->name == NULL) {
		RETURN_(KNH_TNULL(String));
	}
	RETURN_(new_String(ctx, actor->name));
}

//## @Native String Actor.getHost();
KMETHOD Actor_getHost(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_actor_t *actor = RawPtr_to(knh_actor_t *, sfp[0]);
	if (actor->host == NULL) {
		RETURN_(KNH_TNULL(String));
	}
	RETURN_(new_String(ctx, actor->host));
}

//## @Native int Actor.getPort();
KMETHOD Actor_getPort(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_actor_t *actor = RawPtr_to(knh_actor_t *, sfp[0]);
	RETURNi_(actor->port);
}

/* ======================================================================== */
// [DEFAPI]

DEFAPI(void) defActor(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Actor";
	cdef->init = Actor_init;
	cdef->free = Actor_free;
	knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("actor"), ClassTBL(knh_getcid(ctx, STEXT("Actor"))));
}

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.actor");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
