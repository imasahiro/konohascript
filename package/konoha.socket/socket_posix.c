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
} knh_Socket_t ;

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

static knh_io_t SOCKET_open(CTX ctx, const char *ph, const char *mode)
{
	return IO_NULL; // Always opened by external
}
static knh_intptr_t SOCKET_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return recv((int)fd, buf, bufsiz, 0);
}
static knh_intptr_t SOCKET_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	return send((int)fd, buf, bufsiz, 0);
}
static void SOCKET_close(CTX ctx, knh_io_t fd)
{
	close((int)fd);
}
static knh_StreamDPI_t SOCKET_DSPI = {
	K_DSPI_STREAM, "socket",  K_OUTBUF_MAXSIZ,
	SOCKET_open, SOCKET_open, SOCKET_read, SOCKET_write, SOCKET_close,
};

static knh_io_t open_socket(CTX ctx, knh_sfp_t *sfp, const char *ip_or_host, int port)
{
	knh_io_t sd = IO_NULL;
	struct in_addr addr = {0};
	struct sockaddr_in	server = {0};
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
		close((int)sd);
		goto L_PERROR;
	}

	L_PERROR:;
	if (errfunc != NULL) {
		LOGDATA = {sDATA("host", ip_or_host), iDATA("port", port)};
		LIB_Failed(errfunc, "Socket!!");
		sd = IO_NULL;
	}
	else {
		LOGDATA = {sDATA("host", ip_or_host), iDATA("port", port), __ERRNO__};
		NOTE_OK("socket");
	}
	return sd;
}

//## @Throwable Socket Socket.new(String host, int port);
METHOD Socket_new(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	const char* host = String_to(const char*, sfp[1]);
	int port = Int_to(int, sfp[2]);
	if (port == 0) port = 80;
	so->sd = open_socket(ctx, sfp, host, port);
	if (so->sd == IO_NULL) {
		knh_Object_toNULL(ctx, so);
	}
	RETURN_(so);
}

//## InputStream Socket.getInputStream();
METHOD Socket_getInputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(new_InputStreamDPI(ctx, so->sd, &SOCKET_DSPI));
}

//## OutputStream Socket.getOutputStream();
METHOD Socket_getOutputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(new_OutputStreamDPI(ctx, so->sd, &SOCKET_DSPI));
}

//## void Socket.close();
METHOD Socket_close(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	if (so->sd != IO_NULL) {
		close((int)so->sd);
		so->sd = IO_NULL;
	}
}

DEFAPI(void) defServerSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "ServerSocket";
	cdef->init = Socket_init;
	cdef->free = Socket_free;
}

////## @Throwable ServerSocket ServerSocket.new(Int port, Int maxConnection);
METHOD ServerSocket_new(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *ss = (knh_Socket_t*)sfp[0].o;
	int port = Int_to(int ,sfp[1]);
	int backlog = Int_to(int, sfp[2]);
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
		errfunc = "inet_addr"; goto L_RETURN;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons((short)port);
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		errfunc = "bind"; goto L_RETURN;
	}
	if (listen(fd, backlog) == -1) {
		errfunc = "listen"; goto L_RETURN;
	}

	L_RETURN:
	if(errfunc == NULL) {
		ss->sd = fd;
		LOGDATA = {sDATA("host", host), iDATA("port", port), iDATA("max_connection", backlog)};
		NOTE_OK("listen");
	}
	else {
		LOGDATA = {sDATA("host", host), iDATA("port", port), iDATA("max_connection", backlog), __ERRNO__};
		LIB_Failed(errfunc, "Socket!!");
		knh_Object_toNULL(ctx, ss);
	}
	RETURN_(ss);
}

////## Socket ServerSocket.accept(Socket _);
METHOD ServerSocket_accept(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *ss = (knh_Socket_t *)sfp[0].o;
	knh_RawPtr_t *so = (knh_RawPtr_t*)sfp[1].o;
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(struct sockaddr_in);
	knh_intptr_t fd = accept(ss->sd, (struct sockaddr*)&client_address, &client_len);
	if (fd == -1) {
		LOGDATA = {__ERRNO__};
		LIB_Failed("accept", "Socket!!");
	}
	else {
		so = new_RawPtr(ctx, sfp[1].p, (void*)fd);
		LOGDATA = {__ERRNO__};
		NOTE_OK("accept");
	}
	RETURN_(so);
}

METHOD ServerSocket_close(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *ss = (knh_Socket_t*)sfp[0].o;
	if(ss->sd != IO_NULL) {
		close((int)ss->sd);
		ss->sd = IO_NULL;
	}
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
//	kapi->loadIntClassConst(ctx, CLASS_System, IntConstData);
	RETURN_PKGINFO("konoha.socket");
}

#endif


#ifdef __cplusplus
}
#endif
