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

/* ************************************************************************ */

#include<konoha1.h>

#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
/* ConstData */

static knh_IntData_t IntConstData[] = {
	{"System.SIGHUP", SIGHUP},   // hang up (1)
	{"System.SIGINT", SIGINT},   // interrupt (2)
	{"System.SIGQUIT", SIGQUIT}, // quit (3)
	{"System.SIGABRT", SIGABRT}, // abort (9)
	{"System.SIGKILL", SIGKILL}, // kill 9
	{"System.SIGALRM", SIGALRM}, // alarm clock (14)
	{"System.SIGTERM", SIGTERM}, // software termination signal 15
	{"System.SIGBUS",  SIGBUS},
	{"System.SIGSEGV", SIGSEGV},
	{"System.SIGPIPE", SIGPIPE},
//	{"System.WNOHANG", WNOHANG},  // What is THIS?
//	{"System.WUNTRACED", WUNTRACED},
//	{"System.WCONTINUED", WCONTINUED},
	{NULL}  // end of const data
};

//static knh_FloatData_t FloatConstData[] = {
//	{NULL}  // end of const data
//};
//
//static knh_StringData_t StringConstData[] = {
//	{NULL}  // end of const data
//};

/* ------------------------------------------------------------------------ */
/* [API] */

//## @Native String System.getHostName();
METHOD System_getHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *res = TS_EMPTY;
	char buf[256];
	KNH_RESET_ERRNO();
	if(gethostname(buf, sizeof(buf)) == -1) {
		LOGDATA = {__ERRNO__};
		NOTE_Failed("gethostname");
	}
	else {
		res = new_String(ctx, (const char*)buf);
	}
	RETURN_(res);
}

//## @Native String System.getLogin();
METHOD System_getLogin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_String(ctx, getlogin()));
}

//## @Native int System.getUid();
METHOD System_getUid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getuid());
}

//## @Native int System.getEuid();
METHOD System_getEuid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(geteuid());
}

//## @Native int System.getGid();
METHOD System_getGid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getgid());
}

//## @Native int System.getEgid();
METHOD System_getEgid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getegid());
}

//## @Native int System.getPid();
METHOD System_getPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getpid());
}

//## @Native int System.getPPid();
METHOD System_getPPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getppid());
}

//## @Native Boolean System.kill(int pid, int signal);
METHOD System_kill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int tf = 1;
	KNH_RESET_ERRNO();
	if(kill(Int_to(int, sfp[1]), Int_to(int, sfp[2])) == -1) {
		LOGDATA = {iDATA("pid", Int_to(int, sfp[1])), iDATA("signal", Int_to(int, sfp[1])), __ERRNO__};
		NOTE_Failed("kill");
		tf = 0;
	}
	RETURNb_(tf);
}

//## @Native int System.sleep(int sec);
METHOD System_sleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sleep(Int_to(int, sfp[1])));
}

//## @Native Boolean System.usleep(int sec);
METHOD System_usleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
//  FIXME
//	RETURN_ERRNO(usleep, Int_to(int, sfp[1]));
}

//## @Native Boolean System.raise(int signal);
METHOD System_raise(CTX ctx, knh_sfp_t *sfp _RIX)
{
//  FIXME
//	RETURN_ERRNO(raise, Int_to(int, sfp[1]));
}

/* ------------------------------------------------------------------------ */

//## @Native String System.getCwd();
METHOD System_getCwd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char tmpbuf[K_PATHMAX];
	getcwd(tmpbuf, sizeof(tmpbuf));
	RETURN_(new_String(ctx, (const char*)tmpbuf));
}

///* ------------------------------------------------------------------------ */
////## @Native boolean System.chDir(String dirname);
//
//METHOD System_chDir(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	char tmpbuf[FILEPATH_BUFSIZ];
//	if(IS_NULL(sfp[1].s)) {
//		knh_format_ospath(ctx, tmpbuf, sizeof(tmpbuf), ".");
//	}
//	else {
//		knh_format_ospath(ctx, tmpbuf, sizeof(tmpbuf), S_tochar(sfp[1].s));
//	}
//	LOG_RETURN_ERRNO(LOG_DEBUG, "path='%s'", chdir, tmpbuf);
//}

