#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD MouseEvent_lastScreenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsSceneMouseEvent *event = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	QPointF spos = event->lastScreenPos();
	GamPoint *p = new GamPoint(spos.x(), spos.y());
	RETURN_(new_ReturnCppObject(ctx, sfp, p, NULL));
}

KMETHOD MouseEvent_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QGraphicsSceneMouseEvent *event = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	QPointF spos = event->scenePos();
	GamPoint *p = new GamPoint(spos.x(), spos.y());
	//printf("x: %lf, y: %lf\n", spos.x(), spos.y());
	RETURN_(new_ReturnCppObject(ctx, sfp, p, NULL));
}

static void MouseEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "MouseEvent:free\n");
#endif
		QGraphicsSceneMouseEvent *event = (QGraphicsSceneMouseEvent *)p->rawptr;
		(void)event;
		//delete event;
	}
}

static void MouseEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "MouseEvent:reftrace\n");
#endif
	}
}

DEFAPI(void) defMouseEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "MouseEvent";
	cdef->free = MouseEvent_free;
	cdef->reftrace = MouseEvent_reftrace;
}

DEFAPI(void) constMouseEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
