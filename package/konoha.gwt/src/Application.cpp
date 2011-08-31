#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Application_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *args = (knh_Array_t *)sfp[1].o;
	static int args_size = knh_Array_size(args);
	char **value0 = (char **)malloc(args_size * sizeof(char*));
	for (int i = 0; i < args_size; i++) {
		knh_String_t *s = (knh_String_t *)args->list[i];
		value0[i] = (char *)s->str.text;
	}
	QApplication *app = new QApplication(args_size, value0);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, NULL);
	RETURN_(p);
}

KMETHOD Application_exec(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	QApplication *app = RawPtr_to(QApplication *, sfp[0]);
	app->exec();
	RETURNvoid_();
}

static void Application_free(CTX ctx, knh_RawPtr_t *p)
{
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Application:free\n");
#endif
		QApplication *app = (QApplication *)p->rawptr;
		delete app;
	}
}

static void Application_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Application:reftrace\n");
#endif
	}
}

DEFAPI(void) defApplication(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Application";
	cdef->free = Application_free;
	cdef->reftrace = Application_reftrace;
}

DEFAPI(void) constApplication(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}
	
#ifdef __cplusplus
}
#endif
