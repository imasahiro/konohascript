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
#include "knh_socket.h"

#ifdef __cplusplus
extern "C" {
#endif

////## Socket Socket.new(String! ip_addr, Int! port);
//METHOD Socket_new(Ctx* ctx, knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = malloc(sizeof(Socket_t));
//	memset(so, 0, sizeof(Socket_t));
//	knh_RawPtr_t *ptr;
//
//	char* host = String_to(char*, sfp[1]);
//	int port = Int_to(int, sfp[2]);
//	knh_io_t fd = knh_socket_open(ctx, host, port, 0);
//
//	SP(so)->sd = fd;
//	SP(so)->port = SP(so)->port;
//	SP(so)->uri = knh_getURI(ctx, S_tobytes(sfp[1].s));
//
//	knh_StreamDSPI_t *drv = knh_getChannelDriver();
//	KNH_INITv(SP(so)->urn, sfp[1].o);
//	KNH_INITv(SP(so)->in,  new_InputStreamDSPI(ctx, (knh_io_t)SP(so)->sd, drv));
//	KNH_INITv(SP(so)->out, new_OutputStreamDSPI(ctx, (knh_io_t)SP(so)->sd, drv));
//	ptr = new_RawPtr(ctx, so, NULL, CLASS_Any, "socket");
//	RETURN_(ptr);
//}
//
////## InputStream Socket.getInputStream();
//METHOD Socket_getInputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = RawPtr_to(Socket_t*, sfp[0]);
//	if ((SP(so)->sd) == -1){
//		KNH_SYSLOG(ctx, LOG_WARNING, "OutputStream!!", "getInputStream", 0);
//	}
//	RETURN_(SP(so)->in);
//}
//
////## OutputStream Socket.getOutputStream();
//METHOD Socket_getOutputStream(Ctx* ctx,knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = RawPtr_to(Socket_t*, sfp[0]);
//	if ((SP(so)->sd) == -1){
//		KNH_SYSLOG(ctx, LOG_WARNING, "OutputStream!!", "getInputStream", 0);
//	}
//	RETURN_(SP(so)->out);
//}
//
////## Socket ServerSocket.accept();
//METHOD ServerSocket_accept(Ctx* ctx,knh_sfp_t* sfp _RIX)
//{
//	Socket_t *entity = malloc(sizeof(Socket_t));
//	memset(entity, 0, sizeof(Socket_t));
//
//	knh_RawPtr_t *ptr;
//	Socket_t *so = RawPtr_to(Socket_t*, sfp[0]);
//
//	int fd = accept(SP(so)->sd, NULL, NULL);
//	if (fd == -1) {
//		perror("accept");
//		KNH_THROW__T(ctx, "Socket!!: cannot accept socket!");
//	}
//
//	SP(entity)->sd = fd;
//	SP(entity)->port = SP(so)->port;
//	SP(entity)->uri = SP(so)->uri;
//
//	knh_StreamDSPI_t *drv = knh_getChannelDriver();
//	KNH_INITv(SP(entity)->urn, SP(so)->urn);
//	KNH_INITv(SP(entity)->in,  new_InputStreamDSPI(ctx, (knh_io_t)SP(entity)->sd, drv));
//	KNH_INITv(SP(entity)->out, new_OutputStreamDSPI(ctx, (knh_io_t)SP(entity)->sd, drv));
//	ptr = new_RawPtr(ctx, entity, NULL, CLASS_Any, "socket");
//	RETURN_(ptr);
//}
//
////## void Socket.close();
//METHOD Socket_close(CTX ctx, knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = RawPtr_to(Socket_t*, sfp[0]);
//	close((int)SP(so)->sd);
//	SP(so)->sd = -1;
//}
//
////## boolean Socket.beClosed();
//METHOD Socket_beClosed(CTX ctx, knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = RawPtr_to(Socket_t*, sfp[0]);
//	RETURNb_(SP(so)->sd == -1);
//}
//
////## This ServerSocket.new(Int port, Int maxConnection);
//METHOD ServerSocket_new(Ctx* ctx,knh_sfp_t* sfp _RIX)
//{
//	Socket_t *so = (Socket_t*)sfp[0].o;
//	knh_RawPtr_t *ptr;
//	struct sockaddr_in addr;
//	int optval = 1;
//	int port = Int_to(int ,sfp[1]);
//	int backlog = Int_to(int, sfp[2]);
//	//	char *host = String_to(char *,sfp[3]);
//	char *host = "127.0.0.1";
//
//	int fd = socket(AF_INET, SOCK_STREAM, 0);
//	if (fd  == -1){
//		perror("soket");
//		KNH_THROW__T(ctx, "Socket!!: cannot make socket!");
//		}
//
//	in_addr_t hostinfo = inet_addr(host);
//	if (hostinfo == INADDR_NONE) {
//		KNH_THROW__T(ctx, "Socket!!: invalid ip");
//	}
//
//	memset(&addr, 0, sizeof(addr));
//	addr.sin_family = AF_INET;
//	addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	addr.sin_port = htons((short)port);
//
//	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
//
//	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
//	  perror("bind");
//	  KNH_THROW__T(ctx, "Socket!!: cannot connect");
//	}
//
//	if (listen(fd, backlog) == -1) {
//	  perror("listen");
//	}
//
//	knh_StreamDSPI_t *dspi = knh_getChannelDriver();
//	SP(so)->sd = fd;
//	SP(so)->port = port;
//	SP(so)->uri = knh_getURI(ctx, S_tobytes(sfp[3].s));
//	KNH_INITv(SP(so)->urn, sfp[3].o);
//	KNH_INITv(SP(so)->in,  new_InputStreamDSPI(ctx, (knh_io_t)SP(so)->sd, dspi));
//	KNH_INITv(SP(so)->out, new_OutputStreamDSPI(ctx, (knh_io_t)SP(so)->sd, dspi));
//	ptr = new_RawPtr(ctx, so, NULL, CLASS_Any, "serversocket");
//	RETURN_(ptr);
//}

#ifdef __cplusplus
}
#endif
