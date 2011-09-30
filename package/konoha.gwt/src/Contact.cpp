#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_USING_BOX2D
KContact::KContact()
{
	begin = NULL;
	end = NULL;
}

void KContact::BeginContact(b2Contact *contact)
{
	//fprintf(stderr, "CONTACT BEGIN\n");
	b2Fixture *a = contact->GetFixtureA();
	b2Fixture *b = contact->GetFixtureB();
	b2Body *abody = a->GetBody();
	b2Body *bbody = b->GetBody();
	GamObject *data1 = (GamObject *)abody->GetUserData();
	GamObject *data2 = (GamObject *)bbody->GetUserData();
	if (data1 != NULL && data2 != NULL && begin != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *o1 = (knh_RawPtr_t *)data1->userdata;
		knh_RawPtr_t *o2 = (knh_RawPtr_t *)data1->userdata;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(o1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(o2));
		knh_Func_invoke(lctx, begin, lsfp, 2/*argc*/);
	}
}

void KContact::EndContact(b2Contact *contact)
{
	//fprintf(stderr, "CONTACT END\n");
	b2Fixture *a = contact->GetFixtureA();
	b2Fixture *b = contact->GetFixtureB();
	b2Body *abody = a->GetBody();
	b2Body *bbody = b->GetBody();
	GamObject *data1 = (GamObject *)abody->GetUserData();
	GamObject *data2 = (GamObject *)bbody->GetUserData();
	if (data1 != NULL && data2 != NULL && end != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *o1 = (knh_RawPtr_t *)data1->userdata;
		knh_RawPtr_t *o2 = (knh_RawPtr_t *)data1->userdata;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(o1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(o2));
		knh_Func_invoke(lctx, end, lsfp, 2/*argc*/);
	}
}

void KContact::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
	//fprintf(stderr, "CONTACT PRE SOLVE\n");
	(void)contact;
	(void)oldManifold;
}

void KContact::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
	//fprintf(stderr, "CONTACT POST SOLVE\n");
	(void)contact;
	(void)impulse;
}

static void Contact_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Contact:free\n");
#endif
		KContact *c = (KContact *)p->rawptr;
		delete c;
	}
}

static void Contact_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Contact:reftrace\n");
#endif
	}
}

DEFAPI(void) defContact(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Contact";
	cdef->free = Contact_free;
	cdef->reftrace = Contact_reftrace;
}

DEFAPI(void) constContact(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#endif

#ifdef __cplusplus
}
#endif
