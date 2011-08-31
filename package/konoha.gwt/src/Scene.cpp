#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KScene::KScene(void)
{
	mouse_press_func = NULL;
	mouse_move_func = NULL;
	mouse_release_func = NULL;
	added_list = new QList<knh_RawPtr_t *>();
}

void KScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_release_func, lsfp, 2/*argc*/);
	}
}

KMETHOD Scene_setMousePressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(s->mouse_press_func, fo);
}

KMETHOD Scene_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(s->mouse_release_func, fo);
}

KMETHOD Scene_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(s->mouse_move_func, fo);
}

KMETHOD Scene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = new KScene();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, s, NULL);
	s->self = p;
	RETURN_(p);
}

KMETHOD Scene_setItemIndexMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	QGraphicsScene::ItemIndexMethod idx = Int_to(QGraphicsScene::ItemIndexMethod, sfp[1]);
	s->setItemIndexMethod(idx);
	RETURNvoid_();
}

KMETHOD Scene_setBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	s->setBackgroundBrush(*c);
	RETURNvoid_();
}

KMETHOD Scene_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	int width = Int_to(int, sfp[3]);
	int height = Int_to(int, sfp[4]);
	s->setSceneRect(x, y, width, height);
	RETURNvoid_();
}

KMETHOD Scene_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	QGraphicsItem *i = QGraphicsItem_to(sfp[1]);
	s->added_list->append(sfp[1].p);
	s->addItem(i);
	RETURNvoid_();
}

KMETHOD Scene_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	QGraphicsItem *i = QGraphicsItem_to(sfp[1]);
	s->added_list->removeOne(sfp[1].p);
	s->removeItem(i);
	RETURNvoid_();
}

static void Scene_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Scene:free\n");
#endif
		KScene* s = (KScene*)p->rawptr;
	}
}

static void Scene_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Scene:reftrace\n");
#endif
		KScene *s = (KScene *)p->rawptr;
		int list_size = s->added_list->length();
		for (int i = 0; i < list_size; i++) {
			knh_RawPtr_t *item = s->added_list->at(i);
			KNH_ADDREF(ctx, item);
			WCTX(ctx)->ref_size++;
		}
	}
}

DEFAPI(void) defScene(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Scene";
	cdef->free = Scene_free;
	cdef->reftrace = Scene_reftrace;
}

static knh_IntData_t SceneConstInt[] = {
	{"NoIndex", QGraphicsScene::NoIndex},
	{NULL, 0}
};

DEFAPI(void) constScene(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, SceneConstInt);
}

#ifdef __cplusplus
}
#endif
