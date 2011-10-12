//QFocusFrame QFocusFrame.new(QWidget parent);
KMETHOD QFocusFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFocusFrame *ret_v = new KQFocusFrame(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QFocusFrame.setWidget(QWidget widget);
KMETHOD QFocusFrame_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusFrame *  qp = RawPtr_to(QFocusFrame *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QWidget QFocusFrame.getWidget();
KMETHOD QFocusFrame_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusFrame *  qp = RawPtr_to(QFocusFrame *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQFocusFrame::DummyQFocusFrame()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFocusFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFocusFrame::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQFocusFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFocusFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusFrame::event_map->bigin();
	if ((itr = DummyQFocusFrame::event_map->find(str)) == DummyQFocusFrame::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFocusFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusFrame::slot_map->bigin();
	if ((itr = DummyQFocusFrame::event_map->find(str)) == DummyQFocusFrame::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQFocusFrame::KQFocusFrame(QWidget* parent) : QFocusFrame(parent)
{
	self = NULL;
}

KMETHOD QFocusFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusFrame *qp = RawPtr_to(KQFocusFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQFocusFrame::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QFocusFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusFrame *qp = RawPtr_to(KQFocusFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQFocusFrame::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFocusFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFocusFrame *qp = (KQFocusFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFocusFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQFocusFrame *qp = (KQFocusFrame *)p->rawptr;
		(void)qp;
	}
}

static int QFocusFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQFocusFrame::event(QEvent *event)
{
	if (!DummyQFocusFrame::eventDispatcher(event)) {
		QFocusFrame::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQFocusFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFocusFrame";
	cdef->free = QFocusFrame_free;
	cdef->reftrace = QFocusFrame_reftrace;
	cdef->compareTo = QFocusFrame_compareTo;
}


