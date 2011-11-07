//QSocketNotifier QSocketNotifier.new(int socket, int type, QObject parent);
KMETHOD QSocketNotifier_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int socket = Int_to(int, sfp[1]);
	QSocketNotifier::Type type = Int_to(QSocketNotifier::Type, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQSocketNotifier *ret_v = new KQSocketNotifier(socket, type, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QSocketNotifier.isEnabled();
KMETHOD QSocketNotifier_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSocketNotifier *  qp = RawPtr_to(QSocketNotifier *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSocketNotifier.socket();
KMETHOD QSocketNotifier_socket(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSocketNotifier *  qp = RawPtr_to(QSocketNotifier *, sfp[0]);
	if (qp) {
		int ret_v = qp->socket();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSocketNotifier.type();
KMETHOD QSocketNotifier_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSocketNotifier *  qp = RawPtr_to(QSocketNotifier *, sfp[0]);
	if (qp) {
		QSocketNotifier::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSocketNotifier.setEnabled(boolean enable);
KMETHOD QSocketNotifier_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSocketNotifier *  qp = RawPtr_to(QSocketNotifier *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enable);
	}
	RETURNvoid_();
}


DummyQSocketNotifier::DummyQSocketNotifier()
{
	self = NULL;
	activated_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("activated", NULL));
}

void DummyQSocketNotifier::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSocketNotifier::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQSocketNotifier::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSocketNotifier::activatedSlot(int socket)
{
	if (activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = socket;
		knh_Func_invoke(lctx, activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSocketNotifier::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSocketNotifier::event_map->bigin();
	if ((itr = DummyQSocketNotifier::event_map->find(str)) == DummyQSocketNotifier::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSocketNotifier::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSocketNotifier::slot_map->bigin();
	if ((itr = DummyQSocketNotifier::slot_map->find(str)) == DummyQSocketNotifier::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		activated_func = (*slot_map)["activated"];
		return true;
	}
}

void DummyQSocketNotifier::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, activated_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQSocketNotifier::connection(QObject *o)
{
	QSocketNotifier *p = dynamic_cast<QSocketNotifier*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(activated(int)), this, SLOT(activatedSlot(int)));
	}
	DummyQObject::connection(o);
}

KQSocketNotifier::KQSocketNotifier(int socket, QSocketNotifier::Type type, QObject* parent) : QSocketNotifier(socket, type, parent)
{
	self = NULL;
	dummy = new DummyQSocketNotifier();
	dummy->connection((QObject*)this);
}

KMETHOD QSocketNotifier_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSocketNotifier *qp = RawPtr_to(KQSocketNotifier *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSocketNotifier]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSocketNotifier]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSocketNotifier_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSocketNotifier *qp = RawPtr_to(KQSocketNotifier *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSocketNotifier]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSocketNotifier]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSocketNotifier_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSocketNotifier *qp = (KQSocketNotifier *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSocketNotifier_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSocketNotifier *qp = (KQSocketNotifier *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSocketNotifier_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSocketNotifier::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSocketNotifier::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSocketNotifier::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QSocketNotifierConstInt[] = {
	{"Read", QSocketNotifier::Read},
	{"Write", QSocketNotifier::Write},
	{"Exception", QSocketNotifier::Exception},
	{NULL, 0}
};

DEFAPI(void) constQSocketNotifier(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSocketNotifierConstInt);
}


DEFAPI(void) defQSocketNotifier(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSocketNotifier";
	cdef->free = QSocketNotifier_free;
	cdef->reftrace = QSocketNotifier_reftrace;
	cdef->compareTo = QSocketNotifier_compareTo;
}