///* ------------------------------------------------------------------------ */
//
//knh_bool_t knh_unlink(CTX ctx, knh_bytes_t path)
//{
//	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, path);
//	char *phname = knh_cwb_ospath(ctx, cwb);
//#if defined(K_USING_POSIX)
//	PERROR_returnb_(unlink, phname);
//#elif defined(K_USING_WINDOWS)
//	PERROR_returnb_(DeleteFileA, phname);
//#else
//	(void)phname;
//	PERROR_returnb_(UnsupportedAPI, ctx, __FUNCTION__);
//#endif
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_bool_t knh_rename(CTX ctx, knh_bytes_t on, knh_bytes_t nn)
//{
//	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, on);
//	char *phname = knh_cwb_ospath(ctx, cwb);
//	knh_cwb_t cwbbuf2, *cwb2 = knh_cwb_openinit(ctx, &cwbbuf2, nn);
//	char *phname2 = knh_cwb_ospath(ctx, cwb2);
//#if defined(K_USING_POSIX)
//	PERROR_returnb_(rename, phname, phname2);
//#elif defined(K_USING_WINDOWS)
//	PERROR_returnb_(MoveFileA, phname, pathnema2);
//#else
//	(void)phname; (void)phname2;
//	PERROR_returnb_(UnsupportedAPI, ctx, __FUNCTION__);
//#endif
//}
//
///* ------------------------------------------------------------------------ */
////## @Native @Unsafe Boolean System.unlink(String path);
//
//static METHOD System_unlink(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SECURE(ctx, sfp);
//	RETURNb_(knh_unlink(ctx, S_tobytes(sfp[1].s), knh_Context_isStrict(ctx)));
//}
//
///* ------------------------------------------------------------------------ */
////## @Native @Unsafe Boolean System.rename(String path, String newpath);
//
//static METHOD System_rename(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	KNH_SECURE(ctx, sfp);
//	RETURNb_(knh_rename(ctx, S_tobytes(sfp[1].s), S_tobytes(sfp[2].s), knh_Context_isStrict(ctx)));
//}
//
//
///* ======================================================================== */
///* [PIPE] */
//
//static
//knh_io_t knh_iodrv_open__PIPE(CTX ctx, knh_bytes_t file, char *mode, int isThrowable)
//{
//	char *cmd = (char*)knh_bytes_skipscheme(file).buf;
//	FILE *fp = NULL;
//
//	KNH_WARNING(ctx, "opening pipe '%s'", cmd);
//	//KNH_SECURE(ctx, sfp);
//	if(mode != NULL && mode[0] == 'r') {
//		fp = popen(cmd, "r");
//	}
//	else {
//		fp = popen(cmd, "w");
//	}
//	if(fp == NULL) {
//		KNH_PERRNO(ctx, NULL,"IO!!", "popen", isThrowable);
//		return (knh_io_t)-1;
//	}
//	return (knh_io_t)fp;
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//void knh_iodrv_init__NOP(CTX ctx, Object *stream, char *mode)
//{
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//knh_intptr_t knh_iodrv_read__PIPE(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
//{
//	FILE *fp = (FILE*)fd;
//	size_t ssize = fread(buf, 1, bufsiz, fp);
//	return ssize;
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//knh_intptr_t knh_iodrv_write__PIPE(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
//{
//	FILE *fp = (FILE*)fd;
//	size_t ssize = fwrite(buf, 1, bufsiz, fp);
//	fflush(fp);
//	return ssize;
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//void knh_iodrv_close__PIPE(CTX ctx, knh_io_t fd)
//{
//	FILE *fp = (FILE*)fd;
//	pclose(fp);
//}
//
///* ------------------------------------------------------------------------ */
///* @data */
//
//static knh_StreamDSPI_t IO__PIPE = {
//	KNH_STREAM_DSPI, "pipe",
//	0,
//	knh_iodrv_open__PIPE,
//	knh_iodrv_init__NOP,
//	knh_iodrv_read__PIPE,
//	knh_iodrv_write__PIPE,
//	knh_iodrv_close__PIPE
//};

//KNHAPI(int) init(CTX ctx)
//{
//	KNH_NOTICE(ctx, "loading posix package ..");
//	knh_loadIntConstData(ctx, IntConstData);
//	knh_loadFloatConstData(ctx, FloatConstData);
//	knh_loadStringConstData(ctx, StringConstData);
//
//	// pipe dirver
//	knh_addIODriver(ctx, NULL, &IO__PIPE);
//	knh_addIODriver(ctx, "sh", &IO__PIPE);
//	knh_addIODriver(ctx, "cmd", &IO__PIPE);
//	return 1;
//}

/* ======================================================================== */

#ifdef _SETUP

EXPORTAPI(const knh_PackageDef_t*) init(CTX ctx)
{
	static const knh_PackageDef_t pkgdef = KNH_PKGINFO("posix", "0.1", "Konoha POSIX Library", NULL);
	return &pkgdef;
}


EXPORTAPI(void) SystemCONST(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
{
	if(ns == NULL) {
		kapi->loadIntData(ctx, ns, IntConstData);
	}
}

#endif


/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
