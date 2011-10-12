//QStatusBar QStatusBar.new(QWidget parent);
KMETHOD QStatusBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQStatusBar *ret_v = new KQStatusBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QStatusBar.addPermanentWidget(QWidget widget, int stretch);
KMETHOD QStatusBar_addPermanentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->addPermanentWidget(widget, stretch);
	}
	RETURNvoid_();
}

//void QStatusBar.addWidget(QWidget widget, int stretch);
KMETHOD QStatusBar_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->addWidget(widget, stretch);
	}
	RETURNvoid_();
}

//String QStatusBar.currentMessage();
KMETHOD QStatusBar_currentMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->currentMessage();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QStatusBar.insertPermanentWidget(int index, QWidget widget, int stretch);
KMETHOD QStatusBar_insertPermanentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		int stretch = Int_to(int, sfp[3]);
		int ret_v = qp->insertPermanentWidget(index, widget, stretch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QStatusBar.insertWidget(int index, QWidget widget, int stretch);
KMETHOD QStatusBar_insertWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		int stretch = Int_to(int, sfp[3]);
		int ret_v = qp->insertWidget(index, widget, stretch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QStatusBar.isSizeGripEnabled();
KMETHOD QStatusBar_isSizeGripEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSizeGripEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QStatusBar.removeWidget(QWidget widget);
KMETHOD QStatusBar_removeWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->removeWidget(widget);
	}
	RETURNvoid_();
}

//void QStatusBar.setSizeGripEnabled(boolean arg0);
KMETHOD QStatusBar_setSizeGripEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setSizeGripEnabled(arg0);
	}
	RETURNvoid_();
}

//void QStatusBar.clearMessage();
KMETHOD QStatusBar_clearMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		qp->clearMessage();
	}
	RETURNvoid_();
}

//void QStatusBar.showMessage(String message, int timeout);
KMETHOD QStatusBar_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusBar *  qp = RawPtr_to(QStatusBar *, sfp[0]);
	if (qp != NULL) {
		const QString message = String_to(const QString, sfp[1]);
		int timeout = Int_to(int, sfp[2]);
		qp->showMessage(message, timeout);
	}
	RETURNvoid_();
}


DummyQStatusBar::DummyQStatusBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStatusBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStatusBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQStatusBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStatusBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStatusBar::event_map->bigin();
	if ((itr = DummyQStatusBar::event_map->find(str)) == DummyQStatusBar::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStatusBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStatusBar::slot_map->bigin();
	if ((itr = DummyQStatusBar::event_map->find(str)) == DummyQStatusBar::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStatusBar::KQStatusBar(QWidget* parent) : QStatusBar(parent)
{
	self = NULL;
}

KMETHOD QStatusBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStatusBar *qp = RawPtr_to(KQStatusBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStatusBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStatusBar::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStatusBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStatusBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStatusBar *qp = RawPtr_to(KQStatusBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStatusBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStatusBar::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStatusBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStatusBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStatusBar *qp = (KQStatusBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStatusBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStatusBar *qp = (KQStatusBar *)p->rawptr;
		(void)qp;
	}
}

static int QStatusBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQStatusBar::event(QEvent *event)
{
	if (!DummyQStatusBar::eventDispatcher(event)) {
		QStatusBar::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQStatusBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStatusBar";
	cdef->free = QStatusBar_free;
	cdef->reftrace = QStatusBar_reftrace;
	cdef->compareTo = QStatusBar_compareTo;
}


