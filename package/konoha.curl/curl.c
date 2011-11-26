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
#include <konoha1/inlinelibs.h>
#include <curl/curl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_STR 12

/* ======================================================================== */
// [private functions]

/*String call back*/
static size_t write_String(char *buffer, size_t size, size_t nitems, void *string)
{
	kcontext_t *ctx = knh_getCurrentContext();
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	kString *res = (kString *)string;
	kString *str;
	kbytes_t buf = S_tobytes(res);
	size *= nitems;
	knh_Bytes_write(ctx, cwb->ba, buf);
	knh_Bytes_write(ctx, cwb->ba, new_bytes2(buffer, size));
	str = CWB_newString(ctx, cwb, 0);
	res->str.ubuf = str->str.ubuf;
	res->str.len = str->str.len;
	return size;
}

/*Bytes call back*/
static size_t write_Bytes(char *buffer, size_t size, size_t nitems, void *bytes)
{
	kcontext_t *ctx = knh_getCurrentContext();
	kBytes *res = (kBytes *)bytes;
	size *= nitems;
	knh_Bytes_write(ctx, res, new_bytes2(buffer, size));
	return size;
}

/* ------------------------------------------------------------------------ */

static void Curl_init(CTX ctx, kRawPtr *po)
{
	CURL *curl = curl_easy_init();
	po->rawptr = curl;
}

static void Curl_free(CTX ctx, kRawPtr *po)
{
	CURL *curl = (CURL *)po->rawptr;
	if (curl != NULL) {
		curl_easy_cleanup(curl);
		po->rawptr = NULL;
	}
}

//## @Native Curl Curl.new();
KMETHOD Curl_new(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(sfp[0].p);
}

