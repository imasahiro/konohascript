#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF 1024

#ifdef __cplusplus
extern "C" {
#endif

//#undef SP
//#define SP(o) (o)
//typedef struct Socket_t {
//	int port;
//	kString *urn;
//	kuri_t uri;
//	kintptr_t sd; /* socket discripter */
//	kInputStream  *in;
//	kOutputStream *out;
//} Socket_t;
//
//
//KNHAPI(int) knh_socket_send(CTX ctx, kintptr_t sd, char *buf, size_t bufsiz, int flags)
//{
//	int res = -1;
//#if defined(K_USING_WINDOWS)
//	res = send(sd, buf, bufsiz, flags);
//#elif defined(K_USING_POSIX)
//	res = send(sd, buf, bufsiz, flags);
//#elif defined(K_USING_BTRON)
//	res = so_send(sd, buf, bufsiz, flags);
//	if (res < 0) res = -1;
//#endif
//	if(res == -1) {
//	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "send", knh_Context_isStrict(ctx));
//	}
//	return res;
//}
//
//KNHAPI(int) knh_socket_recv(CTX ctx, kintptr_t sd, char *buf, size_t bufsiz, int flags)
//{
//	int res = -1;
//#if defined(K_USING_WINDOWS)
//	res = recv(sd, buf, bufsiz, flags);
//#elif defined(K_USING_POSIX)
//	res = recv(sd, buf, bufsiz, flags);
//#elif defined(K_USING_BTRON)
//	res = so_recv(sd, buf, bufsiz, flags);
//	if (res < 0) res = -1;
//#endif
//	if(res == -1) {
//	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "recv", knh_Context_isStrict(ctx));
//	}
//	return res;
//}
//
//
//KNHAPI(int) knh_socket_close(CTX ctx, kintptr_t sd)
//{
//#if defined(K_USING_WINDOWS)
//	return closeChannel(sd);
//#elif defined(K_USING_POSIX)
//	return close((int)sd);
//#elif defined(K_USING_BTRON)
//	return so_close(sd);
//#else
//	return 0;  /* becuase, it wasn't opened. */
//#endif
//}
//
//KNHAPI(int) kcheck(void)
//{
//    return K_BUILDID;
//}
//
//static kbytes_t knh_bytes_path(kbytes_t t)
//{
//	kindex_t loc = knh_bytes_index(t, ':');
//	if(loc >= 0) {
//		return knh_bytes_last(t, loc + 1);
//	}
//	return t;
//}
//
//static char* knh_format_bytes(char *buf, size_t bufsiz, kbytes_t t)
//{
//	size_t i;
//	for(i = 0; i < t.len; i++) {
//		if((bufsiz - 1) == i) break;
//		buf[i] = t.buf[i];
//	}
//	buf[i] = 0;
//	return buf;
//}
//
//static int knh_iodrv_open__Channel(CTX ctx, kbytes_t file, kuri_t *uri, char *mode)
//{
//	kbytes_t urn = knh_bytes_path(file);
//	kindex_t loc = knh_bytes_rindex(urn, ':');
//	int port = 80; /* default */
//	char host_or_ip[128];
//	if(loc != -1) {
//		kint_t v = 80;
//		knh_bytes_parseint(knh_bytes_last(urn, loc+1), &v);
//		port = (int)v;
//		urn = knh_bytes_first(urn, loc);
//	}
//	knh_format_bytes(host_or_ip, sizeof(host_or_ip), urn);
//	DBG_P("opening Channel host='%s', port=%d", host_or_ip, port);
//	return (int)knh_socket_open(ctx, host_or_ip, port, 0/*isThrowable*/);
//}
//
//static void knh_iodrv_init__Channel(CTX ctx, Object *stream, char *mode)
//{
//}
//
//static kintptr_t knh_iodrv_read__Channel(CTX ctx, int sd, char *buf, size_t bufsiz)
//{
//	return knh_socket_recv(ctx, (kintptr_t)sd, buf, bufsiz, 0);
//}
//
//static kintptr_t knh_iodrv_write__Channel(CTX ctx, int sd, char *buf, size_t bufsiz)
//{
//	return knh_socket_send(ctx, (kintptr_t)sd, buf, bufsiz, 0);
//}
//
//static void knh_iodrv_close__Channel(CTX ctx, int sd)
//{
//	knh_socket_close(ctx, (kintptr_t)sd);
//}
//
//static knh_PathDPI_t IO__Channel = {
//	K_DSPI_STREAM, "Channel",
//	4096,
//	knh_iodrv_open__Channel,
//	knh_iodrv_init__Channel,
//	knh_iodrv_read__Channel,
//	knh_iodrv_write__Channel,
//	knh_iodrv_close__Channel
//};
//
//knh_PathDPI_t *knh_getChannelDriver(void)
//{
//	return &IO__Channel;
//}
//
//
//static knh_IntData_t IntConstData[] = {
//		{"Socket.AF_UNIX",AF_UNIX},
//		{"Socket.AF_LOCAL", AF_LOCAL},
//		{"Socket.AF_INET",AF_INET},
//		{"Socket.AF_INET6",AF_INET6},
//		{"Socket.AF_IPX",AF_IPX},
//		{"Socket.SOCK_STREAM",SOCK_STREAM},
//		{"Socket.SOCK_DGRAM",SOCK_DGRAM},
//		{"Socket.SOCK_SEQPACKET",SOCK_SEQPACKET},
//		{"Socket.SOCK_RAW",SOCK_RAW},
//		{"Socket.SOCK_RDM",SOCK_RDM},
//		{NULL, -1} // end of const
//};
//
//KNHAPI(void) init(CTX ctx, const knh_LoaderAPI_t *kapi)
//{
//    kapi->loadIntData(ctx, IntConstData);
//}

#ifdef __cplusplus
}
#endif
