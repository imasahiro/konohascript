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

/* ======================================================================== */
// [private functions]

static knh_IntData_t SignalConstInt[] = {
	{"SIGHUP"   , SIGHUP   },
	{"SIGINT"   , SIGINT   },
	{"SIGQUIT"  , SIGQUIT  },
	{"SIGILL"   , SIGILL   },
	{"SIGTRAP"  , SIGTRAP  },
	{"SIGABRT"  , SIGABRT  },
#ifdef  SIGEMT
	{"SIGEMT"   , SIGEMT   },
#endif
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
#ifdef  SIGTSOP
	{"SIGTSOP"  , SIGTSOP  },
#endif
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
#ifdef  SIGINFO
	{"SIGINFO"  , SIGINFO  },
#endif
	{"SIGUSR1"  , SIGUSR1  },
	{"SIGUSR2"  , SIGUSR2  },
	{NULL, 0}, //necessary for checking rnd of definition
};

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
	int signum = Int_to(int, sfp[1]);
	if(ctx->sighandlers == NULL) {
		WCTX(ctx)->sighandlers = KNH_MALLOC(ctx, sizeof(knh_Func_t*) * K_SIGNAL_MAX);
		knh_bzero(ctx->sighandlers, sizeof(knh_Func_t*) * K_SIGNAL_MAX);
	}
	THROW_OutOfRange(ctx, sfp, signum, K_SIGNAL_MAX);
	if(IS_NULL(sfp[2].fo)) {
		if(ctx->sighandlers[signum] != NULL) {
			KNH_FINALv(ctx, ctx->sighandlers[signum]);
		}
	}
	else {
		struct sigaction sa;
		sa.sa_handler = signal_handler;
		sa.sa_flags = SA_RESTART;
		if (sigaction(signum, &sa, NULL) < 0) {
			LOGDATA = {iDATA("signum", signum)};
			LIB_Failed("signal", "System!!");
		}
		if(ctx->sighandlers[signum] != NULL) {
			KNH_SETv(ctx, ctx->sighandlers[signum], sfp[2].fo);
		}
		else {
			KNH_INITv(ctx->sighandlers[signum], sfp[2].fo);
		}
	}
}

//## @Native boolean Signal.kill(int pid, int signal);
KMETHOD Signal_kill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int tf = 1;
	KNH_RESET_ERRNO();
	if(kill(Int_to(int, sfp[1]), Int_to(int, sfp[2])) == -1) {
		LOGDATA = {iDATA("pid", Int_to(int, sfp[1])), iDATA("signal", Int_to(int, sfp[2])), __ERRNO__};
		NOTE_Failed("kill");
		tf = 0;
	}
	RETURNb_(tf);
}

//## @Native boolean Signal.raise(int signal);
KMETHOD Signal_raise(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int tf = 1;
	KNH_RESET_ERRNO();
	if(raise(Int_to(int, sfp[1])) == -1) {
		LOGDATA = {iDATA("signal", Int_to(int, sfp[1])), __ERRNO__};
		NOTE_Failed("raise");
		tf = 0;
	}
	RETURNb_(tf);
}

//## @Native int Signal.alarm(int seconds);
KMETHOD Signal_alarm(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(alarm(Int_to(unsigned int, sfp[1])));
}

/* ======================================================================== */
// [DEFAPI]


DEFAPI(void) defSignal(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Signal";
}

DEFAPI(void) constSignal(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, SignalConstInt);
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.signal");
}

#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
