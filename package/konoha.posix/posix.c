///****************************************************************************
// * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
// *
// * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
// * All rights reserved.
// *
// * You may choose one of the following two licenses when you use konoha.
// * See www.konohaware.org/license.html for further information.
// *
// * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
// * (2) Konoha Software Foundation License 1.0
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
// * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
// ****************************************************************************/
//
//// **************************************************************************
//// LIST OF CONTRIBUTERS
////  kimio - Kimio Kuramitsu, Yokohama National University, Japan
////
//// **************************************************************************
//
///* ************************************************************************ */
//
//#include<konoha1.h>
//
//#include <unistd.h>
//#include <signal.h>
//#include <dirent.h>
//#include <sys/stat.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//#define K_PERROR_LIBNAME "libc"
//
///* ======================================================================== */
///* ConstData */
//
//static knh_IntData_t IntConstData[] = {
//	{"System.SIGHUP", SIGHUP},   // hang up (1)
//	{"System.SIGINT", SIGINT},   // interrupt (2)
//	{"System.SIGQUIT", SIGQUIT}, // quit (3)
//	{"System.SIGABRT", SIGABRT}, // abort (9)
//	{"System.SIGKILL", SIGKILL}, // kill 9
//	{"System.SIGALRM", SIGALRM}, // alarm clock (14)
//	{"System.SIGTERM", SIGTERM}, // software termination signal 15
//	{"System.SIGBUS",  SIGBUS},
//	{"System.SIGSEGV", SIGSEGV},
//	{"System.SIGPIPE", SIGPIPE},
//	{"System.WNOHANG", WNOHANG},
//	{"System.WUNTRACED", WUNTRACED},
//	{"System.WCONTINUED", WCONTINUED},
//	{NULL}  // end of const data
//};
//
//static knh_FloatData_t FloatConstData[] = {
//	{NULL}  // end of const data
//};
//
//static knh_StringData_t StringConstData[] = {
//	{NULL}  // end of const data
//};
//
///* ------------------------------------------------------------------------ */
///* [API] */
//
////## @Native String System.getHostName();
//METHOD System_getHostName(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	char buf[256];
//	PERROR_RETURN_(gethostname, CLASS_String, buf, sizeof(buf));
//	RETURN_(ctx->api->new_String(ctx, buf));
//}
//
////## @Native String System.getLogin();
//METHOD System_getLogin(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURN_(ctx->api->new_String(ctx, getlogin()));
//}
//
////## @Native int System.getUid();
//METHOD System_getUid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(getuid());
//}
//
////## @Native int System.getEuid();
//METHOD System_getEuid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(geteuid());
//}
//
////## @Native int System.getGid();
//METHOD System_getGid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(getgid());
//}
//
////## @Native int System.getEgid();
//METHOD System_getEgid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(getegid());
//}
//
////## @Native int System.getPid();
//METHOD System_getPid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(getpid());
//}
//
////## @Native int System.getPPid();
//METHOD System_getPPid(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(getppid());
//}
//
////## @Native Boolean System.kill(int pid, int signal);
//METHOD System_kill(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	KNH_SECURE(ctx, sfp);
//	PERROR_RETURNb_(kill, Int_to(int, sfp[1]), Int_to(int, sfp[2]));
//}
//
////## @Native int System.sleep(int sec);
//METHOD System_sleep(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURNi_(sleep(Int_to(int, sfp[1])));
//}
//
////## @Native Boolean System.usleep(int sec);
//METHOD System_usleep(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	PERROR_RETURNb_(usleep, Int_to(int, sfp[1]));
//}
//
////## @Native Boolean System.raise(int signal);
//METHOD System_raise(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	PERROR_RETURNb_(raise, Int_to(int, sfp[1]));
//}
//
////##// int System.fork()
////METHOD System_fork(Ctx* ctx,knh_sfp_t* sfp)
////{
////	PERROR_RETURNi_(fork);
////}
////
/////* ------------------------------------------------------------------------ */
/////*int System.execv(String path, String[] argv, String[] env)*/
////METHOD System_execv(Ctx* ctx,knh_sfp_t* sfp)
////{
////	//char *path = String_to_(sfp[1]);
////	knh_Array_t *a = (knh_Array_t *)sfp[1].o;
////	int argc = knh_Array_size(a);
////	char **args = (char **)alloca((argc + 1) * sizeof(char*));
////	int i;
////	for (i = 0; i < argc; i++) {
////		args[i] = knh_String_tochar((knh_String_t *)knh_Array_n(a, i));
////	}
////	args[i] = NULL;
////	char *file = args[0];
////	int ret;
////	ret = execvp(file,args);
////	if(ret == -1){
////		KNH_THROW__T(ctx, "Error!!: cannot exec program!");
////	}
////	else{
////		KNH_RETURN_Int(ctx,sfp,ret);
////	}
////}
////
/////* ------------------------------------------------------------------------ */
/////*int System.wait()*/
////
////METHOD System_wait(Ctx* ctx,knh_sfp_t* sfp)
////{
////	int status;
////	int ret;
////	ret = (int)wait(&status);
////	if(ret == -1){
////		KNH_THROW__T(ctx, "Error!!: cannot take process ID!");
////	}
////	else{
////		KNH_RETURN_Int(ctx,sfp,ret);
////	}
////}
////
/////* ------------------------------------------------------------------------ */
/////*int System.waitPid(int pid)*/
////
////METHOD System_waitPid(Ctx* ctx,knh_sfp_t* sfp)
////{
////	int pid = Int_to(int, sfp[1]);
////	int option = 0;
////	if (IS_Int(sfp[2].o)) {
////		option = Int_to(int, sfp[2]);
////	}
////	int status;
////	int ret;
////	ret = (int)waitpid(pid,&status,option);
////	if (ret == -1) {
////		KNH_THROW__T(ctx, "Error!!: cannot take process ID!");
////	}
////	else {
////		if(pid == -1){
////
////		}
////		else if (option == 0 && pid > 0) {
////			ret = status;
////		}
////		// Value "ret" is dead child PID.
////		// If you want to get exit status
////		// you should set pid > 0 and opt = 0.
////		KNH_RETURN_Int(ctx,sfp,ret);
////	}
////}
//
///* -----------------------temporary for et2009------------------------------- */
//
////## @Native int System.system(String cmd)
//METHOD System_system(Ctx* ctx,knh_sfp_t* sfp)
//{
//	char *cmd = String_to_(sfp[1]);
//	PERROR_RETURNb_(system, String_to(char*, sfp[1]));
//}
//
///* ------------------------------------------------------------------------ */
//
////## @Native String System.getCwd();
//METHOD System_getCwd(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	char tmpbuf[FILEPATH_BUFSIZ];
//	PERROR_RETURNs_(getcwd, tmpbuf, sizeof(tmpbuf));
//}
//
///* ------------------------------------------------------------------------ */
////## @Native void System.chDir(String dirname);
//
//METHOD System_chDir(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_cwb_t cwbbuf, *cwb = ctx->api->cwb_open(ctx, &cwbbuf);
//	if(IS_NULL(sfp[1].s)) {
//		ctx->api->putc(ctx, cwb->w, '.');
//	}
//	else {
//		ctx->api->write(ctx, cwb->w, S_tobytes(stp[1].s));
//	}
//	ctx->api->cwb_ospath(ctx, cwb);
//	PERROR_RETURNb_(chdir, ctx->api->cwb_tochar(ctx, cwb));
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_bool_t knh_unlink(Ctx *ctx, knh_bytes_t path)
//{
//	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, path);
//	char *pathname = knh_cwb_ospath(ctx, cwb);
//#if defined(K_USING_POSIX)
//	PERROR_returnb_(unlink, pathname);
//#elif defined(K_USING_WINDOWS)
//	PERROR_returnb_(DeleteFileA, pathname);
//#else
//	(void)pathname;
//	PERROR_returnb_(UnsupportedAPI, ctx, __FUNCTION__);
//#endif
//}
//
///* ------------------------------------------------------------------------ */
//
//knh_bool_t knh_rename(Ctx *ctx, knh_bytes_t on, knh_bytes_t nn)
//{
//	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, on);
//	char *pathname = knh_cwb_ospath(ctx, cwb);
//	knh_cwb_t cwbbuf2, *cwb2 = knh_cwb_openinit(ctx, &cwbbuf2, nn);
//	char *pathname2 = knh_cwb_ospath(ctx, cwb2);
//#if defined(K_USING_POSIX)
//	PERROR_returnb_(rename, pathname, pathname2);
//#elif defined(K_USING_WINDOWS)
//	PERROR_returnb_(MoveFileA, pathname, pathnema2);
//#else
//	(void)pathname; (void)pathname2;
//	PERROR_returnb_(UnsupportedAPI, ctx, __FUNCTION__);
//#endif
//}
//
///* ------------------------------------------------------------------------ */
////## @Native @Unsafe Boolean System.unlink(String path);
//
//static METHOD System_unlink(Ctx *ctx, knh_sfp_t *sfp, long rix)
//{
//	KNH_SECURE(ctx, sfp);
//	RETURNb_(knh_unlink(ctx, S_tobytes(sfp[1].s), knh_Context_isStrict(ctx)));
//}
//
///* ------------------------------------------------------------------------ */
////## @Native @Unsafe Boolean System.rename(String path, String newpath);
//
//static METHOD System_rename(Ctx *ctx, knh_sfp_t *sfp, long rix)
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
//knh_io_t knh_iodrv_open__PIPE(Ctx *ctx, knh_bytes_t file, char *mode, int isThrowable)
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
//void knh_iodrv_init__NOP(Ctx *ctx, Object *stream, char *mode)
//{
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//knh_intptr_t knh_iodrv_read__PIPE(Ctx *ctx, knh_io_t fd, char *buf, size_t bufsiz)
//{
//	FILE *fp = (FILE*)fd;
//	size_t ssize = fread(buf, 1, bufsiz, fp);
//	return ssize;
//}
//
///* ------------------------------------------------------------------------ */
//
//static
//knh_intptr_t knh_iodrv_write__PIPE(Ctx *ctx, knh_io_t fd, char *buf, size_t bufsiz)
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
//void knh_iodrv_close__PIPE(Ctx *ctx, knh_io_t fd)
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
//
///* ======================================================================== */
//
//KNHAPI(int) init(Ctx *ctx)
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
//
///* ------------------------------------------------------------------------ */
//
//#ifdef __cplusplus
//}
//#endif

