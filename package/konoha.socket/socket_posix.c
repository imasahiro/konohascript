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
//  goccy - Masaaki Goshima, Yokohama National University, Japan
// **************************************************************************

#include <konoha1.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

typedef struct {
	knh_hObject_t h;
	knh_io_t sd;
	int port;
} knh_Socket_t ;

typedef struct {
	knh_hObject_t h;
	knh_io_t sd;
	int port;
	int backlog;
} knh_ServerSocket_t ;

static void Socket_init(CTX ctx, knh_RawPtr_t *po)
{
	knh_Socket_t *so = (knh_Socket_t*)po;
	so->sd = IO_NULL;
}

static void Socket_free(CTX ctx, knh_RawPtr_t *po)
{
	knh_Socket_t *so = (knh_Socket_t*)po;
	if (so->sd != IO_NULL) {
		close((int)so->sd);
		so->sd = IO_NULL;
	}
}

DEFAPI(void) defSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Socket";
	cdef->init = Socket_init;
	cdef->free = Socket_free;
}

static knh_bool_t SOCKET_exists(CTX ctx, knh_Path_t *pth)
{
	return 0; // dummy
}
static knh_io_t SOCKET_open(CTX ctx, knh_Path_t *pth, const char *mode, knh_DictMap_t *conf)
{
	return IO_NULL; // Always opened by external
}
static knh_intptr_t SOCKET_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return recv((int)fd, buf, bufsiz, 0);
  //	return recv((int)fd, buf, bufsiz, MSG_PEEK | MSG_DONTWAIT);
}
static knh_intptr_t SOCKET_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	return send((int)fd, buf, bufsiz, 0);
}
static void SOCKET_close(CTX ctx, knh_io_t fd)
{
	close((int)fd);
}

static knh_bool_t SOCKET_info(CTX ctx, knh_io_t fd, knh_Object_t *o)
{
	return 0;
}

static void SOCKET_flush(Ctx *ctx, knh_io_t fd)
{
	//flush((int)fd);
}

static knh_bool_t SOCKET_readline(Ctx *ctx, knh_io_t fd, knh_Bytes_t *ba)
{
	KNH_TODO("SOCKET_readline");
	return 0;
}

static int SOCKET_feof(Ctx *ctx, knh_io_t fd)
{
	KNH_TODO("SOCKET_feof");
	return 1;
}

static int SOCKET_getc(Ctx *ctx, knh_io_t fd)
{
	KNH_TODO("SOCKET_getc");
	return -1;
}

static knh_StreamDPI_t SOCKET_DSPI = {
	K_STREAM_NET, "socket",  K_OUTBUF_MAXSIZ,
	SOCKET_exists, NULL,
	SOCKET_open, SOCKET_open, SOCKET_read, SOCKET_write, SOCKET_close,
	SOCKET_info, SOCKET_getc, SOCKET_readline, SOCKET_feof, SOCKET_flush,
};

static knh_io_t open_socket(CTX ctx, knh_sfp_t *sfp, const char *ip_or_host, int port)
{
	int sd = IO_NULL;
	struct in_addr addr = {0};
	struct sockaddr_in server = {0};
	const char *errfunc = NULL;

	if ((addr.s_addr = inet_addr(ip_or_host)) == -1) {
		struct hostent *host = gethostbyname(ip_or_host);
		if (host == NULL) {
			errfunc = "gethostname";
			goto L_PERROR;
		}
		memcpy(&addr, (struct in_addr *)*host->h_addr_list, sizeof(struct in_addr));
	}

	server.sin_family = AF_INET;
	server.sin_addr = addr;
	server.sin_port = htons(port);

	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		errfunc = "socket";
		goto L_PERROR;
	}

	if (connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
		errfunc = "connect";
		close(sd);
		goto L_PERROR;
	}

	L_PERROR:;
	knh_ldata_t ldata[] = {LOG_s("host", ip_or_host), LOG_i("port", port), LOG_sfp, LOG_END};
	if (errfunc != NULL) {
		KNH_NTHROW(ctx, sfp, "Socket!!", errfunc, K_PERROR, ldata);
		sd = IO_NULL;
	}
	else {
		KNH_NTRACE(ctx, "connect", K_NOTICE, ldata);
	}
	return (knh_io_t) sd;
}

//## @Throwable Socket Socket.new(String host, int port);
KMETHOD Socket_new(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	const char* host = String_to(const char*, sfp[1]);
	int port = Int_to(int, sfp[2]);
	if (port == 0) port = 80;
	so->port = port;
	so->sd = open_socket(ctx, sfp, host, port);
	if (so->sd == IO_NULL) {
		knh_Object_toNULL(ctx, so);
	}
	RETURN_(so);
}