//## @Native void Curl.setOpt(int type, dynamic data);
KMETHOD Curl_setOpt(CTX ctx, ksfp_t *sfp _RIX)
{
	CURL* curl = RawPtr_to(CURL*, sfp[0]);
	long curlopt = Int_to(long, sfp[1]);
//	FILE* fp = NULL;
	kString* str = NULL;
	kBytes* bytes = NULL;
	switch(curlopt) {
	// @FROM http://www.phpmanual.jp/function.curl-setopt.html
	case CURLOPT_AUTOREFERER:
		//		case CURLOPT_BINARYTRANSFER:
	case CURLOPT_COOKIESESSION:
	case CURLOPT_CRLF:
	case CURLOPT_DNS_USE_GLOBAL_CACHE:
	case CURLOPT_FAILONERROR:
	case CURLOPT_FILETIME:
	case CURLOPT_FOLLOWLOCATION:
	case CURLOPT_FORBID_REUSE:
	case CURLOPT_FRESH_CONNECT:
	case CURLOPT_FTP_USE_EPRT:
	case CURLOPT_FTP_USE_EPSV:
	case CURLOPT_FTPAPPEND:
		//		case CURLOPT_FTPASCII:
	case CURLOPT_FTPLISTONLY:
	case CURLOPT_HEADER:
	case CURLOPT_HTTPGET:
	case CURLOPT_HTTPPROXYTUNNEL:
		//		case CURLOPT_MUTE:
	case CURLOPT_NETRC:
	case CURLOPT_NOBODY:
	case CURLOPT_NOPROGRESS: /*	default TRUE */
	case CURLOPT_NOSIGNAL:
	case CURLOPT_POST:
	case CURLOPT_PUT:
		//		case CURLOPT_RETURNTRANSFER:
	case CURLOPT_SSL_VERIFYPEER:
	case CURLOPT_TRANSFERTEXT:
	case CURLOPT_UNRESTRICTED_AUTH:
	case CURLOPT_UPLOAD:
	case CURLOPT_VERBOSE: {
		int bvalue = 1;
		if(IS_NULL(sfp[2].o) ||
				((IS_Boolean(sfp[2].o) && sfp[2].bvalue == 0)) ||
				((IS_Int(sfp[2].o) && Int_to(int, sfp[2]) == 0))) {
			bvalue = 0;
		}
		curl_easy_setopt(curl, curlopt, bvalue);
		break;
	}
	case CURLOPT_BUFFERSIZE:
	case CURLOPT_CLOSEPOLICY:
	case CURLOPT_CONNECTTIMEOUT:
	case CURLOPT_DNS_CACHE_TIMEOUT:
	case CURLOPT_FTPSSLAUTH:
	case CURLOPT_HTTP_VERSION:
	case CURLOPT_HTTPAUTH:
	case CURLAUTH_ANY:
	case CURLAUTH_ANYSAFE:
	case CURLOPT_INFILESIZE:
	case CURLOPT_LOW_SPEED_LIMIT:
	case CURLOPT_LOW_SPEED_TIME:
	case CURLOPT_MAXCONNECTS:
	case CURLOPT_MAXREDIRS:
	case CURLOPT_PORT:
	case CURLOPT_PROXYAUTH:
	case CURLOPT_PROXYPORT:
	case CURLOPT_PROXYTYPE:
	case CURLOPT_RESUME_FROM:
	case CURLOPT_SSL_VERIFYHOST:
	case CURLOPT_SSLVERSION:
	case CURLOPT_TIMECONDITION:
	case CURLOPT_TIMEOUT:
	case CURLOPT_TIMEVALUE: {
		if(IS_Int(sfp[2].o)) {
			curl_easy_setopt(curl, curlopt, Int_to(long, sfp[2]));
		}
		else {
			KNH_NTRACE2(ctx, "Curl.setOpt", K_FAILED, KNH_LDATA(LOG_msg("TypeError")));
		}
		break;
	}
	case CURLOPT_CAINFO:
	case CURLOPT_CAPATH:
	case CURLOPT_COOKIE:
	case CURLOPT_COOKIEFILE: /* filename */
	case CURLOPT_COOKIEJAR:
	case CURLOPT_CUSTOMREQUEST:
		//		case CURLOPT_EGBSOCKET:
	case CURLOPT_ENCODING:
	case CURLOPT_FTPPORT:
	case CURLOPT_INTERFACE:
	case CURLOPT_KRB4LEVEL:
	case CURLOPT_POSTFIELDS:
	case CURLOPT_PROXY:
	case CURLOPT_PROXYUSERPWD:
	case CURLOPT_RANDOM_FILE:
	case CURLOPT_RANGE:
	case CURLOPT_REFERER:
	case CURLOPT_SSL_CIPHER_LIST:
	case CURLOPT_SSLCERT:
		//		case CURLOPT_SSLCERTPASSWD:
	case CURLOPT_SSLCERTTYPE:
	case CURLOPT_SSLENGINE:
	case CURLOPT_SSLENGINE_DEFAULT:
	case CURLOPT_SSLKEY:
		//		case CURLOPT_SSLKEYPASSWD:
	case CURLOPT_SSLKEYTYPE:
	case CURLOPT_URL:
	case CURLOPT_USERAGENT:
	case CURLOPT_USERPWD: {
		if(IS_String(sfp[2].o)) {
			curl_easy_setopt(curl, curlopt, String_to(char*,sfp[2]));
		}
		else {
			KNH_NTRACE2(ctx, "Curl.setOpt", K_FAILED, KNH_LDATA(LOG_msg("TypeError")));
		}
		break;
	}
	case CURLOPT_FILE:
	case CURLOPT_INFILE:
	case CURLOPT_STDERR:
	case CURLOPT_WRITEHEADER:
////		if(IS_OutputStream(sfp[2].o)) {
////			fp = (FILE*)DP(sfp[2].w)->fio;
////			curl_easy_setopt(curl, curlopt, fp);
////			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
////		}
//		else
		if(IS_String(sfp[2].o)){
			//TODO
			//write result to sfp[2] as String
			str = (kString*)sfp[2].o;
			curl_easy_setopt(curl, curlopt, str);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_String);
		}
		else if(IS_Bytes(sfp[2].o)){
			//TODO
			//write result to sfp[2] as Bytes
			bytes = (kBytes*)sfp[2].o;
			curl_easy_setopt(curl, curlopt, bytes);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_Bytes);
		}
		else {
			//if(knh_Context_isStrict(ctx)) {
			//KNH_THROW__T(ctx, "Type!!: data must be OutputStream");
			//}
			KNH_NTRACE2(ctx, "Curl.setOpt", K_FAILED, KNH_LDATA(LOG_msg("TypeError")));
		}
		break;
