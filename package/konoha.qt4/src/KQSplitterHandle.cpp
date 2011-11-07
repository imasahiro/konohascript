//@Virtual @Override QSize QSplitterHandle.sizeHint();
KMETHOD QSplitterHandle_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitterHandle *  qp = RawPtr_to(QSplitterHandle *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSplitterHandle QSplitterHandle.new(int orientation, QSplitter parent);
KMETHOD QSplitterHandle_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QSplitter*  parent = RawPtr_to(QSplitter*, sfp[2]);
	KQSplitterHandle *ret_v = new KQSplitterHandle(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QSplitterHandle.opaqueResize();
KMETHOD QSplitterHandle_opaqueResize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitterHandle *  qp = RawPtr_to(QSplitterHandle *, sfp[0]);
	if (qp) {
		bool ret_v = qp->opaqueResize();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSplitterHandle.getOrientation();
KMETHOD QSplitterHandle_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitterHandle *  qp = RawPtr_to(QSplitterHandle *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSplitterHandle.setOrientation(int orientation);
KMETHOD QSplitterHandle_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitterHandle *  qp = RawPtr_to(QSplitterHandle *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//QSplitter QSplitterHandle.splitter();
KMETHOD QSplitterHandle_splitter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitterHandle *  qp = RawPtr_to(QSplitterHandle *, sfp[0]);
	if (qp) {
		QSplitter* ret_v = qp->splitter();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSplitter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQSplitterHandle::DummyQSplitterHandle()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSplitterHandle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSplitterHandle::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQSplitterHandle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSplitterHandle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplitterHandle::event_map->bigin();
	if ((itr = DummyQSplitterHandle::event_map->find(str)) == DummyQSplitterHandle::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSplitterHandle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplitterHandle::slot_map->bigin();
	if ((itr = DummyQSplitterHandle::slot_map->find(str)) == DummyQSplitterHandle::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSplitterHandle::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQSplitterHandle::connection(QObject *o)
{
	QSplitterHandle *p = dynamic_cast<QSplitterHandle*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQSplitterHandle::KQSplitterHandle(Qt::Orientation orientation, QSplitter* parent) : QSplitterHandle(orientation, parent)
{
	self = NULL;
	dummy = new DummyQSplitterHandle();
	dummy->connection((QObject*)this);
}

KMETHOD QSplitterHandle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplitterHandle *qp = RawPtr_to(KQSplitterHandle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSplitterHandle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplitterHandle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSplitterHandle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplitterHandle *qp = RawPtr_to(KQSplitterHandle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSplitterHandle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplitterHandle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSplitterHandle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSplitterHandle *qp = (KQSplitterHandle *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSplitterHandle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSplitterHandle *qp = (KQSplitterHandle *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSplitterHandle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSplitterHandle::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSplitterHandle::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSplitterHandle::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQSplitterHandle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSplitterHandle";
	cdef->free = QSplitterHandle_free;
	cdef->reftrace = QSplitterHandle_reftrace;
	cdef->compareTo = QSplitterHandle_compareTo;
}


