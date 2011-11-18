//QKeyEvent QKeyEvent.new(int type, int key, QtKeyboardModifiers modifiers, String text, boolean autorep, int count);
KMETHOD QKeyEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent::Type type = Int_to(QKeyEvent::Type, sfp[1]);
	int key = Int_to(int, sfp[2]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[3]);
	const QString text = String_to(const QString, sfp[4]);
	bool autorep = Boolean_to(bool, sfp[5]);
	ushort  count = *RawPtr_to(ushort *, sfp[6]);
	KQKeyEvent *ret_v = new KQKeyEvent(type, key, modifiers, text, autorep, count);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QKeyEvent.count();
KMETHOD QKeyEvent_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QKeyEvent.isAutoRepeat();
KMETHOD QKeyEvent_isAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAutoRepeat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QKeyEvent.key();
KMETHOD QKeyEvent_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->key();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QKeyEvent.matches(int key);
KMETHOD QKeyEvent_matches(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		QKeySequence::StandardKey key = Int_to(QKeySequence::StandardKey, sfp[1]);
		bool ret_v = qp->matches(key);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QtKeyboardModifiers QKeyEvent.modifiers();
KMETHOD QKeyEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QKeyEvent.nativeModifiers();
KMETHOD QKeyEvent_nativeModifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		quint32 ret_v = qp->nativeModifiers();
		quint32 *ret_v_ = new quint32(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QKeyEvent.nativeScanCode();
KMETHOD QKeyEvent_nativeScanCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		quint32 ret_v = qp->nativeScanCode();
		quint32 *ret_v_ = new quint32(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QKeyEvent.nativeVirtualKey();
KMETHOD QKeyEvent_nativeVirtualKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		quint32 ret_v = qp->nativeVirtualKey();
		quint32 *ret_v_ = new quint32(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QKeyEvent.text();
KMETHOD QKeyEvent_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEvent *  qp = RawPtr_to(QKeyEvent *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQKeyEvent::DummyQKeyEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQKeyEvent::~DummyQKeyEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQKeyEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQKeyEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQKeyEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQKeyEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeyEvent::event_map->bigin();
	if ((itr = DummyQKeyEvent::event_map->find(str)) == DummyQKeyEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQKeyEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeyEvent::slot_map->bigin();
	if ((itr = DummyQKeyEvent::slot_map->find(str)) == DummyQKeyEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQKeyEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQKeyEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQInputEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQKeyEvent::connection(QObject *o)
{
	QKeyEvent *p = dynamic_cast<QKeyEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQKeyEvent::KQKeyEvent(QKeyEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString text, bool autorep, ushort count) : QKeyEvent(type, key, modifiers, text, autorep, count)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQKeyEvent();
}

KQKeyEvent::~KQKeyEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QKeyEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeyEvent *qp = RawPtr_to(KQKeyEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QKeyEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeyEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QKeyEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeyEvent *qp = RawPtr_to(KQKeyEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QKeyEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeyEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QKeyEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQKeyEvent *qp = (KQKeyEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QKeyEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QKeyEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQKeyEvent *qp = (KQKeyEvent *)p->rawptr;
		KQKeyEvent *qp = static_cast<KQKeyEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QKeyEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQKeyEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQKeyEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QKeyEvent";
	cdef->free = QKeyEvent_free;
	cdef->reftrace = QKeyEvent_reftrace;
	cdef->compareTo = QKeyEvent_compareTo;
}


