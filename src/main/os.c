/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

/* ************************************************************************ */

#define USE_STEXT 1
#define USE_B     1
#define USE_bytes_startsWith    1
#define USE_bytes_endsWith      1

#define USE_cwb_open      1
#define USE_cwb_openinit  1
#define USE_cwb_tobytes   1
#define USE_cwb_write     1
#define USE_cwb_putc      1

#include"commons.h"

#ifdef K_USING_POSIX_
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <time.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#ifdef K_USING_MACOSX_
#include <mach-o/dyld.h>
#endif
#endif/*K_USING_POSIX_*/

#ifdef K_USING_WINDOWS
#include<windows.h>
#endif

#ifdef K_USING_BTRON
#include<btron/file.h>
#include<btron/dynload.h>
#include<tstring.h>
#endif

#ifdef HAVE_LOCALE_H
#include<locale.h>
#endif

#ifdef HAVE_LOCALCHARSET_H
#include<localcharset.h>
#endif

#ifdef HAVE_LANGINFO_H
#include<langinfo.h>
#endif

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#define K_PERROR_BEFORE_RETRUN

#if defined(K_USING_WINDOWS)
#define K_PERROR_LIBNAME "Windows"
#define K_PERROR_OK  1
#define K_PERROR_FAILED  0

#else
#define K_PERROR_LIBNAME "libc"
#define K_PERROR_OK       0
#define K_PERROR_FAILED  -1

#if !defined(K_USING_POSIX_)
static int UnsupportedAPI(CTX ctx, const char *funcname)
{
	ctx->api->perror(ctx, NULL, K_PERROR_LIBNAME, funcname);
	return K_PERROR_OK;
}
#endif
#endif

/* ------------------------------------------------------------------------ */
/* sysinfo */

#ifdef K_USING_BSDSYSCTL_
static size_t sysctl_getint(const char *name, int defdata)
{
	int data = defdata;
	size_t len = sizeof(int);
	if(sysctlbyname(name, &data, &len, NULL, 0) == -1) {
		//fprintf(stderr, "sysctl: %s=FAILED\n", name);
		return (size_t)data;
	}
	//fprintf(stderr, "sysctl: %s=%d\n", name, data);
	return (size_t)data;
}

static const char *sysctl_getstring(const char *name, char *buffer, size_t len)
{
	size_t len2 = 0;
	if(sysctlbyname(name, NULL, &len2, NULL, 0) == -1) {
		//fprintf(stderr, "sysctl: %s=FAILED, len2=%d<%d\n", name, len2, len);
		return NULL;
	}
	if(len2 <= len) {
		sysctlbyname(name, buffer, &len2, NULL, 0);
		//fprintf(stderr, "sysctl: %s=%s\n", name, buffer);
	}
	else {
		//fprintf(stderr, "sysctl: %s=FAILED, len2=%d<%d\n", name, len2, len);
	}
	return (const char*)buffer;
}

static void setsysinfo_sysctl(knh_sysinfo_t *sysinfo)
{
	static char cpu_brand[128] = {0};
	static char hw_machine[80] = {0};
	static char hw_model[128] = {0};
	static char kern_ostype[40] = {0};
	static char kern_version[40] = {0};
	static char kern_desc[128] = {0};
	sysinfo->cpu_desc = sysctl_getstring("machdep.cpu.brand_string", cpu_brand, sizeof(cpu_brand));
	sysinfo->hw_machine = sysctl_getstring("hw.machine", hw_machine, sizeof(hw_machine));
	sysinfo->hw_model = sysctl_getstring("hw.model", hw_model, sizeof(hw_model));
	sysinfo->hw_ncpu = sysctl_getint("hw.ncpu", 1);
	sysinfo->hw_availcpu = sysctl_getint("hw.availcpu", sysinfo->hw_ncpu);
	sysinfo->hw_physmem = sysctl_getint("hw.physmem", 0);
	sysinfo->hw_usermem = sysctl_getint("hw.usermem", 0);
	sysinfo->hw_cpufrequency = sysctl_getint("hw.cpufrequency", 0);
	sysinfo->hw_l2cachesize = sysctl_getint("hw.l2cachesize", 0);
	sysinfo->kern_ostype = sysctl_getstring("kern.ostype", kern_ostype, sizeof(kern_ostype));
	sysinfo->kern_version = sysctl_getstring("kern.osrelease", kern_version, sizeof(kern_version));
	sysinfo->kern_desc = sysctl_getstring("kern.version", kern_desc, sizeof(kern_desc));
}
#endif/*#ifdef K_USING_BSDSYSCTL*/

