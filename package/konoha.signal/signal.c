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
#include <signal.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

// _POSIX_SIGQUEUE_MAX == 32
#define SIGNAL_MAX _POSIX_SIGQUEUE_MAX

/* ======================================================================== */
// [private functions]

//static knh_FuncData_t SignalConstFunc[] = {
//	{"SIG_DFL", SIG_DFL},
//	{"SIG_IGN", SIG_IGN},
//}

static knh_IntData_t SignalConstInt[] = {
	{"SIGHUP"   , SIGHUP   },
	{"SIGINT"   , SIGINT   },
	{"SIGQUIT"  , SIGQUIT  },
	{"SIGILL"   , SIGILL   },
	{"SIGTRAP"  , SIGTRAP  },
	{"SIGABRT"  , SIGABRT  },
	//{"SIGEMT"   , SIGEMT   },
	{"SIGFPE"   , SIGFPE   },
	{"SIGKILL"  , SIGKILL  },
	{"SIGBUS"   , SIGBUS   },
	{"SIGSYS"   , SIGSYS   },
	{"SIGSEGV"  , SIGSEGV  },
	{"SIGPIPE"  , SIGPIPE  },
	{"SIGALRM"  , SIGALRM  },
	{"SIGTERM"  , SIGTERM  },
	{"SIGURG"   , SIGURG   },
	{"SIGSTOP"  , SIGSTOP  },
	//{"SIGTSOP"  , SIGTSOP  },
	{"SIGCONT"  , SIGCONT  },
	{"SIGCHLD"  , SIGCHLD  },
	{"SIGTTIN"  , SIGTTIN  },
	{"SIGTTOU"  , SIGTTOU  },
	{"SIGIO"    , SIGIO    },
	{"SIGXCPU"  , SIGXCPU  },
	{"SIGXFSZ"  , SIGXFSZ  },
	{"SIGVTALRM", SIGVTALRM},
	{"SIGPROF"  , SIGPROF  },
	{"SIGWINCH" , SIGWINCH },
	//{"SIGINFO"  , SIGINFO  },
	{"SIGUSR1"  , SIGUSR1  },
	{"SIGUSR2"  , SIGUSR2  },
};

//typedef struct {
//	knh_hObject_t h;
//	Ctx *lctx;
//	knh_Array_t *func_array;
//	void *dummy1;
//	void *dummy2;
//} knh_Signal_t;

static void Signal_init(CTX ctx)
{
	if (ctx->sighandlers == NULL) {
		KNH_INITv(WCTX(ctx)->sighandlers, new_Array(ctx, CLASS_Func, SIGNAL_MAX));
		knh_Array_grow(ctx, ctx->sighandlers, SIGNAL_MAX, SIGNAL_MAX);
		knh_Array_size(ctx->sighandlers) = SIGNAL_MAX;
	}
}

//static void Signal_free(CTX ctx, knh_RawPtr_t *po)
//{
//	knh_Signal_t *s = (knh_Signal_t *)po;
//	size_t i;
//	for (i = 0; i < knh_Array_size(s->func_array); i++) {
//		KNH_FINALv(ctx, knh_Array_n(s->func_array), i);
//	}
//	KNH_FINALv(ctx, s->func_array);
//}

static void Signal_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (ctx->sighandlers != NULL) {
#ifdef K_USING_FASTREFS_
		KNH_SETREF(ctx, ctx->sighandlers->list, SIGNAL_MAX);
#else
		size_t i;
		for (i = 0; i < knh_Array_size(ctx->sighandlers); i++) {
			if (a->list[i] != NULL)
				KNH_ADDREF(ctx, a->list[i]);
		}
		KNH_SIZEREF(ctx);
#endif
	}
}

void signal_handler(int signum)
{
	CTX lctx = knh_getCurrentContext();
	WCTX(lctx)->signal = signum;
	SAFEPOINT_SETSIGNAL(lctx);
}

/* ======================================================================== */
// [KMETHODS]

//## @Native void Signal.signal(int signum, Func<int> sighandler);
KMETHOD Signal_signal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	int signum = Int_to(int, sfp[1]);
	if (knh_Array_n(ctx->sighandlers, signum) == NULL)
		KNH_INITv(knh_Array_n(ctx->sighandlers, signum), KNH_NULL);
	KNH_SETv(ctx, knh_Array_n(ctx->sighandlers, signum), sfp[2].fo);
	if (sigaction(signum, &sa, NULL) < 0) {
		LOGDATA = {iDATA("signum", signum)};
		LIB_Failed("Signal.signal", "System!!");
	}
}

//## @Native int Signal.alarm(int seconds);
KMETHOD Signal_alarm(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(alarm(Int_to(unsigned int, sfp[1])));
}

/* ======================================================================== */
// [DEFAPI]

#ifdef _SETUP

DEFAPI(void) defSignal(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Signal";
	cdef->reftrace = Signal_reftrace;
}

DEFAPI(void) constSignal(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, SignalConstInt);
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	Signal_init(ctx);
	RETURN_PKGINFO("konoha.signal");
}

#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
