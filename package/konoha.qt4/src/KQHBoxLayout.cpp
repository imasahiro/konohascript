//QHBoxLayout QHBoxLayout.new();
KMETHOD QHBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *ret_v = new KQHBoxLayout();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHBoxLayout QHBoxLayout.new(QWidget parent);
KMETHOD QHBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQHBoxLayout *ret_v = new KQHBoxLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQHBoxLayout::DummyQHBoxLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQHBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHBoxLayout::self = ptr;
	DummyQBoxLayout::setSelf(ptr);
}

bool DummyQHBoxLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQBoxLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHBoxLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHBoxLayout::event_map->bigin();
	if ((itr = DummyQHBoxLayout::event_map->find(str)) == DummyQHBoxLayout::event_map->end()) {
		bool ret;
		ret = DummyQBoxLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHBoxLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHBoxLayout::slot_map->bigin();
	if ((itr = DummyQHBoxLayout::event_map->find(str)) == DummyQHBoxLayout::slot_map->end()) {
		bool ret;
		ret = DummyQBoxLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQHBoxLayout::KQHBoxLayout() : QHBoxLayout()
{
	self = NULL;
}

KMETHOD QHBoxLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *qp = RawPtr_to(KQHBoxLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHBoxLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQHBoxLayout::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHBoxLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QHBoxLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHBoxLayout *qp = RawPtr_to(KQHBoxLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHBoxLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQHBoxLayout::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHBoxLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHBoxLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQHBoxLayout *qp = (KQHBoxLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QHBoxLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQHBoxLayout *qp = (KQHBoxLayout *)p->rawptr;
		(void)qp;
	}
}

static int QHBoxLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQHBoxLayout::event(QEvent *event)
{
	if (!DummyQHBoxLayout::eventDispatcher(event)) {
		QHBoxLayout::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQHBoxLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHBoxLayout";
	cdef->free = QHBoxLayout_free;
	cdef->reftrace = QHBoxLayout_reftrace;
	cdef->compareTo = QHBoxLayout_compareTo;
}