static char *append_string(char *p, const char *str, size_t len)
{
	size_t i;
	for(i = 0; i < len; i++) p[i] = str[i];
	p[len-1] = ' ';
	return p + (len);
}

#define APPEND_OPTION(p, STR)  p = append_string(p, STR, sizeof(STR));

static void setkonohainfo(knh_sysinfo_t *sysinfo)
{
	static char options[512] = {0};
	static char date[40] = {0};
	char *p = options;
	sysinfo->konoha_type = K_PROGNAME;
	sysinfo->konoha_codename = K_CODENAME;
	sysinfo->konoha_version = K_VERSION;
	sysinfo->konoha_disttype = K_DISTTYPE;
	sysinfo->konoha_disturl  = K_DISTURL;
	sysinfo->konoha_major_version = K_MAJOR_VERSION;
	sysinfo->konoha_minor_version = K_MINOR_VERSION;
	sysinfo->konoha_patch_version = K_PATCH_VERSION;
#if defined(K_PATCH_LEVEL)
	sysinfo->konoha_patch_level = K_PATCH_LEVEL;
#elif defined(K_REVISION)
	sysinfo->konoha_patch_level = K_REVISION;
#endif
	sysinfo->konoha_cc = CC_TYPE;
	knh_snprintf(date, sizeof(date), "%s %s", __DATE__, __TIME__);
	sysinfo->konoha_builtdate = date;
	sysinfo->konoha_config = CC_PLATFORM;
	sysinfo->konoha_disttype = K_DISTTYPE;
	sysinfo->konoha_disturl = K_DISTURL;
	sysinfo->konoha_systembits = (sizeof(void*) * 8);
	sysinfo->konoha_options = (const char*)options;
	/* THESE OPTIONS MUST BE ORDERED ALPHABETICALLY */
#if defined(K_USING_FASTEST)
	APPEND_OPTION(p, "fastest");
#endif
#if defined(K_USING_ICONV)
	APPEND_OPTION(p, "iconv");
#endif
#if defined(K_USING_INT32)
	APPEND_OPTION(p, "int32");
#endif
//#if defined(K_USING_PREFETCH)
//	APPEND_OPTION(p, "prefetch");
//#endif
//#if defined(K_USING_READLINE)
//	APPEND_OPTION(p, "readline");
//#endif
#if defined(K_USING_RCGC)
	APPEND_OPTION(p, "rcgc");
#else
	APPEND_OPTION(p, "msgc");
#endif
#if defined(K_USING_THCODE_)
	APPEND_OPTION(p, "thcode");
#else
	APPEND_OPTION(p, "switch");
#endif
#if defined(K_USING_SQLITE3)
	APPEND_OPTION(p, "sqlite3");
#endif
#if defined(K_USING_SYSLOG)
	APPEND_OPTION(p, "syslog");
#endif
#if defined(K_USING_THREAD)
	APPEND_OPTION(p, "thread");
#endif
#if defined(K_CONFIG_OS)
	if(sysinfo->kern_ostype == NULL) sysinfo->kern_ostype = K_CONFIG_OS;
#endif
}

static const knh_sysinfo_t *sysinfo_ = NULL;

const knh_sysinfo_t* knh_getsysinfo(void)
{
	if(sysinfo_ == NULL) {
		static knh_sysinfo_t sysinfo = {0};
#ifdef K_USING_BSDSYSCTL_
		setsysinfo_sysctl(&sysinfo);
#endif
		setkonohainfo(&sysinfo);
		sysinfo_ = &sysinfo;
	}
	return sysinfo_;
}