//## InputStream Socket.getInputStream();
KMETHOD Socket_getInputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(new_InputStreamDPI(ctx, so->sd, &SOCKET_DSPI, KNH_TNULL(Path)));
}

//## OutputStream Socket.getOutputStream();
KMETHOD Socket_getOutputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(new_OutputStreamDPI(ctx, so->sd, &SOCKET_DSPI, KNH_TNULL(Path)));
}

//## void Socket.close();
KMETHOD Socket_close(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	if (so->sd != IO_NULL) {
		close((int)so->sd);
		so->sd = IO_NULL;
	}
}

KMETHOD Socket_getLocalPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(((knh_Socket_t*)sfp[0].o)->port);
}

KMETHOD Socket_getSendBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	int ret = 0;
	unsigned int len = sizeof(ret);
	knh_ldata_t ldata[] = {LOG_s("option", "SO_SNDBUF"), LOG_sfp, LOG_END};
	KNH_NTRACE(ctx, "getoptsockopt",
		(getsockopt(so->sd, SOL_SOCKET, SO_SNDBUF, &ret, &len) == -1) ? K_PERROR : K_OK, ldata);
	RETURNi_(ret);
}

KMETHOD Socket_getReuseAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	int ret = 0;
//	unsigned int len = sizeof(ret);
//	if(getsockopt(so->sd, SOL_SOCKET, SO_REUSEADDR, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNb_(ret);
}


KMETHOD Socket_getSoTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *s = (knh_Socket_t*)sfp[0].o;
	struct timeval ret = {0, 0};
	unsigned int len = sizeof(ret);
//	if(getsockopt(s->sd, SOL_SOCKET, SO_SNDTIMEO, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNi_(ret.tv_sec * 1000 + ret.tv_sec / 1000);
}

KMETHOD Socket_getKeepAlive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	int ret = 0;
//	unsigned int len = sizeof(ret);
//	if(getsockopt(so->sd, SOL_SOCKET, SO_KEEPALIVE, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNb_(ret);
}

KMETHOD Socket_setSendBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	int ret = Int_to(int, sfp[1]);
//	unsigned int len = sizeof(ret);
//	if(setsockopt(so->sd, SOL_SOCKET, SO_SNDBUF, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNi_(ret);
}

KMETHOD Socket_setReuseAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
//	int ret = Int_to(int, sfp[1]); // sould be a boolean
//	unsigned int len = sizeof(ret);
//	if(setsockopt(so->sd, SOL_SOCKET, SO_REUSEADDR, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNvoid_();
}

KMETHOD Socket_setSoTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
//	int msec = Int_to(int, sfp[1]);
//	int sec = msec / 1000;
//	int usec = (msec - 1000 * sec) * 1000;
//	fprintf(stderr, "%d %d\n", sec, usec);
//	struct timeval ret = {sec, usec};
//	unsigned int len = sizeof(ret);
//	if(setsockopt(so->sd, SOL_SOCKET, SO_SNDTIMEO, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNvoid_();
}

KMETHOD Socket_setKeepAlive(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
//	int ret = Int_to(int, sfp[1]); // sould be a boolean
//	unsigned int len = sizeof(ret);
//	if(setsockopt(so->sd, SOL_SOCKET, SO_KEEPALIVE, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "Socket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
//	RETURNvoid_();
}

KMETHOD Socket_isClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	char buffer[32];
	int ret = 1; // true = closed
	if (recv(so->sd, buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0) {
		//if connection is zero, its closed
		ret = 1; // true = closed
	} else {
		ret = 0; // false = isnotClosed
	}
	RETURNb_(ret);
}

/* ------------------------------------------------------------------------ */
/* [ServerSocket] */

DEFAPI(void) defServerSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "ServerSocket";
	cdef->init = Socket_init;
	cdef->free = Socket_free;
}

