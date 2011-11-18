//
//@Virtual void QWebHistoryInterface.addHistoryEntry(String url);
KMETHOD QWebHistoryInterface_addHistoryEntry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryInterface *  qp = RawPtr_to(QWebHistoryInterface *, sfp[0]);
	if (qp) {
		const QString url = String_to(const QString, sfp[1]);
		qp->addHistoryEntry(url);
	}
	RETURNvoid_();
}

//@Virtual boolean QWebHistoryInterface.historyContains(String url);
KMETHOD QWebHistoryInterface_historyContains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryInterface *  qp = RawPtr_to(QWebHistoryInterface *, sfp[0]);
	if (qp) {
		const QString url = String_to(const QString, sfp[1]);
		bool ret_v = qp->historyContains(url);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebHistoryInterface QWebHistoryInterface.getDefaultInterface();
KMETHOD QWebHistoryInterface_getDefaultInterface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebHistoryInterface* ret_v = QWebHistoryInterface::defaultInterface();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebHistoryInterface*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebHistoryInterface.setDefaultInterface(QWebHistoryInterface defaultInterface);
KMETHOD QWebHistoryInterface_setDefaultInterface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebHistoryInterface*  defaultInterface = RawPtr_to(QWebHistoryInterface*, sfp[1]);
		QWebHistoryInterface::setDefaultInterface(defaultInterface);
	}
	RETURNvoid_();
}


DummyQWebHistoryInterface::DummyQWebHistoryInterface()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQWebHistoryInterface::~DummyQWebHistoryInterface()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWebHistoryInterface::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebHistoryInterface::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQWebHistoryInterface::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWebHistoryInterface::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistoryInterface::event_map->bigin();
	if ((itr = DummyQWebHistoryInterface::event_map->find(str)) == DummyQWebHistoryInterface::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebHistoryInterface::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistoryInterface::slot_map->bigin();
	if ((itr = DummyQWebHistoryInterface::slot_map->find(str)) == DummyQWebHistoryInterface::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebHistoryInterface::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebHistoryInterface::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWebHistoryInterface::connection(QObject *o)
{
	QWebHistoryInterface *p = dynamic_cast<QWebHistoryInterface*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQWebHistoryInterface::KQWebHistoryInterface(QObject* parent) : QWebHistoryInterface(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWebHistoryInterface();
	dummy->connection((QObject*)this);
}

KQWebHistoryInterface::~KQWebHistoryInterface()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWebHistoryInterface_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistoryInterface *qp = RawPtr_to(KQWebHistoryInterface *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistoryInterface]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistoryInterface]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebHistoryInterface_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistoryInterface *qp = RawPtr_to(KQWebHistoryInterface *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistoryInterface]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistoryInterface]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebHistoryInterface_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWebHistoryInterface *qp = (KQWebHistoryInterface *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWebHistoryInterface*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWebHistoryInterface_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWebHistoryInterface *qp = (KQWebHistoryInterface *)p->rawptr;
		KQWebHistoryInterface *qp = static_cast<KQWebHistoryInterface*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebHistoryInterface_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebHistoryInterface::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWebHistoryInterface::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWebHistoryInterface::event(event);
		return false;
	}
//	QWebHistoryInterface::event(event);
	return true;
}



DEFAPI(void) defQWebHistoryInterface(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebHistoryInterface";
	cdef->free = QWebHistoryInterface_free;
	cdef->reftrace = QWebHistoryInterface_reftrace;
	cdef->compareTo = QWebHistoryInterface_compareTo;
}