static void dump_int(CTX ctx, knh_OutputStream_t *w, const char *name, knh_intptr_t data, int isALL)
{
	if(data == -1) {
		if(!isALL) return;
		if(ctx == NULL) {
			fprintf(stderr, "%s: UNDEFINED\n", name);
		}
		else {
			knh_printf(ctx, w, "%s: UNDEFINED\n", name);
		}
	}
	else {
		if(ctx == NULL) {
			fprintf(stderr, "%s: %ld\n", name, (long)data);
		}
		else {
			knh_printf(ctx, w, "%s: %d\n", name, data);
		}
	}
}

static void dump_string(CTX ctx, knh_OutputStream_t *w, const char *name, const char *data, int isALL)
{
	if(data == NULL) {
		if(!isALL) return;
		data = "";
	}
	if(ctx == NULL) {
		fprintf(stderr, "%s: %s\n", name, data);
	}
	else {
		knh_printf(ctx, w, "%s: %s\n", name, data);
	}
}

void dump_sysinfo(CTX ctx, knh_OutputStream_t *w, int isALL)
{
	const knh_sysinfo_t *sysinfo = knh_getsysinfo();
	dump_string(ctx, w, "konoha.type", sysinfo->konoha_type, isALL);
	dump_string(ctx, w, "konoha.version", sysinfo->konoha_version, isALL);
	dump_int(ctx, w, "konoha.patch.level", sysinfo->konoha_patch_level, isALL);
	dump_string(ctx, w, "konoha.options", sysinfo->konoha_options, isALL);
	dump_int(ctx, w, "konoha.systembits", sysinfo->konoha_systembits, isALL);
	dump_string(ctx, w, "konoha.config", sysinfo->konoha_config, isALL);
	dump_string(ctx, w, "konoha.built.cc", sysinfo->konoha_cc, isALL);
	dump_string(ctx, w, "konoha.built.date", sysinfo->konoha_builtdate, isALL);
	dump_string(ctx, w, "konoha.dist_type", sysinfo->konoha_disttype, isALL);
	dump_string(ctx, w, "konoha.dist_url", sysinfo->konoha_disturl, isALL);
	dump_string(ctx, w, "kern.ostype", sysinfo->kern_ostype, isALL);
	dump_string(ctx, w, "kern.version", sysinfo->kern_version, isALL);
	dump_string(ctx, w, "kern.desc", sysinfo->kern_desc, isALL);
	dump_string(ctx, w, "hw.machine", sysinfo->hw_machine, isALL);
	dump_string(ctx, w, "hw.model", sysinfo->hw_model, isALL);
	dump_string(ctx, w, "cpu.desc", sysinfo->cpu_desc, isALL);
	dump_int(ctx, w, "hw.ncpu", sysinfo->hw_ncpu, isALL);
	dump_int(ctx, w, "hw.availcpu", sysinfo->hw_availcpu, isALL);
	dump_int(ctx, w, "hw.physmem", sysinfo->hw_physmem, isALL);
	dump_int(ctx, w, "hw.usermem", sysinfo->hw_usermem, isALL);
	dump_int(ctx, w, "hw.cpufrequency", sysinfo->hw_cpufrequency, isALL);
	dump_int(ctx, w, "hw.l2cachesize", sysinfo->hw_l2cachesize, isALL);
}

/* ------------------------------------------------------------------------ */


static void knh_Bytes_remove(CTX ctx, knh_Bytes_t *ba, size_t offset, size_t len)
{
	DBG_ASSERT(offset + len < BA_size(ba));
	knh_memmove(ba->bu.ubuf + offset, ba->bu.ustr + offset + len, BA_size(ba) - (offset + len));
	knh_bzero(ba->bu.ubuf + (BA_size(ba) - len), len);
	BA_size(ba) = BA_size(ba) - len;
}

static void knh_Bytes_concatZero(CTX ctx, knh_Bytes_t *ba)
{
	if(BA_size(ba) > 0 && ba->bu.ubuf[BA_size(ba)-1] == 0) {
		BA_size(ba) -= 1;
	}
}

/* ------------------------------------------------------------------------ */

