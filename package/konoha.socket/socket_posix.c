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

#define LIBNAME "libc"

typedef struct {
	knh_io_t sd;
	int port;
	knh_String_t *urn;
	knh_uri_t uri;
	knh_InputStream_t *in;
	knh_OutputStream_t *out;
} knh_SocketEX_t;

typedef struct {
	knh_hObject_t h;
	knh_SocketEX_t *b;
	void *data1;
	void *data2;
} knh_Socket_t ;

static void Socket_init(CTX ctx, Object *o)
{
	knh_Socket_t *so = (knh_Socket_t*)o;
	DP(so)->sd = IO_NULL;
	KNH_INITv(DP(so)->in, KNH_TNULL(InputStream));
	KNH_INITv(DP(so)->out, KNH_TNULL(OutputStream));
}

static void Socket_reftrace(CTX ctx, Object *o FTRARG)
{
	knh_Socket_t *so = (knh_Socket_t*)o;
	KNH_ADDREF(ctx, DP(so)->in);
	KNH_ADDREF(ctx, DP(so)->out);
	KNH_SIZEREF(ctx);
}

static void Socket_free(CTX ctx, Object *o)
{
	knh_Socket_t *so = (knh_Socket_t*)o;
	if (DP(so)->sd != IO_NULL) {
		close((int)DP(so)->sd);
		DP(so)->sd = IO_NULL;
	}
}

EXPORTAPI(const knh_ClassDef_t*) Socket(CTX ctx)
{
	static knh_ClassDef_t cdef;
	cdef = *(knh_getDefaultClassDef());
	cdef.name = "Socket";
	cdef.init = Socket_init;
	cdef.reftrace = Socket_reftrace;
	cdef.free = Socket_free;
	return (const knh_ClassDef_t*)&cdef;
}

EXPORTAPI(const knh_ClassDef_t*) ServerSocket(CTX ctx)
{
	static knh_ClassDef_t cdef;
	cdef = *(knh_getDefaultClassDef());
	cdef.name = "ServerSocket";
	cdef.init = Socket_init;
	cdef.reftrace = Socket_reftrace;
	cdef.free = Socket_free;
	return (const knh_ClassDef_t*)&cdef;
}
static knh_bool_t SOCKET_realpath(CTX ctx, knh_NameSpace_t *ns, knh_path_t *ph)
{
	return 0;
}
static knh_io_t SOCKET_open(CTX ctx, knh_path_t *ph, const char *mode, knh_Monitor_t *mon)
{
	return IO_NULL; // Always opened by external
}
static knh_intptr_t SOCKET_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz, knh_Monitor_t *mon)
{
	return recv((int)fd, buf, bufsiz, 0);
}
static knh_intptr_t SOCKET_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz, knh_Monitor_t *mon)
{
	return send((int)fd, buf, bufsiz, 0);
}
static void SOCKET_close(CTX ctx, knh_io_t fd)
{
	close((int)fd);
}

static knh_StreamDSPI_t SOCKET_DSPI = {
	K_DSPI_STREAM, "socket", SOCKET_realpath,
	SOCKET_open,
	SOCKET_open,
	SOCKET_read,
	K_OUTBUF_MAXSIZ,
	SOCKET_write,
	SOCKET_close,
};

static knh_io_t socket_open(CTX ctx, knh_sfp_t *sfp, const char *ip_or_host, int port, knh_Monitor_t *mon)
{
	knh_io_t sd = IO_NULL;
	struct in_addr addr = {0};
	struct hostent	*host;
	struct sockaddr_in	server = {0};
	const char *errfunc = NULL;
	if ((addr.s_addr = inet_addr(ip_or_host)) == -1) {
		host = gethostbyname(ip_or_host);
		if (host == NULL) {
			errfunc = "gethostname";
			goto L_PERROR;
		}
		memcpy(&addr, (struct in_addr *)*host->h_addr_list, sizeof(struct in_addr));
	}
	server.sin_family = AF_INET;
	server.sin_addr = addr;
	server.sin_port = htons(port);
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		errfunc = "socket";
		goto L_PERROR;
	}
	if (connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
		errfunc = "connect";
		sd = IO_NULL;
		goto L_PERROR;
	}
	L_PERROR:;
	if(errfunc != NULL) {
		KNH_PTRACE(ctx, sfp, mon, errfunc, "Socket!!: host='%s', port=%d", ip_or_host, port);
	}
	return sd;
}

//## Socket Socket.new(String host, int port, Monitor mon);
METHOD Socket_new(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	const char* host = String_to(const char*, sfp[1]);
	int port = Int_to(int, sfp[2]);
	if (port == 0) port = 80;
	DP(so)->sd = socket_open(ctx, sfp, host, port, sfp[3].mon);
	if (DP(so)->sd != IO_NULL) {
		KNH_SETv(ctx, DP(so)->in,  new_InputStreamDSPI(ctx, DP(so)->sd, &SOCKET_DSPI));
		KNH_SETv(ctx, DP(so)->out, new_OutputStreamDSPI(ctx, DP(so)->sd, &SOCKET_DSPI));
	}
	RETURN_(so);
}

