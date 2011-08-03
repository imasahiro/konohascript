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

#define USE_STRUCT_Path
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
KMETHOD System_getHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *s = NULL;
	char buf[256];
	KNH_RESET_ERRNO();
	if(gethostname(buf, sizeof(buf)) == -1) {
		LOGDATA = {__ERRNO__};
		NOTE_Failed("gethostname");
	}
	else {
		s = (const char*)buf;
	}
	RETURN_(new_String(ctx, s));
}

//## @Native String System.getLogin();
KMETHOD System_getLogin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_String(ctx, getlogin()));
}

//## @Native int System.getUid();
KMETHOD System_getUid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getuid());
}

//## @Native int System.getEuid();
KMETHOD System_getEuid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(geteuid());
}

//## @Native int System.getGid();
KMETHOD System_getGid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getgid());
}

//## @Native int System.getEgid();
KMETHOD System_getEgid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getegid());
}

//## @Native int System.getPid();
KMETHOD System_getPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getpid());
}

//## @Native int System.getPPid();
KMETHOD System_getPPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getppid());
}

/* ------------------------------------------------------------------------ */
/* [signal] */

//## @Native boolean System.kill(int pid, int signal);
KMETHOD System_kill(CTX ctx, knh_sfp_t *sfp _RIX)
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

//## @Native int System.sleep(int sec);
KMETHOD System_sleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sleep(Int_to(int, sfp[1])));
}

//## @Native boolean System.usleep(int usec);
KMETHOD System_usleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int tf = (usleep(Int_to(useconds_t, sfp[1])) != -1);
	if(!tf) {
		LOGDATA = {iDATA("usec", sfp[1].ivalue), __ERRNO__};
		NOTE_Failed("usleep");
	}
	RETURNb_(tf);
}

//## @Native boolean System.raise(int signal);
KMETHOD System_raise(CTX ctx, knh_sfp_t *sfp _RIX)
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

/* ------------------------------------------------------------------------ */

//## @Native String System.getCwd();

KMETHOD System_getCwd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char tmpbuf[K_PATHMAX];
	getcwd(tmpbuf, sizeof(tmpbuf));
	RETURN_(new_String(ctx, (const char*)tmpbuf));
}

static int fileop(CTX ctx, knh_sfp_t *sfp, const char *name, int (*func)(const char*), knh_Path_t *pth)
{
	if(func(pth->ospath) == -1) {
		LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath), __ERRNO__};
		NOTE_Failed(name);
		return 0;
	}
	return 1;
}

static int fileop2(CTX ctx, knh_sfp_t *sfp, const char *name, int (*func)(const char*, const char*), knh_Path_t *pth, knh_Path_t *pth2)
{
	if(func(pth->ospath, pth2->ospath) == -1) {
		LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath),
				sDATA("path2", S_tochar(pth2->urn)), sDATA("ospath2", pth2->ospath), __ERRNO__};
		NOTE_Failed(name);
		return 0;
	}
	return 1;
}

//## @Native @Restricted boolean System.link(Path path, Path path2);
KMETHOD System_link(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "link", link, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.symlink(Path path, Path path2);
KMETHOD System_symlink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "symlink", symlink, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.rename(Path path, Path path2);
KMETHOD System_rename(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "rename", rename, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.unlink(Path path);
KMETHOD System_unlink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "unlink", unlink, sfp[1].pth));
}

//## @Native boolean System.chdir(Path path);
KMETHOD System_chdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "chdir", chdir, sfp[1].pth));
}

//## @Native boolean System.chroot(Path path);
KMETHOD System_chroot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "chroot", chroot, sfp[1].pth));
}

//## @Native @Restricted boolean System.mkdir(Path path, int mode);
KMETHOD System_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	mode_t mode =  (mode_t)sfp[2].ivalue;
	if(mkdir(pth->ospath, mode) == -1) {
		LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath), iDATA("mode", mode), __ERRNO__};
		NOTE_Failed("mkdir");
		RETURNb_(0);
	}
	else {
		LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath), iDATA("mode", mode)};
		NOTE_OK("mkdir");
		RETURNb_(1);
	}
}

//## @Native @Restricted boolean System.rmdir(Path path);
KMETHOD System_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "rmdir", rmdir, sfp[1].pth));
}

/* ------------------------------------------------------------------------ */
/* [DIR] */

static void Dir_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void Dir_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		closedir((DIR*)po->rawptr);
		po->rawptr = NULL;
	}
}

static void Dir_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
{
	if (po->rawptr != NULL) {
		closedir((DIR*)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defDir(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Dir";
	cdef->init = Dir_init;
	cdef->free = Dir_free;
	cdef->checkout = Dir_checkout;
}

static knh_IntData_t DirConstInt[] = {
	{"DT_UNKNOWN", DT_UNKNOWN},
	{"DT_FIFO",    DT_FIFO},
	{"DT_CHR",     DT_CHR},
	{"DT_DIR",     DT_DIR},
	{"DT_BLK",     DT_BLK},
	{"DT_REG",     DT_REG},
	{"DT_LNK",     DT_LNK},
	{"DT_SOCK",    DT_SOCK},
	{"DT_WHT",     DT_WHT},
	{NULL}
};

DEFAPI(void) constDir(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadIntClassConst(ctx, cid, DirConstInt);
}

/* ------------------------------------------------------------------------ */

//## @Native @Throwable Dir System.openDir(Path path);
KMETHOD System_openDir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	DIR *dirptr = opendir(pth->ospath);
	knh_RawPtr_t *po = 	new_ReturnRawPtr(ctx, sfp, dirptr, NULL/*ignored*/);
	LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath), __ERRNO__};
	LIB_log("opendir", (dirptr != NULL), "IO!!");
	RETURN_(po);
}

