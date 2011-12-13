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

int main(int argc, const char *argv[])
{
    if (argc <= 1) {
        fprintf(stderr, "usage: %s script.k\n", argv[0]);
        return 1;
    }
    konoha_ginit(1, argv);
    konoha_t konoha = konoha_open();
    CTX ctx = konoha;
    KONOHA_BEGIN(ctx);
    kString *s = new_T(argv[1]);
    kPath *path = new_Path(ctx, s);
    knh_DictMap_set(ctx, ctx->share->props, new_T("script.name"), s);
    kbytes_t t = knh_bytes_nsname(S_tobytes(s));
    knh_Script_setNSName(ctx, ctx->script,
            new_String2(ctx, CLASS_String, t.text, t.len, SPOL_TEXT|SPOL_POOLALWAYS));
    kbytes_t pkgname = STEXT("konoha.compiler");
    knh_loadPackage(ctx, pkgname);

    knh_load(ctx, path);

    /* CompilerAPI->dump() */
    kMethod *mtd = load_method(ctx, O_cid(ctx->share->konoha_compiler), STEXT("dump"));
    BEGIN_LOCAL(ctx, lsfp, K_CALLDELTA+1);
    KNH_SETv(ctx, lsfp[K_CALLDELTA].o, ctx->share->konoha_compiler);
    KNH_SCALL(ctx, lsfp, 0, mtd, 0);
    END_LOCAL(ctx, lsfp);
    KONOHA_END(ctx);
    konoha_close(konoha);
    return 0;
}

#ifdef __cplusplus
}
#endif
