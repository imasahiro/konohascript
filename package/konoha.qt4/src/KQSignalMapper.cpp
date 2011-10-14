//QSignalMapper QSignalMapper.new(QObject parent);
KMETHOD QSignalMapper_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQSignalMapper *ret_v = new KQSignalMapper(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QObject QSignalMapper.getMapping(int id);
KMETHOD QSignalMapper_getMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		QObject* ret_v = qp->mapping(id);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QObject QSignalMapper.getMapping(String id);
KMETHOD QSignalMapper_getMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		const QString id = String_to(const QString, sfp[1]);
		QObject* ret_v = qp->mapping(id);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QObject QSignalMapper.getMapping(QWidget widget);
KMETHOD QSignalMapper_getMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		QObject* ret_v = qp->mapping(widget);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QObject QSignalMapper.getMapping(QObject object);
KMETHOD QSignalMapper_getMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QObject* ret_v = qp->mapping(object);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QSignalMapper.removeMappings(QObject sender);
KMETHOD QSignalMapper_removeMappings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		qp->removeMappings(sender);
	}
	RETURNvoid_();
}

//void QSignalMapper.setMapping(QObject sender, int id);
KMETHOD QSignalMapper_setMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		int id = Int_to(int, sfp[2]);
		qp->setMapping(sender, id);
	}
	RETURNvoid_();
}

/*
//void QSignalMapper.setMapping(QObject sender, String text);
KMETHOD QSignalMapper_setMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setMapping(sender, text);
	}
	RETURNvoid_();
}
*/
/*
//void QSignalMapper.setMapping(QObject sender, QWidget widget);
KMETHOD QSignalMapper_setMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		qp->setMapping(sender, widget);
	}
	RETURNvoid_();
}
*/
/*
//void QSignalMapper.setMapping(QObject sender, QObject object);
KMETHOD QSignalMapper_setMapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		QObject*  object = RawPtr_to(QObject*, sfp[2]);
		qp->setMapping(sender, object);
	}
	RETURNvoid_();
}
*/
//void QSignalMapper.map();
KMETHOD QSignalMapper_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		qp->map();
	}
	RETURNvoid_();
}

/*
//void QSignalMapper.map(QObject sender);
KMETHOD QSignalMapper_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalMapper *  qp = RawPtr_to(QSignalMapper *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		qp->map(sender);
	}
	RETURNvoid_();
}
*/

DummyQSignalMapper::DummyQSignalMapper()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSignalMapper::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSignalMapper::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQSignalMapper::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSignalMapper::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSignalMapper::event_map->bigin();
	if ((itr = DummyQSignalMapper::event_map->find(str)) == DummyQSignalMapper::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSignalMapper::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSignalMapper::slot_map->bigin();
	if ((itr = DummyQSignalMapper::slot_map->find(str)) == DummyQSignalMapper::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQSignalMapper::connection(QObject *o)
{
	DummyQObject::connection(o);
}

KQSignalMapper::KQSignalMapper(QObject* parent) : QSignalMapper(parent)
{
	self = NULL;
	dummy = new DummyQSignalMapper();
	dummy->connection((QObject*)this);
}

KMETHOD QSignalMapper_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSignalMapper *qp = RawPtr_to(KQSignalMapper *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSignalMapper]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSignalMapper]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSignalMapper_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSignalMapper *qp = RawPtr_to(KQSignalMapper *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSignalMapper]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSignalMapper]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSignalMapper_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSignalMapper *qp = (KQSignalMapper *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSignalMapper_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQSignalMapper *qp = (KQSignalMapper *)p->rawptr;
		(void)qp;
	}
}

static int QSignalMapper_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSignalMapper::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSignalMapper::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSignalMapper::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSignalMapper(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSignalMapper";
	cdef->free = QSignalMapper_free;
	cdef->reftrace = QSignalMapper_reftrace;
	cdef->compareTo = QSignalMapper_compareTo;
}