//## @Native void Dir.close();
KMETHOD Dir_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DIR *dirptr = (DIR*)sfp[0].p->rawptr;
	if(dirptr != NULL) {
		sfp[0].p->rawptr = NULL;
		closedir(dirptr);
	}
	RETURNvoid_();
}

//## @Const @Static @Hidden Dir Dir.opLink(String urn, NameSpace _);
KMETHOD Dir_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KNH_SETv(ctx, sfp[1].o, new_Path(ctx, sfp[1].s));
	System_openDir(ctx, sfp, K_RIX);
}

//## @Native @Iterative Map Dir.read();
KMETHOD Dir_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	DIR *dirptr = (DIR*)sfp[0].p->rawptr;
	if(dirptr != NULL) {
		struct dirent *dp = readdir(dirptr);
		if(dp != NULL) {
			mdata = new_Map(ctx);
			knh_Map_setString(ctx, mdata, "d_name", dp->d_name);
			knh_Map_setInt(ctx, mdata, "d_type", dp->d_type);
		}
	}
	RETURN_(mdata);
}

//## @Native @Iterative String Dir.readName();
KMETHOD Dir_readName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *dname = NULL;
	DIR *dirptr = (DIR*) sfp[0].p->rawptr;
	if(dirptr != NULL) {
		struct dirent *dp = readdir(dirptr);
		if(dp != NULL) {
			dname = dp->d_name;
		}
	}
	RETURN_(new_String(ctx, dname));
}

/* ======================================================================== */
/* FILE */

static void File_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void File_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		fclose((FILE*)po->rawptr);
		po->rawptr = NULL;
	}
}

static void File_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
{
	if (po->rawptr != NULL) {
		fclose((FILE*)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defFile(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "File";
	cdef->init = File_init;
	cdef->free = File_free;
	cdef->checkout = File_checkout;
}

//## @Native @Throwable File System.fopen(Path path, String mode);
KMETHOD System_fopen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	const char *mode = IS_NULL(sfp[2].s) ? "r" : S_tochar(sfp[2].s);
	FILE *fp = fopen(pth->ospath, mode);
	knh_RawPtr_t *po = 	new_ReturnRawPtr(ctx, sfp, fp, NULL/*ignored*/);
	LOGDATA = {sDATA("path", S_tochar(pth->urn)), sDATA("ospath", pth->ospath), sDATA("mode", mode), __ERRNO__};
	LIB_log("fopen", (fp != NULL), "IO!!");
	RETURN_(po);
}

//## @Native int File.getc();
KMETHOD File_getc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	int ch = EOF;
	if(fp != NULL) {
		ch = fgetc(fp);
	}
	RETURNi_(ch);
}

//## @Native int File.read(Bytes buf, int offset, int len);
KMETHOD File_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	size_t size = 0;
	if(fp != NULL) {
		knh_Bytes_t *ba = sfp[1].ba;
		size_t offset = (size_t)sfp[2].ivalue;
		size_t len = (size_t)sfp[3].ivalue;
		size = BA_size(ba);
		if(!(offset < size)) {
			THROW_OutOfRange(ctx, sfp, offset, size);
		}
		if(len == 0) len = size - offset;
		size = fread(ba->bu.buf + offset, 1, len, fp);
	}
	RETURNi_(size);
}

//## @Native boolean File.putc(int ch);
KMETHOD File_putc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	if(fp != NULL) {
		int ch = fputc((int)sfp[1].ivalue, fp);
		RETURNb_((ch != EOF));
	}
	RETURNb_(0);
}

//## @Native int File.write(Bytes buf, int offset, int len);
KMETHOD File_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	size_t size = 0;
	if(fp != NULL) {
		knh_Bytes_t *ba = sfp[1].ba;
		size_t offset = (size_t)sfp[2].ivalue;
		size_t len = (size_t)sfp[3].ivalue;
		size = BA_size(ba);
		if(!(offset < size)) {
			THROW_OutOfRange(ctx, sfp, offset, size);
		}
		if(len == 0) len = size - offset;
		size = fwrite(ba->bu.buf + offset, 1, len, fp);
	}
	RETURNi_(size);
}

//## @Native void File.close();
KMETHOD File_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	if(fp != NULL) {
		sfp[0].p->rawptr = NULL;
		fclose(fp);
	}
	RETURNvoid_();
}

/* ======================================================================== */

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadIntClassConst(ctx, CLASS_System, IntConstData);
	RETURN_PKGINFO("konoha.posix");
}

//DEFAPI(void) SystemCONST(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
//{
//	kapi->loadIntData(ctx, ns, IntConstData);
//}

#endif


/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
