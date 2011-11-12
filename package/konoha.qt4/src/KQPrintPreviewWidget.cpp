//@Virtual @Override void QPrintPreviewWidget.setVisible(boolean visible);
KMETHOD QPrintPreviewWidget_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QPrintPreviewWidget QPrintPreviewWidget.new(QPrinter printer, QWidget parent, QtWindowFlags flags);
KMETHOD QPrintPreviewWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	initFlag(flags, Qt::WindowFlags, sfp[3]);
	KQPrintPreviewWidget *ret_v = new KQPrintPreviewWidget(printer, parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPrintPreviewWidget QPrintPreviewWidget.new(QWidget parent, QtWindowFlags flags);
KMETHOD QPrintPreviewWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQPrintPreviewWidget *ret_v = new KQPrintPreviewWidget(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QPrintPreviewWidget.getCurrentPage();
KMETHOD QPrintPreviewWidget_getCurrentPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrintPreviewWidget.getOrientation();
KMETHOD QPrintPreviewWidget_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrinter::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrintPreviewWidget.pageCount();
KMETHOD QPrintPreviewWidget_pageCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		int ret_v = qp->pageCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrintPreviewWidget.getViewMode();
KMETHOD QPrintPreviewWidget_getViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrintPreviewWidget::ViewMode ret_v = qp->viewMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QPrintPreviewWidget.getZoomFactor();
KMETHOD QPrintPreviewWidget_getZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->zoomFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QPrintPreviewWidget.getZoomMode();
KMETHOD QPrintPreviewWidget_getZoomMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrintPreviewWidget::ZoomMode ret_v = qp->zoomMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPrintPreviewWidget.fitInView();
KMETHOD QPrintPreviewWidget_fitInView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->fitInView();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.fitToWidth();
KMETHOD QPrintPreviewWidget_fitToWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->fitToWidth();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.print();
KMETHOD QPrintPreviewWidget_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->print();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setAllPagesViewMode();
KMETHOD QPrintPreviewWidget_setAllPagesViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->setAllPagesViewMode();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setCurrentPage(int page);
KMETHOD QPrintPreviewWidget_setCurrentPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		int page = Int_to(int, sfp[1]);
		qp->setCurrentPage(page);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setFacingPagesViewMode();
KMETHOD QPrintPreviewWidget_setFacingPagesViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->setFacingPagesViewMode();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setLandscapeOrientation();
KMETHOD QPrintPreviewWidget_setLandscapeOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->setLandscapeOrientation();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setOrientation(int orientation);
KMETHOD QPrintPreviewWidget_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrinter::Orientation orientation = Int_to(QPrinter::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setPortraitOrientation();
KMETHOD QPrintPreviewWidget_setPortraitOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->setPortraitOrientation();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setSinglePageViewMode();
KMETHOD QPrintPreviewWidget_setSinglePageViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->setSinglePageViewMode();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setViewMode(int mode);
KMETHOD QPrintPreviewWidget_setViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrintPreviewWidget::ViewMode mode = Int_to(QPrintPreviewWidget::ViewMode, sfp[1]);
		qp->setViewMode(mode);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setZoomFactor(float factor);
KMETHOD QPrintPreviewWidget_setZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->setZoomFactor(factor);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.setZoomMode(int zoomMode);
KMETHOD QPrintPreviewWidget_setZoomMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		QPrintPreviewWidget::ZoomMode zoomMode = Int_to(QPrintPreviewWidget::ZoomMode, sfp[1]);
		qp->setZoomMode(zoomMode);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.updatePreview();
KMETHOD QPrintPreviewWidget_updatePreview(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qp->updatePreview();
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.zoomIn(float factor);
KMETHOD QPrintPreviewWidget_zoomIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->zoomIn(factor);
	}
	RETURNvoid_();
}

//void QPrintPreviewWidget.zoomOut(float factor);
KMETHOD QPrintPreviewWidget_zoomOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewWidget *  qp = RawPtr_to(QPrintPreviewWidget *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->zoomOut(factor);
	}
	RETURNvoid_();
}


DummyQPrintPreviewWidget::DummyQPrintPreviewWidget()
{
	self = NULL;
	paint_requested_func = NULL;
	preview_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("paint-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("preview-changed", NULL));
}

void DummyQPrintPreviewWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrintPreviewWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQPrintPreviewWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPrintPreviewWidget::paintRequestedSlot(QPrinter* printer)
{
	if (paint_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPrinter, printer);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, paint_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPrintPreviewWidget::previewChangedSlot()
{
	if (preview_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, preview_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQPrintPreviewWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintPreviewWidget::event_map->bigin();
	if ((itr = DummyQPrintPreviewWidget::event_map->find(str)) == DummyQPrintPreviewWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrintPreviewWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintPreviewWidget::slot_map->bigin();
	if ((itr = DummyQPrintPreviewWidget::slot_map->find(str)) == DummyQPrintPreviewWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		paint_requested_func = (*slot_map)["paint-requested"];
		preview_changed_func = (*slot_map)["preview-changed"];
		return true;
	}
}

knh_Object_t** DummyQPrintPreviewWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPrintPreviewWidget::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, paint_requested_func);
	KNH_ADDNNREF(ctx, preview_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPrintPreviewWidget::connection(QObject *o)
{
	QPrintPreviewWidget *p = dynamic_cast<QPrintPreviewWidget*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(paintRequested(QPrinter*)), this, SLOT(paintRequestedSlot(QPrinter*)));
		connect(p, SIGNAL(previewChanged()), this, SLOT(previewChangedSlot()));
	}
	DummyQWidget::connection(o);
}

KQPrintPreviewWidget::KQPrintPreviewWidget(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags) : QPrintPreviewWidget(printer, parent, flags)
{
	self = NULL;
	dummy = new DummyQPrintPreviewWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QPrintPreviewWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintPreviewWidget *qp = RawPtr_to(KQPrintPreviewWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintPreviewWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintPreviewWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPrintPreviewWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintPreviewWidget *qp = RawPtr_to(KQPrintPreviewWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintPreviewWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintPreviewWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrintPreviewWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPrintPreviewWidget *qp = (KQPrintPreviewWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPrintPreviewWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPrintPreviewWidget *qp = (KQPrintPreviewWidget *)p->rawptr;
//		KQPrintPreviewWidget *qp = static_cast<KQPrintPreviewWidget*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPrintPreviewWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPrintPreviewWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPrintPreviewWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPrintPreviewWidget::event(event);
		return false;
	}
//	QPrintPreviewWidget::event(event);
	return true;
}

static knh_IntData_t QPrintPreviewWidgetConstInt[] = {
	{"SinglePageView", QPrintPreviewWidget::SinglePageView},
	{"FacingPagesView", QPrintPreviewWidget::FacingPagesView},
	{"AllPagesView", QPrintPreviewWidget::AllPagesView},
	{"CustomZoom", QPrintPreviewWidget::CustomZoom},
	{"FitToWidth", QPrintPreviewWidget::FitToWidth},
	{"FitInView", QPrintPreviewWidget::FitInView},
	{NULL, 0}
};

DEFAPI(void) constQPrintPreviewWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPrintPreviewWidgetConstInt);
}


DEFAPI(void) defQPrintPreviewWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrintPreviewWidget";
	cdef->free = QPrintPreviewWidget_free;
	cdef->reftrace = QPrintPreviewWidget_reftrace;
	cdef->compareTo = QPrintPreviewWidget_compareTo;
}


