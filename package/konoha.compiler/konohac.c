#define K_INTERNAL 1
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

#ifdef __cplusplus
extern "C" {
#endif
/* copied from src/main/runtime.c */
static kbytes_t knh_bytes_nsname(kbytes_t t)
{
    size_t i, s = 0;
    for(i = t.len - 1; i > 0; i--) {
        if(t.utext[i] == '/' || t.utext[i] == '\\') {
            s = i + 1;
            break;
        }
    }
    for(i = s; i < t.len; i++) {
        if(t.utext[i] == '.') {
            t.utext = t.utext + s;
            t.len = i - s;
            return t;
        }
    }
    t.utext = t.utext + s;
    t.len = t.len - s;
    return t;
}

/* copied from package/konoha.compiler/compiler.c */
static kMethod *load_method(CTX ctx, kclass_t cid, kbytes_t t)
{
    kmethodn_t mn = knh_getmn(ctx, t, MN_NONAME);
    kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, cid, mn);
    assert(mtd != NULL);
    return mtd;
}

static enum compile_mode {
    EMIT_IR,
    EMIT_LLVM,
    EMIT_JS,
    EMIT_NOP
} compile_mode = EMIT_IR;
static const char * codegenerator_file[] = {
    NULL,
    "konoha.compiler.llvm",
    "konoha.compiler.js",
};

static const char *parse_option(int argc, const char *argv[])
{
    int i, argc_ = 0;
    const char *argv_[argc];
    if (argc <= 1) {
        fprintf(stderr, "usage: %s script.k\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < argc; ++i) {
        kbytes_t t = B(argv[i]);
        if (knh_bytes_equals(t, STEXT("--emit-llvm"))) {
            compile_mode = EMIT_LLVM;
            continue;
        }
        else if (knh_bytes_equals(t, STEXT("--emit-js"))) {
            compile_mode = EMIT_JS;
            continue;
        }
        argv_[argc_++] = argv[i];
    }
    konoha_ginit(argc_, argv_);
    return argv_[1];
}

extern void knh_setCompileMode(CTX ctx, int mode);
static fMethod_compile compilerAPI = NULL;
static void CompilerAPI_enable(CTX ctx)
{
    assert(compilerAPI != NULL && ctx->share->compilerAPI == NULL);
    ctx->wshare->compilerAPI = compilerAPI;
    compilerAPI     = NULL;
}
static void CompilerAPI_disable(CTX ctx)
{
    assert(compilerAPI == NULL && ctx->share->compilerAPI != NULL);
    compilerAPI     = ctx->wshare->compilerAPI;
    ctx->wshare->compilerAPI = NULL;
}

#if defined(K_USING_WINDOWS_)
#define SEPARATOR '\\'
#else
#define SEPARATOR '/'
#endif

static void load_codegenerator(CTX ctx)
{
    CompilerAPI_disable(ctx);
    if (codegenerator_file[compile_mode]) {
        kbytes_t t = new_bytes((char*)codegenerator_file[compile_mode]);
        knh_loadPackage(ctx, t);
        CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
        kString *s = (kString *) knh_DictMap_getNULL(ctx, ctx->share->props, STEXT("konoha.package.path"));
        CWB_clear(cwb, 0);
        knh_buff_addpath(ctx, cwb->ba, cwb->pos, 0, S_tobytes(s));
        knh_buff_addpath(ctx, cwb->ba, cwb->pos, 1, STEXT("konoha.compiler"));
        knh_buff_addpath(ctx, cwb->ba, cwb->pos, 1, STEXT("compiler"));
        knh_buff_addpath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
        void *p = knh_dlopen(ctx, CWB_totext(ctx, cwb));
        typedef void (*knh_Fpkgcomplete)(CTX);
        knh_Fpkgcomplete pkgcomplete = (knh_Fpkgcomplete) knh_dlsym(ctx, p, "reset_compiler_api", NULL, 1);
        if (pkgcomplete) pkgcomplete(ctx);
        CWB_close(ctx, cwb);
    }
    CompilerAPI_enable(ctx);
}

int main(int argc, const char *argv[])
{
    const char *fname = parse_option(argc, argv);
    konoha_t konoha = konoha_open();
    CTX ctx = konoha;
    KONOHA_BEGIN(ctx); {
        kString *s = new_T(fname);
        kPath *path = new_Path(ctx, s);
        knh_DictMap_set(ctx, ctx->share->props, new_T("script.name"), s);
        kbytes_t t = knh_bytes_nsname(S_tobytes(s));
        knh_Script_setNSName(ctx, ctx->script, new_S(t.text, t.len));
        kbytes_t pkgname = STEXT("konoha.compiler");
        knh_loadPackage(ctx, pkgname);

        load_codegenerator(ctx);
        knh_setCompileMode(ctx, 1);
        knh_load(ctx, path);

        /* CompilerAPI->dump() */
        kMethod *mtd = load_method(ctx,
                O_cid(ctx->share->konoha_compiler), STEXT("dump"));
        BEGIN_LOCAL(ctx, lsfp, K_CALLDELTA+1); {
            KNH_SETv(ctx, lsfp[K_CALLDELTA].o, ctx->share->konoha_compiler);
            KNH_SCALL(ctx, lsfp, 0, mtd, 0);
        } END_LOCAL(ctx, lsfp);
    } KONOHA_END(ctx);
    konoha_close(konoha);
    return 0;
}

#ifdef __cplusplus
}
#endif