const char* knh_cwb_ospath(CTX ctx, knh_cwb_t* cwb)
{
	knh_bytes_t path = knh_cwb_tobytes(cwb);
	int hasUTF8 = 0;
	if(knh_bytes_startsWith(path, STEXT("file:"))) {
		knh_Bytes_remove(ctx, cwb->ba, cwb->pos, 5);
	}
	{
		size_t i;
		for(i = 0; i < path.len; i++) {
			int ch = path.ubuf[i];
			if(ch == '/' || ch == '\\') {
				path.ubuf[i] = K_FILESEPARATOR;
			}
			if(ch > 127) hasUTF8 = 1;
		}
	}
	if(hasUTF8) {
		KNH_TODO("multibytes file path");
	}
	return knh_cwb_tochar(ctx, cwb);
}

KNHAPI2(knh_text_t*) knh_format_ospath(CTX ctx, char *buf, size_t bufsiz, const char *path)
{
	knh_snprintf(buf, bufsiz, "%s", path);
	return (knh_text_t*)buf;
}

/* ------------------------------------------------------------------------ */

const char* knh_cwb_realpath(CTX ctx, knh_cwb_t *cwb)
{
	const char *p = knh_cwb_tochar(ctx, cwb);
#if defined(K_USING_POSIX_)
#if defined(PATH_MAX)
	char buf[PATH_MAX] = {0};
#else
	char *buf = NULL;
#endif
	p = realpath(p, buf);
	if(p == NULL) {
		knh_cwb_clear(cwb, 0);
		knh_Bytes_write(ctx, cwb->ba, B(buf));
#if !defined(PATH_MAX)
	free(p);
#endif
	}
	p = knh_cwb_tochar(ctx, cwb);
#elif defined(K_USING_WINDOWS)
#if defined(PATH_MAX)
	char buf[PATH_MAX] = {0};
	int path_max = PATH_MAX;
#else
	char *buf = NULL;
	int path_max = 0;
#endif
	if(_fullpath(buf, p, path_max) == NULL) {
		knh_cwb_clear(cwb, 0);
		knh_Bytes_write(ctx, cwb->ba, B(buf));
#if !defined(PATH_MAX)
	free(buf);
#endif
	}
	p = knh_cwb_tochar(ctx, cwb);
#else
	KNH_HELP("realpath function for this architecture");
#endif
	return p;
}

/* ------------------------------------------------------------------------ */