//				case CURLOPT_WRITEFUNCTION: {
//					if(IS_OutputStream(sfp[2].w)) {
//						curl_write_callback cc = knh_curl_callback;
//						curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cc);
//					}
//					break;
//				}
	default: {
		KNH_NTRACE2(ctx, "Curl.setOpt:UnsupportedOption", K_FAILED, KNH_LDATA(LOG_i("curlopt", curlopt)));
		break;
	}
	}
	RETURNvoid_();
}

//## @Native boolean Curl.perform();
KMETHOD Curl_perform(CTX ctx, ksfp_t *sfp _RIX)
{
	CURL* curl = RawPtr_to(CURL*, sfp[0]);
	CURLcode res = curl_easy_perform(curl);
	if ( res != CURLE_OK ){
		KNH_NTRACE2(ctx, "Curl.perform", K_FAILED, KNH_LDATA(LOG_i("CURLcode", res), LOG_s("error", curl_easy_strerror(res))));
	}
	RETURNb_((res == CURLE_OK));
}

//## @Native dynamic Curl.getInfo(int type);
KMETHOD Curl_getInfo(CTX ctx, ksfp_t *sfp _RIX)
{
	CURL* curl = RawPtr_to(CURL*, sfp[0]);
	char *strptr = NULL;
	long lngptr = 0;
	double dblptr = 0;
	if(curl != NULL) {
		kint_t curlinfo = Int_to(int , sfp[1]);
		switch(curlinfo) {
		case CURLINFO_HEADER_SIZE:
		case CURLINFO_REQUEST_SIZE:
			curl_easy_getinfo(curl, curlinfo, &lngptr);
			RETURN_(new_Int(ctx, lngptr));
			break;
		case CURLINFO_REDIRECT_TIME:
		case CURLINFO_TOTAL_TIME:
		case CURLINFO_NAMELOOKUP_TIME:
		case CURLINFO_CONNECT_TIME:
		case CURLINFO_PRETRANSFER_TIME:
		case CURLINFO_STARTTRANSFER_TIME:
		case CURLINFO_SIZE_UPLOAD:
		case CURLINFO_SIZE_DOWNLOAD:
		case CURLINFO_SPEED_DOWNLOAD:
		case CURLINFO_SPEED_UPLOAD:
			curl_easy_getinfo(curl, curlinfo, &dblptr);
			RETURN_(new_Float(ctx, dblptr));
			break;
		case CURLINFO_EFFECTIVE_URL:
		case CURLINFO_CONTENT_TYPE:
			curl_easy_getinfo(curl, curlinfo, &strptr);
			RETURN_(new_String(ctx, strptr));
			break;
		default: {
			KNH_NTRACE2(ctx, "curl_easy_getinfo", K_FAILED, KNH_LDATA(LOG_i("curlinfo", curlinfo)));
			break;
		}
		}
	}
	RETURN_(KNH_NULL);
}

