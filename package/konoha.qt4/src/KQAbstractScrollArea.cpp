//@Virtual @Override QSize QAbstractScrollArea.minimumSizeHint();
KMETHOD QAbstractScrollArea_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QAbstractScrollArea.sizeHint();
KMETHOD QAbstractScrollArea_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//
//void QAbstractScrollArea.addScrollBarWidget(QWidget widget, int alignment);
KMETHOD QAbstractScrollArea_addScrollBarWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[2]);
		qp->addScrollBarWidget(widget, alignment);
	}
	RETURNvoid_();
}

//QWidget QAbstractScrollArea.getCornerWidget();
KMETHOD QAbstractScrollArea_getCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->cornerWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QScrollBar QAbstractScrollArea.getHorizontalScrollBar();
KMETHOD QAbstractScrollArea_getHorizontalScrollBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QScrollBar* ret_v = qp->horizontalScrollBar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QScrollBar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractScrollArea.getHorizontalScrollBarPolicy();
KMETHOD QAbstractScrollArea_getHorizontalScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::ScrollBarPolicy ret_v = qp->horizontalScrollBarPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QAbstractScrollArea.maximumViewportSize();
KMETHOD QAbstractScrollArea_maximumViewportSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->maximumViewportSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidgetList QAbstractScrollArea.scrollBarWidgets(int alignment);
KMETHOD QAbstractScrollArea_scrollBarWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		QWidgetList ret_v = qp->scrollBarWidgets(alignment);
		QWidgetList *ret_v_ = new QWidgetList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractScrollArea.setCornerWidget(QWidget widget);
KMETHOD QAbstractScrollArea_setCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setCornerWidget(widget);
	}
	RETURNvoid_();
}

//void QAbstractScrollArea.setHorizontalScrollBar(QScrollBar scrollBar);
KMETHOD QAbstractScrollArea_setHorizontalScrollBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QScrollBar*  scrollBar = RawPtr_to(QScrollBar*, sfp[1]);
		qp->setHorizontalScrollBar(scrollBar);
	}
	RETURNvoid_();
}

//void QAbstractScrollArea.setHorizontalScrollBarPolicy(int arg0);
KMETHOD QAbstractScrollArea_setHorizontalScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::ScrollBarPolicy arg0 = Int_to(Qt::ScrollBarPolicy, sfp[1]);
		qp->setHorizontalScrollBarPolicy(arg0);
	}
	RETURNvoid_();
}

//void QAbstractScrollArea.setVerticalScrollBar(QScrollBar scrollBar);
KMETHOD QAbstractScrollArea_setVerticalScrollBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QScrollBar*  scrollBar = RawPtr_to(QScrollBar*, sfp[1]);
		qp->setVerticalScrollBar(scrollBar);
	}
	RETURNvoid_();
}

//void QAbstractScrollArea.setVerticalScrollBarPolicy(int arg0);
KMETHOD QAbstractScrollArea_setVerticalScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::ScrollBarPolicy arg0 = Int_to(Qt::ScrollBarPolicy, sfp[1]);
		qp->setVerticalScrollBarPolicy(arg0);
	}
	RETURNvoid_();
}

//void QAbstractScrollArea.setViewport(QWidget widget);
KMETHOD QAbstractScrollArea_setViewport(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setViewport(widget);
	}
	RETURNvoid_();
}

//QScrollBar QAbstractScrollArea.getVerticalScrollBar();
KMETHOD QAbstractScrollArea_getVerticalScrollBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QScrollBar* ret_v = qp->verticalScrollBar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QScrollBar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractScrollArea.getVerticalScrollBarPolicy();
KMETHOD QAbstractScrollArea_getVerticalScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::ScrollBarPolicy ret_v = qp->verticalScrollBarPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QAbstractScrollArea.getViewport();
KMETHOD QAbstractScrollArea_getViewport(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractScrollArea *  qp = RawPtr_to(QAbstractScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->viewport();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractScrollArea::DummyQAbstractScrollArea()
{
	self = NULL;
	viewport_event_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("viewport-event", NULL));
}

void DummyQAbstractScrollArea::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractScrollArea::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQAbstractScrollArea::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
		ret = viewportEvent(dynamic_cast<QEvent*>(event));
		break;
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractScrollArea::viewportEvent(QEvent* event)
{
	if (viewport_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, viewport_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractScrollArea::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractScrollArea::event_map->bigin();
	if ((itr = DummyQAbstractScrollArea::event_map->find(str)) == DummyQAbstractScrollArea::event_map->end()) {
		bool ret;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		viewport_event_func = (*event_map)["viewport-event"];
		return true;
	}
}

bool DummyQAbstractScrollArea::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractScrollArea::slot_map->bigin();
	if ((itr = DummyQAbstractScrollArea::event_map->find(str)) == DummyQAbstractScrollArea::slot_map->end()) {
		bool ret;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractScrollArea::KQAbstractScrollArea(QWidget* parent) : QAbstractScrollArea(parent)
{
	self = NULL;
}

KMETHOD QAbstractScrollArea_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractScrollArea *qp = RawPtr_to(KQAbstractScrollArea *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractScrollArea]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractScrollArea::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractScrollArea]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractScrollArea_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractScrollArea *qp = RawPtr_to(KQAbstractScrollArea *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractScrollArea]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractScrollArea::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractScrollArea]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractScrollArea_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractScrollArea *qp = (KQAbstractScrollArea *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractScrollArea_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractScrollArea *qp = (KQAbstractScrollArea *)p->rawptr;
//		(void)qp;
		if (qp->viewport_event_func != NULL) {
			KNH_ADDREF(ctx, qp->viewport_event_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QAbstractScrollArea_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractScrollArea::event(QEvent *event)
{
	if (!DummyQAbstractScrollArea::eventDispatcher(event)) {
		QAbstractScrollArea::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractScrollArea(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractScrollArea";
	cdef->free = QAbstractScrollArea_free;
	cdef->reftrace = QAbstractScrollArea_reftrace;
	cdef->compareTo = QAbstractScrollArea_compareTo;
}


