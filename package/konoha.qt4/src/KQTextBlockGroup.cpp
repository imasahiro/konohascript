
DummyQTextBlockGroup::DummyQTextBlockGroup()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBlockGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBlockGroup::self = ptr;
	DummyQTextObject::setSelf(ptr);
}

bool DummyQTextBlockGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextBlockGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockGroup::event_map->bigin();
	if ((itr = DummyQTextBlockGroup::event_map->find(str)) == DummyQTextBlockGroup::event_map->end()) {
		bool ret;
		ret = DummyQTextObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlockGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockGroup::slot_map->bigin();
	if ((itr = DummyQTextBlockGroup::event_map->find(str)) == DummyQTextBlockGroup::slot_map->end()) {
		bool ret;
		ret = DummyQTextObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextBlockGroup::KQTextBlockGroup(QTextDocument* document) : QTextBlockGroup(document)
{
	self = NULL;
}

KMETHOD QTextBlockGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockGroup *qp = RawPtr_to(KQTextBlockGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextBlockGroup::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextBlockGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockGroup *qp = RawPtr_to(KQTextBlockGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextBlockGroup::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlockGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBlockGroup *qp = (KQTextBlockGroup *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBlockGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextBlockGroup *qp = (KQTextBlockGroup *)p->rawptr;
		(void)qp;
	}
}

static int QTextBlockGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTextBlockGroup::event(QEvent *event)
{
	if (!DummyQTextBlockGroup::eventDispatcher(event)) {
		QTextBlockGroup::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTextBlockGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlockGroup";
	cdef->free = QTextBlockGroup_free;
	cdef->reftrace = QTextBlockGroup_reftrace;
	cdef->compareTo = QTextBlockGroup_compareTo;
}