///* ------------------------------------------------------------------------ */
///* StreamDSPI */
//
//typedef struct {
//	CURL *curl;
//	char *buffer;               /* buffer to store cached data*/
//	const char *charset;
//	const char *contenttype;
//	int pos;
//	int buffer_len;             /* currently allocated buffers length */
//	int buffer_pos;             /* end of data in buffer*/
//	int still_running;          /* Is background url fetch still in progress */
//} CURLFILE;
//
///* This global variable was originated in a sample code in libcurl */
//static CURLM *multi_handle = NULL;
//static CURLM *emulti_handle = NULL;
//
//static size_t write_callback(char *buffer, size_t size, size_t nitems, void *userp)
//{
//	char *newbuff;
//	CURLFILE *url = (CURLFILE *)userp;
//	size *= nitems;
//	long rembuff = url->buffer_len - url->buffer_pos; /* remaining space in buffer */
//	if(size > rembuff) {
//		newbuff = realloc(url->buffer, url->buffer_len + (size - rembuff));
//		if(newbuff == NULL) {
//			size = rembuff;
//		}
//		else {
//			url->buffer_len += size - rembuff;
//			url->buffer = newbuff;
//		}
//	}
//	memcpy(&url->buffer[url->buffer_pos], buffer, size);
//	url->buffer_pos += size;
//	if(url->contenttype == NULL){
//		char *type = NULL;
//		curl_easy_getinfo(url->curl, CURLINFO_CONTENT_TYPE, &type);
//		if(type != NULL){
//			char *charset = NULL;
//			charset = strrchr(type, '=');
//			if(charset != NULL){
//				charset++;
//				type = strtok(type, ";");
//			}
//			url->charset = (const char*)charset;
//			url->contenttype = (const char*)type;
//		}
//	}
//	return size;
//}
//
//static int fill_buffer(CURLFILE *file, int want, int waittime)
//{
//	fd_set fdread;
//	fd_set fdwrite;
//	fd_set fdexcep;
//	struct timeval timeout;
//	int rc;
//	/* only attempt to fill buffer if transactions still running and buffer
//	 * doesnt exceed required size already
//	 */
//	if((!file->still_running) || (file->buffer_pos > want))
//		return 0;
//
//	/* attempt to fill buffer */
//	do {
//		int maxfd = -1;
//		FD_ZERO(&fdread);
//		FD_ZERO(&fdwrite);
//		FD_ZERO(&fdexcep);
//
//		/* set a suitable timeout to fail on */
//		timeout.tv_sec = 60; /* 1 minute */
//		timeout.tv_usec = 0;
//
//		/* get file descriptors from the transfers */
//		curl_multi_fdset(multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);
//
//		/* In a real-world program you OF COURSE check the return code of the
//           function calls.  On success, the value of maxfd is guaranteed to be
//           greater or equal than -1.  We call select(maxfd + 1, ...), specially
//           in case of (maxfd == -1), we call select(0, ...), which is basically
//           equal to sleep. */
//
//		rc = select(maxfd+1, &fdread, &fdwrite, &fdexcep, &timeout);
//		switch(rc) {
//		case -1: /* select error */
//		case 0: break;
//		default:
//			/* timeout or readable/writable sockets */
//			/* note we *could* be more efficient and not wait for
//			 * CURLM_CALL_MULTI_PERFORM to clear here and check it on re-entry
//			 * but that gets messy */
//			while(curl_multi_perform(multi_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM);
//			break;
//		}
//	} while(file->still_running && (file->buffer_pos < want));
//	return 1;
//}
//
///* use to remove want bytes from the front of a files buffer */
//static int use_buffer(CURLFILE *file, int want)
//{
//	/* sort out buffer */
//	if((file->buffer_pos - want) <= 0) {
//		/* ditch buffer - write will recreate */
//		if(file->buffer != NULL) free(file->buffer);
//		file->buffer=NULL;
//		file->buffer_pos=0;
//		file->buffer_len=0;
//	} else { /* move rest down make it available for later */
//		memmove(file->buffer, &file->buffer[want], (file->buffer_pos - want));
//		file->buffer_pos -= want;
//	}
//	return 0;
//}
//
//static int CURL_open(CTX ctx, kbytes_t path, const char *mode)
//{
//	//TODO mode treats as method
//	CURLFILE *file = malloc(sizeof(CURLFILE));
//	if(file == NULL) return (int)NULL;
//	memset(file, 0, sizeof(CURLFILE));
//	file->curl = curl_easy_init();
//	curl_easy_setopt(file->curl, CURLOPT_URL, path.ubuf);
//	curl_easy_setopt(file->curl, CURLOPT_WRITEDATA, file);
//	curl_easy_setopt(file->curl, CURLOPT_VERBOSE, 0L);
//	curl_easy_setopt(file->curl, CURLOPT_WRITEFUNCTION, write_callback);
//	if(!multi_handle) multi_handle = curl_multi_init();
//	curl_multi_add_handle(multi_handle, file->curl);
//
//	/* lets start the fetch */
//	while(curl_multi_perform(multi_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM );
//
//	if((file->buffer_pos == 0) && (!file->still_running)) {
//		/* if still_running is 0 now, we should return NULL */
//		/* make sure the easy handle is not in the multi handle anymore */
//		curl_multi_remove_handle(multi_handle, file->curl);
//		/* cleanup */
//		curl_easy_cleanup(file->curl);
//		free(file);
//		file = NULL;
//	}
//	return (int)file;
//}
//
////new OutputStream(http://...)
//static int CURL_init(CTX ctx, kbytes_t path, const char *mode)
//{
//	return (int)NULL;
//}
//
//static void CURL_close(CTX ctx, int fd)
//{
//	CURLFILE *file = (CURLFILE*)fd;
//	curl_multi_remove_handle(multi_handle, file->curl);
//	curl_easy_cleanup(file->curl);
//	if(file->buffer) free(file->buffer);
//	free(file);
//}
//
//static int url_feof(CURLFILE *file)
//{
//	int ret=0;
//	if((file->buffer_pos == 0) && (!file->still_running))
//		ret = 1;
//	return ret;
//}
//
//static kintptr_t CURL_read(CTX ctx, int fd, char *buf, size_t bufsiz)
//{
//	CURLFILE *file = (CURLFILE*)fd;
//	if(file == NULL) return 0;
//	fill_buffer(file, bufsiz, 1);
//	if(!file->buffer_pos) return 0;
//	/* ensure only available data is considered */
//	if(file->buffer_pos < bufsiz) bufsiz = file->buffer_pos;
//	/* xfer data to caller */
//	memcpy(buf, file->buffer, bufsiz);
//	use_buffer(file, bufsiz);
//	return bufsiz;
//}
//
//static kintptr_t CURL_write(CTX ctx, int fd, const char *buf, size_t bufsiz)
//{
//	return 0;
//}
//
//static int CURL_feof(CTX ctx, int fd)
//{
//	return url_feof((CURLFILE*)fd);
//}
//
//static int pos = 0;
//static int CURL_getc(CTX ctx, int fd)
//{
//    CURLFILE *file = (CURLFILE*)fd;
//    if(!file->buffer_pos || file->buffer_pos < file->buffer_len) 
//        fill_buffer(file, 1024, 1);
//    return file->buffer[pos++];
//}
//
//static const char* CURL_getContentType(CTX ctx, int fd)
//{
//	CURLFILE *file = (CURLFILE*)fd;
//	if(file != NULL){
//		if(file->contenttype != NULL){
//			return file->contenttype;
//		}
//	}
//	return NULL;
//}
//
//static const char* CURL_getCharset(CTX ctx, int fd)
//{
//	CURLFILE *file = (CURLFILE*)fd;
//	if(file != NULL){
//		if(file->charset != NULL){
//			return file->charset;
//		}
//	}
//	return NULL;
//}
//
//static knh_StreamDSPI_t CURLDSPI_STREAM = {
//	K_DSPI_STREAM, "libcurl", 0,
//	CURL_open, CURL_init, CURL_read, CURL_write, CURL_close,
//	CURL_feof, CURL_getc, CURL_getContentType, CURL_getCharset
//};
//
////void url_rewind(CURLFILE *file)
////{
////	curl_multi_remove_handle(multi_handle, file->curl);
////	curl_multi_add_handle(multi_handle, file->curl);
////	if(file->buffer) free(file->buffer);
////	file->buffer=NULL;
////	file->buffer_pos=0;
////	file->buffer_len=0;
////}
//
//static kuintptr_t CURL_exists(CTX ctx, kbytes_t path, kNameSpace *ns)
//{
//	CURLFILE *file = malloc(sizeof(CURLFILE));
//	if(file == NULL) return (kuintptr_t)0;
//	memset(file, 0, sizeof(CURLFILE));
//	file->curl = curl_easy_init();
//	curl_easy_setopt(file->curl, CURLOPT_URL, path.ubuf);
//	curl_easy_setopt(file->curl, CURLOPT_WRITEDATA, file);
//	curl_easy_setopt(file->curl, CURLOPT_VERBOSE, 0L);
//	curl_easy_setopt(file->curl, CURLOPT_WRITEFUNCTION, write_callback);
//
//	emulti_handle = curl_multi_init();
//	curl_multi_add_handle(emulti_handle, file->curl);
//	
//	/* lets start the fetch */
//	while(curl_multi_perform(emulti_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM );
//	if((file->buffer_pos == 0) && (!file->still_running)) {
//		/* if still_running is 0 now, we should return NULL */
//		/* make sure the easy handle is not in the multi handle anymore */
//		curl_multi_remove_handle(emulti_handle, file->curl);
//		/* cleanup */
//		curl_easy_cleanup(file->curl);
//		free(file);
//		emulti_handle = NULL;
//		file = NULL;
//		return (kuintptr_t)0;
//	}
//	emulti_handle = NULL;
//	free(file);
//    return (kuintptr_t)1;
//}
//
//static kbool_t CURL_isTyped(CTX ctx, kclass_t cid)
//{
//	return PATH_isTyped(cid);
//}
//
//static Object* newObjectNULL(CTX ctx, kclass_t cid, kString *s, kNameSpace *n)
//{
//    return (Object*)s;
//}
//
//static knh_PathDSPI_t CURLDSPI_PATH = {
//	K_DSPI_PATH, "libcurl",
//	CLASS_InputStream, CLASS_Tvoid,
//	CURL_exists, CURL_isTyped, newObjectNULL
//};

