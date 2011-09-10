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
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
// [private functions]

/* ------------------------------------------------------------------------ */
// [struct]

typedef struct {
	knh_hObject_t h;
	knh_io_t in;
	knh_io_t out;
	knh_io_t err;
	knh_intptr_t pid;
} knh_Proc_t;

static void Proc_init(CTX ctx, knh_RawPtr_t *po)
{
	knh_Proc_t *sp = (knh_Proc_t *)po;
	sp->in = IO_NULL;
	sp->out = IO_NULL;
	sp->err = IO_NULL;
	sp->pid = 0;
}

static void Proc_free(CTX ctx, knh_RawPtr_t *po)
{
	knh_Proc_t *sp = (knh_Proc_t *)po;
	if (sp->in != IO_NULL) {
		if (close(sp->in)) {
			DBG_P("in close failed");
		}
		sp->in = IO_NULL;
	}
	if (sp->out != IO_NULL) {
		if (close(sp->out)) {
			DBG_P("out close failed");
		}
		sp->out = IO_NULL;
	}
	if (sp->err != IO_NULL) {
		if (close(sp->err)) {
			DBG_P("err close failed");
		}
		sp->err = IO_NULL;
	}
}

/* ------------------------------------------------------------------------ */
// [StreamDPI]

static knh_bool_t PROC_exists(CTX ctx, knh_Path_t *path)
{
	return 0;
}

static knh_io_t PROC_open(CTX ctx, knh_Path_t *path, const char *mode, knh_DictMap_t *conf)
{
	return IO_NULL;
}

static knh_intptr_t PROC_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return read(fd, buf, bufsiz);
}

static knh_intptr_t PROC_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	return write(fd, buf, bufsiz);
}

static void PROC_close(CTX ctx, knh_io_t fd)
{
	errno = 0;
	if (fd != IO_NULL && close(fd)) {
		DBG_P("PROC_close failed");
	}
}

static knh_bool_t PROC_info(CTX ctx, knh_io_t fd, knh_Object_t *o)
{
	return 0;
}

static int PROC_getc(Ctx *ctx, knh_io_t fd)
{
	KNH_TODO("PROC_getc");
	return -1;
}

static knh_bool_t PROC_readline(Ctx *ctx, knh_io_t fd, knh_Bytes_t *ba)
{
	KNH_TODO("PROC_readline");
	return 0;
}

static int PROC_feof(Ctx *ctx, knh_io_t fd)
{
	KNH_TODO("PROC_feof");
	return 1;
}

static void PROC_flush(Ctx *ctx, knh_io_t fd)
{
}

static const knh_StreamDPI_t STREAM_PROC = {
	K_STREAM_FD,     // type
	"proc",          // name
	K_OUTBUF_MAXSIZ, // wbufsiz
	PROC_exists,     // existsSPI
	NULL,            // ospath
	PROC_open,       // fopenSPI
	PROC_open,       // wopenSPI
	PROC_read,       // freadSPI
	PROC_write,      // fwriteSPI
	PROC_close,      // fcloseSPI
	PROC_info,       // info
	PROC_getc,       // fgetcSPI
	PROC_readline,   // fgetlineSPI
	PROC_feof,       // feofSPI
	PROC_flush       // fflushSPI
};

static inline CWB_t *CWB_open(CTX ctx, CWB_t *cwb)
{
	cwb->ba = ctx->bufa;
	cwb->w  = ctx->bufw;
	cwb->pos = BA_size(cwb->ba);
	return cwb;
}

static inline void CWB_write(CTX ctx, CWB_t *cwb, knh_bytes_t t)
{
	knh_Bytes_write(ctx, (cwb->ba), t);
}

static inline void CWB_putc(CTX ctx, CWB_t *cwb, int ch)
{
	knh_Bytes_putc(ctx, (cwb->ba), ch);
}

static inline size_t CWB_size(CWB_t *cwb)
{
	return (cwb->ba)->bu.len - cwb->pos;
}

