//QByteArrayMatcher QByteArrayMatcher.new();
KMETHOD QByteArrayMatcher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArrayMatcher *ret_v = new KQByteArrayMatcher();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QByteArrayMatcher QByteArrayMatcher.new(QByteArray pattern);
KMETHOD QByteArrayMatcher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  pattern = *RawPtr_to(const QByteArray *, sfp[1]);
	KQByteArrayMatcher *ret_v = new KQByteArrayMatcher(pattern);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QByteArrayMatcher QByteArrayMatcher.new(String pattern, int length);
KMETHOD QByteArrayMatcher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  pattern = RawPtr_to(const char*, sfp[1]);
	int length = Int_to(int, sfp[2]);
	KQByteArrayMatcher *ret_v = new KQByteArrayMatcher(pattern, length);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QByteArrayMatcher QByteArrayMatcher.new(QByteArrayMatcher other);
KMETHOD QByteArrayMatcher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArrayMatcher  other = *RawPtr_to(const QByteArrayMatcher *, sfp[1]);
	KQByteArrayMatcher *ret_v = new KQByteArrayMatcher(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QByteArrayMatcher.indexIn(QByteArray ba, int from_);
KMETHOD QByteArrayMatcher_indexIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArrayMatcher *  qp = RawPtr_to(QByteArrayMatcher *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->indexIn(ba, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QByteArrayMatcher.indexIn(String str, int len, int from_);
KMETHOD QByteArrayMatcher_indexIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArrayMatcher *  qp = RawPtr_to(QByteArrayMatcher *, sfp[0]);
	if (qp != NULL) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		int from = Int_to(int, sfp[3]);
		int ret_v = qp->indexIn(str, len, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//QByteArray QByteArrayMatcher.getPattern();
KMETHOD QByteArrayMatcher_getPattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArrayMatcher *  qp = RawPtr_to(QByteArrayMatcher *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->pattern();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QByteArrayMatcher.setPattern(QByteArray pattern);
KMETHOD QByteArrayMatcher_setPattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArrayMatcher *  qp = RawPtr_to(QByteArrayMatcher *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  pattern = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setPattern(pattern);
	}
	RETURNvoid_();
}


DummyQByteArrayMatcher::DummyQByteArrayMatcher()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQByteArrayMatcher::setSelf(knh_RawPtr_t *ptr)
{
	DummyQByteArrayMatcher::self = ptr;
}

bool DummyQByteArrayMatcher::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQByteArrayMatcher::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQByteArrayMatcher::event_map->bigin();
	if ((itr = DummyQByteArrayMatcher::event_map->find(str)) == DummyQByteArrayMatcher::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQByteArrayMatcher::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQByteArrayMatcher::slot_map->bigin();
	if ((itr = DummyQByteArrayMatcher::event_map->find(str)) == DummyQByteArrayMatcher::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQByteArrayMatcher::KQByteArrayMatcher() : QByteArrayMatcher()
{
	self = NULL;
}

KMETHOD QByteArrayMatcher_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArrayMatcher *qp = RawPtr_to(KQByteArrayMatcher *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QByteArrayMatcher]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQByteArrayMatcher::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QByteArrayMatcher]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QByteArrayMatcher_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArrayMatcher *qp = RawPtr_to(KQByteArrayMatcher *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QByteArrayMatcher]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQByteArrayMatcher::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QByteArrayMatcher]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QByteArrayMatcher_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQByteArrayMatcher *qp = (KQByteArrayMatcher *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QByteArrayMatcher_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQByteArrayMatcher *qp = (KQByteArrayMatcher *)p->rawptr;
		(void)qp;
	}
}

static int QByteArrayMatcher_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQByteArrayMatcher(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QByteArrayMatcher";
	cdef->free = QByteArrayMatcher_free;
	cdef->reftrace = QByteArrayMatcher_reftrace;
	cdef->compareTo = QByteArrayMatcher_compareTo;
}


