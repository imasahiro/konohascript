//@Virtual @Override boolean QWebInspector.event(QEvent ev);
KMETHOD QWebInspector_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebInspector *  qp = RawPtr_to(QWebInspector *, sfp[0]);
	if (qp) {
		QEvent*  ev = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(ev);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QWebInspector.sizeHint();
KMETHOD QWebInspector_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebInspector *  qp = RawPtr_to(QWebInspector *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebInspector QWebInspector.new(QWidget parent);
KMETHOD QWebInspector_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQWebInspector *ret_v = new KQWebInspector(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QWebPage QWebInspector.getPage();
KMETHOD QWebInspector_getPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebInspector *  qp = RawPtr_to(QWebInspector *, sfp[0]);
	if (qp) {
		QWebPage* ret_v = qp->page();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebInspector.setPage(QWebPage page);
KMETHOD QWebInspector_setPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebInspector *  qp = RawPtr_to(QWebInspector *, sfp[0]);
	if (qp) {
		QWebPage*  page = RawPtr_to(QWebPage*, sfp[1]);
		qp->setPage(page);
	}
	RETURNvoid_();
}


DummyQWebInspector::DummyQWebInspector()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebInspector::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebInspector::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQWebInspector::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWebInspector::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebInspector::event_map->bigin();
	if ((itr = DummyQWebInspector::event_map->find(str)) == DummyQWebInspector::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebInspector::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebInspector::slot_map->bigin();
	if ((itr = DummyQWebInspector::slot_map->find(str)) == DummyQWebInspector::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebInspector::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebInspector::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWebInspector::connection(QObject *o)
{
	QWebInspector *p = dynamic_cast<QWebInspector*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQWebInspector::KQWebInspector(QWidget* parent) : QWebInspector(parent)
{
	self = NULL;
	dummy = new DummyQWebInspector();
	dummy->connection((QObject*)this);
}

KMETHOD QWebInspector_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebInspector *qp = RawPtr_to(KQWebInspector *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebInspector]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebInspector]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebInspector_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebInspector *qp = RawPtr_to(KQWebInspector *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebInspector]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebInspector]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebInspector_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebInspector *qp = (KQWebInspector *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebInspector_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebInspector *qp = (KQWebInspector *)p->rawptr;
//		KQWebInspector *qp = static_cast<KQWebInspector*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebInspector_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebInspector::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWebInspector::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWebInspector::event(event);
		return false;
	}
//	QWebInspector::event(event);
	return true;
}



DEFAPI(void) defQWebInspector(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebInspector";
	cdef->free = QWebInspector_free;
	cdef->reftrace = QWebInspector_reftrace;
	cdef->compareTo = QWebInspector_compareTo;
}


