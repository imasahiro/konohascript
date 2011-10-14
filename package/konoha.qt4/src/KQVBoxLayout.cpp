//QVBoxLayout QVBoxLayout.new();
KMETHOD QVBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQVBoxLayout *ret_v = new KQVBoxLayout();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QVBoxLayout QVBoxLayout.new(QWidget parent);
KMETHOD QVBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQVBoxLayout *ret_v = new KQVBoxLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQVBoxLayout::DummyQVBoxLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQVBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQVBoxLayout::self = ptr;
	DummyQBoxLayout::setSelf(ptr);
}

bool DummyQVBoxLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQBoxLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQVBoxLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQVBoxLayout::event_map->bigin();
	if ((itr = DummyQVBoxLayout::event_map->find(str)) == DummyQVBoxLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQBoxLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQVBoxLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQVBoxLayout::slot_map->bigin();
	if ((itr = DummyQVBoxLayout::slot_map->find(str)) == DummyQVBoxLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQBoxLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQVBoxLayout::connection(QObject *o)
{
	DummyQBoxLayout::connection(o);
}

KQVBoxLayout::KQVBoxLayout() : QVBoxLayout()
{
	self = NULL;
	dummy = new DummyQVBoxLayout();
	dummy->connection((QObject*)this);
}

KMETHOD QVBoxLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQVBoxLayout *qp = RawPtr_to(KQVBoxLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QVBoxLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QVBoxLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QVBoxLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQVBoxLayout *qp = RawPtr_to(KQVBoxLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QVBoxLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QVBoxLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QVBoxLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQVBoxLayout *qp = (KQVBoxLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QVBoxLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQVBoxLayout *qp = (KQVBoxLayout *)p->rawptr;
		(void)qp;
	}
}

static int QVBoxLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQVBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQVBoxLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QVBoxLayout::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQVBoxLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QVBoxLayout";
	cdef->free = QVBoxLayout_free;
	cdef->reftrace = QVBoxLayout_reftrace;
	cdef->compareTo = QVBoxLayout_compareTo;
}