knh_bool_t cwb_isfile(CTX ctx, knh_cwb_t *cwb)
{
	knh_bool_t res = 1;
	const char *pathname = knh_cwb_tochar(ctx, cwb);
#if defined(K_USING_WINDOWS)
	DWORD attr = GetFileAttributesA(pathname);
	if(attr == -1 || (attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) res = 0;
#elif defined(K_USING_POSIX_)
    struct stat buf;
	if(stat(pathname, &buf) == -1) res = 0;
	else res = S_ISREG(buf.st_mode);
#elif defined(K_USING_BTRON)
	FILE* in = fopen(pathname,"r");
	if(in == NULL)  res = 0;
	else fclose(in);
#else
	(void)pathname;
	return 0;
#endif
//	if(res == 0) {
//		DBG_P("isfile='%s' NOTFOUND", pathname);
//	}
	return res;
}

/* ------------------------------------------------------------------------ */

knh_bool_t cwb_isdir(CTX ctx, knh_cwb_t *cwb)
{
	const char *pathname = knh_cwb_tochar(ctx, cwb);
#if defined(K_USING_WINDOWS)
	DWORD attr = GetFileAttributesA(pathname);
	if(attr == -1) return 0;
	return ((attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY);
#elif defined(K_USING_POSIX_)
    struct stat buf;
	if(stat(pathname, &buf) == -1) return 0;
	return S_ISDIR(buf.st_mode);
#else
	// avoid "unused variable" warning unused variable
	(void)pathname;
	return 0;
#endif
}

/* ------------------------------------------------------------------------ */

#define SUBPATH_BUFSIZ 40

knh_bool_t knh_cwb_parentpath(CTX ctx, knh_cwb_t *cwb, char *subbuf)
{
	knh_bytes_t path = knh_cwb_tobytes(cwb);
	knh_intptr_t i;
	for(i = path.len - 1; i > 0; i--) {
		if(path.ustr[i] == '/' || path.ustr[i] == '\\') {
			if(subbuf != NULL) {
				knh_snprintf(subbuf, SUBPATH_BUFSIZ, "%s", path.text + i);
			}
			knh_cwb_clear(cwb, i);
			return 1;
		}
	}
	knh_cwb_clear(cwb, 0);
	return 0;
}

/* ------------------------------------------------------------------------ */

static knh_bool_t knh_cwb_mkdir(CTX ctx, knh_cwb_t *cwb, char *subpath)
{
	const char *pathname;
	if(cwb_isdir(ctx, cwb)) {
		char subbuf[SUBPATH_BUFSIZ];
		if(knh_cwb_parentpath(ctx, cwb, subbuf)) {
			if(knh_cwb_mkdir(ctx, cwb, subpath) == 0) {
				knh_cwb_write(ctx, cwb, B(subbuf));
			}
			else {
				return 0;
			}
		}
	}
	pathname = knh_cwb_tochar(ctx, cwb);
#if defined(K_USING_WINDOWS)
	PERROR_returnb_(CreateDirectory, pathname, NULL);
#elif defined(K_USING_POSIX_)
	PERROR_returnb_(mkdir, pathname, 0777);
#else
	PERROR_returnb_(UnsupportedAPI, ctx, __FUNCTION__);
#endif
}

/* ------------------------------------------------------------------------ */

knh_bool_t knh_mkdir(CTX ctx, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, path);
	knh_bool_t res = 1;
	knh_cwb_ospath(ctx, cwb);
	if(!cwb_isdir(ctx, cwb)) {
		knh_cwb_realpath(ctx, cwb);
		res = knh_cwb_mkdir(ctx, cwb, NULL);
	}
	knh_cwb_close(cwb);
	return res;
}

/* ------------------------------------------------------------------------ */
/* [homepath] */

/* Linux, MacOSX */
// $konoha.path /usr/local/konoha
// $konoha.bin.path  /usr/local/bin/konoha
// $konoha.package.path {$konoha.path}/package
// $konoha.script.path  {$konoha.path}/script

void knh_System_initPath(CTX ctx, knh_System_t *o)
{
	knh_SystemEX_t *sys = DP(o);
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	char *homepath = knh_getenv("KONOHAHOME");
	knh_String_t *shome;
	knh_bytes_t home = {{NULL}, 0};
#if defined(K_PATH_PREFIX)
	if(homepath == NULL) {
		homepath = K_PATH_PREFIX "/konoha";
	}
#endif
	if(homepath != NULL) {
		DictMap_set_(ctx, sys->props, new_T("konoha.path"), UPCAST(new_T(homepath)));
		home = B(homepath);
	}
#if defined(K_USING_WINDOWS)
	{
		char buf[FILEPATH_BUFSIZ];
		int bufsiz = FILEPATH_BUFSIZ;
		HMODULE h = LoadLibrary(NULL);
		GetModuleFileNameA(h, buf, bufsiz);
		knh_cwb_write(ctx, cwb, B(buf));
		DictMap_set_(ctx, sys->props,
			new_T("konoha.bin.path"), UPCAST(knh_cwb_newString(ctx, cwb)));
		if(homepath == NULL) {
			GetModuleFileNameA(h, buf, bufsiz);
			knh_cwb_write(ctx, cwb, B(buf));
			knh_cwb_parentpath(ctx, cwb, NULL);
			shome = knh_cwb_newString(ctx, cwb);
			home = S_tobytes(shome);
			DictMap_set_(ctx, sys->props, new_T("konoha.path"), UPCAST(shome));
		}
	}
#elif defined(K_USING_LINUX_)
	// @url(http://shinh.skr.jp/binary/b2con.html)
	// http://doc.trolltech.com/3.3/qapplication.html#applicationDirPath
	{
		char buf[FILEPATH_BUFSIZ];
		int bufsiz = FILEPATH_BUFSIZ;
		size_t size = readlink("/proc/self/exe", buf, bufsiz);
		knh_cwb_write(ctx, cwb, new_bytes2(buf, size));
		DictMap_set_(ctx, sys->props,
			new_T("konoha.bin.path"), UPCAST(knh_cwb_newString(ctx, cwb)));
		if(homepath == NULL) {
			size = readlink("/proc/self/exe", buf, bufsiz);
			knh_cwb_write(ctx, cwb, new_bytes2(buf, size));
			knh_cwb_parentpath(ctx, cwb, NULL);
			knh_cwb_parentpath(ctx, cwb, NULL);
			knh_cwb_write(ctx, cwb, B("/konoha"));
			shome = knh_cwb_newString(ctx, cwb);
			home = S_tobytes(shome);
			DictMap_set_(ctx, sys->props, new_T("konoha.path"), UPCAST(shome));
		}
	}
#elif defined(K_USING_MACOSX_)
	{
		char buf[PATH_MAX];
		char *s = (char*)_dyld_get_image_name(0);
		s = realpath(s, buf);
		knh_cwb_write(ctx, cwb, B(buf));
		DictMap_set_(ctx, sys->props,
			new_T("konoha.bin.path"), UPCAST(knh_cwb_newString(ctx, cwb)));
		if(homepath == NULL) {
			knh_cwb_write(ctx, cwb, B(s));
			knh_cwb_parentpath(ctx, cwb, NULL);
			knh_cwb_parentpath(ctx, cwb, NULL);
			knh_cwb_write(ctx, cwb, B("/konoha"));
			shome = knh_cwb_newString(ctx, cwb);
			home = S_tobytes(shome);
			DictMap_set_(ctx, sys->props, new_T("konoha.path"), UPCAST(shome));
		}
		//free(s);
	}
#else
	home = STEXT("/konoha");
	DictMap_set_(ctx, sys->props, new_T("konoha.path"), UPCAST(new_T("/konoha")));
#endif
	DBG_ASSERT(home.ustr != NULL);

	/* $konoha.package.path {$konoha.path}/package */
	knh_cwb_clear(cwb, 0);
	knh_cwb_write(ctx, cwb, home);
	knh_cwb_write(ctx, cwb, STEXT("/package/" LIBK_VERSION));
	DictMap_set_(ctx, sys->props,
		new_T("konoha.package.path"), UPCAST(knh_cwb_newString(ctx, cwb)));

	/* $konoha.script.path {$konoha.path}/script */
	knh_cwb_write(ctx, cwb, home);
	knh_cwb_write(ctx, cwb, STEXT("/script/" LIBK_VERSION));
	DictMap_set_(ctx, sys->props, new_T("konoha.tool.path"), UPCAST(knh_cwb_newString(ctx, cwb)));

#if defined(K_USING_WINDOWS)
	homepath = knh_getenv("USERPROFILE");
#else
	homepath = knh_getenv("HOME");
#endif
	if(homepath != NULL) {
		/* $user.path */
		knh_cwb_write(ctx, cwb, B(homepath));
		knh_cwb_putc(ctx, cwb, '/');
		knh_cwb_write(ctx, cwb, STEXT(K_KONOHAFOLDER));
		shome = knh_cwb_newString(ctx, cwb);
		home = S_tobytes(shome);
		DictMap_set_(ctx, sys->props, new_T("user.path"), UPCAST(shome));
		/* $konoha.temp.path ${user.path}/temp */
		knh_cwb_write(ctx, cwb, home);
		knh_cwb_write(ctx, cwb, STEXT("/temp/"));
		knh_write_text(ctx, cwb->w, (const char*)ctx->trace);
		DictMap_set_(ctx, sys->props, new_T("konoha.temp.path"), UPCAST(knh_cwb_newString(ctx, cwb)));

		/* $user.package.path ${user.path}/package */
		knh_cwb_write(ctx, cwb, home);
		knh_cwb_write(ctx, cwb, STEXT("/package/" LIBK_VERSION));
		DictMap_set_(ctx, sys->props, new_T("user.package.path"), UPCAST(knh_cwb_newString(ctx, cwb)));

		/* $user.script.path ${user.path}/script */
		knh_cwb_write(ctx, cwb, home);
		knh_cwb_write(ctx, cwb, STEXT("/script/" LIBK_VERSION));
		DictMap_set_(ctx, sys->props, new_T("user.tool.path"), UPCAST(knh_cwb_newString(ctx, cwb)));
		// Generating Directory
		knh_mkdir(ctx, S_tobytes(knh_getPropertyNULL(ctx, STEXT("user.path"))));
		//knh_mkdir(ctx, S_tobytes(knh_getPropertyNULL(ctx, STEXT("konoha.temp.path"))));
	}
	else {
		knh_cwb_write(ctx, cwb, STEXT("/tmp/"));
		knh_write_text(ctx, cwb->w, (const char*)ctx->trace);
		DictMap_set_(ctx, sys->props, new_T("konoha.temp.path"), UPCAST(knh_cwb_newString(ctx, cwb)));
	}
	knh_cwb_close(cwb);
}

/* ------------------------------------------------------------------------ */
/* [dlopen] */

void *knh_dlopen(CTX ctx, int pe, const char* path)
{
	const char *func = __FUNCTION__;
	void *handler = NULL;
#if defined(K_USING_WINDOWS)
	func = "LoadLibrary";
	handler = (void*)LoadLibraryA((LPCTSTR)path);
#elif defined(K_USING_POSIX_)
	func = "dlopen";
	handler = dlopen(path, RTLD_LAZY);
#else

#endif
	if(handler == NULL) {
		LIB_SYSLOG(ctx, pe, func, "path='%s'", path);
	}
	else {
		KNH_SYSLOG(ctx, LOG_NOTICE, func, "path='%s' HANDLER=%p", path, handler);
	}
	return handler;
}

void *knh_cwb_dlopen(CTX ctx, int pe, knh_cwb_t *cwb)
{
	const char *file;
	if(!knh_bytes_endsWith(knh_cwb_tobytes(cwb), STEXT(K_OSDLLEXT))) {
		knh_Bytes_concatZero(ctx, cwb->ba);
		knh_Bytes_write(ctx, cwb->ba, STEXT(K_OSDLLEXT));
	}
	file = knh_cwb_ospath(ctx, cwb);
	return knh_dlopen(ctx, LOG_NOTICE, file);
}

/* ------------------------------------------------------------------------ */

void *knh_dlsym(CTX ctx, int pe, void* handler, const char* symbol)
{
#if defined(K_USING_WINDOWS)
	void *p = GetProcAddress((HMODULE)handler, (LPCSTR)symbol);
	if(p == NULL) {
		LIB_SYSLOG(ctx, pe, "GetProcAddress", "func='%s', ERR='NotFound'", symbol);
	}
	return p;
#elif defined(K_USING_POSIX_)
	void *p = dlsym(handler, symbol);
	if(p == NULL) {
		LIB_SYSLOG(ctx, pe, "dlsym", "func='%s', ERR='%s'", symbol, dlerror());
	}
	return p;
#else
#endif
	return NULL;
}

/* ------------------------------------------------------------------------ */

int knh_dlclose(CTX ctx, void* hdr)
{
#if defined(K_USING_WINDOWS)
    return (int)FreeLibrary((HMODULE)hdr);
#elif defined(K_USING_POSIX_)
    return dlclose(hdr);
#elif defined(K_USING_BTRON)
    return b_dlclose((W)hdr);
#else
    return 0;
#endif
}

/* ------------------------------------------------------------------------ */
/* [charset] */

#if defined(K_USING_WINDOWS)

#define HAVE_LOCALCHARSET_H 1

static char *locale_charset(void)
{
	static char codepage[64];
	knh_snprintf(codepage, sizeof(codepage), "CP%d", (int)GetACP());
	return codepage;
}

#endif

/* ------------------------------------------------------------------------ */

const char *knh_getSystemEncoding(void)
{
	const char *enc = knh_getenv("KONOHAENC");
	if(enc != NULL) {
		return enc;
	}
#if defined(K_OSENCODING)
	return K_OSENCODING;
#elif defined(HAVE_LOCALCHARSET_H)
	return (char*)locale_charset();
#else
//	char *enc = knh_getenv("LC_CTYPE");
//	if(enc != NULL) {
//		return (char*)enc;
//	}
	return K_ENCODING;
#endif
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
