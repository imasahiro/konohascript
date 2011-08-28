#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KScene::KScene(void)
{
	mouse_press_func = NULL;
	mouse_move_func = NULL;
	mouse_release_func = NULL;
}

//void KGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
//{
//	emit emitDragEnterEvent(event);
//}
/*
void KScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	//fprintf(stderr, "KScene::mousePressEvent\n");
	if (ctx != NULL && sfp != NULL && mouse_press_func != NULL) {
		const knh_ClassTBL_t *ct1 = ClassTBL(cid);
		const knh_ClassTBL_t *ct2 = ClassTBL(mouse_event_cid);
		if (ct1 == NULL || ct2 == NULL) return;
		knh_RawPtr_t *p1 = (knh_RawPtr_t*)new_hObject_(ctx, ct1);
		p1->rawptr = this;
		KNH_SETv(ctx, sfp[5].o, UPCAST(p1));
		knh_RawPtr_t *p2 = (knh_RawPtr_t*)new_hObject_(ctx, ct2);
		p2->rawptr = event;
		KNH_SETv(ctx, sfp[6].o, UPCAST(p2));
		if (mouse_press_func->baseNULL != NULL) {
			KNH_SETv(ctx, sfp[K_CALLDELTA].o, mouse_press_func->baseNULL);
		}
		KNH_SCALL(ctx, sfp, 0, mouse_press_func->mtd, 3);
	}
}

void KScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	//fprintf(stderr, "KScene::mouseMoveEvent\n");
	if (ctx != NULL && sfp != NULL && mouse_move_func != NULL) {
		const knh_ClassTBL_t *ct1 = ClassTBL(cid);
		const knh_ClassTBL_t *ct2 = ClassTBL(mouse_event_cid);
		if (ct1 == NULL || ct2 == NULL) return;
		knh_RawPtr_t *p1 = (knh_RawPtr_t*)new_hObject_(ctx, ct1);
		p1->rawptr = this;
		KNH_SETv(ctx, sfp[5].o, UPCAST(p1));
		knh_RawPtr_t *p2 = (knh_RawPtr_t*)new_hObject_(ctx, ct2);
		p2->rawptr = event;
		KNH_SETv(ctx, sfp[6].o, UPCAST(p2));
		if (mouse_move_func->baseNULL != NULL) {
			KNH_SETv(ctx, sfp[K_CALLDELTA].o, mouse_move_func->baseNULL);
		}
		KNH_SCALL(ctx, sfp, 0, mouse_move_func->mtd, 3);
	}
}

void KScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	//fprintf(stderr, "KScene::mouseReleaseEvent\n");
	if (ctx != NULL && sfp != NULL && mouse_move_func != NULL) {
		const knh_ClassTBL_t *ct1 = ClassTBL(cid);
		const knh_ClassTBL_t *ct2 = ClassTBL(mouse_event_cid);
		if (ct1 == NULL || ct2 == NULL) return;
		knh_RawPtr_t *p1 = (knh_RawPtr_t*)new_hObject_(ctx, ct1);
		p1->rawptr = this;
		KNH_SETv(ctx, sfp[5].o, UPCAST(p1));
		knh_RawPtr_t *p2 = (knh_RawPtr_t*)new_hObject_(ctx, ct2);
		p2->rawptr = event;
		KNH_SETv(ctx, sfp[6].o, UPCAST(p2));
		if (mouse_release_func->baseNULL != NULL) {
			KNH_SETv(ctx, sfp[K_CALLDELTA].o, mouse_release_func->baseNULL);
		}
		KNH_SCALL(ctx, sfp, 0, mouse_release_func->mtd, 3);
	}
}
*/

KMETHOD Scene_setMousePressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	s->mouse_press_func = fo;
}

KMETHOD Scene_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	s->mouse_release_func = fo;
}

KMETHOD Scene_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	s->mouse_move_func = fo;
}

KMETHOD Scene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = new KScene();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, s, NULL);
	/*
	QObject::connect(gs, SIGNAL(emitMousePressEvent(QGraphicsSceneMouseEvent*)),
			s, SLOT(mousePressEvent(QGraphicsSceneMouseEvent*)));
	QObject::connect(gs, SIGNAL(emitMouseMoveEvent(QGraphicsSceneMouseEvent*)),
			s, SLOT(mouseMoveEvent(QGraphicsSceneMouseEvent*)));
	QObject::connect(gs, SIGNAL(emitMouseReleaseEvent(QGraphicsSceneMouseEvent*)),
			s, SLOT(mouseReleaseEvent(QGraphicsSceneMouseEvent*)));
	*/
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
	s->addItem(i);
	RETURNvoid_();
}

KMETHOD Scene_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KScene *s = RawPtr_to(KScene *, sfp[0]);
	QGraphicsItem *i = QGraphicsItem_to(sfp[1]);
	s->removeItem(i);
	RETURNvoid_();
}

static void Scene_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Scene:free\n");
#endif
		KScene* s = (KScene*)p->rawptr;
		(void)s;
		//delete s;
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