//## InputStream Socket.getInputStream();
METHOD Socket_getInputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(DP(so)->in);
}

//## OutputStream Socket.getOutputStream();
METHOD Socket_getOutputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	RETURN_(DP(so)->out);
}

//## void Socket.close();
METHOD Socket_close(CTX ctx, knh_sfp_t* sfp _RIX)
{
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	if (DP(so)->sd != IO_NULL) {
		close((int)DP(so)->sd);
	}
	DP(so)->sd = IO_NULL;
}

////## Socket ServerSocket.accept(NameSpace ns);
METHOD ServerSocket_accept(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	//Socket_t *entity = malloc(sizeof(Socket_t));
	//memset(entity, 0, sizeof(Socket_t));
	knh_NameSpace_t *ns = sfp[1].ns;
	knh_Socket_t *entity = (knh_Socket_t *)new_ObjectNS(ctx, ns, "Socket");
	//knh_RawPtr_t *ptr;
	//knh_Socket_t *so = RawPtr_to(knh_Socket_t*, sfp[0]);//ServerSocket
	knh_Socket_t *so = (knh_Socket_t *)sfp[0].p;
	int fd = accept(DP(so)->sd, NULL, NULL);
	if (fd == -1) {
		perror("accept");
		//KNH_THROW__T(ctx, "Socket!!: cannot accept socket!");
	}

	DP(entity)->sd = fd;
	DP(entity)->port = DP(so)->port;
	DP(entity)->uri = DP(so)->uri;

	//knh_StreamDSPI_t *drv = knh_getChannelDriver();
	knh_StreamDSPI_t *drv = &SOCKET_DSPI;
	KNH_INITv(DP(entity)->urn, DP(so)->urn);
	KNH_INITv(DP(entity)->in,  new_InputStreamDSPI(ctx, (knh_io_t)DP(entity)->sd, drv));
	KNH_INITv(DP(entity)->out, new_OutputStreamDSPI(ctx, (knh_io_t)DP(entity)->sd, drv));
	//ptr = new_RawPtr(ctx, entity, NULL, CLASS_Any, "socket");
	//RETURN_(ptr);
	RETURN_(entity);
}
//
//
////## This ServerSocket.new(Int port, Int maxConnection);
METHOD ServerSocket_new(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	
	knh_Socket_t *so = (knh_Socket_t*)sfp[0].o;
	//knh_RawPtr_t *ptr;
	struct sockaddr_in addr;
	int optval = 1;
	int port = Int_to(int ,sfp[1]);
	int backlog = Int_to(int, sfp[2]);
	//	char *host = String_to(char *,sfp[3]);
	char *host = "127.0.0.1";

	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd  == -1) {
		perror("soket");
		//KNH_THROW__T(ctx, "Socket!!: cannot make socket!");
	}

	in_addr_t hostinfo = inet_addr(host);
	if (hostinfo == INADDR_NONE) {
		//KNH_THROW__T(ctx, "Socket!!: invalid ip");
	}

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons((short)port);

	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
	  perror("bind");
	  //KNH_THROW__T(ctx, "Socket!!: cannot connect");
	}

	if (listen(fd, backlog) == -1) {
		perror("listen");
	}

	//knh_StreamDSPI_t *dspi = knh_getChannelDriver();
	knh_StreamDSPI_t *dspi = &SOCKET_DSPI;
	DP(so)->sd = fd;
	DP(so)->port = port;
	knh_InputStream_t *in = new_InputStreamDSPI(ctx, fd, dspi);//(knh_io_t)DP(so)->sd, dspi);
	knh_OutputStream_t *out = new_OutputStreamDSPI(ctx, fd, dspi);//(knh_io_t)DP(so)->sd, dspi);
	//knh_String_t *urn = sfp[3].o;
	//KNH_INITv(DP(so)->urn, sfp[3].o);
	//KNH_INITv(DP(so)->in,  new_InputStreamDSPI(ctx, (knh_io_t)DP(so)->sd, dspi));
	//KNH_INITv(DP(so)->out, new_OutputStreamDSPI(ctx, (knh_io_t)DP(so)->sd, dspi));
	//ptr = new_RawPtr(ctx, so, NULL, CLASS_Any, "serversocket");
	//RETURN_(ptr);
	DP(so)->in = in;
	DP(so)->out = out;
	//DP(so)->urn = urn;
	RETURN_(so);
}

METHOD ServerSocket_close(Ctx* ctx,knh_sfp_t* sfp _RIX)
{
	
}

#ifdef _SETUP

EXPORTAPI(const knh_PackageDef_t*) init(CTX ctx)
{
	static const knh_PackageDef_t pkgdef = KNH_PKGINFO("socket", "0.0", "Konoha Socket Library", NULL);
	return &pkgdef;
}

//EXPORTAPI(void) SocketCONST(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
//{
//	if(ns == NULL) {
//		kapi->loadFloatData(ctx, FloatConstData);
//	}
//}

#endif


#ifdef __cplusplus
}
#endif
