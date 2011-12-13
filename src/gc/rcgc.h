#ifndef RCGC_H
#define RCGC_H

#include "bmgc.h"

void knh_traverse_refs(CTX ctx, knh_Ftraverse ftr)
{
#ifdef K_USING_RCGC
	int i;
	kmemlocal_t *memlocal = ctx->memlocal;
	if(memlocal->ref_size > 0) {
		prefetch_(memlocal->refs[0], 0, 1);
		for(i = memlocal->ref_size - 1; i >= 0; --i) {
			kObject *ref = memlocal->refs[i];
			ftr(ctx, ref);
		}
	}
#endif
}
static void deref_ostack(CTX ctx, kObject *ref, knh_ostack_t *ostack)
{
	if (knh_Object_RCdec(ref) == 1) {
		ostack_push(ctx, ostack, ref);
	}
}

void knh_Object_RCfree(CTX ctx, Object *o)
{
	long i;
	kObject *ref;
	knh_ostack_t ostackbuf, *ostack = ostack_init(ctx, &ostackbuf);
	kmemlocal_t *memlocal = ctx->memlocal;
	knh_ensurerefs(ctx, memlocal->ref_buf, K_PAGESIZE);
	ostack_push(ctx, ostack, o);
	while((ref = ostack_next(ostack)) != NULL) {
		context_reset_refs(memlocal);
		O_cTBL(ref)->cdef->reftrace(ctx, RAWPTR(ref), ctx->memlocal->refs);
		if (ctx->memlocal->ref_size > 0) {
			for(i = ctx->memlocal->ref_size - 1; prefetch(ctx->memlocal->refs[i-1]), i >= 0; i--) {
				deref_ostack(ctx, ctx->memlocal->refs[i], ostack);
			}
		}
		knh_Object_finalfree(ctx, ref);
	}
	ostack_free(ctx, ostack);
}

void knh_Object_RCsweep(CTX ctx, Object *o)
{
	knh_Object_RCdec(o);
	if(Object_isRC0(o)) {
		knh_Object_RCfree(ctx, o);
	}
}

#endif /* end of include guard */
