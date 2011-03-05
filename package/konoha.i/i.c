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

/* inlinelibs */
#define USE_B
#define USE_STEXT
#define USE_bytes_strcmp
#define USE_cwb_tobytes
#define USE_cwb_size

#include <konoha.h>

#define RL_NO_COMPAT
#include<readline/readline.h>
#include<readline/history.h>
#ifdef RL_VERSION_MAJOR  /* 5, or later */
	char **completion_matches(char *, rl_compentry_func_t *);
#endif

#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* shell spi */

static void* shell_init(Ctx *ctx, char *msg, char *optstr)
{
	fputs(msg, stdout);
	return NULL; // nostatus
}

static knh_bool_t shell_readstmt(Ctx *ctx, void *status, knh_cwb_t *cwb, const knh_ShellAPI_t *api)
{
	int line = 1;
	while(1) {
		char *ln = readline(line == 1 ? ">>> " : "... ");
		int check;
		if(ln == NULL) {
			knh_cwb_clear(cwb, 0); return 0;
		}
		if(line > 1) knh_putc(ctx, cwb->ba, '\n');
		knh_write(ctx, cwb->ba, ln, strlen(ln));
		free(ln);
		if((check = api->checkstmt(knh_cwb_tobytes(cwb))) == 0) break;
		if(check < 0) {
			fputs("(Cancelled)...\n", stdout);
			knh_cwb_clear(cwb, 0); line = 1;
		}
		else {
			line++;
		}
	}
	if(knh_cwb_size(cwb) > 0) {
		const char *p = knh_cwb_tochar(ctx, cwb);
		add_history(p);
	}
	return api->command(ctx, cwb);
}

static void shell_display(Ctx *ctx, void *status, char *msg, const knh_ShellAPI_t *api)
{
	fputs(msg, stdout);
}

static void shell_cleanup(Ctx *ctx, void *status)
{
	knh_Context_setInteractive(ctx, 0);
}

static const knh_ShellSPI_t ReadlineShell = {
	"readline",
	shell_init, shell_readstmt,
	shell_display, shell_cleanup,
};

KNHAPI(int) kcheck(void) { return K_BUILDID; }

KNHAPI(void) init(Ctx *ctx, knh_PackageLoaderAPI_t *kapi, char *dname, int isOVERRIDE)
{
	if(knh_isSelectedDSPI(dname, "shell")) {
		kapi->setShellSPI(ctx, &ReadlineShell, isOVERRIDE);
	}
}

#ifdef __cplusplus
}
#endif

