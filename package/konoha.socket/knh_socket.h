#define USE_bytes_index
#define USE_bytes_last
#define USE_bytes_rindex
#define USE_bytes_parseint
#define USE_bytes_first
#define USE_new_bytes

#include <konoha.h>
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

#undef SP
#define SP(o) (o)
typedef struct Socket_t {
	int port;
	knh_String_t *urn;
	knh_uri_t uri;
	knh_intptr_t sd; /* socket discripter */
	knh_InputStream_t  *in;
	knh_OutputStream_t *out;
} Socket_t; 

KNHAPI(knh_intptr_t) knh_socket_open(Ctx *ctx, char *ip_or_host, int port, int isThrowable)
{
#if defined(K_USING_POSIX)
#if defined(K_USING_WINDOWS)
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,0), &wsaData);
#endif
	struct in_addr addr = {0};
	struct hostent	*host;
	struct sockaddr_in	server = {0};
	knh_intptr_t sd = -1;
	if ((addr.s_addr = inet_addr(ip_or_host)) == -1) {
		host = gethostbyname(ip_or_host);
		if (host == NULL) {
		  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "gethostbyname", isThrowable);
			return -1;
		}
		memcpy(&addr, (struct in_addr *)*host->h_addr_list, sizeof(struct in_addr));
	}
	server.sin_family = AF_INET;
	server.sin_addr = addr;
	server.sin_port = htons(port);

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "Channel", isThrowable);
		return -1;
	}
	if (connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "connect", isThrowable);
		return -1;
	}
	return sd;
#elif defined(K_USING_BTRON)
	char tmp[HBUFLEN];
	struct hostent host;
	struct sockaddr_in server = {0};
	W err, sd;

	err = so_gethostbyname(ip_or_host, &host, tmp);
	if (err < 0) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "gethostbyname", isThrowable);
		return -1;
	}

	server.sin_family = PF_INET;
	memcpy(&(server.sin_addr), host.h_addr, host.h_length);
	server.sin_port = htons(port);

	err = so_socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (err < 0) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "Channel", isThrowable);
		return -1;
	}
	sd = err;

	err = so_connect(sd, (struct sockaddr*)&server, sizeof(server));
	if (err < 0) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "connect", isThrowable);
		so_close(sd);
		return -1;
	}
	return (knh_intptr_t)sd;
#else
	return -1;
#endif
}

KNHAPI(int) knh_socket_send(Ctx *ctx, knh_intptr_t sd, char *buf, size_t bufsiz, int flags)
{
	int res = -1;
#if defined(K_USING_WINDOWS)
	res = send(sd, buf, bufsiz, flags);
#elif defined(K_USING_POSIX)
	res = send(sd, buf, bufsiz, flags);
#elif defined(K_USING_BTRON)
	res = so_send(sd, buf, bufsiz, flags);
	if (res < 0) res = -1;
#endif
	if(res == -1) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "send", knh_Context_isStrict(ctx));
	}
	return res;
}

KNHAPI(int) knh_socket_recv(Ctx *ctx, knh_intptr_t sd, char *buf, size_t bufsiz, int flags)
{
	int res = -1;
#if defined(K_USING_WINDOWS)
	res = recv(sd, buf, bufsiz, flags);
#elif defined(K_USING_POSIX)
	res = recv(sd, buf, bufsiz, flags);
#elif defined(K_USING_BTRON)
	res = so_recv(sd, buf, bufsiz, flags);
	if (res < 0) res = -1;
#endif
	if(res == -1) {
	  KNH_SYSLOG(ctx, LOG_WARNING, "Channel!!", "recv", knh_Context_isStrict(ctx));
	}
	return res;
}


KNHAPI(int) knh_socket_close(Ctx *ctx, knh_intptr_t sd)
{
#if defined(K_USING_WINDOWS)
	return closeChannel(sd);
#elif defined(K_USING_POSIX)
	return close((int)sd);
#elif defined(K_USING_BTRON)
	return so_close(sd);
#else
	return 0;  /* becuase, it wasn't opened. */
#endif
}

KNHAPI(int) kcheck(void)
{
    return K_BUILDID;
}

static knh_bytes_t knh_bytes_path(knh_bytes_t t)
{
	knh_index_t loc = knh_bytes_index(t, ':');
	if(loc >= 0) {
		return knh_bytes_last(t, loc + 1);
	}
	return t;
}

static char* knh_format_bytes(char *buf, size_t bufsiz, knh_bytes_t t)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if((bufsiz - 1) == i) break;
		buf[i] = t.buf[i];
	}
	buf[i] = 0;
	return buf;
}

static knh_io_t knh_iodrv_open__Channel(Ctx *ctx, knh_bytes_t file, knh_uri_t *uri, char *mode)
{
	knh_bytes_t urn = knh_bytes_path(file);
	knh_index_t loc = knh_bytes_rindex(urn, ':');
	int port = 80; /* default */
	char host_or_ip[128];
	if(loc != -1) {
		knh_int_t v = 80;
		knh_bytes_parseint(knh_bytes_last(urn, loc+1), &v);
		port = (int)v;
		urn = knh_bytes_first(urn, loc);
	}
	knh_format_bytes(host_or_ip, sizeof(host_or_ip), urn);
	DBG_P("opening Channel host='%s', port=%d", host_or_ip, port);
	return (knh_io_t)knh_socket_open(ctx, host_or_ip, port, 0/*isThrowable*/);
}

static void knh_iodrv_init__Channel(Ctx *ctx, Object *stream, char *mode)
{
}

static knh_intptr_t knh_iodrv_read__Channel(Ctx *ctx, knh_io_t sd, char *buf, size_t bufsiz)
{
	return knh_socket_recv(ctx, (knh_intptr_t)sd, buf, bufsiz, 0);
}

static knh_intptr_t knh_iodrv_write__Channel(Ctx *ctx, knh_io_t sd, char *buf, size_t bufsiz)
{
	return knh_socket_send(ctx, (knh_intptr_t)sd, buf, bufsiz, 0);
}

static void knh_iodrv_close__Channel(Ctx *ctx, knh_io_t sd)
{
	knh_socket_close(ctx, (knh_intptr_t)sd);
}

static knh_StreamDSPI_t IO__Channel = {
	K_DSPI_STREAM, "Channel",
	4096,
	knh_iodrv_open__Channel,
	knh_iodrv_init__Channel,
	knh_iodrv_read__Channel,
	knh_iodrv_write__Channel,
	knh_iodrv_close__Channel
};

knh_StreamDSPI_t *knh_getChannelDriver(void)
{
	return &IO__Channel;
}


static knh_IntData_t IntConstData[] = {
		{"Socket.AF_UNIX",AF_UNIX},
		{"Socket.AF_LOCAL", AF_LOCAL},
		{"Socket.AF_INET",AF_INET},
		{"Socket.AF_INET6",AF_INET6},
		{"Socket.AF_IPX",AF_IPX},
		{"Socket.SOCK_STREAM",SOCK_STREAM},
		{"Socket.SOCK_DGRAM",SOCK_DGRAM},
		{"Socket.SOCK_SEQPACKET",SOCK_SEQPACKET},
		{"Socket.SOCK_RAW",SOCK_RAW},
		{"Socket.SOCK_RDM",SOCK_RDM},
		{NULL, -1} // end of const
};

KNHAPI(void) init(Ctx *ctx, const knh_PackageLoaderAPI_t *kapi)
{
    kapi->loadIntData(ctx, IntConstData);
}

#ifdef __cplusplus
}
#endif
