//QRect QDesktopWidget.availableGeometry(int screen);
KMETHOD QDesktopWidget_availableGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		int screen = Int_to(int, sfp[1]);
		const QRect ret_v = qp->availableGeometry(screen);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QDesktopWidget.availableGeometry(QWidget widget);
KMETHOD QDesktopWidget_availableGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		const QRect ret_v = qp->availableGeometry(widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRect QDesktopWidget.availableGeometry(QPoint p);
KMETHOD QDesktopWidget_availableGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		const QRect ret_v = qp->availableGeometry(p);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QDesktopWidget.isVirtualDesktop();
KMETHOD QDesktopWidget_isVirtualDesktop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isVirtualDesktop();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QDesktopWidget.primaryScreen();
KMETHOD QDesktopWidget_primaryScreen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		int ret_v = qp->primaryScreen();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QDesktopWidget.screen(int screen);
KMETHOD QDesktopWidget_screen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		int screen = Int_to(int, sfp[1]);
		QWidget* ret_v = qp->screen(screen);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDesktopWidget.screenCount();
KMETHOD QDesktopWidget_screenCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		int ret_v = qp->screenCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QDesktopWidget.screenGeometry(int screen);
KMETHOD QDesktopWidget_screenGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		int screen = Int_to(int, sfp[1]);
		const QRect ret_v = qp->screenGeometry(screen);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QDesktopWidget.screenGeometry(QWidget widget);
KMETHOD QDesktopWidget_screenGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		const QRect ret_v = qp->screenGeometry(widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRect QDesktopWidget.screenGeometry(QPoint p);
KMETHOD QDesktopWidget_screenGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		const QRect ret_v = qp->screenGeometry(p);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QDesktopWidget.screenNumber(QWidget widget);
KMETHOD QDesktopWidget_screenNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		int ret_v = qp->screenNumber(widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QDesktopWidget.screenNumber(QPoint point);
KMETHOD QDesktopWidget_screenNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopWidget *  qp = RawPtr_to(QDesktopWidget *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		int ret_v = qp->screenNumber(point);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/

DummyQDesktopWidget::DummyQDesktopWidget()
{
	self = NULL;
	resized_func = NULL;
	screen_count_changed_func = NULL;
	work_area_resized_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("resized", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("screen-count-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("work-area-resized", NULL));
}

void DummyQDesktopWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDesktopWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQDesktopWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDesktopWidget::resizedSlot(int screen)
{
	if (resized_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = screen;
		knh_Func_invoke(lctx, resized_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDesktopWidget::screenCountChangedSlot(int new_Count)
{
	if (screen_count_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = new_Count;
		knh_Func_invoke(lctx, screen_count_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDesktopWidget::workAreaResizedSlot(int screen)
{
	if (work_area_resized_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = screen;
		knh_Func_invoke(lctx, work_area_resized_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDesktopWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDesktopWidget::event_map->bigin();
	if ((itr = DummyQDesktopWidget::event_map->find(str)) == DummyQDesktopWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDesktopWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDesktopWidget::slot_map->bigin();
	if ((itr = DummyQDesktopWidget::slot_map->find(str)) == DummyQDesktopWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		resized_func = (*slot_map)["resized"];
		screen_count_changed_func = (*slot_map)["screen-count-changed"];
		work_area_resized_func = (*slot_map)["work-area-resized"];
		return true;
	}
}

void DummyQDesktopWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, resized_func);
	KNH_ADDNNREF(ctx, screen_count_changed_func);
	KNH_ADDNNREF(ctx, work_area_resized_func);

	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQDesktopWidget::connection(QObject *o)
{
	QDesktopWidget *p = dynamic_cast<QDesktopWidget*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(resized(int)), this, SLOT(resizedSlot(int)));
		connect(p, SIGNAL(screenCountChanged(int)), this, SLOT(screenCountChangedSlot(int)));
		connect(p, SIGNAL(workAreaResized(int)), this, SLOT(workAreaResizedSlot(int)));
	}
	DummyQWidget::connection(o);
}

KMETHOD QDesktopWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDesktopWidget *qp = RawPtr_to(KQDesktopWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDesktopWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDesktopWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDesktopWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDesktopWidget *qp = RawPtr_to(KQDesktopWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDesktopWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDesktopWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDesktopWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDesktopWidget *qp = (KQDesktopWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDesktopWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDesktopWidget *qp = (KQDesktopWidget *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDesktopWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDesktopWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDesktopWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDesktopWidget::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQDesktopWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDesktopWidget";
	cdef->free = QDesktopWidget_free;
	cdef->reftrace = QDesktopWidget_reftrace;
	cdef->compareTo = QDesktopWidget_compareTo;
}