/* ------------------------------------------------------------------------ */
/* [ConstData] */

static knh_IntData_t CurlConstInt[] = {
	{"AUTOREFERER", CURLOPT_AUTOREFERER},
	{"COOKIESESSION", CURLOPT_COOKIESESSION},
	{"CRLF", CURLOPT_CRLF},
	{"DNS_USE_GLOBAL_CACHE", CURLOPT_DNS_USE_GLOBAL_CACHE},
	{"FAILONERROR", CURLOPT_FAILONERROR},
	{"FILETIME", CURLOPT_FILETIME},
	{"FOLLOWLOCATION", CURLOPT_FOLLOWLOCATION},
	{"FORBID_REUSE", CURLOPT_FORBID_REUSE},
	{"FRESH_CONNECT", CURLOPT_FRESH_CONNECT},
	{"FTP_USE_EPRT", CURLOPT_FTP_USE_EPRT},
	{"FTP_USE_EPSV", CURLOPT_FTP_USE_EPSV},
	{"FTPAPPEND", CURLOPT_FTPAPPEND},
	{"FTPLISTONLY", CURLOPT_FTPLISTONLY},
	{"HEADER", CURLOPT_HEADER},
	{"HTTPGET", CURLOPT_HTTPGET},
	{"HTTPPROXYTUNNEL", CURLOPT_HTTPPROXYTUNNEL},
	{"NETRC", CURLOPT_NETRC},
	{"NOBODY", CURLOPT_NOBODY},
	{"NOPROGRESS", CURLOPT_NOPROGRESS},
	{"NOSIGNAL", CURLOPT_NOSIGNAL},
	{"POST", CURLOPT_POST},
	{"PUT", CURLOPT_PUT},
	{"SSL_VERIFYPEER", CURLOPT_SSL_VERIFYPEER},
	{"TRANSFERTEXT", CURLOPT_TRANSFERTEXT},
	{"UNRESTRICTED_AUTH", CURLOPT_UNRESTRICTED_AUTH},
	{"UPLOAD", CURLOPT_UPLOAD},
	{"VERBOSE", CURLOPT_VERBOSE},
	{"BUFFERSIZE", CURLOPT_BUFFERSIZE},
	{"CLOSEPOLICY", CURLOPT_CLOSEPOLICY},
	{"CONNECTTIMEOUT", CURLOPT_CONNECTTIMEOUT},
	{"DNS_CACHE_TIMEOUT", CURLOPT_DNS_CACHE_TIMEOUT},
	{"FTPSSLAUTH", CURLOPT_FTPSSLAUTH},
	{"HTTP_VERSION", CURLOPT_HTTP_VERSION},
	{"HTTPAUTH", CURLOPT_HTTPAUTH},
	{"AUTH_ANY", CURLAUTH_ANY},
	{"AUTH_ANYSAFE", CURLAUTH_ANYSAFE},
	{"INFILESIZE", CURLOPT_INFILESIZE},
	{"LOW_SPEED_LIMIT", CURLOPT_LOW_SPEED_LIMIT},
	{"LOW_SPEED_TIME", CURLOPT_LOW_SPEED_TIME},
	{"MAXCONNECTS", CURLOPT_MAXCONNECTS},
	{"MAXREDIRS", CURLOPT_MAXREDIRS},
	{"PORT", CURLOPT_PORT},
	{"PROXYAUTH", CURLOPT_PROXYAUTH},
	{"PROXYPORT", CURLOPT_PROXYPORT},
	{"PROXYTYPE", CURLOPT_PROXYTYPE},
	{"RESUME_FROM", CURLOPT_RESUME_FROM},
	{"SSL_VERIFYHOST", CURLOPT_SSL_VERIFYHOST},
	{"SSLVERSION", CURLOPT_SSLVERSION},
	{"TIMECONDITION", CURLOPT_TIMECONDITION},
	{"TIMEOUT", CURLOPT_TIMEOUT},
	{"TIMEVALUE", CURLOPT_TIMEVALUE},
	{"CAINFO", CURLOPT_CAINFO},
	{"CAPATH", CURLOPT_CAPATH},
	{"COOKIE", CURLOPT_COOKIE},
	{"COOKIEFILE", CURLOPT_COOKIEFILE},
	{"COOKIEJAR", CURLOPT_COOKIEJAR},
	{"CUSTOMREQUEST", CURLOPT_CUSTOMREQUEST},
	{"ENCODING", CURLOPT_ENCODING},
	{"FTPPORT", CURLOPT_FTPPORT},
	{"INTERFACE", CURLOPT_INTERFACE},
	{"KRB4LEVEL", CURLOPT_KRB4LEVEL},
	{"POSTFIELDS", CURLOPT_POSTFIELDS},
	{"PROXY", CURLOPT_PROXY},
	{"PROXYUSERPWD", CURLOPT_PROXYUSERPWD},
	{"RANDOM_FILE", CURLOPT_RANDOM_FILE},
	{"RANGE", CURLOPT_RANGE},
	{"REFERER", CURLOPT_REFERER},
	{"SSL_CIPHER_LIST", CURLOPT_SSL_CIPHER_LIST},
	{"SSLCERT", CURLOPT_SSLCERT},
	{"SSLCERTTYPE", CURLOPT_SSLCERTTYPE},
	{"SSLENGINE", CURLOPT_SSLENGINE},
	{"SSLENGINE_DEFAULT", CURLOPT_SSLENGINE_DEFAULT},
	{"SSLKEY", CURLOPT_SSLKEY},
	{"SSLKEYTYPE", CURLOPT_SSLKEYTYPE},
	{"URL", CURLOPT_URL},
	{"USERAGENT", CURLOPT_USERAGENT},
	{"USERPWD", CURLOPT_USERPWD},
	{"FILE", CURLOPT_FILE},
	{"DATA", CURLOPT_WRITEDATA},
	{"INFILE", CURLOPT_INFILE},
	{"STDERR", CURLOPT_STDERR},
	{"WRITEHEADER", CURLOPT_WRITEHEADER},
	{"INFO_HEADER_SIZE", CURLINFO_HEADER_SIZE},
	{"INFO_REQUEST_SIZE", CURLINFO_REQUEST_SIZE},
	{"INFO_REDIRECT_TIME", CURLINFO_REDIRECT_TIME},
	{"INFO_TOTAL_TIME", CURLINFO_TOTAL_TIME},
	{"INFO_NAMELOOKUP_TIME", CURLINFO_NAMELOOKUP_TIME},
	{"INFO_CONNECT_TIME", CURLINFO_CONNECT_TIME},
	{"INFO_PRETRANSFER_TIME", CURLINFO_PRETRANSFER_TIME},
	{"INFO_STARTTRANSFER_TIME", CURLINFO_STARTTRANSFER_TIME},
	{"INFO_SIZE_UPLOAD", CURLINFO_SIZE_UPLOAD},
	{"INFO_SIZE_DOWNLOAD", CURLINFO_SIZE_DOWNLOAD},
	{"INFO_SPEED_DOWNLOAD", CURLINFO_SPEED_DOWNLOAD},
	{"INFO_SPEED_UPLOAD", CURLINFO_SPEED_UPLOAD},
	{"INFO_EFFECTIVE_URL", CURLINFO_EFFECTIVE_URL},
	{"INFO_CONTENT_TYPE", CURLINFO_CONTENT_TYPE},
	{NULL} // end of const data
};

DEFAPI(void) defCurl(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Curl";
	cdef->init = Curl_init;
	cdef->free = Curl_free;
}

DEFAPI(void) constCurl(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, CurlConstInt);
}

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.curl");
}
#endif /* _SETUP */

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