static inline void CWB_close(CWB_t *cwb)
{
	knh_Bytes_clear(cwb->ba, cwb->pos);
}

/* ------------------------------------------------------------------------ */
// [process]

static void child(CTX ctx, knh_sfp_t *sfp, knh_Array_t *args, knh_DictMap_t *env)
{
	size_t i, asize = knh_Array_size(args), msize = env->spi->size(ctx, env->mapptr);
	char *p, *s, *cargs[asize + 1], *cenv[msize + 1];
	for (i = 0; i < asize; i++) {
		cargs[i] = (char *)S_totext((knh_String_t *)knh_Array_n(args, i));
		DBG_P("args[%lu]=%s", i, cargs[i]);
	}
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	s = (char *)CWB_totext(ctx, cwb);
	p = s;
	for (i = 0; i < msize; i++) {
		knh_String_t *key = (knh_String_t *)knh_DictMap_keyAt(env, i);
		knh_String_t *val = (knh_String_t *)knh_DictMap_valueAt(env, i);
		CWB_write(ctx, cwb, S_tobytes(key));
		CWB_putc(ctx, cwb, '=');
		CWB_write(ctx, cwb, S_tobytes(val));
		CWB_putc(ctx, cwb, '\0');
		cenv[i] = p;
		p = s + CWB_size(cwb);
		//fprintf(stderr, "env[%lu]=%s\n", i, cenv[i]);
	}
	cargs[asize] = NULL;
	cenv[msize] = NULL;
	errno = 0;
	if (execve(cargs[0], cargs, cenv) == -1) {
		// [TODO] export log in detail
		LOGDATA = {sDATA("file", cargs[0])};
		LIB_Failed("child", "IO!!");
		_Exit(EXIT_FAILURE);
	}
	CWB_close(cwb);
}

/* ======================================================================== */
// [KMETHODS]

//## @Native Proc Proc.new(String[] args, Map<String,String> env);
KMETHOD Proc_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	knh_Array_t *args = sfp[1].a;
	knh_DictMap_t *env = (knh_DictMap_t *)sfp[2].o;
	int pipes1[2] = {0}; // for write
	int pipes2[2] = {0}; // for read stdout
	int pipes3[2] = {0}; // for read stderr
	int pid = 0;

	// pipe
	errno = 0;
	if (pipe(pipes1)) {
		LOGDATA = {iDATA("pipefd[0]", pipes1[0]), iDATA("pipefd[1]", pipes1[1])};
		LIB_Failed("Proc.new", "System!!");
	}
	if (pipe(pipes2)) {
		LOGDATA = {iDATA("pipefd[0]", pipes2[0]), iDATA("pipefd[1]", pipes2[1])};
		LIB_Failed("Proc.new", "System!!");
	}
	if (pipe(pipes3)) {
		LOGDATA = {iDATA("pipefd[0]", pipes3[0]), iDATA("pipefd[1]", pipes3[1])};
		LIB_Failed("Proc.new", "System!!");
	}

	// fork
	pid = fork();
	errno = 0;
	if (pid == -1) {
		LOGDATA = {iDATA("errno", errno)};
		LIB_Failed("Proc.new", "System!!");
		knh_Object_toNULL(ctx, sp);
		RETURN_(sp);
	}

	if (pid == 0) { // child
		// [NOTE] please implement error handling if needed
		close(0);
		close(1);
		close(2);
		dup(pipes1[0]);
		dup(pipes2[1]);
		dup(pipes3[1]);
		close(pipes1[0]);
		close(pipes1[1]);
		close(pipes2[0]);
		close(pipes2[1]);
		close(pipes3[0]);
		close(pipes3[1]);
		child(ctx, sfp, args, env);
	} else { // parent
		close(pipes1[0]);
		close(pipes2[1]);
		close(pipes3[1]);
		sp->in = pipes2[0];
		DBG_P("in=%lu", sp->in);
		sp->out = pipes1[1];
		DBG_P("out=%lu", sp->out);
		sp->err = pipes3[0];
		DBG_P("err=%lu", sp->err);
		sp->pid = pid;
	}
	RETURN_(sp);
}

