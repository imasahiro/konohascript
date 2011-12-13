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
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
// **************************************************************************

#define USE_STRUCT_InputStream
#define USE_STRUCT_OutputStream

#include <konoha1.h>
#include <konoha1/inlinelibs.h>
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


static knh_IntData_t ProcConstInt[] = {
	{"PIPE", 1},
	{NULL, 0}
};

DEFAPI(void) constProc(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, ProcConstInt);
}

typedef struct {
	kObjectHeader h;
	int out; // used as stdin for child
	int in; // used as stdout for child
	int err; // used as stderr for child
	kintptr_t pid;
} knh_Proc_t;

static void Proc_init(CTX ctx, kRawPtr *po)
{
	knh_Proc_t *sp = (knh_Proc_t *)po;
	sp->out = IO_NULL;
	sp->in = IO_NULL;
	sp->err = IO_NULL;
	sp->pid = 0;
}

static void Proc_free(CTX ctx, kRawPtr *po)
{
	knh_Proc_t *sp = (knh_Proc_t *)po;
	if (sp->out != IO_NULL) {
		if (close(sp->out)) {
			DBG_P("out close failed");
		}
		sp->out = IO_NULL;
	}
	if (sp->in != IO_NULL) {
		if (close(sp->in)) {
			DBG_P("in close failed");
		}
		sp->in = IO_NULL;
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

static kbool_t PROC_exists(CTX ctx, kPath *path)
{
	return 0;
}

//static int PROC_open(CTX ctx, kPath *path, const char *mode, kDictMap *conf)
//{
//	return IO_NULL;
//}


static const knh_PathDPI_t STREAM_PROC = {
	K_STREAM_FD,     // type
	"proc",          // name
	K_OUTBUF_MAXSIZ, // wbufsiz
	PROC_exists,     // existsSPI
	NULL,            // ospath
};

/* ------------------------------------------------------------------------ */
// [process]

static void child(CTX ctx, ksfp_t *sfp, kArray *args, kDictMap *env)
{
	size_t i, asize = knh_Array_size(args), msize = env->spi->size(ctx, env->mapptr);
	char *p, *s, *cargs[asize + 1], *cenv[msize + 1];
	for (i = 0; i < asize; i++) {
		cargs[i] = (char *)S_totext((kString *)knh_Array_n(args, i));
		DBG_P("args[%lu]=%s", i, cargs[i]);
	}
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	s = (char *)CWB_totext(ctx, cwb);
	p = s;
	for (i = 0; i < msize; i++) {
		kString *key = (kString *)knh_DictMap_keyAt(env, i);
		kString *val = (kString *)knh_DictMap_valueAt(env, i);
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
		KNH_NTRACE2(ctx, "execvc", K_PERROR, KNH_LDATA(LOG_s("file", cargs[0])));
		_Exit(EXIT_FAILURE);
	}
	CWB_close(ctx, cwb);
}

/* ======================================================================== */
// [KMETHODS, Proc]

static void trapPIPE (int sig, siginfo_t *si, void *ptr)
{
	CTX ctx = knh_getCurrentContext();
	if (ctx != NULL) {
		KNH_NTRACE2(ctx, "tarpChild", K_NOTICE, KNH_LDATA0);
	}
	printf("SIGPIPE caught\n");
	_Exit(EXIT_FAILURE);
	//	childFlag = 1; // ON
}


#define R 0
#define W 1
#include <fcntl.h>
#include <signal.h>
//## @Native Proc Proc.new(String[] args, Map<String, String> env);

KMETHOD Proc_new(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	kArray *args = sfp[1].a;
	kDictMap *env = (kDictMap *)sfp[2].o;
	int isBackground = Int_to(int, sfp[3]);
	int pid = 0;
	int fd1[2] = {0};
	int fd2[2] = {0};
	int fd3[2] = {0};

	// trap SIGPIPE
	struct sigaction sa = {};
	struct sigaction sa_old = {};
	sa.sa_sigaction = trapPIPE;
	sa.sa_flags = SA_SIGINFO;

	//TODO: also, trap SIGCHLD

	if (sigaction(SIGPIPE, &sa, &sa_old) < 0) {
		//set trapPIPE
		KNH_NTHROW2(ctx, sfp, "Proc!!", "sigaction", K_PERROR, KNH_LDATA(LOG_i("signal", SIGPIPE)));
		kObjectoNULL(ctx, sp);
		RETURN_(sp);
	}
	if (pipe(fd1) < 0 || pipe(fd2) < 0 || pipe(fd3)) {
		//error
		KNH_NTHROW2(ctx, sfp, "Proc!!", "pipe", K_PERROR, KNH_LDATA(
					LOG_i("fd1[0]", fd1[R]), LOG_i("fd1[1]", fd1[W]),
					LOG_i("fd2[0]", fd2[R]), LOG_i("fd2[1]", fd2[W]),
					LOG_i("fd3[0]", fd3[R]), LOG_i("fd3[1]", fd3[W])
					));
		kObjectoNULL(ctx, sp);
		RETURN_(sp);
	}
	errno = 0; // to detect fork error, reset errno
	if ((pid = fork()) < 0) {
		KNH_NTHROW2(ctx, sfp, "Proc!!", "fork", K_PERROR, KNH_LDATA0);
		kObjectoNULL(ctx, sp);
		RETURN_(sp);
	} else if (pid > 0) {
		// parent
		close(fd1[R]); // used as stdin for child
		close(fd2[W]); // used as stdout for child
		close(fd3[W]); // used as stderr for child
		sp->out = fd1[W]; // stdin for child
		sp->in = fd2[R]; // stdout for child
		sp->err = fd3[R]; // stderr for child
		sp->pid = pid;
	} else {
		// child
		close(fd1[W]);
		close(fd2[R]);
		close(fd3[R]);
		if (isBackground == 0) {
			close(0);
			close(1);
			close(2);
			if (dup2(fd1[R], 0) != 0) {
				close(fd1[R]);
			}
			if (dup2(fd2[W], 1) != 1) {
				close(fd2[W]);
			}
			if (dup2(fd3[W], 2) != 2) {
				close(fd3[W]);
			}
			child(ctx, sfp, args, env);
		} else { /* isBackground = false */
			// pipe to devnull
			int dn;
			if ((dn = open("/dev/null", O_RDWR)) < 0) {
				//error;
			}
			if (dup2(fd1[R], dn) != dn) {
				close(fd1[R]);
			}
			if (dup2(fd2[W], dn) != dn) {
				close(fd2[W]);
			}
			if (dup2(fd3[W], dn) != dn) {
				close(fd3[W]);
			}
			child(ctx, sfp, args, env);
		}
	}
	RETURN_(sp);
}

//## @Native InputStream Proc.getInputStream();
KMETHOD Proc_getInputStream(CTX ctx, ksfp_t *sfp _RIX)
{
	KNH_TODO(__FUNCTION__);
	//knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	//RETURN_(new_InputStream(ctx, sp->in, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native OutputStream Proc.getOutputStream();
KMETHOD Proc_getOutputStream(CTX ctx, ksfp_t *sfp _RIX)
{
	KNH_TODO(__FUNCTION__);
	//knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	//RETURN_(new_OutputStream(ctx, sp->out, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native InputStream Proc.getErrorInputStream();
KMETHOD Proc_getErrorInputStream(CTX ctx, ksfp_t *sfp _RIX)
{
	KNH_TODO(__FUNCTION__);
	//knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	//RETURN_(new_InputStream(ctx, sp->err, &STREAM_PROC, KNH_TNULL(Path)));
}

//## @Native void Proc.terminate();
KMETHOD Proc_terminate(CTX ctx, ksfp_t *sfp _RIX)
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
	Proc_free(ctx, (kRawPtr *)sp);
}

//## @Native int Proc.wait();
KMETHOD Proc_wait(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	int status = 0;
	pid_t ret = 0;
	errno = 0;
	ret = waitpid(sp->pid, &status, 0);
	Proc_free(ctx, (kRawPtr *)sp);
	if (ret == -1) {
		KNH_NTHROW2(ctx, sfp, "System!!", "waitpid", K_PERROR, KNH_LDATA0);
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
KMETHOD Proc_isAlive(CTX ctx, ksfp_t *sfp _RIX)
{
	knh_Proc_t *sp = (knh_Proc_t *)sfp[0].o;
	int status = 0;
	pid_t ret = 0;
	errno = 0;
	ret = waitpid(sp->pid, &status, WNOHANG);
	if (ret == -1) {
		KNH_NTHROW2(ctx, sfp, "System!!", "waitpid", K_PERROR, KNH_LDATA0);
	} else {
		if (ret != 0) {
			// process died close fds
			DBG_P("process already died, close fds");
			Proc_free(ctx, (kRawPtr *)sp);
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

DEFAPI(void) defProc(CTX ctx, kclass_t cid, kclassdef_t *cdef)
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