////## @Throwable ServerSocket ServerSocket.new(Int port, Int maxConnection);
KMETHOD ServerSocket_new(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	int port = Int_to(int ,sfp[1]);
	int backlog = Int_to(int, sfp[2]);
	ss->port = port;
	ss->backlog = backlog;

	struct sockaddr_in addr = {0};
	int optval = 1;
	const char *errfunc = NULL;
	const char *host = "127.0.0.1";
	in_addr_t hostinfo;

	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd  == -1) {
		errfunc = "socket"; goto L_RETURN;
	}

	hostinfo = inet_addr(host);
	if (hostinfo == INADDR_NONE) {
		close(fd);
		errfunc = "inet_addr"; goto L_RETURN;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons((short)port);
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		close(fd);
		errfunc = "bind"; goto L_RETURN;
	}
	if (listen(fd, backlog) == -1) {
		close(fd);
		errfunc = "listen"; goto L_RETURN;
	}

	L_RETURN: {
		knh_ldata_t ldata[] = {LOG_s("host", host), LOG_i("port", port), LOG_i("max_connection", backlog), LOG_sfp, LOG_END};
		if(errfunc == NULL) {
			ss->sd = fd;
			KNH_NTRACE(ctx, "listen", K_OK, ldata);
		}
		else {
			KNH_NTHROW(ctx, sfp, "Socket!!", errfunc, K_PERROR, ldata);
			knh_Object_toNULL(ctx, ss);
		}
	}
	RETURN_(ss);
}

////## Socket ServerSocket.accept(Socket _);
KMETHOD ServerSocket_accept(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t *)sfp[0].o;
	struct sockaddr_in client_address;
	socklen_t client_len = sizeof(struct sockaddr_in);
	knh_intptr_t fd = accept(ss->sd, (struct sockaddr*)&client_address, &client_len);
	knh_RawPtr_t *so;
	knh_ldata_t ldata[] = {LOG_END};
	if (fd == -1) {
		so = new_ReturnRawPtr(ctx, sfp, NULL);
		KNH_NTHROW(ctx, sfp, "ServerSocket!!", "accept", K_PERROR, ldata);
	}
	else {
		so = new_ReturnRawPtr(ctx, sfp, (void*)fd);
		KNH_NTRACE(ctx, "accept", K_OK, ldata);
	}
	RETURN_(so);
}

KMETHOD ServerSocket_close(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	if(ss->sd != IO_NULL) {
		close((int)ss->sd);
		ss->sd = IO_NULL;
	}
}

KMETHOD ServerSocket_getLocalPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(((knh_ServerSocket_t*)sfp[0].o)->port);
}

KMETHOD ServerSocket_getReceiveBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	int ret = 0;
//	unsigned int len = sizeof(ret);
//	if(getsockopt(ss->sd, SOL_SOCKET, SO_RCVBUF, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNi_(ret);
}

KMETHOD ServerSocket_getReuseAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	int ret = 0;
//	unsigned int len = sizeof(ret);
//	if(getsockopt(ss->sd, SOL_SOCKET, SO_REUSEADDR, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNb_(ret);
}

KMETHOD ServerSocket_getSoTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	struct timeval ret = {0, 0};
//	unsigned int len = sizeof(ret);
//	if(getsockopt(ss->sd, SOL_SOCKET, SO_RCVTIMEO, &ret, &len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNi_(ret.tv_sec * 1000 + ret.tv_sec / 1000);
}

KMETHOD ServerSocket_setReceiveBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	int ret = Int_to(int, sfp[1]);
//	unsigned int len = sizeof(ret);
//	if(setsockopt(ss->sd, SOL_SOCKET, SO_RCVBUF, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNi_(ret);
}

KMETHOD ServerSocket_setReuseAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	int ret = Int_to(int, sfp[1]); // sould be a boolean
//	unsigned int len = sizeof(ret);
//	if(setsockopt(ss->sd, SOL_SOCKET, SO_REUSEADDR, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNvoid_();
}

KMETHOD ServerSocket_setSoTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
//	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
//	int msec = Int_to(int, sfp[1]);
//	int sec = msec / 1000;
//	int usec = (msec - 1000 * sec) * 1000;
//	fprintf(stderr, "%d %d\n", sec, usec);
//	struct timeval ret = {sec, usec};
//	unsigned int len = sizeof(ret);
//	if(setsockopt(ss->sd, SOL_SOCKET, SO_RCVTIMEO, &ret, len) == -1) {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__, "ServerSocket!!");
//	} else {
//		knh_ldata_t ldata[] = {LOG_END};
//		KNH_NTRACE(ctx, __FUNCTION__);
//	}
	RETURNvoid_();
}

KMETHOD ServerSocket_isClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_ServerSocket_t *ss = (knh_ServerSocket_t*)sfp[0].o;
	char buffer[32];
	int ret = 1; // true = closed
	if (recv(ss->sd, buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0) {
		ret = 1;
	} else {
		ret = 0;
	}
	RETURNb_(ret);
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
//	kapi->loadClassIntConst(ctx, CLASS_System, IntConstData);
	RETURN_PKGINFO("konoha.socket");
}

#endif


#ifdef __cplusplus
}
#endif