//## @Native InputStream Proc.getInputStream();
KMETHOD Proc_getInputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	RETURN_(new_InputStreamDPI(ctx, sp->in, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native OutputStream Proc.getOutputStream();
KMETHOD Proc_getOutputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	RETURN_(new_OutputStreamDPI(ctx, sp->out, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native InputStream Proc.getErrorInputStream();
KMETHOD Proc_getErrorInputStream(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	RETURN_(new_InputStreamDPI(ctx, sp->err, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native void Proc.terminate();
KMETHOD Proc_terminate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	// [TODO] FIXME
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_NOCLDWAIT;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		// [TODO]
		KNH_TODO("Proc_terminate");
	}
	kill(sp->pid, SIGTERM);
	raise(SIGCHLD);
}

//## @Native int Proc.wait();
KMETHOD Proc_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	int status = 0;
	pid_t ret = 0;
	errno = 0;
	ret = waitpid(sp->pid, &status, 0);
	if (ret == -1) {
		LOGDATA = {iDATA("errno", errno)};
		LIB_Failed("Proc.wait", "System!!");
	} else {
		DBG_P("ret=%d", ret);
		DBG_P("WIFEXITED=%s", WIFEXITED(status) ? "true" : "false");
		DBG_P("WEXITSTATUS=%d", WEXITSTATUS(status));
		DBG_P("WIFSIGNALED=%s", WIFSIGNALED(status) ? "true" : "false");
		DBG_P("WTERMSIG=%d", WIFSIGNALED(status) ? WTERMSIG(status) : -1);
		DBG_P("WCOREDUMP=%s", WIFSIGNALED(status) ? (WCOREDUMP(status) ? "true" : "false") : "none");
		DBG_P("WIFSTOPPED=%s", WIFSTOPPED(status) ? "true" : "false");
		DBG_P("WSTOPSIG=%d", WIFSTOPPED(status) ? WSTOPSIG(status) : -1);
	}
	RETURNi_(WEXITSTATUS(status));
}

//## @Native boolean Proc.isAlive();
KMETHOD Proc_isAlive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	int status = 0;
	pid_t ret = 0;
	errno = 0;
	ret = waitpid(sp->pid, &status, WNOHANG);
	if (ret == -1) {
		LOGDATA = {iDATA("errno", errno)};
		LIB_Failed("Proc.isAlive", "System!!");
	} else {
		if (ret != 0) {
			// process died close fds
			DBG_P("process already died, close fds");
			PROC_close(ctx, sp->out);
			sp->out = IO_NULL;
		}
		DBG_P("ret=%d", ret);
		DBG_P("WIFEXITED=%s", WIFEXITED(status) ? "true" : "false");
		DBG_P("WEXITSTATUS=%d", WEXITSTATUS(status));
		DBG_P("WIFSIGNALED=%s", WIFSIGNALED(status) ? "true" : "false");
		DBG_P("WTERMSIG=%d", WIFSIGNALED(status) ? WTERMSIG(status) : -1);
		DBG_P("WCOREDUMP=%s", WIFSIGNALED(status) ? (WCOREDUMP(status) ? "true" : "false") : "none");
		DBG_P("WIFSTOPPED=%s", WIFSTOPPED(status) ? "true" : "false");
		DBG_P("WSTOPSIG=%d", WIFSTOPPED(status) ? WSTOPSIG(status) : -1);
	}
	RETURNb_((ret == 0) ? 1 : 0);
}

/* ======================================================================== */
// [DEFAPI]


DEFAPI(void) defProc(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Proc";
	cdef->init = Proc_init;
	cdef->free = Proc_free;
}

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.proc");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
